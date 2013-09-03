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
#  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER S
#  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
#
#  BUYER S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK S ENTIRE AND CUMULATIVE
#  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
#  AT MEDIATEK S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
#  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
#  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
#
#  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
#  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
#  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
#  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
#  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).

# *************************************************************************
# Include GNU Make Standard Library (GMSL)
# *************************************************************************
-include tools\GMSL\gmsl
Upper = $(subst z,Z,$(subst y,Y,$(subst x,X,$(subst w,W,$(subst v,V,$(subst u,U,$(subst t,T,$(subst s,S,$(subst r,R,$(subst q,Q,$(subst p,P,$(subst o,O,$(subst n,N,$(subst m,M,$(subst l,L,$(subst k,K,$(subst j,J,$(subst i,I,$(subst h,H,$(subst g,G,$(subst f,F,$(subst e,E,$(subst d,D,$(subst c,C,$(subst b,B,$(subst a,A,$(1)))))))))))))))))))))))))))
# *************************************************************************
# Set defaul value to Ckmake flag 
# *************************************************************************
DEPENDENCY_CONFLICT = FALSE
# *************************************************************************
# Dependency Check error message Interfaces
# *************************************************************************
# ------------------------------------------------------------------------
# Usage: 		$(call DEP_ERR_SETA_OR_SETB,OptA,ValA,OptB,ValB)
#						$(call DEP_ERR_SETA_OR_SETB,OptA,ValA,OptB,ValB1/ValB2/.../ValBn)
#						$(call DEP_ERR_SETA_OR_SETB,OptA,ValA,OptB,non ValB)
# Output:		PLEASE set OptA as ValA or set OptB as ValB
#						PLEASE set OptA as ValA or set OptB as ValB1/ValB2/.../ValBn
#						PLEASE set OptA as ValA or set OptB as non ValB
#
# Example:	$(call DEP_ERR_SETA_OR_SETB,BROWSER_SUPPORT,OBIGO_Q05A,UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT,non OBIGO_Q05A)
#						PLEASE set BROWSER_SUPPORT as OBIGO_Q05A or set UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT as non OBIGO_Q05A
# ------------------------------------------------------------------------
DEP_ERR_SETA_OR_SETB = $(warning ERROR: PLEASE set $1 as $2 or set $3 as $4) 
# ------------------------------------------------------------------------
# Usage: 		$(call DEP_ERR_ONA_OR_OFFB,OptA,OptB)
#          $(call DEP_ERR_ONA_OR_OFFB,OptA,OptB$OptC&...&OptN)
# Output:		PLEASE turn on OptA or turn off OptB
#
# Example:	$(call DEP_ERR_ONA_OR_OFFB,NAND_SUPPORT,NAND_FLASH_BOOTING)
#						PLEASE turn on NAND_SUPPORT or turn off NAND_FLASH_BOOTING
# ------------------------------------------------------------------------
DEP_ERR_ONA_OR_OFFB = $(warning ERROR: PLEASE turn on $1 or turn off $2) 
# ------------------------------------------------------------------------
# Usage: 		$(call DEP_ERR_SETA_OR_OFFB,OptA,ValA,OptB)
#						$(call DEP_ERR_SETA_OR_OFFB,OptA,ValA1/ValA2/.../ValAn,OptB)
#						$(call DEP_ERR_SETA_OR_OFFB,OptA,non ValA,OptB)
# Output:		PLEASE set OptA as ValA or turn off OptB
#						PLEASE set OptA as ValA1/ValA2/.../ValAn or turn off OptB
#						PLEASE set OptA as non ValA or turn off OptB
#
# Example:	$(call DEP_ERR_SETA_OR_OFFB,MELODY_VER,DSP_WT_SYN,J2ME_SUPPORT)
#						PLEASE set MELODY_VER as DSP_WT_SYN or turn off J2ME_SUPPORT
# ------------------------------------------------------------------------
DEP_ERR_SETA_OR_OFFB = $(warning ERROR: PLEASE set $1 as $2 or turn off $3)
# ------------------------------------------------------------------------
# Usage: 		$(call DEP_ERR_SETA_OR_ONB,OptA,ValA,OptB)
#						$(call DEP_ERR_SETA_OR_ONB,OptA,ValA1/ValA2/.../ValAn,OptB)
#						$(call DEP_ERR_SETA_OR_ONB,OptA,non ValA,OptB)
# Output:		PLEASE set OptA as ValA or turn on OptB
#						PLEASE set OptA as ValA1/ValA2/.../ValAn or turn on OptB
#						PLEASE set OptA as non ValA or turn on OptB
#
# Example:	$(call DEP_ERR_SETA_OR_ONB,MMS_SUPPORT,non OBIGO_Q05A,UNIFIED_MESSAGE_FOLDER)
#						PLEASE set MMS_SUPPORT as non OBIGO_Q05A or turn on UNIFIED_MESSAGE_FOLDER
# ------------------------------------------------------------------------
DEP_ERR_SETA_OR_ONB = $(warning ERROR: PLEASE set $1 as $2 or turn on $3) 
# ------------------------------------------------------------------------
# Usage: 		$(call DEP_ERR_OFFA_OR_OFFB,OptA,OptB)
# Output:		PLEASE turn off OptA or turn off OptB
#
# Example:	$(call DEP_ERR_OFFA_OR_OFFB,CMUX_SUPPORT,BLUETOOTH_SUPPORT)
#						PLEASE turn off CMUX_SUPPORT or turn off BLUETOOTH_SUPPORT
# ------------------------------------------------------------------------
DEP_ERR_OFFA_OR_OFFB = $(warning ERROR: PLEASE turn off $1 or turn off $2) 
# ------------------------------------------------------------------------
# Usage: 		$(call DEP_ERR_ONA_OR_ONB,OptA,OptB)
# Output:		PLEASE turn on OptA or turn on OptB
#
# Example:	$(call DEP_ERR_ONA_OR_ONB,UCM_SUPPORT,VOIP_SUPPORT)
#						PLEASE turn on UCM_SUPPORT or turn on VOIP_SUPPORT
# ------------------------------------------------------------------------
DEP_ERR_ONA_OR_ONB = $(warning ERROR: PLEASE turn on $1 or turn on $2) 
# *************************************************************************
# Set defaul value to eliminate "option not define" warning
# *************************************************************************
BM_NEW         =  FALSE
RUN_RESGEN      =  FALSE

# *************************************************************************
# Include temporary build script
# *************************************************************************
# Get $(PROJECT) Definition
-include make\~buildinfo.tmp

# Custom specific build script
-include make\Custom.bld         # Custom release build
ifndef CUSTOM_RELEASE
CUSTOM_RELEASE  =  FALSE         # Default custom release
endif

ifndef MTK_SUBSIDIARY
  MTK_SUBSIDIARY = FALSE
endif

ifeq ($(strip $(call Upper,$(CUSTOMER))),MTK)

 ifneq ($(strip $(call Upper,$(APLAT))),NONE)
include make\$(strip $(APLAT))_$(strip $(PROJECT)).mak
THE_MF = make\$(strip $(APLAT))_$(strip $(PROJECT)).mak
 else
include make\$(strip $(CUSTOMER))_$(strip $(PROJECT)).mak
THE_MF = make\$(strip $(CUSTOMER))_$(strip $(PROJECT)).mak
 endif

else
include make\$(strip $(CUSTOMER))_$(strip $(PROJECT)).mak
THE_MF = make\$(strip $(CUSTOMER))_$(strip $(PROJECT)).mak
endif

-include make\USER_SPECIFIC.mak
ifndef DEBUG_MODULES
  DEBUG_MODULES =
endif

ifndef NON_DEBUG_MODULES
  NON_DEBUG_MODULES =
endif

ENABLE_PARTIAL_TRACE=FALSE
ifdef KAL_TRACE_OUTPUT
  ifdef PARTIAL_TRACE_LIB
    ifeq ($(strip $(KAL_TRACE_OUTPUT)),CUST_PARTIAL)
      ifneq ($(strip $(PARTIAL_TRACE_LIB)),)
        ENABLE_PARTIAL_TRACE=TRUE
      endif
    endif
  endif
endif

INSIDE_MTK = 0
ifdef USERINTERNAL
  ifeq ($(strip $(USERINTERNAL)),INTERNAL)
    INSIDE_MTK = 1
  endif
endif

# *************************************************************************
# Include checkvalue.mak to check invalid feature values.
# *************************************************************************
-include make\checkvalue.mak
-include make\OLD_FEATURES.mak

# *************************************************************************
# Environment and Tools
# *************************************************************************
COMPILE_MODE   =  INST16                           # 16bits instruction set

# default is ADS compiler
ifndef COMPILER
  VIA = -via
  MD = -MD
  COMPILER = ADS
  CGEN_DEF_FILE = Tgt_Cnf
else
  ifeq ($(strip $(COMPILER)),RVCT)
    VIA = --via
    MD = --md
    CGEN_DEF_FILE = Tgt_Cnf_RVCT
  else
    CGEN_DEF_FILE = Tgt_Cnf
  endif
  ifeq ($(strip $(COMPILER)),ADS)
    VIA = -via
    MD = -MD
  endif
endif

#ifeq ($(strip $(COMPILER)),RVCT)
#  DIR_ARM        =  C:\Progra~1\ARM\RVCT
#  DIR_ARM := $(strip $(DIR_ARM))
#  DIR_TOOL       =  $(DIR_ARM)\Programs\2.1\328\win_32-pentium
#  DIR_ARMLIB     =  $(DIR_ARM)\Data\2.1\328\lib
#  DIR_ARMINC     =  $(DIR_ARM)\Data\2.1\328\include
#endif

DIR_INT_569  =  $(DIR_ARM)\Programs\3.1\569_init

ifdef RVCT_VERSION
    ifneq ($(strip $(RVCT_VERSION)),NONE)
        ifneq ($(strip $(COMPILER)),RVCT)
            $(call DEP_ERR_SETA_OR_OFFB,COMPILER,RVCT,RVCT_VERSION)
            DEPENDENCY_CONFLICT = TRUE
        endif
    endif
endif

VERIFYCUS = $(shell if %USERINTERNAL% EQU INTERNAL echo MTKINTERNAL)
ifeq ($(strip $(COMPILER)),RVCT)
  ifndef RVCT_VERSION
      $(call DEP_ERR_SETA_OR_ONB,COMPILER,non RVCT,RVCT_VERSION)  
      DEPENDENCY_CONFLICT = TRUE
  endif 
  ifeq ($(strip $(RVCT_VERSION)),NONE)
      $(call DEP_ERR_SETA_OR_ONB,COMPILER,non RVCT,RVCT_VERSION)
      DEPENDENCY_CONFLICT = TRUE
  endif
  DIR_ARM        =  C:\Progra~1\ARM\RVCT
  DIR_ARM := $(strip $(DIR_ARM))
  ifeq ($(strip $(RVCT_VERSION)),V22)
    DIR_TOOL       =  $(DIR_ARM)\Programs\2.2\349\win_32-pentium
    DIR_ARMLIB     =  $(DIR_ARM)\Data\2.2\349\lib
    DIR_ARMINC     =  $(DIR_ARM)\Data\2.2\349\include\windows
    ifeq ($(strip $(MMI_VERSION)),WISDOM_MMI)
      ifeq ($(strip $(WISDOM_CUSTOM_BUILD)),TRUE)
        DIR_TOOL       =  $(RVCT22BIN)
        DIR_ARMLIB     =  $(RVCT22LIB)
        DIR_ARMINC     =  $(RVCT22INC)
      endif
    endif
  endif
  ifeq ($(strip $(RVCT_VERSION)),V31)
        DIR_TOOL       =  $(DIR_ARM)\Programs\3.1\569\win_32-pentium
        DIR_ARMLIB     =  $(DIR_ARM)\Data\3.1\569\lib
        DIR_ARMINC     =  $(DIR_ARM)\Data\3.1\569\include\windows

  ifeq ($(strip $(VERIFYCUS)),MTKINTERNAL)
    ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
      ifeq ($(strip $(MTK_SUBSIDIARY)),FALSE)  
        include make\verifyCus.mak
      endif
    endif
  endif 
  
  endif
endif

ifeq ($(strip $(COMPILER)),ADS)
  DIR_ARM        =  c:\progra~1\arm\adsv1_2
  DIR_ARM := $(strip $(DIR_ARM))
  DIR_TOOL       =  $(DIR_ARM)\bin
  DIR_ARMLIB     =  $(DIR_ARM)\lib
  DIR_ARMINC     =  $(DIR_ARM)\include
endif

ifeq ($(strip $(call Upper,$(COMPILER))),BLACKFIN)
  DIR_BF        =  C:\PROGRA~1\ANALOG~1\VISUAL~1.0
  DIR_TOOL       =  $(DIR_BF)
  DIR_BFLIB     =  $(DIR_BF)\Blackfin\lib
  DIR_BFINC     =  $(DIR_BF)\Blackfin\include
endif


ifeq ($(strip $(call Upper,$(COMPILER))),ADS)
  DIR_TOOL := $(strip $(DIR_TOOL))
  LINK           =  $(DIR_TOOL)\armlink.exe          # Linker
  ASM            =  $(DIR_TOOL)\armasm.exe           # ARM assembler
  LIB            =  $(DIR_TOOL)\armar.exe            # Library tool
  BIN_CREATE     =  $(DIR_TOOL)\fromelf.exe          # Binary tool
endif

ifeq ($(strip $(call Upper,$(COMPILER))),RVCT)
  DIR_TOOL := $(strip $(DIR_TOOL))
  LINK           =  $(DIR_TOOL)\armlink.exe          # Linker
  ASM            =  $(DIR_TOOL)\armasm.exe           # ARM assembler
  LIB            =  $(DIR_ARM)\Programs\3.1\569\win_32-pentium\armar.exe            # Library tool
  BIN_CREATE     =  $(DIR_TOOL)\fromelf.exe          # Binary tool
endif

ifeq ($(strip $(call Upper,$(COMPILER))),BLACKFIN)
  DIR_TOOL := $(strip $(DIR_TOOL))
  LINK           =  $(DIR_TOOL)\linker.exe           # Linker, generating dxe file
  ASM            =  $(DIR_TOOL)\easmBLKFN.exe        # ARM assembler
  LIB            =  $(DIR_TOOL)\elfar.exe            # Library tool
  BIN_CREATE     =  $(DIR_TOOL)\elfloader.exe        # Binary tool, generating ldr file
endif
  

ifeq ($(strip $(COMPILER)),RVCT)
  ifeq ($(strip $(COMPILE_MODE)),INST16)
     CC          =  $(DIR_TOOL)\armcc.exe --thumb    # Thumb Mode(16bits), use tcc
     CC32        =  $(DIR_TOOL)\armcc.exe --arm      # ARM Mode(32bits), use armcc
  else
     ifeq ($(strip $(COMPILE_MODE)),INST32)
        CC          =  $(DIR_TOOL)\armcc.exe --arm   # ARM Mode(32bits), use armcc
     else
        CC          =  $(DIR_TOOL)\armcc.exe --thumb # Default tcc
        CC32        =  $(DIR_TOOL)\armcc.exe --arm   # ARM Mode(32bits), use armcc
     endif
  endif
endif

ifeq ($(strip $(COMPILER)),ADS)
  ifeq ($(strip $(COMPILE_MODE)),INST16)
     CC          =  $(DIR_TOOL)\tcc.exe              # Thumb Mode(16bits), use tcc
     CC32        =  $(DIR_TOOL)\armcc.exe            # ARM Mode(32bits), use armcc
     CPPC        =  $(DIR_TOOL)\tcpp.exe              # Thumb Mode(16bits), use tcc
     CPPC32      =  $(DIR_TOOL)\armcpp.exe            # ARM Mode(32bits), use armcc
  else
     ifeq ($(strip $(COMPILE_MODE)),INST32)
        CC          =  $(DIR_TOOL)\armcc.exe            # ARM Mode(32bits), use armcc
        CPPC        =  $(DIR_TOOL)\armcpp.exe            # ARM Mode(32bits), use armcc
     else
        CC          =  $(DIR_TOOL)\tcc.exe              # Default tcc
        CC32        =  $(DIR_TOOL)\armcc.exe            # ARM Mode(32bits), use armcc
        CPPC        =  $(DIR_TOOL)\tcpp.exe              # Thumb Mode(16bits), use tcc
        CPPC32      =  $(DIR_TOOL)\armcpp.exe            # ARM Mode(32bits), use armcc
     endif
  endif
endif


ifeq ($(strip $(call Upper,$(COMPILER))),BLACKFIN)
  CC          =  $(DIR_TOOL)\ccblkfn.exe            # 16bits Mode, use ccblkfn.exe
  CC32        =  $(DIR_TOOL)\ccblkfn.exe            # 32bits Mode, use ccblkfn.exe
  CPPC        =  $(DIR_TOOL)\ccblkfn.exe            # 16bits Mode, use ccblkfn.exe
  CPPC32      =  $(DIR_TOOL)\ccblkfn.exe            # 32bits Mode, use ccblkfn.exe
endif



# *************************************************************************
# Build Options
# *************************************************************************

# -----------------------------
# CODEGEN option
# -----------------------------
ifeq ($(strip $(COMPILER)),RVCT)
   CGENFLAG = -D__RVCT__
endif

ifeq ($(strip $(COMPILER)),ADS)
   CGENFLAG =
endif

ifeq ($(strip $(COMPILER)),BLACKFIN)
   CGENFLAG = -D__BLACKFIN__
endif

# -----------------------------
# Interwork option
# -----------------------------
APCSINT     =
ifeq ($(strip $(COMPILER)),RVCT)
  ifeq ($(strip $(COMPILE_MODE)),INST16)
     APCSINT  +=  --apcs /inter/noswst
  endif
endif

ifeq ($(strip $(COMPILER)),ADS)
  ifeq ($(strip $(COMPILE_MODE)),INST16)
     APCSINT  +=  -apcs /interwork
  endif
endif

# -----------------------------
# C options COPTION16 for thumb mode and COPTION32 for arm mode
# -----------------------------
-include tools\RVCTBuildNo.tmp
ifeq ($(strip $(COMPILER)),RVCT)

armtoolinfo = $(shell $(CC) --vsn 2>&1)
armtoolver = $(shell perl tools\armversion.pl $(armtoolinfo))
ifeq ($(strip $(armtoolver)),1021)
REMOVE_UNNEEDED_ENTITIES:=--remove_unneeded_entities -D__FILE__=__MODULE__
endif
ifeq ($(strip $(armtoolver)),569)
REMOVE_UNNEEDED_ENTITIES:=--remove_unneeded_entities
endif
 
  CPLUSFLAGS = --cpp --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) 
  CFLAGS     = --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__  -J$(DIR_ARMINC) --fpmode=ieee_fixed
  LNKOPT     = --cpu ARM7EJ-S
  ifeq ($(strip $(PLATFORM)),MT6218B)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
     LNKOPT   :=   --cpu ARM7EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6217)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
     LNKOPT   :=   --cpu ARM7EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6219)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
     LNKOPT   :=   --cpu ARM7EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6226M)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
     LNKOPT   :=   --cpu ARM7EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6229)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
     LNKOPT   :=   --cpu ARM7EJ-S
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6268T)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
     LNKOPT   :=   --cpu ARM7EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6268H)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
     LNKOPT   :=   --cpu ARM7EJ-S
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6268A)
     CFLAGS   :=   --cpu ARM9EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
     LNKOPT   :=   --cpu ARM9EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6268)
     CFLAGS   :=   --cpu ARM9EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
     LNKOPT   :=   --cpu ARM9EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6270A)
     CFLAGS   :=   --cpu ARM9EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
     LNKOPT   :=   --cpu ARM9EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6230)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
     LNKOPT   :=   --cpu ARM7EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6228)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
     LNKOPT   :=   --cpu ARM7EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6227)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
     LNKOPT   :=   --cpu ARM7EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6227D)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
     LNKOPT   :=   --cpu ARM7EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6226)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
     LNKOPT   :=   --cpu ARM7EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6226D)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
     LNKOPT   :=   --cpu ARM7EJ-S
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6208)
     CFLAGS   :=   --cpu ARM7TDMI --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
     LNKOPT   :=   --cpu ARM7TDMI
  endif

  ifeq ($(strip $(PLATFORM)),MT6205B)
     CFLAGS   :=   --cpu ARM7TDMI --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
     LNKOPT   :=   --cpu ARM7TDMI
  endif

  ifeq ($(strip $(PLATFORM)),MT6205C)
     CFLAGS   :=   --cpu ARM7TDMI --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
     LNKOPT   :=   --cpu ARM7TDMI
  endif

  ifeq ($(strip $(PLATFORM)),MT6225)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
     LNKOPT   :=   --cpu ARM7EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6253T)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
     LNKOPT   :=   --cpu ARM7EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6253)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
     LNKOPT   :=   --cpu ARM7EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6253E)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) 
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6252H)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) 
  endif

  ifeq ($(strip $(PLATFORM)),MT6253L)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) 
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6252)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) 
  endif

  ifeq ($(strip $(PLATFORM)),MT6223)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
     LNKOPT   :=   --cpu ARM7EJ-S
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6223P)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
     LNKOPT   :=   --cpu ARM7EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6238)
     CFLAGS   :=   --cpu ARM9EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
     LNKOPT   :=   --cpu ARM9EJ-S
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6239)
     CFLAGS   :=   --cpu ARM9EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
     LNKOPT   :=   --cpu ARM9EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6235)
     CFLAGS   :=   --cpu ARM9EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
     LNKOPT   :=   --cpu ARM9EJ-S
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6235B)
     CFLAGS   :=   --cpu ARM9EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
     LNKOPT   :=   --cpu ARM9EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6236)
     CFLAGS   :=   --cpu ARM9EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
     LNKOPT   :=   --cpu ARM9EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6236B)
     CFLAGS   :=   --cpu ARM9EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
     LNKOPT   :=   --cpu ARM9EJ-S
  endif

  ifeq ($(strip $(PLATFORM)),MT6516)
    ifdef SMART_PHONE_CORE
      ifeq ($(strip $(SMART_PHONE_CORE)),AP)
        CFLAGS   :=   --cpu ARM9EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
      else
        CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
      endif
    else
      CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
    endif
  endif

endif

ifeq ($(strip $(COMPILER)),ADS)
  CPLUSFLAGS = -cpp -cpu ARM7EJ-S -littleend -O2 -zo -Ono_peephole -fa
  CFLAGS     =   -cpu ARM7EJ-S -littleend -O2 -zo -Ono_peephole -fa

  ifeq ($(strip $(PLATFORM)),MT6218B)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6217)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6219)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6226M)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6229)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6268T)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6268H)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6268A)
     CFLAGS     :=   -cpu ARM9EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6268)
     CFLAGS     :=   -cpu ARM9EJ-S -littleend -O2 -zo -fa
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6270A)
     CFLAGS     :=   -cpu ARM9EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6230)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6228)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6227)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6227D)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6226)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6226D)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6208)
      CFLAGS     :=   -cpu ARM7TDMI -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6205B)
      CFLAGS     :=   -cpu ARM7TDMI -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6205C)
      CFLAGS     :=   -cpu ARM7TDMI -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6225)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6253T)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6253)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6253E)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6252H)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6253L)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6252)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6223)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6223P)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6238)
     CFLAGS     :=   -cpu ARM9EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6239)
     CFLAGS     :=   -cpu ARM9EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6235)
     CFLAGS     :=   -cpu ARM9EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6235B)
     CFLAGS     :=   -cpu ARM9EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6236)
     CFLAGS     :=   -cpu ARM9EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6236B)
     CFLAGS     :=   -cpu ARM9EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6516)
    ifdef SMART_PHONE_CORE
      ifeq ($(strip $(SMART_PHONE_CORE)),AP)
        CFLAGS     :=   -cpu ARM9EJ-S -littleend -O2 -zo -fa
      else
        CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
      endif
    else
      CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
    endif
  endif

endif

ifeq ($(strip $(call Upper,$(COMPILER))),BLACKFIN)
     CFLAGS     := -proc ADSP-BF535  -no-extra-keywords  -Ov0 -si-revision none -ipa -c
endif

ifeq ($(strip $(COMPILER)),RVCT)
  CFLAGS += --split_sections 
  CFLAGS += --diag_suppress 1,2548
  ifeq ($(strip $(RVCT_DEBUG_FORMAT)),DWARF3)
    CFLAGS += --dwarf3
  else
    CFLAGS += --dwarf2
  endif
  CPLUSFLAGS := --cpp $(CFLAGS)
endif

ifeq ($(strip $(COMPILER)),ADS)
  CPLUSFLAGS := -cpp $(CFLAGS)
endif

CFLAGS     +=  $(CUSTOM_CFLAGS)
CPLUSFLAGS +=  $(CUSTOM_CFLAGS)

# -----------------------------
# assembly option AOPTION16 for Thumb mode and AOPTION32 for Arm mode
# -----------------------------
ifeq ($(strip $(COMPILER)),RVCT)
  BL_AFLAGS  = --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  AFLAGS     = --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  ifeq ($(strip $(PLATFORM)),MT6218B)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6219)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6217)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6226M)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6226)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6226D)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6227)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6227D)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6228)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6229)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6268T)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6268H)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6268A)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6268)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6270A)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6230)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6225)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6253T)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6253)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6253E)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6252H)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6253L)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6252)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6223)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6223P)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6238)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6239)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6235)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6235B)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6236)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6236B)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6516)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
endif

ifeq ($(strip $(COMPILER)),ADS)
  BL_AFLAGS  = -g -littleend -cpu ARM7TDMI
  AFLAGS     = -g -littleend -cpu ARM7TDMI
  ifeq ($(strip $(PLATFORM)),MT6218B)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6219)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6217)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6226M)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6226)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6226D)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6227)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6227D)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6228)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6229)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6268T)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6268H)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6268A)
    BL_AFLAGS  :=   -g -littleend -cpu ARM9EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM9EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6268)
    BL_AFLAGS  :=   -g -littleend -cpu ARM9EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM9EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6270A)
    BL_AFLAGS  :=   -g -littleend -cpu ARM9EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM9EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6230)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6225)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6253T)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6253)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6253E)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6252H)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6253L)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6252)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif   
  ifeq ($(strip $(PLATFORM)),MT6223)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6223P)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6238)
    BL_AFLAGS  :=   -g -littleend -cpu ARM9EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM9EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6239)
    BL_AFLAGS  :=   -g -littleend -cpu ARM9EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM9EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6235)
    BL_AFLAGS  :=   -g -littleend -cpu ARM9EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM9EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6235B)
    BL_AFLAGS  :=   -g -littleend -cpu ARM9EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM9EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6236)
    BL_AFLAGS  :=   -g -littleend -cpu ARM9EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM9EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6236B)
    BL_AFLAGS  :=   -g -littleend -cpu ARM9EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM9EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6516)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
endif

ifeq ($(strip $(call Upper,$(COMPILER))),BLACKFIN)
     AFLAGS     := -proc ADSP-BF535 -si-revision none -g 
endif


ifeq ($(strip $(COMPILE_MODE)),INST16)
  BL_AFLAGS += -16
  AFLAGS +=  -16
endif

# -----------------------------
# Library option LIBOPT for generating libraries
# -----------------------------
ifeq ($(strip $(COMPILER)),RVCT)
  LIBOPT      =  --create
endif
ifeq ($(strip $(COMPILER)),ADS)
  LIBOPT      =  -create
endif

# -----------------------------
# Linker options
# -----------------------------
ifeq ($(strip $(COMPILER)),RVCT)
  ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
    LNKOPT      +=  --map --info sizes,totals --symbols --feedback lnkfeedback.txt --xref --remove --pad 0x00 --datacompressor off --verbose
  else
    LNKOPT      +=  --map --info sizes,totals --symbols --feedback lnkfeedback.txt --xref --remove --pad 0x00 --datacompressor off
  endif
  ifneq ($(strip $(call Upper,$(PROJECT))),L1S)
    ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
        LNKOPT      +=  --first LARGEPOOL_FIRST_ZI
    endif
  endif
endif

ifeq ($(strip $(COMPILER)),ADS)
  ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
    LNKOPT      =  -map -info sizes,totals -symbols -xref -remove -verbose
  else
    LNKOPT      =  -map -info sizes,totals -symbols -xref -remove
  endif
  ifneq ($(strip $(call Upper,$(PROJECT))),L1S)
    ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
      ifneq ($(strip $(call Upper,$(PROJECT))),MEUT)
        LNKOPT      +=  -first LARGEPOOL_FIRST_ZI
      endif
    endif
  endif
endif


ifeq ($(strip $(call Upper,$(COMPILER))),BLACKFIN)
    LNKOPT      =  -proc ADSP-BF535 -si-revision none -verbose -map -xref -e 
endif

ifeq ($(strip $(FLAVOR)),NON_DEBUG)
    LNKOPT = -remove -map
endif

# -----------------------------
# Binary tool options
# -----------------------------
BIN_FORMAT  =  -bin

ifdef OPTR_SPEC
  ifneq ($(strip $(OPTR_SPEC)),NONE)
    ifneq ($(findstring TECH,$(strip $(subst _, ,$(OPTR_SPEC)))),)
       OPTR_SPEC  := $(strip $(subst _TECH, ,$(OPTR_SPEC)))
       OPTR_DEFS   +=  __OP_TECH_REL__
       OPTR_DEFS   +=  __$(strip $(OPTR_SPEC))_TECH__
       ifdef OPTR_CODE
          OPTR_DEFS   +=  __$(strip $(OPTR_CODE))_$(strip $(word 2,$(subst _, ,$(OPTR_SPEC)))_$(word 3,$(subst _, ,$(OPTR_SPEC))))_TECH__
       endif
    endif
    ifdef OPTR_CODE
       OPTR_DEFS   +=  __$(strip $(OPTR_CODE))__
       OPTR_DEFS   +=  __$(strip $(OPTR_CODE))_$(strip $(word 2,$(subst _, ,$(OPTR_SPEC))))__
       OPTR_DEFS   +=  __$(strip $(OPTR_CODE))_$(strip $(word 2,$(subst _, ,$(OPTR_SPEC)))_$(word 3,$(subst _, ,$(OPTR_SPEC))))__
    endif
  endif
endif

# -----------------------------
# custom release library path
# -----------------------------
ifdef OPTR_SPEC
  ifeq ($(strip $(OPTR_SPEC)),NONE)
    ifdef SWITCHABLE_FEATURE
      ifneq ($(strip $(SWITCHABLE_FEATURE)),NONE)
        ifdef SWITCHABLE_FEATURE_2ND
          ifneq ($(strip $(SWITCHABLE_FEATURE_2ND)),NONE)
            CUS_MTK_LIB = mtk_lib\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT))\$(strip $(SWITCHABLE_FEATURE))\$(strip $($(strip $(SWITCHABLE_FEATURE))))\$(strip $(SWITCHABLE_FEATURE_2ND))\$(strip $($(strip $(SWITCHABLE_FEATURE_2ND))))
            ifeq ($(strip $(ENABLE_PARTIAL_TRACE)),TRUE)
              CUS_MTK_LIB       = mtk_lib\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT))\$(strip $(SWITCHABLE_FEATURE))\NONE\$(strip $(SWITCHABLE_FEATURE_2ND))\$(strip $($(strip $(SWITCHABLE_FEATURE_2ND))))
              CUS_MTK_LIB_TRACE = mtk_lib\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT))\$(strip $(SWITCHABLE_FEATURE))\FULL\$(strip $(SWITCHABLE_FEATURE_2ND))\$(strip $($(strip $(SWITCHABLE_FEATURE_2ND))))
            endif
          else
            CUS_MTK_LIB = mtk_lib\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT))\$(strip $(SWITCHABLE_FEATURE))\$(strip $($(strip $(SWITCHABLE_FEATURE))))
            ifeq ($(strip $(ENABLE_PARTIAL_TRACE)),TRUE)
              CUS_MTK_LIB =       mtk_lib\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT))\$(strip $(SWITCHABLE_FEATURE))\NONE
              CUS_MTK_LIB_TRACE = mtk_lib\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT))\$(strip $(SWITCHABLE_FEATURE))\FULL
            endif
          endif
        else
          CUS_MTK_LIB = mtk_lib\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT))\$(strip $(SWITCHABLE_FEATURE))\$(strip $($(strip $(SWITCHABLE_FEATURE))))
          ifeq ($(strip $(ENABLE_PARTIAL_TRACE)),TRUE)
            CUS_MTK_LIB =       mtk_lib\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT))\$(strip $(SWITCHABLE_FEATURE))\NONE
            CUS_MTK_LIB_TRACE = mtk_lib\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT))\$(strip $(SWITCHABLE_FEATURE))\FULL
          endif
        endif
      else
        CUS_MTK_LIB = mtk_lib\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT))
      endif      
    else
      CUS_MTK_LIB = mtk_lib\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT))
    endif
  else
    ifdef SWITCHABLE_FEATURE
      ifneq ($(strip $(SWITCHABLE_FEATURE)),NONE)
        ifdef SWITCHABLE_FEATURE_2ND
          ifneq ($(strip $(SWITCHABLE_FEATURE_2ND)),NONE)
            CUS_MTK_LIB = mtk_lib\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT))\$(strip $(OPTR_SPEC))\$(strip $(SWITCHABLE_FEATURE))\$(strip $($(strip $(SWITCHABLE_FEATURE))))\$(strip $(SWITCHABLE_FEATURE_2ND))\$(strip $($(strip $(SWITCHABLE_FEATURE_2ND))))
            ifeq ($(strip $(ENABLE_PARTIAL_TRACE)),TRUE)
              CUS_MTK_LIB =       mtk_lib\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT))\$(strip $(OPTR_SPEC))\$(strip $(SWITCHABLE_FEATURE))\NONE\$(strip $(SWITCHABLE_FEATURE_2ND))\$(strip $($(strip $(SWITCHABLE_FEATURE_2ND))))
              CUS_MTK_LIB_TRACE = mtk_lib\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT))\$(strip $(OPTR_SPEC))\$(strip $(SWITCHABLE_FEATURE))\FULL\$(strip $(SWITCHABLE_FEATURE_2ND))\$(strip $($(strip $(SWITCHABLE_FEATURE_2ND))))
            endif
          else
            CUS_MTK_LIB = mtk_lib\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT))\$(strip $(OPTR_SPEC))\$(strip $(SWITCHABLE_FEATURE))\$(strip $($(strip $(SWITCHABLE_FEATURE))))
            ifeq ($(strip $(ENABLE_PARTIAL_TRACE)),TRUE)
              CUS_MTK_LIB =       mtk_lib\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT))\$(strip $(OPTR_SPEC))\$(strip $(SWITCHABLE_FEATURE))\NONE
              CUS_MTK_LIB_TRACE = mtk_lib\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT))\$(strip $(OPTR_SPEC))\$(strip $(SWITCHABLE_FEATURE))\FULL
            endif
          endif
        else
          CUS_MTK_LIB = mtk_lib\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT))\$(strip $(OPTR_SPEC))\$(strip $(SWITCHABLE_FEATURE))\$(strip $($(strip $(SWITCHABLE_FEATURE))))
          ifeq ($(strip $(ENABLE_PARTIAL_TRACE)),TRUE)
            CUS_MTK_LIB =       mtk_lib\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT))\$(strip $(OPTR_SPEC))\$(strip $(SWITCHABLE_FEATURE))\NONE
            CUS_MTK_LIB_TRACE = mtk_lib\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT))\$(strip $(OPTR_SPEC))\$(strip $(SWITCHABLE_FEATURE))\FULL
          endif
        endif
      else
        CUS_MTK_LIB = mtk_lib\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT))\$(strip $(OPTR_SPEC))
      endif      
    else
      CUS_MTK_LIB = mtk_lib\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT))\$(strip $(OPTR_SPEC))
    endif
  endif
endif

ifeq ($(strip $(PLATFORM)),MT6226)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6226,6226M,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6226,6226M,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(subst 6226,6227,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6226,6227,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6227)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6227,6226M,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6227,6226M,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(subst 6227,6226,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6227,6226,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6226M)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6226M,6226,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6226M,6226,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(subst 6226M,6227,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6226M,6227,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6229)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6229,6230,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6229,6230,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6230)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6230,6229,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6230,6229,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6226D)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6226D,6227D,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6226D,6227D,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6227D)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6227D,6226D,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6227D,6226D,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6223)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6223,6223P,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6223,6223P,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6223P)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6223P,6223,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6223P,6223,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6238)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6238,6239,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6238,6239,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6239)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6239,6238,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6239,6238,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6235)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6235,6235B,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6235,6235B,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6235B)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6235B,6235,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6235B,6235,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif

# *************************************************************************
# Common include file and output directory path
# *************************************************************************
ifndef RTOS
   RTOS = NUCLEUS
endif

ifndef RTOS_DEBUG
   RTOS_DEBUG = TRUE
endif

ifeq ($(strip $(RTOS)),NUCLEUS)
COMMINCDIRS    =  nucleus\inc \
                  kal\include kal\common\include \
                  kal\nucleus\include
endif

ifeq ($(strip $(RTOS)),NUCLEUS_V2)
COMMINCDIRS    =  nucleus_v2\inc \
                  kal\include kal\common\include \
                  kal\nucleus\include
endif

ifeq ($(strip $(RTOS)),THREADX)
COMMINCDIRS    =  threadx\inc \
                  kal\include kal\common\include \
                  kal\threadx\include
endif


ifeq ($(strip $(call Upper,$(PROJECT))),L1S)
COMMINCDIRS   +=  tst\database\gv \
                  tst\database\unionTag
endif

ifeq ($(strip $(call Upper,$(PROJECT))),BASIC)
COMMINCDIRS   +=  tst\database\gv \
                  tst\database\unionTag
endif

ifeq ($(strip $(call Upper,$(PROJECT))),MEUT)
COMMINCDIRS   +=  tst\database\gv \
                  tst\database\unionTag \
                  meut\include
endif

ifeq ($(strip $(call Upper,$(PROJECT))),GSM)
COMMINCDIRS   +=  tst\database\gv \
                  tst\database\unionTag
endif

ifeq ($(strip $(call Upper,$(PROJECT))),GPRS)
COMMINCDIRS   +=  tst\database_classb\gv \
                  tst\database_classb\unionTag

endif

ifneq ($(filter UMTS HSPA,$(strip $(call Upper,$(PROJECT)))),)
COMMINCDIRS   +=  tst\database_classb_umts\gv \
                  tst\database_classb_umts\unionTag
endif

CUS_REL_FILES_LIST   +=  tst\database\log2SD_Catcher_filters.ini

COMMINCDIRS   +=  custom\system\$(strip $(BOARD_VER))

ifeq ($(strip $(CUST_CODE)),TC01)
  COMMINCDIRS += custom\system\$(strip $(BOARD_VER))\ERS
endif

COMMINCDIRS   +=  interface\wap \
                  interface\browser \
                  wapadp\include 

COMMINCDIRS   +=  drm\include

COMMINCDIRS   +=  ps\email\inc \
                  ps\email\pop3\inc \
                  ps\email\smtp\inc \
                  ps\email\imap\inc

COMMINCDIRS   +=  ps\emlst\inc

COMMINCDIRS   +=  ps\ems\include ps\cc-ss\ss\include
COMMINCDIRS   +=  ps\l4\smu\include ps\l4\rac\include
COMMINCDIRS   +=  ps\interfaces\local_inc
COMMINCDIRS   +=  applib\asn1\include

ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
  COMMINCDIRS   +=  plutommi\Framework\CommonFiles\CommonInc \
                    plutommi\MMI\MiscFramework\MiscFrameworkInc \
                    plutommi\Framework\DebugLevels\DebugLevelInc \
                    plutommi\Framework\GUI\GUI_INC \
                    plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppInc \
                    plutommi\mtkapp\EngineerMode\EngineerModeEngine\EngineerModeEngineInc \
                    plutommi\mtkapp\FactoryMode\FactoryModeInc \
                    plutommi\Customer\CustomerInc
  CUS_REL_FILES_LIST += applib\misc\include\app_zlib.h
  CUS_REL_FILES_LIST += plutommi\Service\UcmSrv\UcmSrvResDef.h
endif

#for GEMINI
ifdef GEMINI
  ifneq ($(strip $(GEMINI)),FALSE)
    COMMINCDIRS   +=  SIM2\ps\l4\smu\include SIM2\ps\cc-ss\ss\include SIM2\ps\l4\rac\include
  endif  
endif

ifneq ($(filter UMTS HSPA,$(strip $(call Upper,$(PROJECT)))),)
  COMMINCDIRS   +=  ps\mcddll\include ps\rr2\asn\include
else
  COMMINCDIRS   +=  ps\mcddll\include ps\rr\asn\include
endif

COMMINCDIRS   += interface\bt
COMMINCDIRS   += ps\dt\include
COMMINCDIRS   += ps\smslib\include
COMMINCDIRS   += image_codec\sw_jpeg_codec\include


ifdef MSDC_CARD_SUPPORT_TYPE
  ifneq ($(strip $(MSDC_CARD_SUPPORT_TYPE)),NONE)
     ifneq ($(filter FMT_NOT_PRESENT,$(CUSTOM_OPTION)),)
       ifneq ($(call Upper,$(strip $(PROJECT))),BASIC)
         ifneq ($(call Upper,$(strip $(PROJECT))),MEUT)
           $(warning ERROR: Please remove FMT_NOT_PRESENT from CUSTOM_OPTION when MSDC_CARD_SUPPORT_TYPE is set as MSDC_SD_MMC!)
           DEPENDENCY_CONFLICT = TRUE
         endif
       endif
     endif
  endif
endif

ifneq ($(filter FMT_NOT_PRESENT,$(CUSTOM_OPTION)),)
  ifneq ($(filter fmt,$(COMPLIST)),)
    $(warning ERROR: Please remove FMT_NOT_PRESENT from CUSTOM_OPTION when fmt module is defined in COMPLIST)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifneq ($(filter MULTIPLE_BINARY_FILES,$(CUSTOM_OPTION)),)
  $(warning ERROR: Please remove invalid compile optoin MULTIPLE_BINARY_FILES from CUSTOM_OPTION and set feature option MULTIPLE_BINARY_FILES as TRUE!)
  DEPENDENCY_CONFLICT = TRUE
endif

ifdef SIP_SUPPORT
  ifneq ($(strip $(SIP_SUPPORT)),FALSE)
    COMMINCDIRS   += applib\inet\engine\include
    COMMINCDIRS   += applib\inet\app\include
  endif
endif

ifdef XDM_SUPPORT
  ifneq ($(strip $(XDM_SUPPORT)),FALSE)
       COMMINCDIRS  +=	ps\xdm\include
  endif
endif

ifdef VOIP_SUPPORT
  ifneq ($(strip $(VOIP_SUPPORT)),FALSE)
       COMMINCDIRS  +=	ps\voip\include
       COMMINCDIRS  +=	ps\saf\include
  endif
endif

COMMINCDIRS += custom\common\$(strip $(MMI_BASE))
CUS_REL_BASE_COMP += custom\common\$(strip $(MMI_BASE))

ifeq ($(strip $(call Upper,$(PROJECT))),GSM)
  CUS_REL_FILES_LIST   +=  custom\common\custom_gprs_pdp_default_qos_config.h
endif

COMMINCDIRS	+= interface\wifi
COMMINCDIRS += interface\wmt

COMMINCDIRS  += plutommi\MMI\UnifiedMessage\UnifiedMessageInc
COMMINCDIRS  += plutommi\Service\Inc
COMMINCDIRS  += plutommi\Service\UmSrv
COMMINCDIRS   += venusmmi\framework\ui_core\base
COMMINCDIRS   += plutommi\MtkApp\DLAgent\DLAgentInc
COMMINCDIRS   += plutommi\mtkapp\CentralConfigAgent\CentralConfigAgentInc

ISP_NOT_SUPPORT_PLATFORM = MT6223 MT6223P MT6205B
ifdef ISP_SUPPORT
  ifeq ($(strip $(ISP_SUPPORT)),TRUE)
    ifneq ($(filter $(strip $(PLATFORM)),$(ISP_NOT_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does NOT support ISP) 
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

MP4_CODEC_NOT_SUPPORT_PLATFORM = MT6223 MT6223P MT6205B

ifdef MP4_ENCODE
  ifeq ($(strip $(MP4_ENCODE)),TRUE)
    ifneq ($(filter $(strip $(PLATFORM)),$(MP4_CODEC_NOT_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does NOT support $(strip $(MP4_ENCODE)))  
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef MP4_DECODE
  ifeq ($(strip $(MP4_DECODE)),TRUE)
    ifneq ($(filter $(strip $(PLATFORM)),$(MP4_CODEC_NOT_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does NOT support $(strip $(MP4_DECODE))) 
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef MP4_ENCODE
  ifeq ($(strip $(MP4_ENCODE)),TRUE)
    ifdef ISP_SUPPORT
      ifeq ($(strip $(ISP_SUPPORT)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,ISP_SUPPORT,MP4_ENCODE)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifneq ($(strip $(AMR_CODEC)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,AMR_CODEC,MP4_ENCODE)
        DEPENDENCY_CONFLICT = TRUE
    endif       
    ifneq ($(strip $(MP4_DECODE)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,MP4_DECODE,MP4_ENCODE)
        DEPENDENCY_CONFLICT = TRUE
    endif    
  endif
endif

ifdef MP4_DECODE
  ifeq ($(strip $(MP4_DECODE)),TRUE)
    ifneq ($(strip $(AAC_DECODE)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,AAC_DECODE,MP4_DECODE)
        DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

RAW_SENSOR_NOT_SUPPORT_PLATFORM = MT6223 MT6223P MT6205B MT6225 MT6235 MT6235B
YUV_SENSOR_NOT_SUPPORT_PLATFORM = MT6223 MT6223P MT6205B

ifdef ISP_SUPPORT
  ifeq ($(strip $(ISP_SUPPORT)),TRUE)
    ifeq ($(strip $(SENSOR_TYPE)),RAW)
      ifeq ($(filter $(strip $(PLATFORM)),$(RAW_SENSOR_NOT_SUPPORT_PLATFORM)),)
        ifdef MP4_ENCODE
          ifeq ($(strip $(MP4_ENCODE)),NONE)
            $(call DEP_ERR_ONA_OR_OFFB,MP4_ENCODE,ISP_SUPPORT)
            DEPENDENCY_CONFLICT = TRUE
          endif # ifeq ($(strip $(MP4_ENCODE)),NONE)
        endif
        ifdef MP4_DECODE
          ifeq ($(strip $(MP4_DECODE)),NONE)
            $(call DEP_ERR_ONA_OR_OFFB,MP4_DECODE,ISP_SUPPORT)
            DEPENDENCY_CONFLICT = TRUE
          endif # ifeq ($(strip $(MP4_DECODE)),NONE)
        endif
      endif
    endif # ifeq ($(strip $(SENSOR_TYPE)),RAW)
  endif # ifeq ($(strip $(ISP_SUPPORT)),TRUE)
endif # ifdef ISP_SUPPORT

ifneq ($(strip $(SENSOR_TYPE)),RAW)
  ifeq ($(strip $(AF_SUPPORT)),TRUE)
    $(call DEP_ERR_SETA_OR_OFFB,SENSOR_TYPE,RAW,AF_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef SENSOR_TYPE
  ifneq ($(strip $(SENSOR_TYPE)),NONE)
    ifeq ($(strip $(PLATFORM)),MT6223P)
      ifneq ($(strip $(SENSOR_TYPE)),DIRECT)
        $(warning ERROR: MT6223P only supports SENSOR_TYPE=DIRECT, please change SENSOR_TYPE value) 
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifeq ($(strip $(CMOS_SENSOR)),NONE)
         $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR,SENSOR_TYPE)
         DEPENDENCY_CONFLICT = TRUE
    endif

    ifeq ($(strip $(SENSOR_TYPE)),RAW)
      ifneq ($(strip $(ISP_SUPPORT)),TRUE)
        $(call DEP_ERR_SETA_OR_ONB,SENSOR_TYPE,non RAW,ISP_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      else
        ifneq ($(filter $(strip $(PLATFORM)),$(RAW_SENSOR_NOT_SUPPORT_PLATFORM)),)
          $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does NOT support SENSOR_TYPE=$(strip $(SENSOR_TYPE))) 
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif # ifeq ($(strip $(SENSOR_TYPE)),RAW)
    ifeq ($(strip $(SENSOR_TYPE)),YUV)
      ifneq ($(strip $(ISP_SUPPORT)),TRUE)
        $(call DEP_ERR_SETA_OR_ONB,SENSOR_TYPE,non YUV,ISP_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      else
        ifneq ($(filter $(strip $(PLATFORM)),$(YUV_SENSOR_NOT_SUPPORT_PLATFORM)),)
          $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does NOT support SENSOR_TYPE=$(strip $(SENSOR_TYPE))) 
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif #ifeq ($(strip $(SENSOR_TYPE)),YUV)

    ifeq ($(strip $(SENSOR_TYPE)),DIRECT)
      ifneq ($(strip $(ISP_SUPPORT)),FALSE)
         $(call DEP_ERR_SETA_OR_OFFB,SENSOR_TYPE,non DIRECT,ISP_SUPPORT)
         DEPENDENCY_CONFLICT = TRUE
      endif
      ifneq ($(strip $(PLATFORM)),MT6223P)
         $(warning ERROR: Only MT6223P supports SENSOR_TYPE = DIRECT) 
         DEPENDENCY_CONFLICT = TRUE
      endif
      6223_SUPPORT_LCD_SIZE = 240X320 176X220 128X160 128X128 
      ifeq ($(filter $(call Upper,$(strip $(MAIN_LCD_SIZE))),$(6223_SUPPORT_LCD_SIZE)),)
        $(warning ERROR: $(strip $(MAIN_LCD_SIZE)) only supports $(6223_SUPPORT_LCD_SIZE) when CMOS_SENSOR is enabled) 
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif #ifeq ($(strip $(SENSOR_TYPE)),DIRECT)
  else
    ifneq ($(strip $(CMOS_SENSOR)),NONE)
         $(call DEP_ERR_ONA_OR_OFFB,SENSOR_TYPE,CMOS_SENSOR)
         DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(ISP_SUPPORT)),FALSE)
       $(call DEP_ERR_ONA_OR_OFFB,SENSOR_TYPE,ISP_SUPPORT)
       DEPENDENCY_CONFLICT = TRUE
    endif
  endif # ifneq ($(strip $(SENSOR_TYPE)),NONE)
endif# ifdef SENSOR_TYPE

COMMINCDIRS	  += interface\drv_def
COMMINCDIRS	  += interface\meta

ifdef RTSP_SUPPORT
  ifneq ($(strip $(RTSP_SUPPORT)),FALSE)
       COMMINCDIRS  +=	ps\rtsp\include
  endif
endif


ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
   CUSTOM_COMMINC +=  lcmmi\mmi\Inc
   CUSTOM_COMMINC += lcmmi\mmi\Inc\MenuID
else
   CUSTOM_COMMINC   +=  plutommi\MMI\Inc plutommi\Framework\Interface
   CUSTOM_COMMINC   +=  plutommi\MMI\Inc\MenuID
   CUSTOM_COMMINC   +=  plutommi\Framework\CommonFiles\commoninc
   CUSTOM_COMMINC   +=  plutommi\Framework\CommonFiles\commoninc\depreciation
   CUSTOM_COMMINC   +=  applib\mem\include
endif


ifdef OPTR_SPEC
  ifneq ($(strip $(OPTR_SPEC)),NONE)
    COMMINCDIRS  += operator\$(strip $(word 1,$(subst _, ,$(OPTR_SPEC))))\$(strip $(word 2,$(subst _, ,$(OPTR_SPEC))))\plutommi
    COMMINCDIRS  += operator\$(strip $(word 1,$(subst _, ,$(OPTR_SPEC))))\common\plutommi
    COMMINCDIRS  += operator\$(strip $(word 1,$(subst _, ,$(OPTR_SPEC))))\common\venusmmi
    COMMINCDIRS  += operator\$(strip $(word 1,$(subst _, ,$(OPTR_SPEC))))\$(strip $(word 2,$(subst _, ,$(OPTR_SPEC))))\plutommi\$(strip $(word 3,$(subst _, ,$(OPTR_SPEC))))
    COMMINCDIRS  += operator\$(strip $(word 1,$(subst _, ,$(OPTR_SPEC))))\$(strip $(word 2,$(subst _, ,$(OPTR_SPEC))))\plutommi\$(strip $(word 3,$(subst _, ,$(OPTR_SPEC))))\custom\app
    COMMINCDIRS  += operator\$(strip $(word 1,$(subst _, ,$(OPTR_SPEC))))\$(strip $(word 2,$(subst _, ,$(OPTR_SPEC))))\plutommi\$(strip $(word 3,$(subst _, ,$(OPTR_SPEC))))\custom\common
  endif
endif

# ifdef SYNCML_DM_SUPPORT
#  ifneq ($(strip $(SYNCML_DM_SUPPORT)),FALSE)
#       COMMINCDIRS  +=  dm\task\inc 
#       COMMINCDIRS  +=  dm\wrapper\inc 
#  endif
# endif

ifdef SYNCML_DM_SUPPORT
  ifeq ($(strip $(SYNCML_DM_SUPPORT)),INSIGNIA_DM)
       COMMINCDIRS  +=	vendor\dm\signia\adaptation\task\inc
       COMMINCDIRS  +=	vendor\dm\signia\adaptation\wrapper\inc
       COMP_TRACE_DEFS   += vendor\dm\signia\adaptation\task\inc\dm_trc.h
  endif   
endif

ifdef FOTA_ENABLE
  ifneq ($(strip $(FOTA_ENABLE)),NONE)
    COMMINCDIRS    +=	custom\drv\misc_drv\$(strip $(BOARD_VER))
    COMMINCDIRS    +=	custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen
  endif
endif

COMMINCDIRS	+= interface\GIS

COMMINCDIRS += interface\GPS

ifdef GPS_SUPPORT
  ifneq ($(strip $(GPS_SUPPORT)),NONE)
     COMP_TRACE_DEFS += gps\inc\gps_trc.h
  endif
endif

ifdef BT_GPS_SUPPORT
  ifneq ($(strip $(BT_GPS_SUPPORT)),FALSE)
     COMP_TRACE_DEFS += gps\inc\gps_trc.h
  endif
endif

COMMINCDIRS	+= ps\interfaces\asn\rr\include 

COMMINCDIRS  +=  drv\display\include
COMMINCDIRS  +=  drv\graphics\include
COMMINCDIRS  +=  drv\graphics\jpeg_codec\inc
COMMINCDIRS  +=  drv\idp\include
COMMINCDIRS  +=  drv\idp\include\legacy\idp_hw
COMMINCDIRS  +=  image_codec\common\include
COMMINCDIRS  +=  image_codec\sw_jpeg_core\inc

ifdef SECLIB_SUPPORT
  ifeq ($(strip $(SECLIB_SUPPORT)), BASIC)
    COMP_TRACE_DEFS += security\seclib\include\seclib_trc.h
  endif
  ifeq ($(strip $(SECLIB_SUPPORT)), PKI)
    COMP_TRACE_DEFS += security\seclib\include\seclib_trc.h
    COMP_TRACE_DEFS += security\openssl\adaptation\system\include\ossl_os_adp_trc.h
    COMP_TRACE_DEFS += security\openssl\adaptation\system\include\ossl_crypto_trc.h
    COMP_TRACE_DEFS += security\openssl\adaptation\system\include\ossl_pki_trc.h
    COMP_TRACE_DEFS += security\openssl\adaptation\pki\include\ossl_pki_adp_trc.h
  endif
endif

ifdef SSL_SUPPORT
  ifneq ($(strip $(SSL_SUPPORT)), NONE)
    COMMINCDIRS     +=  interface\security
    COMMINCDIRS     +=  applib\misc\include
    COMMINCDIRS     +=  security\certman\include
    COMMINCDIRS     +=  plutommi\mmi\CertificateManager\CertificateManagerMMIInc
    COMP_TRACE_DEFS += security\certman\include\certman_trc.h
  endif
endif

ifdef SOCKET_SSL_SUPPORT
  ifeq ($(strip $(SOCKET_SSL_SUPPORT)), TRUE)
    COMMINCDIRS     += interface\security
    COMP_TRACE_DEFS += security\tls\include\tls_trc.h
  endif
endif

ifneq ($(call Upper,$(strip $(PROJECT))),BASIC)
  COMP_TRACE_DEFS += drv\include\drv_trc.h
endif

ifneq ($(call Upper,$(strip $(PROJECT))),MEUT)
  COMP_TRACE_DEFS += drv\include\drv_trc.h
endif

COMMINCDIRS   += venusmmi\pluto_adapter\ShellApp\panel\ImageViewer
COMMINCDIRS   += drv\graphics\png_codec\inc

# -----------------------------
# Custom Options
# -----------------------------
ifneq ($(filter $(strip $(PLATFORM)),$(UL1_HS_PLATFORM)),)
CUSTOM_COMMINC += ul1_hs\ul1d
else
CUSTOM_COMMINC += ul1\ul1d
endif
CUSTOM_COMMINC += media\camera_v2\include
##COMMINCDIRS    += $(DIR_ARMINC) $(CUSTOM_COMMINC)
COMMINCDIRS    +=  $(CUSTOM_COMMINC)

# *************************************************************************
# Component Compile Options
# *************************************************************************
# -----------------------------
# Common Options
# -----------------------------
CUSTOM_OPTION := $(filter-out $(REMOVE_CUSTOM_OPTION),$(CUSTOM_OPTION))

COM_DEFS    = $(CUSTOM_OPTION)

ifdef OPTR_SPEC
  ifneq ($(strip $(OPTR_SPEC)),NONE)
    COM_DEFS    += $(OPTR_DEFS)
  endif
endif

ifndef FLAVOR
   COM_DEFS    += __FLAVOR_NOT_PRESENT__
endif

ifdef FLAVOR
  ifneq ($(strip $(FLAVOR)),NONE)
    COM_DEFS    += __FLAVOR_$(strip $(FLAVOR))__
  else
    COM_DEFS    += __FLAVOR_NOT_PRESENT__
  endif
endif


ifeq ($(strip $(IC_TEST_TYPE)),IC_BURNIN_TEST)
  ifneq ($(strip $(KAL_DEDUG_AND_TRACE_LEVEL)), RELEASE_KAL)
  $(warning ERROR: Please set KAL_DEDUG_AND_TRACE_LEVEL=RELEASE_KAL when  IC_TEST_TYPE = IC_BURNIN_TEST ) 
  DEPENDENCY_CONFLICT = TRUE
  endif
endif

DUMMY_SCATTER_ENABLE_PLATFORM = MT6252
ifeq ($(filter $(strip $(PLATFORM)),$(DUMMY_SCATTER_ENABLE_PLATFORM)),)
  ifeq ($(strip $(DUMMY_SCATTER_ENABLE)),TRUE)
    $(warning ERROR: DUMMY_SCATTER_ENABLE can only be enabled when PLATFORM is $(DUMMY_SCATTER_ENABLE_PLATFORM))
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(DUMMY_SCATTER_ENABLE)),TRUE)
  ifeq ($(strip $(DEMO_PROJECT)),TRUE)
    $(warning ERROR: DUMMY_SCATTER_ENABLE cannot be enabled when DEMO_PROJECT=TRUE)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifdef NAND_FLASH_BOOTING
    ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
      $(warning ERROR: DUMMY_SCATTER_ENABLE cannot be enabled when NAND_FLASH_BOOTING is not NONE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef KAL_TRACE_OUTPUT
  ifeq ($(strip $(KAL_TRACE_OUTPUT)),NONE)
    COM_DEFS += MODULE_TRACE_OFF
  endif
  ifeq ($(strip $(KAL_TRACE_OUTPUT)),CUST_PARTIAL)
    COM_DEFS += MODULE_TRACE_OFF
  endif
endif

ifdef KAL_DEDUG_AND_TRACE_LEVEL
  ifeq ($(strip $(KAL_DEDUG_AND_TRACE_LEVEL)),NORMAL_DEBUG_KAL)
    COM_DEFS += DEBUG_KAL DEBUG_BUF2 DEBUG_ITC
     DEP_DEBUG_COMPILE_OPTION =DEBUG_KAL DEBUG_BUF2 DEBUG_ITC
     ENABLED_DEBUG_COMPILE_OPTION = $(sort $(filter $(strip $(DEP_DEBUG_COMPILE_OPTION)),$(CUSTOM_OPTION)))
  endif
  ifeq ($(strip $(KAL_DEDUG_AND_TRACE_LEVEL)),SLIM_DEBUG_KAL)
    COM_DEFS += DEBUG_KAL DEBUG_BUF1
    DEP_DEBUG_COMPILE_OPTION = DEBUG_KAL DEBUG_BUF1
    ENABLED_DEBUG_COMPILE_OPTION = $(sort $(filter $(strip $(DEP_DEBUG_COMPILE_OPTION)),$(CUSTOM_OPTION)))
  endif
# dependency rule for KAL,BUFFER & ITC debug compile options
ifneq ($(strip $(ENABLED_DEBUG_COMPILE_OPTION)),)
  ifneq ($(strip $(ENABLED_DEBUG_COMPILE_OPTION)),$(sort $(strip $(DEP_DEBUG_COMPILE_OPTION))))
    DISABLED_DEBUG_COMPILE_OPTION = $(filter-out $(strip $(ENABLED_DEBUG_COMPILE_OPTION)),$(strip $(DEP_DEBUG_COMPILE_OPTION)))
    $(warning ERROR: PLEASE turn on $(DISABLED_DEBUG_COMPILE_OPTION) or turn off $(ENABLED_DEBUG_COMPILE_OPTION))
    DEPENDENCY_CONFLICT = TRUE
  endif
endif
# end
  ifeq ($(strip $(KAL_DEDUG_AND_TRACE_LEVEL)),RELEASE_KAL)
    COM_DEFS += RELEASE_KAL
    DEP_DEBUG_COMPILE_OPTION =
    ENABLED_DEBUG_COMPILE_OPTION = $(sort $(filter $(strip $(DEP_DEBUG_COMPILE_OPTION)),$(CUSTOM_OPTION)))
  endif
endif


ifeq ($(strip $(RTOS)),NUCLEUS)
  COM_DEFS += KAL_ON_NUCLEUS
  ifeq ($(strip $(RTOS_DEBUG)),TRUE)
     COM_DEFS += NU_DEBUG
  else
     COM_DEFS += NU_NO_ERROR_CHECKING
  endif
endif

ifeq ($(strip $(RTOS)),NUCLEUS_V2)
  COM_DEFS += KAL_ON_NUCLEUS __NUCLEUS_VERSION_2__
  ifeq ($(strip $(RTOS_DEBUG)),TRUE)
     COM_DEFS += NU_DEBUG
  else
     COM_DEFS += NU_NO_ERROR_CHECKING
  endif
endif

ifeq ($(strip $(RTOS)),THREADX)
  COM_DEFS += KAL_ON_THREADX
  COM_DEFS += TX_ENABLE_IRQ_NESTING TX_DISABLE_NOTIFY_CALLBACKS \
              TX_DISABLE_PREEMPTION_THRESHOLD TX_DISABLE_STACK_FILLING TX_REACTIVE_INLINE
  ifneq ($(strip $(RTOS_DEBUG)),TRUE)
     COM_DEFS += TX_DISABLE_ERROR_CHECKING
  endif
endif

COM_DEFS    += __BLIND_HANDOVER__

COM_DEFS    +=  IDLE_TASK _DEBUG MTK_KAL  __MTK_TARGET__

ifneq ($(strip $(DSP_SOLUTION)),DSP_FCORE4)
  COM_DEFS    +=  IDMA_DOWNLOAD
endif

COM_DEFS    +=  SME_NOT_PRESENT SME_READER_NOT_PRESENT STDC_HEADERS TARGET_BUILD

COM_DEFS    += DEBUG_LEVEL=0

COM_DEFS    += __MSLT__

ifeq ($(strip $(COMPILER)),RVCT)
  COM_DEFS += __RVCT__
endif

ifeq ($(strip $(COMPILER)),ADS)
  COM_DEFS += __ADS__
endif

ifdef OPTR_SPEC
    ifeq ($(strip $(OPTR_SPEC)),NONE)
       COM_DEFS += __OPTR_NONE__
    endif
endif


ifeq ($(strip $(call Upper,$(PROJECT))),BASIC)
  ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
    COM_DEFS +=  EMPTY_MMI
  endif
endif

ifeq ($(strip $(call Upper,$(PROJECT))),MEUT)
  ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
    COM_DEFS +=  EMPTY_MMI
  endif
endif

ifeq ($(strip $(call Upper,$(PROJECT))),L1S)
  ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
    COM_DEFS +=  EMPTY_MMI
  endif
endif

ifdef DEMO_PROJECT
   ifeq ($(strip $(DEMO_PROJECT)),TRUE)
      COM_DEFS   += DEMO_PROJECT
      COM_DEFS   += MTK_INTERNAL_MMI_FEATURES
      COM_DEFS   += __MTK_INTERNAL__
      
      ifneq ($(strip $(WIFI_SUPPORT)),NONE)
         COM_DEFS += WIFI_BLACKLIST 
      endif
      ifneq ($(strip $(WIFI_SUPPORT)),NONE)
           COM_DEFS += WIFI_PORT_TIMER 
      endif
   endif
endif

MMI_SWITCH = $(shell dir .\$(MMIDIR)\Customer\CustResource\$(strip $(CUSTOMER))_MMI\MMI_features_switch$(strip $(CUSTOMER)).h /b 2>nul)
ifdef DEMO_PROJECT
  ifeq ($(strip $(DEMO_PROJECT)),TRUE)
    ifdef MMI_FEATURES_SWITCH
      ifeq ($(strip $(MMI_FEATURES_SWITCH)),FALSE)
        COM_DEFS   += USE_COMMON_MMI_FEATURES_SWITCH
      else
        ifeq ($(words $(strip $(MMI_SWITCH))),0)
          ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
            $(warning ERROR: .\$(MMIDIR)\Customer\CustResource\$(strip $(CUSTOMER))_MMI\MMI_features_switch$(strip $(CUSTOMER)).h shoule exist when MMI_FEATURES_SWITCH is TRUE) 
            DEPENDENCY_CONFLICT = TRUE
          endif
        endif
      endif
    else
      COM_DEFS   += USE_COMMON_MMI_FEATURES_SWITCH
    endif
  endif
endif

ifdef EMPTY_RESOURCE
  ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
    COM_DEFS += __BT_MP_RELEASE__
  endif
endif

MP4_SW_CODEC_V1_PLATFORM = MT6225 MT6235  MT6235B 
MP4_HW_CODEC_V1_PLATFORM = MT6229 MT6238 MT6239 MT6268 MT6268A MT6268T MT6268H
H264_SW_CODEC_V1_PLATFORM = MT6235 MT6235B 
H264_HW_CODEC_V1_PLATFORM = MT6238 MT6239 MT6268 MT6268A MT6268T MT6268H

RV_SW_CODEC_V2_PLATFORM = MT6236 MT6236B MT6253 MT6253E MT6253L MT6253T MT6276 MT6252 MT6252H
MP4_SW_CODEC_V2_PLATFORM = MT6236 MT6236B MT6253 MT6253E MT6253L MT6253T MT6255 MT6252 MT6252H
MP4_HW_CODEC_V2_PLATFORM =  
H264_SW_CODEC_V2_PLATFORM = MT6236 MT6236B MT6253 MT6253E MT6253L MT6253T MT6255 MT6252 MT6252H
H264_HW_CODEC_V2_PLATFORM = 


ADD_VCODEC_TRC_H_TO_COMP_TRACE_DEFS = FALSE

ifdef MP4_DECODE
  ifeq ($(strip $(MP4_DECODE)),TRUE)
    ifneq ($(filter $(strip $(PLATFORM)),$(MP4_SW_CODEC_V2_PLATFORM)),)
        COM_DEFS    += __VIDEO_ARCHI_V2__
        COM_DEFS    += MP4_DECODE
        COM_DEFS    += __MP4_DEC_SW_SUPPORT__
        COM_DEFS    += __MPEG4_DEC_SUPPORT__
        COM_DEFS    += __MPEG4_DEC_SW_SUPPORT__
    endif
    ifneq ($(filter $(strip $(PLATFORM)),$(MP4_SW_CODEC_V1_PLATFORM)),)
        COM_DEFS    += __VIDEO_ARCHI_V1__
        COM_DEFS    += MP4_DECODE
        COM_DEFS    += __MP4_DEC_SW_SUPPORT__
        ADD_VCODEC_TRC_H_TO_COMP_TRACE_DEFS = TRUE
    endif
    ifneq ($(filter $(strip $(PLATFORM)),$(MP4_HW_CODEC_V2_PLATFORM)),)
        COM_DEFS    += __VIDEO_ARCHI_V2__
        COM_DEFS    += MP4_DECODE
        COM_DEFS    += __MP4_DEC_HW_SUPPORT__
        COM_DEFS    += __MPEG4_DEC_SUPPORT__
        COM_DEFS    += __MPEG4_DEC_HW_SUPPORT__
    endif
    ifneq ($(filter $(strip $(PLATFORM)),$(MP4_HW_CODEC_V1_PLATFORM)),)
        COM_DEFS    += __VIDEO_ARCHI_V1__
        COM_DEFS    += MP4_DECODE
        COM_DEFS    += __MP4_DEC_HW_SUPPORT__
    endif
  endif
endif

ifdef MP4_ENCODE
  ifeq ($(strip $(MP4_ENCODE)),TRUE)
    ifneq ($(filter $(strip $(PLATFORM)),$(MP4_SW_CODEC_V2_PLATFORM)),)
        COM_DEFS    += __VIDEO_ARCHI_V2__
        COM_DEFS    += MP4_ENCODE
        COM_DEFS    += __MP4_ENC_SW_SUPPORT__
        COM_DEFS    += __MPEG4_ENC_SUPPORT__
        COM_DEFS    += __MPEG4_ENC_SW_SUPPORT__
    endif
    ifneq ($(filter $(strip $(PLATFORM)),$(MP4_SW_CODEC_V1_PLATFORM)),)
        COM_DEFS    += __VIDEO_ARCHI_V1__
        COM_DEFS    += MP4_ENCODE
        COM_DEFS    += __MP4_ENC_SW_SUPPORT__
        ADD_VCODEC_TRC_H_TO_COMP_TRACE_DEFS = TRUE
    endif
    ifneq ($(filter $(strip $(PLATFORM)),$(MP4_HW_CODEC_V2_PLATFORM)),)
        COM_DEFS    += __VIDEO_ARCHI_V2__
        COM_DEFS    += MP4_ENCODE
        COM_DEFS    += __MP4_ENC_HW_SUPPORT__
        COM_DEFS    += __MPEG4_ENC_SUPPORT__
        COM_DEFS    += __MPEG4_ENC_HW_SUPPORT__
    endif
    ifneq ($(filter $(strip $(PLATFORM)),$(MP4_HW_CODEC_V1_PLATFORM)),)
        COM_DEFS    += __VIDEO_ARCHI_V1__
        COM_DEFS    += MP4_ENCODE
        COM_DEFS    += __MP4_ENC_HW_SUPPORT__
    endif
  endif
endif

ifdef H264_DECODE
  ifeq ($(strip $(H264_DECODE)),TRUE)
    ifneq ($(filter $(strip $(PLATFORM)),$(H264_SW_CODEC_V2_PLATFORM)),)
        COM_DEFS    += __VIDEO_ARCHI_V2__
        COM_DEFS    += H264_DECODE
        COM_DEFS    += __H264_DEC_SW_SUPPORT__
        COM_DEFS    += __H264_DEC_SUPPORT__
    endif
    ifneq ($(filter $(strip $(PLATFORM)),$(H264_SW_CODEC_V1_PLATFORM)),)
        COM_DEFS    += __VIDEO_ARCHI_V1__
        COM_DEFS    += H264_DECODE
        COM_DEFS    += __H264_DEC_SW_SUPPORT__
        ADD_VCODEC_TRC_H_TO_COMP_TRACE_DEFS = TRUE
    endif
    ifneq ($(filter $(strip $(PLATFORM)),$(H264_HW_CODEC_V2_PLATFORM)),)
        COM_DEFS    += __VIDEO_ARCHI_V2__
        COM_DEFS    += H264_DECODE
        COM_DEFS    += __H264_DEC_HW_SUPPORT__
        COM_DEFS    += __H264_DEC_SUPPORT__
    endif
    ifneq ($(filter $(strip $(PLATFORM)),$(H264_HW_CODEC_V1_PLATFORM)),)
        COM_DEFS    += __VIDEO_ARCHI_V1__
        COM_DEFS    += H264_DECODE
        COM_DEFS    += __H264_DEC_HW_SUPPORT__
    endif
  endif
endif

ifeq ($(strip $(H264_ENCODE)),H264_SW)
    ADD_VCODEC_TRC_H_TO_COMP_TRACE_DEFS = TRUE
endif
ifeq ($(strip $(ADD_VCODEC_TRC_H_TO_COMP_TRACE_DEFS)),TRUE)
    COMP_TRACE_DEFS += media\vcodec\include\vcodec_trc.h
endif

ifdef RM_DECODE
  ifeq ($(strip $(RM_DECODE)),TRUE)
    ifneq ($(filter $(strip $(PLATFORM)),$(RV_SW_CODEC_V2_PLATFORM)),)
        COM_DEFS    += __VIDEO_ARCHI_V2__
        COM_DEFS    += __RM_DEC_SUPPORT__
        COM_DEFS    += __RV_DEC_SW_SUPPORT__
    endif
  endif
endif

ifdef GPS_SUPPORT
  ifneq ($(strip $(GPS_SUPPORT)),NONE)
    COM_DEFS    += __GPS_SUPPORT__
    COM_DEFS    += __GPS_USE_UART2__
    COM_DEFS    += __ONLY_ONE_UART__
    COMPLIST    += gps
    ifeq ($(strip $(GPS_SUPPORT)),MT3316)
       COM_DEFS    += __GPS_MT3316__
    endif
    ifeq ($(strip $(GPS_SUPPORT)),MT3326)
       COM_DEFS    += __GPS_MT3326__ __MNL_SUPPORT__
       COMPLIST    += mnl    
       ifeq ($(strip $(COMPILER)),RVCT)
         COMPOBJS    += gps\mnl\lib\MTKNav_rvct.lib
         CUS_REL_OBJ_LIST += gps\mnl\lib\MTKNav_rvct.lib
       else
         COMPOBJS    += gps\mnl\lib\MTKNav.lib
         CUS_REL_OBJ_LIST += gps\mnl\lib\MTKNav.lib
       endif  
       CUS_REL_OBJ_LIST += gps\mnl\lib\MTKNav_WIN32.lib
    endif
    ifeq ($(strip $(EMPTY_RESOURCE)),FALSE)
      CUS_REL_BASE_COMP += gps\mnl make\mnl
    endif
  endif
endif

ifdef BT_GPS_SUPPORT
  ifneq ($(strip $(BT_GPS_SUPPORT)),FALSE)
    COM_DEFS    += __BT_GPS_SUPPORT__
    COMPLIST    += gps
  endif
endif

ifdef OBIGO_FEATURE
  ifneq ($(strip $(OBIGO_FEATURE)),NONE)
    ifneq ($(strip $(WBXML_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,WBXML_SUPPORT,OBIGO_FEATURE)
      DEPENDENCY_CONFLICT = TRUE
    else
      COM_DEFS    += __PROVISIONING_SERVICE_SUPPORT__
      COM_DEFS    += __CCA_SUPPORT__
      ifdef SIM_PROVISIONING
        ifneq ($(strip $(SIM_PROVISIONING)),NONE)
          COM_DEFS    += __SPA_SUPPORT__
          COM_DEFS    += __DTCNT_SIM_PROFILES_SUPPORT__
        endif
        ifeq ($(strip $(SIM_PROVISIONING)),MMSICP)
          COM_DEFS    += __MMSICP_SUPPORT__
        endif
      endif
    endif
  endif
endif

ifdef RSAT_SUPPORT
  ifeq ($(strip $(RSAT_SUPPORT)),MODEM_WITH_RSAT)
    ifneq ($(strip $(MMI_VERSION)),EMPTY_MMI)
      $(call DEP_ERR_SETA_OR_OFFB,MMI_VERSION,EMPTY_MMI,RSAT_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    else
      COM_DEFS    += __RSAT__
    endif
  endif
  ifeq ($(strip $(RSAT_SUPPORT)),MMI_WITH_RSAT)
    COM_DEFS    += __RSAT__
  endif
endif

ifdef UL1D_COSIM
    ifeq ($(strip $(UL1D_COSIM)),TRUE)
        ifeq ($(strip $(UL1D_LOOPBACK)),0)
            $(call DEP_ERR_SETA_OR_OFFB,UL1D_LOOPBACK,non 0,UL1D_COSIM)
            DEPENDENCY_CONFLICT = TRUE
        endif
    endif
endif

# remove COM_DEFS   += __SIM_PLUS__

# *************************************************************************
# Include Java compile settings.
# *************************************************************************
-include make\JAVA_DEF.mak

# *************************************************************************
# Components
# *************************************************************************
# -----------------------------
# Common Components
# -----------------------------



# *************************************************************************
# Component trace definition header files
# *************************************************************************
# -----------------------------
# Common trace
# -----------------------------

ifdef MMI_VERSION

   ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
      COMP_TRACE_DEFS += plutommi\mmi\inc\mmi_conn_app_trc.h 
      COMP_TRACE_DEFS += plutommi\mmi\inc\mmi_common_app_trc.h 
      COMP_TRACE_DEFS += plutommi\mmi\inc\mmi_inet_app_trc.h 
      COMP_TRACE_DEFS += plutommi\mmi\inc\mmi_media_app_trc.h 
      COMP_TRACE_DEFS += plutommi\Framework\Interface\mmi_fw_trc.h
      COMP_TRACE_DEFS += plutommi\Framework\Interface\pluto_fw_trc.h
      COMP_TRACE_DEFS += plutommi\Framework\GDI\GDIInc\gdi_trc.h
   endif
   ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
      COMP_TRACE_DEFS += lcmmi\mmi\inc\mmi_common_app_trc.h 
      COMP_TRACE_DEFS += lcmmi\mmi\inc\mmi_media_app_trc.h 
      COMP_TRACE_DEFS += lcmmi\mmi\inc\mmi_fw_trc.h 
   endif

endif


ifdef EMAIL_SUPPORT
  ifneq ($(strip $(EMAIL_SUPPORT)),NONE)
     COMP_TRACE_DEFS += ps\email\inc\email_trace.h
  endif
endif

ifdef CMUX_SUPPORT
  ifeq ($(strip $(CMUX_SUPPORT)),TRUE)
     COMP_TRACE_DEFS	+= ps\cmux\include\cmux_trc.h
  endif
endif

ifdef SIP_SUPPORT
  ifneq ($(strip $(SIP_SUPPORT)),FALSE)
     COMP_TRACE_DEFS	+= ps\sip\include\sip_trc.h
  endif
endif

ifdef VOIP_SUPPORT
  ifneq ($(strip $(VOIP_SUPPORT)),FALSE)
     COMP_TRACE_DEFS	+= ps\voip\include\voip_trc.h
     COMP_TRACE_DEFS	+= ps\saf\include\saf_trc.h
  endif
endif

ifdef DT_SUPPORT
ifneq ($(strip $(call Upper,$(PROJECT))),L1S)
  ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
    ifneq ($(strip $(call Upper,$(PROJECT))),MEUT)
      ifneq ($(strip $(DT_SUPPORT)),FALSE)
        COMP_TRACE_DEFS	+= ps\dt\include\dt_trc.h
      endif
    endif
  endif
endif
endif

ifndef SMART_PHONE_CORE
  ifeq ($(strip $(DSP_SOLUTION)),DSP_FCORE4)
    COMP_TRACE_DEFS     += l1audio_fc\inc\l1sp_trc.h
  else
    COMP_TRACE_DEFS += l1audio\inc\l1sp_trc.h
  endif
else
  ifneq ($(strip $(SMART_PHONE_CORE)),NONE)
    COMP_TRACE_DEFS += l1audio_sp\l1sp_trc.h
  else
    ifeq ($(strip $(DSP_SOLUTION)),DSP_FCORE4)
      COMP_TRACE_DEFS     += l1audio_fc\inc\l1sp_trc.h
    else
      COMP_TRACE_DEFS += l1audio\inc\l1sp_trc.h
    endif
  endif
endif

COMP_TRACE_DEFS += dp_engine\dp_engine_trc.h

ifdef XDM_SUPPORT
  ifneq ($(strip $(XDM_SUPPORT)),FALSE)
     COMP_TRACE_DEFS	+= ps\xdm\include\xdm_trc.h
  endif
endif

ifdef J2ME_SUPPORT
  ifneq ($(strip $(J2ME_SUPPORT)),NONE)
    COMP_TRACE_DEFS	+= j2me\interface\j2me_trace.h
  endif
endif

ifdef WIFI_SUPPORT
  ifneq ($(strip $(WIFI_SUPPORT)),NONE)
    ifeq ($(strip $(WIFI_SUPPORT)),MT5911)
      COMP_TRACE_DEFS	+= wifi\wndrv\include\os\wndrv_trc.h
    endif
    ifeq ($(strip $(WIFI_SUPPORT)),MT5921)
      COMP_TRACE_DEFS	+= wifi\release\inc\wndrv_trc.h
    endif
    COMP_TRACE_DEFS	+= wifi\dummy_supc\include\supc_trc.h
    COMP_TRACE_DEFS	+= ps\dhcp\include\dhcp_trc.h
  endif
endif

ifdef IPERF_SUPPORT
  ifneq ($(strip $(IPERF_SUPPORT)),NONE)
     COMP_TRACE_DEFS	+= ps\iperf\include\iperf_trc.h
  endif
endif

ifdef BLUETOOTH_SUPPORT
    ifneq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
          COMP_TRACE_DEFS += btadp\include\bluetooth_trc.h
    endif
endif

ifneq ($(strip $(call Upper,$(PROJECT))),L1S)
  ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
    ifneq ($(strip $(call Upper,$(PROJECT))),MEUT)
      COMP_TRACE_DEFS   += ps\ems\include\ems_trc.h
    endif
  endif
endif

ifdef RTSP_SUPPORT
  ifneq ($(strip $(RTSP_SUPPORT)),FALSE)
     COMP_TRACE_DEFS	+= ps\rtsp\include\rtsp_trc.h
  endif
endif

ifdef OBIGO_FEATURE
  ifneq ($(strip $(OBIGO_FEATURE)),NONE)
      ifndef UNIFIED_PUSH_FEATURES
          $(call DEP_ERR_ONA_OR_OFFB,UNIFIED_PUSH_FEATURES,OBIGO_FEATURE)
          DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(strip $(UNIFIED_PUSH_FEATURES)),NONE)
          $(call DEP_ERR_ONA_OR_OFFB,UNIFIED_PUSH_FEATURES,OBIGO_FEATURE)
          DEPENDENCY_CONFLICT = TRUE
      endif
      COMMINCDIRS      += plutommi\MMI\browserapp\profile\profileInc
  endif
endif
ifdef BROWSER_SUPPORT
  ifeq ($(strip $(BROWSER_SUPPORT)),OBIGO_Q05A)
     COMP_TRACE_DEFS  += vendor\wap\obigo_q05a\adaptation\integration\include\wap_trc.h
  endif
  ifeq ($(strip $(BROWSER_SUPPORT)),OPERA_V10)
     COMP_TRACE_DEFS  += vendor\opera\browser\adaptation\inc\opera_adp_trc.h
  endif
endif

ifdef OBIGO_FEATURE
  ifneq ($(strip $(OBIGO_FEATURE)), NONE)
    ifneq ($(strip $(BROWSER_SUPPORT)), OBIGO_Q05A)
      COM_DEFS += Q03C_IND_MOD_ARCH_SUPPORT
      COM_DEFS += OBIGO_Q03C
      COMPLIST += obigo03cadp obigo03cfwlib obigo03cstkadp obigo03cstklib obigo03cfwadp
      COMP_TRACE_DEFS += vendor\framework\obigo_Q03C\adaptation\integration\include\trc\wps_trc.h
      COMP_TRACE_DEFS  += vendor\wap\obigo_Q03C\adaptation\integration\include\wap_trc.h                
      ifdef LOW_COST_SUPPORT
        ifneq ($(strip $(LOW_COST_SUPPORT)),NONE)
          ifneq ($(strip $(LOW_COST_SUPPORT)),FALSE)
            COM_DEFS    +=  SLIM_WAP_MMS
          endif
        endif
      endif
    endif
    ifeq ($(strip $(OBIGO_FEATURE)), WAP2_SEC)
      ifeq ($(strip $(BROWSER_SUPPORT)), NONE)
        ifneq ($(strip $(SOCKET_SSL_SUPPORT)),TRUE)
          $(call DEP_ERR_SETA_OR_ONB,OBIGO_FEATURE, WAP2, SOCKET_SSL_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
  endif
endif

ifdef SSL_SUPPORT
  ifeq ($(strip $(SSL_SUPPORT)),MTK_SSL_CIC)
     COMP_TRACE_DEFS += vendor_sec\security\certicom\adaptation\ssl\include\sslplus5_trc.h
  endif

  ifeq ($(strip $(SSL_SUPPORT)),SSL_CIC_LIB)
     COMP_TRACE_DEFS += vendor_sec\security\certicom\adaptation\ssl\include\sslplus5_trc.h
  endif

  ifeq ($(strip $(SSL_SUPPORT)),OPENSSL)
     COMP_TRACE_DEFS += security\openssl\adaptation\system\include\ossl_ssl_trc.h
     COMP_TRACE_DEFS += security\openssl\adaptation\ssl\include\ossl_ssladp_trc.h     
  endif

  ifeq ($(strip $(SSL_SUPPORT)),OPENSSL_MTK)
     COMP_TRACE_DEFS += security\openssl\adaptation\system\include\ossl_ssl_trc.h
     COMP_TRACE_DEFS += security\openssl\adaptation\ssl\include\ossl_ssladp_trc.h     
  endif
endif

ifneq ($(strip $(call Upper,$(PROJECT))),L1S)
  ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
    ifneq ($(strip $(call Upper,$(PROJECT))),MEUT)
      ifneq ($(filter __MTK_3G_MRAT_ARCH__,$(strip $(COM_DEFS))),)
        COMP_TRACE_DEFS   +=    ps\rr2\mpal\include\mpal_trace.h
      else
        ifeq ($(strip $(call Upper,$(PROJECT))),GPRS)
          COMP_TRACE_DEFS   +=    ps\rr\mpal\include\mpal_trace.h
        endif
        ifeq ($(strip $(call Upper,$(PROJECT))),GSM)
          COMP_TRACE_DEFS   +=    ps\rr\mpal\include\mpal_trace.h
        endif
      endif
    endif
  endif
endif

ifeq ($(strip $(call Upper,$(PROJECT))),GSM)
  ifneq ($(filter __MTK_3G_MRAT_ARCH__,$(strip $(COM_DEFS))),)
    L1_TMD_FILES   +=    l1_dm\common\l1D_EDGE_trace.tmd
  else
    L1_TMD_FILES   +=    l1\common\l1D_EDGE_trace.tmd
  endif
endif

ifneq ($(filter __MTK_3G_MRAT_ARCH__,$(strip $(COM_DEFS))),)
  L1_TMD_FILES   +=   l1_dm\common\L1D3_Trace.tmd \
                      l1_dm\common\l1c3_Trace.tmd \
                      l1_dm\common\l1c4_Trace.tmd
else
  ifeq ($(call Upper,$(strip $(L1_WCDMA))),TRUE)
    L1_TMD_FILES   +=   l1_dm\common\L1D3_Trace.tmd \
                        l1_dm\common\l1c3_Trace.tmd \
                        l1_dm\common\l1c4_Trace.tmd 
  else
    L1_TMD_FILES   +=   l1\common\L1D3_Trace.tmd \
                        l1\common\l1c3_Trace.tmd \
                        l1\common\l1c4_Trace.tmd
  endif
endif

# ---------------------------------------------------------------
# The followings are global options from $(Customer)_$(Project).bld
# ---------------------------------------------------------------
# Platform Options
COM_DEFS_FOR_MT6208  = MT6208
COM_DEFS_FOR_MT6205  = MT6205 __HW_DIVIDER__
COM_DEFS_FOR_MT6205B = MT6205B __HW_DIVIDER__
COM_DEFS_FOR_FPGA    = FPGA
COM_DEFS_FOR_MT6218  = MT6218  __HW_DIVIDER__
COM_DEFS_FOR_MT6218B = MT6218B __HW_DIVIDER__ MT6218B_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6217  = MT6217 __HW_DIVIDER__ MT6217_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6219  = MT6219 __HW_DIVIDER__ MT6219_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6228  = MT6228 __HW_DIVIDER__ MT6228_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6229  = MT6229 __HW_DIVIDER__ MT6229_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6235  = MT6235 __HW_DIVIDER__ MT6235_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6235B = MT6235B __HW_DIVIDER__ MT6235B_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6236  = MT6236 __HW_DIVIDER__ MT6236_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6236B = MT6236B __HW_DIVIDER__ MT6236B_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6238  = MT6238 __HW_DIVIDER__ MT6238_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6239  = MT6239 __HW_DIVIDER__ MT6239_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6230  = MT6230 __HW_DIVIDER__ MT6230_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6227  = MT6227 __HW_DIVIDER__ MT6227_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6227D = MT6227D __HW_DIVIDER__ MT6227D_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6226  = MT6226 __HW_DIVIDER__ MT6226_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6226D = MT6226D __HW_DIVIDER__ MT6226D_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6226M = MT6226M __HW_DIVIDER__ MT6226M_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6225  = MT6225 __HW_DIVIDER__ MT6225_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6223  = MT6223 __HW_DIVIDER__ MT6223_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6223P  = MT6223P __HW_DIVIDER__ MT6223P_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6268T = MT6268T __HW_DIVIDER__ MT6268T_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6268H = MT6268H __HW_DIVIDER__ MT6268H_$(strip $(CHIP_VER))
COM_DEFS_FOR_TK6516  = TK6516 __HW_DIVIDER__ TK6516_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6516  = MT6516 __HW_DIVIDER__ MT6516_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6516AP  = MT6516AP __HW_DIVIDER__ MT6516AP_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6268A = MT6268A __HW_DIVIDER__ MT6268A_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6268  = MT6268 __HW_DIVIDER__ MT6268_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6270A  = MT6270A __HW_DIVIDER__ MT6270A_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6253T = MT6253T __HW_DIVIDER__ MT6253T_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6253 = MT6253 __HW_DIVIDER__ MT6253_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6253E = MT6253E __HW_DIVIDER__ MT6253E_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6253L = MT6253L __HW_DIVIDER__ MT6253L_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6252 = MT6252 __HW_DIVIDER__ MT6252_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6252H = MT6252H __HW_DIVIDER__ MT6252H_$(strip $(CHIP_VER))

COM_DEFS_FOR_PLATFORM =  COM_DEFS_FOR_$(strip $(PLATFORM))
ifdef $(COM_DEFS_FOR_PLATFORM)
   COM_DEFS		+=  $(COM_DEFS_FOR_$(strip $(PLATFORM)))
else
   $(warning ERROR: [COM_DEFS_FOR_$(strip $(PLATFORM))] was not defined)
   DEPENDENCY_CONFLICT = TRUE
endif

# RF Module Options
# Move to project.mak except EVB
COM_DEFS_FOR_BRIGHT4                  = BRIGHT4_RF BRIGHT4_EVB
COM_DEFS_FOR_EUROPA                   = MT6129C_RF EUROPA_EVB
COM_DEFS_FOR_FOUNTAIN2                = MT6119C_RF FOUNTAIN2_EVB  FOUNTAIN2_RF
COM_DEFS_FOR_MT6129C                  = MT6129C_RF MT6129C_EVB
COM_DEFS_FOR_MT6129D                  = MT6129D_RF MT6129D_EVB
COM_DEFS_FOR_MT6139B                  = MT6139B_RF MT6139B_EVB
COM_DEFS_FOR_MT6139C                  = MT6139C_RF MT6139C_EVB
COM_DEFS_FOR_MT6139E                  = MT6139E_RF MT6139E_EVB
COM_DEFS_FOR_MT6140A                  = MT6140A_RF MT6140A_EVB
COM_DEFS_FOR_MT6140C                  = MT6140C_RF MT6140C_EVB
COM_DEFS_FOR_MT6140D                  = MT6140D_RF MT6140D_EVB
COM_DEFS_FOR_SKY74117                 = SKY74117_RF SKY74117_EVB
COM_DEFS_FOR_SKY74137                 = SKY74137_RF SKY74137_EVB
COM_DEFS_FOR_SKY74045                 = SKY74045_RF SKY74045_EVB
COM_DEFS_FOR_BRIGHT5P                 = BRIGHT5P_RF BRIGHT5P_EVB
COM_DEFS_FOR_AERO2                    = AERO2_RF   AERO2_EVB
COM_DEFS_FOR_SONY_CXA3359             = SONY_CXA3359_RF SONY_CXA3359_EVB
COM_DEFS_FOR_SMARTI3G                 = SMARTI3G_RF SMARTI3G_EVB
COM_DEFS_FOR_MTKSOC1                  = MTKSOC1_RF MTKSOC1_EVB
COM_DEFS_FOR_MT6253ELRF               = MT6253ELRF_RF MT6253ELRF_EVB
COM_DEFS_FOR_MT6255RF                 = MT6255RF_RF MT6255RF_EVB
COM_DEFS_FOR_MT6251RF                 = MT6251RF_RF MT6251RF_EVB
COM_DEFS_FOR_MT6160                   = MT6160_RF MT6160_EVB
COM_DEFS_FOR_AD6546                   = AD6546_RF AD6546_EVB
COM_DEFS_FOR_TECHFAITH68_DEMO_MT6160   = MT6160_RF TECHFAITH68_DEMO_MT6160
COM_DEFS_FOR_TECHFAITH68_DEMO_AD6546   = AD6546_RF TECHFAITH68_DEMO_AD6546

# For Customer projects.
COM_DEFS_FOR_MT6140_CUSTOM = MT6140D_RF MT6140_CUSTOM
COM_DEFS_FOR_MT6139_CUSTOM = MT6139E_RF MT6139_CUSTOM
COM_DEFS_FOR_MT6129_CUSTOM = MT6129D_RF MT6129_CUSTOM
COM_DEFS_FOR_AD6548_CUSTOM = AD6548_RF AD6548_CUSTOM
COM_DEFS_FOR_AD6546_CUSTOM = AD6546_RF AD6546_CUSTOM
COM_DEFS_FOR_SKY74137_CUSTOM = SKY74137_RF SKY74137_CUSTOM
COM_DEFS_FOR_UNICORN53_DEMO_MTKSOC1 = MTKSOC1_RF UNICORN53_DEMO_MTKSOC1
COM_DEFS_FOR_UNICORN53V2_DEMO_MTKSOC1 = MTKSOC1_RF UNICORN53V2_DEMO_MTKSOC1
COM_DEFS_FOR_UNICORN53V3_DEMO_MTKSOC1 = MTKSOC1_RF UNICORN53V3_DEMO_MTKSOC1
COM_DEFS_FOR_UNICORN53V4_DEMO_MTKSOC1 = MTKSOC1_RF UNICORN53V4_DEMO_MTKSOC1

CUS_REL_BASE_COMP += custom\l1_rf\MT6140_CUSTOM custom\l1_rf\MT6139_CUSTOM \
                     custom\l1_rf\MT6129_CUSTOM custom\l1_rf\SKY74137_CUSTOM \
                     custom\l1_rf\AD6548_CUSTOM custom\l1_rf\AD6546_CUSTOM

COM_DEFS_FOR_RF_MODULE =  COM_DEFS_FOR_$(strip $(RF_MODULE))
ifdef $(COM_DEFS_FOR_RF_MODULE)
   COM_DEFS		+=  $(COM_DEFS_FOR_$(strip $(RF_MODULE)))
else
   $(warning ERROR: [COM_DEFS_FOR_$(strip $(RF_MODULE))] was not defined)
    DEPENDENCY_CONFLICT = TRUE
endif

ifdef UMTS_RF_MODULE
  COM_DEFS_FOR_RF_MODULE =  COM_DEFS_FOR_$(strip $(UMTS_RF_MODULE))
  ifdef $(COM_DEFS_FOR_RF_MODULE)
    COM_DEFS  +=  $(COM_DEFS_FOR_$(strip $(UMTS_RF_MODULE)))
  else
    $(warning ERROR: [COM_DEFS_FOR_$(strip $(UMTS_RF_MODULE))] was not defined)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

# check AFC_VCXO_TYPE matches RF_MODULE
ifdef AFC_VCXO_TYPE
  ifdef RF_MODULE
    VCXO_PLATFORM = MT6140C MT6140D MT6139B MT6139C MT6139E
    ifneq ($(filter $(strip $(RF_MODULE)),$(VCXO_PLATFORM)),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCXO)
        ifneq ($(strip $(PLATFORM)),MT6268A)
          ifneq ($(strip $(PLATFORM)),MT6268)
            ifneq ($(strip $(PLATFORM)),MT6270A)
              $(warning ERROR: MT6139/MT6140 series RF_MODULE project must set AFC_VCXO_TYPE = VCXO )
              DEPENDENCY_CONFLICT = TRUE
            endif
          endif
        endif
      endif
    endif
        
    ifneq ($(findstring MT6129D,$(strip $(RF_MODULE))),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCTCXO)
        $(warning WARNING MT6129D series RF_MODULE project must set AFC_VCXO_TYPE = VCTCXO )
      endif
    endif
    ifneq ($(findstring MT6129,$(strip $(RF_MODULE))),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCTCXO)
        $(warning ERROR: MT6129 series RF_MODULE project must set AFC_VCXO_TYPE = VCTCXO ) 
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifneq ($(findstring MT6119,$(strip $(RF_MODULE))),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCTCXO)
        $(warning WARNING MT6119 series RF_MODULE project must set AFC_VCXO_TYPE = VCTCXO )
      endif
    endif
    ifneq ($(findstring BRIGHT4,$(strip $(RF_MODULE))),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCTCXO)
        $(warning WARNING BRIGHT4 series RF_MODULE project must set AFC_VCXO_TYPE = VCTCXO )
      endif
    endif
    ifneq ($(findstring MT6140A,$(strip $(RF_MODULE))),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCTCXO)
        $(warning WARNING MT6140A series RF_MODULE project must set AFC_VCXO_TYPE = VCTCXO )
      endif
    endif
    ifneq ($(findstring SKY74117,$(strip $(RF_MODULE))),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCTCXO)
        $(warning WARNING SKY74117 series RF_MODULE project must set AFC_VCXO_TYPE = VCTCXO )
      endif
    endif
    ifneq ($(findstring SKY74045,$(strip $(RF_MODULE))),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCTCXO)
        $(warning WARNING SKY74045 series RF_MODULE project must set AFC_VCXO_TYPE = VCTCXO )
      endif
    endif
    ifneq ($(findstring BRIGHT5P,$(strip $(RF_MODULE))),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCTCXO)
        $(warning WARNING  BRIGHT5P series RF_MODULE project must set AFC_VCXO_TYPE = VCTCXO )
      endif
    endif
    ifneq ($(findstring FOUNTAIN,$(strip $(RF_MODULE))),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCTCXO)
        $(warning WARNING FOUNTAIN series RF_MODULE project must set AFC_VCXO_TYPE = VCTCXO )
      endif
    endif

    ifneq ($(findstring AERO,$(strip $(RF_MODULE))),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCXO)
        $(warning WARNING AERO series RF_MODULE project must set AFC_VCXO_TYPE = VCXO )
      endif
    endif
    ifneq ($(findstring MT6139,$(strip $(RF_MODULE))),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCXO)
        $(warning WARNING MT6139 series RF_MODULE project must set AFC_VCXO_TYPE = VCXO )
      endif
    endif
    ifneq ($(findstring MT6140D,$(strip $(RF_MODULE))),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCXO)
        ifneq ($(strip $(PLATFORM)),MT6268A)
          ifneq ($(strip $(PLATFORM)),MT6268)
            ifneq ($(strip $(PLATFORM)),MT6270A)
              $(warning ERROR: MT6140D series RF_MODULE project must set AFC_VCXO_TYPE = VCXO )
              DEPENDENCY_CONFLICT = TRUE
            endif
          endif
        endif
      endif
    endif
  endif
endif

# Board Options
ifneq ($(strip $(BOARD_VER)),)
   COM_DEFS    += $(BOARD_VER)
endif

# Board Subversion
ifneq ($(strip $(SUB_BOARD_VER)),)
   COM_DEFS    += $(SUB_BOARD_VER)
endif


# LCD Module Options
# Move to project.mak except EVB
COM_DEFS_FOR_KLMLCM            = PCF8833 COLOR_LCD S6B1713 KLMLCM
COM_DEFS_FOR_MTKLCM_COLOR      = S1D15G00 COLOR_LCD MTKLCM_COLOR
COM_DEFS_FOR_NEPTUNE_LCM       = S6B33B1X COLOR_LCD NEPTUNE_LCM STN_MAINLCD
COM_DEFS_FOR_POWERTIP_LCM      = S6B33B1X COLOR_LCD POWERTIP_LCM STN_MAINLCD
COM_DEFS_FOR_SONY_LCM          = SONY_LCM TFT_MAINLCD
COM_DEFS_FOR_TOPPOLY_LCM       = TOPPOLY_LCM TFT_MAINLCD
COM_DEFS_FOR_RENESAS_LCM       = HD66781 COLOR_LCD HD66791 COLOR_SUBLCD DUAL_LCD RENESAS_LCM TFT_MAINLCD
COM_DEFS_FOR_TAURUS_LCM        = S6B33B2A COLOR_LCD S6B0756 TAURUS_LCM
COM_DEFS_FOR_PHOENIX29_LCM     = PHOENIX29_LCM TFT_MAINLCD
COM_DEFS_FOR_FIREFLY_LCM       = WSX6396A COLOR_LCD SSD1773 COLOR_SUBLCD FIREFLY_LCM TFT_MAINLCD STN_SUBLCD
COM_DEFS_FOR_MTK6225_LCM       = MTK6225_LCM TFT_MAINLCD
COM_DEFS_FOR_TOP_6227_LCM      = TOP_6227_LCM TFT_MAINLCD
COM_DEFS_FOR_LIBRA35_LCM       = LIBRA35_LCM TFT_MAINLCD
COM_DEFS_FOR_WISTRON_2P8_WQVGA_LCM = S6D0170 COLOR_LCD WISTRON_2P8_WQVGA_LCM TFT_MAINLCD
COM_DEFS_FOR_AUO_VGA_LCM = SSD1961 COLOR_LCD AUO_VGA_LCM TFT_MAINLCD
COM_DEFS_FOR_TRULY_HVGA_LCM = TA7601 COLOR_LCD TRULY_HVGA_LCM TFT_MAINLCD
COM_DEFS_FOR_UNICORN53_DEMO_LCM = ILI9325DS COLOR_LCD UNICORN53_DEMO_LCM TFT_MAINLCD
COM_DEFS_FOR_CLAM53_DEMO_LCM   = TFT1N5184 COLOR_LCD TFT1N5184 COLOR_SUBLCD DUAL_LCD CLAM53_DEMO_LCM TFT_MAINLCD
COM_DEFS_FOR_WISTRON_DUAL_DEMO_LCM = HX8340B COLOR_LCD WISTRON_DUAL_DEMO_LCM TFT_MAINLCD COLOR_SUBLCD DUAL_LCD
COM_DEFS_FOR_WISTRON_QCIF_DEMO_LCM = HX8340B COLOR_LCD WISTRON_QCIF_DEMO_LCM TFT_MAINLCD

COM_DEFS_FOR_LCD_MODULE =  COM_DEFS_FOR_$(strip $(LCD_MODULE))
ifdef $(COM_DEFS_FOR_LCD_MODULE)
   COM_DEFS		+=  $(COM_DEFS_FOR_$(strip $(LCD_MODULE)))
else
   $(warning ERROR: No COM_DEFS for LCD_MODULE = $(strip $(LCD_MODULE))!) 
   DEPENDENCY_CONFLICT = TRUE
endif

# BAND_SUPPORT Options
COM_DEFS_FOR_PGSM900   = __PGSM900__
COM_DEFS_FOR_EGSM900   = __EGSM900__
COM_DEFS_FOR_RGSM900   = __RGSM900__
COM_DEFS_FOR_DCS1800   = __DCS1800__
COM_DEFS_FOR_PCS1900   = __PCS1900__
COM_DEFS_FOR_GSM850    = __GSM850__
COM_DEFS_FOR_GSM450    = __GSM450__
COM_DEFS_FOR_DUAL900   = __EGSM900__ __DCS1800__
COM_DEFS_FOR_TRIPLE    = __EGSM900__ __DCS1800__ __PCS1900__
COM_DEFS_FOR_QUAD      = __EGSM900__ __DCS1800__ __PCS1900__  __GSM850__
COM_DEFS_FOR_DUAL850   = __GSM850__ __PCS1900__
COM_DEFS_FOR_TRIPLE850 = __GSM850__ __DCS1800__ __PCS1900__  TRIPLE850

COM_DEFS_FOR_BAND_SUPPORT =  COM_DEFS_FOR_$(strip $(BAND_SUPPORT))
ifdef $(COM_DEFS_FOR_BAND_SUPPORT)
   COM_DEFS		+=  $(COM_DEFS_FOR_$(strip $(BAND_SUPPORT)))
else
   COM_DEFS		+= __EGSM900__ __DCS1800__   # the same as DUAL900
endif


# UMTS_BAND_SUPPORT Options 
UMTS_SUPPORT_BAND =
ifdef UMTS_BAND_I
    ifeq ($(strip $(UMTS_BAND_I)),TRUE)     
        UMTS_SUPPORT_BAND  += __UMTS_BAND_I__
    endif
endif
ifdef UMTS_BAND_II
    ifeq ($(strip $(UMTS_BAND_II)),TRUE)     
        UMTS_SUPPORT_BAND  += __UMTS_BAND_II__
    endif
endif
ifdef UMTS_BAND_III
    ifeq ($(strip $(UMTS_BAND_III)),TRUE)     
        UMTS_SUPPORT_BAND  += __UMTS_BAND_III__
    endif
endif
ifdef UMTS_BAND_IV
    ifeq ($(strip $(UMTS_BAND_IV)),TRUE)     
        UMTS_SUPPORT_BAND  += __UMTS_BAND_IV__
    endif
endif
ifdef UMTS_BAND_V
    ifeq ($(strip $(UMTS_BAND_V)),TRUE)     
        UMTS_SUPPORT_BAND  += __UMTS_BAND_V__
        UMTS_SUPPORT_BAND  += __UMTS_BAND_VI__
    endif
endif
ifdef UMTS_BAND_VI
    ifeq ($(strip $(UMTS_BAND_VI)),TRUE)     
        UMTS_SUPPORT_BAND  += __UMTS_BAND_V__
        UMTS_SUPPORT_BAND  += __UMTS_BAND_VI__
    endif
endif
ifdef UMTS_BAND_VII
    ifeq ($(strip $(UMTS_BAND_VII)),TRUE)     
        UMTS_SUPPORT_BAND  += __UMTS_BAND_VII__
    endif
endif
ifdef UMTS_BAND_VIII
    ifeq ($(strip $(UMTS_BAND_VIII)),TRUE)     
        UMTS_SUPPORT_BAND  += __UMTS_BAND_VIII__
    endif
endif
ifdef UMTS_BAND_IX
    ifeq ($(strip $(UMTS_BAND_IX)),TRUE)     
        UMTS_SUPPORT_BAND  += __UMTS_BAND_IX__
    endif
endif
ifdef UMTS_BAND_X
    ifeq ($(strip $(UMTS_BAND_X)),TRUE)     
        UMTS_SUPPORT_BAND  += __UMTS_BAND_X__
    endif
endif
COM_DEFS    +=  $(strip $(UMTS_SUPPORT_BAND))
# Due to UAS RRC Specification (InterRATHandoverInfo message) limitation, UE at most supports 4 bands in band I~VII.
UMTS_SUPPORT_BAND_I_TO_VII_COUNT = $(words $(filter __UMTS_BAND_I__ __UMTS_BAND_II__ __UMTS_BAND_III__ __UMTS_BAND_IV__ __UMTS_BAND_V__ __UMTS_BAND_VI__ __UMTS_BAND_VII__,$(sort $(strip $(UMTS_SUPPORT_BAND)))))
ifeq ($(call gt,$(strip $(UMTS_SUPPORT_BAND_I_TO_VII_COUNT)),4),T)
    $(warning ERROR: UE at most supports 4 bands in band I~VII due to RRC Specification limitation (UE supports $(strip $(UMTS_SUPPORT_BAND))))
    DEPENDENCY_CONFLICT = TRUE
endif


# AFC_VCXO_TYPE Options
COM_DEFS_FOR_VCXO   		= AFC_VCXO
COM_DEFS_FOR_VCXO_SC   	= AFC_VCXO AFC_SC
COM_DEFS_FOR_VCXO_TC   	= AFC_VCXO AFC_TC
COM_DEFS_FOR_VCXO_SC_TC = AFC_VCXO AFC_SC AFC_TC

COM_DEFS_FOR_AFC_VCXO_TYPE =  COM_DEFS_FOR_$(strip $(AFC_VCXO_TYPE))
ifdef $(COM_DEFS_FOR_AFC_VCXO_TYPE)
   COM_DEFS		+=  $(COM_DEFS_FOR_$(strip $(AFC_VCXO_TYPE)))
endif

#
# Check the dependency of each options
#
ifneq ($(strip $(OBIGO_FEATURE)),NONE)
  ifeq ($(strip $(TCPIP_SUPPORT)),NONE)
    $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPORT,OBIGO_FEATURE)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(BROWSER_SUPPORT)),OBIGO_Q05A)
    ifeq ($(strip $(UNIFIED_MESSAGE_FOLDER)),FALSE)
      $(call DEP_ERR_SETA_OR_ONB,BROWSER_SUPPORT,non OBIGO_Q05A,UNIFIED_MESSAGE_FOLDER)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

#ifdef BROWSER_SUPPORT
#  ifeq ($(strip $(BROWSER_SUPPORT)),NONE)
#    ifneq ($(strip $(JATAAYU_FEATURE)),NONE)
#       $(call DEP_ERR_ONA_OR_OFFB,BROWSER_SUPPORT,JATAAYU_FEATURE)
#    endif    
#    ifneq ($(strip $(OBIGO_FEATURE)),NONE)
#       $(call DEP_ERR_ONA_OR_OFFB,BROWSER_SUPPORT,OBIGO_FEATURE)
#       DEPENDENCY_CONFLICT = TRUE
#    endif    
#  endif
#endif

ifdef J2ME_SUPPORT
  ifneq ($(strip $(J2ME_SUPPORT)),NONE)
    ifeq ($(strip $(OBIGO_FEATURE)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,OBIGO_FEATURE,J2ME_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(MELODY_VER)),DSP_WT_SYN)
      $(call DEP_ERR_SETA_OR_OFFB,MELODY_VER,DSP_WT_SYN,J2ME_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifdef PLATFORM
      ifeq ($(strip $(PLATFORM)),MT6223)
        ifneq ($(strip $(J2ME_SUPPORT)),NONE)
          $(warning ERROR: MT6223 does not support J2ME_SUPPORT yet) 
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
    ifneq ($(strip $(HTTP_INTERFACE_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,HTTP_INTERFACE_SUPPORT,J2ME_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef IMPS_SUPPORT
ifneq ($(strip $(IMPS_SUPPORT)),FALSE)
  ifeq ($(strip $(BROWSER_SUPPORT)),NONE)
    $(call DEP_ERR_ONA_OR_OFFB,BROWSER_SUPPORT,IMPS_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(XML_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,XML_SUPPORT,IMPS_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(HTTP_INTERFACE_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,HTTP_INTERFACE_SUPPORT,IMPS_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(FINGER_TOUCH_SUPPORT)),FTE)
    $(warning ERROR: IMPS_SUPPORT do not support FTE)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif
endif

ifdef DRM_SUPPORT
  ifneq ($(strip $(DRM_SUPPORT)),WS)
    ifneq ($(strip $(DRM_SUPPORT)),NONE)
      ifeq ($(strip $(OBIGO_FEATURE)),NONE)     
        $(call DEP_ERR_ONA_OR_OFFB,OBIGO_FEATURE,DRM_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifdef DRM_SUPPORT
  ifneq ($(strip $(DRM_SUPPORT)),NONE)
     ifeq ($(filter FMT_NOT_PRESENT,$(COM_DEFS)),FMT_NOT_PRESENT)
        $(warning ERROR: Please turn off DRM_SUPPORT when FMT_NOT_PRESENT!) 
        DEPENDENCY_CONFLICT = TRUE
     endif              
  endif
endif

ifdef  NAND_SUPPORT
ifdef  SYSTEM_DRIVE_ON_NAND
   ifeq ($(strip $(NAND_SUPPORT)),FALSE)
     ifeq ($(strip $(SYSTEM_DRIVE_ON_NAND)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,NAND_SUPPORT,SYSTEM_DRIVE_ON_NAND)
        DEPENDENCY_CONFLICT = TRUE
     endif
   endif
endif
endif

ifeq ($(strip $(FLASH_TEST_SELECT)),NAND_FLASH)
  ifneq ($(strip $(NAND_SUPPORT)),TRUE)
    $(call DEP_ERR_SETA_OR_ONB,FLASH_TEST_SELECT,non NAND_FLASH,NAND_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
    COM_DEFS    += __NAND_FLASH_HARDWARE_TEST__
endif

ifeq ($(strip $(FLASH_TEST_SELECT)),NOR_FLASH)
    COM_DEFS    += __NOR_FLASH_HARDWARE_TEST__
endif

ifdef EMAIL_SUPPORT
ifneq ($(strip $(EMAIL_SUPPORT)),NONE)
  ifeq ($(strip $(TCPIP_SUPPORT)),NONE)
    $(call DEP_ERR_SETA_OR_OFFB,TCPIP_SUPPORT,TCP/UDP_TCP,EMAIL_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(TCPIP_SUPPORT)),UDP)
    $(call DEP_ERR_SETA_OR_OFFB,TCPIP_SUPPORT,TCP/UDP_TCP,EMAIL_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifndef SSL_SUPPORT
    $(call DEP_ERR_ONA_OR_OFFB,SSL_SUPPORT,EMAIL_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  else
    ifeq ($(strip $(SSL_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,SSL_SUPPORT,EMAIL_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif
endif

ifdef VOIP_SUPPORT
  ifneq ($(strip $(VOIP_SUPPORT)),FALSE)
    ifeq ($(strip $(call Upper,$(PROJECT))),GSM)
      $(warning ERROR: GSM project does not support VoIP!) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(SIP_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,SIP_SUPPORT,VOIP_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(SDP_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,SDP_SUPPORT,VOIP_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(L1_WCDMA)),TRUE)
      ifndef WIFI_SUPPORT
        $(call DEP_ERR_ONA_OR_OFFB,WIFI_SUPPORT,VOIP_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(strip $(WIFI_SUPPORT)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,WIFI_SUPPORT,VOIP_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    COM_DEFS += __VOIP__  __SAF__
    COMPLIST += media_rtp
    CUS_REL_SRC_COMP += media_rtp
    COMPLIST += dp_engine
    CUS_REL_MTK_COMP += dp_engine
  endif
endif

ifdef SIP_SUPPORT
ifneq ($(strip $(SIP_SUPPORT)),FALSE)
  ifeq ($(strip $(TCPIP_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPORT,SIP_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
  endif
endif
endif


# WIFI_BB_MODULE Options
COM_DEFS_FOR_MT5911       = WIFI_BB_MT5911
COM_DEFS_FOR_MT5921       = WIFI_BB_MT5921
COM_DEFS_FOR_NONE         = WIFI_BB_NONE
COM_DEFS_FOR_None         = WIFI_BB_None

ifdef WIFI_SUPPORT
    COM_DEFS_FOR_WIFI_BB_MODULE =  COM_DEFS_FOR_$(strip $(WIFI_SUPPORT))
    ifdef $(COM_DEFS_FOR_WIFI_BB_MODULE)
        COM_DEFS	+=  $(COM_DEFS_FOR_$(strip $(WIFI_SUPPORT)))
    else
        $(warning ERROR: WIFI_BB_MODULE = $(strip $(WIFI_SUPPORT)) is not defined!) 
        DEPENDENCY_CONFLICT = TRUE
    endif
endif

# WIFI_RF_MODULE Options
COM_DEFS_FOR_AL2236      = WIFI_RF_AL2236
COM_DEFS_FOR_NONE        = WIFI_RF_NONE
COM_DEFS_FOR_None        = WIFI_RF_None

ifdef WIFI_SUPPORT
  ifeq ($(strip $(WIFI_SUPPORT)),none)
     COM_DEFS	+=  $(COM_DEFS_FOR_None)
  endif
  ifeq ($(strip $(WIFI_SUPPORT)),NONE)
     COM_DEFS	+=  $(COM_DEFS_FOR_NONE)
  endif
  ifeq ($(strip $(WIFI_SUPPORT)),MT5911)
     COM_DEFS	+=  $(COM_DEFS_FOR_AL2236)
  endif
endif

ifdef STREAM_SUPPORT
  ifneq ($(strip $(STREAM_SUPPORT)),FALSE)
    STREAM_NOT_SUPPORT_PLATFORM = MT6205% MT6217 MT6218% MT6219 MT6223% MT6225 MT6226% MT6227% MT6228
    ifneq ($(filter $(strip $(STREAM_NOT_SUPPORT_PLATFORM)),$(strip $(PLATFORM))),)
      $(warning ERROR: $(strip $(PLATFORM)) does NOT support STREAM_SUPPORT) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(SDP_SUPPORT)),FALSE)
       $(call DEP_ERR_ONA_OR_OFFB,SDP_SUPPORT,STREAM_SUPPORT)
       DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(RTSP_SUPPORT)),FALSE)
       $(call DEP_ERR_ONA_OR_OFFB,RTSP_SUPPORT,STREAM_SUPPORT)
       DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(AAC_DECODE)),FALSE)
       $(call DEP_ERR_ONA_OR_OFFB,AAC_DECODE,STREAM_SUPPORT)
       DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(MP4_DECODE)),TRUE)
       $(call DEP_ERR_ONA_OR_OFFB,MP4_DECODE,STREAM_SUPPORT)
       DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(OBIGO_FEATURE)),NONE)
       $(call DEP_ERR_ONA_OR_OFFB,OBIGO_FEATURE,STREAM_SUPPORT)
       DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(STREAM_SUPPORT)),TRUE)
     COM_DEFS += STREAM_SUPPORT
     COMPLIST += media_rtp
     CUS_REL_SRC_COMP += media_rtp
  endif
endif

ifdef 3G_VIDEO_CALL
  ifeq ($(strip $(3G_VIDEO_CALL)),TRUE)
    COMPLIST        += 3g324m
    CUS_REL_MTK_COMP += 3g324m
    COMP_TRACE_DEFS += 3g324m\appl\inc\vt_trc.h
    COM_DEFS   += __MEDIA_VT__ __VIDEO_CALL_SUPPORT__
  endif
endif

ifdef UUS_SUPPORT
  ifeq ($(strip $(UUS_SUPPORT)),TRUE)
     COM_DEFS    += __UUS_SUPPORT__
  endif   
endif

ifdef EMLPP_SUPPORT
  ifeq ($(strip $(EMLPP_SUPPORT)),TRUE)
     COM_DEFS    += __EMLPP_SUPPORT__
  endif   
endif

MTV_SUPPORT_ADD_MODULE_CONDITION = FALSE
MTV_SUPPORT_ADD_OPTION_CONDITION = FALSE
ifdef TDMB_SUPPORT
  ifneq ($(strip $(TDMB_SUPPORT)),NONE)
    MTV_SUPPORT_ADD_MODULE_CONDITION = TRUE
    MTV_SUPPORT_ADD_OPTION_CONDITION = TRUE
  endif
endif
ifdef CMMB_SUPPORT
  ifneq ($(strip $(CMMB_SUPPORT)),NONE)
    MTV_SUPPORT_ADD_MODULE_CONDITION = TRUE
    MTV_SUPPORT_ADD_OPTION_CONDITION = TRUE
  endif
endif
ifeq ($(strip $(STREAM_REC_SUPPORT)),TRUE)
  ifeq ($(filter MT6268 MT6235,$(PLATFORM)),)
    $(warning ERROR: PLEASE set STREAM_REC_SUPPORT = FALSE on all the platform except MT6268 and MT6235)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif
ifeq ($(strip $(STREAM_REC_SUPPORT)),TRUE)
  MTV_SUPPORT_ADD_MODULE_CONDITION = TRUE 
endif
ifdef ATV_SUPPORT
  ifneq ($(strip $(ATV_SUPPORT)),FALSE)
    ifndef ATV_CHIP
      $(warning ERROR: PLEASE set ATV_CHIP as VRE00 or VRE01 when ATV_SUPPORT = $(ATV_SUPPORT))
      DEPENDENCY_CONFLICT = TRUE
    endif
    MTV_SUPPORT_ADD_MODULE_CONDITION = TRUE
    MTV_SUPPORT_ADD_OPTION_CONDITION = TRUE
    COMPLIST         += matv_sec 
       
    ATV_ISP_NOT_SUPPORT_PLATFORM = MT6223 MT6223P
    ifeq ($(filter $(strip $(PLATFORM)) ,$(ATV_ISP_NOT_SUPPORT_PLATFORM)),)
        COM_DEFS += YUV_SENSOR_SUPPORT
    endif    
  else
    ifeq ($(strip $(ATV_SUPPORT)),FALSE)
      ifdef FM_RADIO_CHIP
        ifeq ($(strip $(FM_RADIO_CHIP)),MT5192FM)
          $(warning ERROR: PLEASE Not set FM_RADIO_CHIP to be MT5192FM when ATV_SUPPORT = $(ATV_SUPPORT))
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
  endif
endif
ifeq ($(strip $(MTV_SUPPORT_ADD_MODULE_CONDITION)),TRUE)
  COMPLIST += mtv
  ifneq ($(strip $(ATV_SUPPORT)),FALSE)
    COM_DEFS += __ATV_SUPPORT__ __ATV_DRV_OPTIMIZE__
    COMMINCDIRS +=  plutommi\MtkApp\MobileTVPlayer\MobileTVPlayerInc
    COMMINCDIRS    += custom\drv\mATV\$(strip $(ATV_CHIP))
  else
    ifeq ($(strip $(MTV_SUPPORT_ADD_OPTION_CONDITION)),TRUE)
      COM_DEFS += __MTV_SUPPORT__
      CUS_REL_OBJ_LIST += vendor\tdmb\cyberlink\lib\pc\SDL.dll
      CUS_REL_FILES_LIST += MoDIS_VC9\MoDIS\Debug\SDL.dll \
                            MoDIS_VC9\MoDIS\Release\SDL.dll \
                            media\mtv\src\cmmb_ca_mmc.h
    endif
  endif
endif

ifneq ($(strip $(ATV_SUPPORT)),FALSE)
COMPLIST         += matv
CUS_REL_SRC_COMP += matv
endif

ifdef ATV_I2S_PATH
  ifeq ($(strip $(ATV_I2S_PATH)),TRUE)
    ifneq ($(strip $(I2S_INPUT_MODE_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,I2S_INPUT_MODE_SUPPORT,ATV_I2S_PATH)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(ATV_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,ATV_SUPPORT,ATV_I2S_PATH)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __ATV_I2S_SUPPORT__ 
  endif
endif

ifdef ISP_SUPPORT
  ifeq ($(strip $(ISP_SUPPORT)),FALSE)
    ifdef ATV_SUPPORT
      ifeq ($(strip $(ATV_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,ISP_SUPPORT,ATV_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifeq ($(strip $(QN_IC_SUPPORT)),CHIP_QN8610)
 ifeq ($(strip $(ANALOG_TV_CHIP)),CHIP_QN8610)
  COMPLIST += qmatv
  CUSTOM_COMMINC += plutommi\mtkapp\qmatv\inc
  CUS_REL_SRC_COMP += qmatv
  COM_DEFS += __QTV_SUPPORT__
  COM_DEFS += __VIDEO_AUTO_DETECT__ #video auto detect while switch channel.  
#  COM_DEFS += __QTV_TASK_SUPPORT__
#  COM_DEFS += __QN_ISP_ENHANCE__ #to setup isp output for a video problem.
 endif

 ifeq ($(strip $(FM_RADIO_CHIP)),CHIP_QN8610)
  	COMMINCDIRS +=  fm_drv
	CUSTOM_COMMINC += fm_drv	
#	CUS_REL_SRC_COMP += fm_drv\src		
    COM_DEFS  += __FMDRV_FUNC__
    COM_DEFS  += __QFM_SUPPORT__
    COM_DEFS  += __QFM_EARPHONE__ #not to detect earphone. just for debugging, pls remove it later!!!
 endif
endif
ifneq ($(strip $(call Upper,$(PROJECT))),L1S)
  ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
    ifneq ($(strip $(call Upper,$(PROJECT))),MEUT)
      FLC_LIB_INCLUDE_CONDITION = FALSE
      ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
        FLC_LIB_INCLUDE_CONDITION = TRUE
      endif  
      ifneq ($(strip $(CSD_SUPPORT)),NONE)
        FLC_LIB_INCLUDE_CONDITION = TRUE
      endif
      ifeq ($(strip $(FAX_SUPPORT)),TRUE)
        FLC_LIB_INCLUDE_CONDITION = TRUE
      endif
      ifeq ($(strip $(IRDA_SUPPORT)),TRUE)
        FLC_LIB_INCLUDE_CONDITION = TRUE
      endif
      ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
        FLC_LIB_INCLUDE_CONDITION = TRUE
      endif
      ifeq ($(strip $(FLC_LIB_INCLUDE_CONDITION)),TRUE)
          COMPLIST += flc2
          COMP_TRACE_DEFS += ps\flc2\include\flc_trc.h         
          CUSTOM_COMMINC += ps\flc2\include  
          COM_DEFS += __FLC2__ __FLC_SUPPORT__
      endif
    endif
  endif
endif

ifneq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
  COM_DEFS    += __PHB_0x81_SUPPORT__
endif

ifdef SYNCML_DM_SUPPORT
  ifneq ($(strip $(SYNCML_DM_SUPPORT)),FALSE)
    ifeq ($(strip $(OPTR_SPEC)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,OPTR_SPEC,SYNCML_DM_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifndef OPTR_SPEC
      $(call DEP_ERR_ONA_OR_OFFB,OPTR_SPEC,SYNCML_DM_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifndef OBIGO_FEATURE
      $(call DEP_ERR_ONA_OR_OFFB,OBIGO_FEATURE,SYNCML_DM_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifdef OBIGO_FEATURE
      ifeq ($(strip $(OBIGO_FEATURE)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,OBIGO_FEATURE,SYNCML_DM_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifneq ($(strip $(XML_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,XML_SUPPORT,SYNCML_DM_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(HTTP_INTERFACE_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,HTTP_INTERFACE_SUPPORT,SYNCML_DM_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif


ifdef EMPTY_RESOURCE
  ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
    ifdef MMI_FEATURES_SWITCH
      ifeq ($(strip $(MMI_FEATURES_SWITCH)),TRUE)
        $(call DEP_ERR_OFFA_OR_OFFB,MMI_FEATURES_SWITCH,EMPTY_RESOURCE)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif
# Disabled definitions
# COM_DEFS  += MTK_PCM MTK_SLEEP_ENABLE MT6205_SIM GSI_SUPPORT MTK_GSM_ENABLE

# -----------------------------
# Custom Options
# -----------------------------
ifneq ($(filter UMTS HSPA,$(strip $(call Upper,$(PROJECT)))),)
   COM_DEFS += __MTK_3G_MRAT_ARCH__
endif

ifeq ($(strip $(PLATFORM)),MT6225)
   COM_DEFS    += __REDUCE_TCM_SUPPORT__
endif

ifeq ($(strip $(PLATFORM)),MT6253T)
   COM_DEFS    += __REDUCE_TCM_SUPPORT__
endif

ifeq ($(strip $(PLATFORM)),MT6253)
   COM_DEFS    += __REDUCE_TCM_SUPPORT__
endif

ifeq ($(strip $(PLATFORM)),MT6253E)
   COM_DEFS    += __REDUCE_TCM_SUPPORT__
endif

ifeq ($(strip $(PLATFORM)),MT6252H)
   COM_DEFS    += __REDUCE_TCM_SUPPORT__
endif

ifeq ($(strip $(PLATFORM)),MT6253L)
   COM_DEFS    += __REDUCE_TCM_SUPPORT__
endif

ifeq ($(strip $(PLATFORM)),MT6252)
   COM_DEFS    += __REDUCE_TCM_SUPPORT__
endif

ifeq ($(strip $(PLATFORM)),MT6223)
   COM_DEFS    += __REDUCE_TCM_SUPPORT__
endif

ifeq ($(strip $(PLATFORM)),MT6223P)
   COM_DEFS    += __REDUCE_TCM_SUPPORT__
endif

ifeq ($(strip $(PLATFORM)),MT6235)
   COM_DEFS    += __REDUCE_TCM_SUPPORT__ __ARM9_DCACHEABLE__ __DYNAMIC_SWITCH_CACHEABILITY__
endif

ifeq ($(strip $(PLATFORM)),MT6235B)
   COM_DEFS    += __REDUCE_TCM_SUPPORT__ __ARM9_DCACHEABLE__ __DYNAMIC_SWITCH_CACHEABILITY__
endif

ifeq ($(strip $(PLATFORM)),MT6236)
   COM_DEFS    += __REDUCE_TCM_SUPPORT__ __ARM9_DCACHEABLE__ __DYNAMIC_SWITCH_CACHEABILITY__
endif

ifeq ($(strip $(PLATFORM)),MT6236B)
   COM_DEFS    += __REDUCE_TCM_SUPPORT__ __ARM9_DCACHEABLE__ __DYNAMIC_SWITCH_CACHEABILITY__
endif

ifeq ($(strip $(PLATFORM)),MT6238)
   COM_DEFS    += __REDUCE_TCM_SUPPORT__ __ARM9_DCACHEABLE__ __DYNAMIC_SWITCH_CACHEABILITY__
endif

ifeq ($(strip $(PLATFORM)),MT6239)
   COM_DEFS    += __REDUCE_TCM_SUPPORT__ __ARM9_DCACHEABLE__ __DYNAMIC_SWITCH_CACHEABILITY__
endif

ifeq ($(strip $(PLATFORM)),MT6268A)
   COM_DEFS    += __REDUCE_TCM_SUPPORT__ __ARM9_DCACHEABLE__ __DYNAMIC_SWITCH_CACHEABILITY__
endif

ifeq ($(strip $(PLATFORM)),MT6268)
   COM_DEFS    += __REDUCE_TCM_SUPPORT__ __ARM9_DCACHEABLE__ __DYNAMIC_SWITCH_CACHEABILITY__
endif

ifeq ($(strip $(PLATFORM)),MT6270A)
   COM_DEFS    += __REDUCE_TCM_SUPPORT__ __ARM9_DCACHEABLE__ __DYNAMIC_SWITCH_CACHEABILITY__
endif

ifeq ($(strip $(L1_CATCHER)),TRUE)
   ifeq ($(strip $(TST_SUPPORT)),TRUE)
      COM_DEFS    += L1_CATCHER
   endif
endif

ifeq ($(strip $(MTK_SLEEP_ENABLE)),TRUE)
   COM_DEFS    += MTK_SLEEP_ENABLE
endif

ifeq ($(strip $(MTK_DSP_DEBUG)),TRUE)
   COM_DEFS    += MTK_DSP_DEBUG
endif

ifeq ($(strip $(FAX_SUPPORT)),TRUE)
  ifeq ($(strip $(call Upper,$(PROJECT))),L1S)
    $(warning ERROR: FAX_SUPPORT cannot be turned on in L1S projects.)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(call Upper,$(PROJECT))),BASIC)
    $(warning ERROR: FAX_SUPPORT cannot be turned on in BASIC projects.) 
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(call Upper,$(PROJECT))),MEUT)
    $(warning ERROR: FAX_SUPPORT cannot be turned on in MEUT projects.) 
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(FAX_SUPPORT)),FALSE)
  ifneq ($(strip $(BT_FAX_PROFILE)),FALSE)
    $(warning ERROR: Please turn off BT_FAX_PROFILE when FAX_SUPPORT = FALSE)
  endif
endif

ifdef CSD_SUPPORT
  ifneq ($(strip $(CSD_SUPPORT)),NONE)
    ifeq ($(strip $(call Upper,$(PROJECT))),L1S)
      $(warning ERROR: Please turn off CSD_SUPPORT in $(strip $(call Upper,$(PROJECT))) project) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    # can ONLY be set NT_ONLY for 3G projects
    ifneq ($(strip $(CSD_SUPPORT)),NT_ONLY)
      ifeq ($(strip $(L1_WCDMA)),TRUE)
        $(call DEP_ERR_SETA_OR_OFFB,CSD_SUPPORT,NT_ONLY,L1_WCDMA)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    
    # Support CSD
    COM_DEFS    += CSD_SUPPORT 

    ifeq ($(strip $(CSD_SUPPORT)),T_NT)
      COM_DEFS    += __CSD_NT__ __CSD_T__
    else
      ifeq ($(strip $(CSD_SUPPORT)),NT_ONLY)
        COM_DEFS    += __CSD_NT__ 
      else
        $(warning ERROR: CSD_SUPPORT setting is wrong) 
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif

    ifeq ($(strip $(FAX_SUPPORT)),TRUE)
      COM_DEFS    += __CSD_FAX__
    endif
  else
    # FAX only, Not support CSD
    ifeq ($(strip $(FAX_SUPPORT)),TRUE)
      COM_DEFS    += CSD_SUPPORT __CSD_FAX__
    endif
  endif
endif

ifndef CSD_SUPPORT
   # FAX only, Not support CSD
   ifeq ($(strip $(FAX_SUPPORT)),TRUE)
      COM_DEFS    += CSD_SUPPORT __CSD_FAX__
   endif
endif

ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
  COM_DEFS += KAL_ENH_MUTEX
else
  ifneq ($(filter __CS_SERVICE__,$(COM_DEFS)),)
    ifneq ($(strip $(CSD_SUPPORT)),NONE)
      COM_DEFS    += KAL_ENH_MUTEX
    endif
  endif
endif
   
ifdef PMIC_PRESENT
  ifeq ($(strip $(PMIC_PRESENT)),TRUE)
   	COM_DEFS    += PMIC_PRESENT
  endif
endif

ifdef PMIC
  ifneq ($(strip $(PMIC)),NONE)
     COM_DEFS    += PMIC_PRESENT
  endif
  ifeq ($(strip $(PLATFORM)),MT6205)
    ifneq ($(strip $(PMIC)),MT6305)
      ifneq ($(strip $(PMIC)),NONE)
        $(warning ERROR: MT6205 only supports MT6305 PMIC, and does not support $(strip $(PMIC))) 
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifeq ($(strip $(PLATFORM)),MT6205B)
    ifneq ($(strip $(PMIC)),MT6305)
      ifneq ($(strip $(PMIC)),NONE)
        $(warning ERROR: MT6205B only supports MT6305 PMIC, and does not support $(strip $(PMIC))) 
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifeq ($(strip $(PLATFORM)),MT6205C)
    ifneq ($(strip $(PMIC)),MT6305)
      ifneq ($(strip $(PMIC)),NONE)
        $(warning ERROR: MT6205C only supports MT6305 PMIC, and does not support $(strip $(PMIC))) 
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif

  ifeq ($(strip $(PMIC)),MT6235PMU)
    ifneq ($(strip $(PLATFORM)),MT6235)
      ifneq ($(strip $(PLATFORM)),MT6235B)
        $(warning ERROR: $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6235 & MT6235B series chips support $(strip $(PMIC)) PMIC) 
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifeq ($(strip $(PLATFORM)),MT6235)
    ifneq ($(strip $(PMIC)),MT6235PMU)
      ifneq ($(strip $(PMIC)),NONE)
        $(warning ERROR: MT6235 only supports MT6235PMU PMIC, and does not support $(strip $(PMIC))) 
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifeq ($(strip $(PLATFORM)),MT6235B)
    ifneq ($(strip $(PMIC)),MT6235PMU)
      ifneq ($(strip $(PMIC)),NONE)
        $(warning ERROR: MT6235B only supports MT6235PMU PMIC, and does not support $(strip $(PMIC))) 
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif

  ifeq ($(strip $(PMIC)),MT6238PMU)
    ifneq ($(strip $(PLATFORM)),MT6238)
      ifneq ($(strip $(PLATFORM)),MT6239)
        $(warning ERROR: $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6238 & MT6239 series chips support $(strip $(PMIC)) PMIC) 
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifeq ($(strip $(PLATFORM)),MT6238)
    ifneq ($(strip $(PMIC)),MT6238PMU)
      ifneq ($(strip $(PMIC)),NONE)
        $(warning ERROR: MT6238 only supports MT6238PMU PMIC, and does not support $(strip $(PMIC))) 
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifeq ($(strip $(PLATFORM)),MT6239)
    ifneq ($(strip $(PMIC)),MT6238PMU)
      ifneq ($(strip $(PMIC)),NONE)
        $(warning ERROR: MT6239 only supports MT6238PMU PMIC, and does not support $(strip $(PMIC))) 
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif

  ifeq ($(strip $(PMIC)),MT6223PMU)
    ifneq ($(strip $(PLATFORM)),MT6223)
      ifneq ($(strip $(PLATFORM)),MT6223P)
        $(warning ERROR: $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6223 series chips support $(strip $(PMIC)) PMIC) 
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifeq ($(strip $(PLATFORM)),MT6223)
    ifneq ($(strip $(PMIC)),MT6223PMU)
      ifneq ($(strip $(PMIC)),NONE)
        $(warning ERROR: MT6223 only supports MT6223PMU PMIC, and does not support $(strip $(PMIC))) 
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifeq ($(strip $(PLATFORM)),MT6223P)
    ifneq ($(strip $(PMIC)),MT6223PMU)
      ifneq ($(strip $(PMIC)),NONE)
        $(warning ERROR: MT6223P only supports MT6223PMU PMIC, and does not support $(strip $(PMIC))) 
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  PMIC_MT6326_SUPPORT_PLATFORM = MT6268A MT6268 MT6270A 
  ifeq ($(strip $(PMIC)),MT6326)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(PMIC_MT6326_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support PMIC=$(strip $(PMIC))) 
        DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(PMIC)),MT6253PMU)
    ifneq ($(strip $(PLATFORM)),MT6253T)
      ifneq ($(strip $(PLATFORM)),MT6253)
        $(warning ERROR: $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6253 series chips support $(strip $(PMIC)) PMIC) 
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifeq ($(strip $(PMIC)),MT6253ELPMU)
    ifneq ($(strip $(PLATFORM)),MT6253E)
      ifneq ($(strip $(PLATFORM)),MT6253L)
        $(warning ERROR: $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6253EL series chips support $(strip $(PMIC)) PMIC)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifeq ($(strip $(PMIC)),MT6252PMU)
    ifneq ($(strip $(PLATFORM)),MT6252)
      ifneq ($(strip $(PLATFORM)),MT6252H)
        $(warning ERROR: $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6252/H series chips support $(strip $(PMIC)) PMIC)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifeq ($(strip $(PMIC)),MT6236PMU)
    ifneq ($(strip $(PLATFORM)),MT6236)
      ifneq ($(strip $(PLATFORM)),MT6236B)
        $(warning ERROR: $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6236 series chips support $(strip $(PMIC)) PMIC)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif  
endif

ifeq ($(strip $(PMIC)),MT6223PMU)
   COM_DEFS    += MT6223PMU
endif

ifeq ($(strip $(PMIC)),MT6238PMU)
   COM_DEFS    += MT6238PMU
endif

ifeq ($(strip $(PMIC)),MT6235PMU)
   COM_DEFS    += MT6235PMU
endif

ifeq ($(strip $(PMIC)),MT6236PMU)
   COM_DEFS    += MT6236PMU
endif

ifeq ($(strip $(PMIC)),MT6305)
     COM_DEFS    += MT6305
endif

ifeq ($(strip $(PMIC)),MT6318)
   COM_DEFS    += MT6318
endif

ifeq ($(strip $(PMIC)),MT6326)
   COM_DEFS    += MT6326
endif

ifeq ($(strip $(PMIC)),MT6253PMU)
   COM_DEFS    += MT6253PMU
endif

ifeq ($(strip $(PMIC)),MT6253ELPMU)
   COM_DEFS    += MT6253ELPMU
endif

ifeq ($(strip $(PMIC)),MT6252PMU)
   COM_DEFS    += MT6252PMU
endif

ifeq ($(strip $(PMIC)),MT6326_CCCI)
   COM_DEFS    += MT6326_CCCI
endif

ifeq ($(strip $(OBIGO_FEATURE)),WAP)
   COM_DEFS    += WAP_SUPPORT
else
  ifeq ($(strip $(OBIGO_FEATURE)),WAP2)
    COM_DEFS    += WAP_SUPPORT  WAP2
  else
    ifeq ($(strip $(OBIGO_FEATURE)),WAP_SEC)
      COM_DEFS    += WAP_SUPPORT  WAP_SEC_SUPPORT
    else
      ifeq ($(strip $(OBIGO_FEATURE)),WAP2_SEC)
        COM_DEFS    += WAP_SUPPORT  WAP2  WAP_SEC_SUPPORT
      endif
      ifeq ($(strip $(OBIGO_FEATURE)),NONE)
        COM_DEFS    += WAP_NOT_PRESENT
      endif
    endif
  endif
endif

#ifneq ($(strip $(OBIGO_FEATURE)),NONE)
#   COM_DEFS    += OBIGO_SUPPORT
#endif


ifdef DRM_SUPPORT
  COMPLIST    += drm
  COMMINCDIRS     +=  applib\misc\include
  ifneq ($(strip $(DRM_SUPPORT)),NONE)
    COMP_TRACE_DEFS += drm\include\drm_trace.h
    ifneq ($(findstring BSCI,$(strip $(DRM_SUPPORT))),)
      BSCI_NOT_SUPPORT_PLATFORM = MT6205 MT6205B MT6223 MT6223P MT6225 
      ifneq ($(filter $(strip $(PLATFORM)),$(BSCI_NOT_SUPPORT_PLATFORM)),)
        $(warning ERROR: Please set DRM_SUPPORT=MTK and DRM_VESION=V01 for PLATFORM $(strip $(PLATFORM))) 
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS    += __DRM_SUPPORT__ __DRM_BSCI__  __DRM_V01__ __DRM_V02__
      ifneq ($(strip $(PLATFORM)),MT6238)
        ifneq ($(strip $(PLATFORM)),MT6239)
          ifdef STREAM_SUPPORT
            ifdef PURE_AUDIO_SUPPORT
              ifeq ($(strip $(PURE_AUDIO_SUPPORT)),TRUE)
                $(warning ERROR: Please set PURE_AUDIO_SUPPORT as FALSE) 
                DEPENDENCY_CONFLICT = TRUE
              endif
            endif
            ifeq ($(strip $(STREAM_SUPPORT)),TRUE)
              COM_DEFS   += __DRM_PDCF__
            endif
          endif
        endif
      endif
      ifeq ($(strip $(DRM_SUPPORT)),BSCI)
        COMPLIST    += drmadp_bsci
        CUS_REL_SRC_COMP += drmadp_bsci
        COMPOBJS         += vendor\drm\bsci\bsci.lib
        CUS_REL_OBJ_LIST += vendor\drm\bsci\bsci.lib
        CUS_REL_BASE_COMP += vendor\drm\bsci\inc
        CUS_REL_BASE_COMP += vendor\drm\bsci\src\drmagent-v2\inc
        COMMINCDIRS   +=  vendor\drm\$(strip $(DRM_SUPPORT))\adp\include
      else
        ifeq ($(strip $(DRM_SUPPORT)),BSCI_SRC)
          COMPLIST    += bsci
          CUS_REL_MTK_COMP += bsci
          COMMINCDIRS   +=  vendor\drm\bsci\adp\include
        endif
      endif
    endif
    ifeq ($(strip $(DRM_SUPPORT)),MTK)
      COM_DEFS    += __DRM_SUPPORT__ __DRM_MTK__ __DRM_V01__
      COMPLIST    += drmadp_mtk
      CUS_REL_SRC_COMP += drmadp_mtk
      COMMINCDIRS   +=  vendor\drm\MTK\adp\include
    endif
    ifeq ($(strip $(DRM_SUPPORT)),WS)
#      ifneq ($(strip $(MMI_VERSION)),WISDOM_MMI)
#         $(error DRM_SUPPORT as WS does not support MMI_VERSION is not WISDOM_MMI)
#      endif
      COM_DEFS    += __DRM_SUPPORT__ __DRM_WS__ __DRM_V01__ __DRM_EXTERNAL__
      COMPLIST    += drmadp_ws
      CUS_REL_SRC_COMP += drmadp_ws
      COMMINCDIRS   +=  vendor\drm\WS\adp\include
    endif
  endif
endif


ifeq ($(strip $(DRM_VERSION)),V02)
 ifeq ($(strip $(DRM_SUPPORT)),MTK)
   $(warning ERROR: DRM_SUPPORT as MTK does not support DRM_VERSION as V02) 
   DEPENDENCY_CONFLICT = TRUE
 endif    
endif

ifeq ($(strip $(DRM_VERSION)),ALL)
 ifeq ($(strip $(DRM_SUPPORT)),MTK)
   $(warning ERROR: DRM_SUPPORT as MTK does not support DRM_VERSION as ALL) 
   DEPENDENCY_CONFLICT = TRUE
 endif    
endif

ifeq ($(strip $(FAST_UART)),TRUE)
	COM_DEFS    += __FAST_UART__
endif



# We can define __TWO_KEY_DETECTION_SWITCHABLE__  when __KBD_JOYSTICK_SUPPORT__ is not defined.
ifeq ($(filter __KBD_JOYSTICK_SUPPORT__,$(COM_DEFS)),__KBD_JOYSTICK_SUPPORT__)
   ifeq ($(filter __TWO_KEY_DETECTION_SWITCHABLE__,$(COM_DEFS)),__TWO_KEY_DETECTION_SWITCHABLE__)
      $(call DEP_ERR_OFFA_OR_OFFB,__TWO_KEY_DETECTION_SWITCHABLE__,__KBD_JOYSTICK_SUPPORT__)
      DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef NAND_SUPPORT
  ifeq ($(strip $(NAND_SUPPORT)),TRUE)
    COM_DEFS    += NAND_SUPPORT
  endif
endif

ifdef BOOT_FAT_RESET
  ifeq ($(strip $(BOOT_FAT_RESET)),TRUE)
    COM_DEFS    += __BOOT_FAT_RESET__
  endif
endif

ifdef NAND_SUPPORT
ifdef SYSTEM_DRIVE_ON_NAND
  ifeq ($(strip $(SYSTEM_DRIVE_ON_NAND)),TRUE)
    SYSTEM_DRIVE_ON_NAND_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6217 MT6218B MT6219 MT6227 MT6226 MT6226M MT6225 MT6253T MT6253 MT6253E MT6253L MT6223 MT6227D MT6226D MT6223P MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6268T MT6268H MT6268A MT6268 MT6270A 
    ifeq ($(filter $(strip $(PLATFORM)) ,$(SYSTEM_DRIVE_ON_NAND_SUPPORT_PLATFORM)),)
           $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support SYSTEM_DRIVE_ON_NAND.) 
           DEPENDENCY_CONFLICT = TRUE
    else
      ifeq ($(strip $(NAND_SUPPORT)),TRUE)
          COM_DEFS    += __FS_SYSDRV_ON_NAND__
      endif
    endif
  endif
endif
endif


ifdef NAND_SUPPORT
  ifeq ($(strip $(NAND_SUPPORT)),TRUE)
    ifeq ($(strip $(PLATFORM)),MT6205B)
      $(warning ERROR: The $(strip $(PLATFORM)) chip does not have NAND_SUPPORT feature.) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(PLATFORM)),MT6205)
      $(warning ERROR: The $(strip $(PLATFORM)) chip does not have NAND_SUPPORT feature.) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(PLATFORM)),MT6208)
      $(warning ERROR: The $(strip $(PLATFORM)) chip does not have NAND_SUPPORT feature.) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(PLATFORM)),MT6223)
      $(warning ERROR: The $(strip $(PLATFORM)) chip does not have NAND_SUPPORT feature.) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(PLATFORM)),MT6223P)
      $(warning ERROR: The $(strip $(PLATFORM)) chip does not have NAND_SUPPORT feature.) 
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif


ifdef APP_STORAGE_IN_SYS_DRV
  ifeq ($(strip $(APP_STORAGE_IN_SYS_DRV)),FALSE)
     ifdef MMS_SUPPORT
         COM_DEFS    += MMS_IN_LARGE_STORAGE
     endif
     ifeq ($(strip $(IMPS_SUPPORT)),TRUE)
       COM_DEFS   += IMPS_IN_LARGE_STORAGE
     endif
  else
      COM_DEFS    += APP_STORAGE_IN_SYS_DRV
  endif
endif


ifdef FM_RADIO_CHIP
  ifneq ($(strip $(FM_RADIO_CHIP)),NONE)
    COM_DEFS	+= $(FM_RADIO_CHIP)
    COM_DEFS	+= FM_RADIO_ENABLE
    ifdef FM_RADIO_RECORD
      ifeq ($(strip $(FM_RADIO_RECORD)),TRUE)
        COM_DEFS  += FM_RADIO_RECORD
      endif
    endif
    COMPLIST         += fm_drv
    CUS_REL_SRC_COMP += fm_drv
    COMP_TRACE_DEFS += fmr\inc\fmr_trc.h
  endif
endif

ifdef MSDC_CARD_SUPPORT_TYPE
  ifneq ($(strip $(MSDC_CARD_SUPPORT_TYPE)),NONE)
      MSDC_SUPPORT_PLATFORM = MT6217 MT6218B MT6219 MT6228 MT6229 MT6230 MT6226 MT6227 MT6226M MT6225 MT6252 MT6252H MT6253T MT6253 MT6253E MT6253L MT6227D MT6226D MT6223P MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6268T MT6268H MT6268A MT6268 MT6270A 
      ifeq ($(filter $(strip $(PLATFORM)) ,$(MSDC_SUPPORT_PLATFORM)),)
          $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does NOT support MSDC_CARD_SUPPORT_TYPE) 
          DEPENDENCY_CONFLICT = TRUE
      else
           COM_DEFS	+= __FS_CARD_SUPPORT__
         ifeq ($(strip $(MSDC_CARD_SUPPORT_TYPE)),MSDC_SD_MMC)
           COM_DEFS	+= __MSDC_SD_MMC__
         endif
         ifeq ($(strip $(MSDC_CARD_SUPPORT_TYPE)),MSDC_MS)
           COM_DEFS	+= __MSDC_MS__
         endif
         ifeq ($(strip $(MSDC_CARD_SUPPORT_TYPE)),MSDC_MSPRO)
           COM_DEFS	+= __MSDC_MSPRO__
         endif
      endif
  endif
endif

ifneq ($(strip $(USB_SUPPORT)),TRUE)
    ifneq ($(filter __CHARGER_USB_DETECT_WIHT_ONE_EINT__ ,$(CUSTOM_OPTION)),)
        $(warning ERROR: Please remove __CHARGER_USB_DETECT_WIHT_ONE_EINT__ from CUSTOM_OPTION when USB_SUPPORT is not TRUE!) 
        DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(filter __USB_AND_UART_WITH_ONE_GPIO__ ,$(CUSTOM_OPTION)),)
        $(warning ERROR: Please remove __USB_AND_UART_WITH_ONE_GPIO__ from CUSTOM_OPTION when USB_SUPPORT is not TRUE!) 
        DEPENDENCY_CONFLICT = TRUE
    endif
endif

ifeq ($(strip $(USB_SUPPORT)),TRUE)
  USB_SUPPORT_PLATFORM = MT6217 MT6218B MT6219 MT6228 MT6229 MT6230 MT6227 MT6226 MT6226M MT6225 MT6252H MT6252 MT6253T MT6253 MT6253E MT6253L MT6227D MT6226D MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6268T MT6268H MT6268A MT6268 MT6516 MT6270A 
  ifeq ($(filter $(strip $(PLATFORM)) ,$(USB_SUPPORT_PLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support USB.) 
    DEPENDENCY_CONFLICT = TRUE
  else
    ifeq ($(strip $(USB_SUPPORT)),TRUE)
      COM_DEFS    += __USB_ENABLE__  __NVRAM_IN_USB_MS__
      ifeq ($(strip $(BOARD_VER)),MT6228_EVB)
        COM_DEFS    += _USB_VBUS_DETECT_WITH_NIRQ_
      endif
      ifeq ($(strip $(BOARD_VER)),MT6229_EVB)
        COM_DEFS    += _USB_VBUS_DETECT_WITH_NIRQ_
      endif
      ifeq ($(strip $(BOARD_VER)),MT6229_MGM_EVB)
        COM_DEFS    += _USB_VBUS_DETECT_WITH_NIRQ_
      endif
      ifeq ($(strip $(BOARD_VER)),MT6230_EVB)
        COM_DEFS    += _USB_VBUS_DETECT_WITH_NIRQ_
      endif
      ifeq ($(strip $(PLATFORM)),MT6235) 
        COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__
      endif
      ifeq ($(strip $(PLATFORM)),MT6235B) 
        COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__
      endif
      ifeq ($(strip $(PLATFORM)),MT6236) 
        COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__
      endif
      ifeq ($(strip $(PLATFORM)),MT6236B) 
        COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__
      endif
      ifeq ($(strip $(PLATFORM)),MT6238)
        COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__
      endif
      ifeq ($(strip $(PLATFORM)),MT6239)
        COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__
      endif
      ifeq ($(strip $(PLATFORM)),MT6268A) 
        COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__ 
      endif
      ifeq ($(strip $(PLATFORM)),MT6268) 
        COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__ 
      endif
      ifeq ($(strip $(PLATFORM)),MT6270A) 
        COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__ 
      endif
      ifeq ($(strip $(PLATFORM)),MT6253T) 
        COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__ 
      endif
      ifeq ($(strip $(PLATFORM)),MT6253) 
        COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__ 
      endif
      ifeq ($(strip $(PLATFORM)),MT6253E)
        COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__
      endif
      ifeq ($(strip $(PLATFORM)),MT6253L)
        COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__
      endif
      ifeq ($(strip $(PLATFORM)),MT6252)
        COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__
      endif
      ifeq ($(strip $(PLATFORM)),MT6252H)
        COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__
      endif    
    endif
  endif
endif

WT_ROM_V1_SUPPORT_PLATFORM = MT6253 MT6253T MT6253E MT6253L MT6252 MT6252H
WT_ROM_V2_SUPPORT_PLATFORM = MT6251
ifeq ($(strip $(WAVETABLE_VER)),WT_ROM_V1)
    ifeq ($(filter $(strip $(PLATFORM)),$(WT_ROM_V1_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support WAVETABLE_VER=WT_ROM_V1) 
        DEPENDENCY_CONFLICT = TRUE
    endif
endif
ifeq ($(strip $(WAVETABLE_VER)),WT_ROM_V2)
    ifeq ($(filter $(strip $(PLATFORM)),$(WT_ROM_V2_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support WAVETABLE_VER=WT_ROM_V2) 
        DEPENDENCY_CONFLICT = TRUE
    endif
else
  ifneq ($(filter $(strip $(PLATFORM)),$(WT_ROM_V2_SUPPORT_PLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) must set WAVETABLE_VER=WT_ROM_V2)
    DEPENDENCY_CONFLICT = TRUE 
  endif
endif

ifdef MELODY_VER
  ifeq ($(strip $(MELODY_VER)),NONE)
    ifneq ($(strip $(MED_PROFILE)),MED_MODEM)
      $(warning ERROR: Please do not set MELODY_VER to be NONE or set MED_PROFILE to be MED_MODEM) 
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifeq ($(strip $(MELODY_VER)),DSP_WT_SYN)
#  DSP_WT_SYN_NOT_SUPPORT_PLATFORM = MT6205 MT6208 MT6205B MT6208B
#  ifneq ($(filter $(strip $(PLATFORM)),$(DSP_WT_SYN_NOT_SUPPORT_PLATFORM)),)
#     $(error Chip version $(strip $(PLATFORM)) does not support MELODY_VER=DSP_WT_SYN)
#  endif
   ifeq ($(strip $(PLATFORM)),MT6205B)
     $(warning ERROR: $(strip $(PLATFORM)) does not support MELODY_VER=$(strip $(MELODY_VER))) 
     DEPENDENCY_CONFLICT = TRUE
  endif
   COM_DEFS	+= $(strip $(WAVETABLE_VER))
endif

ifdef DEDI_AMR_REC
  DEDI_AMR_REC_NOT_SUPPORT_PLATFORM = MT6205B MT6223 MT6223P
  DEDI_AMR_REC_SWIP_NOT_SUPPORT_PLATFORM = MT6226 MT6226M MT6227 MT6226D MT6227D
  ifeq ($(strip $(DEDI_AMR_REC)),TRUE)
    ifneq ($(filter $(strip $(PLATFORM)),$(DEDI_AMR_REC_NOT_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support DEDI_AMR_REC=TRUE) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifndef AMR_CODEC
      $(call DEP_ERR_ONA_OR_OFFB,AMR_CODEC,DEDI_AMR_REC)
      DEPENDENCY_CONFLICT = TRUE
    else
      ifneq ($(strip $(AMR_CODEC)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,AMR_CODEC,DEDI_AMR_REC)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    COM_DEFS	+= DEDI_AMR_REC
    
    ifeq ($(filter $(strip $(PLATFORM)),$(DEDI_AMR_REC_SWIP_NOT_SUPPORT_PLATFORM)),)
      ifeq ($(strip $(COMPILER)),ADS)
        COMPOBJS    += dp_engine\amr\amr_arm.a
        CUS_REL_OBJ_LIST += dp_engine\amr\amr_arm.a
      endif
      ifeq ($(strip $(COMPILER)),RVCT)
        COMPOBJS    += dp_engine\amr\amr_rvct.a
        CUS_REL_OBJ_LIST += dp_engine\amr\amr_rvct.a
      endif
    endif
  endif
endif

ifdef VR_ENGINE
  ifneq ($(strip $(VR_ENGINE)),NONE)
         COM_DEFS	+= $(VR_ENGINE)
  endif

  ifeq ($(strip $(VR_ENGINE)),VRSI_CYBERON)
    COM_DEFS += VRSI_ENABLE
    ifeq ($(strip $(VRSI_LANGUAGE)),CYBERON_CNBI)
      ifeq ($(strip $(COMPILER)),ADS)
         COMPOBJS    += l1audio\obj\BSR_SI_Shell_CNBI.lib
         CUS_REL_OBJ_LIST += l1audio\obj\BSR_SI_Shell_CNBI.lib
      endif
      ifeq ($(strip $(COMPILER)),RVCT)
         COMPOBJS    += l1audio\obj\BSR_SI_Shell_CNBI_RVCT.lib
         CUS_REL_OBJ_LIST += l1audio\obj\BSR_SI_Shell_CNBI_RVCT.lib
      endif
      COM_DEFS += CYBERON_CNBI
    else
      ifeq ($(strip $(COMPILER)),ADS)
         COMPOBJS    += l1audio\obj\BSR_SI_Shell_TWBI.lib
         CUS_REL_OBJ_LIST    += l1audio\obj\BSR_SI_Shell_TWBI.lib
      endif
      ifeq ($(strip $(COMPILER)),RVCT)
         COMPOBJS    += l1audio\obj\BSR_SI_Shell_TWBI_RVCT.lib
         CUS_REL_OBJ_LIST    += l1audio\obj\BSR_SI_Shell_TWBI_RVCT.lib
      endif
      COM_DEFS += CYBERON_TWBI
    endif
  endif
endif

ifdef PROJECT
  ifdef TCPIP_SUPPORT
    ifeq ($(strip $(TCPIP_SUPPORT)),TCP)
      COM_DEFS   += TCP_SUPPORT
    endif
    ifeq ($(strip $(TCPIP_SUPPORT)),UDP)
      COM_DEFS   += UDP_SUPPORT
    endif
    ifeq ($(strip $(TCPIP_SUPPORT)),UDP_TCP)
      COM_DEFS   += UDP_SUPPORT TCP_SUPPORT
    endif
    ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
      COM_DEFS   += __TCPIP__
      ifneq ($(strip $(TCPIP_LOOP_SUPPORT)),FALSE)
        COM_DEFS += __TCPIP_LOOP_BACK__
      endif
    endif
    ifneq ($(filter UMTS HSPA,$(strip $(call Upper,$(PROJECT)))),)
      ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
        COMPLIST    += abm soc tcpip applib_inet
      else
        COM_DEFS   += ABM_NOT_PRESENT TCPIP_NOT_PRESENT SOC_NOT_PRESENT
      endif
    endif
    ifeq ($(call Upper,$(strip $(PROJECT))),GPRS)
      ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
        COMPLIST    += abm soc tcpip applib_inet
      else
        COM_DEFS   += ABM_NOT_PRESENT TCPIP_NOT_PRESENT SOC_NOT_PRESENT
      endif
    endif
    ifeq ($(strip $(call Upper,$(PROJECT))),GSM)
      ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
        COMPLIST    += abm soc tcpip ppp applib_inet
      else
        COM_DEFS   += ABM_NOT_PRESENT TCPIP_NOT_PRESENT SOC_NOT_PRESENT PPP_NOT_PRESENT
      endif
    endif
  endif
else
  $(warning ERROR: PROJECT is not defined!) 
  DEPENDENCY_CONFLICT = TRUE
endif

ifndef FS_SORT_MAX_ENTRY
  FS_SORT_MAX_ENTRY = 256
endif

ifdef FS_SORT_MAX_ENTRY
  FS_SORT_MAX_ENTRY_PLATFORM = MT6228 MT6229 MT6230 MT6235 MT6235B MT6236 MT6236B MT6238 MT6239 MT6253 MT6253E MT6253L MT6252 MT6252H MT6268 MT6268A MT6270A
  ifneq ($(filter $(strip $(PLATFORM)),$(FS_SORT_MAX_ENTRY_PLATFORM)),)
    ifeq ($(call gt,$(strip $(FS_SORT_MAX_ENTRY)),20000),T)
      $(warning ERROR: FS_SORT_MAX_ENTRY value ($(FS_SORT_MAX_ENTRY)) on $(strip $(PLATFORM)) should not be larger than 20000) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(call lt,$(strip $(FS_SORT_MAX_ENTRY)),64),T)
      $(warning ERROR: FS_SORT_MAX_ENTRY value ($(FS_SORT_MAX_ENTRY)) on $(strip $(PLATFORM)) should not be less than 64) 
      DEPENDENCY_CONFLICT = TRUE
    endif
  else
    ifeq ($(call gt,$(strip $(FS_SORT_MAX_ENTRY)),256),T)
      $(warning ERROR: FS_SORT_MAX_ENTRY value ($(FS_SORT_MAX_ENTRY)) on $(strip $(PLATFORM)) should not be larger than 256) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(call lt,$(strip $(FS_SORT_MAX_ENTRY)),64),T)
      $(warning ERROR: FS_SORT_MAX_ENTRY value ($(FS_SORT_MAX_ENTRY)) on $(strip $(PLATFORM)) should not be less than 64) 
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef FS_SORT_SUPPORT
  ifeq ($(strip $(FS_SORT_SUPPORT)),TRUE)
    COM_DEFS   += __FS_SORT_SUPPORT__ FS_SORT_MAX_ENTRY=$(strip $(FS_SORT_MAX_ENTRY))
  endif
endif

ifdef FS_CHECKDRIVE_SUPPORT
  ifeq ($(strip $(FS_CHECKDRIVE_SUPPORT)),TRUE)
    COM_DEFS   += __FS_CHECKDRIVE_SUPPORT__
  else
    ifeq ($(strip $(NAND_SUPPORT)), TRUE)
      $(warning WARNING recommend set FS_CHECKDRIVE_SUPPORT=TRUE when NAND_SUPPORT=TRUE)
    else
      ifneq ($(strip $(MSDC_CARD_SUPPORT_TYPE)), NONE)
        $(warning WARNING recommend set FS_CHECKDRIVE_SUPPORT=TRUE when MSDC_CARD_SUPPORT_TYPE!=NONE)
      endif
    endif
  endif
endif

ifdef FS_QM_SUPPORT
  ifeq ($(strip $(FS_QM_SUPPORT)),TRUE)
    COM_DEFS   += __FS_QM_SUPPORT__
  endif
endif

ifdef TST_SUPPORT
  ifeq ($(strip $(call Upper,$(PROJECT))),BASIC)
    ifeq ($(strip $(TST_SUPPORT)),TRUE)
      $(warning ERROR: TST_SUPPORT should be FALSE in BASIC project)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif
  
ifdef FS_TRACE_SUPPORT
  ifdef TST_SUPPORT
    ifdef PRODUCTION_RELEASE
      ifeq ($(strip $(FS_TRACE_SUPPORT)),TRUE)
        ifeq ($(strip $(TST_SUPPORT)),TRUE)
          ifeq ($(strip $(PRODUCTION_RELEASE)),FALSE)
            COM_DEFS   += __FS_TRACE_SUPPORT__
            COMP_TRACE_DEFS += kal\efs\include\fs_trc.h
          else
            ifdef CUST_CODE
              ifeq ($(strip $(CUST_CODE)),TC01)
                COM_DEFS   += __FS_TRACE_SUPPORT__
                COMP_TRACE_DEFS += kal\efs\include\fs_trc.h
              endif
            else
              $(call DEP_ERR_OFFA_OR_OFFB,PRODUCTION_RELEASE,FS_TRACE_SUPPORT)
              DEPENDENCY_CONFLICT = TRUE
            endif
          endif
        else
          $(call DEP_ERR_ONA_OR_OFFB,TST_SUPPORT,FS_TRACE_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
  endif
endif

ifdef AMRWB_DECODE
  ifeq ($(strip $(AMRWB_DECODE)),TRUE)
    AMRWB_DECODE_NOT_SUPPORT_PLATFORM = MT6205B MT6218 MT6208 MT6218B MT6217 MT6223 MT6223P MT6253E MT6253L MT6252 MT6252H
    ifneq ($(filter $(strip $(PLATFORM)),$(AMRWB_DECODE_NOT_SUPPORT_PLATFORM)),)
      $(warning ERROR: Platform $(strip $(PLATFORM)) not support AMRWB_DECODE!) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS   += AMRWB_DECODE
  endif
endif

ifdef AMRWB_ENCODE
  ifeq ($(strip $(AMRWB_ENCODE)),TRUE)
    AMRWB_ENCODE_NOT_SUPPORT_PLATFORM = MT6205B MT6218 MT6208 MT6218B MT6217 MT6219 MT6223 MT6223P MT6253E MT6253L MT6252 MT6252H
    ifneq ($(filter $(strip $(PLATFORM)),$(AMRWB_ENCODE_NOT_SUPPORT_PLATFORM)),)
      $(warning ERROR: Platform $(strip $(PLATFORM)) not support AMRWB_ENCODE!)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS   += AMRWB_ENCODE
  endif
endif

ifdef EES_ENABLE
  ifeq ($(strip $(EES_ENABLE)),TRUE)
    ifeq ($(strip $(PLATFORM)),MT6205B)
      $(warning ERROR: Platform $(strip $(PLATFORM)) does not support EES_ENABLE!) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += EES_ENABLE
  else
    ifneq ($(strip $(PLATFORM)),MT6205B)
      ifdef IC_TEST_TYPE
        ifneq ($(strip $(IC_TEST_TYPE)),IC_BURNIN_TEST)
          $(warning ERROR: EES_ENABLE is a mandatory feature. Please turn on EES_ENABLE!)
          DEPENDENCY_CONFLICT = TRUE 
        endif
      endif
    endif
  endif
endif

ifdef AEC_ENABLE
  ifeq ($(strip $(AEC_ENABLE)),TRUE)
    ifeq ($(strip $(PLATFORM)),MT6205B)
      $(warning ERROR: Platform $(strip $(PLATFORM)) does not support AEC_ENABLE!) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += AEC_ENABLE
  else
    ifneq ($(strip $(PLATFORM)),MT6205B)
      ifdef IC_TEST_TYPE
        ifneq ($(strip $(IC_TEST_TYPE)),IC_BURNIN_TEST)
          $(warning ERROR: AEC_ENABLE is a mandatory feature. Please turn on AEC_ENABLE!)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
  endif
endif

ifdef IC_TEST_TYPE
  ifneq ($(strip $(IC_TEST_TYPE)),NONE)
    CUS_REL_MTK_COMP  +=  btmt
  endif
endif

ifdef EMAIL_SUPPORT
  ifneq ($(strip $(EMAIL_SUPPORT)),NONE)
     COM_DEFS    += __EMAIL__  __EMAIL_AUTO_CHECK__ __POP3_LEAVE_COPY_ON_SERVER__
     COM_DEFS    += __EMAIL_DOWNLOAD_OPTION__  EMAIL_BCC  __EMAIL_USE_ASM_ADM__
     COM_DEFS    += __EMAIL_SORT_SUPPORT_SUBJECT__  __EMAIL_SORT_SUPPORT_SENDER__
     COM_DEFS    += __IMAP_REMOTE_FOLDER__  __EMAIL_APOP_SUPPORT__

     ifeq ($(strip $(EMAIL_SUPPORT)),SMTP_POP3)
        COM_DEFS    += __NO_IMAP__
     endif
  endif
endif



#BT_A2DP_PROFILE was not supported on MT6205/6217/6218/6219/6223 platforms
ifdef BT_A2DP_PROFILE
  ifeq ($(strip $(BT_A2DP_PROFILE)),TRUE)
    BT_A2DP_PROFILE_NOT_SUPPORT_PLATFORM = MT6205 MT6217 MT6218 MT6219 MT6223 MT6223P 
    ifneq ($(filter $(strip $(PLATFORM)),$(BT_A2DP_PROFILE_NOT_SUPPORT_PLATFORM)),)
      $(warning ERROR: Platform $(strip $(PLATFORM)) does not support BT_A2DP_PROFILE!) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    COMPLIST += dp_engine
    CUS_REL_MTK_COMP += dp_engine
  endif
endif

#BT_AVRCP_PROFILE was not supported on MT6205/6217/6218/6219/6223 platforms
ifdef BT_AVRCP_PROFILE
  ifeq ($(strip $(BT_AVRCP_PROFILE)),TRUE)
      BT_AVRCP_PROFILE_NOT_SUPPORT_PLATFORM = MT6205 MT6217 MT6218 MT6219 MT6223 MT6223P 
      ifneq ($(filter $(strip $(PLATFORM)),$(BT_AVRCP_PROFILE_NOT_SUPPORT_PLATFORM)),)
          $(warning ERROR: Platform $(strip $(PLATFORM)) does not support BT_AVRCP_PROFILE!) 
          DEPENDENCY_CONFLICT = TRUE
      endif
  endif
endif

ifdef MERCURY_SLAVE_BT_SUPPORT
  ifeq ($(strip $(MERCURY_SLAVE_BT_SUPPORT)),TRUE)
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,MERCURY_SLAVE_BT_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif  

ifeq ($(strip $(BT_SEQ_SUPPORT)),TRUE)
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_SEQ_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    endif
    ifndef BLUETOOTH_SUPPORT
        $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_SEQ_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    +=  __BT_SEQ_SUPPORT__
endif

BLUETOOTH_SUPPORT_CHIP = BTMTK_MT6601 BTMTK_MT6611 BTMTK_MT6612 BTMTK_MT6236 BTMTK_MT6616 BTMTK_MT6622 BTMTK_MT6626 BTMTK_MT6612_22_26
# NONE, BTMTK, BTMTK_MT6601, BTMTK_MT6611, BTMTK_MT6612, BTMTK_MT6236, BTMTK_MT6616 BTMTK_MT6612_22_26
ifdef BLUETOOTH_SUPPORT
  ifneq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
    COM_DEFS    +=  __BT_SUPPORT__
    ifneq ($(strip $(DMA_UART_VIRTUAL_FIFO)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,DMA_UART_VIRTUAL_FIFO,BLUETOOTH_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifdef CMUX_SUPPORT
      ifeq ($(strip $(CMUX_SUPPORT)),TRUE)
        $(call DEP_ERR_OFFA_OR_OFFB,CMUX_SUPPORT,BLUETOOTH_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifneq ($(strip $(UART3_SUPPORT)),TRUE)
       $(call DEP_ERR_ONA_OR_OFFB,UART3_SUPPORT,BLUETOOTH_SUPPORT)
       DEPENDENCY_CONFLICT = TRUE
    endif

    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK)
      COM_DEFS    +=  __BTMTK__ __BTMODULE_RFMD3500__
    endif
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6601)
      COM_DEFS    +=  __BTMTK__ __BTMODULE_MT6601__
    endif    
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6611)
      COM_DEFS    +=  __BTMTK__ __BTMODULE_MT6611__
    endif
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6612)
      COM_DEFS    +=  __BTMTK__ __BTMODULE_MT6612__ __BTMODULE_MT6612_22_26__
    endif
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6236)
      COM_DEFS    +=  __BTMTK__ __BTMODULE_MT6236__ __BRT_SUPPORT__
    endif
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6616)
      COM_DEFS    +=  __BTMTK__ __BTMODULE_MT6616__
    endif
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6622)
      COM_DEFS    +=  __BTMTK__ __BTMODULE_MT6622__ __BTMODULE_MT6622_26__
    endif
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6626)
      COM_DEFS    +=  __BTMTK__ __BTMODULE_MT6626__ __BTMODULE_MT6622_26__
    endif
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6612_22_26)
      COM_DEFS    +=  __BTMTK__ __BTMODULE_MT6612__ __BTMODULE_MT6622__ __BTMODULE_MT6626__ __BTMODULE_MT6622_26__
    endif
    ifeq ($(strip $(BT_HFG_PROFILE)),TRUE)
      COM_DEFS    +=  __BT_HFG_PROFILE__ __BT_SPK_VOL_CONTROL__
      ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK)
        COM_DEFS    +=  __HF_V15__
      endif
      ifneq ($(filter $(strip $(BLUETOOTH_SUPPORT)),$(BLUETOOTH_SUPPORT_CHIP)),)
        COM_DEFS    +=  __HF_V15__
      endif
    endif
    ifeq ($(strip $(BT_AUDIO_VIA_SCO)),TRUE)
      BT_AUDIO_VIA_SCO_NOT_SUPPORT_PLATFORM = MT6205B MT6217 MT6218B MT6219 MT6516 
      ifneq ($(filter $(strip $(PLATFORM)),$(BT_AUDIO_VIA_SCO_NOT_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support BT_AUDIO_VIA_SCO) 
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifdef FM_RADIO_CHIP
        ifneq ($(strip $(FM_RADIO_CHIP)),NONE)
          ifneq ($(strip $(BT_FM_RADIO_VIA_SCO)),TRUE)
            $(call DEP_ERR_ONA_OR_OFFB,BT_FM_RADIO_VIA_SCO,BT_AUDIO_VIA_SCO or FM_RADIO_CHIP)
            DEPENDENCY_CONFLICT = TRUE
          endif
        endif
      endif
      COM_DEFS    +=  __BT_AUDIO_VIA_SCO__
      COM_DEFS    +=  __BT_INBAND_RING__
      COMPLIST += dp_engine
      CUS_REL_MTK_COMP += dp_engine
    endif
    ifeq ($(strip $(BT_FM_RADIO_VIA_SCO)),TRUE)
      ifdef FM_RADIO_CHIP
        ifneq ($(strip $(FM_RADIO_CHIP)),NONE)
          COM_DEFS    +=  __BT_FM_VIA_SCO__
        endif
      endif
    endif
    ifeq ($(strip $(BT_FTS_PROFILE)),TRUE)
      COM_DEFS    +=  __BT_FTS_PROFILE__
    endif
    ifeq ($(strip $(BT_FTC_PROFILE)),TRUE)
      ifneq ($(strip $(XML_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,XML_SUPPORT,BT_FTC_PROFILE)
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS    +=  __BT_FTC_PROFILE__
    endif
    ifeq ($(strip $(BT_OPP_PROFILE)),TRUE)
      COM_DEFS    +=  __BT_OPP_PROFILE__
    endif
    ifeq ($(strip $(BT_DUN_PROFILE)),TRUE)
      COM_DEFS    +=  __BT_DUN_PROFILE__
    endif

    ifeq ($(filter $(strip $(BLUETOOTH_SUPPORT)),$(BLUETOOTH_SUPPORT_CHIP)),)
      ifneq ($(strip $(BT_SPP_SERVER)),NONE)
        $(call DEP_ERR_SETA_OR_OFFB,BLUETOOTH_SUPPORT,BTMTK_MT6601/BTMTK_MT6611/BTMTK_MT6612/BTMTK_MT6236/BTMTK_MT6616/BTMTK_MT6622/BTMTK_MT6626/BTMTK_MT6612_22_26,BT_SPP_SERVER)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifneq ($(strip $(BT_SPP_CLIENT)),NONE)
        $(call DEP_ERR_SETA_OR_OFFB,BLUETOOTH_SUPPORT,BTMTK_MT6601/BTMTK_MT6611/BTMTK_MT6612/BTMTK_MT6236/BTMTK_MT6616/BTMTK_MT6622/BTMTK_MT6626/BTMTK_MT6612_22_26,BT_SPP_CLIENT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    
    ifneq ($(filter $(strip $(BLUETOOTH_SUPPORT)),$(BLUETOOTH_SUPPORT_CHIP)),)
      ifeq ($(strip $(BT_SPP_SERVER)),NONE)
        ifeq ($(strip $(BT_SPP_CLIENT)),NONE)
          ifeq ($(strip $(BT_SPP_PROFILE)),TRUE)
            $(call DEP_ERR_ONA_OR_OFFB,BT_SPP_SERVER & BT_SPP_CLIENT,BT_SPP_PROFILE)
            DEPENDENCY_CONFLICT = TRUE
          endif
        endif
      endif
      ifneq ($(strip $(BT_SPP_SERVER)),NONE)
        ifeq ($(strip $(BT_SPP_PROFILE)),FALSE)
          $(call DEP_ERR_ONA_OR_OFFB,BT_SPP_PROFILE,BT_SPP_SERVER)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
      ifneq ($(strip $(BT_SPP_CLIENT)),NONE)
        ifeq ($(strip $(BT_SPP_PROFILE)),FALSE)
          $(call DEP_ERR_ONA_OR_OFFB,BT_SPP_PROFILE,BT_SPP_CLIENT)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
          
    ifneq ($(filter $(strip $(BLUETOOTH_SUPPORT)),$(BLUETOOTH_SUPPORT_CHIP)),)
      ifeq ($(strip $(BT_SPP_SERVER)),BT_SPP_SRV_NO_SCO)
        COM_DEFS    +=  __BT_SPP_SRV_NO_SCO__
      endif
      ifeq ($(strip $(BT_SPP_SERVER)),BT_SPP_SRV_WITH_SCO)
        COM_DEFS    +=  __BT_SPP_SRV_WITH_SCO__
      endif
      ifeq ($(strip $(BT_SPP_CLIENT)),BT_SPP_CLI_NO_SCO)
        COM_DEFS    +=  __BT_SPP_CLI_NO_SCO__
      endif
      ifeq ($(strip $(BT_SPP_CLIENT)),BT_SPP_CLI_WITH_SCO)
        COM_DEFS    +=  __BT_SPP_CLI_WITH_SCO__
      endif
    endif

    ifeq ($(strip $(BT_SPP_PROFILE)),TRUE)
      COM_DEFS    +=  __BT_SPP_PROFILE__
    endif
    ifeq ($(strip $(BT_A2DP_PROFILE)),TRUE)
      COM_DEFS    +=  __BT_A2DP_PROFILE__ __BT_A2DP_SUPPORT__
    endif
    ifeq ($(strip $(BT_AVRCP_PROFILE)),TRUE)
      COM_DEFS    +=  __BT_AVRCP_PROFILE__
    endif
    ifeq ($(strip $(BT_SIM_PROFILE)),TRUE)
      COM_DEFS    +=  __BT_SIM_PROFILE__
    endif
    ifeq ($(strip $(BT_HIDD_PROFILE)),TRUE)
      COM_DEFS    +=  __BT_HIDD_PROFILE__
    endif
    ifeq ($(strip $(BT_BPP_PROFILE)),TRUE)
      ifneq ($(strip $(XML_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,XML_SUPPORT,BT_BPP_PROFILE)
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS    +=  	__BT_BPP_PROFILE__
    endif
  else
    ifeq ($(strip $(BT_HFG_PROFILE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_HFG_PROFILE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(BT_FTS_PROFILE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_FTS_PROFILE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(BT_FTC_PROFILE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_FTC_PROFILE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(BT_OPP_PROFILE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_OPP_PROFILE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(BT_DUN_PROFILE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_DUN_PROFILE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(BT_A2DP_PROFILE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_A2DP_PROFILE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(BT_AVRCP_PROFILE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_AVRCP_PROFILE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(BT_SPP_SERVER)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_SPP_SERVER)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(BT_SPP_CLIENT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_SPP_CLIENT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(BT_SPP_PROFILE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_SPP_PROFILE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(BT_FM_RADIO_VIA_SCO)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_FM_RADIO_VIA_SCO)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(BT_HIDD_PROFILE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_HIDD_PROFILE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifeq ($(strip $(BT_DUN_PROFILE)),TRUE)
  ifneq ($(strip $(BT_SPP_PROFILE)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,BT_SPP_PROFILE,BT_DUN_PROFILE)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(BT_SPP_SERVER)),NONE)
    $(call DEP_ERR_ONA_OR_OFFB,BT_SPP_SERVER,BT_DUN_PROFILE)
    DEPENDENCY_CONFLICT = TRUE
  endif  
endif

ifeq ($(strip $(BT_FAX_PROFILE)),TRUE)
  ifneq ($(strip $(BT_SPP_PROFILE)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,BT_SPP_PROFILE,BT_FAX_PROFILE)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(BT_SPP_SERVER)),NONE)
    $(call DEP_ERR_ONA_OR_OFFB,BT_SPP_SERVER,BT_FAX_PROFILE)
    DEPENDENCY_CONFLICT = TRUE
  endif  
endif

ifdef BLUETOOTH_SUPPORT
  ifneq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
    ifeq ($(strip $(BLUETOOTH_VERSION)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_VERSION,BLUETOOTH_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef BLUETOOTH_VERSION
  ifneq ($(strip $(BLUETOOTH_VERSION)),NONE)
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BLUETOOTH_VERSION)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(BLUETOOTH_VERSION)),BT_VER_21)
      COM_DEFS    +=  __BT_VER_21__
    endif
    ifeq ($(strip $(BLUETOOTH_VERSION)),BT_VER_30)
      COM_DEFS    +=  __BT_VER_30__
    endif
  endif
endif

ifdef JPG_DECODE
  ifneq ($(strip $(JPG_DECODE)),NONE)
    ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
      $(warning ERROR: NEPTUNE_MMI does not support JPG_DECODE, please set JPG_DECODE=NONE) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += JPG_DECODE
  endif
endif

# only MT6238 supports PNG_HW
PNG_DECODE_HW_PLATFORM = MT6238 MT6239 MT6268A MT6268 MT6270A 
ifdef PNG_DECODE
  ifeq ($(filter $(strip $(PLATFORM)) ,$(PNG_DECODE_HW_PLATFORM)),)
    ifeq ($(strip $(PNG_DECODE)),PNG_HW)
      $(warning ERROR: $(strip $(PLATFORM)) does not support PNG_HW) 
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
  PNG_DECODE_HW_NOT_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6235 MT6235B MT6236 MT6236B MT6225 MT6253T MT6253 MT6253E MT6253L MT6223 MT6223P MT6252 MT6252H
  ifeq ($(strip $(PNG_DECODE)),PNG_HW)
    ifneq ($(filter $(strip $(PLATFORM)),$(strip $(PNG_DECODE_HW_NOT_SUPPORT_PLATFORM))),)
      $(warning ERROR: $(strip $(PLATFORM)) does NOT support PNG_DECODE=$(strip $(PNG_DECODE))) 
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif

  JPG_CODEC_HW_NOT_SUPPORT_PLATFORM = MT6225 MT6253T MT6253 MT6253E MT6253L MT6223 MT6223P MT6252 MT6252H
  ifeq ($(strip $(JPG_DECODE)),JPG_HW)
    ifneq ($(filter $(strip $(PLATFORM)),$(strip $(JPG_CODEC_HW_NOT_SUPPORT_PLATFORM))),)
      $(warning ERROR: $(strip $(PLATFORM)) does NOT support JPG_DECODE=$(strip $(JPG_DECODE))) 
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(JPG_ENCODE)),JPG_HW)
    ifneq ($(filter $(strip $(PLATFORM)),$(strip $(JPG_CODEC_HW_NOT_SUPPORT_PLATFORM))),)
      $(warning ERROR: $(strip $(PLATFORM)) does NOT support JPG_ENCODE=$(strip $(JPG_ENCODE))) 
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif


ifdef GIF_DECODE
  ifneq ($(strip $(GIF_DECODE)),NONE)  
    COM_DEFS    += GIF_DECODE
    
    ifeq ($(strip $(GIF_DECODE)),GIF_SW)
      COM_DEFS    += USE_SW_GIF_DECODER
    endif
    
    GIF_DECODE_NOT_SUPPORT_PLATFORM = MT6205B MT6217 MT6218B MT6223 MT6223P MT6225 MT6235 MT6235B MT6238 MT6239 MT6253 MT6253D MT6253T
    ifeq ($(strip $(GIF_DECODE)),GIF_HW)
      ifneq ($(filter $(strip $(PLATFORM)),$(GIF_DECODE_NOT_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support hardware GIF decoder, please set GIF_DECODE to GIF_SW or NONE)
        DEPENDENCY_CONFLICT = TRUE
      endif
      
      COM_DEFS    +=   USE_SW_GIF_DECODER
      
      ifeq ($(strip $(PLATFORM)),MT6219)
        COM_DEFS    +=   USE_HW_GIF_DECODER_V1
      endif    
      ifeq ($(strip $(PLATFORM)),MT6226)
        COM_DEFS    +=   USE_HW_GIF_DECODER_V1
      endif
      ifeq ($(strip $(PLATFORM)),MT6226M)
        COM_DEFS    +=   USE_HW_GIF_DECODER_V1
      endif
      ifeq ($(strip $(PLATFORM)),MT6226D)
        COM_DEFS    +=   USE_HW_GIF_DECODER_V1
      endif
      ifeq ($(strip $(PLATFORM)),MT6227)
        COM_DEFS    +=   USE_HW_GIF_DECODER_V1
      endif
      ifeq ($(strip $(PLATFORM)),MT6227D)
        COM_DEFS    +=   USE_HW_GIF_DECODER_V1
      endif
      ifeq ($(strip $(PLATFORM)),MT6228)
        COM_DEFS    +=   USE_HW_GIF_DECODER_V2
      endif
      ifeq ($(strip $(PLATFORM)),MT6229)
        COM_DEFS    +=   USE_HW_GIF_DECODER_V2
      endif
      ifeq ($(strip $(PLATFORM)),MT6230)
        COM_DEFS    +=   USE_HW_GIF_DECODER_V2
      endif
      ifeq ($(strip $(PLATFORM)),MT6268T)
        COM_DEFS    +=   USE_HW_GIF_DECODER_V2
      endif
      ifeq ($(strip $(PLATFORM)),MT6268H)
        COM_DEFS    +=   USE_HW_GIF_DECODER_V2
      endif
      ifeq ($(strip $(PLATFORM)),MT6268A)
        COM_DEFS    +=   USE_HW_GIF_DECODER_V3
      endif
      ifeq ($(strip $(PLATFORM)),MT6268)
        COM_DEFS    +=   USE_HW_GIF_DECODER_V3
      endif      
    endif
  endif
endif


ifdef PNG_DECODE
  ifneq ($(strip $(PNG_DECODE)),NONE)
    PNG_HW_DECODE_SUPPORT_PLATFORM = MT6238 MT6239 MT6268 MT6268A MT6270A 
    ifeq ($(strip $(PNG_DECODE)),PNG_HW)
      ifeq ($(filter $(strip $(PLATFORM)),$(PNG_HW_DECODE_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support PNG_DECODE) 
        DEPENDENCY_CONFLICT = TRUE
      else
        COM_DEFS    += USE_HW_PNG_DECODER
      endif
    else
      ifeq ($(strip $(PNG_DECODE)),PNG_SW)
        COM_DEFS    += USE_SW_PNG_DECODER
      endif
    endif
  endif
endif


# sw_jpeg_code only release OBJ!! 
##  CUS_REL_BASE_COMP   +=  image_codec\sw_jpeg_codec 
##  CUS_REL_BASE_COMP   +=  image_codec\common 

ifeq ($(strip $(JPG_DECODE)),JPG_SW)
#  COMPLIST    += sw_jpeg_codec
#  CUS_REL_MTK_COMP  += sw_jpeg_codec
  COM_DEFS    += __SW_JPEG_CODEC_SUPPORT__
  COMMINCDIRS   +=  image_codec\sw_jpeg_codec\include
else
  ifeq ($(strip $(JPG_ENCODE)),JPG_SW)
#    COMPLIST    += sw_jpeg_codec
#    CUS_REL_MTK_COMP  += sw_jpeg_codec
    COM_DEFS    += __SW_JPEG_CODEC_SUPPORT__
    COMMINCDIRS   +=  image_codec\sw_jpeg_codec\include
  endif
endif


ifeq ($(strip $(DAF_DECODE)),TRUE)
   DAF_DECODE_SUPPORT_PLATFORM = MT6217 MT6218B MT6219 MT6226M MT6228 MT6229 MT6230 MT6226 MT6227 MT6225 MT6253T MT6253 MT6253E MT6253L MT6252 MT6252H MT6223 MT6227D MT6226D MT6223P MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6268T MT6268H MT6268A MT6268 MT6270A
  ifeq ($(filter $(strip $(PLATFORM)) ,$(DAF_DECODE_SUPPORT_PLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support DAF_DECODE.) 
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(COMPILER)),ADS)
    COMPOBJS         += l1audio\mp3frmlen\mp3frmlen.a
    CUS_REL_OBJ_LIST += l1audio\mp3frmlen\mp3frmlen.a
  endif
  ifeq ($(strip $(COMPILER)),RVCT)
    COMPOBJS         += l1audio\mp3frmlen\mp3frmlen_rvct.a
    CUS_REL_OBJ_LIST += l1audio\mp3frmlen\mp3frmlen_rvct.a
  endif  
  COM_DEFS += DAF_DECODE
endif


## MT6217, 6219, 6227_S00 and 6228_S00, 6228_S01 and 6229_S00, 6223 not support MUSICAM_DECODE
ifdef MUSICAM_DECODE
  MUSICAM_DECODE_NOT_SUPPORT_PLATFORM = MT6217 MT6218B MT6219 MT6223 MT6253E MT6253L MT6252 MT6252H
  ifeq ($(strip $(MUSICAM_DECODE)),TRUE)
    ifneq ($(filter $(strip $(PLATFORM)),$(MUSICAM_DECODE_NOT_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) not support MUSICAM_DECODE.) 
      DEPENDENCY_CONFLICT = TRUE
    endif  
    ifeq ($(strip $(PLATFORM)),MT6227)
      ifeq ($(strip $(CHIP_VER)),S00)  
        $(warning ERROR: platform $(strip $(PLATFORM)) with chip version $(CHIP_VER) not support MUSICAM_DECODE.) 
        DEPENDENCY_CONFLICT = TRUE  
      endif      
    endif
    ifeq ($(strip $(PLATFORM)),MT6228)
      ifeq ($(strip $(CHIP_VER)),S00)  
        $(warning ERROR: platform $(strip $(PLATFORM)) with chip version $(CHIP_VER) not support MUSICAM_DECODE.)   
        DEPENDENCY_CONFLICT = TRUE
      endif      
      ifeq ($(strip $(CHIP_VER)),S01)  
        $(warning ERROR: platform $(strip $(PLATFORM)) with chip version $(CHIP_VER) not support MUSICAM_DECODE.)   
        DEPENDENCY_CONFLICT = TRUE
      endif          
    endif
    ifeq ($(strip $(PLATFORM)),MT6229)
      ifeq ($(strip $(CHIP_VER)),S00)  
        $(warning ERROR: platform $(strip $(PLATFORM)) with chip version $(CHIP_VER) not support MUSICAM_DECODE.)   
        DEPENDENCY_CONFLICT = TRUE
      endif      
    endif

    ifeq ($(strip $(DAF_DECODE)),TRUE)
      COM_DEFS    += MUSICAM_DECODE
    else
      $(call DEP_ERR_ONA_OR_OFFB,DAF_DECODE,MUSICAM_DECODE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif


ifneq ($(strip $(JPG_ENCODE)),NONE)
  COM_DEFS    += JPG_ENCODE
endif

ifeq ($(strip $(AAC_DECODE)),TRUE)
   AAC_DECODE_SUPPORT_PLATFORM = MT6219 MT6226M MT6228 MT6229 MT6230 MT6226 MT6227 MT6225 MT6253T MT6253 MT6253E MT6253L MT6252 MT6252H MT6227D MT6226D MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6268T MT6268H MT6268A MT6268 MT6270A
   ifeq ($(filter $(strip $(PLATFORM)) ,$(AAC_DECODE_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) not support AAC_DECODE.) 
      DEPENDENCY_CONFLICT = TRUE
   endif
   COM_DEFS    += AAC_DECODE
endif

ifeq ($(strip $(ISP_SUPPORT)),TRUE)
  COM_DEFS    += ISP_SUPPORT
endif

DIRECT_IF_V2_PLATFORM = NONE
SERIAL_IF_V1_PLATFORM = MT6253E MT6253L MT6252 MT6252H

ifdef SENSOR_TYPE
  ifneq ($(strip $(SENSOR_TYPE)),NONE)
    ifdef CMOS_SENSOR   
      ifneq ($(strip $(CMOS_SENSOR)),NONE)
        ifeq ($(strip $(SENSOR_TYPE)),RAW)
          COM_DEFS += RAW_MAIN_CAMERA
        endif
        ifeq ($(strip $(SENSOR_TYPE)),YUV)
          COM_DEFS += YUV_MAIN_CAMERA   
          ifneq ($(filter $(strip $(PLATFORM)),$(DIRECT_IF_V2_PLATFORM)),)
            ifneq ($(findstring _DIRECT,$(CMOS_SENSOR)),)
              COM_DEFS += __DIRECT_SENSOR_V2_SUPPORT__
            endif
          endif      
          ifneq ($(filter $(strip $(PLATFORM)),$(SERIAL_IF_V1_PLATFORM)),)
            ifneq ($(findstring _SERIAL,$(CMOS_SENSOR)),)
              COM_DEFS += __SERIAL_SENSOR_V1_SUPPORT__
            endif
          endif
        endif
        ifneq ($(findstring _DIRECT,$(CMOS_SENSOR)),)
          COM_DEFS += DIRECT_V2_MAIN_CAMERA
        endif
        ifneq ($(findstring _SERIAL,$(CMOS_SENSOR)),)    
          COM_DEFS += SERIAL_V1_MAIN_CAMERA
        endif
      endif
    endif    
    ifdef CMOS_SENSOR_BAK1   
      ifneq ($(strip $(CMOS_SENSOR_BAK1)),NONE)
        ifeq ($(strip $(SENSOR_TYPE)),RAW)
          COM_DEFS += RAW_BAK1_CAMERA
        endif
        ifeq ($(strip $(SENSOR_TYPE)),YUV)
          COM_DEFS += YUV_BAK1_CAMERA
          ifneq ($(filter $(strip $(PLATFORM)),$(DIRECT_IF_V2_PLATFORM)),)
            ifneq ($(findstring _DIRECT,$(CMOS_SENSOR_BAK1)),)
              COM_DEFS += __DIRECT_SENSOR_V2_SUPPORT__
            endif
          endif      
          ifneq ($(filter $(strip $(PLATFORM)),$(SERIAL_IF_V1_PLATFORM)),)           
            ifneq ($(findstring _SERIAL,$(CMOS_SENSOR_BAK1)),)
              COM_DEFS += __SERIAL_SENSOR_V1_SUPPORT__
            endif
          endif                        
        endif
        ifneq ($(findstring _DIRECT,$(CMOS_SENSOR_BAK1)),)
          COM_DEFS += DIRECT_V2_BAK1_CAMERA          
        endif
        ifneq ($(findstring _SERIAL,$(CMOS_SENSOR_BAK1)),)
          COM_DEFS += SERIAL_V1_BAK1_CAMERA          
        endif
      endif
    endif  
  endif
endif

ifdef SENSOR_TYPE_SUB
  ifneq ($(strip $(SENSOR_TYPE_SUB)),NONE)
    ifdef CMOS_SENSOR_SUB
      ifneq ($(strip $(CMOS_SENSOR_SUB)),NONE)
        ifeq ($(strip $(SENSOR_TYPE_SUB)),RAW)
          COM_DEFS += RAW_SUB_CAMERA
        endif
        ifeq ($(strip $(SENSOR_TYPE_SUB)),YUV)
          COM_DEFS += YUV_SUB_CAMERA          
          ifneq ($(filter $(strip $(PLATFORM)),$(DIRECT_IF_V2_PLATFORM)),)
            ifneq ($(findstring _DIRECT,$(CMOS_SENSOR_SUB)),)
              COM_DEFS += __DIRECT_SENSOR_V2_SUPPORT__
            endif
          endif      
          ifneq ($(filter $(strip $(PLATFORM)),$(SERIAL_IF_V1_PLATFORM)),)           
            ifneq ($(findstring _SERIAL,$(CMOS_SENSOR_SUB)),)
              COM_DEFS += __SERIAL_SENSOR_V1_SUPPORT__
            endif
          endif     
        endif     
        ifneq ($(findstring _DIRECT,$(CMOS_SENSOR_SUB)),)
          COM_DEFS += DIRECT_V2_SUB_CAMERA          
       endif
        ifneq ($(findstring _SERIAL,$(CMOS_SENSOR_SUB)),)
          COM_DEFS += SERIAL_V1_SUB_CAMERA          
        endif
      endif
    endif 
    ifdef CMOS_SENSOR_SUB_BAK1 
      ifneq ($(strip $(CMOS_SENSOR_SUB_BAK1)),NONE)
        ifeq ($(strip $(SENSOR_TYPE_SUB)),RAW)
          COM_DEFS += RAW_SUB_BAK1_CAMERA
        endif
        ifeq ($(strip $(SENSOR_TYPE_SUB)),YUV)
          COM_DEFS += YUV_SUB_BAK1_CAMERA
          
          ifneq ($(filter $(strip $(PLATFORM)),$(DIRECT_IF_V2_PLATFORM)),)
            ifneq ($(findstring _DIRECT,$(CMOS_SENSOR_SUB_BAK1)),)
              COM_DEFS += __DIRECT_SENSOR_V2_SUPPORT__
            endif
          endif      
          ifneq ($(filter $(strip $(PLATFORM)),$(SERIAL_IF_V1_PLATFORM)),)           
            ifneq ($(findstring _SERIAL,$(CMOS_SENSOR_SUB_BAK1)),)
              COM_DEFS += __SERIAL_SENSOR_V1_SUPPORT__
            endif
          endif                     
        endif
        ifneq ($(findstring _DIRECT,$(CMOS_SENSOR_SUB_BAK1)),)
          COM_DEFS += DIRECT_V2_SUB_BAK1_CAMERA               
        endif
        ifneq ($(findstring _SERIAL,$(CMOS_SENSOR_SUB_BAK1)),)
          COM_DEFS += SERIAL_V1_SUB_BAK1_CAMERA              
        endif
      endif
    endif  
  endif
endif

ifdef CMOS_SENSOR
  ifneq ($(strip $(CMOS_SENSOR)),NONE)
    COM_DEFS += CMOS_SENSOR_MAIN $(strip $(CMOS_SENSOR))_$(strip $(SENSOR_TYPE)) $(strip $(CMOS_SENSOR))_$(strip $(SENSOR_TYPE))_MAIN
  endif
  ifeq ($(strip $(CMOS_SENSOR)),NONE)
    ifdef ISP_SUPPORT
      ifeq ($(strip $(ISP_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR,ISP_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifneq ($(findstring _MIPI,$(CMOS_SENSOR)),)
    COM_DEFS += MIPI_SENSOR_SUPPORT
  endif  
endif


ifdef LENS_MODULE
  ifneq ($(strip $(LENS_MODULE)),NONE)
    ifndef AF_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,AF_SUPPORT,LENS_MODULE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(AF_SUPPORT)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,AF_SUPPORT,LENS_MODULE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifndef CMOS_SENSOR
      $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR,LENS_MODULE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(CMOS_SENSOR)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR,LENS_MODULE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COMMINCDIRS    +=	custom\drv\lens_module\$(strip $(LENS_MODULE))
    COM_DEFS += $(strip $(LENS_MODULE)) 
  endif
endif

ifdef LENS_MODULE_BAK1
  ifneq ($(strip $(LENS_MODULE_BAK1)),NONE)
    ifndef CMOS_SENSOR_BAK1
      $(warning ERROR: Please define CMOS_SENSOR_BAK1 when LENS_MODULE_BAK1 is defined) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(CMOS_SENSOR_BAK1)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR_BAK1,LENS_MODULE_BAK1)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COMMINCDIRS    +=	custom\drv\lens_module\$(strip $(LENS_MODULE_BAK1))
    COM_DEFS += $(strip $(LENS_MODULE_BAK1)) 
  endif
endif

ifdef CMOS_SENSOR_SUB
  ifneq ($(strip $(CMOS_SENSOR_SUB)),NONE)
    ifeq ($(strip $(DUAL_CAMERA_SUPPORT)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,DUAL_CAMERA_SUPPORT,CMOS_SENSOR_SUB)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifndef SENSOR_TYPE_SUB
      $(call DEP_ERR_ONA_OR_OFFB,SENSOR_TYPE_SUB,CMOS_SENSOR_SUB)
      DEPENDENCY_CONFLICT = TRUE
    else
      ifeq ($(strip $(SENSOR_TYPE_SUB)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,SENSOR_TYPE_SUB,CMOS_SENSOR_SUB)
        DEPENDENCY_CONFLICT = TRUE
      else
        ifeq ($(strip $(SENSOR_TYPE_SUB)),RAW)
          COMMINCDIRS += custom\drv\image_sensor\$(strip $(CMOS_SENSOR_SUB))
        endif
        ifeq ($(strip $(SENSOR_TYPE_SUB)),YUV)
          COMMINCDIRS  +=	custom\drv\YUV_sensor\$(strip $(CMOS_SENSOR_SUB))
          COM_DEFS += YUV_SENSOR_SUPPORT
        endif
      endif
    endif
    COM_DEFS += CMOS_SENSOR_SUB $(strip $(CMOS_SENSOR_SUB))_$(strip $(SENSOR_TYPE_SUB)) $(strip $(CMOS_SENSOR_SUB))_$(strip $(SENSOR_TYPE_SUB))_SUB
  endif
endif

ifdef CMOS_SENSOR_BAK1
  ifndef LENS_MODULE_BAK1
    $(warning ERROR: Please define LENS_MODULE_BAK1 when CMOS_SENSOR_BAK1 is defined) 
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(CMOS_SENSOR_BAK1)),NONE)
    ifndef BACKUP_SENSOR_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,BACKUP_SENSOR_SUPPORT,CMOS_SENSOR_BAK1)
      DEPENDENCY_CONFLICT = TRUE
    else
      ifeq ($(strip $(BACKUP_SENSOR_SUPPORT)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,BACKUP_SENSOR_SUPPORT,CMOS_SENSOR_BAK1)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifndef SENSOR_TYPE
      $(call DEP_ERR_ONA_OR_OFFB,SENSOR_TYPE,CMOS_SENSOR_BAK1)
      DEPENDENCY_CONFLICT = TRUE
    else
      ifeq ($(strip $(SENSOR_TYPE)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,SENSOR_TYPE,CMOS_SENSOR_BAK1)
        DEPENDENCY_CONFLICT = TRUE
      else
        ifeq ($(strip $(SENSOR_TYPE)),RAW)
          COMMINCDIRS += custom\drv\image_sensor\$(strip $(CMOS_SENSOR_BAK1))
        endif
        ifeq ($(strip $(SENSOR_TYPE)),YUV)
          COMMINCDIRS  +=	custom\drv\YUV_sensor\$(strip $(CMOS_SENSOR_BAK1))
        endif
      endif
    endif    
    COM_DEFS += CMOS_SENSOR_BAK1 $(strip $(CMOS_SENSOR_BAK1))_$(strip $(SENSOR_TYPE)) $(strip $(CMOS_SENSOR_BAK1))_$(strip $(SENSOR_TYPE))_BAK1
  endif
endif

ifdef CMOS_SENSOR_SUB_BAK1
  ifneq ($(strip $(CMOS_SENSOR_SUB_BAK1)),NONE)
    ifndef BACKUP_SENSOR_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,BACKUP_SENSOR_SUPPORT,CMOS_SENSOR_SUB_BAK1)
      DEPENDENCY_CONFLICT = TRUE
    else
      ifeq ($(strip $(BACKUP_SENSOR_SUPPORT)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,BACKUP_SENSOR_SUPPORT,CMOS_SENSOR_SUB_BAK1)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifndef SENSOR_TYPE_SUB
      $(call DEP_ERR_ONA_OR_OFFB,SENSOR_TYPE_SUB,CMOS_SENSOR_SUB_BAK1)
      DEPENDENCY_CONFLICT = TRUE
    else
      ifeq ($(strip $(SENSOR_TYPE_SUB)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,SENSOR_TYPE_SUB,CMOS_SENSOR_SUB_BAK1)
        DEPENDENCY_CONFLICT = TRUE
      else
        ifeq ($(strip $(SENSOR_TYPE_SUB)),RAW)
          COMMINCDIRS += custom\drv\image_sensor\$(strip $(CMOS_SENSOR_SUB_BAK1))
        endif
        ifeq ($(strip $(SENSOR_TYPE_SUB)),YUV)
          COMMINCDIRS  +=	custom\drv\YUV_sensor\$(strip $(CMOS_SENSOR_SUB_BAK1))
          COM_DEFS += YUV_SENSOR_SUPPORT
        endif
      endif
    endif    
    COM_DEFS += CMOS_SENSOR_SUB_BAK1 $(strip $(CMOS_SENSOR_SUB_BAK1))_$(strip $(SENSOR_TYPE_SUB)) $(strip $(CMOS_SENSOR_SUB_BAK1))_$(strip $(SENSOR_TYPE_SUB))_SUB_BAK1
  endif
endif

DUAL_CAMERA_SUPPORT_PLATFORM = MT6238 MT6239 MT6268 MT6236
ifdef DUAL_CAMERA_SUPPORT
    ifeq ($(strip $(DUAL_CAMERA_SUPPORT)),TRUE)
      ifeq ($(filter $(strip $(PLATFORM)),$(DUAL_CAMERA_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does NOT support DUAL_CAMERA_SUPPORT )
      endif
    ifndef CMOS_SENSOR_SUB
      $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR_SUB,DUAL_CAMERA_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    else
      ifeq ($(strip $(CMOS_SENSOR_SUB)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR_SUB,DUAL_CAMERA_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    COM_DEFS += DUAL_CAMERA_SUPPORT
  else
    ifneq ($(strip $(CMOS_SENSOR_SUB)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,DUAL_CAMERA_SUPPORT,CMOS_SENSOR_SUB)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef BACKUP_SENSOR_SUPPORT
  ifeq ($(strip $(BACKUP_SENSOR_SUPPORT)),TRUE)
    ifndef CMOS_SENSOR_BAK1
      ifndef CMOS_SENSOR_SUB_BAK1
        $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR_BAK1/CMOS_SENSOR_SUB_BAK1,BACKUP_SENSOR_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      else
        ifeq ($(strip $(CMOS_SENSOR_SUB_BAK1)),NONE)
          $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR_BAK1/CMOS_SENSOR_SUB_BAK1,BACKUP_SENSOR_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif      
    else
      ifeq ($(strip $(CMOS_SENSOR_BAK1)),NONE)
        ifndef CMOS_SENSOR_SUB_BAK1
          $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR_BAK1/CMOS_SENSOR_SUB_BAK1,BACKUP_SENSOR_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
        else
          ifeq ($(strip $(CMOS_SENSOR_SUB_BAK1)),NONE)
            $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR_BAK1/CMOS_SENSOR_SUB_BAK1,BACKUP_SENSOR_SUPPORT)
            DEPENDENCY_CONFLICT = TRUE
          endif
        endif
      endif
    endif
    COM_DEFS += BACKUP_SENSOR_SUPPORT
  else
    ifdef CMOS_SENSOR_BAK1
      ifneq ($(strip $(CMOS_SENSOR_BAK1)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,BACKUP_SENSOR_SUPPORT,CMOS_SENSOR_BAK1)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifdef CMOS_SENSOR_SUB_BAK1
      ifneq ($(strip $(CMOS_SENSOR_SUB_BAK1)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,BACKUP_SENSOR_SUPPORT,CMOS_SENSOR_SUB_BAK1)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifdef LENS_MODULE_BAK1
      ifneq ($(strip $(LENS_MODULE_BAK1)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,BACKUP_SENSOR_SUPPORT,LENS_MODULE_BAK1)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifdef CMOS_SENSOR
  ifneq ($(strip $(CMOS_SENSOR)),NONE)
    ifneq ($(strip $(ISP_SUPPORT)),FALSE)
      COMMINCDIRS    += custom\drv\Camera_common
    endif
    COMMINCDIRS    += custom\drv\camera\$(strip $(BOARD_VER))
    ifeq ($(strip $(SENSOR_TYPE)),RAW)
      COMMINCDIRS    +=	custom\drv\image_sensor\$(strip $(CMOS_SENSOR))
    endif
    ifneq ($(filter $(strip $(PLATFORM)),$(DIRECT_IF_V2_PLATFORM)),)
      COMPLIST       += image_sensor_sec
      CUS_REL_SRC_COMP += image_sensor_sec
    endif    
    ifneq ($(filter $(strip $(PLATFORM)),$(SERIAL_IF_V1_PLATFORM)),)      
      COMPLIST       += image_sensor_sec
      CUS_REL_SRC_COMP += image_sensor_sec     	
    endif
    ifeq ($(strip $(SENSOR_TYPE)),YUV)
      COMMINCDIRS    +=	custom\drv\YUV_sensor\$(strip $(CMOS_SENSOR))
      COM_DEFS += YUV_SENSOR_SUPPORT
    endif
    ifeq ($(strip $(SENSOR_TYPE)),DIRECT)
      COMMINCDIRS    += custom\drv\direct_sensor \
                        drv\drv_sec\include \
                        media\camera\include
      COM_DEFS       += __DIRECT_SENSOR_SUPPORT__ __$(strip $(CMOS_SENSOR))__
      COMPLIST       += image_sensor_sec
      CUS_REL_SRC_COMP += image_sensor_sec
    endif
    ifdef SENSOR_TYPE
      ifneq ($(strip $(SENSOR_TYPE)),NONE)    
        CUS_REL_BASE_COMP  += custom\drv\Image_sensor \
                              custom\drv\YUV_sensor \
                              custom\drv\DIRECT_sensor \
                              custom\drv\Lens_module
      endif
    endif
  endif
endif 

ifdef SENSOR_ROTATE
  ifneq ($(strip $(SENSOR_ROTATE)),NONE)
    COM_DEFS    += $(strip $(SENSOR_ROTATE))
  endif
endif

ifdef SENSOR_SUB_ROTATE
  ifneq ($(strip $(SENSOR_SUB_ROTATE)),NONE)
    COM_DEFS    += SUB_$(strip $(SENSOR_SUB_ROTATE))
  endif
endif

ifdef SENSOR_LOCATION
  ifneq ($(strip $(SENSOR_LOCATION)),NONE)
    COM_DEFS    += $(strip $(SENSOR_LOCATION))
  endif
endif

ifdef MOTION_SENSOR_SUPPORT
  ifneq ($(strip $(MOTION_SENSOR_SUPPORT)),NONE)
    COM_DEFS    += $(strip $(MOTION_SENSOR_SUPPORT))
    COM_DEFS    += MOTION_SENSOR_SUPPORT
    COMMINCDIRS += custom\drv\motion_sensor\$(strip $(MOTION_SENSOR_SUPPORT))
    CUS_REL_BASE_COMP += custom\drv\motion_sensor
  endif
endif

ifdef CMUX_SUPPORT
  ifeq ($(strip $(CMUX_SUPPORT)),TRUE)
    COM_DEFS     += __CMUX_SUPPORT__
  endif
endif

ifdef DIGIT_TONE_SUPPORT
  ifeq ($(strip $(DIGIT_TONE_SUPPORT)),TRUE)
    COM_DEFS    +=  DIGIT_TONE_SUPPORT
  endif
endif

ifdef TTS
  ifneq ($(strip $(TTS)),NONE)
    COM_DEFS    +=  $(strip $(TTS))
  endif
endif

ifdef CUST_KEYPAD_TONE_SUPPORT
  ifeq ($(strip $(CUST_KEYPAD_TONE_SUPPORT)),TRUE)
    COM_DEFS    +=  CUST_KEYPAD_TONE_SUPPORT
  endif
endif

HORIZONTAL_CAMERA_SUPPORT_SIZE = 176X220 220X176 240X320 240X400 320X480 
ifdef HORIZONTAL_CAMERA
  ifeq ($(strip $(HORIZONTAL_CAMERA)),TRUE)
    ifeq ($(filter $(call Upper,$(strip $(MAIN_LCD_SIZE))),$(HORIZONTAL_CAMERA_SUPPORT_SIZE)),)
       $(warning ERROR: $(MAIN_LCD_SIZE) does not support HORIZONTAL_CAMERA. Please disable HORIZONTAL_CAMERA) 
       DEPENDENCY_CONFLICT = TRUE
    else
      COM_DEFS    += HORIZONTAL_CAMERA
    endif
  endif
endif

MJPG_SUPPORT_EXT_CAM_MODULE_DEP_PLATFORM = MT6217 MT6218B MT6225 MT6253T MT6253 MT6253E MT6253L MT6252 MT6252H MT6235 MT6235B MT6236 MT6236B MT6223P
ifneq ($(filter $(strip $(PLATFORM)) ,$(MJPG_SUPPORT_EXT_CAM_MODULE_DEP_PLATFORM)),)
  ifeq ($(strip $(PLATFORM)),MT6223P)
    ifneq ($(strip $(SENSOR_TYPE)),DIRECT)
      ifeq ($(strip $(MJPG_ENCODE)),TRUE)
        $(call DEP_ERR_SETA_OR_OFFB,SENSOR_TYPE,DIRECT,MJPG_ENCODE)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif


ifdef MJPG_ENCODE
  ifeq ($(strip $(MJPG_ENCODE)),TRUE)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(MJPG_SUPPORT_EXT_CAM_MODULE_DEP_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support MJPG_ENCODE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifdef MP4_ENCODE
      ifeq ($(strip $(MP4_ENCODE)),TRUE)
        $(call DEP_ERR_OFFA_OR_OFFB,MP4_ENCODE,MJPG_ENCODE)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifdef MJPG_DECODE
      ifneq ($(strip $(MJPG_DECODE)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,MJPG_DECODE,MJPG_ENCODE)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif

    ifeq ($(strip $(CMOS_SENSOR)),PO4010K)
      $(warning ERROR: $(strip $(CMOS_SENSOR)) does not support MJPG_ENCODE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(CMOS_SENSOR)),SIA100A)
      $(warning ERROR: $(strip $(CMOS_SENSOR)) does not support MJPG_ENCODE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += MJPG_ENCODE
  endif
endif

ifdef MJPG_DECODE
  ifeq ($(strip $(MJPG_DECODE)),TRUE)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(MJPG_SUPPORT_EXT_CAM_MODULE_DEP_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support MJPG_DECODE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += MJPG_DECODE
  endif
endif



ifdef MED_PROFILE
  COM_DEFS    += $(strip $(MED_PROFILE))
endif


ifdef XML_SUPPORT
  ifeq ($(strip $(XML_SUPPORT)),TRUE)
    ifeq ($(strip $(call Upper,$(PROJECT))),GSM)
      $(warning ERROR: GSM project does not support XML_SUPPORT) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS   += __XML_SUPPORT__
    COMMINCDIRS   +=  xmlp\include
  endif
endif

ifdef AMR_LINK_SUPPORT
  ifeq ($(strip $(AMR_LINK_SUPPORT)),TRUE)
    COM_DEFS   += __AMR_SUPPORT__
  endif
endif

ifeq ($(strip $(IMPS_SUPPORT)),TRUE)
  ifeq ($(findstring ORANGE,$(strip $(OPTR_SPEC))),)
    $(warning ERROR: IMPS_SUPPORT can not be turned on in non-ORANGE projects) 
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    += __IMPS__ IMPS_WV13_ENHANCEMENT
endif

ifneq ($(findstring ORANGE,$(strip $(OPTR_SPEC))),)
  ifneq ($(strip $(IMPS_SUPPORT)),TRUE)
     $(warning ERROR: IMPS_SUPPORT must be turned on in ORANGE projects) 
     DEPENDENCY_CONFLICT = TRUE
  endif
endif

TP_INTERNAL_SUPPORT_PLATFORM = MT6235 MT6235B MT6236 MT6236B MT6238 MT6239 MT6268 MT6268A MT6268 MT6516 MT6253 MT6253E MT6253L MT6253T MT6252 MT6252H MT6270A MT6276 MT6573 MT6255 MT6251
ifdef TOUCH_PANEL_SUPPORT
  CUS_REL_FILES_LIST += custom\drv\misc_drv\$(strip $(BOARD_VER))\touch_panel_custom.h
  CUS_REL_FILES_LIST += custom\drv\misc_drv\$(strip $(BOARD_VER))\touch_panel_spi.h
  ifneq ($(strip $(TOUCH_PANEL_SUPPORT)),NONE)
    ifdef HAND_WRITING
      ifeq ($(strip $(HAND_WRITING)),NONE)
        COM_DEFS += __NO_HANDWRITING__
      endif
    else
      COM_DEFS += __NO_HANDWRITING__
    endif
    ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
      $(warning ERROR: TOUCH_PANEL does not support NEPTUNE_MMI) 
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(TOUCH_PANEL_SUPPORT)),MT6301)
     COM_DEFS    += TOUCH_PANEL_SUPPORT
  endif
  ifeq ($(strip $(TOUCH_PANEL_SUPPORT)),MT6301B)
     COM_DEFS    += TOUCH_PANEL_SUPPORT
     COM_DEFS    += TOUCH_PANEL_PRESSURE
  endif
  ifeq ($(strip $(TOUCH_PANEL_SUPPORT)),TP_INTERNAL)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(TP_INTERNAL_SUPPORT_PLATFORM)),)
      $(warning ERROR: $(PLATFORM) does not support TOUCH_PANEL_SUPPORT = TP_INTERNAL) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += TOUCH_PANEL_SUPPORT
    COM_DEFS    += TOUCH_PANEL_PRESSURE
    COM_DEFS    += TOUCH_PANEL_INTERNAL
  endif
  ifneq ($(filter CTP_%,$(TOUCH_PANEL_SUPPORT)),)
    COM_DEFS    += TOUCH_PANEL_SUPPORT
    COM_DEFS    += __TOUCH_PANEL_CAPACITY__
    COM_DEFS    += __$(strip $(TOUCH_PANEL_SUPPORT))__
  endif 
endif


ifdef TOUCH_PANEL_SUPPORT
   ifeq ($(strip $(TOUCH_PANEL_SUPPORT)),NONE)
      ifeq ($(strip $(TOUCH_PANEL_SHORTCUT_SUPPORT)),TRUE)  
          $(call DEP_ERR_ONA_OR_OFFB,TOUCH_PANEL_SUPPORT,TOUCH_PANEL_SHORTCUT_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
      endif
   else 
      ifeq ($(strip $(TOUCH_PANEL_SHORTCUT_SUPPORT)),TRUE)
         COM_DEFS    += TOUCH_PANEL_SHORTCUT_SUPPORT
      endif
   endif     
endif

ifdef TOUCH_PAD_SUPPORT
   ifeq ($(strip $(TOUCH_PAD_SUPPORT)),TRUE)
     ifneq ($(strip $(DEMO_PROJECT)),TRUE)
       $(warning ERROR: TOUCH_PAD_SUPPORT can be turned on only in the internal project) 
       DEPENDENCY_CONFLICT = TRUE
     endif
     COM_DEFS  += TOUCH_PAD_SUPPORT
   endif
endif

ifndef GPRS_MAX_PDP_SUPPORT
     GPRS_MAX_PDP_SUPPORT = 2
     ifdef LOW_COST_SUPPORT
        ifneq ($(strip $(LOW_COST_SUPPORT)),NONE)
          GPRS_MAX_PDP_SUPPORT = 1
        endif
     endif
endif

ifdef GPRS_MAX_PDP_SUPPORT
     COM_DEFS    += GPRS_MAX_PDP_SUPPORT=$(strip $(GPRS_MAX_PDP_SUPPORT))
endif

# if do not define MAX_EXT_PDP_CONTEXT in make file, we will defaultly support 3 GPRS AT context ID
ifndef MAX_EXT_PDP_CONTEXT
    MAX_EXT_PDP_CONTEXT = 3
endif

# define MAX_EXT_PDP_CONTEXT = 0~7, depends on feature option setting from make file
COM_DEFS    += MAX_EXT_PDP_CONTEXT=$(strip $(MAX_EXT_PDP_CONTEXT))

ifdef UART3_SUPPORT
  ifeq ($(strip $(UART3_SUPPORT)),TRUE)
    UART3_NOT_SUPPORT_PLATFORM = MT6205 MT6208 MT6205B MT6208B
    ifneq ($(filter $(strip $(PLATFORM)),$(UART3_NOT_SUPPORT_PLATFORM)),)
       $(warning ERROR: PLATFORM $(strip $(PLATFORM)) not support UART3_SUPPORT.) 
       DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    +=	__UART3_SUPPORT__
    UART_PORT_FREE_COUNT = 1
  else
    UART_PORT_FREE_COUNT = 0
  endif
else
    UART_PORT_FREE_COUNT = 0
endif

ifdef BLUETOOTH_SUPPORT
   ifeq ($(strip $(BLUETOOTH_SUPPORT)), NONE)
      ifdef TOUCH_PAD_SUPPORT
        ifeq ($(strip $(TOUCH_PAD_SUPPORT)), TRUE)
          UART_PORT_USED_COUNT = 1
        else
          UART_PORT_USED_COUNT = 0
        endif
     else
      UART_PORT_USED_COUNT = 0
     endif
   else
     ifdef TOUCH_PAD_SUPPORT
        ifeq ($(strip $(TOUCH_PAD_SUPPORT)), TRUE)
           UART_PORT_USED_COUNT = 2
        else
           UART_PORT_USED_COUNT = 1
        endif
      else
        UART_PORT_USED_COUNT = 1
      endif
   endif
else
  ifdef TOUCH_PAD_SUPPORT
    ifeq ($(strip $(TOUCH_PAD_SUPPORT)), TRUE)
      UART_PORT_USED_COUNT = 1
    else
      UART_PORT_USED_COUNT = 0
    endif
  else
    UART_PORT_USED_COUNT = 0
  endif
endif

ifeq ($(strip $(UART_PORT_FREE_COUNT)),1)
   ifeq ($(strip $(UART_PORT_USED_COUNT)),2)
    # uart count is not enough for engineer mode
    COM_DEFS += __ONLY_ONE_UART__
  endif
endif

ifeq ($(strip $(UART_PORT_FREE_COUNT)),0)
  ifneq ($(strip $(UART_PORT_USED_COUNT)),0)
    # uart count is not enough for engineer mode
    COM_DEFS += __ONLY_ONE_UART__
  endif
endif



ifdef DMA_UART_VIRTUAL_FIFO
  VFIFO_NOT_SUPPORT_PLATFORM = MT6205 MT6208 MT6205B MT6208B
  ifneq ($(filter $(strip $(PLATFORM)),$(VFIFO_NOT_SUPPORT_PLATFORM)),)
    ifeq ($(strip $(DMA_UART_VIRTUAL_FIFO)),TRUE)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) dose NOT support DMA_UART_VIRTUAL_FIFO.) 
      DEPENDENCY_CONFLICT = TRUE
    endif
  else
    ifneq ($(strip $(DMA_UART_VIRTUAL_FIFO)),TRUE)
      $(warning ERROR: DMA_UART_VIRTUAL_FIFO is a mandatory feature on PLATFORM $(strip $(PLATFORM))) 
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(DMA_UART_VIRTUAL_FIFO)),TRUE)
    COM_DEFS    +=	__DMA_UART_VIRTUAL_FIFO__
  endif
endif


ifdef DMA_UART_VIRTUAL_FIFO
  ifeq ($(strip $(DMA_UART_VIRTUAL_FIFO)),TRUE)
    ifeq ($(strip $(DMA_UART_VFIFO_TUNNEL_SUPPORT)),TRUE)
      ifneq ($(strip $(PLATFORM)),MT6235)
        $(warning ERROR: Please set DMA_UART_VFIFO_TUNNEL_SUPPORT = FALSE on $(strip $(PLATFORM)) platform.)
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS    +=  __DMA_UART_VFIFO_SINGLE_TUNNEL__
    endif
  endif
endif

ifdef SIP_SUPPORT
  ifneq ($(strip $(SIP_SUPPORT)),FALSE)
     COM_DEFS    +=  __SIP__
  endif
endif

ifdef SDP_SUPPORT
  ifneq ($(strip $(SDP_SUPPORT)),FALSE)
     COM_DEFS    +=  __SDP__
     COMP_TRACE_DEFS	  += ps\sdp\include\sdp_trc.h
  endif
endif

ifdef WIFI_SUPPORT
  ifeq ($(strip $(WIFI_SUPPORT)),WIFI_LIB)
#     COMPOBJS         += wifi\sslplus.lib
#     CUS_REL_OBJ_LIST += wifi\sslplus.lib
#     COMPOBJS         += wifi\sb.lib
#     CUS_REL_OBJ_LIST += wifi\sb.lib
  endif
  ifneq ($(strip $(WIFI_SUPPORT)),NONE)
     COM_DEFS    +=  __WIFI_SUPPORT__
     COM_DEFS    +=  __WIFI_CHIP_VERIFY__
     COM_DEFS    += __WIFI_WIZARD_SUPPORT__
  endif
endif

ifdef IPERF_SUPPORT
  ifneq ($(strip $(IPERF_SUPPORT)),NONE)
     ifneq ($(strip $(TCPIP_SUPPORT)),UDP_TCP)
        $(call DEP_ERR_SETA_OR_OFFB,TCPIP_SUPPORT,UDP_TCP,IPERF_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
     endif
     ifndef WIFI_SUPPORT
        $(call DEP_ERR_ONA_OR_OFFB,WIFI_SUPPORT,IPERF_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
     endif
     ifeq ($(strip $(WIFI_SUPPORT)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,WIFI_SUPPORT,IPERF_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
     endif
  endif

  ifeq ($(strip $(IPERF_SUPPORT)),QUAD)
     COM_DEFS    += __IPERF__
     COM_DEFS    += __IPERF2__
     COM_DEFS    += __IPERF3__
     COM_DEFS    += __IPERF4__
  endif
  ifeq ($(strip $(IPERF_SUPPORT)),TRIPLE)
     COM_DEFS    += __IPERF__
     COM_DEFS    += __IPERF2__
     COM_DEFS    += __IPERF3__
  endif
  ifeq ($(strip $(IPERF_SUPPORT)),DUAL)
     COM_DEFS    += __IPERF__
     COM_DEFS    += __IPERF2__
  endif
  ifeq ($(strip $(IPERF_SUPPORT)),SINGLE)
     COM_DEFS    += __IPERF__
  endif
endif

ifdef VOIP_SUPPORT
  ifneq ($(strip $(VOIP_SUPPORT)),FALSE)
     COM_DEFS    += __VOIP__  __SAF__
  endif
endif

ifndef PHB_SIM_ENTRY
     PHB_SIM_ENTRY = 250
endif

ifdef PHB_SIM_ENTRY
     COM_DEFS    += MAX_PHB_SIM_ENTRY=$(strip $(PHB_SIM_ENTRY))
endif

ifndef PHB_PHONE_ENTRY
     PHB_PHONE_ENTRY = 200
endif

ifdef PHB_PHONE_ENTRY
     COM_DEFS    += MAX_PHB_PHONE_ENTRY=$(strip $(PHB_PHONE_ENTRY))
endif

ifndef PHB_LN_ENTRY
     PHB_LN_ENTRY = 20
endif

ifdef PHB_LN_ENTRY
     COM_DEFS    += MAX_PHB_LN_ENTRY=$(strip $(PHB_LN_ENTRY))
endif

ifndef PHONE_TYPE
  PHONE_TYPE = BAR
endif

ifdef PHONE_TYPE
  COM_DEFS    += __PHONE_$(strip $(PHONE_TYPE))__
  ifeq ($(strip $(PHONE_TYPE)),CLAMSHELL)
    COM_DEFS  +=  CLAM_SUPPORT
  endif
endif

ifdef SUBLCD_DEDICATED_KEYS_SUPPORT
  ifeq ($(strip $(SUBLCD_DEDICATED_KEYS_SUPPORT)),TRUE)
    ifeq ($(strip $(PHONE_TYPE)),CLAMSHELL)
        COM_DEFS    +=  __SUBLCD_DEDICATED_KEYS_SUPPORT__
    else
        $(call DEP_ERR_SETA_OR_OFFB,PHONE_TYPE,CLAMSHELL,SUBLCD_DEDICATED_KEYS_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif



ifeq ($(strip $(IRDA_SUPPORT)),TRUE)
  IRDA_NOT_SUPPORT_PLATFORM = MT6205 MT6208 MT6205B MT6208B MT6253E MT6253L MT6252 MT6252H
  ifneq ($(filter $(strip $(PLATFORM)),$(IRDA_NOT_SUPPORT_PLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) not support IRDA_SUPPORT.) 
    DEPENDENCY_CONFLICT = TRUE
  endif
  IRDA_FULL_COMPILE_OPTION_PLATFORM = MT6228 MT6229 MT6230 MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6268T MT6268H MT6270A 
  ifneq ($(filter $(strip $(PLATFORM)) ,$(IRDA_FULL_COMPILE_OPTION_PLATFORM)),)
    COM_DEFS    += __IRDA_SUPPORT__ __IRDA_MIR_SUPPORT__ __IRDA_FIR_SUPPORT__
  else
    COM_DEFS    += __IRDA_SUPPORT__
  endif
endif

ifdef NAND_FLASH_BOOTING
  ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
    NAND_FLASH_BOOTING_SUPPORT_PLATFORM = MT6228 MT6229 MT6225 MT6230 MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6268A MT6268 MT6270A 
    NFB_ONDEMAND_SUPPORT_PLATFORM = MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6268A MT6268 MT6270A 
    ifeq ($(strip $(SMART_PHONE_CORE)),AP)
      NAND_FLASH_BOOTING_SUPPORT_PLATFORM += MT6516 
      NFB_ONDEMAND_SUPPORT_PLATFORM += MT6516 
    endif
    ifeq ($(filter $(strip $(PLATFORM)) ,$(NAND_FLASH_BOOTING_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support NAND_FLASH_BOOTING) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifdef NAND_SUPPORT
      ifeq ($(strip $(NAND_SUPPORT)),FALSE)
       $(call DEP_ERR_ONA_OR_OFFB,NAND_SUPPORT,NAND_FLASH_BOOTING)
       DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    COM_DEFS    += _NAND_FLASH_BOOTING_
    ifeq ($(strip $(NAND_FLASH_BOOTING)),ENFB)
      ifneq ($(filter $(strip $(PLATFORM)) ,$(NFB_ONDEMAND_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) should use NAND_FLASH_BOOTING = ONDEMAND / MIXED instead of ENFB) 
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS    += __NFB_THIRD_ROM_SUPPORT__
    endif
    ifeq ($(strip $(NAND_FLASH_BOOTING)),ONDEMAND)
      ifeq ($(filter $(strip $(PLATFORM)) ,$(NFB_ONDEMAND_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support NAND_FLASH_BOOTING = ONDEMAND) 
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS    += __NFB_ON_DEMAND_PAGE_IN__
      COMP_TRACE_DEFS += init\include\demp_trc.h
    endif
    ifeq ($(strip $(NAND_FLASH_BOOTING)),MIXED)
      ifeq ($(filter $(strip $(PLATFORM)) ,$(NFB_ONDEMAND_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support NAND_FLASH_BOOTING = MIXED) 
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS    += __NFB_THIRD_ROM_SUPPORT__
      COM_DEFS    += __NFB_ON_DEMAND_PAGE_IN__
      COMP_TRACE_DEFS += init\include\demp_trc.h
    endif
    CUS_REL_SRC_COMP += bootloader
  endif
  CUS_REL_BASE_COMP += bootloader make\bootloader
  CUS_REL_FILES_LIST += custom\drv\common_drv\gpio_setting.c
  CUS_REL_FILES_LIST += sss\sss.lib sss\interface\src\SSS_interface.c \
                        interface\l1interface\l1_interface.c interface\l1interface\l1_interface.h
endif

ifdef NAND_FLASH_BOOTING
  ifeq ($(strip $(NAND_FLASH_BOOTING)),NONE)
    NAND_FLASH_BOOTING_IS_NONE = TRUE
  endif
else
  NAND_FLASH_BOOTING_IS_NONE = TRUE
endif

ifdef EMMC_BOOTING
  ifeq ($(strip $(EMMC_BOOTING)),NONE)
    EMMC_BOOTING_IS_NONE = TRUE
  endif
else
  EMMC_BOOTING_IS_NONE = TRUE
endif

ifdef SMART_PHONE_CORE
  ifeq ($(strip $(SMART_PHONE_CORE)),NONE)
    SMART_PHONE_CORE_IS_NONE = TRUE
  endif
else
  SMART_PHONE_CORE_IS_NONE = TRUE
endif

ifeq ($(strip $(NAND_FLASH_BOOTING_IS_NONE)),TRUE)
  ifeq ($(strip $(EMMC_BOOTING_IS_NONE)),TRUE)
    ifeq ($(strip $(SMART_PHONE_CORE_IS_NONE)),TRUE)
      COM_DEFS += __NOR_IDLE_SWEEP__
    endif
  endif
endif

ifdef USB_DOWNLOAD
  ifeq ($(strip $(USB_DOWNLOAD)),SECURE)
    ifneq ($(strip $(SECURE_SUPPORT)),TRUE)
      $(call DEP_ERR_SETA_OR_ONB,USB_DOWNLOAD,non SECURE,SECURE_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(USB_SUPPORT)),TRUE)
      $(call DEP_ERR_SETA_OR_ONB,USB_DOWNLOAD,non SECURE,USB_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifneq ($(filter MT6251 MT6252H MT6252,$(PLATFORM)),)
  ifdef USB_DOWNLOAD
    ifeq ($(strip $(USB_DOWNLOAD)),NORMAL)
      $(warning ERROR: USB_DOWNLOAD can not set to NORMAL on $(PLATFORM)) 
      DEPENDENCY_CONFLICT = TRUE
    else
      COM_DEFS    += __USBDL_IN_BOOTROM__
    endif
  endif
endif

ifdef USB_DOWNLOAD
  ifneq ($(strip $(USB_DOWNLOAD)),NONE)
    ifeq ($(strip $(USB_SUPPORT)),TRUE)
      USB_DOWNLOAD_SUPPORT_PLATFORM = MT6227 MT6226 MT6226M MT6227D MT6226D MT6225 MT6253T MT6253 MT6253E MT6253L MT6228 MT6229 MT6230 MT6235 MT6235B MT6236 MT6236B MT6238 MT6239 MT6268A MT6268 MT6270A MT6252 MT6252H
      ifeq ($(filter $(strip $(PLATFORM)) ,$(USB_DOWNLOAD_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support USB_DOWNLOAD.) 
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS    += __USB_DOWNLOAD__
      COM_DEFS    += USBACM_TX_WITHOUT_DMA
      CUS_REL_SRC_COMP += bootloader
      CUS_REL_BASE_COMP += bootloader make\bootloader
      CUS_REL_FILES_LIST += custom\drv\common_drv\gpio_setting.c
      CUS_REL_FILES_LIST += sss\interface\src\SSS_interface.c
      ifeq ($(strip $(USB_DOWNLOAD)),SECURE)
        COM_DEFS  += __SECURE_USB_DOWNLOAD__
        CUS_REL_FILES_LIST += dp_engine\che\sha1.h
        CUS_REL_FILES_LIST += dp_engine\che\rc4.h
      endif
    endif
  endif
endif

ARM9_FOTA_PLATFORM = MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6268 MT6270A
ARM7_FOTA_PLATFORM = MT6223 MT6223P MT6229 MT6228 MT6230 MT6225 MT6226 MT6226M MT6226D MT6227 MT6227D MT6253 MT6253E MT6253L MT6252 MT6252H
ifdef FOTA_ENABLE
  ifneq ($(strip $(FOTA_ENABLE)),NONE)
    ifneq ($(strip $(SYNCML_DM_SUPPORT)),FALSE)
      ifeq ($(strip $(FOTA_ENABLE)),FOTA_DM)
        COM_DEFS += _DM_OMADL_VIA_DLAGENT_ __DM_FOTA_SUPPORT__
      endif
    endif
    COM_DEFS += __$(strip $(FOTA_ENABLE))__ __FOTA_ENABLE__
    ifeq ($(strip $(FOTA_ENABLE)),FOTA_DM)
      ifeq ($(strip $(NAND_FLASH_BOOTING)),NONE)
        ifeq ($(strip $(SYSTEM_DRIVE_ON_NAND)),TRUE)
          $(call DEP_ERR_SETA_OR_OFFB,FOTA_ENABLE,non FOTA_DM,SYSTEM_DRIVE_ON_NAND)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
      ifdef SW_BINDING_SUPPORT
        ifneq ($(strip $(SW_BINDING_SUPPORT)),NONE)
          ifeq ($(strip $(SW_BINDING_SUPPORT)),BIND_TO_CHIP_BASIC)
            $(call DEP_ERR_SETA_OR_SETB,FOTA_ENABLE,non FOTA_DM,SW_BINDING_SUPPORT,non BIND_TO_CHIP_BASIC)
            DEPENDENCY_CONFLICT = TRUE
          endif
        endif
      endif    
      COMPLIST         += ssf
      CUS_REL_MTK_COMP += ssf
      CUS_REL_SRC_COMP += bootloader
      CUS_REL_BASE_COMP += bootloader make\bootloader ssf\inc vendor\hp_fota\UA
      CUS_REL_FILES_LIST += custom\drv\common_drv\gpio_setting.c
      CUS_REL_FILES_LIST += sss\sss.lib sss\interface\src\SSS_interface.c
      CUS_REL_FILES_LIST += applib\misc\include\app_zlib.h sst\include\sst_fue_encrypt.h
      CUS_REL_FILES_LIST += dp_engine\che\sha1.h dp_engine\che\rsa.h dp_engine\che\bignum.h
    endif
    CUS_REL_FILES_LIST += init\src\emi.c
    CUS_REL_BASE_COMP += fota make\fota
    CUS_REL_SRC_COMP += fota
  endif
endif

ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT_SUPPORTED_PLATFORM = MT6205B MT6223 MT6223P MT6225 MT6253T MT6253 MT6253E MT6253L MT6252 MT6252H MT6226 MT6226D MT6226M MT6227 MT6229 MT6230 MT6227D MT6235 MT6235B MT6253
ifdef ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT
  ifeq ($(strip $(ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT)),TRUE)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT_SUPPORTED_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(SYSTEM_DRIVE_ON_NAND)),TRUE)
      $(call DEP_ERR_OFFA_OR_OFFB,ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT,SYSTEM_DRIVE_ON_NAND)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(SINGLE_BANK_NOR_FLASH_SUPPORT)),TRUE)
      $(call DEP_ERR_OFFA_OR_OFFB,ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT,SINGLE_BANK_NOR_FLASH_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    else
      COM_DEFS += __SINGLE_BANK_NOR_FLASH_SUPPORT__
    endif
  endif
endif

ifdef SWDBG_SUPPORT
   ifeq ($(strip $(SWDBG_SUPPORT)),TRUE)
      SWDBG_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6223 MT6223P MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6268T MT6268H MT6268A MT6268 MT6270A 
      ifeq ($(filter $(strip $(PLATFORM)) ,$(SWDBG_SUPPORT_PLATFORM)),)
          $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support SWDBG_SUPPORT.) 
          DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(strip $(NAND_SUPPORT)),TRUE)
        $(call DEP_ERR_OFFA_OR_OFFB,NAND_SUPPORT,SWDBG_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifneq ($(strip $(WIFI_SUPPORT)),NONE)
        $(call DEP_ERR_OFFA_OR_OFFB,WIFI_SUPPORT,SWDBG_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS    += __SWDBG_SUPPORT__
   endif
endif

ifdef SW_BINDING_SUPPORT
  ifneq ($(strip $(SW_BINDING_SUPPORT)),NONE)
    ifeq ($(strip $(SW_BINDING_SUPPORT)),BIND_TO_CHIP_BASIC)
    BIND_TO_CHIP_BASIC_SUPPORT_PLATFORM = MT6223 MT6223P MT6225 MT6235 MT6235B MT6238 MT6239 MT6253 MT6268 MT6236
      ifeq ($(filter $(strip $(PLATFORM)) ,$(BIND_TO_CHIP_BASIC_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support SW_BINDING_SUPPORT=BIND_TO_CHIP_BASIC.) 
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS += __BIND_TO_CHIP_BASIC__
    endif
    ifeq ($(strip $(SW_BINDING_SUPPORT)),BIND_TO_CHIP)
      COM_DEFS += __BIND_TO_CHIP__
    endif
  endif
else
SW_BINDING_SUPPORT = NONE
endif

ifdef RES_PROT
  ifeq ($(strip $(RES_PROT)),TRUE)
    ifndef SW_BINDING_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,SW_BINDING_SUPPORT,RES_PROT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(SW_BINDING_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,SW_BINDING_SUPPORT,RES_PROT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __RES_PROT__
  endif
endif

ifdef WMA_DECODE
  ifeq ($(strip $(WMA_DECODE)),TRUE)
      WMA_DECODE_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6268T MT6268H MT6268A MT6268 MT6253T MT6253 MT6253E MT6253L MT6270A MT6255 MT6252 MT6252H
      ifeq ($(filter $(strip $(PLATFORM)) ,$(WMA_DECODE_SUPPORT_PLATFORM)),)
          $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support WMA_DECODE.) 
          DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS    += WMA_DECODE
  endif
endif

ifdef LOW_COST_SUPPORT
   ifneq ($(strip $(LOW_COST_SUPPORT)),NONE)
     COM_DEFS    +=  LOW_COST_SUPPORT
     COM_DEFS    +=  __DISABLE_SELDOM_USED_PROPRIETARY_CMD__
   endif
   ifeq ($(strip $(LOW_COST_SUPPORT)),COMMON)
     COM_DEFS    +=  __LOW_COST_SUPPORT_COMMON__
   endif
   ifeq ($(strip $(LOW_COST_SUPPORT)),ULC)
     COM_DEFS    +=  __LOW_COST_SUPPORT_COMMON__ __LOW_COST_SUPPORT_ULC__
   endif
endif

ifndef MAX_MIDI_FILE_SIZE
    MAX_MIDI_FILE_SIZE = 2097152
endif

ifdef LARGE_MIDI_FILE_SUPPORT
    ifeq ($(strip $(LARGE_MIDI_FILE_SUPPORT)),TRUE)
        ifndef LOW_COST_SUPPORT
            $(call DEP_ERR_ONA_OR_OFFB,LOW_COST_SUPPORT,LARGE_MIDI_FILE_SUPPORT)
            DEPENDENCY_CONFLICT = TRUE
        endif
        ifeq ($(strip $(LOW_COST_SUPPORT)),NONE)
          $(call DEP_ERR_ONA_OR_OFFB,LOW_COST_SUPPORT,LARGE_MIDI_FILE_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
        endif
        ifneq ($(strip $(MMI_VERSION)),PLUTO_MMI)
          $(call DEP_ERR_SETA_OR_OFFB,MMI_VERSION,PLUTO_MMI,LARGE_MIDI_FILE_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
        endif
        ifdef DRM_SUPPORT
          ifneq ($(strip $(DRM_SUPPORT)),NONE)
            ifneq ($(filter MT6223%,$(PLATFORM)),)
              $(warning ERROR: PLATFORM $(strip $(PLATFORM)) with DRM_SUPPORT does not support LARGE_MIDI_FILE_SUPPORT)
              DEPENDENCY_CONFLICT = TRUE
            endif
          endif
        endif
        COM_DEFS += MIDFILE_PLAY_SUPPORT
        COM_DEFS += MAX_MIDI_FILE_SIZE=$(strip $(MAX_MIDI_FILE_SIZE))
    endif
endif

ifdef AAC_PLUS_DECODE
   ifeq ($(strip $(AAC_PLUS_DECODE)),TRUE)
      AAC_PLUS_DECODE_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6226 MT6227 MT6226M MT6225 MT6253T MT6253 MT6227D MT6226D MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6268T MT6268H MT6268A MT6268 MT6270A 
      ifeq ($(filter $(strip $(PLATFORM)) ,$(AAC_PLUS_DECODE_SUPPORT_PLATFORM)),)
         $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support AAC_PLUS_DECODE.) 
         DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS    +=  AAC_PLUS_DECODE
   endif
endif


ifdef AAC_PLUS_PS_DECODE
   ifeq ($(strip $(AAC_PLUS_PS_DECODE)),TRUE)
      AAC_PLUS_PS_DECODE_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6226 MT6227 MT6226M MT6225 MT6253T MT6253 MT6253E MT6253L MT6227D MT6226D MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6268A MT6268 MT6270A MT6252 MT6252H
      ifeq ($(filter $(strip $(PLATFORM)) ,$(AAC_PLUS_PS_DECODE_SUPPORT_PLATFORM)),)
         $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support AAC_PLUS_PS_DECODE.) 
         DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(strip $(AAC_PLUS_DECODE)),FALSE)
         $(call DEP_ERR_ONA_OR_OFFB,AAC_PLUS_DECODE,AAC_PLUS_PS_DECODE)
         DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS += AAC_PLUS_PS_DECODE
      COMPLIST += dp_engine
      CUS_REL_MTK_COMP += dp_engine
   endif
endif



ifdef EMS_SUPPORT
    ifeq ($(strip $(EMS_SUPPORT)),EMS_50)
      COM_DEFS    +=  __EMS_REL5__
    endif
    ifeq ($(strip $(EMS_SUPPORT)),EMS_40)
       # do nothing
    endif
    ifeq ($(strip $(EMS_SUPPORT)),EMS_NONE)
      COM_DEFS    +=  __SLIM_EMS__
    endif
endif

ifdef EDGE_SUPPORT
   ifeq ($(strip $(EDGE_SUPPORT)),TRUE)
     EDGE_SUPPORT_PLATFORM = MT6229 MT6230 MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6268 TK6516 MT6516 MT6268T MT6268H MT6268A MT6268 MT6270A 
     ifeq ($(filter $(strip $(PLATFORM)) ,$(EDGE_SUPPORT_PLATFORM)),)
       $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support EGPRS.) 
       DEPENDENCY_CONFLICT = TRUE
     endif
     ifeq ($(strip $(call Upper,$(PROJECT))),GSM)
       $(warning ERROR: GSM project does not support EDGE_SUPPORT) 
       DEPENDENCY_CONFLICT = TRUE
     endif
     ifneq ($(strip $(R99_SUPPORT)),TRUE)
       $(call DEP_ERR_ONA_OR_OFFB,R99_SUPPORT,EDGE_SUPPORT)
       DEPENDENCY_CONFLICT = TRUE
     endif
     ifneq ($(strip $(L1_EGPRS)),TRUE)
       $(call DEP_ERR_ONA_OR_OFFB,L1_EGPRS,EDGE_SUPPORT)
       DEPENDENCY_CONFLICT = TRUE
     endif
      
     COM_DEFS    += __EGPRS_MODE__
      
     ifeq ($(strip $(L1_EPSK_TX)),TRUE)
       ifeq ($(filter MT6140D_RF,$(COM_DEFS_FOR_$(strip $(RF_MODULE)))),)
         ifeq ($(filter AD6546_RF,$(COM_DEFS_FOR_$(strip $(RF_MODULE)))),)
           ifeq ($(filter SKY74137_RF,$(COM_DEFS_FOR_$(strip $(RF_MODULE)))),)
             ifeq ($(filter SKY74045_RF,$(COM_DEFS_FOR_$(strip $(RF_MODULE)))),)
               $(warning ERROR: RF_MODULE $(strip $(RF_MODULE)) does not support L1_EPSK_TX.) 
               DEPENDENCY_CONFLICT = TRUE
             endif
           endif
         endif
       endif
       COM_DEFS    +=  __EPSK_TX__
     endif
   else
     ifdef L1_EGPRS
       ifeq ($(strip $(L1_EGPRS)),TRUE)
         $(call DEP_ERR_ONA_OR_OFFB,EDGE_SUPPORT,L1_EGPRS)
         DEPENDENCY_CONFLICT = TRUE
       endif
     endif
     ifdef L1_EPSK_TX
       ifeq ($(strip $(L1_EPSK_TX)),TRUE)
         $(call DEP_ERR_ONA_OR_OFFB,EDGE_SUPPORT,L1_EPSK_TX)
         DEPENDENCY_CONFLICT = TRUE
       endif
     endif
   endif
endif

ifdef XDM_SUPPORT
ifneq ($(strip $(XDM_SUPPORT)),FALSE)
  # XDM_SUPPORT should be based on OBIGO_FEATURE (WAP2 and SEC)
  ifdef OBIGO_FEATURE
    ifneq ($(strip $(OBIGO_FEATURE)),NONE)
      ifneq ($(strip $(OBIGO_FEATURE)),WAP2_SEC)
        $(call DEP_ERR_SETA_OR_OFFB,OBIGO_FEATURE,WAP2_SEC,XDM_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    else
      $(call DEP_ERR_SETA_OR_OFFB,OBIGO_FEATURE,WAP2_SEC,XDM_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  else
    $(call DEP_ERR_SETA_OR_OFFB,OBIGO_FEATURE,WAP2_SEC,XDM_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  # XDM_SUPPORT should be based on XML_SUPPORT
  ifdef XML_SUPPORT
    ifeq ($(strip $(XML_SUPPORT)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,XML_SUPPORT,XDM_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  # XDM_SUPPORT should be based on HTTP_INTERFACE_SUPPORT
  ifneq ($(strip $(HTTP_INTERFACE_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,HTTP_INTERFACE_SUPPORT,XDM_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif
endif

ifdef R99_SUPPORT
  ifeq ($(strip $(R99_SUPPORT)),TRUE)
      COM_DEFS    +=   __R99__
      ifeq ($(strip $(L1_GPRS)),TRUE)
          COM_DEFS    +=   __TBF_EST__
     endif
  endif
endif

ifdef R4_SUPPORT
  R4_NOT_SUPPORT_PLATFORM = MT6205B MT6217 MT6218B MT6219 
  ifeq ($(strip $(R4_SUPPORT)),TRUE)
    ifneq ($(strip $(R99_SUPPORT)),TRUE)
          $(call DEP_ERR_ONA_OR_OFFB,R99_SUPPORT,R4_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
        $(call DEP_ERR_SETA_OR_OFFB,MMI_VERSION,non NEPTUNE_MMI,R4_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    endif    
    ifeq ($(filter $(strip $(PLATFORM)),$(R4_NOT_SUPPORT_PLATFORM)),)
      COM_DEFS    +=   __REL4__ __GERAN_R4__
    else
       $(warning ERROR: PLATFORM $(strip $(PLATFORM)) not support R4_SUPPORT.) 
       DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef R5_SUPPORT
  R5_NOT_SUPPORT_PLATFORM = MT6205B MT6217 MT6218B MT6219 
  ifeq ($(strip $(R5_SUPPORT)),TRUE)
    ifneq ($(strip $(R4_SUPPORT)),TRUE)
          $(call DEP_ERR_ONA_OR_OFFB,R4_SUPPORT,R5_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(filter $(strip $(PLATFORM)),$(R5_NOT_SUPPORT_PLATFORM)),)
          $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support R5_SUPPORT.) 
          DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(USIM_SUPPORT)),TRUE)
      ifeq ($(filter ANDROID_MODEM,$(strip $(SMART_PHONE_CORE))),)
        $(call DEP_ERR_ONA_OR_OFFB,USIM_SUPPORT,R5_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif  
    ifneq ($(strip $(PLATFORM)),MT6516)
          COM_DEFS    +=   __REL5__ __GERAN_R5__
          ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
              COM_DEFS    +=   __ACL_SUPPORT__
          endif
    else
          COM_DEFS    +=   __REL5__ __GERAN_R5__   
    endif
  endif
endif

ifeq ($(strip $(USIM_SUPPORT)),TRUE)
  COM_DEFS    +=   __USIM_SUPPORT__ __EF_NETPAR_SUPPORT__
  COM_DEFS    +=   __PHB_USIM_SUPPORT__
endif

ifeq ($(strip $(PHB_ADDITIONAL_SUPPORT)),TRUE)
  ifneq ($(strip $(USIM_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,USIM_SUPPORT,PHB_ADDITIONAL_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    +=   __PHB_USIM_ADDITIONAL_SUPPORT__
endif

ifdef CHE_SUPPORT
  ifeq ($(strip $(PLATFORM)),MT6228)
    ifeq ($(strip $(CHE_SUPPORT)),TRUE)
       COM_DEFS    +=  __HW_CHE__
    endif
  endif
endif

ifdef TV_OUT_SUPPORT
  ifeq ($(strip $(CAMCORDER_SUPPORT)),NONE)
    ifeq ($(strip $(HORIZONTAL_CAMERA)),TRUE)
      ifeq ($(strip $(TV_OUT_SUPPORT)),TRUE)
        ifeq ($(strip $(LCM_ROTATE_SUPPORT)),FALSE)
          $(call DEP_ERR_ONA_OR_OFFB,LCM_ROTATE_SUPPORT,HORIZONTAL_CAMERA/TV_OUT_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
  endif
  TV_OUT_SUPPORT_PLATFORM = MT6228 MT6229 MT6268T MT6268H MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6230 MT6268A MT6268 MT6270A 
  ifneq ($(filter $(strip $(PLATFORM)) ,$(TV_OUT_SUPPORT_PLATFORM)),)
    ifeq ($(strip $(TV_OUT_SUPPORT)),TRUE)
      COM_DEFS    +=  TV_OUT_SUPPORT
    endif
  endif
endif

ifndef MAIN_LCD_SIZE
   MAIN_LCD_SIZE = 0X0
endif

ifdef MAIN_LCD_SIZE
   ifeq ($(call Upper,$(strip $(MAIN_LCD_SIZE))),120X160)
      # spacial case for MTKLCM_COLOR in MT6208 EVB
      MAIN_LCD_SIZE := 128X160
   endif

   ifeq ($(call Upper,$(strip $(MAIN_LCD_SIZE))),128X128)
     ifneq ($(strip $(TOUCH_PANEL_SUPPORT)),NONE)
       $(warning ERROR: MAIN_LCD_SIZE 128X128 does not support TOUCH_PANEL) 
       DEPENDENCY_CONFLICT = TRUE
     endif
   endif
   COM_DEFS    += __MMI_MAINLCD_$(call Upper,$(strip $(MAIN_LCD_SIZE)))__
endif

ifndef SUB_LCD_SIZE
    SUB_LCD_SIZE = NONE
endif

ifdef SUB_LCD_SIZE
    COM_DEFS += __MMI_SUBLCD_$(call Upper,$(strip $(SUB_LCD_SIZE)))__
endif

BACKGROUND_SOUND_NOT_SUPPORT_PLATFORM = MT6226 MT6226M MT6227
ifdef BACKGROUND_SOUND
  ifeq ($(strip $(BACKGROUND_SOUND)),TRUE)
    ifneq ($(filter $(strip $(PLATFORM)),$(BACKGROUND_SOUND_NOT_SUPPORT_PLATFORM)),)
      $(warning ERROR: $(strip $(PLATFORM)) does not support BACKGROUND_SOUND) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS	+= BGSND_ENABLE
  endif
endif

ifdef WEBCAM_SUPPORT
  ifeq ($(strip $(WEBCAM_SUPPORT)),TRUE)
    ifeq ($(strip $(CMOS_SENSOR)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR,WEBCAM_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    endif
    ifndef CMOS_SENSOR
        $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR,WEBCAM_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(ISP_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,ISP_SUPPORT,WEBCAM_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    endif
    WEBCAM_SUPPORT_NOT_SUPPORT_PLATFORM = MT6205B MT6217 MT6218B
    ifneq ($(filter $(strip $(PLATFORM)),$(WEBCAM_SUPPORT_NOT_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) not support WEBCAM_SUPPORT.) 
      DEPENDENCY_CONFLICT = TRUE
    else
      ifeq ($(strip $(USB_SUPPORT)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,WEBCAM_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      else
        COM_DEFS += WEBCAM_SUPPORT      
      endif
    endif
  endif
  ifeq ($(strip $(VENDOR)),NONE)
    CUS_REL_BASE_COMP += media\camera\include \
                         media\camera_v2\include
  endif
endif

# BES_LIVE_SUPPORT/BES_TS_SUPPORT for 6228/6229/6230/6238 only
BES_LIVE_SUPPORT_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6268A MT6268 MT6270A 
ifdef BES_LIVE_SUPPORT
  ifneq ($(strip $(BES_LIVE_SUPPORT)),FALSE)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(BES_LIVE_SUPPORT_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support BES_LIVE_SUPPORT.) 
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif

  ifeq ($(strip $(BES_LIVE_SUPPORT)),TRUE)
    COM_DEFS	+= __BES_LIVE_SUPPORT__
    CONDITION_COM_DEFS_BESSOUND_SUPPORT = TRUE
    ifeq ($(strip $(COMPILER)),ADS)
      COMPOBJS    += dp_engine\BesSound\BesLive_arm.a
      CUS_REL_OBJ_LIST += dp_engine\BesSound\BesLive_arm.a
    endif
    ifeq ($(strip $(COMPILER)),RVCT)
      COMPOBJS    += dp_engine\BesSound\BesLive_arm_rvct.a
      CUS_REL_OBJ_LIST += dp_engine\BesSound\BesLive_arm_rvct.a
    endif
  endif
endif

ifdef BES_TS_SUPPORT
  ifneq ($(strip $(BES_TS_SUPPORT)),FALSE)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(BES_LIVE_SUPPORT_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support BES_TS_SUPPORT.) 
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(BES_TS_SUPPORT)),TRUE)
    COM_DEFS	+= __BES_TS_SUPPORT__
  endif
endif

ifdef DT_SUPPORT
  ifneq ($(strip $(DT_SUPPORT)),FALSE)
     COM_DEFS    +=  __DT_SUPPORT__
     COMPLIST    +=  dt
  endif
endif

ifeq ($(strip $(AU_DECODE)),TRUE)
   AU_DECODE_NOT_SUPPORT_PLATFORM = MT6205 MT6205B MT6218 MT6218B MT6208
   ifeq ($(filter $(strip $(PLATFORM)),$(AU_DECODE_NOT_SUPPORT_PLATFORM)),$(strip $(PLATFORM)))
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) not support AU_DECODE.) 
      DEPENDENCY_CONFLICT = TRUE
   endif
   COM_DEFS    += AU_DECODE
endif


ifeq ($(strip $(AIFF_DECODE)),TRUE)
   AIFF_DECODE_NOT_SUPPORT_PLATFORM = MT6205 MT6205B MT6218 MT6218B MT6208 
   ifeq ($(filter $(strip $(PLATFORM)),$(AIFF_DECODE_NOT_SUPPORT_PLATFORM)),$(strip $(PLATFORM)))
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) not support AIFF_DECODE.) 
      DEPENDENCY_CONFLICT = TRUE
   endif
   COM_DEFS    += AIFF_DECODE
endif

ifeq ($(strip $(JTONE_SUPPORT)),TRUE)
   JTONE_NOT_SUPPORT_PLATFORM = MT6205 MT6205B MT6218 MT6218B MT6208
   ifeq ($(filter $(strip $(PLATFORM)),$(JTONE_NOT_SUPPORT_PLATFORM)),$(strip $(PLATFORM)))
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) not support JTONE_SUPPORT.) 
      DEPENDENCY_CONFLICT = TRUE
   endif
   COM_DEFS    += JTONE_SUPPORT
endif

ifneq ($(strip $(J2ME_SUPPORT)),NONE)
  ifneq ($(strip $(JTONE_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,JTONE_SUPPORT,J2ME_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef AF_SUPPORT
  ifneq ($(strip $(AF_SUPPORT)),FALSE)
    ifndef LENS_MODULE
  		$(call DEP_ERR_ONA_OR_OFFB,LENS_MODULE,AF_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(LENS_MODULE)),NONE)
  		$(call DEP_ERR_ONA_OR_OFFB,LENS_MODULE,AF_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
    endif
      COM_DEFS    +=  AF_SUPPORT
  endif
endif


ifdef CTM_SUPPORT
  ifneq ($(strip $(CTM_SUPPORT)),FALSE)
    COM_DEFS    +=  __CTM_SUPPORT__
    COMPLIST += dp_engine
    CUS_REL_MTK_COMP += dp_engine
  endif
endif

ifdef XDM_SUPPORT
  ifeq ($(strip $(XDM_SUPPORT)),TRUE)
     COM_DEFS    += __XDM__
  endif
endif

#
#ifdef BT_HFG_PROFILE
#  ifeq ($(strip $(BT_HFG_PROFILE)),TRUE)
#    COM_DEFS    +=  __BT_HFG_PROFILE__
#  else
#    COM_DEFS    += EXCLUDE_HFG_MODULE
#  endif
#endif
#

# JSR184
ifndef SUPPORT_JSR_184
   SUPPORT_JSR_184 = FALSE
endif

ifdef SUPPORT_JSR_184
  ifneq ($(strip $(SUPPORT_JSR_184)),FALSE)
    ifeq ($(filter $(call Upper,$(strip $(MAIN_LCD_SIZE))),96X64 128X128 128X160 176X220 240X320 320X240 ),)
      $(call DEP_ERR_SETA_OR_OFFB,MAIN_LCD_SIZE,non $(strip $(MAIN_LCD_SIZE)),SUPPORT_JSR_184)
      DEPENDENCY_CONFLICT = TRUE
    endif  
    ifeq ($(strip $(OPENGL)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,OPENGL,SUPPORT_JSR_184)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA)
        $(call DEP_ERR_SETA_OR_OFFB,J2ME_SUPPORT,non JBLENDIA,SUPPORT_JSR_184)
        DEPENDENCY_CONFLICT = TRUE
    endif
    # We can turn on SUPPORT_JSR_184  when HI_VM/HI_VM_SOURCE is defined in J2ME_VM.
    ifeq ($(findstring HI_VM,$(J2ME_VM)),)
      $(call DEP_ERR_SETA_OR_OFFB,J2ME_VM,HI_VM/HI_VM_SOURCE,SUPPORT_JSR_184)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifdef OPENGL
      ifneq ($(strip $(OPENGL)),NONE)
        COM_DEFS += M3D_SUPPORT
      endif
    endif
  endif
endif


ifndef M3D_MMI_SUPPORT
   M3D_MMI_SUPPORT = FALSE
endif

ifdef M3D_MMI_SUPPORT
  ifneq ($(strip $(M3D_MMI_SUPPORT)),FALSE)
    ifeq ($(strip $(OPENGL)),NONE)
       $(call DEP_ERR_ONA_OR_OFFB,OPENGL,M3D_MMI_SUPPORT)
       DEPENDENCY_CONFLICT = TRUE
    else
       # We can turn on M3D_MMI_SUPPORT when HI_VM/HI_VM_SOURCE is defined in J2ME_VM.
       ifeq ($(strip $(SUPPORT_JSR_184)),FALSE)
          COM_DEFS += M3D_MMI_SUPPORT M3D_SUPPORT
       else
          COM_DEFS += M3D_MMI_SUPPORT
       endif
    endif
  endif
endif





ifdef LCM_ROTATE_SUPPORT
  ifeq ($(strip $(LCM_ROTATE_SUPPORT)),TRUE)
      COM_DEFS += LCM_ROTATE_SUPPORT
  endif
endif

ifdef EXIF_SUPPORT
  ifeq ($(strip $(EXIF_SUPPORT)),TRUE)
    ifneq ($(strip $(ISP_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,ISP_SUPPORT,EXIF_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
      COM_DEFS += EXIF_SUPPORT
  endif
endif

ifdef SVG_SUPPORT
 ifeq ($(strip $(COMPILER)),ADS)
  ifeq ($(strip $(SVG_SUPPORT)),TRUE) # For backward compatible
    COM_DEFS += SVG_SUPPORT MTK_SVG
  else
    ifeq ($(strip $(SVG_SUPPORT)),MTK_SVG)
      ifneq ($(strip $(XML_SUPPORT)),TRUE)
        $(call DEP_ERR_SETA_OR_ONB,SVG_SUPPORT,non MTK_SVG,XML_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS += SVG_SUPPORT MTK_SVG
    else
      ifneq ($(strip $(SVG_SUPPORT)),FALSE) # For backward compatible
        ifneq ($(strip $(SVG_SUPPORT)),NONE)
          ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
            ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
              ifneq ($(strip $(SVG_SUPPORT)),MTK_SVG)
                $(warning ERROR: Please set SVG_SUPPORT to be MTK_SVG in customer projects) 
                DEPENDENCY_CONFLICT = TRUE
              endif
            endif
          endif
          COM_DEFS += SVG_SUPPORT
          COM_DEFS += $(SVG_SUPPORT)
        endif
      endif
    endif
  endif
 endif
endif

#ifdef USB_IN_NORMAL_MODE_SUPPORT
#  ifeq ($(strip $(USB_IN_NORMAL_MODE_SUPPORT)),TRUE)
#	COM_DEFS += __USB_IN_NORMAL_MODE__
#	ifeq ($(strip $(BOARD_VER)),DRAGONFLY_BB)
#	   COM_DEFS += __USB_IN_NORMAL_MODE_IMPROVE__
#        endif
#	ifeq ($(strip $(BOARD_VER)),SAPPHIRE28_BB)
#	   COM_DEFS += __USB_IN_NORMAL_MODE_IMPROVE__
#        endif
#  endif
#endif

ifdef USB_IN_NORMAL_MODE_SUPPORT
  ifeq ($(strip $(USB_IN_NORMAL_MODE_SUPPORT)),TRUE)
    ifeq ($(strip $(USB_SUPPORT)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,USB_IN_NORMAL_MODE_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    else
      COM_DEFS += __USB_IN_NORMAL_MODE__
      ifneq ($(strip $(MMI_VERSION)),WISDOM_MMI)
        COM_DEFS += __USB_IN_NORMAL_MODE_IMPROVE__
      endif
    endif
  endif
endif


ifneq ($(strip $(PLATFORM)),MT6205B)
   ifneq ($(strip $(PLATFORM)),MT6208)
     ifneq ($(strip $(PLATFORM)),MT6218B)
       ifneq ($(strip $(PLATFORM)),MT6217)
         COM_DEFS +=  __USIM_DRV__
       endif
     endif
   endif
endif

ifdef OTG_SUPPORT
  ifeq ($(strip $(OTG_SUPPORT)),TRUE)
  OTG_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6238 MT6239 MT6268T MT6268H MT6268 MT6270A
    ifeq ($(filter $(strip $(PLATFORM)),$(OTG_SUPPORT_PLATFORM)),)
     $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support OTG.) 
     DEPENDENCY_CONFLICT = TRUE
    else
      ifeq ($(strip $(USB_IN_NORMAL_MODE_SUPPORT)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,USB_IN_NORMAL_MODE_SUPPORT,OTG_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      else
        ifeq ($(strip $(USB_SUPPORT)),FALSE)
          $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,OTG_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
        else
            ifeq ($(strip $(USB_MASS_STORAGE_SUPPORT)),TRUE)
              COM_DEFS	+= __OTG_ENABLE__
            endif
        endif
      endif
    endif
  endif
endif

ifdef OTG_DETECT_ID_PIN_WITH_EINT
  ifeq ($(strip $(OTG_DETECT_ID_PIN_WITH_EINT)),TRUE)
    ifeq ($(strip $(OTG_SUPPORT)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,OTG_SUPPORT,OTG_DETECT_ID_PIN_WITH_EINT)
      DEPENDENCY_CONFLICT = TRUE
    else
	    COM_DEFS += __OTG_DETECT_IDPIN_WITH_EINT__
    endif
  endif
endif



ifdef OPENGL
  ifneq ($(strip $(OPENGL)),NONE)
     COM_DEFS +=  __OPENGL_SUPPORT__
     COMPLIST         += opengl opengl16 opengl_custom
     CUS_REL_MTK_COMP    += opengl opengl16
     CUS_REL_SRC_COMP    += opengl_custom
  endif
  ifeq ($(strip $(OPENGL)),COMMON_LITE)
     COM_DEFS +=  __COMMON_LITE__     
     OPENGL_OBJ_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6235 MT6235B MT6236 MT6236B MT6238 MT6239 
     ifneq ($(filter $(strip $(PLATFORM)) ,$(OPENGL_OBJ_SUPPORT_PLATFORM)),)
      ifeq ($(strip $(COMPILER)),ADS)
       COMPOBJS    += dp_engine\opengl\swrast\affine_span_sfo.obj
       COMPOBJS    += dp_engine\opengl\swrast\fast_persp_span_sfo.obj
       COMPOBJS    += dp_engine\opengl\swrast\s_span_arm_sfo_flat.obj
       COMPOBJS    += dp_engine\opengl\swrast\s_span_arm_sfo_smooth.obj
      endif
     endif
     ifeq ($(strip $(COMPILER)),ADS)
      CUS_REL_OBJ_LIST    += dp_engine\opengl\swrast\affine_span_sfo.obj
      CUS_REL_OBJ_LIST    += dp_engine\opengl\swrast\fast_persp_span_sfo.obj
      CUS_REL_OBJ_LIST    += dp_engine\opengl\swrast\s_span_arm_sfo_flat.obj
      CUS_REL_OBJ_LIST    += dp_engine\opengl\swrast\s_span_arm_sfo_smooth.obj
     endif
  endif
endif


ifneq ($(filter __DISABLE_SMS_CONTROLLED_BY_SIM__,$(strip $(COM_DEFS))),)
  ifeq ($(filter __SAT__,$(strip $(COM_DEFS))),)
    $(warning ERROR: Please define __SAT__ or do not define __DISABLE_SMS_CONTROLLED_BY_SIM__) 
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef USB_MULTI_CHARGE_CURRENT_SUPPORT
  ifeq ($(strip $(USB_MULTI_CHARGE_CURRENT_SUPPORT)),TRUE)
     ifeq ($(strip $(USB_SUPPORT)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,USB_MULTI_CHARGE_CURRENT_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
     else
        COM_DEFS +=  __USB_MULTI_CHARGE_CURRENT__
     endif
  endif
endif

ifdef RC5_SUPPORT
  ifeq ($(strip $(RC5_SUPPORT)),TRUE)
    ifeq ($(findstring SEC,$(strip $(OBIGO_FEATURE))),SEC)
      COM_DEFS    += RC5_SUPPORT
    endif
  endif
endif


ifdef GAME_ENGINE
  ifneq ($(strip $(GAME_ENGINE)),NONE)
     ifeq ($(strip $(OPENGL)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,OPENGL,GAME_ENGINE)
        DEPENDENCY_CONFLICT = TRUE
     else
        COM_DEFS +=  $(strip $(GAME_ENGINE))
     endif
  endif
endif

ifdef YUV_SENSOR_SUPPORT
  ifneq ($(strip $(YUV_SENSOR_SUPPORT)),FALSE)
     ifeq ($(strip $(ISP_SUPPORT)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,ISP_SUPPORT,YUV_SENSOR_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
     else
        COM_DEFS += YUV_SENSOR_SUPPORT
     endif
  endif
endif

ifdef PLATFORM
  ifeq ($(strip $(PLATFORM)),MT6225)
    ifdef ISP_SUPPORT
      ifneq ($(strip $(ISP_SUPPORT)),FALSE)
        ifdef YUV_SENSOR_SUPPORT
          ifeq ($(strip $(YUV_SENSOR_SUPPORT)),FALSE)
            $(call DEP_ERR_ONA_OR_OFFB,YUV_SENSOR_SUPPORT,ISP_SUPPORT)
            DEPENDENCY_CONFLICT = TRUE
          endif
        endif
      endif
    endif
  endif
endif

ifdef EXT_DAC_SUPPORT
  ifeq ($(strip $(EXT_DAC_SUPPORT)),TRUE)
     COM_DEFS    +=  EXT_DAC_SUPPORT
  endif
endif

ifdef EXTERNAL_AMPLIFIER_ROUTE_CONFIGURATION
  ifeq ($(strip $(EXTERNAL_AMPLIFIER_ROUTE_CONFIGURATION)),TRUE)
     COM_DEFS    +=  EXTERNAL_AMPLIFIER_ROUTE_CONFIGURATION
  endif
endif
 
ifdef UNIFIED_MESSAGE_FOLDER
   ifeq ($(strip $(UNIFIED_MESSAGE_FOLDER)),TRUE)
      ifneq ($(strip $(MMI_VERSION)),PLUTO_MMI)
        $(warning ERROR: $(MMI_VERSION) does not support UNIFIED_MESSAGE_FOLDER)
        DEPENDENCY_CONFLICT = TRUE
      endif
   endif
endif

ifdef UNIFIED_MESSAGE_FOLDER
  ifeq ($(strip $(UNIFIED_MESSAGE_FOLDER)),TRUE)
    ifneq ($(strip $(OBIGO_FEATURE)),NONE)
      ifeq ($(findstring WAP,$(strip $(OBIGO_FEATURE))),)
        $(call DEP_ERR_SETA_OR_OFFB,OBIGO_FEATURE,WAP,UNIFIED_MESSAGE_FOLDER)
        DEPENDENCY_CONFLICT = TRUE
      else
        ifeq ($(strip $(MMS_SUPPORT)),NONE)
          $(call DEP_ERR_ONA_OR_OFFB,MMS_SUPPORT,UNIFIED_MESSAGE_FOLDER)
          DEPENDENCY_CONFLICT = TRUE
        else
          COM_DEFS    +=  __UM_FOLDER__
        endif
      endif
    else
      $(call DEP_ERR_SETA_OR_OFFB,OBIGO_FEATURE,WAP,UNIFIED_MESSAGE_FOLDER)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

DRV_CUSTOM_TOOL_SUPPORT_PLATFORM = MT6253 MT6253E MT6253L MT6268 MT6236 MT6236B MT6270A MT6252 MT6252H
ifneq ($(filter $(call Upper,$(strip $(PLATFORM))) ,$(DRV_CUSTOM_TOOL_SUPPORT_PLATFORM)),)
    ifneq ($(strip $(DRV_CUSTOM_TOOL_SUPPORT)),TRUE)
        $(warning ERROR: DRV_CUSTOM_TOOL_SUPPORT must be turned on when PLATFORM = $(strip $(PLATFORM))) 
        DEPENDENCY_CONFLICT = TRUE
    endif
endif

ifdef DRV_CUSTOM_TOOL_SUPPORT
  ifeq ($(strip $(DRV_CUSTOM_TOOL_SUPPORT)),TRUE)
     COM_DEFS    +=  __CUST_NEW__
  endif
endif

ifdef BROWSER_SUPPORT
  ifneq ($(strip $(BROWSER_SUPPORT)),NONE)
    ifdef OBIGO_FEATURE
      ifeq ($(strip $(OBIGO_FEATURE)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,OBIGO_FEATURE,BROWSER_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    else
      $(call DEP_ERR_ONA_OR_OFFB,OBIGO_FEATURE,BROWSER_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif # end of ifneq ($(strip $(BROWSER_SUPPORT)),NONE)
  ifeq ($(strip $(BROWSER_SUPPORT)),OPERA_V10)
    ifneq ($(strip $(OBIGO_FEATURE)),WAP2_SEC)
      $(call DEP_ERR_SETA_OR_SETB,OBIGO_FEATURE,WAP2_SEC,BROWSER_SUPPORT,non OPERA_V10)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(GEMINI)),3)
      $(warning ERROR: BROWSER_SUPPORT = $(strip $(BROWSER_SUPPORT)) does not support GEMINI = $(strip $(GEMINI))) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(GEMINI)),4)
      $(warning ERROR: BROWSER_SUPPORT = $(strip $(BROWSER_SUPPORT)) does not support GEMINI = $(strip $(GEMINI))) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(SOCKET_SSL_SUPPORT)),TRUE)
      $(call DEP_ERR_SETA_OR_ONB,BROWSER_SUPPORT,non OPERA_V10,SOCKET_SSL_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif #end of ifeq ($(strip $(BROWSER_SUPPORT)),OPERA_V10)
endif # end of ifdef BROWSER_SUPPORT

ifdef BROWSER_SUPPORT
  ifeq ($(strip $(BROWSER_SUPPORT)),OBIGO_Q03C)
    COM_DEFS    +=   OBIGO_Q03C
    COM_DEFS    +=   OBIGO_Q03C_BROWSER    
  endif
  ifeq ($(strip $(BROWSER_SUPPORT)),OBIGO_Q05A)
    COM_DEFS    +=  OBIGO_Q05A
  endif
  ifeq ($(strip $(BROWSER_SUPPORT)),OPERA_V10)
    COM_DEFS    +=  OBIGO_Q03C
    COM_DEFS    +=  OPERA_V10_BROWSER
  endif  
  ifneq ($(strip $(BROWSER_SUPPORT)),NONE)
    COM_DEFS      +=  BROWSER_SUPPORT
  endif  
endif

ifneq ($(findstring MMS,$(strip $(OBIGO_FEATURE))),)
    $(warning ERROR: $(strip $(OBIGO_FEATURE)) is not a valid option of OBIGO_FEATURE! Please modify it and set MMS_SUPPORT properly. )
    DEPENDENCY_CONFLICT = TRUE
endif

ifdef MMS_SUPPORT
    ifeq ($(strip $(MMS_SUPPORT)),OBIGO_Q03C_MMS_V02)
      ifneq ($(strip $(UNIFIED_MESSAGE_FOLDER)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,UNIFIED_MESSAGE_FOLDER,MMS_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(findstring COMPOSER,$(UNIFIED_MESSAGE_ADVANCE_FEATURE)),)
        COM_DEFS    +=  __MMS_STANDALONE_COMPOSER_SUPPORT__
      endif
      ifneq ($(strip $(XML_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,XML_SUPPORT,MMS_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
endif

ifeq ($(strip $(OBIGO_FEATURE)),NONE)
  COM_DEFS    += WAP_NOT_PRESENT
  COM_DEFS    += WPS_NOT_PRESENT
else
  ifeq ($(strip $(BROWSER_SUPPORT)),OBIGO_Q05A)
    COM_DEFS    += WAP_NOT_PRESENT
  endif
endif


ifdef DSPIRDBG
   ifeq ($(strip $(DSPIRDBG)),TRUE)
     ifneq ($(strip $(USB_SUPPORT)),TRUE)
       $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,DSPIRDBG)
       DEPENDENCY_CONFLICT = TRUE
     endif
      COM_DEFS    += __DSPIRDBG__
      COM_DEFS    += __USB_LOGGING__
   endif
endif

ifndef ISP_SUPPORT
   COM_DEFS    += MED_C_NOT_PRESENT
endif

ifdef ISP_SUPPORT
   ifeq ($(strip $(ISP_SUPPORT)),FALSE)
      COM_DEFS    += MED_C_NOT_PRESENT
   endif
endif

ifdef PROJECT
  ifneq ($(strip $(call Upper,$(PROJECT))),L1S)
    ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
      ifneq ($(strip $(call Upper,$(PROJECT))),MEUT)
        COM_DEFS    += __MANUAL_MODE_NW_SEL__  __NORMAL_NW_SEARCH__
      endif
    endif
  endif
endif

ifdef CUST_PARA_SUPPORT
   ifeq ($(strip $(CUST_PARA_SUPPORT)),TRUE)
     ifneq ($(strip $(SECURE_SUPPORT)),TRUE)
       $(call DEP_ERR_ONA_OR_OFFB,SECURE_SUPPORT,CUST_PARA_SUPPORT)
       DEPENDENCY_CONFLICT = TRUE
     endif
     COM_DEFS += __CUST_PARA_SUPPORT__
   endif
endif

ifdef DISPLAY_TYPE
  COM_DEFS    += __MMI_DISPLAY_TYPE_$(call Upper,$(strip $(DISPLAY_TYPE)))__
  ifeq ($(strip $(DISPLAY_TYPE)),BW)
    ifdef SENSOR_TYPE
      ifeq ($(strip $(SENSOR_TYPE)),DIRECT)
        $(warning ERROR: DISPLAY_TYPE = $(strip $(DISPLAY_TYPE)) does not support SENSOR_TYPE = $(strip $(SENSOR_TYPE))) 
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifdef OTP_SUPPORT
   ifeq ($(strip $(OTP_SUPPORT)),TRUE)
      COM_DEFS    += __SECURITY_OTP__
   endif
endif

#6226C (S02), 6229E4, and 6225 and newer chip related project only.
SECURE_SUPPORT_NOT_SUPPORT_PLATFORM = MT6205B MT6208 MT6217 MT6218B MT6219 MT6226 MT6226M MT6227 MT6228 MT6229
SECURE_SUPPORT_NOT_SUPPORT_PARTIAL_PLATFORM = MT6226 MT6226M MT6227 MT6229
SECURE_SUPPORT_NOT_SUPPORT_CHIPVER = S00 S01
# For 6226, 6226M, 6227, 6229: only 6226C (S02), 6226M (S02), 6227 (S02), 6229E4 (S02) and later chip version support SECURE PLATFORM

SECURE_SUPPORT_NOT_SUPPORT_NFB_PLATFORM = MT6226 MT6229 MT6225 MT6253T MT6253 MT6253E MT6253L MT6223 MT6227 MT6230 MT6226M MT6223P MT6252 MT6252H
SECURE_SUPPORT_NOT_SUPPORT_NFB_PARTIAL_PLATFORM = MT6226 MT6229 MT6227 MT6226M
SECURE_SUPPORT_NOT_SUPPORT_NFB_CHIPVER = S00 S01 S02
# For 6229 (S00, S01, S02), 6226 (S00, S01, S02), 6227 (S00, S01, S02), 6226M (S00, S01, S02): do not support SECURE PLATFORM when NFB is on

ifdef SECURE_SUPPORT
  ifeq ($(strip $(SECURE_SUPPORT)),TRUE)
    ifneq ($(strip $(SECURE_RO_ENABLE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,SECURE_RO_ENABLE,SECURE_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    # Platforms which do not support secure platform
    ifneq ($(filter $(strip $(PLATFORM)),$(SECURE_SUPPORT_NOT_SUPPORT_PLATFORM)),)
      ifneq ($(filter $(strip $(PLATFORM)), $(SECURE_SUPPORT_NOT_SUPPORT_PARTIAL_PLATFORM)),)
        # Platforms which do not support secure platform
        ifneq ($(filter $(strip $(CHIP_VER)), $(SECURE_SUPPORT_NOT_SUPPORT_CHIPVER)),)
          $(warning ERROR: $(strip $(PLATFORM)) $(strip $(CHIP_VER)) does not support SECURE_SUPPORT.) 
          DEPENDENCY_CONFLICT = TRUE
        # Platforms which partially support secure platform (new chip version)
        else
          ifneq ($(filter $(strip $(PLATFORM)),$(SECURE_SUPPORT_NOT_SUPPORT_NFB_PARTIAL_PLATFORM)),)
            ifneq ($(filter $(strip $(CHIP_VER)),$(SECURE_SUPPORT_NOT_SUPPORT_NFB_CHIPVER)),)
              ifeq ($(strip $(NAND_FLASH_BOOTING)),NONE)
                COM_DEFS    += __MTK_SECURE_PLATFORM__
              else
                $(warning ERROR: $(strip $(PLATFORM)) $(strip $(CHIP_VER)) does not support SECURE_SUPPORT when NAND_FLASH_BOOTING is not NONE.) 
                DEPENDENCY_CONFLICT = TRUE
              endif
            # new chip version of partial NFB support platform
            else
              COM_DEFS    += __MTK_SECURE_PLATFORM__
            endif
          endif
        endif
      # Platforms which do not support secure platform
      else
        $(warning ERROR: $(strip $(PLATFORM)) not support SECURE_SUPPORT.) 
        DEPENDENCY_CONFLICT = TRUE
      endif
    # Platforms which support secure platform
    else
      ifneq ($(filter $(strip $(PLATFORM)),$(SECURE_SUPPORT_NOT_SUPPORT_NFB_PLATFORM)),)
        ifneq ($(filter $(strip $(PLATFORM)),$(SECURE_SUPPORT_NOT_SUPPORT_NFB_PARTIAL_PLATFORM)),)
          ifneq ($(filter $(strip $(CHIP_VER)),$(SECURE_SUPPORT_NOT_SUPPORT_NFB_CHIPVER)),)
            ifeq ($(strip $(NAND_FLASH_BOOTING)),NONE)
              COM_DEFS    += __MTK_SECURE_PLATFORM__
            else
              $(warning ERROR: $(strip $(PLATFORM)) $(strip $(CHIP_VER)) not support SECURE_SUPPORT when NAND_FLASH_BOOTING is not NONE.) 
              DEPENDENCY_CONFLICT = TRUE
            endif
          endif
        #  NFB support platform
        else
          ifeq ($(strip $(NAND_FLASH_BOOTING)),NONE)
            COM_DEFS    += __MTK_SECURE_PLATFORM__
          else
            $(warning ERROR: $(strip $(PLATFORM)) not support SECURE_SUPPORT when NAND_FLASH_BOOTING is not NONE.) 
            DEPENDENCY_CONFLICT = TRUE
          endif
        endif
      # other support platforms
      else
        COM_DEFS    += __MTK_SECURE_PLATFORM__
      endif
    endif
  endif
endif

ifdef SECURE_RO_ENABLE
  ifeq ($(strip $(SECURE_RO_ENABLE)),TRUE)
    ifeq ($(strip $(SECURE_SUPPORT)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,SECURE_SUPPORT,SECURE_RO_ENABLE)
      DEPENDENCY_CONFLICT = TRUE
    else
      COM_DEFS    += __SECURE_RO_ENABLE__
    endif
  endif
endif

ifdef DOWNLOADABLE_THEME
   ifeq ($(strip $(DOWNLOADABLE_THEME)),TRUE)
      ifdef XML_SUPPORT
        ifneq ($(strip $(XML_SUPPORT)),TRUE)
           $(call DEP_ERR_ONA_OR_OFFB,XML_SUPPORT,DOWNLOADABLE_THEME)
           DEPENDENCY_CONFLICT = TRUE
        endif
      endif
      ifeq ($(strip $(BROWSER_SUPPORT)),NONE)
         $(call DEP_ERR_ONA_OR_OFFB,BROWSER_SUPPORT,DOWNLOADABLE_THEME)
         DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS    += __DOWNLOADABLE_THEME__
   endif
endif

ifndef DLT_ALWAYS_LOAD_BUFFER_SIZE
   DLT_ALWAYS_LOAD_BUFFER_SIZE = 0
endif

ifdef DLT_ALWAYS_LOAD_BUFFER_SIZE
   COM_DEFS    += __DLT_ALWAYS_LOAD_BUFFER_SIZE__=$(strip $(DLT_ALWAYS_LOAD_BUFFER_SIZE))
endif

ifndef DLT_LOAD_ON_DEMAND_BUFFER_SIZE
   DLT_LOAD_ON_DEMAND_BUFFER_SIZE = 0
endif

ifdef DLT_LOAD_ON_DEMAND_BUFFER_SIZE
   COM_DEFS    += __DLT_LOAD_ON_DEMAND_BUFFER_SIZE__=$(strip $(DLT_LOAD_ON_DEMAND_BUFFER_SIZE))
endif

TEARING_REDUCTION_FB_PLATFORM = MT6227 MT6227D MT6226 MT6226M MT6226D 
ifneq ($(filter $(strip $(PLATFORM)),$(TEARING_REDUCTION_FB_PLATFORM)),)
   ifeq ($(call Upper,$(strip $(MAIN_LCD_SIZE))),240X320)
      COM_DEFS  +=  __TEARING_REDUCTION_FB_IN_INTSRAM__
   endif
   ifeq ($(call Upper,$(strip $(MAIN_LCD_SIZE))),320X240)
      COM_DEFS  +=  __TEARING_REDUCTION_FB_IN_INTSRAM__
   endif
   ifeq ($(call Upper,$(strip $(MAIN_LCD_SIZE))),400X240)
      COM_DEFS  +=  __TEARING_REDUCTION_FB_IN_INTSRAM__
   endif
   ifeq ($(call Upper,$(strip $(MAIN_LCD_SIZE))),400X240)
      COM_DEFS  +=  __TEARING_REDUCTION_FB_IN_INTSRAM__
   endif
endif

ifdef STREAM_SUPPORT
  ifeq ($(strip $(STREAM_SUPPORT)),TRUE)
     COM_DEFS    += STREAM_SUPPORT
  endif
endif

ifdef PGDL_SUPPORT
  ifeq ($(strip $(PGDL_SUPPORT)),TRUE)
    PGDL_NOT_SUPPORT_PLATFORM = MT6205% MT6217 MT6218% MT6219 MT6223% MT6225 MT6226% MT6227% MT6228
    ifneq ($(filter $(strip $(PGDL_NOT_SUPPORT_PLATFORM)),$(strip $(PLATFORM))),)
      $(warning ERROR: $(strip $(PLATFORM)) does NOT support PGDL_SUPPORT) 
      DEPENDENCY_CONFLICT = TRUE
    endif
     ifneq ($(strip $(STREAM_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,STREAM_SUPPORT,PGDL_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
     endif
     COM_DEFS    += PGDL_SUPPORT
  endif
endif

ifeq ($(strip $(BT_FAX_PROFILE)),TRUE)
    ifdef BT_SPP_CLIENT
        ifneq ($(strip $(BT_SPP_CLIENT)),NONE)
            VIRTUAL_PORTS_NUM       = 5      # with FAX & SPP_CLIENT
        endif
        ifeq ($(strip $(BT_SPP_CLIENT)),NONE)
            VIRTUAL_PORTS_NUM       = 4      # with FAX, without SPP_CLIENT
        endif       
    endif
    ifndef BT_SPP_CLIENT
        VIRTUAL_PORTS_NUM       = 4      # with FAX, without SPP_CLIENT
    endif
else
    ifdef BT_SPP_CLIENT
        ifneq ($(strip $(BT_SPP_CLIENT)),NONE)
            VIRTUAL_PORTS_NUM       = 4      # without FAX, with SPP_CLIENT
        endif
        ifeq ($(strip $(BT_SPP_CLIENT)),NONE)
            VIRTUAL_PORTS_NUM       = 3      # without FAX & SPP_CLIENT
        endif
    endif
    ifndef BT_SPP_CLIENT
        VIRTUAL_PORTS_NUM       = 3      # without FAX & SPP_CLIENT
    endif
endif

ifdef VIRTUAL_PORTS_NUM
     COM_DEFS    += VIRTUAL_PORTS_NUM=$(strip $(VIRTUAL_PORTS_NUM))
endif

ifdef SYNCML_DM_SUPPORT
  ifeq ($(strip $(SYNCML_DM_SUPPORT)),INSIGNIA_DM)
    COM_DEFS    += SYNCML_DM_SUPPORT
    COM_DEFS    += OMADM
    #COM_DEFS    += OMADM_V1
    COMPLIST    += insignia_dm
    #### CUS_REL_SRC_COMP    += dm
    COMPLIST    += insignia_dmsdk
    #### CUS_REL_SRC_COMP    += dmsdk    
  endif    
endif

ifeq ($(strip $(SPATIAL_DITHERING)),TRUE)
     COM_DEFS += __SPATIAL_DITHERING__
endif

ifeq ($(strip $(PICTBRIDGE_SUPPORT)),TRUE)
     ifeq ($(strip $(USB_SUPPORT)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,PICTBRIDGE_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
     endif
     ifeq ($(strip $(XML_SUPPORT)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,XML_SUPPORT,PICTBRIDGE_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
     endif
     COM_DEFS +=  PICTBRIDGE_SUPPORT
     COM_DEFS +=  __USB_IMAGE_CLASS__
endif

ifeq ($(strip $(UNIFIED_MESSAGE_SIMBOX_SUPPORT)),TRUE)
    COM_DEFS	+= __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
endif

ifdef TDMB_SUPPORT
  ifneq ($(strip $(TDMB_SUPPORT)),NONE)
    ifeq ($(strip $(FINGER_TOUCH_SUPPORT)),FTE)
      $(warning ERROR: TDMB_SUPPORT do not support FTE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COMPLIST += cyberlink
    COM_DEFS += __TDMB_SUPPORT__
    COMPOBJS += vendor\tdmb\cyberlink\lib\arm\LibDemuxInterface.a
    COMPOBJS += vendor\tdmb\cyberlink\lib\arm\LibDLSParser.a
    COMPOBJS += vendor\tdmb\cyberlink\lib\arm\LibPADParser.a
    CUS_REL_OBJ_LIST += vendor\tdmb\cyberlink\lib\arm\LibDemuxInterface.a
    CUS_REL_OBJ_LIST += vendor\tdmb\cyberlink\lib\arm\LibDLSParser.a
    CUS_REL_OBJ_LIST += vendor\tdmb\cyberlink\lib\arm\LibPADParser.a	
    CUS_REL_BASE_COMP += vendor\tdmb\cyberlink\lib
  endif
  ifeq ($(strip $(TDMB_SUPPORT)),TELECHIP_TDMB)
    COMPLIST += tdmb
    COM_DEFS    += TELECHIP_TDMB
    COMPOBJS    += tdmb\tc3100\lib\ops.a tdmb\tc3100\lib\opi.a
    COMPOBJS    += tdmb\tc3100\OSSDK\lib\ads_arm7tdmi\CommonAPI.a
    COMPOBJS    += tdmb\tc3100\OSSDK\lib\ads_arm7tdmi\FICParser.a
    CUS_REL_OBJ_LIST += tdmb\tc3100\lib\ops.a tdmb\tc3100\lib\opi.a
    CUS_REL_OBJ_LIST += tdmb\tc3100\OSSDK\lib\ads_arm7tdmi\CommonAPI.a
    CUS_REL_OBJ_LIST += tdmb\tc3100\OSSDK\lib\ads_arm7tdmi\FICParser.a
  endif 
  ifeq ($(strip $(TDMB_SUPPORT)),FRONTIER_TDMB)
    COMPLIST += tdmb
    COM_DEFS    += FRONTIER_TDMB
    COMPOBJS    += tdmb\Frontier\deniro.lib
    COMPOBJS    += tdmb\Frontier\fs_fig.lib
    CUS_REL_OBJ_LIST += tdmb\Frontier\deniro.lib
    CUS_REL_OBJ_LIST += tdmb\Frontier\fs_fig.lib
  endif
endif

ifneq ($(strip $(OPTR_CODE)),OP12)
  COM_DEFS    += __IP_NUMBER__
endif

ifdef ISO_PRIORITY_MODE_SUPPORT
  ifeq ($(strip $(ISO_PRIORITY_MODE_SUPPORT)),TRUE)
    COM_DEFS    += ISO_PRIORITY_SUPPORT 
  endif       
endif

ifdef KEYPAD_TYPE
   ifeq ($(strip $(KEYPAD_TYPE)),NORMAL_KEYPAD)
      COM_DEFS    += NORMAL_KEYPAD 
   endif       
   ifeq ($(strip $(KEYPAD_TYPE)),REDUCED_KEYPAD)
      COM_DEFS    += REDUCED_KEYPAD 
   endif          
   ifeq ($(strip $(KEYPAD_TYPE)),QWERTY_KEYPAD)
      COM_DEFS    += QWERTY_KEYPAD 
   endif
   ifeq ($(strip $(KEYPAD_TYPE)),EXTEND_QWERTY_KEYPAD)
      COM_DEFS    += QWERTY_KEYPAD
      COM_DEFS    += __EXTEND_QWERTY_KEYPAD__
   endif   
endif

ifdef J2ME_SUPPORT
  ifneq ($(strip $(J2ME_SUPPORT)),NONE)
    ifneq ($(filter __KBD_JOYSTICK_SUPPORT__,$(COM_DEFS)),__KBD_JOYSTICK_SUPPORT__)
      ifneq ($(filter __THREE_KEY_DETECTION_SWITCHABLE__,$(COM_DEFS)),__THREE_KEY_DETECTION_SWITCHABLE__)
        COM_DEFS += __THREE_KEY_DETECTION_SWITCHABLE__
      endif
    endif
  endif
endif

ifdef KEYPAD_TYPE
  ifeq ($(strip $(KEYPAD_TYPE)), REDUCED_KEYPAD)
    ifeq ($(strip $(TOUCH_PANEL_SUPPORT)),NONE)
      $(call DEP_ERR_SETA_OR_ONB,KEYPAD_TYPE,non $(KEYPAD_TYPE),TOUCH_PANEL_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(KEYPAD_TYPE)), QWERTY_KEYPAD)
    ifeq ($(filter __THREE_KEY_DETECTION_SWITCHABLE__,$(COM_DEFS)),)
      ifeq ($(filter __TWO_KEY_DETECTION_SWITCHABLE__,$(COM_DEFS)),)
        COM_DEFS += __TWO_KEY_DETECTION_SWITCHABLE__
      endif
    endif
  endif
  ifeq ($(strip $(KEYPAD_TYPE)), EXTEND_QWERTY_KEYPAD)
    ifeq ($(filter __THREE_KEY_DETECTION_SWITCHABLE__,$(COM_DEFS)),)
      ifeq ($(filter __TWO_KEY_DETECTION_SWITCHABLE__,$(COM_DEFS)),)
        COM_DEFS += __TWO_KEY_DETECTION_SWITCHABLE__
      endif
    endif
  endif
  ifeq ($(strip $(KEYPAD_TYPE)), EXTEND_QWERTY_KEYPAD)
    ifneq ($(strip $(DRV_CUSTOM_TOOL_SUPPORT)),TRUE)
      $(call DEP_ERR_SETA_OR_ONB,KEYPAD_TYPE,non EXTEND_QWERTY_KEYPAD,DRV_CUSTOM_TOOL_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef FLASHLIGHT_TYPE
  ifneq ($(strip $(FLASHLIGHT_TYPE)),NONE)
    ifeq ($(strip $(FLASHLIGHT_TYPE)),LED_ONOFF_SUPPORT)
       COM_DEFS    += LED_ONOFF_SUPPORT 
    endif          
    ifeq ($(strip $(FLASHLIGHT_TYPE)),LED_FLASHLIGHT_SUPPORT)
       COM_DEFS    += LED_FLASHLIGHT_SUPPORT 
    endif          
    ifeq ($(strip $(FLASHLIGHT_TYPE)),XENON_FLASHLIGHT)
       COM_DEFS    += XENON_FLASHLIGHT 
    endif          
    ifeq ($(strip $(FLASHLIGHT_TYPE)),XENON_FLASHLIGHT_ANTI_RED_EYE)
       COM_DEFS    += XENON_FLASHLIGHT_ANTI_RED_EYE 
    endif            
  endif
endif

XENON_FLASHLIGHT_SUPPORT_PLATFORM = MT6238 MT6239
ifdef FLASHLIGHT_TYPE
  ifeq ($(strip $(FLASHLIGHT_TYPE)),XENON_FLASHLIGHT)
    ifeq ($(filter $(strip $(PLATFORM)),$(XENON_FLASHLIGHT_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does NOT support $(strip $(FLASHLIGHT_TYPE))) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifdef FLASHLIGHT_MODULE
      ifeq ($(strip $(FLASHLIGHT_MODULE)),NONE)
        $(call DEP_ERR_SETA_OR_ONB,FLASHLIGHT_TYPE,non $(strip $(FLASHLIGHT_TYPE)),FLASHLIGHT_MODULE)
        DEPENDENCY_CONFLICT = TRUE
      endif
    else
        $(call DEP_ERR_SETA_OR_ONB,FLASHLIGHT_TYPE,non $(strip $(FLASHLIGHT_TYPE)),FLASHLIGHT_MODULE)
        DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(FLASHLIGHT_TYPE)),XENON_FLASHLIGHT_ANTI_RED_EYE)
    ifeq ($(filter $(strip $(PLATFORM)),$(XENON_FLASHLIGHT_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does NOT support $(strip $(FLASHLIGHT_TYPE)))
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifdef FLASHLIGHT_MODULE
      ifeq ($(strip $(FLASHLIGHT_MODULE)),NONE)
        $(call DEP_ERR_SETA_OR_ONB,FLASHLIGHT_TYPE,non $(strip $(FLASHLIGHT_TYPE)),FLASHLIGHT_MODULE)
        DEPENDENCY_CONFLICT = TRUE
      endif
    else
        $(call DEP_ERR_SETA_OR_ONB,FLASHLIGHT_TYPE,non $(strip $(FLASHLIGHT_TYPE)),FLASHLIGHT_MODULE)
        DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(FLASHLIGHT_TYPE)),LED_ONOFF_SUPPORT)
    ifdef FLASHLIGHT_MODULE
      ifneq ($(strip $(FLASHLIGHT_MODULE)),NONE)
        $(call DEP_ERR_SETA_OR_OFFB,FLASHLIGHT_TYPE,non $(strip $(FLASHLIGHT_TYPE)),FLASHLIGHT_MODULE)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif 
  endif
  ifeq ($(strip $(FLASHLIGHT_TYPE)),LED_FLASHLIGHT_SUPPORT)
    ifdef FLASHLIGHT_MODULE
      ifneq ($(strip $(FLASHLIGHT_MODULE)),NONE)
        $(call DEP_ERR_SETA_OR_OFFB,FLASHLIGHT_TYPE,non $(strip $(FLASHLIGHT_TYPE)),FLASHLIGHT_MODULE)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif 
  endif
  ifeq ($(strip $(FLASHLIGHT_TYPE)),NONE)
    ifdef FLASHLIGHT_MODULE
      ifneq ($(strip $(FLASHLIGHT_MODULE)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,FLASHLIGHT_TYPE,FLASHLIGHT_MODULE)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifdef FLASHLIGHT_TYPE
  ifneq ($(strip $(FLASHLIGHT_TYPE)),NONE)
    ifneq ($(filter $(strip $(PLATFORM)),$(XENON_FLASHLIGHT_SUPPORT_PLATFORM)),)
      CUS_REL_BASE_COMP += custom\drv\Flashlight_module\IMCR3603_S010AO \
                           media\camera_v2\include
    endif
  endif
endif

ARM9_PLATFORM = MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6268A MT6268 MT6270A
ARM11_PLATFORM = MT6255 MT6256 MT6276 MT6573
ifdef PLATFORM
  ifeq ($(strip $(PLATFORM)),MT6238)
      COM_DEFS    += __ARM9_MMU__ __ARM9_DCACHEABLE__ __DYNAMIC_SWITCH_CACHEABILITY__
  endif
  ifeq ($(strip $(PLATFORM)),MT6239)
      COM_DEFS    += __ARM9_MMU__ __ARM9_DCACHEABLE__ __DYNAMIC_SWITCH_CACHEABILITY__
  endif
  ifeq ($(strip $(PLATFORM)),MT6235)
      COM_DEFS    += __ARM9_MMU__ __ARM9_DCACHEABLE__ __DYNAMIC_SWITCH_CACHEABILITY__
  endif
  ifeq ($(strip $(PLATFORM)),MT6235B)
      COM_DEFS    += __ARM9_MMU__ __ARM9_DCACHEABLE__ __DYNAMIC_SWITCH_CACHEABILITY__
  endif
  ifeq ($(strip $(PLATFORM)),MT6236)
      COM_DEFS    += __ARM9_MMU__ __ARM9_DCACHEABLE__ __DYNAMIC_SWITCH_CACHEABILITY__
  endif
  ifeq ($(strip $(PLATFORM)),MT6236B)
      COM_DEFS    += __ARM9_MMU__ __ARM9_DCACHEABLE__ __DYNAMIC_SWITCH_CACHEABILITY__
  endif
  ifeq ($(strip $(PLATFORM)),MT6268A)
      COM_DEFS    += __ARM9_MMU__ __ARM9_DCACHEABLE__ __DYNAMIC_SWITCH_CACHEABILITY__
  endif
  ifeq ($(strip $(PLATFORM)),MT6268)
      COM_DEFS    += __ARM9_MMU__ __ARM9_DCACHEABLE__ __DYNAMIC_SWITCH_CACHEABILITY__
  endif
  ifeq ($(strip $(PLATFORM)),MT6270A)
      COM_DEFS    += __ARM9_MMU__ __ARM9_DCACHEABLE__ __DYNAMIC_SWITCH_CACHEABILITY__
  endif
  ifeq ($(strip $(PLATFORM)),MT6253E)
      COM_DEFS    += __MTK_MMU__ __DYNAMIC_SWITCH_CACHEABILITY__
  endif
  ifeq ($(strip $(PLATFORM)),MT6253L)
      COM_DEFS    += __MTK_MMU__ __DYNAMIC_SWITCH_CACHEABILITY__
  endif
  ifeq ($(strip $(PLATFORM)),MT6252H)
      COM_DEFS    += __MTK_MMU__ __DYNAMIC_SWITCH_CACHEABILITY__
  endif
  ifeq ($(strip $(PLATFORM)),MT6252)
      COM_DEFS    += __MTK_MMU__ __DYNAMIC_SWITCH_CACHEABILITY__
  endif

endif

ifdef BT_GPS_SUPPORT
  ifneq ($(strip $(BT_GPS_SUPPORT)),FALSE)
    ifndef BT_SPP_CLIENT
      $(call DEP_ERR_ONA_OR_OFFB,BT_SPP_CLIENT,BT_GPS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(BT_SPP_CLIENT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,BT_SPP_CLIENT,BT_GPS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS  += __BT_GPS_SUPPORT__  
    COMPLIST += gps
  endif
endif

ifdef TCPIP_SUPPORT
  ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
    ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
      $(warning ERROR: $(MMI_VERSION) does not support TCPIP_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    TCPIP_SUPPORT_ON_CONDITION = FALSE
    ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
      TCPIP_SUPPORT_ON_CONDITION = TRUE
    endif  
    ifneq ($(strip $(CSD_SUPPORT)),NONE)
      TCPIP_SUPPORT_ON_CONDITION = TRUE
    endif
    ifneq ($(strip $(WIFI_SUPPORT)),NONE)
      TCPIP_SUPPORT_ON_CONDITION = TRUE
    endif
    ifeq ($(strip $(TCPIP_SUPPORT_ON_CONDITION)),FALSE)
      $(warning ERROR: Please add __PS_SERVICE__ to CUSTOM_OPTION or turn on CSD_SUPPORT or turn on WIFI_SUPPORT when TCPIP_SUPPORT is turned on!)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef RRLP_VER_SUPPORT
  ifneq ($(strip $(RRLP_VER_SUPPORT)), NONE)
    ifeq ($(strip $(AGPS_SUPPORT)), NONE)
        $(call DEP_ERR_ONA_OR_OFFB,AGPS_SUPPORT,RRLP_VER_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    endif
    ifndef AGPS_SUPPORT
        $(call DEP_ERR_ONA_OR_OFFB,AGPS_SUPPORT,RRLP_VER_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(RRLP_VER_SUPPORT)), R99)
    COM_DEFS += __RRLP_REL_99__
  endif
  ifeq ($(strip $(RRLP_VER_SUPPORT)), R5)
    COM_DEFS += __RRLP_REL_5__
  endif          
endif

ifdef WIFI_SUPPORT
  ifneq ($(strip $(WIFI_SUPPORT)),NONE)
    ifeq ($(strip $(VENDOR)),NONE)
      ifneq ($(strip $(SSL_SUPPORT)),SSL_CIC_LIB)
        ifneq ($(strip $(SSL_SUPPORT)),MTK_SSL_CIC)
          $(call DEP_ERR_SETA_OR_OFFB,SSL_SUPPORT,SSL_CIC_LIB,WIFI_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
      ifneq ($(strip $(SECLIB_SUPPORT)),BASIC)
          $(call DEP_ERR_SETA_OR_OFFB,SECLIB_SUPPORT,BASIC,WIFI_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifeq ($(strip $(SSL_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,SSL_SUPPORT,WIFI_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifndef SSL_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,SSL_SUPPORT,WIFI_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(TCPIP_SUPPORT)),NONE)
       $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPORT,WIFI_SUPPORT)
       DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif


ifdef SSL_SUPPORT
  ifneq ($(strip $(SSL_SUPPORT)), NONE)
    COM_DEFS            += __CERTMAN_SUPPORT__
    COMPLIST            += certman sec_store
    CUS_REL_BASE_COMP   += security\certman\presetdata
  endif
endif

ifdef SOCKET_SSL_SUPPORT
  ifeq ($(strip $(SOCKET_SSL_SUPPORT)), TRUE)
    COM_DEFS            += __SSL_SUPPORT__
    COMPLIST            += tls
  endif
endif

ifdef SSL_SUPPORT
  ifeq ($(strip $(SSL_SUPPORT)),MTK_SSL_CIC)
     COMPLIST         += sb51 sbpki2 sslplus5 sslplus5adp sbpki2adp
     COM_DEFS         += __SSL_CIC__
  endif   
  
  ifeq ($(strip $(SSL_SUPPORT)),SSL_CIC_LIB)
  
      ifeq ($(strip $(COMPILER)),RVCT)
           COMPOBJS         += vendor_sec\security\certicom\v1_official\sslplus5_rvct.lib
           CUS_REL_OBJ_LIST += vendor_sec\security\certicom\v1_official\sslplus5_rvct.lib
           COMPOBJS         += vendor_sec\security\certicom\v1_official\sb51_rvct.lib
           CUS_REL_OBJ_LIST += vendor_sec\security\certicom\v1_official\sb51_rvct.lib
           COMPOBJS         += vendor_sec\security\certicom\v1_official\sbpki2_rvct.lib
           CUS_REL_OBJ_LIST += vendor_sec\security\certicom\v1_official\sbpki2_rvct.lib
      else
           COMPOBJS         += vendor_sec\security\certicom\v1_official\sslplus5.lib
           CUS_REL_OBJ_LIST += vendor_sec\security\certicom\v1_official\sslplus5.lib
           COMPOBJS         += vendor_sec\security\certicom\v1_official\sb51.lib
           CUS_REL_OBJ_LIST += vendor_sec\security\certicom\v1_official\sb51.lib
           COMPOBJS         += vendor_sec\security\certicom\v1_official\sbpki2.lib
           CUS_REL_OBJ_LIST += vendor_sec\security\certicom\v1_official\sbpki2.lib
      endif
           COMPLIST         += sslplus5adp sbpki2adp
           COM_DEFS         += __SSL_CIC__
  endif
  
  ifeq ($(strip $(SSL_SUPPORT)),OPENSSL)
     COMPLIST         += ossl_ssl ossl_ssladp
     COM_DEFS         += __OPENSSL__
  endif   
  ifeq ($(strip $(SSL_SUPPORT)),OPENSSL_MTK)
     COMPLIST         += ossl_ssl ossl_ssladp
     COM_DEFS         += __OPENSSL__
     COM_DEFS         += __OPENSSL_CHE_PORTING__
  endif   
endif

ifdef SOCKET_SSL_SUPPORT
  ifeq ($(strip $(SOCKET_SSL_SUPPORT)),TRUE)
    ifndef SSL_SUPPORT
     $(warning ERROR: Please define SSL_SUPPORT!)
     DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(SSL_SUPPORT)),NONE)
       $(call DEP_ERR_ONA_OR_OFFB,SSL_SUPPORT,SOCKET_SSL_SUPPORT)
       DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef WIFI_SUPPORT
   ifneq ($(strip $(WIFI_SUPPORT)),NONE)
      COM_DEFS += __WIFI_CHIP_DYM_POWERON__
   endif
endif

ifdef CHIP_VERSION_CHECK
   ifeq ($(strip $(CHIP_VERSION_CHECK)),TRUE)
      COM_DEFS += __CHIP_VERSION_CHECK__
   endif
else
   $(warning ERROR: The feature CHIP_VERSION_CHECK should be defined as TRUE or FALSE)
   DEPENDENCY_CONFLICT = TRUE
endif

ifdef PURE_AUDIO_SUPPORT
   ifeq ($(strip $(PURE_AUDIO_SUPPORT)),TRUE)
      ifeq ($(strip $(AAC_DECODE)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,AAC_DECODE,PURE_AUDIO_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS    += PURE_AUDIO_SUPPORT
   endif
endif

ifdef BACKGROUND_SMS_SUPPORT
  ifeq ($(strip $(BACKGROUND_SMS_SUPPORT)),TRUE)
    COM_DEFS    +=  __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
  endif
endif 

ifeq ($(strip $(call Upper,$(PROJECT))),L1S)
   COM_DEFS    +=  __GSM_RAT__ 
endif

BES_SURROUND_SUPPORT_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6235 MT6235B MT6236 MT6236B MT6238 MT6239 MT6268T MT6268H MT6268 MT6268A MT6268 MT6270A 
ifdef BES_SURROUND_SUPPORT
  ifneq ($(strip $(BES_SURROUND_SUPPORT)),NONE)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(BES_SURROUND_SUPPORT_SUPPORT_PLATFORM)),)
      $(warning ERROR: $(strip $(PLATFORM)) does not support BES_SURROUND_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    CONDITION_COM_DEFS_BESSOUND_SUPPORT = TRUE
    ifeq ($(strip $(BES_SURROUND_SUPPORT)),MODE_LSPK)
      COM_DEFS += __BES_SURROUND_LSPK__
      ifeq ($(strip $(COMPILER)),ADS)
        COMPOBJS    += dp_engine\BesSound\BesSurround_arm.a
        CUS_REL_OBJ_LIST += dp_engine\BesSound\BesSurround_arm.a
      endif
      ifeq ($(strip $(COMPILER)),RVCT)
        COMPOBJS    += dp_engine\BesSound\BesSurround_arm_rvct.a
        CUS_REL_OBJ_LIST += dp_engine\BesSound\BesSurround_arm_rvct.a
      endif
    endif
    ifeq ($(strip $(BES_SURROUND_SUPPORT)),MODE_EARP)
      COM_DEFS += __BES_SURROUND_EARP__
      ifeq ($(strip $(COMPILER)),ADS)
        COMPOBJS    += dp_engine\BesSound\BesHeadPhone_arm.a
        CUS_REL_OBJ_LIST += dp_engine\BesSound\BesHeadPhone_arm.a
      endif
      ifeq ($(strip $(COMPILER)),RVCT)
        COMPOBJS    += dp_engine\BesSound\BesHeadPhone_arm_rvct.a
        CUS_REL_OBJ_LIST += dp_engine\BesSound\BesHeadPhone_arm_rvct.a
      endif
    endif
    ifeq ($(strip $(BES_SURROUND_SUPPORT)),MODE_BOTH)
      COM_DEFS += __BES_SURROUND_LSPK__ __BES_SURROUND_EARP__
      ifeq ($(strip $(COMPILER)),ADS)
        COMPOBJS    += dp_engine\BesSound\BesSurround_arm.a
        CUS_REL_OBJ_LIST += dp_engine\BesSound\BesSurround_arm.a
        COMPOBJS    += dp_engine\BesSound\BesHeadPhone_arm.a
        CUS_REL_OBJ_LIST += dp_engine\BesSound\BesHeadPhone_arm.a
      endif
      ifeq ($(strip $(COMPILER)),RVCT)
        COMPOBJS    += dp_engine\BesSound\BesSurround_arm_rvct.a
        CUS_REL_OBJ_LIST += dp_engine\BesSound\BesSurround_arm_rvct.a
        COMPOBJS    += dp_engine\BesSound\BesHeadPhone_arm_rvct.a
        CUS_REL_OBJ_LIST += dp_engine\BesSound\BesHeadPhone_arm_rvct.a
      endif
    endif
  endif
endif

#ifdef WBXML_SUPPORT
#  ifeq ($(strip $(WBXML_SUPPORT)),TRUE)
#	  ifeq ($(strip $(call Upper,$(PROJECT))),GPRS)
#      COM_DEFS    += WBXML_SUPPORT
#      COMPLIST    += wbxmlp
#      CUS_REL_SRC_COMP    += wbxmlp
#	  endif
#	  ifeq ($(strip $(call Upper,$(PROJECT))),UMTS)
#      COM_DEFS    += WBXML_SUPPORT
#      COMPLIST    += wbxmlp
#      CUS_REL_SRC_COMP    += wbxmlp
#	  endif  
#  endif
#endif

ifdef WBXML_SUPPORT
  ifeq ($(strip $(WBXML_SUPPORT)),TRUE)
    COM_DEFS    += __WBXML_SUPPORT__
    ifneq ($(strip $(XML_SUPPORT)),TRUE)
      COMPLIST    += xmlp
    endif
  endif
endif 

# Check if BT is connected to UART2 or NOT
ifdef BLUETOOTH_SUPPORT
  ifneq ($(strip $(BLUETOOTH_SUPPORT)),NONE)              # BT is supported
    ifdef BT_CONNECT_TO_UART2
      ifeq ($(strip $(BT_CONNECT_TO_UART2)),TRUE)        # BT module is connected to UART2
        COM_DEFS += __BT_USE_UART2__
      endif
    endif
  endif 
endif

# When BT is connected to UART2, we will only allow one uart be configured in engineer mode
ifdef BLUETOOTH_SUPPORT
  ifneq ($(strip $(BLUETOOTH_SUPPORT)),NONE)              # BT is supported
    ifdef BT_CONNECT_TO_UART2
      ifeq ($(strip $(BT_CONNECT_TO_UART2)),TRUE)        # BT module is connected to UART2
        COM_DEFS += __ONLY_ONE_UART__
      endif
    endif
  endif 
endif 

ifdef BES_EQ_SUPPORT
   ifeq ($(strip $(BES_EQ_SUPPORT)),TRUE)
      NON_SW_EQ_SUPPORT_PLATFORM = MT6223 MT6223P MT6225 MT6226 MT6226D MT6226M MT6227D MT6227 MT6253 MT6253E MT6253L MT6251 MT6252 MT6252H
      ifneq ($(filter $(strip $(PLATFORM)),$(NON_SW_EQ_SUPPORT_PLATFORM)),)
         COM_DEFS += __NON_SW_EQ_SUPPORT__
      endif
      COM_DEFS += __BES_EQ_SUPPORT__
      CONDITION_COM_DEFS_BESSOUND_SUPPORT = TRUE

      ifeq ($(strip $(COMPILER)),ADS)
         COMPOBJS    += dp_engine\BesSound\BesEQ_arm.a
         CUS_REL_OBJ_LIST += dp_engine\BesSound\BesEQ_arm.a
      endif
      ifeq ($(strip $(COMPILER)),RVCT)
         COMPOBJS    += dp_engine\BesSound\BesEQ_arm_rvct.a
         CUS_REL_OBJ_LIST += dp_engine\BesSound\BesEQ_arm_rvct.a
      endif
   endif
endif

ifdef BES_LOUDNESS_SUPPORT
   BES_LOUDNESS_SUPPORT_SUPPORT_PLATFORM = MT6225 MT6228 MT6229 MT6230 MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6268A MT6268 MT6268T MT6268H MT6268 MT6253T MT6253 MT6253E MT6253L MT6252 MT6252H MT6270A
   ifeq ($(strip $(BES_LOUDNESS_SUPPORT)),TRUE)
      ifeq ($(strip $(MED_PROFILE)),MED_MODEM)
          $(call DEP_ERR_SETA_OR_OFFB,MED_PROFILE,non MED_MODEM,BES_LOUDNESS_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS += __BES_LOUDNESS_SUPPORT__
      CONDITION_COM_DEFS_BESSOUND_SUPPORT = TRUE
      ifneq ($(filter $(strip $(PLATFORM)) ,$(BES_LOUDNESS_SUPPORT_SUPPORT_PLATFORM)),)
         ifeq ($(strip $(COMPILER)),ADS)
            COMPOBJS    += dp_engine\BesSound\BesLoudness_arm.a
            CUS_REL_OBJ_LIST += dp_engine\BesSound\BesLoudness_arm.a
         endif
         ifeq ($(strip $(COMPILER)),RVCT)
            COMPOBJS    += dp_engine\BesSound\BesLoudness_arm_rvct.a
            CUS_REL_OBJ_LIST += dp_engine\BesSound\BesLoudness_arm_rvct.a
         endif
      else
         $(warning ERROR: $(strip $(PLATFORM)) does not support BES_LOUDNESS_SUPPORT)
         DEPENDENCY_CONFLICT = TRUE
      endif
   endif
endif

ifdef AUDIO_COMPENSATION_ENABLE
   BES_EQ_SUPPORT_AUDIO_COMPENSATION_ENABLE_EXCLUSIVE_PLATFORM = MT6219 MT6223 MT6223P MT6225 MT6226 MT6226D MT6226M MT6227D MT6227 MT6253 MT6253E MT6253L MT6251 MT6252 MT6252H
   ifeq ($(strip $(AUDIO_COMPENSATION_ENABLE)),TRUE)
      ifeq ($(strip $(MED_PROFILE)),MED_MODEM)
         $(call DEP_ERR_SETA_OR_OFFB,MED_PROFILE,non MED_MODEM,AUDIO_COMPENSATION_ENABLE)
         DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS += AUDIO_COMPENSATION_ENABLE
      ifeq ($(strip $(BES_EQ_SUPPORT)),TRUE)
         ifneq ($(filter $(strip $(PLATFORM)),$(BES_EQ_SUPPORT_AUDIO_COMPENSATION_ENABLE_EXCLUSIVE_PLATFORM)),)
            $(warning ERROR: BES_EQ_SUPPORT and AUDIO_COMPENSATION_ENABLE must be exclusive in $(PLATFORM)!)
            DEPENDENCY_CONFLICT = TRUE
         endif
      endif
   endif
endif

ifeq ($(strip $(PLATFORM)),MT6238)
   COM_DEFS += __NFI_VERSION2__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),MT6239)
   COM_DEFS += __NFI_VERSION2__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),MT6235)
   COM_DEFS += __NFI_VERSION2__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),MT6235B)
   COM_DEFS += __NFI_VERSION2__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),MT6236)
   COM_DEFS += __NFI_VERSION2__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),MT6236B)
   COM_DEFS += __NFI_VERSION2__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),MT6253T)
   COM_DEFS += __NFI_VERSION2__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),MT6253)
   COM_DEFS += __NFI_VERSION2__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),TK6516)
   COM_DEFS += __NFI_VERSION2__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),MT6516)
   COM_DEFS += __NFI_VERSION3__
endif

ifeq ($(strip $(PLATFORM)),MT6268A)
   COM_DEFS += __NFI_VERSION2__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),MT6268)
   COM_DEFS += __NFI_VERSION2__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),MT6270A)
   COM_DEFS += __NFI_VERSION2__ __NAND_FDM_50__
endif

ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
   COM_DEFS += __CPI_SUPPORT__ __SS_OPERATION_SUPPORT__
endif

ifeq ($(strip $(SYSDRV_BACKUP_DISK_SUPPORT)),RAW)
  ifneq ($(strip $(NOR_SUPPORT_RAW_DISK)),TRUE)
    $(call DEP_ERR_SETA_OR_ONB,SYSDRV_BACKUP_DISK_SUPPORT),non RAW,NOR_SUPPORT_RAW_DISK)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif
ifeq ($(strip $(SYSDRV_BACKUP_DISK_SUPPORT)),FAT)
  ifneq ($(strip $(NANDFDM_MULTI_INSTANCE)),TRUE)
    $(call DEP_ERR_SETA_OR_ONB,SYSDRV_BACKUP_DISK_SUPPORT),non FAT,NANDFDM_MULTI_INSTANCE)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef NOR_SUPPORT_RAW_DISK
  ifeq ($(strip $(NOR_SUPPORT_RAW_DISK)),TRUE)
    COM_DEFS += __NOR_SUPPORT_RAW_DISK__       
    ifdef SYSDRV_BACKUP_DISK_SUPPORT
      ifeq ($(strip $(SYSDRV_BACKUP_DISK_SUPPORT)),RAW)
        COM_DEFS += __SYSDRV_BACKUP_DISK__
        COM_DEFS += __SYSDRV_BACKUP_DISK_RAW__
      endif
    endif          
    ifdef LGE_SECURITY
      ifeq ($(strip $(LGE_SECURITY)),TRUE)
        COM_DEFS += __CUSTOMER_TC01_DISK__
      endif
    endif
  endif
endif

ifdef NANDFDM_MULTI_INSTANCE
  ifeq ($(strip $(NANDFDM_MULTI_INSTANCE)),TRUE)
    ifneq ($(strip $(MMI_VERSION)),WISDOM_MMI)
      $(warning ERROR: Only WISDOM_MMI supports NANDFDM_MULTI_INSTANCE=TRUE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(NAND_FLASH_BOOTING)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,NAND_FLASH_BOOTING,NANDFDM_MULTI_INSTANCE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __NANDFDM_MULTI_INSTANCE__
    ifdef  NAND_SUPPORT_RAW_DISK
      ifeq ($(strip $(NAND_SUPPORT_RAW_DISK)),TRUE)
        COM_DEFS += __NAND_SUPPORT_RAW_DISK__
        ifdef CUST_CODE
          ifeq ($(strip $(CUST_CODE)),TC01)
            COM_DEFS += __CUSTOMER_TC01_DISK__
          endif
        endif       
      endif
    endif    
    ifdef SYSDRV_BACKUP_DISK_SUPPORT
      ifeq ($(strip $(SYSDRV_BACKUP_DISK_SUPPORT)),FAT)
        COM_DEFS += __SYSDRV_BACKUP_DISK__
        COM_DEFS += __SYSDRV_BACKUP_DISK_FAT__
      endif
      ifeq ($(strip $(SYSDRV_BACKUP_DISK_SUPPORT)),TRUE)
        COM_DEFS += __SYSDRV_BACKUP_DISK__
        COM_DEFS += __SYSDRV_BACKUP_DISK_FAT__
      endif
    endif        
  endif
endif

SAIC_NOT_SUPPORT_FLATFORM = MT6205 MT6205B MT6208 MT6217 MT6218 MT6218B MT6219 MT6225 MT6226 MT6226D MT6226M MT6227 MT6227D MT6228 MT6229 MT6230 
ifeq ($(filter $(strip $(PLATFORM)),$(SAIC_NOT_SUPPORT_FLATFORM)),)
  COM_DEFS    +=    __SAIC__
endif
ifneq ($(filter __SAIC__,$(COM_DEFS)),)
  ifneq ($(filter $(strip $(PLATFORM)),$(SAIC_NOT_SUPPORT_FLATFORM)),)
    $(warning ERROR: __SAIC__ cannot be defined for PLATFORM $(strip $(PLATFORM)).)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

REPEATED_ACCH_NOT_SUPPORT_FLATFORM = MT6205 MT6205B MT6208 MT6217 MT6218 MT6218B MT6219 MT6223 MT6223P MT6225 MT6226 MT6226D MT6226M MT6227 MT6227D MT6228 MT6229 MT6230 MT6235 MT6235B MT6236 MT6236B MT6238 MT6239 MT6268T MT6268H MT6270A 
ifeq ($(filter $(strip $(PLATFORM)),$(REPEATED_ACCH_NOT_SUPPORT_FLATFORM)),)
  COM_DEFS    +=    __REPEATED_ACCH__
endif
ifneq ($(filter __REPEATED_ACCH__,$(COM_DEFS)),)
  ifneq ($(filter $(strip $(PLATFORM)),$(REPEATED_ACCH_NOT_SUPPORT_FLATFORM)),)
    $(warning ERROR: __REPEATED_ACCH__ cannot be defined for PLATFORM $(strip $(PLATFORM)).)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef BSAC_DECODE
  BSAC_DECODE_PLATFORM_CHIP_VER = $(strip $(PLATFORM))_$(strip $(CHIP_VER))
  ifeq ($(strip $(BSAC_DECODE)),TRUE)
    ifneq ($(strip $(BSAC_DECODE_PLATFORM_CHIP_VER)),MT6228_S02)
      ifneq ($(strip $(BSAC_DECODE_PLATFORM_CHIP_VER)),MT6229_S02)
        ifneq ($(strip $(BSAC_DECODE_PLATFORM_CHIP_VER)),MT6230_S02)
          ifneq ($(strip $(PLATFORM)),MT6238)
            ifneq ($(strip $(PLATFORM)),MT6239)
              ifneq ($(strip $(PLATFORM)),MT6268A)
                ifneq ($(strip $(PLATFORM)),MT6268)
                  $(warning ERROR: BSAC_DECODE only support on MT6228_S02, MT6229_S02, MT6230_S02, MT6238, MT6239, MT6268A, MT6268 !!)
                  DEPENDENCY_CONFLICT = TRUE
                endif
              endif
            endif
          endif
        endif
      endif
    endif
    ifneq ($(strip $(AAC_DECODE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,AAC_DECODE,BSAC_DECODE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    
    COM_DEFS += BSAC_DECODE
  endif
endif

ifeq ($(strip $(INTERNAL_ANTENNAL_SUPPORT)),TRUE)
   COM_DEFS    += INTERNAL_ANTENNAL_SUPPORT
endif

ifeq ($(strip $(TST_WRITE_TO_FILE)),TRUE)
   ifeq ($(strip $(TST_SUPPORT)),TRUE)
      COM_DEFS    += __TST_WRITE_TO_FILE__
   endif
endif

ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
  ifdef LOW_COST_SUPPORT
    ifeq ($(strip $(LOW_COST_SUPPORT)),NONE)
      COM_DEFS += __GIS_INTERNAL__
    endif
  else
    COM_DEFS += __GIS_INTERNAL__
  endif
endif

ifdef DCD_SUPPORT
  ifneq ($(strip $(DCD_SUPPORT)), NONE)
    ifeq ($(strip $(BROWSER_SUPPORT)), NONE)
      $(call DEP_ERR_ONA_OR_OFFB,BROWSER_SUPPORT,DCD_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(findstring CMCC,$(strip $(OPTR_SPEC))),) 
      $(call DEP_ERR_ONA_OR_OFFB,OPTR_SPEC,DCD_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif 
    COM_DEFS    += __DCD_SUPPORT__
  endif
  ifeq ($(strip $(DCD_SUPPORT)),INFRAWARE)    
    ifeq ($(strip $(COMPILER)),RVCT)
      DCD_LIB_TARGET   = vendor\dcd\v1_official\Thumb\BrowserApplication_rvct.a\
                       vendor\dcd\v1_official\Thumb\EFCInterface_rvct.a\
                       vendor\dcd\v1_official\Thumb\NetworkComponent_rvct.a\
                       vendor\dcd\v1_official\Thumb\PALComponent_rvct.a\
                       vendor\dcd\v1_official\Thumb\StorageComponent_rvct.a\
                       vendor\dcd\v1_official\Thumb\XMLParsingComponent_rvct.a\
                       vendor\dcd\v1_official\Thumb\DCDAgentComponent_rvct.a
    else  
    DCD_LIB_TARGET   = vendor\dcd\v1_official\Thumb\BrowserApplication.a\
                       vendor\dcd\v1_official\Thumb\EFCInterface.a\
                       vendor\dcd\v1_official\Thumb\NetworkComponent.a\
                       vendor\dcd\v1_official\Thumb\PALComponent.a\
                       vendor\dcd\v1_official\Thumb\StorageComponent.a\
                       vendor\dcd\v1_official\Thumb\XMLParsingComponent.a\
                       vendor\dcd\v1_official\Thumb\DCDAgentComponent.a
    endif
    DCD_LIB_WIN32 = vendor\dcd\v1_official\Win32\BrowserApplication.lib\
                    vendor\dcd\v1_official\Win32\EFCInterface.lib\
                    vendor\dcd\v1_official\Win32\NetworkComponent.lib\
                    vendor\dcd\v1_official\Win32\PALComponent.lib\
                    vendor\dcd\v1_official\Win32\StorageComponent.lib\
                    vendor\dcd\v1_official\Win32\XMLParsingComponent.lib\
                    vendor\dcd\v1_official\Win32\DCDAgentComponent.lib
    COMPOBJS    += $(DCD_LIB_TARGET)
    COM_DEFS    += DCD_$(strip $(DCD_SUPPORT))
    COMPLIST += dcd
    CUS_REL_OBJ_LIST += $(DCD_LIB_TARGET)
    CUS_REL_OBJ_LIST += $(DCD_LIB_WIN32)
    CUS_REL_BASE_COMP   +=  vendor\dcd
  endif
endif

ifeq ($(strip $(FM_RADIO_CHIP)),AR1000)
  ifneq ($(strip $(FM_RADIO_HW_SEARCH)),TRUE)
    $(call DEP_ERR_SETA_OR_ONB,FM_RADIO_CHIP,non AR1000,FM_RADIO_HW_SEARCH)
    DEPENDENCY_CONFLICT = TRUE
  else
    COM_DEFS  += __FM_RADIO_HW_SEARCH__
  endif
endif

ifeq ($(strip $(FM_RADIO_CHIP)),MT6616)
  ifneq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6616)
    $(call DEP_ERR_SETA_OR_ONB,FM_RADIO_CHIP,non MT6616,BLUETOOTH_SUPPORT=BTMTK_MT6616)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(FM_RADIO_HW_SEARCH)),TRUE)
    $(call DEP_ERR_SETA_OR_ONB,FM_RADIO_CHIP,non MT6616,FM_RADIO_HW_SEARCH)
    DEPENDENCY_CONFLICT = TRUE
  else
    COM_DEFS  += __FM_RADIO_HW_SEARCH__
    COM_DEFS  += __FM_RADIO_HW_SCAN__
  endif
  COM_DEFS  += __FM_RADIO_RDS_SUPPORT__
endif

ifeq ($(strip $(FM_RADIO_CHIP)),MT6626)
  ifneq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6626)
    ifneq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6612_22_26)
      $(call DEP_ERR_SETA_OR_ONB,FM_RADIO_CHIP,non MT6626,BLUETOOTH_SUPPORT as BTMTK_MT6626 or BTMTK_MT6612_22_26)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifneq ($(strip $(FM_RADIO_HW_SEARCH)),TRUE)
    $(call DEP_ERR_SETA_OR_ONB,FM_RADIO_CHIP,non MT6626,FM_RADIO_HW_SEARCH)
    DEPENDENCY_CONFLICT = TRUE
  else
    COM_DEFS  += __FM_RADIO_HW_SEARCH__
    COM_DEFS  += __FM_RADIO_HW_SCAN__
  endif
  COM_DEFS  += __FM_RADIO_RDS_SUPPORT__
endif

ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6626)
  ifneq ($(strip $(FM_RADIO_CHIP)),MT6626)
    $(warning ERROR: BLUETOOTH_SUPPORT and FM_RADIO_CHIP shall both indicate to MT6626 !)
  endif
endif

ifdef RFC2507_SUPPORT
  ifeq ($(strip $(RFC2507_SUPPORT)),TRUE)
     COMPLIST          += rfc2507
     COMP_TRACE_DEFS   += uas\l2\rfc2507\include\rfc2507_lib_trc.h
     CUSTOM_COMMINC    += uas\l2\rfc2507\include
     COM_DEFS          += __RFC2507_SUPPORT__
  endif   
endif

ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
  ifeq ($(strip $(USB_SUPPORT)),TRUE)
    ifneq ($(filter __EDGE_MODEM_CARD__,$(COM_DEFS)),)
      COM_DEFS += __USB_MODEM_CARD_SUPPORT__
    endif
  endif
  ifneq ($(strip $(RSAT_SUPPORT)),MODEM_WITH_RSAT)
    $(call DEP_ERR_SETA_OR_OFFB,RSAT_SUPPORT,MODEM_WITH_RSAT,EMPTY_MMI)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

CAMCORDER_SUPPORT_PLATFORM = MT6238 MT6239 MT6268 MT6268A MT6268 MT6236 MT6236B MT6270A MT6276 MT6255 MT6256 
CAMCORDER_LOW_END_SUPPORT_PLATFORM = MT6235 MT6235B MT6253 MT6253T MT6253E MT6253L MT6252 MT6252H
ifdef CAMCORDER_SUPPORT
  ifneq ($(strip $(CAMCORDER_SUPPORT)),NONE)
    
    ifeq ($(filter $(strip $(PLATFORM)) ,$(CAMCORDER_SUPPORT_PLATFORM)),)
      ifeq ($(filter $(strip $(PLATFORM)) ,$(CAMCORDER_LOW_END_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support CAMCORDER_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifneq ($(strip $(ISP_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,ISP_SUPPORT,CAMCORDER_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    
    ifneq ($(strip $(MP4_ENCODE)),TRUE)
      ifneq ($(filter $(strip $(PLATFORM)) ,$(CAMCORDER_SUPPORT_PLATFORM)),)
        $(call DEP_ERR_ONA_OR_OFFB,MP4_ENCODE,CAMCORDER_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifneq ($(filter $(strip $(PLATFORM)) ,$(CAMCORDER_LOW_END_SUPPORT_PLATFORM)),)
        ifneq ($(strip $(MJPG_ENCODE)),TRUE)
          $(call DEP_ERR_SETA_OR_SETB,MP4_ENCODE,MP4_SW,MJPG_ENCODE,TRUE)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
    
    ifneq ($(strip $(MP4_DECODE)),TRUE)
      ifneq ($(filter $(strip $(PLATFORM)) ,$(CAMCORDER_SUPPORT_PLATFORM)),)
        $(call DEP_ERR_ONA_OR_OFFB,MP4_DECODE,CAMCORDER_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifneq ($(filter $(strip $(PLATFORM)) ,$(CAMCORDER_LOW_END_SUPPORT_PLATFORM)),)
        ifneq ($(strip $(MJPG_DECODE)),TRUE)
          $(call DEP_ERR_SETA_OR_SETB,MP4_DECODE,MP4_SW,MJPG_DECODE,TRUE)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
    
    ifneq ($(filter $(strip $(PLATFORM)) ,$(CAMCORDER_LOW_END_SUPPORT_PLATFORM)),)
      ifneq ($(filter STANDARD FULL,$(CAMCORDER_SUPPORT)),)
        COM_DEFS += __CAMCORDER_SUPPORT__ __CAMCORDER_PACKAGE_$(strip $(CAMCORDER_SUPPORT))__
      else
        $(warning ERROR: Please set CAMCORDER_SUPPORT as STANDARD or FULL.)
        DEPENDENCY_CONFLICT = TRUE
      endif
    else
      COM_DEFS += __CAMCORDER_SUPPORT__ __CAMCORDER_PACKAGE_$(strip $(CAMCORDER_SUPPORT))__
    endif    
  else
    ifneq ($(filter $(strip $(PLATFORM)) ,$(CAMCORDER_SUPPORT_PLATFORM)),)
      ifdef ISP_SUPPORT
        ifeq ($(strip $(ISP_SUPPORT)),TRUE)
          $(call DEP_ERR_ONA_OR_OFFB,CAMCORDER_SUPPORT,ISP_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
  endif
endif

ifdef AUD_RECORD
  ifneq ($(strip $(AUD_RECORD)),FALSE)
    COM_DEFS    += AUD_REC_ENABLE
  else
    ifdef DEDI_AMR_REC
      ifeq ($(strip $(DEDI_AMR_REC)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,AUD_RECORD,DEDI_AMR_REC)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifdef FM_RADIO_RECORD
      ifeq ($(strip $(FM_RADIO_RECORD)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,AUD_RECORD,FM_RADIO_RECORD)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
else
    COM_DEFS    += AUD_REC_ENABLE
endif

#ifdef WIFI_SUPPORT
#    ifneq ($(strip $(WIFI_SUPPORT)),NONE)
#        ifneq ($(strip $(CBM_ALWAYS_ASK_SUPPORT)),TRUE)
#            $(call DEP_ERR_ONA_OR_OFFB,CBM_ALWAYS_ASK_SUPPORT,WIFI_SUPPORT)
#            DEPENDENCY_CONFLICT = TRUE
#        endif
#    endif
#endif

ifeq ($(strip $(CBM_ALWAYS_ASK_SUPPORT)),TRUE)
    ifndef TCPIP_SUPPORT
        $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPORT,CBM_ALWAYS_ASK_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(TCPIP_SUPPORT)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPORT,CBM_ALWAYS_ASK_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    +=  __CBM_ALWAYS_ASK__  
endif

ifeq ($(strip $(CBM_CONNECTION_MANAGER_SUPPORT)),TRUE)
    ifneq ($(strip $(MMI_VERSION)),PLUTO_MMI)
      ifneq ($(strip $(MMI_VERSION)),WISDOM_MMI)
        $(call DEP_ERR_SETA_OR_OFFB,MMI_VERSION,PLUTO_MMI/WISDOM_MMI,CBM_CONNECTION_MANAGER_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    COM_DEFS    +=  __CBM_CONNECTION_MANAGER__     
endif

ifeq ($(strip $(CBM_BEARER_FALLBACK_SUPPORT)),TRUE)
    ifndef TCPIP_SUPPORT
        $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPORT,CBM_BEARER_FALLBACK_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(TCPIP_SUPPORT)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPORT,CBM_BEARER_FALLBACK_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    +=  __CBM_BEARER_FALLBACK__
endif

ifeq ($(strip $(MULTIPLE_BINARY_FILES)),TRUE)
  ifeq ($(strip $(NAND_FLASH_BOOTING)),ONDEMAND)
    $(call DEP_ERR_SETA_OR_OFFB,NAND_FLASH_BOOTING,non ONDEMAND,MULTIPLE_BINARY_FILES)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(NAND_FLASH_BOOTING)),BASIC)
    $(call DEP_ERR_SETA_OR_OFFB,NAND_FLASH_BOOTING,non BASIC,MULTIPLE_BINARY_FILES)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    +=  __MULTIPLE_BINARY_FILES__
endif

ifeq ($(strip $(BT_PBAP_PROFILE)),TRUE)  
  ifeq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
    $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_PBAP_PROFILE)
    DEPENDENCY_CONFLICT = TRUE
  endif
    COM_DEFS    +=  __BT_PBAP_PROFILE__
endif

ifneq ($(strip $(CHE_INPUT_FROM_FSAL)),FALSE)
  COM_DEFS    +=  __CHE_INPUT_FROM_FSAL__
endif

ifdef AGPS_SUPPORT
  ifneq ($(strip $(AGPS_SUPPORT)), NONE)
    ifeq ($(strip $(GPS_SUPPORT)), NONE)
        $(call DEP_ERR_ONA_OR_OFFB,GPS_SUPPORT,AGPS_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(RRLP_VER_SUPPORT)), NONE)
        $(call DEP_ERR_ONA_OR_OFFB,RRLP_VER_SUPPORT,AGPS_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    endif
    ifndef RRLP_VER_SUPPORT
        $(call DEP_ERR_ONA_OR_OFFB,RRLP_VER_SUPPORT,AGPS_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(OMA_ULP_SUPPORT)), NONE)
        $(call DEP_ERR_ONA_OR_OFFB,OMA_ULP_SUPPORT,AGPS_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(SSL_SUPPORT)), NONE)
        $(call DEP_ERR_ONA_OR_OFFB,SSL_SUPPORT,AGPS_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(SOCKET_SSL_SUPPORT)), FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,SOCKET_SSL_SUPPORT,AGPS_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(AGPS_SUPPORT)), USER_PLANE)
        COMMINCDIRS     += ps\supl\include
        COMMINCDIRS     += ps\rrlp\include
        COM_DEFS += __AGPS_SUPPORT__ __SUPL_SUPPORT__ __RRLP_SUPPORT__ __AGPS_USER_PLANE__ __NBR_CELL_INFO__
        COMPLIST        += supl rrlp
        COMP_TRACE_DEFS += ps\supl\include\supl_trc.h
        COMP_TRACE_DEFS += ps\rrlp\include\rrlp_trc.h
        ifndef RRC_PAYLOAD_FOR_3G_UP_SUPPORT
            $(warning ERROR: Please define RRC_PAYLOAD_FOR_3G_UP_SUPPORT when AGPS_SUPPORT = $(strip $(AGPS_SUPPORT)))
            DEPENDENCY_CONFLICT = TRUE
        endif
        ifeq ($(strip $(RRC_PAYLOAD_FOR_3G_UP_SUPPORT)),TRUE)
            ifneq ($(filter UMTS HSPA,$(strip $(call Upper,$(PROJECT)))),)
                COM_DEFS += __UAGPS_UP_SUPPORT__
                ifeq ($(strip $(ULCS_ASN_SUPPORT_VERSION)), ULCS_ASN_SUPPORT_R6)
                    COM_DEFS += __ULCS_ASN_SUPPORT_R6__
                endif
                COMPLIST += ulcs
                CUS_REL_MTK_COMP += ulcs
                COMP_TRACE_DEFS += ulcs\uagps_up\include\uagps_up_trc.h
            endif
        endif
    endif
    ifeq ($(strip $(AGPS_SUPPORT)), CONTROL_PLANE)
        COMMINCDIRS     += ps\rrlp\include
        COM_DEFS += __AGPS_SUPPORT__ __RRLP_SUPPORT__ __AGPS_CONTROL_PLANE__
        COMPLIST        += rrlp
        COMP_TRACE_DEFS += ps\rrlp\include\rrlp_trc.h
    endif
    ifeq ($(strip $(AGPS_SUPPORT)), BOTH)
      COMMINCDIRS     += ps\supl\include
      COMMINCDIRS     += ps\rrlp\include
      COM_DEFS += __AGPS_SUPPORT__ __SUPL_SUPPORT__ __RRLP_SUPPORT__ __AGPS_USER_PLANE__ __AGPS_CONTROL_PLANE__ __NBR_CELL_INFO__
      COMPLIST        += supl rrlp
      COMP_TRACE_DEFS += ps\supl\include\supl_trc.h
      COMP_TRACE_DEFS += ps\rrlp\include\rrlp_trc.h
      ifndef RRC_PAYLOAD_FOR_3G_UP_SUPPORT
        $(warning ERROR: Please define RRC_PAYLOAD_FOR_3G_UP_SUPPORT when AGPS_SUPPORT = $(strip $(AGPS_SUPPORT)))
        DEPENDENCY_CONFLICT = TRUE 
      endif
      ifeq ($(strip $(RRC_PAYLOAD_FOR_3G_UP_SUPPORT)),TRUE)
        ifneq ($(filter UMTS HSPA,$(strip $(call Upper,$(PROJECT)))),)
          COM_DEFS += __UAGPS_UP_SUPPORT__
          ifeq ($(strip $(ULCS_ASN_SUPPORT_VERSION)), ULCS_ASN_SUPPORT_R6)
            COM_DEFS += __ULCS_ASN_SUPPORT_R6__
          endif
          COMPLIST += ulcs
          CUS_REL_MTK_COMP += ulcs
          COMP_TRACE_DEFS += ulcs\uagps_up\include\uagps_up_trc.h
        endif
      endif
    endif
  endif
endif

ifdef OMA_ULP_SUPPORT
    ifeq ($(strip $(OMA_ULP_SUPPORT)), V1)
        COM_DEFS += __ULP_VER_1__
    endif
    ifeq ($(strip $(OMA_ULP_SUPPORT)), V1.5)
        COM_DEFS += __ULP_VER_1__
        COM_DEFS += __ULP_VER_1_5__
    endif
    ifeq ($(strip $(OMA_ULP_SUPPORT)), V2)
        COM_DEFS += __ULP_VER_1__
        COM_DEFS += __ULP_VER_1_5__
        COM_DEFS += __ULP_VER_2__
    endif
endif

ifdef NDIS_SUPPORT
  ifeq ($(strip $(NDIS_SUPPORT)),TRUE)
    $(warning ERROR: Please set new value NONE/NDIS/UPS for NDIS_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif  
  ifeq ($(strip $(NDIS_SUPPORT)),FALSE)
    $(warning ERROR: Please set new value NONE/NDIS/UPS for NDIS_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(NDIS_SUPPORT)),NDIS)
    ifneq ($(strip $(CMUX_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,CMUX_SUPPORT,NDIS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __NDIS_SUPPORT__
  endif
  ifeq ($(strip $(NDIS_SUPPORT)),UPS)
    ifneq ($(strip $(CMUX_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,CMUX_SUPPORT,NDIS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __NDIS_SUPPORT__ __UPS_SUPPORT__
    COMPLIST    += ups
    COMP_TRACE_DEFS  += ps\ups\include\ups_trc.h
  endif
endif

ifeq ($(strip $(DISABLE_A5_2)),TRUE)
    COM_DEFS += __DISABLE_A5_2__
endif

ifneq ($(filter MT6223%,$(PLATFORM)),)
   COM_DEFS    += __DRV_SIM_CLK_DUTY_NOT_ENOUGH__
endif

ifeq ($(strip $(CAMCORDER_FACE_DETECTION_MODE_SUPPORT)),TRUE)
  FACEDETECTION_NOSUPPORT_PLATFORM =  MT6253 MT6253T MT6253E MT6253L MT6253PMU MT6252 MT6252H
  ifneq ($(filter $(strip $(PLATFORM)) ,$(FACEDETECTION_NOSUPPORT_PLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support Face Detection)
    DEPENDENCY_CONFLICT = TRUE
  else
    ifeq ($(strip $(CAMCORDER_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,CAMCORDER_SUPPORT,CAMCORDER_FACE_DETECTION_MODE_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(ISP_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,ISP_SUPPORT,CAMCORDER_FACE_DETECTION_MODE_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(CONTOUR_IMPROVEMENT_SUPPORT)),TRUE)
      $(call DEP_ERR_OFFA_OR_OFFB,CONTOUR_IMPROVEMENT_SUPPORT,CAMCORDER_FACE_DETECTION_MODE_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __FACE_DETECTION_SUPPORT__
  endif
endif

ifeq ($(strip $(UNIFIED_MESSAGE_LOW_MEMORY_SUPPORT)),TRUE)
  COM_DEFS		 += __UNIFIED_MESSAGE_LOW_MEMORY_SUPPORT__
endif

ifeq ($(strip $(MSG_SMS_EMAIL_SUPPORT)),TRUE)
  ifneq ($(strip $(OPTR_CODE)),OP11)
    $(warning ERROR: MSG_SMS_EMAIL_SUPPORT is not supported on NON-ORANGE project yet)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(UNIFIED_MESSAGE_LOW_MEMORY_SUPPORT)),TRUE)   
    $(call DEP_ERR_ONA_OR_OFFB,UNIFIED_MESSAGE_LOW_MEMORY_SUPPORT,MSG_SMS_EMAIL_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(findstring COMPOSER,$(strip $(UNIFIED_MESSAGE_ADVANCE_FEATURE))),)
    $(call DEP_ERR_SETA_OR_OFFB,UNIFIED_MESSAGE_LOW_MEMORY_SUPPORT,non $(strip $(UNIFIED_MESSAGE_ADVANCE_FEATURE)),MSG_SMS_EMAIL_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE 
  endif
  COM_DEFS  += __MSG_SMS_EMAIL_SUPPORT__
endif

ifdef WAV_CODEC
    ifeq ($(strip $(WAV_CODEC)),TRUE)
        COM_DEFS    += WAV_CODEC
    else
        ifeq ($(strip $(AIFF_DECODE)),TRUE)   
            $(call DEP_ERR_ONA_OR_OFFB,WAV_CODEC,AIFF_DECODE)
            DEPENDENCY_CONFLICT = TRUE
        endif
        ifeq ($(strip $(AU_DECODE)),TRUE)   
            $(call DEP_ERR_ONA_OR_OFFB,WAV_CODEC,AU_DECODE)
            DEPENDENCY_CONFLICT = TRUE
        endif
    endif
endif

ifdef AMR_CODEC
    ifeq ($(strip $(AMR_CODEC)),TRUE)
        COM_DEFS    += AMR_CODEC
    else
        ifeq ($(strip $(DEDI_AMR_REC)),TRUE)   
            $(call DEP_ERR_ONA_OR_OFFB,AMR_CODEC,DEDI_AMR_REC)
            DEPENDENCY_CONFLICT = TRUE
        endif
        ifeq ($(strip $(AMRWB_ENCODE)),TRUE)   
            $(call DEP_ERR_ONA_OR_OFFB,AMR_CODEC,AMRWB_ENCODE)
            DEPENDENCY_CONFLICT = TRUE
        endif
        ifeq ($(strip $(AMRWB_DECODE)),TRUE)   
            $(call DEP_ERR_ONA_OR_OFFB,AMR_CODEC,AMRWB_DECODE)
            DEPENDENCY_CONFLICT = TRUE
        endif
    endif
endif

ifdef CCBS_SUPPORT
  ifeq ($(strip $(CCBS_SUPPORT)),TRUE)
     COM_DEFS    += __CCBS_SUPPORT__
  endif
endif

ifdef CNAP_SUPPORT
  ifeq ($(strip $(CNAP_SUPPORT)),TRUE)
     COM_DEFS    += __CNAP_SUPPORT__
  endif
endif

ifeq ($(strip $(call Upper,$(PROJECT))),GSM)
  ifdef L1_GPRS
    ifeq ($(strip $(L1_GPRS)),TRUE)
      $(warning ERROR: GSM project does not support L1_GPRS. Please turn off L1_GPRS)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifdef L1_EGPRS
    ifeq ($(strip $(L1_EGPRS)),TRUE)
      $(warning ERROR: GSM project does not support L1_EGPRS. Please turn off L1_EGPRS)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifdef L1_EPSK_TX
    ifeq ($(strip $(L1_EPSK_TX)),TRUE)
      $(warning ERROR: GSM project does not support L1_EPSK_TX. Please turn off L1_EPSK_TX)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
      $(warning ERROR: GSM project does not support __PS_SERVICE__ option )
      DEPENDENCY_CONFLICT = TRUE
   endif
endif

ifeq ($(strip $(TST_LOGACC_SUPPORT)),TRUE)
   ifneq ($(strip $(TST_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,TST_SUPPORT,TST_LOGACC_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
   else
      COM_DEFS    += __LOGACC_ENABLE__
   endif
endif

ifdef SWITCHABLE_FEATURE_2ND
  ifneq ($(strip $(SWITCHABLE_FEATURE_2ND)),NONE)
    ifndef SWITCHABLE_FEATURE
      $(call DEP_ERR_ONA_OR_OFFB,SWITCHABLE_FEATURE,SWITCHABLE_FEATURE_2ND)
      DEPENDENCY_CONFLICT = TRUE
    else
      ifeq ($(strip $(SWITCHABLE_FEATURE)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,SWITCHABLE_FEATURE,SWITCHABLE_FEATURE_2ND)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifeq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
    ifeq ($(strip $(CCBS_SUPPORT)),TRUE)
        $(warning ERROR: Please turn off CCBS_SUPPORT in NEPTUNE project!) 
        DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(CNAP_SUPPORT)),TRUE)
        $(warning ERROR: Please turn off CNAP_SUPPORT in NEPTUNE project!)
        DEPENDENCY_CONFLICT = TRUE 
    endif
endif

ifdef MODEM_3G_LOGGING
   ifeq ($(strip $(MODEM_3G_LOGGING)),TRUE)
     ifneq ($(strip $(USB_SUPPORT)),TRUE)
       $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,MODEM_3G_LOGGING)
       DEPENDENCY_CONFLICT = TRUE
     endif
      COM_DEFS    += __MODEM_3G_LOGGING__
      COM_DEFS    += __USB_LOGGING__
   endif
endif

ifdef EXT_MODEM_SUPPORT
  ifeq ($(strip $(EXT_MODEM_SUPPORT)), TRUE)
    ifndef TCPIP_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPORT,EXT_MODEM_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(TCPIP_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPOR,EXT_MODEM_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COMPLIST          += ext_modem
    COMP_TRACE_DEFS   += ps\ext_modem\include\ext_modem_trc.h
    CUSTOM_COMMINC    += ps\ext_modem\include
    COM_DEFS += __EXT_MODEM__
  endif
endif

ifdef MMS_SUPPORT
  ifneq ($(strip $(MMS_SUPPORT)),NONE)
    ifeq ($(strip $(OBIGO_FEATURE)),NONE)     
      $(call DEP_ERR_ONA_OR_OFFB,OBIGO_FEATURE,MMS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(MMS_SUPPORT)),OBIGO_Q03C_MMS_V02)
      ifeq ($(strip $(OBIGO_FEATURE)),NONE)     
        $(call DEP_ERR_ONA_OR_OFFB,OBIGO_FEATURE,MMS_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS    += MMS_SUPPORT OBIGO_Q03C_MMS_V02
      COMP_TRACE_DEFS += vendor\mms\obigo_q03c\adaptation\integration\include\mms_trc.h
      COMP_TRACE_DEFS += vendor\framework\obigo_Q03C\adaptation\integration\include\trc\wps_trc.h	
      COMPLIST    += obigo03cmmsadp obigo03cmmslib
      COMPLIST    += obigo03cfwlib obigo03cfwadp
      COMMINCDIRS      += plutommi\MMI\UnifiedMMS\MMSBGSR\MMSBGSRInc
    endif     
  endif
endif

ifdef J2ME_SUPPORT
  ifneq ($(strip $(J2ME_SUPPORT)),NONE)
    ifeq ($(strip $(call Upper,$(SUPPORT_JSR_205))),TRUE)
      ifeq ($(filter MMS_SUPPORT,$(COM_DEFS)),)
        $(warning ERROR: MMS_SUPPORT must be added to COM_DEFS when SUPPORT_JSR_205 is TRUE)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(strip $(MMS_SUPPORT)),OBIGO_Q03C_MMS_V02)
        COM_DEFS    +=   __MMS_JSR_205_SUPPORT__
      endif
    endif
  endif
endif

ifdef J2ME_SUPPORT
  ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA)
    ifeq ($(strip $(FINGER_TOUCH_SUPPORT)),FTE)
      $(warning ERROR: J2ME_SUPPORT is JBLENDIA do not support FTE)
      DEPENDENCY_CONFLICT = TRUE
    endif  
  endif
  ifeq ($(strip $(J2ME_SUPPORT)),JBED)
    ifeq ($(strip $(FINGER_TOUCH_SUPPORT)),FTE)
      $(warning ERROR: J2ME_SUPPORT is JBED do not support FTE)
      DEPENDENCY_CONFLICT = TRUE
    endif  
  endif 
endif

ifdef BACKGROUND_SMS_SUPPORT
  ifeq ($(strip $(BACKGROUND_SMS_SUPPORT)),TRUE)
      ifneq ($(filter __EMS_NON_STD_7BIT_CHAR__,$(COM_DEFS)),)
        $(warning ERROR: Please turn off BACKGROUND_SMS_SUPPORT when __EMS_NON_STD_7BIT_CHAR__ is defined! )
        DEPENDENCY_CONFLICT = TRUE
      endif
  endif
endif
    
ifdef LQT_SUPPORT
  ifeq ($(strip $(LQT_SUPPORT)),TRUE)
    COM_DEFS += LQT_SUPPORT
    COMPLIST += lqt
    COMMINCDIRS += lqt\include
  endif
endif

ifeq ($(filter MT6223%,$(PLATFORM)),)
  ifneq ($(strip $(MMI_FEATURES_SWITCH)),TRUE)
    ifneq ($(strip $(LQT_SUPPORT)),TRUE)
      $(warning ERROR: LQT_SUPPORT is a mandatory feature. Please turn on LQT_SUPPORT.)
      DEPENDENCY_CONFLICT = TRUE  
    endif  
  endif
else
  ifeq ($(strip $(LQT_SUPPORT)),TRUE)
    $(warning ERROR: MT6223 series did not support LQT_SUPPORT. Please turn off LQT_SUPPORT.)
    DEPENDENCY_CONFLICT = TRUE  
  endif
endif

ifndef SMS_PHONE_ENTRY
     $(warning ERROR: Please define SMS_PHONE_ENTRY in project makefile.)
     DEPENDENCY_CONFLICT = TRUE
endif

ifndef SMS_TOTAL_ENTRY
     $(warning ERROR: Please define SMS_TOTAL_ENTRY in project makefile.)
     DEPENDENCY_CONFLICT = TRUE
endif

ifdef SMS_PHONE_ENTRY
     COM_DEFS    += SMS_PHONE_ENTRY=$(strip $(SMS_PHONE_ENTRY))
endif

ifdef SMS_TOTAL_ENTRY
     COM_DEFS    += SMS_TOTAL_ENTRY=$(strip $(SMS_TOTAL_ENTRY))
endif

ifndef SMS_SIM_ENTRY
  $(warning ERROR: Please define SMS_SIM_ENTRY in project makefile.)
  DEPENDENCY_CONFLICT = TRUE
endif

ifdef SMS_SIM_ENTRY
  COM_DEFS    += SMS_SIM_ENTRY=$(strip $(SMS_SIM_ENTRY))
endif

ifdef SECURE_PORT_SUPPORT
  ifeq ($(strip $(SECURE_PORT_SUPPORT)),TRUE)
    ifneq ($(strip $(SECURE_RO_ENABLE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,SECURE_RO_ENABLE,SECURE_PORT_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    else
      COM_DEFS    += __SECURE_PORT_SUPPORT__
    endif
  endif
endif

ifdef BIP_SCWS_SUPPORT
  ifeq ($(strip $(BIP_SCWS_SUPPORT)),TRUE)
    ifneq ($(strip $(BROWSER_SUPPORT)),OBIGO_Q03C)
      $(call DEP_ERR_SETA_OR_OFFB,BROWSER_SUPPORT,OBIGO_Q03C,BIP_SCWS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifndef TCPIP_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPORT,BIP_SCWS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(TCPIP_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPORT,BIP_SCWS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(TCPIP_LOOP_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,TCPIP_LOOP_SUPPORT,BIP_SCWS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(filter __SAT__,$(COM_DEFS)),)
        $(warning ERROR: __SAT__ must be defined when BIP_SCWS_SUPPORT is turned on.) 
        DEPENDENCY_CONFLICT = TRUE
    endif   
    COM_DEFS    += __SATCE__
  endif
endif

ifdef IPSEC_SUPPORT
  ifneq ($(strip $(IPSEC_SUPPORT)),FALSE)
    ifneq ($(strip $(TCPIP_SUPPORT)),UDP_TCP)
      $(call DEP_ERR_SETA_OR_OFFB,TCPIP_SUPPORT,UDP_TCP,IPSEC_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __IPSEC__
    COMP_TRACE_DEFS += security\ike\include\ike_trc.h
    COMMINCDIRS     +=  interface\security
    COMPLIST    += ipsec netkey ike
  endif
endif

ifdef FONT_ENGINE
  ifneq ($(strip $(FONT_ENGINE)),NONE)
    VECTORFONT_NOT_SUPPORT_PLATFORM = MT6205 MT6205B MT6223 MT6223P MT6226 MT6227 MT6226M MT6226D
    ifneq ($(filter $(strip $(PLATFORM)),$(VECTORFONT_NOT_SUPPORT_PLATFORM)),)
       $(warning ERROR: Vector font (FONT_ENGINE) is not supported for PLATFORM $(strip $(PLATFORM)))
       DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(filter $(call Upper,$(strip $(MAIN_LCD_SIZE))),240X320 320X240 240X400 320X480),)
      $(warning ERROR: FONT_ENGINE only supports 240X320, 320X240, 240X400 and 320X480 MAIN_LCD_SIZE)
      DEPENDENCY_CONFLICT = TRUE
    endif
     COM_DEFS += FONT_ENGINE_SUPPORT __MMI_VECTOR_FONT_SUPPORT__
     COM_DEFS += $(strip $(FONT_ENGINE))
  endif
  ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
    ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
      ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_MONOTYPE)
        $(warning ERROR: For customer project, please set FONT_ENGINE = FONT_ENGINE_MONOTYPE_DEMO, not set FONT_ENGINE = FONT_ENGINE_MONOTYPE)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_FREETYPE)
        $(warning ERROR: For customer project, please set FONT_ENGINE = FONT_ENGINE_FREETYPE_DEMO, not set FONT_ENGINE = FONT_ENGINE_FREETYPE)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_WTLE)
        $(warning ERROR: For customer project, please set FONT_ENGINE = FONT_ENGINE_MONOTYPE_DEMO because there is no wtle demo resource)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifdef FONT_ENGINE
  ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_MONOTYPE)
    COMPLIST    += vectorfont_monotype
    CUS_REL_SRC_COMP += vectorfont_monotype
    ifeq ($(strip $(COMPILER)),ADS)
      COMPOBJS    += vendor\vectorfont\monotype\official\engine_v1\ads_monotype_engine.a
      CUS_REL_OBJ_LIST  	+= vendor\vectorfont\monotype\official\engine_v1\ads_monotype_engine.a 
      CUS_REL_OBJ_LIST  	+= vendor\vectorfont\monotype\official\engine_v1\monotype_engine.lib
    endif
    ifeq ($(strip $(COMPILER)),RVCT)
      COMPOBJS    += vendor\vectorfont\monotype\official\engine_v1\rvct_monotype_engine.a
      CUS_REL_OBJ_LIST  	+= vendor\vectorfont\monotype\official\engine_v1\rvct_monotype_engine.a 
      CUS_REL_OBJ_LIST  	+= vendor\vectorfont\monotype\official\engine_v1\monotype_engine.lib
    endif
  endif
  ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_MONOTYPE_DEMO)
    COMPLIST    += vectorfont_monotype
    CUS_REL_SRC_COMP += vectorfont_monotype
    CUS_REL_BASE_COMP += vendor\vectorfont\monotype\adaptation \
                         vendor\vectorfont\monotype\demo
    ifeq ($(strip $(COMPILER)),ADS)
      COMPOBJS  	+= vendor\vectorfont\monotype\demo\engine_v1\ads_monotype_engine.a
      CUS_REL_OBJ_LIST  	+= vendor\vectorfont\monotype\demo\engine_v1\ads_monotype_engine.a 
      CUS_REL_OBJ_LIST  	+= vendor\vectorfont\monotype\demo\engine_v1\monotype_engine.lib
    endif
    ifeq ($(strip $(COMPILER)),RVCT)
      COMPOBJS  	+= vendor\vectorfont\monotype\demo\engine_v1\rvct_monotype_engine.a
      CUS_REL_OBJ_LIST  	+= vendor\vectorfont\monotype\demo\engine_v1\rvct_monotype_engine.a 
      CUS_REL_OBJ_LIST  	+= vendor\vectorfont\monotype\demo\engine_v1\monotype_engine.lib
    endif
  endif
  ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_FREETYPE)
    COMPLIST    += vectorfont_freetype
    CUS_REL_SRC_COMP += vectorfont_freetype
    CUS_REL_BASE_COMP += vendor\vectorfont\freetype
  endif
  ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_FREETYPE_DEMO)
    COMPLIST    += vectorfont_freetype
    CUS_REL_SRC_COMP += vectorfont_freetype
    CUS_REL_BASE_COMP += vendor\vectorfont\freetype
  endif
  ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_WTLE)
    COMPLIST    += vectorfont_wtle
    CUS_REL_SRC_COMP += vectorfont_wtle
    ifeq ($(strip $(COMPILER)),ADS)
      COMPOBJS    += vendor\vectorfont\monotype\official\engine_wtle\ads_itype_engine.a
      COMPOBJS    += vendor\vectorfont\monotype\official\engine_wtle\ads_wtle_engine.a
      CUS_REL_OBJ_LIST  	+= vendor\vectorfont\monotype\official\engine_wtle\ads_itype_engine.a 
      CUS_REL_OBJ_LIST  	+= vendor\vectorfont\monotype\official\engine_wtle\itype_engine.lib
      CUS_REL_OBJ_LIST  	+= vendor\vectorfont\monotype\official\engine_wtle\ads_wtle_engine.a 
      CUS_REL_OBJ_LIST  	+= vendor\vectorfont\monotype\official\engine_wtle\wtle_engine.lib
    endif
    ifeq ($(strip $(COMPILER)),RVCT)
      COMPOBJS    += vendor\vectorfont\monotype\official\engine_wtle\rvct_itype_engine.a
      COMPOBJS    += vendor\vectorfont\monotype\official\engine_wtle\rvct_wtle_engine.a
      CUS_REL_OBJ_LIST  	+= vendor\vectorfont\monotype\official\engine_wtle\rvct_itype_engine.a 
      CUS_REL_OBJ_LIST  	+= vendor\vectorfont\monotype\official\engine_wtle\itype_engine.lib
      CUS_REL_OBJ_LIST  	+= vendor\vectorfont\monotype\official\engine_wtle\rvct_wtle_engine.a 
      CUS_REL_OBJ_LIST  	+= vendor\vectorfont\monotype\official\engine_wtle\wtle_engine.lib
    endif
  endif
  ifneq ($(strip $(FONT_ENGINE)),NONE)
    CUS_REL_BASE_COMP += plutommi\Customer\Fonts\Android \
                         plutommi\Customer\Fonts\MTK \
                         plutommi\Customer\Fonts\Arphic_demo \
                         plutommi\Customer\Fonts\Monotype_demo
  endif
endif

ifdef CMMB_SUPPORT
  ifneq ($(strip $(CMMB_SUPPORT)),NONE)
    ifneq ($(strip $(SQLITE3_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,SQLITE3_SUPPORT,CMMB_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(DRA_DECODE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,DRA_DECODE,CMMB_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(FINGER_TOUCH_SUPPORT)),FTE)
      $(warning ERROR: CMMB_SUPPORT do not support FTE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __CMMB_SUPPORT__
    CUS_REL_OBJ_LIST +=  vendor\tdmb\cyberlink\lib\pc\LibCodecInterface.lib \
                         vendor\tdmb\cyberlink\lib\pc\SDL.lib
  endif
  ifneq ($(strip $(CMMB_SUPPORT)),NONE)
    COMPLIST += cmmb
    COM_DEFS += __$(strip $(CMMB_SUPPORT))__
    COMMINCDIRS += custom\drv\CMMB_Demod\$(strip $(CMMB_SUPPORT))\Adaption\inc \
                   custom\drv\CMMB_Demod\$(strip $(CMMB_SUPPORT))\Demod\inc
  endif
  ifeq ($(strip $(CMMB_SUPPORT)),SIANO_SMS2186)
    COMMINCDIRS += custom\drv\CMMB_Demod\SIANO_SMS2186\smshostlib_lite\include \
                     custom\drv\CMMB_Demod\SIANO_SMS2186\smshostlib_lite\include_internal \
                     custom\drv\CMMB_Demod\SIANO_SMS2186\smshostlib_lite\include_internal\zlib \
                     custom\drv\CMMB_Demod\SIANO_SMS2186\smshostlib_lite\platforms\Nucleus \
                     custom\drv\CMMB_Demod\SIANO_SMS2186\smshostlib_lite\platforms\Nucleus\ADR \
                     custom\drv\CMMB_Demod\SIANO_SMS2186\smshostlib_lite\platforms\Nucleus\OSW\Header \
                     custom\drv\CMMB_Demod\SIANO_SMS2186\smshostlib_lite\platforms\Nucleus\SPIDriver\Header
    COMP_TRACE_DEFS += custom\drv\CMMB_Demod\SIANO_SMS2186\Adaption\inc\siano_cmmb_trc.h
  endif
endif

ifdef SQLITE3_SUPPORT
    ifeq ($(strip $(SQLITE3_SUPPORT)),TRUE)
       COMPLIST    += applib_sqlite3
       COM_DEFS    += __SQLITE3_SUPPORT__
       COMP_TRACE_DEFS += applib\sqlite3\inc\sqlite3_trc.h
       CUS_REL_BASE_COMP += applib\sqlite3\inc
    endif
endif

ifeq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
    COM_DEFS += __SAT_LOWCOST_UI_DISABLE__ __SAT_LOWCOST_NW_DISABLE__
endif

ifndef VENDOR
  VENDOR = NONE
endif

ifdef VENDOR
  ifneq ($(strip $(VENDOR)),NONE)
    COM_DEFS +=  DEVAPP_RESOURCE
  endif
endif

ifdef PRODUCTION_RELEASE
  ifeq ($(strip $(PRODUCTION_RELEASE)),FALSE)
    COM_DEFS += L1A_DEVELOP_DEBUG
    ifeq ($(strip $(VENDOR)),NONE)
      ifneq ($(strip $(DEMO_PROJECT)),TRUE)
        ifeq ($(findstring REL_CR_OBJ_JAL_SRC,$(strip $(RELEASE_PACKAGE))),)
          $(call DEP_ERR_ONA_OR_ONB,PRODUCTION_RELEASE,DEMO_PROJECT)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
      ifneq ($(strip $(EMPTY_RESOURCE)),FALSE)
        ifeq ($(findstring REL_CR_OBJ_JAL_SRC,$(strip $(RELEASE_PACKAGE))),)
          $(call DEP_ERR_ONA_OR_OFFB,PRODUCTION_RELEASE,EMPTY_RESOURCE)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
      ifneq ($(strip $(MTK_SUBSIDIARY)),TRUE)
        ifeq ($(filter REL_CR_OBJ_JAL_SRC% REL_CR_MMI_VOGINS%,$(strip $(RELEASE_PACKAGE))),)
          $(call DEP_ERR_ONA_OR_ONB,PRODUCTION_RELEASE,MTK_SUBSIDIARY)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
      ifeq ($(strip $(DEMO_PROJECT)),TRUE)
        ifdef LOW_COST_SUPPORT
          ifeq ($(strip $(LOW_COST_SUPPORT)),NONE)
            ifneq ($(filter __MOD_SMU__,$(COM_DEFS)),)
              ifneq ($(filter __MOD_SMS__,$(COM_DEFS)),)
                COM_DEFS    += __SMS_DEPERSONALIZATION__
              endif
            endif
          endif
        else
          ifneq ($(filter __MOD_SMU__,$(COM_DEFS)),)
            ifneq ($(filter __MOD_SMS__,$(COM_DEFS)),)
              COM_DEFS    += __SMS_DEPERSONALIZATION__
            endif
          endif
        endif
      endif
    else
      ifeq ($(strip $(DEMO_PROJECT)),TRUE)
        ifneq ($(strip $(EMPTY_RESOURCE)),TRUE)
          $(warning ERROR: PLEASE turn on EMPTY_RESOURCE for vendor projects)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
  else
    ifeq ($(strip $(DEMO_PROJECT)),TRUE)
      $(call DEP_ERR_OFFA_OR_OFFB,DEMO_PROJECT,PRODUCTION_RELEASE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifneq ($(filter __SMS_DEPERSONALIZATION__,$(COM_DEFS)),)
  ifeq ($(filter __MOD_SMU__,$(COM_DEFS)),)
    $(call DEP_ERR_ONA_OR_OFFB,__MOD_SMU__,__SMS_DEPERSONALIZATION__)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(filter __MOD_SMS__,$(COM_DEFS)),)
    $(call DEP_ERR_ONA_OR_OFFB,__MOD_SMS__,__SMS_DEPERSONALIZATION__)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef GPRS_DIALUP_PPP_SUPPORT_ESCAPE_ATO
  ifeq ($(strip $(GPRS_DIALUP_PPP_SUPPORT_ESCAPE_ATO)), TRUE)
    COM_DEFS += __GPRS_DIALUP_ESCAPE_ATO_SUPPORT__
  endif
endif

ifneq ($(filter GSM,$(call Upper,$(PROJECT))),)
  ifeq ($(strip $(GPRS_DIALUP_PPP_SUPPORT_ESCAPE_ATO)), TRUE)
    $(warning ERROR: PLEASE turn off GPRS_DIALUP_PPP_SUPPORT_ESCAPE_ATO in $(PROJECT) project)
    DEPENDENCY_CONFLICT = TRUE    
  endif
endif

ifdef GPRS_DIALUP_PPP_DROP_PACKETS_WHEN_2G_PS_SUSPEND 
  ifeq ($(strip $(GPRS_DIALUP_PPP_DROP_PACKETS_WHEN_2G_PS_SUSPEND)), TRUE)
    COM_DEFS += __PPP_DROP_PACKETS_WHEN_2G_PS_SUSPEND__
  endif
endif

ifneq ($(filter GSM,$(call Upper,$(PROJECT))),)
  ifeq ($(strip $(GPRS_DIALUP_PPP_DROP_PACKETS_WHEN_2G_PS_SUSPEND)), TRUE)
    $(warning ERROR: PLEASE turn off GPRS_DIALUP_PPP_DROP_PACKETS_WHEN_2G_PS_SUSPEND in $(PROJECT) project)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef MULTIPLE_PPP_DIALUP_SUPPORT
  ifeq ($(strip $(MULTIPLE_PPP_DIALUP_SUPPORT)),TRUE)
     ifeq ($(call gt,$(strip $(MAX_NUM_OF_PPP_DIALUP_SUPPORT)),$(strip $(GPRS_MAX_PDP_SUPPORT))),T)
       $(warning ERROR: MAX_NUM_OF_PPP_DIALUP_SUPPORT value ($(MAX_NUM_OF_PPP_DIALUP_SUPPORT)) should not be larger than GPRS_MAX_PDP_SUPPORT value ($(GPRS_MAX_PDP_SUPPORT)))
       DEPENDENCY_CONFLICT = TRUE
     endif
     ifeq ($(call gt,$(strip $(MAX_NUM_OF_PPP_DIALUP_SUPPORT)),3),T)
       $(warning ERROR: MAX_NUM_OF_PPP_DIALUP_SUPPORT value ($(MAX_NUM_OF_PPP_DIALUP_SUPPORT)) should not be larger than 3)
       DEPENDENCY_CONFLICT = TRUE
     endif
     ifeq ($(call lt,$(strip $(MAX_NUM_OF_PPP_DIALUP_SUPPORT)),2),T)
       $(warning ERROR: MAX_NUM_OF_PPP_DIALUP_SUPPORT value ($(MAX_NUM_OF_PPP_DIALUP_SUPPORT)) should not be less than 2)
       DEPENDENCY_CONFLICT = TRUE
     endif
     COM_DEFS          += __MULTIPLE_PPP_DIALUP_SUPPORT__
     COM_DEFS          += __MAX_NUM_OF_PPP_DIALUP_SUPPORT__=$(strip $(MAX_NUM_OF_PPP_DIALUP_SUPPORT))
  endif
endif

ifneq ($(filter __REL5__,$(COM_DEFS)),)
    COM_DEFS  +=  __REMOVE_FA__ 
else
  ifdef LOW_COST_SUPPORT
    ifneq ($(strip $(LOW_COST_SUPPORT)),NONE)
     COM_DEFS += __REMOVE_FA__ 
    endif
  endif
endif

MEDIA_PLAYER_VER_MAIN_LCD_SIZE = 128X160 176X220 240X320 240X400 320X480 320X240 
ifdef MEDIA_PLAYER_VER
  ifeq ($(strip $(MEDIA_PLAYER_VER)),INTEGRATED_DB)
    ifneq ($(strip $(SQLITE3_SUPPORT)),TRUE)
      $(call DEP_ERR_SETA_OR_ONB,MEDIA_PLAYER_VER,non INTEGRATED_DB,SQLITE3_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(filter $(strip $(call Upper,$(MAIN_LCD_SIZE))),$(MEDIA_PLAYER_VER_MAIN_LCD_SIZE)),)
      $(warning ERROR: MAIN_LCD_SIZE = $(MAIN_LCD_SIZE) is not supported when MEDIA_PLAYER_VER = INTEGRATED_DB!)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __INTEGRATED_PLAYER_DB__
  endif 
  ifeq ($(strip $(MEDIA_PLAYER_VER)),INTEGRATED)
    ifeq ($(filter $(strip $(call Upper,$(MAIN_LCD_SIZE))),$(MEDIA_PLAYER_VER_MAIN_LCD_SIZE)),)
      $(warning ERROR: MAIN_LCD_SIZE = $(MAIN_LCD_SIZE) is not supported when MEDIA_PLAYER_VER = INTEGRATED!)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __INTEGRATED_PLAYER__
  endif 
  ifeq ($(strip $(MEDIA_PLAYER_VER)),INTEGRATED_FTE_DB)
    ifneq ($(strip $(SQLITE3_SUPPORT)),TRUE)
      $(call DEP_ERR_SETA_OR_ONB,MEDIA_PLAYER_VER,non INTEGRATED_FTE_DB,SQLITE3_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(FINGER_TOUCH_SUPPORT)),FTE)
      $(call DEP_ERR_SETA_OR_SETB,FINGER_TOUCH_SUPPORT,FTE,MEDIA_PLAYER_VER,non INTEGRATED_FTE_DB)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(PLATFORM)),MT6225)
      $(call DEP_ERR_SETA_OR_SETB,MEDIA_PLAYER_VER,non INTEGRATED_FTE_DB,PLATFORM,non MT6225)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __INTEGRATED_PLAYER_FTE_DB__ __PLST_SERVICE_DB_SUPPORT__
  endif
endif

ifdef DRM_SUPPORT
  ifneq ($(strip $(DRM_SUPPORT)),NONE)  
    ifdef DRM_SUPPORT_SCAN_DISK
      ifeq ($(strip $(DRM_SUPPORT_SCAN_DISK)),TRUE)
        ifeq ($(strip $(DRM_SUPPORT)),WS)
          $(warning ERROR: DRM_SUPPORT_SCAN_DISK can not be TRUE when DRM_SUPPORT equals to WS)
          DEPENDENCY_CONFLICT = TRUE
        endif 
        COM_DEFS += __DRM_SUPPORT_SCAN_DISK__
      endif
    endif        
    ifdef DRM_SUPPORT_DB_SIZE
      ifeq ($(strip $(DRM_SUPPORT_DB_SIZE)),NONE)
        COM_DEFS   += MAX_DRM_DB_SIZE=(0)
      endif
      ifneq ($(strip $(DRM_SUPPORT_DB_SIZE)),NONE)
        ifeq ($(strip $(DRM_SUPPORT_DB_SIZE)),DEFAULT)
          ifeq ($(strip $(DRM_SUPPORT)),BSCI)
            COM_DEFS   += MAX_DRM_DB_SIZE=(64)
          else
            COM_DEFS   += MAX_DRM_DB_SIZE=(1024)
          endif
        else  
          ifeq ($(strip $(DRM_SUPPORT)),BSCI)
            ifeq ($(call gt, $(strip $(DRM_SUPPORT_DB_SIZE)),64), T)
                            $(warning ERROR: DRM_SUPPORT_DB_SIZE value is incorrect!)
                            DEPENDENCY_CONFLICT = TRUE
            endif
            COM_DEFS   += MAX_DRM_DB_SIZE=(64)
          else
            ifneq ($(strip $(DRM_SUPPORT_DB_SIZE)),256)
              ifneq ($(strip $(DRM_SUPPORT_DB_SIZE)),512)
                ifneq ($(strip $(DRM_SUPPORT_DB_SIZE)),1024)
                                    $(warning ERROR: DRM_SUPPORT_DB_SIZE value is incorrect!)
                                    DEPENDENCY_CONFLICT = TRUE
                endif 
              endif
            endif   
            COM_DEFS   += MAX_DRM_DB_SIZE=($(strip $(DRM_SUPPORT_DB_SIZE)))
          endif    
        endif
      endif
    endif
  endif
endif

ifdef BACKGROUND_CALL_SUPPORT
    ifeq ($(strip $(BACKGROUND_CALL_SUPPORT)),TRUE)
      ifeq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
        $(warning ERROR: BACKGROUND_CALL_SUPPORT can not be TRUE when MMI_BASE is NEPTUNE_MMI)
        DEPENDENCY_CONFLICT = TRUE
      endif 
      COM_DEFS    +=  __BACKGROUND_CALL_SUPPORT__
    endif
endif

ifneq ($(filter __EDGE_MODEM_CARD__,$(COM_DEFS)),)
    COM_DEFS += __DISABLE_MODEM_AUTO_POWER_OFF__
    COM_DEFS += __DISABLE_MODEM_AUTO_STARTUP__
endif

ifdef MULTIPLE_NDIS_SUPPORT
  ifeq ($(strip $(MULTIPLE_NDIS_SUPPORT)),TRUE)
     ifndef NDIS_SUPPORT
       $(call DEP_ERR_ONA_OR_OFFB,NDIS_SUPPORT,MULTIPLE_NDIS_SUPPORT)
       DEPENDENCY_CONFLICT = TRUE
     endif
     ifeq ($(strip $(NDIS_SUPPORT)),NONE)
       $(call DEP_ERR_ONA_OR_OFFB,NDIS_SUPPORT,MULTIPLE_NDIS_SUPPORT)
       DEPENDENCY_CONFLICT = TRUE
     endif
     ifeq ($(strip $(MULTIPLE_PPP_DIALUP_SUPPORT)),TRUE)
       $(call DEP_ERR_OFFA_OR_OFFB,MULTIPLE_NDIS_SUPPORT,MULTIPLE_PPP_DIALUP_SUPPORT)
       DEPENDENCY_CONFLICT = TRUE
     endif
     ifeq ($(call gt,$(strip $(MAX_NUM_OF_NDIS_SUPPORT)),$(strip $(GPRS_MAX_PDP_SUPPORT))),T)
       $(warning ERROR: MAX_NUM_OF_NDIS_SUPPORT value ($(MAX_NUM_OF_NDIS_SUPPORT)) should not be larger than GPRS_MAX_PDP_SUPPORT value ($(GPRS_MAX_PDP_SUPPORT)))
       DEPENDENCY_CONFLICT = TRUE
     endif
     ifeq ($(call gt,$(strip $(MAX_NUM_OF_NDIS_SUPPORT)),3),T)
       $(warning ERROR: MAX_NUM_OF_NDIS_SUPPORT value ($(MAX_NUM_OF_NDIS_SUPPORT)) should not be larger than 3)
       DEPENDENCY_CONFLICT = TRUE
     endif
     ifeq ($(call lt,$(strip $(MAX_NUM_OF_NDIS_SUPPORT)),2),T)
       $(warning ERROR: MAX_NUM_OF_NDIS_SUPPORT value ($(MAX_NUM_OF_NDIS_SUPPORT)) should not be less than 2)
       DEPENDENCY_CONFLICT = TRUE
     endif
     COM_DEFS          += __MULTIPLE_NDIS_SUPPORT__
     COM_DEFS          += __MAX_NUM_OF_NDIS_SUPPORT__=$(strip $(MAX_NUM_OF_NDIS_SUPPORT))
  endif
endif

ifeq ($(strip $(AF_AUXI_LED_SUPPORT)),TRUE)
    ifneq ($(strip $(AF_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,AF_SUPPORT,AF_AUXI_LED_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __AF_AUXI_LED_SUPPORT__
endif

ifndef NVRAM_NOT_PRESENT
  ifdef NVRAM_PSEUDO_MERGE
    ifeq ($(strip $(NVRAM_PSEUDO_MERGE)),ON)
      COM_DEFS +=  __NVRAM_PSEUDO_MERGE__
    endif
  endif
endif

ifdef UDX_SUPPORT
  ifeq ($(strip $(UDX_SUPPORT)),TRUE)
    ifneq ($(strip $(XML_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,XML_SUPPORT,UDX_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __UDX_SUPPORT__
    COMPLIST    += udx
  endif
endif

ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
  COM_DEFS    += __UCM_SUPPORT__
  COM_DEFS    += __AUTO_CALL_REJECTION__
endif

ifdef DRA_DECODE
  ifeq ($(strip $(DRA_DECODE)),TRUE)
    DRA_DECODE_SUPPORT_PLATFORM = MT6235 MT6235B MT6236 MT6236B MT6238 MT6239 MT6268T MT6268H MT6268A MT6268 MT6270A 
    ifeq ($(filter $(strip $(PLATFORM)),$(DRA_DECODE_SUPPORT_PLATFORM)),)
          $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support DRA_DECODE.)
          DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __DRA_DECODE_SUPPORT__
    ifeq ($(strip $(EMPTY_RESOURCE)),FALSE)
      ifeq ($(strip $(COMPILER)),ADS)
        COMPOBJS    += l1audio\obj\ArmDraDecLib.a
        CUS_REL_OBJ_LIST += l1audio\obj\ArmDraDecLib.a
      endif
      ifeq ($(strip $(COMPILER)),RVCT)
        COMPOBJS    += l1audio\obj\ArmDraDecLib_rvct.a
        CUS_REL_OBJ_LIST += l1audio\obj\ArmDraDecLib_rvct.a
      endif
    else
      ifeq ($(strip $(COMPILER)),ADS)
        COMPOBJS    += l1audio\obj\ArmDraDecLib_Trial.a
        CUS_REL_OBJ_LIST += l1audio\obj\ArmDraDecLib_Trial.a
      endif
      ifeq ($(strip $(COMPILER)),RVCT)
        COMPOBJS    += l1audio\obj\ArmDraDecLib_rvct_Trial.a
        CUS_REL_OBJ_LIST += l1audio\obj\ArmDraDecLib_rvct_Trial.a
      endif
    endif
  endif
endif

ifeq ($(strip $(SMS_R8_NATION_LANGUAGE)),TRUE)
  ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
    ifeq ($(strip $(EMS_SUPPORT)),EMS_NONE)
      $(call DEP_ERR_ONA_OR_OFFB,EMS_SUPPORT,EMS_R8_NATION_LANGUAGE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifndef EMS_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,EMS_SUPPORT,EMS_R8_NATION_LANGUAGE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  COM_DEFS += __SMS_R8_NATION_LANGUAGE__
endif

ifdef UNIFIED_MESSAGE_MARK_SEVERAL_FEATURE
    ifeq ($(strip $(UNIFIED_MESSAGE_MARK_SEVERAL_FEATURE)), TRUE)
        ifeq ($(strip $(UNIFIED_MESSAGE_FOLDER)), TRUE)
            ifneq ($(strip $(MMS_SUPPORT)), OBIGO_Q03C_MMS_V02)
              $(call DEP_ERR_ONA_OR_OFFB,MMS_SUPPORT,UNIFIED_MESSAGE_MARK_SEVERAL_FEATURE)
              DEPENDENCY_CONFLICT = TRUE
            endif
        endif
        COM_DEFS    += __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
    endif
endif

ifeq ($(strip $(BES_BASS_SUPPORT)),TRUE)
  BES_BASS_SUPPORT_SUPPORT_PLATFORM = MT6235 MT6235B MT6236 MT6236B MT6238 MT6239 MT6268T MT6268H MT6268 MT6268A MT6268 MT6270A 
  ifeq ($(filter $(strip $(PLATFORM)) ,$(BES_BASS_SUPPORT_SUPPORT_PLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support BES_BASS_SUPPORT.)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(filter MED_NOT_PRESENT,$(COM_DEFS)),)
    $(warning ERROR: Please turn off BES_BASS_SUPPORT when MED_NOT_PRESENT is defined)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(MED_PROFILE)),MED_MODEM)
    $(call DEP_ERR_SETA_OR_OFFB,MED_PROFILE,non MED_MODEM,BES_BASS_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS   += __BES_BASS_SUPPORT__
  CONDITION_COM_DEFS_BESSOUND_SUPPORT = TRUE
  ifeq ($(strip $(COMPILER)),ADS)
    COMPOBJS   += dp_engine\BesSound\BesBass_arm.a
    CUS_REL_OBJ_LIST += dp_engine\BesSound\BesBass_arm.a
  endif
  ifeq ($(strip $(COMPILER)),RVCT)
    COMPOBJS   += dp_engine\BesSound\BesBass_arm_rvct.a
    CUS_REL_OBJ_LIST += dp_engine\BesSound\BesBass_arm_rvct.a
  endif
endif

ifdef MMS_FEATURES
    ifndef MMS_SUPPORT
        $(warning ERROR: Please define MMS_SUPPORT when MMS_FEATURES is defined!)
        DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(MMS_FEATURES)),NONE)
        ifneq ($(strip $(MMS_SUPPORT)),NONE)
            $(warning ERROR: MMS_FEATURES can NOT be NONE when MMS_SUPPORT != NONE!)
            DEPENDENCY_CONFLICT = TRUE
        endif
    endif
    ifneq ($(strip $(MMS_FEATURES)),NONE)
        ifeq ($(strip $(MMS_SUPPORT)),NONE)
            $(warning ERROR: MMS_FEATURES MUST be NONE when MMS_SUPPORT = NONE!)
            DEPENDENCY_CONFLICT = TRUE
        endif
        ifeq ($(strip $(MMS_FEATURES)),SLIM)
            COM_DEFS += __SLIM_MMS__
        endif
    endif
endif

ifdef SYNCML_DEVICE_SYNC_SUPPORT
    ifeq ($(strip $(SYNCML_DEVICE_SYNC_SUPPORT)),TRUE)
        ifneq ($(strip $(SYNCML_SUPPORT)),TRUE)
          $(call DEP_ERR_ONA_OR_OFFB,SYNCML_SUPPORT,SYNCML_DEVICE_SYNC_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
        endif
        ifndef BLUETOOTH_SUPPORT
            $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,SYNCML_DEVICE_SYNC_SUPPORT)
            DEPENDENCY_CONFLICT = TRUE
        endif
        ifeq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
            $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,SYNCML_DEVICE_SYNC_SUPPORT)
            DEPENDENCY_CONFLICT = TRUE
        endif
        COM_DEFS    += __SYNCML_DEVICE_SYNC__
        COM_DEFS    += __SYNCML_TRANS_BT_SUPPORT__
        COM_DEFS    += __BT_SUPPORT_SYNCML__
        COM_DEFS    += __OBEX_ADAP_SUPPORT__
        ifneq ($(strip $(EMPTY_RESOURCE)),TRUE)
            COM_DEFS    += __SYNCML_DEVICE_SYNC_INTERNAL_TEST__
        endif
    endif
endif

ifdef SYNCML_PC_SYNC_SUPPORT
    ifeq ($(strip $(SYNCML_PC_SYNC_SUPPORT)),TRUE)
        ifneq ($(strip $(SYNCML_SUPPORT)),TRUE)
            $(call DEP_ERR_ONA_OR_OFFB,SYNCML_SUPPORT,SYNCML_PC_SYNC_SUPPORT)
            DEPENDENCY_CONFLICT = TRUE
        endif
        ifndef BLUETOOTH_SUPPORT
            $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,SYNCML_PC_SYNC_SUPPORT)
            DEPENDENCY_CONFLICT = TRUE
        endif
        ifeq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
            $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,SYNCML_PC_SYNC_SUPPORT)
            DEPENDENCY_CONFLICT = TRUE
        endif
        COM_DEFS    += __SYNCML_PC_SYNC_SUPPORT__
        COM_DEFS    += __SYNCML_TRANS_BT_SUPPORT__
        COM_DEFS    += __BT_SUPPORT_SYNCML__
        COM_DEFS    += __OBEX_ADAP_SUPPORT__
    endif
endif

ifeq ($(strip $(SYNCML_DEVICE_SYNC_SUPPORT)),TRUE)
    COMPLIST    += obex_stub
else
    ifeq ($(strip $(SYNCML_PC_SYNC_SUPPORT)),TRUE)
        COMPLIST    += obex_stub
    endif
endif

ifdef MSHUTTER_SUPPORT
  ifneq ($(strip $(MSHUTTER_SUPPORT)),FALSE)
    ifndef CMOS_SENSOR
      $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR,MSHUTTER_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(CMOS_SENSOR)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR,MSHUTTER_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    +=  MSHUTTER_SUPPORT
  endif
endif

ifdef SMS_R8_TABLE_MECHANISM
   COM_DEFS += __$(strip $(SMS_R8_TABLE_MECHANISM))__
else
   COM_DEFS += __SMS_R8_DEFAULT__
endif

ifeq ($(strip $(PANORAMA_VIEW_SUPPORT)),TRUE)
  PANORAMA_NOSUPPORT_PLATFORM =  MT6253 MT6253T MT6253E MT6253L MT6253PMU MT6252 MT6252H
  ifneq ($(filter $(strip $(PLATFORM)) ,$(PANORAMA_NOSUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support Panorama)
       DEPENDENCY_CONFLICT = TRUE
  else
    ifneq ($(strip $(CAMCORDER_SUPPORT)),FULL)
      $(call DEP_ERR_SETA_OR_OFFB,CAMCORDER_SUPPORT,FULL,PANORAMA_VIEW_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(ISP_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,ISP_SUPPORT,PANORAMA_VIEW_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __PANORAMA_VIEW_SUPPORT__
  endif
endif

ifeq ($(strip $(GPS_HS_SUPPORT)),TRUE)
  ifneq ($(strip $(GPS_SUPPORT)),MT3326)
    $(call DEP_ERR_SETA_OR_OFFB,GPS_SUPPORT,MT3326,GPS_HS_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    += __BEE_SUPPORT__ 
  COMPLIST    += bee      
  ifeq ($(strip $(COMPILER)),RVCT)
      COMPOBJS    += gps\bee\lib\MTK_HS_rvct.lib
      CUS_REL_OBJ_LIST += gps\bee\lib\MTK_HS_rvct.lib
  else
      COMPOBJS    += gps\bee\lib\MTK_HS.lib
      CUS_REL_OBJ_LIST += gps\bee\lib\MTK_HS.lib
  endif 
  CUS_REL_FILES_LIST += gps\bee\lib\MTK_HS_WIN32.lib
endif

ifdef PMU_WITH_EXTERNL_CHARGER
  ifeq ($(strip $(PMU_WITH_EXTERNL_CHARGER)),TRUE)
    ifdef GENERAL_EXTERNAL_CHARGER
      ifneq ($(strip $(GENERAL_EXTERNAL_CHARGER)),NONE)
         $(call DEP_ERR_OFFA_OR_OFFB,GENERAL_EXTERNAL_CHARGER,PMU_WITH_EXTERNL_CHARGER)
         DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifdef GENERAL_EXTERNAL_CHARGER
  ifneq ($(strip $(GENERAL_EXTERNAL_CHARGER)),NONE)
    COM_DEFS    +=  __GENERAL_EXTERNAL_CHARGER__
    COM_DEFS    +=  __EXT_CHARGER_$(strip $(GENERAL_EXTERNAL_CHARGER))__
  endif
endif

ifdef PMU_WITH_EXTERNL_CHARGER
  ifeq ($(strip $(PMU_WITH_EXTERNL_CHARGER)),TRUE)
    ifeq ($(strip $(DRV_CUSTOM_TOOL_SUPPORT)),TRUE)
      COM_DEFS    +=  __PMU_WITH_EXTERNL_CHARGER__
    endif
  endif
endif

ifeq ($(strip $(CONDITION_COM_DEFS_BESSOUND_SUPPORT)),TRUE)
    COM_DEFS   += BESSOUND_SUPPORT
endif

A8BOX_SUPPORT_PLATFORM = MT6225 MT6229 MT6235 MT6235B MT6236 MT6236B MT6238 MT6239 MT6268 MT6268A MT6268T MT6268H MT6253 MT6253T MT6253E MT6253L MT6252 MT6252H
ifdef A8BOX_SUPPORT
  ifeq ($(strip $(A8BOX_SUPPORT)),TRUE)
    ifeq ($(filter $(strip $(PLATFORM)),$(A8BOX_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) not support A8BOX.)
      DEPENDENCY_CONFLICT = TRUE
    endif 
    ifneq ($(strip $(BITSTREAM_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BITSTREAM_SUPPORT,A8BOX_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(FINGER_TOUCH_SUPPORT)),FTE)
      $(warning ERROR: A8BOX_SUPPORT do not support FTE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __A8BOX_SUPPORT__ __ELFMUSIC_SUPPORT__
    COMPLIST    += a8box
    COMPOBJS    += vendor\streaming\a8box\lib\official\a8box_arm.lib
    CUS_REL_OBJ_LIST += vendor\streaming\a8box\lib\official\a8box_arm.lib
    CUS_REL_FILES_LIST += vendor\streaming\a8box\lib\official\a8box_arm.lib
    CUS_REL_OBJ_LIST += vendor\streaming\a8box\lib\official\a8box_w32.lib
    CUS_REL_FILES_LIST += vendor\streaming\a8box\lib\official\a8box_w32.lib \
                          vendor\streaming\a8box\adaptation\Inc\elf_def.h \
                          vendor\streaming\a8box\adaptation\Inc\elf_features.h \
                          vendor\streaming\a8box\adaptation\Inc\elf_res_def.h
  endif
endif

ifdef CMMB_CAS_FULL_CARD_SUPPORT
    ifeq ($(strip $(CMMB_CAS_FULL_CARD_SUPPORT)),TRUE)
       ifeq ($(strip $(CMMB_SUPPORT)),NONE)
          $(call DEP_ERR_ONA_OR_OFFB,CMMB_SUPPORT,CMMB_CAS_FULL_CARD_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
       endif
       ifndef CMMB_SUPPORT
          $(call DEP_ERR_ONA_OR_OFFB,CMMB_SUPPORT,CMMB_CAS_FULL_CARD_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
       endif
       COM_DEFS    += __CMMB_CAS_FULL_CARD_SUPPORT__
       ifeq ($(filter DRV_MSDC_CLK_SEARCH,$(COM_DEFS)),)
         COM_DEFS += DRV_MSDC_CLK_SEARCH
       endif
    endif
endif

ifeq ($(strip $(USB_MASS_STORAGE_SUPPORT)),TRUE)
     ifeq ($(strip $(USB_SUPPORT)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,USB_MASS_STORAGE_SUPPORT )
        DEPENDENCY_CONFLICT = TRUE
     endif
     COM_DEFS +=  __USB_MASS_STORAGE_ENABLE__
endif

ifeq ($(strip $(USB_COM_PORT_SUPPORT)),TRUE)
     ifeq ($(strip $(USB_SUPPORT)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,USB_COM_PORT_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
     endif
     COM_DEFS +=  __USB_COM_PORT_ENABLE__
endif

ifndef MELODY_BUFFER_LEN
ifeq ($(strip $(MED_PROFILE)),MED_MODEM)
     MELODY_BUFFER_LEN = 512
else
    ifeq ($(strip $(MED_PROFILE)),MED_LOW)
         MELODY_BUFFER_LEN = 1300
    else
         MELODY_BUFFER_LEN = 102400
    endif
endif
endif 

ifdef OPTR_CODE
  ifeq ($(strip $(OPTR_CODE)),OP12)
    MELODY_BUFFER_LEN = 307200
  endif
endif

ifdef MELODY_BUFFER_LEN
     COM_DEFS += MAX_MELODY_BUF_LEN=$(strip $(MELODY_BUFFER_LEN))
endif

ifdef USB_HS_SUPPORT
  ifeq ($(strip $(USB_HS_SUPPORT)),TRUE)
     ifneq ($(strip $(USB_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,USB_HS_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
     else
       USB_HS_SUPPORT_PLATFORM = MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6268A MT6268 MT6268H MT6253T MT6253 MT6516 MT6270A 
       ifeq ($(filter $(strip $(PLATFORM)),$(USB_HS_SUPPORT_PLATFORM)),)
         $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support USB HS.)
         DEPENDENCY_CONFLICT = TRUE
       else
         COM_DEFS += __USB_HS_ENABLE__
       endif
     endif
   endif
endif

ifdef UNIFIED_MESSAGE_SORT_MESSAGE_LIST
    ifeq ($(strip $(UNIFIED_MESSAGE_SORT_MESSAGE_LIST)), TRUE)
        ifeq ($(strip $(UNIFIED_MESSAGE_FOLDER)), TRUE)
            ifneq ($(strip $(MMS_SUPPORT)), OBIGO_Q03C_MMS_V02)
                $(call DEP_ERR_ONA_OR_OFFB,MMS_SUPPORT,UNIFIED_MESSAGE_SORT_MESSAGE_LIST)
                DEPENDENCY_CONFLICT = TRUE
            endif
        endif
        ifeq ($(strip $(UNIFIED_MESSAGE_LOW_MEMORY_SUPPORT)), TRUE)
            $(call DEP_ERR_OFFA_OR_OFFB,UNIFIED_MESSAGE_LOW_MEMORY_SUPPORT,UNIFIED_MESSAGE_SORT_MESSAGE_LIST)
            DEPENDENCY_CONFLICT = TRUE
        endif

        COM_DEFS    += __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__

        ifeq ($(filter __UNIFIED_MESSAGE_LIST_INDEX_DATA__,$(COM_DEFS)),)
            COM_DEFS    += __UNIFIED_MESSAGE_LIST_INDEX_DATA__
        endif
    endif
endif

ifdef KURO_SUPPORT
  ifneq ($(strip $(KURO_SUPPORT)), NONE)
    ifdef GEMINI
      KURO_SUPPORT_GEMINI = FALSE 2
      ifeq ($(filter $(strip $(GEMINI)),$(KURO_SUPPORT_GEMINI)),)
        $(call DEP_ERR_SETA_OR_OFFB,GEMINI,FALSE/2,KURO_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifneq ($(strip $(DAF_DECODE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,DAF_DECODE,KURO_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(AAC_DECODE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,AAC_DECODE,KURO_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif    
    ifneq ($(strip $(XML_SUPPORT)), TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,XML_SUPPORT,KURO_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    endif
    KURO_SUPPORT_MEDIA_PLAYER_VER = INTEGRATED INTEGRATED_FTE_DB
    ifeq ($(filter $(strip $(MEDIA_PLAYER_VER)),$(KURO_SUPPORT_MEDIA_PLAYER_VER)),)
      $(call DEP_ERR_SETA_OR_OFFB,MEDIA_PLAYER_VER,INTEGRATED/INTEGRATED_FTE_DB,KURO_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(KURO_SUPPORT)), MTK_INTERNAL)
    ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
      $(warning ERROR: KURO_SUPPORT=MTK_INTERNAL can be ONLY enabled for internal use)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += KURO_INTERNAL
  endif
  KURO_SUPPORT_OPTION = OFFICIAL MTK_INTERNAL 
  ifneq ($(filter $(strip $(KURO_SUPPORT)) ,$(KURO_SUPPORT_OPTION)),)
     COM_DEFS               += KUR_DECODE AUD_VOCAL_REMOVAL AUD_PITCH_SHIFTING
     COMPLIST               += kuro
     ifeq ($(strip $(KURO_SUPPORT)),OFFICIAL)
       ifeq ($(strip $(COMPILER)),RVCT)
         COMPOBJS += vendor\player\ipeer\lib\libkuro_rvct.lib
         COMPOBJS += vendor\player\ipeer\lib\libkurodep_rvct.lib
         CUS_REL_OBJ_LIST += vendor\player\ipeer\lib\libkuro_rvct.lib
         CUS_REL_OBJ_LIST += vendor\player\ipeer\lib\libkurodep_rvct.lib
       else
         COMPOBJS           += vendor\player\ipeer\lib\libkuro.lib
         COMPOBJS           += vendor\player\ipeer\lib\libkurodep.lib
         CUS_REL_OBJ_LIST += vendor\player\ipeer\lib\libkuro.lib
         CUS_REL_OBJ_LIST += vendor\player\ipeer\lib\libkurodep.lib
       endif
     else
       ifeq ($(strip $(COMPILER)),RVCT)
         COMPOBJS += vendor\player\ipeer\lib\mtk_internal\libkuro_rvct.lib
         COMPOBJS += vendor\player\ipeer\lib\mtk_internal\libkurodep_rvct.lib
         CUS_REL_OBJ_LIST += vendor\player\ipeer\lib\mtk_internal\libkuro_rvct.lib
         CUS_REL_OBJ_LIST += vendor\player\ipeer\lib\mtk_internal\libkurodep_rvct.lib
       else
         COMPOBJS           += vendor\player\ipeer\lib\mtk_internal\libkuro.lib
         COMPOBJS           += vendor\player\ipeer\lib\mtk_internal\libkurodep.lib
         CUS_REL_OBJ_LIST += vendor\player\ipeer\lib\mtk_internal\libkuro.lib
         CUS_REL_OBJ_LIST += vendor\player\ipeer\lib\mtk_internal\libkurodep.lib
       endif
     endif
     CUS_REL_OBJ_LIST += vendor\player\ipeer\lib\MODIS\libkuro.lib
     CUS_REL_OBJ_LIST += vendor\player\ipeer\lib\MODIS\libkurodep.lib
  endif
endif

ifeq ($(strip $(STREAM_REC_SUPPORT)),TRUE)
  ifneq ($(strip $(STREAM_SUPPORT)),TRUE)
     $(call DEP_ERR_ONA_OR_OFFB,STREAM_SUPPORT,STREAM_REC_SUPPORT)
     DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS += __STREAM_REC_SUPPORT__
endif

ifdef E_COMPASS_SENSOR_SUPPORT 
  ifneq ($(strip $(E_COMPASS_SENSOR_SUPPORT)),NONE) 
    COM_DEFS    += $(strip $(E_COMPASS_SENSOR_SUPPORT)) 
    COM_DEFS    += __E_COMPASS_SENSOR_SUPPORT__
    COMMINCDIRS += custom\drv\e_compass_sensor\$(strip $(E_COMPASS_SENSOR_SUPPORT))
    COMMINCDIRS += vendor\e_compass_sensor\$(strip $(E_COMPASS_SENSOR_SUPPORT)) 
    COMPLIST += ecompass
  endif 
endif

ifdef MTP_SUPPORT
  ifeq ($(strip $(MTP_SUPPORT)),TRUE)
     ifneq ($(strip $(USB_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,MTP_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
     endif
     COMPLIST    += mtp
     COM_DEFS +=  __MTP_ENABLE__
     COM_DEFS +=  __USB_IMAGE_CLASS__
     COMP_TRACE_DEFS  += mtp\include\mtp_trc.h
     CUS_REL_SRC_COMP += mtp   
  endif
  CUS_REL_BASE_COMP += make\mtp mtp
  CUS_REL_FILES_LIST += mtp\include\mtp_trc.h
endif

ifdef SSL_SUPPORT
  ifneq ($(strip $(SSL_SUPPORT)),NONE)
    ifeq ($(strip $(WIFI_SUPPORT)),NONE)
      ifneq ($(strip $(SSL_SUPPORT)),OPENSSL)
        ifneq ($(strip $(SSL_SUPPORT)),OPENSSL_MTK)
          $(call DEP_ERR_SETA_OR_ONB,SSL_SUPPORT,OPENSSL or OPENSSL_MTK,WIFI_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif 
    ifeq ($(strip $(SSL_SUPPORT)),OPENSSL)
      ifneq ($(strip $(SECLIB_SUPPORT)), PKI)
        $(warning ERROR: Please set SSL_SUPPORT as NONE or set SECLIB_SUPPORT as PKI!)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifeq ($(strip $(SSL_SUPPORT)),OPENSSL_MTK)
      ifneq ($(strip $(SECLIB_SUPPORT)), PKI)
        $(warning ERROR: Please set SSL_SUPPORT as NONE or set SECLIB_SUPPORT as PKI!)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifeq ($(strip $(SSL_SUPPORT)),MTK_SSL_CIC)
      ifeq ($(strip $(SECLIB_SUPPORT)), NONE)
         $(warning ERROR: Please set SSL_SUPPORT as NONE or set SECLIB_SUPPORT as BASIC!)
         DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(strip $(SECLIB_SUPPORT)), PKI)
         $(warning WARNING Duplicate PKI library from Certicom SSL and OpenSSL!)
         $(warning ERROR: Please set SSL_SUPPORT as OPENSSL_SRC or set SECLIB_SUPPORT as BASIC.)
         DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifeq ($(strip $(SSL_SUPPORT)),SSL_CIC_LIB)
      ifeq ($(strip $(SECLIB_SUPPORT)), NONE)
         $(warning ERROR: Please set SSL_SUPPORT as NONE or set SECLIB_SUPPORT as BASIC!)
         DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(strip $(SECLIB_SUPPORT)), PKI)
         $(warning WARNING Duplicate PKI library from Certicom SSL and OpenSSL!)
         $(warning ERROR: Please set SSL_SUPPORT as OPENSSL_SRC or set SECLIB_SUPPORT as BASIC.)
         DEPENDENCY_CONFLICT = TRUE
      endif
    endif  
  endif
endif

ifdef SECLIB_SUPPORT
  ifneq ($(strip $(SECLIB_SUPPORT)), NONE)
    ifndef SSL_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,SSL_SUPPORT,SECLIB_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(SSL_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,SSL_SUPPORT,SECLIB_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif 
  ifeq ($(strip $(SECLIB_SUPPORT)), BASIC)
    COMPLIST            += seclib
    COM_DEFS            += __SECLIB_SUPPORT__    
  endif
  ifeq ($(strip $(SECLIB_SUPPORT)), PKI)
    COMPLIST            += seclib ossl_osadp ossl_crypto ossl_pki ossl_pkiadp
    COM_DEFS            += __SECLIB_SUPPORT__    
  endif
endif

ifeq ($(strip $(JOGBALL_SUPPORT)),TRUE)
    COM_DEFS    += JOGBALL_SUPPORT
endif

ifeq ($(strip $(POWERONOFF_BY_POWERKEY)),TRUE)
    COM_DEFS    += __POWERONOFF_BY_POWERKEY__
endif

ifndef MRE_PACKAGE
  ifdef MMI_VERSION
    ifneq ($(filter COSMOS_MMI PLUTO_MMI,$(MMI_VERSION)),)
      $(warning ERROR: Please define MRE_PACKAGE in project makefile if MMI_VERSION = COSMOS_MMI or PLUTO_MMI.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
else
  ifeq ($(filter COSMOS_MMI PLUTO_MMI,$(MMI_VERSION)),)
    $(warning ERROR: Please DO NOT define MRE_PACKAGE in project makefile if MMI_VERSION is NOT COSMOS_MMI or PLUTO_MMI.)
    DEPENDENCY_CONFLICT = TRUE
  else
    COM_DEFS += MRE_VERSION=1000

    COMP_TRACE_DEFS += plutommi\mmi\Inc\MMI_vre_app_info_trc.h

    COMPLIST    += mre_custom
    COMPLIST    += mre_engine

    ifeq ($(strip $(COMPILER)),RVCT)
      ifeq ($(strip $(PRODUCTION_RELEASE)),FALSE)
        COMPOBJS += mre\lib\mrecorervct.lib
      else
        COMPOBJS += mre\lib\mrecorervct_r.lib
      endif
    else
      ifeq ($(strip $(PRODUCTION_RELEASE)),FALSE)
        COMPOBJS += mre\lib\mrecore.lib
      else
        COMPOBJS += mre\lib\mrecore_r.lib
      endif
    endif

    CUS_REL_OBJ_LIST += mre\lib\mrecore.lib
    CUS_REL_OBJ_LIST += mre\lib\mrecore_r.lib
    CUS_REL_OBJ_LIST += mre\lib\mrecorervct.lib
    CUS_REL_OBJ_LIST += mre\lib\mrecorervct_r.lib
    CUS_REL_OBJ_LIST += mre\lib\mrewin32.lib
    CUS_REL_BASE_COMP += mre\vxp
    CUS_REL_BASE_COMP += mre\commoninc
    CUS_REL_BASE_COMP += mre\sdkinc
    CUS_REL_BASE_COMP += mre\sdkextinc
    COMMINCDIRS     += mre\commoninc
    COMMINCDIRS     += mre\sdkinc
    COMMINCDIRS     += mre\sdkextinc
  endif
endif

ifeq ($(strip $(MRE_PACKAGE)),FULL)
  COM_DEFS += __MRE_PACKAGE_FULL__
  COM_DEFS += __NBR_CELL_INFO__
  COM_DEFS += __MRE_MEDIA_BUF__
  COM_DEFS += MRE_SYS_MEMORY_SIZE=1500
  COM_DEFS += __MRE_AM__

  ifneq ($(strip $(XML_SUPPORT)),TRUE)
     $(call DEP_ERR_ONA_OR_OFFB,XML_SUPPORT,MRE_PACKAGE)
     DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(WBXML_SUPPORT)),TRUE)
     $(call DEP_ERR_ONA_OR_OFFB,WBXML_SUPPORT,MRE_PACKAGE)
     DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(MRE_PACKAGE)),NORMAL)
  COM_DEFS += __MRE_PACKAGE_NORMAL__
  COM_DEFS += __NBR_CELL_INFO__
  COM_DEFS += __MRE_MEDIA_BUF__
  COM_DEFS += MRE_SYS_MEMORY_SIZE=1000
endif

ifeq ($(strip $(MRE_PACKAGE)),SLIM)
  COM_DEFS += __MRE_PACKAGE_SLIM__
  COM_DEFS += __NBR_CELL_INFO__
  COM_DEFS += __MRE_MEDIA_BUF__
  COM_DEFS += MRE_SYS_MEMORY_SIZE=600
endif

ifdef IMAGE_VIEWER_VER
  ifneq ($(strip $(IMAGE_VIEWER_VER)),NONE)
    IMAGE_VIEWER_VER_EX_SUPPORT_MAIN_LCD_SIZE = 240X320 240X400 320X480 320X240 
    IMAGE_VIEWER_VER_EX_NOT_SUPPORT_PLATFORM = MT6223 MT6223C MT6219 MT6228 MT6229 MT6230 
    ifeq ($(strip $(IMAGE_VIEWER_VER)),SLIM)
      COM_DEFS += __IMAGE_VIEWER_SLIM__
    endif
    
    ifeq ($(strip $(IMAGE_VIEWER_VER)),STANDARD)
      COM_DEFS += __IMAGE_VIEWER_STANDARD__
    endif 
    
    ifeq ($(strip $(IMAGE_VIEWER_VER)),EX)
      ifeq ($(filter $(strip $(call Upper,$(MAIN_LCD_SIZE))),$(IMAGE_VIEWER_VER_EX_SUPPORT_MAIN_LCD_SIZE)),)
        $(warning ERROR: MAIN_LCD_SIZE = $(strip $(MAIN_LCD_SIZE)) does NOT support IMAGE_VIEWER_VER = $(strip $(IMAGE_VIEWER_VER)))
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifneq ($(filter $(strip $(call Upper,$(PLATFORM))),$(IMAGE_VIEWER_VER_EX_NOT_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does NOT support IMAGE_VIEWER_VER = $(strip $(IMAGE_VIEWER_VER)))
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifndef JPG_DECODE
        $(call DEP_ERR_SETA_OR_ONB,IMAGE_VIEWER_VER,non EX,JPG_DECODE)
        DEPENDENCY_CONFLICT = TRUE
      else
          ifeq ($(strip $(JPG_DECODE)),NONE)
              $(call DEP_ERR_SETA_OR_ONB,IMAGE_VIEWER_VER,non EX,JPG_DECODE)
              DEPENDENCY_CONFLICT = TRUE
          endif
      endif
      COM_DEFS += __IMAGE_VIEWER_EX__
      ifdef LOW_COST_SUPPORT
        ifneq ($(strip $(LOW_COST_SUPPORT)),NONE)
          COM_DEFS += __IMAGE_VIEWER_EX_MEM_SLIM__
        endif
      endif
    endif
    
    ifeq ($(strip $(IMAGE_VIEWER_VER)),EX_DB)
      ifneq ($(strip $(SQLITE3_SUPPORT)),TRUE)
        $(call DEP_ERR_SETA_OR_ONB,IMAGE_VIEWER_VER,non EX_DB,SQLITE3_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifneq ($(filter $(strip $(call Upper,$(PLATFORM))),$(IMAGE_VIEWER_VER_EX_NOT_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does NOT support IMAGE_VIEWER_VER = $(strip $(IMAGE_VIEWER_VER)))
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(filter $(strip $(call Upper,$(MAIN_LCD_SIZE))),$(IMAGE_VIEWER_VER_EX_SUPPORT_MAIN_LCD_SIZE)),)
        $(warning ERROR: MAIN_LCD_SIZE = $(strip $(MAIN_LCD_SIZE)) does NOT support IMAGE_VIEWER_VER = $(strip $(IMAGE_VIEWER_VER)))
        DEPENDENCY_CONFLICT = TRUE
      else
          ifeq ($(strip $(JPG_DECODE)),NONE)
              $(call DEP_ERR_SETA_OR_ONB,IMAGE_VIEWER_VER,non EX_DB,JPG_DECODE)
              DEPENDENCY_CONFLICT = TRUE
          endif
      endif
      ifndef JPG_DECODE
        $(call DEP_ERR_SETA_OR_ONB,IMAGE_VIEWER_VER,non EX_DB,JPG_DECODE)
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS += __IMAGE_VIEWER_EX_DB__
      ifdef LOW_COST_SUPPORT
        ifneq ($(strip $(LOW_COST_SUPPORT)),NONE)
          COM_DEFS += __IMAGE_VIEWER_EX_MEM_SLIM__
        endif
      endif
    endif 
   endif 
endif

ifdef APP_SECONDARY_PDP_SUPPORT
  ifeq ($(strip $(APP_SECONDARY_PDP_SUPPORT)),TRUE)
     COM_DEFS    += __APP_SECONDARY_PDP_SUPPORT__
  endif   
endif

ifeq ($(strip $(3SET_F8F9_ENABLE)),TRUE)
  # can ONLY be turned on for 3G projects
  ifneq ($(strip $(L1_WCDMA)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,L1_WCDMA,3SET_F8F9_ENABLE)
    DEPENDENCY_CONFLICT = TRUE
  endif

  # NOT support 3G PLATFORMs
  3SET_F8F9_ENABLE_NOT_SUPPORT_3G_PLATFORM = MT6268A
  ifneq ($(filter $(strip $(PLATFORM)),$(strip $(3SET_F8F9_ENABLE_NOT_SUPPORT_3G_PLATFORM))),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does NOT support 3SET_F8F9_ENABLE)
    DEPENDENCY_CONFLICT = TRUE
  endif

  COM_DEFS  += __CP_3SET_F8F9_HW_ENABLE__
endif

ifeq ($(strip $(BITSTREAM_SUPPORT)),TRUE)
   COM_DEFS    += __BITSTREAM_API_SUPPORT__
endif

ifdef CMMB_CAS_SMD_SUPPORT
    ifeq ($(strip $(CMMB_CAS_SMD_SUPPORT)),TRUE)
       ifeq ($(strip $(CMMB_SUPPORT)),NONE)
          $(call DEP_ERR_ONA_OR_OFFB,CMMB_SUPPORT,CMMB_CAS_SMD_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
       endif
       ifndef CMMB_SUPPORT
          $(call DEP_ERR_ONA_OR_OFFB,CMMB_SUPPORT,CMMB_CAS_SMD_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
       endif
       COM_DEFS    += __CMMB_CAS_SMD_SUPPORT__
       # CMMB Nagra KDA lib
       COMPOBJS    += vendor\cmmb\nagra\lib\kda.a
       CUS_REL_OBJ_LIST += vendor\cmmb\nagra\lib\kda.a
       CUS_REL_FILES_LIST += vendor\cmmb\nagra\lib\kda.a
    endif
endif

ifdef GPRS_DIALUP_PPP_SUPPORT_SPEED_UP_DIALUP
  ifeq ($(strip $(GPRS_DIALUP_PPP_SUPPORT_SPEED_UP_DIALUP)),TRUE)
    COM_DEFS += __PPP_SPEED_UP_IPV4_GPRS_DIALUP__
  endif
endif

ifeq ($(strip $(VENUS_MMI)),VENUS_LEVEL1)
    ifneq ($(strip $(MMI_VERSION)),PLUTO_MMI)
        $(call DEP_ERR_SETA_OR_OFFB,MMI_VERSION,PLUTO_MMI,VENUS_MMI)
        DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS         += __VENUS_UI_ENGINE__ __FANCY_PLUTO_APP_ON_VENUS_UI__
    COMPLIST         += venusmmi
    CUS_REL_SRC_COMP += venusmmi
endif

ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
    COMPLIST         += vrt vrt16
    CUS_REL_MTK_COMP += vrt vrt16
    CUS_REL_BASE_COMP += venusmmi\app \
                         venusmmi\framework \
                         venusmmi\pluto_adapter \
                         venusmmi\service \
                         venusmmi\test \
                         venusmmi\visual \
                         venusmmi\vrt\interface \
                         venusmmi\xml \
                         make\venusmmi
    COMP_TRACE_DEFS  += venusmmi\pluto_adapter\interface\trc\vadp_sys_trc.h
    COMP_TRACE_DEFS  += venusmmi\pluto_adapter\interface\trc\vadp_app_trc.h
    COMP_TRACE_DEFS  += venusmmi\vrt\interface\vrt_trc.h
endif

COMMINCDIRS   += venusmmi\framework\ui_core\base

ifdef MP4_DECODE_MODE
    ifneq ($(strip $(MP4_DECODE_MODE)),NONE)
        ifneq ($(strip $(MP4_DECODE)),TRUE)
            $(call DEP_ERR_ONA_OR_OFFB,MP4_DECODE,MP4_DECODE_MODE)
            DEPENDENCY_CONFLICT = TRUE
        endif
    endif
    ifeq ($(strip $(MP4_DECODE_MODE)),SLIM)
        MP4_DECODE_MODE_SLIM_SUPPORT_PLATFORM = MT6253T MT6253 MT6253E MT6253L MT6252 MT6252H
        ifeq ($(filter $(strip $(PLATFORM)),$(MP4_DECODE_MODE_SLIM_SUPPORT_PLATFORM)),)
            $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support MP4_DECODE_MODE=$(strip $(MP4_DECODE_MODE)))
            DEPENDENCY_CONFLICT = TRUE
        endif  
        COM_DEFS         += __MP4_DEC_SW_SLIM__
    endif
endif

ifdef MP4_DECODE
    ifeq ($(strip $(MP4_DECODE)),TRUE)
        SW_VIDEO_RESIZER_ADV_SUPPORT_PLATFORM = MT6235 MT6235B 
        ifneq ($(filter $(strip $(PLATFORM)),$(SW_VIDEO_RESIZER_ADV_SUPPORT_PLATFORM)),)
            COM_DEFS    += __SW_VIDEO_ADV_RESIZER_SUPPORT__
        endif
    endif
endif

ifeq ($(strip $(WAP_MEM_DEBUG)),TRUE)
    COM_DEFS    +=   WAP_MEM_DEBUG
endif

COM_DEFS += __HO_IMPROVE__

ifeq ($(strip $(AMRWB_LINK_SUPPORT)),TRUE)
    COM_DEFS  +=  __AMRWB_LINK_SUPPORT__
endif

ifdef FOTA_UPDATE_PACKAGE_ON_NAND
  ifeq ($(strip $(FOTA_UPDATE_PACKAGE_ON_NAND)),TRUE)
    ifeq ($(strip $(FOTA_ENABLE)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,FOTA_ENABLE,FOTA_UPDATE_PACKAGE_ON_NAND)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __UP_PKG_ON_NAND__
  endif
endif

ifdef QOS_PROFILE_SUPPORT
  ifneq ($(strip $(QOS_PROFILE_SUPPORT)),NONE)
    ifeq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
      $(warning ERROR: Please add __PS_SERVICE__ to CUSTOM_OPTION or turn off QOS_PROFILE_SUPPORT.)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(QOS_PROFILE_SUPPORT)), DYNAMIC)
      COM_DEFS    +=  __APP_DYNAMIC_QOS_PROFILE_SUPPORT__
    endif
    ifeq ($(strip $(QOS_PROFILE_SUPPORT)), STATIC)
      COM_DEFS    +=  __APP_STATIC_QOS_PROFILE_SUPPORT__
    endif
    ifeq ($(strip $(QOS_PROFILE_SUPPORT)), ALL)
      COM_DEFS    +=  __APP_DYNAMIC_QOS_PROFILE_SUPPORT__
      COM_DEFS    +=  __APP_STATIC_QOS_PROFILE_SUPPORT__
    endif
  endif
endif 

H264_SW_OPEN_API_PLATFORM = MT6236
H264_HW_OPEN_API_PLATFORM = MT6238
ifdef H264_OPEN_API
  ifeq ($(strip $(H264_OPEN_API)),TRUE)
    ifneq ($(strip $(H264_DECODE)),TRUE)
      $(call DEP_ERR_SETA_OR_OFFB,H264_DECODE,TRUE,H264_OPEN_API)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(filter $(strip $(PLATFORM)),$(H264_SW_OPEN_API_PLATFORM)),)
      COM_DEFS    += __H264_SW_OPEN_API_SUPPORT__
    else
      ifneq ($(filter $(strip $(PLATFORM)),$(H264_HW_OPEN_API_PLATFORM)),)
        COM_DEFS    += __H264_HW_OPEN_API_SUPPORT__
      else
        $(warning ERROR: H264_OPEN_API is not supported by PLATFORM=$(strip $(PLATFORM)))
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    CUS_REL_FILES_LIST += media\video\h264\include\h264_open_api_video_if.h
  endif
endif

ifdef ACCDET_SUPPORT
  ifeq ($(strip $(ACCDET_SUPPORT)),TRUE)
    COM_DEFS    +=  __ACCDET_SUPPORT__
  endif
endif

ifdef DRV_DEBUG_MEMORY_TRACE_SUPPORT
  ifeq ($(strip $(DRV_DEBUG_MEMORY_TRACE_SUPPORT)),TRUE)
    COM_DEFS    +=  __DRV_DBG_MEMORY_TRACE_SUPPORT__
  endif
endif

ifdef QQMOVIE_SUPPORT
 ifeq ($(strip $(COMPILER)),ADS)
  ifeq ($(strip $(QQMOVIE_SUPPORT)),TRUE)
    ifneq ($(strip $(BITSTREAM_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BITSTREAM_SUPPORT,QQMOVIE_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(H264_DECODE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,H264_DECODE,QQMOVIE_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifndef OBIGO_FEATURE
      $(call DEP_ERR_ONA_OR_OFFB,OBIGO_FEATURE,QQMOVIE_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(OBIGO_FEATURE)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,OBIGO_FEATURE,QQMOVIE_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(FINGER_TOUCH_SUPPORT)),FTE)
      $(warning ERROR: QQMOVIE_SUPPORT do not support FTE)
      DEPENDENCY_CONFLICT = TRUE
    endif
        
    COM_DEFS += __QQMOVIE_SUPPORT__ 
    COM_DEFS += __QQM_BUILD_ARM__
    COM_DEFS += QBROWSER_FOR_QQMOVIE

    COMPLIST += qqmovie
    CUS_REL_SRC_COMP += qqmovie
    COMPOBJS += vendor\streaming\qqmovie\lib\qqmovie_lib_ui.a
    COMPOBJS += vendor\streaming\qqmovie\lib\qqmovie_lib_browser.a
    CUS_REL_OBJ_LIST += vendor\streaming\qqmovie\lib\qqmovie_lib_ui.a
    CUS_REL_OBJ_LIST += vendor\streaming\qqmovie\lib\qqmovie_lib_browser.a
  endif
 endif
 ifeq ($(strip $(COMPILER)),RVCT)
  ifeq ($(strip $(QQMOVIE_SUPPORT)),TRUE)
   $(warning ERROR: QQMOVIE does not support RVCT compiler!)
   DEPENDENCY_CONFLICT = TRUE
  endif
 endif  
endif

ifdef SMART_PHONE_CORE
    ifneq ($(strip $(SMART_PHONE_CORE)),NONE)
        COM_DEFS += __AT_EPBW_SUPPORT__
    endif
endif

ifndef PHB_NAME_LENGTH
  ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
     PHB_NAME_LENGTH = 30
  else
     PHB_NAME_LENGTH = 40
  endif   
endif

ifdef PHB_NAME_LENGTH
     ifeq ($(call gt,$(strip $(PHB_NAME_LENGTH)),80),T)
       $(warning ERROR: PHB_NAME_LENGTH value should not be larger than 80)
       DEPENDENCY_CONFLICT = TRUE
     endif
     ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
          COM_DEFS    += MAX_PHB_NAME_LENGTH=16
     else
          COM_DEFS    += MAX_PHB_NAME_LENGTH=$(strip $(PHB_NAME_LENGTH))
     endif
     COM_DEFS += MAX_PS_NAME_SIZE=$(call plus,$(PHB_NAME_LENGTH),2)
endif

COMMINCDIRS +=  fmr\inc

ifneq ($(call Upper,$(strip $(PROJECT))),BASIC)
ifneq ($(call Upper,$(strip $(PROJECT))),MEUT)
  COMPLIST         += fmr
  CUS_REL_SRC_COMP += fmr
  CUS_REL_BASE_COMP += fmr
endif
endif

ifdef SYNCML_DM_VERSION
  ifneq ($(strip $(SYNCML_DM_VERSION)),NONE)
    ifeq ($(strip $(SYNCML_DM_SUPPORT)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,SYNCML_DM_SUPPORT,SYNCML_DM_VERSION)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(SYNCML_DM_VERSION)),DM12)
      COM_DEFS += __SYNCML_DM12__
    endif
    ifeq ($(strip $(SYNCML_DM_VERSION)),DM12_SCTS)
      COM_DEFS += __SYNCML_DM12__
      COM_DEFS += __SCTS_TOOLS_TEST__
    endif 
  endif
endif

MCD_DEFS  = __R99__
### CUS_REL_FILES_LIST += ps\tools\pre_mcdparser.pl
### CUS_REL_FILES_LIST += ps\interfaces\asn\cc-ss\cc\mcd_cc_peer.asn
ifdef MCD_CODESET_SHIFT_SUPPORT
  ifneq ($(strip $(MCD_CODESET_SHIFT_SUPPORT)),NONE)
    MCD_DEFS += __MCD_CODESET_SHIFT__
    MCD_DEFS += $(foreach def, $(MCD_CODESET_SHIFT_SUPPORT), __MCD_CODESET_SHIFT_$(def)__)
    COM_DEFS += __MCD_CODESET_SHIFT__
    COM_DEFS += $(foreach def, $(MCD_CODESET_SHIFT_SUPPORT), __MCD_CODESET_SHIFT_$(def)__)
  endif
endif
MCD_DEFS += MAX_PS_NAME_SIZE=$(call plus,$(PHB_NAME_LENGTH),2)
ifneq ($(filter __L4_MAX_NAME_60__,$(COM_DEFS)),)
    MCD_DEFS += __L4_MAX_NAME_60__
endif

ifeq ($(strip $(MAIN_MEDIA_LAYER_BITS_PER_PIXEL)),24)
    COM_DEFS    +=  MAIN_MEDIA_LAYER_BITS_PER_PIXEL=24
endif

ifeq ($(strip $(PLMN_LIST_PREF_SUPPORT)),ON)
    COM_DEFS += __PLMN_LIST_PREF_SUPPORT__
endif

ifeq ($(strip $(WIFI_BT_SINGLE_ANTENNA_SUPPORT)),TRUE)
    BT_SINGLE_ANTENNA_SUPPORT_CHIP = BTMTK_MT6612 BTMTK_MT6616 BTMTK_MT6236 
    ifeq ($(filter $(strip $(BLUETOOTH_SUPPORT)),$(BT_SINGLE_ANTENNA_SUPPORT_CHIP)),)
      $(warning ERROR: BT $(strip $(BLUETOOTH_SUPPORT)) does not support WIFI_BT_SINGLE_ANTENNA_SUPPORT!)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(WIFI_SUPPORT)),MT5921)
      $(warning ERROR: WIFI $(strip $(WIFI_SUPPORT)) does not support WIFI_BT_SINGLE_ANTENNA_SUPPORT!)
      DEPENDENCY_CONFLICT = TRUE
    endif 
    COM_DEFS  +=  __WIFI_BT_SINGLE_ANTENNA_SUPPORT__
endif

ifneq ($(filter __MONITOR_PAGE_DURING_TRANSFER__,$(COM_DEFS)),)
  ifeq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
    $(warning ERROR: __MONITOR_PAGE_DURING_TRANSFER__ can only be defined when __PS_SERVICE__ is defined.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifneq ($(filter __SMART_PAGING__,$(COM_DEFS)),)
  ifeq ($(filter __MONITOR_PAGE_DURING_TRANSFER__,$(COM_DEFS)),)
    $(warning ERROR: __SMART_PAGING__ can only be defined when __MONITOR_PAGE_DURING_TRANSFER__ is defined.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(filter FMT_NOT_PRESENT,$(COM_DEFS)),)
  COMP_TRACE_DEFS  += fmt\include\fmt_trc.h
endif

ifdef UMTS_MODE_SUPPORT
  ifneq ($(strip $(UMTS_MODE_SUPPORT)),NONE)
    ifeq ($(filter __UMTS_RAT__,$(strip $(COM_DEFS))),)
      $(warning ERROR: UMTS_MODE_SUPPORT can only be turned on when __UMTS_RAT__ defined)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS   += __3G_AUTO_BAND_MECHANISM__
    ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
      COM_DEFS += __UMTS_FDD_MODE__
    endif
    ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
      COM_DEFS += __UMTS_TDD128_MODE__
    endif
  endif
endif

RESOURCE_MANAGER_SUPPORT_PLATFORM = MT6236 MT6236B  
ifeq ($(strip $(RESOURCE_MANAGER)),TRUE)
    ifeq ($(filter $(strip $(PLATFORM)),$(RESOURCE_MANAGER_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support RESOURCE_MANAGER)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __RESOURCE_MANAGER__
endif

ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
   COM_DEFS += __SMS_STORAGE_BY_MMI__ __PHB_STORAGE_BY_MMI__ __CLOG_STORAGE_BY_MMI__
   COM_DEFS += __TCM_EXT_CALL_HISTORY_SUPPORT__
   COM_DEFS += __PHB_NO_CALL_LOG__ __PHB_ACCESS_SIM_LN__
   COMPLIST += smslib
endif
ifeq ($(strip $(MMI_VERSION)),WISDOM_MMI)
   COM_DEFS += __SMS_STORAGE_BY_MMI__
   COMPLIST += smslib
endif

ifdef UNIFIED_PUSH_FEATURES
    ifneq ($(strip $(UNIFIED_PUSH_FEATURES)),NONE)
        ifndef OBIGO_FEATURE
            $(call DEP_ERR_ONA_OR_OFFB,OBIGO_FEATURE,UNIFIED_PUSH_FEATURES)
            DEPENDENCY_CONFLICT = TRUE
        endif
        ifeq ($(strip $(OBIGO_FEATURE)),NONE)
            $(call DEP_ERR_ONA_OR_OFFB,OBIGO_FEATURE,UNIFIED_PUSH_FEATURES)
            DEPENDENCY_CONFLICT = TRUE
        endif
        ifeq ($(strip $(UNIFIED_PUSH_FEATURES)),FULL)
            COM_DEFS    += __FULL_PUSH_FEATURE_SUPPORT__
        endif
        ifeq ($(strip $(UNIFIED_PUSH_FEATURES)),STANDARD)
            COM_DEFS    += __STANDARD_PUSH_FEATURE_SUPPORT__
        endif
        ifeq ($(strip $(UNIFIED_PUSH_FEATURES)),SLIM)
            COM_DEFS    += __SLIM_PUSH_FEATURE_SUPPORT__
        endif
        COMPLIST    += obigo03cpushadp obigo03cpushlib
        COMP_TRACE_DEFS += vendor\framework\obigo_Q03C\adaptation\integration\include\trc\wps_trc.h
    endif
endif

ifdef DM_MO_SUPPORT
  ifneq ($(strip $(DM_MO_SUPPORT)),NONE)
    ifeq ($(strip $(SYNCML_DM_SUPPORT)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,SYNCML_DM_SUPPORT,DM_MO_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifndef OPTR_SPEC
      $(call DEP_ERR_ONA_OR_OFFB,OPTR_SPEC,DM_MO_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(OPTR_SPEC)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,OPTR_SPEC,DM_MO_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif

    COM_DEFS   += __DM_MO_SUPPORT__
 
    ifeq ($(strip $(DM_MO_SUPPORT)),LAW)
      COM_DEFS   += __DM_LAWMO_SUPPORT__
    endif
    ifeq ($(strip $(DM_MO_SUPPORT)),SCO)
      ifndef J2ME_SUPPORT
          $(call DEP_ERR_ONA_OR_OFFB,J2ME_SUPPORT,DM_MO_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(strip $(J2ME_SUPPORT)),NONE)
          $(call DEP_ERR_ONA_OR_OFFB,J2ME_SUPPORT,DM_MO_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS   += __DM_SCOMO_SUPPORT__ _DM_OMADL_VIA_DLAGENT_
    endif
    ifeq ($(strip $(DM_MO_SUPPORT)),LAW_SCO)
      ifndef J2ME_SUPPORT
          $(call DEP_ERR_ONA_OR_OFFB,J2ME_SUPPORT,DM_MO_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(strip $(J2ME_SUPPORT)),NONE)
          $(call DEP_ERR_ONA_OR_OFFB,J2ME_SUPPORT,DM_MO_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
      endif    
      COM_DEFS   += __DM_LAWMO_SUPPORT__ __DM_SCOMO_SUPPORT__ _DM_OMADL_VIA_DLAGENT_
    endif
  endif
endif

ifdef HTTP_INTERFACE_SUPPORT
  ifeq ($(strip $(HTTP_INTERFACE_SUPPORT)),TRUE)
    ifndef OBIGO_FEATURE
      $(call DEP_ERR_ONA_OR_OFFB,OBIGO_FEATURE,HTTP_INTERFACE_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(OBIGO_FEATURE)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,OBIGO_FEATURE,HTTP_INTERFACE_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __HTTP_INTERFACE__
  endif
endif

ifeq ($(strip $(M4A_DECODE)),TRUE)
   ifneq ($(strip $(AAC_DECODE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,AAC_DECODE,M4A_DECODE)
      DEPENDENCY_CONFLICT = TRUE
   endif
   COM_DEFS    += M4A_DECODE
endif

ifeq ($(strip $(YUVCAM_ENCODE_DIRECT_WRITE_FILE)),TRUE)
   ifneq ($(strip $(SENSOR_TYPE)),YUV)
     $(call DEP_ERR_SETA_OR_OFFB,SENSOR_TYPE,YUV,YUVCAM_ENCODE_DIRECT_WRITE_FILE)
     DEPENDENCY_CONFLICT = TRUE
   endif
   ifeq ($(strip $(MMI_VERSION)),WISDOM_MMI)
     $(call DEP_ERR_SETA_OR_OFFB,MMI_VERSION,non WISDOM_MMI,YUVCAM_ENCODE_DIRECT_WRITE_FILE)  
     DEPENDENCY_CONFLICT = TRUE
   endif
   COM_DEFS += __YUVCAM_ENCODE_DIRECT_WRITE_FILE__      
endif

ifdef OPTR_SPEC
  ifneq ($(strip $(OPTR_SPEC)),NONE)
    ifdef OPTR_COMP
       COMPLIST    += $(strip $(OPTR_COMP))        # OPTR_COMP defined in operator.mak
       CUS_REL_SRC_COMP += $(strip $(OPTR_COMP))
    endif
  endif
endif

ifdef FINGER_TOUCH_SUPPORT
    ifneq ($(strip $(FINGER_TOUCH_SUPPORT)),NONE)
        FINGER_TOUCH_SUPPORT_SUPPORT_LCD_SIZE = 240X400 240X320 320X480 
        ifeq ($(filter $(call Upper,$(strip $(MAIN_LCD_SIZE))),$(FINGER_TOUCH_SUPPORT_SUPPORT_LCD_SIZE)),)
            $(warning ERROR: MAIN_LCD_SIZE $(strip $(MAIN_LCD_SIZE)) doesn t support FINGER_TOUCH_SUPPORT=$(strip $(FINGER_TOUCH_SUPPORT)))
            DEPENDENCY_CONFLICT = TRUE
        endif
        ifndef TOUCH_PANEL_SUPPORT
            $(call DEP_ERR_ONA_OR_OFFB,TOUCH_PANEL_SUPPORT,FINGER_TOUCH_SUPPORT)
            DEPENDENCY_CONFLICT = TRUE
        endif
        ifeq ($(strip $(TOUCH_PANEL_SUPPORT)),NONE)
            $(call DEP_ERR_ONA_OR_OFFB,TOUCH_PANEL_SUPPORT,FINGER_TOUCH_SUPPORT)
            DEPENDENCY_CONFLICT = TRUE
        endif
        ifneq ($(filter $(call Upper,$(strip $(MAIN_LCD_SIZE))),240X400 320X480),)
          ifeq ($(strip $(FONT_ENGINE)),NONE)
            $(warning ERROR: FTE only supports vector font on 240X400 and 320X480 MAIN_LCD_SIZE, please set FONT_ENGINE = FONT_ENGINE_FREETYPE or FONT_ENGINE_FREETYPE_DEMO.)
            DEPENDENCY_CONFLICT = TRUE
          endif
        endif                    
        COM_DEFS += __MMI_FTE_SUPPORT__
    endif
endif


# Check 53 PMU API version
PMU53_API_V1_PLATFORM = MT6253_EVB% MT6253T_EVB% TIANYU6253T% UNICORN53%
ifeq ($(strip $(PMIC)),MT6253PMU)
   COM_DEFS    += MT6253PMU
   ifneq ($(filter $(strip $(PMU53_API_V1_PLATFORM)),$(strip $(BOARD_VER))),)
      COM_DEFS    += __DRV_PMU53_SPEC_V1__
   else
      COM_DEFS    += __DRV_PMU53_SPEC_V2__
   endif
endif

ENABLE_M3GPMP4_FILE_FORMAT_SUPPORT_CONDITION = FALSE

ifdef MP4_DECODE
    ifeq ($(strip $(MP4_DECODE)),TRUE)
        ENABLE_M3GPMP4_FILE_FORMAT_SUPPORT_CONDITION = TRUE
    endif
endif
ifdef MP4_ENCODE
    ifeq ($(strip $(MP4_ENCODE)),TRUE)
        ENABLE_M3GPMP4_FILE_FORMAT_SUPPORT_CONDITION = TRUE
    endif
endif
ifdef H264_DECODE
    ifeq ($(strip $(H264_DECODE)),TRUE)
        ENABLE_M3GPMP4_FILE_FORMAT_SUPPORT_CONDITION = TRUE
    endif
endif
ifeq ($(strip $(M4A_DECODE)),TRUE)
        ENABLE_M3GPMP4_FILE_FORMAT_SUPPORT_CONDITION = TRUE
endif
ifeq ($(strip $(PURE_AUDIO_SUPPORT)),TRUE)
        ENABLE_M3GPMP4_FILE_FORMAT_SUPPORT_CONDITION = TRUE
endif

ifeq ($(strip $(ENABLE_M3GPMP4_FILE_FORMAT_SUPPORT_CONDITION)),TRUE)
    ifneq ($(strip $(M3GPMP4_FILE_FORMAT_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,M3GPMP4_FILE_FORMAT_SUPPORT,MP4_DECODE & MP4_ENCODE & H264_DECODE & M4A_DECODE & PURE_AUDIO_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    endif
endif

ifeq ($(strip $(M3GPMP4_FILE_FORMAT_SUPPORT)),TRUE)
    COM_DEFS    += __M3GPMP4_FILE_FORMAT_SUPPORT__
endif

ifdef UART_CHARGER_THE_SAME_INTERFACE
  ifeq ($(strip $(UART_CHARGER_THE_SAME_INTERFACE)),UART1)
    COM_DEFS    += __UART1_WITH_CHARGER__
  endif
  ifeq ($(strip $(UART_CHARGER_THE_SAME_INTERFACE)),UART2)
    COM_DEFS    += __UART2_WITH_CHARGER__
  endif
  ifeq ($(strip $(UART_CHARGER_THE_SAME_INTERFACE)),UART3)
    COM_DEFS    += __UART3_WITH_CHARGER__
  endif
endif

ifdef LOW_COST_SUPPORT
    ifneq ($(strip $(LOW_COST_SUPPORT)),NONE)
        COM_DEFS    +=  __SLIM_NWK_PROFILE__
    endif
endif

ifdef TWOMICNR_SUPPORT
  ifneq ($(strip $(TWOMICNR_SUPPORT)),NONE)
    COM_DEFS += __TWOMICNR_SUPPORT__
  endif
endif

ifneq ($(strip $(call Upper,$(PROJECT))),L1S)
  ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
    ifneq ($(strip $(call Upper,$(PROJECT))),MEUT)
      ifdef TCPIP_SUPPORT
        ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
          ifdef CSD_SUPPORT
            ifneq ($(strip $(CSD_SUPPORT)),NONE)
              COM_DEFS += __TCPIP_OVER_CSD__
            endif
          endif
        endif
      endif
    endif
  endif
endif

ifdef WAPI_SUPPORT
  ifeq ($(strip $(WAPI_SUPPORT)),TRUE)
      ifneq ($(strip $(WIFI_SUPPORT)),MT5921)
        $(call DEP_ERR_SETA_OR_OFFB,WIFI_SUPPORT,MT5921,WAPI_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      else
          COM_DEFS += __WAPI_SUPPORT__ 
          ifeq ($(strip $(MMI_HIDE_WAPI)),TRUE)
              COM_DEFS += __MMI_HIDE_WAPI__ 
          endif         
      endif
  endif
endif

ifeq ($(strip $(MMI_HIDE_WAPI)),TRUE)
  ifneq ($(strip $(WAPI_SUPPORT)),TRUE)
    $(call DEP_ERR_SETA_OR_OFFB,WAPI_SUPPORT,TRUE,MMI_HIDE_WAPI)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(OCSP_SUPPORT)),TRUE)
    ifeq ($(findstring OPENSSL,$(SSL_SUPPORT)),)
      $(call DEP_ERR_SETA_OR_OFFB,SSL_SUPPORT,OPENSSL/OPENSSL_MTK,OCSP_SUPPORT) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(HTTP_INTERFACE_SUPPORT)),TRUE)
    	$(call DEP_ERR_ONA_OR_OFFB,HTTP_INTERFACE_SUPPORT,OCSP_SUPPORT)
    	DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __OCSP_SUPPORT__
endif

ifdef SMS_OVER_PS_SUPPORT
  ifeq ($(strip $(SMS_OVER_PS_SUPPORT)),TRUE)
    ifeq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
      $(warning ERROR: __PS_SERVICE__ must be defined when SMS_OVER_PS_SUPPORT is turned on.)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __SMS_OVER_PS_SUPPORT__
  endif
endif

ifdef DSP_COMPRESS
   ifneq ($(strip $(DSP_COMPRESS)),NONE)
      DSP_COMPRESS_SUPPORT_PLATFORM = MT6225 MT6253 MT6253D MT6253E MT6253L MT6252 MT6252H 
      ifeq ($(strip $(DSP_COMPRESS)),ZIP)
         COM_DEFS += __DSP_COMPRESS__
      endif
      ifeq ($(strip $(DSP_COMPRESS)),7Z)
         COM_DEFS += __DSP_COMPRESS_7Z__
      endif
      ifeq ($(filter $(strip $(PLATFORM)) ,$(DSP_COMPRESS_SUPPORT_PLATFORM)),)
         $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support DSP_COMPRESS.)
         DEPENDENCY_CONFLICT = TRUE
      endif
   endif
endif

# Ext cable detection
ifdef EXTERNAL_CHARGER_DETECTION
  ifneq ($(strip $(EXTERNAL_CHARGER_DETECTION)),NONE)
    COM_DEFS    +=  __DRV_EXT_CHARGER_DETECTION__
    COM_DEFS    +=  __EXT_CHARGER_DETECTION_$(strip $(EXTERNAL_CHARGER_DETECTION))__
    COMMINCDIRS += custom\drv\Ext_Cable_Detection\$(strip $(EXTERNAL_CHARGER_DETECTION))
  endif
endif
    
ifdef EXTERNAL_ACCESSORY_DETECTION
  ifneq ($(strip $(EXTERNAL_ACCESSORY_DETECTION)),NONE)
    COM_DEFS    +=  __DRV_EXT_ACCESSORY_DETECTION__
    COM_DEFS    +=  __EXT_ACCESSORY_DETECTION_$(strip $(EXTERNAL_ACCESSORY_DETECTION))__
    COMMINCDIRS += custom\drv\Ext_Cable_Detection\$(strip $(EXTERNAL_ACCESSORY_DETECTION))
  endif
endif

ifdef SUPPORT_VIDEO_RECORD_ROTATE 
  ifeq ($(strip $(SUPPORT_VIDEO_RECORD_ROTATE)),TRUE)
    COM_DEFS    += __SUPPORT_VIDEO_RECORD_ROTATE__
  endif 
endif

ifdef COOK_DECODE
  ifeq ($(strip $(COOK_DECODE)),TRUE)  
    COM_DEFS += __COOK_DECODE__
    COOK_DECODE_DSP_PLATFORM = MT6253T MT6253 MT6253E MT6253L MT6252 MT6252H MT6236 MT6236B 
    ifeq ($(filter $(strip $(PLATFORM)) ,$(COOK_DECODE_DSP_PLATFORM)),)
       ifeq ($(strip $(COMPILER)),ADS)
          COMPOBJS         += dp_engine\cook_ARM_decode\cokdec_arm.a
          CUS_REL_OBJ_LIST += dp_engine\cook_ARM_decode\cokdec_arm.a
       endif
       ifeq ($(strip $(COMPILER)),RVCT)
          COMPOBJS         += dp_engine\cook_ARM_decode\cokdec_arm_rvct.a
          CUS_REL_OBJ_LIST += dp_engine\cook_ARM_decode\cokdec_arm_rvct.a
       endif  
    else
       COM_DEFS += __COOK_DECODE_DSP__
    endif     
  endif   
endif

ifdef I2S_INPUT_MODE_SUPPORT
   ifeq ($(strip $(I2S_INPUT_MODE_SUPPORT)),TRUE)
      COM_DEFS += __I2S_INPUT_MODE_SUPPORT__      
      I2S_INPUT_SUPPORT_PLATFORM = MT6225 MT6253T MT6253 MT6253E MT6253L MT6252H MT6252 MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6268T MT6268H MT6268A MT6268
      ifeq ($(filter $(strip $(PLATFORM)) ,$(I2S_INPUT_SUPPORT_PLATFORM)),)
         $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support I2S_INPUT_MODE_SUPPORT.)
         DEPENDENCY_CONFLICT = TRUE
      endif
      ifdef DAF_ENCODE
         ifeq ($(strip $(DAF_ENCODE)),TRUE)
            COM_DEFS    += __I2S_DAF_RECORD__
         endif
      endif
      ifdef WAV_CODEC
         ifeq ($(strip $(WAV_CODEC)),TRUE)
            COM_DEFS    += __I2S_WAV_RECORD__
         endif
      endif
      ifdef DEDI_AMR_REC
         ifeq ($(strip $(DEDI_AMR_REC)),TRUE)
            COM_DEFS    += __I2S_AMR_RECORD__
            ifeq ($(strip $(COMPILER)),ADS)
               COMPOBJS         += dp_engine\blisrc\bli.a
               CUS_REL_OBJ_LIST += dp_engine\blisrc\bli.a
            endif
            ifeq ($(strip $(COMPILER)),RVCT)
               COMPOBJS         += dp_engine\blisrc\bli_rvct.a
               CUS_REL_OBJ_LIST += dp_engine\blisrc\bli_rvct.a
            endif 
         endif
      endif
   endif 
endif

ifdef USB_MULTIPLE_COMPORT_ENABLE
  ifeq ($(strip $(USB_MULTIPLE_COMPORT_ENABLE)),TRUE)
    ifneq ($(strip $(USB_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,USB_MULTIPLE_COMPORT_ENABLE)
      DEPENDENCY_CONFLICT = TRUE
    else
      ifeq ($(strip $(USB_MULTI_CHARGE_CURRENT_SUPPORT)),TRUE)
        $(call DEP_ERR_OFFA_OR_OFFB,USB_MULTI_CHARGE_CURRENT_SUPPORT,USB_MULTIPLE_COMPORT_ENABLE)
        DEPENDENCY_CONFLICT = TRUE
      else
        COM_DEFS += __USB_SUPPORT_MULTIPLE_DMA_CHANNEL__
        COM_DEFS += __USB_MULTIPLE_COMPORT_SUPPORT__
        COM_DEFS += __USB_COMPOSITE_DEVICE_SUPPORT__
      endif
    endif
  endif
endif

ifeq ($(strip $(LG_VOICE_ENGINE)),TRUE)
  COMPOBJS         += l1audio\obj\AkouoClarity13v_3GSM_RVCT22_616.a
  CUS_REL_OBJ_LIST += l1audio\obj\AkouoClarity13v_3GSM_RVCT22_616.a
  COMPOBJS         += l1audio\obj\VS_RVCT_lib.a
  CUS_REL_OBJ_LIST += l1audio\obj\VS_RVCT_lib.a
  COM_DEFS += __LG_VOICE_ENGINE__
endif

ifdef DAF_ENCODE
   ifeq ($(strip $(DAF_ENCODE)),TRUE)
      ifneq ($(strip $(I2S_INPUT_MODE_SUPPORT)),TRUE)
         $(call DEP_ERR_ONA_OR_OFFB,I2S_INPUT_MODE_SUPPORT,DAF_ENCODE)
         DEPENDENCY_CONFLICT = TRUE
      endif
      ifneq ($(strip $(CUST_CODE)),TC01)
         $(warning ERROR: DAF_ENCODE  could be enabled in TC01 project onlyd)
         DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(strip $(COMPILER)),ADS)
         COMPOBJS         += l1audio\mp3enc\EmMp3EncLib.a
         CUS_REL_OBJ_LIST += l1audio\mp3enc\EmMp3EncLib.a
      endif
      ifeq ($(strip $(COMPILER)),RVCT)
         COMPOBJS         += l1audio\mp3enc\EmMp3EncLib_rvct.a
         CUS_REL_OBJ_LIST += l1audio\mp3enc\EmMp3EncLib_rvct.a
      endif  
      COM_DEFS += __DAF_ENCODE__
  endif
endif

ifdef PPP_TYPE_PDP_DIALUP_SUPPORT
  ifeq ($(strip $(PPP_TYPE_PDP_DIALUP_SUPPORT)),TRUE)
    COM_DEFS  +=  __PPP_TYPE_PDP_DIALUP_SUPPORT__
  endif
endif

# Customer specific factory mode detection
ifdef CUSTOMER_SPECIFIC_FACTORY_DETECTION
  ifneq ($(strip $(CUSTOMER_SPECIFIC_FACTORY_DETECTION)),NONE)
    COM_DEFS    +=  __CS_FAC_DET__
    COM_DEFS    +=  __$(strip $(CUSTOMER_SPECIFIC_FACTORY_DETECTION))__
  endif
endif

ifdef FM_RADIO_I2S_PATH
  ifeq ($(strip $(FM_RADIO_I2S_PATH)),TRUE)
    ifneq ($(strip $(I2S_INPUT_MODE_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,I2S_INPUT_MODE_SUPPORT,FM_RADIO_I2S_PATH)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifndef FM_RADIO_CHIP
      $(call DEP_ERR_ONA_OR_OFFB,FM_RADIO_CHIP,FM_RADIO_I2S_PATH)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(FM_RADIO_CHIP)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,FM_RADIO_CHIP,FM_RADIO_I2S_PATH)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __FMRADIO_I2S_SUPPORT__ 
  endif
endif

ifneq ($(filter __MTK_INTERNAL__,$(strip $(COM_DEFS))),)
  COM_DEFS    += __CATCHER_EVENT_INFO__
endif

ifeq ($(strip $(FM_INTERFACE_TYPE)),I2C)
    COM_DEFS  += FM_INTERFACE_I2C
endif
ifeq ($(strip $(FM_INTERFACE_TYPE)),HCI)
  ifneq ($(strip $(FM_RADIO_CHIP)),MT6616)
    $(call DEP_ERR_SETA_OR_OFFB,FM_RADIO_CHIP,MT6616,FM_INTERFACE_TYPE)
    DEPENDENCY_CONFLICT = TRUE
  else
    COM_DEFS  += FM_INTERFACE_HCI
  endif
endif

ifneq ($(strip $(YUVCAM_INTERPOLATION)),NONE)
  YUVCAM_INTERPOLATION_SUPPORT_PLATFORM = MT6235 MT6235B MT6253 MT6253E MT6253L MT6252 MT6252H
  ifeq ($(filter $(strip $(PLATFORM)) ,$(YUVCAM_INTERPOLATION_SUPPORT_PLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support YUVCAM_INTERPOLATION)
    DEPENDENCY_CONFLICT = TRUE
  endif  
  ifeq ($(strip $(YUVCAM_INTERPOLATION)),HW)
      COM_DEFS    += __YUVCAM_INTERPOLATION_HW__ 
  endif
  ifeq ($(strip $(YUVCAM_INTERPOLATION)),SW)
      COM_DEFS    += __YUVCAM_INTERPOLATION_SW__ 
  endif
endif

ifneq ($(call Upper,$(strip $(PROJECT))),L1S)
  ifneq ($(call Upper,$(strip $(PROJECT))),BASIC)
    ifneq ($(call Upper,$(strip $(PROJECT))),MEUT)
      ifeq ($(filter WM_MODEM ANDROID_MODEM,$(strip $(SMART_PHONE_CORE))),)
        COMPLIST += applib
      endif
    endif
  endif
endif

ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
    COMPLIST += mcsv
    CUS_REL_MTK_COMP += mcsv
endif

ifdef CAPTURE_SCENARIO
  ifeq ($(strip $(CAPTURE_SCENARIO)),ON_THE_FLY)
    COM_DEFS += CAM_OTF_CAPTURE
  endif
  ifeq ($(strip $(CAPTURE_SCENARIO)),OFFLINE)
    COM_DEFS += CAM_OFFLINE_CAPTURE
  endif
  ifeq ($(strip $(CAPTURE_SCENARIO)),STANDARD)
    COM_DEFS += CAM_STANDARD_CAPTURE
  endif
endif

ifeq ($(strip $(LGE_BT_SYSTEM_SUPPORT)),TRUE)
  ifneq ($(strip $(CUST_CODE)),TC01)
     $(call DEP_ERR_SETA_OR_OFFB,CUST_CODE,TC01,LGE_BT_SYSTEM_SUPPORT)
     DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS += LGE_BT_SYSTEM
endif

ifeq ($(strip $(TC01_OAEP_SUPPORT)),TRUE)
  ifneq ($(strip $(CUST_CODE)),TC01)
    $(call DEP_ERR_SETA_OR_OFFB,CUST_CODE,TC01,TC01_OAEP_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifdef BES_SURROUND_SUPPORT
    ifneq ($(strip $(BES_SURROUND_SUPPORT)),NONE)
      $(call DEP_ERR_OFFA_OR_OFFB,BES_SURROUND_SUPPORT,TC01_OAEP_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifdef BES_LOUDNESS_SUPPORT
    ifneq ($(strip $(BES_LOUDNESS_SUPPORT)),NONE)
      $(call DEP_ERR_OFFA_OR_OFFB,BES_LOUDNESS_SUPPORT,TC01_OAEP_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(BES_LIVE_SUPPORT)),TRUE)
      $(call DEP_ERR_OFFA_OR_OFFB,BES_LIVE_SUPPORT,TC01_OAEP_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(BES_EQ_SUPPORT)),TRUE)
      $(call DEP_ERR_OFFA_OR_OFFB,BES_EQ_SUPPORT,TC01_OAEP_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
  endif
  COMPOBJS         += l1audio\TC01\oaep.a
  CUS_REL_OBJ_LIST += l1audio\TC01\oaep.a
  COM_DEFS += __TC01_OAEP_SUPPORT__
endif

ifeq ($(strip $(CONNECTED_OOS)),TRUE)
    ifeq ($(filter __UMTS_RAT__,$(strip $(COM_DEFS))),)
      $(warning ERROR: CONNECTED_OOS can only be turned on when __UMTS_RAT__ defined)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __R6_OOS__
endif

ifeq ($(filter BASIC L1S MEUT,$(strip $(call Upper,$(PROJECT)))),)
  ifndef LOW_COST_SUPPORT
    COM_DEFS += __STORED_CELL_SELECTION_INFO__
  endif
  ifeq ($(strip $(LOW_COST_SUPPORT)), NONE)
    COM_DEFS += __STORED_CELL_SELECTION_INFO__
  endif
  ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
    COM_DEFS += __STORED_CELL_SELECTION_INFO__
  endif
endif

ifneq ($(filter UMTS HSPA,$(strip $(call Upper,$(PROJECT)))),)
  COMPLIST       += scsi
else 
    ifeq ($(filter BASIC L1S MEUT,$(strip $(call Upper,$(PROJECT)))),)
        ifndef LOW_COST_SUPPORT
            COMPLIST       += scsi
        endif
        ifeq ($(strip $(LOW_COST_SUPPORT)), NONE)
            COMPLIST       += scsi
        endif
        ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
            COMPLIST       += scsi
        endif
    endif
endif

ifdef TST_SET_LOG_BUF_SIZ
  ifneq ($(strip $(TST_SET_LOG_BUF_SIZ)),NONE)
    ifeq ($(strip $(TST_SUPPORT)),TRUE)
      COM_DEFS += FORCE_TST_RING_BUFFER_SCALE=$(strip $(TST_SET_LOG_BUF_SIZ))      
    else
      $(call DEP_ERR_ONA_OR_OFFB,TST_SUPPORT,TST_SET_LOG_BUF_SIZ)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifeq ($(strip $(CAMCORDER_SMILE_SHUTTER_MODE_SUPPORT)),TRUE)
  SMILESHUTTER_NOSUPPORT_PLATFORM = MT6253 MT6253T MT6253E MT6253L MT6253PMU MT6252 MT6252H
  ifneq ($(filter $(strip $(PLATFORM)) ,$(SMILESHUTTER_NOSUPPORT_PLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support Smile Shutter)
    DEPENDENCY_CONFLICT = TRUE
  else 
    ifneq ($(strip $(CAMCORDER_FACE_DETECTION_MODE_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,CAMCORDER_FACE_DETECTION_MODE_SUPPORT,CAMCORDER_SMILE_SHUTTER_MODE_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(CONTOUR_IMPROVEMENT_SUPPORT)),TRUE)
      $(call DEP_ERR_OFFA_OR_OFFB,CONTOUR_IMPROVEMENT_SUPPORT,CAMCORDER_SMILE_SHUTTER_MODE_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __SMILE_SHUTTER_SUPPORT__
  endif
endif

ifdef AT_COMMAND_SET
  ifeq ($(strip $(AT_COMMAND_SET)),SLIM)
    ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
      $(call DEP_ERR_SETA_OR_SETB,MMI_VERSION,not EMPTY_MMI,AT_COMMAND_SET,FULL)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifdef RSAT_SUPPORT
      ifneq ($(strip $(RSAT_SUPPORT)),NONE)
        $(call DEP_ERR_SETA_OR_SETB,RSAT_SUPPORT,NONE,AT_COMMAND_SET,FULL)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    COM_DEFS    += __SLIM_AT__
  endif

  ifeq ($(strip $(AT_COMMAND_SET)),ULC)
    ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
      $(call DEP_ERR_SETA_OR_SETB,MMI_VERSION,not EMPTY_MMI,AT_COMMAND_SET,FULL)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifdef RSAT_SUPPORT
      ifneq ($(strip $(RSAT_SUPPORT)),NONE)
        $(call DEP_ERR_SETA_OR_SETB,RSAT_SUPPORT,NONE,AT_COMMAND_SET,FULL)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    COM_DEFS    += __SLIM_AT__ __ULC_AT__
  endif
endif

ifdef CONTOUR_IMPROVEMENT_SUPPORT
  ifeq ($(strip $(CONTOUR_IMPROVEMENT_SUPPORT)),TRUE)
    CONTOUR_IMPROVEMENT_PLATFORM = MT6235 MT6235B MT6253
    ifeq ($(filter $(strip $(PLATFORM)),$(CONTOUR_IMPROVEMENT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support CONTOUR_IMPROVEMENT_SUPPORT) 
        DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(CAMCORDER_SMILE_SHUTTER_MODE_SUPPORT)),TRUE)
      $(call DEP_ERR_OFFA_OR_OFFB,CAMCORDER_SMILE_SHUTTER_MODE_SUPPORT,CONTOUR_IMPROVEMENT_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(CAMCORDER_FACE_DETECTION_MODE_SUPPORT)),TRUE)
      $(call DEP_ERR_OFFA_OR_OFFB,CAMCORDER_FACE_DETECTION_MODE_SUPPORT,CONTOUR_IMPROVEMENT_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(PLATFORM)),MT6253)
      ifeq ($(strip $(VIDEO_V2_ENABLE)),FALSE)
        $(call DEP_ERR_OFFA_OR_OFFB,VIDEO_V2_ENABLE,CONTOUR_IMPROVEMENT_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif 
    COM_DEFS    += __CONTOUR_IMPROVEMENT_SUPPORT__
  endif
endif

ifneq ($(strip $(USB_COMPORT_PC_DRIVER_SUPPORT)),MS)
    ifneq ($(strip $(USB_COMPORT_PC_DRIVER_SUPPORT)),TC01)
        $(warning ERROR: USB_COMPORT_PC_DRIVER_SUPPORT must be defined as MS or TC01! )
        DEPENDENCY_CONFLICT = TRUE
    endif
endif

ifeq ($(strip $(USB_COMPORT_PC_DRIVER_SUPPORT)),TC01)
    ifeq ($(filter __TC01__,$(COM_DEFS)),)
        $(warning ERROR: USB_COMPORT_PC_DRIVER_SUPPORT can not be TC01 when __TC01__ not defined! )
        DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __USB_COMPOSITE_REMOVE_IAD__
    COM_DEFS    += __USB_COMPORT_SUPPORT_TC01_DRIVER__
    COM_DEFS    += __USB_BOOT_NOT_CHECK_NVRAM_SETTING__
endif

ifeq ($(strip $(CUST_CODE)),TC01)
   COM_DEFS += __ACOUSTIC_LOOPBACK_SUPPORT__
endif

ifeq ($(strip $(KAL_RECORD_BOOTUP_LOG)),TRUE)
  COM_DEFS += __KAL_RECORD_BOOTUP_LOG__
endif

ifeq ($(strip $(KEYPAD_DEBUG_TRACE)),TRUE)
  ifdef SMART_PHONE_CORE
    ifneq ($(strip $(SMART_PHONE_CORE)),NONE)
      $(warning ERROR: Smart Phone does not support KEYPAD_DEBUG_TRACE!)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  COM_DEFS += __KEYPAD_DEBUG_TRACE__
endif

COMP_TRACE_DEFS += init\include\init_trc.h

ifeq ($(strip $(PHB_SYNC)),ON)
  ifneq ($(strip $(USIM_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,USIM_SUPPORT,PHB_SYNC)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    +=   __PHB_USIM_SYNC__
endif

ifdef KAL_ASSERT_SHRINKING
  ifeq ($(strip $(KAL_ASSERT_SHRINKING)),TRUE)
    COM_DEFS   += __KAL_ASSERT_SHRINKING__ 
  endif
endif

ifeq ($(strip $(NVRAM_AFE_DIGITAL_GAIN_SUPPORT)),TRUE) 
    COM_DEFS  += __NVRAM_AFE_DIGITAL_GAIN_SUPPORT__
endif

ifeq ($(strip $(DUAL_MIC_SUPPORT)),TRUE)
    DUAL_MIC_SUPPORT_SUPPORT_PLATFORM = MT6255 MT6276 
    ifeq ($(filter $(strip $(PLATFORM)),$(DUAL_MIC_SUPPORT_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support DUAL_MIC_SUPPORT) 
        DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS +=  __DUAL_MIC_SUPPORT__
endif

ifdef GADGET_SUPPORT
    ifneq ($(strip $(GADGET_SUPPORT)),NONE)
        ifndef VENUS_MMI
            $(call DEP_ERR_ONA_OR_OFFB,VENUS_MMI,GADGET_SUPPORT)
            DEPENDENCY_CONFLICT = TRUE
        endif
        ifeq ($(strip $(VENUS_MMI)),NONE)
            $(call DEP_ERR_ONA_OR_OFFB,VENUS_MMI,GADGET_SUPPORT)
            DEPENDENCY_CONFLICT = TRUE
        endif
        ifndef SSL_SUPPORT
            $(call DEP_ERR_ONA_OR_OFFB,SSL_SUPPORT,GADGET_SUPPORT)
            DEPENDENCY_CONFLICT = TRUE
        endif
        ifeq ($(strip $(SSL_SUPPORT)),NONE)
            $(call DEP_ERR_ONA_OR_OFFB,SSL_SUPPORT,GADGET_SUPPORT)
            DEPENDENCY_CONFLICT = TRUE
        endif
        ifeq ($(strip $(GADGET_SUPPORT)),SHARED_MEMORY)
            COM_DEFS += GADGET_USE_ASM
        endif
        ifneq ($(strip $(HTTP_INTERFACE_SUPPORT)),TRUE)
            $(call DEP_ERR_SETA_OR_ONB,GADGET_SUPPORT,NONE,HTTP_INTERFACE_SUPPORT)
            DEPENDENCY_CONFLICT = TRUE
        endif
        COM_DEFS += __GADGET_SUPPORT__
        COMPLIST += gadget_adp gadget_lib gadget_ports
        COMMINCDIRS   +=  interface\widget
        CUS_REL_BASE_COMP += vendor\widget\google\gadgets
    endif
endif

ifdef ATV_RECORD_SUPPORT 
  ifeq ($(strip $(ATV_RECORD_SUPPORT)),TRUE)
    ifneq ($(strip $(ATV_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,ATV_SUPPORT,ATV_RECORD_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __ATV_RECORD_SUPPORT__ 
  endif
endif

ifdef MMS_SUPPORT
    ifneq ($(strip $(MMS_SUPPORT)),NONE)
        ifeq ($(strip $(MMS_SUPPORT)),OBIGO_Q03C_MMS_V02)
            ifneq ($(filter __FS_CARD_SUPPORT__,$(COM_DEFS)),)
                ifeq ($(filter __SLIM_MMS__,$(COM_DEFS)),)
                    COM_DEFS += __MMS_MEMORY_CARD_STORAGE_SUPPORT__
                endif
            endif        
        endif
    endif
endif

ifeq ($(strip $(GAIN_TABLE_SUPPORT)),TRUE)
  COM_DEFS += __GAIN_TABLE_SUPPORT__
endif

ifneq ($(strip $(MELODY_VER)),NONE)
  COM_DEFS    += $(MELODY_VER)
endif

ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
  COM_DEFS += __NEW_TBF_ARCH__
endif

ifeq ($(strip $(MDP_LCD_FW_UPDATE)),TRUE)
  COM_DEFS    += __MDP_LCD_FW_UPDATE__
endif


COM_DEFS +=  __SW_MP4_LOSSY_SUPPORT__
COM_DEFS +=  __SW_H264_LOSSY_SUPPORT__

ifeq ($(strip $(USIM_SUPPORT)),FALSE)
  ifeq ($(call gt,$(strip $(PHB_SIM_ENTRY)),254),T)
    $(warning ERROR: PHB_SIM_ENTRY value ($(PHB_SIM_ENTRY)) of non USIM projects should not be larger than 254) 
    DEPENDENCY_CONFLICT = TRUE
  endif
else
  ifeq ($(call gt,$(strip $(PHB_SIM_ENTRY)),1000),T)
    $(warning ERROR: PHB_SIM_ENTRY value ($(PHB_SIM_ENTRY)) of USIM projects should not be larger than 1000) 
      DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(BATTERY_CHARGING_SUPPORT)),TRUE) 
    BATTERY_CHARGING_SUPPORT_PLATFORM = MT6236 MT6236B MT6276 MT6255 MT6256
    ifeq ($(filter $(strip $(PLATFORM)),$(BATTERY_CHARGING_SUPPORT_PLATFORM)),) 
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support BATTERY_CHARGING_SUPPORT) 
        DEPENDENCY_CONFLICT = TRUE 
    endif
    ifeq ($(strip $(PLATFORM)), MT6236)
        ifeq ($(strip $(BOARD_VER)), JADE36_DEMO_BB)
            $(warning ERROR: MT6236E1 does not support BATTERY_CHARGING_SUPPORT) 
            DEPENDENCY_CONFLICT = TRUE
        endif
    endif
    COM_DEFS +=  __USB_PHY_BC11_SUPPORT__ 
endif

ifdef CMMB_CAS_MBBMS_SUPPORT
    ifeq ($(strip $(CMMB_CAS_MBBMS_SUPPORT)),TRUE)
       ifeq ($(strip $(CMMB_SUPPORT)),NONE)
          $(call DEP_ERR_ONA_OR_OFFB,CMMB_SUPPORT,CMMB_CAS_MBBMS_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
       endif
       ifndef CMMB_SUPPORT
          $(call DEP_ERR_ONA_OR_OFFB,CMMB_SUPPORT,CMMB_CAS_MBBMS_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
       endif
       COM_DEFS    += __CMMB_CAS_MBBMS_SUPPORT__
    endif
endif

ifdef VUI_SHELL_SUPPORT
  ifeq ($(strip $(VUI_SHELL_SUPPORT)),TRUE)
    ifneq ($(strip $(FINGER_TOUCH_SUPPORT)),FTE)
      $(call DEP_ERR_ONA_OR_OFFB,FINGER_TOUCH_SUPPORT,VUI_SHELL_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif    
    ifneq ($(strip $(SQLITE3_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,SQLITE3_SUPPORT,VUI_SHELL_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(MEDIA_PLAYER_VER)),INTEGRATED_FTE_DB)
      $(call DEP_ERR_SETA_OR_OFFB,MEDIA_PLAYER_VER,INTEGRATED_FTE_DB,VUI_SHELL_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(findstring EX,$(strip $(IMAGE_VIEWER_VER))),)
      $(call DEP_ERR_SETA_OR_OFFB,IMAGE_VIEWER_VER,EX_DB or EX,VUI_SHELL_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(VENUS_MMI)),VENUS_LEVEL1)
      $(call DEP_ERR_ONA_OR_OFFB,VENUS_MMI,VUI_SHELL_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __VUI_SHELL_APP_SUPPORT__
  endif
endif

ifeq ($(strip $(CBM_CONNECTION_MANAGER_SUPPORT)),TRUE)
  ifneq ($(strip $(MMI_VERSION)),PLUTO_MMI)
    ifneq ($(strip $(MMI_VERSION)),WISDOM_MMI)
      $(call DEP_ERR_SETA_OR_OFFB,MMI_VERSION,PLUTO_MMI/WISDOM_MMI,CBM_CONNECTION_MANAGER_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifndef TCPIP_SUPPORT
    $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPORT,CBM_CONNECTION_MANAGER_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
    COM_DEFS    +=  __CBM_CONNECTION_MANAGER__     
    COM_DEFS    +=  __TCM_EXT_CALL_HISTORY_SUPPORT__
endif

ifdef ECC_RETRY_ENHANCEMENT
  ifeq ($(strip $(ECC_RETRY_ENHANCEMENT)),TRUE)
    ifeq ($(filter __UMTS_RAT__,$(strip $(COM_DEFS))),)
      $(warning ERROR: ECC_RETRY_ENHANCEMENT can only be turned on when __UMTS_RAT__ defined)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(filter __GSM_RAT__,$(strip $(COM_DEFS))),)
      $(warning ERROR: ECC_RETRY_ENHANCEMENT can only be turned on when __GSM_RAT__ defined)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __ECC_RETRY_ENHANCEMENT__
  endif
endif

RICH_AUDIO_PROFILE_NOT_SUPPORT_PLATFORM = MT6205B MT6208 MT6223 MT6251
ifeq ($(filter $(strip $(PLATFORM)),$(RICH_AUDIO_PROFILE_NOT_SUPPORT_PLATFORM)),)
   COM_DEFS    += __RICH_AUDIO_PROFILE__
endif

LANDSCAPE_UI_ON_PORTRAIT_LCM_SUPPORT_SIZE = 128X128 128X160 220X176 320X240 400X240 480X320 640X480 800X400
ifdef LANDSCAPE_UI_ON_PORTRAIT_LCM
  ifeq ($(strip $(LANDSCAPE_UI_ON_PORTRAIT_LCM)),TRUE)
    ifeq ($(filter $(call Upper,$(strip $(MAIN_LCD_SIZE))),$(LANDSCAPE_UI_ON_PORTRAIT_LCM_SUPPORT_SIZE)),)
       $(warning ERROR: $(MAIN_LCD_SIZE) does not support LANDSCAPE_UI_ON_PORTRAIT_LCM.) 
       DEPENDENCY_CONFLICT = TRUE
    endif       
    ifdef LANDSCAPE_UI_ON_PORTRAIT_LCM_CCW_ROTATION_ANGLE
      ifeq ($(strip $(LANDSCAPE_UI_ON_PORTRAIT_LCM_CCW_ROTATION_ANGLE)),90)
        COM_DEFS    += __LANDSCAPE_UI_ON_PORTRAIT_LCM_CCW_ROTATION_ANGLE_90__
      endif
      ifeq ($(strip $(LANDSCAPE_UI_ON_PORTRAIT_LCM_CCW_ROTATION_ANGLE)),270)
        COM_DEFS    += __LANDSCAPE_UI_ON_PORTRAIT_LCM_CCW_ROTATION_ANGLE_270__
      endif
    endif
    ifdef LANDSCAPE_UI_ON_PORTRAIT_LCM_SLIM_VERSION
      ifeq ($(strip $(LANDSCAPE_UI_ON_PORTRAIT_LCM_SLIM_VERSION)),TRUE)
        COM_DEFS    += __LANDSCAPE_UI_ON_PORTRAIT_LCM_SLIM_VERSION__
      endif
    endif
    ifeq ($(strip $(HORIZONTAL_CAMERA)),TRUE)
      $(warning ERROR: HORIZONTAL_CAMERA does not support LANDSCAPE_UI_ON_PORTRAIT_LCM.) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(GDI_BLT_WITH_DOUBLE_BUF_SUPPORT)),FALSE)
      $(warning ERROR: GDI_BLT_WITH_DOUBLE_BUF_SUPPORT should be turn on if defined __LANDSCAPE_UI_ON_PORTRAIT_LCM__.) 
      DEPENDENCY_CONFLICT = TRUE
    endif       
    COM_DEFS    += __LANDSCAPE_UI_ON_PORTRAIT_LCM__
    COM_DEFS    += __PORTRAIT_LCM_SIMULATE_LANDSCAPE_LCM__
  endif
endif

ifeq ($(strip $(LANDSCAPE_UI_ON_PORTRAIT_LCM_SLIM_VERSION)),TRUE)
   ifneq ($(strip $(LANDSCAPE_UI_ON_PORTRAIT_LCM)),TRUE) 
      $(call DEP_ERR_ONA_OR_OFFB,LANDSCAPE_UI_ON_PORTRAIT_LCM,LANDSCAPE_UI_ON_PORTRAIT_LCM_SLIM_VERSION) 
      DEPENDENCY_CONFLICT = TRUE
   endif
endif

ifneq ($(filter PLUTO_MMI NEPTUNE_MMI,$(strip $(call Upper,$(MMI_VERSION)))),)
  ifneq ($(strip $(MMI_FEATURES_SWITCH)),TRUE)
    ifneq ($(strip $(USIM_SUPPORT)),TRUE)
      $(warning ERROR: Please turn on USIM_SUPPORT in $(strip $(PLATFORM)) projects) 
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifeq ($(strip $(WIFI_PREFER_SUPPORT)),TRUE)
    ifndef WIFI_SUPPORT
        $(call DEP_ERR_ONA_OR_OFFB,WIFI_SUPPORT,WIFI_PREFER_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(WIFI_SUPPORT)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,WIFI_SUPPORT,WIFI_PREFER_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS            += __WIFI_PREFER__
endif

ifdef MMS_SUPPORT
  ifneq ($(strip $(MMS_SUPPORT)),NONE)
    ifeq ($(strip $(MMS_SUPPORT)),OBIGO_Q03C_MMS_V01)
      $(call DEP_ERR_SETA_OR_OFFB,MMS_SUPPORT,OBIGO_Q03C_MMS_V02,MMS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE    
    endif
  endif
endif

ifdef H264_DECODE_MODE
    ifeq ($(strip $(H264_DECODE)),TRUE)
        ifeq ($(strip $(H264_DECODE_MODE)),SLIM)
            H264_DECODE_MODE_SLIM_SUPPORT_PLATFORM = MT6253T MT6253 MT6253E MT6253L MT6252 MT6252H
            ifeq ($(filter $(strip $(PLATFORM)),$(H264_DECODE_MODE_SLIM_SUPPORT_PLATFORM)),)
                $(error PLATFORM $(strip $(PLATFORM)) does not support H264_DECODE_MODE=$(strip $(RM_DECODE_MODE)))
            endif  
            COM_DEFS         += __H264_DEC_SW_SLIM__
        endif
    endif
endif

ifdef RM_DECODE_MODE
    ifeq ($(strip $(RM_DECODE)),TRUE)
        ifeq ($(strip $(RM_DECODE_MODE)),SLIM)
            RM_DECODE_MODE_SLIM_SUPPORT_PLATFORM = MT6253T MT6253 MT6253E MT6253L MT6252 MT6252H
            ifeq ($(filter $(strip $(PLATFORM)),$(RM_DECODE_MODE_SLIM_SUPPORT_PLATFORM)),)
                $(error PLATFORM $(strip $(PLATFORM)) does not support RM_DECODE_MODE=$(strip $(RM_DECODE_MODE)))
            endif  
            COM_DEFS         += __RM_DEC_SW_SLIM__
        endif
    endif
endif

ifeq ($(strip $(NMC_SUPPORT)), TRUE)
    COM_DEFS         += __NMC_SUPPORT__
    COMP_TRACE_DEFS	 += vendor\nmc\adaption\inc\nmc_trc.h
    COMPOBJS         += vendor\nmc\corelib\target\nmccore.lib
    COMPLIST         += nmc
endif

ifeq ($(strip $(GDI_SCREEN_SHOT_BUFFER)),ON)
    COM_DEFS += __GDI_SCREEN_SHOT_BUFFER__
endif


ifneq ($(filter __TC01__,$(COM_DEFS)),)
  ifeq ($(strip $(GDI_SCREEN_SHOT_BUFFER)),OFF) 
    $(warning ERROR: Please turn on GDI_SCREEN_SHOT_BUFFER when __TC01__  defined! )
    DEPENDENCY_CONFLICT = TRUE
  endif   
endif

ifneq ($(filter __OP11_ATK__,$(OPTR_DEFS)),)
  ifeq ($(strip $(GDI_SCREEN_SHOT_BUFFER)),OFF) 
    $(warning ERROR: Please turn on GDI_SCREEN_SHOT_BUFFER when __OP11_ATK__  defined! )
    DEPENDENCY_CONFLICT = TRUE
  endif   
endif

ifndef NVRAM_NOT_PRESENT
  ifdef NVRAM_COMPRESS_SUPPORT
    ifeq ($(strip $(NVRAM_COMPRESS_SUPPORT)),TRUE)
      ifneq ($(strip $(MMI_VERSION)),PLUTO_MMI)
        $(call DEP_ERR_SETA_OR_OFFB,MMI_VERSION,PLUTO_MMI,NVRAM_COMPRESS_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS +=  __NVRAM_COMPRESS_SUPPORT__
    endif
  endif  
endif

ifeq ($(strip $(DA_MEMORY_CUT_SUPPORT)),TRUE)
    ifndef TCPIP_SUPPORT
        $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPORT,DA_MEMORY_CUT_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(TCPIP_SUPPORT)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPORT,DA_MEMORY_CUT_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    +=  __DA_MEMORY_CUT__
endif

ifneq ($(filter UNICORN53%,$(BOARD_VER)),)
  COM_DEFS    +=  __PHONE__
else
    ifneq ($(filter %_EVB,$(BOARD_VER)),)
      COM_DEFS    +=  __EVB__
    else  
      COM_DEFS    +=  __PHONE__
    endif
endif

ifdef APE_DECODE
   ifeq ($(strip $(APE_DECODE)),TRUE)
      APE_DECODE_SUPPORT_PLATFORM = MT6238 MT6239 MT6235 MT6235B MT6236 MT6236B MT6268T MT6268H MT6268A MT6268 MT6270A MT6255 MT6256 MT6276 
      ifeq ($(filter $(strip $(PLATFORM)),$(APE_DECODE_SUPPORT_PLATFORM)),)
         $(Warning Error: PLATFORM $(strip $(PLATFORM)) not support APE_DECODE.) 
         DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(strip $(COMPILER)),ADS)
         COMPOBJS         += dp_engine\ape_ARM_decode\ape_arm.a
         CUS_REL_OBJ_LIST += dp_engine\ape_ARM_decode\ape_arm.a
      endif
      ifeq ($(strip $(COMPILER)),RVCT)
         COMPOBJS         += dp_engine\ape_ARM_decode\ape_arm_rvct.a
         CUS_REL_OBJ_LIST += dp_engine\ape_ARM_decode\ape_arm_rvct.a
      endif  
      COM_DEFS += __APE_DECODE__
   endif   
endif

ifdef GDI_BLT_WITH_DOUBLE_BUF_SUPPORT
  ifeq ($(strip $(GDI_BLT_WITH_DOUBLE_BUF_SUPPORT)),TRUE)
    COM_DEFS += __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
  endif
endif 

ifeq ($(strip $(SML_SUPPORT)),TRUE)
  COM_DEFS += __SIM_ME_LOCK__
endif  

ifdef VCARD_SUPPORT
  ifneq ($(strip $(VCARD_SUPPORT)),NONE)
    ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
      $(call DEP_ERR_SETA_OR_OFFB,MMI_VERSION,non NEPTUNE_MMI,VCARD_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(VCARD_SUPPORT)),SINGLE)
    COM_DEFS    += __VCARD_SUPPORT__
    COMPLIST    += vcard
  endif
  ifeq ($(strip $(VCARD_SUPPORT)),MULTIPLE)
    COM_DEFS    += __VCARD_SUPPORT__ __MULTI_VCARD_SUPPORT__
    COMPLIST    += vcard udx
    COMMINCDIRS += vcard\include
  endif
endif 

ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
  ifndef VCARD_SUPPORT
    $(call DEP_ERR_SETA_OR_ONB,MMI_VERSION,non PLUTO_MMI,VCARD_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(VCARD_SUPPORT)),NONE)
    $(call DEP_ERR_SETA_OR_ONB,MMI_VERSION,non PLUTO_MMI,VCARD_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef IPERF_WMM_PS_TEST_SUPPORT
  ifeq ($(strip $(IPERF_WMM_PS_TEST_SUPPORT)),TRUE)
      ifndef IPERF_SUPPORT
          $(call DEP_ERR_ONA_OR_OFFB,IPERF_SUPPORT,IPERF_WMM_PS_TEST_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(strip $(IPERF_SUPPORT)),NONE)
          $(call DEP_ERR_ONA_OR_OFFB,IPERF_SUPPORT,IPERF_WMM_PS_TEST_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS    +=  __IPERF_WMM_PS_TEST__
  endif
endif

ifdef DUAL_MEMORY_CARD_SUPPORT
    ifneq ($(strip $(DUAL_MEMORY_CARD_SUPPORT)),NONE)
        ifeq ($(strip $(MSDC_CARD_SUPPORT_TYPE)),NONE)
            $(call DEP_ERR_ONA_OR_OFFB,MSDC_CARD_SUPPORT_TYPE,DUAL_MEMORY_CARD_SUPPORT)
            DEPENDENCY_CONFLICT = TRUE
        else
            COM_DEFS	+= __FS_CARD2_SUPPORT__
            ifeq ($(strip $(DUAL_MEMORY_CARD_SUPPORT)),SWITCH)
                COM_DEFS	+= __MSDC_DUAL_CARD_SWITCH__
            endif
            ifeq ($(strip $(DUAL_MEMORY_CARD_SUPPORT)),DUAL_MSDC)
                COM_DEFS	+= __MSDC_DUAL_CARD_DUAL__
            endif
        endif
    endif
endif

ifdef BT_AUTO_DETECT_SUPPORT
  ifeq ($(strip $(BT_AUTO_DETECT_SUPPORT)),TRUE)
    COM_DEFS    += __BT_AUTO_DETECT_SUPPORT__
  endif
endif

ifeq ($(strip $(ENHANCED_UMTS_RF_CUSTOMIZATION)),TRUE)
    COM_DEFS    += __ENHANCED_UMTS_RF_CUSTOMIZATION__
endif

ifdef ATV_SMS_SUPPORT
  ifeq ($(strip $(ATV_SMS_SUPPORT)),TRUE)
    ifneq ($(strip $(ATV_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,ATV_SUPPORT,ATV_SMS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __ATV_SMS_SUPPORT__ 
  endif
endif

ifeq ($(strip $(MMI_VERSION)),COSMOS_MMI)
  ifndef VCARD_SUPPORT
    $(call DEP_ERR_SETA_OR_ONB,MMI_VERSION,non COSMOS_MMI,VCARD_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(VCARD_SUPPORT)),MULTIPLE)
    $(call DEP_ERR_SETA_OR_ONB,MMI_VERSION,non COSMOS_MMI,VCARD_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

# MAUI_02828542 Rollback
#ifeq ($(filter __GEMINI_PREEMPT_PEER_SERVICE__ ,$(CUSTOM_OPTION)),)
#  ifeq ($(strip $(GEMINI)),TRUE)
#    ifneq ($(strip $(call Upper,$(PROJECT))),GSM)
#      ifneq ($(strip $(L1_WCDMA)),TRUE)
#        COM_DEFS  += __GEMINI_PREEMPT_PEER_SERVICE__
#      endif
#    endif
#  endif
#else
#  ifneq ($(strip $(GEMINI)),TRUE)
#    $(warning ERROR: Please remove __GEMINI_PREEMPT_PEER_SERVICE__ when It isn t GEMINI project!)
#  endif
#  ifeq ($(strip $(call Upper,$(PROJECT))),GSM)
#    $(warning ERROR: Please remove __GEMINI_PREEMPT_PEER_SERVICE__ when It s GSM project!)
#  endif
#  ifeq ($(strip $(L1_WCDMA)),TRUE)
#    $(warning ERROR: Please remove __GEMINI_PREEMPT_PEER_SERVICE__ when It s 3G project!)
#  endif
#endif

ifeq ($(strip $(FONE_MTV)),TRUE)
  COM_DEFS += FONE_MTK_PLATFORM
  COM_DEFS += __FONE_100TV__
  COMPLIST += foneplatform
  CUS_REL_SRC_COMP += foneplatform
  COMPOBJS += vendor\fone\Lib\fonecore.lib
  CUS_REL_OBJ_LIST += vendor\fone\Lib\fonecore.lib
endif

ifdef ZIMAGE_SUPPORT
  ifeq ($(strip $(ZIMAGE_SUPPORT)),TRUE)
    COM_DEFS   +=  __ZIMAGE_SUPPORT__
  endif
endif

ifdef AOC_SUPPORT
  ifeq ($(strip $(AOC_SUPPORT)),TRUE)
     COM_DEFS    += __AOC_SUPPORT__
  endif   
endif

ifeq ($(filter __TC02__,$(strip $(COM_DEFS))),)
  ifneq ($(filter __TC02_SECURITY_REQUIREMENT__,$(strip $(COM_DEFS))),)
    $(warning ERROR: __TC02_SECURITY_REQUIREMENT__ can only be turned on for MOTO project)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef BLUETOOTH_SUPPORT
  ifneq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
    ifeq ($(strip $(LOW_COST_SUPPORT)),COMMON)
      COM_DEFS    +=  __BT_SLIM_ROM__
      COM_DEFS    +=  __BT_SLIM_RAM__
    endif
  endif
endif


COM_DEFS    +=  __MP4_DEC_ASP_PARTIAL_SUPPORT__

ifdef MAUI_SDK_TEST
  ifeq ($(strip $(MAUI_SDK_TEST)),TRUE)
     COM_DEFS += __MAUI_SDK_TEST__
     COMPLIST         += sdk_test
     CUS_REL_SRC_COMP += sdk_test
  endif   
endif

ifeq ($(strip $(SUBLCD_SYNC_LCM_METHOD)),HW)
  COM_DEFS    += __SUBLCD_SYNC_LCM_HW_SUPPORT__  __SUBLCD_SYNC_LCM_SUPPORT__
else
  ifeq ($(strip $(SUBLCD_SYNC_LCM_METHOD)),SW)
    COM_DEFS    += __SUBLCD_SYNC_LCM_SW_SUPPORT__  __SUBLCD_SYNC_LCM_SUPPORT__
  endif
endif

ifeq ($(call Upper,$(strip $(MAIN_LCD_SIZE))),320X480)
    ifeq ($(strip $(TOUCH_PANEL_SUPPORT)),NONE)
        $(call DEP_ERR_SETA_OR_ONB,MAIN_LCD_SIZE,non 320X480,TOUCH_PANEL_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    endif
    ifndef TOUCH_PANEL_SUPPORT
        $(call DEP_ERR_SETA_OR_ONB,MAIN_LCD_SIZE,non 320X480,TOUCH_PANEL_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    endif
endif

ifneq ($(filter MT6236% MT6252%,$(PLATFORM)),)
  COM_DEFS     +=  __BOOT_FOR_USBAT__
endif

ifdef COMBO_MEMORY_SUPPORT
  ifeq ($(strip $(COMBO_MEMORY_SUPPORT)),TRUE)
      ifneq ($(filter MT6252,$(PLATFORM)),)
        COM_DEFS    += __COMBO_MEMORY_SUPPORT__
      else
        $(warning ERROR: COMBO_MEMORY_SUPPORT = TRUE just can be supported on MT6252.)
        DEPENDENCY_CONFLICT = TRUE
      endif
  endif
endif

ifdef CLASSAB_LOW_VOLTAGE_VOLUME_PROTECTION
   ifeq ($(strip $(CLASSAB_LOW_VOLTAGE_VOLUME_PROTECTION)),TRUE)
      CLASSAB_LOW_VOLTAGE_VOLUME_PROTECTION_SUPPORT_PLATFORM = MT6253
      ifeq ($(filter $(strip $(PLATFORM)),$(CLASSAB_LOW_VOLTAGE_VOLUME_PROTECTION_SUPPORT_PLATFORM)),)
         $(warning ERROR: PLATFORM $(strip $(PLATFORM)) not support CLASSAB_LOW_VOLTAGE_VOLUME_PROTECTION.) 
         DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS += __CLASSAB_VOLUME_PROTECTION__
   endif   
endif

ifndef PHB_FDN_ENTRY
     PHB_FDN_ENTRY = 32
endif

ifdef PHB_FDN_ENTRY
     COM_DEFS    += MAX_PHB_FDN_ENTRY=$(strip $(PHB_FDN_ENTRY))
endif

ifeq ($(strip $(INTERGRAFX_SUPPORT)),INTERGRAFX_ENGINE) 
    COM_DEFS  +=  $(strip $(INTERGRAFX_SUPPORT))
endif

# end of COM_DEFS

# EMI latency setting, MPLLDISABLED, MPLLXHALF, MPLLX1, MPLLX2, MPLLX3, MPLLX4
MPLL_SETTING_FOR_MT6205_EXT_13M_MCU_13M   = MPLLDISABLED
MPLL_SETTING_FOR_MT6205B_EXT_13M_MCU_13M  = MPLLDISABLED
MPLL_SETTING_FOR_MT6205B_EXT_26M_MCU_13M  = MPLLXHALF
MPLL_SETTING_FOR_MT6205B_EXT_26M_MCU_26M  = MPLLDISABLED
MPLL_SETTING_FOR_MT6208_EXT_13M_MCU_13M   = MPLLX1
MPLL_SETTING_FOR_MT6208_EXT_13M_MCU_26M   = MPLLX2
MPLL_SETTING_FOR_MT6208_EXT_13M_MCU_39M   = MPLLX3
MPLL_SETTING_FOR_MT6208_EXT_13M_MCU_52M   = MPLLX4
MPLL_SETTING_FOR_MT6218_EXT_13M_MCU_13M   = MPLLX1
MPLL_SETTING_FOR_MT6218_EXT_13M_MCU_26M   = MPLLX2
MPLL_SETTING_FOR_MT6218_EXT_13M_MCU_39M   = MPLLX3
MPLL_SETTING_FOR_MT6218_EXT_13M_MCU_52M   = MPLLX4
MPLL_SETTING_FOR_MT6218_EXT_26M_MCU_26M   = MPLLX1
MPLL_SETTING_FOR_MT6218_EXT_26M_MCU_52M   = MPLLX2
MPLL_SETTING_FOR_MT6218B_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6218B_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6218B_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6218B_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6218B_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6218B_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6219_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6219_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6219_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6219_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6219_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6219_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6217_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6217_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6217_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6217_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6217_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6217_EXT_26M_MCU_52M  = MPLLX2

MPLL_SETTING_FOR_MT6228_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6228_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6228_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6228_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6228_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6228_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6228_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_MT6229_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6229_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6229_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6229_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6229_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6229_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6229_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_MT6268T_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6268T_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6268T_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6268T_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6268T_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6268T_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6268T_EXT_26M_MCU_104M  = MPLLX4
MPLL_SETTING_FOR_MT6268T_EXT_26M_MCU_122_88M = MPLLX4

MPLL_SETTING_FOR_MT6268H_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6268H_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6268H_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6268H_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6268H_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6268H_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6268H_EXT_26M_MCU_104M  = MPLLX4
MPLL_SETTING_FOR_MT6268H_EXT_26M_MCU_122_88M = MPLLX4

MPLL_SETTING_FOR_MT6268A_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6268A_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6268A_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6268A_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6268A_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6268A_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6268A_EXT_26M_MCU_104M  = MPLLX4
MPLL_SETTING_FOR_MT6268A_EXT_26M_MCU_122_88M = MPLLX4
MPLL_SETTING_FOR_MT6268A_EXT_26M_MCU_245_76M = MPLLX4

MPLL_SETTING_FOR_MT6268_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6268_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6268_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6268_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6268_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6268_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6268_EXT_26M_MCU_104M  = MPLLX4
MPLL_SETTING_FOR_MT6268_EXT_26M_MCU_122_88M = MPLLX4
MPLL_SETTING_FOR_MT6268_EXT_26M_MCU_245_76M = MPLLX4

MPLL_SETTING_FOR_MT6270A_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6270A_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6270A_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6270A_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6270A_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6270A_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6270A_EXT_26M_MCU_104M  = MPLLX4
MPLL_SETTING_FOR_MT6270A_EXT_26M_MCU_122_88M = MPLLX4
MPLL_SETTING_FOR_MT6270A_EXT_26M_MCU_245_76M = MPLLX4

MPLL_SETTING_FOR_MT6238_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6238_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6238_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6238_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6238_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6238_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6238_EXT_26M_MCU_104M  = MPLLX4
MPLL_SETTING_FOR_MT6238_EXT_26M_MCU_208M  = MPLLX4

MPLL_SETTING_FOR_MT6239_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6239_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6239_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6239_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6239_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6239_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6239_EXT_26M_MCU_104M  = MPLLX4
MPLL_SETTING_FOR_MT6239_EXT_26M_MCU_208M  = MPLLX4

MPLL_SETTING_FOR_MT6235_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6235_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6235_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6235_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6235_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6235_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6235_EXT_26M_MCU_104M  = MPLLX4
MPLL_SETTING_FOR_MT6235_EXT_26M_MCU_208M  = MPLLX4

MPLL_SETTING_FOR_MT6235B_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6235B_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6235B_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6235B_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6235B_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6235B_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6235B_EXT_26M_MCU_104M  = MPLLX4
MPLL_SETTING_FOR_MT6235B_EXT_26M_MCU_208M  = MPLLX4

MPLL_SETTING_FOR_MT6236_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6236_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6236_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6236_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6236_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6236_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6236_EXT_26M_MCU_104M  = MPLLX4
MPLL_SETTING_FOR_MT6236_EXT_26M_MCU_208M  = MPLLX4

MPLL_SETTING_FOR_MT6236B_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6236B_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6236B_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6236B_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6236B_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6236B_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6236B_EXT_26M_MCU_104M  = MPLLX4
MPLL_SETTING_FOR_MT6236B_EXT_26M_MCU_208M  = MPLLX4

MPLL_SETTING_FOR_MT6230_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6230_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6230_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6230_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6230_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6230_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6230_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_MT6226_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6226_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6226_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6226_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6226_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6226_EXT_26M_MCU_52M  = MPLLX2

MPLL_SETTING_FOR_MT6226M_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6226M_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6226M_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6226M_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6226M_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6226M_EXT_26M_MCU_52M  = MPLLX2

MPLL_SETTING_FOR_MT6226D_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6226D_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6226D_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6226D_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6226D_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6226D_EXT_26M_MCU_52M  = MPLLX2

MPLL_SETTING_FOR_MT6227_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6227_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6227_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6227_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6227_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6227_EXT_26M_MCU_52M  = MPLLX2

MPLL_SETTING_FOR_MT6227D_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6227D_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6227D_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6227D_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6227D_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6227D_EXT_26M_MCU_52M  = MPLLX2

MPLL_SETTING_FOR_MT6225_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6225_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6225_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6225_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6225_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6225_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6225_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_MT6253T_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6253T_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6253T_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6253T_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6253T_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6253T_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6253T_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_MT6253_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6253_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6253_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6253_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6253_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6253_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6253_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_MT6253E_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6253E_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6253E_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6253E_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6253E_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6253E_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6253E_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_MT6253L_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6253L_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6253L_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6253L_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6253L_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6253L_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6253L_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_MT6252H_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6252H_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6252H_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6252H_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6252H_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6252H_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6252H_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_MT6252_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6252_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6252_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6252_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6252_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6252_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6252_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_MT6223_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6223_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6223_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6223_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6223_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6223_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6223_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_MT6223P_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6223P_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6223P_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6223P_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6223P_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6223P_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6223P_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_TK6516_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_TK6516_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_TK6516_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_TK6516_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_TK6516_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_TK6516_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_TK6516_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_MT6516_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6516_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6516_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6516_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6516_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6516_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6516_EXT_26M_MCU_104M  = MPLLX4


MPLL_SETTING_FOR =  MPLL_SETTING_FOR_$(strip $(PLATFORM))_$(strip $(EXT_CLOCK))_$(strip $(MCU_CLOCK))
ifdef $(MPLL_SETTING_FOR)
   MPLL_SETTING      =  $(MPLL_SETTING_FOR_$(strip $(PLATFORM))_$(strip $(EXT_CLOCK))_$(strip $(MCU_CLOCK)))
#   $(error [$(MPLL_SETTING)])
else
  ifeq ($(strip $(PLATFORM)),MT6208)
    $(warning ERROR: MCU Clock and External Clock setting cannot be supported.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif


COM_DEFS    += $(MCU_CLOCK) $(EXT_CLOCK) $(MPLL_SETTING)

ifeq ($(strip $(MCU_DCM)),DCM_ENABLE)
   COM_DEFS    += DCM_ENABLE
endif

ifdef HAND_WRITING
  ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
    ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
      ifeq ($(strip $(HAND_WRITING)),MMI_HANWANG)
        $(warning ERROR: For customer project, please set HAND_WRITING = MMI_HANWANG_DEMO, not set HAND_WRITING = MMI_HANWANG)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(strip $(HAND_WRITING)),MMI_PENPOWER)
        $(warning ERROR: For customer project, please set HAND_WRITING = MMI_PENPOWER_DEMO, not set HAND_WRITING = MMI_PENPOWER)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(strip $(HAND_WRITING)),MMI_DECUMA)
        $(warning ERROR: For customer project, please set HAND_WRITING = MMI_DECUMA_DEMO, not set HAND_WRITING = MMI_DECUMA)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifneq ($(strip $(HAND_WRITING)),NONE)
    ifndef TOUCH_PANEL_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,TOUCH_PANEL_SUPPORT,HAND_WRITING)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(TOUCH_PANEL_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,TOUCH_PANEL_SUPPORT,HAND_WRITING)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(HAND_WRITING)),MMI_HANWANG)
    COM_DEFS    += __MMI_HANWANG__
    COMPLIST    += hanwang
    ifeq ($(strip $(COMPILER)),RVCT)
      ifdef LOW_COST_SUPPORT
        ifneq ($(strip $(LOW_COST_SUPPORT)),NONE)
          COMPOBJS    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_chshw_slim.a
        else
          COMPOBJS    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_chshw.a
        endif
      else      
        COMPOBJS    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_chshw.a
      endif
      COMPOBJS    += vendor\handwriting\hanwang\v1_official\lib\RVCT_mtlhw.a   
      COMPOBJS    += vendor\handwriting\hanwang\v1_official\lib\RVCT_thaihw.a
      COMPOBJS    += vendor\handwriting\hanwang\v1_official\lib\RVCT_arabichw.a    
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\RVCT_chshw.a    
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\RVCT_mtlhw.a    
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\RVCT_thaihw.a   
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\RVCT_arabichw.a
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\RVCT_chshw.lib    
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\RVCT_mtlhw.lib    
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\RVCT_thaihw.lib   
      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\RVCT_arabichw.lib 
    else # ifeq ($(strip $(COMPILER)),RVCT)
      ifeq ($(strip $(DEMO_PROJECT)),TRUE)
        ifeq ($(strip $(MMI_FEATURES_SWITCH)),TRUE)
          COMPOBJS    += vendor\handwriting\hanwang\v1_official\lib\hw_sc.a	  
        else
          COMPOBJS    += vendor\handwriting\hanwang\v1_official\lib\hw.a  
        endif
      else
        COMPOBJS    += vendor\handwriting\hanwang\v1_official\lib\hw.a
      endif  

      COMPOBJS    += vendor\handwriting\hanwang\v1_official\lib\HWRE_MTL_OEM.a \
                     vendor\handwriting\hanwang\v1_official\lib\thaihw.a

      CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\hw.a \
                             vendor\handwriting\hanwang\v1_official\lib\hw.lib \
                             vendor\handwriting\hanwang\v1_official\lib\hw_sc.a \
                             vendor\handwriting\hanwang\v1_official\lib\hw_sc.lib \
                             vendor\handwriting\hanwang\v1_official\lib\HWRE_MTL_OEM.a \
                             vendor\handwriting\hanwang\v1_official\lib\HWRE_MTL_OEM.lib \
                             vendor\handwriting\hanwang\v1_official\lib\thaihw.a \
                             vendor\handwriting\hanwang\v1_official\lib\thaihw.lib \
                             vendor\handwriting\hanwang\v1_official\lib\hws.lib
    endif # ifeq ($(strip $(COMPILER)),RVCT)
    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\hw.dll
    CUSTOM_COMMINC  += vendor\handwriting\hanwang\v1_official\inc
  endif # ifeq ($(strip $(HAND_WRITING)),MMI_HANWANG)
  
  ifeq ($(strip $(HAND_WRITING)),MMI_HANWANG_DEMO)
    COM_DEFS    += __MMI_HANWANG__ __MMI_HANWANG_DEMO__
    COMPLIST    += hanwang
    ifeq ($(strip $(COMPILER)),RVCT)
	    ifeq ($(strip $(DEMO_PROJECT)),TRUE)
        ifeq ($(strip $(MMI_FEATURES_SWITCH)),TRUE)
          COMPOBJS    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_chshw_slim.a	  
        else
          COMPOBJS    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_chshw.a  
        endif
      else
          COMPOBJS    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_chshw.a
      endif   
	    COMPOBJS    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_mtlhw.a   
	    COMPOBJS    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_thaihw.a
	    COMPOBJS    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_arabichw.a    
	    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_chshw.a    
	    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_mtlhw.a    
	    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_thaihw.a   
	    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_arabichw.a
	    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_chshw.lib    
	    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_mtlhw.lib    
	    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_thaihw.lib   
	    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\RVCT_arabichw.lib 
	  else  
    COMPOBJS    += vendor\handwriting\hanwang\v1_demo\lib\hw.a
    COMPOBJS    += vendor\handwriting\hanwang\v1_demo\lib\HWRE_MTL_OEM.a
    COMPOBJS    += vendor\handwriting\hanwang\v1_demo\lib\thaihw.a
    COMPOBJS    += vendor\handwriting\hanwang\v1_demo\lib\arabichw.a
    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\hw.a
    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\hw.lib
    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\arabichw.a
    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\arabichw.lib
    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\HWRE_MTL_OEM.lib
    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\HWRE_MTL_OEM.a
    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\thaihw.a
    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\thaihw.lib
	    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\hws.lib
	  endif
    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\hw.dll
    CUSTOM_COMMINC  +=	vendor\handwriting\hanwang\v1_demo\inc
  endif
  ifeq ($(strip $(HAND_WRITING)),MMI_PENPOWER)
    COM_DEFS    += __MMI_PENPOWER__
    COMPLIST    += penpower
     
    ifeq ($(strip $(COMPILER)),RVCT)
      ifeq (ARM7, $(findstring ARM7, $(strip $(CFLAGS))))
        COMPOBJS    += vendor\handwriting\penpower\v1_official\lib\libMTK_pphwrV3_thumb_rvct_ARM7.a
        CUS_REL_OBJ_LIST  +=   vendor\handwriting\penpower\v1_official\lib\libMTK_pphwrV3_thumb_rvct_ARM7.a
      else
        ifeq (ARM9, $(findstring ARM9, $(strip $(CFLAGS))))
          COMPOBJS    += vendor\handwriting\penpower\v1_official\lib\libMTK_pphwrV3_thumb_rvct_ARM9.a
          CUS_REL_OBJ_LIST  +=   vendor\handwriting\penpower\v1_official\lib\libMTK_pphwrV3_thumb_rvct_ARM9.a
        endif
      endif
    else    
      COMPOBJS    += vendor\handwriting\penpower\v1_official\lib\Thumb_MediaTek_HWRE.a
      CUS_REL_OBJ_LIST  +=   vendor\handwriting\penpower\v1_official\lib\Thumb_MediaTek_HWRE.a
    endif   
    
    COMPOBJS    += vendor\handwriting\penpower\v1_official\lib\MTK_PPhase_thumb.a
    CUS_REL_OBJ_LIST    += vendor\handwriting\penpower\v1_official\lib\MTK_PPhase_thumb.a
    CUS_REL_OBJ_LIST    += vendor\handwriting\penpower\v1_official\lib\MediaTek_HWRE.lib
    CUS_REL_OBJ_LIST    += vendor\handwriting\penpower\v1_official\lib\MTK_PPhrase_WIN.lib
    CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_official\inc\hw_data_big5gb2312_vc6.h
    CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_official\inc\hw_edit_vc6.h
    CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_official\inc\hw_edit_big5tw_vc6.h
    CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_official\inc\hw_edit_gb2312_vc6.h
    CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_official\inc\hw_edit_russian_vc6.h
    CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_official\inc\hw_edit_thai_vc6.h
    CUSTOM_COMMINC  +=	vendor\handwriting\penpower\v1_official\inc
  endif
  ifeq ($(strip $(HAND_WRITING)),MMI_DECUMA)
    COM_DEFS    += __MMI_DECUMA__
    COMPLIST    += decuma
    CUS_REL_SRC_COMP += decuma
    ifeq ($(strip $(COMPILER)),RVCT)
	  	ifeq (ARM7EJ, $(findstring ARM7EJ, $(strip $(CFLAGS))))
		    COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\dclib_rvct_arm9.a
		    COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\mcrlib_rvct_arm9.a
		    COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\scrlib_rvct_arm9.a
		    COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\mcrlib_rvct_arm9.a
		    COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\udmlib_rvct_arm9.a
		    COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\wclib_rvct_arm9.a
		    COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\dltlib_rvct_arm9.a
		    COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\dltpredict_rvct_arm9.a
		    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\dclib_rvct_arm9.a
		    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\mcrlib_rvct_arm9.a
		    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\scrlib_rvct_arm9.a
		    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\udmlib_rvct_arm9.a
		    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\wclib_rvct_arm9.a
		    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\dltlib_rvct_arm9.a
		    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\dltpredict_rvct_arm9.a
			else 
				ifeq (ARM9EJ, $(findstring ARM9EJ, $(strip $(CFLAGS))))
					COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\dclib_rvct_arm9.a
			    COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\mcrlib_rvct_arm9.a
			    COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\scrlib_rvct_arm9.a
			    COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\mcrlib_rvct_arm9.a
			    COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\udmlib_rvct_arm9.a
			    COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\wclib_rvct_arm9.a
			    COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\dltlib_rvct_arm9.a
			    COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\dltpredict_rvct_arm9.a
			    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\dclib_rvct_arm9.a
			    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\mcrlib_rvct_arm9.a
			    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\scrlib_rvct_arm9.a
			    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\udmlib_rvct_arm9.a
			    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\wclib_rvct_arm9.a
			    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\dltlib_rvct_arm9.a
			    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\dltpredict_rvct_arm9.a
		    else
					ifeq (ARM11EJ, $(findstring ARM11EJ, $(strip $(CFLAGS))))
						COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\dclib_rvct_arm11.a
				    COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\mcrlib_rvct_arm11.a
				    COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\scrlib_rvct_arm11.a
				    COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\mcrlib_rvct_arm11.a
				    COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\udmlib_rvct_arm11.a
				    COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\wclib_rvct_arm11.a
				    COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\dltlib_rvct_arm11.a
				    COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\dltpredict_rvct_arm11.a
				    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\dclib_rvct_arm11.a
				    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\mcrlib_rvct_arm11.a
				    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\scrlib_rvct_arm11.a
				    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\udmlib_rvct_arm11.a
				    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\wclib_rvct_arm11.a
				    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\dltlib_rvct_arm11.a
				    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\dltpredict_rvct_arm11.a
			    endif
			  endif
		  endif
	  else
	    COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\scrlib.a
	    COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\dltlib.a
	    COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\dltpredict.a
	  	CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\scrlib.a
	    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\dltlib.a
	    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\dltpredict.a
	  endif
    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\scrlib_MODIS.lib
    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\dltlib_MODIS.lib
    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\dltpredict_MODIS.lib
    CUSTOM_COMMINC  +=	vendor\handwriting\Zi_decuma\v1_official\inc
	endif
  ifeq ($(strip $(HAND_WRITING)),MMI_DECUMA_DEMO)
    COM_DEFS += __NO_HANDWRITING__
    CUS_REL_BASE_COMP += vendor\handwriting\Zi_decuma\adaptation
  endif
  ifdef TOUCH_PANEL_SUPPORT
    ifneq ($(strip $(TOUCH_PANEL_SUPPORT)),NONE)
      ifeq ($(strip $(HAND_WRITING)),MMI_PENPOWER_DEMO)
        COM_DEFS    += __MMI_PENPOWER__ __MMI_PENPOWER_DEMO__
        COMPLIST         += penpower
        ifeq ($(strip $(COMPILER)),RVCT)
          ifeq (ARM7EJ, $(findstring ARM7EJ, $(strip $(CFLAGS))))
            COMPOBJS    += vendor\handwriting\penpower\v1_demo\lib\libMTK_pphwrV3_thumb_rvct_ARM7_evaluation.a
            CUS_REL_OBJ_LIST  +=   vendor\handwriting\penpower\v1_demo\lib\libMTK_pphwrV3_thumb_rvct_ARM7_evaluation.a
          else
            ifeq (ARM9EJ, $(findstring ARM9EJ, $(strip $(CFLAGS))))
              COMPOBJS    += vendor\handwriting\penpower\v1_demo\lib\libMTK_pphwrV3_thumb_rvct_ARM9_evaluation.a
              CUS_REL_OBJ_LIST  +=   vendor\handwriting\penpower\v1_demo\lib\libMTK_pphwrV3_thumb_rvct_ARM9_evaluation.a
            else
              ifeq (ARM11EJ, $(findstring ARM11EJ, $(strip $(CFLAGS))))
                COMPOBJS    += vendor\handwriting\penpower\v1_demo\lib\libMTK_pphwrV3_thumb_rvct_ARM11_evaluation.a
                CUS_REL_OBJ_LIST  +=   vendor\handwriting\penpower\v1_demo\lib\libMTK_pphwrV3_thumb_rvct_ARM11_evaluation.a
              endif
            endif
          endif
        else
          COMPOBJS    += vendor\handwriting\penpower\v1_demo\lib\Thumb_MediaTek_HWRE_demo.a
          CUS_REL_OBJ_LIST  +=   vendor\handwriting\penpower\v1_demo\lib\Thumb_MediaTek_HWRE_demo.a
        endif
        CUS_REL_OBJ_LIST  +=   vendor\handwriting\penpower\v1_demo\lib\MediaTek_Hwre_demo.lib
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_data_big5gb2312_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_big5tw_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_gb2312_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_russian_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_thai_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_portugese_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_italian_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_hungarian_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_finnish_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_dutch_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_danish_norwegian_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_spanish_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_german_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_french_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_czech_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_croatian.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_romanian.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_slovak.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_slovene.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_swedish.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_bulgarian_vc6.h
        COMMINCDIRS  += vendor\handwriting\penpower\v1_demo\inc
      endif
    endif
  endif
endif

ifdef HAND_WRITING
  ifneq ($(strip $(HAND_WRITING)),NONE)
    ifeq ($(strip $(DEMO_PROJECT)),TRUE)
      ifeq ($(strip $(EMPTY_RESOURCE)),FALSE)
        CUS_REL_BASE_COMP += make\hanwang \
                             make\penpower \
                             make\decuma \
                             vendor\handwriting\hanwang \
                             vendor\handwriting\penpower \
                             vendor\handwriting\zi_decuma
      endif
    endif
  endif

# Release demo folder to customer always.
CUS_REL_BASE_COMP += vendor\handwriting\hanwang\v1_demo \
                     vendor\handwriting\penpower\v1_demo
endif

ifneq ($(filter __MMS_STANDALONE_COMPOSER_SUPPORT__,$(COM_DEFS)),)
    COMMINCDIRS  +=  plutommi\MMI\UnifiedComposer\UnifiedComposerInc 
endif

ifdef XDM_SUPPORT
  ifneq ($(strip $(XDM_SUPPORT)),FALSE)
    COMPLIST         += xdm
  endif
endif

ifdef SUPPORT_JSR_184
   ifneq ($(strip $(SUPPORT_JSR_184)),FALSE)
      COMPLIST    += m3d m3g
      CUS_REL_MTK_COMP += m3d m3g
   endif
endif

ifdef M3D_MMI_SUPPORT
ifneq ($(strip $(M3D_MMI_SUPPORT)),FALSE)
   ifeq ($(strip $(SUPPORT_JSR_184)),FALSE)
      COMPLIST    += m3d
      CUS_REL_MTK_COMP += m3d
   endif
endif
endif

ifdef DICT_SUPPORT
  ifeq ($(strip $(DICT_SUPPORT)),MMI_GV)
    COM_DEFS    += __MMI_DICT_GV__
    COMPLIST    += dict
    COMPOBJS  	+= vendor\dict\gv\v01_demo\gvlib_targer_rom.lib
    CUS_REL_OBJ_LIST   	+= vendor\dict\gv\v01_demo\gvlib_targer_rom.lib
  endif
  ifeq ($(strip $(DICT_SUPPORT)),MMI_MOTECH)
    COM_DEFS    += __MMI_DICT_MOTECH__
    COMPLIST    += dict
    ifeq ($(strip $(COMPILER)),RVCT)
      COMPOBJS  	+= vendor\dict\motech\v01_demo\tccDict_armv5tej_rvct.a
      CUS_REL_OBJ_LIST   	+= vendor\dict\motech\v01_demo\tccDict_arm1176jzs_rvct.a
    else
      COMPOBJS  	+= vendor\dict\motech\v01_demo\tccDict.a
      CUS_REL_OBJ_LIST   	+= vendor\dict\motech\v01_demo\tccDict.a
    endif
  endif
  ifeq ($(strip $(DICT_SUPPORT)),MMI_TRILOGY)
    COM_DEFS    += __MMI_DICT_TRILOGY__
    COMPLIST    += dict
    COMPOBJS  	+= vendor\dict\trilogy\v01_demo\Dict_core.obj
    COMPOBJS  	+= vendor\dict\trilogy\v01_demo\bg5_uni.obj
    CUS_REL_OBJ_LIST   	+= vendor\dict\trilogy\v01_demo\Dict_core.obj
    CUS_REL_OBJ_LIST   	+= vendor\dict\trilogy\v01_demo\bg5_uni.obj
  endif
  ifneq ($(strip $(DICT_SUPPORT)),NONE)
    ifeq ($(strip $(EMPTY_RESOURCE)),FALSE)
      CUS_REL_FILES_LIST += vendor\dict\gv\adaptation\inc\libdh.h \
                            vendor\dict\motech\adaptation\inc\de_api.h \
                            vendor\dict\trilogy\adaptation\inc\dict_core.h  
      CUS_REL_BASE_COMP += vendor\dict\gv\v01_demo \
                           vendor\dict\motech\v01_demo \
                           vendor\dict\trilogy\v01_demo
    endif
    ifeq ($(strip $(FINGER_TOUCH_SUPPORT)),FTE)
      $(warning ERROR: DICT_SUPPORT do not support FTE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef SW_FLASH
 ifeq ($(strip $(COMPILER)),ADS)
  ifeq ($(strip $(SW_FLASH)),NEOMTEL)
    COMPOBJS            += vendor\swflash\$(strip $(SW_FLASH))\v1_official\VIS20_ARM12_IRAM_12K_MTK.a
    COMPOBJS            += vendor\swflash\$(strip $(SW_FLASH))\v1_official\zddlib_mtk-ADS.a
    COMMINCDIRS         += vendor\swflash\$(strip $(SW_FLASH))\adaptation\inc
    COM_DEFS         += SWFLASH_$(strip $(SW_FLASH))
    COMPLIST         += swflash
  endif
# always release sw flash libraries to customers except vendors
  ifeq ($(strip $(call Upper,$(VENDOR))),NONE)
    ifeq ($(findstring REL_CR_OBJ_JAL_SRC,$(strip $(RELEASE_PACKAGE))),)
      CUS_REL_OBJ_LIST   	+= vendor\swflash\neomtel\v1_official\VIS20_ARM12_IRAM_12K_MTK.a
      CUS_REL_OBJ_LIST   	+= vendor\swflash\neomtel\v1_official\VIS20_ARM12_MTK.a
      CUS_REL_OBJ_LIST   	+= vendor\swflash\neomtel\v1_official\VIS20_WIN32_MTK.lib
      CUS_REL_OBJ_LIST   	+= vendor\swflash\neomtel\v1_official\zddlib_mtk-ADS.a
      CUS_REL_OBJ_LIST   	+= vendor\swflash\neomtel\v1_official\zdd2_1_lib.lib
      CUS_REL_BASE_COMP  += vendor\swflash\neomtel\adaptation make\swflash
    endif
  endif
 endif
endif

# for bootloader
COMPLIST += che sst_sec

CUS_REL_MTK_COMP += che sst_sec
# end

COMPLIST += image_codec image_codec16 image_codec_public16 

CUS_REL_MTK_COMP += image_codec image_codec16

CUS_REL_SRC_COMP += image_codec_public16

ifneq ($(strip $(DSP_SOLUTION)),DSP_FCORE4)
  COMPLIST += dsp_ram
  CUS_REL_MTK_COMP += dsp_ram
endif

COMPLIST    += drv_display drv_idp drv_graphics drv_sec media_sec32
CUS_REL_SRC_COMP  += drv_display drv_idp drv_graphics 
CUS_REL_MTK_COMP  += drv_sec media_sec32

ifneq ($(strip $(SSS_SUPPORT)),SSS_LIB)
    ifneq ($(strip $(SSS_SUPPORT)),SSS_SOURCE)
        $(warning ERROR: Please define SSS_SUPPORT as SSS_LIB or SSS_SOURCE)
        DEPENDENCY_CONFLICT = TRUE
    endif   
endif

ifdef SSS_SUPPORT
  ifeq ($(strip $(SSS_SUPPORT)),SSS_SOURCE)
     COMPLIST         += sss
     CUS_REL_SRC_COMP += sss
  endif   
endif

ifdef SSS_SUPPORT
  ifeq ($(strip $(SSS_SUPPORT)),SSS_LIB)
     ifeq ($(strip $(COMPILER)),RVCT)
         COMPOBJS         += sss\sss_rvct.lib
         CUS_REL_OBJ_LIST += sss\sss_rvct.lib
     else
         COMPOBJS         += sss\sss.lib
         CUS_REL_OBJ_LIST += sss\sss.lib
     endif
     CUS_REL_FILES_LIST += sss\interface\src\SSS_interface.c
  endif
endif

ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6616)
    COM_DEFS    +=  __WMT_SUPPORT__
    COMPLIST          += wmt
    CUS_REL_MTK_COMP  += wmt
    COMP_TRACE_DEFS   += wmt\inc\wmt_trc.h
else
    ifeq ($(strip $(WIFI_BT_SINGLE_ANTENNA_SUPPORT)),TRUE)
        COM_DEFS    +=  __WMT_SUPPORT__
        COMPLIST          += wmt
        CUS_REL_MTK_COMP  += wmt
        COMP_TRACE_DEFS   += wmt\inc\wmt_trc.h
    endif
endif

ifdef BLUETOOTH_SUPPORT
  ifeq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
    ifeq ($(strip $(MERCURY_SLAVE_BT_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,MERCURY_SLAVE_BT_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifneq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
    COMPLIST  += btadp btprofiles btstack
    CUS_REL_MTK_COMP += btstack
  endif
endif

ifdef WIFI_SUPPORT
  ifneq ($(strip $(WIFI_SUPPORT)),NONE)

    ifeq ($(strip $(WIFI_SUPPORT)),MT5911)
      ifeq ($(strip $(WNDRV_SUPPORT)),SOURCE)
        COMPLIST += wndrv
        CUS_REL_MTK_COMP += wndrv
      else
        ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
          COMPOBJS         += custom\drv\wifi\$(strip $(BOARD_VER))\$(strip $(FLAVOR))\wndrv.lib
          CUS_REL_OBJ_LIST += custom\drv\wifi\$(strip $(BOARD_VER))\$(strip $(FLAVOR))\wndrv.lib
        else
          COMPOBJS         += $(strip $(CUS_MTK_LIB))\wndrv.lib
          CUS_REL_OBJ_LIST += $(strip $(CUS_MTK_LIB))\wndrv.lib
        endif
      endif
    else
      # MT5921
      COMPLIST += wndrv
      CUS_REL_MTK_COMP += wndrv
    endif
    
    ifeq ($(strip $(WIFI_SUPPORT)),MT5921)
      ifeq ($(strip $(MWL_SUPPORT)),SOURCE)
        ifeq ($(strip $(WAPI_SUPPORT)),TRUE)
          COMPLIST += MT5921_wapi
          CUS_REL_MTK_COMP += MT5921_wapi
        else
          COMPLIST += MT5921
          CUS_REL_MTK_COMP += MT5921
        endif
      else
        ifeq ($(strip $(WAPI_SUPPORT)),TRUE)
          COMPOBJS          += wifi\lib\MT5921\MT5921_wapi.lib
          CUS_REL_OBJ_LIST  += wifi\lib\MT5921\MT5921_wapi.lib
        else
          COMPOBJS          += wifi\lib\MT5921\MT5921.lib
          CUS_REL_OBJ_LIST  += wifi\lib\MT5921\MT5921.lib
        endif
      endif
    endif

    ifeq ($(strip $(SUPC_SUPPORT)),SOURCE)
      ifeq ($(strip $(WAPI_SUPPORT)),TRUE)
        COMPLIST += supc_wapi
        CUS_REL_MTK_COMP += supc_wapi
      else
        COMPLIST += supc
        CUS_REL_MTK_COMP += supc
      endif
    else
      ifeq ($(strip $(WAPI_SUPPORT)),TRUE)
        COMPOBJS          += wifi\lib\supc\supc_wapi.lib
        CUS_REL_OBJ_LIST  += wifi\lib\supc\supc_wapi.lib
      else
        COMPOBJS          += wifi\lib\supc\supc.lib
        CUS_REL_OBJ_LIST  += wifi\lib\supc\supc.lib
      endif
    endif

    COMPLIST += dhcp

  endif   
endif

COMPLIST += camera_armcode
CUS_REL_MTK_COMP += camera_armcode

ifneq ($(call Upper,$(strip $(PROJECT))),BASIC)
ifneq ($(call Upper,$(strip $(PROJECT))),MEUT)
  CUS_REL_SRC_COMP += ftc
endif
endif

# GEMINI list
ifdef GEMINI
  ifneq ($(strip $(GEMINI)),FALSE)
    COMPLIST += rsva
    CUS_REL_MTK_COMP += rsva
    ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
      ifndef DUAL_MODE_SUPPORT
        $(call DEP_ERR_ONA_OR_OFFB,DUAL_MODE_SUPPORT,GEMINI)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifdef DUAL_MODE_SUPPORT
        ifneq ($(strip $(DUAL_MODE_SUPPORT)),GEMINI)
          $(call DEP_ERR_SETA_OR_OFFB,DUAL_MODE_SUPPORT,GEMINI,GEMINI)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
    ifndef SENDKEY_MODE
      $(call DEP_ERR_ONA_OR_OFFB,SENDKEY_MODE,GEMINI)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifndef MERCURY_SLAVE_BT_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,MERCURY_SLAVE_BT_SUPPORT,GEMINI)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifdef BT_SIM_PROFILE
      ifeq ($(strip $(BT_SIM_PROFILE)),TRUE)
        ifneq ($(strip $(PLATFORM)),MT6516)
          $(call DEP_ERR_OFFA_OR_OFFB,BT_SIM_PROFILE,GEMINI)
          DEPENDENCY_CONFLICT = TRUE
        endif 
      endif 
    endif
    ifdef UNIFIED_MESSAGE_FOLDER
      ifeq ($(strip $(UNIFIED_MESSAGE_FOLDER)),TRUE)
        ifneq ($(strip $(MMS_SUPPORT)), OBIGO_Q03C_MMS_V02)
          $(call DEP_ERR_ONA_OR_OFFB,MMS_SUPPORT,GEMINI & UNIFIED_MESSAGE)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
    ifdef PLATFORM
      ifneq ($(filter MT6223%,$(PLATFORM)),)
        ifneq ($(strip $(PLATFORM)),MT6223P)
          ifeq ($(strip $(PRODUCTION_RELEASE)),TRUE)
            $(call DEP_ERR_SETA_OR_OFFB,PLATFORM,MT6223P,GEMINI)
            DEPENDENCY_CONFLICT = TRUE
          endif
        endif
      endif
    endif
  
    COM_DEFS += __GEMINI__ __GEMINI_GSM__ __GSM_RAT__ DRV_MULTIPLE_SIM
    COM_DEFS += __L4C_ROOT__

    ifneq ($(strip $(GEMINI)),2)
      ifneq ($(strip $(SIM_PROVISIONING)),NONE)
        $(call DEP_ERR_SETA_OR_OFFB,GEMINI,FALSE or 2,SIM_PROVISIONING)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    
    # assign GEMINI to GEMINI_PLUS_GSM
    ifndef GEMINI_PLUS
      GEMINI_PLUS = $(strip $(GEMINI))
    endif
    ifndef GEMINI_PLUS_GSM
      GEMINI_PLUS_GSM = $(strip $(GEMINI))
    endif

    COM_DEFS    += GEMINI_PLUS=$(strip $(GEMINI))
    COM_DEFS    += GEMINI_PLUS_GSM=$(strip $(GEMINI_PLUS_GSM))


    ifndef SMART_PHONE_CORE
        COM_DEFS += __CTA_DUAL_SIM_STANDARD__
    endif
    ifeq ($(strip $(SMART_PHONE_CORE)),NONE)
        COM_DEFS += __CTA_DUAL_SIM_STANDARD__
    endif
    
    COMPLIST += as_semaphore_utility
    COMMINCDIRS += ps\common\as_semaphore_utility\include

    ifneq ($(filter MT6223P,$(strip $(PLATFORM))),)
      ifdef TOUCH_PANEL_SUPPORT
        ifneq ($(strip $(TOUCH_PANEL_SUPPORT)),NONE)
          COM_DEFS     += __DRV_SIM_TP_SHARE_PIN__
        endif
      endif
    endif
  endif
  ifeq ($(strip $(GEMINI)),FALSE)
    ifdef DUAL_MODE_SUPPORT
      ifneq ($(strip $(DUAL_MODE_SUPPORT)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,GEMINI,DUAL_MODE_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifdef MERCURY_SLAVE_BT_SUPPORT
      ifneq ($(strip $(MERCURY_SLAVE_BT_SUPPORT)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,GEMINI,MERCURY_SLAVE_BT_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifdef DUAL_MODE_SUPPORT
  ifeq ($(strip $(DUAL_MODE_SUPPORT)),GEMINI)
    ifndef GEMINI
      $(call DEP_ERR_SETA_OR_ONB,DUAL_MODE_SUPPORT,non GEMINI,GEMINI)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifdef GEMINI
      ifeq ($(strip $(GEMINI)),FALSE)
        $(call DEP_ERR_SETA_OR_ONB,DUAL_MODE_SUPPORT,non GEMINI,GEMINI)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifdef DUAL_MODE_SUPPORT
  ifneq ($(strip $(DUAL_MODE_SUPPORT)),NONE)
    ifneq ($(strip $(MMI_VERSION)),PLUTO_MMI)
      $(warning ERROR: Only PLUTO_MMI supports DUAL_MODE_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef SENDKEY_MODE
  ifeq ($(strip $(SENDKEY_MODE)),SENDKEY2_SUPPORT)
    COM_DEFS  += __SENDKEY2_SUPPORT__
  endif
endif

ifdef MERCURY_SLAVE_BT_SUPPORT
  ifdef BLUETOOTH_SUPPORT
    ifeq ($(strip $(MERCURY_SLAVE_BT_SUPPORT)),TRUE)
      ifneq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
        COM_DEFS  += __MERCURY_SLAVE_BT_MASTER_SIDE__
      endif
    endif
  endif
endif
# end of GEMINI


ifeq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R99_SUPPORT)
  R99_NOT_SUPPORT_PLATFORM = MT6205B MT6217 MT6218B MT6219 
  ifeq ($(findstring $(strip $(PLATFORM)),$(R99_NOT_SUPPORT_PLATFORM)),)
    COM_DEFS    +=   __R99__ 
  else
     $(warning ERROR: Chip version $(strip $(PLATFORM)) not support R99_SUPPORT.)
     DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R4_SUPPORT)
  R4_NOT_SUPPORT_PLATFORM = MT6205B MT6217 MT6218B MT6219 
  ifeq ($(findstring $(strip $(PLATFORM)),$(R4_NOT_SUPPORT_PLATFORM)),)
    COM_DEFS    +=   __R99__ __GERAN_R4__ __REL4__ __NEW_TBF_ARCH__ __REMOVE_FA__ __MAC_NEW_ARCH__
  else
     $(warning ERROR: Chip version $(strip $(PLATFORM)) not support R4_SUPPORT.)
     DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R5_SUPPORT)
  R5_NOT_SUPPORT_PLATFORM = MT6205B MT6217 MT6218B MT6219
  ifeq ($(findstring $(strip $(PLATFORM)),$(R5_NOT_SUPPORT_PLATFORM)),)
    COM_DEFS    +=   __R99__ __GERAN_R4__ __REL4__  __GERAN_R5__ __REL5__  __USIM_SUPPORT__
      ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
          COM_DEFS    +=   __ACL_SUPPORT__
      endif
  else
     $(warning ERROR: Chip version $(strip $(PLATFORM)) not support R5_SUPPORT.)
     DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R6_SUPPORT)
  R6_NOT_SUPPORT_PLATFORM = MT6205B MT6217 MT6218B MT6219 
  ifeq ($(findstring $(strip $(PLATFORM)),$(R6_NOT_SUPPORT_PLATFORM)),)
    COM_DEFS    +=   __R99__ __GERAN_R4__ __REL4__  __GERAN_R5__ __REL5__  __GERAN_R6__  __REL6__ __USIM_SUPPORT__ __NEW_TBF_ARCH__ __REMOVE_FA__ __MAC_NEW_ARCH__
      ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
          COM_DEFS    +=   __ACL_SUPPORT__
      endif
  else
     $(warning ERROR: Chip version $(strip $(PLATFORM)) does not support R6_SUPPORT.)
     DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R5_SUPPORT)
  COM_DEFS    +=  __UMTS_R5__ __REL4__ __REL5__
  ifeq ($(strip $(HSDPA_SUPPORT)),TRUE)
    COM_DEFS    +=   __HSDPA_SUPPORT__ __HSPA_PREFERENCE_SETTING__
    COM_DEFS    +=   FDD_HSDSCH_CATEGORY=$(strip $(FDD_HSDSCH_PHYSICAL_CATEGORY))
  endif
endif

ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R6_SUPPORT)
  COM_DEFS    +=   __UMTS_R5__ __REL4__ __REL5__ __UMTS_R6__  __REL6__ 
  ifeq ($(strip $(HSDPA_SUPPORT)),TRUE)
    COM_DEFS    +=   __HSDPA_SUPPORT__ __HSPA_PREFERENCE_SETTING__
    COM_DEFS    +=   FDD_HSDSCH_CATEGORY=$(strip $(FDD_HSDSCH_PHYSICAL_CATEGORY))
    ifeq ($(strip $(HSUPA_SUPPORT)),TRUE)
      COM_DEFS    +=   __HSUPA_SUPPORT__
      COM_DEFS    +=   FDD_EDCH_CATEGORY=$(strip $(FDD_EDCH_PHYSICAL_CATEGORY))
    endif
  endif
  ifeq ($(strip $(NOT_BENEFIT_FROM_BATTERY_CONSUMPTION_OPTIMISATION)),TRUE)
    COM_DEFS    +=   __NOT_BENEFIT_FROM_BATTERY_CONSUMPTION_OPTIMISATION__
  endif
endif

ifneq ($(filter __DYNAMIC_HSPA_PREFERENCE__,$(COM_DEFS)),)
  ifeq ($(filter __HSPA_PREFERENCE_SETTING__,$(strip $(COM_DEFS))),)
    $(error ERROR: PLEASE turn off __DYNAMIC_HSPA_PREFERENCE__ when __HSPA_PREFERENCE_SETTING__ is not defined.)
  endif
endif

ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R5_SUPPORT)
  COM_DEFS    +=   __UMTS_R5__ __REL4__ __REL5__
endif

ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R6_SUPPORT)
  COM_DEFS    +=   __UMTS_R5__ __REL4__ __REL5__ __UMTS_R6__  __REL6__ 
endif

ifeq ($(strip $(PS_HANDOVER)),TRUE)
  ifneq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R6_SUPPORT)
    $(call DEP_ERR_SETA_OR_OFFB,GERAN_RELEASE_SUPPORT,GERAN_R6_SUPPORT,PS_HANDOVER)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS += __PS_HO__  __EXT_SEG_CTRL_BLK__
endif

ifeq ($(filter __CPHS__,$(COM_DEFS)),)
  ifeq ($(filter __REL4__,$(COM_DEFS)),)
    ifneq ($(filter __SS_CPHS_QUERY_CFU_ALWAYS__,$(strip $(COM_DEFS))),)
      $(error ERROR: PLEASE turn on __CPHS__ or __REL4__ when __SS_CPHS_QUERY_CFU_ALWAYS__ is on)
    endif
  endif
endif

ifeq ($(strip $(MULTIPLE_TBF)),TRUE)
  ifneq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R6_SUPPORT)
    $(call DEP_ERR_SETA_OR_OFFB,GERAN_RELEASE_SUPPORT,GERAN_R6_SUPPORT,MULTIPLE_TBF)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS += __MTBF__
endif
ifeq ($(strip $(MMI_VERSION)),WISDOM_MMI)
ifeq ($(strip $(WISDOM_CUSTOM_BUILD)),TRUE)
  COMPLIST += wise
  COMMINCDIRS += external_mmi\wise\main external_mmi\wise\bal\sys\include
else
  COMPLIST += wise lgoem
  COMMINCDIRS += external_mmi\wise\main external_mmi\wise\bal\sys\include
  CUS_REL_SRC_COMP += lgoem
endif
endif

ifeq ($(strip $(TTL_SUPPORT)),SOURCE)
  COMPLIST         += ttl
  CUS_REL_MTK_COMP += ttl
else
#ttl.lib is a must-be-linked library.
  COMPOBJS         += ttl\lib\ttl.lib
  CUS_REL_OBJ_LIST += ttl\lib\ttl.lib
endif

#COM_DEFS    += $(CUSTOM_OPTION)
# end of COMPLIST


ifndef MMI_BASE
  MMI_BASE = PLUTO_MMI
  MMIDIR   = plutommi
else
  ifeq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
    MMIDIR         =  lcmmi
  else
    MMIDIR         =  plutommi
  endif
endif

MMI_BASE_PRJ = $(strip $(subst _MMI,,$(MMI_BASE)))

ifeq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
  ifeq ($(strip $(call Upper,$(MAIN_LCD_SIZE))),128X128)
    CUS_REL_BASE_COMP += $(strip $(MMIDIR))\Customer\Images\$(strip $(MMI_BASE_PRJ))$(strip $(DISPLAY_TYPE))$(strip $(MAIN_LCD_SIZE))_WITHOUT_ENHANCED
  endif
endif

ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
ifneq ($(strip $(call Upper,$(PROJECT))),MEUT)
ifneq ($(strip $(call Upper,$(PROJECT))),L1S)

INPUT_METHOD_BASE = $(strip $(MMIDIR))
ifeq ($(strip $(DEMO_PROJECT)),FALSE)
  ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
    INPUT_METHOD_BASE := $(strip $(call Upper,$(CUSTOMER)))
  endif
  ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
    INPUT_METHOD_BASE := $(strip $(call Upper,$(CUSTOMER)))
  endif
endif

ifneq ($(strip $(MMI_VERSION)),PLUTO_MMI)
  ifneq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
  ifneq ($(strip $(MMI_VERSION)),NEPTUNE_COLOR_MMI)
    INPUT_METHOD_BASE := $(strip $(call Upper,$(CUSTOMER)))
  endif
  endif
endif

# unitl W10.21
OP_CHECK_FORCE_ERROR = 0
#ifndef OP_CHECK_FORCE_ERROR
#OP_CHECK_FORCE_ERROR = 0
#  ifdef OPTR_SPEC
#    ifneq ($(strip $(OPTR_SPEC)),NONE)
#      OP_CHECK_FORCE_ERROR = 1
#    endif
#  endif
#endif

ifdef FONT_RESOURCE
  ifeq ($(strip $(FONT_RESOURCE)),OFFICIAL)
    ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
       $(warning ERROR: For customer project, please not set FONT_RESOURCE = OFFICIAL)
       DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(MMIDIR)),lcmmi)
      CUSTOM_COMMINC += vendor\font\MTK\official\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      FONTRES_PATH_CUST = vendor\font\MTK\official\project\$(strip $(INPUT_METHOD_BASE))\content\src\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      FONTRES_PATH_MTK = vendor\font\MTK\official\project\$(strip $(MMIDIR))\content\src\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
    else
      CUSTOM_COMMINC += vendor\font\MTK\official\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      FONTRES_PATH_CUST = vendor\font\MTK\official\project\$(strip $(INPUT_METHOD_BASE))\content\src\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      FONTRES_PATH_MTK = vendor\font\MTK\official\project\$(strip $(MMIDIR))\content\src\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
    endif
    CUS_REL_BASE_COMP += vendor\font\MTK\official\project\$(strip $(INPUT_METHOD_BASE))

    ifneq ($(strip $(INPUT_METHOD_BASE)),$(strip $(MMI_BASE_PRJ)))
      ifneq ($(strip $(MMIDIR)),lcmmi)
        CUSTOM_COMMINC += vendor\font\MTK\official\project\$(strip $(MMIDIR))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      else
        CUSTOM_COMMINC += vendor\font\MTK\official\project\$(strip $(MMIDIR))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      endif
      CUS_REL_BASE_COMP += vendor\font\MTK\official\project\$(strip $(MMIDIR))
    endif

    ifeq ($(strip $(EMPTY_RESOURCE)),FALSE)
      ifneq ($(strip $(MMIDIR)),lcmmi)
        CUSTOM_COMMINC += vendor\font\Arphic\official\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE))) \
        vendor\font\Dynacom\official\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      else
        CUSTOM_COMMINC += vendor\font\Arphic\official\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE))) \
        vendor\font\Dynacom\official\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      endif
      CUS_REL_BASE_COMP += vendor\font\Arphic\official\project\$(strip $(INPUT_METHOD_BASE)) vendor\font\Dynacom\official\project\$(strip $(INPUT_METHOD_BASE))
    endif
    COM_DEFS  += __FONT_RESOURCE_OFFICIAL__
  endif
endif

ifdef FONT_RESOURCE
  ifeq ($(strip $(FONT_RESOURCE)),DEMO)
    ifeq ($(strip $(MMIDIR)),lcmmi)
     $(warning ERROR: DEMO font is only applied in PLUTOMMI project, please set FONT_RESOURCE=OFFICIAL)
     DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(filter $(call Upper,$(strip $(MAIN_LCD_SIZE))),128X128 128X160 176X220 220X176 240X320 320X240 240X400 320X480),)
      $(warning ERROR: DEMO font only supports 128X128, 128X160, 176X220, 220X176,  240X320, 320X240, 240X400 and 320X480 MAIN_LCD_SIZE, for other MAIN_LCD_SIZE, please set FONT_RESOURCE=OFFICIAL)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(MMIDIR)),lcmmi)
      CUSTOM_COMMINC += vendor\font\MTK\demo\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      CUSTOM_COMMINC += vendor\font\Dynacom\demo\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      CUSTOM_COMMINC += vendor\font\Arphic\demo\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      FONTRES_PATH_CUST = vendor\font\MTK\demo\project\$(strip $(INPUT_METHOD_BASE))\content\src\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      FONTRES_PATH_MTK = vendor\font\MTK\demo\project\$(strip $(MMIDIR))\content\src\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
    else
      CUSTOM_COMMINC += vendor\font\MTK\demo\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      CUSTOM_COMMINC += vendor\font\Arphic\demo\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      CUSTOM_COMMINC += vendor\font\Dynacom\demo\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      FONTRES_PATH_CUST = vendor\font\MTK\demo\project\$(strip $(INPUT_METHOD_BASE))\content\src\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      FONTRES_PATH_MTK = vendor\font\MTK\demo\project\$(strip $(MMIDIR))\content\src\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
    endif    
    
    CUS_REL_BASE_COMP += vendor\font\MTK\demo\project\$(strip $(INPUT_METHOD_BASE))

    ifneq ($(strip $(INPUT_METHOD_BASE)),$(strip $(MMI_BASE_PRJ)))
      ifneq ($(strip $(MMIDIR)),lcmmi)
        CUSTOM_COMMINC += vendor\font\MTK\demo\project\$(strip $(MMIDIR))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
        CUSTOM_COMMINC += vendor\font\Dynacom\demo\project\$(strip $(MMIDIR))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
        CUSTOM_COMMINC += vendor\font\Arphic\demo\project\$(strip $(MMIDIR))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      else
        CUSTOM_COMMINC += vendor\font\MTK\demo\project\$(strip $(MMIDIR))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
        CUSTOM_COMMINC += vendor\font\Dynacom\demo\project\$(strip $(MMIDIR))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
        CUSTOM_COMMINC += vendor\font\Arphic\demo\project\$(strip $(MMIDIR))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      endif
      CUS_REL_BASE_COMP += vendor\font\MTK\demo\project\$(strip $(MMIDIR))
      CUS_REL_BASE_COMP += vendor\font\Dynacom\demo\project\$(strip $(MMIDIR))
      CUS_REL_BASE_COMP += vendor\font\Arphic\demo\project\$(strip $(MMIDIR))
    endif

    ifeq ($(strip $(EMPTY_RESOURCE)),FALSE)
      ifneq ($(strip $(MMIDIR)),lcmmi)
        CUSTOM_COMMINC += vendor\font\Arphic\demo\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE))) \
        vendor\font\Dynacom\demo\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      else
        CUSTOM_COMMINC += vendor\font\Arphic\demo\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE))) \
        vendor\font\Dynacom\demo\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      endif
      CUS_REL_BASE_COMP += vendor\font\Arphic\demo\project\$(strip $(INPUT_METHOD_BASE)) vendor\font\Dynacom\demo\project\$(strip $(INPUT_METHOD_BASE))
    endif
    COM_DEFS  += __FONT_RESOURCE_DEMO__
  endif
endif

ifdef FONT_RESOURCE
  ifeq ($(strip $(EMPTY_RESOURCE)),FALSE)
    CUS_REL_BASE_COMP += vendor\font\MTK\official\project\$(strip $(INPUT_METHOD_BASE)) \
                         vendor\font\MTK\official\project\$(strip $(MMIDIR)) \
                         vendor\font\Arphic\official\project\$(strip $(INPUT_METHOD_BASE)) \
                         vendor\font\Dynacom\official\project\$(strip $(INPUT_METHOD_BASE)) \
                         vendor\font\MTK\demo\project\$(strip $(INPUT_METHOD_BASE)) \
                         vendor\font\MTK\demo\project\$(strip $(MMIDIR)) \
                         vendor\font\Dynacom\demo\project\$(strip $(MMIDIR)) \
                         vendor\font\Arphic\demo\project\$(strip $(MMIDIR)) \
                         vendor\font\Arphic\demo\project\$(strip $(INPUT_METHOD_BASE)) \
                         vendor\font\Dynacom\demo\project\$(strip $(INPUT_METHOD_BASE))
  endif
endif

endif
endif
endif

ifdef INPUT_METHOD
  ifneq ($(strip $(INPUT_METHOD)),NONE)
    ifneq ($(strip $(INPUT_METHOD)),MMI_CSTAR_V2_DEMO)
      ifneq ($(strip $(INPUT_METHOD)),MMI_CSTAR_FREE_SLIM_0K)
        ifneq ($(strip $(INPUT_METHOD)),MMI_CSTAR_FREE_SLIM_5K)
          ifneq ($(strip $(INPUT_METHOD)),MMI_CSTAR_FREE_SLIM_10K)
            ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
              ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
                $(warning ERROR: Please set INPUT_METHOD to be MMI_CSTAR_V2_DEMO or NONE or use free libraries in customer projects)
                DEPENDENCY_CONFLICT = TRUE
              endif
            endif
          endif
        endif
      endif
    endif
  endif
  ifeq ($(strip $(INPUT_METHOD)),MMI_ZI_V6) 
    ifeq ($(strip $(COMPILER)),RVCT)
      CUSTOM_COMMINC  += vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v6_official_rvct\inc
      COMPOBJS   += vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v6_official_rvct\lib\zi8clib.a
      CUS_REL_OBJ_LIST   += vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v6_official_rvct\lib\zi8clib.a
      CUS_INPUTMETHOD_BASE = vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v6_official_rvct
    else 
      CUSTOM_COMMINC  +=  vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v6_official\inc
      COMPOBJS    += vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v6_official\lib\zi8clib.a
      CUS_REL_OBJ_LIST    += vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v6_official\lib\zi8clib.a
      CUS_INPUTMETHOD_BASE = vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v6_official  
    endif
  endif
   ifeq ($(strip $(INPUT_METHOD)),MMI_ZI) 
    ifeq ($(strip $(COMPILER)),RVCT)
      CUSTOM_COMMINC  += vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official_rvct\inc
      COMPOBJS   += vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official_rvct\lib\zi8clib.a
      CUS_REL_OBJ_LIST   += vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official_rvct\lib\zi8clib.a
      CUS_INPUTMETHOD_BASE   = vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official_rvct
    else
      CUSTOM_COMMINC  += vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official\inc
      COMPOBJS   += vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official\lib\zi8clib.a
      CUS_REL_OBJ_LIST   += vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official\lib\zi8clib.a
      CUS_INPUTMETHOD_BASE   = vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official
    endif
  endif
  ifeq ($(strip $(INPUT_METHOD)),MMI_ZI_V7)
    ifeq ($(strip $(COMPILER)),RVCT)
      CUSTOM_COMMINC  += vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official_rvct\inc
      COMPOBJS   += vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official_rvct\lib\zi8clib.a
      CUS_REL_OBJ_LIST   += vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official_rvct\lib\zi8clib.a
      CUS_INPUTMETHOD_BASE   = vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official_rvct
    else
      CUSTOM_COMMINC  += vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official\inc
      COMPOBJS   += vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official\lib\zi8clib.a
      CUS_REL_OBJ_LIST   += vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official\lib\zi8clib.a
      CUS_INPUTMETHOD_BASE   = vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official
    endif
  endif

# CSTAR free version with full database  .This one can be released to customer.
  ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_FREE_FULL)
    CUS_INPUTMETHOD_BASE = vendor\inputmethod\CStar\free_full
  endif

# CSTAR free version with slim database  10k words.This one can be released to customer.
  ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_FREE_SLIM_10K)
    CUS_INPUTMETHOD_BASE = vendor\inputmethod\CStar\free_slim_10k
  endif

# CSTAR free version with slim database 5k words .This one can be released to customer.
  ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_FREE_SLIM_5K)
    CUS_INPUTMETHOD_BASE = vendor\inputmethod\CStar\free_slim_5k
  endif

# CSTAR free version with slim database 0k words .This one can be released to customer.
  ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_FREE_SLIM_0K)
    CUS_INPUTMETHOD_BASE = vendor\inputmethod\CStar\free_slim_0k
  endif

# CSTAR slim 1 for romanian , czech , polish and Hungarian slim database  .This one CANNOT  be released to customer.
  ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_EASTERNEURO_SLIM1)
    CUS_INPUTMETHOD_BASE = vendor\inputmethod\CStar\eastern_euro_slim1
  endif

# CSTAR slim 2 for romanian , czech , polish and Hungarian slim database  .This one CANNOT  be released to customer.
  ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_EASTERNEURO_SLIM2)
    CUS_INPUTMETHOD_BASE = vendor\inputmethod\CStar\eastern_euro_slim2
  endif

# CSTAR Official version
  ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_V2)
    CUS_INPUTMETHOD_BASE = vendor\inputmethod\CStar\v2_official
  endif

# better way will be to OR the coming four    blocks , currently i dont know how to do.


#block 1  can be released
 ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_FREE_FULL)
    COMPLIST    += cstar
    ifeq ($(strip $(COMPILER)),RVCT)
      ifeq (ARM7EJ,$(findstring ARM7EJ,$(strip $(CFLAGS))))
        COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm7_rvct.a
      else
        ifeq (ARM9EJ,$(findstring ARM9EJ,$(strip $(CFLAGS))))
          COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm9_rvct.a
        else
          ifeq (ARM1176JZ,$(findstring ARM1176JZ,$(strip $(CFLAGS))))
            COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm11_rvct.a
          endif
        endif
      endif
    else
      COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime.a
    endif
    COM_DEFS    += __MMI_CSTAR__
    COM_DEFS    += __MMI_CSTAR_V2__
 # need this for feature file check  that only 4 languages can be enabled
    COM_DEFS    += __MMI_CSTAR_FREE_FULL__
    CUSTOM_COMMINC += $(strip $(CUS_INPUTMETHOD_BASE))\inc
    CUS_REL_BASE_COMP   += $(strip $(CUS_INPUTMETHOD_BASE))\lib
    CUS_REL_SRC_COMP += cstar
  endif


# block 2 can be released
 ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_FREE_SLIM_10K)
    COMPLIST    += cstar
    ifeq ($(strip $(COMPILER)),RVCT)
      ifeq (ARM7EJ,$(findstring ARM7EJ,$(strip $(CFLAGS))))
        COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm7_rvct.a
      else
        ifeq (ARM9EJ,$(findstring ARM9EJ,$(strip $(CFLAGS))))
          COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm9_rvct.a
        else
          ifeq (ARM1176JZ,$(findstring ARM1176JZ,$(strip $(CFLAGS))))
            COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm11_rvct.a
          endif
        endif
      endif
    else
      COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime.a
    endif
    COM_DEFS    += __MMI_CSTAR__
    COM_DEFS    += __MMI_CSTAR_V2__
 # need this for feature file check  that only 4 languages can be enabled
    COM_DEFS    += __MMI_CSTAR_FREE_SLIM_10K__
    CUSTOM_COMMINC += $(strip $(CUS_INPUTMETHOD_BASE))\inc
    CUS_REL_BASE_COMP   += $(strip $(CUS_INPUTMETHOD_BASE))\lib
    CUS_REL_SRC_COMP += cstar
  endif


# block 3 can be released
 ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_FREE_SLIM_5K)
    COMPLIST    += cstar
    ifeq ($(strip $(COMPILER)),RVCT)
      ifeq (ARM7EJ,$(findstring ARM7EJ,$(strip $(CFLAGS))))
        COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm7_rvct.a
      else
        ifeq (ARM9EJ,$(findstring ARM9EJ,$(strip $(CFLAGS))))
          COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm9_rvct.a
        else
          ifeq (ARM1176JZ,$(findstring ARM1176JZ,$(strip $(CFLAGS))))
            COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm11_rvct.a
          endif
        endif
      endif
    else
      COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime.a
    endif
    COM_DEFS    += __MMI_CSTAR__
    COM_DEFS    += __MMI_CSTAR_V2__
 # need this for feature file check  that only 4 languages can be enabled
    COM_DEFS    += __MMI_CSTAR_FREE_SLIM_5K__
    CUSTOM_COMMINC += $(strip $(CUS_INPUTMETHOD_BASE))\inc
    CUS_REL_BASE_COMP   += $(strip $(CUS_INPUTMETHOD_BASE))\lib
    CUS_REL_SRC_COMP += cstar
  endif



# block 4 can be released
 ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_FREE_SLIM_0K)
    COMPLIST    += cstar
    ifeq ($(strip $(COMPILER)),RVCT)
      ifeq (ARM7EJ,$(findstring ARM7EJ,$(strip $(CFLAGS))))
        COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm7_rvct.a
      else
        ifeq (ARM9EJ,$(findstring ARM9EJ,$(strip $(CFLAGS))))
          COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm9_rvct.a
        else
          ifeq (ARM1176JZ,$(findstring ARM1176JZ,$(strip $(CFLAGS))))
            COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm11_rvct.a
          endif
        endif
      endif
    else
      COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime.a
    endif
    COM_DEFS    += __MMI_CSTAR__
    COM_DEFS    += __MMI_CSTAR_V2__
 # need this for feature file check  that only 4 languages can be enabled
    COM_DEFS    += __MMI_CSTAR_FREE_SLIM_0K__
    CUSTOM_COMMINC += $(strip $(CUS_INPUTMETHOD_BASE))\inc
    CUS_REL_BASE_COMP   += $(strip $(CUS_INPUTMETHOD_BASE))\lib
    CUS_REL_SRC_COMP += cstar
  endif



# block 5 can be released
  ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_V2)
    COMPLIST    += cstar
    ifeq ($(strip $(COMPILER)),RVCT)
      ifeq (ARM7EJ,$(findstring ARM7EJ,$(strip $(CFLAGS))))
        COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm7_rvct.a
      else
        ifeq (ARM9EJ,$(findstring ARM9EJ,$(strip $(CFLAGS))))
          COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm9_rvct.a
        else
          ifeq (ARM1176JZ,$(findstring ARM1176JZ,$(strip $(CFLAGS))))
            COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm11_rvct.a
          endif
        endif
      endif
    else
      COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime.a
    endif    
    COM_DEFS    += __MMI_CSTAR__
    COM_DEFS    += __MMI_CSTAR_V2__
    CUSTOM_COMMINC += $(strip $(CUS_INPUTMETHOD_BASE))\inc
    CUS_REL_BASE_COMP   += $(strip $(CUS_INPUTMETHOD_BASE))\lib
    CUS_REL_SRC_COMP += cstar
  endif


# block 6 cannot release to customer
  ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_EASTERNEURO_SLIM1)
    COMPLIST    += cstar
    ifeq ($(strip $(COMPILER)),RVCT)
      ifeq (ARM7EJ,$(findstring ARM7EJ,$(strip $(CFLAGS))))
        COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm7_rvct.a
      else
        ifeq (ARM9EJ,$(findstring ARM9EJ,$(strip $(CFLAGS))))
          COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm9_rvct.a
        else
          ifeq (ARM1176JZ,$(findstring ARM1176JZ,$(strip $(CFLAGS))))
            COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm11_rvct.a
          endif
        endif
      endif
    else
      COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime.a
    endif    
    COM_DEFS    += __MMI_CSTAR__
    COM_DEFS    += __MMI_CSTAR_EASTERNEURO_SLIM2__
    CUSTOM_COMMINC += $(strip $(CUS_INPUTMETHOD_BASE))\inc
    CUS_REL_BASE_COMP   += $(strip $(CUS_INPUTMETHOD_BASE))\lib
  endif



# block 7  canot release to customer
  ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_EASTERNEURO_SLIM2)
    COMPLIST    += cstar
    ifeq ($(strip $(COMPILER)),RVCT)
      ifeq (ARM7EJ,$(findstring ARM7EJ,$(strip $(CFLAGS))))
        COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm7_rvct.a
      else
        ifeq (ARM9EJ,$(findstring ARM9EJ,$(strip $(CFLAGS))))
          COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm9_rvct.a
        else
          ifeq (ARM1176JZ,$(findstring ARM1176JZ,$(strip $(CFLAGS))))
            COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm11_rvct.a
          endif
        endif
      endif
    else
      COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime.a
    endif    
    COM_DEFS    += __MMI_CSTAR__
    COM_DEFS    += __MMI_CSTAR_EASTERNEURO_SLIM2__
    CUSTOM_COMMINC += $(strip $(CUS_INPUTMETHOD_BASE))\inc
    CUS_REL_BASE_COMP   += $(strip $(CUS_INPUTMETHOD_BASE))\lib
  endif


# CSTAR Demo version
  ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_V2_DEMO)
    CUS_INPUTMETHOD_BASE = vendor\inputmethod\CStar\v2_demo
    COMPLIST    += cstar
    ifeq ($(strip $(COMPILER)),RVCT)
      ifeq (ARM7EJ,$(findstring ARM7EJ,$(strip $(CFLAGS))))
        COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm7_rvct_demo.a
      else
        ifeq (ARM9EJ,$(findstring ARM9EJ,$(strip $(CFLAGS))))
          COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm9_rvct_demo.a
        else
          ifeq (ARM1176JZ,$(findstring ARM1176JZ,$(strip $(CFLAGS))))
            COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime_arm11_rvct_demo.a
          endif
        endif
      endif
    else
      COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime.a
    endif 
    COM_DEFS    += __MMI_CSTAR__
    COM_DEFS    += __MMI_CSTAR_V2__
    CUSTOM_COMMINC += $(strip $(CUS_INPUTMETHOD_BASE))\inc
    CUS_REL_BASE_COMP   += $(strip $(CUS_INPUTMETHOD_BASE))\lib
    CUS_REL_SRC_COMP += cstar
  endif

  ifneq ($(findstring MMI_ZI,$(INPUT_METHOD)),)
    COM_DEFS    += __MMI_ZI__
    ifeq ($(strip $(call Upper,$(INPUT_METHOD))),MMI_ZI_V7)
      COM_DEFS    += __MMI_ZI_V7__
    endif
    ifeq ($(strip $(call Upper,$(INPUT_METHOD))),MMI_ZI)
      COM_DEFS    += __MMI_ZI_V7__
    endif
    COMPLIST    += zi
    ifeq ($(strip $(INPUT_METHOD)),MMI_ZI_V7)
      CUS_ZI = $(shell dir $(strip $(CUS_INPUTMETHOD_BASE))\lib\ziShape.a /b 2>nul)
    else
      ifeq ($(strip $(INPUT_METHOD)),MMI_ZI)
        CUS_ZI = $(shell dir $(strip $(CUS_INPUTMETHOD_BASE))\lib\ziShape.a /b 2>nul)
      else
        CUS_ZI = $(shell dir $(strip $(CUS_INPUTMETHOD_BASE))\lib\zi8ARShape.a /b 2>nul)
      endif
    endif
    ifeq ($(words $(strip $(CUS_ZI))),1)
      ifeq ($(strip $(INPUT_METHOD)),MMI_ZI_V7)
      COMPOBJS  	+= $(strip $(CUS_INPUTMETHOD_BASE))\lib\ziShape.a
      CUS_REL_OBJ_LIST  	+= $(strip $(CUS_INPUTMETHOD_BASE))\lib\ziShape.a
      else
        ifeq ($(strip $(INPUT_METHOD)),MMI_ZI)
          COMPOBJS  	+= $(strip $(CUS_INPUTMETHOD_BASE))\lib\ziShape.a
          CUS_REL_OBJ_LIST  	+= $(strip $(CUS_INPUTMETHOD_BASE))\lib\ziShape.a
        else
          COMPOBJS  	+= $(strip $(CUS_INPUTMETHOD_BASE))\lib\zi8ARShape.a
          CUS_REL_OBJ_LIST  	+= $(strip $(CUS_INPUTMETHOD_BASE))\lib\zi8ARShape.a
        endif
      endif
    endif
  endif
  ifneq ($(findstring MMI_T9,$(INPUT_METHOD)),)
    COM_DEFS    += __MMI_T9__
    ifeq ($(strip $(call Upper,$(INPUT_METHOD))),MMI_T9_V7_4)
       ifeq ($(strip $(MMIDIR)),plutommi)
          COM_DEFS    += __MMI_T9_V7_4__
       endif
    endif
    ifeq ($(strip $(call Upper,$(INPUT_METHOD))),MMI_T9)
       ifeq ($(strip $(MMIDIR)),plutommi)
          COM_DEFS    += __MMI_T9_V7_4__
       endif
    endif
    COMPLIST    += t9
  endif
  ifeq ($(strip $(INPUT_METHOD)),MMI_XT9)
    COMPLIST    += t9
    COM_DEFS    += __MMI_T9__
    COM_DEFS    += __MMI_XT9__
    CUSTOM_COMMINC  +=  vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\xt9\inc
    COMPOBJS    += vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\xt9\lib\xt9.o
    CUS_REL_OBJ_LIST    += vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\xt9\lib\xt9.o
    CUS_INPUTMETHOD_BASE   = vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\xt9
  endif

  ifeq ($(strip $(INPUT_METHOD)),MMI_T9)
    ifeq ($(strip $(COMPILER)),RVCT)
        CUSTOM_COMMINC  +=  vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official_rvct\inc
        COMPOBJS    += vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official_rvct\lib\t9relChinese_rvct.o
        CUS_REL_OBJ_LIST    += vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official_rvct\lib\t9relChinese_rvct.o
        CUS_INPUTMETHOD_BASE   = vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official_rvct
    else
        CUSTOM_COMMINC  +=  vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official\inc
        COMPOBJS    += vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official\lib\t9relChinese.o
        CUS_REL_OBJ_LIST    += vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official\lib\t9relChinese.o
        CUS_INPUTMETHOD_BASE   = vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official
    endif
  endif

  ifeq ($(strip $(INPUT_METHOD)),MMI_T9_V7_4)
    ifeq ($(strip $(COMPILER)),RVCT)
        COMPOBJS    += vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official_rvct\lib\t9relChinese_rvct.o
        CUS_REL_OBJ_LIST    += vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official_rvct\lib\t9relChinese_rvct.o
        CUSTOM_COMMINC  +=  vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official_rvct\inc
        CUS_INPUTMETHOD_BASE   = vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official_rvct
    else
        COMPOBJS    += vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official\lib\t9relChinese.o
        CUS_REL_OBJ_LIST    += vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official\lib\t9relChinese.o
        CUSTOM_COMMINC  +=  vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official\inc
        CUS_INPUTMETHOD_BASE   = vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_4_official
    endif 
  endif
  ifeq ($(strip $(INPUT_METHOD)),MMI_T9_V7)
    ifeq ($(strip $(COMPILER)),RVCT)
        CUSTOM_COMMINC  +=  vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_official_rvct\inc
        COMPOBJS    += vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_official_rvct\lib\t9relChinese_rvct.o
        CUS_REL_OBJ_LIST    += vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_official_rvct\lib\t9relChinese_rvct.o
        CUS_INPUTMETHOD_BASE   = vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_official_rvct
    else
        CUSTOM_COMMINC  +=  vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_official\inc
        COMPOBJS    += vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_official\lib\t9relChinese.o
        CUS_REL_OBJ_LIST    += vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_official\lib\t9relChinese.o
        CUS_INPUTMETHOD_BASE   = vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_official
    endif 
  endif
  ifeq ($(strip $(INPUT_METHOD)),MMI_T9_V6)
    $(warning ERROR: INPUT_METHOD MMI_T9_V6 is phased out. Please change INPUT_METHOD value)
    DEPENDENCY_CONFLICT = TRUE
  endif
  CUS_REL_BASE_COMP   += $(strip $(CUS_INPUTMETHOD_BASE))
  ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
    ifneq ($(strip $(INPUT_METHOD)),NONE)
      CUS_ZI = $(shell dir $(strip $(CUS_INPUTMETHOD_BASE)) /b 2>nul)
      ifneq ($(words $(strip $(CUS_ZI))),2)
        $(warning ERROR: $(strip $(CUS_INPUTMETHOD_BASE)) does NOT exist!)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif

  ifneq ($(strip $(INPUT_METHOD_BASE)),plutommi)
    ifneq ($(strip $(INPUT_METHOD_BASE)),lcmmi)
      CUS_T9 = $(shell dir vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE)) /b 2>nul)
      ifneq ($(words $(strip $(CUS_T9))),0)
        CUS_REL_BASE_COMP   += vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE)) make\t9 vendor\InputMethod\T9\adaptation
      endif
      CUS_ZI = $(shell dir vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE)) /b 2>nul)
      ifneq ($(words $(strip $(CUS_ZI))),0)
        CUS_REL_BASE_COMP   += vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE)) make\zi vendor\InputMethod\ZI\adaptation
      endif
    endif
  endif

endif

ifdef INPUT_METHOD
  ifneq ($(strip $(INPUT_METHOD)),NONE)
    ifeq ($(strip $(EMPTY_RESOURCE)),FALSE)
      CUS_REL_BASE_COMP += vendor\InputMethod\ZI\project\$(MMIDIR) \
                           vendor\InputMethod\T9\project\$(MMIDIR) \
                           vendor\InputMethod\cstar\v2_official \
                           vendor\InputMethod\cstar\v2_demo
    endif
  endif
  CUS_REL_BASE_COMP += vendor\InputMethod\ZI\adaptation make\zi \
                       vendor\InputMethod\T9\adaptation make\t9 \
                       vendor\InputMethod\cstar\adaptation make\cstar
endif

ifdef GAME_ENGINE
  ifneq ($(strip $(GAME_ENGINE)),NONE)
    COMPLIST    += game_engine
  endif
  ifeq ($(strip $(GAME_ENGINE)),GE_BROGENT)
    COMPOBJS    += vendor\game_engine\brogent\engine_v1\arm\mini_bgl.lib \
                   vendor\game_engine\brogent\game\GoGoRobot2\GAME_LIB\arm\bgt_ggr2_optimize.lib \
                   vendor\game_engine\brogent\game\HeatBreaker2\GAME_LIB\arm\bgt_hb2_utils.lib
    CUS_REL_OBJ_LIST += vendor\game_engine\brogent\engine_v1\arm\mini_bgl.lib \
                        vendor\game_engine\brogent\game\GoGoRobot2\GAME_LIB\arm\bgt_ggr2_optimize.lib \
                        vendor\game_engine\brogent\game\HeatBreaker2\GAME_LIB\arm\bgt_hb2_utils.lib \
                        vendor\game_engine\brogent\engine_v1\pc\mini_bgl.lib \
                        vendor\game_engine\brogent\game\GoGoRobot2\GAME_LIB\pc\bgt_ggr2_optimize.lib \
                        vendor\game_engine\brogent\game\HeatBreaker2\GAME_LIB\pc\bgt_hb2_utils.lib
  endif
  ifeq ($(strip $(GAME_ENGINE)),GE_INTERGRAFX)
    #COMPOBJS  	+= vendor\game_engine\brogent\engine_v1\arm\ur_engine.lib
  endif
endif

#ifdef JATAAYU_FEATURE
#   ifeq ($(findstring WAP,$(JATAAYU_FEATURE)),WAP) # if $(JATAAYU_FEATURE) is *WAP*
#       COMPLIST    += jataayu jataayuapp jdd
#   endif
#endif

ifdef DRV_CUSTOM_TOOL_SUPPORT
  ifeq ($(strip $(DRV_CUSTOM_TOOL_SUPPORT)),TRUE)
      CUS_REL_BASE_COMP += custom\drv\Drv_Tool
  endif
endif

ifdef BROWSER_SUPPORT
  ifeq ($(strip $(BROWSER_SUPPORT)),OBIGO_Q03C)
    COMPLIST    += obigo03capp obigo03cadp obigo03clib
    COMPLIST    += obigo03cstkadp obigo03cstklib
  endif
  ifeq ($(strip $(BROWSER_SUPPORT)),OBIGO_Q05A)
    COMPLIST    += obigo05aadp obigo05alib
  endif
  ifeq ($(strip $(BROWSER_SUPPORT)),OPERA_V10)
    COMPLIST    += opera10adp opera10opdev
    COMPLIST    += obigo03capp obigo03cadp obigo03clib
    COMPLIST    += opera10int
    CUS_REL_MTK_COMP += opera10int
    ifeq ($(strip $(COMPILER)),RVCT)
      COMPOBJS    += vendor\opera\browser\v1_official\lib\rvct\opera_rvct.lib
      CUS_REL_OBJ_LIST += vendor\opera\browser\v1_official\lib\rvct\opera_rvct.lib
    else
      COMPOBJS    += vendor\opera\browser\v1_official\lib\arm\opera.lib
      CUS_REL_OBJ_LIST += vendor\opera\browser\v1_official\lib\arm\opera.lib
    endif    
    CUS_REL_BASE_COMP += vendor\opera\browser\v1_official\Resource
    CUS_REL_FILES_LIST += vendor\opera\browser\v1_official\lib\win32\opera.lib
    CUS_REL_FILES_LIST += vendor\opera\browser\v1_official\lib\win32\ulldvrm.obj
  endif
endif


ifdef SYNCML_SUPPORT
  ifneq ($(strip $(SYNCML_SUPPORT)),FALSE)
    ifeq ($(strip $(OBIGO_FEATURE)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,OBIGO_FEATURE,SYNCML_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(HTTP_INTERFACE_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,HTTP_INTERFACE_SUPPORT,SYNCML_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif  
  endif
  ifeq ($(strip $(SYNCML_SUPPORT)),TRUE)
    ifndef VCARD_SUPPORT
     $(call DEP_ERR_ONA_OR_OFFB,OBIGO_FEATURE,SYNCML_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
    endif
  ifeq ($(strip $(VCARD_SUPPORT)),NONE)
  $(call DEP_ERR_ONA_OR_OFFB,OBIGO_FEATURE,SYNCML_SUPPORT)
  DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __SYNCML_SUPPORT__
    COMPLIST    += syncml
    COMP_TRACE_DEFS += ps\syncml\include\syncml_trc.h
  endif
endif

ifdef UNIFIED_MESSAGE_ADVANCE_FEATURE
    CUS_REL_FILES_LIST += plutommi\Service\SmsSrv\SmsArchiveSrv.h
    ifneq ($(findstring COMPOSER,$(strip $(UNIFIED_MESSAGE_ADVANCE_FEATURE))),)
        COMMINCDIRS	+= plutommi\MMI\UnifiedComposer\UnifiedComposerInc
    endif
endif

CUS_REL_FILES_LIST += plutommi\Service\WgtMgrSrv\mem_widget_icon.png.hex
CUS_REL_FILES_LIST += plutommi\Service\WgtMgrSrv\mem_widget_icon_big.png.hex

ifdef MMS_SUPPORT
ifdef UNIFIED_MESSAGE_ADVANCE_FEATURE
  ifneq ($(findstring COMPOSER,$(strip $(UNIFIED_MESSAGE_ADVANCE_FEATURE))),)
    ifneq ($(strip $(MMS_SUPPORT)),OBIGO_Q03C_MMS_V02)
      $(call DEP_ERR_ONA_OR_OFFB,MMS_SUPPORT,COMPOSER in UNIFIED_MESSAGE_ADVANCE_FEATURE)
      DEPENDENCY_CONFLICT = TRUE
    endif

    COM_DEFS    +=  __UNIFIED_COMPOSER_SUPPORT__
  endif
endif    
endif    

ifdef UNIFIED_MESSAGE_ADVANCE_FEATURE
  ifneq ($(findstring ARCHIVE,$(strip $(UNIFIED_MESSAGE_ADVANCE_FEATURE))),)
      COM_DEFS    +=  __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
  endif
endif

ifdef RTSP_SUPPORT
  ifeq ($(strip $(RTSP_SUPPORT)),TRUE)
    COMPLIST	+= rtsp
    COM_DEFS    += __RTSP__
  endif
endif

ifneq ($(filter __KTEST__,$(CUSTOM_OPTION)),)
  COMPLIST += ktest 
  CUS_REL_SRC_COMP += ktest
endif
CUS_REL_BASE_COMP += mtkdebug\ktest make\ktest


SYNC_LCM_SUPPORT_NOT_SUPPORT_FLATFORM = MT6205 MT6217 MT6218 MT6223 MT6223P MT6225 
SYNC_LCM_HW_SUPPORT_PLATFORM = MT6235 MT6235B MT6236 MT6236B MT6238 MT6239 MT6268 MT6253T MT6253 MT6516 MT6270A MT6255 MT6256 MT6276 MT6253E MT6253L MT6252 MT6252H
SYNC_LCM_SUPPORT_DISABLE_OPTION = FALSE NONE 

ifdef SYNC_LCM_SUPPORT
  ifeq ($(filter $(strip $(SYNC_LCM_SUPPORT)) ,$(SYNC_LCM_SUPPORT_DISABLE_OPTION)),)
      ifneq ($(filter $(strip $(PLATFORM)) ,$(SYNC_LCM_SUPPORT_NOT_SUPPORT_FLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support SYNC_LCM_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif  

      ifdef SYNC_LCM_METHOD
        ifeq ($(strip $(SYNC_LCM_METHOD)),BY_CHIP)
          #legacy chip-dependent method
          ifneq ($(filter $(strip $(PLATFORM)) ,$(SYNC_LCM_HW_SUPPORT_PLATFORM)),)
            COM_DEFS    += __SYNC_LCM_SUPPORT__ __SYNC_LCM_HW_SUPPORT__
          else    
            COM_DEFS    += __SYNC_LCM_SUPPORT__ __SYNC_LCM_SW_SUPPORT__
          endif
        else
          COM_DEFS    += __SYNC_LCM_SUPPORT__
          COM_DEFS    += __SYNC_LCM_$(strip $(SYNC_LCM_METHOD))_SUPPORT__
        endif
      else
        #legacy chip-dependent method
        ifneq ($(filter $(strip $(PLATFORM)) ,$(SYNC_LCM_HW_SUPPORT_PLATFORM)),)
          COM_DEFS    += __SYNC_LCM_SUPPORT__ __SYNC_LCM_HW_SUPPORT__
        else    
          COM_DEFS    += __SYNC_LCM_SUPPORT__ __SYNC_LCM_SW_SUPPORT__
        endif
      endif

  endif
endif


ifeq ($(strip $(call Upper,$(PLATFORM))),MT6225)
   ifeq ($(strip $(call Upper,$(CHIP_VER))),S00)
      COM_DEFS    +=  MT6225_DMA_EMI_ISSUE
   endif
endif

ifeq ($(strip $(call Upper,$(PLATFORM))),MT6235)
  ifeq ($(strip $(call Upper,$(CHIP_VER))),S00)
    $(warning ERROR: CHIP_VER should be larger than S00 for MT6235)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(call Upper,$(PLATFORM))),MT6235B)
  ifeq ($(strip $(call Upper,$(CHIP_VER))),S00)
    $(warning ERROR: CHIP_VER should be larger than S00 for MT6235B)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef VDOEDT_SUPPORT
  VDOEDT_SUPPORT_NOT_SUPPORT_FLATFORM = MT6205B MT6208 MT6217 MT6218B MT6219 MT6226 MT6227 MT6227D MT6226D
  ifeq ($(strip $(VDOEDT_SUPPORT)),TRUE)
    ifneq ($(strip $(MP4_DECODE)),TRUE)
      $(call DEP_ERR_SETA_OR_OFFB,MP4_DECODE,TRUE,VDOEDT_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(MP4_ENCODE)),TRUE)
      $(call DEP_ERR_SETA_OR_OFFB,MP4_ENCODE,TRUE,VDOEDT_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(filter $(strip $(PLATFORM)),$(MP4_HW_CODEC_V1_PLATFORM)),)
      $(warning ERROR: VDOEDT_SUPPORT require MP4_HW which is not supported by PLATFORM=$(strip $(PLATFORM)))
      DEPENDENCY_CONFLICT = TRUE    
    endif
    ifneq ($(filter $(strip $(PLATFORM)),$(VDOEDT_SUPPORT_NOT_SUPPORT_FLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support VDOEDT_SUPPORT.)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(FINGER_TOUCH_SUPPORT)),FTE)
      $(warning ERROR: VDOEDT_SUPPORT do not support FTE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(VDOEDT_SUPPORT)),TRUE)
     COM_DEFS    += VDOEDT_SUPPORT
     COM_DEFS    += __VIDEO_EDITOR__
  endif
endif

ifneq ($(filter DUAL_LCD,$(COM_DEFS)),)
  ifeq ($(strip $(SUB_LCD_SIZE)),NONE)
    ifneq ($(strip $(PLATFORM)),TK6516)
      ifneq ($(strip $(PLATFORM)),MT6516)
        $(warning ERROR: Please set SUB_LCD_SIZE when DUAL LCD (LCD_MODULE=$(strip $(LCD_MODULE))) is used)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

L1CACHEABLE_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6268T MT6268H TK6516 MT6225 MT6253T MT6253
ifneq ($(filter $(strip $(PLATFORM)) ,$(L1CACHEABLE_SUPPORT_PLATFORM)),)
  COM_DEFS += __MTK_L1CACHEABLE__
endif

L2CACHEABLE_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6268T MT6268H MT6238 MT6239 
ifneq ($(filter $(strip $(PLATFORM)) ,$(L2CACHEABLE_SUPPORT_PLATFORM)),)
  COM_DEFS += __MTK_L2CACHEABLE__
endif

DCM_SUPPORT_PLATFORM = MT6223% MT6225 MT6235% MT6238 MT6239 MT6268% MT6253T MT6253 MT6236% MT6270A
ifneq ($(filter $(strip $(DCM_SUPPORT_PLATFORM)) ,$(PLATFORM)),)
  COM_DEFS += __DYNAMIC_CODE_MANAGER__
endif

WTCACHEABLE_SUPPORT_PLATFORM = MT6253 
ifneq ($(filter $(strip $(PLATFORM)) ,$(WTCACHEABLE_SUPPORT_PLATFORM)),)
  COM_DEFS += __WRITE_THROUGH_CACHEABLE__
endif

CUS_REL_BASE_COMP += make\theme_rom

ifeq ($(filter dp_engine,$(COMPLIST)),dp_engine)
  ifeq ($(strip $(call Upper,$(PLATFORM))),MT6205B)
    $(warning ERROR: MT6205B does not support dp_engine)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

CARD_DOWNLOAD_NOT_SUPPORT_PLATFORM = MT6223 MT6223C MT6225
ifdef CARD_DOWNLOAD
  ifneq ($(strip $(CARD_DOWNLOAD)),NONE)
    ifneq ($(filter $(strip $(PLATFORM)),$(CARD_DOWNLOAD_NOT_SUPPORT_PLATFORM)),)
      $(error $(strip $(PLATFORM)) does not support CARD_DOWNLOAD)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __CARD_DOWNLOAD__
  endif
endif

ifdef L1_GPRS
   ifneq ($(call Upper ,$(strip $(L1_GPRS))),TRUE)
      ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
         $(warning ERROR: __PS_SERVICE__ is not supported with L1_GPRS != TURE)
         DEPENDENCY_CONFLICT = TRUE
      endif
   endif
endif

ifneq ($(filter __VIDEO_ARCHI_V1__,$(strip $(COM_DEFS))),)
    COMMINCDIRS += media\video\sw_video\include
endif

ifneq ($(filter __VIDEO_ARCHI_V2__,$(strip $(COM_DEFS))),)
    COMMINCDIRS += media\video_v2\common\include
    COMMINCDIRS += media\media_sec\video_v2\renderer\include
    COMMINCDIRS += media\codec\include  
    COMMINCDIRS += media\media_sec\video_v2\include
endif 
          
COMMINCDIRS += interface\l1audio

#end of COMMINCDIRS

ifdef CUST_CODE
  ifneq ($(strip $(CUST_CODE)),NONE)
    COM_DEFS += __$(strip $(CUST_CODE))__
  endif
  ifeq ($(strip $(CUST_CODE)),TC01)
    COM_DEFS += __RMMI_EXTEND_CUSTOM_CMD__ __AT_ME_IDENTIFICATION_WITHOUT_HEADER__
    ifneq ($(strip $(DRM_SUPPORT)),NONE)
      COM_DEFS += __LONG_AT_CMD_SUPPORT__
    endif
  endif
endif

ifdef TC01_ERS_LOCATION
  ifeq ($(strip $(TC01_ERS_LOCATION)),NVRAM)
    COM_DEFS += __TC01_ERS_NVRAM__
  endif
  ifeq ($(strip $(TC01_ERS_LOCATION)),BACKUP)
    ifndef SYSDRV_BACKUP_DISK_SUPPORT
      $(warning ERROR: PLEASE set SYSDRV_BACKUP_DISK_SUPPORT to be FAT or set TC01_ERS_LOCATION to be NVRAM)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(SYSDRV_BACKUP_DISK_SUPPORT)),FAT)
      $(warning ERROR: PLEASE set SYSDRV_BACKUP_DISK_SUPPORT to be FAT or set TC01_ERS_LOCATION to be NVRAM)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __TC01_ERS_BACKUP__
  endif
endif

ifeq ($(strip $(MMI_VERSION)),WISDOM_MMI)

CUS_REL_BASE_COMP += external_mmi make\lgoem

ifeq ($(strip $(WISDOM_CUSTOM_BUILD)),TRUE)
WISE_LIB_PATH = ..\App\Lib\Phone_WISDOM35B_DEMO_MEXICO_TELCEL\release
WISE_MODULE_LIB_PATH = ..\App\Component\MSApiLib\Image\Adapt\GrImage\ScaladoLib\bin
WISE_JAVA_VM_LIB_PATH = ..\App\Module\Java\VM\Lib\tgt\MEXICO_TELCEL
else
WISE_LIB_PATH = external_mmi\wise\wise_headers\$(strip $(BOARD_VER))\App\Lib\Phone_WISDOM35B_DEMO_MEXICO_TELCEL\release
WISE_MODULE_LIB_PATH = external_mmi\wise\wise_headers\$(strip $(BOARD_VER))\App\Component\MSApiLib\Image\Adapt\GrImage\ScaladoLib\bin
WISE_JAVA_VM_LIB_PATH = external_mmi\wise\wise_headers\$(strip $(BOARD_VER))\App\Module\Java\VM\Lib\tgt\MEXICO_TELCEL
endif

WISE_LIB := $(strip $(WISE_LIB_PATH))\ApiLinkLib.lib \
  $(strip $(WISE_LIB_PATH))\BasicApiAdapt.lib \
  $(strip $(WISE_LIB_PATH))\BasicApiCore.lib \
  $(strip $(WISE_LIB_PATH))\CommLib.lib \
  $(strip $(WISE_LIB_PATH))\DataComApiLib.lib \
  $(strip $(WISE_LIB_PATH))\DeviceApiLib.lib \
  $(strip $(WISE_LIB_PATH))\Pal.lib \
  $(strip $(WISE_LIB_PATH))\PalDevice.lib \
  $(strip $(WISE_LIB_PATH))\PeanutCore.lib \
  $(strip $(WISE_LIB_PATH))\PeanutOem.LIB \
  $(strip $(WISE_LIB_PATH))\PIMSLib.lib \
  $(strip $(WISE_LIB_PATH))\TAPILib.lib \
  $(strip $(WISE_LIB_PATH))\ZLib.lib \
  $(strip $(WISE_LIB_PATH))\LGDrmWBXml.lib \
  $(strip $(WISE_LIB_PATH))\LGDrmXml.lib \
  $(strip $(WISE_LIB_PATH))\LGDrmLib.lib \
  $(strip $(WISE_LIB_PATH))\LGDrmOpenSSL.lib \
  $(strip $(WISE_LIB_PATH))\LGDrmPBLisam.lib \
  $(strip $(WISE_LIB_PATH))\LGDrmXySSL.lib \
  $(strip $(WISE_LIB_PATH))\WapApiLib.lib \
  $(strip $(WISE_LIB_PATH))\GifLib.lib \
  $(strip $(WISE_LIB_PATH))\caivs.LIB	\
  $(strip $(WISE_LIB_PATH))\FlashLib.lib \
  $(strip $(WISE_LIB_PATH))\MMApiLib.lib \
  $(strip $(WISE_LIB_PATH))\SVGApiLib.lib \
  $(strip $(WISE_LIB_PATH))\MFlash20.lib \
  $(strip $(WISE_LIB_PATH))\GNLib.lib \
  $(strip $(WISE_LIB_PATH))\MSFImage.lib \
  $(strip $(WISE_LIB_PATH))\MSFPlayer.lib \
  $(strip $(WISE_LIB_PATH))\MSFCamera.lib \
  $(strip $(WISE_LIB_PATH))\JavaLib.lib

ifeq ($(strip $(WISDOM_CUSTOM_BUILD)),TRUE)
  WISE_LIB += $(strip $(WISE_LIB_PATH))\lgoem.lib
endif

WISE_LIB += $(strip $(WISE_MODULE_LIB_PATH))\baseapi.a\
  $(strip $(WISE_MODULE_LIB_PATH))\capseng.a\
  $(strip $(WISE_MODULE_LIB_PATH))\cmface.a\
  $(strip $(WISE_MODULE_LIB_PATH))\excodecs.a\
  $(strip $(WISE_MODULE_LIB_PATH))\fmautorama.a   \
  $(strip $(WISE_MODULE_LIB_PATH))\fmclearshot.a  \
  $(strip $(WISE_MODULE_LIB_PATH))\fmexif.a\
  $(strip $(WISE_MODULE_LIB_PATH))\fmextencoder.a \
  $(strip $(WISE_MODULE_LIB_PATH))\fmjpegsqueeze.a\
  $(strip $(WISE_MODULE_LIB_PATH))\fmjpegtools.a\
  $(strip $(WISE_MODULE_LIB_PATH))\fmphotoart.a\
  $(strip $(WISE_MODULE_LIB_PATH))\fmspeedview.a\
  $(strip $(WISE_MODULE_LIB_PATH))\fmfacewarp.a \
  $(strip $(WISE_JAVA_VM_LIB_PATH))\libjbedfbcc_GM210.a  

COMPOBJS += $(WISE_LIB)
CUS_REL_OBJ_LIST += $(WISE_LIB)
endif

            
# For MoDIS AVLib release.

CUS_REL_FILES_LIST += MoDIS_VC9\MoDIS\w32_av_lib.cpp \
                      MoDIS_VC9\MoDIS\w32_av_lib.h \
                      MoDIS_VC9\MoDIS\w32_av_types.h \
                      MoDIS_VC9\MoDIS\AVLib\Player.h \
                      MoDIS_VC9\MoDIS\AVLib\RgbFormat.h \
                      MoDIS_VC9\MoDIS\AVLib\VideoSample.h       

# For NEPTUNE voice prompt release.
ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
CUS_REL_FILES_LIST += lcmmi\Customer\VoicePrompt\VPres\VP.zip
endif

# For smart phone settings.
ifdef SMART_PHONE_CORE
  ifneq ($(strip $(SMART_PHONE_CORE)),NONE)
    include make\smart_phone_option.mak
  endif
endif

# BASIC or MEUT projects do not need L1_TMD_FILES
ifeq ($(strip $(call Upper,$(PROJECT))),BASIC)
  L1_TMD_FILES :=
endif
ifeq ($(strip $(call Upper,$(PROJECT))),MEUT)
  L1_TMD_FILES :=
  
endif

ifeq ($(strip $(ATV_RECORD_SUPPORT)),TRUE)
    ifneq ($(strip $(ATV_SUPPORT)),TRUE)
      $(call DEP_ERR_SETA_OR_SETB,ATV_SUPPORT,TRUE,ATV_RECORD_SUPPORT,FALSE)
      #$(call DEP_ERR_ONA_OR_OFFB,ATV_SUPPORT,ATV_RECORD_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __ATV_RECORD_SUPPORT__ 
endif

ifeq ($(strip $(ATV_SUPPORT)),SLIM)
    COM_DEFS += __ATV_SLIM_VERSION__
endif

ifneq ($(strip $(ATV_SUPPORT)),SLIM)
  REMOVE_CR += MAUI_02615646
endif

#####
# COMMON SECTION used by gsm2.mak and custom_release.mak
#####

DEFAULT_CUSTOMER = MTK MTK_RF PLUTO
ifneq ($(filter $(call Upper,$(strip $(CUSTOMER))),$(strip $(DEFAULT_CUSTOMER))),)
  VERNOFILE		=  make\Verno.bld

  ifdef FOTA_ENABLE
    ifneq ($(strip $(FOTA_ENABLE)),NONE)
      SCATTERFILE		=	custom\system\$(strip $(BOARD_VER))\scat$(strip $(PLATFORM))_FOTA.txt
    else
      SCATTERFILE		=	custom\system\$(strip $(BOARD_VER))\scat$(strip $(PLATFORM)).txt
    endif
  else
    SCATTERFILE		=	custom\system\$(strip $(BOARD_VER))\scat$(strip $(PLATFORM)).txt
  endif
  ifneq ($(strip $(FOTA_ENABLE)),NONE)
    SCATTERFILE		:=	custom\system\$(strip $(BOARD_VER))\scat$(strip $(PLATFORM))_FOTA.txt
  endif
  ifeq ($(strip $(call Upper,$(PROJECT))),L1S)
    SCATTERFILE		:=	custom\system\$(strip $(BOARD_VER))\scat$(strip $(PLATFORM))_L1S.txt
  endif
  ifeq ($(strip $(call Upper,$(PROJECT))),BASIC)
    SCATTERFILE		:=	custom\system\$(strip $(BOARD_VER))\scat$(strip $(PLATFORM))_BASIC.txt
  endif
  ifeq ($(strip $(call Upper,$(PROJECT))),MEUT)
    SCATTERFILE		:=	custom\system\$(strip $(BOARD_VER))\scat$(strip $(PLATFORM))_MEUT.txt
  endif
  ifeq ($(strip $(call Upper,$(PROJECT))),GPRS)
    VERNOFILE		:=  make\Verno_ClassB.bld
  endif
  ifneq ($(filter UMTS HSPA,$(strip $(call Upper,$(PROJECT)))),)
    VERNOFILE		:=  make\Verno_ClassB_UMTS.bld
  endif
else
  VERNOFILE		=  make\Verno_$(strip $(CUSTOMER)).bld

  ifdef FOTA_ENABLE
    ifneq ($(strip $(FOTA_ENABLE)),NONE)
      SCATTERFILE		=	custom\system\$(strip $(BOARD_VER))\scat$(strip $(CUSTOMER))_FOTA.txt
    else
      SCATTERFILE		=	custom\system\$(strip $(BOARD_VER))\scat$(strip $(CUSTOMER)).txt
    endif
  else
    SCATTERFILE		=	custom\system\$(strip $(BOARD_VER))\scat$(strip $(CUSTOMER)).txt
  endif

  ifeq ($(strip $(call Upper,$(PROJECT))),L1S)
    SCATTERFILE		:=	custom\system\$(strip $(BOARD_VER))\scat$(strip $(CUSTOMER))_L1S.txt
  endif
  ifeq ($(strip $(call Upper,$(PROJECT))),BASIC)
    SCATTERFILE		:=	custom\system\$(strip $(BOARD_VER))\scat$(strip $(CUSTOMER))_BASIC.txt
  endif
  ifeq ($(strip $(call Upper,$(PROJECT))),MEUT)
    SCATTERFILE		:=	custom\system\$(strip $(BOARD_VER))\scat$(strip $(CUSTOMER))_MEUT.txt
  endif
endif

BL_SCATTERFILE   = custom\system\$(strip $(BOARD_VER))\scatBL_$(strip $(PLATFORM)).txt
FOTA_SCATTERFILE = custom\system\$(strip $(BOARD_VER))\scatFOTA_$(strip $(PLATFORM)).txt

include $(strip $(VERNOFILE))
SLIM_BRANCH := $(call Upper,$(strip $(BRANCH)))
BRANCH   +=   $(call Upper,$(strip $(CUSTOMER)))

# *************************************************************************
# Include extra dependency check.
# *************************************************************************
-include make\Extra_dep.mak

# *************************************************************************
# Build path, directories
# *************************************************************************
FIXPATH        =  .
TARGNAME       =  $(strip $(CUSTOMER))_$(strip $(SUB_BOARD_VER))_$(PROJECT)_$(strip $(PLATFORM))_$(strip $(CHIP_VER))
PLATLIBROOT    =  $(strip $(FIXPATH))\lib\$(strip $(PLATFORM))
TSTDIR         =  $(strip $(FIXPATH))\tst
TST_DB         =  $(strip $(TSTDIR))\database
ifeq ($(call Upper,$(PROJECT)),GPRS)
	TST_DB         :=  $(strip $(TSTDIR))\database_classb
endif
ifneq ($(filter UMTS HSPA,$(strip $(call Upper,$(PROJECT)))),)
	TST_DB         :=  $(strip $(TSTDIR))\database_classb_umts
endif
BUILDDIR       =  $(strip $(FIXPATH))\build
TARGDIR        =  $(strip $(BUILDDIR))\$(strip $(CUSTOMER))
PROJDIR        =  $(strip $(TARGDIR))\$(PROJECT)
BPLGUINFOCUSTOMPREFIX = BPLGUInfoCustomApp_$(strip $(PLATFORM))_$(strip $(CHIP_VER))
DBG_INFO_VERNO = $(subst .,_,$(VERNO))

OBJSDIR        =  $(strip $(PROJDIR))\$(strip $(PLATFORM))o
RULESDIR       =  $(strip $(PROJDIR))\$(strip $(PLATFORM))r
COMPLIBDIR     =  $(strip $(OBJSDIR))\lib

# Component s log file
COMPLOGDIR     =  $(strip $(TARGDIR))\log

HEADER_TEMP    =  header_temp
CUSTPACKDIR    =  $(strip $(FIXPATH))\custpack

NOT_REMOVAL_DIR_FILE = make\NotRemovalCodeDir.def

# Move to project makefile
# Settings for operator
#ifdef MMI_BASE
#  ifeq ($(strip $(MMI_BASE)),PLUTO_MMI)
#    ifneq ($(strip $(OPTR_SPEC)),NONE)
#      OPTR_PATH = operator\$(strip $(word 1,$(subst _, ,$(OPTR_SPEC)))\$(word 2,$(subst _, ,$(OPTR_SPEC))))\plutommi
#      -include $(OPTR_PATH)\operator.mak
#    endif
#  endif
#endif

#  Settings for emigen
BB_FOLDER_PATH    = $(strip $(FIXPATH))\custom\system\$(strip $(BOARD_VER))
FLASH_OPTIONS_HDR = $(strip $(FIXPATH))\custom\system\$(strip $(BOARD_VER))\flash_opt.h
CUSTOM_EMI_H      = $(strip $(FIXPATH))\custom\system\$(strip $(BOARD_VER))\custom_EMI.h
CUSTOM_EMI_RELEASE_H = $(strip $(FIXPATH))\custom\system\$(strip $(BOARD_VER))\custom_EMI_release.h
CUSTOM_EMI_C      = $(strip $(FIXPATH))\custom\system\$(strip $(BOARD_VER))\custom_EMI.c
CUSTOM_FLASH_C    = $(strip $(FIXPATH))\custom\system\$(strip $(BOARD_VER))\custom_flash.c
CUSTOM_FLASH_NORFDM5_C = $(strip $(FIXPATH))\custom\system\$(strip $(BOARD_VER))\custom_flash_norfdm5.c
MEMORY_DEVICE_HDR = $(strip $(FIXPATH))\custom\system\$(strip $(BOARD_VER))\custom_MemoryDevice.h
ifeq ($(strip $(PLATFORM)),MT6252)
    EMI_GENERATOR     = $(strip $(FIXPATH))\tools\emiGenV7.pl
else
    EMI_GENERATOR     = $(strip $(FIXPATH))\tools\emiGenV6.pl
endif

FLASHFILE = $(strip $(FIXPATH))\~flash_cfg_tmp.c
MEMORY_CFG = $(strip $(CUSTOM_EMI_H))

KEYFILE_PATH = tools\sw_binding_key.ini

# Settings for MSC
NETSIM       = $(strip $(FIXPATH))\MoDIS_VC9\NetSim\NetSim.exe
MSCWORKSPACE = $(strip $(FIXPATH))\mtk_tools\AutoTest\MSC_TestCase\target.msc
CUSTMENUTREE = $(strip $(FIXPATH))\$(strip $(MMIDIR))\Customer\CustResource\CustMenuTree_Out.c

#ifdef NAND_FLASH_BOOTING
#  ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
#    ifneq (,$(filter $(strip $(PLATFORM)), $(strip $(NAND_FLASH_BOOTING_SUPPORT_PLATFORM))))
#      FLASHFILE := $(strip $(MEMORY_DEVICE_HDR))
#      MEMORY_CFG := $(strip $(CUSTOM_EMI_H))
#    endif
#  endif
#endif

# Determine if BOOTLOADER built required

  NEED_BUILD_BOOTLOADER = FALSE

ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
  NEED_BUILD_BOOTLOADER = TRUE
  BOOTLOADER_CHE = ON
else
  ifdef USB_DOWNLOAD
    ifneq ($(strip $(USB_DOWNLOAD)),NONE)
      NEED_BUILD_BOOTLOADER = TRUE
      BOOTLOADER_CHE = ON
    endif
  endif
  ifdef FOTA_ENABLE
    ifeq ($(strip $(FOTA_ENABLE)),FOTA_DM)
      NEED_BUILD_BOOTLOADER = TRUE
      BOOTLOADER_CHE = ON
    endif
  endif

  ifdef SECURE_SUPPORT
    ifeq ($(strip $(SECURE_SUPPORT)),TRUE)
      BOOTLOADER_SUPPORT_SECURE_NOR_PLATFORM = MT6253 MT6253E MT6253L MT6236% MT6252 MT6252H
      ifneq ($(filter $(strip $(BOOTLOADER_SUPPORT_SECURE_NOR_PLATFORM)),$(strip $(PLATFORM))),)
        NEED_BUILD_BOOTLOADER = TRUE
        BOOTLOADER_CHE = ON
      endif
    endif
  endif

  BOOTLOADER_SUPPORT_NOR_PLATFORM = MT6235% MT6236% MT6238 MT6239 MT6225 MT6253
  ifneq ($(filter $(strip $(BOOTLOADER_SUPPORT_NOR_PLATFORM)),$(strip $(PLATFORM))),)
    NEED_BUILD_BOOTLOADER = TRUE
    BOOTLOADER_CHE = ON
  endif
endif

ifneq ($(strip $(CARD_DOWNLOAD)),NONE)
  NEED_BUILD_BOOTLOADER = TRUE
  BOOTLOADER_CHE = ON
endif

ifeq ($(strip $(PLATFORM)),MT6268T)
  NEED_BUILD_BOOTLOADER = TRUE
  BOOTLOADER_CHE = ON
endif

ifeq ($(strip $(PLATFORM)),MT6268H)
  NEED_BUILD_BOOTLOADER = TRUE
  BOOTLOADER_CHE = ON
endif

ifeq ($(strip $(PLATFORM)),MT6268A)
  NEED_BUILD_BOOTLOADER = TRUE
  BOOTLOADER_CHE = ON
endif

ifeq ($(strip $(NEED_BUILD_BOOTLOADER)),TRUE)
  CUS_REL_SRC_COMP += bootloader
  CUS_REL_BASE_COMP += bootloader make\bootloader
  CUS_REL_FILES_LIST += $(strip $(BL_SCATTERFILE))
else
  ifeq ($(strip $(SW_BINDING_SUPPORT)),BIND_TO_CHIP)
    $(warning ERROR: SW_BINDING_SUPPORT cannot be BIND_TO_CHIP when BOOTLOADER is not needed.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(call Upper,$(LEVEL))),VENDOR)
include make\REL_CR_VENDOR.mak
endif

ifdef RELEASE_TYPE 
ifeq ($(call Upper ,$(strip $(RELEASE_TYPE))),INTERNAL)
include make\INT_PKG.mak
endif
endif

# Define 8-bit encryption platform for update_img.exe
8_BIT_ENCRYPTION_PLATFORM = MT6268 MT6516 MT6253 MT6253E MT6253L MT6236 MT6252 MT6252H

#########################################################
# Replace alias modules. (for build flow)
#########################################################
include make\ALIAS.mak
ifdef COMPLIST
COMPLIST_TEMP = $(foreach mod,$(call Upper,$(COMPLIST)), \
  $(if $(filter $($(mod)),TRUE),$($(mod)_CHILD),$(call lc,$(mod))))
endif
COMPLIST := $(strip $(COMPLIST_TEMP))
#########################################################
# End of replacing alias modules.
#########################################################

#########################################################
# Replace alias modules. (for custom release flow)
#########################################################
ifdef CUS_REL_SRC_COMP
CUS_REL_SRC_COMP_TEMP = $(foreach mod,$(call Upper,$(CUS_REL_SRC_COMP)), \
  $(if $(filter $($(mod)),TRUE),$($(mod)_CHILD),$(call lc,$(mod))))
endif
CUS_REL_SRC_COMP := $(CUS_REL_SRC_COMP_TEMP)

ifdef CUS_REL_PAR_SRC_COMP
CUS_REL_PAR_SRC_COMP_TEMP = $(foreach mod,$(call Upper,$(CUS_REL_PAR_SRC_COMP)), \
  $(if $(filter $($(mod)),TRUE),$($(mod)_CHILD),$(call lc,$(mod))))
endif
CUS_REL_PAR_SRC_COMP := $(CUS_REL_PAR_SRC_COMP_TEMP)

ifdef CUS_REL_MTK_COMP
CUS_REL_MTK_COMP_TEMP = $(foreach mod,$(call Upper,$(CUS_REL_MTK_COMP)), \
  $(if $(filter $($(mod)),TRUE),$($(mod)_CHILD),$(call lc,$(mod))))
endif
CUS_REL_MTK_COMP := $(CUS_REL_MTK_COMP_TEMP)

#########################################################
# End of replacing alias modules.
#########################################################

CLEANROOM_COMP = j2me_11 j2me_hi sb51 sbpki2 sslplus5 bsci wndrv supc
# consistency check for COMPLIST & CUS_REL_XXX_COMP
# check each comp in $(COMPLIST) if it has been put in $(CUS_REL_XXX_COMP)
COMPLIST_NO_REL_TYPE_COMP = $(filter-out $(CUS_REL_SRC_COMP) $(CUS_REL_PAR_SRC_COMP) $(CUS_REL_HDR_COMP) $(CUS_REL_MTK_COMP),$(COMPLIST))
COMPLIST_NO_REL_TYPE_COMP := $(filter-out $(CLEANROOM_COMP),$(COMPLIST_NO_REL_TYPE_COMP))
ifneq ($(words $(COMPLIST_NO_REL_TYPE_COMP)),0)
  $(warning ERROR: $(foreach comp,$(COMPLIST_NO_REL_TYPE_COMP),"$(comp)") in COMPLIST but NOT in CUS_REL_XXX_COMP)
  DEPENDENCY_CONFLICT = TRUE
endif

# check each comp in $(CUS_REL_XXX_COMP) if it has been put in $(COMPLIST)
CREL_COMP_NOT_COMPLIST = $(filter-out $(COMPLIST),$(CUS_REL_SRC_COMP) $(CUS_REL_PAR_SRC_COMP) $(CUS_REL_HDR_COMP) $(CUS_REL_MTK_COMP))
CREL_COMP_NOT_COMPLIST := $(filter-out bootloader,$(CREL_COMP_NOT_COMPLIST))
CREL_COMP_NOT_COMPLIST := $(filter-out fota,$(CREL_COMP_NOT_COMPLIST))
ifneq ($(words $(CREL_COMP_NOT_COMPLIST)),0)
  $(warning ERROR: $(foreach comp,$(CREL_COMP_NOT_COMPLIST),"$(comp)") in CUS_REL_XXX_COMP but NOT in COMPLIST)
  DEPENDENCY_CONFLICT = TRUE
endif


# COMPLIST(during CUSTOM_RELEASE)      = CUS_REL_SRC_COMP + CUS_REL_PAR_SRC_COMP
ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
  COMPLIST =     $(strip $(CUS_REL_SRC_COMP))
  COMPLIST +=    $(strip $(CUS_REL_PAR_SRC_COMP))
  COMPLIST := $(filter-out bootloader,$(COMPLIST))
  COMPLIST := $(filter-out fota,$(COMPLIST))

  ifeq ($(strip $(call Upper,$(PROJECT))),GSM)
    ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
      COMPLIST :=  	$(filter-out plutommi,$(COMPLIST))
      COMPLIST :=  	$(filter-out mmiresource,$(COMPLIST))
      COMPLIST :=  	$(subst lc ,lcmmiresource ,$(COMPLIST))
      COMPLIST :=  	$(filter-out mtkapp,$(COMPLIST))
      COMPLIST :=  	$(subst lc ,lcmtkapp ,$(COMPLIST))
    else
      ifeq ($(strip $(MMI_VERSION)),NEPTUNE_COLOR_MMI)
        COMPLIST :=  	$(filter-out plutommi,$(COMPLIST))
        COMPLIST :=  	$(filter-out mmiresource,$(COMPLIST))
        COMPLIST :=  	$(subst lc ,lcmmiresource ,$(COMPLIST))
        COMPLIST :=  	$(filter-out mtkapp,$(COMPLIST))
        COMPLIST :=  	$(subst lc ,lcmtkapp ,$(COMPLIST))
      else
        COMPLIST :=  	$(filter-out lcmmi,$(COMPLIST))
        COMPLIST :=  	$(filter-out lcmmiresource,$(COMPLIST))
        COMPLIST :=  	$(filter-out lcmtkapp,$(COMPLIST))
      endif
    endif
  endif
endif

ifneq ($(call Upper,$(strip $(LEVEL))),VENDOR)
ifdef OPTR_SPEC
ifneq ($(strip $(MTK_SUBSIDIARY)),TRUE)
ifneq ($(strip $(OPTR_SPEC)),NONE)
CUS_REL_BASE_COMP += operator\$(strip $(word 1,$(subst _, ,$(OPTR_SPEC)))\$(word 2,$(subst _, ,$(OPTR_SPEC))))\$(strip $(MMIDIR))
CUS_REL_BASE_COMP += operator\$(strip $(word 1,$(subst _, ,$(OPTR_SPEC))))\common
THE_OP_CUSTOM_LIS = $(OPTR_PATH)\op_custom.lis
OPTR_MMI = operator\$(strip $(word 1,$(subst _, ,$(OPTR_SPEC)))\$(word 2,$(subst _, ,$(OPTR_SPEC))))\$(strip $(MMIDIR))
endif
else
CUS_REL_BASE_COMP += operator
THE_OP_CUSTOM_LIS = $(OPTR_PATH)\op_custom.lis
OPTR_MMI = operator\$(strip $(word 1,$(subst _, ,$(OPTR_SPEC)))\$(word 2,$(subst _, ,$(OPTR_SPEC))))\$(strip $(MMIDIR))
endif
endif
endif

ifneq ($(filter __ACL_SUPPORT__,$(COM_DEFS)),) 
    ifeq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
        $(warning ERROR:  __ACL_SUPPORT__ cannot be defined if __PS_SERVICE__ not defined)
        DEPENDENCY_CONFLICT = TRUE
    endif
endif

ifdef DEPENDENCY_CONFLICT
  ifeq ($(strip $(DEPENDENCY_CONFLICT)),TRUE)
    $(error PLEASE check above dependency errors!)
  endif
endif

ifdef LAMP_SUPPORT
ifneq ($(strip $(LAMP_SUPPORT)), NONE)
ifeq ($(strip $(LAMP_SUPPORT)), SW)
    COM_DEFS    += LAMP_SW
endif
endif
endif

ifdef RYTENSOR
ifeq ($(strip $(RYTENSOR)), TRUE)
    COM_DEFS    += __RYTENSOR__
endif
endif

ifdef DUAL_CAMERA
ifeq ($(strip $(DUAL_CAMERA)), TRUE)
    COM_DEFS    += DUAL_CAMERA
endif
endif

#
#xp define
#**************************************************************************
#°Ý»áÄÖÖÓ
ifeq ($(strip $(AZAN_ALARM)), TRUE)
	COM_DEFS	+= __AZAN_ALARM__
endif

#end xp

##
## HOME SAFE
##
WS_HOME_SAFE = TRUE
WS_HOME_SAFE_VER = VDO_VER   #Â¼Ïñ°æ±¾VDO_VER
                             #ÓïÒô°æ±¾ADO_VER
                             #ÓïÒôºÍÂ¼Ïñ¶¼¿ªÆô ADO_VDO_VER
													
ifeq ($(strip $(WS_HOME_SAFE)),TRUE)
  COM_DEFS += __WS_HOME_SAFE__ __MSGCMD_SUPPORT__
  CUS_REL_SRC_COMP	+= homesafe
  CUSTOM_COMMINC	+= homesafe\inc
  COMPLIST          += homesafe
endif
ifeq ($(strip $(WS_HOME_SAFE_VER)),ADO_VER)
  COM_DEFS += __ADO_VER__ 
endif
ifeq ($(strip $(WS_HOME_SAFE_VER)),VDO_VER)
  COM_DEFS += __VDO_VER__  __MSGCMD_DTMF__ __MSGCMD_DTMF_OLD_VERSION__ __VDORECD_VERSION_FEATRUE__ __ADO_VER__
endif
ifeq ($(strip $(WS_HOME_SAFE_VER)),ADO_VDO_VER)
  COM_DEFS += __ADO_VER__ __VDO_VER__ __MSGCMD_DTMF__ __MSGCMD_DTMF_OLD_VERSION__ __VDORECD_VERSION_FEATRUE__
endif