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
 * MMITask.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Protocol task functionality.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

   FILENAME : MMItask.c

   PURPOSE     : Protocol task functionality 

   REMARKS     : nil

   AUTHOR      : Neeraj Sharma

   DATE     : Dec' 28, 2002

**************************************************************/

/*****************************************************************************
* Include                                                                     
*****************************************************************************/

#if !defined(__MTK_TARGET__)
#include <windows.h>
#endif 

#include "MMI_features.h"
#include "MMI_include.h"
#include "mmi_frm_gprot.h"
#include "mmi_frm_prot.h"
#include "mmi_frm_ucs2_str_dcl.h"		/* define the string function pointer */
#include "StatusIconRes.h"
/* __CUSTPACK_MULTIBIN     Terry   BEGIN */
#include "wgui_categories_inputs.h"
#include "IMERes.h"
#include "CommonScreensResDef.h"
/* __CUSTPACK_MULTIBIN     Terry   END */
#if defined(__MMI_RESOURCE_ENFB_SUPPORT__)
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */
#include "AllAppGprot.h"
#include "ProtocolEvents.h"
#include "AsyncEventsGprot.h"
#include "ATHandlerProt.h"
#include "AlarmFrameWorkProt.h"
#include "Service.h"
#include "SATGProts.h"
#include "CPHSProtocolHandlers.h"
#include "EngineerModeGprot.h"
#include "FactoryModeProt.h"
#include "gpioInc.h"
#include "PhoneBookGProt.h"
#include "FunAndGamesProts.h"
#include "MessagesResourceData.h"
#include "OrganizerGprot.h"
#include "AlarmGprot.h"
#include "ScheduledPowerOnOffGprot.h"
#include "OrganizerGProt.h"
#include "ExtraGProt.h"
#include "IdleAppProt.h"
#include "IdleHomescreenGprot.h"
#include "IdleVenus.h"
#include "IdleToolbarGprot.h"
#include "Conversions.h"
#include "datetimetype.h"
#include "app_datetime.h"
#include "MessagesExDcl.h"
#include "FlightModeGProt.h"
#include "BootUp.h"
#include "BootupSrvGprot.h"
#include "SmsAppGProt.h"
#include "mmi_cache_table.h"
#include "IdleGprot.h"
#include "CharBatSrvGprot.h"

#ifdef __MMI_USB_SUPPORT__
#include "USBDeviceGprot.h"
extern kal_bool INT_USBBoot(void);
#endif /* __MMI_USB_SUPPORT__ */ 

#ifdef __MMI_IRDA_SUPPORT__
#include "IrdaMMIGprots.h"
#endif 


#ifdef __MMI_BT_SUPPORT__
#include "BTMMIScrGprots.h"
#endif 

#ifdef __MMI_FILE_MANAGER__
#include "FileManagerGProt.h"
#include "msdc_def.h"
#endif /* __MMI_FILE_MANAGER__ */ 
#include "FileMgrSrvGProt.h"

#ifdef __MMI_WEBCAM__
#include "mdi_datatype.h"
#include "mdi_webcam.h"
#endif /* __MMI_WEBCAM__ */ 

#include "SoundEffect.h"

#include "vObjects.h"
#include "vCalendar.h"

#include "ShortcutsProts.h"
//#include "ToDoListDef.h"
#include "DataAccountGProt.h"
#include "WPSSProtos.h"
#if defined(__MMI_STOPWATCH__)
#include "StopwatchGprot.h"
#endif 
#if defined(__MMI_EMAIL__)
#include "EmailAppGProt.h"
#endif /* def __MMI_EMAIL__ */

#ifdef __MMI_EBOOK_READER__
#include "EbookGprot.h"
#endif 
#include "SimDetectionGprot.h"
#include "PowerOnChargerProt.h"
#include "SettingGprots.h"
#include "SimDetectionGexdcl.h"
#include "PhoneSetupGprots.h"   /* PhnsetReadNvramCalibrationData */

#if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
#include "SmsGuiInterfaceType.h"
#endif 

#ifdef __MMI_VOIP__
#include "VoIPGProt.h"
#endif
#ifdef __MMI_UCM__
#include "UCMGProt.h"
#endif

#include "UcmSrvGProt.h"

#ifdef __MMI_POC__
#include "PoCGProt.h"
#endif 

#ifdef __MMI_AVATAR__
#include "avatargprot.h"
#endif


#ifdef __MMI_MY_FAVORITE__
/* under construction !*/
#endif

#if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
#include "HomeScreenOp11V32Gprot.h"
#endif

extern void InitAlarmHandler(void);


#if defined(__MMI_THEMES_APPLICATION__)
extern void InitThemes(void);
#endif

#ifdef __FLIGHT_MODE_SUPPORT__
#include "WallpaperDefs.h"
#include "PhoneSetup.h"
#endif /* __FLIGHT_MODE_SUPPORT__ */ 

extern void ATHandlerInit(void);


extern void PhnsetInitSetTimeNDateNvram(void);
extern void ReadValueCityNVRAM(void);


#include "lcd_sw.h"
#include "lcd_sw_inc.h"

#include "ComposeRingToneProts.h"

#include "gdi_include.h"

#include "UMGProt.h"

#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
#include "UcAppGprot.h"
#endif 

#ifdef __MMI_WLAN_FEATURES__
#include "NetworkSetupDefs.h"
#endif

#ifdef __MMI_PICT_BRIDGE_SUPPORT__
#include "PictBridgeGProt.h"
#endif

#ifdef MMS_SUPPORT
//#include "MMSMsgCommonProt.h"
#endif

#ifdef __MMI_MMS_2__
//#include "MMSViewerAPPDefs.h"
//#include "MMSAppGprot.h"
#include "MMSJsrTypes.h"
#include "MMSJSRProts.h"
#endif /* __MMI_MMS_2__ */
#ifdef __MMI_BROWSER_2__
#include "BrowserGprots.h"
#endif /* __MMI_BROWSER_2__ */

#ifdef __MMI_DM_SELF_REGISTER_SUPPORT__
#include "DmSelfRegisterGprot.h"
#endif /* __MMI_DM_SELF_REGISTER_SUPPORT__ */

#ifdef __DRM_SUPPORT__
#include "RightsMgrGProt.h"
#endif

#ifdef __MMI_MAPBAR_GIS__
#include "MB_GISGProt.h"
#endif

#ifdef __MMI_SUNAVI_GIS__
#include "SN_GISGProt.h"
#endif

#ifdef __MMI_MIGO_GIS__
#include "MG_GISGProt.h"
#endif

#include "mdi_datatype.h"
#include "mdi_include.h"

#ifdef __CERTMAN_SUPPORT__
#include "CertManMMIGprots.h"
#endif

#ifdef __MMI_IPSEC__
#include "IPSecAppGprot.h"
#endif /* __MMI_IPSEC__ */

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_master_header.h"
#endif

#ifdef  __FLAVOR_VENDOR_SDK__
#include "DevAppGprot.h"
#endif

#include "vmsock.h"
#include "vmappcomm.h"

#if defined(OPERA_V10_BROWSER) || defined(__GADGET_SUPPORT__)
#include "npplg_av_include.h"
#endif

#include "GpioSrvGprot.h"
#include "ShutdownSrvGprot.h"
/*****************************************************************************
* Define                                                                      
*****************************************************************************/

/*****************************************************************************
* Typedef                                                                     
*****************************************************************************/

/*****************************************************************************
* Local Variable                                                              
*****************************************************************************/

/*****************************************************************************
* Extern Global Variable                                                      
*****************************************************************************/
oslMsgqid mmi_ext_qid = KAL_NILQ_ID;
MMI_BOOL g_keypad_flag = MMI_FALSE;
U8 g_input_msg_in_queue = 0;
MMI_BOOL framework_initialized = MMI_FALSE;

U8 gInitAllAppFlag = 0;
U8 gInsertSimAppFlag = 0;

MYTIME StartUpTime, LastDuration;

#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
U8 g_sim_insert_state;
U8 g_dual_mode_value;
#endif

extern kal_mutexid mmi_mutex_trace;

#ifdef __MMI_PREFER_INPUT_METHOD__
extern U16 MMI_all_prefered_input_mode_set[IMM_INPUT_MODE_MAX_NUM];
#endif 
extern const sIMEModeDetails *gIMEModeArray;
extern const sIMEModeDetails *gIMEQSearchModeArray;
extern const mmi_imm_input_mode_enum MMI_implement_input_mode_set[];

#ifdef __FLIGHT_MODE_SUPPORT__
extern PHNSET_CNTX g_phnset_cntx;
#endif /* __FLIGHT_MODE_SUPPORT__ */


/*****************************************************************************
* Local Function                                                              
*****************************************************************************/
static void InitializeAll(void);
static void InitEventHandlersBeforePowerOn(void);

static U8 mmi_frm_check_is_valid_msg(MYQUEUE *base, MYQUEUE *msg);

static MMI_BOOL IMECheck(mmi_imm_input_mode_enum IME_Mode, const mmi_imm_input_mode_enum all_implement_IME[]);
/* comment out by Wen, mbj07024
static void InitIME(void);
*/
static void InitIMESetting(const sIMEModeDetails *IMEArray);

/*****************************************************************************
* Extern Global Function                                                      
*****************************************************************************/

extern void applib_mime_init(void);

#ifdef __MMI_WAP_PROF__
extern void mmi_wap_prof_init(void);
#endif /* __MMI_WAP_PROF__ */

extern void goto_opening_screen(void);

extern void InitAllApplications(void);
extern void ReadThemesFromNVRAM(void);
extern void InitializeChargingScr(void);
extern void QuitSystemOperation(void);

extern void setup_UI_wrappers(void);


#ifdef __MMI_PREFER_INPUT_METHOD__
extern U16 MMI_all_prefered_input_mode_set[IMM_INPUT_MODE_MAX_NUM];
#endif

#if defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_PREFER_WRITING_LANG__)
extern ime_writing_lang_struct g_ime_writing_lang_array[12]; /* for 123 and null end */
extern S16 g_ime_main_writing_lang;
#if defined(__MMI_MIXED_LANG_SUPPORT__)
extern S16 g_ime_sub_writing_lang;
#endif /* defined(__MMI_MIXED_LANG_SUPPORT__) */
#endif


extern const sIMEModeDetails *gIMEModeArray;
extern const sIMEModeDetails *gIMEQSearchModeArray;
extern const mmi_imm_input_mode_enum MMI_implement_input_mode_set[];

/* 
 * Move InitPhoneSetupApp() to InitializeAll() for text encoding 
 */
extern void InitAppMem(void);

extern void SetDateTime(void *t);

/* diamond, 2005/07/05 Flight mode */
#ifdef __FLIGHT_MODE_SUPPORT__
extern void PhnsetFlightModeQueryBackground(void);  /* diamond, 2006/01/01 Force to draw the background */
extern void mmi_flight_mode_set_mode(U8 bFlightMode); /* send the mode to L4C ASAP to speed up the L4C startup time */
#endif /* __FLIGHT_MODE_SUPPORT__ */ 
/* end, diamond */

extern void mdi_audio_set_audio_mode(U8 mode);

#ifdef __MMI_SWFLASH__
extern void mmi_swflash_init_app(void);
#endif

#if defined(__GPS_SUPPORT__) || defined(__BT_GPS_SUPPORT__)
extern void InitGPSSetting(void);
extern void mmi_gps_mgr_init(void);
#endif

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
extern void gui_inputs_cache_init_mutex(void);
#endif

#ifdef __MMI_BOOTUP_SCALE__
#define MMI_APP_INIT(func) {U32 start_time, end_time;\
                            S8 func_name[] = #func;\
                            kal_get_time(&start_time);\
                            func;\
                            kal_get_time(&end_time);\
                            Trace2(TRACE_FUNC, "[BOOTUP SCALE]Function: %s Time: %d", func_name, (end_time-start_time));\
                           }
#else
#define MMI_APP_INIT(func)  func
#endif

#ifdef __VENUS_UI_ENGINE__
extern void vfx_mmi_sys_init(void);
extern void vfx_mmi_onidle(void);
extern void vfx_mmi_before_process_msg(void);
extern void vfx_mmi_check_update(void);
#endif

#ifdef __MMI_LCM_PRIMITIVE_FLUSH__    
void mmi_frm_scr_mgm_init(void);
#endif /* __MMI_LCM_PRIMITIVE_FLUSH__ */
/*****************************************************************************
 * FUNCTION
 *  MMI_Init
 * DESCRIPTION
 *  MMI Init Function
 * PARAMETERS
 *  task_indx       [IN]        Index of task
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL MMI_Init(task_indx_type task_indx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mutex_trace = kal_create_mutex("mmi_trace");

    applib_mime_init();
    mmi_frm_init_key_event();
    mmi_frm_fix_mem_init();
    mmi_frm_event_flag_create();
    mmi_frm_init_scenario();


    /* 
     * initial the system service timer 
     */
    L4InitTimer();
    setup_UI_wrappers();

#if defined(__MMI_RESOURCE_ENFB_SUPPORT__)
    /* 
     * Init Resource Memory Manamger  for E-NFB
     */
	mmi_frm_resmem_init();
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

    mmi_fe_init();
#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    /* init the editor cache mutext */
    gui_inputs_cache_init_mutex();
#endif /* GUI_INPUT_BOX_CACHE_SUPPORT */

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_check_wait_to_run
 * DESCRIPTION
 *  This function checks how many jobs want to run in MMI task
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_STATUS_NONE_WANT_TO_RUN     - there is nothing in MMI task.
 *  MMI_STATUS_ONE_WANT_TO_RUN      - there is one job wants to run.
 *  MMI_STATUS_FEW_WANT_TO_RUN      - there are few jobs want to run.
 *  MMI_STATUS_MEDIUM_WANT_TO_RUN   - there are meidum jobs want to run.
 *  MMI_STATUS_MANY_WANT_TO_RUN     - there are many jobs want to run.
 *****************************************************************************/
mmi_status_enum mmi_frm_check_wait_to_run(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 external_queue_node_number = 0;
    U32 circular_queue_node_number = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_fetch_msg_from_extQ_to_circularQ();

    msg_get_ext_queue_info(mmi_ext_qid, &external_queue_node_number);
    circular_queue_node_number = (U32)OslNumOfCircularQMsgs();

    if (IsBitSet(g_input_msg_in_queue, MMI_DEVICE_KEY) || 
        IsBitSet(g_input_msg_in_queue, MMI_DEVICE_PEN))
    {
        return MMI_STATUS_INPUT_EVENTS_WANT_TO_RUN;
    }

    if (IsInNVRAMProcedure() == MMI_FALSE)
    {   /* general case */
        if (external_queue_node_number  == 0)
        {
            if (circular_queue_node_number == 0)
            {
                return MMI_STATUS_NONE_WANT_TO_RUN;
            }
            else if (circular_queue_node_number > (CIRCQ_NO_OF_NODES/4))
            {
                return MMI_STATUS_MANY_WANT_TO_RUN;
            }
            else if (circular_queue_node_number > (CIRCQ_NO_OF_NODES/16))
            {
                return MMI_STATUS_MEDIUM_WANT_TO_RUN;
            }
            else if (circular_queue_node_number > 1)
            {
                return MMI_STATUS_FEW_WANT_TO_RUN;
            }
            else
            {    /* circular_queue_node_number = 1 */
                return MMI_STATUS_ONE_WANT_TO_RUN;
            }
        }
        else
        {
            return MMI_STATUS_MANY_WANT_TO_RUN;
        }
    }
    else
    {   /* In NVRAM procedure */
        return MMI_STATUS_MANY_WANT_TO_RUN;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_fetch_msg_from_extQ_to_circularQ
 * DESCRIPTION
 *  fetch the message from external queue and put
 *  in the circular queue.
 *  (*) Need to set my_index & mmi_ext_qid before using
 *  this function
 * PARAMETERS
 *  void
 * RETURNS
 *  1 - the message is invalid, and discard the message
 *  0 - the message is vaild
 *****************************************************************************/
void mmi_frm_fetch_msg_from_extQ_to_circularQ(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    U32 my_index;
    U32 queue_node_number = 0;
    MYQUEUE checkBaseNode = {0};
    U8 flag = 0;
    ilm_struct ilm_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsInNVRAMProcedure() == MMI_FALSE)
    {
        /*
         * If not in NVRAM access procedure,
         * receive the message from MMI queue and put in circular queue 
         */
        msg_get_ext_queue_info(mmi_ext_qid, &queue_node_number);
        MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_TASK_COPY_EXTERNAL_Q_TO_CIRCULAR_Q, queue_node_number);
        while ((queue_node_number > 0) && !OslIsCircularQFull())
        {
            OslReceiveMsgExtQ(mmi_ext_qid, &Message);
            OslGetMyTaskIndex(&my_index);
            OslStackSetActiveModuleID(my_index, MOD_MMI);
            OslLookUpLastCircularQMsg((void*)&checkBaseNode);

            if (mmi_frm_check_is_valid_msg(&checkBaseNode, &Message) == 1)
            {
                /* put Message in circular queue */
                ilm_ptr.src_mod_id = Message.src_mod_id;
                ilm_ptr.dest_mod_id = Message.dest_mod_id;
                ilm_ptr.msg_id = Message.msg_id;
                ilm_ptr.sap_id = Message.sap_id;
                ilm_ptr.local_para_ptr = Message.local_para_ptr;
                ilm_ptr.peer_buff_ptr = Message.peer_buff_ptr;

                flag = OslWriteCircularQ(&ilm_ptr);

				/* Check if the input message */
				if (Message.msg_id == MSG_ID_MMI_EQ_KEYPAD_DETECT_IND)
				{
					SetBit(g_input_msg_in_queue, MMI_DEVICE_KEY);
				}
				if (Message.msg_id == MSG_ID_TP_EVENT_IND)
				{
					SetBit(g_input_msg_in_queue, MMI_DEVICE_PEN);
				}

                MMI_ASSERT(flag == 1);
                /* TIMER use special data in the local_para_ptr field. Can NOT treat as general ILM */
                if (Message.src_mod_id != MOD_TIMER)
                {
                    hold_local_para(ilm_ptr.local_para_ptr);
                    hold_peer_buff(ilm_ptr.peer_buff_ptr);
                }
            }
            OslFreeInterTaskMsg(&Message);

            msg_get_ext_queue_info(mmi_ext_qid, &queue_node_number);
        }
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_frm_power_on_init_procedure
 * DESCRIPTION
 *  Power on initializations
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_power_on_init_procedure(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static U8 bInit = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!bInit)
    {
        MMI_APP_INIT(InitializeAll());

        bInit = 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_is_mmi_task_started
 * DESCRIPTION
 *  To judge MMI task is start or not
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE  - Has entered MMI task entry function
 *  MMI_FALSE - Has not entered MMI task entry function
 *****************************************************************************/
MMI_BOOL mmi_frm_is_mmi_task_started(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (mmi_ext_qid != KAL_NILQ_ID) ? MMI_TRUE : MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  MMI_task
 * DESCRIPTION
 *  Entry function for Protocol task
 *  
 *  This receives protocol task events from the stack and forwards it to
 *  MMI task.
 * PARAMETERS
 *  entry_param     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MMI_task(oslEntryType *entry_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    oslMsgqid qid;

    U32 my_index;
    U32 count = 0;
    U32 queue_node_number = 0;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    qid = task_info_g[entry_param->task_indx].task_ext_qid;
    mmi_ext_qid = qid;
    mmi_frm_nvram_cache_validate();
    InitEventHandlersBeforePowerOn();
    mmi_frm_set_event_flag(MMI_EVT_F_NOT_IN_NVRAM);
    mmi_frm_set_event_flag(MMI_EVT_F_NOT_IN_GDD);

    while (1)
    {
        {

            if (g_keypad_flag == MMI_TRUE)
            {
                mmi_frm_key_handle(NULL);
            #ifdef __VENUS_UI_ENGINE__
                vfx_mmi_check_update();
            #endif  

            #if defined(__MMI_TOUCH_SCREEN__) && defined(__MTK_TARGET__)
                /* MAUI_01901848
                 * END key down->mmi_pen_disable
                 * so during the END key down, mmi_frm_pen_flush_queue will always return MMI_FALSE
                 * g_has_switch_screen will not has the opportunity to reset to MMI_FALSE;
                 * If the END key's up event is handle here(the upper function) and the Message
                 * MSG_ID_TP_EVENT_IND is in the MMI external queue and it is the first message in the queue
                 * that need to be handled and the first pen event is pen down in the pen event buffer.
                 * After pen down is handled in the protocol event handler, pen abort will be generated
                 * The behavior is not right, so we add reset_context_for_new_screen here.
                 */
                /* Make sure there should be a new start for pen event when entering new screen */
            #ifdef __MMI_VUI_3D_CUBE_APP__
                if (!vadp_p2v_uc_is_in_venus())
            #endif
                {
                    mmi_frm_pen_reset_context_for_new_screen();
                }
            #endif                
                              
            }

            /* Leo start 20050825 */
/********************************************************************
*   Check if number of events in queue increases.
*   If yes, clear more external queue events, else clear less external queue events.
*   At lease clear one external queue event.
********************************************************************/

        #ifdef __VENUS_UI_ENGINE__
            /* Get Total count in external queue */
            msg_get_ext_queue_info(mmi_ext_qid, &queue_node_number);

            if ((queue_node_number == 0) && (OslNumOfCircularQMsgs() == 0) && (g_keypad_flag == MMI_FALSE))
            {
                vfx_mmi_onidle();
            }
        #endif       

            /* Get Total count in external queue */
            msg_get_ext_queue_info(mmi_ext_qid, &queue_node_number);

            if ((queue_node_number == 0) && (OslNumOfCircularQMsgs() == 0) && (g_keypad_flag == MMI_FALSE))
            {
                U8 flag = 0;
                ilm_struct ilm_ptr;

                /* MMI task suspends for the queue */
                MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_TASK_SUSPEND_EXTERNAL_Q);
                OslReceiveMsgExtQ(qid, &Message);
                OslGetMyTaskIndex(&my_index);
                OslStackSetActiveModuleID(my_index, MOD_MMI);

                /* put Message in circular queue */
                ilm_ptr.src_mod_id = Message.src_mod_id;
                ilm_ptr.dest_mod_id = Message.dest_mod_id;
                ilm_ptr.msg_id = Message.msg_id;
                ilm_ptr.sap_id = Message.sap_id;
                ilm_ptr.local_para_ptr = Message.local_para_ptr;
                ilm_ptr.peer_buff_ptr = Message.peer_buff_ptr;

                flag = OslWriteCircularQ(&ilm_ptr);
                MMI_ASSERT(flag == 1);
                /* TIMER use special data in the local_para_ptr field. Can NOT treat as general ILM */
                if (Message.src_mod_id != MOD_TIMER)
                {
                    hold_local_para(ilm_ptr.local_para_ptr);
                    hold_peer_buff(ilm_ptr.peer_buff_ptr);
                    OslFreeInterTaskMsg(&Message);
                }
            }
            else
            {
                mmi_frm_fetch_msg_from_extQ_to_circularQ();
            }

            count = OslNumOfCircularQMsgs();
            while (count > 0)
            {
                /* 
                 * Notify Venus UI in each message done 
                 */
                #ifdef __VENUS_UI_ENGINE__
                vfx_mmi_before_process_msg();
                #endif                
            
                OslGetMyTaskIndex(&my_index);
                OslStackSetActiveModuleID(my_index, MOD_MMI);

                if (OslReadCircularQ(&Message))
                {
                    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_TASK_MSG_HANDLE_BEGIN, Message.msg_id, Message.oslSrcId, Message.oslDestId);
                    CheckAndPrintMsgId((U16) (Message.msg_id));

                    if (Message.dest_mod_id == MOD_WAP)
                    {
                    #if defined(JATAAYU_SUPPORT) || defined(OBIGO_Q05A)
                        extern void mmi_wap_handle_msg(void *msgPtr);

                        mmi_wap_handle_msg((void*)&Message);
                    #endif /* JATAAYU_SUPPORT */ 
                    }
                    #if defined(OBIGO_Q05A)
                    else if (Message.dest_mod_id == MOD_MMS)
                    {
                        extern void mmi_wap_handle_msg(void *msgPtr);
                        mmi_wap_handle_msg((void*)&Message);
                    }
                    #endif /* OBIGO_Q05A */ 
                    else
                    {
                    #if defined(__WS_HOME_SAFE__)
							extern void hf_mmi_task_process(ilm_struct *current_ilm);
							hf_mmi_task_process(&Message);
					#endif
                        switch (Message.msg_id)
                        {
                            case MSG_ID_TIMER_EXPIRY:
                            {
                                kal_uint16 msg_len;

                                EvshedMMITimerHandler(get_local_para_ptr(Message.oslDataPtr, &msg_len));
                            }
                                break;

                            case MSG_ID_MMI_EQ_POWER_ON_IND:
                            {
                                mmi_eq_power_on_ind_struct *p = (mmi_eq_power_on_ind_struct*) Message.oslDataPtr;

                                srv_bootup_set_mode(p);

                                /* To initialize data/time */
                                SetDateTime((void*)&(p->rtc_time));
                                gdi_init();
                            #ifdef __VENUS_UI_ENGINE__
                                vfx_mmi_sys_init();
                            #endif
                                g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_INDICATION;       /* 0x01: POWER_ON_KEYPAD indication */
                            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__                            
                                g_pwr_context_2.PowerOnMMIStatus = MMI_POWER_ON_INDICATION;
                            #endif

                            #ifdef __MMI_TVOUT__
                                mmi_phnset_tvout_check_pwron_start();
                            #endif
                                MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_TASK_POWER_PROC_BEGIN, p->poweron_mode);
                                switch (p->poweron_mode)
                                {
                                    case POWER_ON_KEYPAD:
                                    #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                                        PhnsetSetUARTConfig(p->dual_sim_uart_setting); 
                                    #endif

                                        g_charbat_context.PowerOnCharger = 0;
                                        g_pwr_context.PowerOnMode = POWER_ON_KEYPAD;
                                    #ifdef __MMI_DUAL_SIM_SINGLE_CALL__                            
                                        g_pwr_context_2.PowerOnMMIStatus = POWER_ON_KEYPAD;
                                    #endif

                                        DTGetRTCTime(&StartUpTime);
                                        memset(&LastDuration, 0, sizeof(LastDuration));

                                        /* disk check */
                                #ifdef __FLIGHT_MODE_SUPPORT__
                                        g_phnset_cntx.curFlightMode = p->flightmode_state;
                                #endif 

                                        break;

                                    case POWER_ON_PRECHARGE:
                                    case POWER_ON_CHARGER_IN:
                           /************************************** 
                            * Always send charger-in indication
                            * to avoid fast repeating charger 
                            * in-out b4 power-on completes
                            * Lisen 04/13/2004
                           ***************************************/
                                        g_pwr_context.PowerOnMode = p->poweron_mode;    /* Charger/Pre-charge Power On */
                                        mmi_frm_start_scenario(MMI_SCENARIO_ID_DEFAULT);
                                        InitializeChargingScr();
                                        if (!srv_charbat_is_charging())
                                        {
                                            //QuitSystemOperation();
                                        #ifdef __COSMOS_MMI_PACKAGE__    
                                            srv_shutdown_exit_system(APP_COSMOS_DEVICEAPP);
                                        #else
                                            srv_shutdown_exit_system(APP_CHARGER);
                                        #endif
                                        }
                                        break;

                                    case POWER_ON_ALARM:
                                        g_pwr_context.PowerOnMode = POWER_ON_ALARM;
                                    #ifdef __MMI_SUBLCD__
                                        gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
                                        gdi_layer_clear(GDI_COLOR_BLACK);
                                        gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
                                    #endif /* __MMI_SUBLCD__ */ 
                                        gdi_layer_clear(GDI_COLOR_BLACK);
                                        mmi_frm_start_scenario(MMI_SCENARIO_ID_DEFAULT);
                                        AlmInitRTCPwron();
                                        break;
                                    case POWER_ON_EXCEPTION:
                                        g_pwr_context.PowerOnMode = POWER_ON_EXCEPTION;

                                    #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                                        PhnsetSetUARTConfig(p->dual_sim_uart_setting); 
                                    #endif
                                        break;

                                    #ifdef __MMI_USB_SUPPORT__
                                    case POWER_ON_USB:
                                        g_pwr_context.PowerOnMode = POWER_ON_USB;
                           /***************************************
                            * Because Aux task will not init in USB boot mode 
                            * Interrupt service routine for clam detection CLAM_EINT_HISR() 
                            * is not register, force the clam state to open 
                            * If Aux task is necessary in USB mode, this tircky could be removed 
                            * Robin 1209 
                            ***************************************/
                                        mmi_frm_start_scenario(MMI_SCENARIO_ID_DEFAULT);                                        
                                        InitializeUsbScr();
                           /***************************************
                            * To disable keypad tone state 
                            ***************************************/
                                        mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
                                        break;
                                    #endif /* __MMI_USB_SUPPORT__ */ 

                                    default:
                                        break;
                                }

                            #ifdef __FLIGHT_MODE_SUPPORT__
                                mmi_flight_mode_power_on_ind_hdlr(p);
                            #endif

                                srv_bootup_power_on_ind_hdlr(p);
                                
                                MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_TASK_POWER_PROC_END, p->poweron_mode);
                            }
                                break;

                            default:
                            #ifdef __MULTI_VCARD_SUPPORT__
                                {
                                extern void vcard_app_common_hdlr(void *ilm);
                                vcard_app_common_hdlr((void*)&Message);
                                }
                            #endif
                                ProtocolEventHandler(
                                    (U16) Message.oslMsgId,
                                    (void*)Message.oslDataPtr,
                                    (int)Message.oslSrcId,
                                    (void*)&Message);
                                break;
                        }

                    }

                    OslFreeInterTaskMsg(&Message);
                    mmi_frm_invoke_post_event();
                    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_TASK_MSG_HANDLE_END, Message.oslMsgId, Message.oslSrcId, Message.oslDestId);
                }   /* OslReadCircularQ(&Message) */
                msg_get_ext_queue_info(mmi_ext_qid, &queue_node_number);
                count--;
            #ifdef __VENUS_UI_ENGINE__
                vfx_mmi_check_update();
            #endif
                /* dispatch MRE message */
                vm_appcomm_dispatch_msg();
            #if defined(__MMI_TOUCH_SCREEN__) && defined(__MTK_TARGET__)
            #ifdef __MMI_VUI_3D_CUBE_APP__
                if (!vadp_p2v_uc_is_in_venus())
            #endif
                {
                    /* Make sure there should be a new start for pen event when entering new screen */
                    mmi_frm_pen_reset_context_for_new_screen();
                }                
            #endif
            }
        }     
    }
}


/*****************************************************************************
 * FUNCTION
 *  InitFramework
 * DESCRIPTION
 *  To Initialize framework,
 *  
 *  This is used to To Initialize framework,.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitFramework(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (framework_initialized)
    {
        return;
    }
    framework_initialized = MMI_TRUE;
    /* 
     * Initialize events handler  
     */
    InitEvents();
    mmi_frm_init_inject_string();
    mmi_frm_init_dump_screen_string();
    /* 
     * Initialize history 
     */
    InitHistory(NULL, NULL);

    /* init the scenario(screen group) mech.  */
    mmi_frm_shell_init();

    /* initialize notification service */
    mmi_frm_notification_service_init();

    /* initialize screen management service. (for anti-blink mechanism)*/
#ifdef __MMI_LCM_PRIMITIVE_FLUSH__    
    mmi_frm_scr_mgm_init();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  ProtocolEventHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  eventID         [IN]        
 *  MsgStruct       [IN]         
 *  mod_src         [IN]        
 *  peerBuf         [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void ProtocolEventHandler(U16 eventID, void *MsgStruct, int mod_src, void *Message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ExecuteCurrProtocolHandler((U16) eventID, MsgStruct, mod_src, Message);
}


/*****************************************************************************
 * FUNCTION
 *  InitUnicodeSupport
 * DESCRIPTION
 *  Initalizes string functions for UCS2 support
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitUnicodeSupport(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* This function will be invoked in charger/alarm power on, too */

#if defined (__MMI_FRAMEWORK_BACKWARD_COMPATIBLE__) || defined (__MMI_FRAMEWORK_BACKWARD_COMPATIBLE_SPEC__)
    pfnUnicodeToEncodingScheme = mmi_wc_to_ucs2;
    pfnEncodingSchemeToUnicode = mmi_ucs2_to_wc;
    pfnUnicodeStrlen = mmi_ucs2strlen;
    pfnUnicodeStrcpy = mmi_ucs2cpy;
    pfnUnicodeStrcmp = mmi_ucs2cmp;
    pfnUnicodeStrncpy = mmi_ucs2ncpy;
    pfnUnicodeStrncmp = mmi_ucs2ncmp;
    pfnUnicodeStrcat = mmi_ucs2cat;
    pfnUnicodeStrncat = mmi_ucs2ncat;
#endif /* __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__ */
}


/*****************************************************************************
 * FUNCTION
 *  InitAllApplications
 * DESCRIPTION
 *  Initialize all application which requires SIM to be present
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitAllApplications(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (gInitAllAppFlag != 0)
    {
        return; /* not init applications twice */
    }

    /* please see the detailed description in InitializeAll() */
    gInitAllAppFlag = 1;
    gInsertSimAppFlag = 0;


}


/*****************************************************************************
 * FUNCTION
 *  InitInsertSimApp
 * DESCRIPTION
 *  Initialize few applications which do not require SIM to be present
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitInsertSimApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* please see the detailed description in InitializeAll() */
    gInsertSimAppFlag = 1;

    /* Not re-init these applications if no sim indication is sent after successful power on with sim */
    if (gInitAllAppFlag != 0)
    {
        return; /* not init applications twice */
    }
    gInitAllAppFlag = 1;
}


/*****************************************************************************
 * FUNCTION
 *  InitNvramDataBeforeAnimation
 * DESCRIPTION
 *  Allows the applications to read their NVRAM data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitNvramDataBeforeAnimation(void)
{

}


/*****************************************************************************
 * FUNCTION
 *  InitNvramData
 * DESCRIPTION
 *  Allows the applications to read their NVRAM data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitNvramData(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* make sure the cache buffer is large enough */
    MMI_ASSERT((mmi_rp_mmi_cache_get_byte_number() * DS_BYTE) <= NVRAM_CACHE_SIZE);
    MMI_ASSERT((mmi_rp_mmi_cache_get_short_number() * DS_SHORT) <= NVRAM_CACHE_SIZE);
    MMI_ASSERT((mmi_rp_mmi_cache_get_double_number() * DS_DOUBLE) <= NVRAM_CACHE_SIZE);
}



/*****************************************************************************
* Local Function                                                              
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  InitEventHandlersBeforePowerOn
 * DESCRIPTION
 *  Init event handlers before power on indication
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void InitEventHandlersBeforePowerOn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    InitEvents();
    mmi_frm_init_kpd_bf_pwon();
    SetProtocolEventHandler(GpioDetectInd, MSG_ID_MMI_EQ_GPIO_DETECT_IND);
    SetProtocolEventHandler(srv_charbat_status_ind_hdlr, MSG_ID_MMI_EQ_BATTERY_STATUS_IND);
#ifdef __MMI_USB_SUPPORT__
    SetProtocolEventHandler(UsbDetectIndHdlr, PRT_EQ_USB_DETECT_IND);
#endif 
    InitAlarmHandler();

#ifdef __MMI_TVOUT__
    /* init tvout, since TV-out indication will come before poweron indication */
    mmi_phnset_early_init_tvout_before_pwron();
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_check_is_valid_msg
 * DESCRIPTION
 *  Check if the follow message is useful
 *  If the successive messages are MSG_ID_TIMER_EXPIRY,
 *  only one message will be usegful. We will keep only one
 *  MSG_ID_TIMER_EXPIRY in the queue
 * PARAMETERS
 *  base        [IN]     
 *  msg         [IN]     
 * RETURNS
 *  0 - the message is invalid, and discard the message
 *  1 - the message is vaild
 *****************************************************************************/
static U8 mmi_frm_check_is_valid_msg(MYQUEUE *base, MYQUEUE *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((base != NULL) && (msg != NULL) && (base->msg_id == msg->msg_id))
    {
        switch (base->msg_id)
        {
            case MSG_ID_TIMER_EXPIRY:
            {
                kal_uint16 msg_len = 0;
                stack_timer_struct *base_timer_ptr;
                stack_timer_struct *timer_ptr;

                base_timer_ptr = (stack_timer_struct*) get_local_para_ptr(base->oslDataPtr, &msg_len);
                timer_ptr = (stack_timer_struct*) get_local_para_ptr(msg->oslDataPtr, &msg_len);
                if (base_timer_ptr == timer_ptr)
                {
                    stack_is_time_out_valid(base_timer_ptr);
                    stack_process_time_out(base_timer_ptr);
                    /* msg is invalid, can discard it */
                    return 0;
                }
            }
                break;

            default:
                break;
        }
    }
    /* msg is valid, can't discard */
    return 1;
}


/* __CUSTPACK_MULTIBIN     Terry   BEGIN */

/*****************************************************************************
 * FUNCTION
 *  ime_check_input_type
 * DESCRIPTION
 *  To check if the specified input type is supported
 * PARAMETERS
 *  input_type  [IN] the specified input type
 * RETURNS
 *  MMI_TRUE    the specified input type is supported
 *  MMI_FALSE   the specified input type is not supported
 *****************************************************************************/
MMI_BOOL ime_check_input_type(S16 input_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  IMECheck
 * DESCRIPTION
 *  To Check IME,
 *  
 *  This is used to To Check IME,.
 * PARAMETERS
 *  IME_Mode                [IN]        
 *  all_implement_IME       [IN]        
 * RETURNS
 *  MMI_TRUE : if the IME_Mode is in
 *  MMI_FALSE : if the IME_Mode is not in
 *****************************************************************************/
static MMI_BOOL IMECheck(mmi_imm_input_mode_enum IME_Mode, const mmi_imm_input_mode_enum all_implement_IME[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (;;)
    {
        if (IMM_INPUT_MODE_MAX_NUM > all_implement_IME[i])
        {
            if (IME_Mode == all_implement_IME[i])
            {
                return MMI_TRUE;
            }
        }
        else
        {
            return MMI_FALSE;
        }
        i++;
        if (i > IMM_INPUT_MODE_MAX_NUM)
        {
            ASSERT(0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  InitIME
 * DESCRIPTION
 *  To Initialize IME,
 *  
 *  This is used to To Initialize IME,.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitIME(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_imc_init_all();
}
/* __CUSTPACK_MULTIBIN     Terry   END */


/*****************************************************************************
 * FUNCTION
 *  InitializeAll
 * DESCRIPTION
 *  This is used to initialize framework
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void InitializeAll()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_IRDA_SUPPORT__
    MMI_APP_INIT(mmi_irda_init_cntx());
    MMI_APP_INIT(mmi_irda_set_recv_files_cnt(0));
#endif /* __MMI_IRDA_SUPPORT__ */ 


#if defined(JATAAYU_SUPPORT) && !defined(__MTK_TARGET__)
    {
        ilm_struct *ilm_ptr = NULL;

        ilm_ptr = allocate_ilm(MOD_MMI);
        ilm_ptr->local_para_ptr = NULL;
        ilm_ptr->msg_id = MSG_ID_MMI_EQ_POWER_ON_IND;
        ilm_ptr->peer_buff_ptr = NULL;

        ilm_ptr->src_mod_id = MOD_MMI;
        ilm_ptr->dest_mod_id = MOD_WAP;
        ilm_ptr->sap_id = WPS_APP_SAP;
        msg_send_ext_queue(ilm_ptr);
    }
#endif /* defined(JATAAYU_SUPPORT) && !defined(__MTK_TARGET__) */ 


#ifdef __MMI_SWFLASH__
    MMI_APP_INIT(mmi_swflash_init_app());
#endif

}

