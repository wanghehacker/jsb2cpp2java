//
//  GCTestAppDelegate.h
//  GCTest
//
//  Created by Rohan Kuruvilla on 06/08/2012.
//  Copyright __MyCompanyName__ 2012. All rights reserved.
//

#ifndef  _APP_DELEGATE_H_
#define  _APP_DELEGATE_H_

#include "CCApplication.h"
/**
 @brief    The cocos2d Application.
 
 The reason for implement as private inheritance is to hide some interface call by CCDirector.
 */
class  AppDelegate : private cocos2d::CCApplication
{
public:
    AppDelegate();
    virtual ~AppDelegate();
    
    /**
     @brief    Implement CCDirector and CCScene init code here.
     @return true    Initialize success, app continue.
     @return false   Initialize failed, app terminate.
     */
    virtual bool applicationDidFinishLaunching();
    
    /**
     @brief  The function be called when the application enter background
     @param  the pointer of the application
     */
    virtual void applicationDidEnterBackground();
    
    /**
     @brief  The function be called when the application enter foreground
     @param  the pointer of the application
     */
    virtual void applicationWillEnterForeground();


    /**
     *获取电话号码
     */
    virtual const char* getPhoneNumber();

    /**
     * 获取运营商的名字
     */
    virtual const char* getProviderName();

	
	/**
	* 供JS调用的函数
	*	获取电话号码
	*/
	virtual	JSBool getPhone(JSContext *cx, uint32_t argc, jsval *vp);

	/**
	* 供JS调用的函数
	* 获取运营商的名字
	*/
	virtual	JSBool getProvider(JSContext *cx, uint32_t argc, jsval *vp);
};

#endif // _APP_DELEGATE_H_

