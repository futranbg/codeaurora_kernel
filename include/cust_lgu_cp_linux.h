#ifndef __CUST_LGU_CP_LINUX_H
#define __CUST_LGU_CP_LINUX_H

/* =============================================================================
FILE: cust_lgu_cp_mdm.h

Copyright (c) 2010 by PANTECH Incorporated.  All Rights Reserved.

��)     FEATURE_LGU_CP_xxx_XXX_001
         Ver.001 : 2011-08-18 : Jake, Lee 
���� ���� : -------------------------------------------------------------------------

1.	Custfile�� ���� ������ �ڼ��� �ۼ��� �ֽð� �ش� �ڵ� �κп� feature�� ������ �ۼ��մϴ�.
2.	���� ���� �ۼ��ÿ��� ����� �䱸 ���� �� standard spec. �� index�� �켱���� �ۼ��Ͻð�
3.	�׿� ��û���� �� side effect ������ ���� �ۼ� �մϴ�.

============================================================================= */

/*************************************************/
/*               COMMON INTERFACE                */
/*************************************************/

/*
    DDMS �� ���ؼ� radio log Ȯ���� ���ؼ��� �Ʒ� feature�� define�ؾ���..
*/
/* #define FEATURE_SKY_CP_RADIO_LOG_DDMS */



#define FEATURE_LGU_CP_MANAGER_DAEMON_INTERFACE
#ifdef FEATURE_LGU_CP_MANAGER_DAEMON_INTERFACE
#define FEATURE_LGU_CP_CPMGRIF_QMI_CLIENT
#define FEATURE_LGU_CP_OEM_COMMANDS_WITH_QMI // MDM Side
#define FEATURE_LGU_CP_OEM_MSM_COMMANDS_WITH_QMI // FEATURE_LGU_CP_1X_FACTORY_INIT
#define FEATURE_LGU_CP_OEM_QMI_ACCESS
#define FEATURE_LGU_COMMON_TELEPHONY_IF
#endif

#define FEATURE_LGU_CP_RIL_SOCKET_OPEN_RETRY_MILIS

#define FEATURE_LGU_CP_MANAGER_GW_DAEMON_INTERFACE
#define FEATURE_LGU_GW_COMMON_TELEPHONY_IF

#define FEATURE_LGU_COMMON_DEBUG_SCREEN

#define FEATURE_LGU_CP_COMMON_GLOBAL_SD
#ifdef FEATURE_LGU_CP_COMMON_GLOBAL_SD
#define FEATURE_LGU_CP_COMMON_MODE_PREF_CHG_BLK_WHEN_TEST_MODE
#endif

#define FEATURE_LGU_CP_SKY_ENG_MENU

#define FEATURE_LGU_CP_COMMON_MSM_NVIO_WITH_QMI
#define FEATURE_LGU_CP_COMMON_MDM_NVIO_WITH_QMI

#define FEATURE_LGU_CP_COMMON_RSSI

#define FEATURE_LGU_CP_COMON_DEFAULT_SETTINGS

#define FEATURE_LGU_CP_COMMON_MDN_MIN_FIX

#define FEATURE_LGU_CP_COMMON_PLMN_FIX_FOR_CDMA

#define FEATURE_LGU_CP_COMMON_AIRPLANE_MODE_RELEASE_AFTER_BOOT

/* SKY �ڵ������� Interface */
#define FEATURE_LGU_CP_AUTOANSWER_INTERFACE

#define FEATURE_LGU_CP_PROCESS_CMD_WITH_RPC

#define FEATURE_LGU_CP_CARD_POWER_DOWN_NOT_SUPPORT

#define FEATURE_LGU_CP_COMMON_OPERATORS_FOR_3GPP2

#define FEATURE_LGU_CP_COMMON_SUPPORT_DIAG_CALL

#define FEATURE_LGU_CP_COMMON_CLEAR_ALL_CONNECTIONS_WHEN_LPM

#define FEATURE_LGU_CP_COMMON_UPDATE_VOICE_RTE

#define FEATURE_LGU_CP_COMMON_SKIP_REMOVEREFERENCES_WHEN_PHONE_CHG

#define FEATURE_LGU_CP_GUARD_NULL_EXCEPTION_WHEN_PHONE_CHANGE

#define FEATURE_LGU_CP_COMMON_OPMODE_CMD_FIX

#define FEATURE_LGU_CP_COMMON_UPDATE_SERVICE_STATE_FOR_DATA_ONLY 
// [kkosu] qcril_qmi_nas.c  lte_plmn_id get�� ���� local_db_lte �߰� �ʿ� (��������)

#define FEATURE_LGU_CP_COMMON_ROAMING_STATE_FIX // from EF46L

#define FEATURE_LGU_CP_COMMON_ANDROID_OTASP_BLOCK // from EF46L

#define FEATURE_LGU_CP_COMMON_CARD_ABSENT_BUG_FIX // from EF46L

#define FEATURE_LGU_CP_COMMON_RUDE_WAKEUP

#define FEATURE_LGU_CP_COMMON_NITZ_LOG

#define FEATURE_LGU_CP_RIL_FW_ANDROID_REQUEST_HNDL_MAX_EVT_ID_FIX // from EF50L
#define FEATURE_LGU_CP_FW_DEDICATED_ANDROID_REQ_BUG_FIX

//#define FEATURE_LGU_CP_COMMON_OPENING_DAY // from EF46L
// [kkosu] sky raw data ���� �Ͽ� ���� Ȯ�� �� ���� Ǯ��..

#ifdef FEATURE_LGU_CP_COMMON_OPENING_DAY
#define FEATURE_SKY_CP_NEW_OPENING_DAY
#define FEATURE_SKY_CP_OEM_PH_EVENT_WITH_QMI /* Deliver CM PH event info via qmi(nas) */
#endif /* FEATURE_LGU_CP_COMMON_OPENING_DAY */

#define FEATURE_LGU_CP_COMMON_CARD_ABSENT_BUG_FIX

/*************************************************/
/*                     1X                        */
/*************************************************/

#define FEATURE_LGU_CP_1X_DEFAULT_SETUP

#define FEATURE_LGU_CP_1X_LOCAL_DB

#ifdef FEATURE_LGU_CP_1X_LOCAL_DB
#define FEATURE_LGU_CP_1X_LOCAL_DB_WITH_QMI
#endif /* FEATURE_LGU_CP_1X_LOCAL_DB */

#ifdef FEATURE_LGU_COMMON_DEBUG_SCREEN
#define FEATURE_LGU_CP_1X_DEBUG_SCREEN
#endif /* FEATURE_LGU_COMMON_DEBUG_SCREEN */

#define FEATURE_LGU_CP_OEM_API

#define FEATURE_LGU_CP_1X_OTASP

#define FEATURE_LGU_CP_1X_PRL_VERSION

#define FEATURE_LGU_CP_1X_SYSLOST_MONITOR

#define FEATURE_LGU_CP_1X_TEST_CALL_SO

#define FEATURE_LGU_CP_1X_SWITCH_TO_BURST_DTMF

#define FEATURE_LGU_CP_1X_TEST_SBA_FOR_CNAP

#define FEATURE_LGU_CP_1X_8BIT_CHAR_SUPPORT

#define FEATURE_LGU_CP_1X_REG_STATE_UPDATE

#define FEATURE_LGU_CP_1X_FACTORY_INIT

#define FEATURE_LGU_CP_1X_REJ_DISPLAY

#define FEATURE_LGU_CP_1X_MISSED_CALL_BUG_FIX

#define FEATURE_LGU_CP_SKIP_TOA_CHECK // Number Type fix

/*************************************************/
/*                    EVDO                       */
/*************************************************/
#ifdef FEATURE_LGU_COMMON_DEBUG_SCREEN
#define FEATURE_LGU_CP_EVDO_DEBUG_SCREEN
#define FEATURE_LGU_CP_EVDO_DB_QMI
#endif /* FEATURE_LGU_COMMON_DEBUG_SCREEN */

#define FEATURE_LGU_CP_EVDO_ENG_MODE
#ifdef FEATURE_LGU_CP_EVDO_ENG_MODE
#undef FEATURE_LGU_CP_EVDO_ERROR_CODE_NETWORK_ERROR
#undef FEATURE_LGU_CP_EVDO_ERROR_CODE_UI_STRING
#define FEATURE_LGU_CP_EVDO_REV_SETTING
#define FEATURE_LGU_CP_EVDO_SESSION_RESET
#define FEATURE_LGU_CP_EVDO_ERROR_REASON_CODE_WITH_QMI
#define FEATURE_LGU_CP_EVDO_CHECK_VT_REG_STATUS
#define FEATURE_LGU_CP_EVDO_SESSION_CLOSE_NOTY_FOR_VT
#endif

/*************************************************/
/*                     WCDMA/GSM                        */
/*************************************************/
#define FEATURE_LGU_CP_GW_LOCAL_DB

#define FEATURE_LGU_CP_LOCAL_DB_GW_ACCESS_CPMGRIF

#define FEATURE_LGU_CP_GW_LOCAL_DB_WITH_QMI

#define FEATURE_LGU_CP_GW_DEBUG_SCREEN

#define FEATURE_LGU_CP_GW_REJECT_CAUSE_DISPLAY

#define FEATURE_LGU_CP_GW_RSSI_LEVEL

/* QMI �� ���ؼ� CM system selection preference ȣ�� */
#define FEATURE_LGU_CP_CM_SYS_SELECTION_PREF

/* UMTS SMS MO PS/CS Domain setting menu support */
#define FEATURE_LGU_CP_SMS_CFG_SET_GW_DOMAIN

/* Phone Operation Mode setting (lpm, offline, online .. ) */
#define FEATURE_LGU_CP_PHONE_OPERATION_MODE

/* Voice Call connection sound event */
#define FEATURE_LGU_CP_GW_CS_CALL_CONNECTION_SND_START

/*
   ��ȭ�� ����� ������ ���� Setup ind. ���� signal value�� ������.
   AMSS���� FEATURE_SKY_CP_SETUP_IND_SIGNAL_VALUE �� �ݵ�� �����Ǿ�� ��.
*/   
#define FEATURE_LGU_CP_GW_SETUP_IND_SIGNAL_VALUE

/* PLMN ���� �˻�  */
#define FEATURE_LGU_CP_GW_NETWORK_PLMN_MANUAL_SELECTION
#ifdef FEATURE_LGU_CP_GW_NETWORK_PLMN_MANUAL_SELECTION
#define FEATURE_LGU_CP_GW_MANUAL_SELECTION_WITH_RAT
#endif/* FEATURE_LGU_CP_GW_NETWORK_PLMN_MANUAL_SELECTION */

/* Limited service���¸� �����ϱ� ���ؼ� ServiceState ����. */
#define FEATURE_LGU_CP_GW_SERVICE_STATUS_DETAIL_SUBSTATE

/* 
    Network Name�� ������������ �ұ��ϰ�, "nas_cached_info.current_plmn" ���� Invalid�� ó���Ǿ� 
   �ش� Network Name�� �ƴ� Table�� name�� ǥ���ϴ� ������ ���� Qcril���� �����ϴ� system info�� 
   state ��ȭ�ø��� update�ϵ��� ��.
   QCT�� �� system info�� LCD enable�ÿ��� update �ϵ��� �ϰ� ����
*/
#define FEATURE_LGU_CP_GW_QMI_SYS_INFO_ALWAYS_UPDATE

/* 
  �ܸ� PS ONLY ���� ������ android�ܿ��� Reg state�� No Service�� ó���ϴ� ������ ���� 
  CS reject, PS accept �Ǵ� reject cause���迡���� ���� ���� �߻�.
*/
#define FEATURE_LGU_CP_GW_SUPPORT_PS_ONLY_MODE

/*
   MccMnc Table ���� ( SKT�� ����.. )
*/
#define FEATURE_LGU_CP_GW_PLMN_TABLE_LIST_SEARCH

/*
   ���� ���� ������ MCC/MNC �� update �Ǵ� �κ��� Limited service���¿����� update�� �����ϵ��� ������.
*/
#define FEATURE_LGU_CP_GW_GET_MCCMNC_UPDATE_IN_LIMITED_SRV

/*
   �ؿ� �ιֽ� (52501: Sing Tel) NITZ ������ �������� ������ OP NAME ������ NULL�� �ƴ����� length�� (0)�� ��쿡 �ش� ��.
   MCCMNC Table���� �ش� OP NAME�� �Ѹ��ٰ� MM INFO ���� ���� NAME�� �Ⱥ��̴� ��� ������.
*/
#define FEATURE_LGU_CP_GW_FIX_OPERATOR_NAME_DISPLAY

/*
    ����� �� ���� ���� property�� ������ network nameǥ�⸦ �߸��ϴ� ������ �߻��Ͽ� ����.
*/
#define FEATURE_LGU_CP_GW_INIT_NITZ_INFO_PROPERTY

/*
   invalid code input --> network no response --> ui pop-up remain forever....
*/
#define FEATURE_LGU_CP_GW_USSD_NEWORK_NO_RESPONSE

// centralized_eons_supported  ��� ���ۿ� ���� network name �� manual search list ǥ�� ������ �߻���.
#define FEATURE_LGU_CP_GW_CENTRALIZED_EONS_NOT_SUPPORTED


/*************************************************/
/*                    LTE                        */
/*************************************************/
#ifdef FEATURE_LGU_COMMON_DEBUG_SCREEN
#define FEATURE_LGU_CP_LTE_DEBUG_SCREEN
#define FEATURE_LGU_CP_LTE_DB_QMI
#endif /* FEATURE_LGU_COMMON_DEBUG_SCREEN */

#define FEATURE_LGU_CP_LTE_PROCESS_REJECT
#define FEATURE_LGU_CP_LTE_REJECT_DISPLAY_SIMULATION

#define FEATURE_LGU_CP_LTE_ANDSF_CELLID

/*************************************************/
/*                    UICC                       */
/*************************************************/
#ifdef FEATURE_LGU_CP_MANAGER_DAEMON_INTERFACE
#define FEATURE_LGU_UICC_CARD_TYPE
#endif

#define FEATURE_LGU_SUPPORT_FOR_ISIM_APPLICATION

#define FEATURE_LGU_CP_CHECK_PIN_PUK_RETRY_COUNT_WHEN_BOOTUP

#define FEATURE_LGU_CP_CARD_MODE

#define FEATURE_LGU_CP_BIP_STATUS

#define FEATURE_LGU_CP_STK_RESEND

#define FEAUTRE_LGU_CP_UICC_ERROR_FIX
#define FEATURE_LGU_CP_SUPPORT_NFC
#define FEATURE_LGU_CP_CHECK_ROAMING_SETTINGS

/*************************************************/
/*                   LBS(GPS)                    */
/*************************************************/
// EF35L GPS Porting
#define FEATURE_LGU_CP_GPS
#define FEATURE_LGU_CP_GPS_TESTMENU
#define FEATURE_LGU_CP_GPS_GPSONEXTRA
#define FEATURE_LGU_CP_GPS_GPSON
#define FEATURE_LGU_CP_GPS_XTRA_T
#define FEATURE_LGU_CP_GPS_WIPER
#define FEATURE_LGU_CP_GPS_GSIFF
#define FEATURE_LGU_CP_GPS_HIDDENMENU
#define FEATURE_LGU_CP_GPS_SD_CARD

#endif /* __CUST_LGU_CP_LINUX_H */

