//
//  MultiTouch.h
//  No drag release delay
//
//  Created by Pravdomil Toman on 16/12/2017.
//  Copyright © 2017 Pravdomil Toman. All rights reserved.
//

#ifndef MultiTouch_h
#define MultiTouch_h

// https://github.com/jnordberg/FingerMgmt/blob/master/FingerMgmt/MultiTouch.h

typedef struct { float x,y; } mtPoint;
typedef struct { mtPoint pos,vel; } mtReadout;

typedef struct {
    int frame;
    double timestamp;
    int identifier, state, foo3, foo4;
    mtReadout normalized;
    float size;
    int zero1;
    float angle, majorAxis, minorAxis; // ellipsoid
    mtReadout mm;
    int zero2[2];
    float unk2;
} Finger;

typedef void *MTDeviceRef;
typedef int (*MTContactCallbackFunction)(int,Finger*,int,double,int);

MTDeviceRef MTDeviceCreateDefault();
void MTRegisterContactFrameCallback(MTDeviceRef, MTContactCallbackFunction);
void MTDeviceStart(MTDeviceRef, int); // thanks comex
int MTDeviceGetVersion(MTDeviceRef, int);

#endif /* MultiTouch_h */
