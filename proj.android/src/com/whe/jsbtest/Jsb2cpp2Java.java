/****************************************************************************
Copyright (c) 2010-2012 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
package com.whe.jsbtest;

import org.cocos2dx.lib.Cocos2dxActivity;

import android.content.Context;
import android.os.Bundle;

/**
 * @author wanghe
 *
 */
public class Jsb2cpp2Java extends Cocos2dxActivity{
	
	protected void onCreate(Bundle savedInstanceState){
		super.onCreate(savedInstanceState);
		instance = this;
	}
	
    static {
        System.loadLibrary("cocos2djs");
    }
    
    /**
     * 临时实例
     */
    public static Jsb2cpp2Java instance;
    
    /**
     * 获取当前的Activity实例
     * @return
     */
    public static Jsb2cpp2Java getInstance() {
		if(instance==null)
		{
			instance = new Jsb2cpp2Java();
		}
		return instance;
	}
    
    /**
     * 获取电话号码
     * @return
     */
    public static String getPhoneNumber() {
		SimCardInfo info = new SimCardInfo((Context)getInstance());
		return info.getNativePhoneNumber();
	}
    
    /**
     * 获取运营商的名字
     * @return
     */
    public static String getProviderNamer() {
    	SimCardInfo info = new SimCardInfo((Context)getInstance());
		return info.getProviderName();
	}
}
