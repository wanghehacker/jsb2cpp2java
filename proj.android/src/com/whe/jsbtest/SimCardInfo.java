package com.whe.jsbtest;


import android.content.Context;
import android.telephony.TelephonyManager;

public class SimCardInfo
{
	/**
	 *  电话管理器
	 */
	private TelephonyManager telephonyManager;
	
	/**
	 * 国际移动用户识别码
	 */
	private String IMSI;
	public SimCardInfo(Context context) 
	{
		telephonyManager = (TelephonyManager)context.getSystemService(Context.TELEPHONY_SERVICE);
	}
	
	public String getNativePhoneNumber() 
	{
		String phoneNumber=null;
		phoneNumber = telephonyManager.getLine1Number();
		return phoneNumber;
	}
	
	public String getProviderName() 
	{
		String providerName=null;
		IMSI=telephonyManager.getSubscriberId();
		if (IMSI.startsWith("46000")||IMSI.startsWith("46002")) {
			providerName = "中国移动";
		}
		else if (IMSI.startsWith("46001")) {
			providerName="中国联通";
		}
		else if(IMSI.startsWith("46003"))
		{
			providerName="中国电信";
		}
		
		return providerName;
	}
}
