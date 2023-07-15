#define signal_pin A0
#define LED 2
#define button 3
#define ENA 10
#define ENB 5
#define In1 9
#define In2 8
#define In3 7
#define In4 6

float third;
int button_state;
float sensorValue = 0;
unsigned int a = 0, b, c = 0, Ave = 0;
unsigned int count = 0;
unsigned int button_count = 0;


void setup() {

  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(button, INPUT);
  pinMode(signal_pin, INPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
}


void loop() {

  button_state = digitalRead(button);

  if (button_state == HIGH) button_count++;

  if (button_count == 0) Serial.print("Waiting for activation....\t");
  if (button_count == 1) Serial.print("NOT Active\t");
  if (button_count == 2) Serial.print("Active\t");

  if (button_count % 2 != 0) {

    c = analogRead(A0);
    if (b == 0.0) b = a;
    a = max(a, c);
    b = min(b, c);

  } else a = a;

  float sensorValue = analogRead(A0);
  float milivolt = (sensorValue / 1023) * 5;

  third = (a-b)/3;

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

  if (button_count == 2 && sensorValue > b && sensorValue <= b + third ) forward();
  if (button_count == 2 &&  sensorValue < (a - third) && sensorValue >= b + third) stop();
  if (button_count == 2 &&  sensorValue >= (a - third) && sensorValue <a) backward();

  delay(500);

  count++;
}


//---------------FUNCTIONS
void forward() {

  digitalWrite(LED, HIGH);
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  analogWrite(ENA, 255);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  analogWrite(ENB, 255);
}


void backward() {
  
  digitalWrite(LED, LOW);
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
