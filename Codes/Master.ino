#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define button 4
#define signal_pin A0


RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";
int value =0;
float third;
//
int button_state;
float sensorValue = 0;
unsigned int a = 0, b, c = 0, Ave = 0;
unsigned int count = 0;
unsigned int button_count = 0;
  const char esm1[]="A";
  const char esm2[]="B";
  const char esm3[]="C";

void setup() {
  pinMode(button,INPUT);
  pinMode(signal_pin, INPUT);
  Serial.begin(9600);
  
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
 
  int val = digitalRead(button);
  if (val == 1) button_count++;
  
  if (button_count == 0) Serial.print("Waiting for activation....\t");
  if (button_count == 1) Serial.print("NOT Active\t");
  if (button_count == 2) Serial.print("Active\t");
  //--------------------------------------determining 3 ranges
  if (button_count % 2 != 0) {

    c = analogRead(A0);
    if (b == 0.0) b = a;
    a = max(a, c);
    b = min(b, c);

  } else a = a;

  float sensorValue = analogRead(A0);
  float milivolt = (sensorValue / 1023) * 5;

  third = (a-b)/3;
 //-------------------------------printing in serial monitor
  Serial.print("Max: ");
  Serial.print(a);
  Serial.print("\t Min: ");
  Serial.print(b);
  Serial.print("\t one_third: ");
  Serial.print(third);
  Serial.print("\t button_count: ");
  Serial.print(button_count);
  Serial.print("\t Sensor value: ");
  Serial.print(sensorValue);
  Serial.print("\t Voltage: ");
  Serial.print(milivolt * 1000);
  Serial.print(" mV");
  Serial.print(" \n");
//-----------------------------3 modes of working
  if (button_count == 2 && sensorValue > b && sensorValue <= b + third ) {
    radio.write(&esm1, sizeof(esm1));
  }
  if (button_count == 2 &&  sensorValue < (a - third) && sensorValue >= b + third){
    radio.write(&esm3, sizeof(esm3));
  }
  if (button_count == 2 &&  sensorValue >= (a - third) && sensorValue <a) {
    radio.write(&esm2, sizeof(esm2));
  }

  delay(500);

  count++;
}
