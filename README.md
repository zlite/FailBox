# FailBox
Device to inject predictable failures into autopilots


This can read up to four incoming RC channels and trigger up to four outputs. Outputs can be brushed motors for vibration, a buzzer for vibration, or simple on/off current for devices such as a magnetometer

It defaults to motors on all four ports. 

/ Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *myMotor1 = AFMS.getMotor(1);
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(2);
Adafruit_DCMotor *myMotor3 = AFMS.getMotor(3);
Adafruit_DCMotor *myMotor4 = AFMS.getMotor(4);

To assign a buzzer to a port, use this:

  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  // Set the speed to start, from 0 (off) to 255 (max speed)

Set the speed of any motor like this:

myMotor1->setSpeed(150);
  myMotor1->run(FORWARD);
  // turn on motor
  myMotor1->run(RELEASE);
 
 
If you open a serial terminal at 9600 baud, it will report the current status. You can change motor speed by typing in any number between 0 and 255 in the terminal and pressing "enter".
