#ifndef __DLJFSLDJFOELDSDF__
#define __DLJFSLDJFOELDSDF__
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



extern int hf_scanf(const char *buff, int buff_sz, const char *format, ...);
extern void hf_print(char* fmt,...);

#if defined(__MSGCMD_SUPPORT__)
#ifndef mc_trace
#define mc_trace hf_print
#endif
#endif

#endif
