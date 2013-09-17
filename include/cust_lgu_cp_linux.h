#ifndef __CUST_LGU_CP_LINUX_H
#define __CUST_LGU_CP_LINUX_H

/* =============================================================================
FILE: cust_lgu_cp_mdm.h

Copyright (c) 2010 by PANTECH Incorporated.  All Rights Reserved.

예)     FEATURE_LGU_CP_xxx_XXX_001
         Ver.001 : 2011-08-18 : Jake, Lee 
수정 내용 : -------------------------------------------------------------------------

1.	Custfile에 수정 내용을 자세히 작성해 주시고 해당 코드 부분엔 feature만 남도록 작성합니다.
2.	수정 내용 작성시에는 사업자 요구 사항 및 standard spec. 의 index를 우선으로 작성하시고
3.	그외 요청사항 및 side effect 등으로 내용 작성 합니다.

============================================================================= */

/*************************************************/
/*               COMMON INTERFACE                */
/*************************************************/

/*
    DDMS 를 통해서 radio log 확인을 위해서는 아래 feature를 define해야함..
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

/* SKY 자동응답기능 Interface */
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
// [kkosu] qcril_qmi_nas.c  lte_plmn_id get을 위해 local_db_lte 추가 필요 (추후적용)

#define FEATURE_LGU_CP_COMMON_ROAMING_STATE_FIX // from EF46L

#define FEATURE_LGU_CP_COMMON_ANDROID_OTASP_BLOCK // from EF46L

#define FEATURE_LGU_CP_COMMON_CARD_ABSENT_BUG_FIX // from EF46L

#define FEATURE_LGU_CP_COMMON_RUDE_WAKEUP

#define FEATURE_LGU_CP_COMMON_NITZ_LOG

#define FEATURE_LGU_CP_RIL_FW_ANDROID_REQUEST_HNDL_MAX_EVT_ID_FIX // from EF50L
#define FEATURE_LGU_CP_FW_DEDICATED_ANDROID_REQ_BUG_FIX

//#define FEATURE_LGU_CP_COMMON_OPENING_DAY // from EF46L
// [kkosu] sky raw data 관련 하여 추후 확인 후 피쳐 풀기..

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

/* QMI 를 통해서 CM system selection preference 호출 */
#define FEATURE_LGU_CP_CM_SYS_SELECTION_PREF

/* UMTS SMS MO PS/CS Domain setting menu support */
#define FEATURE_LGU_CP_SMS_CFG_SET_GW_DOMAIN

/* Phone Operation Mode setting (lpm, offline, online .. ) */
#define FEATURE_LGU_CP_PHONE_OPERATION_MODE

/* Voice Call connection sound event */
#define FEATURE_LGU_CP_GW_CS_CALL_CONNECTION_SND_START

/*
   통화중 대기음 설정을 위해 Setup ind. 에서 signal value를 설정함.
   AMSS에서 FEATURE_SKY_CP_SETUP_IND_SIGNAL_VALUE 와 반드시 연동되어야 함.
*/   
#define FEATURE_LGU_CP_GW_SETUP_IND_SIGNAL_VALUE

/* PLMN 수동 검색  */
#define FEATURE_LGU_CP_GW_NETWORK_PLMN_MANUAL_SELECTION
#ifdef FEATURE_LGU_CP_GW_NETWORK_PLMN_MANUAL_SELECTION
#define FEATURE_LGU_CP_GW_MANUAL_SELECTION_WITH_RAT
#endif/* FEATURE_LGU_CP_GW_NETWORK_PLMN_MANUAL_SELECTION */

/* Limited service상태를 구분하기 위해서 ServiceState 설정. */
#define FEATURE_LGU_CP_GW_SERVICE_STATUS_DETAIL_SUBSTATE

/* 
    Network Name을 수신했음에도 불구하고, "nas_cached_info.current_plmn" 값이 Invalid로 처리되어 
   해당 Network Name이 아닌 Table의 name을 표시하는 문제를 위해 Qcril에서 관리하는 system info를 
   state 변화시마다 update하도록 함.
   QCT는 이 system info를 LCD enable시에만 update 하도록 하고 있음
*/
#define FEATURE_LGU_CP_GW_QMI_SYS_INFO_ALWAYS_UPDATE

/* 
  단말 PS ONLY 모드로 설정시 android단에서 Reg state를 No Service로 처리하는 오류를 수정 
  CS reject, PS accept 되는 reject cause시험에서도 동일 증상 발생.
*/
#define FEATURE_LGU_CP_GW_SUPPORT_PS_ONLY_MODE

/*
   MccMnc Table 정의 ( SKT향 참조.. )
*/
#define FEATURE_LGU_CP_GW_PLMN_TABLE_LIST_SEARCH

/*
   서비스 상태 에서만 MCC/MNC 가 update 되던 부분을 Limited service상태에서도 update가 가능하도록 수정함.
*/
#define FEATURE_LGU_CP_GW_GET_MCCMNC_UPDATE_IN_LIMITED_SRV

/*
   해외 로밍시 (52501: Sing Tel) NITZ 정보가 내려오는 망에서 OP NAME 정보가 NULL은 아니지만 length가 (0)인 경우에 해당 됨.
   MCCMNC Table에서 해당 OP NAME을 뿌리다가 MM INFO 수신 이후 NAME이 안보이는 경우 수정함.
*/
#define FEATURE_LGU_CP_GW_FIX_OPERATOR_NAME_DISPLAY

/*
    망등록 시 이전 망의 property를 가져와 network name표기를 잘못하는 문제가 발생하여 수정.
*/
#define FEATURE_LGU_CP_GW_INIT_NITZ_INFO_PROPERTY

/*
   invalid code input --> network no response --> ui pop-up remain forever....
*/
#define FEATURE_LGU_CP_GW_USSD_NEWORK_NO_RESPONSE

// centralized_eons_supported  기능 동작에 따라 network name 및 manual search list 표시 오류가 발생함.
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

