//
//  AppDelegate.h
//  No drag release delay
//
//  Created by Pravdomil Toman on 16/12/2017.
//  Copyright © 2017 Pravdomil Toman. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface AppDelegate : NSObject <NSApplicationDelegate>

@property (strong, nonatomic) NSStatusItem *statusBar;

@property (strong) IBOutlet NSMenu *statusMenu;

@end
