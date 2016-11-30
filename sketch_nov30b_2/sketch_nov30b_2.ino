//uno

#include <Wire.h>

#define LEDR 3
#define LEDG 5
#define LEDB 6


void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(115200);           // start serial for output
}

void turnoff(){
  digitalWrite(LEDR, LOW);
  digitalWrite(LEDG, LOW);
  digitalWrite(LEDB, LOW);
}


void loop() {
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  
/*char x = Wire.read();    // receive byte as an integer
  Serial.println(x);         // print the integer
  int y = Wire.read();    // receive byte as an integer
  Serial.println(y);         // print the integer
  int z = Wire.read();    // receive byte as an integer
  Serial.println(z);         // print the integer*/
 
   int r = Wire.read(); // receive byte as a character
   Serial.print(r);         // print the character
     int g= Wire.read(); // receive byte as a character
   Serial.print(g);         // print the character
     int b = Wire.read(); // receive byte as a character
   Serial.print(b);         // print the character

   analogWrite(LEDR,r);
  analogWrite(LEDG,g);
  analogWrite(LEDB,b);
  
  
  
}

