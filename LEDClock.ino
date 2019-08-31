// Date and time functions using a DS3231 msr connected via I2C and Wire lib
#include "RTClib.h"
#include <Adafruit_NeoPixel.h>

// LED Pins - Der Pin am Arduino vom dem das Daten Signal rausgeht
#define msLED_PIN     2  
#define hLED_PIN      3  
#define dLED_PIN      4  
#define wdLED_PIN     5  
#define mLED_PIN      6              

// LED COUNT - Anzahl an LEDs im Ring oder Strip
#define msLED_COUNT   60 
#define hLED_COUNT    12 
#define dLED_COUNT    12 
#define wdLED_COUNT   7 
#define mLED_COUNT    10           
 
// Declare NeoPixel objects:
Adafruit_NeoPixel hLED(hLED_COUNT, hLED_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel msLED(msLED_COUNT, msLED_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel dLED(dLED_COUNT, dLED_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel wdLED(wdLED_COUNT, wdLED_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel mLED(mLED_COUNT, mLED_PIN, NEO_GRB + NEO_KHZ800);

// Farben
uint8_t msColorR[msLED_COUNT]; 
uint8_t msColorG[msLED_COUNT];            
uint8_t msColorB[msLED_COUNT]; 

uint8_t hColorR[hLED_COUNT]; 
uint8_t hColorG[hLED_COUNT];            
uint8_t hColorB[hLED_COUNT]; 

uint8_t dColorR[dLED_COUNT]; 
uint8_t dColorG[dLED_COUNT];            
uint8_t dColorB[dLED_COUNT]; 

uint8_t wdColorR[wdLED_COUNT]; 
uint8_t wdColorG[wdLED_COUNT];            
uint8_t wdColorB[wdLED_COUNT]; 

uint8_t mColorR[mLED_COUNT]; 
uint8_t mColorG[mLED_COUNT];            
uint8_t mColorB[mLED_COUNT]; 

uint32_t msColors;
uint32_t hColors;
uint32_t dColors;
uint32_t wdColors;
uint32_t mColors;

uint32_t clearColor = msLED.Color(0 , 0 , 0);  

// Variablen
uint8_t x;
uint8_t y;
uint8_t z;
uint8_t i;


RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup () {

  msLED.begin();
  msLED.setBrightness(20);
  msLED.show();  

  // Fabre definieren: hue Spektrum (Rainbow)
  do{
    for (i = 0; i < msLED.numPixels(); i++)
    {
      lsrColors = msLED.ColorHSV(i * 65536 / msLED.numPixels(), 255, 30);
      //msLED.setPixelColor(i, lsrColors);
      msColorR[i] = (lsrColors >> 16 & 0xFF);
      msColorG[i] = (lsrColors >> 8 & 0xFF);
      msColorB[i] = (lsrColors & 0xFF);
    }
    x++;
  } while (x < msLED.numPixels());


#ifndef ESP8266
  while (!Serial); // for Leonardo/Micro/Zero
#endif

  Serial.begin(9600);

  delay(3000); // wait for console opening

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
}

void loop () {
    
  DateTime now = rtc.now();
/*
Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();

    Serial.print(" since midnight 1/1/1970 = ");
    Serial.print(now.unixtime());
    Serial.print("s = ");
    Serial.print(now.unixtime() / 86400L);
    Serial.println("d");

    // calculate a date which is 7 days and 30 seconds into the future
    DateTime future (now + TimeSpan(7,12,30,6));

    Serial.print(" now + 7d + 30s: ");
    Serial.print(future.year(), DEC);
    Serial.print('/');
    Serial.print(future.month(), DEC);
    Serial.print('/');
    Serial.print(future.day(), DEC);
    Serial.print(' ');
    Serial.print(future.hour(), DEC);
    Serial.print(':');
    Serial.print(future.minute(), DEC);
    Serial.print(':');
    Serial.print(future.second(), DEC);
    Serial.println();

    Serial.print("Temperature: ");
    Serial.print(rtc.getTemperature());
    Serial.println(" C");

    Serial.println();
   
*/  


  
 

// if(now.second() == 0){  msLED.clear();   }

  
  

// Set LED for Minutes and Seconds
if(now.minute() > now.second() && now.second() != 0){
  
  msLED.clear();

  x = 0;
  do
  {
    for (i = 0; i < now.minute() ; i++)
    {
      msLED.setPixelColor(i, msColorR[i], msColorG[i], msColorB[i]);
    }
    x++;
  } while (x < (now.minute() ));

  msLED.fill(clearColor, 0, now.second()-1 );
}

if(now.minute() == now.second() ){
    msLED.clear();
    msLED.setPixelColor(now.second()-1, msColorR[now.second()], msColorG[now.second()], msColorB[now.second()]);  
}

if(now.minute() < now.second() ){
    msLED.setPixelColor(now.second()-1 , msColorR[now.second()], msColorG[now.second()], msColorB[now.second()]);  
}

if(now.second() == 0){
    msLED.setPixelColor(msLED.numPixels()-1, msColorR[now.second()], msColorG[now.second()], msColorB[now.second()]);  
}    
  
msLED.show();


// Set LED for Hours

// Set LED for Days

// Set LED for Workdays

// Set LED for Month



}
