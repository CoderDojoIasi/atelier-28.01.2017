/*
  Arduino Motion Sensor

  Created: 26/01/2017
  By CODERDOJO IASI
  Modified N/A
  By CODERDOJO IASI
*/


//int ledPin = 4;                // pinul la care ledul este conectat
int piezoBuzzerPin = 3;     // pinul la care buzzerul este conectat
int pirSensorPin = 2;               // pinul la care senzorul PIR este conectat

int detectareMiscare = LOW;             // starea initiala a senzorului este de 0 (LOW)
                                        // nicio miscare detectata

void setup() {
 // pinMode(ledPin, OUTPUT);      // declarara pinul de LED ca output - el afiseaza o lumina, primeste curent de la microcontroller 
  pinMode(pirSensorPin, INPUT);     // declara senzorul PIN ca input - el primeste informatii din mediul extern
  pinMode(piezoBuzzerPin, OUTPUT); // declara buzzerul ca output
  Serial.begin(9600); //  
  Serial.println("Incepe masuratoare...");
  delay(10000); //  permite senzorului PIR de a detecta obiectele din jur si a stabili cantitatea de infrarosu
}

void loop(){
  detectareMiscare = digitalRead(pirSensorPin);  // citeste senzorul PIR
  if(detectareMiscare == HIGH) {// daca a fost detectata o miscare (un input pe care senzorul il primeste din mediul extern)
              
    Serial.println("Miscare detectata");
    //digitalWrite(ledPin, HIGH);
    analogWrite(piezoBuzzerPin, 200);
    delay(100);
   // analogWrite(ledPin, LOW);
    analogWrite(piezoBuzzerPin, 25);
    delay(100);
  }
  else{
 // digitalWrite(ledPin, LOW);
  digitalWrite(piezoBuzzerPin,LOW);
  }

