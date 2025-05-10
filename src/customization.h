/*
This tab is the one you use to customize the behavior of the motors and the connections if you wish to modify them.

If you're using a J.I.M. board that I gave you you don't need to modify the "PINS" section.
*/

//PINS, use this section to modify connections if you're making your own circuit.
#define SERVO1_PIN 20
#define SERVO2_PIN 21
#define BUTTON_PIN 7
#define RIGHT_EYE 3
#define LEFT_EYE 4

//SERVO PWM VALUES, modify them according to the specs of the servos you are using.
#define PWM_LOW 500
#define PWM_HIGH 2500

//SERVOS OPEN AND CLOSE POSITION
#define SERVO1_OPEN_POS 160
#define SERVO1_CLOSE_POS 20
#define SERVO2_OPEN_POS 20
#define SERVO2_CLOSE_POS 160

//EYES STARTUP EFFECT, uncomment this line to have a cool startup flickering effect when you turn on the helmet.
#define EYES_EFFECT