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

/* Argentina */
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Movistar", /* Account Name */
            "http://mms.movistar.com.ar", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {200,68,32,239},   /* proxy address */
            "mms", "mms",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "722010,722070" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.gprs.unifon.com.ar"
    }, 
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Personal", /* Account Name */
            "http://172.25.7.31", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {172,25,7,31},   /* proxy address */
            "mms", "mms",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "722340" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
    }, 

/* Australia */
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Optus", /* Account Name */
            "http://mmsc.optus.com.au:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8070, /* proxy port */
            {61,88,190,10},   /* proxy address */
            "411", "optus",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "50502" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
    }, 
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Telstra", /* Account Name */
            "http://10.0.3.70:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {10,1,1,180},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "50501" /* SIM ID */
        },
        
        (const kal_uint8*)"telstra.mms"
    }, 
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Vodafone", /* Account Name */
            "http://pxt.vodafone.net.au/pxtsend", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,202,2,60},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "50503" /* SIM ID */
        },
        
        (const kal_uint8*)"live.vodafone.com"
    }, 

/* Austria */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"A1 (MobilKom)", /* Account Name */
            "http://mmsc.a1.net", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8001, /* proxy port */
            {194,48,125,71},   /* proxy address */
            "ppp@A1plus.at", "ppp",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "23201,23209,23211" /* SIM ID */
        },
        
        (const kal_uint8*)"A1.net"
    }, 
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"One", /* Account Name */
            "http://mmsc.one.at/mms/wapenc", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {194,24,128,118},   /* proxy address */
            "wap", "wap",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "23205" /* SIM ID */
        },
        
        (const kal_uint8*)"web.one.at"
    }, 
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Tele Ring", /* Account Name */
            "http://relay.mms.telering.at", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {212,95,31,50},   /* proxy address */
            "wap@telering.at", "wap",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "23207" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
    }, 
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"T-Mobile", /* Account Name */
            "http://mmsc.t-mobile.at/servlets/mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {10,12,0,2},   /* proxy address */
            "wap", "wap",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "23203" /* SIM ID */
        },
        
        (const kal_uint8*)"gprsinternet"
    }, 

/* Belgium */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Base", /* Account Name */
            "http://mmsc.base.be", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {217,72,235,1},   /* proxy address */
            "base", "base",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "20620" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.base.be"
    }, 
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Mobistar", /* Account Name */
            "http://mmsc.mobistar.be", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {212,65,63,143},   /* proxy address */
            "mobistar", "mobistar",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "20610" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.be"
    }, 
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Proximus", /* Account Name */
            "http://mmsc.proximus.be/mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,55,14,75},   /* proxy address */
            "mms", "mms",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "20601" /* SIM ID */
        },
        
        (const kal_uint8*)"event.proximus.be"
    }, 

/* Brazil */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Brazil Telecom", /* Account Name */
            "http://mms.brasiltelecom.com.br", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {200,96,8,29},   /* proxy address */
            "brt", "brt",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "72416" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.brt.br"
    }, 
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Claro", /* Account Name */
            "http://mms.claro.com.br", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {200,169,126,10},   /* proxy address */
            "claro", "claro",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "72405" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.claro.com.br"
    }, 
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"CTBC", /* Account Name */
            "http://mms.ctbccelular.com.br/was", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {172,29,7,70},   /* proxy address */
            "ctbc", "1212",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "72415,72432,72433,72434" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.ctbc.br"
    }, 
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Oi (TNL PCS)", /* Account Name */
            "http://200.222.42.204:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {192,168,10,50},   /* proxy address */
            "oimms", "oioioi",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "72431" /* SIM ID */
        },
        
        (const kal_uint8*)"mmsgprs.oi.com.br"
    }, 
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"TIM", /* Account Name */
            "http://mms.tim.br/servlets/mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {200,179,66,242},   /* proxy address */
            "tim", "tim",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "72402,72403,72404,72408" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.tim.br"
    }, 
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"VIVO", /* Account Name */
            "http://termnat.vivomms.com.br:8088/mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {200,142,130,104},   /* proxy address */
            "vivo", "vivo",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "72406,72410,72411,72423" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.vivo.com.br"
    }, 

/* Brunei */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"DST", /* Account Name */
            "http://mms.dst.com.bn/mmsc", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,100,6,101},   /* proxy address */
            "mms", "mms",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "52811" /* SIM ID */
        },
        
        (const kal_uint8*)"dst.mms"
    }, 

/* Bulgaria */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Globul", /* Account Name */
            "http://mmsc1.mms.globul.bg:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {192,168,87,11},   /* proxy address */
            "mms", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "28405" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.globul.bg"
    }, 
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Mtel", /* Account Name */
            "http://mmsc", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,150,0,33},   /* proxy address */
            "mtel", "mtel",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "28401" /* SIM ID */
        },
        
        (const kal_uint8*)"mms-gprs.mtel.bg"
    }, 
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Vivacom", /* Account Name */
            "http://mms.vivacom.bg", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {192,168,123,123},   /* proxy address */
            "mms", "mms",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "28403" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.vivacom.bg"
    }, 

/* Canada */
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Fido", /* Account Name */
            "http://mms.fido.ca", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {205,151,11,13},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "302370" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.fido.ca"
    }, 
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Bell", /* Account Name */
            "http://mms.bell.ca/mms/wapenc", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {1,1,1,1},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "302610,302690,302880" /* SIM ID */
        },
        
        (const kal_uint8*)"pda.bell.ca"
    }, 
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Rogers", /* Account Name */
            "http://mms.gprs.rogers.com", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {172,25,0,107},   /* proxy address */
            "media", "mda01",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "302720" /* SIM ID */
        },
        
        (const kal_uint8*)"media.com"
    }, 

/* Chile */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Entel PCS", /* Account Name */
            "http://mmsc.entelpcs.cl", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,99,0,10},   /* proxy address */
            "entelmms", "entelpcs",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "73001" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.entelpcs.cl"
    }, 
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Telefonica", /* Account Name */
            "http://mms.tmovil.ch", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {172,17,8,11},   /* proxy address */
            "mms", "mms",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "73002" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.tmovil.cl"
    }, 

/* Colombia */
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"movistar", /* Account Name */
            "http://mms.movistar.com.co", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            9001, /* proxy port */
            {192,168,222,7},   /* proxy address */
            "movistar", "movistar",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "732102" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.movistar.com.co"
    }, 
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Tigo", /* Account Name */
            "http://mms.tigo.com.co", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {200,58,228,81},   /* proxy address */
            "mms-cm1900", "mms-cm1900",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "732103,732111" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.colombiamovil.com.co"
    }, 

/* Croatia */
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"VIPNet", /* Account Name */
            "http://mms.vipnet.hr/servlets/mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {212,91,99,91},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "21910" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.vipnet.hr"
    }, 

/* Cyprus */
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Areeba", /* Account Name */
            "http://mms.areeba.com.cy/mmsc", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {172,24,97,1},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "28010" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.areeba.com.cy"
    }, 
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"CytaMobile VodaFone", /* Account Name */
            "http://mmsc.cyta.com.cy", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {212,31,96,161},   /* proxy address */
            "user", "pass",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "28001" /* SIM ID */
        },
        
        (const kal_uint8*)"cytamobile"
    }, 
/* Czech Republic */
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Eurotel", /* Account Name */
            "http://mms.eurotel.cz:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {160,218,160,218},   /* proxy address */
            "mms", "mms",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "23002" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
    }, 
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"T-Mobile", /* Account Name */
            "http://mms", /* Home page */
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
            "23001" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.t-mobile.cz"
    }, 
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Vodafone", /* Account Name */
            "http://mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {10,11,10,111},   /* proxy address */
            "mms", "mms",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "23003,23099" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
    }, 

/* Denmark */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Sonofon", /* Account Name */
            "http://mms.sonofon.dk", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {212,88,64,8},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "23802" /* SIM ID */
        },
        
        (const kal_uint8*)"sonofon"
    }, 
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"TDC", /* Account Name */
            "http://192.168.241.114:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {194,182,251,15},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "23801" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Telia", /* Account Name */
            "http://mms.telia.dk", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {193,209,134,131},   /* proxy address */
            "telia", "1010",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "23820,23830" /* SIM ID */
        },
        
        (const kal_uint8*)"www.mms.telia.dk"
    },

/* Dominica */
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Lime", /* Account Name */
            "http://mmsc", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8799, /* proxy port */
            {10,20,5,34},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "366110" /* SIM ID */
        },
        
        (const kal_uint8*)"internet"
    },

/* Egypt */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"MobilNil", /* Account Name */
            "http://10.7.13.24:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {62,241,155,45},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "60201" /* SIM ID */
        },
        
        (const kal_uint8*)"Mobinilmms"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Vodafone", /* Account Name */
            "http://mms.vodafone.com.eg/servlets/mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {163,121,178,2},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "60202" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.vodafone.com.eg"
    },

/* Estonia */

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
            "24802" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
    },

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"EMT", /* Account Name */
            "http://mms.emt.ee/servlets/mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {217,71,32,82},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "24801" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.emt.ee"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Tele 2", /* Account Name */
            "http://mmsc.tele2.ee", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {193,12,40,6},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "24803" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.tele2.ee"
    },

/* Fiji */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Digicel", /* Account Name */
            "http://mms.digicelpacific.com:8990", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,150,122,12},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "54202" /* SIM ID */
        },
        
        (const kal_uint8*)"wap.digicelpacific.com"
    }, 

/* Finland */
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
            8080, /* proxy port */
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
            8080, /* proxy port */
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
            8080, /* proxy port */
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
            (const kal_uint8*)L"Sonera", /* Account Name */
            "http://mms.sonera.fi:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {195,156,25,33},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "24491" /* SIM ID */
        },
        
        (const kal_uint8*)"wap.sonera.net"
    }, 


/* France */
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
            8080, /* proxy port */
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
            8080, /* proxy port */
            {192,168,10,200},   /* proxy address */
            "orange", "orange",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "20801,20802" /* SIM ID */
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
            8080, /* proxy port */
            {10,151,0,1},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "20810,20811,20813" /* SIM ID */
        },
        
        (const kal_uint8*)"mmssfr"
    },

/* Germany */	
	
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
            8080, /* proxy port */
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
            "http://10,81,0,7:8002/", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
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
            8008, /* proxy port */
            {172,28,23,131},   /* proxy address */
            "t-mobil", "mms",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "26201,26206" /* SIM ID */
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
            8080, /* proxy port */
            {139,7,29,17},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "26202,26204,26209" /* SIM ID */
        },
        
        (const kal_uint8*)"event.vodafone.de"
    }, 	

/* Greece */	

    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Cosmote", /* Account Name */
            "http://195.167.65.220:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
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
            8080, /* proxy port */
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
            "http://192.168.200.95/servlets/mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
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
            8080, /* proxy port */
            {213,249,19,49},   /* proxy address */
            "user", "pass",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "20205" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.vodafone.net"
    }, 

/* Hong Kong */	

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
            8080, /* proxy port */
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
            "http://mmsc.nwmobility.com:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
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
            8080, /* proxy port */
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
            8080, /* proxy port */
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
            8080, /* proxy port */
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
            "http://mmsc.mms.Sunday.com:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,131,2,1},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "45416" /* SIM ID */
        },
        
        (const kal_uint8*)"smms"
    }, 	

/* Hungary */		

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
            8080, /* proxy port */
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
            8080, /* proxy port */
            {212,51,126,10},   /* proxy address */
            "mms", "mms",  /* proxy username, password */
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
            8080, /* proxy port */
            {80,244,97,2},   /* proxy address */
            "mms", "mms",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "21670" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.vodafone.net"
    }, 

/* India */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Airtel", /* Account Name */
            "http://100.1.201.171:10021/mmsc", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {100,1,201,172},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */            "40402,40403,40410,40416,40440,40441,40442,40445,40449,40470,40490,40492,40493,40494,40495,40496,40497,40498,40551,40552,40553,40554,40555,40556" /* SIM ID */
        },
        
        (const kal_uint8*)"airtelmms.com"
    }, 	
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"BPL", /* Account Name */
            "http://mms.bplmobile.com:8080", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,0,0,10},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */            "40421,405854,405855,405856,405857,405858,405859,405860,405861,405862,405863,405864,405865,405867,405868,405869,405870,405871,405872,405873,405874" /* SIM ID */
        },
        
        (const kal_uint8*)"mizone"
    }, 	
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"CellOne", /* Account Name */
            "http://10.31.53.18/mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,31,54,2},   /* proxy address */
            "ppp", "ppp123",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */            "40434,40438,40451,40453,40454,40455,40457,40458,40459,40462,40464,40466,40471,40472,40473,40474,40475,40476,40477,40479,40480,40481" /* SIM ID */
        },
        
        (const kal_uint8*)"bsnlmms"
    }, 	
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Idea", /* Account Name */
            "http://10.4.42.21:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,4,42,15},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */            "405845,405846,405847,405848,405849,405850,405851,405852,405853,405908,405909,405910,405911" /* SIM ID */
        },
        
        (const kal_uint8*)"mmsc"
    }, 	
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"VodaFone", /* Account Name */
            "http://mms1.live.vodafone.in/mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,10,1,100},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */            "40401,40405,40411,40413,40415,40420,40427,40430,40443,40446,40460,40484,40486,40488,40566,405750,405751,405752,405753,405754,405755,405756" /* SIM ID */
        },
        
        (const kal_uint8*)"portalnmms"
    },

/* Indonesia */

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
            8080, /* proxy port */
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
            8080, /* proxy port */
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
    },
/* Ireland */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Meteor", /* Account Name */
            "http://mms.mymeteor.ie", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8799, /* proxy port */
            {10,85,85,85},   /* proxy address */
            "my", "mms",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "27203" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.mymeteor.ie"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"O2", /* Account Name */
            "http://mmsc.mms.o2.ie:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {62,40,32,40},   /* proxy address */
            "gprs", "gprs",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "27202" /* SIM ID */
        },
        
        (const kal_uint8*)"wap.dol.ie"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Vodafone", /* Account Name */
            "http://www.vodafone.ie/mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {10,24,59,200},   /* proxy address */
            "dublin", "dublin",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "27201" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.vodafone.net"
    },

/* Israel */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Orange", /* Account Name */
            "http://192.168.220.15/servlets/mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {192,118,11,55},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "42501" /* SIM ID */
        },
        
        (const kal_uint8*)"wap.orange.co.il"
    },

/* Italy */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"TIM", /* Account Name */
            "http://mms.tim.it/servlets/mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {213,230,130,89},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "22201" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.tim.it"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Vodafone", /* Account Name */
            "http://mms.vodafone.it/servlets/mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,128,224,10},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "22201" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.vodafone.it"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Wind", /* Account Name */
            "http://mms.wind.it", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {212,245,244,11},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "22288" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.wind"
    },

/* Jamaica */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Cable and Wireless", /* Account Name */
            "http://mmsc", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,20,5,34},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "338020,338180" /* SIM ID */
        },
        
        (const kal_uint8*)"internet"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Digicell", /* Account Name */
            "http://mmc.digiceljamaica.com/servlets/mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {172,16,7,12},   /* proxy address */
            "wapuser", "wap03jam",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "33850" /* SIM ID */
        },
        
        (const kal_uint8*)"wap.digiceljamaica.com"
    },

/* Jordan */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"MobileCom", /* Account Name */
            "http://172.16.1.96/servlets/mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {172,16,1,2},   /* proxy address */
            "mms", "mms",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "41677" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.mobilecom.jo"
    },

/* Kazakhstan */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Kcell", /* Account Name */
            "http://192.168.75.10:6001/MM1Servlet", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {195,47,255,15},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "40102" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
    },

/* Kenya */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Safaricom", /* Account Name */
            "http://mms.gprs.safaricom.com", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {172,22,2,38},   /* proxy address */
            "saf", "data",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "63902" /* SIM ID */
        },
        
        (const kal_uint8*)"safaricom"
    },

/* Kuwait */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"MTC", /* Account Name */
            "http://176.0.0.1", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {176,0,0,65},   /* proxy address */
            "annyway", "online",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "41902" /* SIM ID */
        },
        
        (const kal_uint8*)"pps"
    },

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Wataniya", /* Account Name */
            "http://action.wataniya.com", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {194,126,53,64},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "41903" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.wataniya.com"
    },

/* Liechtenstein */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"MobilKom", /* Account Name */
            "http://mmsc.a1.net", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {194,48,124,71},   /* proxy address */
            "ppp@a1plus.at", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "29505" /* SIM ID */
        },
        
        (const kal_uint8*)"free.fl1.net"
    },

/* Lithuania */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Omnitel", /* Account Name */
            "http://mms:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,16,35,50},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "24601" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.omnitel.net"
    },

/* Luxembourg */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Tango", /* Account Name */
            "http://mms.tango.lu", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {212,66,75,3},   /* proxy address */
            "tango", "tango",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "27077" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"VOX", /* Account Name */
            "http://mms.vox.lu", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {212,88,139,44},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "27099" /* SIM ID */
        },
        
        (const kal_uint8*)"vox.lu"
    },

/* Macedonia */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Cosmofon", /* Account Name */
            "http://195.167.65.220:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,10,10,20},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "29402" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
    },

/* Malaysia */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Celcom", /* Account Name */
            "http://mms.celcom.net.my", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,128,1,242},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "50213,50219" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.celcom.net.my"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"DiGi", /* Account Name */
            "http://mms.digi.com.my/servlets/mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {203,92,128,160},   /* proxy address */
            "mms", "mms",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "50216" /* SIM ID */
        },
        
        (const kal_uint8*)"digimms"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Maxis", /* Account Name */
            "http://172.16.74.100:10021/mmsc", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {202,75,133,49},   /* proxy address */
            "maxis", "wap",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "50212" /* SIM ID */
        },
        
        (const kal_uint8*)"net"
    },

/* Malta */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Vodafone", /* Account Name */
            "http://mms.vodafone.com.mt/servlets/mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,12,0,3},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "27801" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.vodafone.com.mt"
    },

/* Mexico */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Telcel", /* Account Name */
            "http://mms.itelcel.com/servlets/mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {148,233,151,240},   /* proxy address */
            "mmsgprs", "mmsgprs2003",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "334020" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.itelcel.com"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Movistar", /* Account Name */
            "http://mms.movistar.mx", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,2,20,1},   /* proxy address */
            "movistar", "movistar",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "334030" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.movistar.mx"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Iusacell", /* Account Name */
            "http://mms.iusacell3g.com", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {192,200,1,110},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "334040,334050" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.iusacell3g.mx"
    },

/* Moldova */
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"MoldCell", /* Account Name */
            "http://mms.moldcell.md/cmmsc/post", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,0,10,10},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "25902" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
    },

/* Morocco */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"IAM", /* Account Name */
            "http://mms:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,16,35,50},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "60401" /* SIM ID */
        },
        
        (const kal_uint8*)"mmsiam"
    },

/* Nepal */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Mero Mobile", /* Account Name */
            "http://192.168.29.9", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {192,168,29,9},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "42901" /* SIM ID */
        },
        
        (const kal_uint8*)"mero"
    },

/* Netherlands */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"KPN", /* Account Name */
            "http://mp.mobiel.kpn/mmsc", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            5080, /* proxy port */
            {10,10,100,20},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "20408" /* SIM ID */
        },
        
        (const kal_uint8*)"portalmmm.nl"
    },

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Telfort", /* Account Name */
            "http://mmsc.mms.telfort.nl:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {193,113,200,195},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "20412" /* SIM ID */
        },
        
        (const kal_uint8*)"multimedia"
    },

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"T-Mobile", /* Account Name */
            "http://t-mobilemms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,10,10,11},   /* proxy address */
            "tmobilemms", "tmobilemms",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "20416" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Vodafone", /* Account Name */
            "http://mmsc.mms.vodafone.nl", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8799, /* proxy port */
            {192,168,251,150},   /* proxy address */
            "vodafone", "vodafone",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "20404" /* SIM ID */
        },
        
        (const kal_uint8*)"live.vodafone.com"
    },

/* New Zealand */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Vodafone", /* Account Name */
            "http://pxt.vodafone.net.nz/pxtsend", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {172,30,38,3},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "53001" /* SIM ID */
        },
        
        (const kal_uint8*)"live.vodafone.com"
    },

/* Nigeria */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Globacom", /* Account Name */
            "http://mms.gloworld.com/mmsc", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,100,82,4},   /* proxy address */
            "mms", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "62150" /* SIM ID */
        },
        
        (const kal_uint8*)"glomms"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"MTN", /* Account Name */
            "http://10.199.212.8/servlets/mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,199,212,2},   /* proxy address */
            "web", "web",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "62130" /* SIM ID */
        },
        
        (const kal_uint8*)"web.gprs.mtnnigeria.net"
    },

/* Norway */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Netcom", /* Account Name */
            "http://mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {193,209,134,133},   /* proxy address */
            "mms", "netcom",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "24202" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.netcom.no"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Telenor", /* Account Name */
            "http://mmsc", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,10,10,11},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "24201" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
    },

/* Oman */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Nawras", /* Account Name */
            "http://10.128.240.16/servlets/mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,128,240,16},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "42203" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.nawras.com.om"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Oman Mobile", /* Account Name */
            "http://mmsc.omanmobile.om:10021/mmsc", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {192,168,203,35},   /* proxy address */
            "mms", "mms",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "42202" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
    },

/* Pakistan */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Telenor", /* Account Name */
            "http://mmstelenor", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {172,18,19,11},   /* proxy address */
            "telenor", "telenor",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "41006" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Ufone", /* Account Name */
            "http://www.ufonemms.com:80/alias=PP", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {172,16,13,27},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "41003" /* SIM ID */
        },
        
        (const kal_uint8*)"ufone.mms"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Warid", /* Account Name */
            "http://10.4.0.132/servlets/mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,4,2,1},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "41007" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.warid"
    },

/* Panama */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Cable and Wireless", /* Account Name */
            "http://mms.zonamovil.com.pa:80/i.bin", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {172,25,3,5},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "71401" /* SIM ID */
        },
        
        (const kal_uint8*)"apn01.cwpanama.com.pa"
    },

/* Philippines */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Digitell", /* Account Name */
            "http://mmscenter.suncellular.com.ph", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {202,138,159,78},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "51511,51513,51527,51530,51543,51584,51586,515752,515753,51505" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Globe Telecom", /* Account Name */
            "http://192.40.100.22:10021/mmsc", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {192,40,100,20},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "51502" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.globe.com.ph"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Smart", /* Account Name */
            "http://10.102.61.238:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,102,61,46},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "51503" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
    },

/* Poland */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"ERA", /* Account Name */
            "http://mms.era.pl/servlets/mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {213,158,194,226},   /* proxy address */
            "eramms", "eramms",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "26002" /* SIM ID */
        },
        
        (const kal_uint8*)"eramms"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Heyah", /* Account Name */
            "http://mms.heyah.pl/servlets/mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {213,158,194,226},   /* proxy address */
            "heyah", "heyah",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "26002" /* SIM ID */
        },
        
        (const kal_uint8*)"heyahmms"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Idea", /* Account Name */
            "http://192.168.6.104", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {192,168,6,104},   /* proxy address */
            "idea", "idea",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "26003" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Orange", /* Account Name */
            "http://mms.orange.pl", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {192,168,6,104},   /* proxy address */
            "mms", "mms",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "26003" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Play", /* Account Name */
            "http://10.10.28.164/mms/wapenc", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,10,25,5},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "26006" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Plus GSM", /* Account Name */
            "http://mms.plusgsm.pl:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {212,2,96,16},   /* proxy address */
            "brak", "brak",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "26001" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.plusgsm.pl"
    },

/* Portugal */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Optimus", /* Account Name */
            "http://mmsc:10021/mmsc", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8799, /* proxy port */
            {62,169,66,1},   /* proxy address */
            "mms", "mms",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "26803" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"TMN", /* Account Name */
            "http://mmsc", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,111,2,16},   /* proxy address */
            "tmn", "tmnnet",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "26806" /* SIM ID */
        },
        
        (const kal_uint8*)"mmsc.tmn.pt"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Vodafone", /* Account Name */
            "http://mms/servlets/mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8799, /* proxy port */
            {172,16,19,50},   /* proxy address */
            "vas", "vas",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "26801" /* SIM ID */
        },
        
        (const kal_uint8*)"vas.vodafone.pt"
    },

/* Qatar */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Qtel", /* Account Name */
            "http://mmsr.qtelmms.qa", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,23,8,3},   /* proxy address */
            "mms", "mms",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "42701" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.qtel"
    },

/* Romania */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Connex-Vodafone", /* Account Name */
            "http://multimedia/servlets/mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {193,230,161,231},   /* proxy address */
            "mms.vodafone.ro", "connex",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "22601" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.connex.ro"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Orange", /* Account Name */
            "http://wap.mms.orange.ro:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {62,217,247,252},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "22610" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
    },

/* Russia */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Beeline", /* Account Name */
            "http://192.168.17.7/servlets/mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {192,168,94,23},   /* proxy address */
            "beeline", "beeline",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "25099" /* SIM ID */
        },
        
        (const kal_uint8*)"wap.beeline.ru"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Megafon", /* Account Name */
            "http://mmsc:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,10,10,10},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "25002" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Motiv", /* Account Name */
            "http://mms.ycc.ru", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {172,16,2,10},   /* proxy address */
            "motiv", "motiv",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "25035" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.ycc.ru"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Smarts", /* Account Name */
            "http://172.24.120.135/mms/wapenc", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {172,24,121,5},   /* proxy address */
            "wap", "wap",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "25007" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.smarts.ru"
    },

/* Saudi Arabia */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"STC", /* Account Name */
            "http://mms.net.sa:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,1,1,1},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "42001,42004,42003" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.net.sa"
    },

/* Singapore */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"M1", /* Account Name */
            "http://mmsgw:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {172,16,14,10},   /* proxy address */
            "65", "user123",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "52503" /* SIM ID */
        },
        
        (const kal_uint8*)"miworld"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"SingTel", /* Account Name */
            "http://mms.e-ideas.com.sg:10021/mmsc", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {165,21,42,84},   /* proxy address */
            "65eideas", "eideas",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "52501" /* SIM ID */
        },
        
        (const kal_uint8*)"e-ideas"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Starhub", /* Account Name */
            "http://mms.starhubgee.com.sg:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,12,1,80},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "52505" /* SIM ID */
        },
        
        (const kal_uint8*)"shmms"
    },

/* Slovakia */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"O2", /* Account Name */
            "http://mms.o2world.sk:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,97,1,11},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "23106" /* SIM ID */
        },
        
        (const kal_uint8*)"o2mms"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Orange", /* Account Name */
            "http://imms.orange.sk", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8799, /* proxy port */
            {213,151,208,145},   /* proxy address */
            "wap", "wap",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "23101" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
    },

/* Slovenia */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Mobitel", /* Account Name */
            "http://mms,mobitel.si/servlets/mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {213,229,249,40},   /* proxy address */
            "mobitel", "internet",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "29341" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.mobitel.si"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Si Mobil", /* Account Name */
            "http://mmc", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {80,95,224,46},   /* proxy address */
            "simobil", "internet",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "29340" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.simobil.si"
    },

/* South Africa */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Cell C", /* Account Name */
            "http://mms.cmobile.co.za", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {196,31,116,242},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "65507" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"MTN", /* Account Name */
            "mms.mtn.co.za/mms/wapenc", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {196,11,240,241},   /* proxy address */
            "mtnmms", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "65510" /* SIM ID */
        },
        
        (const kal_uint8*)"myMTN"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"VodaCom", /* Account Name */
            "http://mmsc.vodacom4me.co.za", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {196,6,128,13},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "65501" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.vodacom.net"
    },

/* Spain */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Amena", /* Account Name */
            "http://mms.amena.com", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {172,22,188,25},   /* proxy address */
            "MMS", "AMENA",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "21403" /* SIM ID */
        },
        
        (const kal_uint8*)"amenamms"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Movistar", /* Account Name */
            "http://mms.movistar.com", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,138,255,5},   /* proxy address */
            "movistar@mms", "movistar",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "21407" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.movistar.es"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Vodafone", /* Account Name */
            "http://mmsc.vodafone.es/servlets/mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {212,73,32,10},   /* proxy address */
            "wap@wap", "wap125",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "21401,21406,21409" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.vodafone.net"
    },

/* Sweden */
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Tele2", /* Account Name */
            "http://mmsc.tele2.se", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {130,244,202,30},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "24007" /* SIM ID */
        },
        
        (const kal_uint8*)"internet.tele2.se"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Telenor", /* Account Name */
            "http://mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8799, /* proxy port */
            {172,30,253,241},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "24008" /* SIM ID */
        },
        
        (const kal_uint8*)"services.telenor.se"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Telia", /* Account Name */
            "http://mmss", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {193,209,134,132},   /* proxy address */
            "mms", "telia",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "24001" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.telia.se"
    },

/* Switzerland */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Orange", /* Account Name */
            "http://192.168.151.3:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {192,168,151,2},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "22803" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Sunrise", /* Account Name */
            "http://mmsc.sunrise.ch", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {212,35,34,75},   /* proxy address */
            "mms", "mms",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "22802" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.sunrise.ch"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Swisscom", /* Account Name */
            "http://mmsc.swisscom.ch", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {192,168,210,2},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "22801" /* SIM ID */
        },
        
        (const kal_uint8*)"event.swisscom.ch"
    },

/* Taiwan */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Chunghwa", /* Account Name */
            "http://mms.emome.net:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,1,1,1},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "46611" /* SIM ID */
        },
        
        (const kal_uint8*)"emome"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"ForEasTone", /* Account Name */
            "http://mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {210,241,199,199},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "46601" /* SIM ID */
        },
        
        (const kal_uint8*)"fetnet01"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"KG Telcom", /* Account Name */
            "http://mms.kgtmms.net.tw/mms/wapenc", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {172,28,33,5},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "46688" /* SIM ID */
        },
        
        (const kal_uint8*)"kgtmms"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Mobitai", /* Account Name */
            "http://mms.mobeelife.net/mms/wapenc", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {192,168,77,5},   /* proxy address */
            "gprs", "gprs",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "46693" /* SIM ID */
        },
        
        (const kal_uint8*)"gprs1"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"TransAsia", /* Account Name */
            "http://mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {211,78,224,100},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "46699" /* SIM ID */
        },
        
        (const kal_uint8*)"hank"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"TWN", /* Account Name */
            "http://mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,1,1,2},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "46697" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Vibo", /* Account Name */
            "http://mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {210,241,199,199},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "46689" /* SIM ID */
        },
        
        (const kal_uint8*)"internet"
    },

/* Thailand */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"AIS", /* Account Name */
            "http://mms.mobilelife.co.th", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {203,170,229,34},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "52001" /* SIM ID */
        },
        
        (const kal_uint8*)"multimedia"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"DTAC", /* Account Name */
            "http://mms.dtac.co.th:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {203,155,200,133},   /* proxy address */
            "-", "0",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "52018" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Orange", /* Account Name */
            "http://mms.orange.co.th:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,4,7,39},   /* proxy address */
            "orange", "orange",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "52099" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
    },

/* Turkey */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Turkcell", /* Account Name */
            "http://mms.turkcell.com.tr/servlets/mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {212,252,169,217},   /* proxy address */
            "mms", "mms",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "28601" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
    },

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Vodafone", /* Account Name */
            "http://mms:6001/MM1Servlet", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {217,31,233,18},   /* proxy address */
            "mms", "mms",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "28602" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
    },

/* Ukraine */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Kyivstar", /* Account Name */
            "http://mms.kyivstar.net", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,10,10,10},   /* proxy address */
            "mms", "mms",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "25503" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.kyivstar.net"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"UMC", /* Account Name */
            "http://mmsc:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {192,168,10,10},   /* proxy address */
            "mms", "umc",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "25501" /* SIM ID */
        },
        
        (const kal_uint8*)"mms.umc.ua"
    },

/* United Arab Emirates */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Etisalat", /* Account Name */
            "http://mms/servlets/mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,12,0,30},   /* proxy address */
            "mms", "mms",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "42402" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
    },

/* United Kingdom */

{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"BT", /* Account Name */
            "http://mmsc.btmms.co.uk:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {62,239,21,123},   /* proxy address */
            "user", "btmms",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "23410" /* SIM ID */
        },
        
        (const kal_uint8*)"mobile.bt.uk"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"O2", /* Account Name */
            "http://mmsc.mms.o2.co.uk:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {193,113,200,195},   /* proxy address */
            "o2wap", "password",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "23402,23410,23411" /* SIM ID */
        },
        
        (const kal_uint8*)"wap.o2.co.uk"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Orange", /* Account Name */
            "http://mms.orange.co.uk", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {192,168,224,10},   /* proxy address */
            "orange", "multimedia",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "23433,23434" /* SIM ID */
        },
        
        (const kal_uint8*)"orangemms"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"T-Mobile", /* Account Name */
            "http://mmsc.t-mobile.co.uk:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {149,254,211,10},   /* proxy address */
            "user", "one2one",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "23430" /* SIM ID */
        },
        
        (const kal_uint8*)"general.t-mobile.uk"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Virgin", /* Account Name */
            "http://mms.virginmobile.co.uk:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {193,30,166,1},   /* proxy address */
            "user", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "23431,23432" /* SIM ID */
        },
        
        (const kal_uint8*)"goto.virginmobile.uk"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Vodafone", /* Account Name */
            "http://mms.vodafone.co.uk/servlets/mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8799, /* proxy port */
            {212,183,137,12},   /* proxy address */
            "wap", "wap",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "23415" /* SIM ID */
        },
        
        (const kal_uint8*)"wap.vodafone.co.uk"
    },

/* United States */
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"AT&T Wireless", /* Account Name */
            "http://mmsc.mobile.attwireless.net", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {10,250,250,100},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "310030,310170,310150,310280,310380,310410,310560,310680,310980" /* SIM ID */
        },
        
        (const kal_uint8*)"proxy"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Cellular One", /* Account Name */
            "http://www.openmobilealliance.org", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {172,23,1,252},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "310320,310440,310390" /* SIM ID */
        },
        
        (const kal_uint8*)"cellular1wap"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Cincinnati Bell Wireless", /* Account Name */
            "http://wap.gocbw.com", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {216,68,79,199},   /* proxy address */
            "cbw", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "310420" /* SIM ID */
        },
        
        (const kal_uint8*)"wap.gocbw.com"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"T-Mobile", /* Account Name */
            "http://mms.msg.eng.t-mobile.com/mms/wapenc", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {216,155,165,50},   /* proxy address */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "310026,310160,310200,310210,310220,310230,310240,310250,310260, 310270,310290, 310310,310330, 310490,310580,310660,310800" /* SIM ID */
        },
        
        (const kal_uint8*)"epc.tmobile.com"
    },

/* Vietnam */
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Mobifone", /* Account Name */
            "http://203.162.21.114/mmsc", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {203,162,21,114},   /* proxy address */
            "mms", "mms",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "45201" /* SIM ID */
        },
        
        (const kal_uint8*)"m-wap"
    },
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Vinafone", /* Account Name */
            "http://mms.vinaphone.vnn.vn:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            {10,1,10,46},   /* proxy address */
            "mms", "mms",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "45202" /* SIM ID */
        },
        
        (const kal_uint8*)"m3-mms"
    },

/* Yemen */
{
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Sabafon", /* Account Name */
            "http://mms.sabafon.com", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            {192,168,30,174},   /* proxy address */
            "wap", "wap",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MMS, /* app type */
            "42101" /* SIM ID */
        },
        
        (const kal_uint8*)"mms"
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

