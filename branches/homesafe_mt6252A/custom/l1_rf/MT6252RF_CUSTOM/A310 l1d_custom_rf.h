/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
* 
********************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 *	 l1d_custom_rf.h
 *
 * Project:
 * --------
 *   MT6252
 *
 * Description:
 * ------------
 *   MT6252 constant defintion
 *
 * Author:
 * -------
 * -------
 *
 *******************************************************************************/

#ifndef  _L1D_CUSTOM_RF_H_
#define  _L1D_CUSTOM_RF_H_
/* ------------------------------------------------------------------------- */

#if !defined(MT6252RF_RF)
   #error "rf files mismatch with compile option!"
#endif


#if  IS_RF_MT6252RF
/*MT6252RF*/
/*MT6252RF*/
/*MT6252RF*/
/*MT6252RF*/ /*--------------------------------------------------------*/
/*MT6252RF*/ /*   Event Timing Define                                  */
/*MT6252RF*/ /*--------------------------------------------------------*/
/*MT6252RF*/
/*MT6252RF*/
/*MT6252RF*/ #define  QB_RX_FENA_2_FSYNC          36   /* this value shall be 4N+0 */
/*MT6252RF*/ #define  QB_RX_FSYNC_2_FENA           0
/*MT6252RF*/ #define  QB_TX_FENA_2_FSYNC          40   /* this value shall be 4N+0 */
/*MT6252RF*/ #define  QB_TX_FSYNC_2_FENA          30
/*MT6252RF*/
/*MT6252RF*/
/*MT6252RF*/ #define  QB_SR0                     213
/*MT6252RF*/ #define  QB_SR1                     148
/*MT6252RF*/ #define  QB_SR2                      71
/*MT6252RF*/ #define  QB_SR3                       0
/*MT6252RF*/ #define  QB_SR2M                     44
/*MT6252RF*/ #define  QB_PR1                      40
/*MT6252RF*/ #define  QB_PR2                      33
/*MT6252RF*/ #define  QB_PR3                       6
/*MT6252RF*/ #define  QB_ST0                     325
/*MT6252RF*/ #define  QB_ST1                     280
/*MT6252RF*/ #define  QB_ST2B                     52
/*MT6252RF*/ #define  QB_ST3                      36
/*MT6252RF*/ #define  QB_PT1                     245
/*MT6252RF*/ #define  QB_PT2                      20
/*MT6252RF*/ #define  QB_PT2B                      0
/*MT6252RF*/ #define  QB_PT3                      31
/*MT6252RF*/ #define  QB_APCON                    18
/*MT6252RF*/ #define  QB_APCMID                   26
/*MT6252RF*/ #define  QB_APCOFF                    5
/*MT6252RF*/ #define  QB_APCDACON                 36
/*MT6252RF*/ #define  TX_PROPAGATION_DELAY        43
/*MT6252RF*/
/*MT6252RF*/
/*MT6252RF*/ /*--------------------------------------------------------*/
/*MT6252RF*/ /*   define  BPI data for MT6253EL                        */
/*MT6252RF*/ /*--------------------------------------------------------*/
/*MT6252RF*/ /*    PRCB : bit   pin                                    */
/*MT6252RF*/ /*            0    VC3                                    */
/*MT6252RF*/ /*            1    VC2                                    */
/*MT6252RF*/ /*            2    VC1                                    */
/*MT6252RF*/ /*            3    PAEN                                   */
/*MT6252RF*/ /*            4    not used                               */
/*MT6252RF*/ /*            5    not used                               */
/*MT6252RF*/ /*            6    not used                               */
/*MT6252RF*/ /*            7    not used                               */
/*MT6252RF*/ /*            8    not used                               */
/*MT6252RF*/ /*            9    not used                               */
/*MT6252RF*/ /*--------------------------------------------------------*/
/*MT6252RF*/
/*MT6252RF*/
/*MT6252RF*/ /*-------------------------------------------------------------------------------------*/
/*MT6252RF*/
/*MT6252RF*/
/*MT6252RF*/ #define  PDATA_INIT            0x0
/*MT6252RF*/ #define  PDATA_IDLE            0x0
/*MT6252RF*/
/*MT6252RF*/ #define  PDATA_GSM850_PR1      PDATA_IDLE
/*MT6252RF*/ #define  PDATA_GSM850_PR2      0x2
/*MT6252RF*/ #define  PDATA_GSM850_PR3      PDATA_IDLE
/*MT6252RF*/ #define  PDATA_GSM850_PT1      PDATA_IDLE
/*MT6252RF*/ #define  PDATA_GSM850_PT2      PDATA_IDLE
/*MT6252RF*/ #define  PDATA_GSM850_PT2B     0xA
/*MT6252RF*/ #define  PDATA_GSM850_PT3      PDATA_IDLE
/*MT6252RF*/ #define  PDATA_GSM_PR1         PDATA_IDLE
/*MT6252RF*/ #define  PDATA_GSM_PR2         0x2
/*MT6252RF*/ #define  PDATA_GSM_PR3         PDATA_IDLE
/*MT6252RF*/ #define  PDATA_GSM_PT1         PDATA_IDLE
/*MT6252RF*/ #define  PDATA_GSM_PT2         PDATA_IDLE
/*MT6252RF*/ #define  PDATA_GSM_PT2B        0xA
/*MT6252RF*/ #define  PDATA_GSM_PT3         PDATA_IDLE
/*MT6252RF*/ #define  PDATA_DCS_PR1         PDATA_IDLE
/*MT6252RF*/ #define  PDATA_DCS_PR2         0x6
/*MT6252RF*/ #define  PDATA_DCS_PR3         PDATA_IDLE
/*MT6252RF*/ #define  PDATA_DCS_PT1         PDATA_IDLE
/*MT6252RF*/ #define  PDATA_DCS_PT2         PDATA_IDLE
/*MT6252RF*/ #define  PDATA_DCS_PT2B        0xE
/*MT6252RF*/ #define  PDATA_DCS_PT3         PDATA_IDLE
/*MT6252RF*/ #define  PDATA_PCS_PR1         PDATA_IDLE
/*MT6252RF*/ #define  PDATA_PCS_PR2         0x6
/*MT6252RF*/ #define  PDATA_PCS_PR3         PDATA_IDLE
/*MT6252RF*/ #define  PDATA_PCS_PT1         PDATA_IDLE
/*MT6252RF*/ #define  PDATA_PCS_PT2         PDATA_IDLE
/*MT6252RF*/ #define  PDATA_PCS_PT2B        0xE
/*MT6252RF*/ #define  PDATA_PCS_PT3         PDATA_IDLE
/*MT6252RF*/
/*MT6252RF*/
/*MT6252RF*/
/*MT6252RF*/ /*----------------------------------------------*/
/*MT6252RF*/ /*   APC Compensate Thresholds                  */
/*MT6252RF*/ /*----------------------------------------------*/
/*MT6252RF*/
/*MT6252RF*/ #define    SECONDS2FRAME(n)                     ((int)((n)*1000/4.165))
/*MT6252RF*/ #define    VOLT2UVOLT(n)                        ((int)((n)*1000000))
/*MT6252RF*/ #define    TEMP2MTEMP(n)                        ((int)((n)*1000))
/*MT6252RF*/
/*MT6252RF*/ #define    BAT_VOLTAGE_SAMPLE_PERIOD            SECONDS2FRAME(180)
/*MT6252RF*/ #define    BAT_VOLTAGE_AVERAGE_COUNT            1
/*MT6252RF*/ #define    BAT_LOW_VOLTAGE                      VOLT2UVOLT(3.5)
/*MT6252RF*/ #define    BAT_HIGH_VOLTAGE                     VOLT2UVOLT(4.0)
/*MT6252RF*/
/*MT6252RF*/ #define    BAT_TEMPERATURE_SAMPLE_PERIOD        SECONDS2FRAME(180)
/*MT6252RF*/ #define    BAT_TEMPERATURE_AVERAGE_COUNT        1
/*MT6252RF*/ #define    BAT_LOW_TEMPERATURE                  TEMP2MTEMP(0)
/*MT6252RF*/ #define    BAT_HIGH_TEMPERATURE                 TEMP2MTEMP(50)
/*MT6252RF*/
#endif

/*----------------------------------------------*/
/*   Crystal parameter                          */
/*----------------------------------------------*/

#define Custom_RF_XO_CapID  50
/*MT6252RF*/ /*------------------------------------------------------------------------------------*/
/*MT6252RF*/ /*   0: GSM850 Signal go through GSM850, GSM900 Signal go through GSM900  (default)   */
/*MT6252RF*/ /*   1: GSM850 Signal go through GSM900, GSM900 Signal go through GSM850  (default)   */
/*MT6252RF*/ /*------------------------------------------------------------------------------------*/
/*MT6252RF*/ #define GSM850_GSM900_SWAP      0
/*MT6252RF*/ /*------------------------------------------------------------------------------------*/
/*MT6252RF*/ /*   0: DCS1800 Signal go through DCS1800, PCS1900 Signal go through PCS1900(default) */
/*MT6252RF*/ /*   1: DCS1800 Signal go through PCS1900, PCS1900 Signal go through DCS1800          */
/*MT6252RF*/ /*------------------------------------------------------------------------------------*/
/*MT6252RF*/ #define DCS1800_PCS1900_SWAP    0

/*===============================================================================*/
/* for TX power rollback                                                         */
/*===============================================================================*/
/*MT6252RF*/ #define IS_TX_POWER_ROLLBACK_SUPPORT 1 /* 0: turn off, 1: turn on */
/*MT6252RF*/
/*MT6252RF*/ #if IS_TX_POWER_ROLLBACK_SUPPORT
/*MT6252RF*/    #define TX_POWER_ROLLBACK_SUPPORT
/*MT6252RF*/    /*GSMK*/
/*MT6252RF*/    #define ROLLBACK_DB_F2_GMSK 1       // Reduced power value for 2 TX slots (it could be set float)
/*MT6252RF*/    #define ROLLBACK_DB_F3_GMSK 3       // Reduced power value for 3 TX slots (it could be set float)
/*MT6252RF*/    #define ROLLBACK_DB_F4_GMSK 4       // Reduced power value for 4 TX slots (it could be set float)
/*MT6252RF*/ #endif
/*============================================================================== */
#endif