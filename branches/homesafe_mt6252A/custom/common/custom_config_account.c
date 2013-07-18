/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 * custom_config_account.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends to configure data account.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __TCPIP__

#include "custom_config_account.h"
#include "custom_data_account.h"

#include "kal_non_specific_general_types.h"

#ifndef __DA_MEMORY_CUT__

static const custom_dtcnt_prof_gprs_struct g_config_account_gprs[] = 
{    
    /* CMCC CMWAP */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"China Mobile WAP", /* Account Name */
            "http://wap.monternet.com", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {10, 0, 0, 172},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_VRE_WAP, /* app type */
            "46000, 46002, 46007" /* SIM ID */
        },
        
        (const kal_uint8*)"cmwap"
    }, 

    /* CMCC CMNET */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"China Mobile Internet", /* Account Name */
            "http://wap.monternet.com", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            0,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {0, 0, 0, 0},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_EMAIL | DTCNT_APPTYPE_VRE_NET, /* app type */
            "46000, 46002, 46007" /* SIM ID */
        },

        (const kal_uint8*)"cmnet"
    },

    /* CMCC MMS */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"China Mobile MMS", /* Account Name */
            "http://mmsc.monternet.com", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {10, 0, 0, 172},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_MMS, /* app type */
            "46000, 46002, 46007" /* SIM ID */
        },
        
        (const kal_uint8*)"cmwap"
    }, 
#if defined(__WS_HOME_SAFE__)
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Alands", /* Account Name */
            "http://mms.amt.aland.fi", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {194,110,177,70},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "24414" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.amt.aland.fi"
    }, 
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"DNA", /* Account Name */
            "http://mmsc.dnafinland.fi", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {10,1,1,2},   /* proxy address */
            "dna", "mms",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "24403,24409,24412" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
    }, 
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Elisa", /* Account Name */
            "http://mms.elisa.fi", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {213,161,41,57},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "24401,24405,24421" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
    }, 
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Bouygues", /* Account Name */
            "http://mms.bouyguestelecom.fr/mms/wapenc", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {62,201,137,17},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "20820,20821,20888" /* SIM ID */
        },
        
        (const kal_uint8*)"mmsbouygtel.com"
    }, 
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Orange", /* Account Name */
            "http://mms.orange.fr", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {192,168,10,200},   /* proxy address */
            "orange", "orange",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "20800,20801,20802" /* SIM ID */
        },
        
        (const kal_uint8*)"orange.acte"
    }, 		
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"SFR", /* Account Name */
            "http://mms1", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {10,151,0,1},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "20810,20811,20813" /* SIM ID */
        },
        
        (const kal_uint8*)"mmssfr"
    }, 			
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"E-Plus", /* Account Name */
            "http://mms/eplus", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {212,23,97,153},   /* proxy address */
            "mms", "eplus",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "26203,26205,26277" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.eplus.de"
    }, 
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"O2", /* Account Name */
            "http://10.81.0.7:8002/", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {195,182,114,52},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "26207,26208,26211" /* SIM ID */
        },
        
        (const kal_uint8*)"internet"
    }, 		
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"T-Mobile", /* Account Name */
            "http://mms.t-mobile.de/servlets/mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {172,28,23,131},   /* proxy address */
            "t-mobil", "mms",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "26201" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.t-d1.de"
    }, 		
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"VodaFone", /* Account Name */
            "http://139.7.24.1/servlets/mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {139,7,29,17},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "26202,26204,26209" /* SIM ID */
        },
        
        (const kal_uint8*)"event.vodafone.de"
    }, 	
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Cosmote", /* Account Name */
            "http://195.167.65.220:8002/", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {10,10,10,20},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "20201" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
    }, 		
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Q-Telecom", /* Account Name */
            "http://mms.myq.gr/", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {192,168,80,134},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "20209" /* SIM ID */
        },
        
        (const kal_uint8*)"q-mms.myq.gr"
    }, 
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"TIM", /* Account Name */
            "http://192.168.200.95/servlets/mms/", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {192,168,200,11},   /* proxy address */
            "wap", "wap",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "20210" /* SIM ID */
        },
        
        (const kal_uint8*)"mnet.b-online.gr"
    }, 	
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Vodafone", /* Account Name */
            "http://mms.vodafone.gr/", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {213,249,19,49},   /* proxy address */
            "user", "pass",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "20205" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.vodafone.net"
    }, 
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"CSL", /* Account Name */
            "http://192.168.58.171:8002/", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {192,168,59,51},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "45400,45402,45418" /* SIM ID */
        },
        
        (const kal_uint8*)"hkcsl"
    }, 	
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"New World", /* Account Name */
            "http://mmsc.nwmobility.com:8002/", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {192,168,111,1},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "45410" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
    }, 
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Orange", /* Account Name */
            "http://10.30.15.51:10021/mmsc", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {10,30,15,53},   /* proxy address */
            "orange", "1234",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "45401,45404,45414" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.orangehk.com"
    }, 
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Peoples", /* Account Name */
            "http://mms.peoples.com.hk/mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {172,31,31,36},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "45412" /* SIM ID */
        },
        
        (const kal_uint8*)"peoples.mms"
    }, 	
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"SmartOne", /* Account Name */
            "http://mms.smartone.com.hk/server", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {10,9,9,9},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "45406,45415,45417" /* SIM ID */
        },
        
        (const kal_uint8*)"smartone"
    }, 		
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Sunday", /* Account Name */
            "http://mmsc.mms.Sunday.com:8002/", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {10,131,2,1},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "45416" /* SIM ID */
        },
        
        (const kal_uint8*)"smms"
    }, 		
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"PannonGSM", /* Account Name */
            "http://mmsc.pgsm.hu", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {193,225,154,22},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "21601" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
    }, 		
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"T-Mobile", /* Account Name */
            "http://mms.westel900.net/servlets/mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {12,51,126,10},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "21630" /* SIM ID */
        },
        
        (const kal_uint8*)"mms-westel"
    }, 			
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Vodafone", /* Account Name */
            "http://mms.vodafone.hu/servlets/mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {80,244,97,2},   /* proxy address */
            "mms", "mms",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "21670" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.vodafone.net"
    }, 
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"mizone", /* Account Name */
            "http://mms.bplmobile.com:8080", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {10,0,0,10},   /* proxy address */
            "mms", "mms",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "40443,40446,40427,40421" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.vodafone.net"
    }, 	
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"IM3", /* Account Name */
            "http://mmsc.m3-access.com/", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {10,19,19,19},   /* proxy address */
            "mms", "im3",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "51021" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.indosat-m3.net"
    }, 	
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Telkomsel", /* Account Name */
            "http://mms.telkomsel.com/", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {10,1,89,150},   /* proxy address */
            "wap", "wap123",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "51010" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
    }, 		
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"XL WAP", /* Account Name */
            "http://wap.lifeinhand.com", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {202,152,240,50},   /* proxy address */
            "xlgprs", "proxl",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "51011" /* SIM ID */
        },
        
        (const kal_uint8*)"www.xlgprs.net"
    }, 	
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"three wap", /* Account Name */
            "http://wap.three.co.id", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,4,0,10},   /* proxy address */
            "3gprs", "3gprs",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_VRE_WAP, /* app type */
            "51089" /* SIM ID */
        },
        
        (const kal_uint8*)"3gprs"
    }
 #endif
};


static const custom_dtcnt_prof_csd_struct g_config_account_csd[] = 
{
    /* CMCC WAP */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"China Mobile CSD", /* Account Name */
            "http://wap.monternet.com", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "wap", "wap"  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {10, 0, 0, 172},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP, /* app type */
            "46000, 46002, 46007" /* SIM ID */
        },

        (const kal_uint8*)"17266",     /* CSD profile dial number(ASCII) */
        CUSTOM_DTCNT_PROF_CSD_DIAL_TYPE_ANALOGUE,   /* CSD dial type */
        CUSTOM_DTCNT_PROF_CSD_RATE_NINE_SIX         /* CSD data rate */
    },

    /* CMCC MMS */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"China Mobile CSD MMS", /* Account Name */
            "http://mmsc.monternet.com", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "wap", "wap"  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {10, 0, 0, 172},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_MMS, /* app type */
            "46000, 46002, 46007" /* SIM ID */
        },

        (const kal_uint8*)"17266",     /* CSD profile dial number(ASCII) */
        CUSTOM_DTCNT_PROF_CSD_DIAL_TYPE_ANALOGUE,   /* CSD dial type */
        CUSTOM_DTCNT_PROF_CSD_RATE_NINE_SIX         /* CSD data rate */
    },

    /* CHT WAP */
    {
        {
            0,  0,
                CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
                CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
                (const kal_uint8*)L"CHT CSD", /* Account Name */
                "http://wap.monternet.com", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                    "", ""  /* username, password */
            },
            0,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
                {10, 1, 1, 1},   /* proxy address */
                "", "",  /* proxy username, password */
                "", "", "", "", "", "",
                DTCNT_APPTYPE_BRW_HTTP, /* app type */
                "46692" /* SIM ID */
        },
        
        (const kal_uint8*)"0933000369",     /* CSD profile dial number(ASCII) */
        CUSTOM_DTCNT_PROF_CSD_DIAL_TYPE_ISDN,  /* CSD dial type */
        CUSTOM_DTCNT_PROF_CSD_RATE_NINE_SIX    /* CSD data rate */
    },

    /* CHT MMS */
    {
        {
            0,  0,
                CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
                CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
                (const kal_uint8*)L"CHT CSD MMS", /* Account Name */
                "http://mms.emome.net:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                    "", ""  /* username, password */
            },
            0,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
                {10, 1, 1, 1},   /* proxy address */
                "", "",  /* proxy username, password */
                "", "", "", "", "", "",
                DTCNT_APPTYPE_MMS, /* app type */
                "46692" /* SIM ID */
        },
        
        (const kal_uint8*)"0933000369",     /* CSD profile dial number(ASCII) */
        CUSTOM_DTCNT_PROF_CSD_DIAL_TYPE_ISDN,  /* CSD dial type */
        CUSTOM_DTCNT_PROF_CSD_RATE_NINE_SIX    /* CSD data rate */
    },
    
    /* FET */
    {
        {
            0,  0,
                CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
                CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
                (const kal_uint8*)L"FET CSD", /* Account Name */
                "http://mobile.fetnet.net", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                    "", ""  /* username, password */
            },
            0,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
                {210, 241, 199, 199},   /* proxy address */
                "", "",  /* proxy username, password */
                "", "", "", "", "", "",
                DTCNT_APPTYPE_BRW_HTTP, /* app type */
                "46601" /* SIM ID */
        },
        
        (const kal_uint8*)"0936010010",     /* CSD profile dial number(ASCII) */
        CUSTOM_DTCNT_PROF_CSD_DIAL_TYPE_ISDN,  /* CSD dial type */
        CUSTOM_DTCNT_PROF_CSD_RATE_NINE_SIX    /* CSD data rate */
    },

    /* FET MMS */
    {
        {
            0,  0,
                CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
                CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
                (const kal_uint8*)L"FET CSD MMS", /* Account Name */
                "http://mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                    "", ""  /* username, password */
            },
            0,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
                {210, 241, 199, 199},   /* proxy address */
                "", "",  /* proxy username, password */
                "", "", "", "", "", "",
                DTCNT_APPTYPE_MMS, /* app type */
                "46601" /* SIM ID */
        },
        
        (const kal_uint8*)"0936010010",     /* CSD profile dial number(ASCII) */
        CUSTOM_DTCNT_PROF_CSD_DIAL_TYPE_ISDN,  /* CSD dial type */
        CUSTOM_DTCNT_PROF_CSD_RATE_NINE_SIX    /* CSD data rate */
    },

    /* TWN */
    {
        {
            0,  0,
                CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
                CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
                (const kal_uint8*)L"TWN CSD", /* Account Name */
                "http://ewap", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                    "", ""  /* username, password */
            },
            0,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
                {10, 1, 1, 1},   /* proxy address */
                "", "",  /* proxy username, password */
                "", "", "", "", "", "",
                DTCNT_APPTYPE_BRW_HTTP, /* app type */
                "46697" /* SIM ID */
        },
        
        (const kal_uint8*)"0935120120",     /* CSD profile dial number(ASCII) */
        CUSTOM_DTCNT_PROF_CSD_DIAL_TYPE_ISDN,  /* CSD dial type */
        CUSTOM_DTCNT_PROF_CSD_RATE_NINE_SIX    /* CSD data rate */
    },

    /* TWN */
    {
        {
            0,  0,
                CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
                CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
                (const kal_uint8*)L"TWN CSD MMS", /* Account Name */
                "http://mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                    "", ""  /* username, password */
            },
            0,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
                {10, 1, 1, 1},   /* proxy address */
                "", "",  /* proxy username, password */
                "", "", "", "", "", "",
                DTCNT_APPTYPE_MMS, /* app type */
                "46697" /* SIM ID */
        },
        
        (const kal_uint8*)"0935120120",     /* CSD profile dial number(ASCII) */
        CUSTOM_DTCNT_PROF_CSD_DIAL_TYPE_ISDN,  /* CSD dial type */
        CUSTOM_DTCNT_PROF_CSD_RATE_NINE_SIX    /* CSD data rate */
    },
    
    /* TAT */
    {
        {
            0,  0,
                CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
                CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
                (const kal_uint8*)L"TAT CSD", /* Account Name */
                "", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                    "", ""  /* username, password */
            },
            0,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
                {0, 0, 0, 0},   /* proxy address */
                "", "",  /* proxy username, password */
                "", "", "", "", "", "",
                DTCNT_APPTYPE_NONE, /* app type */
                "46699" /* SIM ID */
        },
        
        (const kal_uint8*)"0931777777",     /* CSD profile dial number(ASCII) */
        CUSTOM_DTCNT_PROF_CSD_DIAL_TYPE_ISDN,  /* CSD dial type */
        CUSTOM_DTCNT_PROF_CSD_RATE_NINE_SIX    /* CSD data rate */
    }                
};


#define CUSTOM_TABLE_SIZE(a)    sizeof(a)/sizeof(a[0])


/*****************************************************************************
 * FUNCTION
 *  custom_config_get_gprs_account
 * DESCRIPTION
 *  get gprs bearer account
 * PARAMETERS
 *  type    [IN]   bearer type
 * RETURNS
 *  void * return account information on success, otherwise NULL.
 *****************************************************************************/
static void *custom_config_get_gprs_account(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static kal_int32 gprs_num = 0;
    kal_int32 max_size = CUSTOM_TABLE_SIZE(g_config_account_gprs);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gprs_num < max_size)
    {
        return (void*)&g_config_account_gprs[gprs_num++];
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  custom_config_get_csd_account
 * DESCRIPTION
 *  get csd bearer account
 * PARAMETERS
 *  type    [IN]   bearer type
 * RETURNS
 *  void * return account information on success, otherwise NULL.
 *****************************************************************************/
static void *custom_config_get_csd_account(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static kal_int32 csd_num = 0;
    kal_int32 max_size = CUSTOM_TABLE_SIZE(g_config_account_csd);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    if (csd_num < max_size)
    {
        return (void*)&g_config_account_csd[csd_num++];
    }
    
    return NULL;    
}


#endif  //__DA_MEMORY_CUT__

/*****************************************************************************
 * FUNCTION
 *  custom_config_get_account
 * DESCRIPTION
 *  get bearer account
 * PARAMETERS
 *  type    [IN]   bearer type
 * RETURNS
 *  void * return account information on success, otherwise NULL.
 *****************************************************************************/
void *custom_config_get_account(kal_int32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DA_MEMORY_CUT__
    return NULL;
#else
    if (type == CUSTOM_DATA_ACCOUNT_BEARER_GPRS)
    {
        return custom_config_get_gprs_account();
    }

    return custom_config_get_csd_account();
#endif
}

#endif /* __TCPIP__ */ 



