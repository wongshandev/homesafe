#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2006
#
#  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
#  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
#  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
#  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
#  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
#  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
#  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
#  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
#  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
#  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
#  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
#  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
#
#  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
#  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
#  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
#  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
#  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
#
#  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
#  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
#  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
#  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
#  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
#
#*****************************************************************************
#*
#* Filename:
#* ---------
#*   sysGen1.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script embedded several .c .h source code templates and will 
#*       1. generate custom_util.c if not exists
#*       2. generate custom_util.h if not exists
#*       3. generate custom_sap.h if not exists
#*       4. generate custom1_create.c if not exists
#*       5. generate custom_config.h if not exists
#*       6. generate custom_config.c if not exists
#*       7. generate fs_config.c if not exists
#*       8. generate custom_fs.h if not exists
#*       9. generate custom_jump_tbl.h if not exists
#*      10. generate custom_jump_tbl.c if not exists
#*      11. generate custom_fota.h if not exists
#*      12. generate custom_fota.c if not exists
#*      13. generate custom_img_config.c if not exists
#*
#* Author:
#* -------
#*   JI Huang  (mtk01077)
#*
#*============================================================================
#*             HISTORY
#* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*------------------------------------------------------------------------------
#* $Revision$
#* $Modtime$
#* $Log$
#*
#*
#*------------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================
#****************************************************************************/

#****************************************************************************
# Included Modules
#****************************************************************************
use strict;

#****************************************************************************
# Constants
#****************************************************************************
my $SYSGEN_VERNO     = " V1.35 -> p1.38";
                       # p1.38 , 2011/02/23 , Shrink debug memory based on control buffer numbers and statistics
                       # v1.35 , 2011/02/18 , Modify fs_config.c template to enlarge FS_MAX_THREAD by 1 for LC(COMMON) projects
                       # v1.34 , 2011/02/17 , Shrink system/debug memory for control buffer refinement (remove long-time occupants)
                       # v1.33 , 2011/02/15 , Enlarge GPRS lowest segment system memory by 50KB to fix CLAM53 insufficient system memory power-on failure
                       # v1.31 , 2011/01/31 , Fine-tune system/debug memory and control buffer configurations for Gemini+, GSM, and Low-Cost projects
                       # v1.29 , 2011/01/21 , Modify fs_config.c template to support Card DL
                       # v1.28 , 2011/01/21 , Change FS_MAX_THREAD from 7 to 8 when LOW_COST_SUPPORT != NONE
                       # v1.22 , 2010/12/29 , Search additioinal check in pattern "MANUAL-CHECKIN" in each target file and not to remove a target file when this pattern is found.
                       # v1.17 , 2010/12/09 , Merge 10AW1039OF_RHR to 10A
                       # v1.16 , 2010/12/09 , Modify template of custom_config.c, custom_config.h and custom_sap.h to __MAUI_SDK_TEST__ to turn on/off MAUI SDK AVK.
                       # v1.14 , 2010/12/01 , Modify dependency_check to remove redundant check-in message check. Add generate_autogen_file subroutine and modify code segment generating output files to generate output files collectively.
                       # v1.13 , 2010/11/18 , Modify custom_config.c template to shrink system/debug memory for SLIM_DEBUG_KAL or RELEASE_KAL
                       # v1.12 , 2010/11/18 , Modify custom_fs.h to remove smart file seeker compile option for MP
                       # v1.11 , 2010/11/17 , Enlarge GPRS+__WIFI_SUPPORT__ system memory by 30KB to fix MAUI_02837414
                       # v1.09 , 2010/11/08 , Modify custom_config.c template to shrink system/debug memory by 1028-1040 statistics and for data buffer
                       # v1.07 , 2010/10/11 , Modify fs_config.c template to support Dual T-Card
                       # v1.04 , 2010/08/06 , Modify fs_config.c template to change __ARMx_MMU__ to __DYNAMIC_SWITCH_CACHEABILITY__ to support MT6253E/L write-back cache
                       # v1.03 , 2010/08/04 , Modify custom_fs.h to enable FS Smart File Seeker by compile option for QC
                       # v1.01 , 2010/07/29 , Modify fs_config.c template to force FS buffers to be 4-byte aligned to prevent data abort
                       # v1.00 , 2010/07/09 , Add a customer-configurable heap for malloc
                       # v0.99 , 2010/06/23 , Add 1 thread to FS_MAX_THREAD for GADGET for GPRS projects
                       # v0.98 , 2010/06/21 , Support Smart Phone projects with fixed FS drive number 3
                       # v0.97 , 2010/06/03 , Modify custom_fs.h template to support disk size limitation
                       # v0.96 , 2010/06/01 , Remove SINGLE_BANK_NOR_FLASH_SUPPORT makefile option
                       # v0.95 , 2010/05/26 , Modify fs_config.c template to put FS memory card performance enhancement dedicated buffer in Noncached region
                       # v0.94 , 2010/05/17 , Modify custom_fs.h and fs_config.c template to support FS memory card performance enhancement by dedicated buffer
                       # v0.93 , 2010/05/13 , Modify custom_util.c template to support enabling MAUI init debugging trace by keypad
                       # v0.92 , 2010/04/13 , Enlarge System Memory size when __GADGET_SUPPORT__ is defined
                       # v0.91 , 2010/04/13 , Enlarge System Memory size when OPERA_V10_BROWSER is defined 
                       # v0.90 , 2010/02/25 , Modify custom_fs.h and fs_config.c template to enable FS Open Hint
                       # v0.89 , 2010/01/25 , Modify custom_util.c template to support printing log at init
                       # v0.88 , 2010/01/23 , Modify fs_config.c template to increase file handle for __MMI_VECTOR_FONT_SUPPORT__
                       # v0.87 , 2010/01/05 , Support ARM11 Phase-in
                       # v0.86 , 2009/12/20 , Add MT6253D
                       # v0.85 , 2009/12/18 , Rename fs_config.h as custom_fs.h and temporarily disable FS_OPEN_HINT
                       # v0.84 , 2009/12/08 , Enlarge Edge System Memory pool size by 30KB
                       # v0.83 , 2009/11/24 , Modify fs_config.c template and add fs_config.h for FS internal hint
                       # v0.82 , 2009/11/10 , __OP01__ __OP11__ __OP12__ option for gprs GLOBAL_MEM_SIZE determine
                       #                      Remove unused option
                       # v0.81 , 2009/10/28 , Merge WISE_Dev to MAUI
                       # v0.80 , 2009/10/23 , gprs RAM configure template case switch correction
                       # v0.79 , 2009/09/16 , __WCDMA_RAT__ to __UMTS_RAT__
                       # v0.78 , 2009/09/02 , Enlarge System Memory pool 10KB for all edge projects
                       # v0.77 , 2009/07/31 , Modify fs_config.h template to update max thread number
                       # v0.76 , 2009/05/27 , Modify custom_jump_tbl.h template to support External MMI for WISE
                       # v0.75 , 2009/05/19 , Modify custom_MemoryDevice.h, custom_flash.c, custom_flash_norfdm5.c, flash_opt.h, custom_fota.c to re-organize flash-related configurations
                       # v0.74 , 2009/05/15 , Enlarge System Memory pool for new tasks for CMMB (__CMMB_CAS_SMD_SUPPORT__)
                       # v0.73 , 2009/04/09 , Enlarge system memory and debug memory pools for MT6268 (3G projects)
                       # v0.72 , 2009/04/03 , Enlarge system memory and debug memory pools for MT6268 (3G projects)
                       # v0.71 , 2009/03/12 , Modify custom_config.c control buffer and system memory template for MT6268 (3G projects)
                       # v0.70 , 2009/03/03 , Modify custom_fota.c template to meet NOR FOTA requirement
                       # v0.69 , 2009/02/18 , Modify custom_fota.c template for NFB+FOTA case for new boot-loader
                       # v0.68 , 2009/02/12 , Enlarge EDGE debug memory on MoDIS
                       # v0.67 , 2009/02/06 , Add the support of MT6268
                       # v0.66 , 2009/01/05 , Modify custom_fota.h template for FOTA and Secure RO co-existence
                       # v0.65 , 2008/12/31 , Remove MT6205B related codes
                       # v0.64 , 2008/12/31 , Enlarge system memory pool size by 40KB for GSM segment
                       # v0.63 , 2008/12/25 , Remove FOTA_PROPRIETARY
                       # v0.62 , 2008/11/26 , Modify custom_fota.c, custom_fota.h, and custom_img_config.c templates for FOTA+NFB
                       # v0.61 , 2008/11/07 , Modify fs_config.c template for ULC to reduce the number of file handles
                       # v0.60 , 2008/10/31 , Modify fs_config.c template for USB OTG device number
                       # v0.59 , 2008/10/15 , Support FOTA+NFB Auto-Gen
                       # v0.58 , 2008/10/08 , Increase ULC FS_MAX_THREAD by 1.
                       # v0.57 , 2008/10/08 , Modify custom_img_config.c and custom_fota.c templates to make FUE space larger than backup area.
                       # v0.56 , 2008/10/03 , Add custom task VS to support AVK (API Verify Kit)
                       # v0.55 , 2008/09/12 , Add file name and fline number information and unify all auto-gen error messages
                       # v0.54 , 2008/09/03 , To support Dcache Phase3
                       # v0.53 , 2008/09/03 , NAND_FLASH_BOOTING makefile option is changed
                       # v0.52 , 2008/08/28 , Modify custom_fota.c template to support FOTA on ARM9
                       # v0.51 , 2008/08/21 , Unify Auto-Gen error messages
                       # v0.50 , 2008/08/14 , Support FOTA Auto-Gen
                       # v0.49 , 2008/08/11 , Enable MT6238 stack@cacheable region
                       # v0.48 , 2008/08/08 , Modify fs_config.c template for Ultra Low Cost support
                       # v0.47 , 2008/08/04 , Increase system memory pool size by 5KB when GSM+LOW_COST_SUPPORT
                       # v0.46 , 2008/07/23 , Modify GLOBAL_CACHED_MEM_SIZE definition
                       # v0.45 , 2008/07/17 , Modify custom_img_config.c template for FOTA
                       # v0.44 , 2008/07/15 , Modify custom_img_config.c template for FOTA bug fix on boot-loader
                       # v0.43 , 2008/07/13 , Modify templates for FOTA
                       # v0.42 , 2008/07/09 , Modify fs_config.c template for FS Sorting Enhancement
                       # v0.41 , 2008/07/04 , Modify remap_mod_task_g for OBIGO_Q03C_MMS_V02
                       # v0.40 , 2008/07/02 , Modify custom_configmem API separation criteria for MoDIS
                       # v0.39 , 2008/07/01 , Move Cached_System_Mem_Pool out from cached region on MT6238
                       # v0.38 , 2008/06/21 , Modify custom_jump_tbl.c template for BASIC Load
                       # v0.35 , 2008/06/16 , Modify custom_config.c template for MT6235/MT6238 dynamic cacheable region
                       # v0.34 , 2008/06/13 , custom_img_config.c template imported and modify for FOTA and NFB MBA
                       # v0.33 , 2008/06/04 , Modify EDGE and GPRS custom_config.c templates to enlarge system memory and debug memory when AGPS_SUPPORT is turned on
                       # v0.32 , 2008/06/02 , Change makefile option LOW_COST_SUPPORT from FALSE/TRUE to NONE/COMMON/ULC
                       # v0.31 , 2008/04/09 , Modify custom_jump_tbl.c template for __MULTIPLE_BINARY_FILES__
                       # v0.30 , 2008/04/03 , Enlarge system memory pool for GEMINI
                       # v0.29 , 2008/03/27 , custom_config.c add custom_config_demp_page() for demand page in
                       # v0.28 , 2008/03/27 , fs_config.c revise for MT6235/MT6238
                       # v0.27 , 2008/03/27 , GLOBAL_MEM_SIZE 290K -> 320K on GPRS Generic globalmem_gprs for GEMINI projects
                       # v0.26 , 2008/03/05 , move custom_nor_large_disk.c generation to EMI Gen
                       # v0.25 , 2007/12/17 , GLOBAL_MEM_SIZE 330K -> 350K on Edge Generic globalmem_edge
                       # v0.24 , 2007/10/05 , fs_config.c revise for Dual MSDC setting
                       # v0.22 , 2007/08/20 , fs_config.c revise for MT6223P platform setting
                       # v0.21 , 2007/08/20 , custom_config.c system RAM default value alignment on GSM projects
                       # v0.20 , 2007/08/10 , custom_config.c system RAM and MMI stack adjustment if OBIGO_Q05A
                       # v0.19 , 2007/05/14 , custom_config.c control buffer slots adjustment
                       # v0.18 , 2007/05/14 , custom_config.c fs_config.c resource enlarge for DM , DRMT tasks
                       # v0.17 , 2007/04/23 , dependency_check enable
                       # v0.16 , 2007/04/23 , custom_config.c OBIGO_Q05A compile option 
                       # v0.15 , 2007/04/17 , GLOBAL_DEBUG_MEM_SIZE 150K -> 160K on globalmem_gsm
                       # v0.14 , 2007/03/12 , custom_config.c new function custom_config_task_stack_location()
                       # v0.13 , 2007/02/26 , fs_config.c revise for MSDC device configure update
                       # v0.12 , 2007/01/21 , make event schedule pool size customizable
                       # v0.11 , 2007/01/02 , custom_nor_large_disk.c template imported
                       #                    , add error checking on file close
                       # v0.10 ,            , minor revise on custom_fota.h template
                       # v0.09 , 2006/12/25 , fs_config.c support SIM_PLUS, custom_fota.c custom_fota.h template
                       # v0.08 , 2006/12/18 , new mechanism for custom task present on usb / factory boot mode

#****************************************************************************
# File Names
#****************************************************************************
# to align error message file name format
$ARGV[0] =~ s/^.\\|^\\//;
my $CUSTOM_UTIL_C    = $ARGV[0] . '\\' . "custom_util.c";
my $CUSTOM_UTIL_H    = $ARGV[0] . '\\' . "custom_util.h";
my $CUSTOM_SAP_H     = $ARGV[0] . '\\' . "custom_sap.h";
my $CUSTOM1_CREATE_C = $ARGV[0] . '\\' . "custom1_create.c";
my $CUSTOM_CONFIG_H  = $ARGV[0] . '\\' . "custom_config.h";
my $CUSTOM_CONFIG_C  = $ARGV[0] . '\\' . "custom_config.c";
my $FS_CONFIG_C      = $ARGV[0] . '\\' . "fs_config.c";
my $CUSTOM_FS_H      = $ARGV[0] . '\\' . "custom_fs.h";
my $CUSTOM_JUMPTBL_H = $ARGV[0] . '\\' . "custom_jump_tbl.h";
my $CUSTOM_JUMPTBL_C = $ARGV[0] . '\\' . "custom_jump_tbl.c";
my $CUSTOM_FOTA_H    = $ARGV[0] . '\\' . "custom_fota.h";
my $CUSTOM_FOTA_C    = $ARGV[0] . '\\' . "custom_fota.c";
my $CUSTOM_IMG_CONFIG_C = $ARGV[0] . '\\' . "custom_img_config.c";

#****************************************************************************
# Script filename
#****************************************************************************
my $sysgen_pl        = $0;

#****************************************************************************
# Project Make File
#****************************************************************************
my %MAKEFILE_OPTIONS;
my $keyname;

my $themf = $ARGV[1];
# to align error message file name format
$themf =~ s/^.\\|^\\//;
&error_handler("$themf: NOT exist!", __FILE__, __LINE__) if (!-e $themf);

open (FILE_HANDLE, "<$themf") or &error_handler("$themf: file error!", __FILE__, __LINE__);
while (<FILE_HANDLE>) {
  if (/^(\S+)\s*=\s*(\S+)/) {
    $keyname = lc($1);
    defined($${keyname}) && warn "$1 redefined in $themf!\n";
    $MAKEFILE_OPTIONS{$keyname} = uc($2);
  }
}
close (FILE_HANDLE);

#****************************************************************************
# 1 >>>  Generate custom_util.c
#****************************************************************************
my @dep_list = ($sysgen_pl);
my @desc_list = ("custom_util.c", 
                          "This file provides the custom utililty APIs",
                                 "system auto generator". $SYSGEN_VERNO);
&generate_autogen_file($CUSTOM_UTIL_C, "custom_util_c_file_body", \@desc_list, \@dep_list);

#****************************************************************************
# 2 >>>  Generate custom_util.h
#****************************************************************************
my @dep_list = ($sysgen_pl);
my @desc_list = ("custom_util.h", 
                  "This file provides the custom utililty declarations",
                                 "system auto generator". $SYSGEN_VERNO);
&generate_autogen_file($CUSTOM_UTIL_H, "custom_util_h_file_body", \@desc_list, \@dep_list);

#****************************************************************************
# 3 >>>  Generate custom_sap.h
#****************************************************************************
my @dep_list = ($sysgen_pl);
my @desc_list = ("custom_sap.h", 
                       "This file provide for customization message id",
                                 "system auto generator". $SYSGEN_VERNO);
&generate_autogen_file($CUSTOM_SAP_H, "custom_sap_h_file_body", \@desc_list, \@dep_list);

#****************************************************************************
# 4 >>>  Generate custom1_create.c
#****************************************************************************
my @dep_list = ($sysgen_pl);
my @desc_list = ("custom1_create.c", 
          "This file implements custom1 component task create function",
                                 "system auto generator". $SYSGEN_VERNO);
&generate_autogen_file($CUSTOM1_CREATE_C, "custom1_create_c_file_body", \@desc_list, \@dep_list);

#****************************************************************************
# 5 >>>  Generate custom_config.h
#****************************************************************************
my @dep_list = ($sysgen_pl);
my @desc_list = ("custom_config.h", 
          "This file provides the custom task index and module index configuration",
                                 "system auto generator". $SYSGEN_VERNO);
&generate_autogen_file($CUSTOM_CONFIG_H, "custom_config_h_file_body", \@desc_list, \@dep_list);

#****************************************************************************
# 6 >>>  Generate custom_config.c
#****************************************************************************
my @dep_list = ($sysgen_pl, $themf);
my @desc_list = ("custom_config.c", 
                 "This file contain definition of custom component module configuration variables, and routines",
                                 "system auto generator". $SYSGEN_VERNO);
    # template generator here, 
    # See Also  dispatch_globalmem_and_ctrlbuffpool();  for algorithm
    #
&generate_autogen_file($CUSTOM_CONFIG_C, "custom_config_c_file_body", \@desc_list, \@dep_list);

#****************************************************************************
# 7 >>>  Generate fs_config.c
#****************************************************************************
my @dep_list = ($sysgen_pl, $themf);
my @desc_list = ("fs_config.c", 
                "This file defines all resource setting in file system",
                                 "system auto generator". $SYSGEN_VERNO);
    # template generator here, 
    # See Also  dispatch_drivenum(), dispatch_buffnum(),
    #           dispatch_fhnum(), dispatch_threadnum()   for algorithms
    #
&generate_autogen_file($FS_CONFIG_C, "fs_config_c_file_body", \@desc_list, \@dep_list);

#****************************************************************************
# 8 >>>  Generate custom_fs.h
#****************************************************************************
my @dep_list = ($sysgen_pl);
my @desc_list = ("custom_fs.h", 
                "header file for all resource setting in file system",
                                 "system auto generator". $SYSGEN_VERNO);
&generate_autogen_file($CUSTOM_FS_H, "custom_fs_h_file_body", \@desc_list, \@dep_list);

#****************************************************************************
# 9 >>>  Generate custom_jump_tbl.h
#****************************************************************************
my @dep_list = ($sysgen_pl);
my @desc_list = ("custom_jump_tbl.h", 
          "header file for indirect jump table for multiple binary load",
                                 "system auto generator". $SYSGEN_VERNO);
&generate_autogen_file($CUSTOM_JUMPTBL_H, "custom_jump_tbl_h_file_body", \@desc_list, \@dep_list);

#****************************************************************************
# 10 >>>  Generate custom_jump_tbl.c
#****************************************************************************
my @dep_list = ($sysgen_pl);
my @desc_list = ("custom_jump_tbl.c", 
            "source file for indirect jump table for multiple binary load",
                                 "system auto generator". $SYSGEN_VERNO);
&generate_autogen_file($CUSTOM_JUMPTBL_C, "custom_jump_tbl_c_file_body", \@desc_list, \@dep_list);

#****************************************************************************
# 11 >>>  Generate custom_fota.h
#****************************************************************************
my @dep_list = ($sysgen_pl);
my @desc_list = ("custom_fota.h", 
          "This Module defines the FOTA (Firmware Over the Air) related setting.",
             "Yoda Chen (mtk01178)     " . "system auto generator". $SYSGEN_VERNO);
&generate_autogen_file($CUSTOM_FOTA_H, "custom_fota_h_file_body", \@desc_list, \@dep_list);

#****************************************************************************
# 12 >>>  Generate custom_fota.c
#****************************************************************************
my @dep_list = ($sysgen_pl, $themf);
my @desc_list = ("custom_fota.c", 
          "This Module defines the FOTA (Firmware Over the Air) related setting.",
             "Yoda Chen (mtk01178)     " . "system auto generator". $SYSGEN_VERNO);
&generate_autogen_file($CUSTOM_FOTA_C, "custom_fota_c_file_body", \@desc_list, \@dep_list);

#****************************************************************************
# 13 >>>  Generate custom_img_config.c
#****************************************************************************
my @dep_list = ($sysgen_pl);
my @desc_list = ("custom_img_config.c", 
          "This file implements image information feature.",
             "Kirk Lee (mtk01337)     " . "system auto generator". $SYSGEN_VERNO);
&generate_autogen_file($CUSTOM_IMG_CONFIG_C, "custom_img_config_c_file_body", \@desc_list, \@dep_list);

#****************************************************************************
# oo >>>  Finished
#****************************************************************************
exit;


#****************************************************************************
# subroutine:  SCHEME Configure Routines :: Query :: ARM9 Family
# input:       BB chip
# Output:      whether this chip belongs to ARM9 Family
#****************************************************************************
sub config_query_arm9
{
    my ($bb) = @_;

    my %BBtbl_ARM9_Family =
       (        
                'MT6235'  => 1,
                'MT6235B' => 1,
                'MT6238'  => 1,
                'MT6239'  => 1,
                'MT6268A' => 1,
                'MT6268'  => 1,
                'MT6236'  => 1,
                'MT6236B' => 1,
       );
       
    return $BBtbl_ARM9_Family{$bb};
}

#****************************************************************************
# subroutine:  SCHEME Configure Routines :: Query :: CS1 base address
# input:       BB chip
# Output:      CS1 default base address
#****************************************************************************
sub config_query_cs1_addr
{
    my ($bb) = @_;

    if (&config_query_arm9($bb) == 1)
    {
        return 0x10000000;
    }
    else
    {
        return 0x08000000;
    }
}

#****************************************************************************
# subroutine:  dependency check
# return:      None
#****************************************************************************
sub dependency_check
{
    my ($target, @depends) = (@_);
    
    return unless (-e $target);

    ## Now check if the $target file check-in or auto-gen
    ## Read whole file ##
    open SRC_FILE_R , "<$target" or &error_handler("$target: file error!", __FILE__, __LINE__);
    my $saved_sep = $/;
    undef $/;
    my $reading = <SRC_FILE_R>; 
    close SRC_FILE_R;
    $/ = $saved_sep;

    ## Look for check-in pattern ##
    if (($reading =~ /\[MAUI_\d{8}\]/) or ($reading =~ /MANUAL-CHECKIN/i))
    {
        print "$target: Check-in message is found. No need to update.\n";
        return;
    }

    my @stat_target = stat $target;

    foreach my $dep (@depends)
    {
        next unless (-e $dep);
        my @stat_dep = stat $dep;

        next if ($stat_dep[9] < $stat_target[9]);

        print "$target is older than $dep, force delete and update\n";
        unlink $target;

        return;
    }
}

#****************************************************************************
# subroutine:  Generate output file based on input parameters
# input:        $filename: filename
# input:        $file_body_func_name: Name of function to generate file body
# input:        $desc_ref: Reference to hash with descriptions of generated file
# input:        $dep_ref: Reference to array with dependency checking files
# Output:       CS1 default base address
#****************************************************************************
sub generate_autogen_file
{
    ## enable calling function with variable-indexed name
    no strict 'refs';

    my($filename, $file_body_func_name, $desc_ref, $dep_ref) = @_;
    my(@desc, @dep);
    @desc = @{$desc_ref};
    @dep = @{$dep_ref};

    &dependency_check($filename, @dep);

    if(-e $filename)
        {
        print "$filename already exists\n";
        }
    else
    {
        open (OUT_FILE_INDEX, ">$filename") or &error_handler("$filename: file error!", __FILE__, __LINE__);

        print OUT_FILE_INDEX &copyright_file_header();
        print OUT_FILE_INDEX &description_file_header(@desc);
        print OUT_FILE_INDEX &{$file_body_func_name}();
        close OUT_FILE_INDEX or &error_handler("$filename: file error!", __FILE__, __LINE__);

        print "$filename is generated\n";
    }
}


#****************************************************************************
# subroutine:  determine the amount for file system configure in fs_config.c
# return:      the value for recommend drive number <NOTE!!!: scalar context>
#****************************************************************************
sub dispatch_drivenum
{
    my $value;

    if (exists $MAKEFILE_OPTIONS{'smart_phone_core'} and $MAKEFILE_OPTIONS{'smart_phone_core'} =~ /MODEM/)
    {
    	   if (exists $MAKEFILE_OPTIONS{'platform'} and $MAKEFILE_OPTIONS{'platform'} eq 'MT6516')
    	   {
            $value = 3;
            return $value;
        }
    }
    if (exists $MAKEFILE_OPTIONS{'low_cost_support'} and $MAKEFILE_OPTIONS{'low_cost_support'} eq 'ULC')
    {
           $value = 1;
    }
    elsif (exists $MAKEFILE_OPTIONS{'nand_flash_booting'} and $MAKEFILE_OPTIONS{'nand_flash_booting'} ne 'NONE')
    {
           $value = 2;
    }
    elsif (exists $MAKEFILE_OPTIONS{'system_drive_on_nand'} and $MAKEFILE_OPTIONS{'system_drive_on_nand'} eq 'TRUE')
    {
           $value = 2;
    }
    elsif (exists $MAKEFILE_OPTIONS{'nand_support'} and $MAKEFILE_OPTIONS{'nand_support'} ne 'TRUE')
    {
           $value = 2;
    }
    else
    {
           $value = 3;
    }

    return $value;
}

#****************************************************************************
# subroutine:  determine the amount for file system configure in fs_config.c
# return:      the value for recommend buffer number <NOTE!!!: scalar context>
#****************************************************************************
sub dispatch_buffnum
{
    if (exists $MAKEFILE_OPTIONS{'low_cost_support'} and $MAKEFILE_OPTIONS{'low_cost_support'} eq 'ULC')
    {
        return 2;
    }
    elsif (exists $MAKEFILE_OPTIONS{'l1_gprs'} and $MAKEFILE_OPTIONS{'l1_gprs'} eq 'TRUE')
    # GPRS  capability
    {   return 16;
    }
    elsif (exists $MAKEFILE_OPTIONS{'low_cost_support'} and $MAKEFILE_OPTIONS{'low_cost_support'} eq 'NONE')
    # GSM   capability  ; default
    {   return  8;
    }
    else
    # GSM   capability  + Low cost (single bank no matter)
    {   return  4;
    }
    &error_handler("tools\\sysGen1.pl: search buffer number fail!", __FILE__, __LINE__);
}

#****************************************************************************
# subroutine:  determine the amount for file system configure in fs_config.c
# return:      the value for recommend file handle number <NOTE!!!: scalar context>
#****************************************************************************
sub dispatch_fhnum
{
    if (exists $MAKEFILE_OPTIONS{'low_cost_support'} and $MAKEFILE_OPTIONS{'low_cost_support'} eq 'ULC')
    {
        return 1;
    }
    elsif (exists $MAKEFILE_OPTIONS{'l1_gprs'} and $MAKEFILE_OPTIONS{'l1_gprs'} eq 'TRUE')
    # GPRS  capability
    {   return 24;
    }
    elsif (exists $MAKEFILE_OPTIONS{'low_cost_support'} and $MAKEFILE_OPTIONS{'low_cost_support'} eq 'NONE')
    # GSM   capability  ; default
    {   return 16;
    }
    else
    # GSM   capability  ; low cost
    {   return  8;
    }
    &error_handler("tools\\sysGen1.pl: search file handle number fail!", __FILE__, __LINE__);
}

#****************************************************************************
# subroutine:  determine the amount for file system configure in fs_config.c
# return:      the value for recommend max thread number <NOTE!!!: scalar context>
#****************************************************************************
sub dispatch_threadnum
{
    if (exists $MAKEFILE_OPTIONS{'low_cost_support'} and $MAKEFILE_OPTIONS{'low_cost_support'} eq 'ULC')
    {
        return 3;
    }
    elsif (exists $MAKEFILE_OPTIONS{'l1_egprs'} and $MAKEFILE_OPTIONS{'l1_egprs'} eq 'TRUE')
    # EDGE  capability
    {   return 35;
    }
    elsif (exists $MAKEFILE_OPTIONS{'l1_gprs'} and $MAKEFILE_OPTIONS{'l1_gprs'} eq 'TRUE')
    # GPRS  capability
    {   return 23;
    }
    elsif (exists $MAKEFILE_OPTIONS{'low_cost_support'} and $MAKEFILE_OPTIONS{'low_cost_support'} eq 'NONE')
    # GSM   capability  ; default
    {   return 14;
    }
    else
    # GSM   capability  ; low cost (single bank no matter)
    {   return  9;
    }
    &error_handler("tools\\sysGen1.pl: search thread number fail!", __FILE__, __LINE__);
}

#****************************************************************************
# subroutine:  determine the template of global sys memory and
#              global debug memory for custom_config.c
# return:      the partial body strings in <NOTE!!!: list context>
#****************************************************************************
sub dispatch_globalmem_and_ctrlbuffpool
{
    my $gm_str_ref;
    my $cb_str_ref;
    my $gm_sys_tuning;
    my $gm_dbg_tuning;

    undef $gm_sys_tuning;
    undef $gm_dbg_tuning;
    
    if    (exists $MAKEFILE_OPTIONS{'mmi_version'} and $MAKEFILE_OPTIONS{'mmi_version'} eq 'WISDOM_MMI')
    {
        $gm_sys_tuning = " + 150*1024";
    }
    
    if    (exists $MAKEFILE_OPTIONS{'l1_wcdma'} and $MAKEFILE_OPTIONS{'l1_wcdma'} eq 'TRUE')
    # WCDMA capability
    {
        $gm_str_ref = &globalmem_wcdma($gm_sys_tuning, $gm_dbg_tuning);
        $cb_str_ref = &ctrlbuffpool_wcdma;
    }
    elsif (exists $MAKEFILE_OPTIONS{'l1_egprs'} and $MAKEFILE_OPTIONS{'l1_egprs'} eq 'TRUE')
    # EDGE  capability
    {
        $gm_str_ref = &globalmem_edge($gm_sys_tuning, $gm_dbg_tuning);
        $cb_str_ref = &ctrlbuffpool_as_default;
        $cb_str_ref.= &ctrlbuffpool_adjust_on_edge_class;
    }
    elsif (exists $MAKEFILE_OPTIONS{'l1_gprs'} and $MAKEFILE_OPTIONS{'l1_gprs'} eq 'TRUE')
    # GPRS  capability
    {
        $gm_str_ref = &globalmem_gprs($gm_sys_tuning, $gm_dbg_tuning);
        $cb_str_ref = &ctrlbuffpool_as_default;
        $cb_str_ref.= &ctrlbuffpool_adjust_on_gprs_class;
    }
    elsif (exists $MAKEFILE_OPTIONS{'low_cost_support'} and $MAKEFILE_OPTIONS{'low_cost_support'} eq 'COMMON')
    # GSM   capability  ; LOW_COST_SUPPORT = COMMON
    {   
    	  $gm_str_ref = &globalmem_gsm_lowcost($gm_sys_tuning, $gm_dbg_tuning);
        $cb_str_ref = &ctrlbuffpool_as_default;
    }
    elsif (exists $MAKEFILE_OPTIONS{'low_cost_support'} and $MAKEFILE_OPTIONS{'low_cost_support'} eq 'ULC')
    # GSM   capability  ; LOW_COST_SUPPORT = ULC
    {
        $gm_str_ref = &globalmem_gsm_lowcost_ulc($gm_sys_tuning, $gm_dbg_tuning);
        $cb_str_ref = &ctrlbuffpool_as_default;
    }
    return ($gm_str_ref, $cb_str_ref);
}

#****************************************************************************
# subroutine:  generate global memory definiation for WCDMA type
# return:      the body strings
# EXAMPLE PROJECT : MONZA29E2_EVB
#****************************************************************************
sub globalmem_wcdma
{
    my ($sys_mem_tuning_str, $dbg_mem_tuning_str) = @_;
    my $template = <<"__TEMPLATE";
/* SysGen Template Type : WCDMA Generic */
#if defined(__UMTS_RAT__)

    #if defined(KAL_ON_OSCAR)
       #if defined(OPERA_V10_BROWSER)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          (7570*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (5450*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          (7570*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (5270*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          (7555*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (5270*1024$dbg_mem_tuning_str)
          #endif
       #else
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          (7490*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (5450*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          (7490*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (5270*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          (7475*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (5270*1024$dbg_mem_tuning_str)
          #endif
       #endif       
    #else /* KAL_ON_OSCAR */
       #if defined(__CMMB_CAS_SMD_SUPPORT__) && defined(OPERA_V10_BROWSER)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          (4290*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 260*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          (4290*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  80*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          (4275*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  80*1024$dbg_mem_tuning_str)
          #endif
       #elif defined(__CMMB_CAS_SMD_SUPPORT__) || defined(OPERA_V10_BROWSER)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          (1580*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 230*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          (1580*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  50*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          (1565*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  50*1024$dbg_mem_tuning_str)
          #endif
       #else
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          (1480*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 230*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          (1480*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  50*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          (1465*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  50*1024$dbg_mem_tuning_str)
          #endif
       #endif
    #endif

#else  /* __UMTS_RAT__ */

    #if defined(KAL_ON_OSCAR)
       #define GLOBAL_MEM_SIZE          ( 290*1024$sys_mem_tuning_str)
       #define GLOBAL_DEBUG_MEM_SIZE    ( 100*1024$dbg_mem_tuning_str)
    #else /* KAL_ON_OSCAR */
       #define GLOBAL_MEM_SIZE          ( 290*1024$sys_mem_tuning_str)
       #define GLOBAL_DEBUG_MEM_SIZE    ( 100*1024$dbg_mem_tuning_str)
    #endif

#endif /* __UMTS_RAT__ */

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  generate global memory definiation for EDGE type
# return:      the body strings
# EXAMPLE PROJECT : SUPERMAN29_BB
#****************************************************************************
sub globalmem_edge
{
    my ($sys_mem_tuning_str, $dbg_mem_tuning_str) = @_;
    my $template = <<"__TEMPLATE";
/* SysGen Template Type : EDGE Generic */
#if defined(__EGPRS_MODE__) && ( defined(__VOIP__) || defined(__WIFI_SUPPORT__) ) && defined(OPERA_V10_BROWSER)

    #if defined(KAL_ON_OSCAR)
       #if defined(__GEMINI__) && defined(__GADGET_SUPPORT__)
          #if ( GEMINI_PLUS > 2 )
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 600*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 272*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 600*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 212*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 595*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 212*1024$dbg_mem_tuning_str)
             #endif
          #else  /* GEMINI_PLUS > 2 */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 570*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 272*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 570*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 212*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 565*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 212*1024$dbg_mem_tuning_str)
             #endif
          #endif  /* GEMINI_PLUS > 2 */
       #elif defined(__GEMINI__)
          #if ( GEMINI_PLUS > 2 )
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 580*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 272*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 580*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 212*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 575*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 212*1024$dbg_mem_tuning_str)
             #endif
          #else  /* GEMINI_PLUS > 2 */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 550*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 272*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 550*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 212*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 545*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 212*1024$dbg_mem_tuning_str)
             #endif
          #endif  /* GEMINI_PLUS > 2 */
       #elif defined(__GADGET_SUPPORT__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 550*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 272*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 550*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 227*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 546*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 227*1024$dbg_mem_tuning_str)
          #endif
       #else
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 530*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 252*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 530*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 207*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 526*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 207*1024$dbg_mem_tuning_str)
          #endif
       #endif
    #elif defined(__CMMB_CAS_SMD_SUPPORT__) /* KAL_ON_OSCAR */
       #if defined(__GEMINI__) && defined(__GADGET_SUPPORT__)
          #if ( GEMINI_PLUS > 2 )
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 680*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 100*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 680*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  40*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 675*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  40*1024$dbg_mem_tuning_str)
             #endif
          #else  /* GEMINI_PLUS > 2 */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 650*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 100*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 650*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  40*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 645*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  40*1024$dbg_mem_tuning_str)
             #endif
          #endif  /* GEMINI_PLUS > 2 */
       #elif defined(__GEMINI__)
          #if ( GEMINI_PLUS > 2 )
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 660*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 100*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 660*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  40*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 655*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  40*1024$dbg_mem_tuning_str)
             #endif
          #else  /* GEMINI_PLUS > 2 */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 630*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 100*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 630*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  40*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 625*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  40*1024$dbg_mem_tuning_str)
             #endif
          #endif  /* GEMINI_PLUS > 2 */
       #elif defined(__GADGET_SUPPORT__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 630*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 100*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 630*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  55*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 626*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  55*1024$dbg_mem_tuning_str)
          #endif
       #else
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 610*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  80*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 610*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  35*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 606*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  35*1024$dbg_mem_tuning_str)
          #endif
       #endif
    #else /* KAL_ON_OSCAR */
       #if defined(__GEMINI__) && defined(__GADGET_SUPPORT__)
          #if ( GEMINI_PLUS > 2 )
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 594*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  87*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 594*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  27*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 589*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  27*1024$dbg_mem_tuning_str)
             #endif
          #else  /* GEMINI_PLUS > 2 */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 564*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  87*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 564*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  27*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 559*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  27*1024$dbg_mem_tuning_str)
             #endif
          #endif  /* GEMINI_PLUS > 2 */
       #elif defined(__GEMINI__)
          #if ( GEMINI_PLUS > 2 )
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 580*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 100*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 580*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  40*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 575*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  40*1024$dbg_mem_tuning_str)
             #endif
          #else  /* GEMINI_PLUS > 2 */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 550*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 100*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 550*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  40*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 545*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  40*1024$dbg_mem_tuning_str)
             #endif
          #endif  /* GEMINI_PLUS > 2 */
       #elif defined(__GADGET_SUPPORT__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 550*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 100*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 550*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  55*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 546*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  55*1024$dbg_mem_tuning_str)
          #endif
       #else
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 484*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  67*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 484*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  22*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 480*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  22*1024$dbg_mem_tuning_str)
          #endif
       #endif
    #endif

#elif defined(__EGPRS_MODE__) && ( defined(__VOIP__) || defined(__WIFI_SUPPORT__) ) && defined(OBIGO_Q05A)

    #if defined(KAL_ON_OSCAR)
       #if defined(__GEMINI__) && defined(__GADGET_SUPPORT__)
          #if ( GEMINI_PLUS > 2 )
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 554*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 272*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 554*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 212*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 549*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 212*1024$dbg_mem_tuning_str)
             #endif
          #else  /* GEMINI_PLUS > 2 */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 524*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 272*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 524*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 212*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 519*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 212*1024$dbg_mem_tuning_str)
             #endif
          #endif  /* GEMINI_PLUS > 2 */
       #elif defined(__GEMINI__)
          #if ( GEMINI_PLUS > 2 )
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 534*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 272*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 534*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 212*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 529*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 212*1024$dbg_mem_tuning_str)
             #endif
          #else  /* GEMINI_PLUS > 2 */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 504*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 272*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 504*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 212*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 499*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 212*1024$dbg_mem_tuning_str)
             #endif
          #endif  /* GEMINI_PLUS > 2 */
       #elif defined(__GADGET_SUPPORT__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 504*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 272*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 504*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 227*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 500*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 227*1024$dbg_mem_tuning_str)
          #endif
       #else
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 484*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 252*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 484*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 207*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 480*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 207*1024$dbg_mem_tuning_str)
          #endif
       #endif
    #elif defined(__CMMB_CAS_SMD_SUPPORT__) /* KAL_ON_OSCAR */
       #if defined(__GEMINI__) && defined(__GADGET_SUPPORT__)
          #if ( GEMINI_PLUS > 2 )
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 634*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 100*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 634*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  40*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 629*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  40*1024$dbg_mem_tuning_str)
             #endif
          #else  /* GEMINI_PLUS > 2 */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 604*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 100*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 604*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  40*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 599*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  40*1024$dbg_mem_tuning_str)
             #endif
          #endif  /* GEMINI_PLUS > 2 */
       #elif defined(__GEMINI__)
          #if ( GEMINI_PLUS > 2 )
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 614*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 100*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 614*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  40*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 609*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  40*1024$dbg_mem_tuning_str)
             #endif
          #else  /* GEMINI_PLUS > 2 */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 584*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 100*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 584*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  40*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 579*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  40*1024$dbg_mem_tuning_str)
             #endif
          #endif  /* GEMINI_PLUS > 2 */
       #elif defined(__GADGET_SUPPORT__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 584*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 100*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 584*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  55*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 580*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  55*1024$dbg_mem_tuning_str)
          #endif
       #else
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 564*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  80*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 564*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  35*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 560*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  35*1024$dbg_mem_tuning_str)
          #endif
       #endif
    #else /* KAL_ON_OSCAR */
       #if defined(__GEMINI__) && defined(__GADGET_SUPPORT__)
          #if ( GEMINI_PLUS > 2 )
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 554*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 100*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 554*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  40*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 549*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  40*1024$dbg_mem_tuning_str)
             #endif
          #else  /* GEMINI_PLUS > 2 */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 524*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 100*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 524*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  40*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 519*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  40*1024$dbg_mem_tuning_str)
             #endif
          #endif  /* GEMINI_PLUS > 2 */
       #elif defined(__GEMINI__)
          #if ( GEMINI_PLUS > 2 )
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 479*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  82*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 479*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  22*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 474*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  22*1024$dbg_mem_tuning_str)
             #endif
          #else  /* GEMINI_PLUS > 2 */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 449*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  82*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 449*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  22*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 444*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  22*1024$dbg_mem_tuning_str)
             #endif
          #endif  /* GEMINI_PLUS > 2 */
       #elif defined(__GADGET_SUPPORT__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 449*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  82*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 449*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  37*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 445*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  37*1024$dbg_mem_tuning_str)
          #endif
       #else
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 449*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  67*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 449*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  22*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 445*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  22*1024$dbg_mem_tuning_str)
          #endif
       #endif
    #endif

#elif defined(__EGPRS_MODE__) && ( defined(__VOIP__) || defined(__WIFI_SUPPORT__) )

    #if defined(KAL_ON_OSCAR)
       #if defined(__GEMINI__) && defined(__GADGET_SUPPORT__)
          #if ( GEMINI_PLUS > 2 )
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 524*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 272*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 524*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 212*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 519*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 212*1024$dbg_mem_tuning_str)
             #endif
          #else  /* GEMINI_PLUS > 2 */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 494*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 272*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 494*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 212*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 489*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 212*1024$dbg_mem_tuning_str)
             #endif
          #endif  /* GEMINI_PLUS > 2 */
       #elif defined(__GEMINI__)
          #if ( GEMINI_PLUS > 2 )
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 504*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 272*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 504*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 212*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 499*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 212*1024$dbg_mem_tuning_str)
             #endif
          #else  /* GEMINI_PLUS > 2 */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 474*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 272*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 474*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 212*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 469*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 212*1024$dbg_mem_tuning_str)
             #endif
          #endif  /* GEMINI_PLUS > 2 */
       #elif defined(__GADGET_SUPPORT__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 474*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 272*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 474*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 227*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 470*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 227*1024$dbg_mem_tuning_str)
          #endif
       #else
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 454*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 252*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 454*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 207*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 450*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 207*1024$dbg_mem_tuning_str)
          #endif
       #endif
    #elif defined(__CMMB_CAS_SMD_SUPPORT__) /* KAL_ON_OSCAR */
       #if defined(__GEMINI__) && defined(__GADGET_SUPPORT__)
          #if ( GEMINI_PLUS > 2 )
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 604*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 100*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 604*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  40*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 599*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  40*1024$dbg_mem_tuning_str)
             #endif
          #else  /* GEMINI_PLUS > 2 */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 574*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 100*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 574*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  40*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 569*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  40*1024$dbg_mem_tuning_str)
             #endif
          #endif  /* GEMINI_PLUS > 2 */
       #elif defined(__GEMINI__)
          #if ( GEMINI_PLUS > 2 )
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 584*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 100*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 584*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  40*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 579*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  40*1024$dbg_mem_tuning_str)
             #endif
          #else  /* GEMINI_PLUS > 2 */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 554*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 100*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 554*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  40*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 549*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  40*1024$dbg_mem_tuning_str)
             #endif
          #endif  /* GEMINI_PLUS > 2 */
       #elif defined(__GADGET_SUPPORT__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 554*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 100*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 554*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  55*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 550*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  55*1024$dbg_mem_tuning_str)
          #endif
       #else
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 534*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  80*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 534*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  35*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 530*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  35*1024$dbg_mem_tuning_str)
          #endif
       #endif
    #else /* KAL_ON_OSCAR */
       #if defined(__GEMINI__) && defined(__GADGET_SUPPORT__)
          #if ( GEMINI_PLUS > 2 )
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 554*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  87*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 554*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  27*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 549*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  27*1024$dbg_mem_tuning_str)
             #endif
          #else  /* GEMINI_PLUS > 2 */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 524*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  87*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 524*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  27*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 519*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  27*1024$dbg_mem_tuning_str)
             #endif
          #endif  /* GEMINI_PLUS > 2 */
       #elif defined(__GEMINI__)
          #if ( GEMINI_PLUS > 2 )
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 484*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  87*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 484*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  27*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 479*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  27*1024$dbg_mem_tuning_str)
             #endif
          #else  /* GEMINI_PLUS > 2 */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 454*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  87*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 454*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  27*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 449*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  27*1024$dbg_mem_tuning_str)
             #endif
          #endif  /* GEMINI_PLUS > 2 */
       #elif defined(__GADGET_SUPPORT__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 454*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  87*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 454*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  42*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 450*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  42*1024$dbg_mem_tuning_str)
          #endif
       #else
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 434*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  82*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 434*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  37*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 430*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  37*1024$dbg_mem_tuning_str)
          #endif
       #endif
    #endif

#elif defined(OPERA_V10_BROWSER)

    #if defined(KAL_ON_OSCAR)
       #if defined(__GEMINI__) && defined(__GADGET_SUPPORT__)
          #if ( GEMINI_PLUS > 2 )
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 540*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  82*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 540*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  22*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 535*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  22*1024$dbg_mem_tuning_str)
             #endif
          #else  /* GEMINI_PLUS > 2 */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 510*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  82*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 510*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  22*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 505*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  22*1024$dbg_mem_tuning_str)
             #endif
          #endif  /* GEMINI_PLUS > 2 */
       #elif defined(__GEMINI__)
          #if ( GEMINI_PLUS > 2 )
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 520*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  82*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 520*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  22*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 515*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  22*1024$dbg_mem_tuning_str)
             #endif
          #else  /* GEMINI_PLUS > 2 */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 490*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  82*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 490*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  22*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 485*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  22*1024$dbg_mem_tuning_str)
             #endif
          #endif  /* GEMINI_PLUS > 2 */
       #elif defined(__GADGET_SUPPORT__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 490*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  82*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 490*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  37*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 486*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  37*1024$dbg_mem_tuning_str)
          #endif
       #else
          #if defined(__AGPS_SUPPORT__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 490*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  72*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 490*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  27*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 486*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  27*1024$dbg_mem_tuning_str)
             #endif
          #else
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 470*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  62*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 470*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  17*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 466*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  17*1024$dbg_mem_tuning_str)
             #endif
          #endif
       #endif
    #elif defined(__CMMB_CAS_SMD_SUPPORT__) /* KAL_ON_OSCAR */
       #if defined(__GEMINI__) && defined(__GADGET_SUPPORT__)
          #if ( GEMINI_PLUS > 2 )
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 607*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  78*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 1214*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 1205*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #endif
          #else  /* GEMINI_PLUS > 2 */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 574*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  73*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 1148*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 1139*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #endif
          #endif  /* GEMINI_PLUS > 2 */
       #elif defined(__GEMINI__)
          #if ( GEMINI_PLUS > 2 )
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 587*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  78*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 1174*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 1165*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #endif
          #else  /* GEMINI_PLUS > 2 */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 554*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  73*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 1108*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 1099*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #endif
          #endif  /* GEMINI_PLUS > 2 */
       #elif defined(__GADGET_SUPPORT__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 556*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  77*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 1112*512$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (   74*512$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 1104*512$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (   74*512$dbg_mem_tuning_str)
          #endif
       #else
          #if defined(__AGPS_SUPPORT__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 556*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  67*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 1112*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   54*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 1104*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   54*512$dbg_mem_tuning_str)
             #endif
          #else
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 536*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  57*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 1072*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   34*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 1064*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   34*512$dbg_mem_tuning_str)
             #endif
          #endif
       #endif
    #else /* KAL_ON_OSCAR */
       #if defined(__GEMINI__) && defined(__GADGET_SUPPORT__)
          #if ( GEMINI_PLUS > 2 )
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 527*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  78*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 1054*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 1045*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #endif
          #else  /* GEMINI_PLUS > 2 */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 494*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  73*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  988*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  979*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #endif
          #endif  /* GEMINI_PLUS > 2 */
       #elif defined(__GEMINI__)
          #if ( GEMINI_PLUS > 2 )
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 511*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  63*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 1022*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   14*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 1013*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   14*512$dbg_mem_tuning_str)
             #endif
          #else  /* GEMINI_PLUS > 2 */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 478*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  58*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  956*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   14*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  947*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   14*512$dbg_mem_tuning_str)
             #endif
          #endif  /* GEMINI_PLUS > 2 */
       #elif defined(__GADGET_SUPPORT__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 480*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  62*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          (  960*512$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          (  952*512$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
          #endif
       #else
          #if defined(__AGPS_SUPPORT__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 476*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  67*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  952*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   54*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  944*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   54*512$dbg_mem_tuning_str)
             #endif
          #else
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 456*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  57*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  912*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   34*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  904*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   34*512$dbg_mem_tuning_str)
             #endif
          #endif
       #endif
    #endif

#elif defined(OBIGO_Q05A)

    #if defined(KAL_ON_OSCAR)
       #if defined(__GEMINI__) && defined(__GADGET_SUPPORT__)
          #if ( GEMINI_PLUS > 2 )
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 494*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  82*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 494*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  22*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 489*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  22*1024$dbg_mem_tuning_str)
             #endif
          #else  /* GEMINI_PLUS > 2 */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 464*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  82*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 464*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  22*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 459*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  22*1024$dbg_mem_tuning_str)
             #endif
          #endif  /* GEMINI_PLUS > 2 */
       #elif defined(__GEMINI__)
          #if ( GEMINI_PLUS > 2 )
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 474*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  82*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 474*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  22*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 469*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  22*1024$dbg_mem_tuning_str)
             #endif
          #else  /* GEMINI_PLUS > 2 */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 444*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  82*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 444*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  22*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 439*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  22*1024$dbg_mem_tuning_str)
             #endif
          #endif  /* GEMINI_PLUS > 2 */
       #elif defined(__GADGET_SUPPORT__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 444*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  82*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 444*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  37*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 440*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  37*1024$dbg_mem_tuning_str)
          #endif
       #else
          #if defined(__AGPS_SUPPORT__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 444*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  72*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 444*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  27*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 440*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  27*1024$dbg_mem_tuning_str)
             #endif
          #else
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 424*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  62*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 424*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  17*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 420*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  17*1024$dbg_mem_tuning_str)
             #endif
          #endif
       #endif
    #elif defined(__CMMB_CAS_SMD_SUPPORT__) /* KAL_ON_OSCAR */
       #if defined(__GEMINI__) && defined(__GADGET_SUPPORT__)
          #if ( GEMINI_PLUS > 2 )
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 541*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  78*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 1082*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 1073*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #endif
          #else  /* GEMINI_PLUS > 2 */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 508*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  73*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 1016*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 1007*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #endif
          #endif  /* GEMINI_PLUS > 2 */
       #elif defined(__GEMINI__)
          #if ( GEMINI_PLUS > 2 )
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 521*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  78*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 1042*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 1033*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #endif
          #else  /* GEMINI_PLUS > 2 */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 488*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  73*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  976*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  967*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #endif
          #endif  /* GEMINI_PLUS > 2 */
       #elif defined(__GADGET_SUPPORT__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 490*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  77*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          (  980*512$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (   74*512$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          (  972*512$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (   74*512$dbg_mem_tuning_str)
          #endif
       #else
          #if defined(__AGPS_SUPPORT__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 490*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  67*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  980*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   54*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  972*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   54*512$dbg_mem_tuning_str)
             #endif
          #else
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 470*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  57*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  940*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   34*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  932*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   34*512$dbg_mem_tuning_str)
             #endif
          #endif
       #endif
    #else /* KAL_ON_OSCAR */
       #if defined(__GEMINI__) && defined(__GADGET_SUPPORT__)
          #if ( GEMINI_PLUS > 2 )
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 461*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  78*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  922*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  913*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #endif
          #else  /* GEMINI_PLUS > 2 */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 428*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  73*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  856*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  847*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #endif
          #endif  /* GEMINI_PLUS > 2 */
       #elif defined(__GEMINI__)
          #if ( GEMINI_PLUS > 2 )
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 441*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  78*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  882*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  873*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #endif
          #else  /* GEMINI_PLUS > 2 */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 408*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  73*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  816*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  807*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #endif
          #endif  /* GEMINI_PLUS > 2 */
       #elif defined(__GADGET_SUPPORT__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 410*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  77*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          (  820*512$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (   74*512$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          (  812*512$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (   74*512$dbg_mem_tuning_str)
          #endif
       #else
          #if defined(__AGPS_SUPPORT__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 410*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  67*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  820*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   54*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  812*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   54*512$dbg_mem_tuning_str)
             #endif
          #else
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 390*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  57*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  780*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   34*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  772*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   34*512$dbg_mem_tuning_str)
             #endif
          #endif
       #endif
    #endif

#else  /* __EGPRS_MODE__ && ( __VOIP__ || __WIFI_SUPPORT__ ) && OBIGO_Q05A */

    #if defined(KAL_ON_OSCAR)
       #if defined(__GEMINI__) && defined(__GADGET_SUPPORT__)
          #if ( GEMINI_PLUS > 2 )
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 464*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  82*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 464*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  22*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 459*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  22*1024$dbg_mem_tuning_str)
             #endif
          #else  /* GEMINI_PLUS > 2 */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 434*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  82*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 434*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  22*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 429*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  22*1024$dbg_mem_tuning_str)
             #endif
          #endif  /* GEMINI_PLUS > 2 */
       #elif defined(__GEMINI__)
          #if ( GEMINI_PLUS > 2 )
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 444*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  82*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 444*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  22*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 439*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  22*1024$dbg_mem_tuning_str)
             #endif
          #else  /* GEMINI_PLUS > 2 */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 414*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  82*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 414*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  22*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 409*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  22*1024$dbg_mem_tuning_str)
             #endif
          #endif  /* GEMINI_PLUS > 2 */
       #elif defined(__GADGET_SUPPORT__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 414*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  82*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 414*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  37*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 410*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  37*1024$dbg_mem_tuning_str)
          #endif
       #else
          #if defined(__AGPS_SUPPORT__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 414*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  72*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 414*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  27*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 410*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  27*1024$dbg_mem_tuning_str)
             #endif
          #else
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 394*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  62*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 394*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  17*1024$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 390*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  17*1024$dbg_mem_tuning_str)
             #endif
          #endif
       #endif
    #elif defined(__CMMB_CAS_SMD_SUPPORT__) /* KAL_ON_OSCAR */
       #if defined(__GEMINI__) && defined(__GADGET_SUPPORT__)
          #if ( GEMINI_PLUS > 2 )
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 531*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  78*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 1062*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 1053*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #endif
          #else  /* GEMINI_PLUS > 2 */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 498*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  73*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  996*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  987*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #endif
          #endif  /* GEMINI_PLUS > 2 */
       #elif defined(__GEMINI__)
          #if ( GEMINI_PLUS > 2 )
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 511*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  78*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          ( 1022*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          ( 1013*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #endif
          #else  /* GEMINI_PLUS > 2 */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 478*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  73*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  956*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  947*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #endif
          #endif  /* GEMINI_PLUS > 2 */
       #elif defined(__GADGET_SUPPORT__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 480*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  77*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          (  960*512$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (   74*512$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          (  952*512$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (   74*512$dbg_mem_tuning_str)
          #endif
       #else
          #if defined(__AGPS_SUPPORT__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 480*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  67*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  960*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   54*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  952*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   54*512$dbg_mem_tuning_str)
             #endif
          #else
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 460*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  57*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  920*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   34*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  912*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   34*512$dbg_mem_tuning_str)
             #endif
          #endif
       #endif
    #else /* KAL_ON_OSCAR */
       #if defined(__GEMINI__) && defined(__GADGET_SUPPORT__)
          #if ( GEMINI_PLUS > 2 )
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 451*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  78*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  902*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  893*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #endif
          #else  /* GEMINI_PLUS > 2 */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 418*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  73*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  836*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  827*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #endif
          #endif  /* GEMINI_PLUS > 2 */
       #elif defined(__GEMINI__)
          #if ( GEMINI_PLUS > 2 )
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 457*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  78*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  914*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  905*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #endif
          #else  /* GEMINI_PLUS > 2 */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 424*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  73*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  848*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  839*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   44*512$dbg_mem_tuning_str)
             #endif
          #endif  /* GEMINI_PLUS > 2 */
       #elif defined(__GADGET_SUPPORT__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 405*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  77*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          (  810*512$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (   74*512$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          (  802*512$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (   74*512$dbg_mem_tuning_str)
          #endif
       #else
          #if defined(__AGPS_SUPPORT__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 395*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  57*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  790*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   34*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  782*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   34*512$dbg_mem_tuning_str)
             #endif
          #else
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 380*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  57*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  760*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   34*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  752*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   34*512$dbg_mem_tuning_str)
             #endif
          #endif
       #endif
    #endif

#endif /* __EGPRS_MODE__ && ( __VOIP__ || __WIFI_SUPPORT__ ) && OBIGO_Q05A */

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  generate global memory definiation for GPRS type
# return:      the body strings
# EXAMPLE PROJECT : SAPPHIRE28_BB
#****************************************************************************
sub globalmem_gprs
{
    my ($sys_mem_tuning_str, $dbg_mem_tuning_str) = @_;
    my $template = <<"__TEMPLATE";
/* SysGen Template Type : GPRS Generic */
#if defined(__OP01__) || defined(__OP11__) || defined(__OP12__)
#define __SYS_MEM_OP_PROJ__
#endif /* __OP01__ || __OP11__ || __OP12__ */

#if (defined(__WIFI_SUPPORT__) || defined(__VOIP__)) && defined(OBIGO_Q05A)

    #if defined(__GEMINI__) && defined(__GADGET_SUPPORT__)
       #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 450*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 120*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 450*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 445*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024$dbg_mem_tuning_str)
          #endif
       #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 430*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 120*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 430*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 425*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024$dbg_mem_tuning_str)
          #endif
       #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 410*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 120*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 410*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 405*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024$dbg_mem_tuning_str)
          #endif
       #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
    #elif defined(__GEMINI__)
       #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 430*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 120*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 430*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 425*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024$dbg_mem_tuning_str)
          #endif
       #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 410*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 120*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 410*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 405*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024$dbg_mem_tuning_str)
          #endif
       #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 390*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 120*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 390*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 385*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024$dbg_mem_tuning_str)
          #endif
       #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
    #elif defined(__GADGET_SUPPORT__)
       #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 430*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 120*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 430*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  75*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 426*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  75*1024$dbg_mem_tuning_str)
          #endif
       #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 410*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 120*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 410*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  75*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 406*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  75*1024$dbg_mem_tuning_str)
          #endif
       #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 390*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 120*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 390*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  75*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 386*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  75*1024$dbg_mem_tuning_str)
          #endif
       #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
    #else
       #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 410*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 110*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 410*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  65*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 406*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  65*1024$dbg_mem_tuning_str)
          #endif
       #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 390*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 110*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 390*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  65*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 386*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  65*1024$dbg_mem_tuning_str)
          #endif
       #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 370*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 110*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 370*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  65*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 366*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  65*1024$dbg_mem_tuning_str)
          #endif
       #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
    #endif

#elif defined(__WIFI_SUPPORT__) || defined(__VOIP__)

    #if defined(__GEMINI__) && defined(__GADGET_SUPPORT__)
       #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 420*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 120*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 420*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 415*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024$dbg_mem_tuning_str)
          #endif
       #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 400*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 120*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 400*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 395*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024$dbg_mem_tuning_str)
          #endif
       #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 380*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 120*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 380*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 375*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024$dbg_mem_tuning_str)
          #endif
       #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
    #elif defined(__GEMINI__)
       #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 400*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 120*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 400*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 395*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024$dbg_mem_tuning_str)
          #endif
       #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 380*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 120*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 380*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 375*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024$dbg_mem_tuning_str)
          #endif
       #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 370*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 120*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 370*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 365*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024$dbg_mem_tuning_str)
          #endif
       #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
    #elif defined(__GADGET_SUPPORT__)
       #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 400*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 120*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 400*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  75*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 396*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  75*1024$dbg_mem_tuning_str)
          #endif
       #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 380*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 120*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 380*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  75*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 376*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  75*1024$dbg_mem_tuning_str)
          #endif
       #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 370*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 120*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 370*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  75*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 366*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  75*1024$dbg_mem_tuning_str)
          #endif
       #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
    #else /* __GEMINI__ */
       #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 380*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 110*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 380*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  65*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 376*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  65*1024$dbg_mem_tuning_str)
          #endif
       #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 370*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 110*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 370*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  65*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 366*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  65*1024$dbg_mem_tuning_str)
          #endif
       #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 370*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 110*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 370*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  65*1024$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          ( 366*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  65*1024$dbg_mem_tuning_str)
          #endif
       #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
    #endif /* __GEMINI__ */

#elif defined(OBIGO_Q05A)

    #if defined(__GEMINI__) && defined(__GADGET_SUPPORT__)
       #if ( GEMINI_PLUS > 2 )
          #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 397*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 106*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  794*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  775*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #endif
          #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 377*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 106*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  754*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  745*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #endif
          #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
             #if defined(DEBUG_BUF2)
	        #define GLOBAL_MEM_SIZE          ( 357*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 106*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  714*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  705*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #endif
          #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
       #else  /* GEMINI_PLUS > 2 */
          #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 394*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 101*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  788*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  779*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #endif
          #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 374*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 101*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  748*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  739*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #endif
          #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 354*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 101*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  708*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  699*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #endif
          #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
       #endif  /* GEMINI_PLUS > 2 */
    #elif defined(__GEMINI__)
       #if ( GEMINI_PLUS > 2 )
          #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 377*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 106*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  754*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  745*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #endif
          #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 357*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 106*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  714*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  705*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #endif
          #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 337*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 106*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  674*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  665*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #endif
          #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
       #else  /* GEMINI_PLUS > 2 */
          #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 374*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 101*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  748*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  739*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #endif
          #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 354*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 101*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  708*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  699*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #endif
          #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 334*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 101*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  668*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  659*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #endif
          #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
       #endif  /* GEMINI_PLUS > 2 */
    #elif defined(__GADGET_SUPPORT__)
       #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 376*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 105*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          (  752*512$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          (  744*512$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
          #endif
       #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 356*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 105*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          (  712*512$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          (  704*512$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
          #endif
       #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 336*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 105*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          (  672*512$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          (  664*512$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
          #endif
       #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
    #else /* __GEMINI__ */
       #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 356*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  95*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          (  712*512$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          (  704*512$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
          #endif
       #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 286*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          (  572*512$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          (  564*512$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
          #endif
       #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 316*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  95*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          (  632*512$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          (  624*512$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
          #endif
       #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
    #endif /* __GEMINI__ */

#else /* (__WIFI_SUPPORT__ || __VOIP__) && OBIGO_Q05A */

    #if defined(__GEMINI__) && defined(__GADGET_SUPPORT__)
       #if ( GEMINI_PLUS > 2 )
          #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 397*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 106*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  794*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  785*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #endif
          #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 377*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 106*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  754*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  745*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #endif
          #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 357*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 106*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  714*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  705*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #endif
          #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
       #else  /* GEMINI_PLUS > 2 */
          #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 394*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 101*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  788*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  779*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #endif
          #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 374*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 101*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  748*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  739*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #endif
          #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 354*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 101*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  708*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  699*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #endif
          #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
       #endif  /* GEMINI_PLUS > 2 */
    #elif defined(__GEMINI__)
       #if ( GEMINI_PLUS > 2 )
          #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 377*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 106*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  754*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  745*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #endif
          #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 352*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  76*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  704*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  695*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #endif
          #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 337*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 106*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  674*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  665*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #endif
          #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
       #else  /* GEMINI_PLUS > 2 */
          #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 374*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 101*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  748*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  739*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #endif
          #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 349*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (  71*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  698*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  689*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #endif
          #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 334*1024$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 101*1024$dbg_mem_tuning_str)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  668*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #else
                #define GLOBAL_MEM_SIZE          (  659*512$sys_mem_tuning_str)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
             #endif
          #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
       #endif  /* GEMINI_PLUS > 2 */
    #elif defined(__GADGET_SUPPORT__)
       #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 376*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 105*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          (  752*512$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          (  744*512$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
          #endif
       #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 351*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  75*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          (  702*512$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          (  694*512$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
          #endif
       #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 336*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 105*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          (  672*512$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          (  664*512$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
          #endif
       #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
    #else /* __GEMINI__ */
       #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 326*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  95*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          (  652*512$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          (  644*512$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
          #endif
       #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 336*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  75*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          (  672*512$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          (  664*512$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
          #endif
       #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 296*1024$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (  50*1024$dbg_mem_tuning_str)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          (  592*512$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
          #else
             #define GLOBAL_MEM_SIZE          (  584*512$sys_mem_tuning_str)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512$dbg_mem_tuning_str)
          #endif
       #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
    #endif /* __GEMINI__ */

#endif /* (__WIFI_SUPPORT__ || __VOIP__) && OBIGO_Q05A */

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  generate global memory definiation for GSM type
# return:      the body strings
# EXAMPLE PROJECT : MT6205_CEVB
#****************************************************************************
sub globalmem_gsm
{
    my ($sys_mem_tuning_str, $dbg_mem_tuning_str) = @_;
    my $template = <<"__TEMPLATE";
/* SysGen Template Type : GSM Generic */
#if defined(__GEMINI__) && defined(__GADGET_SUPPORT__)

    #if defined(DEBUG_BUF2)
       #define GLOBAL_MEM_SIZE          ( 240*1024$sys_mem_tuning_str)
       #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024$dbg_mem_tuning_str)
    #elif defined(DEBUG_BUF1)
       #define GLOBAL_MEM_SIZE          ( 240*1024$sys_mem_tuning_str)
       #define GLOBAL_DEBUG_MEM_SIZE    (   5*1024$dbg_mem_tuning_str)
    #else
       #define GLOBAL_MEM_SIZE          ( 235*1024$sys_mem_tuning_str)
       #define GLOBAL_DEBUG_MEM_SIZE    (   5*1024$dbg_mem_tuning_str)
    #endif

#elif defined(__GEMINI__)

    #if defined(DEBUG_BUF2)
       #define GLOBAL_MEM_SIZE          ( 220*1024$sys_mem_tuning_str)
       #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024$dbg_mem_tuning_str)
    #elif defined(DEBUG_BUF1)
       #define GLOBAL_MEM_SIZE          ( 220*1024$sys_mem_tuning_str)
       #define GLOBAL_DEBUG_MEM_SIZE    (   5*1024$dbg_mem_tuning_str)
    #else
       #define GLOBAL_MEM_SIZE          ( 215*1024$sys_mem_tuning_str)
       #define GLOBAL_DEBUG_MEM_SIZE    (   5*1024$dbg_mem_tuning_str)
    #endif

#elif defined(__GADGET_SUPPORT__)

    #if defined(DEBUG_BUF2)
       #define GLOBAL_MEM_SIZE          ( 220*1024$sys_mem_tuning_str)
       #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024$dbg_mem_tuning_str)
    #elif defined(DEBUG_BUF1)
       #define GLOBAL_MEM_SIZE          ( 220*1024$sys_mem_tuning_str)
       #define GLOBAL_DEBUG_MEM_SIZE    (  35*1024$dbg_mem_tuning_str)
    #else
       #define GLOBAL_MEM_SIZE          ( 218*1024$sys_mem_tuning_str)
       #define GLOBAL_DEBUG_MEM_SIZE    (  35*1024$dbg_mem_tuning_str)
    #endif

#else

    #if defined(DEBUG_BUF2)
       #define GLOBAL_MEM_SIZE          ( 200*1024$sys_mem_tuning_str)
       #define GLOBAL_DEBUG_MEM_SIZE    (  40*1024$dbg_mem_tuning_str)
    #elif defined(DEBUG_BUF1)
       #define GLOBAL_MEM_SIZE          ( 200*1024$sys_mem_tuning_str)
       #define GLOBAL_DEBUG_MEM_SIZE    (  15*1024$dbg_mem_tuning_str)
    #else
       #define GLOBAL_MEM_SIZE          ( 198*1024$sys_mem_tuning_str)
       #define GLOBAL_DEBUG_MEM_SIZE    (  15*1024$dbg_mem_tuning_str)
    #endif
        
#endif
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  generate global memory definiation for GSM + LOW COST (COMMON) type
# return:      the body strings
# EXAMPLE PROJECT : NEPTUNE_BB
#****************************************************************************
sub globalmem_gsm_lowcost
{
    my ($sys_mem_tuning_str, $dbg_mem_tuning_str) = @_;
    my $template = <<"__TEMPLATE";
/* SysGen Template Type : GSM + LOW COST (COMMON) */
#if ( GEMINI_PLUS > 3 )

    #if defined(PLUTO_MMI)
       #if defined(DEBUG_BUF2)
          #define GLOBAL_MEM_SIZE          ( 458*512$sys_mem_tuning_str)
          #define GLOBAL_DEBUG_MEM_SIZE    (  68*512$dbg_mem_tuning_str)
       #elif defined(DEBUG_BUF1)
          #define GLOBAL_MEM_SIZE          ( 917*256$sys_mem_tuning_str)
          #define GLOBAL_DEBUG_MEM_SIZE    (  40*256$dbg_mem_tuning_str)
       #else
          #define GLOBAL_MEM_SIZE          ( 909*256$sys_mem_tuning_str)
          #define GLOBAL_DEBUG_MEM_SIZE    (  40*256$dbg_mem_tuning_str)
       #endif
    #else
       #if defined(DEBUG_BUF2)
          #define GLOBAL_MEM_SIZE          ( 308*512$sys_mem_tuning_str)
          #define GLOBAL_DEBUG_MEM_SIZE    (  68*512$dbg_mem_tuning_str)
       #elif defined(DEBUG_BUF1)
          #define GLOBAL_MEM_SIZE          ( 617*256$sys_mem_tuning_str)
          #define GLOBAL_DEBUG_MEM_SIZE    (  40*256$dbg_mem_tuning_str)
       #else
          #define GLOBAL_MEM_SIZE          ( 609*256$sys_mem_tuning_str)
          #define GLOBAL_DEBUG_MEM_SIZE    (  40*256$dbg_mem_tuning_str)
       #endif
    #endif

#elif ( GEMINI_PLUS > 2 )

    #if defined(PLUTO_MMI)
       #if defined(DEBUG_BUF2)
          #define GLOBAL_MEM_SIZE          ( 446*512$sys_mem_tuning_str)
          #define GLOBAL_DEBUG_MEM_SIZE    (  68*512$dbg_mem_tuning_str)
       #elif defined(DEBUG_BUF1)
          #define GLOBAL_MEM_SIZE          ( 893*256$sys_mem_tuning_str)
          #define GLOBAL_DEBUG_MEM_SIZE    (  40*256$dbg_mem_tuning_str)
       #else
          #define GLOBAL_MEM_SIZE          ( 885*256$sys_mem_tuning_str)
          #define GLOBAL_DEBUG_MEM_SIZE    (  40*256$dbg_mem_tuning_str)
       #endif
    #else
       #if defined(DEBUG_BUF2)
          #define GLOBAL_MEM_SIZE          ( 308*512$sys_mem_tuning_str)
          #define GLOBAL_DEBUG_MEM_SIZE    (  68*512$dbg_mem_tuning_str)
       #elif defined(DEBUG_BUF1)
          #define GLOBAL_MEM_SIZE          ( 617*256$sys_mem_tuning_str)
          #define GLOBAL_DEBUG_MEM_SIZE    (  40*256$dbg_mem_tuning_str)
       #else
          #define GLOBAL_MEM_SIZE          ( 609*256$sys_mem_tuning_str)
          #define GLOBAL_DEBUG_MEM_SIZE    (  40*256$dbg_mem_tuning_str)
       #endif
    #endif

#elif defined(__GEMINI__)
    
    #if defined(PLUTO_MMI)
       #if defined(DEBUG_BUF2)
          #define GLOBAL_MEM_SIZE          ( 358*512$sys_mem_tuning_str)
          #define GLOBAL_DEBUG_MEM_SIZE    (  66*512$dbg_mem_tuning_str)
       #elif defined(DEBUG_BUF1)
          #define GLOBAL_MEM_SIZE          ( 717*256$sys_mem_tuning_str)
          #define GLOBAL_DEBUG_MEM_SIZE    (  20*256$dbg_mem_tuning_str)
       #else
          #define GLOBAL_MEM_SIZE          ( 709*256$sys_mem_tuning_str)
          #define GLOBAL_DEBUG_MEM_SIZE    (  20*256$dbg_mem_tuning_str)
       #endif
    #else
       #if defined(DEBUG_BUF2)
          #define GLOBAL_MEM_SIZE          ( 308*512$sys_mem_tuning_str)
          #define GLOBAL_DEBUG_MEM_SIZE    (  66*512$dbg_mem_tuning_str)
       #elif defined(DEBUG_BUF1)
          #define GLOBAL_MEM_SIZE          ( 617*256$sys_mem_tuning_str)
          #define GLOBAL_DEBUG_MEM_SIZE    (  20*256$dbg_mem_tuning_str)
       #else
          #define GLOBAL_MEM_SIZE          ( 609*256$sys_mem_tuning_str)
          #define GLOBAL_DEBUG_MEM_SIZE    (  20*256$dbg_mem_tuning_str)
       #endif
    #endif

#else

    #if defined(PLUTO_MMI)
       #if defined(DEBUG_BUF2)
          #define GLOBAL_MEM_SIZE          ( 358*512$sys_mem_tuning_str)
          #define GLOBAL_DEBUG_MEM_SIZE    (  66*512$dbg_mem_tuning_str)
       #elif defined(DEBUG_BUF1)
          #define GLOBAL_MEM_SIZE          ( 717*256$sys_mem_tuning_str)
          #define GLOBAL_DEBUG_MEM_SIZE    (  20*256$dbg_mem_tuning_str)
       #else
          #define GLOBAL_MEM_SIZE          ( 709*256$sys_mem_tuning_str)
          #define GLOBAL_DEBUG_MEM_SIZE    (  20*256$dbg_mem_tuning_str)
       #endif
    #else
       #if defined(DEBUG_BUF2)
          #define GLOBAL_MEM_SIZE          ( 308*512$sys_mem_tuning_str)
          #define GLOBAL_DEBUG_MEM_SIZE    (  66*512$dbg_mem_tuning_str)
       #elif defined(DEBUG_BUF1)
          #define GLOBAL_MEM_SIZE          ( 617*256$sys_mem_tuning_str)
          #define GLOBAL_DEBUG_MEM_SIZE    (  20*256$dbg_mem_tuning_str)
       #else
          #define GLOBAL_MEM_SIZE          ( 609*256$sys_mem_tuning_str)
          #define GLOBAL_DEBUG_MEM_SIZE    (  20*256$dbg_mem_tuning_str)
       #endif
    #endif

#endif
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  generate global memory definiation for GSM + LOW COST (ULC) type.
# return:      the body strings
# EXAMPLE PROJECT : 
#****************************************************************************
sub globalmem_gsm_lowcost_ulc
{
    my ($sys_mem_tuning_str, $dbg_mem_tuning_str) = @_;
    my $template = <<"__TEMPLATE";
/* SysGen Template Type : GSM + LOW COST (ULC) */
#if defined(__GEMINI__)

    #define GLOBAL_MEM_SIZE         ( 122*1024)
    #define GLOBAL_DEBUG_MEM_SIZE   (   5*1024)

#else

    #define GLOBAL_MEM_SIZE         (  97*1024)
    #define GLOBAL_DEBUG_MEM_SIZE   (   2*1024)

#endif
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  generate control buffer setting , type : adjust on gprs class
# return:      the body strings
#****************************************************************************
sub ctrlbuffpool_adjust_on_edge_class
{
    my $template = <<"__TEMPLATE";
   /* EDGE class : ctrl buffer slots adjustment */

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  generate control buffer setting , type : adjust on gprs class
# return:      the body strings
#****************************************************************************
sub ctrlbuffpool_adjust_on_gprs_class
{
    my $template = <<"__TEMPLATE";
   /* GPRS class : ctrl buffer slots adjustment */

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  generate control buffer setting , type : as default
# return:      the body strings
#****************************************************************************
sub ctrlbuffpool_as_default
{
    my $template = <<"__TEMPLATE";
   /* These constants defined in adaptation\\include\\ctrl_buff_pool.h */
   ctrl_buff_pool_info_g[0].size        = CTRL_BUFF_POOL_SIZE08;
   ctrl_buff_pool_info_g[0].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE08;

   ctrl_buff_pool_info_g[1].size        = CTRL_BUFF_POOL_SIZE16;
   ctrl_buff_pool_info_g[1].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE16;

   ctrl_buff_pool_info_g[2].size        = CTRL_BUFF_POOL_SIZE32;
   ctrl_buff_pool_info_g[2].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE32;

   ctrl_buff_pool_info_g[3].size        = CTRL_BUFF_POOL_SIZE64;
   ctrl_buff_pool_info_g[3].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE64;

   ctrl_buff_pool_info_g[4].size        = CTRL_BUFF_POOL_SIZE128;
   ctrl_buff_pool_info_g[4].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE128;

   ctrl_buff_pool_info_g[5].size        = CTRL_BUFF_POOL_SIZE256;
   ctrl_buff_pool_info_g[5].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE256;

   ctrl_buff_pool_info_g[6].size        = CTRL_BUFF_POOL_SIZE512;
   ctrl_buff_pool_info_g[6].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE512;

   ctrl_buff_pool_info_g[7].size        = CTRL_BUFF_POOL_SIZE1024;
   ctrl_buff_pool_info_g[7].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE1024;

   ctrl_buff_pool_info_g[8].size        = CTRL_BUFF_POOL_SIZE2048;
   ctrl_buff_pool_info_g[8].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE2048;

   ctrl_buff_pool_info_g[9].size        = CTRL_BUFF_POOL_SIZE4096;
   ctrl_buff_pool_info_g[9].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE4096;

   ctrl_buff_pool_info_g[10].size       = CTRL_BUFF_POOL_SIZE8192;
   ctrl_buff_pool_info_g[10].no_of_buff = NUM_CTRL_BUFF_POOL_SIZE8192;

   ctrl_buff_pool_info_g[11].size       = CTRL_BUFF_POOL_SIZE16384;
   ctrl_buff_pool_info_g[11].no_of_buff = NUM_CTRL_BUFF_POOL_SIZE16384;

   ctrl_buff_pool_info_g[12].size       = CTRL_BUFF_POOL_SIZE32768;
   ctrl_buff_pool_info_g[12].no_of_buff = NUM_CTRL_BUFF_POOL_SIZE32768;

   ctrl_buff_pool_info_g[13].size       = CTRL_BUFF_POOL_SIZE65536;
   ctrl_buff_pool_info_g[13].no_of_buff = NUM_CTRL_BUFF_POOL_SIZE65536;

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  generate control buffer setting , type : WCDMA
# return:      the body strings
#****************************************************************************
sub ctrlbuffpool_wcdma
{
    my $template = <<"__TEMPLATE";
   /* These constants defined in adaptation\\include\\ctrl_buff_pool.h */
   ctrl_buff_pool_info_g[0].size        = CTRL_BUFF_POOL_SIZE08;
   ctrl_buff_pool_info_g[0].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE08;

   ctrl_buff_pool_info_g[1].size        = CTRL_BUFF_POOL_SIZE16;
   ctrl_buff_pool_info_g[1].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE16;

   ctrl_buff_pool_info_g[2].size        = CTRL_BUFF_POOL_SIZE32;
   ctrl_buff_pool_info_g[2].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE32;

   ctrl_buff_pool_info_g[3].size        = CTRL_BUFF_POOL_SIZE64;
   ctrl_buff_pool_info_g[3].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE64;

   ctrl_buff_pool_info_g[4].size        = CTRL_BUFF_POOL_SIZE128;
   ctrl_buff_pool_info_g[4].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE128;

   ctrl_buff_pool_info_g[5].size        = CTRL_BUFF_POOL_SIZE256;
   ctrl_buff_pool_info_g[5].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE256;

   ctrl_buff_pool_info_g[6].size        = CTRL_BUFF_POOL_SIZE512;
   ctrl_buff_pool_info_g[6].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE512;

   ctrl_buff_pool_info_g[7].size        = CTRL_BUFF_POOL_SIZE1024;
   ctrl_buff_pool_info_g[7].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE1024;

   ctrl_buff_pool_info_g[8].size        = CTRL_BUFF_POOL_SIZE2048;
   ctrl_buff_pool_info_g[8].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE2048;

   ctrl_buff_pool_info_g[9].size        = CTRL_BUFF_POOL_SIZE4096;
   ctrl_buff_pool_info_g[9].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE4096;

   ctrl_buff_pool_info_g[10].size       = CTRL_BUFF_POOL_SIZE8192;
   ctrl_buff_pool_info_g[10].no_of_buff = NUM_CTRL_BUFF_POOL_SIZE8192;

   ctrl_buff_pool_info_g[11].size       = CTRL_BUFF_POOL_SIZE16384;
   ctrl_buff_pool_info_g[11].no_of_buff = NUM_CTRL_BUFF_POOL_SIZE16384;

   ctrl_buff_pool_info_g[12].size       = CTRL_BUFF_POOL_SIZE32768;
   ctrl_buff_pool_info_g[12].no_of_buff = NUM_CTRL_BUFF_POOL_SIZE32768;

   ctrl_buff_pool_info_g[13].size       = CTRL_BUFF_POOL_SIZE65536;
   ctrl_buff_pool_info_g[13].no_of_buff = NUM_CTRL_BUFF_POOL_SIZE65536;

#ifdef  __UMTS_RAT__
   ctrl_buff_pool_info_g[14].size       = CTRL_BUFF_POOL_SIZE100000;
#if defined(KAL_ON_OSCAR)
   ctrl_buff_pool_info_g[14].no_of_buff = NUM_CTRL_BUFF_POOL_SIZE100000 + 4;
#else
   ctrl_buff_pool_info_g[14].no_of_buff = NUM_CTRL_BUFF_POOL_SIZE100000;
#endif

   ctrl_buff_pool_info_g[15].size       = CTRL_BUFF_POOL_SIZE400000;
   ctrl_buff_pool_info_g[15].no_of_buff = NUM_CTRL_BUFF_POOL_SIZE400000;

   ctrl_buff_pool_info_g[16].size       = CTRL_BUFF_POOL_SIZE550000;
   ctrl_buff_pool_info_g[16].no_of_buff = NUM_CTRL_BUFF_POOL_SIZE550000;
#endif
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  generate control buffer setting , Type : GSM + LOWCOST
# return:      the body strings
#****************************************************************************
sub ctrlbuffpool_gsm_lowcost
{
    my $template = <<"__TEMPLATE";
   /* sysGen Template : GSM + LOWCOST */
   /* These constants defined in adaptation\\include\\ctrl_buff_pool.h */
   ctrl_buff_pool_info_g[0].size        = CTRL_BUFF_POOL_SIZE08;
   ctrl_buff_pool_info_g[0].no_of_buff  = 50;

   ctrl_buff_pool_info_g[1].size        = CTRL_BUFF_POOL_SIZE16;
   ctrl_buff_pool_info_g[1].no_of_buff  = 50;

   ctrl_buff_pool_info_g[2].size        = CTRL_BUFF_POOL_SIZE32;
   ctrl_buff_pool_info_g[2].no_of_buff  = 50;

   ctrl_buff_pool_info_g[3].size        = CTRL_BUFF_POOL_SIZE64;
   ctrl_buff_pool_info_g[3].no_of_buff  = 30;

   ctrl_buff_pool_info_g[4].size        = CTRL_BUFF_POOL_SIZE128;
   ctrl_buff_pool_info_g[4].no_of_buff  = 40;

   ctrl_buff_pool_info_g[5].size        = CTRL_BUFF_POOL_SIZE256;
   ctrl_buff_pool_info_g[5].no_of_buff  = 30;

   ctrl_buff_pool_info_g[6].size        = CTRL_BUFF_POOL_SIZE512;
   ctrl_buff_pool_info_g[6].no_of_buff  = 18+2;

   ctrl_buff_pool_info_g[7].size        = CTRL_BUFF_POOL_SIZE1024;
   ctrl_buff_pool_info_g[7].no_of_buff  = 11-2;

   ctrl_buff_pool_info_g[8].size        = CTRL_BUFF_POOL_SIZE2048;
   ctrl_buff_pool_info_g[8].no_of_buff  = 5;

   ctrl_buff_pool_info_g[9].size        = CTRL_BUFF_POOL_SIZE4096;
   ctrl_buff_pool_info_g[9].no_of_buff  = 0;

   ctrl_buff_pool_info_g[10].size       = CTRL_BUFF_POOL_SIZE8192;
   ctrl_buff_pool_info_g[10].no_of_buff = 0;

   ctrl_buff_pool_info_g[11].size       = CTRL_BUFF_POOL_SIZE16384;
   ctrl_buff_pool_info_g[11].no_of_buff = 0;

   ctrl_buff_pool_info_g[12].size       = CTRL_BUFF_POOL_SIZE32768;
   ctrl_buff_pool_info_g[12].no_of_buff = 0;

   ctrl_buff_pool_info_g[13].size       = CTRL_BUFF_POOL_SIZE65536;
   ctrl_buff_pool_info_g[13].no_of_buff = 0;

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  generate control buffer setting , Type : GSM + LOWCOST + SINGLEBANK
# return:      the body strings
#****************************************************************************
sub ctrlbuffpool_gsm_lowcost_singlebank
{
    my $template = <<"__TEMPLATE";
   /* sysGen Template : GSM + LOWCOST + SINGLEBANK */
   /* These constants defined in adaptation\\include\\ctrl_buff_pool.h */
   ctrl_buff_pool_info_g[0].size        = CTRL_BUFF_POOL_SIZE08;
   ctrl_buff_pool_info_g[0].no_of_buff  = 50;

   ctrl_buff_pool_info_g[1].size        = CTRL_BUFF_POOL_SIZE16;
   ctrl_buff_pool_info_g[1].no_of_buff  = 50;

   ctrl_buff_pool_info_g[2].size        = CTRL_BUFF_POOL_SIZE32;
   ctrl_buff_pool_info_g[2].no_of_buff  = 50;

   ctrl_buff_pool_info_g[3].size        = CTRL_BUFF_POOL_SIZE64;
   ctrl_buff_pool_info_g[3].no_of_buff  = 30;

   ctrl_buff_pool_info_g[4].size        = CTRL_BUFF_POOL_SIZE128;
   ctrl_buff_pool_info_g[4].no_of_buff  = 40;

   ctrl_buff_pool_info_g[5].size        = CTRL_BUFF_POOL_SIZE256;
   ctrl_buff_pool_info_g[5].no_of_buff  = 30;

   ctrl_buff_pool_info_g[6].size        = CTRL_BUFF_POOL_SIZE512;
   ctrl_buff_pool_info_g[6].no_of_buff  = 18;

   ctrl_buff_pool_info_g[7].size        = CTRL_BUFF_POOL_SIZE1024;
   ctrl_buff_pool_info_g[7].no_of_buff  = 8;

   ctrl_buff_pool_info_g[8].size        = CTRL_BUFF_POOL_SIZE2048;
   ctrl_buff_pool_info_g[8].no_of_buff  = 4;

   ctrl_buff_pool_info_g[9].size        = CTRL_BUFF_POOL_SIZE4096;
   ctrl_buff_pool_info_g[9].no_of_buff  = 0;

   ctrl_buff_pool_info_g[10].size       = CTRL_BUFF_POOL_SIZE8192;
   ctrl_buff_pool_info_g[10].no_of_buff = 0;

   ctrl_buff_pool_info_g[11].size       = CTRL_BUFF_POOL_SIZE16384;
   ctrl_buff_pool_info_g[11].no_of_buff = 0;

   ctrl_buff_pool_info_g[12].size       = CTRL_BUFF_POOL_SIZE32768;
   ctrl_buff_pool_info_g[12].no_of_buff = 0;

   ctrl_buff_pool_info_g[13].size       = CTRL_BUFF_POOL_SIZE65536;
   ctrl_buff_pool_info_g[13].no_of_buff = 0;

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  generate custom_util.c content body
# return:      the body strings
#****************************************************************************
sub custom_util_c_file_body
{
    my $template = <<"__TEMPLATE";
/*************************************************************************
 * Include Header Files
 *************************************************************************/
#include "uart_sw.h"
#include "kal_non_specific_general_types.h"

/*************************************************************************
 * Function Declaration
 *************************************************************************/
#ifdef DRV_DEBUG
extern void dbg_print(char *fmt,...);
#endif /* DRV_DEBUG */

/*************************************************************************
 * Global variable declaration
 *************************************************************************/
#if defined(__KAL_RECORD_BOOTUP_LOG__) || defined(__KEYPAD_DEBUG_TRACE__)
  kal_bool is_init_log_enable; // setup in INT_setInitLogFlag
  kal_bool is_init_stage;
  const UART_PORT init_log_port = uart_port1;
  const UART_baudrate init_log_baudrate = 460800;
#else //#ifdef __KAL_RECORD_BOOTUP_LOG__   
  const kal_bool is_init_log_enable = KAL_FALSE;
  kal_bool is_init_stage = KAL_TRUE;
  const UART_PORT init_log_port = uart_port1;
  const UART_baudrate init_log_baudrate = 115200;
#endif  //__KAL_RECORD_BOOTUP_LOG__

/*************************************************************************
* FUNCTION
*  custom_print
*
* DESCRIPTION
*       This function implements output display through uart port for custom
*       debugging without MTK tool utility.
*
*       Notice:
*       The routine is possibly to hit race condition because of reentrant caller.
*
* PARAMETERS
*       string  -       output string
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void
custom_print(kal_char* string)
{
#ifdef DRV_DEBUG
        dbg_print("\%s\\r\\n", string);
#elif defined(__TST_MODULE__) && defined(__CUSTOM_RELEASE__)
        //kal_print(string);
        kal_prompt_trace(MOD_MMI,"\%s",string);
#endif /* DVR_DEBUG */
}

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  generate custom_util.h content body
# return:      the body strings
#****************************************************************************
sub custom_util_h_file_body
{
    my $template = <<"__TEMPLATE";
#ifndef _CUSTOM_UTIL_H
#define _CUSTOM_UTIL_H
#include "kal_non_specific_general_types.h"

/*************************************************************************
 * Function Declaration
 *************************************************************************/
extern void custom_print(kal_char* string);

#endif /* _CUSTOM_UTIL_H */

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  generate custom_sap.h content body
# return:      the body strings
#****************************************************************************
sub custom_sap_h_file_body
{
    my $template = <<"__TEMPLATE";
/* Add customization message id here */
MSG_ID_CUSTOM1_CUSTOM2  =  CUSTOM_MSG_CODE_BEGIN,
MSG_ID_CUSTOM2_CUSTOM1,
#if defined (__FLAVOR_VENDOR_SDK__) || defined(__MAUI_SDK_TEST__)
MSG_ID_MMI_VS_INTQ_REQ,
MSG_ID_MMI_VS_SEMAPHONE,
MSG_ID_MMI_VS_MUTEX,
#endif
#if defined(__WS_HOME_SAFE__)
MSG_ID_MSGCMD_COMMAND_1,
MSG_ID_MSGCMD_COMMAND_2,
MSG_ID_MSGCMD_COMMAND_3,
MSG_ID_MSGCMD_COMMAND_4,
MSG_ID_MSGCMD_COMMAND_5,
MSG_ID_MSGCMD_COMMAND_6,
MSG_ID_MSGCMD_COMMAND_7,
MSG_ID_MSGCMD_COMMAND_8,
MSG_ID_MSGCMD_COMMAND_9,
MSG_ID_MSGCMD_COMMAND_10,
MSG_ID_MSGCMD_COMMAND_11,
MSG_ID_MSGCMD_COMMAND_12,
MSG_ID_MSGCMD_COMMAND_13,
MSG_ID_MSGCMD_COMMAND_14,
MSG_ID_MSGCMD_COMMAND_15,
MSG_ID_MSGCMD_COMMAND_16,
MSG_ID_MSGCMD_COMMAND_17,
MSG_ID_MSGCMD_COMMAND_18,
MSG_ID_MSGCMD_COMMAND_19,
MSG_ID_MSGCMD_COMMAND_20,
#endif
#if defined(MSG_CMD_TASK_SUPPORT)
MSG_ID_MSGCMD_COMMAND,
#endif

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  generate custom1_create.c content body
# return:      the body strings
#****************************************************************************
sub custom1_create_c_file_body
{
    my $template = <<"__TEMPLATE";
/*************************************************************************
* Include Statements
 *************************************************************************/
#include "task_main_func.h"
#include "app_ltlcom.h"
#include "task_config.h"
#include "syscomp_config.h"
#include "custom_util.h"
#include "stack_ltlcom.h"
#include "kal_non_specific_general_types.h"
#include "stack_config.h"

/*************************************************************************
* Function declaration
 *************************************************************************/
static void custom1_main(task_entry_struct * task_entry_ptr);
static void custom2_main(task_entry_struct * task_entry_ptr);

/*************************************************************************
* FUNCTION
*  custom1_create
*
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool
custom1_create(comptask_handler_struct **handle)
{
   static const comptask_handler_struct custom1_handler_info =
   {
      custom1_main,  /* task entry function */
      NULL,  /* task initialization function */
      NULL,  /* task configuration function */
      NULL,  /* task reset handler */
      NULL,  /* task termination handler */
   };

   *handle = (comptask_handler_struct *)&custom1_handler_info;
   return KAL_TRUE;
}

static void
custom1_main(task_entry_struct * task_entry_ptr)
{
   ilm_struct current_ilm;
#ifdef DRV_DEBUG
   ilm_struct *send_ilm;

   custom_print("Custom1 Send Test\\n");
   send_ilm = allocate_ilm(MOD_CUSTOM1);
   send_ilm->src_mod_id = MOD_CUSTOM1;
   send_ilm->dest_mod_id = MOD_CUSTOM2;
   send_ilm->msg_id = MSG_ID_CUSTOM1_CUSTOM2;
   msg_send_ext_queue(send_ilm);
#endif /* DRV_DEBUG */

   while ( 1 ) {
      receive_msg_ext_q(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);

      switch (current_ilm.msg_id) {
          case MSG_ID_CUSTOM2_CUSTOM1:
                 custom_print("Custom1 receive message from custom2.\\n");
                 break;
      default:
         break;
      }

      free_ilm(&current_ilm);
   }
}

/*************************************************************************
* FUNCTION
*  custom2_create
*
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool
custom2_create(comptask_handler_struct **handle)
{
   static const comptask_handler_struct custom2_handler_info =
   {
      custom2_main,  /* task entry function */
      NULL,  /* task initialization function */
      NULL,  /* task configuration function */
      NULL,  /* task reset handler */
      NULL,  /* task termination handler */
   };

   *handle = (comptask_handler_struct *)&custom2_handler_info;
   return KAL_TRUE;
}

static void
custom2_main(task_entry_struct * task_entry_ptr)
{
   ilm_struct current_ilm;
#ifdef DRV_DEBUG
   ilm_struct *send_ilm;

   custom_print("Custom1 Send Test\\n");
   send_ilm = allocate_ilm(MOD_CUSTOM2);
   send_ilm->src_mod_id = MOD_CUSTOM2;
   send_ilm->dest_mod_id = MOD_CUSTOM1;
   send_ilm->msg_id = MSG_ID_CUSTOM2_CUSTOM1;
   msg_send_ext_queue(send_ilm);
#endif /* DRV_DEBUG */

   while ( 1 ) {
      receive_msg_ext_q(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);

      switch (current_ilm.msg_id) {
          case MSG_ID_CUSTOM1_CUSTOM2:
                 custom_print("Custom1 receive message from custom2.\\n");
                 break;
      default:
         break;
      }

      free_ilm(&current_ilm);
   }
}

__TEMPLATE

   return $template;
}

#****************************************************************************
# subroutine:  generate custom_config.h content body
# return:      the body strings
#****************************************************************************
sub custom_config_h_file_body
{
    my $template = <<"__TEMPLATE";
#ifndef _CUSTOM_CONFIG_H
#define _CUSTOM_CONFIG_H

#include "stack_config.h"


/*************************************************************************
* Steps to add component task
*
* DESCRIPTION
*   The file describes steps to add component task.
*
*  1. add component task's index (Please add before system service)
*
*  2. add component task's module id definition (Please add before system service)
*
*  3. add module to task transformation in syscomp_config.c
*
*  4. add and implement component task's create handler
*
* GLOBALS AFFECTED
*
*************************************************************************/

/*************************************************************************
 * [Very Important Message]
 * 1. Component Task Index (Please add before system service)
 * 2. Customers are allowed to create at most 16 tasks as defined in 
 *    config\\include\\stack_config.h (MAX_CUSTOM_TASKS = 16)
 *************************************************************************/
typedef enum {
   INDX_CUSTOM1 = RPS_CUSTOM_TASKS_BEGIN,
   INDX_CUSTOM2,
#if defined (__FLAVOR_VENDOR_SDK__) || defined(__MAUI_SDK_TEST__)
   INDX_VS,
#endif
#if defined(MSG_CMD_TASK_SUPPORT)
   INDX_MSGCMD,
#endif
   RPS_CUSTOM_TASKS_END
} custom_task_indx_type;

/*************************************************************************
 * [Very Important Message]
 * 1. Component task's module id (Please add before system service)
 * 2. Customers are allowed to create at most 16 task module ID as defined 
 *    in config\\include\\stack_config.h (MAX_CUSTOM_MODS = 16)
 *************************************************************************/
typedef enum {
   MOD_CUSTOM1 = MOD_CUSTOM_BEGIN,
   MOD_CUSTOM2,
#if defined (__FLAVOR_VENDOR_SDK__) || defined(__MAUI_SDK_TEST__)
   MOD_VS,
#endif
#if defined(MSG_CMD_TASK_SUPPORT)
   MOD_MSGCMD,
#endif
   MOD_CUSTOM_END
} custom_module_type;

/*************************************************************************
 * Other Declarations
 *************************************************************************/
extern custom_task_indx_type custom_mod_task_g[ MAX_CUSTOM_MODS ];

#endif /* _CUSTOM_CONFIG_H */

__TEMPLATE

   return $template;
}

#****************************************************************************
# subroutine:  generate custom_config.c content body
# return:      the body strings
#****************************************************************************
sub custom_config_c_file_body
{
    my ($global_mem_config_string, $ctrl_buff_pool_config_string) = &dispatch_globalmem_and_ctrlbuffpool;
    my $template = <<"__TEMPLATE";
/*************************************************************************
 * Include Statements
 *************************************************************************/
#include "kal_release.h"
#include "syscomp_config.h"
#include "stack_common.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "task_config.h"
#include "custom_config.h"
#include "stack_buff_pool.h"
#include "ctrl_buff_pool.h"
#include "system_inc.h"    /* include system_inc.h after including above header files */
#include "page.h"
#include "kal_non_specific_general_types.h"
#include "kal_common_defs.h"

//#define CUSTOM1_EXIST
//#define CUSTOM2_EXIST

/*************************************************************************
 * External function declaration
 *************************************************************************/
extern kal_bool custom1_create(comptask_handler_struct **handle);
extern kal_bool custom2_create(comptask_handler_struct **handle);

#if defined (__FLAVOR_VENDOR_SDK__) || defined(__MAUI_SDK_TEST__)
extern kal_bool vs_sys_task_001_create(comptask_handler_struct **handle);
#endif
#if defined(MSG_CMD_TASK_SUPPORT)
extern kal_bool MsgCmd_TaskCreate(comptask_handler_struct **handle);
#endif
/*************************************************************************
* Global
*  custom_mod_task_g
*
* DESCRIPTION
*   module to task index mapping.
*   for example:
*      INDX_CUSTOM1 -> MOD_CUSTOM1
*   means module MOD_CUSTOM1 belongs to INDX_CUSTOM1 task
*
*   Please arrange the mapping according to custom_config.h custom_module_type
*   sequence.
*
* GLOBALS AFFECTED
*
*************************************************************************/
custom_task_indx_type custom_mod_task_g[ MAX_CUSTOM_MODS ] =
{
   INDX_CUSTOM1,        /* MOD_CUSTOM1 */
   INDX_CUSTOM2,        /* MOD_CUSTOM2 */
#if defined (__FLAVOR_VENDOR_SDK__) || defined(__MAUI_SDK_TEST__)
   INDX_VS,
#endif
#if defined(MSG_CMD_TASK_SUPPORT)
   INDX_MSGCMD,
#endif
   INDX_NIL             /* Please end with INDX_NIL element */
};

/*************************************************************************
* Global
*  custom_comp_config_tbl
*
* DESCRIPTION
*   The array contains system component tasks' configuration information
*
* GLOBALS AFFECTED
*
*************************************************************************/
const comptask_info_struct custom_comp_config_tbl[ MAX_CUSTOM_TASKS ] =
{
   /* INDX_CUSTOM1 */
   {"CUST1", "CUST1 Q", 210, 1024, 
#ifdef CUSTOM1_EXIST
   custom1_create, KAL_FALSE
#else   
   NULL, KAL_FALSE
#endif
    , 10, 0
   },

   /* INDX_CUSTOM2 */
   {"CUST2", "CUST2 Q", 211, 1024, 
#ifdef CUSTOM2_EXIST
   custom2_create, KAL_FALSE
#else
   NULL, KAL_FALSE
#endif
    , 10, 0
   },

#if defined (__FLAVOR_VENDOR_SDK__) || defined(__MAUI_SDK_TEST__)
   /* INDX_VS */
   {"VS", "VS Q", 212, 1024, 
   vs_sys_task_001_create, KAL_FALSE, 10, 0
   },
#endif
#if defined(MSG_CMD_TASK_SUPPORT)
   /*INDX_MSGCMD*/
   {"MSGCMD", "MSGCMD Q", 213, 1024, 
   MsgCmd_TaskCreate, KAL_FALSE, 10, 0
   },
#endif
};

/*************************************************************************
* FUNCTION
*  custom_configmem()
*
* DESCRIPTION
*   This routine configure 
*        
*   a. system total memory usage 
*      Task's stack, external queue, control buffer entries etc.
*      Any one who attempts to create new task or enlarge control
*      buffer size should fine tune the value!
*
*   b. system total debug memory usage 
*      Valid for DEBUG_KAL + DEBUG_[some items, ITC, BUF etc] 
*
* PARAMETERS
*        system_mem_sz       -        system all memory usage
*        debug_mem_sz        -        system all debug memory usage
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

$global_mem_config_string

static kal_uint32 System_Mem_Pool[GLOBAL_MEM_SIZE/sizeof(kal_uint32)];

#if defined(DEBUG_KAL)
static kal_uint32 Debug_Mem_Pool[GLOBAL_DEBUG_MEM_SIZE/sizeof(kal_uint32)];
#endif /* DEBUG_KAL */

void
custom_configmem(kal_uint32 *system_mem_sz, kal_uint32** system_mem_addr, 
                 kal_uint32 *debug_mem_sz,  kal_uint32** debug_mem_addr)
{
   *system_mem_sz   = GLOBAL_MEM_SIZE;
   *system_mem_addr = System_Mem_Pool;
   
#if defined(DEBUG_KAL)   
   *debug_mem_addr  = Debug_Mem_Pool;
   *debug_mem_sz    = GLOBAL_DEBUG_MEM_SIZE;
#else
   *debug_mem_addr  = (kal_uint32 *)0;
   *debug_mem_sz    = 0;
#endif
}

/*************************************************************************
* FUNCTION
*  custom_config_libc_heap()
*
* DESCRIPTION
*   This routine configure libc heap size & location.
*
* PARAMETERS
*
* RETURNS
*  heap size & heap location. if heap_size return 0, then no heap is
*  initialized.
*
* GLOBALS AFFECTED
*
*************************************************************************/
#ifdef __GADGET_SUPPORT__
#define GLOBAL_LIBC_HEAP_SIZE 10240
#else 
#define GLOBAL_LIBC_HEAP_SIZE 0
#endif
#if GLOBAL_LIBC_HEAP_SIZE != 0
/* if we don't define heap, we won't define a symbol call System_Libc_Heap
 * using this method, we can detect whether system allow to use 
 * malloc/free/realloc/calloc
 */
kal_uint32 System_Libc_Heap[GLOBAL_LIBC_HEAP_SIZE/sizeof(kal_uint32)];
#endif
void custom_config_libc_heap(kal_uint32 *heap_size, void **heap_addr)
{
#if GLOBAL_LIBC_HEAP_SIZE == 0
    *heap_size = 0;
    *heap_addr = 0;
#else
    *heap_size = sizeof(System_Libc_Heap);
    *heap_addr = System_Libc_Heap;
#endif
}

/*************************************************************************
* FUNCTION
*  custom_config_ctrl_buff_info()
*
* DESCRIPTION
*   This routine configure control buffer pool information (run time 
*   memory allocation usage)
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void
custom_config_ctrl_buff_info(void)
{
$ctrl_buff_pool_config_string        
} 

/*************************************************************************
* FUNCTION
*  custom_config_task_stack_size
*
* DESCRIPTION
*  This function dedicates to specify one task's stack size.
*  Note: Each task's stack size is originally defined in the task 
*        configuration table (in sys_comp_config_tbl[]). When allocating 
*        stack for each task, system will invoke this function. If the 
*        return value is zero, system will use the original stack-size
*        setting for the task. Otherwise, system will use the return value 
*        as the task's stack size IF AND ONLY IF the return value is larger 
*        than the original settting.
*
* PARAMETERS
*  task_indx   -   task index of task to configure
*
* RETURNS
*  Task's stack size (in bytes). Zero value implies that system uses
*  the original setting to allocate stack for the task.
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 custom_config_task_stack_size(task_indx_type task_indx)
{
   switch (task_indx) {

   /*
    * Return a non-zero value for the task you are interesting.
    * For example,
    *    case INDX_MMI:
    *       // configure MMI's stack size as 8KB
    *       return 8096;
    */

#if defined(OBIGO_Q05A)
   case INDX_MMI:
   // en-large the MMI stack size to 26KB
      return (26 * 1024);
#endif /* OBIGO_Q05A */

   default:
      return 0;
   }

   return 0;
}

/*************************************************************************
* FUNCTION
*  custom_config_task_extq_size
*
* DESCRIPTION
*  This function dedicates to specify one task's external queue size.
*  Note: Each task's external queue size is originally defined in the task 
*        configuration table (in sys_comp_config_tbl[]). When allocating 
*        queue for each task, system will invoke this function. If the 
*        return value is zero, system will use the original queue-size 
*        setting for the task. Otherwise, system will use the return value 
*        as the task's external queue size IF AND ONLY IF the return value 
*        is larger than the original settting.
*
* PARAMETERS
*  task_indx   -   task index of task to configure
*
* RETURNS
*  Task's external queue size (number of entries). Zero value implies that
*  system uses the original setting to allocate queue for the task.
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 custom_config_task_extq_size(task_indx_type task_indx)
{
   switch (task_indx) {

   /*
    * Return a non-zero value for the task you are interesting.
    * For example,
    *    case INDX_MMI:
    *       // configure MMI's external queue size as 40
    *       return 30;
    */

   default:
      return 0;
   }

   return 0;
}

/*************************************************************************
* FUNCTION
*  custom_config_evshed_pool_size
*
* DESCRIPTION
*  This function dedicates to specify larger pool size on event scheduler.
*
* PARAMETERS
*  void   -   
*
* RETURNS
*  evshed pool size (number of entries). Smaller value than default 
*  implies that system uses the original setting to allocate pool for event.
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 custom_config_evshed_pool_size(void)
{
#ifdef __SIP__
   return 160;
#else
   return 0;
#endif
}

/*************************************************************************
* FUNCTION
*  custom_config_task_under_usb_boot
*
* DESCRIPTION
*  This function dedicates custom tasks present or not under usb boot mode
*
* PARAMETERS
*  task_indx   -   task index of task to configure
*
* RETURNS
*  KAL_TRUE  : present on usb boot mode
*  KAL_FALSE : otherwise
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_config_task_under_usb_boot(task_indx_type task_indx)
{
   switch (task_indx) {

   /*
    * Return true value for the custom task you are interesting.
    * For example,
    *    case INDX_CUSTOM1:
    *       return KAL_TRUE;
    */

   default:
      return KAL_FALSE;
   }

   return KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*  custom_config_task_under_factory_boot
*
* DESCRIPTION
*  This function dedicates custom tasks present or not under factory boot mode
*
* PARAMETERS
*  task_indx   -   task index of task to configure
*
* RETURNS
*  KAL_TRUE  : present on factory boot mode
*  KAL_FALSE : otherwise
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_config_task_under_factory_boot(task_indx_type task_indx)
{
   switch (task_indx) {

   /*
    * Return true value for the custom task you are interesting.
    * For example,
    *    case INDX_CUSTOM1:
    *       return KAL_TRUE;
    */

   default:
      return KAL_FALSE;
   }

   return KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*  custom_config_task_stack_location
*
* DESCRIPTION
*  This function will re-configure task stack location (INTSRAM/EXTSRAM)
*  Original configuration in config.lib will be overwritten.
*  XXX PLEASE DON'T EDIT THE FUNCTION.
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*  task_info_g
*
*************************************************************************/
void custom_config_task_stack_location(void)
{
#ifdef __SYS_INTERN_RAM__
   /* DCM_ENABLE feature ON/OFF
    * IDLE task have to put in internal SRAM when DCM_ENABLE ON
    */
   #if defined(DCM_ENABLE)
      task_info_g[ INDX_IDLE ].task_internal_ram_stack = KAL_TRUE;
   #endif /* DCM_ENABLE */
#endif /* __SYS_INTERN_RAM__ */
   return;
}

/*************************************************************************
* FUNCTION
*  custom_get_task_module()
*
* DESCRIPTION
*  This routine returns the number of customer tasks and modules.
*
* PARAMETERS
*  Pointer of 8-bits unsigned integer used to return the value.
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void 
custom_get_task_module(kal_uint8 *custom_task, kal_uint8 *custom_module)
{
   *custom_task = RPS_CUSTOM_TASKS_END - RPS_CUSTOM_TASKS_BEGIN;
   *custom_module = MOD_CUSTOM_END - MOD_CUSTOM_BEGIN;
}

/*************************************************************************
* FUNCTION
*  remap_mod_task_g
*
* DESCRIPTION
*  This function will remap module to new task at initialization stage.
*  Original configuration in config.lib will be overwritten.
*  XXX PLEASE DON'T EDIT THE FUNCTION.
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*  mod_task_g
*
*************************************************************************/
void remap_mod_task_g(void)
{
#if defined(JATAAYU_SUPPORT) || defined(OBIGO_Q05A)
   mod_task_g[MOD_WAP] = INDX_MMI;
#endif
#ifndef OBIGO_Q03C_MMS_V02
   mod_task_g[MOD_MMS] = mod_task_g[MOD_WAP];
#endif
   return;
}

/*************************************************************************
* FUNCTION
*  customization_check
*
* DESCRIPTION
*  Checking system customization, including number of tasks, modules,
*  message ID and SAP.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void
customization_check(void)
{
   /* Check if customer tasks exceeding limitation */
   if ( (RPS_CUSTOM_TASKS_END - RPS_CUSTOM_TASKS_BEGIN) > MAX_CUSTOM_TASKS )
      kal_fatal_error_handler(KAL_ERROR_CUSTOMER_TASK_ID_EXCEED_UPPER_BOUND,
                              (kal_uint32)(RPS_CUSTOM_TASKS_BEGIN-RPS_CUSTOM_TASKS_END)
                             );
                             
   /* Check if customer module ID exceeding limitation */
   if ( (MOD_CUSTOM_END - MOD_CUSTOM_BEGIN) > MAX_CUSTOM_TASKS )
      kal_fatal_error_handler(KAL_ERROR_CUSTOMER_MOD_ID_EXCEED_UPPER_BOUND,
                              (kal_uint32)(MOD_CUSTOM_END - MOD_CUSTOM_BEGIN)
                             );
                             
   /* Check if customer message ID exceeding limitation */
   if ( (MSG_ID_END - CUSTOM_MSG_CODE_BEGIN) > MAX_CUSTOM_MESSAGE_ID )
      kal_fatal_error_handler(KAL_ERROR_CUSTOMER_MEESAGE_ID_EXCEED_UPPER_BOUND,
                              (kal_uint32)(MSG_ID_END - CUSTOM_MSG_CODE_BEGIN)
                             );
                          
   /* Check if customer tasks exceeding limitation */
   if ( (LAST_SAP_CODE - CUSTOM_SAP_BEGIN - 1) > MAX_CUSTOM_SAP_ID )
      kal_fatal_error_handler(KAL_ERROR_CUSTOMER_SAP_ID_EXCEED_UPPER_BOUND,
                              (kal_uint32)(LAST_SAP_CODE - CUSTOM_SAP_BEGIN - 1)
                             );
}

/*************************************************************************
* FUNCTION
*  custom_config_mod_task_g()
*
* DESCRIPTION
*   This routine process custom module to global module to task mapping 
*   relation. XXX. PLEASE DON'T EDIT THE FUNCTION.
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void 
custom_config_mod_task_g(void)
{
   kal_uint32 i;

   for (i = 0; i < MAX_CUSTOM_MODS; i++) {
      if ((task_indx_type)custom_mod_task_g[i] == INDX_NIL)
         break;

      mod_task_g[i + MOD_CUSTOM_BEGIN] = (task_indx_type)custom_mod_task_g[i];
   }
}

/*************************************************************************
* FUNCTION
*  custom_config_demp_page
*
* DESCRIPTION
*  This routine configures pages for demand paging.
*
* PARAMETERS
*  page        -   returned pointer to control blocks
*  pool        -   returned pointer to page pool
*  pool_size   -   returned pointer to page pool size
*
* RETURNS
*  0 fo success; -1 for failure.
*
************************************************************************/
#define DEMP_PAGE_POOL_SIZE (800 * 1024)

#if defined(__NFB_ON_DEMAND_PAGE_IN__)

/* define page pool */
#if defined(__MTK_TARGET__)
#pragma arm section zidata = "NONCACHEDZI"
static __align((2 << PAGE_CLUSTER) * 1024) kal_uint32 DEMP_PAGE_POOL[DEMP_PAGE_POOL_SIZE / 4];
#pragma arm section zidata
#else
static kal_uint32 DEMP_PAGE_POOL[DEMP_PAGE_POOL_SIZE / 4];
#endif /* MTK_TARGET */

/* define the control block for pages */
static demp_page_t DEMP_PAGE_LIST[DEMP_PAGE_POOL_SIZE >> (PAGE_SHIFT_2K + (PAGE_CLUSTER - 1))];
#endif  /* __NFB_ON_DEMAND_PAGE_IN__ */

kal_int32
custom_config_demp_page(kal_uint32 **list, kal_uint32 **pool, kal_uint32 *pool_size)
{
#if defined(__NFB_ON_DEMAND_PAGE_IN__)

   if (list != NULL) {
      *list = (kal_uint32 *)DEMP_PAGE_LIST;
   } else {
      return -1;
   }

   if (pool != NULL) {
      *pool = (kal_uint32 *)DEMP_PAGE_POOL;
   } else {
      return -1;
   }

   if (pool_size != NULL) {
      *pool_size = DEMP_PAGE_POOL_SIZE;
   } else {
      return -1;
   }

   return 0;

#else   /* __NFB_ON_DEMAND_PAGE_IN__ */

   return -1;

#endif  /* __NFB_ON_DEMAND_PAGE_IN__ */
}

__TEMPLATE

   return $template;
}

#****************************************************************************
# subroutine:  generate fs_config.c content body
# return:      the body strings
#****************************************************************************
sub fs_config_c_file_body
{
    my $drive_num     = &dispatch_drivenum();
    my $buffer_num    = &dispatch_buffnum();
    my $fh_num        = &dispatch_fhnum();
    my $maxthread_num = &dispatch_threadnum();
    
    my $template = <<"__TEMPLATE";
#ifndef _KAL_RELEASE_H
#include "kal_release.h"
#endif

#include "fs_type.h"
#include "custom_fs.h"
#include "kal_non_specific_general_types.h"

   /* IMPORT DEVICE DRIVER and DRIVER DATA */
#include "drvflash.h"
extern NOR_FLASH_DRV_Data  FlashDriveData;
extern FS_Driver NORFlashDriver;

#ifdef NAND_SUPPORT
#include "NAND_FDM.h"
#if ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
extern NAND_FLASH_DRV_DATA  NANDFlashDriveData[NAND_DISK_NUM];
#else   // ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) ) 
extern NAND_FLASH_DRV_DATA  NANDFlashDriveData;
#endif  // ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
extern FS_Driver NANDFlashDriver;
#endif

#if (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined(__MSDC_MSPRO__))
#include "msdc_def.h"
extern FS_Driver FS_MsDrv;
extern FS_Driver FS_SdDrv;
extern FS_Driver FS_MspDrvAll;
extern FS_Driver FS_SdDrv2;
#endif

#ifdef __OTG_ENABLE__
#include "usb_host_ms_if.h"
extern kal_uint8 USBHost_Media_Handle[];
extern FS_Driver FS_OTGDrv;
#endif

   /* EXTRA DRIVE/FILEHANDLE NUM Declaration */
#if (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined(__MSDC_MSPRO__))
#define MSDC1_DRIVE_NUM (1)
#else
#define MSDC1_DRIVE_NUM (0)
#endif

#ifdef __SIM_PLUS__
#define SIMPLUS_DRIVE_NUM (1)
#else
#define SIMPLUS_DRIVE_NUM (0)
#endif

#ifdef __MSDC2_SD_MMC__
#define MSDC2_DRIVE_NUM (1)
#else
#define MSDC2_DRIVE_NUM (0)
#endif

// Dual T-card support
#ifdef __FS_CARD2_SUPPORT__
#define MSDC3_DRIVE_NUM (1)
#else
#define MSDC3_DRIVE_NUM (0)
#endif

#ifdef __OTG_ENABLE__
/* The number of supported OTG devices is not configurable */
#define OTG_DRIVE_NUM  (USB_HOST_MS_SUPPORT_LUN)
#else
#define OTG_DRIVE_NUM  (0)
#endif

#define EXTRA_DRIVE_NUM (MSDC1_DRIVE_NUM + SIMPLUS_DRIVE_NUM + MSDC2_DRIVE_NUM + MSDC3_DRIVE_NUM + OTG_DRIVE_NUM)

#ifdef __FS_CARD_DOWNLOAD__
/* Bootloader w/ TinyFS */
#define EXTRA_FH_NUM    (0)
#define EXTRA_FH_NUM2	(0)

#else

#ifdef __J2ME__
#include "j2me_custom.h"
#if (defined(J2ME_JSR_75_FILE_HANDLER_RESERVE_COUNT))
#define EXTRA_FH_NUM    (J2ME_JSR_75_FILE_HANDLER_RESERVE_COUNT)
#else
#define EXTRA_FH_NUM    (0)
#endif
#else /* __J2ME__ */
#define EXTRA_FH_NUM    (0)
#endif /* __J2ME__ */

#ifdef __MMI_VECTOR_FONT_SUPPORT__
#include "vector_font_resource_def.h"
#define EXTRA_FH_NUM2   (MMI_FE_EXT_RESOURCE_NUM)
#else
#define EXTRA_FH_NUM2	(0)
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */
#endif /* __FS_CARD_DOWNLOAD__ */

/************************ User Configuration ************************/
/* The nubmer of drive in file system: EXTRA_DRIVE_NUM + X;
 * X : partitions on (NOR/NAND) flash. 1 <= X <= 4 
 *     3 in general (system drive + user drive on NOR + user drive on NAND)
 *     modify X to best-fit your case
 * EXTRA_DRIVE_NUM : number of external device other than flash device
 *                   auto calculated, don't remove
 */
#ifdef __FS_CARD_DOWNLOAD__
const UINT FS_MAX_DRIVES = 1;
#elif defined(__NANDFDM_MULTI_INSTANCE__)
const UINT FS_MAX_DRIVES = EXTRA_DRIVE_NUM + NAND_DISK_NUM + 1;
#else // defined(__NANDFDM_MULTI_INSTANCE__)
const UINT FS_MAX_DRIVES = EXTRA_DRIVE_NUM + $drive_num;
#endif // defined(__NANDFDM_MULTI_INSTANCE__)

/* The number of buffer in file system:  X >= 1 */
#ifdef __FS_CARD_DOWNLOAD__
const UINT FS_MAX_BUFFERS = 2;
#else
const UINT FS_MAX_BUFFERS = $buffer_num;
#endif

/* The number of file handle in file system: EXTRA_FH_NUM + X;
 * EXTRA_FH_NUM: number of file handle for downloadable application, don't remove
 * X >=  4 #if GSM
 * X >= 16 #if GPRS
 * Recommend Value For General Case: 24  # modify this value to best fit your case
 *
 *      24 =  9 (foreground app.) + 12 (basic background app. worst case) + 3 (optional)
 * 
 * Table of Background File Handle Usage by optional application/feature
 * { 4,  BlueTooth FTP + OPP profile },
 * { 1,  IRDA Support                },
 * { 1,  DT Support (Phone Suite)    },
 * { 2,  IMPS                        },
 * { 1,  EMail                       },
 * { 1,  POC                         },
 * { 1,  SIP                         },
 */
#ifdef __FS_CARD_DOWNLOAD__
const UINT FS_MAX_FILES = 1;
#else 
const UINT FS_MAX_FILES = EXTRA_FH_NUM + EXTRA_FH_NUM2 + $fh_num;
#endif

/* The number of tasks that will use file system: X >=  5 #if GSM
 *                                                X >= 10 #if GPRS
 * Default Value: 23 (GPRS), 35 (EDGE)
 * Common {NVRAM, MMI, MED, FMT, WAP, WPS, L4, L1AUDIO}
 * Discount 1 per feature OFF to optimize
 * {BLUETOOTH, DT, EMAIL, GDC, GDD, IMPS, JVM, JAM, POC, SIP}
 * {XDM, VOIP, DHCP, TFTP, SAF, SUPC, RTSP, DM, DRMT, CERTMAN}
 * {TLS, SYNCML, VRT, MMS, IVD, TR, USB, GADGET}
 */
#ifdef __FS_CARD_DOWNLOAD__ 
const UINT FS_MAX_THREAD = 1;
#else
const UINT FS_MAX_THREAD = $maxthread_num;
#endif
/* The max number of continuous cluster for copy iteration
 *
 * Default value: 128 , 32 (MT6223P)
 */
#if defined(MT6223P)
const UINT FS_MAX_COPY_CLUSTER =  32;
#else /* MT6223P */
const UINT FS_MAX_COPY_CLUSTER = 128;
#endif /* MT6223P */

#if defined(__FS_SORT_SUPPORT__)
const UINT FS_SORTING_MAX_ENTRY = FS_SORT_MAX_ENTRY;
#endif /* FS_SORT_SUPPORT */

#if (defined __FS_SYSDRV_ON_NAND__) && !(defined _NAND_FLASH_BOOTING_)
        /* Treat __FS_SYSDRV_ON_NAND__ equal _NAND_FLASH_BOOTING_ */
#define _NAND_FLASH_BOOTING_
#endif

// FS internal open hint management - Resource configuration
#ifdef __FS_OPEN_HINT__
#if (defined(MT6235) || defined(MT6235B) || defined(MT6238) || defined(MT6239) || defined(MT6268))
const UINT FS_MAX_OPEN_HINT_PATH               =  8;
const UINT FS_MAX_OPEN_HINT_LOCATION_PER_HINT  =  2;
#else
const UINT FS_MAX_OPEN_HINT_PATH               =  4;
const UINT FS_MAX_OPEN_HINT_LOCATION_PER_HINT  =  2;
#endif
#endif /* __FS_OPEN_HINT__ */

#ifdef __FS_DEDICATED_BUFFER__
const UINT FS_DEDICATED_BUFFER_SIZE         = (16 FS_KB);
#endif /* __FS_DEDICATED_BUFFER__ */

#ifdef _NAND_FLASH_BOOTING_
/* The size of sanity check buffer in byte */
/* It's for system drive on NAND flash booting type project */
/* If the size is not big enough, it will assert when booting up */
const UINT FS_MAX_CHECK_BUFFER = 5*1024;
#else
const UINT FS_MAX_CHECK_BUFFER = 4;
#endif

/* Device List Configuration */
FS_Device gFS_DeviceList[] = {
#ifndef __FS_CARD_DOWNLOAD__
#ifndef _NAND_FLASH_BOOTING_
        {FS_DEVICE_FDISK, 0, FS_DEVICE_NOR_FLASH, &NORFlashDriver, (void *)&FlashDriveData, NULL},
#endif

#ifdef NAND_SUPPORT
        #if ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
        {FS_DEVICE_FDISK, 0, FS_DEVICE_NAND_FLASH, &NANDFlashDriver, (void *)&(NANDFlashDriveData[0]), NULL},
        #if (NAND_DISK_NUM > 1)
        {FS_DEVICE_FDISK, 0, FS_DEVICE_NAND_FLASH, &NANDFlashDriver, (void *)&(NANDFlashDriveData[1]), NULL},
        #endif /* NAND_DISK_NUM > 1 */
        #if (NAND_DISK_NUM > 2)
        {FS_DEVICE_FDISK, 0, FS_DEVICE_NAND_FLASH, &NANDFlashDriver, (void *)&(NANDFlashDriveData[2]), NULL},
        #endif /* NAND_DISK_NUM > 2 */
        #if (NAND_DISK_NUM > 3)
        {FS_DEVICE_FDISK, 0, FS_DEVICE_NAND_FLASH, &NANDFlashDriver, (void *)&(NANDFlashDriveData[3]), NULL},
        #endif /* NAND_DISK_NUM > 3 */
        #if (NAND_DISK_NUM > 4)
        {FS_DEVICE_FDISK, 0, FS_DEVICE_NAND_FLASH, &NANDFlashDriver, (void *)&(NANDFlashDriveData[4]), NULL},
        #endif /* NAND_DISK_NUM > 4 */
        #if (NAND_DISK_NUM > 5)
        {FS_DEVICE_FDISK, 0, FS_DEVICE_NAND_FLASH, &NANDFlashDriver, (void *)&(NANDFlashDriveData[5]), NULL},
        #endif /* NAND_DISK_NUM > 5 */
        #if (NAND_DISK_NUM > 6)
        {FS_DEVICE_FDISK, 0, FS_DEVICE_NAND_FLASH, &NANDFlashDriver, (void *)&(NANDFlashDriveData[6]), NULL},
        #endif /* NAND_DISK_NUM > 6 */
        #if (NAND_DISK_NUM > 7)
        {FS_DEVICE_FDISK, 0, FS_DEVICE_NAND_FLASH, &NANDFlashDriver, (void *)&(NANDFlashDriveData[7]), NULL},
        #endif /* NAND_DISK_NUM > 7 */
        #else // ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
        {FS_DEVICE_FDISK, 0, FS_DEVICE_NAND_FLASH, &NANDFlashDriver, (void *)&NANDFlashDriveData, NULL},
        #endif // ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
#endif
#endif /* __FS_CARD_DOWNLOAD__ */

#ifdef __MSDC_MS__
        {FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE, &FS_MsDrv, (void *)&gMSDC_Handle, NULL},
#elif (defined __MSDC_SD_MMC__)
        #if defined(__SIM_PLUS__)
        {FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE, &FS_SdDrv, (void *)&MSDC_Blk[SD_EXT], NULL},
        {FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE
                           | FS_DEVICE_SIMPLUS  , &FS_SdDrv, (void *)&MSDC_Blk[SD_SIM], NULL},
        #elif defined(__MSDC2_SD_MMC__)
        {FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE, &FS_SdDrv , (void *)&MSDC_Blk[0], NULL},
        {FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE, &FS_SdDrv2, (void *)&MSDC_Blk[1], NULL},
        #else
        {FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE, &FS_SdDrv, (void *)&MSDC_Blk[0], NULL},
        
        #ifdef __FS_CARD2_SUPPORT__ // Dual T-Card Support
        {FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE | FS_DEVICE_NO_EXPORT, &FS_SdDrv, (void *)&MSDC_Blk[1], NULL},
        #endif
        
        #endif
#elif (defined __MSDC_MSPRO__)
        {FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE
                           | FS_DEVICE_CHECK_PART
                           | FS_DEVICE_MEMORY_STICK, &FS_MspDrvAll, (void *)&gMSDC_Handle, NULL},
#endif 
#ifdef __OTG_ENABLE__
  /* The number of supported OTG devices is not configurable */
        {FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE
                           | FS_DEVICE_EXTERNAL  , &FS_OTGDrv, (void *) &USBHost_Media_Handle[0], NULL},
        {FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE
                           | FS_DEVICE_EXTERNAL  , &FS_OTGDrv, (void *) &USBHost_Media_Handle[1], NULL},
        {FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE
                           | FS_DEVICE_EXTERNAL  , &FS_OTGDrv, (void *) &USBHost_Media_Handle[2], NULL},
        {FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE
                           | FS_DEVICE_EXTERNAL  , &FS_OTGDrv, (void *) &USBHost_Media_Handle[3], NULL},
        {FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE
                           | FS_DEVICE_EXTERNAL  , &FS_OTGDrv, (void *) &USBHost_Media_Handle[4], NULL},
        {FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE
                           | FS_DEVICE_EXTERNAL  , &FS_OTGDrv, (void *) &USBHost_Media_Handle[5], NULL},
        {FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE
                           | FS_DEVICE_EXTERNAL  , &FS_OTGDrv, (void *) &USBHost_Media_Handle[6], NULL},
        {FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE
                           | FS_DEVICE_EXTERNAL  , &FS_OTGDrv, (void *) &USBHost_Media_Handle[7], NULL},
#endif
   { 0, 0, 0, 0, 0, 0 }    // end of list marker
};

/************* Do not modify anything behind this line *************/
FS_Drive          gFS_DriveTable[FS_MAX_DRIVES];
FS_File           gFS_FileTable[FS_MAX_FILES];
FS_Buffer         gFS_BufferTable[FS_MAX_BUFFERS];

#ifdef __DYNAMIC_SWITCH_CACHEABILITY__
#pragma arm section zidata = "NONCACHEDZI"
#endif // __DYNAMIC_SWITCH_CACHEABILITY__

__align(4) BYTE              gFS_BufferData[FS_MAX_BUFFERS * FS_BUFFER_SIZE];

#ifdef __FS_DEDICATED_BUFFER__
UINT              gFS_DedicatedBufferPool[FS_DEDICATED_BUFFER_SIZE / sizeof(UINT)];
#endif /* __FS_DEDICATED_BUFFER__ */

#ifdef __DYNAMIC_SWITCH_CACHEABILITY__
#pragma arm section zidata
#endif // __DYNAMIC_SWITCH_CACHEABILITY__

kal_taskid        gFS_TaskList[FS_MAX_THREAD];
FS_ExceptionData* gFS_TaskData[FS_MAX_THREAD][MAX_TLS_INDEX];

#ifdef __FS_TRACE_SUPPORT__
kal_bool          gFS_TraceTask[FS_MAX_THREAD][FS_TRACE_INDEX] = {KAL_FALSE, KAL_FALSE};
#endif

#ifndef __FS_CARD_DOWNLOAD__
__align(4) BYTE              gFS_SanityCheckBuffer[FS_MAX_CHECK_BUFFER];
#endif

#if defined(__NANDFDM_MULTI_INSTANCE__)
const int         gFS_DeviceNumOfSYSDRV = NAND_DISK_NUM;
#else  // defined(__NANDFDM_MULTI_INSTANCE__)
const int         gFS_DeviceNumOfSYSDRV = 1;
#endif // defined(__NANDFDM_MULTI_INSTANCE__)

#ifdef __FS_OPEN_HINT__
FS_OpenHintPath     gFS_OpenHintPath[FS_MAX_OPEN_HINT_PATH];
FS_OpenHintInt      gFS_OpenHint[FS_MAX_THREAD];
__align(4) BYTE                gFS_OpenHintLocationData[FS_MAX_OPEN_HINT_PATH * FS_MAX_OPEN_HINT_LOCATION_PER_HINT * sizeof(FS_OpenHintLocation)];
#endif /* __FS_OPEN_HINT__ */

#ifdef __FS_DEDICATED_BUFFER__
const UINT        FS_BUFF_SIZE_COUNT_FREE_CLUSTER = FS_DEDICATED_BUFFER_SIZE;
const UINT        FS_BUFF_SIZE_MOVE               = FS_DEDICATED_BUFFER_SIZE;
#endif /* __FS_DEDICATED_BUFFER__ */

FS_Tables gFS_Data  = 
{ 
   gFS_DriveTable,
   gFS_FileTable,
   gFS_BufferTable,
   gFS_BufferData 
};

__TEMPLATE

   return $template;
}

#****************************************************************************
# subroutine:  generate custom_fs.h content body
# return:      the body strings
#****************************************************************************
sub custom_fs_h_file_body
{
    my $template = <<"__TEMPLATE";
#ifndef _CUSTOM_FS_H
#define _CUSTOM_FS_H

/*---------------------------------------------------------------------------
 * FS Internal Open Hint Management
 *
 * If this feature is enabled, FS will try to preserve recently found locations of
 * files or folders internally. If FS user wants to open those files or folders,
 * the opening time can be minimized.
 *
 * For detailed resource configuration of FS Internal Open Hint Management, please
 * refer to fs_config.c.
 *
 * Please define/un-define this option to enable/disable this feature.
 ----------------------------------------------------------------------------*/
#if !defined(MT6223) && !defined(MT6223C) && !defined(MT6223D)
#ifndef __FS_CARD_DOWNLOAD__
#define __FS_OPEN_HINT__
#endif
#endif

/*---------------------------------------------------------------------------
 * FS Dedicated Buffer
 *
 * If this feature is enabled, FS will allocated a dedicated buffer to enhance file system
 * performance, like file copy, file move (to differenct drive), memory card hot-plug-in.
 *
 * The size of dedicated buffer could be configured in fs_config.c
 *
 * Please define/un-define this option to enable/disable this feature.
 ----------------------------------------------------------------------------*/
#if !defined(LOW_COST_SUPPORT) && !defined(__FS_CARD_DOWNLOAD__)
#define  __FS_DEDICATED_BUFFER__
#endif /* !LOW_COST_SUPPORT && !__FS_CARD_DOWNLOAD__ */

/*---------------------------------------------------------------------------
 * FS Disk Size Limitation
 *
 * If this option is defined, all disks with size larger than the defined value
 * will not be mounted. FS user will always get "mount failed" while accessing this
 * disk.
 *
 * Please note this is effective for all disks in file system.
 *
 * Please define/un-define this option to enable/disable this limitation.
 ----------------------------------------------------------------------------*/
//#define  FS_MAX_DISK_SIZE  2048   // Unit: Mega Bytes

#endif /* !_CUSTOM_FS_H */
__TEMPLATE

   return $template;
}

#****************************************************************************
# subroutine:  generate custom_jump_tbl.h content body
# return:      the body strings
#****************************************************************************
sub custom_jump_tbl_h_file_body
{
    my $template = <<"__TEMPLATE";
#ifndef _CUSTOM_JUMP_TBL_H_
#define _CUSTOM_JUMP_TBL_H_

#include "kal_release.h"
#include "resource_verno.h"

#if defined(_NAND_FLASH_BOOTING_)
#define SYSTEM_JUMP_TABLE_VAR_MODIFIER  
#else    /* _NAND_FLASH_BOOTING_ */
#define SYSTEM_JUMP_TABLE_VAR_MODIFIER const
#endif   /* _NAND_FLASH_BOOTING_ */

extern SYSTEM_JUMP_TABLE_VAR_MODIFIER Type_Preamble_Content system_jump_table[];

//__CUSTPACK_MULTIBIN
typedef enum 
{
   JUMP_TABLE_ENTRY_START, 
   
   JUMP_TABLE_ENTRY_LANG_PACK = JUMP_TABLE_ENTRY_START, 
   JUMP_TABLE_ENTRY_CUSTPACK,
   JUMP_TABLE_ENTRY_AUTOGEN_AUDIO,
   JUMP_TABLE_ENTRY_END = JUMP_TABLE_ENTRY_CUSTPACK

} JUMP_TABLE_ENTRY_ENUM;


#define JUMP_TABLE_ENTRY_END              JUMP_TABLE_ENTRY_CUSTPACK


/* Macros for addressing each resource */
#define GET_Res_Addr(R, X)                (((kal_uint32 *) (system_jump_table[R].StartAddress)) + X)
#define GET_Res_ProjectID(X)              (system_jump_table[X].ProjectID)
#define GET_Res_Magic(X)                  (system_jump_table[X].Magic)


#if defined(__MULTIPLE_BINARY_FILES__) && defined(__MTK_TARGET__)


extern Type_Preamble_Content AudioResPreamble;
extern void* audio2ndJumpTbl[];

extern Type_Preamble_Content AutogenAudioResPreamble;
extern void* autogenaudio2ndJumpTbl[];

extern Type_Preamble_Content ImageResPreamble;
extern void* image2ndJumpTbl[];

#ifdef __J2ME__
extern Type_Preamble_Content J2MEResPreamble;
extern void* J2ME2ndJumpTbl[];
#endif /*__J2ME__*/

#define CONST_RES_IMAGE_ADDR              ((kal_uint32 *)&ImageResPreamble)
#define CONST_RES_IMAGE_TBL_SIZE          ((kal_uint32)0)
#define CONST_RES_IMAGE_CONTENT_SIZE      ((kal_uint32)0)
#define CONST_RES_AUDIO_ADDR              ((kal_uint32 *)&AudioResPreamble)
#define CONST_RES_AUDIO_TBL_SIZE          ((kal_uint32)0)
#define CONST_RES_AUDIO_CONTENT_SIZE      ((kal_uint32)0)

#define CONST_RES_AUTOGEN_AUDIO_ADDR              ((kal_uint32 *)&AutogenAudioResPreamble)
#define CONST_RES_AUTOGEN_AUDIO_TBL_SIZE          ((kal_uint32)0)
#define CONST_RES_AUTOGEN_AUDIO_CONTENT_SIZE      ((kal_uint32)0)

#ifdef __J2ME__
#define CONST_RES_J2ME_ADDR               ((kal_uint32 *)&J2MEResPreamble)
#define CONST_RES_J2ME_TBL_SIZE           ((kal_uint32)0)
#define CONST_RES_J2ME_CONTENT_SIZE       ((kal_uint32)0)
#endif /*__J2ME__*/  


/* Macros below specific for multiple binary files or multiple load segments only */
/* Collection of Lang Pack */
extern kal_uint32  Load\$\$LANG_PACK_ROM\$\$Base;
extern kal_uint32  Image\$\$LANG_PACK_ROM\$\$Length;
extern kal_uint32  Image\$\$LANG_PACK_ROM_CONTENT\$\$Length;

//__CUSTPACK_MULTIBIN__
extern kal_uint32  Load\$\$CUSTPACK_ROM\$\$Base;
extern kal_uint32  Image\$\$CUSTPACK_ROM\$\$Length;
extern kal_uint32  Image\$\$CUSTPACK_ROM_CONTENT\$\$Length;


/* macro of resource address and size for const arrary initialization */
#define GET_ResLangPack_Addr(X)           GET_Res_Addr(JUMP_TABLE_ENTRY_LANG_PACK, X)
#define CONST_RES_LANG_PACK_ADDR          (&Load\$\$LANG_PACK_ROM\$\$Base)
#define CONST_RES_LANG_PACK_TBL_SIZE      ((kal_uint32)&Image\$\$LANG_PACK_ROM\$\$Length)
#define CONST_RES_LANG_PACK_CONTENT_SIZE  ((kal_uint32)&Image\$\$LANG_PACK_ROM_CONTENT\$\$Length)


//__CUSTPACK_MULTIBIN__
#define GET_ResCUSTPACK_Addr(X)           GET_Res_Addr(JUMP_TABLE_ENTRY_CUSTPACK, X)
#define CONST_RES_CUSTPACK_ADDR           (&Load\$\$CUSTPACK_ROM\$\$Base)
#define CONST_RES_CUSTPACK_TBL_SIZE       ((kal_uint32)&Image\$\$CUSTPACK_ROM\$\$Length)
#define CONST_RES_CUSTPACK_CONTENT_SIZE   ((kal_uint32)&Image\$\$CUSTPACK_ROM_CONTENT\$\$Length)



#else /* __MULTIPLE_BINARY_FILES__ && __MTK_TARGET__ */

extern Type_Preamble_Content AudioResPreamble;
extern void* audio2ndJumpTbl[];
extern Type_Preamble_Content AutogenAudioResPreamble;
extern void* autogenaudio2ndJumpTbl[];
extern Type_Preamble_Content ImageResPreamble;
extern void* image2ndJumpTbl[];
extern Type_Preamble_Content LangPackResPreamble ;
extern void* langpack2ndJumpTbl[];

#ifdef __J2ME__
extern Type_Preamble_Content J2MEResPreamble;
extern void* J2ME2ndJumpTbl[];
#endif /*__J2ME__*/

extern Type_Preamble_Content CustPackResPreamble ;
extern void* custpack2ndJumpTbl[];


#define CONST_RES_IMAGE_ADDR                   ((kal_uint32 *)&ImageResPreamble)
#define CONST_RES_IMAGE_TBL_SIZE               ((kal_uint32)0)
#define CONST_RES_IMAGE_CONTENT_SIZE           ((kal_uint32)0)

#define CONST_RES_AUDIO_ADDR                   ((kal_uint32 *)&AudioResPreamble)
#define CONST_RES_AUDIO_TBL_SIZE               ((kal_uint32)0)
#define CONST_RES_AUDIO_CONTENT_SIZE           ((kal_uint32)0)

#define CONST_RES_AUTOGEN_AUDIO_ADDR           ((kal_uint32 *)&AutogenAudioResPreamble)
#define CONST_RES_AUTOGEN_AUDIO_TBL_SIZE       ((kal_uint32)0)
#define CONST_RES_AUTOGEN_AUDIO_CONTENT_SIZE   ((kal_uint32)0)

#if defined(EMPTY_MMI) || defined(EXTERNAL_MMI)
#define CONST_RES_LANG_PACK_ADDR               ((kal_uint32)0)
#define CONST_RES_LANG_PACK_TBL_SIZE           ((kal_uint32)0)
#define CONST_RES_LANG_PACK_CONTENT_SIZE       ((kal_uint32)0)
#else  /* EMPTY_MMI || EXTERNAL_MMI */
#define CONST_RES_LANG_PACK_ADDR               ((kal_uint32 *)&LangPackResPreamble)
#define CONST_RES_LANG_PACK_TBL_SIZE           ((kal_uint32)0)
#define CONST_RES_LANG_PACK_CONTENT_SIZE       ((kal_uint32)0)
#endif /* EMPTY_MMI || EXTERNAL_MMI */

#define CONST_RES_CUSTPACK_ADDR                ((kal_uint32 *)&CustPackResPreamble)
#define CONST_RES_CUSTPACK_TBL_SIZE            ((kal_uint32)0)
#define CONST_RES_CUSTPACK_CONTENT_SIZE        ((kal_uint32)0)

#ifdef __J2ME__
#define CONST_RES_J2ME_ADDR                    ((kal_uint32 *)&J2MEResPreamble)
#define CONST_RES_J2ME_TBL_SIZE                ((kal_uint32)0)
#define CONST_RES_J2ME_CONTENT_SIZE            ((kal_uint32)0)
#endif /*__J2ME__*/


#define GET_ResImage_Addr(X)                   ((kal_uint32 *)&image2ndJumpTbl)
#define GET_ResAudio_Addr(X)                   ((kal_uint32 *)&audio2ndJumpTbl)
#define GET_ResAutogenAudio_Addr(X)            ((kal_uint32 *)&autogenaudio2ndJumpTbl)
#define GET_ResFont_Addr(X)                    ((kal_uint32 *)&font2ndJumpTbl)
#define GET_ResStr_Addr(X)                     ((kal_uint32 *)&str2ndJumpTbl)
#define GET_ResIME_Addr(X)                     ((kal_uint32 *)&IME2ndJumpTbl)
#define GET_ResLangPack_Addr(X)                ((kal_uint32 *)&langpack2ndJumpTbl)
#define GET_ResCUSTPACK_Addr(X)                ((kal_uint32 *)&custpack2ndJumpTbl)

#ifdef __J2ME__
#define GET_ResJ2ME_Addr(X)                    ((kal_uint32 *)&J2ME2ndJumpTbl)
#endif /*__J2ME__*/


#endif /* __MULTIPLE_BINARY_FILES__ && __MTK_TARGET__ */

#endif /* _CUSTOM_JUMP_TBL_H_ */
__TEMPLATE

   return $template;
}

#****************************************************************************
# subroutine:  generate custom_jump_tbl.c content body
# return:      the body strings
#****************************************************************************
sub custom_jump_tbl_c_file_body
{
    my $template = <<"__TEMPLATE";
#include "kal_release.h"
#include "custom_jump_tbl.h"
#include "verno.h"

#if ( (defined(__MTK_TARGET__) || defined(KAL_ON_OSCAR) ) && !defined(__MAUI_BASIC__) && !defined(__L1_STANDALONE__) ) 

#if defined(_NAND_FLASH_BOOTING_)
#define SYSTEM_JUMP_TABLE_VAR_MODIFIER  
#else    /* _NAND_FLASH_BOOTING_ */
#define SYSTEM_JUMP_TABLE_VAR_MODIFIER const
#endif   /* _NAND_FLASH_BOOTING_ */

SYSTEM_JUMP_TABLE_VAR_MODIFIER Type_Preamble_Content  system_jump_table[8] = { 
   /* Language Pack */
   { VERNO_STR,
     (kal_uint32)(RESOURCE_TYPE_LANG_PACK + CURRENT_LANG_PACK_RES_VERSION), 
     CONST_RES_LANG_PACK_ADDR,
     CONST_RES_LANG_PACK_TBL_SIZE,
     CONST_RES_LANG_PACK_CONTENT_SIZE, 
     (kal_uint32)MAGIC_NUMBER
   },
   /*__CUSTPACK_MULTIBIN__ */
   { VERNO_STR,
     (kal_uint32)(RESOURCE_TYPE_CUSTPACK+CURRENT_CUSTPACK_RES_VERSION),
     CONST_RES_CUSTPACK_ADDR,
     CONST_RES_CUSTPACK_TBL_SIZE,
     CONST_RES_CUSTPACK_CONTENT_SIZE,
     (kal_uint32)MAGIC_NUMBER
   },
   { VERNO_STR,
     (kal_uint32)0,
     (kal_uint32 *)0,
     (kal_uint32)0,
     (kal_uint32)0,
     (kal_uint32)MAGIC_NUMBER
   },
   { VERNO_STR,
     (kal_uint32)0,
     (kal_uint32 *)0,
     (kal_uint32)0,
     (kal_uint32)0,
     (kal_uint32)MAGIC_NUMBER
   },
   { VERNO_STR,
     (kal_uint32)0,
     (kal_uint32 *)0,
     (kal_uint32)0,
     (kal_uint32)0,
     (kal_uint32)MAGIC_NUMBER
   },
   { VERNO_STR,
     (kal_uint32)0,
     (kal_uint32 *)0,
     (kal_uint32)0,
     (kal_uint32)0,
     (kal_uint32)MAGIC_NUMBER
   },
   { VERNO_STR,
     (kal_uint32)0,
     (kal_uint32 *)0,
     (kal_uint32)0,
     (kal_uint32)0,
     (kal_uint32)MAGIC_NUMBER
   },
   { VERNO_STR,
     (kal_uint32)0,
     (kal_uint32 *)0,
     (kal_uint32)0,
     (kal_uint32)0,
     (kal_uint32)MAGIC_NUMBER
   }
}; 

#endif  /* __MTK_TARGET__ || KAL_ON_OSCAR && !__MAUI_BASIC__ && !__L1_STANDALONE__ */

/*************************************************************************
* FUNCTION
*  NFBMBA_loader_iteration_callback
*
* DESCRIPTION
*  This routine called when NFB MBA resource binary loaded
*
* PARAMETERS
*  addr        -   the resource binary begin address
*  len         -   the resource binary length 
*
* RETURNS
*  void
*
typedef struct
{
    kal_char ProjectID[PROJECTID_LEN];
    kal_uint32 Resource_version;
    kal_uint32 *StartAddress;
    kal_uint32 TableSize;
    kal_uint32 ContentSize;
    kal_uint32 Magic;
} Type_Preamble_Content;
*
************************************************************************/
extern kal_uint32 SSF_GetMAUIImageNumber(void);

#if defined(_NAND_FLASH_BOOTING_) 
void
NFBMBA_loader_iteration_callback(kal_uint32 addr, kal_uint32 length)
{
   #if defined(__MULTIPLE_BINARY_FILES__)
   static index=0;
   Type_Preamble_Content  *pHeader;

   pHeader = (Type_Preamble_Content *) addr;

   system_jump_table[index].StartAddress = (kal_uint32*) addr;
   system_jump_table[index].TableSize    = pHeader->TableSize;
   system_jump_table[index].ContentSize  = pHeader->ContentSize;
   //system_jump_table[index].Resource_version = pHeader->Resource_version;
   
   if (SSF_GetMAUIImageNumber() > 0)
   // dummy reference to keep IMG_FOTA_INFO
   {
   index++;
   }
   #endif /* __MULTIPLE_BINARY_FILES__ */
}
#endif   /* _NAND_FLASH_BOOTING_ */

/*************************************************************************
* FUNCTION
*  NFBMBA_loader_getImageLength
*
* DESCRIPTION
*  This routine called when NFB MBA resource binary identified
*
* PARAMETERS
*  data        -   the resource binary begin address (only 1 page loaded)
*
* RETURNS
*  the image total length calculated from header
*
typedef struct
{
    kal_char ProjectID[PROJECTID_LEN];
    kal_uint32 Resource_version;
    kal_uint32 *StartAddress;
    kal_uint32 TableSize;
    kal_uint32 ContentSize;
    kal_uint32 Magic;
} Type_Preamble_Content;
*
************************************************************************/
#if defined(_NAND_FLASH_BOOTING_) 
kal_uint32
NFBMBA_loader_getImageLength(void *data)
{
   #if defined(__MULTIPLE_BINARY_FILES__)
   Type_Preamble_Content  *pHeader;
   kal_uint32  len;
   
   pHeader = (Type_Preamble_Content *) data;
   len = pHeader->TableSize + pHeader->ContentSize;
   
   return len;

   #else  /* __MULTIPLE_BINARY_FILES__ */
   return 0;
   #endif /* __MULTIPLE_BINARY_FILES__ */
}
#endif   /* _NAND_FLASH_BOOTING_ */

/*************************************************************************
* FUNCTION
*  NFBMBA_loader_getImageExecViewAddress
*
* DESCRIPTION
*  This routine called when NFB MBA resource binary identified
*
* PARAMETERS
*  data        -   the resource binary begin address (only 1 page loaded)
*
* RETURNS
*  the starting address of RESB retrieved from the header
*
typedef struct
{
    kal_char ProjectID[PROJECTID_LEN];
    kal_uint32 Resource_version;
    kal_uint32 *StartAddress;
    kal_uint32 TableSize;
    kal_uint32 ContentSize;
    kal_uint32 Magic;
} Type_Preamble_Content;
*
************************************************************************/
#if defined(_NAND_FLASH_BOOTING_) 
kal_uint32
NFBMBA_loader_getImageExecViewAddress(void *data)
{
   #if defined(__MULTIPLE_BINARY_FILES__)
   Type_Preamble_Content  *pHeader;
   kal_uint32  addr;
   
   pHeader = (Type_Preamble_Content *) data;
   addr = (kal_uint32) pHeader->StartAddress;
   
   return addr;

   #else  /* __MULTIPLE_BINARY_FILES__ */
   return 0;
   #endif /* __MULTIPLE_BINARY_FILES__ */
}
#endif   /* _NAND_FLASH_BOOTING_ */

__TEMPLATE

   return $template;
}

#****************************************************************************
# subroutine:  generate custom_fota.h content body
# return:      the body strings
#****************************************************************************
sub custom_fota_h_file_body
{
    my $template = <<"__TEMPLATE";
#ifndef __CUSTOM_FOTA_H__
#define __CUSTOM_FOTA_H__
#include "kal_non_specific_general_types.h"

#define END_MAUI_INFO  {0xFFFFFFFF, 0xFFFFFFFF}
/*****************************************
 * Don't modify any code above this line *
 *****************************************/

#if defined(__FOTA_DM__)

#define FUE_CACHE_WAY     (4) /* must be power of 2 */
#define FUE_CACHE_ENTRIES (8) /* must be power of 2 */

#endif /* __FOTA_DM__ */

/*****************************************
 * Don't modify any code below this line *
 *****************************************/
#if defined(__MTK_TARGET__)

#define FOTA_SYSRAM_SHARED_BUFFER_SIZE  (0x1000)

extern const kal_uint32 FOTA_FUE_RESIDENT_SPACE;

typedef kal_uint16 FOTA_NFB_Table_Element_type;

#if defined(_NAND_FLASH_BOOTING_)

#if defined(__FOTA_DM__)

typedef struct {
   kal_uint32 load_base;
   kal_uint32 load_length;
}FOTA_NFB_ROM_Image_Info;

kal_uint32 FOTA_Reserved_Area_Base_Address(void);
void FOTA_GetPackageStorage(kal_uint32 *base_addr, kal_uint32 *len);
kal_uint32 FOTA_GetPackageStorageBase(void);
kal_uint32 FOTA_GetPackageStorageSize(void);
kal_uint32 FOTA_GetRAMBaseAddr(void);
kal_uint32 FOTA_GetFATBaseAddr(void);

#endif /* __FOTA_DM__ */

#else /* !_NAND_FLASH_BOOTING_ */

#include "fat_fs.h"
#include "drvflash.h"

typedef struct {
   kal_uint32 BlockBase;
   kal_uint32 BlockSize;
} FlashBlockInfo;
#define EndBlockInfo  {0, 0}

#if defined(__FOTA_DM__)
/* For FOTA, these region information shoule be put on RAM */
extern FlashBlockInfo NORBlockInfo[];
extern FlashRegionInfo NORRegionInfo[];
extern FlashBankInfo FOTANORBankInfo[];
#endif /* __FOTA_DM__ */

#define FOTA_NOR_FLASH_PAGE_SIZE  (0x800)

#endif /* _NAND_FLASH_BOOTING_ */

#else /* !__MTK_TARGET__ */

#if defined(_NAND_FLASH_BOOTING_)

#else /* !_NAND_FLASH_BOOTING_ */

#if defined(__FOTA_DM__)

#define FOTA_NOR_FLASH_PAGE_SIZE  (0)

#endif /* __FOTA_DM__ */

#endif /* _NAND_FLASH_BOOTING_ */

#endif /*__MTK_TARGET__ */

extern kal_int32 FOTA_CustomInitialize(void);

extern const kal_uint32  FOTA_MAX_PAGE_SIZE;

#endif /*__CUSTOM_FOTA_H__*/
__TEMPLATE

   return $template;
}

#****************************************************************************
# subroutine:  generate custom_fota.c content body
# return:      the body strings
#****************************************************************************
sub custom_fota_c_file_body
{
    my $cs1_base_address = sprintf("0x%08X", &config_query_cs1_addr($MAKEFILE_OPTIONS{'platform'}));
   
    my $template = <<"__TEMPLATE";
/*******************************************
*   Customization Part      
********************************************/
#ifdef __MTK_TARGET__

#ifdef __FOTA_ENABLE__
#include "kal_non_specific_general_types.h"
#include "flash_opt.h"
#include "kal_release.h"
#include "DrvFlash.h"
#include "custom_fota.h"
#if defined(__FOTA_DM__)
#include "custom_img_config.h"
#include "fue_err.h"
#include "fue.h"
#include "ssf_fue_support.h"
#include "fue_update_support.h"
#include "bl_fota.h"
#include "fue_internal.h"
#endif /* __FOTA_DM__ */
#include "bl_loader.h"

#if defined(__FOTA_DM__)
/*******************************************
*  Data buffer declaration
********************************************/
#if defined(__UBL__)
//kal_uint32 sst_fue_header_buffer_bl[FOTA_INFO_BLOCK_SEARCH_ROUND][FOTA_FLASH_MAX_PAGE_SIZE>>2];
#endif /* __UBL__ */

#if defined(__FUE__)
//kal_uint32 ssf_page_buff_ua[FOTA_FLASH_MAX_PAGE_SIZE>>2];
#endif /* __FUE__ */

//kal_uint32 local_temp_page_buffer_ua[FOTA_FLASH_MAX_PAGE_SIZE>>2];

kal_uint32 fue_adm_buffer_pool[FOTA_FLASH_MAX_PAGE_SIZE];

FOTA_Package_List_st g_fota_package_blocks[FOTA_PACKAGE_BLOCK_NUMBER];

#if defined(_NAND_FLASH_BOOTING_)
#pragma arm section zidata = "NONCACHEDZI"
#endif

kal_uint32 fue_pkg_page_buffer[FOTA_FLASH_MAX_PAGE_SIZE>>2];
kal_uint32 fue_record_header_buffer[FOTA_INFO_BLOCK_SEARCH_ROUND][FOTA_FLASH_MAX_PAGE_SIZE>>2];
kal_uint32 fue_update_page_buffer[FOTA_FLASH_MAX_PAGE_SIZE>>2];
kal_uint32 fue_temp_table_buffer_ua[FOTA_MAUI_MAPPING_TABLE_SIZE>>2];

#if defined(_NAND_FLASH_BOOTING_)
#pragma arm section zidata
#endif

const kal_uint32  FOTA_PKG_BLOCKS = FOTA_PACKAGE_BLOCK_NUMBER;

const kal_uint32 FOTA_FUE_RESIDENT_SPACE =  FOTA_UE_RESIDENT_FLASH_SPACE_SIZE;

const kal_uint32 FOTA_FUE_BACKUP_SPACE =  FOTA_UE_BACKUP_FLASH_SPACE_SIZE;

const kal_uint32 FOTA_IMAGE_MAPPING_TABLE_SIZE = FOTA_MAUI_MAPPING_TABLE_SIZE;

const kal_uint32 FOTA_MAUI_INFO_SEARCH_RANGE=  MAUI_IMAGE_INFO_RANGE;

const kal_uint32 FOTA_FUE_PAGE_BUFFER_SIZE =  FOTA_FLASH_MAX_PAGE_SIZE;

const kal_uint32 FOTA_IMG_SPACE_INFO_PAGE =  IMAGE_SPACE_PAGE_INDEX;

const kal_uint32 FOTA_IMG_LIST_INFO_PAGE =  IMAGE_LIST_PAGE_INDEX;

const kal_uint32 FOTA_IMG_VERSION_INFO_PAGE =  VERSION_INFO_PAGE_INDEX;

const kal_uint32 FOTA_IMG_LIST_VALID_PAGES =  VALID_PAGE_NUMBER;

const kal_uint32 FOTA_MTK_ILB_TAIL[] = MTK_ILB_TAIL_TAG;

const kal_uint32 FOTA_MTK_ILB_FOTA[] = MTK_ILB_FOTA_TAG;

const kal_uint32 FOTA_MTK_ILB_TAG_SIZE = sizeof(FOTA_MTK_ILB_TAIL);

FOTA_Area_Info_Wrapper_st  FOTA_NFB_Area_Info;

#endif /* __FOTA_DM__ */

/*******************************************
*  Data structure declaration
********************************************/
#if defined(__FUE__)
extern kal_uint32 Image\$\$UA_CUSTOM_ZI\$\$Base;
const kal_uint32 fota_ua_heap_base = (kal_uint32)&Image\$\$UA_CUSTOM_ZI\$\$Base;
#endif

#if defined(__FOTA_DM__)
#if defined(_NAND_FLASH_BOOTING_)

/* ROM image region information */
/* auto gen according to scatter file */
extern kal_uint32 Image\$\$SECONDARY_ROM\$\$Base;
extern kal_uint32 Load\$\$DUMMY_END\$\$Base;
extern kal_uint32 Load\$\$FOTA_ROM_TAIL\$\$Base;
extern kal_uint32 Load\$\$FOTA_FIXED\$\$Base;

/* Image execution region information */
FOTA_NFB_ROM_Image_Info FOTA_NFB_LOAD_INFO[FOTA_MAUI_IMAGE_AMOUNT];

const kal_uint32  FOTA_NFB_UE_SEARCH_RANGE = FOTA_UE_SEARCH_RANGE_SIZE;
const kal_uint32  FOTA_FAT_BASE_ADDR        = NAND_FLASH_BASE_ADDRESS;

#if defined(__FUE__)

#pragma arm section zidata = "NONCACHEDZI"

/* FUE NAND flash content cache */
FOTA_NAND_Cache_Entry_st FOTA_Page_Cache[FUE_CACHE_WAY][FUE_CACHE_ENTRIES];

/* FUE block mapping table */
kal_uint16 FUE_Map_Table[FOTA_MAUI_MAPPING_TABLE_SIZE>>1];

#pragma arm section zidata

/* FUE updateble area information */
FOTA_Flash_Alloc_Range_st  FUE_Update_Alloc_info[FOTA_MAUI_IMAGE_AMOUNT+1]; /* plus one for update agent itself */
FOTA_Image_Area_st         FUE_Update_Image_area[FOTA_MAUI_IMAGE_AMOUNT+1];

/* FUE mapping information of each image */
kal_uint32           FUE_NFB_Mapping_Block[FOTA_MAUI_IMAGE_AMOUNT+1];             /* plus 1 for UA image */
kal_uint32           FUE_NFB_Session_Record[FOTA_MAUI_IMAGE_AMOUNT+1];            /* for mapping block */
kal_uint32           FUE_NFB_Mapping_Session[FOTA_MAUI_IMAGE_AMOUNT+1];           /* for mapping table */
kal_uint32           FUE_NFB_Mapping_Page[FOTA_MAUI_IMAGE_AMOUNT+1];              /* starting page that contains current mappiong table */
kal_uint32           FUE_NFB_Next_Available_Page[FOTA_MAUI_IMAGE_AMOUNT+1];  /* available page next to the end page of current mapping table */
Nand_Update_Area_ST  FUE_NFB_Area[FOTA_MAUI_IMAGE_AMOUNT+1];

#endif /*__FUE__*/

#else /* !_NAND_FLASH_BOOTING_ */

/* For FOTA, these region information shoule be put on RAM */
FlashRegionInfo NORRegionInfo[] =
{
    CONFIG_FOTA_NOR_REGION_DEF
    EndRegionInfo /* Don't modify this line */
};

FlashBlockInfo NORBlockInfo[] =
{
    CONFIG_FOTA_NOR_BLOCK_DEF
    EndBlockInfo /* Don't modify this line */
};

FlashBankInfo FOTANORBankInfo[] =
{
    CONFIG_FOTA_NOR_BANK_DEF
    EndBankInfo /* Don't modify this line */
};

const kal_uint32  FOTA_FAT_BASE_ADDR        = NOR_FLASH_BASE_ADDRESS;

#endif /* _NAND_FLASH_BOOTING_ */
#endif /* __FOTA_DM__ */

#if !defined(__FUE__) && !defined(__BL__)
/* ---------------------------------------------------------------------------------
DESCRIPTION
   FOTA Customization Initialization API
   FOTA_Initialize() will call this function, this is for customization.
   User can register their own customized authentication or 
   decryption function in this function
PARAMETER
   NULL
RETURN
   0: means pass initialization step (ERROR_FOTA_SUCCESS)
   < 0: means fail
      ERROR_FOTA_CUSTOMIZATION: customization error
--------------------------------------------------------------------------------- */
#if !defined(__FOTA_DM__)
kal_int32 FOTA_CustomInitialize(void)
{
   kal_uint32 AddrLowBound=0, AddrUpperBound  = 0;
   kal_uint32 region = 0, StartBlkIndex = 0;

   FOTAData.SpareBaseAddr = FOTAData.FlashBaseAddr + FOTA_SPARE_BASE_ADDRESS;
   FOTAData.OriginalBaseAddr = FOTAData.FlashBaseAddr + FOTA_ORIGINAL_BASE_ADDRESS;
   FOTAData.TotalFOTALength = FOTA_SPARE_ALLOCATED_SIZE;
   FOTAData.NORRegionInfo = (FlashRegionInfo *)NORRegionInfo;
   FOTAData.SpareCurrAddr = FOTAData.SpareBaseAddr;
   FOTAData.NextBlockAddr = FOTAData.SpareBaseAddr;
   
   /*calculate the start block index*/
   AddrUpperBound = NORRegionInfo[0].RegionBlocks * NORRegionInfo[0].BlockSize;
   
   do{
      if (AddrUpperBound >= FOTA_SPARE_BASE_ADDRESS)
         break;
      else
      {
         StartBlkIndex += NORRegionInfo[region].RegionBlocks;
         region++;
         AddrLowBound = AddrUpperBound;
         AddrUpperBound = NORRegionInfo[region].RegionBlocks * NORRegionInfo[region].BlockSize;
      }
   }while(NORRegionInfo[region].RegionBlocks != 0);

   if(NORRegionInfo[region].RegionBlocks == 0 || (FOTA_SPARE_BASE_ADDRESS - AddrLowBound)%NORRegionInfo[region].BlockSize !=0)
   {
      return ERROR_FOTA_CUSTOMIZATION;
   }
   FOTAData.SpareStartBlkIndex = StartBlkIndex + (FOTA_SPARE_BASE_ADDRESS - AddrLowBound)/NORRegionInfo[region].BlockSize;

   /*register private authentication function or encryption function */
   FOTA_Reg_Auth((CALLBACK_Auth_FUNC)NULL);
   FOTA_Reg_Decrypt((CALLBACK_Decrypt_FUNC)NULL);
   
   return 0;
   
}
#else /* __FOTA_DM__ */
/* ---------------------------------------------------------------------------------
DESCRIPTION
   FOTA Customization Initialization API
   FOTA_Initialize() will call this function, this is for customization.
   User can register their own customized authentication or 
   decryption function in this function
PARAMETER
   NULL
RETURN
   0: means pass initialization step (ERROR_FOTA_SUCCESS)
   < 0: means fail
      ERROR_FOTA_CUSTOMIZATION: customization error
--------------------------------------------------------------------------------- */
kal_int32 FOTA_CustomInitialize(void)
{
   return 0;
}

#endif /* __FOTA_DM__ */
#endif /* !__FUE__ && !__UBL__ */

#if defined(__FOTA_DM__)
/* ---------------------------------------------------------------------------------
DESCRIPTION
   return flash reserved area base address
PARAMETER
   NULL
RETURN
   NULL
--------------------------------------------------------------------------------- */
kal_uint32 FOTA_Reserved_Area_Base_Address(void)
{
   kal_uint32 start_addr = 0;
   if(FOTA_BACKUP_STORAGE_BASE != INVALID_DWORD)
   {
      start_addr = FOTA_BACKUP_STORAGE_BASE+FOTA_BACKUP_STORAGE_SIZE;
   }
   else
   {
      start_addr = FOTA_PACKAGE_STORAGE_BASE+FOTA_PACKAGE_STORAGE_SIZE;
   }
   return start_addr;
}

/* ---------------------------------------------------------------------------------
DESCRIPTION
   return package storage area space information
PARAMETER
   NULL
RETURN
   NULL
--------------------------------------------------------------------------------- */
void FOTA_GetPackageStorage(kal_uint32 *base_addr, kal_uint32 *len)
{
    ASSERT(base_addr != NULL);
    ASSERT(len != NULL);

    *base_addr = FOTA_PACKAGE_STORAGE_BASE;
    *len = FOTA_PACKAGE_STORAGE_SIZE;
}

/* ---------------------------------------------------------------------------------
DESCRIPTION
   return package storage area space base address
PARAMETER
   NULL
RETURN
   NULL
--------------------------------------------------------------------------------- */
kal_uint32 FOTA_GetPackageStorageBase(void)
{
    return FOTA_PACKAGE_STORAGE_BASE;
}

/* ---------------------------------------------------------------------------------
DESCRIPTION
   return package storage area space size
PARAMETER
   NULL
RETURN
   NULL
--------------------------------------------------------------------------------- */
kal_uint32 FOTA_GetPackageStorageSize(void)
{
    return FOTA_PACKAGE_STORAGE_SIZE;
}

#define CS0_BASE_ADDRESS 0x00000000
#define CS1_BASE_ADDRESS $cs1_base_address
/* ---------------------------------------------------------------------------------
DESCRIPTION
   return memory base address
PARAMETER
   NULL
RETURN
   NULL
--------------------------------------------------------------------------------- */
kal_uint32 FOTA_GetRAMBaseAddr(void)
{
#if defined(_NAND_FLASH_BOOTING_)
    return CS0_BASE_ADDRESS;
#else /* !_NAND_FLASH_BOOTING_ */
    return CS1_BASE_ADDRESS;
#endif /* _NAND_FLASH_BOOTING_ */
}

/* ---------------------------------------------------------------------------------
DESCRIPTION
   return FAT area base address
PARAMETER
   NULL
RETURN
   NULL
--------------------------------------------------------------------------------- */
kal_uint32 FOTA_GetFATBaseAddr(void)
{
#if defined(_NAND_FLASH_BOOTING_) || defined(__UP_PKG_ON_NAND__)
    return NAND_FLASH_BASE_ADDRESS;
#else
    return NOR_FLASH_BASE_ADDRESS;
#endif
}

#if defined(__FUE__)

#if defined(_NAND_FLASH_BOOTING_)
/* ---------------------------------------------------------------------------------
DESCRIPTION
   return FAT area base address
PARAMETER
   NULL
RETURN
   NULL
--------------------------------------------------------------------------------- */
void FOTA_InitNFBControl(FOTA_NFB_Control *fota_ctrl)
{
    ASSERT(fota_ctrl != NULL);

    kal_mem_set(FUE_Map_Table, 0xFF, FOTA_MAUI_MAPPING_TABLE_SIZE);

    kal_mem_set(FUE_NFB_Mapping_Block, 0xFF, (FOTA_MAUI_IMAGE_AMOUNT+1)<<2);
    kal_mem_set(FUE_NFB_Session_Record, 0xFF, (FOTA_MAUI_IMAGE_AMOUNT+1)<<2);
    kal_mem_set(FUE_NFB_Mapping_Session, 0xFF, (FOTA_MAUI_IMAGE_AMOUNT+1)<<2);
    kal_mem_set(FUE_NFB_Mapping_Page, 0xFF, (FOTA_MAUI_IMAGE_AMOUNT+1)<<2);
    kal_mem_set(FUE_NFB_Next_Available_Page, 0xFF, (FOTA_MAUI_IMAGE_AMOUNT+1)<<2);
    
    kal_mem_set(FUE_NFB_Area, 0xFF, sizeof(Nand_Update_Area_ST)*(FOTA_MAUI_IMAGE_AMOUNT+1));
    kal_mem_set(FUE_Update_Alloc_info, 0xFF, sizeof(FOTA_Flash_Alloc_Range_st)*(FOTA_MAUI_IMAGE_AMOUNT+1));
    kal_mem_set(FUE_Update_Image_area, 0xFF, sizeof(FOTA_Image_Area_st)*(FOTA_MAUI_IMAGE_AMOUNT+1));

    fota_ctrl->FOTA_NFB_LTP_Table       = FUE_Map_Table;
    fota_ctrl->FOTA_NFB_Area            = FUE_NFB_Area;
    
    fota_ctrl->NFB_Mapping_Block        = FUE_NFB_Mapping_Block;
    fota_ctrl->NFB_Session_Record       = FUE_NFB_Session_Record;
    fota_ctrl->NFB_Mapping_Session      = FUE_NFB_Mapping_Session;
    fota_ctrl->NFB_Mapping_Page         = FUE_NFB_Mapping_Page;
    fota_ctrl->NFB_Next_Available_Page  = FUE_NFB_Next_Available_Page;

    fota_ctrl->NFB_FUE_Info.m_update_alloc = FUE_Update_Alloc_info;
    fota_ctrl->NFB_FUE_Info.m_update_area  = FUE_Update_Image_area;
}

#endif /* _NAND_FLASH_BOOTING_ */

#endif /* __FUE__ */

#endif /* __FOTA_DM__ */

#endif /*__FOTA_ENABLE__*/

#endif
__TEMPLATE

   return $template;
}

#****************************************************************************
# subroutine:  generate custom_img_config.c content body
# return:      the body strings
#****************************************************************************
sub custom_img_config_c_file_body
{
    my $template = <<"__TEMPLATE";
#include "kal_non_specific_general_types.h"
#include "custom_fota.h"
#include "custom_img_config.h"
#include "SSF_ROMInfo_type.h"


#if !defined(__UBL__) && !defined(__FUE__)
#ifdef __MTK_TARGET__
#pragma arm section rodata = "MAUI_FOTA_HEAD_INFO"
#endif
const MTK_FOTA_ROM_Info_v1_ST IMG_FOTA_INFO =
{
   { "MTK_FOTA_ROMINFO_V01",
     0x6e659a9a },
   "N/A",
   "N/A",
   MTK_FOTA_ROMINFO_VERSION,
   FOTA_MAUI_IMAGE_AMOUNT,
   FOTA_MAUI_FLASH_SPACE,
   FOTA_PACKAGE_STORAGE_BASE,
   FOTA_PACKAGE_STORAGE_SIZE,
   FOTA_BACKUP_STORAGE_BASE,
   FOTA_BACKUP_STORAGE_SIZE,
   FOTA_EXTRA_RESERVED_BLOCKS,
   0x85
};

#ifdef __MTK_TARGET__
#pragma arm section rodata
#endif

/*************************************************************************
 * Global function definition
 *************************************************************************/
/*******************************************************************************/
kal_uint32 SSF_GetMAUIImageNumber(void)
{
   return IMG_FOTA_INFO.m_fota_image_number;
}
/*******************************************************************************/
kal_uint32 SSF_GetMAUIImageLength(kal_uint32 idx)
{
   return IMG_FOTA_INFO.m_fota_updatable_area[idx].m_image_load_size;
}
/*******************************************************************************/
kal_uint32 SSF_GetMAUIImageLoadAddr(kal_uint32 idx)
{
   return IMG_FOTA_INFO.m_fota_updatable_area[idx].m_image_base_address;
}

#endif /* !__UBL__ */

#if defined(__FUE__)

#ifdef __MTK_TARGET__
#pragma arm section rodata = "UA_HEAD"
#endif

STORAGE_QUALIFIER const MTK_UA_ROMInfo_Head_v1_ST IMG_UA_HEAD_INFO = 
{
   {"MTK_UA_ROMINFO_HEAD_V01",
    0xA7C8A3D2},
   "N/A",
   "N/A",
   MTK_UA_HEAD_ROMINFO_VERSION,
   {FOTA_UE_FLASH_BASE_ADDRESS, FOTA_UE_EXECUTION_BASE, FOTA_UE_RESIDENT_FLASH_SPACE_SIZE},
   0xF8
};
 
/*******************************************************************************/
kal_uint32 SSF_GetUpdateAgentAvailableSize(void)
{
   return IMG_UA_HEAD_INFO.m_ua_head_info.m_ua_max_length;
}

/*******************************************************************************/
extern const kal_uint32 FOTA_FUE_BACKUP_SPACE;
kal_uint32 SSF_GetUpdateAgentBackupSize(void)
{
   return FOTA_FUE_BACKUP_SPACE;
}

#endif /* __FUE__ */

#if defined(__UBL__)

#if  defined(__MTK_TARGET__)
extern kal_uint32 Image\$\$READ_ONLY\$\$Base;
#define BL_LOAD_BASE ((kal_uint32)&Image\$\$READ_ONLY\$\$Base)
#else
#define BL_LOAD_BASE 0
#endif

#ifdef __MTK_TARGET__
#pragma arm section rodata = "HEAD_BL"
#endif
STORAGE_QUALIFIER const MTK_BL_ROMInfo_v1_ST IMG_BL_INFO = 
{
   {"MTK_BOOT_LOADER_ROMINFO_V01",
    0
   },
   "N/A",
   "N/A",
   MTK_BL_ROMINFO_VERSION,
   BL_LOAD_BASE,
   FOTA_BL_IMG_MAX_SIZE,
   FOTA_BL_IMG_MAX_SIZE,
   0
};
#ifdef __MTK_TARGET__
#pragma arm section rodata
#endif
STORAGE_QUALIFIER MTK_UA_ROMInfo_Head_v1_ST IMG_UA_HEAD_INFO;
/*************************************************************************
 * Global function definition
 *************************************************************************/
/*******************************************************************************/
kal_uint32 SSF_GetBootloaderSize(void)
{
   return IMG_BL_INFO.m_bl_length;
}

/*******************************************************************************/
kal_uint32 SSF_GetBootloaderAreaSize(void)
{
   return IMG_BL_INFO.m_bl_max_length;
}
#endif /* __BL__ */
__TEMPLATE

   return $template;
}

#****************************************************************************
# subroutine:  error_handler
# input:       $error_msg:     error message
#****************************************************************************
sub error_handler
{
   my ($error_msg, $file, $line_no) = @_;
      
   my $final_error_msg = "SYSGEN ERROR: $error_msg at $file line $line_no\n";
   print $final_error_msg;
   die $final_error_msg;
}

#****************************************************************************
# subroutine:  description_file_header
# return:      file header -- description 
# input:       $filename:     filename
# input:       $description:  one line description
# input:       $author:       optional
#****************************************************************************
sub description_file_header
{
    my ($filename, $description, $author) = @_;
    my $template = <<"__TEMPLATE";
/*****************************************************************************
 *
 * Filename:
 * ---------
 *   $filename
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   $description
 *
 * Author:
 * -------
 *   $author
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * \$Revision\$
 * \$Modtime\$
 * \$Log\$
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

__TEMPLATE

   return $template;
}

#****************************************************************************
# subroutine:  copyright_file_header
# return:      file header -- copyright
#****************************************************************************
sub copyright_file_header
{
    my $template = <<"__TEMPLATE";
/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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

__TEMPLATE

   return $template;
}
