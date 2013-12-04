package com.whe.jsbtest;


import android.content.Context;
import android.telephony.TelephonyManager;

public class SimCardInfo
{
	/**
	 *  �绰������
	 */
	private TelephonyManager telephonyManager;
	
	/**
	 * �����ƶ��û�ʶ����
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
			providerName = "�й��ƶ�";
		}
		else if (IMSI.startsWith("46001")) {
			providerName="�й���ͨ";
		}
		else if(IMSI.startsWith("46003"))
		{
			providerName="�й�����";
		}
		
		return providerName;
	}
}
