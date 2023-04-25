#include "Servo.h"
#define treshhold 200
Servo s1;
float sensorValue;
float a = 0, b ;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  s1.attach(9);
 
}

void loop() {
  // put your main code here, to run repeatedly:
float sensorValue = analogRead(A0);
float milivolt = (sensorValue/1023)*5;
 float  c = analogRead(A0);
 if(b==0.0){
 b = a;
 }
 a = max(a,c);
 b = min(b,c);

Serial.print("a: ");
Serial.print(a);
Serial.print("\t b: ");
Serial.print(b);



Serial.print("\t Sensor value: ");
Serial.print(sensorValue);
Serial.print("\t Voltage: ");
Serial.print(milivolt * 1000);
Serial.print(" mV");
Serial.print(" \n");
delay(500);

if (sensorValue > treshhold) s1.write(90);
else s1.write(0);

}
