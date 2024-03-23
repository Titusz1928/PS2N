/*se va afișa pe interfața serială (SerialMonitor) temperatura curentă citită de la un senzor de temperatura (LM35) 
și se va implementa controlul unui LED prin comenzi UART (ie: ‘A’ -> va aprinde LED-ul, ‘S’ -> va stinge LED-ul). 
(Termen limită: 11.03.2024)*/

const int ledPin = 13;
int i=0;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

float sensorValue;
float temp;

void afisareDate(float temp){
  //sensorValue = analogRead(A0);
  //temp = (sensorValue*500) /1023;
  if (digitalRead(ledPin) == HIGH) {
    Serial.print(temp);
    Serial.println(" aprins");
  } else {
    Serial.print(temp);
    Serial.println(" stins");
  }
}



void loop() {
  // read the input on analog pin 0:
  if(i<1){
    sensorValue = analogRead(A0);
    temp = (sensorValue*500) /1023;
    Serial.print(temp);
    Serial.println(" stins");
    i++;
  }

   sensorValue = analogRead(A0);
   temp = (sensorValue*500) /1023;

  if (Serial.available() > 0) {
    char command = Serial.read(); // Read the incoming command from serial
    
    // Check the command and perform corresponding action
    if (command == 'A') {
      digitalWrite(ledPin, HIGH); // Turn on the LED
      //delay(500);
      afisareDate(temp);
    } else if (command == 'S') {
      digitalWrite(ledPin, LOW); // Turn off the LED
      //Serial.println("LED OFF");
      //delay(500);
      afisareDate(temp);
    }else if (command == 'T'){
      afisareDate(temp);
    }
  }


  float sensorValue = analogRead(A0);
  float temp = (sensorValue*500) /1023;
  //afisareDate(temp);
  
  // delay before reading the sensor again
  
}