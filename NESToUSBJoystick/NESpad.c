/*
  NESpad - Arduino library for interfacing with a NES joystick

  Version: 1.3 (11/12/2010) - get rid of shortcut constructor - seems to be broken
  Version: 1.2 (05/25/2009) - put pin numbers in constructor (Pascal Hahn)
  Version: 1.1 (09/22/2008) - fixed compilation errors in arduino 0012 (Rob Duarte)
  Version: 1.0 (09/20/2007) - Created (Rob Duarte)
  
  This file is part of NESpad.

  NESpad is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  NESpad is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with NESpad.  If not, see <http://www.gnu.org/licenses/>.  
*/

#include "NESpad.h"
#include "Arduino.h"

#include <util/delay.h>

// change the next three lines if necessary
// arduino pins and their connection to the nes joystick
// default: digital pin 2=strobe, 3=clock, 4=data
// see readme.txt for game pad pinout

// -- actually, let's just eliminate this since people seem to be having
// -- trouble with it.. stick with specifying the pin numbers as 
// -- arguments to the constructor

// NESpad::NESpad() {
//     NESpad::NESpad(2,3,4);
// }

#define delayMicroseconds _delay_us

static void strobe(NESpad *pad)
{
  digitalWrite(pad->m_strobe,HIGH);
  delayMicroseconds(12);
  digitalWrite(pad->m_strobe,LOW);
}

static byte shiftin(NESpad *pad)
{
  byte ret = digitalRead(pad->m_data);
  delayMicroseconds(12);
  digitalWrite(pad->m_clock,HIGH);
  delayMicroseconds(12);
  digitalWrite(pad->m_clock,LOW);
  return ret;
}

NESpad *NESpad_Create(int strobe, int clock, int data)
{
  NESpad *pad = malloc(sizeof(*pad));
  pad->m_strobe = strobe;
  pad->m_clock = clock;
  pad->m_data = data;

  pinMode(strobe, OUTPUT);
  pinMode(clock,  OUTPUT);
  pinMode(data, INPUT);

  return pad;
}

uint8_t NESpad_Buttons(NESpad *pad)
{
  byte ret = 0;
  byte i;
  strobe(pad);
  for (i = 0; i < 8; i++) {
    ret |= shiftin(pad) << i;
  }
  return ~ret;
}
