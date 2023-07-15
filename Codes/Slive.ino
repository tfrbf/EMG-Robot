#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#define led 4
#define ENA 10
#define ENB 5
#define In1 9
#define In2 2
#define In3 3
#define In4 6

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";
int buttonState =0;

char text1='A';
void setup() {
  pinMode(led,OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  
  Serial.begin(115200);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
 
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);

 if(text[0]=='A'){
 
  digitalWrite(led,HIGH);
 forward();
 }
 else if(text[0] == 'C'){
 stop();
 } 
 else if(text[0] == 'B'){
  backward();
  }
  }
  } 
  //---------------FUNCTIONS
void forward() {

  digitalWrite(led, HIGH);
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  analogWrite(ENA, 255);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  analogWrite(ENB, 255);
}

void backward() {

  digitalWrite(led, LOW);
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  analogWrite(ENA, 255);
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
  analogWrite(ENB, 255);
}

void stop() {

  digitalWrite(In1, HIGH);
  digitalWrite(In1, LOW);
  analogWrite(ENA, 0);
  digitalWrite(In1, HIGH);
  digitalWrite(In1, LOW);
  analogWrite(ENB, 0);
}
