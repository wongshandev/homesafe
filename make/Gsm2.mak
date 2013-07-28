#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2005
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
# *************************************************************************
# GSM2.MAK  - GSM phase 2 master project build script
#
#  DISCUSSION:
#     CUSTOMER = MTK, PLUTO ...
#     PROJECT = L1S, GSM, GPRS
#
#  USAGE:
#     tools\make.exe -f[make file] [build_flag] <CUSTOMER> <PROJECT> <ACTION>
#
#     Example:
#     tools\make.exe -fmake\gsm2.mak -r -R CUSTOMER=mtk PROJECT=gprs new
#
#  IMPORTANT NOTES:
#
# *************************************************************************

# *************************************************************************
# Set SUFFIXES
# *************************************************************************
.SUFFIXES:
.SUFFIXES: .ptr .h .ltp

# *************************************************************************
# Set PHONY
# *************************************************************************
.PHONY : new cleanall emigen cmmgen asngen nvram_auto_gen codegen ptrgen asnregen update genlog cleanbin genverno gencustominfo gencustomlists cksysdrv cksysdrv_slim cksysdrv_clean resgen scan remake libs code_generate cleancodegen cleanmod done gen_bl_verno startbuildlibs bootloader fota gen_infolog mmi_feature_check operator_check mcp_check ckmake ckscatter ckscatter2 mmi_obj_check dummy_data_check removecode custpackini custpack copylintlog genlintstatlog xgc_all_libs echo_lib_lists echo_che_sss_lib_in_list echo_che_lib_in_list xgc_all_libs_2 echo_che_ssf_sss_lib_in_list echo_che_ssf_lib_in_list ck3rdptylic gendoc cci clean_codegen slim_codegen slim_mcddll slim_update crip ss_lcs_gen check_db ckmemcons backup findpad elfpatch xml_parser ximgen gen_modlibtbl

# *************************************************************************
# MediaTek is the default CUSTOMER.
# *************************************************************************

# *************************************************************************
# Common macro definitions
# *************************************************************************
#$(call Upper,$(1)) ...... reference $(1) in upper-case letters
Upper = $(subst z,Z,$(subst y,Y,$(subst x,X,$(subst w,W,$(subst v,V,$(subst u,U,$(subst t,T,$(subst s,S,$(subst r,R,$(subst q,Q,$(subst p,P,$(subst o,O,$(subst n,N,$(subst m,M,$(subst l,L,$(subst k,K,$(subst j,J,$(subst i,I,$(subst h,H,$(subst g,G,$(subst f,F,$(subst e,E,$(subst d,D,$(subst c,C,$(subst b,B,$(subst a,A,$(1)))))))))))))))))))))))))))

# -----------------------------
#  Include scripts
# -----------------------------
include make\option.mak            # Build option definitons
-include make\app_cfg.mak
-include make\internal_action.mak

NEED_TRANS_CLASSB = FALSE
ifeq ($(call Upper,$(strip $(PROJECT))),L1S)
  ifeq ($(strip $(L1_GPRS)),TRUE)
      NEED_TRANS_CLASSB = TRUE
  endif
else
  ifeq ($(call Upper,$(strip $(PROJECT))),GPRS)
      NEED_TRANS_CLASSB = TRUE
  endif
endif

NEED_TRANS_UMTS = FALSE
ifneq ($(filter UMTS HSPA,$(strip $(call Upper,$(PROJECT)))),)
   NEED_TRANS_UMTS = TRUE
endif
	
-include make\~cleanmod.tmp      # Define clean modules
ifndef DO_CLEAN_MODULE
   # Default clean all
	DO_CLEAN_MODULE   =  FALSE
	CLEAN_MODS        =
else

  ifneq ($(filter L1,$(call Upper,$(CLEAN_MODS))),)
		NEED_CLEAN_CGENLST	=  TRUE
  else
		NEED_CLEAN_CGENLST	=  FALSE
  endif

   # Do component module name parsing according to different project combination
   # For example, in classb solution, l1 -> l1_classb instead l1,
   # but l1_classb should be accepted, too.

  ifeq ($(NEED_TRANS_CLASSB),TRUE)
    CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out l1,$(comp)),$(comp),$(comp)_classb))
    CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out rr,$(comp)),$(comp),$(comp)_classb))
    CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out mm,$(comp)),$(comp),$(comp)_classb))
    CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out l4,$(comp)),$(comp),$(comp)_classb))
    CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out peer,$(comp)),$(comp),$(comp)_classb))
    CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out interface,$(comp)),$(comp),$(comp)_classb))
    ifneq ($(strip $(L1_WCDMA)),TRUE)
      CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out l1_classb,$(comp)),$(comp),l1_classb_g2))
      CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out rr_classb,$(comp)),$(comp),rr_classb2))
      CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out mm_classb,$(comp)),$(comp),mm_classb2))
    endif
  else
    ifeq ($(NEED_TRANS_UMTS),FALSE)
      ifneq ($(strip $(L1_WCDMA)),TRUE)
        CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out l1,$(comp)),$(comp),$(comp)_g2))
        CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out rr,$(comp)),$(comp),$(comp)2))
        CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out mm,$(comp)),$(comp),$(comp)2))
      endif
    endif
  endif

  ifeq ($(NEED_TRANS_UMTS),TRUE)
    CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out l1,$(comp)),$(comp),l1_classb_umts))
    CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out rr,$(comp)),$(comp),rr_classb_umts))
    CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out mm,$(comp)),$(comp),mm_classb_umts))
    CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out l1_classb,$(comp)),$(comp),l1_classb_umts))
    CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out rr_classb,$(comp)),$(comp),rr_classb_umts))
    CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out mm_classb,$(comp)),$(comp),mm_classb_umts))
    CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out l4,$(comp)),$(comp),l4_classb))
    CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out peer,$(comp)),$(comp),peer_classb))
    CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out interface,$(comp)),$(comp),interface_classb))
  endif

ifdef SIM_NEW_ARCH
  ifeq ($(strip $(SIM_NEW_ARCH)),TRUE)
    CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out sim,$(comp)),$(comp),$(comp)2))
  endif
endif

#$(warning CLEAN_MODS = $(CLEAN_MODS))
endif


-include make\~updatemod.tmp     # Define update modules
ifndef DO_UPDATE_MODULE
   # Default update all
	DO_UPDATE_MODULE  =  FALSE
	UPDATE_MODS       =
	RUN_RESGEN			=  TRUE
else

	RUN_RESGEN			=  FALSE

  ifneq ($(filter MMIRESOURCE,$(call Upper,$(UPDATE_MODS))),)
		RUN_RESGEN			=  TRUE
  endif
  ifneq ($(filter LCMMIRESOURCE,$(call Upper,$(UPDATE_MODS))),)
		RUN_RESGEN			=  TRUE
  endif  

endif

# reset RUN_RESGEN if $(PROJECT) == BASIC || L1S
ifeq ($(strip $(call Upper,$(PROJECT))),BASIC)
	RUN_RESGEN			=  FALSE
endif

ifeq ($(strip $(call Upper,$(RELEASE_PACKAGE))),REL_SUB_UAS_UMTS)
	RUN_RESGEN			=  FALSE
	REDUCE_PLUTO_HEADER_DEPTH  := FALSE	
endif

ifeq ($(strip $(call Upper,$(PROJECT))),L1S)
	RUN_RESGEN			=  FALSE
endif

ifeq ($(strip $(call Upper,$(PROJECT))),MEUT)
	RUN_RESGEN			=  FALSE
endif

ifneq ($(findstring MODEM,$(CUSTOMER)),)
	RUN_RESGEN			=  FALSE
endif

ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
	RUN_RESGEN			=  FALSE
endif

ifeq ($(strip $(MMI_VERSION)),WISDOM_MMI)
	RUN_RESGEN			=  FALSE
endif

#$(warning RUN_RESGEN: $(RUN_RESGEN))

-include make\~remakemod.tmp     # Define remake modules
ifndef DO_REMAKE_MODULE
   # Default remake all
	DO_REMAKE_MODULE  =  FALSE
	REMAKE_MODS       =
endif


-include make\~scanmod.tmp     # Define scan modules
ifndef DO_SCAN_MODULE
   # Default scan all
	DO_SCAN_MODULE  =  FALSE
	SCAN_MODS       =
endif
-include make\~gendocmod.tmp     # Define gendoc modules
ifndef DO_GENDOC_MODULE
   # Default gendoc all
	DO_GENDOC_MODULE  =  FALSE
	GENDOC_MODS       =
endif

-include make\Custom.bld         # Custom release build
ifndef CUSTOM_RELEASE
   # Default custom release
	CUSTOM_RELEASE  =  FALSE
endif

CODE_GEN_SRCS =

ifndef EXT_CAM_MODULE
	EXT_CAM_MODULE = NONE
endif

ifndef CMOS_SENSOR
	CMOS_SENSOR = NONE
endif

ifdef COMPILER
   ifeq ($(strip $(COMPILER)),RVCT)
      VIA = --via
   endif
   ifeq ($(strip $(COMPILER)),ADS)
      VIA = -via
   endif
endif

ifdef COMPILER
   ifeq ($(strip $(COMPILER)),RVCT)
      DEPEND = --depend
   endif
   ifeq ($(strip $(COMPILER)),ADS)
      DEPEND = -depend
   endif
endif

# default is ADS compiler
ifndef COMPILER
   COMPILER = ADS
   VIA = -via
endif

# default mbis tempfile
ifndef MBIS_BUILD_TIME_TMP
   MBIS_BUILD_TIME_TMP = tmp
endif
ifndef MBIS_BUILD_INFO_LOG
   MBIS_BUILD_INFO_LOG = tmp
endif   

# default codegen 
ifndef USE_CODEGEN_CFG
   USE_CODEGEN_CFG = TRUE
endif

ifndef FLAVOR
   FLAVOR = NONE
endif

ifneq ($(strip $(FLAVOR)),NONE)
   PROJECT_NAME = $(strip $(CUSTOMER))($(strip $(FLAVOR)))_$(strip $(PROJECT))
else
   PROJECT_NAME = $(strip $(CUSTOMER))_$(strip $(PROJECT))
endif

#########################################################
# Replace alias modules. (for update/remake/scan/clean)
#########################################################
ifdef UPDATE_MODS
UPDATE_MODS_TEMP = $(foreach mod,$(call Upper,$(UPDATE_MODS)), \
  $(if $(filter $($(mod)),TRUE),$($(mod)_CHILD),$(call lc,$(mod))))
endif
UPDATE_MODS := $(strip $(UPDATE_MODS_TEMP))

ifdef REMAKE_MODS
REMAKE_MODS_TEMP = $(foreach mod,$(call Upper,$(REMAKE_MODS)), \
  $(if $(filter $($(mod)),TRUE),$($(mod)_CHILD),$(call lc,$(mod))))
endif
REMAKE_MODS := $(REMAKE_MODS_TEMP)

ifdef SCAN_MODS
SCAN_MODS_TEMP = $(foreach mod,$(call Upper,$(SCAN_MODS)), \
  $(if $(filter $($(mod)),TRUE),$($(mod)_CHILD),$(call lc,$(mod))))
endif
SCAN_MODS := $(SCAN_MODS_TEMP)

ifdef CLEAN_MODS
CLEAN_MODS_TEMP = $(foreach mod,$(call Upper,$(CLEAN_MODS)), \
  $(if $(filter $($(mod)),TRUE),$($(mod)_CHILD),$(call lc,$(mod))))
endif
CLEAN_MODS := $(CLEAN_MODS_TEMP)

####################################################################
# End of alias build settings.
####################################################################

# *************************************************************************
# Build path, directories
# *************************************************************************
# Do not support new mmi feature file architecture
OPTR_WARNING_DEF = $(strip $(FIXPATH))\operator\$(strip $(word 1,$(subst _, ,$(OPTR_SPEC))))\$(strip $(word 2,$(subst _, ,$(OPTR_SPEC))))\plutommi\operator_checklist.txt
PURE_VERNO = $(subst .,_, $(subst $(call Upper,$(strip $(CUSTOMER))).,, $(subst MAUI_SW.,, $(subst MAUI_SW.CLASSB.,, $(call Upper,$(VERNO))))))
FOTA_PURE_VERNO = $(subst .,_, $(subst $(call Upper,$(strip $(CUSTOMER))).,, $(subst MAUI.,, $(subst MAUI_SW.,, $(subst MAUI_SW.CLASSB.,, $(call Upper,$(VERNO)))))))
NEWTARGNAME    =  $(strip $(TARGNAME)).$(strip $(PURE_VERNO))
BPLGUINFOCUSTOMSRCP = BPLGUInfoCustomAppSrcP_$(strip $(PLATFORM))_$(strip $(CHIP_VER))_$(strip $(PURE_VERNO))
MMI_FEATURES_FILE = $(FIXPATH)\$(MMIDIR)\MMI\Inc\MMI_features.h
MMI_FEATURES_SWITCH_FILE = $(FIXPATH)\$(MMIDIR)\MMI\Inc\MMI_features_switch.h

ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
  ifdef SWITCHABLE_FEATURE
    ifneq ($(strip $(SWITCHABLE_FEATURE)),NONE)
      ifdef SWITCHABLE_FEATURE_2ND
        ifneq ($(strip $(SWITCHABLE_FEATURE_2ND)),NONE)
          ifeq ($(strip $(ENABLE_PARTIAL_TRACE)),TRUE)
            COPY_DB := $(shell copy /y $(TST_DB)\$(strip $(SWITCHABLE_FEATURE))\NONE\$(strip $(SWITCHABLE_FEATURE_2ND))\$(strip $($(strip $(SWITCHABLE_FEATURE_2ND))))\*.* $(TST_DB)\)
          else
            COPY_DB := $(shell copy /y $(TST_DB)\$(strip $(SWITCHABLE_FEATURE))\$(strip $($(strip $(SWITCHABLE_FEATURE))))\$(strip $(SWITCHABLE_FEATURE_2ND))\$(strip $($(strip $(SWITCHABLE_FEATURE_2ND))))\*.* $(TST_DB)\)
          endif
          ifneq ($(filter tst ,$(strip $(COMPLIST))),)
            ifeq ($(strip $(ENABLE_PARTIAL_TRACE)),TRUE)
              COPY_TRCMOD := $(shell copy /y tst\src\$(strip $(SWITCHABLE_FEATURE))\NONE\$(strip $(SWITCHABLE_FEATURE_2ND))\$(strip $($(strip $(SWITCHABLE_FEATURE_2ND))))\*.* tst\src\)
              COPY_TRCMOD := $(shell copy /y tst\include\$(strip $(SWITCHABLE_FEATURE))\NONE\$(strip $(SWITCHABLE_FEATURE_2ND))\$(strip $($(strip $(SWITCHABLE_FEATURE_2ND))))\*.* tst\include\)
            else
              COPY_TRCMOD := $(shell copy /y tst\src\$(strip $(SWITCHABLE_FEATURE))\$(strip $($(strip $(SWITCHABLE_FEATURE))))\$(strip $(SWITCHABLE_FEATURE_2ND))\$(strip $($(strip $(SWITCHABLE_FEATURE_2ND))))\*.* tst\src\)
              COPY_TRCMOD := $(shell copy /y tst\include\$(strip $(SWITCHABLE_FEATURE))\$(strip $($(strip $(SWITCHABLE_FEATURE))))\$(strip $(SWITCHABLE_FEATURE_2ND))\$(strip $($(strip $(SWITCHABLE_FEATURE_2ND))))\*.* tst\include\)
            endif
          endif
        else
          ifeq ($(strip $(ENABLE_PARTIAL_TRACE)),TRUE)
            COPY_DB := $(shell copy /y $(TST_DB)\$(strip $(SWITCHABLE_FEATURE))\NONE\*.* $(TST_DB)\)
          else
            COPY_DB := $(shell copy /y $(TST_DB)\$(strip $(SWITCHABLE_FEATURE))\$(strip $($(strip $(SWITCHABLE_FEATURE))))\*.* $(TST_DB)\)
          endif
          ifneq ($(filter tst ,$(strip $(COMPLIST))),)
            ifeq ($(strip $(ENABLE_PARTIAL_TRACE)),TRUE)
              COPY_TRCMOD := $(shell copy /y tst\src\$(strip $(SWITCHABLE_FEATURE))\NONE\*.* tst\src\)
              COPY_TRCMOD := $(shell copy /y tst\include\$(strip $(SWITCHABLE_FEATURE))\NONE\*.* tst\include\)
            else
              COPY_TRCMOD := $(shell copy /y tst\src\$(strip $(SWITCHABLE_FEATURE))\$(strip $($(strip $(SWITCHABLE_FEATURE))))\*.* tst\src\)
              COPY_TRCMOD := $(shell copy /y tst\include\$(strip $(SWITCHABLE_FEATURE))\$(strip $($(strip $(SWITCHABLE_FEATURE))))\*.* tst\include\)
            endif
          endif
        endif
      else
        ifeq ($(strip $(ENABLE_PARTIAL_TRACE)),TRUE)
          COPY_DB := $(shell copy /y $(TST_DB)\$(strip $(SWITCHABLE_FEATURE))\NONE\*.* $(TST_DB)\)
        else
          COPY_DB := $(shell copy /y $(TST_DB)\$(strip $(SWITCHABLE_FEATURE))\$(strip $($(strip $(SWITCHABLE_FEATURE))))\*.* $(TST_DB)\)
        endif  
        ifneq ($(filter tst ,$(strip $(COMPLIST))),)
          ifeq ($(strip $(ENABLE_PARTIAL_TRACE)),TRUE)
            COPY_TRCMOD := $(shell copy /y tst\src\$(strip $(SWITCHABLE_FEATURE))\NONE\*.* tst\src\)
            COPY_TRCMOD := $(shell copy /y tst\include\$(strip $(SWITCHABLE_FEATURE))\NONE\*.* tst\include\)
          else
            COPY_TRCMOD := $(shell copy /y tst\src\$(strip $(SWITCHABLE_FEATURE))\$(strip $($(strip $(SWITCHABLE_FEATURE))))\*.* tst\src\)
            COPY_TRCMOD := $(shell copy /y tst\include\$(strip $(SWITCHABLE_FEATURE))\$(strip $($(strip $(SWITCHABLE_FEATURE))))\*.* tst\include\)
          endif
        endif
      endif
    endif
  endif
  BPLGUINFOCUSTOM = $(shell dir $(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOMPREFIX))* /b)
else
   BPLGUINFOCUSTOM = $(BPLGUINFOCUSTOMPREFIX)_$(strip $(PURE_VERNO))
endif

PLATFORM_LIB   =

MCD_SCANDEFS   = $(foreach def, $(MCD_DEFS),-D$(def))

COM_SCANDEFS   = $(foreach def, $(COM_DEFS),-define $(def))

COM_SCANDEFS_NEW  = $(foreach def, $(COM_DEFS),-D$(def))

# .log
LOGDIR         =  $(strip $(TARGDIR))

# version no dir
VERNODIR       =  $(strip $(FIXPATH))\verno

# summary log
LOG            =  $(strip $(LOGDIR))\$(strip $(PLATFORM)).log
BOOTLOADER_LOG =  $(strip $(LOGDIR))\bootloader.log
FOTA_LOG       =  $(strip $(LOGDIR))\fota.log
LNKERRORLOG    =  $(strip $(LOGDIR))\$(strip $(PLATFORM))_error.log

# Component's log file
COMPLOGDIR     =  $(strip $(TARGDIR))\log

COMPLINTLOGDIR     =  $(strip $(TARGDIR))\lint_log

INFOLOG        =  $(strip $(COMPLOGDIR))\info.log
MMI_FEATURES_LOG   =  $(strip $(COMPLOGDIR))\MMI_features.log
INFOMAKELOG        =  $(strip $(COMPLOGDIR))\infomake.log
CODE_GEN_LOG   =  $(strip $(COMPLOGDIR))\codegen.log
MCDDLL_UPDATE_LOG = $(strip $(COMPLOGDIR))\mcddll_update.log
DB_CHECK_LOG   =  $(strip $(COMPLOGDIR))\db_check.log

# L1 database
L1_DB_COMM     =  $(strip $(FIXPATH))\l1\common

# Cgen
CGEN           =  $(strip $(FIXPATH))\tools\Cgen.exe
DB_CHECK       =  $(strip $(FIXPATH))\tools\basic_db_check.exe
CGEN_CFG_FILE  =  $(strip $(FIXPATH))\cgen.cfg

# Catbin
CATBIN         =  $(strip $(FIXPATH))\tools\catbin.exe

ifeq ($(CUSTOM_RELEASE),FALSE)
	TMD_FILES         = $(L1_TMD_FILES)
	TST_GEN_DEP_SRCS  = $(strip $(TSTDIR))\database\msglog_db\parse_db.c
	TST_GEN_DEP_OUTS  = $(strip $(TST_DB))\msglog_db\pri.db
	PTR_GEN_OUTS  		= $(patsubst %.h,%.ptr, $(notdir $(subst \,/,$(COMP_TRACE_DEFS))))
	SINGLE_PTR        = codegen_single.ptr
	SINGLE_HEADER     = codegen_single.h
	TST_GEN_DEP_STP3_SRCS  	= $(strip $(TST_DB))\msglog_db\BInfo
	TST_GEN_DEP_STP3_OUTS  	= $(strip $(TST_DB))\pstrace_db\BPInfo

else
	TMD_FILES         		=
	TST_GEN_DEP_SRCS  		= $(strip $(TSTDIR))\database\msglog_db\custom_parse_db.c
	TST_GEN_DEP_OUTS  		= $(strip $(TST_DB))\BPLGUInfoCustomAppSrc
	COMP_TRACE_DEFS			= $(EXISTED_CUS_REL_TRACE_DEFS)
	COMP_TRACE_DEFS			+= $(NEW_CUS_REL_TRACE_DEFS)
	PTR_GEN_OUTS  				= $(patsubst %.h,%.ptr, $(notdir $(subst \,/,$(COMP_TRACE_DEFS))))
	SINGLE_PTR            = codegen_single.ptr	
	SINGLE_HEADER         = codegen_single.h
ifeq ($(strip $(USE_CODEGEN_CFG)),TRUE)		
	TST_GEN_DEP_STP3_SRCS  	= $(strip $(TST_DB))\BPLGUInfoCustomAppSrc $(strip $(TST_DB))\pstrace_db\$(SINGLE_PTR)
else
	TST_GEN_DEP_STP3_SRCS  	= $(strip $(TST_DB))\BPLGUInfoCustomAppSrc $(PTR_GEN_OUTS)
endif
	TST_GEN_DEP_STP3_OUTS  	= $(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOMSRCP))

endif

# Concat module's local preprocessor definition
COMPDEFS          = __NULL_DEF__
COMPDEFS += $(foreach COMP,$(COMPLIST),$(shell type make\$(COMP)\$(COMP).def))
#$(warning [$(COMPDEFS)])

# -----------------------------
# Macros definition
# -----------------------------
PURELNKOPT     = $(strip $(LNKOPT))

ifeq ($(strip $(COMPILER)),RVCT)
  LNKOPT += --largeregions --scatter $(SCATTERFILE) --output $(strip $(TARGDIR))\$(TARGNAME).elf \
            --symdefs $(strip $(TARGDIR))\$(TARGNAME).sym \
            --list $(strip $(TARGDIR))\$(TARGNAME).lis \
            --libpath $(DIR_ARMLIB)
  LNKOPT += --keep EMI_INFO_2
  LNKOPT += --keep CUST_MEM_INFO

  LNKOPT += --keep g_bl_maui_paired_ver

ifeq ($(strip $(USB_DOWNLOAD)),SECURE)
  LNKOPT += --keep g_DummyKeep_Data
endif

ifeq ($(strip $(SECURE_SUPPORT)),TRUE)
  LNKOPT += --keep g_secinfo_tail \
            --keep g_SEC_RO \
            --keep g_FlashToolCfg \
            --keep g_SecureMAC_Size \
            --keep g_SecureMAC
endif

ifeq ($(strip $(CUST_PARA_SUPPORT)),TRUE)
  LNKOPT       += --keep g_CustParaCfg \
                  --keep g_CustParaCfg_Tail
endif

ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
  LNKOPT       += --keep g_enfb_3rdrom_header
endif

ifeq ($(strip $(MULTIPLE_BINARY_FILES)),TRUE)
  CUSTPACK_LNKOPT = --map --info sizes,totals --symbols --xref --libpath $(DIR_ARMLIB) --remove
  CUSTPACK_LNKOPT += --keep mtk_theme_header
  LNKOPT += --keep IMG_FOTA_INFO
endif

ifeq ($(strip $(SECURE_SUPPORT)),TRUE)
  BTLD_LNKOPT += --keep g_BlSecInfo \
                 --keep g_BlSecureMAC \
                 --keep g_BlSecureMAC_Size
  ifeq ($(strip $(USB_DOWNLOAD)),SECURE)
    BTLD_LNKOPT += --keep g_BlFunc_Table
  endif
  ifeq ($(strip $(FOTA_ENABLE)),FOTA_DM)
    LNKOPT += --keep g_DummyKeep_Data
    FOTA_LNKOPT += --keep g_fota_secinfo
  endif
endif

ifeq ($(strip $(FOTA_ENABLE)),FOTA_DM)
  LNKOPT += --keep IMG_FOTA_INFO
  BTLD_LNKOPT += --keep IMG_BL_INFO
  FOTA_LNKOPT += --keep IMG_UA_HEAD_INFO
endif

endif

ifeq ($(strip $(COMPILER)),ADS)
  LNKOPT += -scatter $(SCATTERFILE) -output $(strip $(TARGDIR))\$(TARGNAME).elf \
            -symdefs $(strip $(TARGDIR))\$(TARGNAME).sym \
            -list $(strip $(TARGDIR))\$(TARGNAME).lis \
            -libpath $(DIR_ARMLIB)
  LNKOPT += -keep EMI_INFO_2
  LNKOPT += -keep CUST_MEM_INFO

  LNKOPT += -keep g_bl_maui_paired_ver

ifeq ($(strip $(USB_DOWNLOAD)),SECURE)
  LNKOPT += -keep g_DummyKeep_Data
endif

ifeq ($(strip $(SECURE_SUPPORT)),TRUE)
  LNKOPT  += -keep g_secinfo_tail \
             -keep g_SEC_RO \
             -keep g_FlashToolCfg \
             -keep g_SecureMAC_Size \
             -keep g_SecureMAC \
             -keep g_secinfo
endif

ifeq ($(strip $(CUST_PARA_SUPPORT)),TRUE)
  LNKOPT       += -keep g_CustParaCfg \
                  -keep g_CustParaCfg_Tail
endif

ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
  LNKOPT       += -keep g_enfb_3rdrom_header
endif

ifeq ($(strip $(MULTIPLE_BINARY_FILES)),TRUE)
#  CUSTPACK_LNKOPT = -remove -map -info sizes,totals,unused -symbols -xref -libpath $(DIR_ARMLIB) 
   CUSTPACK_LNKOPT = -map -info sizes,totals -symbols -xref -remove -libpath $(DIR_ARMLIB) 
   CUSTPACK_LNKOPT += -keep mtk_theme_header
endif

ifeq ($(strip $(SECURE_SUPPORT)),TRUE)
  BTLD_LNKOPT += -keep g_BlSecInfo \
                 -keep g_BlSecureMAC \
                 -keep g_BlSecureMAC_Size
  ifeq ($(strip $(USB_DOWNLOAD)),SECURE)
    BTLD_LNKOPT += -keep g_BlFunc_Table
  endif
  ifeq ($(strip $(FOTA_ENABLE)),FOTA_DM)
    LNKOPT += -keep g_DummyKeep_Data
    FOTA_LNKOPT += -keep g_fota_secinfo
  endif
endif

ifeq ($(strip $(FOTA_ENABLE)),FOTA_DM)
  LNKOPT += -keep IMG_FOTA_INFO
  BTLD_LNKOPT += -keep IMG_BL_INFO
  FOTA_LNKOPT += -keep IMG_UA_HEAD_INFO
endif

endif


# *************************************************************************
#  Target Definitions
# *************************************************************************

ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)

  ifneq ($(filter init,$(COMPLIST)),)
		INITLIB        =  $(strip $(COMPLIBDIR))\init.lib
  else
		INITLIB        =  $(CUS_MTK_LIB)\init.lib
  endif

  ifneq ($(filter UMTS HSPA,$(strip $(call Upper,$(PROJECT)))),)

    ifeq ($(strip $(call Upper,$(L1_3GSOLUTION))),MTK_UL1_FDD)
      ifneq ($(filter init,$(COMPLIST)),)
		    INITLIB        =  $(strip $(COMPLIBDIR))\init.lib
      else
		    INITLIB        =  $(CUS_MTK_LIB)\init.lib
      endif
    else
      ifneq ($(filter init_ma,$(COMPLIST)),)
		    INITLIB        =  $(strip $(COMPLIBDIR))\init_ma.lib
      else
		    INITLIB        =  $(CUS_MTK_LIB)\init_ma.lib
      endif
    endif

  endif

ifeq ($(strip $(ENABLE_PARTIAL_TRACE)),TRUE)
  MTK_LIBS =  $(foreach COMP,$(filter-out $(PARTIAL_TRACE_LIB),$(CUS_REL_HDR_COMP)),$(CUS_MTK_LIB)\$(COMP).lib)
  MTK_LIBS += $(foreach COMP,$(filter-out $(PARTIAL_TRACE_LIB),$(CUS_REL_MTK_COMP)),$(CUS_MTK_LIB)\$(COMP).lib)
  MTK_LIBS += $(foreach COMP,$(filter $(PARTIAL_TRACE_LIB),$(CUS_REL_HDR_COMP)),$(CUS_MTK_LIB_TRACE)\$(COMP).lib)
  MTK_LIBS += $(foreach COMP,$(filter $(PARTIAL_TRACE_LIB),$(CUS_REL_MTK_COMP)),$(CUS_MTK_LIB_TRACE)\$(COMP).lib)
else
  MTK_LIBS =  $(foreach COMP,$(CUS_REL_HDR_COMP),$(CUS_MTK_LIB)\$(COMP).lib)
  MTK_LIBS += $(foreach COMP,$(CUS_REL_MTK_COMP),$(CUS_MTK_LIB)\$(COMP).lib)
endif

else

  ifneq ($(filter init,$(COMPLIST)),)
	  INITLIB        =  $(strip $(COMPLIBDIR))\init.lib
  endif
  ifneq ($(filter init_ma,$(COMPLIST)),)
	  INITLIB        =  $(strip $(COMPLIBDIR))\init_ma.lib
  endif
	MTK_LIBS       =

endif



ifeq ($(call Upper,$(PROJECT)),L1S)
  ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
    CODEGEN_RESULT = $(strip $(TST_DB))\l1validation_db\BPLVInfo
  endif
else

  ifeq ($(strip $(SPLIT_SYSTEM)),TRUE)
  	CODEGEN_RESULT = $(strip $(TST_DB))\BPLGUSplitInfo
  else

    ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
      CODEGEN_RESULT = $(strip $(TST_GEN_DEP_STP3_OUTS))		# used to control which steps will be available in custom release
    else
      CODEGEN_RESULT = $(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOM))
    endif
  endif
endif


ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
  ifneq ($(call Upper,$(strip $(PROJECT))),BASIC)
    NEED_RM_TSTDB = TRUE
  endif
else
  ifneq ($(call Upper,$(strip $(PROJECT))),MEUT)
    NEED_RM_TSTDB = TRUE
  else
    NEED_RM_TSTDB = FALSE
  endif
endif

ifeq ($(strip $(call Upper,$(LEVEL))),VENDOR)
  NEED_RM_TSTDB = FALSE
endif

L1TRACE_DB_DIR  =  $(strip $(TST_DB))\l1trace_db
L1VAL_DB_DIR    =  $(strip $(TST_DB))\l1validation_db
L1VAL_DB_PARSE_DIR    =  $(strip $(TST_DB))\l1validation_db\l1v_db
PSTRACE_DB_DIR  =  $(strip $(TST_DB))\pstrace_db
GV_DB_DIR       =  $(strip $(TST_DB))\gv
GV_DB_PARSE_DIR       =  $(strip $(TST_DB))\gv\gv_db
MMI_SCR_ID_FILE = make\~mmi_scr_id.c
MMI_SCR_ID_DB = make\~mmi_scr_id.db

TMD_GEN_C_H_FILES = $(foreach tmd_file,$(TMD_FILES), $(basename $(tmd_file)).c $(strip $(TSTDIR))\include\$(notdir $(basename $(tmd_file)).h))

GV_FILES			 = $(shell dir $(strip $(TST_DB))\gv\*.gv /s/b)
#$(error [$(GV_FILES)])

ifeq ($(call Upper,$(PROJECT)),L1S)
	L1V_FILES	 = $(shell dir $(strip $(TST_DB))\l1validation_db\*.l1v /s/b)
#$(error [$(L1V_FILES)])
endif


ifeq ($(strip $(DO_UPDATE_MODULE)),TRUE)
  ifeq ($(filter verno,$(UPDATE_MODS)),)
    UPDATE_MODS := $(UPDATE_MODS) verno
  endif
  COMPLIBLIST = $(foreach comp,$(UPDATE_MODS),$(comp).lib)
else
  ifeq ($(strip $(DO_REMAKE_MODULE)),TRUE)
    ifeq ($(filter verno,$(REMAKE_MODS)),)
      REMAKE_MODS := $(REMAKE_MODS) verno
    endif
    COMPLIBLIST = $(foreach comp,$(REMAKE_MODS),$(comp).lib)
  else
    COMPLIBLIST = $(call sort,$(foreach comp,$(COMPLIST),$(comp).lib))
  endif
endif

ifeq ($(strip $(DO_UPDATE_MODULE)),TRUE)
  COMPSCANLIST = $(UPDATE_MODS)
else
  ifeq ($(strip $(DO_SCAN_MODULE)),TRUE)
#    ifeq ($(filter verno,$(SCAN_MODS)),)
#      SCAN_MODS := $(SCAN_MODS) verno
#    endif
    COMPSCANLIST = $(SCAN_MODS)
  else
   COMPSCANLIST = $(COMPLIST)
  endif
endif

# either drmadp.lib or custom.lib will run custominfo.pl
# but some project may not have to compile drmadp.lib, so put drmadp.lib first
ifneq ($(filter drmadp.lib,$(COMPLIBLIST)),)
	CUSTOM_EXIST   =  TRUE
else
	CUSTOM_EXIST   =  FALSE
endif

ifneq ($(filter custom.lib,$(COMPLIBLIST)),)
	CUSTOM_EXIST   =  TRUE
else
  ifneq ($(filter ecompass.lib image_sensor_sec.lib obigo03cpushadp.lib obigo03cpushlib.lib lgoem.lib wise.lib,$(COMPLIBLIST)),)
    CUSTOM_EXIST   =  TRUE
  else
    CUSTOM_EXIST   =  FALSE
  endif
endif

# Do component module name parsing according to different project combination
# For example, in classb solution, l1 -> l1_classb instead l1,
# but l1_classb should be accepted, too.
ifeq ($(NEED_TRANS_CLASSB),TRUE)
  COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out l1.lib,$(comp)),$(comp),l1_classb.lib))
  COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out rr.lib,$(comp)),$(comp),rr_classb.lib))
  COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out mm.lib,$(comp)),$(comp),mm_classb.lib))
  COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out l4.lib,$(comp)),$(comp),l4_classb.lib))
  COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out peer.lib,$(comp)),$(comp),peer_classb.lib))
  COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out interface.lib,$(comp)),$(comp),interface_classb.lib))
  ifneq ($(strip $(L1_WCDMA)),TRUE)
    COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out l1_classb.lib,$(comp)),$(comp),l1_classb_g2.lib))
    COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out rr_classb.lib,$(comp)),$(comp),rr_classb2.lib))
    COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out mm_classb.lib,$(comp)),$(comp),mm_classb2.lib))
  endif
else
  ifeq ($(NEED_TRANS_UMTS),FALSE)
    ifneq ($(strip $(L1_WCDMA)),TRUE)
      COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out l1.lib,$(comp)),$(comp),l1_g2.lib))
      COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out rr.lib,$(comp)),$(comp),rr2.lib))
      COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out mm.lib,$(comp)),$(comp),mm2.lib))
    endif
  endif
endif

ifeq ($(NEED_TRANS_UMTS),TRUE)
  COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out l1.lib,$(comp)),$(comp),l1_classb_umts.lib))
  COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out rr.lib,$(comp)),$(comp),rr_classb_umts.lib))
  COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out mm.lib,$(comp)),$(comp),mm_classb_umts.lib))
  COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out l1_classb.lib,$(comp)),$(comp),l1_classb_umts.lib))
  COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out rr_classb.lib,$(comp)),$(comp),rr_classb_umts.lib))
  COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out mm_classb.lib,$(comp)),$(comp),mm_classb_umts.lib))
  COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out l4.lib,$(comp)),$(comp),l4_classb.lib))
  COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out peer.lib,$(comp)),$(comp),peer_classb.lib))
  COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out interface.lib,$(comp)),$(comp),interface_classb.lib))
endif

ifdef SIM_NEW_ARCH
  ifeq ($(strip $(SIM_NEW_ARCH)),TRUE)
    COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out sim.lib,$(comp)),$(comp),sim2.lib))
  endif
endif

LINT_COMP_LIST =  $(subst .lib,.ltp,$(COMPLIBLIST))

#$(warning COMPLIBLIST = $(COMPLIBLIST))

ifneq ($(strip $(call Upper,$(REMAKE_MODS))),BOOTLOADER)
ifneq ($(strip $(call Upper,$(REMAKE_MODS))),FOTA)
   CHK_COMPLIST = $(filter-out $(foreach comp,$(COMPLIST),$(comp).lib),$(COMPLIBLIST))
   ifneq ($(words $(CHK_COMPLIST)),0)
      ifneq ($(strip $(LINT)),TRUE)
         ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
            ifeq ($(strip $(PARTIAL_COPY)),TRUE)
               $(error $(foreach comp,$(CHK_COMPLIST),"$(comp)") NOT in PC_SRC_COMP of pc_cfg.ini when Partial Copy)
            else
               $(error $(foreach comp,$(CHK_COMPLIST),"$(comp)") NOT in CUS_REL_SRC_COMP or NOT in CUS_REL_PAR_SRC_COMP)
            endif
         else
            $(error $(foreach comp,$(CHK_COMPLIST),"$(comp)") NOT in COMPLIST)
         endif
      else
         REMOVELINTCOMP = $(subst .lib,.ltp,$(CHK_COMPLIST))
         LINT_COMP_LIST := $(filter-out $(REMOVELINTCOMP),$(LINT_COMP_LIST))
      endif
   endif
endif
endif

LINTLOGFILE=$(subst .ltp,.log,$(LINT_COMP_LIST))

ifdef COMPLIST
COM_DEF_PATH = $(foreach mod,$(COMPLIST),$(strip $(TARGDIR))\module\$(mod)\$(mod).def))
endif

# Do component module name parsing according to different project combination
# For example, in classb solution, l1 -> l1_classb instead l1,
# but l1_classb should be accepted, too.
ifeq ($(NEED_TRANS_CLASSB),TRUE)
	COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out l1,$(comp)),$(comp),$(comp)_classb))
	COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out rr,$(comp)),$(comp),$(comp)_classb))
	COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out mm,$(comp)),$(comp),$(comp)_classb))
	COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out l4,$(comp)),$(comp),$(comp)_classb))
	COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out peer,$(comp)),$(comp),$(comp)_classb))
	COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out interface,$(comp)),$(comp),$(comp)_classb))
endif
#$(warning COMPSCANLIST = $(COMPSCANLIST))
ifeq ($(NEED_TRANS_UMTS),TRUE)
	COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out l1,$(comp)),$(comp),$(comp)_classb_umts))
	COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out rr,$(comp)),$(comp),$(comp)_classb_umts))
	COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out mm,$(comp)),$(comp),$(comp)_classb_umts))
	COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out l1_classb,$(comp)),$(comp),$(comp)_umts))
	COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out rr_classb,$(comp)),$(comp),$(comp)_umts))
	COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out mm_classb,$(comp)),$(comp),$(comp)_umts))
	COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out l4,$(comp)),$(comp),$(comp)_classb))
	COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out peer,$(comp)),$(comp),$(comp)_classb))
	COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out interface,$(comp)),$(comp),$(comp)_classb))
endif

ifdef SIM_NEW_ARCH
  ifeq ($(strip $(SIM_NEW_ARCH)),TRUE)
    COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out sim,$(comp)),$(comp),$(comp)2))
  endif
endif


COMP_DEP_LIST = $(foreach comp,$(COMPSCANLIST),$(comp).dep)

# copy mmi_features_switch.h & CustMiscData.c will be used when CUSTOM_RELEASE == FALSE
# 1. MMI_VERSION != (PLUTO_MMI | NEPTUNE_MMI) ............................. MP is in our site     => CUSTOMER_MMI
# 2. MMI_VERSION == (PLUTO_MMI | NEPTUNE_MMI) & EMPTY_RESOURCE == TRUE .... MP is NOT in our site => CUSTOMER_MMI
# 3. MMI_VERSION == (PLUTO_MMI | NEPTUNE_MMI) & EMPTY_RESOURCE == FALSE ... MTK internal          => PLUTO_MMI or NEPTUNE_MMI
# copy mmi_features_switch.h & CustMiscData.c will be used when CUSTOM_RELEASE == TRUE
# 4. MMI_VERSION != (PLUTO_MMI | NEPTUNE_MMI) ............................. MP is in our site     => CUSTOMER_MMI
# 5. MMI_VERSION == (PLUTO_MMI | NEPTUNE_MMI) & EMPTY_RESOURCE == TRUE .... MP is NOT in our site => CUSTOMER_MMI
NEED_COPY_MMIFEATURE = CUSTOMER_MMI

ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
  NEED_COPY_MMIFEATURE = PLUTO_MMI

    ifdef EMPTY_RESOURCE
      ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
        NEED_COPY_MMIFEATURE = CUSTOMER_MMI
      endif
    endif
else
  ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
    NEED_COPY_MMIFEATURE = NEPTUNE_MMI

      ifdef EMPTY_RESOURCE
        ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
          NEED_COPY_MMIFEATURE = CUSTOMER_MMI
        endif
      endif
  endif
endif

ifeq ($(call Upper,$(PROJECT)),BASIC)
  NEED_COPY_MMIFEATURE = NONE
endif

ifeq ($(call Upper,$(PROJECT)),MEUT)
  NEED_COPY_MMIFEATURE = NONE
endif

ifeq ($(call Upper,$(PROJECT)),L1S)
  NEED_COPY_MMIFEATURE = NONE
endif

ifndef MMI_PROJ
MMI_PROJ = $(strip $(subst _MMI,,$(MMI_VERSION)))
endif

ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
  ifndef RUN_HTOGETHER
    RUN_HTOGETHER = FALSE
  endif
else
  ifeq ($(strip $(call Upper,$(LEVEL))),LEVEL2_SRC)
    ifndef RUN_HTOGETHER
      RUN_HTOGETHER = TRUE
    endif
  endif
endif

# *************************************************************************
# Search Paths
# *************************************************************************
vpath
vpath %.h   $(subst \,/,$(dir $(COMP_TRACE_DEFS)))
vpath %.ptr $(subst \,/,$(strip $(TST_DB))\pstrace_db)
vpath %.dep $(subst \,/,$(strip $(RULESDIR)))
vpath %.lib $(strip $(OBJSDIR))\lib
vpath %.ltp $(strip $(COMPLINTLOGDIR))

vpath %.bin $(strip $(TARGDIR))

# *************************************************************************
#  Implicit Rules and Compiler Options
# *************************************************************************
BIN_FILE       =  $(strip $(NEWTARGNAME)).bin
LIS_FILE       =  $(strip $(TARGNAME)).lis
IMG_FILE       =  $(strip $(TARGNAME)).elf
CODE_GEN_LST	=  $(strip $(TST_DB))\codegen.lis
ROM_IMG_FILE   =  rompatch\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\ROMSA_$(strip $(PLATFORM))_$(strip $(CHIP_VER)).sym
# *************************************************************************
#  Settings for BOOTLOADER
# *************************************************************************
BTLDVERNODIR   =  $(strip $(FIXPATH))\BootLoader\src
BTLD_PREFIX    =  $(strip $(CUSTOMER))_BOOTLOADER_$(strip $(BTLD_VERNO))_$(strip $(PLATFORM))_$(strip $(PURE_VERNO))
BTLD_BIN_FILE  =  $(strip $(BTLD_PREFIX)).bin
BTLDLNKOPT     = $(strip $(LNKOPT)) $(strip $(BTLD_LNKOPT)) -scatter $(BL_SCATTERFILE) \
                  -output $(strip $(TARGDIR))\$(BTLD_PREFIX).elf \
                  -symdefs $(strip $(TARGDIR))\$(BTLD_PREFIX).sym \
                  -list $(strip $(TARGDIR))\$(BTLD_PREFIX).lis \
                  -libpath $(DIR_ARMLIB)
-include $(BTLDVERNODIR)\verno_bootloader.bld
# *************************************************************************
#  Settings for FOTA
# *************************************************************************
# FOTA bin file name (cannot contain MAUI in FOTA bin file name)
FOTA_PREFIX    =  $(strip $(CUSTOMER))_FOTA_$(strip $(PLATFORM))_$(strip $(FOTA_PURE_VERNO))
FOTA_BIN_FILE  =  $(strip $(FOTA_PREFIX)).bin
CUSTOM_FOTA_H = $(strip $(FIXPATH))\custom\system\$(strip $(BOARD_VER))\custom_fota.h

FOTALNKOPT     = $(strip $(LNKOPT)) $(strip $(FOTA_LNKOPT)) -scatter $(FOTA_SCATTERFILE) \
                  -output $(strip $(TARGDIR))\$(FOTA_PREFIX).elf \
                  -symdefs $(strip $(TARGDIR))\$(FOTA_PREFIX).sym \
                  -list $(strip $(TARGDIR))\$(FOTA_PREFIX).lis \
                  -libpath $(DIR_ARMLIB)

# *************************************************************************
#  Remove Repeated Common Include Path
# *************************************************************************

ifneq ($(call uc,$(strip $(ACTION))),CRIP)
COMMINCDIRS :=  $(call uniq,$(COMMINCDIRS))
else
endif

# *************************************************************************
#  Debug
# *************************************************************************
# USER_SPECIFIC.mak is included in Option.mak

ifneq ($(filter ALL,$(call Upper,$(DEBUG_MODULES))),)
  DEBUG_MODULES := $(call Upper,$(COMPLIST))
else
  DEBUG_MODULES := $(filter-out NONE,$(call Upper,$(DEBUG_MODULES)))
endif
ifneq ($(filter ALL,$(call Upper,$(NON_DEBUG_MODULES))),)
  NON_DEBUG_MODULES := $(call Upper,$(COMPLIST))
else
  NON_DEBUG_MODULES := $(filter-out NONE,$(call Upper,$(NON_DEBUG_MODULES)))
endif

ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
  $(info WARNING: Ignore CUSTOM_DEBUG_MODULES CUSTOM_NON_DEBUG_MODULES before CUSTOM_RELEASE)
  TEMP := $(filter $(NON_DEBUG_MODULES),$(DEBUG_MODULES))
  ifneq ($(words $(TEMP)),0)
    DEBUG_MODULES := $(filter-out $(TEMP),$(DEBUG_MODULES))
    $(info WARNING: Ignore DEBUG_MODULES = $(TEMP))
  endif
else
  ifndef CUSTOM_DEBUG_MODULES
    CUSTOM_DEBUG_MODULES :=
  else
    ifneq ($(filter ALL,$(call Upper,$(CUSTOM_DEBUG_MODULES))),)
      CUSTOM_DEBUG_MODULES := $(call Upper,$(COMPLIST))
    else
      CUSTOM_DEBUG_MODULES := $(filter-out NONE,$(call Upper,$(CUSTOM_DEBUG_MODULES)))
    endif
  endif
  ifndef CUSTOM_NON_DEBUG_MODULES
    CUSTOM_NON_DEBUG_MODULES :=
  else
    ifneq ($(filter ALL,$(call Upper,$(CUSTOM_NON_DEBUG_MODULES))),)
      CUSTOM_NON_DEBUG_MODULES := $(call Upper,$(COMPLIST))
    else
      CUSTOM_NON_DEBUG_MODULES := $(filter-out NONE,$(call Upper,$(CUSTOM_NON_DEBUG_MODULES)))
    endif
  endif

  DEBUG_MODULES := $(filter-out $(CUSTOM_DEBUG_MODULES),$(DEBUG_MODULES))
  NON_DEBUG_MODULES := $(filter-out $(CUSTOM_NON_DEBUG_MODULES),$(NON_DEBUG_MODULES))

  TEMP := $(filter $(CUSTOM_NON_DEBUG_MODULES) $(NON_DEBUG_MODULES),$(DEBUG_MODULES))
  ifneq ($(words $(TEMP)),0)
    DEBUG_MODULES := $(filter-out $(TEMP),$(DEBUG_MODULES))
    $(info WARNING: Ignore DEBUG_MODULES = $(TEMP))
  endif
  TEMP := $(filter $(CUSTOM_DEBUG_MODULES),$(NON_DEBUG_MODULES))
  ifneq ($(words $(TEMP)),0)
    NON_DEBUG_MODULES := $(filter-out $(TEMP),$(NON_DEBUG_MODULES))
    $(info WARNING: Ignore NON_DEBUG_MODULES = $(TEMP))
  endif
  TEMP := $(filter $(CUSTOM_NON_DEBUG_MODULES),$(CUSTOM_DEBUG_MODULES))
  ifneq ($(words $(TEMP)),0)
    CUSTOM_DEBUG_MODULES := $(filter-out $(TEMP),$(CUSTOM_DEBUG_MODULES))
    $(info WARNING: Ignore CUSTOM_DEBUG_MODULES = $(TEMP))
  endif

  DEBUG_MODULES := $(sort $(CUSTOM_DEBUG_MODULES) $(DEBUG_MODULES))
  NON_DEBUG_MODULES := $(sort $(CUSTOM_NON_DEBUG_MODULES) $(NON_DEBUG_MODULES))
endif

ifeq ($(strip $(DEBUG_MODULES)),)
  DEBUG_MODULES := NONE
endif

ifeq ($(strip $(NON_DEBUG_MODULES)),)
  NON_DEBUG_MODULES := NONE
endif

# *************************************************************************
#  Config for MoDIS
# *************************************************************************
ifndef MODIS_CONFIG
  MODIS_CONFIG = FALSE
endif

ifeq ($(strip $(MODIS_CONFIG)),TRUE)
  include make\modisConfig.mak
  INFOLOG = $(strip $(COMPLOGDIR))\info_modis.log
  INFOMAKELOG = $(strip $(COMPLOGDIR))\infomake_modis.log
endif

MODULELIS = $(foreach comp,$(sort $(COMPLIST)),$(comp).lis)

ifeq ($(strip $(NEED_BUILD_BOOTLOADER)),TRUE)
MODULELIS += bootloader.lis
endif

ifneq ($(strip $(FOTA_ENABLE)),NONE)
MODULELIS += fota.lis
endif

# *************************************************************************
# New Build
# *************************************************************************
ifeq ($(strip $(call Upper,$(LEVEL))),VENDOR)
  ifeq ($(strip $(NEED_BUILD_BOOTLOADER)),TRUE)
    ifeq ($(filter bootloader, $(strip $(CUS_REL_SRC_COMP))),bootloader)
      ifeq  ($(strip $(call Upper,$(PROJECT))),UMTS)
new : backup cleanall genlog cleancodegen asngen umts_gen ss_lcs_gen codegen asnregen cleanbin mcddll_update resgen nvram_auto_gen $(BTLD_BIN_FILE) remake
      else
new : backup cleanall genlog cleancodegen asngen codegen asnregen cleanbin mcddll_update resgen nvram_auto_gen $(BTLD_BIN_FILE) remake
      endif    
    else
      ifeq  ($(strip $(call Upper,$(PROJECT))),UMTS)
new : backup cleanall genlog cleancodegen asngen umts_gen ss_lcs_gen codegen asnregen cleanbin mcddll_update resgen nvram_auto_gen remake
      else
new : backup cleanall genlog cleancodegen asngen codegen asnregen cleanbin mcddll_update resgen nvram_auto_gen remake
      endif    
    endif
  else
    ifeq  ($(strip $(call Upper,$(PROJECT))),UMTS)
new : backup cleanall genlog cleancodegen asngen umts_gen ss_lcs_gen codegen asnregen cleanbin mcddll_update resgen nvram_auto_gen remake
    else
new : backup cleanall genlog cleancodegen asngen codegen asnregen cleanbin mcddll_update resgen nvram_auto_gen remake
    endif  
  endif
else
  ifeq ($(strip $(NEED_BUILD_BOOTLOADER)),TRUE)
    ifeq  ($(strip $(call Upper,$(L1_WCDMA))),TRUE)
new : backup cleanall genlog sysgen ckscatter mmi_feature_check cleancodegen asngen umts_gen ss_lcs_gen codegen asnregen operator_check resgen $(BTLD_BIN_FILE) update
    else
new : backup cleanall genlog sysgen ckscatter mmi_feature_check cleancodegen asngen codegen asnregen operator_check resgen $(BTLD_BIN_FILE) update  
    endif
  else
    ifneq ($(filter UMTS HSPA,$(strip $(call Upper,$(PROJECT)))),)
new : backup cleanall genlog sysgen ckscatter mmi_feature_check cleancodegen asngen umts_gen ss_lcs_gen codegen asnregen operator_check update
    else
new : backup cleanall genlog sysgen ckscatter mmi_feature_check cleancodegen asngen codegen asnregen operator_check update
    endif
  endif
endif

# *************************************************************************
#  Update Build
# *************************************************************************
#update : genlog cleanbin codegen mcddll_update resgen cksysdrv_slim remake

ifeq ($(strip $(ACTION)),slim_update)

ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
  ifeq ($(strip $(CUSTOM)),MONZA29)
update : backup genlog codegen remake
  else
    ifneq ($(filter UMTS HSPA,$(strip $(call Upper,$(PROJECT)))),)
update : backup genlog cleanbin umts_gen codegen  cksysdrv_slim resgen remake
    else
update : backup genlog cleanbin codegen  cksysdrv_slim resgen remake
    endif
  endif
else
  ifneq ($(filter UMTS HSPA,$(strip $(call Upper,$(PROJECT)))),)
update : backup genlog cleanbin umts_gen codegen resgen mmi_obj_check cksysdrv_slim remake
  else
update : backup genlog cleanbin codegen resgen mmi_obj_check cksysdrv_slim remake
  endif
endif

else  
## update

ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
  ifeq ($(strip $(CUSTOM)),MONZA29)
update : backup genlog codegen remake
  else
    ifneq ($(filter UMTS HSPA,$(strip $(call Upper,$(PROJECT)))),)
update : backup genlog cleanbin umts_gen ss_lcs_gen codegen mcddll_update cksysdrv_slim resgen remake
    else
update : backup genlog cleanbin codegen mcddll_update cksysdrv_slim resgen remake
    endif
  endif
else
  ifneq ($(filter UMTS HSPA,$(strip $(call Upper,$(PROJECT)))),)
update : backup genlog cleanbin umts_gen ss_lcs_gen codegen mcddll_update resgen mmi_obj_check cksysdrv_slim remake
  else
update : backup genlog cleanbin codegen mcddll_update resgen mmi_obj_check cksysdrv_slim remake
  endif
endif

endif

# *************************************************************************
#  Remake Build
# *************************************************************************
ifneq ($(strip $(LINT)),TRUE)
ifeq ($(strip $(LEVEL)),VENDOR)
  ifneq ($(strip $(FOTA_ENABLE)),NONE)
    ifeq ($(filter fota, $(strip $(CUS_REL_SRC_COMP))),fota)
remake : backup mcp_check genlog cleanbin genverno libs $(FOTA_BIN_FILE) $(BIN_FILE) cmmgen done
    else
remake : backup mcp_check genlog cleanbin genverno libs $(BIN_FILE) cmmgen done
    endif
  else
remake : backup mcp_check genlog cleanbin genverno libs $(BIN_FILE) cmmgen done
  endif
else
  ifeq ($(strip $(call Upper,$(REMAKE_MODS))),BOOTLOADER)
remake : backup $(BTLD_BIN_FILE) done
  else
    ifeq ($(strip $(call Upper,$(REMAKE_MODS))),FOTA)
remake : backup $(FOTA_BIN_FILE) done
    else
      ifdef FOTA_ENABLE
        ifneq ($(strip $(FOTA_ENABLE)),NONE)
remake : backup mcp_check genlog cleanbin genverno libs $(FOTA_BIN_FILE) $(BIN_FILE) cmmgen done
        else
remake : backup mcp_check genlog cleanbin genverno libs $(BIN_FILE) cmmgen done
        endif
      else
remake : backup mcp_check genlog cleanbin genverno libs $(BIN_FILE) cmmgen done
      endif
    endif
  endif
endif
else
remake : backup libs copylintlog genlintstatlog done 
endif
# *************************************************************************
#  Tools code preprocess and generation
# *************************************************************************
ifeq ($(strip $(ACTION)),slim_codegen)

ifneq ($(filter UMTS HSPA,$(strip $(call Upper,$(PROJECT)))),)
slim_codegen: cleancodegen asngen umts_gen codegen asnregen cleanbin  done
else
slim_codegen: cleancodegen asngen codegen asnregen cleanbin  done
endif

else
## codegen

ifneq ($(filter UMTS HSPA,$(strip $(call Upper,$(PROJECT)))),)
code_generate: cleancodegen asngen umts_gen ss_lcs_gen codegen asnregen cleanbin mcddll_update done
else
code_generate: cleancodegen asngen codegen asnregen cleanbin mcddll_update done
endif

endif
# *************************************************************************
#  Resgen
# *************************************************************************
ifeq ($(strip $(ACTION)),new)
resgen:new_resgen
else
ifeq ($(strip $(ACTION)),bm_new)
resgen:new_resgen
else
resgen:remake_resgen
endif
endif
# ---------------------------------------
# 3G Codegen Gen Files: ASN and DBME
# ---------------------------------------
umts_gen:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
ifneq ($(call Upper,$(strip $(PROJECT))),L1S)
ifneq ($(call Upper,$(strip $(PROJECT))),BASIC)
ifneq ($(call Upper,$(strip $(PROJECT))),MEUT)
	(cd uas) &  \
	(perl uas_generate.pl --CC=$(CC) --feature=" $(UMTS_RELEASE_SUPPORT) $(UMTS_MODE_SUPPORT) $(ULCS_ASN_SUPPORT_VERSION) $(REMOVE_DEBUG_INFO)") &  \
	(if ERRORLEVEL 1 exit 1) & \
	(cd ..)
endif
endif
endif
else
ifneq ($(findstring REL_SUB_MBJ_RD3_PROTOCOL,$(call Upper,$(strip $(RELEASE_PACKAGE)))),)
	(cd uas) &  \
	(perl uas_generate.pl --CC=$(CC) --feature=" $(UMTS_RELEASE_SUPPORT) $(UMTS_MODE_SUPPORT) $(ULCS_ASN_SUPPORT_VERSION) $(REMOVE_DEBUG_INFO)") &  \
	(if ERRORLEVEL 1 exit 1) & \
	(cd ..)
endif
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# ---------------------------------------
# SS LCS Codegen Gen Files: ASN
# ---------------------------------------
ss_lcs_gen:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	(cd ps\l4\csm\ss\tools) &  \
	(ss_lcs_generate.bat) &  \
	(cd ..\..\..\..\..)
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# ---------------------------------------
# MCDDLL update
# ---------------------------------------
ifeq ($(strip $(ACTION)),slim_mcddll)
slim_mcddll: 
else
mcddll_update: codegen
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'mcddll_update START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
ifneq ($(call Upper,$(strip $(PROJECT))),L1S)
ifneq ($(call Upper,$(strip $(PROJECT))),BASIC)
ifneq ($(call Upper,$(strip $(PROJECT))),MEUT)
	(cd ps) &  \
	(cd mcddll) &  \
    (perl updatemcddll_msvc.pl $(call Upper,$(strip $(PROJECT))) 2>..\..\$(MCDDLL_UPDATE_LOG)) &  \
    (if ERRORLEVEL 1 exit 1) & \
    (cd ..) &  \
    (cd ..) &  \
	(copy /y ps\mcddll\mcddll.dll $(strip $(TST_DB))\mcddll.dll > nul)
endif
endif
endif
else
ifneq ($(findstring REL_SUB_MBJ_RD3_PROTOCOL,$(call Upper,$(strip $(RELEASE_PACKAGE)))),)
	(cd ps) &  \
	(cd mcddll) &  \
    (perl updatemcddll_msvc.pl $(call Upper,$(strip $(PROJECT))) 2>..\..\$(MCDDLL_UPDATE_LOG)) &  \
    (if ERRORLEVEL 1 exit 1) & \
    (cd ..) &  \
    (cd ..) &  \
	(copy /y ps\mcddll\mcddll.dll $(strip $(TST_DB))\mcddll.dll > nul)
endif
endif
	@perl -e "print 'mcddll_update END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# -----------------------------
# Asn Gen Files
# -----------------------------
asngen: pre_gen gen_infolog
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'asngen START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # XXX!!!. Temporary solution for customer engagement
	@if /I $(CUSTOMER) EQU PLUTO   \
		(@if /I $(CUSTOM_RELEASE) EQU FALSE   \
			(copy /z init\src\Pluto_idma.c init\src\idma.c) & \
			(copy /z init\include\Pluto_idma_out.h init\include\idma_out.h) & \
			(copy /z init\src\Pluto_bootarm.s init\src\bootarm.s) & \
			(copy /z init\src\Pluto_init.c init\src\init.c) \
		)
ifeq ($(findstring REL_SUB_MBJ_RD3_PROTOCOL,$(call Upper,$(strip $(RELEASE_PACKAGE)))),)
	-@if /I $(PROJECT) NEQ L1S   \
		(@if /I $(PROJECT) NEQ BASIC   \
			(@if /I $(PROJECT) NEQ MEUT   \
				(@if /I $(CUSTOM_RELEASE) EQU FALSE   \
					(@if /I $(MCD_SUPPORT) EQU TRUE   \
						(md ps\gen) & \
						(@echo Generate ASN Gen Files 1st Phase ...) & \
						(cd ps\tools) & \
						(perl ./mcdparser.pl mcd.ini --only=$(PROJECT) --deffile="..\.$(INFOLOG)") & \
						(cd ..\..) \
					else \
						(@echo Generate ASN Gen Files ...) & \
						(cd ps) & \
						(generate.bat) & \
						(@echo Generate ASN Gen Files Done ...) \
					) & \
					(@echo Compiling Csi ASN files...) & \
					(cd ps\scsi\gen) & \
					(perl ./scsi_generate.pl --CC=$(CC) --feature=" $(UMTS_RELEASE_SUPPORT) $(UMTS_MODE_SUPPORT) ") & \
					(if ERRORLEVEL 1 exit 1) & \
					(cd ..\..\..) & \
					(@echo Compilation Csi ASN files done ...) \
				) \
			) \
		)
else
	if /I $(MCD_SUPPORT) EQU TRUE   \
		(md ps\gen) & \
		(@echo Generate ASN Gen Files 1st Phase ...) & \
		(cd ps\tools) & \
		(perl ./mcdparser.pl mcd.ini --only=$(PROJECT) --deffile="..\.$(INFOLOG)") & \
		(cd ..\..) \
	else \
		(@echo Generate ASN Gen Files ...) & \
		(cd ps) & \
		(generate.bat) & \
		(@echo Generate ASN Gen Files Done ...)
		
	(@echo Compiling Csi ASN files...) & \
	(cd ps\scsi\gen) & \
	(perl ./scsi_generate.pl --CC=$(CC) --feature=" $(UMTS_RELEASE_SUPPORT) $(UMTS_MODE_SUPPORT) ") & \
	(if ERRORLEVEL 1 exit 1) & \
	(cd ..\..\..) & \
	(@echo Compilation Csi ASN files done ...)
endif
	@perl -e "print 'asngen END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

asnregen: gen_infolog
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'asnregen START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
ifeq ($(findstring REL_SUB_MBJ_RD3_PROTOCOL,$(call Upper,$(strip $(RELEASE_PACKAGE)))),)
	-@if /I $(PROJECT) NEQ L1S   \
		(@if /I $(PROJECT) NEQ BASIC   \
			(@if /I $(PROJECT) NEQ MEUT   \
				(@if /I $(CUSTOM_RELEASE) EQU FALSE   \
					(@if /I $(MCD_SUPPORT) EQU TRUE   \
						(@echo Generate ASN Gen Files 2nd Phase ...) & \
						(cd ps\tools) & \
						(perl ./mcdparser.pl mcd.ini  --only=$(PROJECT) --only=for_catcher --deffile="..\.$(INFOLOG)") & \
						(cd ..\..) \
					) \
				) \
			) \
		)
else
	(@if /I $(MCD_SUPPORT) EQU TRUE   \
		(@if /I $(CUSTOM_RELEASE) EQU FALSE   \
			(@echo Generate ASN Gen Files 2nd Phase ...) & \
			(cd ps\tools) & \
			(perl ./mcdparser.pl mcd.ini  --only=$(PROJECT) --only=for_catcher --deffile="..\.$(INFOLOG)") & \
			(cd ..\..) \
		else \
			(@echo Generate ASN Gen Files 2nd Phase ...) & \
			(cd ps\tools) & \
			(perl ./mcdparser.pl mcd.ini  --only=$(PROJECT) --only=for_catcher --deffile="..\.$(INFOLOG)" --custom) & \
			(cd ..\..) \
		) \
	)
endif
	@perl -e "print 'asnregen END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

pre_gen :
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
	perl ps\tools\pre_mcdparser.pl $(CC) $(MCD_SCANDEFS)
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

codegen : ss_lcs_gen gencustominfo operator_check gencustomlists xml_parser nvram_auto_gen cgen_preflow $(CODEGEN_RESULT)
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))	
# =================================================================
ifeq ($(strip $(USE_CODEGEN_CFG)),TRUE)
 ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
	@if not exist $(strip $(CGEN_CFG_FILE)) \
		(echo Error: $(CGEN_CFG_FILE) does not exit!) &\
		(exit 1)
	@echo Cgen -cfg $(CGEN_CFG_FILE)
	@($(CGEN) -cfg $(CGEN_CFG_FILE) 2>>$(CODE_GEN_LOG) &\
 			(if ERRORLEVEL 1 exit 1) \
 		)
 endif
 
 ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
	-@if /I $(PROJECT) NEQ BASIC \
 		(if /I $(MTK_SUBSIDIARY) EQU TRUE \
 		(if exist $(MMI_SCR_ID_FILE) del /q $(MMI_SCR_ID_FILE) > nul) & \
 		(if exist $(MMI_SCR_ID_DB) del /q $(MMI_SCR_ID_DB) > nul) & \
 		(if exist $(strip $(TST_DB))\BPLGUInfoCustomSrc del /q $(strip $(TST_DB))\BPLGUInfoCustomSrc) & \
 		(if exist $(strip $(TST_DB))\enumFileCustomSrc del /q $(strip $(TST_DB))\enumFileCustomSrc) \
 		)
 	  
	-@if /I $(PROJECT) NEQ BASIC \
 		(echo $(strip $(TST_DB))\BPLGUInfoCustomAppSrc > $(CODE_GEN_LST)) &\
 		(echo $(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOMSRCP)) >> $(CODE_GEN_LST)) & \
 		(echo $(strip $(TST_DB))\pstrace_db\ps_trace.h >> $(CODE_GEN_LST)) & \
 		(echo $(strip $(TST_DB))\pstrace_db\$(SINGLE_HEADER)) & \
 		(if exist $(strip $(TST_DB))\pstrace_db\ps_trace_1.h del /q $(strip $(TST_DB))\pstrace_db\ps_trace_1.h > nul) & \
 		(if exist $(strip $(TST_DB))\BPLGUInfoCustomAppSrc del /q $(strip $(TST_DB))\BPLGUInfoCustomAppSrc > nul)
 else
	-@if /I $(PROJECT) NEQ BASIC \
 		(echo $(strip $(TST_DB))\msglog_db\BInfo >> $(CODE_GEN_LST)) & \
 		(echo $(strip $(TST_DB))\enumFile >> $(CODE_GEN_LST)) &\
 		(echo $(strip $(TST_DB))\pstrace_db\BPInfo >> $(CODE_GEN_LST)) & \
 		(echo $(strip $(TST_DB))\msglog_db\BInfo >> $(CODE_GEN_LST)) & \
 		(echo $(strip $(TST_DB))\pstrace_db\ps_trace.h >> $(CODE_GEN_LST)) & \
 		(echo $(strip $(TST_DB))\l1trace_db\BPLInfo >> $(CODE_GEN_LST)) & \
 		(echo $(strip $(TSTDIR))\src\TrcMod.c >> $(CODE_GEN_LST)) & \
 		(echo $(strip $(TSTDIR))\include\TrcMod.h >> $(CODE_GEN_LST)) &\
 		(echo $(strip $(TST_DB))\BPLGInfo >> $(CODE_GEN_LST)) & \
 		(echo $(strip $(TST_DB))\l1validation_db\BPLVInfo >> $(CODE_GEN_LST)) & \
 		(echo $(strip $(TST_DB))\BPLGUInfo >> $(CODE_GEN_LST)) & \
 		(echo $(strip $(TST_DB))\pstrace_db\$(SINGLE_HEADER)) & \
 		(if exist $(strip $(TST_DB))\pstrace_db\ps_trace_1.h del /q $(strip $(TST_DB))\pstrace_db\ps_trace_1.h > nul) & \
 		(if exist $(strip $(TST_DB))\msglog_db\BInfo del /q $(strip $(TST_DB))\msglog_db\BInfo > nul) &\
 		(if exist $(strip $(TST_DB))\l1trace_db\BPLInfo del /q $(strip $(TST_DB))\l1trace_db\BPLInfo > nul) &\
 		(if exist $(strip $(TST_DB))\BPLGInfo del /q $(strip $(TST_DB))\BPLGInfo > nul) &\
 		(if exist $(MMI_SCR_ID_FILE) del /q $(MMI_SCR_ID_FILE) > nul) & \
 		(if exist $(MMI_SCR_ID_DB) del /q $(MMI_SCR_ID_DB) > nul) & \
 		(if exist $(strip $(TST_DB))\BPLGUInfo del /q $(strip $(TST_DB))\BPLGUInfo > nul) & \
 		(if exist $(strip $(TST_DB))\BPLGUInfoCustom del /q $(strip $(TST_DB))\BPLGUInfoCustom > nul)
 
	-@if /I $(PROJECT) NEQ BASIC \
 			(for /d %%i in ($(TMD_GEN_C_H_FILES)) do \
 			   (echo %%i >> $(CODE_GEN_LST)) \
 			)
 endif
endif

	@if exist $(strip $(RULESDIR))\codegen.dep del $(strip $(RULESDIR))\codegen.dep
	@if exist $(strip $(RULESDIR))\custom_parse_db.d (perl .\tools\pack_dep.pl $(strip $(RULESDIR))\custom_parse_db.d tools\copy_mmi_include_h.bat> $(strip $(RULESDIR))\custom_parse_db.det) & (del $(strip $(RULESDIR))\custom_parse_db.d)
	@if exist $(strip $(RULESDIR))\app_parse_db.d (perl .\tools\pack_dep.pl $(strip $(RULESDIR))\app_parse_db.d tools\copy_mmi_include_h.bat> $(strip $(RULESDIR))\app_parse_db.det) & (del $(strip $(RULESDIR))\app_parse_db.d)
	@if exist $(strip $(RULESDIR))\custom_parse_db.det (type $(strip $(RULESDIR))\custom_parse_db.det >> $(strip $(RULESDIR))\codegen.dep) & (del $(strip $(RULESDIR))\custom_parse_db.det)
	@if exist $(strip $(RULESDIR))\app_parse_db.det (type $(strip $(RULESDIR))\app_parse_db.det >> $(strip $(RULESDIR))\codegen.dep) & (del $(strip $(RULESDIR))\app_parse_db.det)

	@perl -e "print 'codegen END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

cgen_preflow :	
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'codegen START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
	-@if exist $(strip $(INFOMAKELOG)) \
		echo COMP_TRACE_DEFS = $(call sort, $(foreach def,$(COMP_TRACE_DEFS),$(def))) >> $(INFOMAKELOG)
ifeq ($(strip $(USE_CODEGEN_CFG)),TRUE)
	-@if exist $(strip $(CGEN_CFG_FILE)) \
		del /Q /F $(strip $(CGEN_CFG_FILE))
	@(if exist plutommi\Customer\ResGenerator\res_parse_screen_id.pl \
		(@perl plutommi\Customer\ResGenerator\res_parse_screen_id.pl $(strip $(MMI_VERSION))) & \
		(if ERRORLEVEL 1 exit 1))
endif
	@if not exist $(strip $(FIXPATH))\custom\tst \
		md $(strip $(FIXPATH))\custom\tst

	@if exist $(strip $(MMI_FEATURES_LOG)) \
		(echo $(strip $(INFOLOG)) $(strip $(MMI_FEATURES_LOG)) $(strip $(THE_MF)) > $(strip $(TSTDIR))\database\SaveFile.ini) \
	else \
		(echo $(strip $(INFOLOG)) $(strip $(THE_MF)) > $(strip $(TSTDIR))\database\SaveFile.ini)

	@perl tools\lnitem.pl $(strip $(TSTDIR))\database\SaveFile.ini

   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

# -----------------------------
# Step 1: Preprocess
# -----------------------------
$(TST_GEN_DEP_OUTS) : $(TST_GEN_DEP_SRCS) genmoduleinfo
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@echo Check Directories ...
	-@if exist $(strip $(CODE_GEN_LOG)) \
		del /Q /F $(strip $(CODE_GEN_LOG))

	-@if not exist $(strip $(TST_DB)) \
		md $(TST_DB)

	-@if not exist $(strip $(TST_DB))\msglog_db \
		md $(strip $(TST_DB))\msglog_db

	-@if /I $(PROJECT) NEQ BASIC \
		(@if /I $(CUSTOM_RELEASE) EQU FALSE   \
			(@if not exist $(strip $(L1TRACE_DB_DIR)) \
				(md $(strip $(L1TRACE_DB_DIR))) \
			) & \
			(@if not exist $(strip $(L1VAL_DB_DIR)) \
				(md $(strip $(L1VAL_DB_DIR))) \
			) & \
			(@if not exist $(strip $(L1VAL_DB_PARSE_DIR)) \
				(md $(strip $(L1VAL_DB_PARSE_DIR))) \
			) \
		)

	-@if not exist $(strip $(PSTRACE_DB_DIR)) \
		md $(strip $(PSTRACE_DB_DIR))

	-@if not exist $(strip $(GV_DB_DIR)) \
		md $(strip $(GV_DB_DIR))
		
	-@if not exist $(strip $(GV_DB_PARSE_DIR)) \
		md $(strip $(GV_DB_PARSE_DIR))		

	-@if exist $(strip $(PSTRACE_DB_DIR)) \
		del /Q $(strip $(PSTRACE_DB_DIR))\*.*

	@echo Preprocessing C source code ...

	@tools\strcmpex.exe def def e make\~inc_def.tmp $(foreach def,$(COM_DEFS),-D$(def))
	@echo -D__NULL_DEF__ >> make\~inc_def.tmp

	@perl tools\echoLongString2.pl make\~inc_def.tmp -D $(COM_DEF_PATH)

	@tools\strcmpex.exe inc inc e make\~inc.tmp $(foreach inc,$(COMMINCDIRS),-I$(inc))
	@type make\~inc.tmp >> make\~inc_def.tmp

# based on gv_db.c generate gv_parse.gv
	@echo Preprocessing GV scripts ... $<
	@if /I $(PROJECT) NEQ BASIC \
			(@if /I $(CUSTOM_RELEASE) EQU FALSE   \
				(echo Generate Global variable Information ...) & \
			($(CC) -E -W -DGEN_FOR_CPARSER -DGEN_FOR_PC $(VIA) make\~inc_def.tmp -USTDC_HEADERS -o $(strip $(TST_DB))\gv\gv_db\gv_db.gv $(strip $(TSTDIR))\database\gv\gv_db.c 2>$(CODE_GEN_LOG)) & \
			(if ERRORLEVEL 1 exit 1) & \
			(@echo $(strip $(TST_DB))\gv\gv_db\gv_db.gv > $(CODE_GEN_LST)) & \
			(@echo Compiling gv_db.c was done.) \
		)

# based on unionTag_db.c generate unionTag_parse.txt
	@echo Preprocessing unionTag scripts ... $<
	@if /I $(PROJECT) NEQ BASIC \
		(@if /I $(CUSTOM_RELEASE) EQU FALSE   \
			(echo Generate UnionTag Information ...) & \
		($(CC) -E -W -DGEN_FOR_CPARSER -DGEN_FOR_PC $(VIA) make\~inc_def.tmp -USTDC_HEADERS -o $(strip $(TST_DB))\unionTag\unionTag_parse.txt $(strip $(TSTDIR))\database\unionTag\unionTag_db.c 2>$(CODE_GEN_LOG)) & \
		(if ERRORLEVEL 1 exit 1) & \
		(@echo $(strip $(TST_DB))\unionTag\unionTag_parse.txt > $(CODE_GEN_LST)) & \
		(@echo Compiling unionTag_db.c was done.) \
		)
ifneq ($(findstring REL_SUB_MBJ_RD3_PROTOCOL,$(call Upper,$(strip $(RELEASE_PACKAGE)))),)
	@if /I $(PROJECT) NEQ BASIC \
		(@if /I $(CUSTOM_RELEASE) EQU TRUE   \
			(echo Generate UnionTag Information ...) & \
		($(CC) -E -W -DGEN_FOR_CPARSER -DGEN_FOR_PC $(VIA) make\~inc_def.tmp -USTDC_HEADERS -o $(strip $(TST_DB))\unionTag\unionTag_parse.txt $(strip $(TSTDIR))\database\unionTag\unionTag_db.c 2>$(CODE_GEN_LOG)) & \
		(if ERRORLEVEL 1 exit 1) & \
		(@echo $(strip $(TST_DB))\unionTag\unionTag_parse.txt > $(CODE_GEN_LST)) & \
		(@echo Compiling unionTag_db.c was done.) \
		)
endif
	@if /I $(PROJECT) EQU BASIC \
		((if not exist $(strip $(TST_DB))\unionTag \
		(md $(strip $(TST_DB))\unionTag)) & \
		(@perl -e "print \"\n\" ;" > $(strip $(TST_DB))\unionTag\unionTag_parse.txt))

# based on l1v_db.c generate l1v_parse.l1v
ifeq ($(call Upper,$(PROJECT)),L1S)
	@if /I $(PROJECT) NEQ BASIC \
		(@if /I $(CUSTOM_RELEASE) EQU FALSE   \
			(@echo Preprocessing L1V scripts ...) & \
		($(CC) -E -W -DGEN_FOR_CPARSER -DGEN_FOR_PC $(VIA) make\~inc_def.tmp -USTDC_HEADERS -o $(L1VAL_DB_PARSE_DIR)\l1v_db.l1v $(L1VAL_DB_DIR)\l1v_db.c 2>$(CODE_GEN_LOG)) & \
		(if ERRORLEVEL 1 exit 1) & \
		(@echo $(L1VAL_DB_PARSE_DIR)\l1v_db.l1v > $(CODE_GEN_LST)) & \
		(@echo Compiling l1v_db.c was done.) \
		)
endif

# based on custom_parse_db.c generate codegen.dep
	-@if not exist $(RULESDIR) (md $(RULESDIR))
	-@if not exist $(OBJSDIR) (md $(OBJSDIR))

ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
	@echo Compile parse_db.c ...
	@($(CC) -E -W -DGEN_FOR_CPARSER -DGEN_FOR_PC $(VIA) make\~inc_def.tmp -USTDC_HEADERS -o $(strip $(TST_DB))\msglog_db\pri.db $(strip $(TSTDIR))\database\msglog_db\parse_db.c 2>$(CODE_GEN_LOG)) & \
		(if ERRORLEVEL 1 exit 1) & \
	@echo $(strip $(TST_DB))\msglog_db\pri.db >> $(CODE_GEN_LST)
	@echo Compiling parse_db.c was done.
else
  ifneq ($(strip $(PROJECT)),BASIC)
		@($(CC) -E -W -DGEN_FOR_CPARSER -DGEN_FOR_PC $(VIA) make\~inc_def.tmp -USTDC_HEADERS -o $(strip $(TST_DB))\msglog_db\custom_pri.db $(strip $(TSTDIR))\database\msglog_db\custom_parse_db.c 2>$(CODE_GEN_LOG)) & \
			(if ERRORLEVEL 1 exit 1)
		@($(CC) -M -W -DGEN_FOR_CPARSER -DGEN_FOR_PC $(VIA) make\~inc_def.tmp -USTDC_HEADERS -o $(strip $(TST_DB))\msglog_db\custom_parse_db.obj $(strip $(TSTDIR))\database\msglog_db\custom_parse_db.c $(DEPEND) $(strip $(RULESDIR))\custom_parse_db.d 2>$(CODE_GEN_LOG)) & \
			(if ERRORLEVEL 1 exit 1)
    ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
			@($(CC) -E -W -DGEN_FOR_CPARSER -DGEN_FOR_PC $(VIA) make\~inc_def.tmp -USTDC_HEADERS -o $(strip $(TST_DB))\msglog_db\app_pri.db $(strip $(TSTDIR))\database\msglog_db\app_parse_db.c 2>>$(CODE_GEN_LOG)) & \
				(if ERRORLEVEL 1 exit 1)
			@($(CC) -M -W -DGEN_FOR_CPARSER -DGEN_FOR_PC $(VIA) make\~inc_def.tmp -USTDC_HEADERS -o $(strip $(TST_DB))\msglog_db\app_parse_db.obj $(strip $(TSTDIR))\database\msglog_db\app_parse_db.c $(DEPEND) $(strip $(RULESDIR))\app_parse_db.d 2>>$(CODE_GEN_LOG)) & \
				(if ERRORLEVEL 1 exit 1))
    endif
		@if $(words $(strip $(BPLGUINFOCUSTOM))) NEQ 1 ((echo More than two $(strip $(BPLGUINFOCUSTOM)). Please check.) & (exit 644))
  endif
endif

ifeq ($(strip $(USE_CODEGEN_CFG)),TRUE)
  ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
    ifneq ($(strip $(PROJECT)),BASIC)
      ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
				@if exist plutommi\Customer\ResGenerator\res_parse_screen_id.pl (perl plutommi\Customer\ResGenerator\res_parse_screen_id.pl $(strip $(MMI_VERSION))) & \
					(if ERRORLEVEL 1 exit 1))
				@echo $(CGEN) -cm $(strip $(TST_DB))\BPLGUInfoCustomSrc $(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOM)) $(strip $(TST_DB))\msglog_db\custom_pri.db $(strip $(TST_DB))\enumFileCustomSrc $(strip $(PLATFORM))_$(strip $(CHIP_VER)) $(strip $(VERNO)) -savFile-$(strip $(TSTDIR))\database\SaveFile.ini -prjName-$(strip $(PROJECT_NAME)) >>$(CGEN_CFG_FILE)
				@($(CGEN) -src $(MMI_SCR_ID_FILE) $(FIXPATH)\$(strip $(MMIDIR)) )& \
					(if ERRORLEVEL 1 exit 1)
				@($(CC) -E -W -DGEN_FOR_CPARSER -DGEN_FOR_PC $(VIA) make\~inc_def.tmp -USTDC_HEADERS -o $(MMI_SCR_ID_DB) $(MMI_SCR_ID_FILE) 2>$(CODE_GEN_LOG)) & \
					(if ERRORLEVEL 1 exit 1)
				@echo $(CGEN) -ap $(strip $(TST_DB))\BPLGUInfoCustomAppSrc $(strip $(TST_DB))\BPLGUInfoCustomSrc $(strip $(TST_DB))\msglog_db\app_pri.db $(strip $(TST_DB))\enumFileCustomAppSrc $(strip $(PLATFORM))_$(strip $(CHIP_VER)) $(strip $(VERNO)) $(MMI_SCR_ID_DB) >>$(CGEN_CFG_FILE))
				@echo $(CGEN) -filter_gen src $(strip $(TST_DB))\BPLGUInfoCustomAppSrc $(strip $(TSTDIR))\database\log2SD_Catcher_filters.ini $(strip $(FIXPATH))\custom\tst\tst_file_default_Catcher_filter.c __TST_WRITE_TO_FILE__ >>$(CGEN_CFG_FILE))
      else
				@echo $(CGEN) -cm $(strip $(TST_DB))\BPLGUInfoCustomAppSrc $(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOM)) $(strip $(TST_DB))\msglog_db\custom_pri.db $(strip $(TST_DB))\enumFileCustomAppSrc $(strip $(PLATFORM))_$(strip $(CHIP_VER)) $(strip $(VERNO)) -savFile-$(strip $(TSTDIR))\database\SaveFile.ini -prjName-$(strip $(PROJECT_NAME)) >>$(CGEN_CFG_FILE)
				@echo $(CGEN) -filter_gen src $(strip $(TST_DB))\BPLGUInfoCustomAppSrc $(strip $(TSTDIR))\database\log2SD_Catcher_filters.ini $(strip $(FIXPATH))\custom\tst\tst_file_default_Catcher_filter.c __TST_WRITE_TO_FILE__ >>$(CGEN_CFG_FILE)
      endif
    endif
  endif
else
	@if /I $(CUSTOM_RELEASE) EQU TRUE \
		(if /I $(PROJECT) NEQ BASIC \
		(if /I $(MTK_SUBSIDIARY) EQU TRUE \
		(if exist plutommi\Customer\ResGenerator\res_parse_screen_id.pl \
		(@perl plutommi\Customer\ResGenerator\res_parse_screen_id.pl $(strip $(MMI_VERSION))) & \
		(if ERRORLEVEL 1 exit 1)) & \
		($(CGEN) -cm $(strip $(TST_DB))\BPLGUInfoCustomSrc $(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOM)) $(strip $(TST_DB))\msglog_db\custom_pri.db $(strip $(TST_DB))\enumFileCustomSrc $(strip $(PLATFORM))_$(strip $(CHIP_VER)) $(strip $(VERNO)) -savFile-$(strip $(TSTDIR))\database\SaveFile.ini -prjName-$(strip $(PROJECT_NAME)) 2>>$(CODE_GEN_LOG)) & \
		(if ERRORLEVEL 1 exit 1) & \
		($(CGEN) -src $(MMI_SCR_ID_FILE) $(FIXPATH)\$(strip $(MMIDIR)) )& \
		(if ERRORLEVEL 1 exit 1) & \
		($(CC) -E -W -DGEN_FOR_CPARSER -DGEN_FOR_PC $(VIA) make\~inc_def.tmp -USTDC_HEADERS -o $(MMI_SCR_ID_DB) $(MMI_SCR_ID_FILE) 2>$(CODE_GEN_LOG)) & \
		(if ERRORLEVEL 1 exit 1) & \
		($(CGEN) -ap $(strip $(TST_DB))\BPLGUInfoCustomAppSrc $(strip $(TST_DB))\BPLGUInfoCustomSrc $(strip $(TST_DB))\msglog_db\app_pri.db $(strip $(TST_DB))\enumFileCustomAppSrc $(strip $(PLATFORM))_$(strip $(CHIP_VER)) $(strip $(VERNO)) $(MMI_SCR_ID_DB) 2>>$(CODE_GEN_LOG)) & \
		($(CGEN) -filter_gen src $(strip $(TST_DB))\BPLGUInfoCustomAppSrc $(strip $(TSTDIR))\database\log2SD_Catcher_filters.ini $(strip $(FIXPATH))\custom\tst\tst_file_default_Catcher_filter.c __TST_WRITE_TO_FILE__ 2>>$(CODE_GEN_LOG)) & \
		(if ERRORLEVEL 1 exit 1) & \
		(if exist $(MMI_SCR_ID_FILE) del /q $(MMI_SCR_ID_FILE) > nul) & \
		(if exist $(MMI_SCR_ID_DB) del /q $(MMI_SCR_ID_DB) > nul) & \
		(if exist $(strip $(TST_DB))\BPLGUInfoCustomSrc del /q $(strip $(TST_DB))\BPLGUInfoCustomSrc) & \
		(if exist $(strip $(TST_DB))\enumFileCustomSrc del /q $(strip $(TST_DB))\enumFileCustomSrc) \
		else \
		(if exist plutommi\Customer\ResGenerator\res_parse_screen_id.pl \
		(@perl plutommi\Customer\ResGenerator\res_parse_screen_id.pl $(strip $(MMI_VERSION))) & \
		(if ERRORLEVEL 1 exit 1)) & \
		($(CGEN) -cm $(strip $(TST_DB))\BPLGUInfoCustomAppSrc $(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOM)) $(strip $(TST_DB))\msglog_db\custom_pri.db $(strip $(TST_DB))\enumFileCustomAppSrc $(strip $(PLATFORM))_$(strip $(CHIP_VER)) $(strip $(VERNO)) -savFile-$(strip $(TSTDIR))\database\SaveFile.ini -prjName-$(strip $(PROJECT_NAME)) 2>>$(CODE_GEN_LOG)) & \
		($(CGEN) -filter_gen src $(strip $(TST_DB))\BPLGUInfoCustomAppSrc $(strip $(TSTDIR))\database\log2SD_Catcher_filters.ini $(strip $(FIXPATH))\custom\tst\tst_file_default_Catcher_filter.c __TST_WRITE_TO_FILE__ 2>>$(CODE_GEN_LOG)) & \
		(if ERRORLEVEL 1 exit 1)) & \
		(@echo $(strip $(TST_DB))\BPLGUInfoCustomAppSrc > $(CODE_GEN_LST)) \
	  )
endif
   # mbis time probe
$(strip $(TST_DB))\pstrace_db\$(SINGLE_HEADER):
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@tools\strcmpex.exe def def e $(strip $(TST_DB))\pstrace_db\$(SINGLE_HEADER) $(foreach comp,$(COMP_TRACE_DEFS), '#include"$(comp)"')
	@perl tools\lnitem.pl $(strip $(TST_DB))\pstrace_db\$(SINGLE_HEADER)
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

#	based on .h generate .ptr
.h.ptr:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$(@F),F,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@echo Preprocessing PS trace definition ... $<
	@if /I $(PROJECT) NEQ BASIC \
			(copy $(subst /,\,$<) ~$(basename $(notdir $(subst \,/,$<))).c >nul) & \
			($(CC) -E -W -DGEN_FOR_PC $(VIA) make\~inc_def.tmp -o $(strip $(TST_DB))\pstrace_db\$(basename $(notdir $(subst \,/,$<))).ptr ~$(basename $(notdir $(subst \,/,$<))).c 2>>$(CODE_GEN_LOG)) & \
			(if ERRORLEVEL 1 exit 1) & \
			(echo $(strip $(TST_DB))\pstrace_db\$(basename $(notdir $(subst \,/,$<))).ptr >> $(CODE_GEN_LST)) & \
			(if exist ~$(basename $(notdir $(subst \,/,$<))).c del ~$(basename $(notdir $(subst \,/,$<))).c)
			
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$(@F),F,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# -----------------------------
# B ==> Base information
# P ==> Protocol trace information
# L ==> Layer 1 trace information
# G ==> Global variable information
# V ==> Layer 1 validation information
# U ==> GSM/GPRS Union Information
# -----------------------------

# -----------------------------
# Step 2: Generate Base Information
# -----------------------------
ifeq ($(strip $(USE_CODEGEN_CFG)),TRUE)
$(strip $(TST_DB))\msglog_db\BInfo :  $(TST_GEN_DEP_OUTS) $(strip $(TST_DB))\pstrace_db\$(SINGLE_PTR) $(strip $(TSTDIR))\database\$(CGEN_DEF_FILE)
else
$(strip $(TST_DB))\msglog_db\BInfo :  $(TST_GEN_DEP_OUTS) $(PTR_GEN_OUTS) $(strip $(TSTDIR))\database\$(CGEN_DEF_FILE)
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifeq ($(strip $(USE_CODEGEN_CFG)),TRUE)
  ifneq ($(strip $(PROJECT)),BASIC)
    ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
			@echo Generate Base Information ...
			@echo $(CGEN) -c $(strip $(TST_DB))\msglog_db\pri.db $(strip $(TSTDIR))\database\$(CGEN_DEF_FILE) $(strip $(TSTDIR))\database\Pc_Cnf $(strip $(TST_DB))\msglog_db\BInfo $(strip $(TST_DB))\enumFile $(strip $(PLATFORM))_$(strip $(CHIP_VER)) $(strip $(VERNO)) -qModSim-$(strip $(TSTDIR))\src\tst_querysimid.c -savFile-$(strip $(TSTDIR))\database\SaveFile.ini -prjName-$(strip $(PROJECT_NAME)) >>$(CGEN_CFG_FILE)
    endif
  endif
else
	@if /I $(PROJECT) NEQ BASIC \
		(@if /I $(CUSTOM_RELEASE) EQU FALSE   \
			(echo Generate Base Information ...) & \
			(if exist plutommi\Customer\ResGenerator\res_parse_screen_id.pl \
			(@perl plutommi\Customer\ResGenerator\res_parse_screen_id.pl $(strip $(MMI_VERSION))) & \
			(if ERRORLEVEL 1 exit 1)) & \
			($(CGEN) -c $(strip $(TST_DB))\msglog_db\pri.db $(strip $(TSTDIR))\database\$(CGEN_DEF_FILE) $(strip $(TSTDIR))\database\Pc_Cnf $(strip $(TST_DB))\msglog_db\BInfo $(strip $(TST_DB))\enumFile $(strip $(PLATFORM))_$(strip $(CHIP_VER)) $(strip $(VERNO)) -qModSim-$(strip $(TSTDIR))\src\tst_querysimid.c -savFile-$(strip $(TSTDIR))\database\SaveFile.ini -prjName-$(strip $(PROJECT_NAME)) 2>>$(CODE_GEN_LOG)) & \
			(if ERRORLEVEL 1 exit 1) & \
			(echo $(strip $(TST_DB))\msglog_db\BInfo >> $(CODE_GEN_LST)) & \
			(echo $(strip $(TST_DB))\enumFile >> $(CODE_GEN_LST)) \
		)
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# -----------------------------
# Step 3: Protocol trace information
# -----------------------------
$(strip $(TST_GEN_DEP_STP3_OUTS)) : $(strip $(TST_GEN_DEP_STP3_SRCS))
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifeq ($(strip $(USE_CODEGEN_CFG)),TRUE)
	@if /I $(PROJECT) NEQ BASIC \
		(@if /I $(CUSTOM_RELEASE) EQU FALSE   \
			(echo Generate PS Trace Information ...) & \
			(echo $(CGEN) -ps $(strip $(TST_DB))\pstrace_db\BPInfo $(strip $(TST_DB))\msglog_db\BInfo $(strip $(TST_DB))\pstrace_db $(strip $(TST_DB))\pstrace_db\ps_trace_1.h >>$(CGEN_CFG_FILE)) &\
			(echo $(CGEN) -rle $(strip $(TST_DB))\pstrace_db\ps_trace.h $(strip $(TST_DB))\pstrace_db\ps_trace_1.h >>$(CGEN_CFG_FILE)) \
		else \
			(echo Generate PS Trace Information ...) & \
			(echo $(CGEN) -ps $(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOMSRCP)) $(strip $(TST_DB))\BPLGUInfoCustomAppSrc $(strip $(TST_DB))\pstrace_db $(strip $(TST_DB))\pstrace_db\ps_trace_1.h >>$(CGEN_CFG_FILE)) & \
			(echo $(CGEN) -rle $(strip $(TST_DB))\pstrace_db\ps_trace.h $(strip $(TST_DB))\pstrace_db\ps_trace_1.h >>$(CGEN_CFG_FILE)) \
		) 
else
	@if /I $(PROJECT) NEQ BASIC \
		(@if /I $(CUSTOM_RELEASE) EQU FALSE   \
			(echo Generate PS Trace Information ...) & \
			(if exist plutommi\Customer\ResGenerator\res_parse_screen_id.pl \
			(@perl plutommi\Customer\ResGenerator\res_parse_screen_id.pl $(strip $(MMI_VERSION))) & \
			(if ERRORLEVEL 1 exit 1)) & \
			($(CGEN) -ps $(strip $(TST_DB))\pstrace_db\BPInfo $(strip $(TST_DB))\msglog_db\BInfo $(strip $(TST_DB))\pstrace_db $(strip $(TST_DB))\pstrace_db\ps_trace_1.h 2>>$(CODE_GEN_LOG)) & \
			($(CGEN) -rle $(strip $(TST_DB))\pstrace_db\ps_trace.h $(strip $(TST_DB))\pstrace_db\ps_trace_1.h 2>>$(CODE_GEN_LOG)) & \
			(if ERRORLEVEL 1 exit 1) & \
			(echo $(strip $(TST_DB))\pstrace_db\BPInfo >> $(CODE_GEN_LST)) & \
			(echo $(strip $(TST_DB))\msglog_db\BInfo >> $(CODE_GEN_LST)) & \
			(echo $(strip $(TST_DB))\pstrace_db\ps_trace.h >> $(CODE_GEN_LST)) & \
			(if exist $(strip $(TST_DB))\pstrace_db\ps_trace_1.h del /q $(strip $(TST_DB))\pstrace_db\ps_trace_1.h > nul) & \
			(if exist $(strip $(TST_DB))\msglog_db\BInfo del /q $(strip $(TST_DB))\msglog_db\BInfo > nul) \
		)
	@if /I $(PROJECT) NEQ BASIC \
		(@if /I $(CUSTOM_RELEASE) EQU TRUE   \
			(echo Generate PS Trace Information ...) & \
			(if exist plutommi\Customer\ResGenerator\res_parse_screen_id.pl \
			(@perl plutommi\Customer\ResGenerator\res_parse_screen_id.pl $(strip $(MMI_VERSION))) & \
			(if ERRORLEVEL 1 exit 1)) & \
			($(CGEN) -ps $(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOMSRCP)) $(strip $(TST_DB))\BPLGUInfoCustomAppSrc $(strip $(TST_DB))\pstrace_db $(strip $(TST_DB))\pstrace_db\ps_trace_1.h 2>$(CODE_GEN_LOG)) & \
			($(CGEN) -rle $(strip $(TST_DB))\pstrace_db\ps_trace.h $(strip $(TST_DB))\pstrace_db\ps_trace_1.h 2>>$(CODE_GEN_LOG)) & \
			(if ERRORLEVEL 1 exit 1) & \
			(echo $(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOMSRCP)) >> $(CODE_GEN_LST)) & \
			(echo $(strip $(TST_DB))\pstrace_db\ps_trace.h >> $(CODE_GEN_LST)) & \
			(if exist $(strip $(TST_DB))\pstrace_db\ps_trace_1.h del /q $(strip $(TST_DB))\pstrace_db\ps_trace_1.h > nul) & \
			(if exist $(strip $(TST_DB))\BPLGUInfoCustomAppSrc del /q $(strip $(TST_DB))\BPLGUInfoCustomAppSrc > nul) \
		)
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# -----------------------------
# Step 4: Layer 1 trace information
# -----------------------------
$(strip $(TST_DB))\l1trace_db\BPLInfo : $(strip $(TST_DB))\pstrace_db\BPInfo $(TMD_FILES)
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))		
ifeq ($(strip $(USE_CODEGEN_CFG)),TRUE)
  ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
    ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
			@echo Generate L1 Trace Information ...
      ifeq ($(strip $(TMD_FILES)),)
				@echo $(CGEN) -L1 $(strip $(TST_DB))\l1trace_db\BPLInfo $(strip $(TST_DB))\pstrace_db\BPInfo L1_CATCHER $(strip $(TSTDIR))\src\TrcMod.c $(strip $(TSTDIR))\include\TrcMod.h $(TMD_FILES) >>$(CGEN_CFG_FILE)
      else
				@echo $(CGEN) -L1 $(strip $(TST_DB))\l1trace_db\BPLInfo $(strip $(TST_DB))\pstrace_db\BPInfo L1_CATCHER $(strip $(TSTDIR))\src\TrcMod.c $(strip $(TSTDIR))\include\TrcMod.h $(strip $(TSTDIR))\database\L1ModMsg.chk $(TMD_FILES) >>$(CGEN_CFG_FILE)
      endif
    endif
  endif
else
  ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
    ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
			@echo Generate L1 Trace Information ...
			@(if exist plutommi\Customer\ResGenerator\res_parse_screen_id.pl \
			(@perl plutommi\Customer\ResGenerator\res_parse_screen_id.pl $(strip $(MMI_VERSION))) & \
			(if ERRORLEVEL 1 exit 1))
      ifeq ($(strip $(TMD_FILES)),)
				@($(CGEN) -L1 $(strip $(TST_DB))\l1trace_db\BPLInfo $(strip $(TST_DB))\pstrace_db\BPInfo L1_CATCHER $(strip $(TSTDIR))\src\TrcMod.c $(strip $(TSTDIR))\include\TrcMod.h $(TMD_FILES) 2>>$(CODE_GEN_LOG)) & \
				(if ERRORLEVEL 1 exit 1)
      else
				@($(CGEN) -L1 $(strip $(TST_DB))\l1trace_db\BPLInfo $(strip $(TST_DB))\pstrace_db\BPInfo L1_CATCHER $(strip $(TSTDIR))\src\TrcMod.c $(strip $(TSTDIR))\include\TrcMod.h $(strip $(TSTDIR))\database\L1ModMsg.chk $(TMD_FILES) 2>>$(CODE_GEN_LOG)) & \
				(if ERRORLEVEL 1 exit 1)
      endif
			@echo $(strip $(TST_DB))\l1trace_db\BPLInfo >> $(CODE_GEN_LST)
			@echo $(strip $(TSTDIR))\src\TrcMod.c >> $(CODE_GEN_LST)
			@echo $(strip $(TSTDIR))\include\TrcMod.h >> $(CODE_GEN_LST)
    endif
  endif

	@if /I $(PROJECT) NEQ BASIC \
		(@if /I $(CUSTOM_RELEASE) EQU FALSE   \
			(for /d %%i in ($(TMD_GEN_C_H_FILES)) do \
			   (echo %%i >> $(CODE_GEN_LST)) \
			) & \
			(if exist $(strip $(TST_DB))\pstrace_db\BPInfo del /q $(strip $(TST_DB))\pstrace_db\BPInfo > nul) \
		)
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# -----------------------------
# Step 5: Result temporary - Global variable information
# -----------------------------
$(strip $(TST_DB))\BPLGInfo : $(strip $(TST_DB))\l1trace_db\BPLInfo $(GV_FILES)
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))		
ifeq ($(strip $(USE_CODEGEN_CFG)),TRUE)
	@if /I $(PROJECT) NEQ BASIC \
		(@if /I $(CUSTOM_RELEASE) EQU FALSE   \
			(echo Generate Global variable Information ...) & \
			(echo $(CGEN) -gv $(strip $(TST_DB))\BPLGInfo $(strip $(TST_DB))\l1trace_db\BPLInfo $(strip $(TST_DB))\gv\gv_db\ $(strip $(TSTDIR))\src\gvTbl.c >>$(CGEN_CFG_FILE)) \
		)
else
	@if /I $(PROJECT) NEQ BASIC \
		(@if /I $(CUSTOM_RELEASE) EQU FALSE   \
			(echo Generate Global variable Information ...) & \
			(if exist plutommi\Customer\ResGenerator\res_parse_screen_id.pl \
			(@perl plutommi\Customer\ResGenerator\res_parse_screen_id.pl $(strip $(MMI_VERSION))) & \
			(if ERRORLEVEL 1 exit 1)) & \
			($(CGEN) -gv $(strip $(TST_DB))\BPLGInfo $(strip $(TST_DB))\l1trace_db\BPLInfo $(strip $(TST_DB))\gv\gv_db\ $(strip $(TSTDIR))\src\gvTbl.c 2>>$(CODE_GEN_LOG)) & \
			(if ERRORLEVEL 1 exit 1) & \
			(echo $(strip $(TST_DB))\BPLGInfo >> $(CODE_GEN_LST)) & \
			(if exist $(strip $(TST_DB))\l1trace_db\BPLInfo del /q $(strip $(TST_DB))\l1trace_db\BPLInfo > nul) \
		)
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# -----------------------------
# Step 6:  Result - Layer 1 validation information (L1S)
# -----------------------------
$(strip $(TST_DB))\l1validation_db\BPLVInfo :  $(strip $(TST_DB))\BPLGInfo $(L1V_FILES)
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifeq ($(strip $(USE_CODEGEN_CFG)),TRUE)
	@if /I $(PROJECT) NEQ BASIC \
		(@if /I $(CUSTOM_RELEASE) EQU FALSE   \
			(echo Generate L1 Validation Information ...) & \
			(echo $(CGEN) -L1V $(strip $(TST_DB))\l1validation_db\BPLVInfo $(strip $(TST_DB))\BPLGInfo $(strip $(TST_DB))\l1validation_db\l1v_db\ >>$(CGEN_CFG_FILE)) \
		)
else
	@if /I $(PROJECT) NEQ BASIC \
		(@if /I $(CUSTOM_RELEASE) EQU FALSE   \
			(echo Generate L1 Validation Information ...) & \
			(if exist plutommi\Customer\ResGenerator\res_parse_screen_id.pl \
			(@perl plutommi\Customer\ResGenerator\res_parse_screen_id.pl $(strip $(MMI_VERSION))) & \
			(if ERRORLEVEL 1 exit 1)) & \
			($(CGEN) -L1V $(strip $(TST_DB))\l1validation_db\BPLVInfo $(strip $(TST_DB))\BPLGInfo $(strip $(TST_DB))\l1validation_db\l1v_db\ 2>>$(CODE_GEN_LOG)) & \
			(if ERRORLEVEL 1 exit 1) & \
			(echo $(strip $(TST_DB))\l1validation_db\BPLVInfo >> $(CODE_GEN_LST)) & \
			(if exist $(strip $(TST_DB))\BPLGInfo del /q $(strip $(TST_DB))\BPLGInfo > nul) \
		)
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# -----------------------------
# Step 7: Result - Union Information (GSM/GPRS)
#------------------------------
$(strip $(TST_DB))\BPLGUInfo :  $(strip $(TST_DB))\BPLGInfo $(strip $(TST_DB))\unionTag\unionTag_parse.txt
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifeq ($(strip $(USE_CODEGEN_CFG)),TRUE)
	@if /I $(PROJECT) NEQ BASIC \
		(@if /I $(CUSTOM_RELEASE) EQU FALSE   \
			(echo Generate Union Information ...) & \
			(echo $(CGEN) -un $(strip $(TST_DB))\BPLGUInfo $(strip $(TST_DB))\BPLGInfo $(strip $(TST_DB))\unionTag\unionTag_parse.txt >>$(CGEN_CFG_FILE)) \
		)
else
	@if /I $(PROJECT) NEQ BASIC \
		(@if /I $(CUSTOM_RELEASE) EQU FALSE   \
			(echo Generate Union Information ...) & \
			(if exist plutommi\Customer\ResGenerator\res_parse_screen_id.pl \
			(@perl plutommi\Customer\ResGenerator\res_parse_screen_id.pl $(strip $(MMI_VERSION))) & \
			(if ERRORLEVEL 1 exit 1)) & \
			($(CGEN) -un $(strip $(TST_DB))\BPLGUInfo $(strip $(TST_DB))\BPLGInfo $(strip $(TST_DB))\unionTag\unionTag_parse.txt 2>>$(CODE_GEN_LOG)) & \
			(if ERRORLEVEL 1 exit 1) & \
			(echo $(strip $(TST_DB))\BPLGUInfo >> $(CODE_GEN_LST)) & \
			(if exist $(strip $(TST_DB))\BPLGInfo del /q $(strip $(TST_DB))\BPLGInfo > nul) \
		)
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# ------------------------------------------
# Step 8: Result - Merge customization code
# ------------------------------------------
$(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOM)) :  $(strip $(TST_DB))\BPLGUInfo genmoduleinfo
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@tools\strcmpex.exe def def e make\~inc_def.tmp $(foreach def,$(COM_DEFS),-D$(def))
	@echo -D__NULL_DEF__ >> make\~inc_def.tmp

	@perl tools\echoLongString2.pl make\~inc_def.tmp -D $(COM_DEF_PATH)

	@tools\strcmpex.exe inc inc e make\~inc.tmp $(foreach inc,$(COMMINCDIRS),-I$(inc))
	@type make\~inc.tmp >> make\~inc_def.tmp
ifeq ($(strip $(USE_CODEGEN_CFG)),TRUE)
  ifneq ($(strip $(PROJECT)),BASIC)
    ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
			@echo Merge customization code ...
			@($(CC) -E -W -DGEN_FOR_CPARSER -DGEN_FOR_PC $(VIA) make\~inc_def.tmp -USTDC_HEADERS -o $(strip $(TST_DB))\msglog_db\custom_pri.db $(strip $(TSTDIR))\database\msglog_db\custom_parse_db.c 2>>$(CODE_GEN_LOG)) & \
				(if ERRORLEVEL 1 exit 1)
			@($(CC) -M -W -DGEN_FOR_CPARSER -DGEN_FOR_PC $(VIA) make\~inc_def.tmp -USTDC_HEADERS -o $(strip $(TST_DB))\msglog_db\custom_parse_db.obj $(strip $(TSTDIR))\database\msglog_db\custom_parse_db.c $(DEPEND) $(strip $(RULESDIR))\custom_parse_db.d 2>$(CODE_GEN_LOG)) & \
				(if ERRORLEVEL 1 exit 1)
			@echo Compile app_parse_db.c
			@($(CC) -E -W -DGEN_FOR_CPARSER -DGEN_FOR_PC $(VIA) make\~inc_def.tmp -USTDC_HEADERS -o $(strip $(TST_DB))\msglog_db\app_pri.db $(strip $(TSTDIR))\database\msglog_db\app_parse_db.c 2>>$(CODE_GEN_LOG)) & \
				(if ERRORLEVEL 1 exit 1)
			@($(CC) -M -W -DGEN_FOR_CPARSER -DGEN_FOR_PC $(VIA) make\~inc_def.tmp -USTDC_HEADERS -o $(strip $(TST_DB))\msglog_db\app_parse_db.obj $(strip $(TSTDIR))\database\msglog_db\app_parse_db.c $(DEPEND) $(strip $(RULESDIR))\app_parse_db.d 2>>$(CODE_GEN_LOG)) & \
				(if ERRORLEVEL 1 exit 1)
			@echo Compiling app_parse_db.c was done.
			@echo $(CGEN) -cm $(strip $(TST_DB))\BPLGUInfoCustom $(strip $(TST_DB))\BPLGUInfo $(strip $(TST_DB))\msglog_db\custom_pri.db $(strip $(TST_DB))\enumFileCustom $(strip $(PLATFORM))_$(strip $(CHIP_VER)) $(strip $(VERNO)) -savFile-$(strip $(TSTDIR))\database\SaveFile.ini -prjName-$(strip $(PROJECT_NAME)) >>$(CGEN_CFG_FILE)
			@($(CGEN) -src $(MMI_SCR_ID_FILE) $(FIXPATH)\$(strip $(MMIDIR)) )& \
				(if ERRORLEVEL 1 exit 1)
			@($(CC) -E -W -DGEN_FOR_CPARSER -DGEN_FOR_PC $(VIA) make\~inc_def.tmp -USTDC_HEADERS -o $(MMI_SCR_ID_DB) $(MMI_SCR_ID_FILE) 2>$(CODE_GEN_LOG)) & \
				(if ERRORLEVEL 1 exit 1)
			@echo $(CGEN) -ap $(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOM)) $(strip $(TST_DB))\BPLGUInfoCustom $(strip $(TST_DB))\msglog_db\app_pri.db $(strip $(TST_DB))\enumFileCustomApp $(strip $(PLATFORM))_$(strip $(CHIP_VER)) $(strip $(VERNO)) $(MMI_SCR_ID_DB) >>$(CGEN_CFG_FILE)
			@echo $(CGEN) -filter_gen src $(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOM)) $(strip $(TSTDIR))\database\log2SD_Catcher_filters.ini $(strip $(FIXPATH))\custom\tst\tst_file_default_Catcher_filter.c __TST_WRITE_TO_FILE__ >>$(CGEN_CFG_FILE)
    endif
  endif
else
  ifneq ($(strip $(PROJECT)),BASIC)
    ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
			@echo Merge customization code ...
			@($(CC) -E -W -DGEN_FOR_CPARSER -DGEN_FOR_PC $(VIA) make\~inc_def.tmp -USTDC_HEADERS -o $(strip $(TST_DB))\msglog_db\custom_pri.db $(strip $(TSTDIR))\database\msglog_db\custom_parse_db.c 2>$(CODE_GEN_LOG)) & \
				(if ERRORLEVEL 1 exit 1)
			@($(CC) -M -W -DGEN_FOR_CPARSER -DGEN_FOR_PC $(VIA) make\~inc_def.tmp -USTDC_HEADERS -o $(strip $(TST_DB))\msglog_db\custom_parse_db.obj $(strip $(TSTDIR))\database\msglog_db\custom_parse_db.c $(DEPEND) $(strip $(RULESDIR))\custom_parse_db.d 2>$(CODE_GEN_LOG)) & \
				(if ERRORLEVEL 1 exit 1)
			@echo Compile app_parse_db.c
			@($(CC) -E -W -DGEN_FOR_CPARSER -DGEN_FOR_PC $(VIA) make\~inc_def.tmp -USTDC_HEADERS -o $(strip $(TST_DB))\msglog_db\app_pri.db $(strip $(TSTDIR))\database\msglog_db\app_parse_db.c 2>>$(CODE_GEN_LOG)) & \
				(if ERRORLEVEL 1 exit 1)
			@($(CC) -M -W -DGEN_FOR_CPARSER -DGEN_FOR_PC $(VIA) make\~inc_def.tmp -USTDC_HEADERS -o $(strip $(TST_DB))\msglog_db\app_parse_db.obj $(strip $(TSTDIR))\database\msglog_db\app_parse_db.c $(DEPEND) $(strip $(RULESDIR))\app_parse_db.d 2>>$(CODE_GEN_LOG)) & \
				(if ERRORLEVEL 1 exit 1)
			@echo Compiling app_parse_db.c was done.
			@(if exist plutommi\Customer\ResGenerator\res_parse_screen_id.pl \
				(@perl plutommi\Customer\ResGenerator\res_parse_screen_id.pl $(strip $(MMI_VERSION))) & \
				(if ERRORLEVEL 1 exit 1))
			@($(CGEN) -cm $(strip $(TST_DB))\BPLGUInfoCustom $(strip $(TST_DB))\BPLGUInfo $(strip $(TST_DB))\msglog_db\custom_pri.db $(strip $(TST_DB))\enumFileCustom $(strip $(PLATFORM))_$(strip $(CHIP_VER)) $(strip $(VERNO)) -savFile-$(strip $(TSTDIR))\database\SaveFile.ini -prjName-$(strip $(PROJECT_NAME)) 2>>$(CODE_GEN_LOG)) & \
				(if ERRORLEVEL 1 exit 1)
			@($(CGEN) -src $(MMI_SCR_ID_FILE) $(FIXPATH)\$(strip $(MMIDIR)) )& \
				(if ERRORLEVEL 1 exit 1)
			@($(CC) -E -W -DGEN_FOR_CPARSER -DGEN_FOR_PC $(VIA) make\~inc_def.tmp -USTDC_HEADERS -o $(MMI_SCR_ID_DB) $(MMI_SCR_ID_FILE) 2>$(CODE_GEN_LOG)) & \
				(if ERRORLEVEL 1 exit 1)
			@(if exist plutommi\Customer\ResGenerator\res_parse_screen_id.pl \
				(@perl plutommi\Customer\ResGenerator\res_parse_screen_id.pl $(strip $(MMI_VERSION))) & \
				(if ERRORLEVEL 1 exit 1))
			@($(CGEN) -ap $(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOM)) $(strip $(TST_DB))\BPLGUInfoCustom $(strip $(TST_DB))\msglog_db\app_pri.db $(strip $(TST_DB))\enumFileCustomApp $(strip $(PLATFORM))_$(strip $(CHIP_VER)) $(strip $(VERNO)) $(MMI_SCR_ID_DB) 2>>$(CODE_GEN_LOG)) & \
				(if ERRORLEVEL 1 exit 1)
			@($(CGEN) -filter_gen src $(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOM)) $(strip $(TSTDIR))\database\log2SD_Catcher_filters.ini $(strip $(FIXPATH))\custom\tst\tst_file_default_Catcher_filter.c __TST_WRITE_TO_FILE__ >>$(CGEN_CFG_FILE)) &\
				(if ERRORLEVEL 1 exit 1)
			@if exist $(MMI_SCR_ID_FILE) del /q $(MMI_SCR_ID_FILE) > nul
			@if exist $(MMI_SCR_ID_DB) del /q $(MMI_SCR_ID_DB) > nul
			@if exist $(strip $(TST_DB))\BPLGUInfo del /q $(strip $(TST_DB))\BPLGUInfo > nul
			@if exist $(strip $(TST_DB))\BPLGUInfoCustom del /q $(strip $(TST_DB))\BPLGUInfoCustom > nul
    endif
  endif
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# Disable Step 9 due to this flow is not used now.

# ------------------------------------------
# Step 10: Verify codegen database
# ------------------------------------------
check_db:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@if /I $(PROJECT) NEQ BASIC \
		(@if /I $(CUSTOM_RELEASE) EQU FALSE   \
			((echo Checking database... $(DB_CHECK) $(CODEGEN_RESULT)) & \
			($(DB_CHECK) $(CODEGEN_RESULT) >$(DB_CHECK_LOG)) & \
			(if ERRORLEVEL 1 \
				echo ERROR!! Please check interface\ps\nvram_data_items.h & \
				exit)) \
		)
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

xml_parser:
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'xml_parser START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log

ifeq ($(filter ANDROID_MODEM,$(strip $(SMART_PHONE_CORE))),)
ifneq ($(filter PLUTO_MMI VENUS_MMI,$(strip $(MMI_BASE))),)
ifeq ($(filter EMPTY_MMI,$(strip $(MMI_VERSION))),)
ifneq ($(strip $(call Upper,$(LEVEL))),VENDOR)
	@if exist $(MMIDIR)\customer \
		(@if /I $(RUN_RESGEN) EQU TRUE \
			(echo CUSTOM_OPTION = $(foreach def,$(BOARD_VER) $(PLATFORM) $(LCD_MODULE) $(EXT_CAM_MODULE) $(CMOS_SENSOR),-D "$(def)") \> $(MMIDIR)\customer\resGenerator\custom_option.txt) \
		)
		
	@tools\strcmpex.exe TRUE TRUE e make\~cus_opt.tmp $(foreach def,$(sort $(COM_DEFS)),-D \"$(def)\")
	@if exist $(MMIDIR)\customer \
		(@if /I $(RUN_RESGEN) EQU TRUE \
			(type make\~cus_opt.tmp >> $(MMIDIR)\customer\resGenerator\custom_option.txt) \
		)
		
	@tools\strcmpex.exe TRUE TRUE e make\~inc.tmp $(foreach inc,$(COMMINCDIRS),$(inc))
	@if exist $(MMIDIR)\customer \
		(@if /I $(RUN_RESGEN) EQU TRUE \
			(type make\~inc.tmp > $(MMIDIR)\customer\resGenerator\custom_include.tmp) & \
			(@perl -e "open F,'<$(MMIDIR)\customer\resGenerator\custom_include.tmp';my $$i=join('',<F>);close F;$$i =~s/\s+/ /gs;$$i =~ s/(\S+)/-I \"..\\..\\..\\$$1\"/gs;print \"CUSTOM_INC = $$i\";" > $(MMIDIR)\customer\resGenerator\custom_include.txt) \
		)
		
endif
		
ifdef OPTR_SPEC
  ifneq ($(strip $(OPTR_SPEC)),NONE)
	@if exist $(MMIDIR)\customer\replace_project_name.pl \
		(@if exist $(OPTR_PATH)\ResGenerator_OP.tmp \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(OPTR_PATH)\ResGenerator_OP.tmp {OP_NAME} $(strip $(word 1,$(subst _, ,$(OPTR_SPEC)))) $(OPTR_PATH)\ResGenerator_OP.bat) & \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(OPTR_PATH)\ResGenerator_OP.bat {VER_NUM} $(strip $(word 2,$(subst _, ,$(OPTR_SPEC)))) $(OPTR_PATH)\ResGenerator_OP.bat) & \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(OPTR_PATH)\ResGenerator_OP.bat {SEG_NAME} $(strip $(word 3,$(subst _, ,$(OPTR_SPEC)))) $(OPTR_PATH)\ResGenerator_OP.bat)  \
		) & \
		(@if exist $(OPTR_PATH)\operator_CustResDef.tmp \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(OPTR_PATH)\operator_CustResDef.tmp {OP_NAME} $(strip $(word 1,$(subst _, ,$(OPTR_SPEC)))) $(OPTR_PATH)\operator_CustResDef.h) & \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(OPTR_PATH)\operator_CustResDef.h {VER_NUM} $(strip $(word 2,$(subst _, ,$(OPTR_SPEC)))) $(OPTR_PATH)\operator_CustResDef.h) & \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(OPTR_PATH)\operator_CustResDef.h {SEG_NAME} $(strip $(word 3,$(subst _, ,$(OPTR_SPEC)))) $(OPTR_PATH)\operator_CustResDef.h) ) 
  endif
endif

  # generate a dummy ps_trace.h
ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
ifneq ($(strip $(call Upper,$(PROJECT))),UDVT)
	-@if not exist $(strip $(PSTRACE_DB_DIR)) \
		md $(strip $(PSTRACE_DB_DIR))
	@if not exist $(strip $(TST_DB))\pstrace_db\ps_trace.h \
		((echo #ifdef PSTRC_Mainh_DEF_H > $(strip $(TST_DB))\pstrace_db\ps_trace.h) & \
		(echo #undef PSTRC_Mainh_DEF_H >> $(strip $(TST_DB))\pstrace_db\ps_trace.h) & \
		(echo #endif >> $(strip $(TST_DB))\pstrace_db\ps_trace.h))
endif
endif

	@if not exist plutommi\customer\ResGenerator_XML.bat \
	(@if exist $(MMIDIR)\customer\replace_project_name.pl \
	(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator_XML.tmp XXX $(patsubst %_MMI,%,$(MMI_VERSION)) $(MMIDIR)\customer\ResGenerator_XML.bat) & \
	(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator_XML.bat YYY $(patsubst %_MMI,%,$(CUSTOMER)) $(MMIDIR)\customer\ResGenerator_XML.bat) & \
	(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator_XML.bat SSS $(call Upper,$(strip $(OPTR_SPEC))) $(MMIDIR)\customer\ResGenerator_XML.bat) & \
	(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator_XML.bat MMM $(call Upper,$(strip $(MAIN_LCD_SIZE))) $(MMIDIR)\customer\ResGenerator_XML.bat) & \
	(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator_XML.bat PPP $(strip $(OPTR_PATH)) $(MMIDIR)\customer\ResGenerator_XML.bat) & \
	(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator_XML.bat QQQ $(call Upper,$(strip $(TOUCH_PANEL_SUPPORT))) $(MMIDIR)\customer\ResGenerator_XML.bat))
				
	@if exist $(MMIDIR)\customer\ResGenerator_XML.bat \
	($(MMIDIR)\customer\ResGenerator_XML.bat $(MMI_VERSION) $(CUSTOMER) B C)  
endif
endif
endif

	@perl -e "print 'xml_parser END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# *************************************************************************
# nvram_auto_gen
# *************************************************************************
nvram_auto_gen : 
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'nvram_auto_gen START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
#nvram_auto_gen : gencustominfo
	@tools\strcmpex.exe TRUE TRUE e make\~cus_opt.tmp $(foreach def,$(sort $(COM_DEFS)),-D \"$(def)\")
	@tools\strcmpex.exe TRUE TRUE e make\~inc.tmp $(foreach inc,$(sort $(COMMINCDIRS)),$(inc))

ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
ifneq ($(strip $(call Upper,$(PROJECT))),UDVT)
	-@if not exist $(strip $(PSTRACE_DB_DIR)) \
		md $(strip $(PSTRACE_DB_DIR))
	@if not exist $(strip $(TST_DB))\pstrace_db\ps_trace.h \
		((echo #ifdef PSTRC_Mainh_DEF_H > $(strip $(TST_DB))\pstrace_db\ps_trace.h) & \
		(echo #undef PSTRC_Mainh_DEF_H >> $(strip $(TST_DB))\pstrace_db\ps_trace.h) & \
		(echo #endif >> $(strip $(TST_DB))\pstrace_db\ps_trace.h))
	@if exist $(MMIDIR)\customer \
		((echo CUSTOM_FOLDER = $(foreach def,$(BOARD_VER),$(def))> tools\NVRAMStatistic\include\custom_option.txt) & \
		(echo MMI_FOLDER = $(foreach def,$(MMI_BASE),$(def))>> tools\NVRAMStatistic\include\custom_option.txt) & \
		(echo CUSTOM_OPTION = \>> tools\NVRAMStatistic\include\custom_option.txt) & \
		(type make\~cus_opt.tmp >> tools\NVRAMStatistic\include\custom_option.txt))

	@if exist $(MMIDIR)\customer \
		(@perl -e "open F,'<make\~inc.tmp';my $$i=join('',<F>);close F;$$i =~s/\s+/ /gs;$$i =~ s/(\S+)/-I \"..\\..\\..\\$$1\"/gs;print \"CUSTOM_INC = $$i\";" > tools\NVRAMStatistic\include\custom_include.txt)

   #Output NVRAM info
   ifneq ($(filter WM_MODEM ANDROID_MODEM,$(strip $(SMART_PHONE_CORE))),)
     ifdef OPTR_SPEC
      ifneq ($(strip $(OPTR_SPEC)),NONE)
			@if exist tools\NVRAMStatistic\include \
			(tools\NVRAMStatistic\NVRAMAutogen.bat $(strip $(CUSTOMER)) $(strip $(BOARD_VER)) ..\..\..\$(strip $(OPTR_PATH)\$(word 3,$(subst _, ,$(OPTR_SPEC))))\custom\app 1 $(strip $(call Upper,$(LEVEL))) $(strip $(call Upper,$(CUSTOM_RELEASE))))
      else
			@if exist tools\NVRAMStatistic\include \
			(tools\NVRAMStatistic\NVRAMAutogen.bat $(strip $(CUSTOMER)) $(strip $(BOARD_VER)) NONE 1 $(strip $(call Upper,$(LEVEL))) $(strip $(call Upper,$(CUSTOM_RELEASE))))
      endif
    endif
  else
    ifdef OPTR_SPEC
      ifneq ($(strip $(OPTR_SPEC)),NONE)
			@if exist tools\NVRAMStatistic\include \
			(tools\NVRAMStatistic\NVRAMAutogen.bat $(strip $(CUSTOMER)) $(strip $(BOARD_VER)) ..\..\..\$(strip $(OPTR_PATH)\$(word 3,$(subst _, ,$(OPTR_SPEC))))\custom\app 0 $(strip $(call Upper,$(LEVEL))) $(strip $(call Upper,$(CUSTOM_RELEASE))))
      else
			@if exist tools\NVRAMStatistic\include \
			(tools\NVRAMStatistic\NVRAMAutogen.bat $(strip $(CUSTOMER)) $(strip $(BOARD_VER)) NONE 0 $(strip $(call Upper,$(LEVEL))) $(strip $(call Upper,$(CUSTOM_RELEASE))))
      endif
    endif
  endif
endif
endif

	@if exist $(strip $(RULESDIR))\nvram_auto_gen.dep (del /q $(strip $(RULESDIR))\nvram_auto_gen.dep)
	@if exist tools\NVRAMStatistic\debug\nvram_auto_gen.dep (copy /y tools\NVRAMStatistic\debug\nvram_auto_gen.dep $(strip $(RULESDIR))\nvram_auto_gen.dep >NUL)
	@if exist $(strip $(TST_DB))\BPLGUInfoCustomAppSrc (del /q $(strip $(TST_DB))\BPLGUInfoCustomAppSrc)

	@perl -e "print 'nvram_auto_gen END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# *************************************************************************
# Clean Generated Code Sources
# *************************************************************************
cleancodegen:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))	
	@perl -e "print 'cleancodegen START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
	@echo clean codegen list
   # $(CODE_GEN_LST) should be copied to another place then delete
	-@if exist $(CODE_GEN_LST)						         \
		(copy $(CODE_GEN_LST) make\~codegenlis.tmp) &   \
		(@for /f %%i in ($(CODE_GEN_LST)) do 	         \
			(@if exist %%i	(del %%i))                                    \
		)
	@perl -e "print 'cleancodegen END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# *************************************************************************
#  Executable Targets
# *************************************************************************
$(BIN_FILE):
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,B,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'LINKING START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log

	@echo Linking $(strip $(NEWTARGNAME)) ...
	@perl tools\time.pl -n
	@echo $(LNKOPT) $(INITLIB)(bootarm.obj) > make\~libs.tmp
	@for /d %%i in ($(COMPLIST)) do \
		@if /I "%%i" NEQ "rompatch" \
			(if /I "%%i" NEQ "wndrv" \
				(echo $(COMPLIBDIR)\%%i.lib >> make\~libs.tmp) \
			else \
				(if "$(strip $(WIFI_SUPPORT))" EQU "MT5911" \
					(echo $(FIXPATH)\custom\drv\wifi\$(strip $(BOARD_VER))\$(strip $(FLAVOR))\wndrv.lib >> make\~libs.tmp) \
				else \
					(echo $(COMPLIBDIR)\%%i.lib >> make\~libs.tmp)))

ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
	@if /I "$(strip $(MAUI_IN_ROM))" EQU "TRUE" \
		echo $(CUS_MTK_LIB)\rompatch.lib(*) >> make\~libs.tmp
else
	@if /I "$(strip $(MAUI_IN_ROM))" EQU "TRUE" \
		echo $(COMPLIBDIR)\rompatch.lib(*) >> make\~libs.tmp
endif

ifneq ($(strip $(MTK_LIBS)),)
	@tools\strcmpex.exe abc abc e make\~libs_2.tmp $(MTK_LIBS)
	@perl tools\lnitem.pl make\~libs_2.tmp
	@type make\~libs_2.tmp >> make\~libs.tmp
	@if exist make\~libs_2.tmp del make\~libs_2.tmp
endif

ifneq ($(strip $(COMPOBJS)),)
	@perl tools\echoLongString4.pl make\~libs.tmp $(COMPOBJS)
endif

ifdef FONT_ENGINE
  ifneq ($(strip $(FONT_ENGINE)),NONE)
	@type plutommi\Customer\ResGenerator\vf_obj.txt >> make\~libs.tmp
  endif
endif

	@if /I "$(strip $(MAUI_IN_ROM))" EQU "TRUE" \
		(echo $(ROM_IMG_FILE) >> make\~libs.tmp)

	@perl .\tools\sortLib.pl make\~libs.tmp $(strip $(COMPOBJS))

ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
	@echo Copy make\~sortedlibs.tmp 
	copy /y make\~sortedlibs.tmp make\sortedlibs.tmp
endif

ifdef RVCT_PARTIAL_LINK
ifeq ($(strip $(RVCT_PARTIAL_LINK)),FALSE)
ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
	@if /I %OS% EQU WINDOWS_NT \
		(($(LINK) --show_cmdline -vsn>$(LOG) 2>&1) & \
		($(LINK) -errors $(LNKERRORLOG) $(VIA) make\~sortedLibs.tmp >> $(LOG) 2>&1) & \
			(if ERRORLEVEL 1 \
				((perl mtk_tools\parse_linkerror.pl $(LNKERRORLOG) $(LOG)) & \
				(if exist $(strip $(HEADER_TEMP)) \
				(rd /S /Q $(strip $(HEADER_TEMP)))) & \
				(exit 1)) \
			else \
				(perl mtk_tools\parse_linkerror.pl $(LNKERRORLOG) $(LOG)))) \
	else \
		($(LINK) --show_cmdline $(VIA) make\~sortedLibs.tmp > $(LOG) )
else
	@if /I "$(strip $(MTK_SUBSIDIARY))" EQU "TRUE" \
	(@if /I %OS% EQU WINDOWS_NT \
		(($(LINK) --show_cmdline $(VIA) make\~sortedLibs.tmp > $(LOG) 2>&1) & \
			(if ERRORLEVEL 1 \
				(if exist $(strip $(HEADER_TEMP)) \
				(rd /S /Q $(strip $(HEADER_TEMP)))) & \
				(exit 1))) \
	else \
		(($(LINK) --show_cmdline $(VIA) make\~sortedLibs.tmp > $(LOG) ) & \
			(if ERRORLEVEL 1 \
				(if exist $(strip $(HEADER_TEMP)) \
				(rd /S /Q $(strip $(HEADER_TEMP)))) & \
				(exit 1)))) \
	else \
	(@if /I %USERINTERNAL% EQU INTERNAL \
			($(DIR_INT_569)\win_32-pentium\armlink.exe $(VIA) make\~sortedLibs.tmp > $(LOG)) \
		else \
		(	@if /I %OS% EQU WINDOWS_NT \
		(($(LINK) $(VIA) make\~sortedLibs.tmp > $(LOG) 2>&1) & \
			(if ERRORLEVEL 1 \
				(if exist $(strip $(HEADER_TEMP)) \
				(rd /S /Q $(strip $(HEADER_TEMP)))) & \
				(exit 1))) \
		else \
		(($(LINK) $(VIA) make\~sortedLibs.tmp > $(LOG) ) & \
			(if ERRORLEVEL 1 \
				(if exist $(strip $(HEADER_TEMP)) \
				(rd /S /Q $(strip $(HEADER_TEMP)))) & \
				(exit 1))) \
			))
endif
else
	@if exist pl_exclusion.txt \
	del /q pl_exclusion.txt
	
	@for %%i in ($(CUS_REL_PAR_SRC_COMP)) do \
	echo %%i.lib * >>pl_exclusion.txt

		@perl tools\partialLink.pl --lib-dir=$(COMPLIBDIR)	--scatter-file=$(SCATTERFILE) --link-option-file=$(FIXPATH)\make\~sortedLibs.tmp --readelf=$(FIXPATH)\tools\MinGW\bin\arm-none-eabi-readelf.exe --nm=$(FIXPATH)\tools\MinGW\bin\arm-none-eabi-nm.exe --link-err-file=$(LOG)
endif
else
 $(error RVCT_PARTIAL_LINK not defined!)
endif
   # -----------------------------
   # The size of the binary image depends on the available memory on the target
   # platform.
   # -----------------------------
	@echo Creating binary file $(BIN_FILE)
ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
	$(BIN_CREATE) $(strip $(TARGDIR))\$(IMG_FILE) $(BIN_FORMAT) -output $(strip $(TARGDIR))\$(BIN_FILE)
else
  ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
		$(BIN_CREATE) $(strip $(TARGDIR))\$(IMG_FILE) $(BIN_FORMAT) -output $(strip $(TARGDIR))\$(BIN_FILE)
  else
	@if /I %USERINTERNAL% EQU INTERNAL \
	($(DIR_INT_569)\win_32-pentium\fromelf.exe $(strip $(TARGDIR))\$(IMG_FILE) $(BIN_FORMAT) -output $(strip $(TARGDIR))\$(BIN_FILE)) \
	else \
	($(BIN_CREATE) $(strip $(TARGDIR))\$(IMG_FILE) $(BIN_FORMAT) -output $(strip $(TARGDIR))\$(BIN_FILE))
 
  endif
endif

ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
ifneq ($(findstring JRD,$(call Upper,$(strip $(CUSTOMER)))),)
	$(BIN_CREATE) $(strip $(TARGDIR))\$(IMG_FILE) -m32 -output $(strip $(TARGDIR))\$(patsubst %.bin,%.m32,$(strip $(BIN_FILE)))
endif
endif
	
	@tools\strcmpex.exe def def e make\~customIncDef.tmp $(foreach def,$(COM_DEFS),-D$(def))
	@echo -D__NULL_DEF__ >> make\~customIncDef.tmp
	@tools\strcmpex.exe inc inc e make\~customInc.tmp $(foreach inc,$(COMMINCDIRS),-I$(inc))
	@type make\~customInc.tmp >> make\~customIncDef.tmp
ifneq ($(strip $(call Upper,$(LEVEL))),VENDOR)
	@for /F %%i in (make\custom\custom.def) do \
		(echo -D%%i >> make\~customIncDef.tmp)
	@for /F %%i in (make\custom\custom.inc) do \
		(echo -I%%i >> make\~customIncDef.tmp)
	@$(CC) $(VIA) make\~customIncDef.tmp -E tools\NVRAMStatistic\src\ckSysDrv_flash_cfg_preproc.c > ~flash_cfg_tmp.c
endif

ifeq ($(strip $(ZIMAGE_SUPPORT)),TRUE)
  ifneq ($(strip $(DUMMY_SCATTER_ENABLE)),TRUE)
		@echo creating ZIMAGE ...
		@.\tools\7lzma.exe e $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ZIMAGE $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ZIMAGE.gz
		@ren $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ZIMAGE ZIMAGE.bin
		@ren $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ZIMAGE.gz ZIMAGE
		@perl tools\ckImgSize.pl $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ZIMAGE $(strip $(FIXPATH))\custom\system\$(strip $(call Upper,$(BOARD_VER)))\custom_MemoryDevice.h >$(strip $(TARGDIR))\log\ckImgSize.log  & \
	    (if ERRORLEVEL 1 (exit 1))
  else
    ifeq ($(strip $(DUMMY_SCATTER_ENABLE)),TRUE)
      ifneq ($(strip $(INSIDE_MTK)),1)
				@echo creating ZIMAGE ...
				@.\tools\7lzma.exe e $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ZIMAGE $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ZIMAGE.gz
				@ren $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ZIMAGE ZIMAGE.bin
				@ren $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ZIMAGE.gz ZIMAGE
				@perl tools\ckImgSize.pl $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ZIMAGE $(strip $(FIXPATH))\custom\system\$(strip $(call Upper,$(BOARD_VER)))\custom_MemoryDevice.h >$(strip $(TARGDIR))\log\ckImgSize.log  & \
				(if ERRORLEVEL 1 (exit 1))
      endif
    endif
  endif
endif

ifneq ($(filter $(strip $(PLATFORM)),$(8_BIT_ENCRYPTION_PLATFORM)),)
	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM  \
		(@if /I "$(strip $(SW_BINDING_SUPPORT))" EQU "BIND_TO_CHIP_BASIC"  .\tools\update_img.exe -sym $(strip $(TARGDIR))\$(TARGNAME).sym -path $(strip $(TARGDIR))\$(BIN_FILE)\ROM -align 8) & \
		(@if /I "$(strip $(SW_BINDING_SUPPORT))" EQU "BIND_TO_CHIP"  .\tools\update_img.exe -sym $(strip $(TARGDIR))\$(TARGNAME).sym -path $(strip $(TARGDIR))\$(BIN_FILE)\ROM -blpath $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE)) -keyini $(strip $(KEYFILE_PATH)) -align 8) & \
		(@if /I "$(strip $(NAND_FLASH_BOOTING))" EQU "NONE" \
		  (@echo Combine resource images with original ROM) & \
		  ($(CATBIN) -p $(strip $(TARGDIR))\$(BIN_FILE) -s $(SCATTERFILE) -o $(strip $(TARGDIR))\$(strip $(BIN_FILE))\JTAG_$(BIN_FILE)) & \
		  (if ERRORLEVEL 1 \
		  		(@echo Warning: Failed to generate JTAG binary file!!!) & \
		  		(@echo Please make sure the fullpath length of the generated file is valid on your machine file system) & \
		  		(@echo Try to reduce the length of your current work directory or map it to a network driver, then "remake verno" to solve this problem)) \
		)
else
	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM  \
		(@if /I "$(strip $(SW_BINDING_SUPPORT))" EQU "BIND_TO_CHIP_BASIC"  .\tools\update_img.exe -sym $(strip $(TARGDIR))\$(TARGNAME).sym -path $(strip $(TARGDIR))\$(BIN_FILE)\ROM) & \
		(@if /I "$(strip $(SW_BINDING_SUPPORT))" EQU "BIND_TO_CHIP"  .\tools\update_img.exe -sym $(strip $(TARGDIR))\$(TARGNAME).sym -path $(strip $(TARGDIR))\$(BIN_FILE)\ROM -blpath $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE)) -keyini $(strip $(KEYFILE_PATH))) & \
		(@if /I "$(strip $(NAND_FLASH_BOOTING))" EQU "NONE" \
		  (@echo Combine resource images with original ROM) & \
		  ($(CATBIN) -p $(strip $(TARGDIR))\$(BIN_FILE) -s $(SCATTERFILE) -o $(strip $(TARGDIR))\$(strip $(BIN_FILE))\JTAG_$(BIN_FILE)) & \
		  (if ERRORLEVEL 1 \
		  		(@echo Warning: Failed to generate JTAG binary file!!!) & \
		  		(@echo Please make sure the fullpath length of the generated file is valid on your machine file system) & \
		  		(@echo Try to reduce the length of your current work directory or map it to a network driver, then "remake verno" to solve this problem)) \
		)
endif

	@if exist .\tools\NFBPack3rdROM.pl \
	(if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\THIRD_ROM  \
		(perl .\tools\NFBPack3rdROM.pl $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ $(strip $(THE_MF))))

	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM  \
		(@if exist $(strip $(FLASHFILE)) \
			(perl .\tools\append2.pl $(strip $(TARGDIR))\$(TARGNAME).sym $(strip $(FLASHFILE)) $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM $(call Upper,$(strip $(CUSTOMER))_$(strip $(SUB_BOARD_VER))_$(strip $(PROJECT))_$(strip $(PLATFORM))_$(strip $(CHIP_VER))).$(strip $(PURE_VERNO)).BIN $(VERNO) $(strip $(THE_MF)) $(MEMORY_CFG) $(strip $(SCATTERFILE))) >> $(LOG) \
			else \
			(perl .\tools\append2.pl $(strip $(TARGDIR))\$(TARGNAME).sym $(FLASH_CFG) $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM $(call Upper,$(strip $(CUSTOMER))_$(strip $(SUB_BOARD_VER))_$(strip $(PROJECT))_$(strip $(PLATFORM))_$(strip $(CHIP_VER))).$(strip $(PURE_VERNO)).BIN $(VERNO) $(strip $(THE_MF)) $(EMI_INFO) $(strip $(SCATTERFILE))) >> $(LOG) \
		)

ifneq ($(filter $(strip $(PLATFORM)),$(8_BIT_ENCRYPTION_PLATFORM)),)
	@if not exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM  \
	(@if /I "$(strip $(SW_BINDING_SUPPORT))" EQU "BIND_TO_CHIP_BASIC"  .\tools\update_img.exe -sym $(strip $(TARGDIR))\$(TARGNAME).sym -path $(strip $(TARGDIR))\$(BIN_FILE) -align 8) & \
	(@if /I "$(strip $(SW_BINDING_SUPPORT))" EQU "BIND_TO_CHIP"  .\tools\update_img.exe -sym $(strip $(TARGDIR))\$(TARGNAME).sym -path $(strip $(TARGDIR))\$(BIN_FILE) -blpath $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE)) -keyini $(strip $(KEYFILE_PATH)) -align 8) & \
		(@if exist $(strip $(FLASHFILE)) \
			(perl .\tools\append2.pl $(strip $(TARGDIR))\$(TARGNAME).sym $(strip $(FLASHFILE)) $(strip $(TARGDIR))\$(BIN_FILE) $(call Upper,$(strip $(CUSTOMER))_$(strip $(SUB_BOARD_VER))_$(strip $(PROJECT))_$(strip $(PLATFORM))_$(strip $(CHIP_VER))).$(strip $(PURE_VERNO)).BIN $(VERNO) $(strip $(THE_MF)) $(MEMORY_CFG) $(strip $(SCATTERFILE))) >> $(LOG) \
			else \
			(perl .\tools\append2.pl $(strip $(TARGDIR))\$(TARGNAME).sym $(FLASH_CFG) $(strip $(TARGDIR))\$(BIN_FILE) $(call Upper,$(strip $(CUSTOMER))_$(strip $(SUB_BOARD_VER))_$(strip $(PROJECT))_$(strip $(PLATFORM))_$(strip $(CHIP_VER))).$(strip $(PURE_VERNO)).BIN $(VERNO) $(strip $(THE_MF)) $(EMI_INFO) $(strip $(SCATTERFILE))) >> $(LOG) \
		)
else
	@if not exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM  \
	(@if /I "$(strip $(SW_BINDING_SUPPORT))" EQU "BIND_TO_CHIP_BASIC"  .\tools\update_img.exe -sym $(strip $(TARGDIR))\$(TARGNAME).sym -path $(strip $(TARGDIR))\$(BIN_FILE)) & \
	(@if /I "$(strip $(SW_BINDING_SUPPORT))" EQU "BIND_TO_CHIP"  .\tools\update_img.exe -sym $(strip $(TARGDIR))\$(TARGNAME).sym -path $(strip $(TARGDIR))\$(BIN_FILE) -blpath $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE)) -keyini $(strip $(KEYFILE_PATH))) & \
		(@if exist $(strip $(FLASHFILE)) \
			(perl .\tools\append2.pl $(strip $(TARGDIR))\$(TARGNAME).sym $(strip $(FLASHFILE)) $(strip $(TARGDIR))\$(BIN_FILE) $(call Upper,$(strip $(CUSTOMER))_$(strip $(SUB_BOARD_VER))_$(strip $(PROJECT))_$(strip $(PLATFORM))_$(strip $(CHIP_VER))).$(strip $(PURE_VERNO)).BIN $(VERNO) $(strip $(THE_MF)) $(MEMORY_CFG) $(strip $(SCATTERFILE))) >> $(LOG) \
			else \
			(perl .\tools\append2.pl $(strip $(TARGDIR))\$(TARGNAME).sym $(FLASH_CFG) $(strip $(TARGDIR))\$(BIN_FILE) $(call Upper,$(strip $(CUSTOMER))_$(strip $(SUB_BOARD_VER))_$(strip $(PROJECT))_$(strip $(PLATFORM))_$(strip $(CHIP_VER))).$(strip $(PURE_VERNO)).BIN $(VERNO) $(strip $(THE_MF)) $(EMI_INFO) $(strip $(SCATTERFILE))) >> $(LOG) \
		)
endif

ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
ifneq ($(strip $(call Upper,$(LEVEL))),VENDOR)
	@if exist .\tools\CheckBinaryBlockUsage.pl \
		(perl .\tools\CheckBinaryBlockUsage.pl ~flash_cfg_tmp.c $(strip $(TARGDIR))\$(strip $(BIN_FILE)) $(strip $(NEED_BUILD_BOOTLOADER)) $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE)) $(strip $(FOTA_ENABLE)) $(strip $(TARGDIR))\$(strip $(FOTA_BIN_FILE)))
endif
endif

# Check if memory expiration.
	@if exist tools\parse_lis.pl \
		(perl tools\parse_lis.pl $(strip $(TARGDIR))\$(TARGNAME).lis ~lis_temp)
	@if exist $(FIXPATH)\tools\ckScatter.pl \
		(if exist ~lis_temp \
			(perl $(FIXPATH)\tools\ckScatter.pl 2 TRUE $(SCATTERFILE) ~lis_temp ~flash_cfg_tmp.c $(strip $(THE_MF)) $(strip $(BB_FOLDER_PATH)) $(strip $(INSIDE_MTK)) > $(strip $(COMPLOGDIR))\ckscatter2.log) & \
				(if ERRORLEVEL 1 \
					(@echo Error: ckScatter Error. Please refer to log\ckScatter2.log for more details.) & \
					(if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM \
						rd /S /Q $(strip $(TARGDIR))\$(strip $(BIN_FILE))) & \
					(if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE)) \
						del /q $(strip $(TARGDIR))\$(strip $(BIN_FILE))) & \
				(exit 1)))

# To support GPS_SUPPORT
ifdef GPS_SUPPORT
ifneq ($(filter $(strip $(GPS_SUPPORT)),MT3316 MT3318),)
	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM \
		((@if not exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\GPS (md $(strip $(TARGDIR))\$(strip $(BIN_FILE))\GPS)) & \
		@if exist gps\core\mt3318_gps_core.bin (copy /Y gps\core\mt3318_gps_core.bin $(strip $(TARGDIR))\$(strip $(BIN_FILE))\GPS)) \
	else \
		((@if not exist $(strip $(TARGDIR))\GPS (md $(strip $(TARGDIR))\GPS)) & \
		@if exist gps\core\mt3318_gps_core.bin (copy /Y gps\core\mt3318_gps_core.bin $(strip $(TARGDIR))\GPS))
ifeq ($(strip $(DRV_CUSTOM_TOOL_SUPPORT)),TRUE)
	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM \
		(@if exist tools\gps_config2.pl \
			(perl tools\gps_config2.pl $(strip $(FIXPATH))\custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\gpio_var.c $(strip $(TARGDIR))\$(strip $(BIN_FILE))\GPS\gps.ini)) \
	else \
		(@if exist tools\gps_config2.pl \
			(perl tools\gps_config2.pl $(strip $(FIXPATH))\custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\gpio_var.c $(strip $(TARGDIR))\GPS\gps.ini))
else
	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM \
		(@if exist tools\gps_config.pl \
			(perl tools\gps_config.pl $(strip $(FIXPATH))\custom\drv\gps\$(strip $(BOARD_VER))\gpsmtk_config.c $(strip $(TARGDIR))\$(strip $(BIN_FILE))\GPS\gps.ini)) \
	else \
		(@if exist tools\gps_config.pl \
			(perl tools\gps_config.pl $(strip $(FIXPATH))\custom\drv\gps\$(strip $(BOARD_VER))\gpsmtk_config.c $(strip $(TARGDIR))\GPS\gps.ini))
endif
endif
endif

   # -----------------------------
   # Nothting related binary directly
   # -----------------------------
	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\__* (del /q $(strip $(TARGDIR))\$(strip $(BIN_FILE))\__*)
	@if exist $(strip $(TARGDIR))\__* (del /q $(strip $(TARGDIR))\__*)
	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM  \
		((@copy /y $(SCATTERFILE) $(strip $(TARGDIR))\$(strip $(BIN_FILE)) > nul) & \
			(if exist $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE)) \
				(@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\$(strip $(BTLD_BIN_FILE)) del $(strip $(TARGDIR))\$(strip $(BIN_FILE))\$(strip $(BTLD_BIN_FILE))) & \
				(copy /Y $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE)) $(strip $(TARGDIR))\$(strip $(BIN_FILE)) > nul)) & \
			(if exist $(strip $(TARGDIR))\$(strip $(FOTA_BIN_FILE)) \
				(@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\$(strip $(FOTA_BIN_FILE)) del $(strip $(TARGDIR))\$(strip $(BIN_FILE))\$(strip $(FOTA_BIN_FILE))) & \
				(copy /Y $(strip $(TARGDIR))\$(strip $(FOTA_BIN_FILE)) $(strip $(TARGDIR))\$(strip $(BIN_FILE)) > nul)) \
		) \
	else \
		(copy /y $(SCATTERFILE) $(strip $(TARGDIR)) > nul)

	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM \
	  (if exist $(strip $(TARGDIR))\EXT_BOOTLOADER \
	     copy /Y $(strip $(TARGDIR))\EXT_BOOTLOADER $(strip $(TARGDIR))\$(strip $(BIN_FILE))\EXT_BOOTLOADER)

	@if exist $(strip $(MMI_FEATURES_FILE)) (copy /y $(strip $(MMI_FEATURES_FILE)) $(strip $(TARGDIR)) > nul)
	@if exist $(strip $(MMI_FEATURES_SWITCH_FILE)) (copy /y $(strip $(MMI_FEATURES_SWITCH_FILE)) $(strip $(TARGDIR)) > nul)
	@if exist $(strip $(THE_MF)) (copy /y $(strip $(THE_MF)) $(strip $(TARGDIR)) > nul)

# To support DBG Info Gen.
	@tools\DbgInfoGen.exe $(strip $(TARGDIR))\$(TARGNAME).elf $(strip $(TST_DB))\DbgInfo_$(strip $(SLIM_BRANCH))_$(strip $(CUSTOMER))_$(strip $(DBG_INFO_VERNO))_$(DBG_BUILD_DATE_TIME) "$(strip $(BRANCH))" $(strip $(PLATFORM))_$(strip $(CHIP_VER)) $(strip $(VERNO)) "$(BUILD_DATE_TIME)" >$(strip $(COMPLOGDIR))\DbgInfoGen.log
	@if exist $(strip $(TARGDIR))\DbgInfo_* del /Q /F $(strip $(TARGDIR))\DbgInfo_*
	@copy /Y $(strip $(TST_DB))\DbgInfo_$(strip $(SLIM_BRANCH))_$(strip $(CUSTOMER))_$(strip $(DBG_INFO_VERNO))_$(DBG_BUILD_DATE_TIME) $(strip $(TARGDIR))

	@perl -e "print 'LINKING END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,B,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# *************************************************************************
#  FOTA Targets
# *************************************************************************
fota: $(FOTA_BIN_FILE) done

echo_che_ssf_sss_lib_in_list:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifeq ($(strip $(COMPILER)),RVCT)
  ifeq ($(strip $(LQT_SUPPORT)),TRUE)
		@echo COMPLIBLIST=che.lib sst_sec.lib ssf.lib sss_rvct.lib lqt.lib > make\complib.txt
  else
		@echo COMPLIBLIST=che.lib sst_sec.lib ssf.lib sss_rvct.lib lqt.lib > make\complib.txt
  endif
else
  ifeq ($(strip $(LQT_SUPPORT)),TRUE)
		@echo COMPLIBLIST=che.lib sst_sec.lib ssf.lib sss.lib lqt.lib > make\complib.txt
  else
		@echo COMPLIBLIST=che.lib sst_sec.lib ssf.lib sss.lib > make\complib.txt
  endif
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))	

echo_che_ssf_lib_in_list:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifeq ($(strip $(LQT_SUPPORT)),TRUE)
	@echo COMPLIBLIST=che.lib sst_sec.lib ssf.lib lqt.lib > make\complib.txt
else
	@echo COMPLIBLIST=che.lib sst_sec.lib ssf.lib > make\complib.txt
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

del_fota:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifneq ($(strip $(FOTA_ENABLE)),NONE)
	@-if not exist $(TARGDIR) (md $(TARGDIR))            	\
	else                                                 	\
		(@if exist $(strip $(TARGDIR))\$(FOTA_BIN_FILE) (del $(strip $(TARGDIR))\$(FOTA_BIN_FILE))) &  	\
		(@if exist $(strip $(TARGDIR))\$(FOTA_PREFIX).elf (del $(strip $(TARGDIR))\$(FOTA_PREFIX).elf)) & \
		(@if exist $(strip $(TARGDIR))\$(FOTA_PREFIX).lis (del $(strip $(TARGDIR))\$(FOTA_PREFIX).lis)) & \
		(@if exist $(strip $(TARGDIR))\$(FOTA_PREFIX).sym (del $(strip $(TARGDIR))\$(FOTA_PREFIX).sym)) & \
		(@if exist $(strip $(TARGDIR))\$(FOTA_PREFIX).htm (del $(strip $(TARGDIR))\$(FOTA_PREFIX).htm)) & \
		(@if exist $(strip $(TARGDIR))\*.log (del /q $(strip $(TARGDIR))\*.log))
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)

ifeq ($(strip $(FOTA_ENABLE)),FOTA_DM)

ifeq ($(strip $(SSS_SUPPORT)),SSS_SOURCE)
  ifeq ($(strip $(XGC_AND_NOT_BOOTLOADER)),TRUE)
$(FOTA_BIN_FILE): gencompbld echo_che_ssf_sss_lib_in_list xgc_all_libs del_fota
  else
    ifeq ($(strip $(COMPILER)),RVCT)
      ifeq ($(strip $(LQT_SUPPORT)),TRUE)
$(FOTA_BIN_FILE): gencompbld che.lib sst_sec.lib ssf.lib sss_rvct.lib lqt.lib del_fota
      else
$(FOTA_BIN_FILE): gencompbld che.lib sst_sec.lib ssf.lib sss_rvct.lib del_fota
      endif
    else
      ifeq ($(strip $(LQT_SUPPORT)),TRUE)
$(FOTA_BIN_FILE): gencompbld che.lib sst_sec.lib ssf.lib sss.lib lqt.lib del_fota
      else
$(FOTA_BIN_FILE): gencompbld che.lib sst_sec.lib ssf.lib sss.lib del_fota
      endif
    endif
  endif
else
  ifeq ($(strip $(XGC_AND_NOT_BOOTLOADER)),TRUE)
$(FOTA_BIN_FILE): gencompbld echo_che_ssf_lib_in_list xgc_all_libs del_fota
  else
    ifeq ($(strip $(LQT_SUPPORT)),TRUE)
$(FOTA_BIN_FILE): gencompbld che.lib sst_sec.lib ssf.lib lqt.lib del_fota
    else
$(FOTA_BIN_FILE): gencompbld che.lib sst_sec.lib ssf.lib del_fota
    endif
  endif
endif

else
$(FOTA_BIN_FILE): gencompbld del_fota
endif

else

ifeq ($(strip $(FOTA_ENABLE)),FOTA_DM)
  ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
    ifeq ($(strip $(LQT_SUPPORT)),TRUE)
$(FOTA_BIN_FILE): gencompbld $(strip $(CUS_MTK_LIB))\sst_sec.lib lqt.lib del_fota
    else
$(FOTA_BIN_FILE): gencompbld $(strip $(CUS_MTK_LIB))\sst_sec.lib del_fota
    endif
  else
$(FOTA_BIN_FILE): gencompbld $(strip $(CUS_MTK_LIB))\sst_sec.lib del_fota
  endif
else
$(FOTA_BIN_FILE): gencompbld del_fota
endif
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,B,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifneq ($(strip $(FOTA_ENABLE)),NONE)

	-@if not exist $(COMPLOGDIR)	(md $(COMPLOGDIR))         \
	else (@if exist $(strip $(COMPLOGDIR))\fota.log (del /q $(strip $(COMPLOGDIR))\fota.log))

	-@if not exist $(PROJDIR)	(md $(PROJDIR))
	-@if not exist $(OBJSDIR)	(md $(OBJSDIR))

	@echo Generate FOTA CMM file ...
	@perl .\tools\fota_NocodeCMMAutoGen.pl themf=$(strip $(THE_MF)) verno=$(strip $(FOTA_PURE_VERNO)) \
	   > FOTA_$(strip $(CUSTOMER))_$(strip $(PLATFORM))_nocode.cmm

	-@if not exist $(strip $(OBJSDIR))\fota	(md $(strip $(OBJSDIR))\fota) \
	else	(@if exist $(strip $(OBJSDIR))\fota\*.obj (del $(strip $(OBJSDIR))\fota\*.obj))

	-@if not exist $(strip $(COMPLIBDIR))	(md $(COMPLIBDIR)) \
	else	(@if exist $(strip $(COMPLIBDIR))\fota.lib (del $(strip $(COMPLIBDIR))\fota.lib))

	-@if not exist $(RULESDIR) (md $(RULESDIR))	\
	else	(@if exist $(strip $(RULESDIR))\fota.dep (del $(strip $(RULESDIR))\fota.dep))

ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
	@if exist $(TARGDIR)\module\fota\~fota.lis \
		(copy /y $(TARGDIR)\module\fota\~fota.lis $(TARGDIR)\module\fota\fota.lis)
	@if exist $(TARGDIR)\module\fota\fota.lis \
		(copy /y $(TARGDIR)\module\fota\fota.lis $(TARGDIR)\module\fota\~fota.lis)
	@echo custom\drv\misc_drv\$(strip $(BOARD_VER))\uem_gpio.c>> $(TARGDIR)\module\fota\fota.lis
	@echo custom\drv\misc_drv\$(strip $(BOARD_VER))\custom_equipment.c>> $(TARGDIR)\module\fota\fota.lis
	@echo custom\drv\misc_drv\$(strip $(BOARD_VER))\custom_hw_default.c>> $(TARGDIR)\module\fota\fota.lis
	@echo custom\drv\misc_drv\$(strip $(BOARD_VER))\gpio_drv.c>> $(TARGDIR)\module\fota\fota.lis
	@echo custom\drv\misc_drv\$(strip $(BOARD_VER))\pwmdrv.c>> $(TARGDIR)\module\fota\fota.lis
	@echo custom\drv\misc_drv\$(strip $(BOARD_VER))\alerterdrv.c>> $(TARGDIR)\module\fota\fota.lis
	@echo custom\system\$(strip $(BOARD_VER))\custom_fota.c>> $(TARGDIR)\module\fota\fota.lis
	@echo custom\system\$(strip $(BOARD_VER))\custom_img_config.c>> $(TARGDIR)\module\fota\fota.lis
	@echo custom\system\$(strip $(BOARD_VER))\custom_flash.c>> $(TARGDIR)\module\fota\fota.lis
	@echo custom\system\$(strip $(BOARD_VER))\custom_blconfig.c>> $(TARGDIR)\module\fota\fota.lis
	@echo custom\drv\misc_drv\$(strip $(BOARD_VER))\pmic_custom.c>> $(TARGDIR)\module\fota\fota.lis
ifeq ($(strip $(DRV_CUSTOM_TOOL_SUPPORT)),TRUE)
	@echo custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\gpio_var.c>> $(TARGDIR)\module\fota\fota.lis
  ifeq ($(strip $(PLATFORM)),MT6226)
		@echo custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\uem_drv.c>> $(TARGDIR)\module\fota\fota.lis
  endif
  ifeq ($(strip $(PLATFORM)),MT6225)
		@echo custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\uem_drv.c>> $(TARGDIR)\module\fota\fota.lis
  endif
else
  ifeq ($(strip $(PLATFORM)),MT6226)
		@echo custom\drv\misc_drv\$(strip $(BOARD_VER))\custom_equipment.c>> $(TARGDIR)\module\fota\fota.lis
  endif
endif
ifeq ($(strip $(FOTA_ENABLE)),FOTA_DM)
	@echo vendor\hp_fota\UA\uaheapsettings.c>> $(TARGDIR)\module\fota\fota.lis
	@echo vendor\hp_fota\UA\uamain.c>> $(TARGDIR)\module\fota\fota.lis
	@echo vendor\hp_fota\UA\uawdebug.c>> $(TARGDIR)\module\fota\fota.lis
	@echo vendor\hp_fota\UA\uawdevice.c>> $(TARGDIR)\module\fota\fota.lis
	@echo vendor\hp_fota\UA\uawflash.c>> $(TARGDIR)\module\fota\fota.lis
	@echo vendor\hp_fota\UA\uawpackage.c>> $(TARGDIR)\module\fota\fota.lis
	@echo fota\src\fue_env_api.c>> $(TARGDIR)\module\fota\fota.lis
	@echo sss\interface\src\SSS_interface.c>> $(TARGDIR)\module\fota\fota.lis
	@echo fota\src\fue_dbg_print.c>> $(TARGDIR)\module\fota\fota.lis
	@echo fota\src\fue_dbg_print.c>> $(TARGDIR)\module\fota\fota.lis
	@echo fota\src\fue_uart_drv.c>> $(TARGDIR)\module\fota\fota.lis
	@echo fota\src\fue_cache.c>> $(TARGDIR)\module\fota\fota.lis
	@echo fota\src\fue_adm.c>> $(TARGDIR)\module\fota\fota.lis
	@echo fota\src\fue_nor_mtd.c>> $(TARGDIR)\module\fota\fota.lis
	@echo fota\src\fue_nor_support.c>> $(TARGDIR)\module\fota\fota.lis
	@echo fota\src\fue_nand_lae_support.c>> $(TARGDIR)\module\fota\fota.lis
	@echo fota\src\fue_backup_support.c>> $(TARGDIR)\module\fota\fota.lis
	@echo fota\src\fue_nand_update_support.c>> $(TARGDIR)\module\fota\fota.lis
	@echo fota\src\fue_mem_heap.c>> $(TARGDIR)\module\fota\fota.lis
	@echo drv\src\dma.c>> $(TARGDIR)\module\fota\fota.lis
	@echo drv\src\flash_mtd.c>> $(TARGDIR)\module\fota\fota.lis
	@echo drv\src\flash_mtd.amd.c>> $(TARGDIR)\module\fota\fota.lis
	@echo drv\src\flash_mtd.intel.c>> $(TARGDIR)\module\fota\fota.lis
	@echo fota\src\fue_partial_fota.c>> $(TARGDIR)\module\fota\fota.lis
	@echo init\src\mmu.c>> $(TARGDIR)\module\fota\fota.lis
	@echo init\src\cache.c>> $(TARGDIR)\module\fota\fota.lis
	@echo custom\drv\common_drv\pwic_cust.c >> $(TARGDIR)\module\fota\fota.lis
	@echo init\src\init_memory_stack.c >> $(TARGDIR)\module\fota\fota.lis
ifeq ($(call Upper,$(strip $(PMIC))),MT6238PMU)
	@echo custom\drv\misc_drv\$(strip $(BOARD_VER))\pmu_custom.c>> $(TARGDIR)\module\fota\fota.lis
	@echo drv\src\pmu.c>> $(TARGDIR)\module\fota\fota.lis
endif
ifeq ($(call Upper,$(strip $(PMIC))),MT6235PMU)
	@echo custom\drv\misc_drv\$(strip $(BOARD_VER))\pmu_custom.c>> $(TARGDIR)\module\fota\fota.lis
	@echo drv\src\pmu.c>> $(TARGDIR)\module\fota\fota.lis
endif
ifeq ($(call Upper,$(strip $(PMIC))),MT6223PMU)
	@echo custom\drv\misc_drv\$(strip $(BOARD_VER))\pmu_custom.c>> $(TARGDIR)\module\fota\fota.lis
	@echo drv\src\pmu.c>> $(TARGDIR)\module\fota\fota.lis
endif
ifeq ($(call Upper,$(strip $(PMIC))),MT6253PMU)
	@echo custom\drv\misc_drv\$(strip $(BOARD_VER))\pmu_custom.c>> $(TARGDIR)\module\fota\fota.lis
	@echo drv\src\pmu6253.c>> $(TARGDIR)\module\fota\fota.lis
endif
ifeq ($(call Upper,$(strip $(PMIC))),MT6236PMU)
	@echo custom\drv\misc_drv\$(strip $(BOARD_VER))\pmu_custom.c>> $(TARGDIR)\module\fota\fota.lis
	@echo drv\src\pmu6236.c>> $(TARGDIR)\module\fota\fota.lis
endif
ifeq ($(call Upper,$(strip $(PMIC))),MT6318)
	@echo drv\src\i2c_dual.c>> $(TARGDIR)\module\fota\fota.lis
	@echo drv\src\pmic6318.c>> $(TARGDIR)\module\fota\fota.lis
endif
ifeq ($(call Upper,$(strip $(PMIC))),MT6326)
	@echo drv\src\i2c_dual.c>> $(TARGDIR)\module\fota\fota.lis
	@echo drv\src\pmic6326.c>> $(TARGDIR)\module\fota\fota.lis
endif
ifneq ($(strip $(NAND_FLASH_BOOTING)), NONE)
	@echo fota\src\fue_nand_mtd.c>> $(TARGDIR)\module\fota\fota.lis
	@echo drv\src\NAND_MTD.c>> $(TARGDIR)\module\fota\fota.lis
	@echo drv\src\NAND_DAL.c>> $(TARGDIR)\module\fota\fota.lis
	@echo drv\src\NAND_MTD_FDM50.c>> $(TARGDIR)\module\fota\fota.lis
	@echo drv\src\NAND_DevConfig.c>> $(TARGDIR)\module\fota\fota.lis
	@echo fota\src\fue_nand_lae_if.c>> $(TARGDIR)\module\fota\fota.lis
endif
ifneq ($(strip $(FOTA_UPDATE_PACKAGE_ON_NAND)), FALSE)
	@echo fota\src\fue_nand_mtd.c>> $(TARGDIR)\module\fota\fota.lis
	@echo drv\src\NAND_MTD.c>> $(TARGDIR)\module\fota\fota.lis
	@echo drv\src\NAND_DAL.c>> $(TARGDIR)\module\fota\fota.lis
	@echo drv\src\NAND_MTD_FDM50.c>> $(TARGDIR)\module\fota\fota.lis
	@echo drv\src\NAND_DevConfig.c>> $(TARGDIR)\module\fota\fota.lis
endif
endif
endif

	@tools\make.exe -fmake\gsm2.mak -r -R $(strip $(CMD_ARGU)) XGC_AND_NOT_BOOTLOADER=FALSE CUSTOMER=$(strip $(CUSTOMER)) PROJECT=$(strip $(PROJECT)) fota.lib

	@echo Linking $(strip $(FOTA_PREFIX)) ...
	@perl tools\time.pl -n
	@echo $(FOTALNKOPT) > make\~libs.tmp
	@echo $(strip $(COMPLIBDIR))\fota.lib(*) >> make\~libs.tmp
	
ifdef FOTA_ENABLE
  ifeq ($(strip $(FOTA_ENABLE)),FOTA_DM)
   ifeq ($(strip $(COMPILER)),ADS)
    ifneq ($(filter $(strip $(PLATFORM)),$(ARM9_FOTA_PLATFORM)),)
			@echo vendor\hp_fota\lib\libmprove610_MTKarm9_tcc.a>> make\~libs.tmp
    endif
    ifneq ($(filter $(strip $(PLATFORM)),$(ARM7_FOTA_PLATFORM)),)
			@echo vendor\hp_fota\lib\libmprove610_MTKarm7_tcc.a>> make\~libs.tmp
    endif
   endif
   ifeq ($(strip $(COMPILER)),RVCT)
    ifneq ($(filter $(strip $(PLATFORM)),$(ARM9_FOTA_PLATFORM)),)
			@echo vendor\hp_fota\lib\libmprove610_MTKarm9_rvct.a>> make\~libs.tmp
    endif
    ifneq ($(filter $(strip $(PLATFORM)),$(ARM7_FOTA_PLATFORM)),)
			@echo vendor\hp_fota\lib\libmprove610_MTKarm7_rvct.a>> make\~libs.tmp
    endif
   endif
    ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
			@echo $(strip $(COMPLIBDIR))\che.lib >> make\~libs.tmp
			@echo $(strip $(COMPLIBDIR))\ssf.lib >> make\~libs.tmp
			@echo $(strip $(COMPLIBDIR))\sst_sec.lib >> make\~libs.tmp
      ifeq ($(strip $(LQT_SUPPORT)),TRUE)
				@echo $(strip $(COMPLIBDIR))\lqt.lib >> make\~libs.tmp
      endif
    else
			@echo $(strip $(CUS_MTK_LIB))\che.lib >> make\~libs.tmp
			@echo $(strip $(CUS_MTK_LIB))\ssf.lib >> make\~libs.tmp
			@echo $(strip $(CUS_MTK_LIB))\sst_sec.lib >> make\~libs.tmp
      ifeq ($(strip $(LQT_SUPPORT)),TRUE)
        ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
					@echo $(strip $(COMPLIBDIR))\lqt.lib >> make\~libs.tmp
        else
					@echo $(strip $(CUS_MTK_LIB))\lqt.lib >> make\~libs.tmp
        endif
      endif
    endif

    ifeq ($(strip $(SSS_SUPPORT)),SSS_SOURCE)
      ifeq ($(strip $(COMPILER)),RVCT)
				@echo $(strip $(COMPLIBDIR))\sss_rvct.lib >> make\~libs.tmp
      else
				@echo $(strip $(COMPLIBDIR))\sss.lib >> make\~libs.tmp
      endif
    endif   
    ifeq ($(strip $(SSS_SUPPORT)),SSS_LIB)
      ifeq ($(strip $(COMPILER)),RVCT)
				@echo sss\sss_rvct.lib >> make\~libs.tmp
      else
				@echo sss\sss.lib >> make\~libs.tmp
      endif
    endif   

  endif
endif

	@echo $(LINK) $(VIA) make\~libs.tmp

	@perl .\tools\sortLib.pl make\~libs.tmp $(strip $(COMPOBJS))
	@if /I %OS% EQU WINDOWS_NT \
		($(LINK) $(VIA) make\~sortedLibs.tmp >> $(FOTA_LOG) 2>&1) \
	else \
		($(LINK) $(VIA) make\~sortedLibs.tmp >> $(FOTA_LOG) )

	@echo Creating binary file $(FOTA_BIN_FILE)
	@echo $(BIN_CREATE) $(strip $(TARGDIR))\$(FOTA_PREFIX).elf $(BIN_FORMAT) -output $(strip $(TARGDIR))\$(FOTA_BIN_FILE)
	$(BIN_CREATE) $(strip $(TARGDIR))\$(FOTA_PREFIX).elf $(BIN_FORMAT) -output $(strip $(TARGDIR))\$(FOTA_BIN_FILE)

	perl .\tools\fota_append.pl $(strip $(TARGDIR))\$(strip $(FOTA_PREFIX)).sym $(call Upper,$(strip $(BIN_FILE))) $(strip $(VERNO)) $(strip $(THE_MF)) $(strip $(FOTA_SCATTERFILE)) $(strip $(TARGDIR))\$(FOTA_BIN_FILE)
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,B,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# *************************************************************************
#  BOOTLOADER Targets
# *************************************************************************
bootloader: $(BTLD_BIN_FILE) done

echo_che_lib_in_list:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@echo COMPLIBLIST=che.lib sst_sec.lib > make\complib.txt
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

echo_che_sss_lib_in_list:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifeq ($(strip $(COMPILER)),RVCT)
	@echo COMPLIBLIST=che.lib sst_sec.lib sss_rvct.lib > make\complib.txt
else
	@echo COMPLIBLIST=che.lib sst_sec.lib sss.lib > make\complib.txt
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)     

ifeq ($(strip $(SSS_SUPPORT)),SSS_SOURCE)
ifeq ($(strip $(FOTA_ENABLE)),FOTA_DM)
  ifeq ($(strip $(XGC_AND_NOT_BOOTLOADER)),TRUE)
    $(BTLD_BIN_FILE): gen_bl_verno gencompbld echo_che_ssf_sss_lib_in_list xgc_all_libs
  else
    ifeq ($(strip $(COMPILER)),RVCT)
      $(BTLD_BIN_FILE): gen_bl_verno gencompbld che.lib sst_sec.lib ssf.lib sss_rvct.lib
    else
      $(BTLD_BIN_FILE): gen_bl_verno gencompbld che.lib sst_sec.lib ssf.lib sss.lib
    endif
  endif
else
  ifeq ($(strip $(XGC_AND_NOT_BOOTLOADER)),TRUE)
    $(BTLD_BIN_FILE): gen_bl_verno gencompbld echo_che_sss_lib_in_list xgc_all_libs
  else
    ifeq ($(strip $(COMPILER)),RVCT)
      $(BTLD_BIN_FILE): gen_bl_verno gencompbld che.lib sst_sec.lib sss_rvct.lib
    else
      $(BTLD_BIN_FILE): gen_bl_verno gencompbld che.lib sst_sec.lib sss.lib
    endif
  endif
endif
else
ifeq ($(strip $(FOTA_ENABLE)),FOTA_DM)
  ifeq ($(strip $(XGC_AND_NOT_BOOTLOADER)),TRUE)
    $(BTLD_BIN_FILE): gen_bl_verno gencompbld echo_che_ssf_lib_in_list xgc_all_libs
  else
    $(BTLD_BIN_FILE): gen_bl_verno gencompbld che.lib sst_sec.lib ssf.lib
  endif
else
  ifeq ($(strip $(XGC_AND_NOT_BOOTLOADER)),TRUE)
    $(BTLD_BIN_FILE): gen_bl_verno gencompbld echo_che_lib_in_list xgc_all_libs
  else
    $(BTLD_BIN_FILE): gen_bl_verno gencompbld che.lib sst_sec.lib
  endif
endif
endif

else

ifeq ($(strip $(FOTA_ENABLE)),FOTA_DM)
$(BTLD_BIN_FILE): gen_bl_verno gencompbld $(strip $(CUS_MTK_LIB))\sst_sec.lib
else
$(BTLD_BIN_FILE): gen_bl_verno gencompbld
endif

endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,B,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifeq ($(strip $(NEED_BUILD_BOOTLOADER)),TRUE)
	@-if not exist $(TARGDIR) (md $(TARGDIR))            	\
	else                                                 	\
		(@if exist $(strip $(TARGDIR))\$(BTLD_BIN_FILE) (del $(strip $(TARGDIR))\$(BTLD_BIN_FILE))) &  	\
		(@if exist $(strip $(TARGDIR))\$(BTLD_PREFIX).elf (del $(strip $(TARGDIR))\$(BTLD_PREFIX).elf)) & \
		(@if exist $(strip $(TARGDIR))\$(BTLD_PREFIX).lis (del $(strip $(TARGDIR))\$(BTLD_PREFIX).lis)) & \
		(@if exist $(strip $(TARGDIR))\$(BTLD_PREFIX).sym (del $(strip $(TARGDIR))\$(BTLD_PREFIX).sym)) & \
		(@if exist $(strip $(TARGDIR))\$(BTLD_PREFIX).htm (del $(strip $(TARGDIR))\$(BTLD_PREFIX).htm)) & \
		(@if exist $(strip $(TARGDIR))\*.log (del /q $(strip $(TARGDIR))\*.log))

	-@if not exist $(COMPLOGDIR)	(md $(COMPLOGDIR))         \
	else (@if exist $(strip $(COMPLOGDIR))\bootloader.log (del /q $(strip $(COMPLOGDIR))\bootloader.log))

	-@if not exist $(PROJDIR)	(md $(PROJDIR))
	-@if not exist $(OBJSDIR)	(md $(OBJSDIR))

	-@if not exist $(strip $(OBJSDIR))\bootloader	(md $(strip $(OBJSDIR))\bootloader) \
	else	(@if exist $(strip $(OBJSDIR))\bootloader\*.obj (del $(strip $(OBJSDIR))\bootloader\*.obj))

	-@if not exist $(strip $(COMPLIBDIR))	(md $(COMPLIBDIR)) \
	else	(@if exist $(strip $(COMPLIBDIR))\bootloader.lib (del $(strip $(COMPLIBDIR))\bootloader.lib))

	-@if not exist $(RULESDIR) (md $(RULESDIR))	\
	else	(@if exist $(strip $(RULESDIR))\bootloader.dep (del $(strip $(RULESDIR))\bootloader.dep))

	@tools\make.exe -fmake\gsm2.mak -k -r -R XGC_AND_NOT_BOOTLOADER=FALSE CUSTOMER=$(strip $(CUSTOMER)) PROJECT=$(strip $(PROJECT)) bootloader.lib

	@echo Linking $(strip $(BTLD_PREFIX)) ...
	@perl tools\time.pl -n
	@echo $(BTLDLNKOPT) > make\~libs.tmp
	@echo $(strip $(COMPLIBDIR))\bootloader.lib(*) >> make\~libs.tmp


ifdef SSS_SUPPORT
  ifeq ($(strip $(SSS_SUPPORT)),SSS_SOURCE)
    ifeq ($(strip $(COMPILER)),RVCT)
			@echo $(strip $(COMPLIBDIR))\sss_rvct.lib >> make\~libs.tmp
    else
			@echo $(strip $(COMPLIBDIR))\sss.lib >> make\~libs.tmp
    endif
  endif   
  ifeq ($(strip $(SSS_SUPPORT)),SSS_LIB)
    ifeq ($(strip $(COMPILER)),RVCT)
			@echo sss\sss_rvct.lib >> make\~libs.tmp
    else
			@echo sss\sss.lib >> make\~libs.tmp
    endif
  endif   
  ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
		@echo $(strip $(COMPLIBDIR))\che.lib >> make\~libs.tmp
  else
		@echo $(strip $(CUS_MTK_LIB))\che.lib >> make\~libs.tmp
  endif
  ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
		@echo $(strip $(COMPLIBDIR))\sst_sec.lib >> make\~libs.tmp
  else
		@echo $(strip $(CUS_MTK_LIB))\sst_sec.lib >> make\~libs.tmp
  endif
endif

ifdef FOTA_ENABLE
  ifeq ($(strip $(FOTA_ENABLE)),FOTA_DM)
    ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
			@echo $(COMPLIBDIR)\ssf.lib >> make\~libs.tmp
    else
			@echo $(strip $(CUS_MTK_LIB))\ssf.lib >> make\~libs.tmp
    endif
  endif
endif

	@perl .\tools\sortLib.pl make\~libs.tmp $(strip $(COMPOBJS))
	@if /I %OS% EQU WINDOWS_NT \
		($(LINK) $(VIA) make\~sortedLibs.tmp >> $(BOOTLOADER_LOG) 2>&1) \
	else \
		($(LINK) $(VIA) make\~sortedLibs.tmp >> $(BOOTLOADER_LOG) )

	@echo Creating binary file $(BTLD_BIN_FILE)
	$(BIN_CREATE) $(strip $(TARGDIR))\$(BTLD_PREFIX).elf $(BIN_FORMAT) -output $(strip $(TARGDIR))\$(BTLD_BIN_FILE)

	@if exist $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE))\EXT_READ_ONLY \
		copy /Y $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE))\EXT_READ_ONLY $(strip $(TARGDIR))\EXT_BOOTLOADER

	@if exist $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE))\READ_ONLY \
		copy /Y $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE))\READ_ONLY $(strip $(TARGDIR))\READ_ONLY & \
		rmdir /S /Q $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE)) & \
		move /Y $(strip $(TARGDIR))\READ_ONLY $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE))

	@perl .\tools\bl_append.pl $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE)) $(strip $(BTLDVERNODIR))\bl_verno.c $(strip $(BL_SCATTERFILE)) $(strip $(THE_MF)) $(strip $(TARGDIR))\$(BTLD_PREFIX).sym $(call Upper,$(strip $(BIN_FILE))) $(strip $(VERNO))

	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM \
	  (if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\$(strip $(BTLD_BIN_FILE)) \
	     del $(strip $(TARGDIR))\$(strip $(BIN_FILE))\$(strip $(BTLD_BIN_FILE))) & \
	  copy /Y $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE)) $(strip $(TARGDIR))\$(strip $(BIN_FILE)) > nul

	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM \
	  (if exist $(strip $(TARGDIR))\EXT_BOOTLOADER \
	     copy /Y $(strip $(TARGDIR))\EXT_BOOTLOADER $(strip $(TARGDIR))\$(strip $(BIN_FILE))\EXT_BOOTLOADER)

endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,B,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# *************************************************************************
# Generate Bootloader VersionNo
# *************************************************************************
gen_bl_verno:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'gen_bl_verno START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log

	@echo Generate BOOTLOADER CMM file ...
	@perl .\tools\bl_NocodeCMMAutoGen.pl plat=$(strip $(PLATFORM)) board_ver=$(strip $(BOARD_VER)) \
	   custom=$(strip $(CUSTOMER)) blver=$(strip $(BTLD_VERNO)) verno=$(strip $(PURE_VERNO)) \
	   > BOOTLOADER_$(strip $(CUSTOMER))_$(strip $(PLATFORM))_nocode.cmm

	@echo Generate BOOTLOADER version number ...
	@if not exist $(strip $(BTLDVERNODIR)) exit 0

	@if exist $(strip $(BTLDVERNODIR))\bl_verno.c (del $(strip $(BTLDVERNODIR))\bl_verno.c)

	@echo #include "kal_release.h" > $(strip $(BTLDVERNODIR))\bl_verno.c
	@echo const kal_uint32 CHECKSUM_SEED = $(strip $(BTLD_CHECKSUM_SEED)); >> $(strip $(BTLDVERNODIR))\bl_verno.c
	@echo const kal_int8 BootLDVerno[5] = "$(strip $(BTLD_VERNO))"; >> $(strip $(BTLDVERNODIR))\bl_verno.c

	@echo Generate BOOTLOADER .lis and .pth file ...
#	@perl .\tools\bl_info.pl board_ver=$(strip $(BOARD_VER)) themf=$(strip $(THE_MF))
ifeq ($(strip $(FOTA_ENABLE)),FOTA_DM)
	@echo custom\system\$(strip $(BOARD_VER))\custom_fota.c>>$(FIXPATH)\make\bootloader\bootloader.lis
	@echo custom\system\$(strip $(BOARD_VER))\custom_img_config.c>>$(FIXPATH)\make\bootloader\bootloader.lis
	@echo drv\src\flash_mtd.c>>$(FIXPATH)\make\bootloader\bootloader.lis
endif

	@perl -e "print 'gen_bl_verno END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# *************************************************************************
# Generate VersionNo
# *************************************************************************
genverno:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'genverno START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
	@echo Generate version number ... >> $(LOG)

	@if not exist $(VERNODIR) \
		md $(VERNODIR)

	@if exist $(strip $(VERNODIR))\verno.c (del $(strip $(VERNODIR))\verno.c)

	@echo #include "kal_release.h" > $(strip $(VERNODIR))\verno.c
	@echo kal_char* release_verno(void) >> $(strip $(VERNODIR))\verno.c
	@echo { >> $(strip $(VERNODIR))\verno.c
	@echo    static kal_char verno_str[] = "$(strip $(VERNO))"; >> $(strip $(VERNODIR))\verno.c
	@echo    return verno_str; >> $(strip $(VERNODIR))\verno.c
	@echo } >> $(strip $(VERNODIR))\verno.c

	@echo kal_char* release_hw_ver(void) >> $(strip $(VERNODIR))\verno.c
	@echo { >> $(strip $(VERNODIR))\verno.c
ifeq ($(call Upper,$(strip $(CUSTOMER))),TIANYU28_DEMO)
ifeq ($(call Upper,$(strip $(FLAVOR))),TP_Q05A_LANDSCAPE)
	@echo    static kal_char hw_ver_str[] = "TIANYU28_TP_DEMO_HW"; >> $(strip $(VERNODIR))\verno.c
else
	@echo    static kal_char hw_ver_str[] = "$(strip $(HW_VER))"; >> $(strip $(VERNODIR))\verno.c
endif
else
	@echo    static kal_char hw_ver_str[] = "$(strip $(HW_VER))"; >> $(strip $(VERNODIR))\verno.c
endif
	@echo    return hw_ver_str; >> $(strip $(VERNODIR))\verno.c
	@echo } >> $(strip $(VERNODIR))\verno.c

	@echo kal_char* build_date_time(void) >> $(strip $(VERNODIR))\verno.c
	@echo { >> $(strip $(VERNODIR))\verno.c
	@echo    static kal_char build_date_time_str[] = "$(strip $(BUILD_DATE_TIME))"; >> $(strip $(VERNODIR))\verno.c
	@echo    return build_date_time_str; >> $(strip $(VERNODIR))\verno.c
	@echo } >> $(strip $(VERNODIR))\verno.c

	@echo kal_char* release_build(void) >> $(strip $(VERNODIR))\verno.c
	@echo { >> $(strip $(VERNODIR))\verno.c
	@echo    static kal_char build_str[] = "$(strip $(BUILD))"; >> $(strip $(VERNODIR))\verno.c
	@echo    return build_str; >> $(strip $(VERNODIR))\verno.c
	@echo } >> $(strip $(VERNODIR))\verno.c

	@echo kal_char* release_branch(void) >> $(strip $(VERNODIR))\verno.c
	@echo { >> $(strip $(VERNODIR))\verno.c
	@echo    static kal_char build_branch_str[] = "$(strip $(BRANCH))"; >> $(strip $(VERNODIR))\verno.c
	@echo    return build_branch_str; >> $(strip $(VERNODIR))\verno.c
	@echo } >> $(strip $(VERNODIR))\verno.c
	
	@echo kal_char* release_flavor(void) >> $(strip $(VERNODIR))\verno.c
	@echo { >> $(strip $(VERNODIR))\verno.c
	@echo    static kal_char build_flavor_str[] = "$(strip $(FLAVOR))"; >> $(strip $(VERNODIR))\verno.c
	@echo    return build_flavor_str; >> $(strip $(VERNODIR))\verno.c
	@echo } >> $(strip $(VERNODIR))\verno.c

	@echo #define VERNO_STR "$(strip $(VERNO))" > $(strip $(VERNODIR))\verno.h

	@echo #define HW_VER_STR "$(strip $(HW_VER))" >> $(strip $(VERNODIR))\verno.h
	@echo #define BUILD_DATE_TIME_STR "$(strip $(BUILD_DATE_TIME))" >> $(strip $(VERNODIR))\verno.h
	@echo #define BUILD_STR "$(strip $(BUILD))" >> $(strip $(VERNODIR))\verno.h
	@echo #define BUILD_BRANCH_STR "$(strip $(BRANCH))" >> $(strip $(VERNODIR))\verno.h

	@perl -e "print 'genverno END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# *************************************************************************
# Generate Custom Information
# *************************************************************************
gencustominfo:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@if exist $(strip $(TARGDIR))\build.log \
		(@perl -e "print 'gencustominfo START TIME='";>>$(strip $(TARGDIR))\build.log & \
		@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log)
# For RF_MODULE = MT6129D
ifdef DRV_CUSTOM_TOOL_SUPPORT
ifeq ($(strip $(DRV_CUSTOM_TOOL_SUPPORT)),TRUE)
ifeq ($(findstring MT6129D,$(strip $(RF_MODULE))),MT6129D)
	@if exist $(FIXPATH)\custom\drv\Drv_Tool\DrvGen.exe \
	(if exist $(FIXPATH)\custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\codegen_MT6129D.dws \
		   ($(FIXPATH)\custom\drv\Drv_Tool\DrvGen.exe $(FIXPATH)\custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\codegen_MT6129D.dws) \
	else \
	($(FIXPATH)\custom\drv\Drv_Tool\DrvGen.exe $(FIXPATH)\custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\codegen.dws) \
	)
endif
endif
endif

# For RF_MODULE = MT6139E
ifdef DRV_CUSTOM_TOOL_SUPPORT
ifeq ($(strip $(DRV_CUSTOM_TOOL_SUPPORT)),TRUE)
ifeq ($(findstring MT6139E,$(strip $(RF_MODULE))),MT6139E)
	@if exist $(FIXPATH)\custom\drv\Drv_Tool\DrvGen.exe \
	(if exist $(FIXPATH)\custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\codegen_MT6139E.dws \
		   ($(FIXPATH)\custom\drv\Drv_Tool\DrvGen.exe $(FIXPATH)\custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\codegen_MT6139E.dws) \
	else \
	($(FIXPATH)\custom\drv\Drv_Tool\DrvGen.exe $(FIXPATH)\custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\codegen.dws) \
	)
endif
endif
endif

# For RF_MODULE != MT6129D or != MT6139E
ifdef DRV_CUSTOM_TOOL_SUPPORT
ifeq ($(strip $(DRV_CUSTOM_TOOL_SUPPORT)),TRUE)
ifeq ($(findstring MT6129D,$(strip $(RF_MODULE))),)
ifeq ($(findstring MT6139E,$(strip $(RF_MODULE))),)
	@if /I "$(strip  $(DRV_CUSTOM_TOOL_SUPPORT))" EQU "TRUE" \
		(if exist $(FIXPATH)\custom\drv\Drv_Tool\DrvGen.exe \
		(if exist $(FIXPATH)\custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\codegen.dws \
		   ($(FIXPATH)\custom\drv\Drv_Tool\DrvGen.exe $(FIXPATH)\custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\codegen.dws) \
		) \
		)
endif
endif
endif
endif

	@if /I "$(strip  $(DRV_CUSTOM_TOOL_SUPPORT))" EQU "TRUE" \
	(if /I "$(strip $(BOARD_VER))" EQU "SUPERMAN29_DEMO_BB" \
		(if exist $(FIXPATH)\custom\drv\Drv_Tool\DrvGen.exe \
		(if exist $(FIXPATH)\custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\codegen_$(strip $(SUB_BOARD_VER)).dws \
		   ($(FIXPATH)\custom\drv\Drv_Tool\DrvGen.exe $(FIXPATH)\custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\codegen_$(strip $(SUB_BOARD_VER)).dws) \
		) \
		) \
	)

   # For rotated keypad on Tianyu28_demo landscape MMI
	@if /I "$(strip  $(DRV_CUSTOM_TOOL_SUPPORT))" EQU "TRUE" \
	(if /I "$(strip $(BOARD_VER))" EQU "TIANYU28_DEMO_BB" \
	(if /I "$(strip $(MAIN_LCD_SIZE))" EQU "320X240" \
		(if exist $(FIXPATH)\custom\drv\Drv_Tool\DrvGen.exe \
		(if exist $(FIXPATH)\custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\codegen1.dws \
		   ($(FIXPATH)\custom\drv\Drv_Tool\DrvGen.exe $(FIXPATH)\custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\codegen1.dws) \
		) \
		) \
	) \
	)

  # For rotated keypad on UNICORN53V3_DEMO landscape MMI
	@if /I "$(strip  $(DRV_CUSTOM_TOOL_SUPPORT))" EQU "TRUE" \
	(if /I "$(strip $(BOARD_VER))" EQU "UNICORN53V3_DEMO_EVB" \
	(if /I "$(strip $(MAIN_LCD_SIZE))" EQU "320X240" \
		(if exist $(FIXPATH)\custom\drv\Drv_Tool\DrvGen.exe \
		(if exist $(FIXPATH)\custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\codegen1.dws \
		   ($(FIXPATH)\custom\drv\Drv_Tool\DrvGen.exe $(FIXPATH)\custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\codegen1.dws) \
		) \
		) \
	) \
	)

  # For rotated keypad on UNICORN53V4_DEMO landscape MMI
	@if /I "$(strip  $(DRV_CUSTOM_TOOL_SUPPORT))" EQU "TRUE" \
	(if /I "$(strip $(BOARD_VER))" EQU "UNICORN53V4_DEMO_EVB" \
	(if /I "$(strip $(MAIN_LCD_SIZE))" EQU "320X240" \
		(if exist $(FIXPATH)\custom\drv\Drv_Tool\DrvGen.exe \
		(if exist $(FIXPATH)\custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\codegen1.dws \
		   ($(FIXPATH)\custom\drv\Drv_Tool\DrvGen.exe $(FIXPATH)\custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\codegen1.dws) \
		) \
		) \
	) \
	)

ifneq ($(call Upper,$(strip $(PROJECT))),BASIC)
ifneq ($(call Upper,$(strip $(PROJECT))),MEUT)
  ifeq ($(call Upper,$(strip $(CUSTOM_RELEASE))),FALSE)
    ifeq ($(strip $(call Upper,$(TOUCH_PANEL_SUPPORT))),NONE)
	-@if exist $(FIXPATH)\$(MMIDIR)\Customer\LcdResource\MainLcd$(strip $(MAIN_LCD_SIZE))\*.* \
		   (copy /y $(FIXPATH)\$(MMIDIR)\Customer\LcdResource\MainLcd$(strip $(MAIN_LCD_SIZE))\*.* $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(MMI_VERSION))\*.* > nul)
	-@if exist $(FIXPATH)\$(MMIDIR)\Customer\LcdResource\MainLcd$(strip $(MAIN_LCD_SIZE))\non_touch\*.* \
		   (copy /y $(FIXPATH)\$(MMIDIR)\Customer\LcdResource\MainLcd$(strip $(MAIN_LCD_SIZE))\non_touch\*.* $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(MMI_VERSION))\*.* > nul)
    else
      ifneq ($(strip $(call Upper,$(FINGER_TOUCH_SUPPORT))),NONE)
		-@if exist $(FIXPATH)\$(MMIDIR)\Customer\LcdResource\MainLcd$(strip $(MAIN_LCD_SIZE))\FTE\*.* \
				(copy /y $(FIXPATH)\$(MMIDIR)\Customer\LcdResource\MainLcd$(strip $(MAIN_LCD_SIZE))\FTE\*.* $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(MMI_VERSION))\*.* > nul)
      else
	-@if exist $(FIXPATH)\$(MMIDIR)\Customer\LcdResource\MainLcd$(strip $(MAIN_LCD_SIZE))\*.* \
		   (copy /y $(FIXPATH)\$(MMIDIR)\Customer\LcdResource\MainLcd$(strip $(MAIN_LCD_SIZE))\*.* $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(MMI_VERSION))\*.* > nul)
	-@if exist $(FIXPATH)\$(MMIDIR)\Customer\LcdResource\MainLcd$(strip $(MAIN_LCD_SIZE))\touch\*.* \
		   (copy /y $(FIXPATH)\$(MMIDIR)\Customer\LcdResource\MainLcd$(strip $(MAIN_LCD_SIZE))\touch\*.* $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(MMI_VERSION))\*.* > nul)
      endif    
    endif # ifeq ($(strip $(call Upper,$(TOUCH_PANEL_SUPPORT))),NONE)
  else
    ifneq ($(strip $(call Upper,$(LEVEL))),LEVEL2_OBJ)
      ifeq ($(strip $(call Upper,$(TOUCH_PANEL_SUPPORT))),NONE)
	-@if exist $(FIXPATH)\$(MMIDIR)\Customer\LcdResource\MainLcd$(strip $(MAIN_LCD_SIZE))\*.* \
		   (copy /y $(FIXPATH)\$(MMIDIR)\Customer\LcdResource\MainLcd$(strip $(MAIN_LCD_SIZE))\*.* $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(MMI_VERSION))\*.* > nul)
	-@if exist $(FIXPATH)\$(MMIDIR)\Customer\LcdResource\MainLcd$(strip $(MAIN_LCD_SIZE))\non_touch\*.* \
		   (copy /y $(FIXPATH)\$(MMIDIR)\Customer\LcdResource\MainLcd$(strip $(MAIN_LCD_SIZE))\non_touch\*.* $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(MMI_VERSION))\*.* > nul)
      else
        ifneq ($(strip $(call Upper,$(FINGER_TOUCH_SUPPORT))),NONE)
		-@if exist $(FIXPATH)\$(MMIDIR)\Customer\LcdResource\MainLcd$(strip $(MAIN_LCD_SIZE))\FTE\*.* \
					(copy /y $(FIXPATH)\$(MMIDIR)\Customer\LcdResource\MainLcd$(strip $(MAIN_LCD_SIZE))\FTE\*.* $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(MMI_VERSION))\*.* > nul)
        else
	-@if exist $(FIXPATH)\$(MMIDIR)\Customer\LcdResource\MainLcd$(strip $(MAIN_LCD_SIZE))\*.* \
		   (copy /y $(FIXPATH)\$(MMIDIR)\Customer\LcdResource\MainLcd$(strip $(MAIN_LCD_SIZE))\*.* $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(MMI_VERSION))\*.* > nul)
	-@if exist $(FIXPATH)\$(MMIDIR)\Customer\LcdResource\MainLcd$(strip $(MAIN_LCD_SIZE))\touch\*.* \
		   (copy /y $(FIXPATH)\$(MMIDIR)\Customer\LcdResource\MainLcd$(strip $(MAIN_LCD_SIZE))\touch\*.* $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(MMI_VERSION))\*.* > nul)
        endif
      endif # ifeq ($(strip $(call Upper,$(TOUCH_PANEL_SUPPORT))),NONE)
    endif # ifneq ($(strip $(call Upper,$(LEVEL))),LEVEL2_OBJ)
  endif # ifeq ($(call Upper,$(strip $(CUSTOM_RELEASE))),FALSE)
endif # ifneq ($(call Upper,$(strip $(PROJECT))),MEUT)
endif # ifneq ($(call Upper,$(strip $(PROJECT))),BASIC)
   # copy only for Neptune_Color
	@if /I "$(strip $(CUSTOMER))" EQU "NEPTUNE_COLOR" \
		(if exist $(FIXPATH)\plutommi\customer\CustResource\NEPTUNE_COLOR_MMI\Themecomponents.h \
		   (copy /y $(FIXPATH)\plutommi\Customer\CustResource\NEPTUNE_COLOR_MMI\Themecomponents.h $(FIXPATH)\plutommi\Customer\CustResource\PLUTO_MMI\Themecomponents.h > nul) \
		)


	@if /I "$(NEED_COPY_MMIFEATURE)" EQU "CUSTOMER_MMI" \
		(if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(MMI_BASE))\MMI_features_switch$(strip $(MMI_BASE_PRJ)).h \
			(copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(MMI_BASE))\MMI_features_switch$(strip $(MMI_BASE_PRJ)).h $(FIXPATH)\$(MMIDIR)\MMI\Inc\MMI_features_switch.h) \
		) & \
		(if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(CUSTOMER))_MMI\MMI_features_switch$(strip $(CUSTOMER)).h \
			(copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(CUSTOMER))_MMI\MMI_features_switch$(strip $(CUSTOMER)).h $(FIXPATH)\$(MMIDIR)\MMI\Inc\MMI_features_switch.h > nul) \
		) & \
		(if exist "$(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(CUSTOMER))_MMI\MMI_features_switch$(strip $(CUSTOMER))($(strip $(FLAVOR))).h" \
			(copy /y "$(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(CUSTOMER))_MMI\MMI_features_switch$(strip $(CUSTOMER))($(strip $(FLAVOR))).h" $(FIXPATH)\$(MMIDIR)\MMI\Inc\MMI_features_switch.h > nul) \
		)


	@if /I "$(NEED_COPY_MMIFEATURE)" EQU "PLUTO_MMI" \
		(if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\PLUTO_MMI\MMI_features_switchPLUTO.h \
			(copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\PLUTO_MMI\MMI_features_switchPLUTO.h $(FIXPATH)\$(MMIDIR)\MMI\Inc\MMI_features_switch.h) \
		) & \
		(if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(CUSTOMER))_MMI\MMI_features_switch$(strip $(CUSTOMER)).h \
			(copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(CUSTOMER))_MMI\MMI_features_switch$(strip $(CUSTOMER)).h $(FIXPATH)\$(MMIDIR)\MMI\Inc\MMI_features_switch.h) \
		) & \
		(if exist "$(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(CUSTOMER))_MMI\MMI_features_switch$(strip $(CUSTOMER))($(strip $(FLAVOR))).h" \
			(copy /y "$(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(CUSTOMER))_MMI\MMI_features_switch$(strip $(CUSTOMER))($(strip $(FLAVOR))).h" $(FIXPATH)\$(MMIDIR)\MMI\Inc\MMI_features_switch.h) \
		)


	@if /I "$(NEED_COPY_MMIFEATURE)" EQU "NEPTUNE_MMI" \
		(if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\NEPTUNE_MMI\MMI_features_switchNEPTUNE.h \
			(copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\NEPTUNE_MMI\MMI_features_switchNEPTUNE.h $(FIXPATH)\$(MMIDIR)\MMI\Inc\MMI_features_switch.h) \
		) & \
		(if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(CUSTOMER))_MMI\MMI_features_switch$(strip $(CUSTOMER)).h \
			(copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(CUSTOMER))_MMI\MMI_features_switch$(strip $(CUSTOMER)).h $(FIXPATH)\$(MMIDIR)\MMI\Inc\MMI_features_switch.h) \
		)


       # Because MMIDIR\mmi\inc\mmi_features.h includes switch file,
       # but EMPTY_MMI , L1S , BASIC will not copy switch file
       # So copy an empty MMI_features_switchEMPTY.h to MMIDIR\mmi\inc for new mmi feature files architecture

ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
	if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\EMPTY_MMI\MMI_features_switchEMPTY.h \
		(copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\EMPTY_MMI\MMI_features_switchEMPTY.h $(FIXPATH)\$(MMIDIR)\MMI\Inc\MMI_features_switch.h)
endif

ifeq ($(call Upper,$(PROJECT)),L1S)
	if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\EMPTY_MMI\MMI_features_switchEMPTY.h \
		(copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\EMPTY_MMI\MMI_features_switchEMPTY.h $(FIXPATH)\$(MMIDIR)\MMI\Inc\MMI_features_switch.h)
endif

ifeq ($(call Upper,$(PROJECT)),BASIC)
ifeq ($(call Upper,$(PROJECT)),MEUT)
	if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\EMPTY_MMI\MMI_features_switchEMPTY.h \
		(copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\EMPTY_MMI\MMI_features_switchEMPTY.h $(FIXPATH)\$(MMIDIR)\MMI\Inc\MMI_features_switch.h)
endif
endif

	@if /I "$(NEED_COPY_MMIFEATURE)" EQU "CUSTOMER_MMI" \
		(if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(MMI_BASE))\CustMiscData$(strip $(MMI_BASE_PRJ)).c \
		   (copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(MMI_BASE))\CustMiscData$(strip $(MMI_BASE_PRJ)).c $(FIXPATH)\$(MMIDIR)\Customer\CustResource\CustMiscData.c) \
		) & \
		(if exist $(FIXPATH)\$(MMIDIR)\customer\CustResource\$(strip $(CUSTOMER))_MMI\CustMiscData$(strip $(CUSTOMER)).c \
		   (copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(CUSTOMER))_MMI\CustMiscData$(strip $(CUSTOMER)).c $(FIXPATH)\$(MMIDIR)\Customer\CustResource\CustMiscData.c) \
		)

	@if /I "$(NEED_COPY_MMIFEATURE)" EQU "PLUTO_MMI" \
		(if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\PLUTO_MMI\CustMiscDataPLUTO.c \
		   (copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\PLUTO_MMI\CustMiscDataPLUTO.c $(FIXPATH)\$(MMIDIR)\Customer\CustResource\CustMiscData.c) \
		)

	@if /I "$(NEED_COPY_MMIFEATURE)" EQU "NEPTUNE_MMI" \
		(if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\NEPTUNE_MMI\CustMiscDataNEPTUNE.c \
		   (copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\NEPTUNE_MMI\CustMiscDataNEPTUNE.c $(FIXPATH)\$(MMIDIR)\Customer\CustResource\CustMiscData.c) \
		)

	@if /I "$(NEED_COPY_MMIFEATURE)" EQU "CUSTOMER_MMI" \
		(if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(MMI_BASE))\CustResDef$(strip $(MMI_BASE_PRJ)).h \
		   (copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(MMI_BASE))\CustResDef$(strip $(MMI_BASE_PRJ)).h $(FIXPATH)\$(MMIDIR)\Customer\CustomerInc\CustResDef.h) \
		) & \
		(if exist $(FIXPATH)\$(MMIDIR)\customer\CustResource\$(strip $(CUSTOMER))_MMI\CustResDef$(strip $(CUSTOMER)).h \
		   (copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(CUSTOMER))_MMI\CustResDef$(strip $(CUSTOMER)).h $(FIXPATH)\$(MMIDIR)\Customer\CustomerInc\CustResDef.h) \
		)

	@if /I "$(NEED_COPY_MMIFEATURE)" EQU "PLUTO_MMI" \
		(if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\PLUTO_MMI\CustResDefPLUTO.h \
		   (copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\PLUTO_MMI\CustResDefPLUTO.h $(FIXPATH)\$(MMIDIR)\Customer\CustomerInc\CustResDef.h) \
		)

	@if /I "$(NEED_COPY_MMIFEATURE)" EQU "NEPTUNE_MMI" \
		(if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\NEPTUNE_MMI\CustResDefNEPTUNE.h \
		   (copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\NEPTUNE_MMI\CustResDefNEPTUNE.h $(FIXPATH)\$(MMIDIR)\Customer\CustomerInc\CustResDef.h) \
		)

   # clean font related files in $(FIXPATH)\$(MMIDIR)\Customer\CustResource
ifneq ($(call Upper,$(PROJECT)),BASIC)
ifneq ($(call Upper,$(PROJECT)),MEUT)
ifneq ($(call Upper,$(PROJECT)),L1S)
ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
	@if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\FontRes.c \
		(del $(FIXPATH)\$(MMIDIR)\Customer\CustResource\FontRes.c)

	@if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\L_*.h \
		(if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\L_MMIProp.h \
			(copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\L_MMIProp.h $(FIXPATH)\make) \
		) & \
		(del $(FIXPATH)\$(MMIDIR)\Customer\CustResource\L_*.h) & \
		(if exist $(FIXPATH)\make\L_MMIProp.h \
			(copy /y $(FIXPATH)\make\L_MMIProp.h $(FIXPATH)\$(MMIDIR)\Customer\CustResource) & \
			(del $(FIXPATH)\make\L_MMIProp.h) \
		)
endif
endif
endif
endif

ifneq ($(strip $(MMI_VERSION)),WISDOM_MMI)

	@if $(call Upper,$(PROJECT)) NEQ BASIC ( \
	if exist $(strip $(FONTRES_PATH_MTK))\FontRes.c \
		   (copy /y $(strip $(FONTRES_PATH_MTK))\FontRes.c $(FIXPATH)\$(MMIDIR)\Customer\CustResource\FontRes.c > nul) \
		   )

	@if $(call Upper,$(PROJECT)) NEQ BASIC ( \
	if exist $(strip $(FONTRES_PATH_CUST))\FontRes.c \
		   (copy /y $(strip $(FONTRES_PATH_CUST))\FontRes.c $(FIXPATH)\$(MMIDIR)\Customer\CustResource\FontRes.c > nul) \
		   )

	@if /I "$(MMI_BASE)" EQU "PLUTO_MMI" \
		(if exist $(FIXPATH)\$(MMIDIR)\customer\CustResource\PLUTO_MMI\ref_list.txt \
		   (copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\PLUTO_MMI\ref_list.txt $(FIXPATH)\$(MMIDIR)\Customer\CustResource\ref_list.txt) \
		) & \
		(if exist $(FIXPATH)\$(MMIDIR)\customer\CustResource\$(strip $(CUSTOMER))_MMI\ref_list.txt \
		   (copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(CUSTOMER))_MMI\ref_list.txt $(FIXPATH)\$(MMIDIR)\Customer\CustResource\ref_list.txt) \
		)

	@if /I "$(MMI_BASE)" EQU "NEPTUNE_MMI" \
		(if exist $(FIXPATH)\$(MMIDIR)\customer\CustResource\NEPTUNE_MMI\ref_list.txt \
		   (copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\NEPTUNE_MMI\ref_list.txt $(FIXPATH)\$(MMIDIR)\Customer\CustResource\ref_list.txt) \
		) & \
		(if exist $(FIXPATH)\$(MMIDIR)\customer\CustResource\$(strip $(CUSTOMER))_MMI\ref_list.txt \
		   (copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(CUSTOMER))_MMI\ref_list.txt $(FIXPATH)\$(MMIDIR)\Customer\CustResource\ref_list.txt) \
		)
endif
	@if exist $(strip $(TARGDIR))\build.log \
		(@perl -e "print 'gencustominfo END TIME='";>>$(strip $(TARGDIR))\build.log & \
		@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log)
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

gencustomlists: gencustominfo
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'gencustomlists START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # If module "custom" is released to customer with .lib only, don't run custominfo.pl
ifneq ($(strip $(call Upper,$(LEVEL))),VENDOR)
	@if /I "$(CUSTOM_EXIST)" EQU "TRUE" \
		(@echo Generate customization information ... >> $(LOG)) & \
		(@if /I $(PROJECT) NEQ BASIC \
			(@if /I $(PROJECT) NEQ MEUT \
				(@if /I $(PROJECT) NEQ L1S \
			   	(@if /I $(CUSTOM_RELEASE) EQU FALSE (perl tools\gencust.pl $(strip $(THE_MF)))) \
				) \
			) \
		) & \
		(perl tools\custominfo.pl $(strip $(THE_MF)) make\Custom.bld $(strip $(THE_OP_CUSTOM_LIS)) $(strip $(OPTR_PATH)))
endif
	@if /I "$(strip $(MAUI_IN_ROM))" EQU "TRUE" \
		(@if exist make\rompatch\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\rompatch.* \
			(xcopy /Y make\rompatch\$(strip $(PLATFORM))\$(strip $(CHIP_VER)) make\rompatch > nul 2>&1) \
		else \
			(echo Directory make\rompatch\$(strip $(PLATFORM))\$(strip $(CHIP_VER)) Does NOT exist.) \
		)
	@perl -e "print 'gencustomlists END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# *************************************************************************
# Check MMI Feature Files
# *************************************************************************
mmi_feature_check: gencustominfo gen_infolog
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@if exist $(strip $(TARGDIR))\build.log \
		(perl -e "print 'mmi_feature_check START TIME='";>>$(strip $(TARGDIR))\build.log & \
		perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log)
	@if exist $(strip $(TARGDIR))\log\mmi_check.log \
		(del /q /f $(strip $(TARGDIR))\log\mmi_check.log)
	@if exist $(strip $(TARGDIR))\MMI_DRV_DEFS.mak \
		(del /q /f $(strip $(TARGDIR))\MMI_DRV_DEFS.mak)
ifneq ($(strip $(MMI_VERSION)),WISDOM_MMI)
ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
ifneq ($(strip $(call Upper,$(PROJECT))),MEUT)
ifneq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
ifneq ($(strip $(MMI_VERSION)),EMPTY_MMI)
	@if exist tools\mmi_feature_check.pl \
	   (perl tools\mmi_feature_check.pl $(strip $(CUSTOMER)) $(firstword $(strip $(CC))) $(strip $(VIA)) plutommi\mmi\inc\MMI_features.h plutommi\mmi\inc\MMI_features_switch.h TRUE 0 $(strip $(TARGDIR))\MMI_DRV_DEFS.mak MMI 2>>$(strip $(TARGDIR))\log\mmi_check.log)
endif
else
ifneq ($(strip $(MMI_VERSION)),EMPTY_MMI)
	@if exist tools\mmi_feature_check.pl \
	   (perl tools\mmi_feature_check.pl $(strip $(CUSTOMER)) $(firstword $(strip $(CC))) $(strip $(VIA)) lcmmi\mmi\inc\MMI_features.h lcmmi\mmi\inc\MMI_features_switch.h TRUE 0 $(strip $(TARGDIR))\MMI_DRV_DEFS.mak MMI 2>>$(strip $(TARGDIR))\log\mmi_check.log)
endif
endif
	@if exist tools\mmi_feature_check.pl \
	   (perl tools\mmi_feature_check.pl $(strip $(CUSTOMER)) $(firstword $(strip $(CC))) $(strip $(VIA)) interface\drv_def\drv_features.h interface\drv_def\drv_features_option.h FALSE 0 $(strip $(TARGDIR))\MMI_DRV_DEFS.mak DRV 2>>$(strip $(TARGDIR))\log\mmi_check.log)
endif
endif

else

ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
	@if exist tools\mmi_feature_check.pl \
	   (perl tools\mmi_feature_check.pl $(strip $(CUSTOMER)) $(firstword $(strip $(CC))) $(strip $(VIA)) plutommi\mmi\inc\MMI_features.h plutommi\mmi\inc\MMI_features_switch.h TRUE 0 $(strip $(TARGDIR))\MMI_DRV_DEFS.mak MMI 2>>$(strip $(TARGDIR))\log\mmi_check.log)
	@if exist tools\mmi_feature_check.pl \
	   (perl tools\mmi_feature_check.pl $(strip $(CUSTOMER)) $(firstword $(strip $(CC))) $(strip $(VIA)) interface\drv_def\drv_features.h interface\drv_def\drv_features_option.h FALSE 0 $(strip $(TARGDIR))\MMI_DRV_DEFS.mak DRV 2>>$(strip $(TARGDIR))\log\mmi_check.log)
endif

endif
	@if exist $(strip $(TARGDIR))\build.log \
		(perl -e "print 'mmi_feature_check END TIME='";>>$(strip $(TARGDIR))\build.log & \
		perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log)
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# *************************************************************************
# Check Custom Menu Tree
# *************************************************************************
cust_menu_tree_check:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))	
	@perl -e "print 'cust_menu_tree_check START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
	@if exist $(FIXPATH)\MoDIS_VC9\NetSim\get_resname_for_CustMenuTreeID_Out_c.pl \
	if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\CustMenuTreeID_Out.c \
	if exist $(FIXPATH)\$(MMIDIR)\Customer\ResGenerator\menu_resource_usage.txt \
		(perl $(FIXPATH)\MoDIS_VC9\NetSim\get_resname_for_CustMenuTreeID_Out_c.pl $(FIXPATH)\$(MMIDIR)\Customer\CustResource\CustMenuTreeID_Out.c $(FIXPATH)\$(MMIDIR)\Customer\ResGenerator\menu_resource_usage.txt $(FIXPATH)\$(MMIDIR)\Customer\CustResource\owner.txt)
	
	@if exist $(FIXPATH)\MoDIS_VC9\NetSim\CustMenuTreeOutVerifier.exe \
	if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\CustMenuTree_Out.c \
		($(FIXPATH)\MoDIS_VC9\NetSim\CustMenuTreeOutVerifier.exe $(FIXPATH)\$(MMIDIR)\Customer\CustResource\CustMenuTree_Out.c)
		
	@if exist $(FIXPATH)\MoDIS_VC9\NetSim\CustMenuTreeOutVerifier_Reporter.pl \
	if exist $(FIXPATH)\MoDIS_VC9\NetSim\CustMenuTreeOutResult.txt \
		(perl $(FIXPATH)\MoDIS_VC9\NetSim\CustMenuTreeOutVerifier_Reporter.pl $(VERNO) $(MMIDIR) $(MMI_BASE) $(CUSTOMER) $(PROJECT))
endif
	@perl -e "print 'cust_menu_tree_check END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# *************************************************************************
# Check MMI Obj Values
# *************************************************************************
mmi_obj_check: sysgen mmi_feature_check genmoduleinfo
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'mmi_obj_check START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
ifneq ($(strip $(call Upper,$(PROJECT))),MEUT)
  ifneq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
    ifneq ($(strip $(MMI_VERSION)),EMPTY_MMI)
      ifneq ($(strip $(MMI_VERSION)),WISDOM_MMI)
        ifeq ($(call Upper,$(strip $(CUSTOM_RELEASE))),FALSE)
	@if exist tools\objcheck.pl \
		(perl tools\objcheck.pl $(strip $(CUSTOMER)) $(firstword $(strip $(CC))) $(strip $(VIA)))
        else
          ifneq ($(strip $(call Upper,$(LEVEL))),LEVEL2_OBJ)
	@if exist tools\objcheck.pl \
		(perl tools\objcheck.pl $(strip $(CUSTOMER)) $(firstword $(strip $(CC))) $(strip $(VIA)))
          endif # ifneq ($(strip $(call Upper,$(LEVEL))),LEVEL2_OBJ)
        endif # ifeq ($(call Upper,$(strip $(CUSTOM_RELEASE))),FALSE)
      endif # ifneq ($(strip $(MMI_VERSION)),WISDOM_MMI)
    endif # ifneq ($(strip $(MMI_VERSION)),EMPTY_MMI)
  endif # ifneq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
endif # ifneq ($(strip $(call Upper,$(PROJECT))),MEUT)
endif # ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
	@perl -e "print 'mmi_obj_check END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

dummy_data_check:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@if exist tools\ROParser.pl \
		(perl tools\ROParser.pl $(strip $(TARGDIR))\$(strip $(LIS_FILE)) $(strip $(PROJDIR))\ $(strip $(FIXPATH))\ $(strip $(SLIM_BRANCH)))
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# *************************************************************************
# To remove codes from the specified file
# *************************************************************************
removecode:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@tools\strcmpex.exe abc abc e make\~com_def.tmp $(strip $(COM_DEFS))
ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
	@echo _SST_FUNCTION_ENABLE_ >> make\~com_def.tmp
endif
ifeq ($(strip $(PRODUCTION_RELEASE)),TRUE)
	@if not exist make\$(strip $(CUSTOMER))_$(PROJECT)_en.def \
		(type make\SUPERSET_CUSTOM_en.def > make\$(strip $(CUSTOMER))_$(PROJECT)_en.def)
endif
	@if not exist make\$(strip $(CUSTOMER))_$(PROJECT)_en.def \
		(copy /y nul make\$(strip $(CUSTOMER))_$(PROJECT)_en.def > nul)
	@if not exist make\$(strip $(CUSTOMER))_$(PROJECT)_dis.def \
		(perl mtk_tools\Auto_RemovingCode.pl $(strip $(CUSTOMER)) $(PROJECT) $(CC) $(MTK_SUBSIDIARY))
	@echo .> ~customRemovalDir.tmp
	@if exist mtk_tools\traversedir.pl \
		(perl mtk_tools\traverseDir.pl "$(REMOVE_DIR)" make\$(strip $(CUSTOMER))_$(PROJECT)_en.def make\$(strip $(CUSTOMER))_$(PROJECT)_dis.def TRUE TRUE ~customRemovalDir.tmp $(strip $(NOT_REMOVAL_DIR_FILE)))
	@if exist make\~com_def.tmp del make\~com_def.tmp
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# *************************************************************************
# Generate CustPack information
# *************************************************************************
custpackini: nvram_auto_gen
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'custpackini START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
	@if not exist $(CUSTPACKDIR)	\
		(md $(CUSTPACKDIR))
	@tools\strcmpex.exe def def e make\~cuspack_optInc.tmp $(foreach def,$(COM_DEFS),-D$(def))
	@tools\strcmpex.exe inc inc e make\~cuspack_inc.tmp $(foreach inc,$(COMMINCDIRS),-I$(inc))
	@type make\~cuspack_inc.tmp >> make\~cuspack_optInc.tmp
	@type make\~cuspack_optInc.tmp >> make\~cuspack_theme_optInc.tmp
	@type make\~cuspack_optInc.tmp >> make\~cuspack_nvram_optInc.tmp
	(for /F %%i in (make\custom\custom.def) do \
		(echo -D%%i >> make\~cuspack_optInc.tmp) \
	) & \
	(for /F %%i in (make\custom\custom.inc) do \
		(echo -I%%i >> make\~cuspack_optInc.tmp) \
	)
ifeq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
	(for /F %%i in (make\lcmmiresource\lcmmiresource.def) do \
		(echo -D%%i >> make\~cuspack_theme_optInc.tmp) \
	) & \
	(for /F %%i in (make\lcmmiresource\lcmmiresource.inc) do \
		(echo -I%%i >> make\~cuspack_theme_optInc.tmp) \
	)
else
	(for /F %%i in (make\mmiresource\mmiresource.def) do \
		(echo -D%%i >> make\~cuspack_theme_optInc.tmp) \
	) & \
	(for /F %%i in (make\mmiresource\mmiresource.inc) do \
		(echo -I%%i >> make\~cuspack_theme_optInc.tmp) \
	)
endif
	@if exist custom\common\$(strip $(MMI_VERSION))\nvram_cust_pack.c \
		($(CC) $(VIA) make\~cuspack_optInc.tmp -E custom\common\$(strip $(MMI_VERSION))\nvram_cust_pack.c > ~nvram_cust_pack.c)
		
	@if exist custom\common\custpack_audio.c \
		($(CC) $(VIA) make\~cuspack_optInc.tmp -E custom\common\custpack_audio1.c > ~custpack_audio.c)
		
	@echo. > ~nvram_tmp.c
	@if exist nvram\src\nvram_data_items.c \
		(for /F %%i in (make\nvram\nvram.def) do \
			(echo -D%%i >> make\~cuspack_nvram_optInc.tmp) \
		) & \
		(for /F %%i in (make\nvram\nvram.inc) do \
			(echo -I%%i >> make\~cuspack_nvram_optInc.tmp) \
		) & \
		($(CC) $(VIA) make\~cuspack_nvram_optInc.tmp -E nvram\src\nvram_data_items.c >> ~nvram_tmp.c)

	@if exist custom\common\$(strip $(MMI_BASE))\nvram_common_config.c \
		(@if exist custom\app\$(strip $(BOARD_VER))\nvram_user_config.c \
			($(CC) $(VIA) make\~cuspack_optInc.tmp -E custom\app\$(strip $(BOARD_VER))\nvram_user_config.c >> ~nvram_tmp.c) & \
			($(CC) $(VIA) make\~cuspack_optInc.tmp -E custom\common\$(strip $(MMI_BASE))\nvram_common_config.c >> ~nvram_tmp.c) \
		)
		
	@if exist custom\common\custom_wap_cust_pack.c \
		($(CC) $(VIA) make\~cuspack_optInc.tmp -E custom\common\custom_wap_cust_pack.c > ~custom_wap_cust_pack.c)

ifeq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
	@if exist $(strip $(MMIDIR))\Customer\ResGenerator\retrieve_ext_img_names.pl \
		((cd $(strip $(MMIDIR))\Customer\ResGenerator) & \
		(perl retrieve_ext_img_names.pl $(strip $(MMIDIR))\Customer\Images\$(strip $(MMI_PROJ))$(strip $(DISPLAY_TYPE))$(strip $(MAIN_LCD_SIZE))\))
	@if exist $(strip $(MMIDIR))\Customer\ResGenerator\retrieve_ext_ado_names.pl \
		((cd $(strip $(MMIDIR))\Customer\ResGenerator) & \
		(perl retrieve_ext_ado_names.pl $(strip $(MMIDIR))\Customer\Audio\$(strip $(MMI_PROJ))\))
else
	@if exist $(strip $(MMIDIR))\Customer\ResGenerator\retrieve_ext_img_names.pl \
		((cd $(strip $(MMIDIR))\Customer\ResGenerator) & \
		(perl retrieve_ext_img_names.pl $(strip $(MMIDIR))\Customer\Images\$(strip $(MMI_PROJ))$(strip $(MAIN_LCD_SIZE))\))
	@if exist $(strip $(MMIDIR))\Customer\ResGenerator\retrieve_ext_ado_names.pl \
		((cd $(strip $(MMIDIR))\Customer\ResGenerator) & \
		(perl retrieve_ext_ado_names.pl $(strip $(MMIDIR))\Customer\Audio\$(strip $(MMI_PROJ))\))
endif
	@echo retrieve_ext_img_names.pl is done!!!
	@if exist tools\processExtractObj.pl \
		(perl tools\processExtractObj.pl ~nvram_lid_size.log ~nvram_cust_pack.c ~custom_wap_cust_pack.c $(strip $(CUSTOMER)) $(strip $(PROJECT)) $(strip $(CUSTPACKDIR)) tools\ExtractObj.ini)

# Use extractObj.pl to generate binary files
	@echo Execute extractObj.pl
	@if exist tools\extractObj.pl \
	(perl tools\extractObj.pl)

# Geerate Theme_ROM scatter files, Linker argument file and theme_rom lis files

	@echo Generate the Theme_ROM scatter file.
	@if exist tools\genThemeRomScatter.pl \
		(perl tools\genThemeRomScatter.pl $(strip $(TARGDIR))\$(TARGNAME).sym $(strip $(FIXPATH))\ThemeRom_scatter.txt $(strip $(FIXPATH))\~Theme_ROM.tmp $(strip $(CUSTPACKDIR)) theme_rom $(MMIDIR)\Customer\CustResource\themeres.c $(strip $(EMPTY_RESOURCE)) $(CUSTPACK_LNKOPT))

	@if exist $(strip $(OBJSDIR))\theme_rom\themeres.obj (del /q /f $(strip $(OBJSDIR))\theme_rom\themeres.obj)
	@if exist $(strip $(OBJSDIR))\lib\theme_rom.lib (del /q /f $(strip $(OBJSDIR))\lib\theme_rom.lib)

custpack: custpackini gencompbld theme_rom.lib
# Use Linker to generate Theme_ROM ELF file
	-@if exist $(strip $(CUSTPACKDIR))\THEME_ROM.bin \
		(del /q /f $(strip $(CUSTPACKDIR))\THEME_ROM.bin)
	-@if exist $(strip $(CUSTPACKDIR))\THEME_ROM.bin \
		(rmdir /S /Q $(strip $(CUSTPACKDIR))\THEME_ROM.bin)
ifeq ($(strip $(DISPLAY_TYPE)),BW)
 ifneq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
	@echo $(strip $(OBJSDIR))\theme_rom\themeres.obj $(strip $(OBJSDIR))\theme_rom\custpackthemeres.obj >> $(strip $(FIXPATH))\~Theme_ROM.tmp
	$(LINK) --entry dummy_entry --info unused --verbose --xref $(VIA) $(strip $(FIXPATH))\~Theme_ROM.tmp
	$(BIN_CREATE) $(strip $(CUSTPACKDIR))\THEME_ROM.elf $(BIN_FORMAT) -output $(strip $(CUSTPACKDIR))\THEME_ROM.bin
 else
	@echo It should not include Themes when DISPLAY_TYPE = BW in NEPTUNE_MMI
 endif
else
	@echo $(strip $(OBJSDIR))\theme_rom\themeres.obj $(strip $(OBJSDIR))\theme_rom\custpackthemeres.obj >> $(strip $(FIXPATH))\~Theme_ROM.tmp
	$(LINK) --entry dummy_entry --info unused $(VIA) $(strip $(FIXPATH))\~Theme_ROM.tmp
	$(BIN_CREATE) $(strip $(CUSTPACKDIR))\THEME_ROM.elf $(BIN_FORMAT) -output $(strip $(CUSTPACKDIR))\THEME_ROM.bin
endif

	@echo Generate the CustPack.ini.
ifeq ($(strip $(EMPTY_RESOURCE)),FALSE)
	@if exist tools\processCustPack.pl \
		(if exist $(strip $(MMIDIR))\Customer\CustResource\CustImgNamesExt \
			(if exist $(strip $(MMIDIR))\Customer\CustResource\CustAdoNamesExt \
			(perl tools\processCustPack.pl $(strip $(MMIDIR))\Customer\CustResource\CustImgNamesExt ~nvram_lid_size.log ~nvram_tmp.c ~nvram_cust_pack.c ~custom_wap_cust_pack.c $(strip $(MMIDIR))\Customer\CustResource\CustAdoNamesExt $(strip $(CUSTPACKDIR))\THEME_ROM.bin $(strip $(CUSTPACKDIR)) tools\CustPack.ini tools\CustPack.ini $(CODEGEN_RESULT) $(strip $(TARGDIR))\$(TARGNAME).sym $(strip $(TARGDIR))\$(strip $(BIN_FILE)))))
else
ifeq ($(strip $(BROWSER_SUPPORT)),NONE)
	@if exist tools\processCustPack.pl \
		(if exist $(strip $(MMIDIR))\Customer\CustResource\CustImgNamesExt \
			(if exist $(strip $(MMIDIR))\Customer\CustResource\CustAdoNamesExt \
			(perl tools\processCustPack.pl $(strip $(MMIDIR))\Customer\CustResource\CustImgNamesExt ~nvram_lid_size.log ~nvram_tmp.c ~nvram_cust_pack.c ~custom_wap_cust_pack.c $(strip $(MMIDIR))\Customer\CustResource\CustAdoNamesExt $(strip $(CUSTPACKDIR))\THEME_ROM.bin $(strip $(CUSTPACKDIR)) tools\CustPack.ini tools\CustPack.ini $(CODEGEN_RESULT) $(strip $(TARGDIR))\$(TARGNAME).sym $(strip $(TARGDIR))\$(strip $(BIN_FILE)) 0)))
else
	@if exist tools\processCustPack.pl \
		(if exist $(strip $(MMIDIR))\Customer\CustResource\CustImgNamesExt \
			(if exist $(strip $(MMIDIR))\Customer\CustResource\CustAdoNamesExt \
			(perl tools\processCustPack.pl $(strip $(MMIDIR))\Customer\CustResource\CustImgNamesExt ~nvram_lid_size.log ~nvram_tmp.c ~nvram_cust_pack.c ~custom_wap_cust_pack.c $(strip $(MMIDIR))\Customer\CustResource\CustAdoNamesExt $(strip $(CUSTPACKDIR))\THEME_ROM.bin $(strip $(CUSTPACKDIR)) tools\CustPack.ini tools\CustPack.ini $(CODEGEN_RESULT) $(strip $(TARGDIR))\$(TARGNAME).sym $(strip $(TARGDIR))\$(strip $(BIN_FILE)) 1)))
endif
endif
	@echo processCustPack.pl is done!!!
	@echo copy mtk_resgenerator.exe ....
	@if exist $(strip $(MMIDIR))\Customer\ResGenerator\mtk_resgenerator.exe (copy /Y $(strip $(MMIDIR))\Customer\ResGenerator\mtk_resgenerator.exe $(strip $(FIXPATH))\tools\)
	@if exist $(strip $(MMIDIR))\Customer\ResGenerator\convert.exe (copy /Y $(strip $(MMIDIR))\Customer\ResGenerator\convert.exe $(strip $(FIXPATH))\tools\)

# Run custpack.exe to generate CUSTPACK_ROM
	@echo Executing custpack.exe
	@if exist tools\CustPack.exe \
		(tools\CustPack.exe)
	@echo Done.

	@perl -e "print 'custpackini END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# *************************************************************************
# Check operator setting Files (An independent target)
# *************************************************************************
operator_check: gencustominfo gen_infolog
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'operator_check START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
ifdef OPTR_SPEC
  ifneq ($(strip $(OPTR_SPEC)),NONE)
	@if exist tools\operator_check.pl \
	   (perl tools\operator_check.pl $(strip $(CUSTOMER)) $(strip $(call Upper,$(PROJECT))) $(strip $(OPTR_WARNING_DEF)) $(firstword $(strip $(CC))) $(strip $(VIA)))

	@if exist tools\mmi_feature_check.pl \
		(@if exist $(strip $(OPTR_PATH))\operator_mmi.h \
			(perl tools\mmi_feature_check.pl $(strip $(CUSTOMER)) $(firstword $(strip $(CC))) $(strip $(VIA)) plutommi\mmi\inc\mmi_features.h $(strip $(OPTR_PATH))\operator_mmi.h TRUE $(strip $(OP_CHECK_FORCE_ERROR)) $(strip $(TARGDIR))\MMI_DRV_DEFS.mak OPTR) \
			else \
		 	(perl tools\mmi_feature_check.pl $(strip $(CUSTOMER)) $(firstword $(strip $(CC))) $(strip $(VIA)) plutommi\mmi\inc\mmi_features.h $(strip $(OPTR_PATH)\$(word 3,$(subst _, ,$(OPTR_SPEC))))\operator_mmi.h TRUE $(strip $(OP_CHECK_FORCE_ERROR)) $(strip $(TARGDIR))\MMI_DRV_DEFS.mak OPTR) \
		)
  endif
endif

	@perl -e "print 'operator_check END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# *************************************************************************
# Check if system drive space is enough or not
# *************************************************************************
$(strip $(COMPLOGDIR))\ckSysDrv.log : custom\app\$(strip $(BOARD_VER))\nvram_user_config.c custom\common\fs_quota.c tools\NVRAMStatistic\src\ckSysDrv_flash_cfg_preproc.c custom\system\$(strip $(BOARD_VER))\custom_MemoryDevice.h custom\system\$(strip $(BOARD_VER))\flash_opt.h
#cksysdrv:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'cksysdrv START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # If building for basic, l1s, don't run cksysdrv.pl
   # If module "custom" is released to customer with .lib only, don't run cksysdrv.pl
   # If NAND_FLASH_BOOTING is TRUE, don't run cksysdrv.pl
ifneq ($(strip $(call Upper,$(PROJECT))),L1S)
ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
ifneq ($(strip $(call Upper,$(PROJECT))),MEUT)
ifeq ($(strip $(CUSTOM_EXIST)),TRUE)

	@echo checking system drive space ...
	@tools\strcmpex.exe def def e make\~customIncDef.tmp $(foreach def,$(COM_DEFS),-D$(def))
	@echo -D__NULL_DEF__ >> make\~customIncDef.tmp
	@tools\strcmpex.exe inc inc e make\~customInc.tmp $(foreach inc,$(COMMINCDIRS),-I$(inc))

	@if exist custom\app\$(strip $(BOARD_VER))\nvram_user_config.c \
		(@if exist custom\common\fs_quota.c \
			(@type make\~customInc.tmp >> make\~customIncDef.tmp) & \
			(for /F %%i in (make\custom\custom.def) do \
				(echo -D%%i >> make\~customIncDef.tmp) \
			) & \
			(for /F %%i in (make\custom\custom.inc) do \
				(echo -I%%i >> make\~customIncDef.tmp) \
			) & \
			($(CC) $(VIA) make\~customIncDef.tmp -E tools\NVRAMStatistic\src\ckSysDrv_flash_cfg_preproc.c > ~flash_cfg_tmp.c) \
		)
	perl tools\ckSysDrv.pl ~flash_cfg_tmp.c ~fs_quota_usage.log ~nvram_lid_size.log $(strip $(FEATURE_OVERLOAD)) $(strip $(SYSTEM_DRIVE_ON_NAND)) $(strip $(NVRAM_PSEUDO_MERGE))> $(strip $(COMPLOGDIR))\ckSysDrv.log
 
endif
endif
endif
endif
	@perl -e "print 'cksysdrv END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

cksysdrv_slim: $(strip $(COMPLOGDIR))\ckSysDrv.log
	@echo cksysdrv was done.

cksysdrv: cksysdrv_clean nvram_auto_gen $(strip $(COMPLOGDIR))\ckSysDrv.log
	@echo cksysdrv was done.

cksysdrv_clean:
	if exist $(strip $(COMPLOGDIR))\cksysdrv.log \
		del /q /f $(strip $(COMPLOGDIR))\cksysdrv.log

# *************************************************************************
# Clean 3 emi setting related files
# *************************************************************************
emiclean:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'emiclean START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log

	@echo Clean EMI settings
	@if exist $(strip $(EMI_GENERATOR)) \
		(perl $(strip $(EMI_GENERATOR)) TRUE $(strip $(MEMORY_DEVICE_HDR)) $(strip $(THE_MF)) > $(strip $(COMPLOGDIR))\emigen.log) 2>&1

	@perl -e "print 'emiclean END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# *************************************************************************
# check scatter file and memory device consistency
# *************************************************************************
ifneq ($(strip $(call Upper,$(LEVEL))),VENDOR)
ckscatter:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'ckscatter START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log

	@if exist $(FIXPATH)\tools\ckScatter.pl \
		(perl $(FIXPATH)\tools\ckScatter.pl 1 TRUE $(SCATTERFILE) ~lis_temp ~flash_cfg_tmp.c $(strip $(THE_MF)) $(strip $(BB_FOLDER_PATH)) $(strip $(INSIDE_MTK)) > $(strip $(COMPLOGDIR))\ckscatter1.log)

	@perl -e "print 'ckscatter END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

ckscatter2:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'ckscatter2 START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log

	@if exist $(FIXPATH)\tools\ckScatter.pl \
		(if exist ~lis_temp \
		   (perl $(FIXPATH)\tools\ckScatter.pl 2 TRUE $(SCATTERFILE) ~lis_temp ~flash_cfg_tmp.c $(strip $(THE_MF)) $(strip $(BB_FOLDER_PATH)) $(strip $(INSIDE_MTK)) > $(strip $(COMPLOGDIR))\ckscatter2.log))

	@perl -e "print 'ckscatter2 END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
endif
# *************************************************************************
# Generate emi settings based on configurations in custom_MemoryDevice.h
# *************************************************************************
emigen:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'emigen START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log

	@if not exist $(COMPLOGDIR)	\
		(md $(COMPLOGDIR))
	@echo Generate EMI settings
	@if exist $(strip $(EMI_GENERATOR)) \
		(perl $(strip $(EMI_GENERATOR)) FALSE $(strip $(MEMORY_DEVICE_HDR)) $(strip $(THE_MF)) > $(strip $(COMPLOGDIR))\emigen.log) 2>&1
		
	@perl -e "print 'emigen END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

mcp_check:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'mcp_check START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
ifneq ($(call Upper,$(strip $(LEVEL))),VENDOR)
	@if not exist $(COMPLOGDIR)	(md $(COMPLOGDIR))
	@echo perl .\tools\emiMCPcheck.pl $(strip $(PLATFORM)) $(call Upper,$(strip $(PROJECT))) $(strip $(FIXPATH))\custom\system\$(strip $(BOARD_VER))
	@echo $(strip $(COMPLOGDIR))\mcp_check.log
	@perl .\tools\emiMCPcheck.pl $(call Upper,$(strip $(PLATFORM))) $(call Upper,$(strip $(PROJECT))) $(strip $(FIXPATH))\custom\system\$(strip $(BOARD_VER)) > $(strip $(COMPLOGDIR))\mcp_check.log
endif
	@perl -e "print 'mcp_check END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# *************************************************************************
# Generate custom\system\BB\* base on makefile and EMI.h
# *************************************************************************
sysgen: emigen mcp_check
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'sysgen START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
	@if exist $(strip $(SCATTERFILE)) (perl tools\emidel.pl $(strip $(SCATTERFILE)))
	@if exist $(strip $(BL_SCATTERFILE)) (perl tools\emidel.pl $(strip $(BL_SCATTERFILE)))
	@if exist $(strip $(FOTA_SCATTERFILE)) (perl tools\emidel.pl $(strip $(FOTA_SCATTERFILE)))
	@if exist $(FIXPATH)\tools\scatGen.pl \
			(perl $(FIXPATH)\tools\scatGen.pl $(SCATTERFILE) $(BL_SCATTERFILE) $(FOTA_SCATTERFILE) $(strip $(THE_MF)) $(FIXPATH)\custom\system\$(strip $(BOARD_VER)) $(strip $(NEED_BUILD_BOOTLOADER)) $(strip $(INSIDE_MTK)) > $(strip $(COMPLOGDIR))\sysgen.log)
else
	@if exist $(strip $(SCATTERFILE)) (perl tools\emidel.pl $(strip $(SCATTERFILE)))
	@if exist $(strip $(BL_SCATTERFILE)) (perl tools\emidel.pl $(strip $(BL_SCATTERFILE)))
	@if exist $(strip $(FOTA_SCATTERFILE)) (perl tools\emidel.pl $(strip $(FOTA_SCATTERFILE)))
	@if exist $(FIXPATH)\tools\scatGen.pl \
			(perl $(FIXPATH)\tools\scatGen.pl $(SCATTERFILE) $(BL_SCATTERFILE) $(FOTA_SCATTERFILE) $(strip $(THE_MF)) $(FIXPATH)\custom\system\$(strip $(BOARD_VER)) $(strip $(NEED_BUILD_BOOTLOADER)) $(strip $(INSIDE_MTK)) > $(strip $(COMPLOGDIR))\sysgen.log)
endif
	@if exist $(FIXPATH)\tools\sysGen1.pl \
		(perl $(FIXPATH)\tools\sysGen1.pl $(FIXPATH)\custom\system\$(strip $(BOARD_VER)) $(strip $(THE_MF)) >> $(strip $(COMPLOGDIR))\sysgen.log)
	@if exist $(FIXPATH)\tools\sysGen2.pl \
		(perl $(FIXPATH)\tools\sysGen2.pl $(FIXPATH)\custom\system\$(strip $(BOARD_VER)) $(SCATTERFILE) $(strip $(THE_MF)) >> $(strip $(COMPLOGDIR))\sysgen.log)
	@perl -e "print 'sysgen END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# *************************************************************************
# Generate cmm files for different SUB_BOARD_VER
# *************************************************************************
ifeq ($(call Upper,$(strip $(LEVEL))),VENDOR)
cmmgen:
else
cmmgen:
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'cmmgen START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log

ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
	@if not exist $(strip $(TARGDIR))\$(strip $(BIN_FILE)) \
		((echo $(strip $(TARGDIR))\$(strip $(BIN_FILE)) does not exist. Please check it.) & (exit 2))

	@echo Generate cmm files
	@if exist mtk_tools\NocodeCMMAutoGen.pl  \
		(if exist ~lis_temp \
		((perl mtk_tools\NocodeCMMAutoGen.pl $(strip $(THE_MF)) $(strip $(FLASH_OPTIONS_HDR)) $(FIXPATH)\$(strip $(TARGNAME))_nocode.cmm ~lis_temp inc\reg_base_$(strip $(PLATFORM)).h) & \
		 (perl mtk_tools\NocodeCMMAutoGen.pl -ps1 $(strip $(THE_MF)) $(strip $(FLASH_OPTIONS_HDR)) $(FIXPATH)\$(strip $(TARGNAME))_MTK_only.cmm ~lis_temp)) \
		else \
		((perl mtk_tools\NocodeCMMAutoGen.pl $(strip $(THE_MF)) $(strip $(FLASH_OPTIONS_HDR)) $(FIXPATH)\$(strip $(TARGNAME))_nocode.cmm $(strip $(TARGDIR))\$(TARGNAME).lis inc\reg_base_$(strip $(PLATFORM)).h) & \
		 (perl mtk_tools\NocodeCMMAutoGen.pl -ps1 $(strip $(THE_MF)) $(strip $(FLASH_OPTIONS_HDR)) $(FIXPATH)\$(strip $(TARGNAME))_MTK_only.cmm $(strip $(TARGDIR))\$(TARGNAME).lis)))
  ifeq ($(strip $(PLATFORM)),MT6268T)
		@if exist mtk_tools\FastDLCMMUpdateVerno.pl  \
			(perl mtk_tools\FastDLCMMUpdateVerno.pl $(strip $(VERNO)) $(FIXPATH)\Fast_DL\MT6268T_FastDL.cmm $(strip $(THE_MF)) $(strip $(BTLD_VERNO)))
		@if exist mtk_tools\metaCMMUpdateVerno.pl \
			(perl mtk_tools\metaCMMUpdateVerno.pl $(strip $(VERNO)) $(FIXPATH)\MT6268T_meta.cmm $(strip $(THE_MF)))
  else
		@if exist mtk_tools\FastDLCMMAutoGen.pl  \
			(perl mtk_tools\FastDLCMMAutoGen.pl $(strip $(THE_MF)) $(strip $(FLASH_OPTIONS_HDR)) $(FIXPATH)\Fast_DL\$(strip $(TARGNAME)).cmm)
  endif
endif
	@perl -e "print 'cmmgen END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# *************************************************************************
# Library Targets
# *************************************************************************
ifneq ($(strip $(LINT)),TRUE)
ifneq ($(strip $(XGC_AND_NOT_BOOTLOADER)),TRUE)
libs: cleanlib startbuildlibs $(COMPLIBLIST)
else 
libs : echo_lib_lists cleanlib startbuildlibs xgc_all_libs_2
endif 
else
libs: $(LINT_COMP_LIST)
endif

echo_lib_lists	:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@echo COMPLIBLIST=$(COMPLIBLIST) > make\complib.txt
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

startbuildlibs: gencompbld
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@echo Start to build $(COMPLIBLIST)
# Copy plutommi header files to a temp folder to improve compiler performance.
ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
ifeq ($(strip $(REDUCE_PLUTO_HEADER_DEPTH)),TRUE)
	@perl -e "print 'hTogether START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log

ifeq ($(strip $(RUN_HTOGETHER)),TRUE)
	if exist $(CUS_MTK_LIB)\tools\copy_mmi_include_h.bat (copy $(CUS_MTK_LIB)\tools\copy_mmi_include_h.bat tools\copy_mmi_include_h.bat)
else

ifeq ($(strip $(RTOS)),NUCLEUS)
	@copy /Y tools\copy_mmi_include_h_nucleus.bat tools\copy_mmi_include_h.bat
endif
ifeq ($(strip $(RTOS)),NUCLEUS_V2)
	@copy /Y tools\copy_mmi_include_h_nucleus_v2.bat tools\copy_mmi_include_h.bat
endif
endif
	@echo Copying header files ......
	-@if exist $(strip $(HEADER_TEMP)) (del /q /f $(strip $(HEADER_TEMP))\*.*)
	-@if exist $(strip $(HEADER_TEMP)) (del /q /f $(strip $(HEADER_TEMP)))
	@if exist tools\mmi_include.dep (del /q /f tools\mmi_include.dep)
	@if not exist $(strip $(HEADER_TEMP)) (md $(strip $(HEADER_TEMP)))
	-@tools\copy_mmi_include_h.bat $(strip $(HEADER_TEMP)) 1>nul

	@perl -e "print 'hTogether END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log

endif
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

cleanlib:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'cleanlib START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log

   # can be moved to genlog
	-@if exist $(strip $(TARGDIR))\$(NEWTARGNAME).bin (del $(strip $(TARGDIR))\$(strip $(NEWTARGNAME)).bin)
	-@if exist $(strip $(TARGDIR))\$(TARGNAME).elf (del $(strip $(TARGDIR))\$(strip $(TARGNAME)).elf)
	-@if exist $(strip $(TARGDIR))\$(TARGNAME).lis (del $(strip $(TARGDIR))\$(strip $(TARGNAME)).lis)
	-@if exist $(strip $(TARGDIR))\$(TARGNAME).sym (del $(strip $(TARGDIR))\$(strip $(TARGNAME)).sym)
	-@if exist $(strip $(TARGDIR))\$(TARGNAME).htm (del $(strip $(TARGDIR))\$(strip $(TARGNAME)).htm)

ifneq ($(strip $(LINT)),TRUE)
	@echo Clean $(COMPLIBLIST) under $(strip $(COMPLIBDIR))
	-@for /d %%i in ($(COMPLIBLIST)) do \
		(@if exist $(strip $(COMPLIBDIR))\%%i if not exist $(strip $(OBJSDIR))\%%~ni md $(strip $(OBJSDIR))\%%~ni)
	-@for /d %%i in ($(COMPLIBLIST)) do \
		(@if exist $(strip $(COMPLIBDIR))\%%i if not exist $(strip $(OBJSDIR))\%%~ni\*.obj (copy $(strip $(COMPLIBDIR))\%%i $(strip $(OBJSDIR))\%%~ni\%%i_bak ))		
endif

ifneq ($(strip $(LINT)),TRUE)
ifdef BOOTLOADER_CHE
  ifeq ($(strip $(call Upper,$(BOOTLOADER_CHE))),ON)
    ifneq ($(strip $(DO_UPDATE_MODULE)),TRUE)
      ifneq ($(strip $(DO_REMAKE_MODULE)),TRUE)
			-@for /d %%i in ($(COMPLIBLIST)) do \
				(@if exist $(strip $(COMPLIBDIR))\%%i \
					(if "%%i" NEQ "che.lib" \
						(if "%%i" NEQ "sst_sec.lib" \
							(if "%%i" NEQ "ssf.lib" (del $(strip $(COMPLIBDIR))\%%i))))
      else
			-@for /d %%i in ($(COMPLIBLIST)) do \
				(@if exist $(strip $(COMPLIBDIR))\%%i (del $(strip $(COMPLIBDIR))\%%i))  
      endif
    else
			-@for /d %%i in ($(COMPLIBLIST)) do \
				(@if exist $(strip $(COMPLIBDIR))\%%i (del $(strip $(COMPLIBDIR))\%%i))
    endif
  else
	-@for /d %%i in ($(COMPLIBLIST)) do \
		(@if exist $(strip $(COMPLIBDIR))\%%i (del $(strip $(COMPLIBDIR))\%%i))
  endif
else
	-@for /d %%i in ($(COMPLIBLIST)) do \
		(@if exist $(strip $(COMPLIBDIR))\%%i (del $(strip $(COMPLIBDIR))\%%i))
endif
endif

	@perl -e "print 'cleanlib END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

ifneq ($(strip $(LINT)),TRUE)
ifneq ($(strip $(XGC_AND_NOT_BOOTLOADER)),TRUE)
%.lib:
else
xgc_all_libs xgc_all_libs_2:
endif
else
%.ltp: gencompbld
endif
   # mbis time probe
ifneq ($(strip $(XGC)),TRUE)
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_S,$(@F),L,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@if /I "$(strip $(MBIS_EN_OBJ_LOG))" EQU "TRUE" \
		(if not exist $(TARGDIR)\log\mbis\$* (md $(TARGDIR)\log\mbis\$*) &\
		if exist $(TARGDIR)\log\mbis\$*\*.mbis (del /q /f $(TARGDIR)\log\mbis\$*\*.mbis))
else
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_S,$@,L,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
endif

	-@if not exist $(strip $(COMPLIBDIR))	\
		(md $(COMPLIBDIR))

ifneq ($(strip $(XGC_AND_NOT_BOOTLOADER)),TRUE)
	@if $*==fota \
		(@echo Beginning $* component build process ... > $(FOTA_LOG)) \
	else \
		@if $*==bootloader \
			(@echo Beginning $* component build process ... > $(BOOTLOADER_LOG)) \
		else \
			(@echo Beginning $* component build process ... >> $(LOG))
		
	@if $*==theme_rom \
		(if $(MMI_VERSION)==NEPTUNE_MMI \
		(copy /Y make\theme_rom\lcmmi\*.* make\theme_rom) \
		else \
		(copy /Y make\theme_rom\plutommi\*.* make\theme_rom))
	
	@perl tools\time.pl
	@echo Building $*
	@echo                     LOG: $(strip $(COMPLOGDIR))\$*.log

	@if not exist $(strip $(OBJSDIR))\$* (md $(strip $(OBJSDIR))\$*)
	@if $(ACTION)==new if exist $(strip $(RULESDIR))\$*.dep del /q /f $(strip $(RULESDIR))\$*.dep
	@if $(ACTION)==bm_new if exist $(strip $(RULESDIR))\$*.dep del /q /f $(strip $(RULESDIR))\$*.dep
	@if not $(ACTION)==remake if not exist $(strip $(RULESDIR))\$*_dep md $(strip $(RULESDIR))\$*_dep
	@if $(ACTION)==new if exist $(strip $(RULESDIR))\$*_dep\*.det del /f /q $(strip $(RULESDIR))\$*_dep\*.det
	@if $(ACTION)==bm_new if exist $(strip $(RULESDIR))\$*_dep\*.det del /f /q $(strip $(RULESDIR))\$*_dep\*.det
	@if exist *.via del /f /q *.via
	@if exist *.d del /f /q *.d
endif
   # -----------------------------
   # invoke component build script
   # -----------------------------
	
# Start to extract obj
ifneq ($(strip $(LINT)),TRUE)
  ifneq ($(strip $(XGC)),TRUE)
    ifneq ($(strip $(RVCT_PARTIAL_LINK)),TRUE)
			@if exist $(strip $(OBJSDIR))\$*\$*.lib_bak if not exist $(subst /,\,$(OBJSDIR))\$*\*.obj  perl tools\extract_obj_from_lib.pl  $(subst /,\,$(OBJSDIR))\$*\$*.lib_bak  $(subst /,\,$(OBJSDIR))\$* $(subst /,\,$(LIB)) $(TARGDIR)\module\$*\$*.lis
    endif
  else
     #...
  endif
endif
# End of extract obj

	@perl -e "print '$* START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
ifneq ($(strip $(LINT)),TRUE)
#@echo tools\make.exe -fmake\comp.mak -r -R COMPONENT=$* ... $(strip $(COMPLOGDIR))\$*.log
ifneq ($(strip $(XGC_AND_NOT_BOOTLOADER)),TRUE)
	@(tools\make.exe -fmake\comp.mak -k -r -R $(strip $(CMD_ARGU)) COMPONENT=$* setup_env > $(strip $(COMPLOGDIR))\$*_setEnv.log 2>&1) 
	@if /I %OS% EQU WINDOWS_NT \
		(if /I $(BM_NEW) EQU TRUE \
			(if not exist $(strip $(COMPLOGDIR))\$* md $(strip $(COMPLOGDIR))\$*) & \
			(tools\make.exe -fmake\comp.mak -k -r -R $(strip $(CMD_ARGU)) COMPONENT=$* update_lib > $(strip $(COMPLOGDIR))\$*.log 2>&1) & \
			(if ERRORLEVEL 1 \
			  (perl tools\get_log.pl $(strip $(COMPLOGDIR))\$*.log $(strip $(COMPLOGDIR))\$* tools\copy_mmi_include_h.bat) & \
			  (rd /S /Q $(strip $(COMPLOGDIR))\$*) & \
			  (rd /S /Q $(strip $(HEADER_TEMP))) & \
			  (exit 1) \
			else \
			  (perl tools\get_log.pl $(strip $(COMPLOGDIR))\$*.log $(strip $(COMPLOGDIR))\$* tools\copy_mmi_include_h.bat) & \
			  (rd /S /Q $(strip $(COMPLOGDIR))\$*) \
			) \
		else \
			(if not exist $(strip $(COMPLOGDIR))\$* md $(strip $(COMPLOGDIR))\$*) & \
			(tools\make.exe -fmake\comp.mak -r -R $(strip $(CMD_ARGU)) COMPONENT=$* update_lib > $(strip $(COMPLOGDIR))\$*.log 2>&1) & \
			(if ERRORLEVEL 1 \
			  (perl tools\get_log.pl $(strip $(COMPLOGDIR))\$*.log $(strip $(COMPLOGDIR))\$* tools\copy_mmi_include_h.bat) & \
			  (rd /S /Q $(strip $(COMPLOGDIR))\$*) & \
			  (rd /S /Q $(strip $(HEADER_TEMP))) & \
			  (exit 1) \
			else \
			  (perl tools\get_log.pl $(strip $(COMPLOGDIR))\$*.log $(strip $(COMPLOGDIR))\$* tools\copy_mmi_include_h.bat) & \
			  (rd /S /Q $(strip $(COMPLOGDIR))\$*) \
			) \
		) \
	else \
		(if /I $(BM_NEW) EQU TRUE \
			(tools\make.exe -fmake\comp.mak -k -r -R $(strip $(CMD_ARGU)) COMPONENT=$* update_lib > $(strip $(COMPLOGDIR))\$*.log) \
		else \
			(tools\make.exe -fmake\comp.mak -r -R $(strip $(CMD_ARGU)) COMPONENT=$* update_lib > $(strip $(COMPLOGDIR))\$*.log) \
		)

ifeq ($(strip $(WIFI_SUPPORT)),MT5911)
	@if $*==wndrv \
		((if not exist $(FIXPATH)\custom\drv\wifi\$(strip $(BOARD_VER))\$(strip $(FLAVOR)) md $(FIXPATH)\custom\drv\wifi\$(strip $(BOARD_VER))\$(strip $(FLAVOR))) & \
			(if exist $(OBJSDIR)\lib\wndrv.lib \
				(move /Y $(OBJSDIR)\lib\wndrv.lib $(FIXPATH)\custom\drv\wifi\$(strip $(BOARD_VER))\$(strip $(FLAVOR))\wndrv.lib)))
endif


else
#XGC	
	@if /I %OS% EQU WINDOWS_NT \
		(if /I $(BM_NEW) EQU TRUE \
			(XGConsole /command="tools\make.exe  -fmake\intermed.mak -k -r -R $(strip $(CMD_ARGU))  " /NOLOGO /profile="tools\XGConsole.xml" )  \
		else \
			(XGConsole /command="tools\make.exe  -fmake\intermed.mak -r -R $(strip $(CMD_ARGU))   " /NOLOGO /profile="tools\XGConsole.xml"  )  \
		) \
	else \
		(if /I $(BM_NEW) EQU TRUE \
			(XGConsole /command="tools\make.exe  -fmake\intermed.mak -k -r -R $(strip $(CMD_ARGU))  " /NOLOGO /profile="tools\XGConsole.xml" ) \
		else \
			(XGConsole /command="tools\make.exe  -fmake\intermed.mak -r -R $(strip $(CMD_ARGU))  " /NOLOGO /profile="tools\XGConsole.xml"  ) \
		)
endif

ifneq ($(strip $(XGC_AND_NOT_BOOTLOADER)),TRUE)
	@if $*==fota \
		(@type $(strip $(COMPLOGDIR))\$*.log >> $(FOTA_LOG)) \
	else \
		@if $*==bootloader \
			(@type $(strip $(COMPLOGDIR))\$*.log >> $(BOOTLOADER_LOG)) \
		else \
			(@type $(strip $(COMPLOGDIR))\$*.log >> $(LOG))
				
	@perl .\tools\chk_lib_err_warn.pl $(strip $(COMPLOGDIR))\$*.log
endif
	
else
#LINT
	@if not exist $(COMPLINTLOGDIR)	(md $(COMPLINTLOGDIR))
	@if exist $(strip $(COMPLINTLOGDIR))\targetl.end del /F /Q $(strip $(COMPLINTLOGDIR))\targetl.end
	-@if exist $(strip $(COMPLINTLOGDIR))\$*_build.log del /F /Q $(strip $(COMPLINTLOGDIR))\$*_build.log
	-@if exist $(strip $(COMPLINTLOGDIR))\$*.log del /F /Q $(strip $(COMPLINTLOGDIR))\$*.log
	@tools\make.exe -fmake\comp.mak -k -r -R $(strip $(CMD_ARGU)) COMPONENT=$* update_lib> $(strip $(COMPLINTLOGDIR))\$*_build.log 2>&1 
endif
	@perl -e "print '$* END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
ifneq ($(strip $(XGC)),TRUE)
	@if /I "$(strip $(MBIS_EN_OBJ_LOG))"  EQU "TRUE" (if exist $(TARGDIR)\log\mbis\$*\*.mbis (perl tools\mbis.pl -o $(TARGDIR)\log\mbis\$*)) 
	@if exist $(TARGDIR)\log\mbis\$*\*.mbis ((del /q /f $(TARGDIR)\log\mbis\$*\*.mbis) & (rmdir /S /Q $(TARGDIR)\log\mbis\$*))
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$(@F),L,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
else
	@if /I "$(strip $(MBIS_EN))" EQU "TRUE" (@perl -e "print 'T_E,$@,L,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
endif
# *************************************************************************
# Scan Target For Scanning Header Dependencies
# *************************************************************************
ifeq ($(strip $(CHECK_SCAN)),TRUE)
scan: $(COMP_DEP_LIST)
else
scan: cleandep $(COMP_DEP_LIST)
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@echo Scanning Header Dependencies finished.
ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
ifeq ($(strip $(REDUCE_PLUTO_HEADER_DEPTH)),TRUE)
	@if exist $(strip $(HEADER_TEMP)) (rd /S /Q $(strip $(HEADER_TEMP)))
endif
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

cleandep:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	-@for /d %%i in ($(COMPSCANLIST)) do \
		(@echo clean %%i.dep) & \
		(@if exist $(strip $(RULESDIR))\%%i.dep (del $(strip $(RULESDIR))\%%i.dep))
# Copy plutommi header files to a temp folder to improve compiler performance.
ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
ifeq ($(strip $(REDUCE_PLUTO_HEADER_DEPTH)),TRUE)
ifeq ($(strip $(RTOS)),NUCLEUS)
	@copy /Y tools\copy_mmi_include_h_nucleus.bat tools\copy_mmi_include_h.bat
endif
ifeq ($(strip $(RTOS)),NUCLEUS_V2)
	@copy /Y tools\copy_mmi_include_h_nucleus_v2.bat tools\copy_mmi_include_h.bat
endif
	@if exist $(strip $(HEADER_TEMP)) (del /q /f $(strip $(HEADER_TEMP))\*.*)
	@if not exist $(strip $(HEADER_TEMP)) (md $(strip $(HEADER_TEMP)))
	-@tools\copy_mmi_include_h.bat $(strip $(HEADER_TEMP)) 1>nul
endif
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

%.dep: gencompbld
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,D,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	echo scan $* dependency. >> $(LOG)
	@if exist *.d (del /f /q *.d)
	@if exist *.via (del /f /q *.via)
	@if not exist $(strip $(RULESDIR))\$@ \
		(if not exist $(strip $(RULESDIR))\$*_dep (md $(strip $(RULESDIR))\$*_dep)) & \
		(if /I %OS% EQU WINDOWS_NT \
			(if not exist $(strip $(COMPLOGDIR))\$*_dep md $(strip $(COMPLOGDIR))\$*_dep) & \
			(tools\make.exe -fmake\comp.mak -k -r -R $(strip $(CMD_ARGU)) COMPONENT=$* update_dep > $(strip $(COMPLOGDIR))\$*_dep.log 2>&1) & \
			(if NOT ERRORLEVEL 1 \
				(rd /S /Q $(strip $(COMPLOGDIR))\$*_dep) & (del /q $(strip $(COMPLOGDIR))\$*_dep.log)  \
			 ) \
		else \
			(tools\make.exe -fmake\comp.mak -k -r -R $(strip $(CMD_ARGU)) COMPONENT=$* update_dep > $(strip $(COMPLOGDIR))\$*_dep.log))
		
	@echo $(strip $(RULESDIR))\$@
	
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,D,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

# *************************************************************************
# Standard "cleanall" Target
# *************************************************************************
cleanall:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'cleanall START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log

   # -----------------------------
   # Check build root, target, and project directories
   #
   # build ->
   #  +-$(CUSTOMER)
   #     +-$(PROJECT)
   #        +-$(PLATFORM)r    - Dependency directory
   #        +-$(PLATFORM)o    - Object directory
   #           +-$(COMPLIST)  - Component object directory
   #           +-lib          - Component libraries directory
   # -----------------------------
	@echo Cleaning directories under $(strip $(PROJDIR)) ...
	@if not exist $(BUILDDIR)  \
		md $(BUILDDIR)

	@-if not exist $(TARGDIR)                             \
		(md $(TARGDIR))                                   	\
	else                                                 	\
		(@if /I %OS% EQU Windows_NT                      	\
			(@if exist $(strip $(TARGDIR))\$(NEWTARGNAME).bin \
				(del /Q $(strip $(TARGDIR))\$(NEWTARGNAME).bin)) & 	\
			(@if exist $(strip $(TARGDIR))\$(NEWTARGNAME).bin \
			   (rd /S /Q $(strip $(TARGDIR))\$(NEWTARGNAME).bin)) 	\
		else                                              	\
			(@if exist $(strip $(TARGDIR))\$(NEWTARGNAME).bin \
				(del $(strip $(TARGDIR))\$(NEWTARGNAME).bin))) &  	\
		(@if exist $(strip $(TARGDIR))\$(TARGNAME).elf \
			(del $(strip $(TARGDIR))\$(TARGNAME).elf)) &      	\
		(@if exist $(strip $(TARGDIR))\$(TARGNAME).lis \
			(del $(strip $(TARGDIR))\$(TARGNAME).lis)) &      	\
		(@if exist $(strip $(TARGDIR))\$(TARGNAME).sym \
			(del $(strip $(TARGDIR))\$(TARGNAME).sym)) &      	\
		(@if exist $(strip $(TARGDIR))\$(TARGNAME).htm \
			(del $(strip $(TARGDIR))\$(TARGNAME).htm)) &      	\
		(@if exist $(strip $(TARGDIR))\*.log (del /q $(strip $(TARGDIR))\*.log))

	if exist $(strip $(COMPLOGDIR))\cksysdrv.log \
		attrib +r $(strip $(COMPLOGDIR))\cksysdrv.log

	-@if not exist $(COMPLOGDIR)	\
		(md $(COMPLOGDIR))         \
	else                          \
		(@if exist $(strip $(COMPLOGDIR))\*.log (del /q $(strip $(COMPLOGDIR))\*.log))

	if exist $(strip $(COMPLOGDIR))\cksysdrv.log \
		attrib -r $(strip $(COMPLOGDIR))\cksysdrv.log

ifeq ($(strip $(LINT)),TRUE)	
	-@if not exist $(COMPLINTLOGDIR)	(md $(COMPLINTLOGDIR)) 
endif

	-@if exist make\~romizing.log \
		(copy /Y make\~romizing.log $(strip $(COMPLOGDIR))\romizing.log)

   # -----------------------------
   # Remove TST database files
   # -----------------------------
	-@if /I $(NEED_RM_TSTDB) EQU TRUE						\
		(@if exist $(strip $(TST_DB))\msglog_db\pri.db (del $(strip $(TST_DB))\msglog_db\pri.db)) &   	\
		(@if exist $(strip $(TST_DB))\pstrace_db\*.ptr (del $(strip $(TST_DB))\pstrace_db\*.ptr)) &   	\
		(@if exist $(strip $(TST_DB))\msglog_db\BInfo (del $(strip $(TST_DB))\msglog_db\BInfo)) &   	\
		(@if exist $(strip $(TST_DB))\pstrace_db\BPInfo (del $(strip $(TST_DB))\pstrace_db\BPInfo)) &   	\
		(@if exist $(strip $(TST_DB))\l1trace_db\BPLInfo (del $(strip $(TST_DB))\l1trace_db\BPLInfo)) &	\
		(@if exist $(strip $(TST_DB))\BPLVInfo (del $(strip $(TST_DB))\BPLVInfo)) &   				\
		(@if exist $(strip $(TST_DB))\pstrace_db\ps_trace.h (del $(strip $(TST_DB))\pstrace_db\ps_trace.h))

	-@if exist $(CODE_GEN_LST)						         \
		(copy $(CODE_GEN_LST) make\~codegenlis.tmp) &   \
		(@for /f %%i in ($(CODE_GEN_LST)) do 	         \
			(@if exist %%i (del %%i))                                    \
		) &							 	         \
		(@if exist $(CODE_GEN_LST) (del $(CODE_GEN_LST)))

	@if not exist $(PROJDIR)   \
		(md $(PROJDIR))


	-@if not exist $(RULESDIR)  									\
		(md $(RULESDIR))												\
	else																	\
		(@echo Cleaning directories under $(RULESDIR)) &	\
		(@if exist $(strip $(RULESDIR))\*.dep (del $(strip $(RULESDIR))\*.dep))


	@if not exist $(OBJSDIR)   \
		(md $(OBJSDIR))

   # -----------------------------
   # Check component directories
   # -----------------------------
   #
   #  Blackfin compiler output object filename extension can only be .doj or .o 
   
	-@for /d %%i in ($(COMPLIST)) do 			\
		(@if not exist $(strip $(OBJSDIR))\%%i	\
			(md $(strip $(OBJSDIR))\%%i)			\
		else												\
			(@echo Cleaning object files under %%i) & \
			(@if exist $(strip $(OBJSDIR))\%%i\*.obj (del $(strip $(OBJSDIR))\%%i\*.obj)) & \
			(@if exist $(strip $(OBJSDIR))\%%i\%%i.lib_bak (del $(strip $(OBJSDIR))\%%i\%%i.lib_bak)))


ifeq ($(strip $(call Upper,$(COMPILER))),BLACKFIN)			
	-@for /d %%i in ($(COMPLIST)) do 			\
		(@if not exist $(strip $(OBJSDIR))\%%i	\
			(md $(strip $(OBJSDIR))\%%i)			\
		else												\
			(@echo Cleaning object files under %%i) & \
			(@if exist $(strip $(OBJSDIR))\%%i\*.obj (del $(strip $(OBJSDIR))\%%i\*.obj)) & \
			(@if exist $(strip $(OBJSDIR))\%%i\*.o (del $(strip $(OBJSDIR))\%%i\*.o)) & \
			(@if exist $(strip $(OBJSDIR))\%%i\%%i.lib_bak (del $(strip $(OBJSDIR))\%%i\%%i.lib_bak)))
endif



	-@if not exist $(strip $(COMPLIBDIR))	\
		(md $(COMPLIBDIR)) 						\
	else												\
		(@echo Cleaning lib files under $(COMPLIBDIR)) & \
		(@if exist $(strip $(COMPLIBDIR))\*.lib (del $(strip $(COMPLIBDIR))\*.lib))

	@perl -e "print 'cleanall END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

cleanbin:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'cleanbin START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log

	@if exist $(INFOLOG) \
		(@if exist ps\mcddll (copy /y $(INFOLOG) ps\mcddll > nul))

	-@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM          \
		(rd /s /q $(strip $(TARGDIR))\$(BIN_FILE))

	@perl -e "print 'cleanbin END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# *************************************************************************
# Standard "genlog" Target
# *************************************************************************
genlog: gen_infolog gen_infomakelog
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'genlog START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
	-@if exist make\~romizing.log \
		(copy /Y make\~romizing.log $(strip $(COMPLOGDIR))\romizing.log)
	@perl -e "print 'genlog END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
# *************************************************************************
# Standard "cleanmod" Target
# *************************************************************************
cleanmod:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
   # -----------------------------
   # Check build root, target, and project directories
   #
   # build ->
   #  +-$(CUSTOMER)
   #     +-$(PROJECT)
   #        +-$(PLATFORM)r    - Dependency directory
   #        +-$(PLATFORM)o    - Object directory
   #           +-$(COMPLIST)  - Component object directory
   #           +-lib          - Component libraries directory
   # -----------------------------
	@echo Cleaning directories under $(strip $(PROJDIR)) ...
	@if not exist $(BUILDDIR)  \
		md $(BUILDDIR)

	@-if not exist $(TARGDIR)                             \
		(md $(TARGDIR))                                   	\
	else                                                 	\
		(@if /I %OS% EQU Windows_NT                      	\
			(@if exist $(strip $(TARGDIR))\$(NEWTARGNAME).bin (del /Q $(strip $(TARGDIR))\$(NEWTARGNAME).bin)) & 	\
			(@if exist $(strip $(TARGDIR))\$(NEWTARGNAME).bin (rd /S /Q $(strip $(TARGDIR))\$(NEWTARGNAME).bin)) 	\
		else                                              	\
			(@if exist $(strip $(TARGDIR))\$(NEWTARGNAME).bin (del $(strip $(TARGDIR))\$(NEWTARGNAME).bin)) &  	\
		(@if exist $(strip $(TARGDIR))\$(TARGNAME).elf (del $(strip $(TARGDIR))\$(TARGNAME).elf)) &      	\
		(@if exist $(strip $(TARGDIR))\$(TARGNAME).lis (del $(strip $(TARGDIR))\$(TARGNAME).lis)) &      	\
		(@if exist $(strip $(TARGDIR))\$(TARGNAME).sym (del $(strip $(TARGDIR))\$(TARGNAME).sym)) &      	\
		(@if exist $(strip $(TARGDIR))\$(TARGNAME).htm (del $(strip $(TARGDIR))\$(TARGNAME).htm)) &      	\
		(@if exist $(strip $(TARGDIR))\*.log (del /q $(strip $(TARGDIR))\*.log)))

	-@if not exist $(COMPLOGDIR)	\
		(md $(COMPLOGDIR))         \
	else                          \
		(for /d %%i in ($(CLEAN_MODS)) do \
			(@if exist $(strip $(COMPLOGDIR))\%%i.log (del /q $(strip $(COMPLOGDIR))\%%i.log)) \
		)

	@if not exist $(PROJDIR)   \
		(md $(PROJDIR))

	@if not exist $(OBJSDIR)   \
		(md $(OBJSDIR))

   # -----------------------------
   # Check component directories
   # -----------------------------
	-@for /d %%i in ($(CLEAN_MODS)) do 			\
		(@if not exist $(strip $(OBJSDIR))\%%i	\
			(md $(strip $(OBJSDIR))\%%i)			\
		else												\
			(@echo Cleaning object files under %%i) & \
			(@if exist $(strip $(OBJSDIR))\%%i\*.obj (del $(strip $(OBJSDIR))\%%i\*.obj)) & \
			(@if exist $(strip $(OBJSDIR))\%%i\%%i.lib_bak (del $(strip $(OBJSDIR))\%%i\%%i.lib_bak)))


	-@if not exist $(strip $(COMPLIBDIR))	\
		(md $(COMPLIBDIR)) 						\
	else												\
		(@echo Cleaning library files $(CLEAN_MODS) under $(COMPLIBDIR)) & \
		(for /d %%i in ($(CLEAN_MODS)) do \
			(@if exist $(strip $(COMPLIBDIR))\%%i.lib (del /q $(strip $(COMPLIBDIR))\%%i.lib)) \
		) & \
		(@echo Cleaning code gen files) & \
		(if /I $(NEED_CLEAN_CGENLST) EQU TRUE \
			(@if exist $(CODE_GEN_LST)						         \
				(copy $(CODE_GEN_LST) make\~codegenlis.tmp) &   \
				(@for /f %%j in ($(CODE_GEN_LST)) do 	         \
					(@if exist %%j (del %%j))                                    \
				) &							 	         \
				(@if exist $(CODE_GEN_LST) (del $(CODE_GEN_LST))) \
			) \
		)

   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
##############################################################
# Resource generate
##############################################################
resgen_public:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'resgen START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
ifeq ($(strip $(call Upper,$(LEVEL))),VENDOR)
	@if exist $(MMIDIR)\VendorApp\DevResource\ResGenerator.bat \
		($(MMIDIR)\VendorApp\DevResource\ResGenerator.bat -t)
else
	@if exist $(MMIDIR)\customer \
		(@if /I $(RUN_RESGEN) EQU TRUE \
			(echo CUSTOM_OPTION = $(foreach def,$(BOARD_VER) $(PLATFORM) $(LCD_MODULE) $(EXT_CAM_MODULE) $(CMOS_SENSOR),-D "$(def)") \> $(MMIDIR)\customer\resGenerator\custom_option.txt) \
		)

	@tools\strcmpex.exe TRUE TRUE e make\~cus_opt.tmp $(foreach def,$(sort $(COM_DEFS)),-D \"$(def)\")
	@if exist $(MMIDIR)\customer \
		(@if /I $(RUN_RESGEN) EQU TRUE \
			(type make\~cus_opt.tmp >> $(MMIDIR)\customer\resGenerator\custom_option.txt) \
		)

	@tools\strcmpex.exe TRUE TRUE e make\~tgt_opt.tmp $(foreach def,$(COM_DEFS) $(LCD_MODULE),/D \"$(def)\")
	@if exist $(MMIDIR)\customer \
		(@if /I $(RUN_RESGEN) EQU TRUE \
			(@if exist $(MMIDIR)\mmi\TargetOption.txt del $(MMIDIR)\mmi\TargetOption.txt) & \
			(copy /Y make\~tgt_opt.tmp $(MMIDIR)\MMI\TargetOption.txt) \
		)

	@tools\strcmpex.exe TRUE TRUE e make\~inc.tmp $(foreach inc,$(COMMINCDIRS),$(inc))
	@if exist $(MMIDIR)\customer \
		(@if /I $(RUN_RESGEN) EQU TRUE \
			(type make\~inc.tmp > $(MMIDIR)\customer\resGenerator\custom_include.tmp) \
		)

ifeq ($(strip $(NEED_COPY_MMIFEATURE)),CUSTOMER_MMI)
	@if exist $(MMIDIR)\customer \
		(@if /I $(RUN_RESGEN) EQU TRUE \
			(@perl -e "open F,'<$(MMIDIR)\customer\resGenerator\custom_include.tmp';my $$i=join('',<F>);close F;$$i =~s/\s+/ /gs;$$i =~ s/(\S+)/-I \"..\\..\\..\\$$1\"/gs;print \"CUSTOM_INC = $$i\";" > $(MMIDIR)\customer\resGenerator\custom_include.txt) & \
			(@perl -e "open F,'<$(MMIDIR)\customer\resGenerator\custom_include.tmp';my $$i=join('',<F>);close F;$$i =~s/\s+/ /gs;$$i =~ s/(\S+)/\/I \"..\\..\\$$1\"\n/gs;print \"$$i\";" > $(MMIDIR)\MMI\GlobalTargetPathDef) & \
			(@if exist $(MMIDIR)\customer\replace_project_name.pl \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator_HW.tmp XXX $(patsubst %_MMI,%,$(MMI_VERSION)) $(MMIDIR)\customer\ResGenerator_HW.bat) & \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator.tmp XXX $(patsubst %_MMI,%,$(MMI_VERSION)) $(MMIDIR)\customer\ResGenerator.bat) & \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\remakeResource.tmp XXX $(patsubst %_MMI,%,$(MMI_VERSION)) $(MMIDIR)\customer\remakeResource.bat) & \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\UpdateSkin.tmp XXX $(patsubst %_MMI,%,$(MMI_VERSION)) $(MMIDIR)\customer\UpdateSkin.bat) & \
					(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator_HW.bat YYY $(patsubst %_MMI,%,$(CUSTOMER)) $(MMIDIR)\customer\ResGenerator_HW.bat) & \
					(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator.bat YYY $(patsubst %_MMI,%,$(CUSTOMER)) $(MMIDIR)\customer\ResGenerator.bat) & \
					(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\remakeResource.bat YYY $(patsubst %_MMI,%,$(CUSTOMER)) $(MMIDIR)\customer\remakeResource.bat) & \
					(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\UpdateSkin.bat YYY $(patsubst %_MMI,%,$(CUSTOMER)) $(MMIDIR)\customer\UpdateSkin.bat) \
			) \
		)
else
	@if exist $(MMIDIR)\customer \
		(@if /I $(RUN_RESGEN) EQU TRUE \
			(@perl -e "open F,'<$(MMIDIR)\customer\resGenerator\custom_include.tmp';my $$i=join('',<F>);close F;$$i =~s/\s+/ /gs;$$i =~ s/(\S+)/-I \"..\\..\\..\\$$1\"/gs;print \"CUSTOM_INC = $$i\";" > $(MMIDIR)\customer\resGenerator\custom_include.txt) & \
			(@perl -e "open F,'<$(MMIDIR)\customer\resGenerator\custom_include.tmp';my $$i=join('',<F>);close F;$$i =~s/\s+/ /gs;$$i =~ s/(\S+)/\/I \"..\\..\\$$1\"\n/gs;print \"$$i\";" > $(MMIDIR)\MMI\GlobalTargetPathDef) & \
			(@if exist $(MMIDIR)\customer\replace_project_name.pl \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator_HW.tmp XXX $(patsubst %_MMI,%,$(MMI_VERSION)) $(MMIDIR)\customer\ResGenerator_HW.bat) & \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator.tmp XXX $(patsubst %_MMI,%,$(MMI_VERSION)) $(MMIDIR)\customer\ResGenerator.bat) & \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\remakeResource.tmp XXX $(patsubst %_MMI,%,$(MMI_VERSION)) $(MMIDIR)\customer\remakeResource.bat) & \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\UpdateSkin.tmp XXX $(patsubst %_MMI,%,$(MMI_VERSION)) $(MMIDIR)\customer\UpdateSkin.bat) & \
					(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator_HW.bat YYY $(patsubst %_MMI,%,$(MMI_VERSION)) $(MMIDIR)\customer\ResGenerator_HW.bat) & \
					(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator.bat YYY $(patsubst %_MMI,%,$(MMI_VERSION)) $(MMIDIR)\customer\ResGenerator.bat) & \
					(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\remakeResource.bat YYY $(patsubst %_MMI,%,$(MMI_VERSION)) $(MMIDIR)\customer\remakeResource.bat) & \
					(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\UpdateSkin.bat YYY $(patsubst %_MMI,%,$(MMI_VERSION)) $(MMIDIR)\customer\UpdateSkin.bat) \
			) \
		)
endif
endif

	@perl -e "print 'resgen END TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

new_resgen: resgen_public
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifneq ($(strip $(call Upper,$(LEVEL))),VENDOR)

  ifeq ($(strip $(RUN_RESGEN)),TRUE)
	@if exist $(MMIDIR)\customer if exist $(MMIDIR)\customer\replace_project_name.pl (\
		(perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator_HW.bat SSS $(call Upper,$(strip $(OPTR_SPEC))) $(MMIDIR)\customer\ResGenerator_HW.bat) & \
		(perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator_HW.bat MMM $(call Upper,$(strip $(MAIN_LCD_SIZE))) $(MMIDIR)\customer\ResGenerator_HW.bat) & \
		(perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator_HW.bat PPP $(strip $(OPTR_PATH)) $(MMIDIR)\customer\ResGenerator_HW.bat) & \
		(perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator_HW.bat QQQ $(call Upper,$(strip $(TOUCH_PANEL_SUPPORT))) $(MMIDIR)\customer\ResGenerator_HW.bat) \
	)
	@if exist $(MMIDIR)\customer if exist $(MMIDIR)\customer\replace_project_name.pl (\
		(perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator_XML.bat SSS $(call Upper,$(strip $(OPTR_SPEC))) $(MMIDIR)\customer\ResGenerator_XML.bat) & \
		(perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator_XML.bat MMM $(call Upper,$(strip $(MAIN_LCD_SIZE))) $(MMIDIR)\customer\ResGenerator_XML.bat) & \
		(perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator_XML.bat PPP $(strip $(OPTR_PATH)) $(MMIDIR)\customer\ResGenerator_XML.bat) & \
		(perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator_XML.bat QQQ $(call Upper,$(strip $(TOUCH_PANEL_SUPPORT))) $(MMIDIR)\customer\ResGenerator_XML.bat) \
	)
	@if exist $(MMIDIR)\customer if exist $(MMIDIR)\customer\replace_project_name.pl (\
		(perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator.bat SSS $(call Upper,$(strip $(OPTR_SPEC))) $(MMIDIR)\customer\ResGenerator.bat) & \
		(perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator.bat MMM $(call Upper,$(strip $(MAIN_LCD_SIZE))) $(MMIDIR)\customer\ResGenerator.bat) & \
		(perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator.bat PPP $(strip $(OPTR_PATH)) $(MMIDIR)\customer\ResGenerator.bat) & \
		(perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator.bat QQQ $(call Upper,$(strip $(TOUCH_PANEL_SUPPORT))) $(MMIDIR)\customer\ResGenerator.bat) \
	)
	@if exist $(MMIDIR)\customer if exist $(MMIDIR)\customer\replace_project_name.pl (\
		(perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\remakeResource.bat SSS $(call Upper,$(strip $(OPTR_SPEC))) $(MMIDIR)\customer\remakeResource.bat) & \
		(perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\remakeResource.bat MMM $(call Upper,$(strip $(MAIN_LCD_SIZE))) $(MMIDIR)\customer\remakeResource.bat) & \
		(perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\remakeResource.bat PPP $(strip $(OPTR_PATH)) $(MMIDIR)\customer\remakeResource.bat) & \
		(perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\remakeResource.bat QQQ $(call Upper,$(strip $(TOUCH_PANEL_SUPPORT))) $(MMIDIR)\customer\remakeResource.bat) \
	)
	@if exist $(MMIDIR)\customer (\
		(del $(MMIDIR)\customer\resGenerator\custom_include.tmp) & \
		($(MMIDIR)\customer\ResGenerator_HW.bat $(MMI_VERSION) $(CUSTOMER)) \
	)
  endif

# copy only for Neptune162
	if /I "$(strip $(CUSTOMER))" EQU "NEPTUNE162" \
		(if exist $(FIXPATH)\$(MMIDIR)\customer\CustResource\$(strip $(CUSTOMER))_MMI\resource_shortcuts.c \
		   (copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(CUSTOMER))_MMI\resource_shortcuts.c $(FIXPATH)\$(MMIDIR)\Customer\CustResource\resource_shortcuts.c) \
		)

	@if exist $(MMIDIR)\customer\resGenerator\custom_option.txt \
		(@if exist $(MMIDIR)\VendorApp\resGenerator \
			(copy /z $(MMIDIR)\customer\resGenerator\custom_option.txt $(MMIDIR)\VendorApp\resGenerator\custom_option.txt) & \
			(copy /z $(MMIDIR)\customer\resGenerator\custom_include.txt $(MMIDIR)\VendorApp\resGenerator\custom_include.txt) \
		)
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

remake_resgen: resgen_public
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifneq ($(strip $(call Upper,$(LEVEL))),VENDOR)

  ifeq ($(strip $(RUN_RESGEN)),TRUE)
	@if exist $(MMIDIR)\customer if exist $(MMIDIR)\customer\replace_project_name.pl (\
		(perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator_XML.tmp XXX $(patsubst %_MMI,%,$(MMI_VERSION)) $(MMIDIR)\customer\ResGenerator_XML.bat) & \
		(perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator_XML.bat YYY $(patsubst %_MMI,%,$(CUSTOMER)) $(MMIDIR)\customer\ResGenerator_XML.bat) \
	)
	@if exist $(MMIDIR)\customer if exist $(MMIDIR)\customer\replace_project_name.pl (\
		(perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator_HW.bat SSS $(call Upper,$(strip $(OPTR_SPEC))) $(MMIDIR)\customer\ResGenerator_HW.bat) & \
		(perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator_HW.bat MMM $(call Upper,$(strip $(MAIN_LCD_SIZE))) $(MMIDIR)\customer\ResGenerator_HW.bat) & \
		(perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator_HW.bat PPP $(strip $(OPTR_PATH)) $(MMIDIR)\customer\ResGenerator_HW.bat) & \
		(perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator_HW.bat QQQ $(call Upper,$(strip $(TOUCH_PANEL_SUPPORT))) $(MMIDIR)\customer\ResGenerator_HW.bat) \
	)
	@if exist $(MMIDIR)\customer if exist $(MMIDIR)\customer\replace_project_name.pl (\
		(perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator_XML.bat SSS $(call Upper,$(strip $(OPTR_SPEC))) $(MMIDIR)\customer\ResGenerator_XML.bat) & \
		(perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator_XML.bat MMM $(call Upper,$(strip $(MAIN_LCD_SIZE))) $(MMIDIR)\customer\ResGenerator_XML.bat) & \
		(perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator_XML.bat PPP $(strip $(OPTR_PATH)) $(MMIDIR)\customer\ResGenerator_XML.bat) & \
		(perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator_XML.bat QQQ $(call Upper,$(strip $(TOUCH_PANEL_SUPPORT))) $(MMIDIR)\customer\ResGenerator_XML.bat) \
	)
	@if exist $(MMIDIR)\customer if exist $(MMIDIR)\customer\replace_project_name.pl (\
		(perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator.bat SSS $(call Upper,$(strip $(OPTR_SPEC))) $(MMIDIR)\customer\ResGenerator.bat) & \
		(perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator.bat MMM $(call Upper,$(strip $(MAIN_LCD_SIZE))) $(MMIDIR)\customer\ResGenerator.bat) & \
		(perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator.bat PPP $(strip $(OPTR_PATH)) $(MMIDIR)\customer\ResGenerator.bat) & \
		(perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator.bat QQQ $(call Upper,$(strip $(TOUCH_PANEL_SUPPORT))) $(MMIDIR)\customer\ResGenerator.bat) \
	)
	@if exist $(MMIDIR)\customer if exist $(MMIDIR)\customer\replace_project_name.pl (\
		(perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\remakeResource.bat SSS $(call Upper,$(strip $(OPTR_SPEC))) $(MMIDIR)\customer\remakeResource.bat) & \
		(perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\remakeResource.bat MMM $(call Upper,$(strip $(MAIN_LCD_SIZE))) $(MMIDIR)\customer\remakeResource.bat) & \
		(perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\remakeResource.bat PPP $(strip $(OPTR_PATH)) $(MMIDIR)\customer\remakeResource.bat) & \
		(perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\remakeResource.bat QQQ $(call Upper,$(strip $(TOUCH_PANEL_SUPPORT))) $(MMIDIR)\customer\remakeResource.bat) \
	)
	@if exist $(MMIDIR)\customer (\
		(del $(MMIDIR)\customer\resGenerator\custom_include.tmp) & \
		($(MMIDIR)\customer\ResGenerator_XML.bat $(MMI_VERSION) $(CUSTOMER) R 0) & \
		($(MMIDIR)\customer\ResGenerator.bat $(MMI_VERSION) $(CUSTOMER)) \
	)
  endif

   # copy only for Neptune162
	if /I "$(strip $(CUSTOMER))" EQU "NEPTUNE162" \
		(if exist $(FIXPATH)\$(MMIDIR)\customer\CustResource\$(strip $(CUSTOMER))_MMI\resource_shortcuts.c \
		   (copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(CUSTOMER))_MMI\resource_shortcuts.c $(FIXPATH)\$(MMIDIR)\Customer\CustResource\resource_shortcuts.c) \
		)

	@if exist $(MMIDIR)\customer\resGenerator\custom_option.txt \
		(@if exist $(MMIDIR)\VendorApp\resGenerator \
			(copy /z $(MMIDIR)\customer\resGenerator\custom_option.txt $(MMIDIR)\VendorApp\resGenerator\custom_option.txt) & \
			(copy /z $(MMIDIR)\customer\resGenerator\custom_include.txt $(MMIDIR)\VendorApp\resGenerator\custom_include.txt) \
		)
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

##############################################################
gen_infolog:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@if exist $(strip $(TARGDIR))\build.log \
		(@perl -e "print 'gen_infolog START TIME='";>>$(strip $(TARGDIR))\build.log & \
		@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log)

	@if not exist $(COMPLOGDIR)	\
		(md $(COMPLOGDIR))

	@tools\strcmpex.exe def def e make\~def.tmp $(foreach def,$(sort $(COM_DEFS)),$(def))
	@perl tools\lnitem.pl make\~def.tmp

	@if exist make\~inc.tmp \
		(del /f /q make\~inc.tmp)

	@tools\strcmpex.exe inc inc e make\~inc.tmp $(foreach inc,$(COMMINCDIRS),$(inc))
	@perl tools\lnitem.pl make\~inc.tmp

	@if exist $(COMPLOGDIR)                    	\
		(@echo [ COMMON OPTION ]> $(INFOLOG)) & \
		(type make\~def.tmp >> $(INFOLOG))

	@if exist $(COMPLOGDIR) \
		(@echo [ COMMON INCLUDE PATH ] >> $(INFOLOG)) & \
		(type make\~inc.tmp >> $(INFOLOG))

	@if exist $(strip $(TARGDIR))\build.log \
		(@perl -e "print 'gen_infolog END TIME='";>>$(strip $(TARGDIR))\build.log & \
		@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log)
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
##############################################################
gen_infomakelog:	
  # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl -e "print 'gen_infomakelog START TIME='";>>$(strip $(TARGDIR))\build.log
	@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log
	
	@tools\strcmpex.exe def def e $(INFOMAKELOG) COM_DEFS = $(call sort, $(foreach def,$(COM_DEFS),$(def)))
	@tools\strcmpex.exe def def e make\~remove.tmp COMMINCDIRS = $(call sort, $(foreach inc,$(COMMINCDIRS),$(inc)))
	@type make\~remove.tmp >> $(INFOMAKELOG)
	@perl tools\echoLongString.pl $(INFOMAKELOG) COMP_TRACE_DEFS $(COMP_TRACE_DEFS)
	@echo COMPLIST = $(call sort, $(foreach def,$(COMPLIST),$(def))) >> $(INFOMAKELOG)
	@perl tools\echoLongString.pl $(INFOMAKELOG) COMPOBJS $(COMPOBJS)
	@echo CUS_REL_BASE_COMP = $(call sort, $(foreach def,$(CUS_REL_BASE_COMP),$(def))) >> $(INFOMAKELOG)
	@echo CUS_REL_SRC_COMP = $(call sort, $(foreach def,$(CUS_REL_SRC_COMP),$(def))) >> $(INFOMAKELOG)
	@echo CUS_REL_PAR_SRC_COMP = $(call sort, $(foreach def,$(CUS_REL_PAR_SRC_COMP),$(def))) >> $(INFOMAKELOG)
ifneq ($(words $(CUS_REL_PAR_SRC_COMP)),0)
	@tools\strcmpex.exe def def e make\~remove.tmp ALL_CUS_REL_PAR_SRC_COMP = $(foreach comp,$(call Upper,$(CUS_REL_PAR_SRC_COMP)),$(CUS_REL_$(comp)_PAR_SRC_LIST))
	@type make\~remove.tmp >> $(INFOMAKELOG)
endif
	@if exist make\~remove.tmp del make\~remove.tmp
	@echo CUS_REL_MTK_COMP = $(call sort, $(foreach def,$(CUS_REL_MTK_COMP),$(def))) >> $(INFOMAKELOG)
	@echo CUS_REL_OBJ_LIST = $(call sort, $(foreach def,$(CUS_REL_OBJ_LIST),$(def))) >> $(INFOMAKELOG)
	@echo LEVEL = $(strip $(LEVEL)) >> $(INFOMAKELOG)
	@echo CUSTOM_RELEASE = $(strip $(CUSTOM_RELEASE)) >> $(INFOMAKELOG)
	@echo VERNO = $(strip $(VERNO)) >> $(INFOMAKELOG)
	@echo MTK_SUBSIDIARY = $(strip $(MTK_SUBSIDIARY)) >> $(INFOMAKELOG)
	@echo HEADER_TEMP = $(strip $(HEADER_TEMP)) >> $(INFOMAKELOG)
	@echo JBLENDIA_LIB = $(strip $(JBLENDIA_LIB)) >> $(INFOMAKELOG)
	@echo DEBUG_MODULES = $(strip $(DEBUG_MODULES))>> $(INFOMAKELOG)
	@echo NON_DEBUG_MODULES = $(strip $(NON_DEBUG_MODULES))>> $(INFOMAKELOG)
ifeq ($(strip $(MODIS_CONFIG)),TRUE)
	@echo MODIS_EN_LIBS = $(strip $(MODIS_EN_LIBS)) >> $(INFOMAKELOG)
	@echo MODIS_DIS_LIBS = $(strip $(MODIS_DIS_LIBS)) >> $(INFOMAKELOG)
	@echo MODIS_MTK_LIBS = $(strip $(MODIS_MTK_LIBS)) >> $(INFOMAKELOG)
endif

	@if exist $(strip $(TARGDIR))\build.log \
		(@perl -e "print 'gen_infomakelog END TIME='";>>$(strip $(TARGDIR))\build.log & \
		@perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log)
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
##############################################################
gendoc:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@if not exist $(COMPLOGDIR)	\
		(md $(COMPLOGDIR))

	@if exist tools\gen_doc.pl\
	   (perl tools\gen_doc.pl $(GENDOC_MODS))> $(strip $(COMPLOGDIR))\gendoc_dom.log
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

ifeq ($(strip $(REMOVE_DEBUG_INFO)),TRUE)
done: rmdebugobj
else
  ifeq ($(strip $(ACTION)),new)
    ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
done: gen_modlibtbl
    else
done:
    endif
  else
done:
  endif
endif

# -----------------------------
# Clean temporary files in make directory
# -----------------------------
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifneq ($(strip $(call Upper,$(PROJECT))),L1S)
ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
ifneq ($(strip $(call Upper,$(PROJECT))),MEUT)
ifeq ($(strip $(NAND_FLASH_BOOTING)),NONE)
ifneq ($(strip $(FEATURE_OVERLOAD)),TRUE)
	@echo check system drive ....
	@if exist $(strip $(COMPLOGDIR))\ckSysDrv.log \
		(@perl -e "open F,'<$(strip $(COMPLOGDIR))\ckSysDrv.log';my $$backup=$$/;undef $$/;my $$reading=<F>;close F;if($$reading =~ /Shortage/i){print 'cksysdrv has errors. Delete the binary file.'.\"\n\";system('del $(strip $(TARGDIR))\$(strip $(BIN_FILE))');exit 1;};")
endif
endif
endif
endif
endif
ifeq ($(strip $(NEED_BUILD_BOOTLOADER)),TRUE)
	@if not exist $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE)) \
		(echo $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE)) does not exist. Please check it. & \
		(if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM \
		(rd /S /Q $(strip $(TARGDIR))\$(strip $(BIN_FILE)))) & \
		(if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE)) \
		(del /Q /F $(strip $(TARGDIR))\$(strip $(BIN_FILE)))) & \
		exit 1)
endif
ifdef FOTA_ENABLE
  ifneq ($(strip $(FOTA_ENABLE)),NONE)
	@if not exist $(strip $(TARGDIR))\$(strip $(FOTA_BIN_FILE)) \
		(echo $(strip $(TARGDIR))\$(strip $(FOTA_BIN_FILE)) does not exist. Please check it. & \
		(if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM \
		(rd /S /Q $(strip $(TARGDIR))\$(strip $(BIN_FILE)))) & \
		(if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE)) \
		(del /Q /F $(strip $(TARGDIR))\$(strip $(BIN_FILE)))) & \
		exit 1)
  endif
endif
ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
	@if exist $(strip $(TARGDIR))\~$(strip $(BIN_FILE)) \
		del /Q /F $(strip $(TARGDIR))\~$(strip $(BIN_FILE))
	@echo Check if any error happened during the build process .....
	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE)) \
		@perl tools\parse_comp_err.pl $(strip $(CUSTOMER)) TRUE
	@if exist $(strip $(FIXPATH))\comp_err.txt \
		if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE)) \
			(@perl -e "open F,'<$(strip $(FIXPATH))\comp_err.txt';my $$backup=$$/;undef $$/;my $$reading=<F>;close F;if($$reading =~ /might be failed/i){print 'Some error happened during the build process. Delete the binary file.'.\"\n\";system('move /Y $(strip $(TARGDIR))\$(strip $(BIN_FILE)) $(strip $(TARGDIR))\~$(strip $(BIN_FILE))');exit 1;};")
endif

# -----------------------------
# remove dep and via folders under build folder
# -----------------------------
	@if exist $(strip $(TARGDIR))\dep (rd /S /Q $(strip $(TARGDIR))\dep)
	@if exist $(strip $(TARGDIR))\via (rd /S /Q $(strip $(TARGDIR))\via)

	@echo Cleaning make\~*.tmp files ...
	@if exist make\~*.tmp \
		del make\~*.tmp
	@if exist $(strip $(HEADER_TEMP)) (rmdir /S /Q $(strip $(HEADER_TEMP)))		
	@echo Done.
	@perl tools\time.pl -n
	@rar.bat
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

ckmake:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@if exist $(strip $(TARGDIR))\build.log \
		(perl -e "print 'ckmake START TIME='";>>$(strip $(TARGDIR))\build.log & \
		perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log)
	perl tools\chk_verno.pl $(VERNO)

ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
 ifeq ($(strip $(DEMO_PROJECT)),TRUE)
  ifneq ($(strip $(VENDOR)),NONE)
		perl tools\chk_env.pl make $(CUSTOMER)_$(PROJECT).mak -customer
  else
		perl tools\chk_env.pl make $(CUSTOMER)_$(PROJECT).mak -internal
  endif
 else
	perl tools\chk_env.pl make $(CUSTOMER)_$(PROJECT).mak -customer
 endif
else
	perl tools\chk_env.pl make $(CUSTOMER)_$(PROJECT).mak -internal
endif

ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
	@if exist tools\GLBOptionSwtichRef\$(subst make\,,$(strip $(THE_MF))) \
		(@perl tools\SpecialDepChk.pl $(strip $(THE_MF)) tools\GLBOptionSwtichRef\$(subst make\,,$(strip $(THE_MF))) tools\GLBOptionSwtichRef\ChkSpecialFeatures.lis) \
	else \
		(@echo warning: tools\GLBOptionSwtichRef\$(subst make\,,$(strip $(THE_MF))) does NOT exist, skip off special dependency check!!!)
endif
	@echo makefile check is done

	@if exist $(strip $(TARGDIR))\build.log \
		(perl -e "print 'ckmake END TIME='";>>$(strip $(TARGDIR))\build.log & \
		perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log)
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

ck3rdptylic:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@if exist $(strip $(TARGDIR))\build.log \
		(perl -e "print 'ck3rdptylic START TIME='";>>$(strip $(TARGDIR))\build.log & \
		perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log)

ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
  ifeq ($(strip $(PRODUCTION_RELEASE)),TRUE)
		@if exist tools\Feat2Mod.ini \
			(@perl tools\3rdPartiesLicChk.pl $(strip $(THE_MF)) "" tools\Feat2Mod.ini "$(strip $(CUS_REL_SRC_COMP))" "$(strip $(CUS_REL_PAR_SRC_COMP))" "$(strip $(CUS_REL_MTK_COMP))") \
		else \
			(@echo warning:  tools\Feat2Mod.ini does NOT exist, skip 3rd party feature's srouce release level license check!!!) & \
			(@perl tools\3rdPartiesLicChk.pl $(strip $(THE_MF)) "")
  else
		@echo Skip 3rd party feature license check for internal demo projects!!!
  endif
else
	@echo Skip 3rd party feature license check for custom release projects!!!
endif

	@if exist $(strip $(TARGDIR))\build.log \
		(perl -e "print 'ck3rdptylic END TIME='";>>$(strip $(TARGDIR))\build.log & \
		perl tools\time.pl -n>>$(strip $(TARGDIR))\build.log)

   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

copylintlog:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifeq ($(strip $(LINT)),TRUE)      
	@copy $(COMPLINTLOGDIR)\*.log mtk_tools\lint_cfg
	@if exist mtk_tools\lint_cfg\*_build.log del /F /Q  mtk_tools\lint_cfg\*_build.log
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

genlintstatlog:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifeq ($(strip $(LINT)),TRUE)      
	@$(foreach alintlog,$(LINTLOGFILE),$(shell  cd mtk_tools\lint_cfg & perl lint_stats_by_team.pl  $(alintlog)  & cd ..\.. ))
endif
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

## clean_codegen_intermedia_file
cci clean_codegen : cleancodegen 
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@echo clean codegen intermedia file
	-@if exist make\~inc.tmp del make\~inc.tmp
	-@if exist make\~def.tmp del make\~def.tmp
	-@if exist make\~inc_def.tmp del make\~inc_def.tmp
	-@if exist $(strip $(TST_DB))\unionTag\unionTag_parse.txt del $(strip $(TST_DB))\unionTag\unionTag_parse.txt
	-@if exist $(strip $(L1VAL_DB_PARSE_DIR))\l1v_db.l1v del $(strip $(L1VAL_DB_PARSE_DIR))\l1v_db.l1v
	-@if exist $(strip $(TST_DB))\msglog_db\pri.db del $(strip $(TST_DB))\msglog_db\pri.db
	-@if exist $(strip $(TST_DB))\msglog_db\custom_pri.db del $(strip $(TST_DB))\msglog_db\custom_pri.db
	-@if exist $(strip $(TST_DB))\msglog_db\app_pri.db del $(strip $(TST_DB))\msglog_db\app_pri.db 
	-@if exist $(strip $(TST_DB))\pstrace_db\*.ptr del $(strip $(TST_DB))\pstrace_db\*.ptr
	-@if exist $(strip $(TST_DB))\msglog_db\custom_pri.db del $(strip $(TST_DB))\msglog_db\custom_pri.db
	-@if exist $(strip $(TST_DB))\msglog_db\app_pri.db del $(strip $(TST_DB))\msglog_db\app_pri.db
	-@if exist $(MMI_SCR_ID_DB) del $(MMI_SCR_ID_DB)
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
## check_repeated_include_path
#################### begin to check repeated common include path ############
crip : 
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@perl tools\check_repeated.pl $(COMMINCDIRS)
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))	
###################### end ##############


ckmemcons:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@if exist tools\GetMemCons.pl \
	   (perl tools\GetMemCons.pl $(strip $(TARGDIR))\$(strip $(LIS_FILE)) tools\prebuild_backup\$(basename $(strip $(LIS_FILE)))_bak.lis $(strip $(COMPLOGDIR))\mem_cons.log $(strip $(COMPILER)))
	@echo Check memory consumption done!
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

backup : getoptions
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@if not exist tools\prebuild_backup \
		md tools\prebuild_backup
	@if exist $(strip $(TARGDIR))\$(strip $(LIS_FILE)) \
	   (copy /y $(strip $(TARGDIR))\$(strip $(LIS_FILE)) tools\prebuild_backup\$(basename $(strip $(LIS_FILE)))_bak.lis > nul) 
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

getoptions:
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" \
		(@perl -e "print 'CFLAGS,$(CFLAGS)' . \"\n\"";>>$(MBIS_BUILD_INFO_LOG) &\
		@perl -e "print 'CPLUSFLAGS,$(CPLUSFLAGS)' . \"\n\"";>>$(MBIS_BUILD_INFO_LOG)  &\
		@perl -e "print 'LIBOPT,$(LIBOPT)' . \"\n\"";>>$(MBIS_BUILD_INFO_LOG)  &\
		@perl -e "print 'LNKOPT,$(LNKOPT)' . \"\n\"";>>$(MBIS_BUILD_INFO_LOG))

	@tools\strcmpex.exe def def e make\~mbis_def.tmp $(foreach def,$(COM_DEFS),$(def))

	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" \
		(@perl -e "print 'COM_DEFS,'";>>$(MBIS_BUILD_INFO_LOG) &\
		@type make\~mbis_def.tmp >>$(MBIS_BUILD_INFO_LOG))

	@if exist make\~mbis_def.tmp del /Q /F make\~mbis_def.tmp

   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

elfpatch:
	@echo $(strip $(TARGDIR))\$(IMG_FILE)!!
	@if exist $(strip $(TARGDIR))\$(IMG_FILE) \
	(@echo elfpatcher start....) &\
	(@tools\elfpatcher.exe $(strip $(TARGDIR))\$(IMG_FILE)) &\
	(@echo elfpatcher done!) \
	else \
	(@echo $(strip $(TARGDIR))\$(IMG_FILE) is not existed!Please build firstly!)

rmdebugobj:
  # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@echo Start stripping debug information for objects...
	@perl mtk_tools\strip_debug.pl $(OBJSDIR)
   # mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

gencompbld:
   # -----------------------------
   # Write the required script variables to config file
   # -----------------------------
	@echo FIXPATH 	= $(strip $(FIXPATH))>  make\~compbld.tmp
	@echo OBJSDIR  = $(strip $(OBJSDIR))>> make\~compbld.tmp
	@echo RULESDIR	= $(strip $(RULESDIR))>> make\~compbld.tmp
	@echo TARGDIR 	= $(strip $(TARGDIR))>> make\~compbld.tmp
	@echo PROJDIR 	= $(strip $(PROJDIR))>> make\~compbld.tmp
   # mbis time probe for enable msib time probe in comp.mak
ifneq ($(strip $(XGC)),TRUE)
	@echo MBIS_EN_OBJ_LOG 	= $(strip $(MBIS_EN_OBJ_LOG))>>  make\~compbld.tmp
else
	@echo MBIS_EN_OBJ_LOG 	= FALSE>>  make\~compbld.tmp
endif

ifeq ($(strip $(LINT)),TRUE)	
	@echo COMPLINTLOGDIR	= $(strip $(COMPLINTLOGDIR))>> make\~compbld.tmp
endif
	@echo PLATFORM = $(strip $(call Upper,$(PLATFORM)))>> make\~compbld.tmp
	@echo BOARD_VER = $(strip $(call Upper,$(BOARD_VER)))>> make\~compbld.tmp
	@echo CHIP_VER = $(strip $(call Upper,$(CHIP_VER)))>> make\~compbld.tmp
	@echo MCU_DCM = $(strip $(call Upper,$(MCU_DCM)))>> make\~compbld.tmp
	@echo DEBUG_SAVE_CUR_THREAD	= $(strip $(DEBUG_SAVE_CUR_THREAD))>> make\~compbld.tmp
	@echo PRODUCTION_RELEASE   	= $(strip $(PRODUCTION_RELEASE))>> make\~compbld.tmp
	@echo APCSINT 	= $(strip $(APCSINT))>> make\~compbld.tmp
	@echo ASM = $(strip $(ASM))>> make\~compbld.tmp
	@echo LIB     	= $(strip $(LIB))>> make\~compbld.tmp
	@echo CC	    	= $(strip $(CC))>> make\~compbld.tmp
	@echo CC32	 	= $(strip $(CC32))>> make\~compbld.tmp
	@echo CPPC	    	= $(strip $(CPPC))>> make\~compbld.tmp
	@echo CPPC32	 	= $(strip $(CPPC32))>> make\~compbld.tmp
	@echo CFLAGS 	= $(strip $(CFLAGS))>> make\~compbld.tmp
	@echo CPLUSFLAGS = $(strip $(CPLUSFLAGS))>> make\~compbld.tmp
	@echo VIA = $(strip $(VIA))>> make\~compbld.tmp
	@echo SWDBG_SUPPORT = $(strip $(SWDBG_SUPPORT))>> make\~compbld.tmp
	@echo SW_BINDING_SUPPORT    = $(strip $(SW_BINDING_SUPPORT))>> make\~compbld.tmp
	@echo RTOS    = $(strip $(RTOS))>> make\~compbld.tmp
	@echo CUS_MTK_LIB    = $(strip $(CUS_MTK_LIB))>> make\~compbld.tmp
	@echo FOTA_ENABLE    = $(strip $(FOTA_ENABLE))>> make\~compbld.tmp
	@echo LCD_MODULE    = $(strip $(LCD_MODULE))>> make\~compbld.tmp
	@echo JPG_DECODE = $(strip $(JPG_DECODE))>> make\~compbld.tmp
	@echo JPG_ENCODE = $(strip $(JPG_ENCODE))>> make\~compbld.tmp
	@echo CHIP_VERSION_CHECK = $(strip $(CHIP_VERSION_CHECK))>> make\~compbld.tmp
	@echo KEYPAD_DEBUG_TRACE = $(strip $(KEYPAD_DEBUG_TRACE))>> make\~compbld.tmp
	@echo NEED_BUILD_BOOTLOADER = $(strip $(NEED_BUILD_BOOTLOADER))>> make\~compbld.tmp
	@echo FLASH_TEST_SELECT = $(strip $(FLASH_TEST_SELECT))>> make\~compbld.tmp
	@echo FLAVOR = $(strip $(FLAVOR))>> make\~compbld.tmp
	@echo MMI_VERSION = $(strip $(MMI_VERSION))>> make\~compbld.tmp
	@echo ZIMAGE_SUPPORT = $(strip $(ZIMAGE_SUPPORT))>> make\~compbld.tmp

	@echo CARD_DOWNLOAD_NOT_SUPPORT_PLATFORM = $(strip $(CARD_DOWNLOAD_NOT_SUPPORT_PLATFORM))>> make\~compbld.tmp
	@echo CARD_DOWNLOAD = $(strip $(CARD_DOWNLOAD))>> make\~compbld.tmp
	@echo GADGET_SUPPORT = $(strip $(GADGET_SUPPORT))>> make\~compbld.tmp
	@echo ENABLE_PARTIAL_TRACE = $(strip $(ENABLE_PARTIAL_TRACE))>> make\~compbld.tmp
	@echo PARTIAL_TRACE_LIB = $(strip $(PARTIAL_TRACE_LIB))>> make\~compbld.tmp

ifneq ($(strip $(XGC_AND_NOT_BOOTLOADER)),TRUE)
	-@if /I "$*" EQU "BOOTLOADER" \
		((echo AFLAGS	= $(strip $(BL_AFLAGS))>> make\~compbld.tmp) & \
		(echo ACTION	= UPDATE>> make\~compbld.tmp)) \
	else \
		(echo AFLAGS	= $(strip $(AFLAGS))>> make\~compbld.tmp)

	@for /F "tokens=3" %%i in ($(strip $(FIXPATH))\custom\system\$(strip $(call Upper,$(BOARD_VER)))\custom_MemoryDevice.h) do \
	((@if /I "%%i" EQU "NOR_LPSDRAM_MCP"   \
		(@if /I "$*" EQU "BOOTLOADER" \
		((echo AFLAGS	= $(strip $(BL_AFLAGS)) -pd "_NOR_LPSDRAM_MCP_ SETL {TRUE}">> make\~compbld.tmp) & \
		(echo ACTION	= UPDATE>> make\~compbld.tmp)) \
		else \
		(echo AFLAGS	= $(strip $(AFLAGS)) -pd "_NOR_LPSDRAM_MCP_ SETL {TRUE}">> make\~compbld.tmp))))

	@for /F "tokens=3" %%i in ($(strip $(FIXPATH))\custom\system\$(strip $(call Upper,$(BOARD_VER)))\custom_MemoryDevice.h) do \
	((@if /I "%%i" EQU "LPSDRAM"   \
		(@if /I "$*" EQU "BOOTLOADER" \
		((echo AFLAGS	= $(strip $(BL_AFLAGS)) -pd "_LPSDRAM_ SETL {TRUE}">> make\~compbld.tmp) & \
		(echo ACTION	= UPDATE>> make\~compbld.tmp)) \
		else \
		(echo AFLAGS	= $(strip $(AFLAGS)) -pd "_LPSDRAM_ SETL {TRUE}">> make\~compbld.tmp))))

	@for /F "tokens=3" %%i in ($(strip $(FIXPATH))\custom\system\$(strip $(call Upper,$(BOARD_VER)))\custom_MemoryDevice.h) do \
	((@if /I "%%i" EQU "NOR_RAM_MCP"   \
		(@if /I "$*" EQU "BOOTLOADER" \
		((echo AFLAGS	= $(strip $(BL_AFLAGS)) -pd "_NOR_RAM_MCP_ SETL {TRUE}">> make\~compbld.tmp) & \
		(echo ACTION	= UPDATE>> make\~compbld.tmp)) \
		else \
		(echo AFLAGS	= $(strip $(AFLAGS)) -pd "_NOR_RAM_MCP_ SETL {TRUE}">> make\~compbld.tmp))))
else
	@echo AFLAGS = $(strip $(AFLAGS))>> make\~compbld.tmp

	@for /F "tokens=3" %%i in ($(strip $(FIXPATH))\custom\system\$(strip $(call Upper,$(BOARD_VER)))\custom_MemoryDevice.h) do \
	((@if /I "%%i" EQU "NOR_LPSDRAM_MCP"   \
		(echo AFLAGS	= $(strip $(AFLAGS)) -pd "_NOR_LPSDRAM_MCP_ SETL {TRUE}">> make\~compbld.tmp)))

	@for /F "tokens=3" %%i in ($(strip $(FIXPATH))\custom\system\$(strip $(call Upper,$(BOARD_VER)))\custom_MemoryDevice.h) do \
	((@if /I "%%i" EQU "LPSDRAM"   \
		(echo AFLAGS	= $(strip $(AFLAGS)) -pd "_LPSDRAM_ SETL {TRUE}">> make\~compbld.tmp)))

	@for /F "tokens=3" %%i in ($(strip $(FIXPATH))\custom\system\$(strip $(call Upper,$(BOARD_VER)))\custom_MemoryDevice.h) do \
	((@if /I "%%i" EQU "NOR_RAM_MCP"   \
		(echo AFLAGS	= $(strip $(AFLAGS)) -pd "_NOR_RAM_MCP_ SETL {TRUE}">> make\~compbld.tmp)))		
endif

	@echo SWDBG_SUPPORT = $(strip $(SWDBG_SUPPORT))>> make\~compbld.tmp
	@echo NAND_FLASH_BOOTING = $(strip $(NAND_FLASH_BOOTING))>> make\~compbld.tmp
	@echo SECURE_SUPPORT = $(strip $(SECURE_SUPPORT))>> make\~compbld.tmp
	@echo ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT = $(strip $(ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT))>> make\~compbld.tmp
	@echo USB_DOWNLOAD   = $(strip $(USB_DOWNLOAD))>> make\~compbld.tmp
	@echo L1_WCDMA = $(strip $(L1_WCDMA))>> make\~compbld.tmp
	@echo L1_3GSOLUTION = $(strip $(L1_3GSOLUTION))>> make\~compbld.tmp		
	@echo BM_NEW = $(strip $(BM_NEW))>> make\~compbld.tmp
	@echo SW_BINDING_SUPPORT = $(strip $(SW_BINDING_SUPPORT))>> make\~compbld.tmp
	@echo KAL_RECORD_BOOTUP_LOG = $(strip $(KAL_RECORD_BOOTUP_LOG))>> make\~compbld.tmp

ifeq ($(strip $(LINT)),TRUE)
	-@if not exist $(COMPLINTLOGDIR)	(md $(COMPLINTLOGDIR)) 
	-@if exist $(strip $(COMPLINTLOGDIR))\lint.cfg del /F /Q $(strip $(COMPLINTLOGDIR))\lint.cfg
	@perl tools\SetLintEnv.pl $(strip $(COMPLINTLOGDIR))\lint.cfg $(COMPLINTLOGDIR) $*
endif

ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
ifeq ($(strip $(REDUCE_PLUTO_HEADER_DEPTH)),TRUE)
	@tools\strcmpex.exe abc abc e make\~compbld_2.tmp  INCDIRS  = $(strip $(HEADER_TEMP)) $(strip $(COMMINCDIRS))
else
	@tools\strcmpex.exe abc abc e make\~compbld_2.tmp  INCDIRS  = $(strip $(COMMINCDIRS))
endif
else
	@tools\strcmpex.exe abc abc e make\~compbld_2.tmp  INCDIRS  = $(strip $(COMMINCDIRS))
endif

	@type make\~compbld_2.tmp >> make\~compbld.tmp
	@if exist make\~compbld_2.tmp del  make\~compbld_2.tmp
	@tools\strcmpex.exe abc abc e make\~compbld_2.tmp  DEFINES  = $(strip $(COM_DEFS))
	@type make\~compbld_2.tmp >> make\~compbld.tmp
	@if exist make\~compbld_2.tmp del  make\~compbld_2.tmp
	@echo MMIDIR   = $(strip $(MMIDIR))>> make\~compbld.tmp
	@echo MMI_BASE   = $(strip $(MMI_BASE))>> make\~compbld.tmp
	@echo RF_MODULE   = $(strip $(RF_MODULE))>> make\~compbld.tmp
	@echo PROJECT   = $(strip $(PROJECT))>> make\~compbld.tmp
	@echo THE_MF   = $(strip $(THE_MF))>> make\~compbld.tmp
	@echo ARM9_PLATFORM   = $(strip $(ARM9_PLATFORM))>> make\~compbld.tmp
	@echo ARM11_PLATFORM   = $(strip $(ARM11_PLATFORM))>> make\~compbld.tmp
	@if not %0$(COMPILER)==%0 echo COMPILER = $(COMPILER)>> make\~compbld.tmp
	@if not %0$(RVCT_MULTI_FILE)==%0 echo RVCT_MULTI_FILE = $(RVCT_MULTI_FILE)>> make\~compbld.tmp
	@if not %0$(HEADER_TEMP)==%0 echo HEADER_TEMP = $(strip $(HEADER_TEMP)) >> make\~compbld.tmp

ifneq ($(strip $(XGC_AND_NOT_BOOTLOADER)),TRUE)		
	@if exist $(FIXPATH)\make\$*\master echo MASTER = TRUE>> make\~compbld.tmp
	@if exist $(FIXPATH)\make\$*\master echo MASTER = TRUE
	@if exist $(FIXPATH)\make\$*\slave echo SLAVE = TRUE>> make\~compbld.tmp
	@if exist $(FIXPATH)\make\$*\slave echo SLAVE = TRUE
endif

ifdef DUAL_MODE_SUPPORT
	@echo DUAL_MODE_SUPPORT = $(strip $(DUAL_MODE_SUPPORT))>> make\~compbld.tmp
endif

ifdef SMART_PHONE_CORE
ifneq ($(strip $(SMART_PHONE_CORE)),NONE)	
	@echo SMART_PHONE_CORE = $(strip $(SMART_PHONE_CORE))>> make\~compbld.tmp
endif
endif
	@echo ACTION = $(strip $(ACTION))>> make\~compbld.tmp			
	@echo COMPLOGDIR = $(strip $(COMPLOGDIR))>> make\~compbld.tmp
	@echo DEBUG_MODULES = $(strip $(DEBUG_MODULES))>> make\~compbld.tmp
	@echo NON_DEBUG_MODULES = $(strip $(NON_DEBUG_MODULES))>> make\~compbld.tmp
	@echo CUS_REL_PAR_SRC_COMP = $(strip $(CUS_REL_PAR_SRC_COMP))>> make\~compbld.tmp

ifdef MODIS_CONFIG
  ifeq ($(strip $(MODIS_CONFIG)),TRUE)
		@echo MODIS_CONFIG = TRUE>> make\~compbld.tmp 
  endif
endif


genmoduleinfo: genlog gencompbld
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifeq ($(strip $(MODIS_CONFIG)),TRUE)
	@tools\make.exe -fmake\gsm2.mak -r -R $(CMD_ARGU) genmoduleinfo_start
	@echo setup MoDIS env is done
else
	@perl tools\time.pl -n
	@tools\make.exe -fmake\gsm2.mak -r -R $(CMD_ARGU) genmoduleinfo_start
	@echo Generating .lis and .def files are done
	@perl tools\time.pl -n
endif
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

genmoduleinfo_start: $(MODULELIS)
	@echo genmoduleinfo is done.

%.lis:
ifeq ($(strip $(MODIS_CONFIG)),TRUE)
	@if not exist $(strip $(COMPLOGDIR))\modis_setup md $(strip $(COMPLOGDIR))\modis_setup
	@echo setup MoDIS env of $*
	@(tools\make.exe -fmake\comp.mak -k -r -R $(strip $(CMD_ARGU)) COMPONENT=$* GEN_MODULE_INFO=TRUE setup_env > $(strip $(COMPLOGDIR))\modis_setup\$*_setEnv_MoDIS.log 2>&1) 
else
	@if not exist $(strip $(COMPLOGDIR))\module_info md $(strip $(COMPLOGDIR))\module_info
	@if not exist $(strip $(TARGDIR))\module md $(strip $(TARGDIR))\module
	@echo Generate $* information
	@(tools\make.exe -fmake\comp.mak -k -r -R $(strip $(CMD_ARGU)) COMPONENT=$* GEN_MODULE_INFO=TRUE setup_env > $(strip $(COMPLOGDIR))\module_info\$*_module_info.log 2>&1) 
endif

# *************************************************************************
#  ximgen for CardDownload
# *************************************************************************
ximgen:
# mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
	@echo Start to execute ximgen
	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE)) \
		(perl $(FIXPATH)\tools\cfgGen.pl 2 $(strip $(TARGDIR)) $(strip $(BIN_FILE)) $(strip $(BTLD_BIN_FILE)) $(strip $(FOTA_BIN_FILE)) $(strip $(THE_MF)) $(FIXPATH)\custom\system\$(strip $(BOARD_VER)) $(SCATTERFILE) > $(strip $(COMPLOGDIR))\ximgen_1.log)
	 
	@if exist $(strip $(FIXPATH))\tools\CardDownload\ximgen.bat \
	($(strip $(FIXPATH))\tools\CardDownload\ximgen.bat $(FIXPATH)\custom\system\$(strip $(BOARD_VER))\IM_Maker.ini $(strip $(TARGDIR)) $(strip $(CUSTOMER))_$(strip $(PLATFORM))_$(strip $(PURE_VERNO)) $(strip $(EMPTY_RESOURCE)) > $(strip $(COMPLOGDIR))\ximgen.log) & \
	(if ERRORLEVEL 1 \
		(@echo ximgen ERROR!! Please check $(strip $(COMPLOGDIR))\ximgen.log) & \
    (exit 1) \
   else \
		(@echo ximgen is done) )
# mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))

# *************************************************************************
#  gen module ID and library table for databse trace information
# *************************************************************************	
gen_modlibtbl:
# mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_S,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
ifneq ($(strip $(ACTION)),new)
	@tools\make.exe -fmake\gsm2.mak -r -R CHECK_SCAN=TRUE scan
endif
	@echo Generate a table for module ID and library...
ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
	@tools\ModLibTbl.exe -log-$(strip $(COMPLOGDIR)) -dep-$(strip $(RULESDIR)) -out-$(strip $(TST_DB))\custom_databaseinfo.csv
else
	@tools\ModLibTbl.exe -log-$(strip $(COMPLOGDIR)) -dep-$(strip $(RULESDIR)) -out-$(strip $(TST_DB))\MTK_databaseinfo.csv
endif
# mbis time probe
	@if /I "$(strip $(MBIS_EN))"  EQU "TRUE" (@perl -e "print 'T_E,$@,T,'. time . \"\n\"";>>$(MBIS_BUILD_TIME_TMP))
