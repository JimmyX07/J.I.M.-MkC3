/* 
Hi! The name's Jim, I'm what some define "an engineer in training", I love to mess ardund with electronics
especially when it comes to Iron Man stuff. My mentors are obviously the guys from CrashWorks3D, so
if you want a 100% working code for an arduino powered helmet head to their repository. 

This one is made for fun, and if you're using it it means you're brave or desperate. This code has been
designed to work on ESP32 C3 SuperMini modules: it is in the updated version of the original code
on my github made for ESP32 DEV Wroom modules.

If you're seeing this message, it means that I haven't given you a J.I.M. board, which is a custom PCB
that I made to make the helmet work. If you have one, you don't need to do anything, the board is already
wired and the code is already set up to work with it.

If you want to customize a little bit the code, the customization.h is the only one you have to modify.

All that being said, hope you enjoy this and that nothing blows up!



Oh wait, formalities: THIS CODE IS MADE FOR RECREATIONAL PURPOSES ONLY, I AM NOT RESPONSIBLE FOR ANY DAMAGE TO
YOURSELF OR YOUR PROPERTY CAUSED BY THE USE OF THIS CODE.
USE AT YOUR OWN RISK.

There you go, now im free of any liability.

Jim
*/

#include <functions.h>

void setup() {
  startUp();
}

void loop() {
  button.tick();
  delay(10);
}