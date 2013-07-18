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
 * SmsPsHandler.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for MMI SMS APP.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : SmsPsHandler.c

   PURPOSE     : It handles protocol SMS messages. 

   REMARKS     : nil

   AUTHOR      : Magesh K, Hiran 

   DATE     : 01-01-2003

**************************************************************/
#ifdef __MOD_SMSAL__
#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_non_specific_general_types.h"
#include "gui_typedef.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_util.h"
#include "mmi_rp_app_sms_def.h"
#include "mmi_msg_struct.h"
#include "mmi_frm_mem_gprot.h"
#include "app_buff_alloc.h"
#include "kal_release.h"
#include "DebugInitDef_Int.h"
#include "string.h"
#include "nvram_common_defs.h"
#include "SmsAppGprot.h"
#include "GeneralDeviceGprot.h"
#include "mmi_frm_input_gprot.h"
#include "Unicodexdcl.h"
#include "custom_mmi_default_value.h"
#include "mmi_frm_events_gprot.h"
#include "CustDataRes.h"
#include "gui_data_types.h"
#include "UmSrvStruct.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "mmi_frm_queue_gprot.h"
#include "mmi_rp_app_unifiedmessage_def.h"
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
#include "FileMgrSrvGProt.h"
#endif
#include "UmSrvDefs.h"

#include "MessagesMiscell.h"
#include "MessagesExDcl.h"
#include "SmsGuiInterfaceProt.h"
#include "SMsGuiInterfaceType.h"
#include "SmsPsHandler.h"
#include "l4c2smsal_struct.h"
#include "ems.h"
#include "SimDetectionGprot.h"
#include "SmsSrvGprot.h"
#include "UMGProt.h"

#ifdef __MMI_UNIFIED_COMPOSER__
#include "UcAppGprot.h"
#endif /* __MMI_UNIFIED_COMPOSER__ */

#ifdef __MMI_MSG_UM_LOW_MEMORY_COST__
#include "DateTimeGprot.h"
#endif /* __MMI_MSG_UM_LOW_MEMORY_COST__ */

#if defined(__MMI_OP11_HOMESCREEN__)
/* under construction !*/
#endif /* __MMI_OP11_HOMESCREEN__ */

#if defined(__MMI_VUI_HOMESCREEN__)
#include "IdleRecentEventGprot.h"
#endif /* __MMI_VUI_HOMESCREEN__ */

#include "DateTimeType.h"
#include "IdleNotificationManagerGprot.h"
#include "SmsAppType.h"
#include "SmsAppProt.h"
#include "SmsAppMsg.h"
#include "SmsAppUtil.h"
#include "UcmSrvGprot.h"

#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
#include "UmSrvDefs.h"
#endif /*__SRV_UM_THREAD_MESSAGE_SUPPORT__*/

#include "SimCtrlSrvGProt.h"
#include "IdleGprot.h"
#include "ModeSwitchSrvGprot.h"

#ifdef __MMI_OPERATOR_LOGO__
extern void mmi_op_logo_parse_ota_data(void);
#endif 

#ifdef __MMI_CLI_ICON__
extern void mmi_cli_icon_parse_ota_data(void);
#endif 

extern msg_active_profile_struct activeProfile;
extern U16 processRSKStrId;
extern void MoveCursorToPosition(EMSData *data, EMSPosition *dst);

extern EMSData *GetEMSDataForView(EMSData **p, U8 force);
extern EMSData *GetEMSDataForEdit(EMSData **p, U8 force);
static void mmi_sms_update_msg_screen(MMI_BOOL is_update_msg, MMI_BOOL is_update_icon);
static void mmi_sms_update_new_sms_ind(srv_sms_storage_enum storage_type);


/*******************************************************


            protocol event handler           


*******************************************************/
extern msg_msgbox_info_struct msgbox_info;

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_sim_ctrl_availability_changed_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sms_sim_ctrl_availability_changed_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_availability_changed_evt_struct *availability_changed_evt = (srv_sim_ctrl_availability_changed_evt_struct*)evt;
#ifndef __MMI_DUAL_SIM_MASTER__
    S32 start_icon_id = STATUS_ICON_UNREAD_VOICE_L1;
#else /* __MMI_DUAL_SIM_MASTER__ */
    S32 start_icon_id = STATUS_ICON_UNREAD_VOICE_L1_MASTER;
#endif /* __MMI_DUAL_SIM_MASTER__ */
    S32 i = 0;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_SIM_CTRL_UA_CAUSE_BT_ACCESS_PROFILE == availability_changed_evt->unavailable_cause)
    {
        if (GRP_ID_INVALID != g_sms_gid)
        {
            mmi_frm_group_close(g_sms_gid);
        }

        mmi_sms_vm_group_close();
        mmi_sms_settings_group_close();
    #ifdef __MMI_MESSAGES_TEMPLATE__
        mmi_sms_template_group_close();
    #endif
    }

    if ((availability_changed_evt->is_available_before)
        && (availability_changed_evt->is_available_now == MMI_FALSE)
        )
    {
        mmi_sms_set_msg_icon(MMI_TRUE, SRV_SMS_SIM_1);
        mmi_sms_set_msg_icon(MMI_TRUE, SRV_SMS_SIM_2);

    #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    #ifndef __MMI_DUAL_SIM_MASTER__
        wgui_status_icon_bar_hide_icon(STATUS_ICON_OUTBOX_INDICATOR);
        wgui_status_icon_bar_hide_icon(STATUS_ICON_SMS_SENDING);
    #else
        mmi_msg_update_unsent_icon();
    #endif
    #endif

    #ifndef __MMI_DUAL_SIM_MASTER__
        for (i = 0; i < MMI_SMS_MAX_MSG_WAITING_ICON; i++)
        {
            wgui_status_icon_bar_set_icon_flag((start_icon_id + i), 0);
        }
    #else
        if(availability_changed_evt->sim & MMI_SIM1)
        {
            S32 max_icon = MMI_SMS_MAX_MSG_WAITING_ICON/2;

            for (i = 0; i < max_icon; i++)
            {
                wgui_status_icon_bar_set_icon_flag((start_icon_id + i), 0);
            }
        }
        if(availability_changed_evt->sim & MMI_SIM2)
        {
            S32 max_icon = MMI_SMS_MAX_MSG_WAITING_ICON/2;
            start_icon_id = STATUS_ICON_UNREAD_VOICE_L1_SLAVE;

            for (i = 0; i < max_icon; i++)
            {
                wgui_status_icon_bar_set_icon_flag((start_icon_id + i), 0);
            }
        }
    #endif
    }

    if ((MMI_FALSE == availability_changed_evt->is_available_before)
        && (availability_changed_evt->is_available_now)
        )
    {

        if (srv_mode_switch_is_network_service_available())
        {
            if (srv_sms_is_sms_ready() == MMI_TRUE)
            {
                mmi_sms_set_msg_icon(MMI_TRUE, SRV_SMS_SIM_1);
                mmi_sms_set_msg_icon(MMI_TRUE, SRV_SMS_SIM_2);
            #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
                mmi_msg_update_unsent_icon();
            #endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
            }

            mmi_sms_check_msg_waiting_icon();
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_mode_switch_finish_evt_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sms_mode_switch_finish_evt_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mode_switch_notify_struct *flight_mode_evt = (srv_mode_switch_notify_struct*)evt;
#ifndef __MMI_DUAL_SIM_MASTER__
    S32 start_icon_id = STATUS_ICON_UNREAD_VOICE_L1;
#else /* __MMI_DUAL_SIM_MASTER__ */
    S32 start_icon_id = STATUS_ICON_UNREAD_VOICE_L1_MASTER;
#endif /* __MMI_DUAL_SIM_MASTER__ */
	S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY)
    {
        if ((flight_mode_evt->gsm_curr_mode != SRV_MODE_SWITCH_ALL_OFF)
            &&(flight_mode_evt->gsm_select_mode == SRV_MODE_SWITCH_ALL_OFF)
            )
        {
            mmi_sms_hide_msg_icon(SRV_SMS_SIM_1);
            mmi_sms_hide_msg_icon(SRV_SMS_SIM_2);
        #if (MMI_MAX_SIM_NUM >= 3)
            mmi_sms_hide_msg_icon(SRV_SMS_SIM_3);
        #endif
        #if (MMI_MAX_SIM_NUM >= 4)
            mmi_sms_hide_msg_icon(SRV_SMS_SIM_4);
        #endif
        #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
            wgui_status_icon_bar_hide_icon(STATUS_ICON_OUTBOX_INDICATOR);
            wgui_status_icon_bar_hide_icon(STATUS_ICON_SMS_SENDING);
        #endif

            for (i = 0; i < MMI_SMS_MAX_MSG_WAITING_ICON; i++)
            {
                wgui_status_icon_bar_set_icon_flag(start_icon_id + i, 0);
            }

        #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
            {
            	U16 msg_list_size;
                U16 index;
                U16 msg_id;
                srv_sms_send_status_enum send_status;

                msg_list_size = srv_sms_get_list_size(SRV_SMS_BOX_UNSENT);

                for (index = 0; index < msg_list_size; index++)
                {
                    msg_id = srv_sms_get_msg_id(SRV_SMS_BOX_UNSENT, index);
                    send_status = srv_sms_get_unsent_msg_status(msg_id);

                    if ((send_status == SRV_SMS_SEND_SENDING) || (send_status == SRV_SMS_SEND_WAITING))
                    {
                        srv_sms_set_unsent_msg_status(msg_id, SRV_SMS_SEND_FAIL);
                    }
                }
            }
        #endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
        }
        else if (flight_mode_evt->gsm_select_mode != SRV_MODE_SWITCH_ALL_OFF)
        {
            mmi_sms_set_msg_icon(MMI_TRUE, SRV_SMS_SIM_1);
            mmi_sms_set_msg_icon(MMI_TRUE, SRV_SMS_SIM_2);

        #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
        	mmi_msg_update_unsent_icon();
        #endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
            mmi_sms_check_msg_waiting_icon();
        #ifdef __SRV_SMS_BACKGROUND_SEND_SUPPORT__
            srv_sms_send_from_storage_schedule();
        #endif
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_ready_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dummy       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sms_handle_ready_ind(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
    srv_sms_event_sms_ready_struct *event_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    event_info = (srv_sms_event_sms_ready_struct*)event_data->event_info;

    /* The case of SMS not Ready is only happened when SIM Refresh */
    if (event_info->is_sms_ready == MMI_TRUE)
	{
    #ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_OP11_HOMESCREEN__ */
    
    #if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
        mmi_sms_update_sidebar_info();
        mmi_sms_update_shct_data();
        mmi_voicemail_update_op11_hs32_vm_shct_data();
    #endif /* #if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */

    #ifdef __MMI_VUI_HOMESCREEN__
        if ((mmi_hs_is_on_recent_event() == MMI_TRUE))
        {
            mmi_msg_hs_update_sms_recent_event(MMI_HS_MAX_RECENT_EVENT_NUM);
        }
    #endif /* __MMI_VUI_HOMESCREEN__ */

        if (srv_mode_switch_is_network_service_available())
        {
            mmi_sms_set_msg_icon(MMI_TRUE, SRV_SMS_SIM_1);
            mmi_sms_set_msg_icon(MMI_TRUE, SRV_SMS_SIM_2);

        #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
            mmi_msg_update_unsent_icon();
            srv_sms_send_from_storage_schedule();
        #endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
        }

    #ifdef __MMI_UM_ITERATOR_VIEWER__
        g_sms_cntx.iter_viewer_result = NULL;
    #endif /* __MMI_UM_ITERATOR_VIEWER__ */
    }
    else
    {
        if (g_sms_gid != GRP_ID_INVALID)
        {
            mmi_frm_group_close(g_sms_gid);
        }
        mmi_sms_vm_group_close();
        mmi_sms_settings_group_close();
    #ifdef __MMI_MESSAGES_TEMPLATE__
        mmi_sms_template_group_close();
    #endif

        mmi_sms_hide_msg_icon(SRV_SMS_SIM_1);
        mmi_sms_hide_msg_icon(SRV_SMS_SIM_2);
    #if (MMI_MAX_SIM_NUM >= 3)
        mmi_sms_hide_msg_icon(SRV_SMS_SIM_3);
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        mmi_sms_hide_msg_icon(SRV_SMS_SIM_4);
    #endif

    #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
        wgui_status_icon_bar_hide_icon(STATUS_ICON_OUTBOX_INDICATOR);
    #endif
    }

    mmi_msg_send_ready_ind((kal_bool)event_info->is_sms_ready);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_msg_waiting_ind_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pMsgIndExt      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_msg_handle_msg_waiting_ind_ext(l4csmsal_msg_waiting_ind_ext_struct *pMsgIndExt, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined (__MMI_OP11_HOMESCREEN__)
/* under construction !*/
#endif /* defined (__MMI_OP11_HOMESCREEN__) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MSG_REL4_SUPPORT__
	if (srv_sms_check_r4_support() == MMI_TRUE)
	{
		/* R4R5 mode, only show the Line1, ignore the Line2 */
        if (pMsgIndExt->line_no >= 1)
		{
			return;
		}
	}
	else
	{
        if (pMsgIndExt->line_no >= MAX_WAITING_LINE_NUM)
		{
			return;
		}
	}
#else /* __MMI_MSG_REL4_SUPPORT__ */
    if (pMsgIndExt->line_no >= MAX_WAITING_LINE_NUM)
	{
		return;
	}
#endif /* __MMI_MSG_REL4_SUPPORT__ */

    if (pMsgIndExt->ind_type >= MAX_WAITING_TYPE_NUM)
    {
        return;
    }

    if (pMsgIndExt->is_clear)
    {
        g_msg_cntx.msg_waiting_info[(pMsgIndExt->line_no)].number[pMsgIndExt->ind_type] = 0;
        mmi_msg_set_msg_waiting_icon(sim_id, pMsgIndExt->line_no, pMsgIndExt->ind_type, 0);
	#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif /* __MMI_OP11_HOMESCREEN__ */
            if (g_msg_cntx.msg_waiting_line_number == pMsgIndExt->line_no && g_msg_cntx.msg_waiting_ind == pMsgIndExt->ind_type + 1
              #if (MMI_MAX_SIM_NUM >= 2)
                        && ((g_msg_cntx.msg_waiting_info[g_msg_cntx.msg_waiting_line_number].curr_sim == MMI_SIM1 && sim_id == SRV_SMS_SIM_1) 
                            || (g_msg_cntx.msg_waiting_info[g_msg_cntx.msg_waiting_line_number].curr_sim == MMI_SIM2 && sim_id == SRV_SMS_SIM_2)
                        #if  (MMI_MAX_SIM_NUM >= 3)
                            || (g_msg_cntx.msg_waiting_info[g_msg_cntx.msg_waiting_line_number].curr_sim == MMI_SIM3 && sim_id == SRV_SMS_SIM_3)                        
                        #endif
                        #if  (MMI_MAX_SIM_NUM >= 4)
                            || (g_msg_cntx.msg_waiting_info[g_msg_cntx.msg_waiting_line_number].curr_sim == MMI_SIM4 && sim_id == SRV_SMS_SIM_4)
                        #endif
                          )
		#endif
			)
		{
			if (GetMessagesCurrScrnID() == SCR_ID_MSG_MSG_WAITING_IND)
			{
				mmi_sms_go_back_from_msg_waiting_ind();
			}

		    /* clear notification manager */
            if (g_msg_cntx.msg_waiting_ind == 1)
            {
                mmi_nmgr_refresh(MMI_NMGR_APP_MESSAGE_WAITING, MMI_NMGR_OPTION_USE_DEFAULT);
            }
            g_msg_cntx.msg_waiting_ind = 0;
   		}
		
    #ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_OP11_HOMESCREEN__ */

#if defined (__MMI_OP11_HOMESCREEN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined (__MMI_OP11_HOMESCREEN__) */
    }        
    else
    {
        g_msg_cntx.msg_waiting_info[(pMsgIndExt->line_no)].number[pMsgIndExt->ind_type] = pMsgIndExt->waiting_num;
	#ifdef __MMI_DUAL_SIM_MASTER__
        if (sim_id == SRV_SMS_SIM_1)
        {
            g_msg_cntx.msg_waiting_info[(pMsgIndExt->line_no)].curr_sim = MMI_SIM1;
        }
        else if (sim_id == SRV_SMS_SIM_2)
        {
            g_msg_cntx.msg_waiting_info[(pMsgIndExt->line_no)].curr_sim = MMI_SIM2;
        }
	#if (MMI_MAX_SIM_NUM >= 3)
        else if (sim_id == SRV_SMS_SIM_3)
        {
            g_msg_cntx.msg_waiting_info[(pMsgIndExt->line_no)].curr_sim = MMI_SIM3;
        }
	#endif
	#if (MMI_MAX_SIM_NUM >= 4)
        else
        {
            g_msg_cntx.msg_waiting_info[(pMsgIndExt->line_no)].curr_sim = MMI_SIM4;
        }
	#endif
	#endif

        /* Only display icon for message indication in storage, not from network. */
        if (pMsgIndExt->is_from_storage)
        {
            mmi_msg_set_msg_waiting_icon(sim_id, pMsgIndExt->line_no, pMsgIndExt->ind_type, 1);

            return;
        }
        
        g_msg_cntx.msg_waiting_is_show_number = pMsgIndExt->is_show_num;        
        g_msg_cntx.msg_waiting_line_number = pMsgIndExt->line_no;        

#if defined (__MMI_OP11_HOMESCREEN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined (__MMI_OP11_HOMESCREEN__) */

        mmi_msg_msg_waiting_ind(pMsgIndExt->ind_type);
    }

#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP11_HOMESCREEN__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_msg_waiting_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sms_handle_msg_waiting_ind(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
    srv_sms_event_msg_waitting_struct* event_info = (srv_sms_event_msg_waitting_struct*)event_data->event_info;

    srv_sms_sim_enum sim_id = event_info->sim_id;
    mmi_sms_msg_waiting_ind_struct *msgInd = (mmi_sms_msg_waiting_ind_struct*)event_info->msg_data;
    l4csmsal_msg_waiting_ind_ext_struct msgIndExt;

    U8 ext_ind = msgInd->ext_indicator;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    if ((sim_id == SRV_SMS_SIM_2)
        && (srv_sim_ctrl_get_unavailable_cause(MMI_SIM2) == SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED)
        )
    {
        return MMI_RET_OK;
    }
    else if (sim_id == SRV_SMS_SIM_1)    
#endif /* __MMI_DUAL_SIM_MASTER__ */ 
    {
        if (srv_sim_ctrl_get_unavailable_cause(MMI_SIM1) == SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED)
        {
            return MMI_RET_OK;
        }
    }

    msgIndExt.ind_type = msgInd->ind_type;
    msgIndExt.line_no = msgInd->line_no;
    msgIndExt.msp_no = msgInd->msp_no;
    msgIndExt.waiting_num = msgInd->waiting_num;
    msgIndExt.ind_type = msgInd->ind_type;
    msgIndExt.is_show_num = msgInd->is_show_num;
    msgIndExt.is_clear = msgInd->is_clear;
    msgIndExt.is_from_storage = msgInd->is_from_storage;
		
    mmi_msg_handle_msg_waiting_ind_ext(&msgIndExt, sim_id);
#ifdef __MMI_SMS_FOR_HOMESCREEN__
    if (msgIndExt.ind_type == 0)
    {
        if (msgIndExt.is_clear)
        {
            g_msg_cntx.msg_waiting_vm_num = 0;
        }
        else
        {
            if (msgIndExt.is_show_num)
            {
                g_msg_cntx.msg_waiting_vm_num = msgIndExt.waiting_num;
            }
            else
            {
                g_msg_cntx.msg_waiting_vm_num = 1;
            }
        }
#if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
     mmi_voicemail_update_op11_hs32_vm_shct_data();
#endif        
    }
#endif /* __MMI_SMS_FOR_HOMESCREEN__ */
    
    for (i = 0; i < ext_ind; i++)
    {
        msgIndExt.ind_type = msgInd->msg_waiting[i].ind_type;
        msgIndExt.line_no = msgInd->msg_waiting[i].line_no;
        msgIndExt.msp_no = msgInd->msg_waiting[i].msp_no;
        msgIndExt.waiting_num = msgInd->msg_waiting[i].waiting_num;
        msgIndExt.ind_type = msgInd->msg_waiting[i].ind_type;
        msgIndExt.is_show_num = msgInd->msg_waiting[i].is_show_num;
        msgIndExt.is_clear = msgInd->msg_waiting[i].is_clear;
        msgIndExt.is_from_storage = msgInd->msg_waiting[i].is_from_storage;

        mmi_msg_handle_msg_waiting_ind_ext(&msgIndExt, sim_id);
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_deliver_report_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sms_handle_deliver_report_ind(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
    srv_sms_event_new_status_report_struct *event_info = (srv_sms_event_new_status_report_struct*)event_data->event_info;
    srv_sms_status_report_struct *report_data = &event_info->report_data;
#ifndef __MMI_UM_REPORT_BOX__
    srv_sms_status_report_struct *dest_report;
#endif /* __MMI_UM_REPORT_BOX__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_UM_REPORT_BOX__
    if (g_sms_cntx.report_count == MMI_SMS_MAX_REPORT_NUM)
    {
        U32 i;

        /* Remove Oldest one (first Index) */
        OslMfree(g_sms_cntx.report_data[0]);

        for (i = 0; i < (MMI_SMS_MAX_REPORT_NUM - 1); i++)
        {
            g_sms_cntx.report_data[i] = g_sms_cntx.report_data[i + 1];
        }

        g_sms_cntx.report_count--;
    }

    MMI_ASSERT(g_sms_cntx.report_count < MMI_SMS_MAX_REPORT_NUM);

    dest_report = OslMalloc(sizeof(srv_sms_status_report_struct));

    memcpy(dest_report, report_data, sizeof(srv_sms_status_report_struct));
    g_sms_cntx.report_data[g_sms_cntx.report_count] = dest_report;
#else /* __MMI_UM_REPORT_BOX__ */
    g_sms_cntx.curr_report_id = event_info->report_id;
#endif /* __MMI_UM_REPORT_BOX__ */

    if (g_sms_cntx.report_count < MMI_SMS_MAX_REPORT_NUM)
    {
        g_sms_cntx.report_count++;
    }

    mmi_sms_entry_delivery_report_ind();

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_mem_full_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sms_handle_mem_full_ind(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
    srv_sms_event_mem_full_struct *event_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    event_info = (srv_sms_event_mem_full_struct*)event_data->event_info;

    if (event_info->mem_type == SRV_SMS_MEM_NORMAL
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        || event_info->mem_type == SRV_SMS_MEM_ME_ONLY
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
       )
    {
        mmi_sim_enum mmi_sim_id = MMI_SIM1;

            if (event_info->sim_id == SRV_SMS_SIM_1)
            {
                g_msg_cntx.msg_full_ind = TRUE;
            }
        #if (MMI_MAX_SIM_NUM >= 2)
        if (event_info->sim_id == SRV_SMS_SIM_2)
        {
                g_msg_cntx.sim2_msg_full_ind = MMI_TRUE;
            mmi_sim_id = MMI_SIM2;
        }
        #if  (MMI_MAX_SIM_NUM >= 3)
            else if (event_info->sim_id == SRV_SMS_SIM_3)
        {
                g_msg_cntx.sim3_msg_full_ind = MMI_TRUE;
                mmi_sim_id = MMI_SIM3;
        }
        #endif
        #if  (MMI_MAX_SIM_NUM >= 4)        
            else if (event_info->sim_id == SRV_SMS_SIM_4)
            {
                g_msg_cntx.sim4_msg_full_ind = MMI_TRUE;
                mmi_sim_id = MMI_SIM4;
            }            
        #endif            
        #endif /*  (MMI_MAX_SIM_NUM >= 2) */


        mmi_sms_set_msg_icon(MMI_TRUE, event_info->sim_id);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_mem_exceed_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sms_handle_mem_exceed_ind(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
    srv_sms_event_mem_exceed_struct *pMemExceed = (srv_sms_event_mem_exceed_struct*)event_data->event_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pMemExceed->mem_type == SRV_SMS_MEM_NORMAL || pMemExceed->mem_type == SRV_SMS_MEM_SIM_ONLY)
    {
        g_msg_cntx.msg_exceed_ind = MMI_TRUE;
        g_msg_cntx.msg_exceed_type = pMemExceed->mem_type;

    #ifdef __MMI_DUAL_SIM_MASTER__
        if (pMemExceed->sim_id == SRV_SMS_SIM_1)
        {
			g_msg_cntx.msg_exceed_sim = MMI_SIM1;
        }
        else if (pMemExceed->sim_id == SRV_SMS_SIM_2)
        {
			g_msg_cntx.msg_exceed_sim = MMI_SIM2;
        }
	#if  (MMI_MAX_SIM_NUM >= 3)
        else if (pMemExceed->sim_id == SRV_SMS_SIM_3)
        {
			g_msg_cntx.msg_exceed_sim = MMI_SIM3;
        }
	#endif
	#if  (MMI_MAX_SIM_NUM >= 4)	
        else if (pMemExceed->sim_id == SRV_SMS_SIM_4)
        {
			g_msg_cntx.msg_exceed_sim = MMI_SIM4;
        }
	#endif
    #endif /* __MMI_DUAL_SIM_MASTER__ */

        TurnOnBacklight(1);

        if (IsMMIInIdleState())
        {
            ClearKeyEvents();
            if (IsKeyPadLockState())
            {
                 mmi_idle_display();
            }
            else
            {
                mmi_msg_entry_mem_exceed_ind();
            }
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_mem_avail_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sms_handle_mem_avail_ind(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
    srv_sms_event_mem_available_struct *event_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    event_info = (srv_sms_event_mem_available_struct*)event_data->event_info;

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    if ((event_info->mem_type == SRV_SMS_MEM_NORMAL) || 
        (event_info->mem_type == SRV_SMS_MEM_ME_ONLY))
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    {
        #if (MMI_MAX_SIM_NUM >= 2)
        if (event_info->sim_id == SRV_SMS_SIM_2)
        {
                g_msg_cntx.sim2_msg_full_ind = FALSE;
                g_msg_cntx.msg_exceed_sim = MMI_SIM2;
            }
        #if (MMI_MAX_SIM_NUM >= 3)            
            else if (event_info->sim_id == SRV_SMS_SIM_3)
            {
                g_msg_cntx.sim3_msg_full_ind = FALSE;
                g_msg_cntx.msg_exceed_sim = MMI_SIM3;
            }
        #endif
        #if  (MMI_MAX_SIM_NUM >= 4)                    
            else if (event_info->sim_id == SRV_SMS_SIM_4)
            {
                g_msg_cntx.sim4_msg_full_ind= FALSE;
                g_msg_cntx.msg_exceed_sim = MMI_SIM4;
        }
        #endif            
        else
        #endif /*  (MMI_MAX_SIM_NUM >= 2) */
        {
                g_msg_cntx.msg_full_ind = FALSE;
        }

        mmi_sms_set_msg_icon(MMI_TRUE, event_info->sim_id);

            g_msg_cntx.msg_exceed_ind = FALSE;
    }

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    if (((event_info->mem_type == SRV_SMS_MEM_NORMAL) ||
         (event_info->mem_type == SRV_SMS_MEM_SIM_ONLY)) && 
        (g_msg_cntx.msg_exceed_type == SRV_SMS_MEM_SIM_ONLY))
    {
            g_msg_cntx.msg_exceed_ind = FALSE;
    }
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_class0_msg_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 *  content     [?]     
 * RETURNS
 *  
 *****************************************************************************/
void mmi_msg_handle_class0_msg_ind(srv_sms_event_new_sms_struct* event_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_new_msg_struct *new_msg_data = (srv_sms_new_msg_struct*)event_info->msg_data;
#ifdef __MMI_DUAL_SIM_MASTER__
    srv_sms_sim_enum sim_id = new_msg_data->sim_id;
#endif /* __MMI_DUAL_SIM_MASTER__ */
    S8 *unicodecontent = (S8*)event_info->content;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_msg_cntx.msg_class0_p != NULL)
    {
        if (g_msg_cntx.msg_class0_p->data != NULL)
        {
            OslMfree(g_msg_cntx.msg_class0_p->data);
            g_msg_cntx.msg_class0_p->data = NULL;
        }
        OslMfree(g_msg_cntx.msg_class0_p);
        g_msg_cntx.msg_class0_p = NULL;
    }
    g_msg_cntx.msg_class0_p = OslMalloc(sizeof(msg_class0_msg_struct));
    g_msg_cntx.msg_class0_p->length = (U16) new_msg_data->message_len;
    g_msg_cntx.msg_class0_p->dcs = new_msg_data->dcs;
    g_msg_cntx.msg_class0_p->totalseg = new_msg_data->total_seg;
#ifdef __MMI_DUAL_SIM_MASTER__
	if (sim_id == SRV_SMS_SIM_1)
	{
		g_msg_cntx.msg_class0_p->curr_sim = MMI_SIM1;
	}
	else if (sim_id == SRV_SMS_SIM_2)
	{
		g_msg_cntx.msg_class0_p->curr_sim = MMI_SIM2;
	}
#if  (MMI_MAX_SIM_NUM >= 3)

	else if (sim_id == SRV_SMS_SIM_3)
	{
		g_msg_cntx.msg_class0_p->curr_sim = MMI_SIM3;
	}
#endif
#if  (MMI_MAX_SIM_NUM >= 4)
	else
	{
		g_msg_cntx.msg_class0_p->curr_sim = MMI_SIM4;
	}
#endif
#endif /* __MMI_DUAL_SIM_MASTER__ */

    mmi_asc_to_ucs2((S8*)g_msg_cntx.msg_class0_p->number, (S8*)new_msg_data->number);
    memcpy(&(g_msg_cntx.msg_class0_p->timestamp), &(new_msg_data->timestamp), sizeof(MYTIME));

    g_msg_cntx.msg_class0_p->data = OslMalloc(g_msg_cntx.msg_class0_p->length + ENCODING_LENGTH);
    memset((S8*) g_msg_cntx.msg_class0_p->data, 0, g_msg_cntx.msg_class0_p->length + ENCODING_LENGTH);
    memcpy((S8*) g_msg_cntx.msg_class0_p->data, (S8*) unicodecontent, g_msg_cntx.msg_class0_p->length);

    g_class0_sms_info.fo = new_msg_data->fo;
    memcpy(g_class0_sms_info.sc_addr, new_msg_data->sc_number, SRV_SMS_MAX_ADDR_LEN);
    g_class0_sms_info.sc_addr[SRV_SMS_MAX_ADDR_LEN] = '\0';
    memcpy(g_class0_sms_info.number, new_msg_data->number, SRV_SMS_MAX_ADDR_LEN);
    g_class0_sms_info.number[SRV_SMS_MAX_ADDR_LEN] = '\0';
	memcpy(&(g_class0_sms_info.timestamp), &(new_msg_data->timestamp), sizeof(MYTIME));

    mmi_msg_class0_msg_ind();

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_get_msg_new_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_get_msg_new_callback(mmi_sms_result_enum result, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == SMS_RESULT_OK)
    {
        mmi_sms_msg_status_enum msg_status = *(mmi_sms_msg_status_enum*)data;

        g_sms_cntx.curr_msg_status = msg_status;

        if ((g_sms_gid == mmi_frm_group_get_active_id())
            && (SCR_ID_SMS_PROCESSING == mmi_frm_scrn_get_active_id()))
        {
            mmi_sms_entry_viewer();
            mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_PROCESSING);
        }
        else if (mmi_frm_scrn_is_present(g_sms_gid, SCR_ID_SMS_PROCESSING, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
        {
            mmi_frm_node_struct new_node_info;
            new_node_info.id = SCR_ID_SMS_VIEWER;
            new_node_info.entry_proc = (mmi_proc_func)mmi_sms_entry_viewer;
            mmi_frm_scrn_replace(g_sms_gid, SCR_ID_SMS_PROCESSING , &new_node_info);
        }
    }
    else
    {
        mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_PROCESSING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_msg_new
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_get_msg_new(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_msg_cntx.msg_ind_in_idle = MMI_FALSE;
    mmi_frm_deregister_deferring_notification(SCR_ID_MSG_NEW_MSG_IND);

    if (srv_sms_is_msg_exist(g_msg_cntx.msg_ind_index) == MMI_FALSE)
    {
        mmi_sms_display_popup(
            (UI_string_type) GetString(STR_GLOBAL_UNFINISHED),
            MMI_EVENT_FAILURE);
    }
    else
    {
        if (srv_sms_is_sms_ready() == MMI_FALSE)
        {
            mmi_msg_exit_inbox_list_dummy();
        }

        g_sms_cntx.msg_ind_in_idle = MMI_FALSE;
        g_sms_cntx.curr_list_type = MMI_SMS_LIST_INBOX;
        g_sms_cntx.curr_box_type = SRV_SMS_BOX_INBOX;
        g_sms_cntx.curr_msg_id = g_sms_cntx.ind_msg_index;

        mmi_sms_read_msg(g_sms_cntx.curr_msg_id, MMI_TRUE, mmi_sms_get_msg_new_callback);
    }
}


#ifdef __MMI_MESSAGES_SEND_BY_GROUP__
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_send_msg_to_group
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cnt             [IN]        
 *  PhbIndex        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_send_msg_to_group(U16 cnt, U16 *PhbIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}
#endif /* __MMI_MESSAGES_SEND_BY_GROUP__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_delete_all_msg_by_um_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_handle_delete_all_msg_by_um_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
#ifndef __MMI_MSG_UM_LOW_MEMORY_COST__
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_um_traverse_msg_req
 * DESCRIPTION
 *  When open conversation box, um will need several boxes messges.
 * PARAMETERS
 *  inMsg       [IN]: Request structure from UM    
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_msg_handle_um_traverse_msg_req(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 start_entry; 
    kal_uint16 msg_number = 0;
    kal_bool more = KAL_FALSE;
    kal_bool result;
    srv_um_traverse_msg_req_struct *msgReq = (srv_um_traverse_msg_req_struct*) (inMsg);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (msgReq->msg_type != SRV_UM_MSG_SMS)
    {
        return MMI_FALSE;
    }
    if ((msgReq->msg_box_type == SRV_UM_MSG_BOX_PREDEF_TEMPLATES)
        || (msgReq->msg_box_type == SRV_UM_MSG_BOX_PREDEF_TEMPLATES))
    {
        MMI_ASSERT(0);
    }
    start_entry = msgReq->start_entry;         
    if (start_entry < 0)
    {
        msg_number = msgReq->msg_number;
    }
    result = mmi_msg_um_traverse_msg(
                    msgReq->msg_box_type
                    ,start_entry
                    ,&msg_number
                    ,msgReq->msg_id
                #ifdef __MMI_DUAL_SIM_MASTER__
                    ,SRV_UM_SIM_ALL
                #endif /*__MMI_DUAL_SIM_MASTER__*/
                    ,&more
                    ,msgReq->field
                    ,msgReq->traverse_func
                    ,msgReq->user_data
                    );
    mmi_msg_send_traverse_msg_rsp(msgReq->app_id, msg_number, more, result);
    return MMI_TRUE;
}
#endif /*__MMI_MSG_UM_LOW_MEMORY_COST__*/


/***********************************************************************************
 * FUNCTION
 *  mmi_msg_send_traverse_msg_rsp
 * DESCRIPTION
 *  Send MSG_ID_MMI_UM_TRAVERSE_MSG_RSP response back to UM
 * PARAMETERS
 *  app_id       [IN]: app id
 *  more         [IN]: Info um that whether there has more sms need to handle or not    
 *  result       [IN]: Info um traverse msg result
 * RETURNS
 *  void
 ***********************************************************************************/
void mmi_msg_send_traverse_msg_rsp(kal_uint32 app_id, kal_uint16 msg_number, kal_bool more, kal_bool result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    srv_um_traverse_msg_rsp_struct *msg = (srv_um_traverse_msg_rsp_struct*) construct_local_para(
        sizeof(srv_um_traverse_msg_rsp_struct), 
        TD_CTRL | TD_RESET);
    msg->msg_type = SRV_UM_MSG_SMS;
    msg->app_id   = app_id;
    msg->msg_number = msg_number;
    msg->more = more;
    msg->result = result;
    mmi_msg_send_message(MOD_MMI, MOD_MMI, 0, MSG_ID_MMI_UM_TRAVERSE_MSG_RSP, (oslParaType*) msg, NULL);
}
#endif /* __SRV_UM_THREAD_MESSAGE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_send_ready_ind
 * DESCRIPTION
 *  send ready indication to UM
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_send_ready_ind(kal_bool result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_ready_ind_struct *msg = (srv_um_ready_ind_struct*) construct_local_para(sizeof(srv_um_ready_ind_struct), TD_CTRL | TD_RESET);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg->result = result;
    msg->msg_type = SRV_UM_MSG_SMS;

    mmi_msg_send_message(MOD_MMI, MOD_MMI, 0, MSG_ID_MMI_UM_READY_IND, (oslParaType*) msg, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_send_new_msg_ind
 * DESCRIPTION
 *  send new msg indication to UM
 * PARAMETERS
 *  msg_box_type        [IN]        
 *  list_index          [IN]        
 *  timestamp           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_send_new_msg_ind(U8 msg_box_type, U16 msg_id, U32 timestamp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_new_msg_ind_struct *msg = (srv_um_new_msg_ind_struct*)construct_local_para(
															sizeof(srv_um_new_msg_ind_struct),
															TD_CTRL | TD_RESET);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg->msg_type = SRV_UM_MSG_SMS;
    msg->msg_box_type = (srv_um_msg_box_enum)msg_box_type;
    msg->msg_id = msg_id;
    msg->timestamp = timestamp;
#ifdef __MMI_DUAL_SIM_MASTER__
    if (srv_sms_get_msg_sim_id(msg_id) == SRV_SMS_SIM_1)
    {
        msg->sim_id = SRV_UM_SIM_GSM_SIM1;
    }
    else
    {
        msg->sim_id = SRV_UM_SIM_GSM_SIM2;
    }
#endif

    mmi_msg_send_message(MOD_MMI, MOD_MMI, 0, MSG_ID_MMI_UM_NEW_MSG_IND, (oslParaType*) msg, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_send_highlight_decided_by_um_ind
 * DESCRIPTION
 *  send highlight need to change ind to UM when msg is deleted after sent
 * PARAMETERS
 *  msg_box_type        [IN]	UM box type
 *  msg_index			[IN]	the deleted msg index after sent 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_send_highlight_decided_by_um_ind(U8 msg_box_type, U16 msg_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_sms_box_enum sms_box_type;
    srv_um_highlight_decided_by_UM_struct *msg =
        (srv_um_highlight_decided_by_UM_struct*) construct_local_para(sizeof(srv_um_highlight_decided_by_UM_struct), TD_CTRL | TD_RESET);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	sms_box_type = mmi_sms_um_um_box_to_sms((srv_um_msg_box_enum)msg_box_type);

	msg->msg_type = SRV_UM_MSG_SMS;
    msg->msg_box_type = (srv_um_msg_box_enum)msg_box_type;
    msg->msg_id = srv_sms_get_msg_id(sms_box_type, msg_index);

    mmi_msg_send_message(MOD_MMI, MOD_MMI, 0, MSG_ID_MMI_UM_HIGHLIGHT_DECIDED_BY_UM_IND, (oslParaType*)msg, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_send_message
 * DESCRIPTION
 *  Common function for sending message
 * PARAMETERS
 *  MOD_SRC         [IN]        Source module
 *  MOD_DEST        [IN]        Destination module
 *  MSG_SAP         [IN]        Message SAP
 *  MSG_ID          [IN]        Message ID
 *  LOCAL           [IN]        Local parameter
 *  PEER            [IN]        Peer buffer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_send_message(
        module_type MOD_SRC,
        module_type MOD_DEST,
        U8 MSG_SAP,
        const U16 MSG_ID,
        void *LOCAL,
        void *PEER)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_send_ilm(MOD_DEST, MSG_ID, LOCAL, PEER);
}


#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_sim_msg_new
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_get_sim_msg_new(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_deregister_deferring_notification(SCR_ID_MSG_SIMBOX_MSG);

    /* Go back to Idle screen if the new msg is deleted by AT or SIM refresh is ongoing. */
    if (srv_sms_is_msg_exist(g_msg_cntx.sim_msg_ind_index) == MMI_FALSE)
    {
        mmi_sms_display_popup(
            (UI_string_type) GetString(STR_GLOBAL_UNFINISHED),
            MMI_EVENT_FAILURE);
        g_msg_cntx.sim_msg_ind_in_idle = MMI_FALSE;
        return;
    }

    g_msg_cntx.sim_msg_ind_in_idle = MMI_FALSE;
    /* disallow re-entering SMS application when there is a pending SMS job running in the background */
    if (srv_sms_is_sms_ready() == MMI_TRUE)
    {       
        mmi_um_pre_entry_simbox();        
    }    
    else
    {
        mmi_sms_display_popup(
            (UI_string_type) GetString(STR_SMS_MSG_NOT_READY_YET),
            MMI_EVENT_FAILURE);
        g_msg_cntx.sim_msg_ind_in_idle = MMI_FALSE;
        mmi_frm_deregister_deferring_notification(SCR_ID_MSG_SIMBOX_MSG);
        mmi_nmgr_refresh(MMI_NMGR_APP_SIM_SMS, MMI_NMGR_OPTION_USE_DEFAULT);
    }
}
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_set_protocol_event_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_set_protocol_event_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_OP12_MESSAGE_VOICEMAIL__
    srv_sms_set_interrupt_event_handler(EVT_ID_SRV_SMS_NEW_MSG, mmi_msg_handle_new_mt_voicemail, NULL);
#endif /* __MMI_OP12_MESSAGE_VOICEMAIL__ */

    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_UM_GET_MSG_NUM_REQ, (PsIntFuncPtr)mmi_sms_um_get_num_req_hdlr, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_UM_GET_MSG_LIST_REQ, (PsIntFuncPtr)mmi_sms_um_get_list_info_req_hdlr, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_UM_GET_MSG_INFO_REQ, (PsIntFuncPtr)mmi_sms_um_get_msg_info_req_hdlr, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_UM_DELETE_FOLDER_REQ, (PsIntFuncPtr)mmi_sms_um_del_folder_req_hdlr, MMI_TRUE);

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_UM_MARK_SEVERAL_OP_REQ, (PsIntFuncPtr)mmi_msg_handle_um_multi_op_req, MMI_TRUE);
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */

#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_UM_TRAVERSE_MSG_REQ, (PsIntFuncPtr)mmi_msg_handle_um_traverse_msg_req, MMI_TRUE);
#endif /* __SRV_UM_THREAD_MESSAGE_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_new_sms_flag
 * DESCRIPTION
 *  check whether new sms is vailded in idle, if invalide, need to clear flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_handle_new_sms_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_msg_need_change_new_sms_flag() == MMI_TRUE)
    {
        g_msg_cntx.msg_ind_in_idle = MMI_FALSE;
        mmi_frm_deregister_deferring_notification(SCR_ID_MSG_NEW_MSG_IND);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_need_change_new_sms_flag
 * DESCRIPTION
 *  check whether new sms is vailded in idle, if invalide, need to clear flag
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_msg_need_change_new_sms_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_msg_cntx.msg_ind_in_idle == MMI_TRUE)
    {
        if (g_msg_cntx.msg_ind_index == SRV_SMS_INVALID_MSG_ID)
        {
            result = MMI_TRUE;
        }
        else
        {
            if ((srv_sms_is_msg_exist(g_msg_cntx.msg_ind_index) == MMI_TRUE) &&
                (srv_sms_get_msg_status(g_msg_cntx.msg_ind_index) & SRV_SMS_STATUS_UNREAD))
            {
                result = MMI_TRUE;
            }
        }
    }

    return result;
}


#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_new_sim_sms_flag
 * DESCRIPTION
 *  check whether new sim sms is vailded in idle, if invalide, need to clear flag
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_msg_need_change_new_sim_sms_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_msg_cntx.sim_msg_ind_in_idle == MMI_TRUE)
    {
        if (g_msg_cntx.sim_msg_ind_index == SRV_SMS_INVALID_MSG_ID)
        {
            result = MMI_TRUE;
        }
        else
        {
            if  ((srv_sms_is_msg_exist(g_msg_cntx.sim_msg_ind_index) == MMI_TRUE) &&
                (srv_sms_get_msg_status(g_msg_cntx.sim_msg_ind_index) & SRV_SMS_STATUS_UNREAD)) 
            {
                result = MMI_TRUE;
            }
        }
    }

    return result;
}
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_handle_sms_update_sending_icon_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sms_handle_sms_update_sending_icon_ind(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
    static U16 showIconCount = 0;
    srv_sms_event_update_sending_icon_struct *event_info = 
                        (srv_sms_event_update_sending_icon_struct*)event_data->event_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (event_info->is_show)
    {
        showIconCount++;
        BlinkStatusIcon(STATUS_ICON_SMS_SENDING);
    }
    else
    {
        if (showIconCount)
        {
            showIconCount--;
        }

        if (showIconCount == 0)
        {
            wgui_status_icon_bar_hide_icon(STATUS_ICON_SMS_SENDING);
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_handle_sms_update_unsent_msg_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sms_handle_sms_update_unsent_msg_status(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
    srv_sms_event_update_unsent_msg_status_struct *event_info;
    srv_um_msg_box_enum refresh_box_type = 0;
    U16 unsent_msg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    event_info = (srv_sms_event_update_unsent_msg_status_struct*)event_data->event_info;
    unsent_msg_id = event_info->msg_id;

	switch (event_info->status)
	{
		case SRV_SMS_SEND_SUCCESS:
			{
				srv_um_msg_box_enum box_type;

				box_type = mmi_um_get_current_msg_box_type();

				if (box_type & SRV_UM_MSG_BOX_UNSENT)
				{
					mmi_msg_send_highlight_decided_by_um_ind(SRV_UM_MSG_BOX_UNSENT, (U16)g_msg_cntx.background_sending_index);
				}

				mmi_msg_update_unsent_icon();

				if(srv_sms_is_save_sent_sms_setting(SRV_SMS_SIM_1) == MMI_TRUE)
				{
					refresh_box_type |= SRV_UM_MSG_BOX_SENT;
				}
			}
			break;

		case SRV_SMS_SEND_FAIL:
			{
                if (event_info->is_send_abort == MMI_FALSE)
                {
                    mmi_sms_nmgr_display_popup(
                        (UI_string_type) GetString(STR_SMS_SEND_FAILED),
                        MMI_EVENT_FAILURE);
                }
			}
			break;

		case SRV_SMS_SEND_SENDING:
			{
				g_msg_cntx.background_sending_index = unsent_msg_id;

				mmi_msg_update_unsent_icon();
			}
			break;

		case SRV_SMS_SEND_WAITING:	
		default:
			break;
	}

	refresh_box_type |= SRV_UM_MSG_BOX_UNSENT;

	mmi_sms_send_refresh_ind(refresh_box_type, SRV_UM_REFRESH_NONE);
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_ascii_to_usc2
 * DESCRIPTION
 *  Convert ASCII content to USC2;
 *  Remove Null char which is not end of the message content;
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_ascii_to_usc2(S8* out_usc2, const S8* in_ascii, U16 ascci_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 ascii_index = 0;
	U16 usc2_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	while(ascii_index < ascci_len)
	{
		if (in_ascii[ascii_index] != '\0')
		{
			out_usc2[usc2_index] = in_ascii[ascii_index];
			out_usc2[usc2_index + 1] = 0;

			usc2_index += 2; 
		}
		ascii_index++;
	}

	out_usc2[usc2_index] = 0;
	out_usc2[usc2_index + 1] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_msgbox_caption_string_id
 * DESCRIPTION
 *  Get the msgbox caption string ID
 * PARAMETERS
 *  msgbox_type		[IN] msg type
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_msg_get_msgbox_caption_string_id(U16 msgbox_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 string_id;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch (msgbox_type)
	{
		case SRV_SMS_BOX_INBOX:
			string_id = STR_GLOBAL_INBOX;
			break;
			
		case SRV_SMS_BOX_OUTBOX:
				string_id = STR_UM_SENT_ID;
			break;

	#ifdef __MMI_MESSAGES_DRAFT_BOX__
		case SRV_SMS_BOX_DRAFTS:
			string_id = STR_DRAFTBOX_MENUENTRY;
			break;
	#endif /* __MMI_MESSAGES_DRAFT_BOX__ */

		case SRV_SMS_BOX_UNSENT:
			string_id = STR_GLOBAL_OUTBOX;
			break;

	#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
		case SRV_SMS_BOX_ARCHIVE:
			string_id = STR_UM_ARCHIVE_ID;
			break;
	#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */ 

	#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
		case SRV_SMS_BOX_SIM:
			string_id = STR_SIMBOX_MENUENTRY;
			break;
	#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */ 

		default:
			string_id = 0;
			break;
	}

	return string_id;
}


#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
typedef struct
{
	srv_um_mark_several_op_req_struct req_data;
	srv_um_mark_several_op_rsp_struct rsp_data;
}mmi_msg_um_multi_op_data_struct;

static void mmi_msg_um_multi_op_free_data(void);
static void mmi_msg_um_multi_op_delete_req(void);
static void mmi_msg_um_multi_op_delete_rsp(srv_sms_callback_struct* callback_data);
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
static void mmi_msg_um_multi_op_move_to_archive_req(void);
static void mmi_msg_um_multi_op_move_to_archive_rsp(srv_sms_callback_struct* callback_data);
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

#ifdef __MMI_MESSAGES_COPY__
static void mmi_msg_um_multi_op_copy_to_phone_req(void);
static void mmi_msg_um_multi_op_copy_to_phone_rsp(srv_sms_callback_struct* callback_data);
static void mmi_msg_um_multi_op_move_to_phone_req(void);
static void mmi_msg_um_multi_op_move_to_phone_rsp(srv_sms_callback_struct* callback_data);
static void mmi_msg_um_multi_op_copy_to_sim_req(void);
static void mmi_msg_um_multi_op_copy_to_sim_rsp(srv_sms_callback_struct* callback_data);
static void mmi_msg_um_multi_op_move_to_sim_req(void);
static void mmi_msg_um_multi_op_move_to_sim_rsp(srv_sms_callback_struct* callback_data);
#endif /* __MMI_MESSAGES_COPY__ */
static void mmi_msg_um_multi_op_send_rsp_to_um(void);

static mmi_msg_um_multi_op_data_struct *msg_multi_op_data;


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_um_multi_op_init_data
 * DESCRIPTION
 *  init the data for UM multi-operate
 * PARAMETERS
 *  in_msg		[IN] multi-operate request data	
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_um_multi_op_init_data(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_um_mark_several_op_req_struct *req_msg = (srv_um_mark_several_op_req_struct*)in_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT((req_msg->msg_number > 0) && (req_msg->msg_number <= SRV_UM_MAX_MSG_PER_MARK_SEVERAL_OP));

	if (msg_multi_op_data != NULL)
	{
		OslMfree(msg_multi_op_data);
	}

	msg_multi_op_data = OslMalloc(sizeof(mmi_msg_um_multi_op_data_struct));
	
	memcpy(&msg_multi_op_data->req_data, req_msg, sizeof(srv_um_mark_several_op_req_struct));

	msg_multi_op_data->rsp_data.msg_type 	 = req_msg->msg_type;
	msg_multi_op_data->rsp_data.app_id 	 	 = req_msg->app_id;
	msg_multi_op_data->rsp_data.msg_box_type = req_msg->msg_box_type;
	msg_multi_op_data->rsp_data.action_type  = req_msg->action_type;
	msg_multi_op_data->rsp_data.msg_number   = 0;

	memset(&msg_multi_op_data->rsp_data.msg_id, 0, sizeof(msg_multi_op_data->rsp_data.msg_id));
	memset(&msg_multi_op_data->rsp_data.action_result, 0, sizeof(msg_multi_op_data->rsp_data.action_result));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_um_multi_op_free_data
 * DESCRIPTION
 *  free the data for UM multi-operate
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_msg_um_multi_op_free_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (msg_multi_op_data != NULL)
	{
		OslMfree(msg_multi_op_data);
		msg_multi_op_data = NULL;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_um_multi_op_delete
 * DESCRIPTION
 *  Handle UM delete multi message
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_um_multi_op_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_msg_um_multi_op_delete_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_um_multi_op_delete_req
 * DESCRIPTION
 *  UM multi-operate delete msg request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_msg_um_multi_op_delete_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 msg_id = msg_multi_op_data->req_data.msg_id[msg_multi_op_data->rsp_data.msg_number];
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (msg_id == SRV_SMS_INVALID_MSG_ID)
	{
	    srv_sms_callback_struct callback_data;
        callback_data.result = MMI_FALSE;
		mmi_msg_um_multi_op_delete_rsp(&callback_data);
	}
	else
	{
    #ifdef __MMI_UM_REPORT_BOX__
        if (msg_multi_op_data->req_data.msg_box_type == SRV_UM_MSG_BOX_REPORT)
        {
            U16 report_id;
	        srv_sms_callback_struct callback_data;

            report_id = srv_sms_msg_id_to_report_id((U16)msg_id);

            callback_data.result = srv_sms_delete_status_report(report_id);

    		mmi_msg_um_multi_op_delete_rsp(&callback_data);
        }
        else
	#endif /* __MMI_UM_REPORT_BOX__ */
        {
    	    srv_sms_delete_msg((U16)msg_id, mmi_msg_um_multi_op_delete_rsp, NULL);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_um_multi_op_delete_rsp
 * DESCRIPTION
 *  UM multi-operate delete msg response
 * PARAMETERS
 *  dummy       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_msg_um_multi_op_delete_rsp(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 index = msg_multi_op_data->rsp_data.msg_number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (callback_data->result == MMI_TRUE)
	{
        mmi_msg_handle_new_sms_flag();

	    mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_1);
        mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_2);
    #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
        mmi_msg_update_unsent_icon();
    #endif
        
		msg_multi_op_data->rsp_data.action_result[index] = KAL_TRUE;
	}
	else
	{
		msg_multi_op_data->rsp_data.action_result[index] = KAL_FALSE;
	}

	msg_multi_op_data->rsp_data.msg_id[index] = msg_multi_op_data->req_data.msg_id[index];

	msg_multi_op_data->rsp_data.msg_number++;

	if (msg_multi_op_data->rsp_data.msg_number < msg_multi_op_data->req_data.msg_number)
	{
		mmi_msg_um_multi_op_delete_req();
	}
	else
	{
		mmi_msg_um_multi_op_send_rsp_to_um();
		mmi_msg_um_multi_op_free_data();
	}
}


#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_um_multi_op_move_to_archive
 * DESCRIPTION
 *  Handle UM move multi message to archive
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_um_multi_op_move_to_archive(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_msg_box_enum um_box_type = msg_multi_op_data->req_data.msg_box_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ((um_box_type & SRV_UM_MSG_BOX_INBOX) || (um_box_type & SRV_UM_MSG_BOX_SENT))
	{	
		mmi_msg_um_multi_op_move_to_archive_req();
	}
	else
	{
		msg_multi_op_data->rsp_data.msg_number = msg_multi_op_data->req_data.msg_number;

		memcpy(
			&msg_multi_op_data->rsp_data.msg_id, 
			&msg_multi_op_data->req_data.msg_id,
			sizeof(msg_multi_op_data->rsp_data.msg_id));

		memset(
			&msg_multi_op_data->rsp_data.action_result, 
			KAL_FALSE,
			sizeof(msg_multi_op_data->rsp_data.action_result));

		mmi_msg_um_multi_op_send_rsp_to_um();
		mmi_msg_um_multi_op_free_data();
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_um_multi_op_move_to_archive_req
 * DESCRIPTION
 *  UM multi-operate move to archive request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_msg_um_multi_op_move_to_archive_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 msg_id = msg_multi_op_data->req_data.msg_id[msg_multi_op_data->rsp_data.msg_number];
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (msg_id == SRV_SMS_INVALID_MSG_ID)
	{
        srv_sms_callback_struct cb_data;
        cb_data.result = MMI_FALSE;

		mmi_msg_um_multi_op_move_to_archive_rsp(&cb_data);
	}
	else
	{
        srv_sms_mti_enum sms_mti;
        srv_sms_status_enum status;

        sms_mti = srv_sms_get_msg_mti((U16)msg_id);
        status = srv_sms_get_msg_status((U16)msg_id);
        
        /* Can't move the status repoert or unsupport SMS to archive */
        if ((sms_mti == SRV_SMS_MTI_STATUS_REPORT) ||
            (status & SRV_SMS_STATUS_UNSUPPORTED))
        {
        	srv_sms_callback_struct cb_data;
            cb_data.result = MMI_FALSE;

            mmi_msg_um_multi_op_move_to_archive_rsp(&cb_data);
        }
        else
        {
            srv_sms_move_msg_to_archive(
                (U16)msg_id,
                mmi_msg_um_multi_op_move_to_archive_rsp,
                NULL);
        }
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_um_multi_op_move_to_archive_rsp
 * DESCRIPTION
 *  UM multi-operate move to archive response
 * PARAMETERS
 *  dummy       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_msg_um_multi_op_move_to_archive_rsp(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 index = msg_multi_op_data->rsp_data.msg_number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (callback_data->result == MMI_TRUE)
	{
        mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_1);
        mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_2);

		msg_multi_op_data->rsp_data.action_result[index] = KAL_TRUE;
	}
	else
	{
		msg_multi_op_data->rsp_data.action_result[index] = KAL_FALSE;
	}

	msg_multi_op_data->rsp_data.msg_id[index] = msg_multi_op_data->req_data.msg_id[index];

	msg_multi_op_data->rsp_data.msg_number++;

	if (msg_multi_op_data->rsp_data.msg_number < msg_multi_op_data->req_data.msg_number)
	{
		mmi_msg_um_multi_op_move_to_archive_req();
	}
	else
	{
		mmi_msg_um_multi_op_send_rsp_to_um();
		mmi_msg_um_multi_op_free_data();
	}
}
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/


#ifdef __MMI_MESSAGES_COPY__
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_um_multi_op_copy_to_phone
 * DESCRIPTION
 *  Handle UM copy to phone multi message
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_um_multi_op_copy_to_phone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_msg_um_multi_op_copy_to_phone_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_um_multi_op_copy_to_phone_req
 * DESCRIPTION
 *  UM multi-operate copy to phone request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_msg_um_multi_op_copy_to_phone_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 msg_id = msg_multi_op_data->req_data.msg_id[msg_multi_op_data->rsp_data.msg_number];
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (msg_id == SRV_SMS_INVALID_MSG_ID)
	{
	    srv_sms_callback_struct callback_data;
        callback_data.result = MMI_FALSE;
		mmi_msg_um_multi_op_copy_to_phone_rsp(&callback_data);
	}
	else
	{
	    srv_sms_copy_msg((U16)msg_id, SRV_SMS_STORAGE_ME, mmi_msg_um_multi_op_copy_to_phone_rsp, NULL);
	}

}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_um_multi_op_copy_to_phone_rsp
 * DESCRIPTION
 *  UM multi-operate copy to phone response
 * PARAMETERS
 *  callback_data  :[IN]       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_msg_um_multi_op_copy_to_phone_rsp(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 index = msg_multi_op_data->rsp_data.msg_number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (callback_data->result == MMI_TRUE)
	{
	    mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_1);
        mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_2);
		msg_multi_op_data->rsp_data.action_result[index] = KAL_TRUE;
	}
	else
	{
		msg_multi_op_data->rsp_data.action_result[index] = KAL_FALSE;
	}

	msg_multi_op_data->rsp_data.msg_id[index] = msg_multi_op_data->req_data.msg_id[index];

	msg_multi_op_data->rsp_data.msg_number++;

	if (msg_multi_op_data->rsp_data.msg_number < msg_multi_op_data->req_data.msg_number)
	{
		mmi_msg_um_multi_op_copy_to_phone_req();
	}
	else
	{
		mmi_msg_um_multi_op_send_rsp_to_um();
		mmi_msg_um_multi_op_free_data();
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_um_multi_op_move_to_phone
 * DESCRIPTION
 *  Handle UM move to phone multi message
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_um_multi_op_move_to_phone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_msg_um_multi_op_move_to_phone_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_um_multi_op_move_to_phone_req
 * DESCRIPTION
 *  UM multi-operate move to phone request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_msg_um_multi_op_move_to_phone_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 msg_id = msg_multi_op_data->req_data.msg_id[msg_multi_op_data->rsp_data.msg_number];
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (msg_id == SRV_SMS_INVALID_MSG_ID)
	{
	    srv_sms_callback_struct callback_data;
        callback_data.result = MMI_FALSE;
		mmi_msg_um_multi_op_move_to_phone_rsp(&callback_data);
	}
	else
	{
	    srv_sms_move_msg((U16)msg_id, SRV_SMS_STORAGE_ME, mmi_msg_um_multi_op_move_to_phone_rsp, NULL);
	}

}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_um_multi_op_move_to_phone_rsp
 * DESCRIPTION
 *  UM multi-operate move to phone response
 * PARAMETERS
 *  callback_data  :[IN]       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_msg_um_multi_op_move_to_phone_rsp(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 index = msg_multi_op_data->rsp_data.msg_number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (callback_data->result == MMI_TRUE)
	{
        mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_1);
        mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_2);

		msg_multi_op_data->rsp_data.action_result[index] = KAL_TRUE;
	}
	else
	{
		msg_multi_op_data->rsp_data.action_result[index] = KAL_FALSE;
	}

	msg_multi_op_data->rsp_data.msg_id[index] = msg_multi_op_data->req_data.msg_id[index];

	msg_multi_op_data->rsp_data.msg_number++;

	if (msg_multi_op_data->rsp_data.msg_number < msg_multi_op_data->req_data.msg_number)
	{
		mmi_msg_um_multi_op_move_to_phone_req();
	}
	else
	{
		mmi_msg_um_multi_op_send_rsp_to_um();
		mmi_msg_um_multi_op_free_data();
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_um_multi_op_copy_to_sim
 * DESCRIPTION
 *  Handle UM copy to sim multi message
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_um_multi_op_copy_to_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_msg_um_multi_op_copy_to_sim_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_um_multi_op_copy_to_sim_req
 * DESCRIPTION
 *  UM multi-operate copy to sim request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_msg_um_multi_op_copy_to_sim_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 msg_id = msg_multi_op_data->req_data.msg_id[msg_multi_op_data->rsp_data.msg_number];
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (msg_id == SRV_SMS_INVALID_MSG_ID)
	{
	    srv_sms_callback_struct callback_data;
        callback_data.result = MMI_FALSE;
		mmi_msg_um_multi_op_copy_to_sim_rsp(&callback_data);
	}
	else
	{
	    srv_sms_copy_msg((U16)msg_id, SRV_SMS_STORAGE_SIM, mmi_msg_um_multi_op_copy_to_sim_rsp, NULL);
	}

}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_um_multi_op_copy_to_sim_rsp
 * DESCRIPTION
 *  UM multi-operate copy to sim response
 * PARAMETERS
 *  callback_data  :[IN]       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_msg_um_multi_op_copy_to_sim_rsp(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 index = msg_multi_op_data->rsp_data.msg_number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (callback_data->result == MMI_TRUE)
	{
        mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_1);
        mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_2);

		msg_multi_op_data->rsp_data.action_result[index] = KAL_TRUE;
	}
	else
	{
		msg_multi_op_data->rsp_data.action_result[index] = KAL_FALSE;
	}

	msg_multi_op_data->rsp_data.msg_id[index] = msg_multi_op_data->req_data.msg_id[index];

	msg_multi_op_data->rsp_data.msg_number++;

	if (msg_multi_op_data->rsp_data.msg_number < msg_multi_op_data->req_data.msg_number)
	{
		mmi_msg_um_multi_op_copy_to_sim_req();
	}
	else
	{
		mmi_msg_um_multi_op_send_rsp_to_um();
		mmi_msg_um_multi_op_free_data();
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_um_multi_op_move_to_sim
 * DESCRIPTION
 *  Handle UM move to sim multi message
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_um_multi_op_move_to_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_msg_um_multi_op_move_to_sim_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_um_multi_op_move_to_sim_req
 * DESCRIPTION
 *  UM multi-operate move to sim request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_msg_um_multi_op_move_to_sim_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 msg_id = msg_multi_op_data->req_data.msg_id[msg_multi_op_data->rsp_data.msg_number];
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (msg_id == SRV_SMS_INVALID_MSG_ID)
	{
	    srv_sms_callback_struct callback_data;
        callback_data.result = MMI_FALSE;
		mmi_msg_um_multi_op_move_to_sim_rsp(&callback_data);
	}
	else
	{
	    srv_sms_move_msg((U16)msg_id, SRV_SMS_STORAGE_SIM, mmi_msg_um_multi_op_move_to_sim_rsp, NULL);
	}

}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_um_multi_op_move_to_sim_rsp
 * DESCRIPTION
 *  UM multi-operate move to sim response
 * PARAMETERS
 *  callback_data  :[IN]       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_msg_um_multi_op_move_to_sim_rsp(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 index = msg_multi_op_data->rsp_data.msg_number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (callback_data->result == MMI_TRUE)
	{
        mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_1);
        mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_2);

		msg_multi_op_data->rsp_data.action_result[index] = KAL_TRUE;
	}
	else
	{
		msg_multi_op_data->rsp_data.action_result[index] = KAL_FALSE;
	}

	msg_multi_op_data->rsp_data.msg_id[index] = msg_multi_op_data->req_data.msg_id[index];

	msg_multi_op_data->rsp_data.msg_number++;

	if (msg_multi_op_data->rsp_data.msg_number < msg_multi_op_data->req_data.msg_number)
	{
		mmi_msg_um_multi_op_move_to_sim_req();
	}
	else
	{
		mmi_msg_um_multi_op_send_rsp_to_um();
		mmi_msg_um_multi_op_free_data();
	}
}
#endif /* __MMI_MESSAGES_COPY__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_um_multi_op_send_rsp_to_um
 * DESCRIPTION
 *  Send mulit operate respone to UM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_msg_um_multi_op_send_rsp_to_um(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_um_mark_several_op_rsp_struct *rsp_msg;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp_msg = (srv_um_mark_several_op_rsp_struct*)construct_local_para(
	   			  sizeof(srv_um_mark_several_op_rsp_struct), TD_CTRL | TD_RESET);

	rsp_msg->msg_type = msg_multi_op_data->rsp_data.msg_type;
	rsp_msg->app_id = msg_multi_op_data->rsp_data.app_id;
	rsp_msg->msg_box_type = msg_multi_op_data->rsp_data.msg_box_type;
	rsp_msg->action_type = msg_multi_op_data->rsp_data.action_type;
	rsp_msg->msg_number = msg_multi_op_data->rsp_data.msg_number;

	memcpy(rsp_msg->msg_id, &msg_multi_op_data->rsp_data.msg_id, sizeof(rsp_msg->msg_id));
	memcpy(rsp_msg->action_result, &msg_multi_op_data->rsp_data.action_result, sizeof(rsp_msg->action_result));
	
    mmi_msg_send_message(
    	MOD_MMI,
    	MOD_MMI,
    	0,
    	MSG_ID_MMI_UM_MARK_SEVERAL_OP_RSP,
    	(oslParaType*)rsp_msg,
    	NULL);
}
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_handle_new_msg_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_data      [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
mmi_ret mmi_sms_handle_new_msg_ind(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
    srv_sms_event_new_sms_struct* event_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    event_info = (srv_sms_event_new_sms_struct*)event_data->event_info;
#if defined (__WS_HOME_SAFE__)
{
	extern void hf_new_msg_ind(char * rev_num,char * rev_content);
	char sms_content[400] = {0};

	srv_sms_new_msg_struct *new_msg_data = (srv_sms_new_msg_struct*)event_info->msg_data;
	mmi_ucs2_to_asc((S8 *)sms_content, (S8 *)event_info->content);
	hf_new_msg_ind(new_msg_data->number,sms_content);
	return MMI_RET_OK;
}	
#endif

    if (event_info->msg_id == SRV_SMS_INVALID_MSG_ID)
    {
        mmi_msg_handle_class0_msg_ind(event_info);
    }
    else
    {
        mmi_msg_new_msg_ind(event_info);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_handle_sync_msgbox_with_at
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_data      [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
mmi_ret mmi_sms_handle_sync_msgbox_with_at(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
    srv_sms_event_at_cmd_ind_struct *event_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    event_info = (srv_sms_event_at_cmd_ind_struct*)event_data->event_info;
    mmi_sms_update_msg_screen(MMI_TRUE, MMI_FALSE);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_handle_msg_add_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_data      [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
mmi_ret mmi_sms_handle_msg_add_event(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
    srv_sms_event_add_struct *event_info;
    srv_um_msg_box_enum msg_box_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_is_sms_ready() == MMI_TRUE)
    {
        event_info = (srv_sms_event_add_struct*)event_data->event_info;

        msg_box_type = mmi_sms_um_get_um_box_type(
                        event_info->msg_info.status,
                        event_info->msg_info.folder_id,
                        event_info->msg_info.storage_type);

        mmi_sms_send_refresh_ind(msg_box_type, SRV_UM_REFRESH_NONE);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_handle_msg_del_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_data      [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
mmi_ret mmi_sms_handle_msg_del_event(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
    srv_sms_event_delete_struct *event_info;
    srv_um_msg_box_enum msg_box_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    event_info = (srv_sms_event_delete_struct*)event_data->event_info;

    if (srv_sms_is_sms_ready() == MMI_TRUE)
    {
        msg_box_type = mmi_sms_um_get_um_box_type(
                        event_info->msg_info.status,
                        event_info->msg_info.folder_id,
                        event_info->msg_info.storage_type);

        mmi_sms_send_refresh_ind(msg_box_type, SRV_UM_REFRESH_NONE);
    }

    if (event_info->msg_id == g_sms_cntx.curr_msg_id || event_info->msg_id == g_sms_cntx.ind_msg_index)
    {
    #ifdef __MMI_UM_ITERATOR_VIEWER__
        if (mmi_frm_scrn_is_present(g_sms_gid, SCR_ID_SMS_VIEWER, MMI_FRM_NODE_ALL_FLAG)
            && (MMI_FALSE == g_sms_cntx.is_from_hs)
            && (g_sms_cntx.is_del_msg)
            )
        {
            mmi_sms_update_msg_screen(MMI_FALSE, MMI_FALSE);
        }
        else
    #endif
        {
            mmi_sms_update_msg_screen(MMI_TRUE, MMI_FALSE);
        }
    }

    if(event_info->msg_info.status & SRV_SMS_STATUS_UNREAD)
    {
	    mmi_sms_update_new_sms_ind(event_info->msg_info.storage_type);
    }

#ifdef __MMI_UM_ITERATOR_VIEWER__
    if (event_info->msg_id == g_sms_cntx.curr_msg_id)
    {
        mmi_sms_iter_viewer_handle_curr_msg_deleted();
    }
#endif /* __MMI_UM_ITERATOR_VIEWER__ */

#ifdef __MMI_SMS_DETAILS_INFO__
    if ((event_info->msg_id == g_sms_cntx.curr_msg_id)
        && mmi_frm_scrn_is_present(g_sms_gid, SCR_ID_SMS_OPTION_DETAILS, MMI_FRM_NODE_ALL_FLAG))
    {
        if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) <= 0)
        {
            mmi_sms_display_popup(
                (UI_string_type) GetString(STR_ID_SMS_MESSAGES_UPDATED),
                MMI_EVENT_PROGRESS);
        }

        mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_OPTION_DETAILS);
    }
#endif /* __MMI_SMS_DETAILS_INFO__ */

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_handle_msg_update_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_data      [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
mmi_ret mmi_sms_handle_msg_update_event(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
    srv_sms_event_update_struct *event_info;
    srv_um_msg_box_enum src_box_type;
    srv_um_msg_box_enum dest_box_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_is_sms_ready() == MMI_TRUE)
    {
        event_info = (srv_sms_event_update_struct*)event_data->event_info;

        if (event_info->change_para_flag & SRV_SMS_PARA_STATUS)
        {
            if ((event_info->old_msg_info.status == SRV_SMS_STATUS_UNREAD) ||
                (event_info->old_msg_info.status == SRV_SMS_STATUS_READ))
            {
            #ifndef __MMI_DUAL_SIM_MASTER__
                if (event_info->old_msg_info.sim_id == SRV_SMS_SIM_2)
                {
                    mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_2);
                }
                else
            #endif
                {
                    mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_1);
                }
            }

        #ifdef __MMI_SMS_DETAILS_INFO__
        #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
            if ((event_info->old_msg_info.status == SRV_SMS_STATUS_UNSENT) &&
                (event_info->new_msg_info.status == SRV_SMS_STATUS_SENT)
                )
            {
                if ((event_info->msg_id == g_sms_cntx.curr_msg_id)
                    && mmi_frm_scrn_is_present(g_sms_gid, SCR_ID_SMS_OPTION_DETAILS, MMI_FRM_NODE_ALL_FLAG))
                {
                    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) <= 0)
                    {
                        mmi_sms_display_popup(
                            (UI_string_type) GetString(STR_ID_SMS_MESSAGES_UPDATED),
                            MMI_EVENT_PROGRESS);
                    }

                    mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_OPTION_DETAILS);
                }
            }
        #endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
        #endif /* __MMI_SMS_DETAILS_INFO__ */
        }

        src_box_type = mmi_sms_um_get_um_box_type(
                        event_info->old_msg_info.status,
                        event_info->old_msg_info.folder_id,
                        event_info->old_msg_info.storage_type);

        dest_box_type = mmi_sms_um_get_um_box_type(
                            event_info->new_msg_info.status,
                            event_info->new_msg_info.folder_id,
                            event_info->new_msg_info.storage_type);

        if ((event_info->change_para_flag == SRV_SMS_PARA_STATUS)
            && ((event_info->old_msg_info.status == SRV_SMS_STATUS_UNREAD) ||(event_info->old_msg_info.status == SRV_SMS_STATUS_READ))
            )
        {
            mmi_sms_send_refresh_ind((src_box_type | dest_box_type), SRV_UM_REFRESH_MSG_STATUS_CHANGED);
        }
        else
        {
            mmi_sms_send_refresh_ind((src_box_type | dest_box_type), SRV_UM_REFRESH_NONE);
        }

        if ((event_info->old_msg_info.status & SRV_SMS_STATUS_UNREAD)
            && (event_info->new_msg_info.status & SRV_SMS_STATUS_READ)
            )
        {
            mmi_sms_update_new_sms_ind(event_info->old_msg_info.storage_type);
        }

    #ifdef __MMI_SMS_DETAILS_INFO__
    #ifdef __MMI_UM_REPORT_STATUS_IN_SENT_BOX__
        if (event_info->change_para_flag & SRV_SMS_PARA_DELIVERY_STATUS)
        {
            if ((event_info->old_msg_info.status == SRV_SMS_STATUS_SENT) &&
                (event_info->new_msg_info.status == SRV_SMS_STATUS_SENT)
                )
            {
                if ((SCR_ID_SMS_OPTION_DETAILS == mmi_frm_scrn_get_active_id())
                    && (event_info->msg_id == g_sms_cntx.curr_msg_id)
                    )
                {
                    mmi_sms_display_popup(
                        (UI_string_type) GetString(STR_ID_SMS_MESSAGES_UPDATED),
                        MMI_EVENT_PROGRESS);
                }
            }
        }
    #endif /* __MMI_UM_REPORT_STATUS_IN_SENT_BOX__ */
    #endif /* __MMI_SMS_DETAILS_INFO__ */
        mmi_sms_set_msg_icon(MMI_FALSE, (SRV_SMS_SIM_1 | SRV_SMS_SIM_2));
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_handle_report_change_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_data      [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
mmi_ret mmi_sms_handle_report_change_event(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UM_REPORT_BOX__
    mmi_sms_send_refresh_ind(SRV_UM_MSG_BOX_REPORT, SRV_UM_REFRESH_NONE);
#endif /* __MMI_UM_REPORT_BOX__ */

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_handle_um_enter_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_data      [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
mmi_ret mmi_sms_handle_um_enter_folder(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_entry_folder_evt_struct* event_data = (mmi_um_entry_folder_evt_struct*)evt;
    srv_um_msg_box_enum um_msg_box = event_data->msg_box;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (um_msg_box & SRV_UM_MSG_BOX_INBOX)
    {
        g_msg_cntx.msg_ind_in_idle = MMI_FALSE;
    }

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    if (um_msg_box & SRV_UM_MSG_BOX_SIM)
    {
        g_msg_cntx.sim_msg_ind_in_idle = MMI_FALSE;
    }
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

#ifdef __MMI_UM_REPORT_BOX__
    if (um_msg_box & SRV_UM_MSG_BOX_REPORT)
    {
        g_sms_cntx.report_count = 0;
    }
#endif /* __MMI_UM_REPORT_BOX__ */

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_handle_sim_refresh_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_data      [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
mmi_ret mmi_sms_handle_sim_refresh_ind(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* For L4C_AT_SMS_ADD, the refresh ind would be sent in mmi_frm_sms_get_sms_rsp() */
    mmi_sms_send_refresh_ind(SRV_UM_MSG_BOX_INBOX | SRV_UM_MSG_BOX_UNSENT | SRV_UM_MSG_BOX_SENT |
                             SRV_UM_MSG_BOX_DRAFT
                        #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
                                 | SRV_UM_MSG_BOX_SIM
                        #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
                            , SRV_UM_REFRESH_NONE);
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_update_msg_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_update_msg      [IN]
 *  is_update_icon      [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static void mmi_sms_update_msg_screen(MMI_BOOL is_update_msg, MMI_BOOL is_update_icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_refresh = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((is_update_msg)
        && mmi_frm_scrn_is_present(g_sms_gid, SCR_ID_SMS_VIEWER, MMI_FRM_NODE_ALL_FLAG))
    {
        is_refresh = MMI_TRUE;
    }

    /* For the case of SIM Refresh, the msg screens should be deleted in mmi_frm_sms_sim_refresh_ind() */
    /* If the SMS screens cannot be deleted, do not show the done pupup. */
    if (is_refresh == MMI_TRUE)
    {
        /* Do not interrupt calling screen */
        if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) <= 0)
        {
            mmi_sms_display_popup(
                (UI_string_type) GetString(STR_ID_SMS_MESSAGES_UPDATED),
                MMI_EVENT_PROGRESS);
        }

        /* Viewer related */
        if (g_sms_gid != GRP_ID_INVALID)
        {
            mmi_frm_group_close(g_sms_gid);
        }
    }
#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP11_HOMESCREEN__ */

#if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    mmi_sms_update_sidebar_info();
    mmi_sms_update_shct_data();
#endif /* #if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    mmi_msg_update_unsent_icon();
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

    /* For L4C_AT_SMS_DELETE, if new msg is deleted, will clear new msg flag */

    mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_1);
    mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_update_new_sms_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_update_msg      [IN]
 *  is_update_icon      [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static void mmi_sms_update_new_sms_ind(srv_sms_storage_enum storage_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* For L4C_AT_SMS_DELETE, if new msg is deleted, will clear new msg flag */
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    if ((storage_type == SRV_SMS_STORAGE_SIM) && g_msg_cntx.sim_msg_ind_in_idle)
    {
        if (srv_sms_is_msg_exist(g_msg_cntx.sim_msg_ind_index) == MMI_TRUE)
        {
            srv_sms_status_enum status;

            status = srv_sms_get_msg_status(g_msg_cntx.sim_msg_ind_index);

            if (status & SRV_SMS_STATUS_READ)
            {
                g_msg_cntx.sim_msg_ind_in_idle = MMI_FALSE;
            }
        }
        else
        {
            g_msg_cntx.sim_msg_ind_in_idle = MMI_FALSE;
        }

        mmi_nmgr_refresh(MMI_NMGR_APP_SIM_SMS, MMI_NMGR_OPTION_USE_DEFAULT);
    }
    else if (storage_type == SRV_SMS_STORAGE_ME)
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    {
        if (g_msg_cntx.msg_ind_in_idle)
        {
            if (srv_sms_is_msg_exist(g_msg_cntx.msg_ind_index) == MMI_TRUE)
            {
                srv_sms_status_enum status;

                status = srv_sms_get_msg_status(g_msg_cntx.msg_ind_index);

                if (status & SRV_SMS_STATUS_READ)
                {
                    g_msg_cntx.msg_ind_in_idle = MMI_FALSE;
                }
            }
            else
            {
                g_msg_cntx.msg_ind_in_idle = MMI_FALSE;
            }

            mmi_nmgr_refresh(MMI_NMGR_APP_SMS, MMI_NMGR_OPTION_USE_DEFAULT);
        }
    }
}


#ifdef __MMI_UM_ITERATOR_VIEWER__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_box_to_sms_box
 * DESCRIPTION
 *  convert the UM box type to SMS type
 * PARAMETERS
 *  msg_box_type        [IN]     UM Box type   
 * RETURNS
 *  void
 *****************************************************************************/
static srv_sms_box_enum mmi_sms_um_box_to_sms_box(srv_um_msg_box_enum um_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_sms_box_enum sms_box_type = SRV_SMS_BOX_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (um_box_type & SRV_UM_MSG_BOX_INBOX)
    {
        sms_box_type |= SRV_SMS_BOX_INBOX;
    }

    if (um_box_type & SRV_UM_MSG_BOX_UNSENT)
    {
        sms_box_type |= SRV_SMS_BOX_UNSENT;
    }

    if (um_box_type & SRV_UM_MSG_BOX_SENT)
    {
        sms_box_type |= SRV_SMS_BOX_OUTBOX;
    }

    if (um_box_type & SRV_UM_MSG_BOX_DRAFT)
    {
        sms_box_type |= SRV_SMS_BOX_DRAFTS;
    }

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__  
    if (um_box_type & SRV_UM_MSG_BOX_ARCHIVE)
    {
        sms_box_type |= SRV_SMS_BOX_ARCHIVE;
    }
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    if (um_box_type & SRV_UM_MSG_BOX_SIM)
    {
        sms_box_type |= SRV_SMS_BOX_SIM;
    }
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

#ifdef __MMI_UM_REPORT_BOX__
    if (um_box_type & SRV_UM_MSG_BOX_REPORT)
    {
        sms_box_type |= SRV_SMS_BOX_REPORT;
    }
#endif /* __MMI_UM_REPORT_BOX__ */

	return sms_box_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_iterator_viewer_refresh_hdlr
 * DESCRIPTION
 *  Handle message being deleted or moved to archive when at iterator viewer
 *  screen.
 * PARAMETERS
 *  is_update_msg      [IN]
 *  is_update_icon      [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
mmi_ret mmi_sms_iterator_viewer_refresh_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_refresh_evt_struct* refresh_ind = (mmi_um_refresh_evt_struct*)evt;
    srv_sms_box_enum sms_msg_box_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_msg_box_type = mmi_sms_um_box_to_sms_box(refresh_ind->msg_box);
    if ((g_sms_cntx.curr_box_type & sms_msg_box_type) && (mmi_frm_scrn_get_active_id() == SCR_ID_SMS_VIEWER || 
        (mmi_frm_scrn_is_present(g_sms_gid, SCR_ID_SMS_VIEWER, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))))
    {
    #if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__)
        mmi_frm_gesture_stop_listen_event();
    #endif /* defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__) */
        if (mmi_sms_iter_viewer_query_indexing())
        {
            mmi_sms_iter_viewer_entry_viewer_scrn();
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_iter_viewer_handle_curr_msg_deleted
 * DESCRIPTION
 *  If the current msg has been deleted or moved at iterator viewer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_iter_viewer_handle_curr_msg_deleted(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_iter_viewer_result_struct *iter_viewer_result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    iter_viewer_result = g_sms_cntx.iter_viewer_result;
    if (iter_viewer_result == NULL)
    {
        return;
    }
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__)
    mmi_frm_gesture_stop_listen_event();
#endif /* defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__) */
    if ((iter_viewer_result->prev_launch_func_ptr == NULL) && (iter_viewer_result->next_launch_func_ptr == NULL))
    {
        mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_VIEWER);
        return;
    }
    else if (iter_viewer_result->next_launch_func_ptr == NULL)
    {
        iter_viewer_result->prev_launch_func_ptr(g_sms_parent_gid, iter_viewer_result->prev_msg_id, g_sms_cntx.user_data, CUI_MSG_VIEWER_TYPE_ITERATOR);
        mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_VIEWER);
    }
    else
    {
        iter_viewer_result->next_launch_func_ptr(g_sms_parent_gid, iter_viewer_result->next_msg_id, g_sms_cntx.user_data, CUI_MSG_VIEWER_TYPE_ITERATOR);
        mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_VIEWER);
    }
}
#endif /* __MMI_UM_ITERATOR_VIEWER__ */


#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_fmgr_format_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sms_fmgr_format_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_fmgr_notification_format_event_struct *event_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    event_data = (srv_fmgr_notification_format_event_struct*)evt;

    if((event_data->state == SRV_FMGR_NOTIFICATION_STATE_AFTER) &&
       ((event_data->drv_letter == 'C') || (event_data->drv_letter == 'D')))
    {
        srv_sms_format_archive();
    }

	return MMI_RET_OK;
}
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_shutdown_deinit_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sms_shutdown_deinit_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeInitMessagesApp();

	return MMI_RET_OK;
}


#endif /* __MOD_SMSAL__ */ 

