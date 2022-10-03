//www.elegoo.com
//2016.12.9

#include "IRremote.h"

/*-----( Global Constants )-----*/
const int receiver = 5;      // Signal Pin of IR receiver to Arduino Digital Pin 11
bool a = false;
int timelen = 50;
/*-----( Declare objects )-----*/
IRrecv IrReciever(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'


void setup(){   /*----( SETUP: RUNS ONCE )----*/
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);
  IrReciever.enableIRIn();           // Start the receiver

}/*--(end setup )---*/

void loop(){   /*----( LOOP: RUNS CONSTANTLY )----*/
  if (IrReciever.decode())   // have we received an IR signal?
  {
    for (int i = 0; i < timelen; i++){
      digitalWrite(7, HIGH);
      delay(100);
      digitalWrite(7, LOW);
      delay(100);
    }
    IrReciever.resume();
    
  }
}/* --(end main loop )-- */
