#include "Servo.h"

Servo lshoulder;
Servo lelbow;
Servo lclaw;

Servo rshoulder;
Servo relbow;
Servo rclaw;

int toDigit(int character) {
  return character - 48;
}

void setup() {
  lshoulder.attach(6);
  lelbow.attach(9);
  lclaw.attach(10);
//
//  
//  rshoulder.attach(6);
//  relbow.attach(9);
//  rclaw.attach(10);
  Serial.begin(115200);
  Serial.write("Hello from Robot1!");
}
int byteCount = 0;
int digits[11];
void loop() {
  if (true) {
    int number = Serial.read();
    if (number == 13) {
      int shoulder = 100 * toDigit(digits[0]) + 10 * toDigit(digits[1]) + toDigit(digits[2]);
      int elbow = 100 * toDigit(digits[4]) + 10 * toDigit(digits[5]) + toDigit(digits[6]);
      int claw = 100 * toDigit(digits[8]) + 10 * toDigit(digits[9]) + toDigit(digits[10]);
      Serial.print(shoulder);
      Serial.print(elbow);
      Serial.println(claw);
      lshoulder.write(shoulder);
      lelbow.write(elbow);
      lclaw.write(claw);
      
      byteCount = 0;
    }
    else if (byteCount < 11) {
      digits[byteCount] = number;
      byteCount++;
    }
  }
}
