#ifndef _CUST_SKY_FILE_
#define _CUST_SKY_FILE_

#include "BOARD_REV.h"

/*******************************************************************************
      !!!!!!!!!!!!!!!!!! MUST BE DEFINED AS FOLLOWS (ANDROID)!!!!!!!!!!!!!!!!!!
      CONFIG_{COMPANY_NAME}_{FUNCTION_NAME}_{ACTION_NAME}
      ex) PMIC function.
      #define CONFIG_PANTECH_PMIC

      for using BOTH (android & kernel) definition, please read engineer note about chapter 5 Arm Linux Kernel.

      IF YOU ADD FEATURE IN KERNEL , YOU CHECK THE RELEASE ENGINNER NOTE

      __KERNELBUILD__ :  for avoid redefined , this is predefined name in kernel makefile.

*******************************************************************************/

 
#define CONFIG_PANTECH

#if defined(T_EF39S)
    #define CONFIG_SKY_EF39S_BOARD
#elif defined(T_EF40S)
    #define CONFIG_SKY_EF40S_BOARD
#elif defined(T_EF40K)
    #define CONFIG_SKY_EF40K_BOARD
#elif defined(T_PRESTO)
    #define CONFIG_PANTECH_PRESTO_BOARD
#elif defined(T_EF65L)
	#define CONFIG_SKY_EF65L_BOARD
#else
#error "Not supported MODEL"
#endif

#define FEATURE_PANTECH_MSG_ONOFF // QXDM MSG ONOFF
#define FEATURE_PANTECH_VOLUME_CTL

/*******************************************************************************
**  PDL
*******************************************************************************/
#define FEATURE_SKY_PDL_DLOADINFO
#define FEATURE_SKY_PDL_DLOAD
#define FEATURE_SKY_FLASH_ACCESS
#define FEATURE_SKY_DLOAD_USB
#define FEATURE_SKY_REBOOT_FOR_IDLE_DL


/*******************************************************************************
**  USER DATA REBUILDING VERSION
*******************************************************************************/
#define FEATURE_SKY_USER_DATA_VER


/*******************************************************************************
**  RAWDATA PARTITION ACCESS, FOR BACKUP
*******************************************************************************/
#define FEATURE_SKY_RAWDATA_ACCESS


/****************************************************
** MMC(eMMC, MicroSD)
****************************************************/
#define FEATURE_SKY_MMC
/* paiksun... */  //kobj 110524

/****************************************************
** USB CHARGING
****************************************************/
#define FEATURE_SKY_CHARGING
#define FEATURE_SKY_CHG_LOGO  // p14682 kobj 110621

/****************************************************
** PMIC
****************************************************/
#define FEATURE_SKY_PMIC

/* paiksun... */
/****************************************************
** Fuel Guage (lk)
****************************************************/
#define FEATURE_SKY_BATTERY_MAX17040

/****************************************************
** POWER ON/OFF REASON COUNT
****************************************************/
#define FEATURE_SKY_PWR_ONOFF_REASON_CNT

/*******************************************************************************
**  BOOTLOADER UART LOG for debugging
*******************************************************************************/
#define FEATURE_SKY_BOOTLOADER_UART_LOG

/*******************************************************************************
** USER BUILD
*******************************************************************************/
#ifdef T_BUILD_USER
#define FEATURE_BUILD_USER
#endif
#define FEATURE_SKY_NFC_PN544

/*******************************************************************************
**  Camera
*******************************************************************************/
#include "CUST_PANTECH_CAMERA.h"

/*******************************************************************************
**  RF FEATURE (TESTMENU and RPC)
*******************************************************************************/
#define F_PANTECH_RF_TESTMENU
#define F_PANTECH_RF_PWR_BACKOFF
#define FEATURE_SKY_GPS
#define F_PANTECH_RESET_FROM_MDM
#define F_PANTECH_INIT_SYS_CHECK

#define FEATURE_PANTECH_MDM_TO_MSM_CMD /*yjw 20110801*/

/*******************************************************************************
**  WLAN
*******************************************************************************/
#define FEATURE_SKY_WLAN
#define FEATURE_SKY_WLAN_TESTMENU
#define FEATURE_SKY_WLAN_FC
#define FEATURE_SKY_WLAN_RAWDATA_ACCESS
#define FEATURE_SKY_WLAN_ADDR_BACKUP


/*******************************************************************************
  **  SW reset changed to HW reset.
  *******************************************************************************/
#ifndef T_PRESTO
#define FEATURE_SW_RESET_CONVERT_HW_RESET
#endif
#define FEATURE_SKY_SAVE_LOG_SDCARD
#define FEATURE_PANTECH_ERR_LOG_TESTMENU
#define FEATURE_SKY_FAT16_FOR_SBL3
#define FEATURE_PANTECH_RAMDUMP_ONOFF

/*
  2011/06/22 ?ֺ???
  PANTECH multimedia engine/codec ???? ???? feature d?????? (?ֻ?' FEATURE_PANTECH_MMP ??)
*/
#include "cust_pantech_mmp.h"
/* [PS3] Kang Seong-Goo framework features about SurfaceFlinger */
#include "CUST_SKYDISP.h"

#define PANTECH_STABILITY_AT_COMMAND

/****************************************************
** TDMB LS6 P12509
****************************************************/
#if defined(T_EF39S) || defined(T_EF40S) || defined(T_EF40K) || defined(T_EF65L)
#define FEATURE_BUILD_WITH_TDMB
#endif


/****************************************************
** SOUND
****************************************************/
#define FEATURE_SKYSND
#define FEATURE_SKYSND_CR295399  //Fix:MIC mute during the VOIP calls on audio Path

#undef FEATURE_SKYSND_LPA  //2011.08.10 ojs : delete lpa code

#if defined(T_EF39S) || defined(T_EF40S) || defined(T_EF40K) 
#define FEATURE_SKY_QSOUND_QFX
#define FEATURE_SKYSND_VT_VOIP
#define FEATURE_SKYSND_MVS
#define FEATURE_SKYSND_EFXX
#elif defined(T_EF65L)
#define FEATURE_SKYSND_LPA  //20111130 jhsong : LPA feature
#define FEATURE_SKY_QSOUND_QFX  //20111121 jhsong : qsound
#define FEATURE_SKYSND_VT_VOIP
//#define FEATURE_SKYSND_MVS //20111026 frogLove : for LTE VT
#define FEATURE_SKYSND_EFXX
#endif

/*******************************************************************************
**  BLUETOOTH
*******************************************************************************/
#define FEATURE_PANTECH_BLUETOOTH_BDADDR_PROPERTY_SET
#define FEATURE_SKY_BT_DEVICE_ADDR_BACKUP
#define FEATURE_SKY_BT_FC
#if defined(T_EF39S) || defined(T_EF40S) || defined(T_EF40K) || defined(T_EF65L)
#define FEATURE_SKY_BT
#elif defined(T_PRESTO)
//#define FEATURE_PANTECH_BT
#endif
/*******************************************************************************
**  Android Pattern Reset
*******************************************************************************/
#define F_PANTECH_PATTERN_LOCK
/*******************************************************************************
**  ssec secure esn
*******************************************************************************/
#if defined(T_EF39S) || defined(T_EF40S) || defined(T_EF40K) || defined(T_EF65L)
#define FEATURE_SKY_SSEC_ACCESS_TO_AP_MODEM //110901 parkchun
#endif

#define PANTECH_DIAG_MSECTOR
/* jslee 20110615 */ //jslee 20110622
#if defined(T_PRESTO)
#define FEATURE_FOTA_FS_REDBEND
#endif
/*******************************************************************************
**  FOTA
*******************************************************************************/
#if defined(T_EF39S) || defined(T_EF40S)
#define GOTA_CONFIG
#define FEATURE_GOTA_UPGRADE	//p14777 jang gota upgrade
#endif

/*******************************************************************************
**  PWR_ONOFF_CNT and SW RESET
*******************************************************************************/
#define CONFIG_PANTECH_PWR_ONOFF_REASON_CNT
#define CONFIG_SW_RESET
#define CONFIG_PANTECH_WDOG_WORKAROUND
#define FEATURE_SKY_ABNORMAL_POWER_INFO         //p13156@lks ps1_20110520
/*******************************************************************************
**  Sky Station
*******************************************************************************/
// #if defined(T_EF39S) || defined(T_EF40S) //kimhojun
#define FEATURE_SKY_SDCARD_UPGRADE
#define FEATURE_SKY_SELF_UPGRADE_SDCARD
// #endif

/*******************************************************************************
**  Data Encryption
*******************************************************************************/
#define FEATURE_SKY_DATA_ENCRYPTION

/*******************************************************************************
**  SENSOR
*******************************************************************************/
#if (defined(CONFIG_SKY_EF39S_BOARD) && (BOARD_REV >= TP10)) || \
	(defined(CONFIG_SKY_EF40K_BOARD) && (BOARD_REV >= WS20)) || \
	(defined(CONFIG_SKY_EF40S_BOARD) && (BOARD_REV >= WS20))
#define	FEATURE_GYROSENSOR_QUP_I2C
#endif
/*******************************************************************************
 **  WIDEVINE DRM
*******************************************************************************/
#define FEATURE_PANTECH_WIDEVINE_DRM

/*******************************************************************************
 **  PANTECH ROOTING CHECK		//lsi@ls1
*******************************************************************************/
#define F_PANTECH_OEM_ROOTING
#define FEATURE_PANTECH_KEY_CERTIFICATION
/*
  20110906 HKSONG
  LGU+ Call Protocol CUST FILE
  FEATURE_LGU_CP_COMON_DEFAULT_SETTINGS
*/
#include "cust_lgu_cp_linux.h"

#define FEATURE_ANDROID_PANTECH_USB_TESTMENU

#define FEATURE_PANTECH_AUTO_REPAIR
#define FEATURE_CS_USERDATA_BACKUP

#endif/*_CUST_SKY_FILE_*/
