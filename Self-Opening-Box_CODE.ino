#include <Servo.h>                      //Include library for servo motor

Servo servo;
const int motorPin = 9;
const int trigPin = 7;  
const int echoPin = 6;                  //Pin for distance input
float duration, distance;

void setup()
{
  servo.attach(motorPin);               //Attach the Servo variable to a pin.
 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);  
  Serial.begin(9600);
  servo.write(0);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;       //Calculate distance from input recieved using speed of light
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);

  if(distance<=25)
  {
   servo.write(90);
    delay(1000);  
    servo.write(70);
    delay(1000);
    servo.write(50);
    delay(1000);
    servo.write(30);
    delay(1000);
    servo.write(10);
    delay(1000);
    servo.write(0);                  //Gives 5 seconds to throw at different angles
  }
 
  else
  {
    servo.write(0);
    delay(1000);                    //Check every 1 sec if anyone is near.
  }
}
