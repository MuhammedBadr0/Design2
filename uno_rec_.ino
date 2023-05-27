#include <Wire.h>
#include <Servo.h>
#include <LiquidCrystal.h>
/* Create object named lcd of the class LiquidCrystal */
LiquidCrystal lcd(0,7,8, 2, 3, 4, 9, 10,11, 12, 13);  /* For 8-bit mode */
//LiquidCrystal lcd(13, 12, 11, 6, 5, 4, 3);  /* For 4-bit mode */

unsigned char Character1[8] = { 0x04, 0x1F, 0x11, 0x11, 0x1F, 0x1F, 0x1F, 0x1F }; /* Custom Character 1 */
unsigned char Character2[8] = { 0x01, 0x03, 0x07, 0x1F, 0x1F, 0x07, 0x03, 0x01 }; /* Custom Character 2 */



Servo myservo1;
Servo myservo2;

int z = 0; 
void setup() { 
Serial.begin(9600);
// Start the I2C Bus as Slave on address 9 
  myservo1.attach(5);
  myservo2.attach(6);
  lcd.begin(16,2);          /* Initialize 16x2 LCD */
  delay(100);
  lcd.clear();            /* Clear the LCD */
  lcd.createChar(0, Character1);  /* Generate custom character */
  lcd.createChar(1, Character2);
       /* Set cursor to column 0 row 0 */
  myservo1.write(5);
  myservo2.write(32);

Wire.begin(0x9); 
// Attach a function to trigger when something is received.
Wire.onReceive(receiveEvent); 
} 

void receiveEvent(int bytes) { 
z = Wire.read(); // read one character from the I2C 
if (z == 31) { 
lcd.setCursor(0,0); 
lcd.print("Start");
delay(2000); 
lcd.clear();
lcd.print("Geo 1");

}

}

void loop() { 
if (z == 11) {
lcd.print("Start");
delay(2000); 
lcd.print("Math1");

} 

if (z == 12) { 
lcd.print("Start");
delay(2000); 
lcd.clear();
lcd.print("Math2");

} 

if (z == 21) { 
lcd.print("Start");
delay(2000); 
lcd.clear();
lcd.print("Bio 1");

}
if (z == 22) { 
lcd.print("Start");
delay(2000); 
lcd.clear();
lcd.print("Bio 2");

}


if (z == 32) { 
lcd.print("Start");
delay(2000); 
lcd.clear();
lcd.print("Geo 2");

}

}
