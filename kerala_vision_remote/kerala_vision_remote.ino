
/*
  hi,
  this a mini proj by ashwin cs
  dated: 30/07/2018 : 17:20 IST

  connect ur arduino to bluetooth module and connect ir led's +ive to pin D3 nd -ive to GND via suitable resistor
  this sends the ir signal if u send appropriate charecters to ur ardino via hc-05 bluetooth module
  serial communication
  range: 10mtrs
  apps to send data to hc05 : blynk
                            : arduino bluetooth
 
 CS CREATIONS
 Version 1.0.0
 */
#include <IRremote.h>

IRsend irsend;

void setup() {
Serial.begin(9600);
 pinMode(4, OUTPUT); // put your setup code here, to run once:
 }

void loop() {
  // put your main code here, to run repeatedly:
 if(Serial.available()>0)
   {     
      char data= Serial.read(); // reading the data received from the bluetooth module
      switch(data)
      {
        case '1':{ irsend.sendNEC(0xFF38C7,32); delay(20); irsend.sendNEC(0xFFFFFFFF,32); break;}  //power
        case '2':{ irsend.sendNEC(0xFF28D7,32); delay(20); irsend.sendNEC(0xFFFFFFFF,32); break;}  //mute
        case '3':{ irsend.sendNEC(0xFFC03F,32); delay(20); irsend.sendNEC(0xFFFFFFFF,32); break;}  //up
        case '4':{ irsend.sendNEC(0xFF40BF,32); delay(20); irsend.sendNEC(0xFFFFFFFF,32); break;}  //down
        case '5':{ irsend.sendNEC(0xFF58A7,32); delay(20); irsend.sendNEC(0xFFFFFFFF,32); break;}  //left
        case '6':{ irsend.sendNEC(0xFF708F,32); delay(20); irsend.sendNEC(0xFFFFFFFF,32); break;}  //right
        case '7':{ irsend.sendNEC(0xFFE01F,32); delay(20); irsend.sendNEC(0xFFFFFFFF,32); break;}  // ok
        case '8':{ irsend.sendNEC(0xFFA05F,32); delay(20); irsend.sendNEC(0xFFFFFFFF,32); break;}  //menu
        case '9':{ irsend.sendNEC(0xFF18E7,32); delay(20); irsend.sendNEC(0xFFFFFFFF,32); break;}  //exit
        case '0':{ irsend.sendNEC(0xFF6897,32); delay(20); irsend.sendNEC(0xFFFFFFFF,32); break;}  //previous channel
        default : break;
      }
      Serial.println(data);
   }
   delay(30);
}
