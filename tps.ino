//you can use any pin but it should be analog cause tps working like potentiometer
const int tpsPin = A0;

//it base on tps voltage
const float VREF = 5.0;

//it based on how much voltage that you want use
const float TPS_VMAX = 2.5;

//it used base on how much angle you want to use
const float ANGLE_MAX = 90.0;

void setup() {
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int adcValue = analogRead(tpsPin);
  float voltage = (adcValue / 1023.0) * VREF;

  if (voltage > TPS_VMAX) voltage = TPS_VMAX;
  float angle = (voltage / TPS_VMAX) * ANGLE_MAX;

  Serial.print("ADC: ");
  Serial.print(adcValue);
  Serial.print(" | Tegangan: ");
  Serial.print(voltage, 2);
  Serial.print(" V | Sudut: ");
  Serial.print(angle, 1);
  Serial.println("°");

  delay(100);
}