
#include<SoftwareSerial.h> 
#define BLUETOOTH_SPEED 9600
SoftwareSerial mySerial(0,1);

void setup()
{
  pinMode(4, OUTPUT); 

  mySerial.begin(BLUETOOTH_SPEED);
  delay(1000);
 // Should respond with OK
  mySerial.print("AT");
  waitForResponse();

  // Should respond with its version
  mySerial.print("AT+VERSION");
  waitForResponse();

  // Set pin to 0000
  mySerial.print("AT+PIN0000");
  waitForResponse();

  // Set the name to ROBOT_NAME
  mySerial.print("AT+NAME");
  mySerial.print("ARJUN");
  waitForResponse();

  // Set baudrate to 57600
  mySerial.print("AT+BAUD4");
  waitForResponse();

}

void loop()
{/*
  mySerial.flush();

  char get_char = ' ';  //read serial

  // wait for incoming data
  if (mySerial.available() < 1) return; // if serial empty, return to loop().

  // parse incoming command start flag 
  get_char = mySerial.read();
  if (get_char != 's') return; // if no command start flag, return to loop().
  
   for (int i=255; i>=0; i--) {
    analogWrite(4, i);  // PWM the LED from 255 (max) to 0
    delay(5);
  }*/
  
 
}
void waitForResponse() {
    delay(1000);
    while (mySerial.available()) {
      analogWrite(4, HIGH);
    }
     analogWrite(4, LOW);
}

