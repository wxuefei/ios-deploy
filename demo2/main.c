//
//  main.m
//  CBasediOSApp
//
//  Created by Richard Ross on 4/23/12.
//  Copyright (c) 2012 Ultimate Computer Services, Inc. All rights reserved.
//
//#include <CoreFoundation/CoreFoundation.h>

#include <objc/runtime.h>
#include <objc/message.h>
#include <UIKit/UIKit.h>

//extern void UIApplicationMain(int, ...);
//#define NSLog(FORMAT,...)fprintf(stderr,"%s\n",[[NSString stringWithFormat:FORMAT,##__VA_ARGS__] UTF8String]);

int main(int argc, char *argv[])
{
	//Class cls = objc_getClass("NSApplication");
	//objc_object* appInst = objc_msgSend((objc_object*)cls, sel_registerName("sharedApplication"));
	
	//Class cls = objc_getClass("NSApplication");
	//objc_object* appInst = ((objc_object * (*)(objc_object *, SEL)) objc_msgSend)((objc_object*)cls, 
    //                   sel_registerName("sharedApplication"));
	NSLog(@"nslog: %s, %d", __FILE__, __LINE__);
	Class clz = objc_getClass("NSAutoreleasePool");
	id pool = objc_msgSend(clz, sel_registerName("alloc"));
    id autoreleasePool = objc_msgSend(pool, sel_registerName("init"));
    
	NSLog(@"nslog: %s, %d", __FILE__, __LINE__);
    UIApplicationMain(argc, argv, nil, CFSTR("AppDelegate"));
	NSLog(@"nslog: %s, %d", __FILE__, __LINE__);
    
    objc_msgSend(autoreleasePool, sel_registerName("drain"));
}