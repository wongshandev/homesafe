#if defined(__WS_HOME_SAFE__)
#include "ws_ps.h"
#include "MMIDataType.h"
#include "ws_main.h"


#define SF_WRITE_FS
extern hf_nvram	  hf_nv;












void hf_write_nvram(void)
{
	S16 error;
	WriteRecord(NVRAM_HF_DATA_LID, 1, &hf_nv, NVRAM_EF_HF_DATA_SIZE, &error);
}
void hf_read_nvram(void)
{
	S16 error;
	ReadRecord(NVRAM_HF_DATA_LID,1, &hf_nv, NVRAM_EF_HF_DATA_SIZE, &error);
}

/* 大写转换小写*/
char * str_big_to_low(char * _data)
{
	int _count = 0;
	
	if(_data == NULL) return NULL;
	for(_count=0;_count<strlen(_data);_count++)
	{
		if((*(_data+_count) >= 'A')&&((*(_data+_count))<= 'Z'))
		{
			*(_data+_count) += 32;
		}
	}
	return _data;
}

#define NMEA_TOKS_COMPARE   (1)
#define NMEA_TOKS_PERCENT   (2)
#define NMEA_TOKS_WIDTH     (3)
#define NMEA_TOKS_TYPE      (4)
#define NMEA_VERSION_MAJOR  (0)
#define NMEA_VERSION_MINOR  (5)
#define NMEA_VERSION_PATCH  (3)

#define NMEA_CONVSTR_BUF    (256)
#define NMEA_TIMEPARSE_BUF  (256)
/**
 * \brief Convert string to number
 */
int nmea_atoi(const char *str, int str_sz, int radix)
{
    char *tmp_ptr;
    char buff[NMEA_CONVSTR_BUF];
    int res = 0;

    if(str_sz < NMEA_CONVSTR_BUF)
    {
        memcpy(&buff[0], str, str_sz);
        buff[str_sz] = '\0';
        res = strtol(&buff[0], &tmp_ptr, radix);
    }

    return res;
}

/**
 * \brief Convert string to fraction number
 */
double nmea_atof(const char *str, int str_sz)
{
    char *tmp_ptr;
    char buff[NMEA_CONVSTR_BUF];
    double res = 0;

    if(str_sz < NMEA_CONVSTR_BUF)
    {
        memcpy(&buff[0], str, str_sz);
        buff[str_sz] = '\0';
        res = strtod(&buff[0], &tmp_ptr);
    }

    return res;
}
int hf_scanf(const char *buff, int buff_sz, const char *format, ...)
{
    const char *beg_tok;
    const char *end_buf = buff + buff_sz;

    va_list arg_ptr;
    int tok_type = NMEA_TOKS_COMPARE;
    int width = 0;
    const char *beg_fmt = 0;
    int snum = 0, unum = 0;

    int tok_count = 0;
    void *parg_target;

    va_start(arg_ptr, format);
    
    for(; *format && buff < end_buf; ++format)
    {
        switch(tok_type)
        {
        case NMEA_TOKS_COMPARE:
            if('%' == *format)
                tok_type = NMEA_TOKS_PERCENT;
            else if(*buff++ != *format)
                goto fail;
            break;
        case NMEA_TOKS_PERCENT:
            width = 0;
            beg_fmt = format;
            tok_type = NMEA_TOKS_WIDTH;
        case NMEA_TOKS_WIDTH:
            if(isdigit(*format))
                break;
            {
                tok_type = NMEA_TOKS_TYPE;
                if(format > beg_fmt)
                    width = nmea_atoi(beg_fmt, (int)(format - beg_fmt), 10);
            }
        case NMEA_TOKS_TYPE:
            beg_tok = buff;

            if(!width && ('c' == *format || 'C' == *format) && *buff != format[1])
                width = 1;

            if(width)
            {
                if(buff + width <= end_buf)
                    buff += width;
                else
                    goto fail;
            }
            else
            {
                if(!format[1] || (0 == (buff = (char *)memchr(buff, format[1], end_buf - buff))))
                    buff = end_buf;
            }

            if(buff > end_buf)
                goto fail;

            tok_type = NMEA_TOKS_COMPARE;
            tok_count++;

            parg_target = 0; width = (int)(buff - beg_tok);

            switch(*format)
            {
            case 'c':
            case 'C':
                parg_target = (void *)va_arg(arg_ptr, char *);
                if(width && 0 != (parg_target))
                    *((char *)parg_target) = *beg_tok;
                break;
            case 's':
            case 'S':
                parg_target = (void *)va_arg(arg_ptr, char *);
                if(width && 0 != (parg_target))
                {
                    memcpy(parg_target, beg_tok, width);
                    ((char *)parg_target)[width] = '\0';
                }
                break;
            case 'f':
            case 'g':
            case 'G':
            case 'e':
            case 'E':
                parg_target = (void *)va_arg(arg_ptr, double *);
                if(width && 0 != (parg_target))
                    *((double *)parg_target) = nmea_atof(beg_tok, width);
                break;
            };

            if(parg_target)
                break;
            if(0 == (parg_target = (void *)va_arg(arg_ptr, int *)))
                break;
            if(!width)
                break;

            switch(*format)
            {
            case 'd':
            case 'i':
                snum = nmea_atoi(beg_tok, width, 10);
                memcpy(parg_target, &snum, sizeof(int));
                break;
            case 'u':
                unum = nmea_atoi(beg_tok, width, 10);
                memcpy(parg_target, &unum, sizeof(unsigned int));
                break;
            case 'x':
            case 'X':
                unum = nmea_atoi(beg_tok, width, 16);
                memcpy(parg_target, &unum, sizeof(unsigned int));
                break;
            case 'o':
                unum = nmea_atoi(beg_tok, width, 8);
                memcpy(parg_target, &unum, sizeof(unsigned int));
                break;
            default:
                goto fail;
            };

            break;
        };
    }

fail:

    va_end(arg_ptr);

    return tok_count;
}


#if defined(SF_WRITE_FS)
#include "DateTimeType.h"

#if defined(WIN32)
extern S32 MsgCmd_GetUsableDrive(void);
#endif
#define FILE_BUF_SIZE	5*1024
static S8 log_is_enable = 0;
static U32 max_file_size = 50;
static kal_uint8 file_buffer[FILE_BUF_SIZE]={0};

void WriteLogFile(kal_uint8* buf)
{
	UINT filesize=0;
	UINT LENG=0;
	UINT str_len=0;
	UINT str_len2=0;
	FS_HANDLE file_handle;//文件句柄
	UI_character_type path[20];

	if(buf == NULL) return;
	str_len2 = strlen(buf);
	str_len = strlen(file_buffer);
	if(str_len + str_len2 < FILE_BUF_SIZE)
	{
		strcat(file_buffer, buf);
		str_len += str_len2;
	}
	kal_wsprintf((kal_wchar*)path, "%c:\\hf_log.txt", (S8)MsgCmd_GetUsableDrive());
	file_handle = FS_Open(path,FS_CREATE|FS_READ_WRITE);
	if (file_handle >= FS_NO_ERROR)
	{
		if(FS_GetFileSize(file_handle, &filesize) == FS_NO_ERROR)
		{
			if(filesize > max_file_size*1024)
			{
				FS_Close(file_handle);
				FS_Delete(path);
				WriteLogFile(buf);
				return;
			}
		}
		FS_Seek(file_handle, 0, FS_FILE_END);
		if(FS_Write(file_handle, file_buffer, str_len, &LENG) >= FS_NO_ERROR)
		{
			int sub_len = 0;
			if(LENG < str_len)
			{
				sub_len = str_len - LENG;
				memcpy(file_buffer, file_buffer+LENG, sub_len);
			}
			memset(file_buffer+(sub_len), 0, LENG);
		}
		FS_Close(file_handle);
	}
	
}


void hf_print(char* fmt,...)
{	
	MYTIME time;
	char buf[1024] = {0};
	char time_str[128] = {0};
	va_list MyList;
	
	va_start(MyList,fmt);
	vsprintf(buf, fmt, MyList);
	va_end(MyList);
	
#if defined(WIN32)
	printf("%s\r\n",buf);
#else
	DTGetRTCTime(&time);
	sprintf(time_str, "\t[%d-%d:%d:%d]\n",
		time.nDay,
		time.nHour,
		time.nMin,
		time.nSec);
	strcat(buf,time_str);
	kal_prompt_trace(MOD_ENG,"%s",buf);
	WriteLogFile(buf);
#endif
}

#else
void hf_print(char * fmt,...)
{
	va_list MyList;
	char buf[512];
	va_start(MyList,fmt);
	vsprintf(buf, fmt, MyList);
#ifndef WIN32
	kal_prompt_trace(MOD_ENG,"%s",buf);
#else
	printf("%s\r\n",buf);
#endif
	va_end(MyList);
}
#endif

#endif

