#ifndef NESpad_h
#define NESpad_h

#include <inttypes.h>

#define NES_A       B00000001
#define NES_B       B00000010
#define NES_SELECT  B00000100
#define NES_START   B00001000
#define NES_UP      B00010000
#define NES_DOWN    B00100000
#define NES_LEFT    B01000000
#define NES_RIGHT   B10000000

typedef struct {
    int m_strobe, m_clock, m_data;
} NESpad;

extern void NESpad_Init(NESpad *gamepad, int strobe, int clock, int data);
extern uint8_t NESpad_Buttons(NESpad *pad);

#endif

