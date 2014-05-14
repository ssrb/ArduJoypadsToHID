#include "NESpad.h"
#include "Arduino.h"

#include <util/delay.h>

#define delayMicroseconds _delay_us

static void strobe(NESpad *pad)
{
  digitalWrite(pad->m_strobe,HIGH);
  delayMicroseconds(12);
  digitalWrite(pad->m_strobe,LOW);
}

void NESpad_Init(NESpad *gamepad, int strobe, int clock, int data)
{
  gamepad->m_strobe = strobe;
  gamepad->m_clock = clock;
  gamepad->m_data = data;

  pinMode(strobe, OUTPUT);
  pinMode(clock,  OUTPUT);
  pinMode(data, INPUT);
}

uint8_t NESpad_Buttons(NESpad *pad)
{
  strobe(pad);
  digitalWrite(pad->m_clock,LOW);
  byte ret = digitalRead(pad->m_data) 
    | (shiftIn(pad->m_data, pad->m_clock, LSBFIRST) << 1);
  return ~ret;
}
