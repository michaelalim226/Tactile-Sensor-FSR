const int adcPin = A0;
const int idleOffset = 80; 


int readAverage(int pin, int n) {
  long total = 0;
  for (int i = 0; i < n; i++) {
    total += analogRead(pin);
    delay(2);
  }
  return total / n;
}

void setup() {
  Serial.begin(9600);
  while (!Serial) {
  
  }
  Serial.println("FSR Reader dengan Averaging");
}

void loop() {
  
  int raw = readAverage(adcPin, 20);

  float percent = (raw - idleOffset) / (1023.0 - idleOffset) * 100.0;

  percent = constrain(percent, 0, 100);

  Serial.print("ADC: ");
  Serial.print(raw);
  Serial.print("\tPersen: ");
  Serial.print(percent, 1);
  Serial.println("%");

  delay(100); 
}