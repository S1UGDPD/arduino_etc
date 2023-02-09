
/*
 Stepper Motor Control - one revolution

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.

 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.


 Created 11 Mar. 2007
 Modified 30 Nov. 2009
 by Tom Igoe

 */

#include <Stepper.h>

const int stepsPerRevolution = 4096;  // changed to fit the number of steps per revolution
// for your motor. Since Arduino library runs in "4 step mode", use 2048 steps per revolution
// as per documentation for this stepper motor.

// Initialize with pin sequence IN1-IN3-IN2-IN4 for using Stepper.h with 28BYJ-48
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11); // changed ordering from default in sketch

// "the Sketch believes that the pins are sequenced 8, 9,10, 11. 
// However, the pins are not sequenced that way in the controller.

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(12); //16 doesn't always stick; 
  
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(500);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500);
}

