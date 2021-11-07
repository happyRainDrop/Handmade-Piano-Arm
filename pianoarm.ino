# include <Servo.h>

Servo baseServo;
Servo fingerServo;
Servo armServo;

void setup() {
  // Setting up servo pins
  armServo.attach(6);
  fingerServo.attach(2);
  baseServo.attach(4);
  Serial.begin(115200);
}

void loop() {
  // Positions for servos to go to for each note were determined experimentally
  //                                       C     D     Eb    F     G     Ab    B   
  int baseServoMicroseconds[] =   {1350, 1350, 1250, 1050,  950,  800,  700,  500};
  int fingerServoMicroseconds[] = {1000, 1000, 1000, 800, 1800, 2000, 1000, 1700};
  int armServoMicroseconds[] =    {1300,  900, 1000, 1000, 1000, 1000, 1000, 1000};
  int sizeArr = sizeof(baseServoMicroseconds) / sizeof(baseServoMicroseconds[0]);
  for (int i = 0; i<sizeArr; i++) {
    delay(250);
    baseServo.writeMicroseconds(baseServoMicroseconds[i]);
    delay(250);
    fingerServo.writeMicroseconds(fingerServoMicroseconds[i]);
    delay(250);
    if (i==0) {
      armServo.writeMicroseconds(armServoMicroseconds[i]);
    } else {
      armDown(armServoMicroseconds[i]);
    }
  }
}

void armDown(int microsec) {
  Serial.println("hey");
  int initial = 1300;
  while (initial!=microsec) {
    delay(5);
    initial-=5;
    Serial.print("arm is at ");
    Serial.println(initial);
    armServo.writeMicroseconds(initial);
  }
  delay(500);
  while (initial<1300) {
    delay(5);
    initial+=2;
    armServo.writeMicroseconds(initial);
  }
}
