//
//  AppDelegate.m
//  DragReleaseDelay
//
//  Created by Pravdomil Toman on 19.09.14.
//

#import "AppDelegate.h"
#import "MultiTouch.h"

@implementation AppDelegate

- (void) awakeFromNib {
    self.statusBar = [[NSStatusBar systemStatusBar] statusItemWithLength:NSVariableStatusItemLength];
    
    self.statusBar.title = @"⥺";
    
    self.statusBar.menu = _statusMenu;
    self.statusBar.highlightMode = YES;
}

- (IBAction)donate:(id)sender {
    [[NSWorkspace sharedWorkspace] openURL:[NSURL URLWithString:@"https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=BCL2X3AFQBAP2&item_name=DragReleaseDelay"]];
}

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    registerCallback();
}

static bool threeFinger = true;

static int callback(int device, Finger *data, int nFingers, double timestamp, int frame) {
    if( nFingers == 3 ) {
        threeFinger = true;
        return 0;
    }
    
    if(threeFinger && nFingers == 0) {
        simulateMouseEvent(kCGEventLeftMouseUp);
        return 0;
    }
    
    return 0;
}

static void simulateMouseEvent(CGEventType eventType) {
    CGPoint mouseLocation = CGEventGetLocation(CGEventCreate(NULL));
    CGEventRef event = CGEventCreateMouseEvent(CGEventSourceCreate(kCGEventSourceStateHIDSystemState), eventType, mouseLocation, kCGMouseButtonLeft);
    CGEventPost(kCGHIDEventTap, event);
    CFRelease(event);
}

void registerCallback() {
    MTDeviceRef dev = MTDeviceCreateDefault();
    MTRegisterContactFrameCallback(dev, callback);
    MTDeviceStart(dev, 0);
}

@end
