#IOS_SDK = $(shell xcrun --sdk iphoneos --show-sdk-path)
IOS_SDK = /Applications/Xcode13.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk
IOS_CC = clang 
IOS_CFLAG = -arch arm64 -isysroot $(IOS_SDK) -ObjC -D__swift__ \
 			-framework CoreFoundation -framework CoreGraphics -framework UIKit -framework Foundation

all: clean demo.app

demo.app: demo sign


sign:
	codesign -f -s "dmss@sina.com" --entitlements Entitlements.plist demo.app

v:
	codesign -vv -d demo.app 

demo: 
	mkdir -p demo.app
	cp Info.plist ResourceRules.plist embedded.mobileprovision demo.app/
	$(IOS_CC) $(IOS_CFLAG) -o demo.app/demo main.c AppDelegate.c view.c

debug: all ios-deploy
	@../build/Release/ios-deploy --debug --bundle demo.app

clean:
	@rm -rf demo.app demo demo.dSYM
	
ios-deploy:
	@xcodebuild -project ../ios-deploy.xcodeproj

install: 
	ios-deploy --bundle demo.app
