/*se va afișa pe interfața serială (SerialMonitor) temperatura curentă citită de la un senzor de temperatura (LM35) 
și se va implementa controlul unui LED prin comenzi UART (ie: ‘A’ -> va aprinde LED-ul, ‘S’ -> va stinge LED-ul). 
(Termen limită: 11.03.2024)*/

const int ledPin = 13;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}


void loop() {
  // read the input on analog pin 0:
  if (Serial.available() > 0) {
    char command = Serial.read(); // Read the incoming command from serial
    
    // Check the command and perform corresponding action
    if (command == 'A') {
      digitalWrite(ledPin, HIGH); // Turn on the LED
      Serial.println("LED ON");
    } else if (command == 'S') {
      digitalWrite(ledPin, LOW); // Turn off the LED
      Serial.println("LED OFF");
    }
  }


  float sensorValue = analogRead(A0);
  float temp = (sensorValue*500) /1023;
  
  // print out the temperature value without moving to the next line:
  Serial.print(sensorValue);
  
  // add a space to separate values for better readability in the Serial Monitor
  Serial.print(" ");
  
  // delay for a short time to allow the Serial Monitor to catch up
  delay(50);

  // print out the value on the same line for the Serial Plotter
  Serial.println(temp);
  
  // delay before reading the sensor again
  delay(1000);
}
