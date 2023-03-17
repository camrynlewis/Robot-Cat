/*
 Camryn Lewis Final Project Apr 2019
 with snippets of code from:

 Project 4 - Color Mixing Lamp
 created by Scott Fitzgerald 13 Sep 2012
 modified by Federico Vanzati 14 Nov 2012
 
 The Cat's Meow
 created by Jeff Highsmith
 http://www.jeffhighsmith.com/the-cats-meow/
*/

// EYES
const int greenLEDPin = 9;
const int redLEDPin = 10;
const int redSensorPin = A0;
int redSensorValue = 0;
int initialRedSensorValue=450;
void setup() {
 // initialize serial communications at 9600 bps:
 Serial.begin(9600);
 pinMode(greenLEDPin, OUTPUT);
 digitalWrite(greenLEDPin, LOW);
 pinMode(redLEDPin, OUTPUT);
 digitalWrite(redLEDPin, HIGH);
}
void loop() {
 // read the value from the phototransistor:
 redSensorValue = analogRead(redSensorPin);
 if(redSensorValue < initialRedSensorValue){
 digitalWrite(redLEDPin, LOW);
 digitalWrite(greenLEDPin, HIGH);
 }else{
 digitalWrite(redLEDPin, HIGH);
 digitalWrite(greenLEDPin, LOW);
 }
 
// SOUND
int switchState=0;
pinMode(2,OUTPUT);
pinMode(3,INPUT);
switchState=digitalRead(3);
if (switchState==LOW) {
 int i=60;
 while(i < 1500) {
 tone(2,i,1);
 delay(1);
 i=(i+2); }
 i=1100;
 tone(2,i,3);
 delay(720);
 i=i-(i/80)+1;
}
else {
 tone(2,22,180);
 delay(1);
}
}
