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
#
#
# *************************************************************************
#
#        MediaTek Inc GSM/GPRS Wireless Communicatin Project
#              Build/Make Development Tools
#
#                 Copyright (C) 2002
#
#        Author         Date        Description
#        Rex Luo  2002/06/07     Create version 1.0
#
# *************************************************************************
#  MTK_GPRS.BLD  - Build option script
#
#  DISCUSSION:
#  USAGE:
#  IMPORTANT NOTES:
# *************************************************************************
#
#  Copyright Statement:
#  --------------------
#     This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2002
#
# *************************************************************************



# *************************************************************************
# Feature Options (TRUE or FALSE)
# *************************************************************************

COMPILER          =  RVCT       # RVCT or ADS
                               # ADS : ADS v1.2 , standard release
                               # RVCT : RVCT v3.1 , MediaTek internal use


RVCT_VERSION      =  V31      # NONE, V22, V31

MODIS_ON_VC9      =  TRUE     # TRUE, FALSE

RVCT_MULTI_FILE   =  NONE      # NONE for ADS compiler
                               # NONE or MULTI_FILE for RVCT compiler

RTOS              =  NUCLEUS   # NUCLEUS or THREADX

L1_CATCHER        =  TRUE        # L1 Catcher Support

MTK_SLEEP_ENABLE  =  TRUE       # Sleep Mode Support


RTOS_DEBUG        =  TRUE        # RTOS Debug Support

RF_MODULE         =  MT6252RF_CUSTOM      # BRIGHT2, BRIGHT4, MT6119, AERO, FOUNTAIN, FOUNTAIN2, SPRING, KLM2003_FOUNTAIN2, KLM2003_SPRING,MT6253ELRF 
                                 # CHICAGO2003_FOUNTAIN2, CHICAGO2003_AERO, CANNON_FOUNTAIN2, MT6129D, AERO1PLUS

L1_GPRS           =  TRUE        # L1 GPRS Funtion, Notice: MT6205 don t support that

L1_EGPRS          =  FALSE        #

L1_EPSK_TX        =  FALSE        # EDGE TX

MTK_DSP_DEBUG     =  FALSE       # DSP Debugging Feature

CSD_SUPPORT       =  NONE       # CSD Feature

PMIC              =  MT6252PMU  # Charge Function, NONE, MT6305 or MT6318

PLATFORM          =  MT6252      # Hardware Platform, MT6208, FPGA, MT6218, MT6218B, MT6219, MT6226, MT6227, MT6228, MT6229, MT6225 ...etc.

CHIP_VER          =  S01         # Chip version code of Platform MT6218B, SHOULD BE ONE OF THE FOLLOWINGS
                                 # BN, CN, DN, EN, FN
                                 # S00 for MT6228

CHIP_VERSION_CHECK    = TRUE       #  TRUE, FALSE
                                   # TURE: enable HW ID check
                                   # FALSE: disable HW ID check
                                   
MCUROM_SUPPORT    =  FALSE       # Only works for MT6226 and MT6227

SW_BINDING_SUPPORT = NONE                # NONE, BIND_TO_CHIP_BASIC, BIND_TO_CHIP
                           # NONE, No SW binding support
                           # BIND_TO_CHIP_BASIC, Support SW binding to chip. FOTA is not supported. Same as original sw protection solution
                           # BIND_TO_CHIP, Support SW binding to chip. Support FOTA
                             
RES_PROT = FALSE  # TRUE, FALSE
                                 # For MT6226M, MT6226-9. FALSE for basic/evb/l1s

BOARD_VER         =  NEOTEL52_6432_10A_BB # Baseband main board description, SHOULD BE ONE OF THE FOLLOWINGS
                                 # MT6208_EVB, MT6208_CEVB, MT6205_CEVB, ORDNANCE, KLM2003_BB, CHICAGO2003_BB,
                                 # MT6218_MW001, CANNON, MT6218B_EVB, JUPITER_EVB, MT6219_EVB,
                                 # MT6226_EVB, MT6227_EVB, MT6228_EVB, MT6229_EVB, MT6225_EVB

SUB_BOARD_VER     =  PCB01       # MT6218_MW001 Baseband main board subversion, SHOULD BE ONE OF THE FOLLOWINGS
                                 # PCB01

LCD_MODULE        =  NEOTEL52_6432_10A_LCM  # Based on the LCM solutions (even multiple LCM modules for this project)
                                  # SHOULD BE ONE OF THE FOLLOWINGS, based on the LCM
                                  # MTKLCM				-	Mono, 	102x64
                                  # MTKLCM_COLOR		-	Color, 	120x160, for MT6218_MW001 or MT6205_CEVB
                                  # ORDNANCELCM		-	Mono, 	112x64
                                  # KLMLCM				-	Color,	128x128
                                  # INFOLCM			-	Color,	128x128
                                  # TOPPOLY_LCM     -  Color,   128x160, for MT6218B_EVB
                                  # SONY_LCM        -  Color,   176x220, for JUPITER_EVB

MCU_CLOCK			=	MCU_104M		# MCU clock setting, MCU_13M, MCU_26M, MCU_39M, MCU_52M, MCU_104M

MCU_DCM           =  DCM_ENABLE   # Dynamic Clock Management, switch MCU clock in idle task
                                  # Dynamic Clock Management
                                  # Available BB chip: MT6217, MT6226, MT6226M, MT6227, MT6228, MT6229...etc.

EXT_CLOCK			=	EXT_26M		# External clock source setting, EXT_13M, EXT_26M

CUSTOM_CFLAGS = #--debug --no_debug_macros         # custom flag

MMI_BASE  =  PLUTO_MMI    # PLUTO_MMI, NEPTUNE_MMI

MMI_VERSION 		= 	PLUTO_MMI  	# FCB_MMI, PLUTO_MMI, BW_MMI, EMPTY_MMI, CHICAGO_MMI, KLM_MMI


EMPTY_RESOURCE    =  TRUE       #
	
MMI_FEATURES_SWITCH = FALSE       # TRUE or FALSE   It s for the internal usage only.

SPLIT_SYSTEM      =  FALSE       # Split system feature

MCD_SUPPORT       =  TRUE       # MCD support feature

MCD_CODESET_SHIFT_SUPPORT = NONE  # NONE, 440000

TST_SUPPORT			=	TRUE          # TST task Support

TST_SET_LOG_BUF_SIZ = NONE  # NONE: Use the default setting
                            # Or, it could be in the range of 13 ~ 23: the power size of the logging buffer.
                            # If the number is 13, the logging buffer size is (2^13) == 8KByte
                            # If the number is 23, the logging buffer size is (2^23) == 8MByte                              

TST_WRITE_TO_FILE  =  FALSE

TCPIP_SUPPORT     =  UDP_TCP    # UDP_TCP, UDP, TCP, or NONE

TCPIP_LOOP_SUPPORT  = FALSE   # TRUE, FALSE

OBIGO_FEATURE    =  WAP2         # WAP, WAP2, WAP_SEC, WAP2_SEC, NONE

IRDA_SUPPORT      =  FALSE       # IRDA support feature

INPUT_METHOD = MMI_CSTAR_V2_DEMO #MMI_CSTAR_V2_DEMO	 # Input methods: NONE, MMI_T9, MMI_ZI, MMI_T9_V7_4

HAND_WRITING 		= 	NONE      # NONE, MMI_HANWANG, MMI_PENPOWER, MMI_PENPOWER_DEMO, MMI_HANWANG_DEMO, MMI_DECUMA, MMI_DECUMA_DEMO

DICT_SUPPORT		=	NONE        # NONE, MMI_MOTECH

NVRAM_SUPPORT     =  TRUE       # NVRAM Support

AFC_VCXO_TYPE     = VCXO		    # VCTCXO     : VCTCXO
                                # VCXO       : VCXO
                                # VCXO_SC    : VCXO with 7 area slope control
                                # VCXO_TC    : VCXO with temperature compensation
                                # VCXO_SC_TC : VCXO with 7 area slope control & temperature compensation




HORIZONTAL_CAMERA = FALSE       # FALSE, TRUE
                                # To enable horizontal camera feature. 
                                # Add HORIZONTAL_CAMERA to global compile option when the value is TRUE.


MELODY_VER	     = 	DSP_WT_SYN   # NONE, DSP_WT_SYN

WAVETABLE_VER     = WT20K      # Wavetable version, Please choose one among:
                                   #  WT600K, WT300K, WT150K, WT100K, WT70K, WT20K, WT100K_ROM, WT_ROM_V1, and WT_ROM_V2 for DSP_WT_SYN


DEDI_AMR_REC      =  FALSE      # AMR recording in GSM traffic mode. This function requires more than 50%MCU computing power.
                               # For running smoothly, the system needs to be equipped with good flash/SRAM that have short
                               # access time and page mode been enabled.

VR_ENGINE         =   NONE       #  NONE, VRSI_CYBERON


VRSI_LANGUAGE     =  NONE     # VRSI language, 
                              # CYBERON_TWBI, CYBERON_CNBI, NONE


BAND_SUPPORT	    = QUAD     # support of designated band: PGSM900, EGSM900, RGSM900, DCS1800, PCS1900, GSM850, GSM450, GSM480, DUAL900, TRIPLE, QUAD, DUAL850
 
MSDC_CARD_SUPPORT_TYPE = MSDC_SD_MMC      #  MSDC_SD_MMC      for SD/MMC card support
                                          #  MSDC_MS 	      for MS card support
                                          #  MSDC_MSPRO       for MS-PRO card support
                                          #  NONE
                                          #  MT6218B, MT6217, MT6219 support MSDC
                                          #  MT6218, MT6205B, MT6208 don t support MSDC

QN_IC_SUPPORT     = NONE # NONE ///zfq 
ANALOG_TV_CHIP    = NONE # NONE QN8610 ///zfq
FM_RADIO_CHIP     = NONE # NONE, MT6189A1, MT6188A1, AR1000 //zfq
#FM_RADIO_CHIP     = RDA_BTFM       # NONE, MT6189A1, MT6188A1, AR1000

FM_RADIO_RECORD = FALSE     #TRUE/FALSE


NAND_SUPPORT     =  FALSE      # NAND SUPPORT

SYSTEM_DRIVE_ON_NAND = FALSE   # FALSE : System Drive on NOR flash
                 	                              # TRUE : System Drive on NAND flash

APP_STORAGE_IN_SYS_DRV = FALSE   # To put Email and MMS message to NOR or NAND flash

USB_SUPPORT      =  TRUE       # MT6218B and MT6219 chip support USB

USB_COMPORT_PC_DRIVER_SUPPORT = MS  # TC01, MS

USB_MULTIPLE_COMPORT_ENABLE = FALSE  # TRUE/FALSE. To enable USB multiple com port feature

USB_HS_SUPPORT = FALSE  # TRUE, FALSE

USB_COM_PORT_SUPPORT = TRUE  # TRUE, FALSE

USB_MASS_STORAGE_SUPPORT = TRUE  # TRUE, FALSE

USB_IN_NORMAL_MODE_SUPPORT =  TRUE  # TRUE,FALSE
                                     # To enable USB mass storage support in normal mode

USB_DOWNLOAD         = NONE     # Support USB Download in bootloader or not. 
                                # To enable Factory Download/Connection via USB cable

SSS_SUPPORT      = SSS_LIB     # SSS_LIB, SSS_SOURCE

TTL_SUPPORT = LIB  # LIB


OTG_SUPPORT      = FALSE       #  TRUE, FALSE

                               #  To enable OTG suuport  feature

J2ME_SUPPORT       = NONE   # NONE, IJET, JBLENDIA, JBED, MTK_DUMMYVM

J2ME_VM			       = NONE   # J2ME VM:  NONE, KVM, KVM_SOURCE, HI_VM, HI_VM_SOURCE, JAZELLE, KVM_KDWP, KVM_KDWP_SOURCE

J2ME_FEATURE_SET   = NONE	  # J2ME_FEATURE_SET: NONE, BASIC, JTWI

 
           
J2ME_SHARE_MED_EXT_MEM = FALSE    # TRUE, FALSE

SUPPORT_JAVA_NOKIA_UI = FALSE  # TRUE, FALSE

SUPPORT_JSR_75_PIM  = FALSE

SUPPORT_JSR_75_PIM_MSA = FALSE

SUPPORT_JSR_179 = FALSE # TRUE, FALSE
					
SUPPORT_JSR_184     = FALSE

SUPPORT_JSR_205     = FALSE

SUPPORT_JSR_82 = FALSE  # TRUE, FALSE

SUPPORT_BACKGROUND_JAVA = FALSE  # TRUE, FALSE

J2ME_SLIM_MEMORY_SUPPORT = FALSE  # TRUE, FALSE


 
J2ME_SLIM_SCREEN_MEMORY_SUPPORT = FALSE    # TRUE, FALSE

DRM_SUPPORT = NONE #DRM VENDOR: NONE, MTK, BSCI

DRM_VERSION = NONE # DRM VERSION: NONE, V01, V02, ALL

AMRWB_LINK_SUPPORT = FALSE    # TRUE, FALSE

AMRWB_DECODE 		= FALSE    # TRUE/FALSE

AMRWB_ENCODE 		= FALSE    # TRUE/FALSE
                           # MT6219 DSP cannot support AMRWB_ENCODE when GPRS connection

JPG_DECODE 			= JPG_SW   # NONE, JPG_SW

JPG_ENCODE 			= JPG_SW   # NONE, JPG_SW


GIF_DECODE = GIF_SW    # NONE, GIF_HW, GIF_SW

PNG_DECODE 	      = NONE    #  (NONE, PNG_HW, PNG_SW)

MUSICAM_DECODE  = FALSE   # TRUE, FALSE

DAF_DECODE 			= TRUE    # TRUE/FALSE

MJPG_DECODE = TRUE  # TRUE/FALSE

MJPG_ENCODE = TRUE  # TRUE/FALSE

MP4_DECODE = TRUE    # FALSE, TRUE


MP4_ENCODE = FALSE    # FALSE, TRUE

AAC_DECODE      = TRUE    # TRUE/FALSE

M4A_DECODE = FALSE   # TRUE or FALSE

ISP_SUPPORT     = TRUE    # TRUE/FALSE

CMOS_SENSOR     = GC0309  # OV7670, OV9640, PAS105, PAS302, NONE, MT9D011, MT9M111, OV9650, OV7670

SENSOR_ROTATE           = SENSOR_ROTATE_0    # SENSOR_ROTATE_0, SENSOR_ROTATE_90, SENSOR_ROTATE_180, SENSOR_ROTATE_270

SENSOR_SUB_ROTATE = SENSOR_ROTATE_0    # SENSOR_ROTATE_0 : sub camera not rotate
                                       # SENSOR_ROTATE_180: sub camera rotate 180 degree

SENSOR_LOCATION = SENSOR_ON_BODY    # SENSOR_ON_BODY, SENSOR_ON_CLAM, SENSOR_INSIDE_CLAM


PHB_SIM_ENTRY	=	200	# Phonebook Entry Number in SIM: 100, 200

PHB_PHONE_ENTRY	=	200	# Phonebook Entry Number in NVRAM: 100, 200

PHB_LN_ENTRY	       =	20	# Last Number Entry Number: 10, 20, 50

PHB_FDN_ENTRY = 32    # 32, 50

EMAIL_SUPPORT           =  NONE   # NONE or  SMTP_POP3 or ALL

FS_SORT_SUPPORT		=  TRUE	  # Both file system and file manager will support sort function

FS_MOVE_SUPPORT		=  TRUE	  # Both file system and file manager will support move/copy function

FS_QM_SUPPORT		=  TRUE	  # File system will support quota management mechanism

FS_TRACE_SUPPORT	=  FALSE  # File system trace feature. 

FS_CHECKDRIVE_SUPPORT	= FALSE	  # Both file system and file manager will support check drive function
                                # Drive more than 128MB should turn off this feature.

AEC_ENABLE              =  TRUE  # Acoustic Echo Cancellation (AEC)
                                  # TRUE, FALSE

EES_ENABLE              =  TRUE  # Enhanced Echo Suppression (EES)
                                  # TRUE, FALSE

 

BLUETOOTH_SUPPORT       = NONE   # NONE, BTMTK, BTMTK_MT6601, BTMTK_MT6611, BTMTK_MT6612, BTMTK_MT6236, BTMTK_MT6616

BLUETOOTH_VERSION       = NONE    # NONE, BT_VER_PRE21, BT_VER_21, BT_VER_30

BLUETOOTH_DRIVER		  = NONE  # NONE, RDA


CMUX_SUPPORT	        = FALSE   #

DIGIT_TONE_SUPPORT      = FALSE   # TRUE or FALSE

TTS                     = NONE    # SIMPLE_TTS, CYBERON_DIC_TTS or IFLY_TTS or SINOVOICE_TTS or NONE
					
CUST_KEYPAD_TONE_SUPPORT = FALSE  # TRUE or FALSE

MED_PROFILE             = MED_HIGH  # MED_LOW, MED_NORMAL, MED_HIGH, MED_MODEM

XML_SUPPORT             = TRUE    # TRUE or FALSE

AMR_LINK_SUPPORT        = TRUE    # TRUE or FALSE

IMPS_SUPPORT            =  FALSE  # TRUE or FALSE, IMPS Feature Support

FINGER_TOUCH_SUPPORT    = NONE   #  NONE, FTE

TOUCH_PANEL_SUPPORT = NONE    # NONE, MT6301, MT6301B, TP_INTERNAL, CTP_IT_7250, CTP_CYPRESS_TMA340

DEMO_PROJECT		= FALSE # TRUE, FALSE. TRUE for internal demo project.

GPRS_MAX_PDP_SUPPORT    = 2      # 2, 3, 4, 5, 6 or 7  Maximum simultaneous PDP contexts (2~7)

BT_CONNECT_TO_UART2   = FALSE      # TRUE, FALSE
                                   # TRUE: BT module is connected to UART2
                                   # FALSE: BT module is connected to UART3, this is general case for most projects

UART3_SUPPORT		= TRUE   # TRUE or FALSE,  SUPPORT UART 3

DMA_UART_VIRTUAL_FIFO   = TRUE   # TRUE or FALSE

DMA_UART_VFIFO_TUNNEL_SUPPORT = FALSE  # TRUE, FALSE

SIP_SUPPORT 	        = FALSE        # TRUE or FALSE

SDP_SUPPORT 	        = FALSE        # TRUE or FALSE


XDM_SUPPORT             = FALSE      # TRUE or FALSE

VOIP_SUPPORT            = FALSE     # TRUE, FALSE

PHONE_TYPE 		=  BAR      # BAR, CLAMSHELL, SLIDE  
                           #  Default is BAR

SWDBG_SUPPORT        = FALSE     # MT6228 support software debug 

NAND_FLASH_BOOTING   = NONE        # NONE, ENFB, ONDEMAND, MIXED, BASIC
                                   # NONE: NORXIP Project and it s not NAND FLASH BOOTING
                                   # ENFB: MMI Images and string put on THIRD_ROM and dynmaic load into RAM by application. Default for MT6228/29/30
                                   # ONDEMAND: MMI Resource and Some Non-Real-Time App RO put on NAND and on-demand page in. 
                                   #           ARM9 MMU Required. Default for MT6235/38
                                   # MIXED: Both ENFB and On-Demand Page In mechanism enabled. ARM9 MMU Required. Pick this to support MBA Feature.
                                   # BASIC: Nand Flash Booting is turned on, but none of ENFB and ONDEMAND exists. Only ROM and SECONDARY_ROM.

SW_FLASH            = NONE    # NONE 

WMA_DECODE = FALSE              # MT6228 support WMA DECODE

LOW_COST_SUPPORT = COMMON  # NONE, COMMON, ULC
                         #  Please not that a module can define its own low-cost levels, or it can just adopt this compile option.


SUB_LCD_SIZE = NONE # NONE, 48X64BW, 64X96, 96X64BW, 96X64, 128X128

MAIN_LCD_SIZE = 240X320 #240X320                              # To distinguish the main lcd size. 
                                                                        # We can use it to copy the matching resources, such themecomponents.h, Fontres.c, L_xxx.h, etc, to PLUTO_MMI folder




SUBLCD_DEDICATED_KEYS_SUPPORT = FALSE     # TRUE/FALSE
                                          # FALSE: No dedicated keys for subLCD operation
                                          # TRUE:  Have dedicated keys for subLCD when clam close, 
                                          # ex. KEY_MP3_PLAY_STOP, KEY_MP3_FWD, KEY_MP3_BACK


ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT = TRUE # Support FS access for single bank NOR flash or 
                                               # For single-bank NOR-flash solution without shadowed NVRAM requirement.

AAC_PLUS_DECODE  =  FALSE		# TRUE/FALSE

EMS_SUPPORT          = EMS_NONE   # EMS_40 support only EMS 4.0
                                # EMS_50 support EMS 5.0 
                                # EMS_NONE support only pure text content.

WEBCAM_SUPPORT       = FALSE      # TRUE, FALSE for WEB CAMERA support 

R4_SUPPORT      = FALSE   # Release 4 support

R5_SUPPORT      = FALSE   # Release 5 support

R99_SUPPORT	    = TRUE	  # Release 99 support

EDGE_SUPPORT	= FALSE	  # EDGE support

CHE_SUPPORT          = FALSE    # CHE support

TV_OUT_SUPPORT 		= FALSE       # TRUE, FALSE  only MT6228 and MT6229 support TV OUT

BACKGROUND_SOUND	   = FALSE	  # TRUE/FALSE

AU_DECODE             = FALSE       #  TRUE, FALSE

AIFF_DECODE           = FALSE       #  TRUE, FALSE

JTONE_SUPPORT         = FALSE       #  TRUE, FALSE

BES_SURROUND_SUPPORT     = NONE  # NONE, MODE_LSPK, MODE_EARP, MODE_BOTH
                                  # to enable 3D surround

BES_LIVE_SUPPORT    = FALSE	  # TRUE, FALSE

BES_TS_SUPPORT    = FALSE	  # TRUE, FALSE

MOTION_SENSOR_SUPPORT = NONE  # NONE, KXP84_SPI, KXP84_I2C, KXP74_SPI, MXC6202_I2C, MMA7660_I2C, KXTF9_I2C

LENS_MODULE 	     = NONE   # NONE, ABICO_VQ26A10_OV2640_AD5398, ABICO_WZ36A333_OV3640_MD118B, ACME_900_0043_00_OV3640_AD5398, 
                                                  # AOCI_BASAV0422_MT9T012_AD5398, AOCI_BTIAV0486_ET8EE6_MD115, FOXCONN_ATCM_5011_MT9P012_AD5820, 
                                                  # FOXLINK_FM30AF_13_L1_MT9T012_MD115, FOXLINK_FM50AF_04_MT9P012_MD218B, FOXLINK_FO20AF_25_OV2640_MD115, 
                                                  # FOXLINK_M30AF_26_OV3640_MD115, LITEONSEMI_DCM_300MAV_MT9T012_MD115, MCNEX_MC_20A2_05_MT9D011_ID9701, 
                                                  # MCNEX_MC300A_2IC1B0626_MT9T012_ID9701, MCNEX_MC320A_2JC1L0711_MT9T012_AD5398, NANOFOCUS_HSMW2_C04_AM7S_001_MT9D011_ID9700, 
                                                  # NANOFOCUS_NFMW3_C07_AM7M_004_MT9T012_AD5398, NANOFOCUS_NFMW3_S01_AM7M_002_MT9T012_ID9701,
                                                  # SANYO_ED_20MA_NOON200PC11_AD5398, SUNNY_8212E_OV2640_AD5398, YAHSIN_M20P1A_BGK_OV2640_MD115

AF_SUPPORT	     = FALSE         # TRUE or FALSE

DT_SUPPORT           = FALSE      # TRUE, FALSE

CTM_SUPPORT          = FALSE    # TRUE, FALSE 


M3D_MMI_SUPPORT          = FALSE      # TRUE, FALSE

BT_SIM_PROFILE       = FALSE      # TRUE, FALSE

 
BT_BPP_PROFILE       = FALSE      # TRUE, FALSE, 
					
BT_HIDD_PROFILE      = FALSE      # TRUE, FALSE       
                                  # Turn on or turn off bluetooth HID profile feature

BT_HFG_PROFILE       = FALSE      # TRUE, FALSE

BT_FTS_PROFILE       = FALSE      # TRUE, FALSE

BT_FTC_PROFILE       = FALSE      # TRUE, FALSE

BT_OPP_PROFILE       = FALSE      # TRUE, FALSE

BT_DUN_PROFILE       = FALSE      # TRUE, FALSE

BT_SPP_SERVER        = NONE       # NONE, BT_SPP_SRV_NO_SCO or BT_SPP_SRV_WITH_SCO (default:BT_SPP_SRV_NO_SCO)
                                  # This is only used in BLUETOOTH_SUPPORT = BTMTK_MT6601
                                  # If BLUETOOTH_SUPPORT is not BTMTK_MT6601, its value must be NONE

BT_SPP_CLIENT        = NONE       # NONE, BT_SPP_CLI_NO_SCO or BT_SPP_CLI_WITH_SCO (default: NONE)
                                  # This is only used in BLUETOOTH_SUPPORT = BTMTK_MT6601
                                  # If BLUETOOTH_SUPPORT is not BTMTK_MT6601, its value must be NONE

BT_SPP_PROFILE       = FALSE      # TRUE, FALSE

BT_A2DP_PROFILE      = FALSE      # TRUE, FALSE

BT_AVRCP_PROFILE     = FALSE      # TRUE, FALSE 
                                  # Turn on or off AVRCP profile feature

EXIF_SUPPORT         = FALSE      # TRUE, FALSE

LCM_ROTATE_SUPPORT   = FALSE     # TRUE, FALSE

SVG_SUPPORT = NONE  # NONE, MTK_SVG

WIFI_PREFER_SUPPORT = FALSE    # TRUE, FALSE

WIFI_SUPPORT = NONE  # NONE, MT5911, MT5921

 

WNDRV_SUPPORT = LIB

WIFI_ENHANCE_SUPPORT = FALSE   # TRUE or FALSE

WIFI_BT_SINGLE_ANTENNA_SUPPORT = FALSE  # TRUE, FALSE



IPERF_SUPPORT        = NONE  	 #  SINGLE, DUAL, TRIPLE, QUAD, NONE


IPERF_WMM_PS_TEST_SUPPORT = FALSE    # TRUE,FALSE

OPENGL               =  NONE     # COMMON_LITE, NONE
                                 # This compile option is defined for 3D graphics engine.
                                 # Only MT6228 and MT6229 support OPENGL.

USB_MULTI_CHARGE_CURRENT_SUPPORT = FALSE  # TRUE, FALSE 
                                          # Turn On or Off USB multiple charging-current support

RC5_SUPPORT          = TRUE      # TRUE or FALSE, RC5 feature support

GAME_ENGINE          = NONE      # NONE, GE_BROGENT
                                 # to add game engine 


EXT_DAC_SUPPORT      = FALSE     # TRUE, FALSE
                                 # To enable the interface between AFE control and EXT_DAC control.

UNIFIED_MESSAGE_MARK_SEVERAL_FEATURE = FALSE  # TRUE, FALSE

UNIFIED_MESSAGE_SORT_MESSAGE_LIST = FALSE  # TRUE, FALSE

UNIFIED_MESSAGE_FOLDER = TRUE  # TRUE or FALSE, To support unified message folder of multiple message types

UNIFIED_MESSAGE_SIMBOX_SUPPORT  = FALSE   # TRUE, FALSE, 
                                          # only can be turned on if unified message feature is turned on.
					
DRV_CUSTOM_TOOL_SUPPORT  = TRUE # TRUE or FALSE, To enable using driver customization tool for GPIO/EINT/ADC/UEM/Keypad setting.


BROWSER_SUPPORT          = OBIGO_Q03C  # NONE, OBIGO_Q03C, OBIGO_Q05A, OPERA_V10

UNIFIED_PUSH_FEATURES = SLIM  # FULL, STANDARD, SLIM, NONE

WAP_MEM_DEBUG = FALSE    # TRUE, FALSE. Works only for WAP_SUPPORT is OBIGO_Q03C
					
DSPIRDBG             = FALSE     # IRDBG interface for dsp debugging
                                 # only support in 6229 E2 and MT6225
                                 
					
SECURE_SUPPORT      = FALSE       #

IPSEC_SUPPORT = FALSE  # FALSE, IPSEC_IKEv1

SECURE_VERSION      = 1          #

SECURE_JTAG_ENABLE  = FALSE       # Support JTAG or not on secure chip

SECURE_CUSTOM_NAME  = MTK        # MTK (6227C/6225 EVB) or JRD (JRD_06A) 

SECURE_RO_ENABLE    = FALSE       # TRUE, FALSE

DISPLAY_TYPE        = COLOR      # BW, COLOR

OTP_SUPPORT         = FALSE      # TRUE, FALSE

DOWNLOADABLE_THEME =  FALSE      # TRUE, FALSE

DLT_ALWAYS_LOAD_BUFFER_SIZE =  0

DLT_LOAD_ON_DEMAND_BUFFER_SIZE =  0

SYNCML_SUPPORT                   = FALSE        # TRUE or FALSE

SYNCML_DEVICE_SYNC_SUPPORT = FALSE  # TRUE, FALSE

UNIFIED_MESSAGE_ADVANCE_FEATURE  = NONE              	# Unified message advance feture:
                                                      # NONE, COMPOSER, ARCHIVE, COMPOSER_ARCHIVE

STREAM_SUPPORT   =   FALSE   # TRUE or FALSE

PGDL_SUPPORT  =  FALSE          # TRUE or FALSE

RTSP_SUPPORT = FALSE            # TRUE or FALSE

FOTA_ENABLE = NONE   # FOTA_DM, NONE

FOTA_UPDATE_PACKAGE_ON_NAND = FALSE  # TRUE, FALSE

SYNC_LCM_SUPPORT = FALSE         # TRUE or FALSE 
                                 # TRUE if Sync mode LCM is applied and FALSE if Sync mode LCM is applied.
                           
SUBLCD_SYNC_LCM_METHOD = NONE    # NONE, SW, HW

SYNC_LCM_METHOD = BY_CHIP    # BY_CHIP, SW, HW

FEATURE_OVERLOAD = FALSE         # TRUE or FALSE  
                                 # TRUE : turn on bypassing 
                                 # FLASE : turn off bypassing
                         
AAC_PLUS_PS_DECODE = FALSE       # TRUE, FALSE                                                    

VDOEDT_SUPPORT     = FALSE       # TRUE, FALSE    

OPTR_SPEC               = NONE   # NONE, CMCC_0202_SEGA, CMCC_0202_SEGB, CMCC_0202_SEGC, CMCC_0202_SEGA_TECH, CMCC_0202_SEGB_TECH
                                 # CMCC_0202_SEGC_TECH, ORANGE_0605_CAM240, ORANGE_0800_MEDIAENTRY, VODAFONE_R12_LIVE, CMCC_0203_SEGA
                                 # CMCC_0203_SEGB, CMCC_0203_SEGC, CMCC_0203_SEGD, CMCC_0203_SEGE, CMCC_0203_SEGA_TECH
                                 # CMCC_0203_SEGB_TECH, CMCC_0203_SEGC_TECH, CMCC_0203_SEGD_TECH, CMCC_0203_SEGE_TECH, UNICOM_0100_GENERAL
                                 # CMCC_0204_SEGA, CMCC_0204_SEGB, CMCC_0204_SEGC, CMCC_0204_SEGD, CMCC_0204_SEGE, 
                                 # CMCC_0204_SEGA_TECH, CMCC_0204_SEGB_TECH, CMCC_0204_SEGC_TECH, CMCC_0204_SEGD_TECH, CMCC_0204_SEGE_TECH

SYNCML_DM_SUPPORT = FALSE    # INSIGNIA_DM, FALSE

SYNCML_DM_VERSION = NONE  # NONE, DM11, DM12, DM12_SCTS

DM_MO_SUPPORT       = NONE     # LAW_SCO, LAW, SCO, or NONE

					
SPATIAL_DITHERING       = TRUE   # TRUE or FALSE
                                 # support by MT6225, MT6228, MT6229 and MT6230

PICTBRIDGE_SUPPORT      = FALSE  # TRUE or FALSE, IMPS Feature Support
					
TDMB_SUPPORT            = NONE       # NONE, TELECHIP_TDMB, FRONTIER_TDMB    

WBXML_SUPPORT   = TRUE		# TRUE or FALSE
					
ISO_PRIORITY_MODE_SUPPORT = FALSE   # FALSE, TRUE
					
KEYPAD_TYPE             = EXTEND_QWERTY_KEYPAD  # NORMAL_KEYPAD, REDUCED_KEYPAD, QWERTY_KEYPAD, EXTEND_QWERTY_KEYPAD

FLASHLIGHT_TYPE         = NONE           # NONE, LED_ONOFF_SUPPORT, LED_FLASHLIGHT_SUPPORT, XENON_FLASHLIGHT, XENON_FLASHLIGHT_ANTI_RED_EYE

FLASHLIGHT_MODULE       = NONE     # NONE, IMCR3603_S010AO

UCM_SUPPORT             = TRUE          # TRUE or FALSE
                                         # to enable unified call management feature

TOUCH_PANEL_SHORTCUT_SUPPORT   = FALSE         # FALSE, TRUE
                                               # TRUE for  touch panel size need to be larger than LCD size
                                               # Support touch panel shortcut functionality 




SSL_SUPPORT             = NONE   # NONE, SSL_CIC_LIB, MTK_SSL_CIC

SECLIB_SUPPORT = NONE   # NONE, BASIC, PKI
                       # NONE: disable security library
                       # BASIC: enable security library
                       # PKI: enable OpenSSL library
                          
SOCKET_SSL_SUPPORT = FALSE  # TRUE, FALSE

SYSGEN_ENABLE         = TRUE         # FALSE, TRUE
                                   
BACKGROUND_SMS_SUPPORT = FALSE		     # TRUE or FALSE                                    

PURE_AUDIO_SUPPORT      = FALSE         # TRUE or FALSE 
                                       # Support pure audio 3GP/MP4 file in audio player
 
 
GPS_SUPPORT           = NONE       # NONE, MT3316, MT3326

FAX_SUPPORT           = FALSE       # TRUE, FALSE

FONT_RESOURCE         = DEMO   # DEMO, OFFICIAL

 
BES_EQ_SUPPORT           = TRUE # TRUE, FALSE

AUDIO_COMPENSATION_ENABLE = FALSE # TRUE, FALSE

BSAC_DECODE = FALSE # TRUE, FALSE

INTERNAL_ANTENNAL_SUPPORT = FALSE  # TRUE, FALSE

BT_GPS_SUPPORT = FALSE  # TRUE, FALSE
                        # FALSE:  Don t support the phone connect GPS via bluetooth
                        # TRUE: Support the phone connect GPS via bluetooth

EMLPP_SUPPORT = FALSE  # TRUE, FALSE
                       # TRUE: CC EMLPP  feature is supported
                       # FALSE: CC EMLPP  feature is NOT supported

	
UUS_SUPPORT = FALSE  # TRUE, FALSE
                     # TRUE: CC User-User Service feature is supported
                     # FALSE: CC User-User Service feature is NOT supported

H264_DECODE = FALSE  # TRUE, FALSE

RM_DECODE  = FALSE  # TRUE, FALSE

H264_OPEN_API = FALSE  # TRUE, FALSE


DCD_SUPPORT = NONE    # INFRAWARE, NONE

SENSOR_TYPE = YUV    # RAW, YUV, DIRECT, NONE

FM_RADIO_HW_SEARCH = FALSE    # TRUE, FALSE

BT_FAX_PROFILE = FALSE  # TRUE, FALSE

IC_TEST_TYPE = NONE  # NONE, IC_MODULE_TEST, IC_BURNIN_TEST
                                
RSAT_SUPPORT = NONE  # NONE, MODEM_WITH_RSAT, MMI_WITH_RSAT


CAMCORDER_SUPPORT = NONE  # TRUE or FALSE, only can be turned on in MT6238 series platform

CAMCORDER_SMILE_SHUTTER_MODE_SUPPORT = FALSE  # TRUE, FALSE

AUD_RECORD = TRUE          # TRUE, FALSE : Turn on audio record feature, olny set to FALSE for very low cost project

BT_AUDIO_VIA_SCO = FALSE  # TRUE, FALSE
                                
BT_FM_RADIO_VIA_SCO = FALSE  # TRUE, FALSE
                                
BT_AUTO_DETECT_SUPPORT = FALSE    # TRUE, FALSE

CBM_ALWAYS_ASK_SUPPORT = FALSE  # TRUE or FALSE

CBM_CONNECTION_MANAGER_SUPPORT = FALSE  # TRUE or FALSE

CBM_BEARER_FALLBACK_SUPPORT = FALSE  # TRUE or FALSE


MULTIPLE_BINARY_FILES = FALSE  # FALSE, TRUE

BT_PBAP_PROFILE = FALSE  # TRUE or FALSE

AGPS_SUPPORT = NONE  # NONE, USER_PLANE, CONTROL_PLANE, BOTH

OMA_ULP_SUPPORT = NONE    # NONE, V1

NDIS_SUPPORT = NONE  # NONE, NDIS, UPS

DISABLE_A5_2 = TRUE  # TRUE, FALSE

CAMCORDER_FACE_DETECTION_MODE_SUPPORT = FALSE  # TRUE, FALSE

REDUCE_PLUTO_HEADER_DEPTH = TRUE  # TRUE, FALSE

UNIFIED_MESSAGE_LOW_MEMORY_SUPPORT = FALSE  # TRUE, FALSE

MSG_SMS_EMAIL_SUPPORT = FALSE  # TRUE, FALSE

WAV_CODEC = TRUE  # TRUE, FALSE

AMR_CODEC = TRUE  # TRUE, FALSE

CCBS_SUPPORT = FALSE  # TRUE, FALSE

CNAP_SUPPORT = FALSE  # TRUE, FALSE

TST_LOGACC_SUPPORT = FALSE  # TRUE, FALSE

MODEM_3G_LOGGING = FALSE  # TRUE, FALSE

EXT_MODEM_SUPPORT = FALSE  # TRUE, FALSE

MMS_SUPPORT = OBIGO_Q03C_MMS_V02  # OBIGO_Q05A, OBIGO_Q03C_MMS_V01, OBIGO_Q03C_MMS_V02, NONE

MMS_FEATURES = SLIM  # NONE, SLIM, FULL

SMS_PHONE_ENTRY = 50  # SMS Entry Number in NVRAM: 200

SMS_SIM_ENTRY = 50    # 10~255

SMS_TOTAL_ENTRY = 100  # SMS Entry Number in NVRAM and SIM: 200 (>=SMS_PHONE_ENTRY)
                       # SMS_TOTAL_ENTRY >= SMS_PHONE_ENTRY > 0

LQT_SUPPORT = TRUE  # FALSE, TRUE

BT_SEQ_SUPPORT = FALSE  # FALSE, TRUE

BES_LOUDNESS_SUPPORT = FALSE    # TRUE, FALSE

BES_BASS_SUPPORT = FALSE  # TRUE, FALSE


MSHUTTER_SUPPORT = FALSE  # TRUE, FALSE

PANORAMA_VIEW_SUPPORT = FALSE  # TRUE, FALSE

GPS_HS_SUPPORT = FALSE  # TRUE, FALSE


PMU_WITH_EXTERNL_CHARGER = FALSE  # TRUE, FALSE

A8BOX_SUPPORT = FALSE  # TRUE, FALSE

MELODY_BUFFER_LEN = 20480    # 102400, 307200, 1300, 1024, 512

OTG_DETECT_ID_PIN_WITH_EINT = FALSE  # FALSE, TRUE
                                
SMART_PHONE_CORE = NONE  # NONE: feature phone
                         # MODEM: smart phone modem
                         # AP: smart phone AP
                                
DUAL_CAMERA_SUPPORT = FALSE  # TRUE: enable dual camera support
                             # FALSE: disable dual camera support

CMOS_SENSOR_SUB = NONE       # NONE: no sub camera sensor module
                             # other supported sensor module name

SENSOR_TYPE_SUB = NONE       # RAW: raw type sub camera sensor module
                             # YUV : yuv type sub camera sensor module
                             # NONE: not support sub camera
                               
FONT_ENGINE = NONE  # NONE, FONT_ENGINE_MONOTYPE, FONT_ENGINE_MONOTYPE_DEMO, FONT_ENGINE_FREETYPE, FONT_ENGINE_FREETYPE_DEMO, FONT_ENGINE_WTLE
                                

MULTIPLE_NDIS_SUPPORT = FALSE    # TRUE/FALSE, Enable/Disable Multiple PPP GPRS Dialup support
                                 # MULTIPLE_NDIS_SUPPORT only works when NDIS_SUPPORT = TRUE


AF_AUXI_LED_SUPPORT = FALSE    # TRUE, FALSE

MAX_NUM_OF_PPP_DIALUP_SUPPORT = 3  # 2,3 
                                   # This MAX_NUM_OF_PPP_DIALUP_SUPPORT value only works when MULTIPLE_PPP_DIALUP_SUPPORT = TRUE
                                   # valid values: 2,3
                                   # The value of MAX_NUM_OF_PPP_DAILUP_SUPPORT must <= GPRS_MAX_PDP_SUPPORT

FS_SORT_MAX_ENTRY = 64  # The maximum number of files can be sorted by file system file sorting feature. 

MULTIPLE_PPP_DIALUP_SUPPORT = FALSE  # TRUE/FALSE, Enable/Disable Multiple PPP GPRS Dialup support

SMS_R8_NATION_LANGUAGE = FALSE    # TRUE/FALSE, to support Turkish letter in SMS

SMS_R8_TABLE_MECHANISM = SMS_R8_DEFAULT   #SMS_R8_DEFAULT or SMS_R8_LOCKING or SMS_R8_SINGLE or SMS_R8_BOTH or SMS_R8_AUTO

BIP_SCWS_SUPPORT = FALSE  # TRUE, FALSE

SQLITE3_SUPPORT = FALSE  # TRUE, FALSE

MAX_NUM_OF_NDIS_SUPPORT = 3 	 # 2,3 
                                 # This MAX_NUM_OF_NDIS_SUPPORT value only works when MULTIPLE_NDIS_SUPPORT = TRUE
                                 # valid values: 2,3
                                 # The value of MAX_NUM_OF_PPP_DAILUP_SUPPORT must <= GPRS_MAX_PDP_SUPPORT


CMMB_SUPPORT = NONE  # NONE, INNOFIDEI_IF201, INNOFIDEI_IF202, TELEPATH_TP3001B

CMMB_CAS_SMD_SUPPORT = FALSE   # TRUE, FALSE

GPRS_DIALUP_PPP_DROP_PACKETS_WHEN_2G_PS_SUSPEND = FALSE  # TRUE, FALSE

BACKGROUND_CALL_SUPPORT = FALSE  # TRUE, FALSE

GPRS_DIALUP_PPP_SUPPORT_ESCAPE_ATO = FALSE  # TRUE, FALSE

GPRS_DIALUP_PPP_SUPPORT_SPEED_UP_DIALUP = FALSE  # TRUE, FALSE

NVRAM_PSEUDO_MERGE = OFF    # ON, OFF

DRA_DECODE = FALSE    # TRUE, FALSE

MEDIA_PLAYER_VER = SEPARATED  # SEPARATED, INTEGRATED, INTEGRATED_DB, INTEGRATED_FTE_DB
                              # SEPARATED : Seperate audio player and video player
                              # INTEGRATED : Integrated media player for key, pen touch
                              # INTEGRATED_DB : Integrated media player for key, pen touch using SQL database
                              # INTEGRATED_FTE_DB : Integrated media player for finger touch enable (FTE) using SQL database

UDX_SUPPORT = FALSE    # TRUE, FALSE

DRM_SUPPORT_SCAN_DISK = FALSE  # TRUE/FALSE (DRM supports scan disk or not)

DRM_SUPPORT_DB_SIZE = NONE  # NONE/DEFAULT/64/256/512/1024 (DRM database size cnfiguration)

# below macro definition is for dual mode
DUAL_MODE_SUPPORT = GEMINI # MASTER, SLAVE, NONE, 
                           # GEMINI: Single chip dual card solution


SENDKEY_MODE = SENDKEY2_SUPPORT # SINGLE_KEY_SELECT_MENU   SENDKEY2_SUPPORT
                                      # SINGLE_KEY_SELECT_MENU only one sendkey will popup a menu to select dail card1 or card2
                                      # SENDKEY2_SUPPORT  two sendkeys the one is for card1 and the other is for card2
                                      
MERCURY_SLAVE_BT_SUPPORT = FALSE # TRUE or FALSE

GEMINI = 2    # FALSE, 2, 3, 4


KURO_SUPPORT = NONE	 # OFFICIAL, NONE, MTK_INTERNAL

UMTS_BAND_I    = FALSE  # TRUE, FALSE
UMTS_BAND_II   = FALSE  # TRUE, FALSE
UMTS_BAND_III  = FALSE  # TRUE, FALSE
UMTS_BAND_IV   = FALSE  # TRUE, FALSE
UMTS_BAND_V    = FALSE  # TRUE, FALSE
UMTS_BAND_VI   = FALSE  # TRUE, FALSE
UMTS_BAND_VII  = FALSE  # TRUE, FALSE
UMTS_BAND_VIII = FALSE  # TRUE, FALSE
UMTS_BAND_IX   = FALSE  # TRUE, FALSE
UMTS_BAND_X    = FALSE  # TRUE, FALSE

STREAM_REC_SUPPORT = FALSE  # TRUE, FALSE
                            # TRUE: enable stream record support
                            # FALSE: disable stream record support                                          

SIM_PROVISIONING = NONE  # NONE, MMSICP

VENDOR = NONE     # NONE, DEFAULT, XXX(for XXX_VENDOR)
                  
MTP_SUPPORT = FALSE  # TRUE : enable MTP protocol feature
                     # FALSE : disable MTP protocol feature
                  
E_COMPASS_SENSOR_SUPPORT = NONE  # NONE, AMI304_I2C, MMC2120_I2C
                  
JOGBALL_SUPPORT = FALSE  # TRUE, FALSE

SYNCML_PC_SYNC_SUPPORT = FALSE  # TRUE, FALSE

POWERONOFF_BY_POWERKEY = FALSE  # TRUE, FALSE

IMAGE_VIEWER_VER = STANDARD    # SLIM, STANDARD, EX, EX_DB, NONE





3SET_F8F9_ENABLE = FALSE  # TRUE, FALSE

BITSTREAM_SUPPORT = FALSE  # TRUE, FALSE

VENUS_MMI = NONE   # NONE, VENUS_LEVEL1

BACKUP_SENSOR_SUPPORT = FALSE  # TRUE, FALSE

CMOS_SENSOR_BAK1 = NONE        # NONE: not support backup sensor feature in main camera
                               # Others: sensor module name for backup sensor feature in main camera
                                 
CMOS_SENSOR_SUB_BAK1 = NONE    # NONE: not support backup sensor feature in sub camera
                               # Others: sensor module name for backup sensor feature in sub camera
                                 
LENS_MODULE_BAK1 = NONE        # NONE:  not support AF lens backup sensor feature in main camera
                               # Others: AF lens module name for backup sensor feature in main camera
                               
MP4_DECODE_MODE = SLIM  # NORMAL, SLIM, NONE



MP4_DECODE_PROFILE = SP    # SP, ASP, ASP_PARTIAL
                           # SP: simple profile (by default)
                           # ASP: advanced simple profile
                           # ASP_PARTIAL: partial advanced simple profile

QOS_PROFILE_SUPPORT = NONE  # NONE, STATIC, DYNAMIC, ALL

ACCDET_SUPPORT		= FALSE   # TRUE or FALSE

DRV_DEBUG_MEMORY_TRACE_SUPPORT = FALSE  # TRUE, FALSE

QQMOVIE_SUPPORT = FALSE  # TRUE, FALSE

RRLP_VER_SUPPORT = NONE    # NONE, R5

USIM_SUPPORT = TRUE  # TRUE or FALSE

ULCS_ASN_SUPPORT_VERSION = ULCS_ASN_SUPPORT_R99  #ULCS_ASN_SUPPORT_R99, ULCS_ASN_SUPPORT_R6

MAIN_MEDIA_LAYER_BITS_PER_PIXEL = DEFAULT  # DEFAULT, 24

PLMN_LIST_PREF_SUPPORT = OFF  # ON, OFF

CMMB_CAS_FULL_CARD_SUPPORT = FALSE  # TRUE, FALSE

CMMB_CAS_MBBMS_SUPPORT = FALSE  # TRUE, FALSE                              
                                
UMTS_MODE_SUPPORT = NONE                      # NONE, UMTS_FDD_MODE_SUPPORT, UMTS_TDD128_MODE_SUPPORT

RESOURCE_MANAGER = FALSE  # TRUE, FALSE

HTTP_INTERFACE_SUPPORT = FALSE   # TRUE or FALSE

EXTERNAL_AMPLIFIER_ROUTE_CONFIGURATION = FALSE  # TRUE or FALSE

YUVCAM_ENCODE_DIRECT_WRITE_FILE = FALSE  # TRUE, FALSE
                                         # TRUE : JPEG encode writes file directly for saving memory
                                         # FALSE : MED camera writes file

LARGE_MIDI_FILE_SUPPORT  =  FALSE   # TRUE, FALSE


M3GPMP4_FILE_FORMAT_SUPPORT  =  TRUE    # TRUE, FALSE

RRC_PAYLOAD_FOR_3G_UP_SUPPORT  =  FALSE   # TRUE, FALSE

TWOMICNR_SUPPORT    =  NONE        # NONE, FORTEMEDIA_FM2018

UART_CHARGER_THE_SAME_INTERFACE  = NONE  # NONE, not exist any UART port use the same interface with charger
                                         # UART1, UART1 use the same interface with charger
                                         # UART2, UART2 use the same interface with charger
                                         # UART3, UART3 use the same interface with charger

OCSP_SUPPORT  = FALSE  # TRUE, FALSE
SMS_OVER_PS_SUPPORT  = TRUE   # TRUE, FALSE

COOK_DECODE  = FALSE  # TRUE, FALSE

I2S_INPUT_MODE_SUPPORT = FALSE  # TRUE, FALSE

FM_RADIO_I2S_PATH = FALSE  # TRUE, FALSE

DAF_ENCODE = FALSE  # TRUE, FALSE


LG_VOICE_ENGINE = FALSE   # TRUE, FALSE

WAPI_SUPPORT = FALSE   # TRUE, FALSE

DSP_COMPRESS = 7Z    # ZIP, 7Z, NONE

ATV_I2S_PATH = FALSE  # TRUE, FALSE

ATV_SUPPORT = FALSE   # TRUE, FALSE

ATV_CHIP = NONE   # VER00                          

ATV_SMS_SUPPORT = FALSE    # TRUE, FALSE

EXTERNAL_CHARGER_DETECTION   = NONE        # NONE, MAX14526, TS5USBA33402

EXTERNAL_ACCESSORY_DETECTION = NONE        # NONE, MAX14526, TS5USBA33402

SUPPORT_VIDEO_RECORD_ROTATE = FALSE  # TRUE, FALSE

PPP_TYPE_PDP_DIALUP_SUPPORT = FALSE  # TRUE, FALSE

CUSTOMER_SPECIFIC_FACTORY_DETECTION = NONE        # NONE, CS_FAC_DET_TYPE_1

FM_INTERFACE_TYPE = NONE     # NONE, I2C, HCI

YUVCAM_INTERPOLATION = NONE    # NONE, HW, SW
             
GENERAL_EXTERNAL_CHARGER = NONE    # NONE, BQ25040, RT9505_BQ24020, ISL9221
             
CAPTURE_SCENARIO = ON_THE_FLY  # STANDARD, OFFLINE, ON_THE_FLY


LGE_BT_SYSTEM_SUPPORT = FALSE  # TRUE, FALSE

TC01_OAEP_SUPPORT = FALSE  # TRUE, FALSE

CONNECTED_OOS = FALSE  # TRUE, FALSE

NAND_SUPPORT_RAW_DISK = FALSE # TRUE, FALSE 

NOR_SUPPORT_RAW_DISK = FALSE  # TRUE, FALSE

SYSDRV_BACKUP_DISK_SUPPORT = NONE  # NONE, FAT, RAW
             
AT_COMMAND_SET = ULC    # FULL ,SLIM ,ULC
                         # FULL : FULL AT command set
                         # SLIM : SLIM AT command set
                         # ULC : ULC AT command set
                         # Please refer to MTK AT document for detail SLIM  and ULC AT command list


CONTOUR_IMPROVEMENT_SUPPORT = FALSE   # TRUE, FALSE
                                      # If TRUE, must tune LCM gamma = 2.2


KAL_RECORD_BOOTUP_LOG = FALSE   # TRUE, FALSE                          

PHB_SYNC = OFF   # ON, OFF                          


PHB_ADDITIONAL_SUPPORT = FALSE    # TRUE, FALSE

KAL_ASSERT_SHRINKING = TRUE  # TRUE, FALSE

CARD_DOWNLOAD = NONE    # NONE, RAW_FORMAT_CARD, FILESYSTEM_ON_CARD

NVRAM_AFE_DIGITAL_GAIN_SUPPORT = FALSE  # TRUE, FALSE

DUAL_MIC_SUPPORT = FALSE  # TRUE, FALSE

GADGET_SUPPORT = NONE    # NONE, STANDARD, SHARED_MEMORY

ATV_RECORD_SUPPORT = FALSE  # TRUE, FALSE

GAIN_TABLE_SUPPORT = FALSE  # TRUE, FALSE

LANDSCAPE_UI_ON_PORTRAIT_LCM = FALSE  # TRUE, FALSE

LANDSCAPE_UI_ON_PORTRAIT_LCM_CCW_ROTATION_ANGLE = 270  # 90, 270

LCD_SHARE_WITH_EMI = FALSE  # TRUE, FALSE

BATTERY_CHARGING_SUPPORT = FALSE  # TRUE, FALSE

MDP_LCD_FW_UPDATE = FALSE    # TRUE, FALSE
                              
KEYPAD_DEBUG_TRACE = FALSE  # TRUE, FALSE

MP4_DECODE_LOW_COMP = NONE  # NONE, SW

H264_DECODE_LOW_COMP = NONE  # NONE, SW

VUI_SHELL_SUPPORT = FALSE  # TRUE, FALSE


ECC_RETRY_ENHANCEMENT = FALSE  # TRUE, FALSE

VIDEO_V2_ENABLE = TRUE  # TRUE, FALSE

H264_DECODE_MODE = NONE  # NORMAL, SLIM, NONE

GDI_SCREEN_SHOT_BUFFER = OFF  # ON, OFF
					
NVRAM_COMPRESS_SUPPORT = TRUE  # TRUE, FALSE

DA_MEMORY_CUT_SUPPORT = FALSE  # TRUE, FALSE

APE_DECODE = FALSE  # TRUE, FALSE

NMC_SUPPORT = FALSE  # TRUE, FALSE

GDI_BLT_WITH_DOUBLE_BUF_SUPPORT = FALSE # TRUE, FALSE
					
LANDSCAPE_UI_ON_PORTRAIT_LCM_SLIM_VERSION = FALSE # TRUE, FALSE
					
KAL_DEDUG_AND_TRACE_LEVEL = RELEASE_KAL  # NORMAL_DEBUG_KAL, SLIM_DEBUG_KAL, RELEASE_KAL
					
KAL_TRACE_OUTPUT = FULL    # FULL, NONE, CUST_PARTIAL

SML_SUPPORT = FALSE # TRUE, FALSE
					
MMI_HIDE_WAPI = FALSE # TRUE, FALSE
					
VCARD_SUPPORT = SINGLE  # MULTIPLE, SINGLE, NONE
					
DUAL_MEMORY_CARD_SUPPORT = NONE    # NONE, SWITCH
                                   # NONE   no dual card support
                                   # SWITCH   use single msdc controller + switch to support dual card

ENHANCED_UMTS_RF_CUSTOMIZATION = FALSE    # TRUE, FALSE

ZIMAGE_SUPPORT = FALSE    # TRUE, FALSE

AOC_SUPPORT = FALSE    # TRUE, FALSE

MAUI_SDK_TEST = FALSE    # TRUE, FALSE

RM_DECODE_MODE = NORMAL    # SLIM, NORMAL

MRE_PACKAGE = SLIM    # FULL, NORMAL, SLIM

COMBO_MEMORY_SUPPORT = TRUE    # TRUE, FALSE

CLASSAB_LOW_VOLTAGE_VOLUME_PROTECTION = FALSE    # TRUE, FALSE

RVCT_PARTIAL_LINK = FALSE    # TRUE, FALSE

PRODUCTION_RELEASE	= TRUE	  # Production release feature includs autoreset when system hang

SWITCHABLE_FEATURE = KAL_TRACE_OUTPUT

SWITCHABLE_FEATURE_2ND = FLAVOR

FLAVOR = GEMINI_2_KAL_FULL # GEMINI_2_KAL_FULL, GEMINI_2_KAL_NONE, GEMINI_NO_KAL_FULL, GEMINI_NO_KAL_NONE, GEMINI_4_KAL_FULL, GEMINI_4_KAL_FULL

#FLAVOR = NONE  # FLAVOR = NONE/$(FLAVOR)
               # FLAVOR = NONE: No flavor name was used.
               # FLAVOR = $(FALVOR): A flavor name $(FLAVOR) was used and a compile option __FLAVOR_$(FLAVOR)__ was defined.
               # __FLAVOR_$(FLAVOR)__ will be used in MMI feature files.

# *************************************************************************
# Custom Setting Section
# *************************************************************************
#ÊÖµçÍ²
LAMP_SUPPORT		= NONE    #NONE, SW, HW

#T Sensor
RYTENSOR			= FALSE  #TRUE, FALSE

GSENSOR_TASK		= FALSE
#Ë«ÉãÏñÍ·
DUAL_CAMERA       = FALSE  #TRUE, FALSE

DUAL_LCD			= FALSE  #TRUE, FALSE   #zsl 20111017

COLOR_SUBLCD  = FALSE  #TRUE, FALSE   #zsl 20111017

#³¯°Ý
AZAN_ALARM          = FALSE #TRUE ,FALSE
# *************************************************************************
# Release Setting Section
# *************************************************************************
RELEASE_PACKAGE		= REL_CR_MMI_$(strip $(PROJECT))	# REL_CR_MMI_GPRS, REL_CR_MMI_GSM, REL_CR_L4_GPRS, REL_CR_L4_GSM
RELEASE_WAE		= SRC		# MTK/SRC, only works when TELECA_FEATURES works
RELEASE_WAP		= MTK		# MTK/SRC, only works when TELECA_FEATURES works
 
RELEASE_$(strip $(INPUT_METHOD)) = SRC	# MTK/SRC, only works when INPUT_METHOD is turning on
RELEASE_INPUT_METHODS_SRC =		# MMI_ZI, MMI_T9, MMI_ITAP,
 
# *************************************************************************
# Consistent Feature Options
# *************************************************************************
COM_DEFS_FOR_MT6252RF_CUSTOM = MT6252RF_RF MT6252RF_CUSTOM
#COM_DEFS_FOR_LION52_V2_DEMO_LCM = LION52_V2_DEMO_LCM TFT_MAINLCD
COM_DEFS_FOR_NEOTEL52_6432_10A_LCM = NEOTEL52_6432_10A_LCM TFT_MAINLCD
# *************************************************************************
# Include MODEM.mak
# *************************************************************************
include make\MODEM.mak

# *************************************************************************
# Project specified preprocessor definitions
# *************************************************************************
CUSTOM_OPTION     +=  __MSDC_NO_WRITE_PROTECT__ __BT_SHRINK_SIZE__ __MSDC_NOT_SUPPORT_HOT_PLUG__ __MMS_MEMORY_CARD_STORAGE_SUPPORT__

# *************************************************************************
# Custom Release Component Configuration
# *************************************************************************
include make\$(strip $(RELEASE_PACKAGE)).mak


# ************************************************************************* 
# Component trace definition header files for custom release only 
# ************************************************************************* 
# Following trace headers are already existed in custom release 
# You can add new traces with kal_trace() in the following trace headers 
EXISTED_CUS_REL_TRACE_DEFS = 
EXISTED_CUS_REL_TRACE_DEFS += plutommi\framework\interface\pluto_fw_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += plutommi\mmi\inc\mmi_inet_app_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += media\common\include\med_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += plutommi\mmi\inc\mmi_conn_app_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += plutommi\mmi\inc\mmi_common_app_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += plutommi\mmi\inc\mmi_media_app_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += plutommi\framework\interface\mmi_fw_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += plutommi\mmi\inc\mmi_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += fmt\include\fmt_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += ps\sim2\include\sim_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += drv\include\drv_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += init\include\init_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += usb\include\usb_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += bmt\bmt_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += nvram\include\nvram_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += ps\l4\include\l4_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += ps\l4\phb\include\phb_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += ps\l4\uem\include\uem_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += l1audio\inc\l1sp_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += vendor\framework\obigo_q03c\adaptation\integration\include\trc\wps_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += vendor\wap\obigo_q03c\adaptation\integration\include\wap_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += fmr\inc\fmr_trc.h 
 
# Customer can add new trace headers here for new modules 
NEW_CUS_REL_TRACE_DEFS = 
