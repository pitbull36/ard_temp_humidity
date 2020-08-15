#include <dht.h>
#include <LiquidCrystal.h>// include the library code

dht DHT;

//int tim = 250;  //the value of delay time

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);

#define DHT11_PIN 7

// custom chars
byte Thermo[8] =
{
0b01110,
0b01110,
0b01110,
0b01010,
0b01010,
0b11011,
0b10001,
0b11111
};

byte Drop[8] =
{
0b00000,
0b00100,
0b01110,
0b11111,
0b11111,
0b11111,
0b01110,
0b00000
};


// ultrasonic sensor
const int trigPin = 9; 
const int echoPin = 3;
long duration;
int distanceCM; 

// buzzer
int buzzerPin = 2;


void setup(){
  lcd.begin(16, 2);  // set up the LCD's number of columns and rows: 

  // create new characters
  lcd.createChar(0, Thermo);
  lcd.createChar(1, Drop);

  // pin of the ultrasonic sensor
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 

  // buzzer
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);

}

void loop(){

  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  distanceCM = duration*0.034/2;

  if (distanceCM <= 35) {

  lcd.clear();

  // make a beep
  digitalWrite(buzzerPin, HIGH);   // turn the buzzer on (HIGH is the voltage level)
  delay(50);                       // wait for a second
  digitalWrite(buzzerPin, LOW);    // turn the buzzer off by making the voltage LOW
  delay(50);
  digitalWrite(buzzerPin, HIGH);   // turn the buzzer on (HIGH is the voltage level)
  delay(50);                       // wait for a second
  digitalWrite(buzzerPin, LOW);    // turn the buzzer off by making the voltage LOW
  delay(250);

  // start reading temp and humidity
  int chk = DHT.read11(DHT11_PIN);
  delay(250);

  int t = DHT.temperature;
  int h = DHT.humidity;

  // display things on the LCD  
  lcd.setCursor(0,0);  // set the cursor to column 15, line 0
  lcd.print("Temp:");  // Print a message to the LCD.
  lcd.setCursor(6,0);
  lcd.print(t);
  lcd.setCursor(8, 0);
  lcd.print((char)223);
  // print the thermo cutom icon
  lcd.setCursor(10, 0);
  lcd.write(byte(0));

  lcd.setCursor(0,1);  // set the cursor to column 15, line 0
  lcd.print(" Hum:");  // Print a message to the LCD.
  lcd.setCursor(6,1);
  lcd.print(h);
  lcd.setCursor(8, 1);
  lcd.print("%");
  // print the drop custom icon
  lcd.setCursor(10, 1);
  lcd.write(byte(1));

  delay(5000);
  lcd.clear();
  
//  lcd.setCursor(17,0);  // set the cursor to column 15, line 0
//  lcd.print("Dario's weather station");
//  for (int positionCounter = 0; positionCounter < 40; positionCounter++){
//    if (distanceCM <= 35) {     // bail out on sensor detect
//    break;
//    }
//    lcd.scrollDisplayLeft();  //Scrolls the contents of the display one space to the left.
//    //lcd.print(mex[positionCounter]);  // Print a message to the LCD.
//    delay(200);
//    }

  lcd.setCursor(1,1);  // set the cursor to column 15, line 0
  lcd.print("Come closer...");
    
  }
  
  // Prints the distance on the Serial Monitor
//  Serial.print("Distance: ");
//  Serial.println(distanceCM);

  
//    delay(tim);  //wait for 250 microseconds
//    lcd.clear();  //Clears the LCD screen and positions the cursor in the upper-left corner.

//    for (int positionCounter2 = 0; positionCounter2 < 26; positionCounter2++)
//    {
//      lcd.scrollDisplayLeft();  //Scrolls the contents of the display one space to the left.
//      lcd.print(array2[positionCounter2]);  // Print a message to the LCD.
//      delay(tim);  //wait for 250 microseconds
//    }
//    lcd.clear();  //Clears the LCD screen and positions the cursor in the upper-left corner.

}
