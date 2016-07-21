/* Light sensor
 * ------------------ 
 *
 * turns on and off a light emitting diode(LED) connected to digital  
 * pin 13. The amount of time the LED will be on and off depends on
 * the value obtained by analogRead() that is depending of the amount
 * of light in the LDR
 *
 */

int LDR = 2;       // select the input pin for the LDR
int ledPin = 13;   // select the pin for the LED
int val = 0;       // variable to store the value coming from the sensor
int average = 0;

void setup() {
  pinMode(LDR, INPUT);       // declare the LDR as an INPUT
  pinMode(ledPin, OUTPUT);  // declare the ledPin as an OUTPUT
  Serial.begin(9600);
  digitalWrite(ledPin, HIGH);  // turn the ledPin on
  delay(3000);
  for (int i = 0; i < 1000; i++) {
    average = (average + analogRead(LDR)) / 2;
  }
}

void loop() {
  val = analogRead(LDR);       // read the value from the sensor
  //average = (average + val) / 2;
  Serial.println(val);
  if (val >= (average + 10)) {
    delay(1000);
  }
 // delay(val);                  // stop the program for some time
 // digitalWrite(ledPin, LOW);   // turn the ledPin off
 // delay(val);                  // stop the program for some time
}
