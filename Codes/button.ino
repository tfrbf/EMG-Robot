#define signal_pin A0
#define LED 2
#define button 3

int button_state;
float sensorValue = 0;
unsigned int a = 0, b, c = 0, Ave = 0;
unsigned int count = 0;
unsigned int button_count = 0;

void setup() {

  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {

  Serial.print("Waiting for activation....\t");
  button_state = digitalRead(button);

  if (button_state == HIGH) button_count++;

  if (button_count % 2 != 0) {
    c = analogRead(A0);
    if (b == 0.0) b = a;
    a = max(a, c);
    b = min(b, c);

  } else {
    a = a;
  }

  float sensorValue = analogRead(A0);
  float milivolt = (sensorValue / 1023) * 5;

  Ave = (a + b) / 2;

  Serial.print("a: ");
  Serial.print(a);
  Serial.print("\t b: ");
  Serial.print(b);
  Serial.print("\t Ave: ");
  Serial.print(Ave);
  Serial.print("\t button_count: ");
  Serial.print(button_count);
  Serial.print("\t Sensor value: ");
  Serial.print(sensorValue);
  Serial.print("\t Voltage: ");
  Serial.print(milivolt * 1000);
  Serial.print(" mV");
  Serial.print(" \n");

  if (sensorValue > Ave) {

    digitalWrite(2, HIGH);
  }

  else {
    digitalWrite(2, LOW);
  }
  delay(500);
  count++;
}
