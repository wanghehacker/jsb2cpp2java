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
	bool isHave = JniHelper::getStaticMethodInfo(info,"com/whe/jsbtest/Jsb2cpp2Java","getPhoneNumber","()Ljava/lang/String;");
	if(!isHave)
	{
		CCLog("此函数不存在");
	}
	else
	{
		CCLog("此函数存在");
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

