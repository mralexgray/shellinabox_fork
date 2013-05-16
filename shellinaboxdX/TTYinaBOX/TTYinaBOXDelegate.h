//
//  AppDelegate.h
//  TTYinaBOX
//
//  Created by Alex Gray on 5/16/13.
//  Copyright (c) 2013 Alex Gray. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <WebKit/WebKit.h>

@interface TTYinaBOXDelegate : NSObject <NSApplicationDelegate>

@property (assign) IBOutlet NSWindow *window;
@property (assign) IBOutlet WebView *webView;
@property (strong) NSURL *url;

@end
