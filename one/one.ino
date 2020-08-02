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
        case '1':{ irsend.sendNEC(0x488F3CBB,32); delay(20); irsend.sendNEC(0xFFFFFFFF,32); break;}
        case '2':{ irsend.sendNEC(0xFF28D7,32); delay(20); irsend.sendNEC(0xFFFFFFFF,32); break;}
        case '3':{ irsend.sendNEC(0xFFC03F,32); delay(20); irsend.sendNEC(0xFFFFFFFF,32); break;}
        case '4':{ irsend.sendNEC(0xFF40BF,32); delay(20); irsend.sendNEC(0xFFFFFFFF,32); break;}
        case '5':{ irsend.sendNEC(0xFF58A7,32); delay(20); irsend.sendNEC(0xFFFFFFFF,32); break;}
        case '6':{ irsend.sendNEC(0xFF708F,32); delay(20); irsend.sendNEC(0xFFFFFFFF,32); break;}
        case '7':{ irsend.sendNEC(0xF076C13B,32); delay(20); irsend.sendNEC(0xFFFFFFFF,32); break;}
        //case '8':{ irsend.sendNEC(0xFFC03F,32); delay(20); irsend.sendNEC(0xFFFFFFFF,32); break;}
        //case '9':{ irsend.sendNEC(0xFFC03F,32); delay(20); irsend.sendNEC(0xFFFFFFFF,32); break;}
        default : break;
      }
      Serial.println(data);
   }
   delay(50);
}
