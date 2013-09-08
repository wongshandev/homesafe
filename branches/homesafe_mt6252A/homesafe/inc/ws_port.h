#ifndef __DLJFSLDJFOELDSDF__
#define __DLJFSLDJFOELDSDF__

//ฑ๊สถ   __WS_HOME_SAFE__  


#include "MMI_include.h"
#include "Nvram_user_defs.h"
#include "conversions.h"
#include "task_main_func.h"
#include "app_ltlcom.h"
#include "task_config.h"
#include "syscomp_config.h"
#include "custom_util.h"
#include "stack_ltlcom.h"
#include "kal_non_specific_general_types.h"
#include "stack_config.h"
#include "custom_config.h"
#include "stack_timer.h"
#include "custom_config.h"
#include "med_utility.h"
#include "profilessrvgprot.h"
#include "DateTimeType.h"
#include "mmi_rp_srv_prof_def.h"
#include "gpiosrvgprot.h"
#include "mdi_audio.h"
#include "aud_defs.h"
#include "mmi_rp_app_charger_def.h"
#include "GeneralDeviceGprot.h"
#include "TimerEvents.h"



extern int hf_scanf(const char *buff, int buff_sz, const char *format, ...);
extern void hf_print(char* fmt,...);
extern char * str_big_to_low(char * _data);
extern void hf_write_nvram(void);
extern void hf_read_nvram(void);
extern void hf_send_sms_req(const char * _number, const char* content);
extern void hf_sms_init(void);
extern kal_uint8 hf_get_signal_changed(void);
extern MMI_BOOL mmi_idle_is_active(void);
extern void hf_main_init(void);
extern pBOOL mmi_bootup_is_network_service_available(void);
extern BOOL hf_is_vaild_service(void);
extern void mmi_ucm_outgoing_call_endkey(void);
extern BOOL hf_is_incoming_call;
#if defined(__MSGCMD_SUPPORT__)
#ifndef mc_trace
#define mc_trace hf_print
#endif
#endif

#endif
