// RH_ASK.cpp
//
// Copyright (C) 2014 Mike McCauley
// $Id: RH_ASK.cpp,v 1.23 2018/09/23 23:54:01 mikem Exp $

#include <RH_ASK.h>
#include <RHCRC.h>

// RH_ASK on Arduino uses Timer 1 to generate interrupts 8 times per bit interval
// Define RH_ASK_ARDUINO_USE_TIMER2 if you want to use Timer 2 instead of Timer 1 on Arduino
// You may need this to work around other librraies that insist on using timer 1
// Should be moved to header file
define RH_ASK_ARDUINO_USE_TIMER2
