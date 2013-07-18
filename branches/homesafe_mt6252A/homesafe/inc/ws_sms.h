#ifndef __WS_SMS_XXXX__
#define __WS_SMS_XXXX__
#include "ws_port.h"
#include "ws_main.h"

#define HF_MAX_SMS_CONTENT       200
#define HF_MAX_SMS_QUEUE_COUNT	 10

typedef struct _sms_send_queue{

	char send_content[HF_MAX_SMS_QUEUE_COUNT][HF_MAX_SMS_CONTENT];
	
	char send_number[HF_MAX_SMS_QUEUE_COUNT][MAX_PHONENUMBER_LENTH];
	
	signed char   send_index;

}sms_send_queue;

typedef enum _sms_send_statues{

	HF_SMS_SEND_IDLE,
	HF_SMS_SENDING,

	HF_SMS_SEND_END
}ENUM_SEND_STATUE;

typedef struct _hf_sms_struct{

	sms_send_queue	sms_note;
	
	ENUM_SEND_STATUE sms_send_statue;
	

}hf_sms_struct;
#endif
