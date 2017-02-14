//
//  AppDelegate.h
//  DragReleaseDelay
//
//  Created by Pravdomil Toman on 19.09.14.
//

#import <Cocoa/Cocoa.h>

@interface AppDelegate : NSObject <NSApplicationDelegate>

@property (strong, nonatomic) NSStatusItem *statusBar;

@property (strong) IBOutlet NSMenu *statusMenu;

@end
