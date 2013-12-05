#include "SIMCardInfo.h"
#include "..\..\..\cocos2dx\platform\android\jni\JniHelper.h"


SIMCardInfo::SIMCardInfo()
{

}

SIMCardInfo::~SIMCardInfo()
{

}

const char* SIMCardInfo::getPhoneNumber()
{
#if(CC_TARGET_PLATFORM==CC_PLATFORM_ANDROID)
	JniMethodInfo info;
	bool isHave = JniHelper::getStaticMethodInfo(info,"com/whe/jsbtest/Jsb2cpp2Java","getPhoneNumber","(V)java/lang/String");
	if(!isHave)
	{
		CCLog("�˺���������");
	}
	else
	{
		CCLog("�˺�������");
		jobject obj = info.env->CallStaticObjectMethod(info.classID,info.methodID);
		const char* num = info.env->GetStringUTFChars((jstring)obj,0);
		return num;
	}
#endif
	return "not Android plantform";
}

const char* SIMCardInfo::getProviderName()
{
	return "";
}

