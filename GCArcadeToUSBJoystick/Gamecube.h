#pragma once

// bits: 0, 0, 0, start, y, x, b, a
#define GC_START 16 
#define GC_Y 8
#define GC_X 4
#define GC_B 2
#define GC_A 1
#define GC_L 64
#define GC_R 32
#define GC_Z 16
#define GC_UP 8
#define GC_DOWN 4
#define GC_RIGHT 2
#define GC_LEFT 1

// 8 bytes of data that we get from the controller
typedef struct {
    // bits: 0, 0, 0, start, y, x, b, a
    unsigned char data1;
    // bits: 1, L, R, Z, Dup, Ddown, Dright, Dleft
    unsigned char data2;
    unsigned char stick_x;
    unsigned char stick_y;
    unsigned char cstick_x;
    unsigned char cstick_y;
    unsigned char left;
    unsigned char right;
} gc_status_t;

extern void SetupGCJoystick(void);
extern void ReadGCJoystick(gc_status_t *gc_status);
