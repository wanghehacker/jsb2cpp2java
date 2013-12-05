#include "AppDelegate.h"

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "ScriptingCore.h"
#include "generated/jsb_cocos2dx_auto.hpp"
#include "generated/jsb_cocos2dx_extension_auto.hpp"
#include "jsb_cocos2dx_extension_manual.h"
#include "cocos2d_specifics.hpp"
#include "js_bindings_chipmunk_registration.h"
#include "js_bindings_system_registration.h"
#include "js_bindings_ccbreader.h"
#include "jsb_opengl_registration.h"
#include "XMLHTTPRequest.h"
#include "jsb_websocket.h"
#include "jni.h"
#include "platform/android/jni/JniHelper.h"
#include "SIMCardInfo.h"

USING_NS_CC;
using namespace CocosDenshion;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
	CCScriptEngineManager::purgeSharedManager();
}

bool AppDelegate::applicationDidFinishLaunching()
{
	// initialize director
	CCDirector *pDirector = CCDirector::sharedDirector();
	pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());

	// turn on display FPS
	pDirector->setDisplayStats(true);

	// set FPS. the default value is 1.0/60 if you don't call this
	pDirector->setAnimationInterval(1.0 / 60);

	ScriptingCore* sc = ScriptingCore::getInstance();
	sc->addRegisterCallback(register_all_cocos2dx);
	sc->addRegisterCallback(register_all_cocos2dx_extension);
	sc->addRegisterCallback(register_all_cocos2dx_extension_manual);
	sc->addRegisterCallback(register_cocos2dx_js_extensions);
	sc->addRegisterCallback(register_CCBuilderReader);
	sc->addRegisterCallback(jsb_register_chipmunk);
	sc->addRegisterCallback(jsb_register_system);
	sc->addRegisterCallback(JSB_register_opengl);
	sc->addRegisterCallback(MinXmlHttpRequest::_js_register);
	sc->addRegisterCallback(register_jsb_websocket);

	sc->start();

	CCScriptEngineProtocol *pEngine = ScriptingCore::getInstance();
	CCScriptEngineManager::sharedManager()->setScriptEngine(pEngine);
	

	CCLOG("beforecall");
	//°ó¶¨º¯Êý^
	JSContext* cx = sc->getGlobalContext();
	JSObject* obj = sc->getGlobalObject();

	JS_DefineFunction(cx,obj,"getphonenumber",getPhone,0,JSPROP_READONLY | JSPROP_PERMANENT);
	CCLOG("end call");

	ScriptingCore::getInstance()->runScript("main.js");

	return true;
}

void handle_signal(int signal) 
{
	static int internal_state = 0;
	ScriptingCore* sc = ScriptingCore::getInstance();
	// should start everything back
	CCDirector* director = CCDirector::sharedDirector();
	if (director->getRunningScene()) 
	{
		director->popToRootScene();
	} 
	else
	{
		CCPoolManager::sharedPoolManager()->finalize();
		if (internal_state == 0) 
		{
			//sc->dumpRoot(NULL, 0, NULL);
			sc->start();
			internal_state = 1;
		} 
		else
		{
			sc->runScript("hello.js");
			internal_state = 0;
		}
	}
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
	CCDirector::sharedDirector()->stopAnimation();
	SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
	SimpleAudioEngine::sharedEngine()->pauseAllEffects();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
	CCDirector::sharedDirector()->startAnimation();
	SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
	SimpleAudioEngine::sharedEngine()->resumeAllEffects();
}

JSBool getPhone( JSContext *cx, uint32_t argc, jsval *vp )
{
	if(argc == 0)
	{
		const char* pnum = SIMCardInfo::getPhoneNumber();
		std::string str(pnum);
		jsval jsret;
		jsret = std_string_to_jsval(cx,str);
		JS_SET_RVAL(cx,vp,jsret);
	}
	return 1;
}

JSBool getProvider( JSContext *cx, uint32_t argc, jsval *vp )
{
	return 1;
}





