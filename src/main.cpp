#include <Arduino.h>
#include <Servo.h>
Servo myServo;
int trigPin = 9;
int echoPin = 10;
void setup() {
    // write your initialization code here
    pinMode(trigPin,OUTPUT);
    pinMode(echoPin,INPUT);
    myServo.attach(5);
    Serial.begin(9600);
}
void loop() {
    // write your code here
    digitalWrite(trigPin,0);
    delayMicroseconds(2);

    digitalWrite(trigPin, 1);
    delayMicroseconds(10);

    digitalWrite(trigPin,0);
    long duration = pulseIn(echoPin, HIGH);
    long distance = (duration * 0.0343) / 2;

    if (distance <= 5) {
        myServo.write(180);   // rotate servo
    } else {
        myServo.write(0);     // reset servo
    }
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    delay(500);
}