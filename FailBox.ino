/*
 For use with the Adafruit Motor Shield v2 
---->  http://www.adafruit.com/products/1438
*/

#include <Wire.h>
#include <Adafruit_MotorShield.h>

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *myMotor1 = AFMS.getMotor(1);
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(2);
Adafruit_DCMotor *myMotor3 = AFMS.getMotor(3);
Adafruit_DCMotor *myMotor4 = AFMS.getMotor(4);

const int PWM_PIN1 = 5;
const int PWM_PIN2 = 6;
const int PWM_PIN3 = 9;
const int PWM_PIN4 = 10;
const int LED_PIN = 13;
int motor_speed;
int ch1;
int ch2;
int ch3;
int ch4;


void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.setTimeout(100);
  Serial.println("3DR FailBox");

  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  // Set the speed to start, from 0 (off) to 255 (max speed)
  myMotor1->setSpeed(150);
  myMotor1->run(FORWARD);
  // turn on motor
  myMotor1->run(RELEASE);
  
  pinMode(PWM_PIN1, INPUT);
  pinMode(PWM_PIN2, INPUT);
  pinMode(PWM_PIN3, INPUT);
  pinMode(PWM_PIN4, INPUT);
  pinMode(LED_PIN, OUTPUT);  
  digitalWrite(LED_PIN, HIGH);
  motor_speed = 100; //initialize motor speed
}

void loop() {
  ch1 = pulseIn(PWM_PIN1, HIGH, 10000);  //use timeout of 10,000 microseconds or 10 milliseconds 
//  ch2 = pulseIn(PWM_PIN2, HIGH, 10000);
//  ch3 = pulseIn(PWM_PIN3, HIGH, 10000);
//  ch4 = pulseIn(PWM_PIN4, HIGH, 10000);  
  Serial.print("CH1 in ");
  Serial.println(ch1);  
  Serial.print("CH2 in ");
  Serial.println(ch2);  
  Serial.print("CH3 in ");
  Serial.println(ch3);  
  Serial.print("CH4 in ");
  Serial.println(ch4);  

  while (Serial.available() > 0) {
    motor_speed = Serial.parseInt();
    if (Serial.read() == '\n') {
      // constrain the values to 0 - 255
      motor_speed = constrain(motor_speed, 0, 255);
      Serial.print("Motor speed changed to ");
      Serial.println(motor_speed);
    }
  }

  if (ch1 > 1500) {
    for (int i = 1; i <= 255; i = i + 10) {
      motor_speed = i;
      Serial.print("Driving motor at ");
      Serial.println(motor_speed);
      myMotor1->setSpeed(motor_speed); 
      myMotor1->run(FORWARD);
      delay(1000);
    }
  }
  else {
  myMotor1->run(RELEASE);
  }
}
