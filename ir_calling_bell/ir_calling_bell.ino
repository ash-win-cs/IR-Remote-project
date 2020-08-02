/*
  IR Receiver Demonstration 2
  IR-Rcv-Demo2.ino
  Determine IR codes manufacturer type with IR Receiver
  Displays results on Serial Monitor
  DroneBot Workshop 2017
  http://dronebotworkshop.com
*/

// Include IR Remote Library by Ken Shirriff
#include <IRremote.h>

// Define sensor pin
const int RECV_PIN = 4;
const int LED_PIN12 = 12;
const int L_PIN5 = 5;
const int L_PIN2 = 2;

int b;

// Define IR Receiver and Results Objects
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup(){
  // Serial Monitor @ 9600 baud
  Serial.begin(9600);
  // Enable the IR Receiver
  irrecv.enableIRIn();
  pinMode(LED_PIN12,OUTPUT);
  pinMode(L_PIN5,OUTPUT);
  pinMode(L_PIN2,OUTPUT);
}

void loop(){
  digitalWrite(L_PIN5,HIGH);
  digitalWrite(L_PIN2,LOW);
  if (irrecv.decode(&results)){
        switch (results.decode_type){
            case SONY: 
             b=(results.value);
             if(b==-7928){
             Serial.println(b); 
             Serial.println("SONY"); 
             digitalWrite(LED_PIN12,HIGH);
             delay(100);
             digitalWrite(LED_PIN12,LOW);
             }break;
            default:
            case UNKNOWN:  
              break;
          }
        irrecv.resume();
 }
}
