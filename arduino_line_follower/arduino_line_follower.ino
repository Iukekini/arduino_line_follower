
// pin for IR Analog Values.
const int pinAnalogLeftIR = A0;
const int pinAnalogRightIR = A1;

int IRLeftValue = 0;
int IRRightValue = 0;


// Set Motor Speeds
const int motorStop = 0;
const int motorCrawlSpeed = 75;

//Set Value for line detection
const int irDetectionValue = 75;

// connect motor controller pins to Arduino digital pins
// motor one
int pinMotorEnableLeft = 10;
int motorLeftSpeed = 0;
int in1 = 9;
int in2 = 8;
// motor two
int pinMotorEnableRight = 5;
int motorRightSpeed = 0;
int in3 = 7;
int in4 = 6;
void setup()
{
  Serial.begin(9600);

  //IR Senosrs
  pinMode(pinAnalogLeftIR, INPUT);
  pinMode(pinAnalogRightIR, INPUT);

  //Motor Controller
  // set all the motor control pins to outputs
  pinMode(pinMotorEnableLeft, OUTPUT);
  pinMode(pinMotorEnableLeft, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Set the motors to run in a forward direction
  // motor one
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // motor two
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

}

int calculateMotorSpeed(int value) {
  if (value <= irDetectionValue) {
    return motorStop;
  } else {
    return motorCrawlSpeed;
  }
}

void loop()
{
  Serial.print("Left Reading=");
  Serial.print(IRLeftValue);
  Serial.print("\t Right Reading=");
  Serial.println(IRRightValue);
  Serial.print("Left Motor=");
  Serial.print(calculateMotorSpeed(IRLeftValue));
  Serial.print("\t Right Motor=");
  Serial.println(calculateMotorSpeed(IRRightValue));



  //Check IR Values
  IRLeftValue = analogRead(pinAnalogLeftIR);
  IRRightValue = analogRead(pinAnalogRightIR);

  //Set Motor Speed
  analogWrite(pinMotorEnableLeft, calculateMotorSpeed(IRRightValue));
  analogWrite(pinMotorEnableRight, calculateMotorSpeed(IRLeftValue));
}
