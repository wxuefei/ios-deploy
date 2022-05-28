IOS_CC = clang -ObjC
#IOS_SDK = $(shell xcrun --sdk iphoneos --show-sdk-path)
IOS_SDK = /Applications/Xcode13.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk

all: clean demo.app

demo.app: demo Info.plist
	mkdir -p demo.app
	cp demo demo.app/
	cp Info.plist ResourceRules.plist embedded.mobileprovision demo.app/
	codesign -f -s "dmss@sina.com" --entitlements Entitlements.plist demo.app
	ls -l demo.app/demo demo.app/_CodeSignature/CodeResources

sign:
	codesign -f -s "dmss@sina.com" --entitlements Entitlements.plist demo.app

v:
	codesign -vv -d demo.app 

demo: demo.c
	$(IOS_CC) -g -arch arm64 -isysroot $(IOS_SDK) -framework CoreFoundation -o demo demo.c

debug: all ios-deploy
	@../build/Release/ios-deploy --debug --bundle demo.app

clean:
	@rm -rf demo.app demo demo.dSYM
	
ios-deploy:
	@xcodebuild -project ../ios-deploy.xcodeproj

install: 
	ios-deploy --bundle demo.app
