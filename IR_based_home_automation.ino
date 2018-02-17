#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

#include <IRremote.h>

int lm=13;

int RECV_PIN = 6;//pin 6 of arduino to data pin of ir receiver
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  // put your setup code here, to run once:
pinMode(lm,OUTPUT);
Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  // put your main code here, to run repeatedly:
if (irrecv.decode(&results))
    {
     Serial.println(results.value, HEX);
     irrecv.resume(); // Receive the next value

     //LIGHT ON
     if(results.value==0x10)
    {
      digitalWrite(lm,HIGH);
      
    }
    //LIGHT OFF
    if(results.value==0x410)
    {
      digitalWrite(lm,LOW);
      
    }
    }
    
}
