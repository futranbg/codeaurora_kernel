#ifndef __CUST_PANTECH_DS_H__
#define __CUST_PANTECH_DS_H__
/* ========================================================================
FILE: cust_pantech_ds.h

Copyright (c) 2011 by PANTECH Incorporated.  All Rights Reserved.

USE the format "FEATURE_LGT_DS_XXXX"
=========================================================================== */ 


/*===========================================================================

                      EDIT HISTORY FOR FILE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.

  when        	who     what, where, why
--------   	---      ----------------------------------------------------------
11/09/30    sjm   	  initial
11/12/22    phi   	  move to EF46L from EF65L. 
11/12/30    Alice     delete some of feature not yet adapted.
12/01/13    Alice     change file name. : Cust_pantech_data_linux.h -> CUST_PANTECH_DS.h

===========================================================================*/

/*===========================================================================*/
  //4!!ATTENTION!!
/*===========================================================================*/
/*------------------------------------------------------------------------------------

  1. must record history in this file header when you modify this file.

  2. FEEATUR's name start with "FEATURE_LGT_DS_xxx".
  
  3. each FEATURE is need to detailed description. because this file is instad of Feature Specification.
        - Item, Comment(Date, Author), Reason, Modified Files, Added Files, Deleted Files.

  4. In Java Code, Feature' exprssion is comment.
        - Exmaple. // FEATURE_LGT_DS_COMMON
        
--------------------------------------------------------------------------------------*/

/*===========================================================================
    Data Service Features
===========================================================================*/

/* 20120105 Alice : Common import, include.. etc. */
#define FEATURE_LGT_DS_COMMON

#ifdef FEATURE_LGT_DS_COMMON
/* -----------------------------------------------------------------------------------*/
    //3 Android & QCT Bug Fix
/*-------------------------------------------------------------------------------------*/

/* Item : Method - startusingnetworkfeature()
    Commnet - 20120109 Alice( merge 65L ics 20120814 jsmin)
	Reason - return value check before reconnect() belong to  startUsingNetworkFeature().
	                 -> do not return Phone.APN_REQUEST_STARTED unconditional.
	Modified files -\LINUX\android\frameworks\base\services\java\com\android\server\ConnectivityService.java
*/
#define FEATURE_LGT_DS_BUG_FIX_STARTUSINGNETWORKFEATURE

/* Item : Settings >> Data Usage
 	Commnet - 20120224 phi  ( merge 65L ics 20120814 jsmin)
  	Reason - set to Data Usage >> Set mobile data limit >> Restrict background data,
                UID/SYS_UID's setting is processed one by one as android's source architetecture.
                on the way setting if user request App., occur ANR(Application Not Responsding).
  	           - merge from EF45K
 	Modified files - NetworkPolicyManagerService.java(android\frameworks\base\services\java\com\android\server\net)
*/
#define FEATURE_SKY_DS_BACKGROUND_RESTRICT_BUG_FIX

/* Item : IPTABLEV6
 	Commnet - 20120224 phi ( merge 65L ics 20120814 jsmin)
  	Reason - /system/bin/iptables's permission is set to system permission. 
  	             on the other hands ip6tables's permission is set to shell permission.
  	             and change ip6tables's permission to system permission.
  	          - merge from EF45K
 	Modified files - android_filesystem_config.h (android\system\core\include\private)
*/
#define FEATURE_SKY_DS_IP6TABLE_UID_BUG_FIX

/* Item : Tethering  
 	Commnet - 20120329 Alice  ( merge 65L ics 20120814 jsmin)
  	Reason - when be called NetworkManagementService, change to catch exception error.
  	             RemoteException -> Exception
  	          - for IPV6
  	          - derive problem in SystemServer.
  	          - merge EF45K
 	Modified files - \LINUX\android\frameworks\base\services\java\com\android\server\connectivity\Tethering.java
*/
#define FEATURE_SKY_DS_EXCEPTION_CATCH_BUG_FIX

/* Item : DNS
 	Commnet - 20120404 Alice ( merge 65L ics 20120814 jsmin)
  	Reason - Code Bug fix about DNS setting.
 	Modified files - \LINUX\android\frameworks\base\services\java\com\android\server\ConnectivityService.java
*/
#define FEATURE_LGT_DS_DNS_IDX_BUG_FIX

/* added snapshot when QCT patch v1045 */
#define FEATURE_LGT_DS_SNAPSHOT

#ifdef FEATURE_LGT_DS_SNAPSHOT
/* Item : Icon Dispaly in No Srv
	Commnet - 20120412 Alice
	Reason - added snapshot property
	          - QCT SR Case 00825309 :CR 347576
	Modified files - qcril_qmi_nas.c(android\linux\vendor\qcom\proprietary\qcril\qcril_qmi)
*/
#undef FEATURE_LGT_DS_ICON_NO_SRV_CR347576

/* Item : Snapshot
	Commnet - 20120412 Alice
	Reason - It's too late that informed framework of entering no service.
	          - Snapshot feature disabled.
	Modified files - qcril_qmi_nas.c(android\linux\vendor\qcom\proprietary\qcril\qcril_qmi)
		               - move to init_EF46L.rc
	
*/
#undef FEATURE_LGT_DS_SNAPSHOT_DISABLED
#endif /* FEATURE_LGT_DS_SNAPSHOT */

#define FEATURE_LGT_DS_RMNET_CRASH

#ifdef FEATURE_LGT_DS_RMNET_CRASH
/* Item : rmnet crash
	Commnet - 20120412 Alice  ( merge 65L ics 20120814 jsmin)
	Reason - rmnet crash, failure to establish data connection during voice testing.
	           - QCT SR Case 00821603 :CR 350813
	Modified files - netmgr_tc.c(android\linux\vendor\qcom\proprietary\data\netmgr\src)
*/
#define FEATURE_LGT_DS_RMNET_CRASH_CR350813

/* Item : rmnet crash
	Commnet - 20120413 Alice
	Reason - The main reason for these recent netmgrd crashes is because of enabling the QoS feature 
	             by default in recent builds. If the you don't require the QoS feature then disabling it 
	             in your build might be the quickest way to resolve these problems temporarily.
	           - persist.data.netmgrd.qos.enable = false
	           - From STARQ.
	Modified files - netmgr_main.c(android\linux\vendor\qcom\proprietary\data\netmgr\src)
		               - move to init.rc
*/
#undef FEATURE_LGT_DS_RMNET_CRASH_PROPERTY_DISABLED

#endif /* FEATURE_LGT_DS_RMNET_CRASH */

/* Item : TCP Buffer
 	Commnet - 20120413 Alice( merge 65L ics 20120814 jsmin)
  	Reason - It doesn't exist TCP buffer size about EHRPD. 
  	             TCP Buffer size is choosen default size when connected to data in EHRPD.
  	             It's derived to change radio technology from EHRPD to LTE. because of keeping
  	             in Defualt TCP Buffer size.
  	          - modify to change TCP Buffer size
  	          - From EF45K.
 	Modified files - \LINUX\android\frameworks\base\core\java\android\net\MobileDataStateTracker.java
  Commnet - 20120509 Alice  ( merge 65L ics 20120814 jsmin)
  Reason - changes radiotech type for EF46L.
  
  Modified files - MobileDataStateTracker.c
*/
#define FEATURE_SKY_DS_SET_TCPBUF_IN_RAT_CHANGE



/* Item : UDP
 	Commnet - 20120618, Alice  ( merge 65L ics 20120814 jsmin)
  	Reason - https://android-review.googlesource.com/#/c/37471/
  	          - Fix an ICS DatagramPacket bug.
 	Modified files - DatagramPacket.java (android\libcore\luni\src\main\java\java\net),
                        DatagramSocket.java (android\libcore\luni\src\main\java\java\net),
                        IoBridge.java (android\libcore\luni\src\main\java\libcore\io),
                        OldDatagramSocketTest.java (android\libcore\luni\src\test\java\libcore\java\net)
*/
#define FEATURE_ICS_DATAGRAM_PKT_BUG_FIX


/* Item : Retry Count
 	Commnet - 20120810, Alice  ( merge 65L ics 20120814 jsmin)
  	Reason - Telephony : reset retry alarm count in active state

 	Modified files - DataConnection.java(frameworks\base\telephony\java\com\android\internal\telephony)
*/
#define FEATURE_LGT_DS_CR355482
/*......................................................................................................................................
  Roaming
.........................................................................................................................................*/

/* Item : Tethering, Hotspot
 	Commnet - 20120315 Yoonjunho ( merge 65L ics 20120814 jsmin)
  	Reason - When we use USB Tethering or WIFI Hotspot service,
  	         if google dns address is used in that service then we can not connect to some web site
  	       - merge EF45K modification.
  	       - include FEATURE_P_VZW_DS_TETHERING_EXCEPTION
 	Modified files - \LINUX\android\frameworks\base\services\java\com\android\server\ConnectivityService.java,
	                  Tethering.java
*/
#define FEATURE_SKY_DS_SET_TETHERED_DNS

/* Item : Data Connection
 	Commnet - 20120315 Yoonjunho  ( merge 65L ics 20120814 jsmin)
  	Reason - First data connection is disconnected and reconnected after EFS erase or APN initialization
  	       - because setPreferredApn() insert preferred apn after deletion process even though there is no preferred apn
  	       - modified to delete preferred apn only if there exist prefered apn at setPreferredApn()
  	       - merge EF47S modification
 	Modified files - GsmDataConnectionTracker.java
*/
#define FEATRUE_SKY_SET_PREFERAPN_BUG_FIX

/* Item : Data Connection
 	Commnet - 20120315 Yoonjunho
  	Reason - When we start CS call, data state is changed to disconnect state
  	       - In qcril_qmi_nas_request_data_registration_state(), preferred data tech is changed from LTE to WCDMA
  	       - modified to reload preferred data tech just before use
  	       - merge EF47S modification
 	Modified files - qcril_qmi_nas.c
*/
#define FEATURE_SKY_DS_FIX_RADIO_TECH_UNKOWN_IN_CS

/* Item : Data Connection
 	Commnet - 20120326 Yoonjunho
  	Reason - If we got Access Control 0x400, Packet Service is restricted
  	       - The spec defines AC 0x400 for emergency call so PS should not be affected by it
 	Modified files - qcril_qmi_nas.c
*/
#define FEATURE_SKY_DS_PS_RESTRICTED_BUG_FIX

/* Item : Data Connection
 	Commnet - 20120326 Yoonjunho
  	Reason - 약전계에서 pdp connection fail 후 retry timer 증가하면서 강전계 이동시에 증가된 timer 값으로 retry 하여 연결이 안되는것으로
             보이는 현상발생하여 screen on 상태에서는 timer 증가시키지 않고, off->on 될 경우 바로 try 하도록수정
  	       - merge EF45K modification
 	Modified files - DataConnectionTracker.java

 	Comment - 20120808 Alice
 	Reason - replaced of FEATURE_LGT_DS_RESET_RETRY_COUNTER
*/
#undef FEATURE_SKY_DS_IMMEDIATE_SETUP

/* -----------------------------------------------------------------------------------*/
    //3    LGU+ Request
/*-------------------------------------------------------------------------------------*/

/* Item : APN List
	Commnet - 2012  ( merge 65L ics 20120814 jsmin)
	Reason - merge to EF65L APN list, and added bearer, roaming_protocol for ICS version.
	Modified files - \LINUX\android\frameworks\base\core\res\res\xml\apns.xml
*/
#define FEATURE_LGT_DS_LTE_SINGLE_APN


/* Item : LTE Auth Check

	Commnet - 20120403 Alice   ( merge 65L ics 20120814 jsmin)
	Reason - default authType is set to RILConstants.SETUP_DATA_AUTH_NONE.
	Modified files -\LINUX\android\frameworks\base\telephony\java\com\android\internal\telephony\DataProfile.java
*/
#define FEATURE_LGT_DS_PS_AUTH_CHAP_PAP_CHECK

/* Item : DHCP
	Commnet - 20120227 Alice  ( merge 65L ics 20120814 jsmin)
	Reason - Since default DHCP Lease Time is 1 hour, 
	             VPN, RMNET and android Tethering are disconnected frequently. 
	             So, Increase the DHCP Lease Time to 7 days
	Modified files - \LINUX\android\system\netd\TetherController.cpp
*/
#define FEATURE_LGT_DS_INCREASE_DHCP_LEASETIME

/* DUN */
#define FEATURE_LGT_DS_DUN

#ifdef FEATURE_LGT_DS_DUN
/* Item : TYPE_DUN
	Commnet - 20120105 Alice
	Reason - define "TYPE_DUN" to use VT, VOIP
	Modified files - config.xml(android\frameworks\base\core\res\res\values)

	Commnet - 20120308 Alice
	Reason - merge from QCT patch 1032.
	           - priority 4 -> 2 
*/
#undef FEATURE_LGT_DS_TYPE_DUN //#define FEATURE_LGT_DS_TYPE_DUN

/* 
   Item : RestoreTimer
   Commnet - 20120618 Alice  ( merge 65L ics 20120814 jsmin)
   Reason - not used RestoreTimer : DUN, IMS
              - and HIPRI : Spec Out - but MQS Issue.
              - deleted FEATURE_LGT_DS_DISABLE_INACTIVITY_TIMER
              - concerned FEATURE_LGT_DS_LTE_MULTIPLE_APN

              - HIPRI : 5 min >> 10min

   Modified files - \LINUX\android\frameworks\base\core\res\res\values\config.xml
*/
#define FEATURE_LGT_DS_DISABLE_RESTORE_TIMER

/*Item : DUN
 	Commnet - 20120111 Alice
 	Reason - 1. QualcommSetting 디렉토리에 있는 파일들은 user mode 시 실행되지 않으므로, 
        			    dun, sync manager, data manger, curi explore가 실행되지 않음.
        			2. /dev/pantech에 File Write 권한 부여 시 CTS Fail 발생하여 /dev/pantech 권한 삭제
        			3. DUN_FIFO_FILE for DUN /data/dun -> /dev/pantech/dun
        			4. QualcommSetting 내 파일이 patch로 인해 수정되었다면, 이동된 파일들도 같이 수정해 주어야 함.
        			5. DUN_Autoboot에서 등록되는 DunService class blocking.

 	Modified files - init_EF46L.rc(android\system\core\rootdir), Android.mk(android\frameworks\base),
 				 AndroidManifest.xml (android\packages\apps\phone),
 				 DUN_Autoboot.java
 				 
	Added files - SkyPhoneBroadcastReceiver.java (android\packages\apps\phone\src\com\android\phone)
              		  IDun.aidl ->  ISkyDun.aidl (android\frameworks\base\telephony\java\com\android\internal\telephony),
              		  DunService.java -> SkyDunService.java (android\packages\apps\phone\src\com\android\phone)


   Commnet - 20120307 Alice
 	Reason - DUN service is working in user build mode. and this feature is unnecessariness.

 	Modified files - init_EF46L.rc(android\system\core\rootdir), Android.mk(android\frameworks\base),
           				 AndroidManifest.xml (android\packages\apps\phone),
           				 DUN_Autoboot.java (android\vendor\qcom\proprietary\qulacommsettings\src\com\android\qualcommsettings),
           				 SkyPhoneBroadcastReceiver.java (android\packages\apps\phone\src\com\android\phone)              		  
*/
#undef FEATURE_LGT_DS_DUN_USER_MODE//#define FEATURE_LGT_DS_DUN_USER_MODE
#endif /* FEATURE_LGT_DS_DUN */

/* Item : TCP sync retries
	Commnet - 20120104 Alice ( merge 65L ics 20120814 jsmin)
	Reason - change RTO and TCP_SYN_RETRIES when TCP syn transfer
	           - tcp resync nymber is 6.(first transfer, 1s, 2s, 4s, 8s)
	Modified files - tcp.h(android\kernel\include\net), tcp_output.c(android\kernel\net\ipv4)
*/
#define FEATURE_LGT_DS_TCP_SYN_RETRANSMIT

/* Item : DNS
	Commnet - 20120111 Alice  ( merge 65L ics 20120814 jsmin)
	Reason - do not query DNS IPv6.
	Modified files - \LINUX\android\bionic\libc\netbsd\net\getaddrinfo.c
*/
#define FEATURE_LGT_DS_IPV6_DNS_QUERY

/* EVDO/EHRPD Error */
#define FEATURE_LGT_DS_EVDO_ERROR

#ifdef FEATURE_LGT_DS_EVDO_ERROR
/* Item : EVDO/EHRPD Error
	Commnet - 20120113 Alice ( merge 65L ics 20120816 jsmin)
	Reason - In AMSS side found out EVDO/EHRPD Error, 
	             write EVDO/EHRPD error cause to property_set(ril.cdma.errorcause) in QCRIL.
	Modified files - 
	\LINUX\android\vendor\qcom\proprietary\data\dss\src\dsc_qmi_wds.h
    \LINUX\android\vendor\qcom\proprietary\data\dss\src\dsc_qmi_wds.c
    \LINUX\android\vendor\qcom\proprietary\qmi\inc\qmi_wds_srvc.h
    \LINUX\android\vendor\qcom\proprietary\qcril\common\data\qcril_data_netctrl.c
*/
#define FEATURE_LGT_DS_EVDO_ERROR_REASON

/* Item : EVDO/EHRPD Error
	Commnet - 20120213 Alice( merge 65L ics 20120816 jsmin)
	Reason - after read EVDO/EHRPD Error casue in property(ril.cdma.errorcause) 
	             show the Pop-up Message or Toast and write Error cause to other property(ril.cdma.wipinetval).
	Modified files -  DataConnectionTracker.java,
	                     CdmaDataConnectionTracker.java, GsmDataConnectionTracker.java,
	                     Strings_ds.xml (msm8960ics\linux\android\vendor\pantech\overlay\frameworks\base\core\res\res\values),
	                     Strings_ds.xml (msm8960ics\linux\android\vendor\pantech\overlay\frameworks\base\core\res\res\values-ko)
*/
#define FEATURE_LGT_DS_EVDO_ERROR_MESSAGE


/*
    Item : EVDO/EHRPD Error
    Commnet - 20121129 jsmin
    Reason - °£ÇæÀûÀ¸·Î radio tech 1x »óÅÂ chap fail3È¸  ÆË¾÷ Ç¥½Ã ¾ÈµÇ´Â ¹®Á¦
     Modified files -  DataConnectionTracker.java,
*/

#define FEATURE_LGT_DS_EVDO_ERROR_MESSAGE_FIX
#endif /* FEATURE_LGT_DS_EVDO_ERROR */

/* Item : Emergency Call
	Commnet - 20120118 Alice ( merge 65L ics 20120816 jsmin)
	Reason - keep connecting the Data Call after Emergency call end.
	Modified files - \LINUX\android\frameworks\base\telephony\java\com\android\internal\telephony\cdma\CdmaCallTracker.java
*/
#define FEATURE_LGT_DS_NO_TEARDOWN_DATA_EMERGENCYCALL

/* Item : Connectivity(Dormancy)
	Commnet - 20120126 Alice
	Reason - when screen off, change CTA Timer to 3 sec.
	          - !Warning! pre-define FEATURE_LGT_DS_FAST_DORMANCY
	Modified files - Android.mk (android\frameworks\base),
				            DataConnectionTracker.java
					 
	Added files - Android.mk(android\vendor\qcom\proprietary\cds_native),
			     OdsNative.java(android\vendor\qcom\proprietary\cds_native\java\com\pantech\monitor)		 
	
	Moving files - android\vendor\qcom\proprietary\cds_native\*-> android\vendor\qcom\proprietary\cds_native\jni\*
*/
#define FEATURE_LGT_DS_FAST_DORMANCY

/* Item : Connectivity
 	Commnet - 20120215 Alice ( merge 65L ics 20120814 jsmin)
  	Reason - 1. only try to connect Data call when EVDO_REV_0/EVDO_REV_A 
  	                -> 1x Data call isn't possible.
  	             2. do not try to connect Data call IPV6 in LTE/EHRPD system.
  	                -> but possible aborad.
 	Modified files - \LINUX\android\frameworks\base\telephony\java\com\android\internal\telephony\cdma\CdmaDataConnection.java
	                   \LINUX\android\frameworks\base\telephony\java\com\android\internal\telephony\gsm\GsmDataConnection.java
*/
#define FEATURE_LGT_DS_RESTRICT_DATA_CALL
/*

	Commnet -  ( merge 65L ics 20120816 jsmin)

 	Modified files - 
CdmaDataConnectionTracker.java (msm8960ics\linux\android\frameworks\base\telephony\java\com\android\internal\telephony\cdma)
CDMAPhone.java (msm8960ics\linux\android\frameworks\base\telephony\java\com\android\internal\telephony\cdma)
DataConnectionTracker.java (msm8960ics\linux\android\frameworks\base\telephony\java\com\android\internal\telephony)
GsmDataConnectionTracker.java (msm8960ics\linux\android\frameworks\base\telephony\java\com\android\internal\telephony\gsm)
GSMPhone.java (msm8960ics\linux\android\frameworks\base\telephony\java\com\android\internal\telephony\gsm)
Phone.java (msm8960ics\linux\android\frameworks\base\telephony\java\com\android\internal\telephony)
PhoneBase.java (msm8960ics\linux\android\frameworks\base\telephony\java\com\android\internal\telephony)
PhoneProxy.java (msm8960ics\linux\android\frameworks\base\telephony\java\com\android\internal\telephony)
SkyDataConInterfaceManager.java (msm8960ics\linux\android\frameworks\base\telephony\java\com\android\internal\telephony)

*/
#define FEATURE_LGT_DS_ADD_DATA_SUSPEND_FUNC     

/* Item : Data On/off customize
	Commnet - 20120128 Ksg  ( merge 65L ics 20120814 jsmin)
	Reason - support data on/off for LG U+ request
	Modified files - DataConnectionTracker.java (android\frameworks\base\telephony\java\com\android\internal\telephony),
	                 EasySetting.java (android\frameworks\base\packages\SystemUI\src\com\android\systemui\statusbar\easysetting),
	                 ISkyDataConnection.aidl (android\frameworks\base\telephony\java\com\android\internal\telephony),
	                 Settings.java (android\packages\apps\Phone\src\com\android\phone),
	                 SkyDataConInterfaceManager.java (android\frameworks\base\telephony\java\com\android\internal\telephony)
*/
#define FEATURE_LGT_DS_PS_DISABLE

/* Item : Data On/off Property
	Commnet - 20120128 Ksg  ( merge 65L ics 20120814 jsmin)
	Reason - Manage pantech's customized Data on/off property
	Modified files - ConnectivityService.java (android\frameworks\base\services\java\com\android\server),
	                 DatabaseHelper.java (android\frameworks\base\packages\SettingsProvider\src\com\android\providers\settings),
	                 DataConnectionTracker.java (android\frameworks\base\telephony\java\com\android\internal\telephony),
	                 GpsLocationProvider.java (android\frameworks\base\services\java\com\android\server\location),
	                 ISkyDataConnection.aidl (android\frameworks\base\telephony\java\com\android\internal\telephony),
	                 Settings.java (android\frameworks\base\core\java\android\provider),
	                 SkyDataConInterfaceManager.java (android\frameworks\base\telephony\java\com\android\internal\telephony)
*/
#define FEATURE_LGT_DS_GET_SECUREDB_FOR_LGT

/* Item : stop all using networks
	Commnet - 20120128 Ksg ( merge 65L ics 20120814 jsmin)
	Reason - When disconnect Data, remove all networks.
	Modified files - ConnectivityService.java (android\frameworks\base\services\java\com\android\server),
	                 DataConnectionTracker.java (android\frameworks\base\telephony\java\com\android\internal\telephony),
	                 IConnectivityManager.aidl (android\frameworks\base\core\java\android\net)
					 \LINUX\android\frameworks\base\core\java\android\net\ConnectivityManager.java
					 
*/
#define FEATURE_LGT_DS_DISCONNECT_ALL_NETWORK_FEATURE

/* EasySetting : 3G ON/OFF menu */
#define FEATURE_LGT_DS_DATA_MENU_POPUP

#ifdef FEATURE_LGT_DS_DATA_MENU_POPUP

/* Item : 3G/4G data on/off toast
	Commnet - 20120128 Ksg ( merge 65L ics 20120816 jsmin)
	Reason - Show Data Conn/Disconn info toast
	Modified files - DataConnectionTracker.java (android\frameworks\base\telephony\java\com\android\internal\telephony)
*/
#define FEATURE_LGT_DS_DATA_MENU_TOAST

/* Item : 3G/4G boot-up Connection/Disconnection Dialog
	Commnet - 20120128 Ksg  ( merge 65L ics 20120816 jsmin)
	Reason - Show Boot-up Dialog that use for Data Conn/Disconn
	Modified files - CdmaDataConnectionTracker.java (android\frameworks\base\telephony\java\com\android\internal\telephony\cdma),
	                 DatabaseHelper.java (android\frameworks\base\packages\SettingsProvider\src\com\android\providers\settings),
	                 DataConnectionTracker.java (android\frameworks\base\telephony\java\com\android\internal\telephony),
	                 GsmDataConnectionTracker.java (android\frameworks\base\telephony\java\com\android\internal\telephony\gsm),
	                 ISkyDataConnection.aidl (android\frameworks\base\telephony\java\com\android\internal\telephony),
	                 Settings.java (android\frameworks\base\core\java\android\provider),
	                 SkyDataConInterfaceManager.java (android\frameworks\base\telephony\java\com\android\internal\telephony),
                     Strings_ds.xml (android\vendor\pantech\overlay\frameworks\base\core\res\res\values),
	                 Strings_ds.xml (android\vendor\pantech\overlay\frameworks\base\core\res\res\values-ko)
*/
#define FEATURE_LGT_DS_3G_DATA_MENU_POPUP

/* Item : 3G/4G Boot-up pop-up fix
	Commnet - 20120128 Ksg  ( merge 65L ics 20120816 jsmin)
	Reason - Fix & add something at FEATURE_LGT_DS_3G_DATA_MENU_POPUP
	Modified files - CdmaDataConnectionTracker.java (android\frameworks\base\telephony\java\com\android\internal\telephony\cdma),
                     GsmDataConnectionTracker.java (android\frameworks\base\telephony\java\com\android\internal\telephony\gsm)
*/
#define FEATURE_LGT_DS_3G_DATA_MENU_POPUP_BUG_FIX

/* Item : Non-IMEI
 	Commnet - 20120229 Alice
 	Reason - Invalid IMEI Check, Do not pop-up to enable data when booting.
 	          - instead of "FEATURE_LGT_DS_NO_DATA_POPUOP_WHEN_UNAVAILABLE_UICC"
 	Modified files - CDMAPhone.java(linux\android\frameworks\base\telephony\java\com\android\internal\telephony\cdma), 
 	                     DataConnectionTracker.java,
 	                     CdmaDataConnectionTracker.java,
 	                     GsmDataConnectionTracker.java                 
*/

#define FEATURE_LGU_DS_CHECK_IMEI // #define FEATURE_LGT_DS_NO_DATA_POPUOP_WHEN_UNAVAILABLE_UICC
#endif /* FEATURE_LGT_DS_DATA_MENU_POPUP */

/* Item : Eng Menu
 	Commnet - 20120128 Alice
*/
#define FEATURE_LGT_DS_ENG_MENU

#ifdef FEATURE_LGT_DS_ENG_MENU
/* Item : Dun Setting
 	Commnet - 20120128 Alice
  	Reason - Feature "DS1_DS_LGT_DUN_SETTING_1" 우선 적용 되어 있어야 함.
  		    - ENG MENU의 DUN On/Off Menu 구현.
 	Modified files - LgtSkyEngMenu.java,  
                        - Cpmgrif.c
                      - Cpmgrif.h
                      - Cpmgrnative.cpp
                      - ISkyTelephony.aidl
                      - LgtSkyEngMenu.java
                      - Oem_rapi_fusion.h
                      - SkyTelephonyInterfaceManager.java
 	
*/
#define FEATURE_LGT_DS_ENG_DUN_MENU

/* Item : Alwayson Setting
 	Commnet - 20120128 Alice
  	Reason - FEATURE_LGT_DS_PS_DISABLE 우선 적용 되어 있어야 함.
  		       - ENG Menu의 AlwasyOn/Off API 적용
 	Modified files - LgtSkyEngMenu.java,


*/
#define FEATURE_LGT_DS_ENG_3G_MENU
#endif /* FEATURE_LGT_DS_ENG_MENU */

/*......................................................................................................................................
  Roaming
.........................................................................................................................................*/

/* Item : Roaming Data Connection
 	Commnet - 20120315 Yoonjunho
  	Reason - Show roaming data connection dialog box when we are in roaming area
 	Modified files - DataConnectionTracker.java, GsmDataConnectionTracker.java, ISkyDataConnection.aidl, SkyDataConInterfaceManager.java
 	               - Strings_ds.xml (linux\android\vendor\pantech\overlay\frameworks\base\core\res\res\values\)
 	               - Strings_ds.xml (linux\android\vendor\pantech\overlay\frameworks\base\core\res\res\values-ko\)
*/
#define FEATURE_LGT_DS_ROAMING_DATA_MENU_POPUP

/* Item : Roaming Data Connection
 	Commnet - 20120315 Yoonjunho
  	Reason - Check whether PS domain attachment is rejected or not when we are in roaming area
 	Modified files - DataConnectionTracker.java, GsmDataConnectionTracker.java
*/
#define FEATURE_LGT_DS_PS_REJECT

/* Item : Roaming Data Connection
 	Commnet - 20120315 Yoonjunho
  	Reason - Disable data connection menu in easy setting when we are in roaming area
 	Modified files - GsmDataConnectionTracker.java, GsmServiceStateTracker.java
*/
#define FEATURE_LGT_DS_ALWAYSON_MENU_DISABLED_IN_ROAMING

/* Item : Roaming Data Connection
 	Commnet - 20120510 Yoonjunho
  	Reason - Change default APN with "wroaming.lguplus.co.kr" when we are in roaming area
 	Modified files - GsmDataConnectionTracker.java, Qcril_data_netctrl.c
*/
#define FEATURE_LGT_DS_ROAMING_APN_CHANGE

/* -----------------------------------------------------------------------------------*/
    //3 Issue Follow up
/*-------------------------------------------------------------------------------------*/
/* Item : Data Connection Interface, AIDL
	Commnet - 20120104 Alice  ( merge 65L ics 20120814 jsmin)
	Reason - Phone Interface를 접근 못하는 APP를 위하여 AIDL을 추가

	Modified files - Android.mk(LINUX\android\frameworks\base), 
			              service_manager.c(LINUX\android\frameworks\base\cmds\servicemanager),
				           DataConnectionTracker.java (msm8960ics\linux\android\frameworks\base\telephony\java\com\android\internal\telephony)
				           
	Added files - ISkyDataConnection.aidl (LINUX\android\frameworks\base\telephony\java\com\android\internal\telephony),
			            SkyDataConInterfaceManager.java (LINUX\android\frameworks\base\telephony\java\com\android\internal\telephony)
*/
#define FEATURE_LGT_DS_ADD_DATA_AIDL

/* Item : Toast
	Commnet - 20120105 Alice ( merge 65L ics 20120814 jsmin)
	Reason - (2011.12.01 PLM Issue 1341)
	             Data 접속 시도 시 접속 중 Toast Display
	             wifi -> 3G/4G Connect 일 시 Connection Toast 출력하도록 수정
	Modified files -\LINUX\android\frameworks\base\services\java\com\android\server\ConnectivityService.java
*/
#define FEATURE_LGT_DS_DATA_CONNECTION_TOAST

/* Item : CNE
 	Commnet - 20120105 Alice  
 	Reason - CNE Enable로 인해 Wifi접속 후 3G 연결 시 DefaultRoute가 Set 되지 않아 인터넷 연결할 수 없음.
 	Modified files - init.rc(LINUX\android\system\core\rootdir)
*/
#define FEATURE_LGT_DS_DISABLE_CNE
 
/* Item : Max windowsize/memsize for LTE
 	Commnet - 20120105 Alice, 20120202 Alice 
 	Reason - change max windowsize/memsize for LTE
 	          -  FEATURE_SKY_DS_SET_TCPBUF_IN_RAT_CHANGE
 	Modified files - init.rc(LINUX\android\system\core\rootdir)
*/
#define FEATURE_LGT_DS_TCP_BUFFER_FOR_LTE

/* Item : MTU
 	Commnet - 20120105 Alice, 20120202 Alice
 	Reason - change MTU size for LTE
 		    - deleted usb0 interface set MTU size and change TCP MSS for tethering by NAT
 		       (merged MirachJ)
 	Modified files - init.rc(LINUX\android\system\core\rootdir),
                       msm8660-perf-EF65L_TP20_defconfig(LINUX\android\kernel\arch\arm\configs),
 				         \LINUX\android\system\netd\NatController.cpp
*/
#define FEATURE_LGT_DS_USB_KERNEL_MTU_SETTING

/* Item : DNS
 	Commnet - 20120105 Alice  ( merge 65L ics 20120814 jsmin)
 	Reason - dns check 부분에서 null_ip 를 0.0.0.0 인 경우 만 체크하는 문제
 			       null 인 경우(length가 0)도 체크하도록 수정.
 	Modified files -\LINUX\android\frameworks\base\telephony\java\com\android\internal\telephony\cdma\CdmaDataConnection.java,
	                 \LINUX\android\frameworks\base\telephony\java\com\android\internal\telephony\gsm\GsmDataConnection.java
*/
#define FEATURE_LGT_DS_PS_NULL_DNS_CHECK

/* Item : Data Connection
 	Commnet - 20120111 Alice ( merge 65L ics 20120816 jsmin)
 	Reason - data connection fail cause 에 대해 처리되지 않는 문제
 	             fail 발생시 cause query 하도록 수정.
 	Modified files - DataConnection.java(android\frameworks\base\telephony\java\com\android\internal\telephony)
*/
#define FEATURE_LGT_DS_PS_FAIL_CAUSE

/* Item : Data Connection
 	Commnet - 20120111 Alice ( merge 65L ics 20120816 jsmin)
 	Modified files - DataConnection.java(android\frameworks\base\telephony\java\com\android\internal\telephony)
*/
#define FEATURE_LGT_DS_PS_FAIL_CAUSE_FATAL_EXCEPTION

/* Item : DNS
 	Commnet - 20120113 Alice  ( merge 65L ics 20120814 jsmin)
 	Reason - data disconnect 된 순간_test_dns check 수행해서 mms 전송하려고 
 			      Inetaddress.getbyname 하면 unknown host exception 발생하는 문제 
 	Modified files -\LINUX\android\bionic\libc\netbsd\net\getaddrinfo.c
*/
#define FEATURE_LGT_DS_DISABLE_TEST_DNS

/* Item : Data Connection
 	Commnet - 20120113 Alice ( merge 65L ics 20120814 jsmin)
 	Reason - VT(startusingnetworkfeature(), TYPE_DUN) 시, 
 			      "168.126.63.1"/"168.126.63.2" 에 대해서 ROUTE TABLE 등록 하지 않음.
 	Modified files - \LINUX\android\frameworks\base\services\java\com\android\server\ConnectivityService.java
*/
#define FEATURE_LGU_DS_3G_DNS_REMOVE_IN_ROUTETABLE

/* Item : RADIO
	Commnet - 20120113 Alice
   Reason - RADIO Tech가 Data Connection state, qcril단 정보와 일치 하지 않는 경우.
*/
#define FEATURE_LGU_DS_UNKNOWN_RADIO

#ifdef FEATURE_LGU_DS_UNKNOWN_RADIO
/* Item : RADIO
	Commnet - 20120113 Alice   ( merge 65L ics 20120816 jsmin)
	Reason - preferred data radio tech 중 eHRPD 가 QMI_WDS 에서 전달되지 않아 Preferred mode change 시 
	             LTE 값 유지하고, 이로인해 pdt_modem_id  에러 처리되는 문제 수정.
	Modified files - qcril_arb.c(android\vendor\qcom\proprietary\qcril\qcril_fusion), 
*/
#define FEATURE_LGT_DS_PS_UNKNOWN_RADIO_TECH

/* Item : RADIO
	Commnet - 20120113 Alice  ( merge 65L ics 20120816 jsmin)
	Reason - OOS(Out of Service) 인 경우(RADIO TECH UNKNOWK), Framework에서  networkinfo.available() 이
	             false로 설정되어 AMSS가 실제 Network 연결 상태, 즉 데이터 연결 중임에도
	             App.에서 연결이 끊어진 것으로 인식하는 문제 수정.
	Modified files - MobileDataStateTracker.java,	
				 NetworkController.java (android\frameworks\base\packages\systemui\src\com\android\systemui\statusbar\policy)	 
*/
#define FEATURE_LGT_DS_AVOID_OOS_FOR_APP

/* Item : RADIO
 	Commnet - 20120320 Alice  ( merge 65L ics 20120816 jsmin)
 	Reason - set to false "TelephonyProperties.PROPERTY_OOS_IS_DISCONNECT".
 	           - if mOosIsDisconnect == true, changed data connection to disconnection as soon as entering no-service.
 	           - cause confusion in App. layer.
 	           - merge from EF47S.
 	Modified files - \LINUX\android\frameworks\base\telephony\java\com\android\internal\telephony\PhoneBase.java
*/
#define FEATURE_LGT_DS_OOS_PROPERTY_INITIAL_VAL

#endif /* FEATURE_LGU_DS_UNKNOWN_RADIO */

/* Item : VPN
 	Commnet - 20120117 Alice ( merge 65L ics 20120816 jsmin)
 	Reason - VPN Editing -> Null check
 	Modified files - \LINUX\android\packages\apps\Settings\src\com\android\settings\vpn2\VpnDialog.java
*/
#define FEATURE_LGT_DS_VPN_SPACE_CHECK

/* Item : VPN
 	Commnet - 20120117 Alice, 20120217 Alice  ( merge 65L ics 20120816 jsmin)
 	Reason - 1. VPN BUG FIX :  just function execution's order change.
	              -> L2tp.c 	
 	             2. added a few compile option
 	             3. adapted to new file (msm8960_ef46l_tp20_defconfig)
 	Modified files  L2tp.c(LINUX\android\external\mtpd),
 	                  msm8660-perf-EF65L_TP20_defconfig(LINUX\android\kernel\arch\arm\configs), 	   	
*/
#define FEATURE_LGT_DS_VPN_FIX

/* Item : Interface Name
 	Commnet - 20120118 Alice 
  	Reason - change to Rmnet Interface name : rmnet_sdioX -> rmnet 
 	Modified files - HandsetProperty.java (android\frameworks\base\core\java\android\lgt\handset)
*/
#define FEATURE_LGT_DS_RMNET_INTERFACE_NAME

#define FEATURE_LGT_DS_CTS

#ifdef FEATURE_LGT_DS_CTS
/* Item : UID_STAT CONFIG
 	Commnet - 2012 ksg.  ( merge 65L ics 20120816 jsmin)
 	Reason - enable UID_STAT=y for TrafficStats(CTS TEST Fail)
 	Modified files -msm8660-perf-EF65L_TP20_defconfig(LINUX\android\kernel\arch\arm\configs),
*/
#define FEATURE_LGT_DS_UID_TRAFFIC_STATS_ENABLE

/* Item : HTTP 
 	Commnet - 20120405 Alice  ( merge 65L ics 20120816 jsmin)
 	Reason - blocking error exception (CTS TEST Fail)
 	Modified files -HttpEngine.java (android\libcore\luni\src\main\java\libcore\net\http)
*/
#define FEATURE_LGT_DS_HTTP_ENGINE

#endif /* FEATURE_LGT_DS_CTS */

/* Item : MMS
 	Commnet - 20120217 Alice  ( merge 65L ics 20120816 jsmin)
  	Reason - MMS App. Request.
            - added "isAvailableForMms" return to connection state of mobile_mms before "startUsingNetworkFeature" 
            - return true :: AlwaysOnSetting true, AuthFail false, DC.FailCause not permanantfail, In service.

            - added getServiceState:: for No service.
            - as 1x Data Disable return false when RadioTech is 1x
            
    Modified files - ISkyDataConnection.aidl, SkyDataConInterfaceManager.java,
 	                    MobileDataStateTracker.java, DataConnectionTracker.java
*/
#define FEATURE_LGT_DS_CHECK_NETWORK_AVAILABLE_FOR_MMS

#define FEATURE_LGT_DS_NETWORK_TOOL

#ifdef FEATURE_LGT_DS_NETWORK_TOOL
/* Item : BUSYBOX 
	Commnet - 20120404 Alice
	Reason - busybox install for root(eng) version 1.19.0
	          - merge from STARQ
	Modified files - init.rc (android\system\core\rootdir)
   Added files - busybox folder all (android\pantech\development\busybox)
*/
#define FEATURE_LGT_DS_BUSYBOX_INSTALL

/* Item : IPERF 
	Commnet - 20120404 Alice
	Reason - iperf install for root, version : 2.0.5 (08 Jul 2010)
	          - merge from STARQ	
	Modified files - init.rc (android\system\core\rootdir)
   Added files - iperf folder all (android\pantech\development\iperf)
*/
#define FEATURE_LGT_DS_IPERF_INSTALL
#endif /* FEATURE_LGT_DS_NETWORK_TOOL */

/* Item : Tethering 
	Commnet - 20120404 Alice ( merge 65L ics 20120814 jsmin)
	Reason - enable DIAG port when usb tethering.
	          - merge from STARQ	
	Modified files - Tethering.java (frameworks\base\services\java\com\android\server\connectivity),
	                 UsbManager.java (frameworks\base\core\java\android\hardware\usb)
*/
#define FEATURE_LGT_DS_ADD_DIAG_PORT_WHEN_TETHERING

/* Item : NetworkInfo
 	Commnet - 20120417 Alice  ( merge 65L ics 20120816 jsmin)
  	Reason - NetworkInfo isAvailable is false when APN State is failed
  	          - merge From STARQ, FEATURE_P_VZW_DS_APN_FAILED_STATE_BUG
 	Modified files - GsmDataConnectionTracker.java
*/
#define FEATURE_LGT_DS_APN_FAILED_STATE_BUG


/* Item : Route
 	Commnet - 20120418 Alice( merge 65L ics 20120814 jsmin)
  	Reason - Reconnect when routing add failed.
  	          - If occured failure to add Route, do tear down and try to reconnect after 3 sec.
  	          - merge From STARQ, FEATURE_P_VZW_DS_ROUTE_ADD_FAIL
 	Modified files - ConnectivityService.java(frameworks\base\services\java\com\android\server),
 	                     NetworkStateTracker.java (frameworks\base\core\java\android\net),
 	                     MobileDataStateTracker.java (frameworks\base\core\java\android\net),

  below files - implements NetworkStateTracker
  
                        BluetoothTetheringDataTracker.java (frameworks\base\core\java\android\bluetooth),
                        DummyDataStateTracker.java (frameworks\base\core\java\android\net)
                        EthernetDataTracker.java (frameworks\base\core\java\android\net),
 	                     WifiStateTracker.java (frameworks\base\wifi\java\android\net\wifi)
*/
#define FEATURE_LGT_DS_ROUTE_ADD_FAILURE

/* Item : Tethering
 	Commnet - 20120418 Alice ( merge 65L ics 20120814 jsmin)
  	Reason - at the same time USB tethering and WiFi Hotstop, DATA off -> DATA on -> WiFi on
  	             display both WiFi icon and DATA icon for a few seconds. maybe the longest 60 sec.
  	           - after startUsingNetworkFeature, don't call stopUsingNetworkFeature
  	              now, when IMS de-registration, call stopUsingNetworkFeature.
  	           - If IMS doesn't call stopUsingNetworkFeature, do stopUsingNetworkFeature.
 	Modified files - Tethering.java (frameworks\base\services\java\com\android\server\connectivity)
*/
#define FEATURE_LGT_DS_DISPLAY_WIFI_DATA_ICON_WHEN_TETHERING

/* Item : RADIO

  Commnet - 20120105 Alice  ( merge 65L ics 20120816 jsmin)
  Reason - Preferred data tech는 1x이지만 MDM은 LTE로 동작하는 경우가 발생하여 
               LTE Service available이면 Radio tech을 LTE로 수정
  Modified files - qcril_cm.c(android\vendor\qcom\proprietary\qcril\qcril_fusion)
*/
#define FEATURE_LGT_DS_DATA_RADIO_TECH_FIX

/*
//20120730 sjm
- Check Data onoff in startUsingNetworkFeature()
   ConnectivityService.java(frameworks\base\services\java\com\android\server)
*/
#define FEATURE_LGT_DS_WPS_CHECK_DATA_ONOFF
/*
//20120808 sjm
- do not wait to expire data retry timer for 30 mins when RSSI(Received Signal Strength Indication) iw weak
   DataConnectionTracker.java
*/

#define FEATURE_LGT_DS_RESET_RETRY_COUNTER

/*20111005 sjm
- ACTION_ANY_DATA_CONNECTION_STATE_CHANGED 를 phoneStateListener 보다 우선 처리되도록 변경.
- PhoneStateListener처리에서 syncronized 이후 intent action broadcasting 되지 않는 경우 1회 발생.
- TelephonyRegistry.java
*/
#define FEATURE_LGT_DS_DATA_CON_INTENT_FAST_BROADCASTING


/*
//20120723 sjm (from  merge 50L ics 20120828 jsmin)
- Tethering DNS Forward Error Fix from SKT 
   Tethering.java (apq8064\frameworks\base\services\java\com\android\server\connectivity)
*/
#define FEATURE_LGT_DS_TETHERING_DNS_FORWARD

/*20120831 jsmin 
Reason - change apn db  at the ics upgrade (not efs delete)
Modified files -apns.xm
                     Telephony.java
                    Telephonyprovider.java

*/
#define FEATURE_LGT_DS_APN_DB_UPGRADE
#define  FEATURE_LGT_DS_CHECK_NULL_POINTER_EXCEPTION




/*
//20120727 sjm
Reason - Ignore APN Changed event due to setRoaminAPN()
Modified files - DataConnectionTracker.java (msm8660\linux\android\frameworks\base\telephony\java\com\android\internal\telephony)
                      GsmDataConnectionTracker.java (msm8660\linux\android\frameworks\base\telephony\java\com\android\internal\telephony\gsm)
*/
#define  FEATURE_LGT_DS_IGNORE_APN_CHANGED


 /*
 - 20120816 sjm
Reason - immediatly send Connection_action intent 
Modified files - ConnectivityService.java (msm8660\frameworks\base\services\java\com\android\server)
 */
 #define FEATURE_LGT_DS_CONNECTIVTY_INTENT_IMMEDIATE


 /*
 - 20120905 sjm
 - SilentReset when modify route
 - Add try/catch and syncronized
 ConnectivityService.java (msm8660\frameworks\base\services\java\com\android\server)
 */
 #define FATURE_LGT_DS_CONCURRENTMODIFICATIONEXCEPTION

 /*
 - 20120912 sjm
 - APN State Bug WorkAround Code
Modified files - GsmDataConnectionTracker.java (msm8660\frameworks\base\telephony\java\com\android\internal\telephony\gsm)
 */
 #define FEATURE_LGT_DS_APN_STATE_FIX


/*
- 20120918 sjm
- Change mutex time to 300ms for fixing ANR
Modified files -NetworkPolicyManagerService.java (msm8660\frameworks\base\services\java\com\android\server\net)
*/
#define FEATURE_LGT_DS_RELEASE_MUTEX_TIME

/*
-20121012 jsmin
Reason - not display App DATA  OFF POPUP  in the U+phonebook sync APP (when data off) 
Modified files - DataConnectionTracker.java
*/
#define FEATURE_LGT_DS_PBSYNC_CHECK_DATA_ONOFF

/*
-20130320 jsmin
Reason - not  execute  App MMS (when data off and data roaming on ) 
 ConnectivityService.java (msm8660\frameworks\base\services\java\com\android\server)
*/
#define FEATURE_LGT_DS_ROAMING_DATAOFF
/*......................................................................................................................................
  Roaming
.........................................................................................................................................*/

/* Item : Data Connection
 	Commnet - 20120406 Yoonjunho
  	Reason - ISkyDataConnection에 3rd parth app에서 데이터 사용량 초과 제한을 판단할 수 있는 API 추가
 	Modified files - SkyDataConInterfaceManager.java, ISkyDataConnection.aidl, DataConnectionTracker.java
*/ 
#define FEATURE_LGT_DS_NET_OVERLIMIT_API


#endif /* FEATURE_LGT_DS_COMMON */

/*===========================================================================
    Others
===========================================================================*/

/* Item : Log change (Radio -> Main)
	Commnet - 20120119 hongss  ( merge 65L ics 20120814 jsmin)
	Reason - change buffer to print Data Framework log, RADIO BUFFER -> MAIN BUFFER.
	Modified files - connetivityservice.java(frameworks\base\services\java\com\android\server),
	                 mobiledatastatetracker.java(frameworks\base\core\java\android\net),
	                 \LINUX\android\system\core\liblog\logd_write.c
                          
	Commnet - 20120320 Alice
	Reason - change buffer to print Data Framework log, RADIO BUFFER -> MAIN BUFFER.
	             for Data Call State.
	          - merge from STARQ : FEATURE_P_VZW_DS_DATA_CALL_STATE_LOG 
	Modified files - \LINUX\android\frameworks\base\telephony\java\com\android\internal\telephony\gsm\GsmDataConnectionTracker.java
*/
#define FEATURE_LGT_DS_PS_CHANGE_RADIO_LOG

#endif/* __CUST_PANTECH_DS_H__ */


