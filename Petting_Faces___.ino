#include "LedControl.h"
#include "binary.h"
/*///////////////////////////////////////////////////FACES//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
 DIN connects to pin 12
 CLK connects to pin 11
 CS connects to pin 10 
*/
LedControl lc=LedControl(12,11,10,1);
// delay time between faces
unsigned long delaytimeOpen=1700;
unsigned long delaytimeClosed=50;
// happy face
byte hf[8]= {B01100110, B00000000, B00100100, B00100100, B00000000, B01000010, B00111100, B00000000};
byte hb[8]= {B01100110, B00000000, B00000000, B00100100, B00000000, B01000010, B00111100, B00000000};
byte hbf[8]= {B01100110, B00000000, B00000000, B00000000, B00000000, B01000010, B00111100, B00000000};
//sad face
byte sf[8]= {B01100110, B10000001, B00100100, B00100100,B00000000,B00111100,B01000010,B00000000};
byte sfb[8]= {B01100110, B10000001, B00000000, B00100100,B00000000,B00111100,B01000010,B00000000};
byte sb[8]= {B01100110, B10000001, B00000000, B00000000,B00000000,B00111100,B01000010,B00000000};
//excited face
byte ef[8]= {B01100110, B00000000, B00100100, B00000000, B00111100, B00111100, B00011000, B00000000};
byte eb[8]= {B01100110, B00000000, B00000000, B00000000, B00111100, B00111100, B00011000, B00000000};
//neutral face
byte pf[8]= {B01100110, B00000000, B00100100, B00100100, B00000000, B00111100, B00000000, B00000000};
byte pfb[8]= {B01100110, B00000000, B00000000, B00100100, B00000000, B00111100, B00000000, B00000000};
byte pb[8]= {B01100110, B00000000, B00000000, B00000000, B00000000, B00111100, B00000000, B00000000};
void setup() {
  lc.shutdown(0,false);
  lc.setIntensity(0,8);
  lc.clearDisplay(0); 
  Serial.begin(9600);
}
void NeutralFaceBlinkStart(){
  lc.setRow(0,0,pf[0]);
  lc.setRow(0,1,pf[1]);
  lc.setRow(0,2,pf[2]);
  lc.setRow(0,3,pf[3]);
  lc.setRow(0,4,pf[4]);
  lc.setRow(0,5,pf[5]);
  lc.setRow(0,6,pf[6]);
  lc.setRow(0,7,pf[7]);
}
void NeutralFaceBlinkMiddle(){
  lc.setRow(0,0,pfb[0]);
  lc.setRow(0,1,pfb[1]);
  lc.setRow(0,2,pfb[2]);
  lc.setRow(0,3,pfb[3]);
  lc.setRow(0,4,pfb[4]);
  lc.setRow(0,5,pfb[5]);
  lc.setRow(0,6,pfb[6]);
  lc.setRow(0,7,pfb[7]);
}
void NeutralFaceBlinkEnd(){
  lc.setRow(0,0,pb[0]);
  lc.setRow(0,1,pb[1]);
  lc.setRow(0,2,pb[2]);
  lc.setRow(0,3,pb[3]);
  lc.setRow(0,4,pb[4]);
  lc.setRow(0,5,pb[5]);
  lc.setRow(0,6,pb[6]);
  lc.setRow(0,7,pb[7]);
  delay(delaytimeClosed);
}
void ExcitedFaceBlinkStart(){
  lc.setRow(0,0,ef[0]);
  lc.setRow(0,1,ef[1]);
  lc.setRow(0,2,ef[2]);
  lc.setRow(0,3,ef[3]);
  lc.setRow(0,4,ef[4]);
  lc.setRow(0,5,ef[5]);
  lc.setRow(0,6,ef[6]);
  lc.setRow(0,7,ef[7]);
}
void ExcitedFaceBlinkEnd(){
  lc.setRow(0,0,eb[0]);
  lc.setRow(0,1,eb[1]);
  lc.setRow(0,2,eb[2]);
  lc.setRow(0,3,eb[3]);
  lc.setRow(0,4,eb[4]);
  lc.setRow(0,5,eb[5]);
  lc.setRow(0,6,eb[6]);
  lc.setRow(0,7,eb[7]);
  delay(delaytimeClosed);
}
void SadFaceBlinkStart(){
  lc.setRow(0,0,sf[0]);
  lc.setRow(0,1,sf[1]);
  lc.setRow(0,2,sf[2]);
  lc.setRow(0,3,sf[3]);
  lc.setRow(0,4,sf[4]);
  lc.setRow(0,5,sf[5]);
  lc.setRow(0,6,sf[6]);
  lc.setRow(0,7,sf[7]);
}
void SadFaceBlinkMiddle(){
  lc.setRow(0,0,sfb[0]);
  lc.setRow(0,1,sfb[1]);
  lc.setRow(0,2,sfb[2]);
  lc.setRow(0,3,sfb[3]);
  lc.setRow(0,4,sfb[4]);
  lc.setRow(0,5,sfb[5]);
  lc.setRow(0,6,sfb[6]);
  lc.setRow(0,7,sfb[7]);
}
void SadFaceBlinkEnd(){
  lc.setRow(0,0,sb[0]);
  lc.setRow(0,1,sb[1]);
  lc.setRow(0,2,sb[2]);
  lc.setRow(0,3,sb[3]);
  lc.setRow(0,4,sb[4]);
  lc.setRow(0,5,sb[5]);
  lc.setRow(0,6,sb[6]);
  lc.setRow(0,7,sb[7]);
}
void HappyFaceBlinkStart(){
  lc.setRow(0,0,hf[0]);
  lc.setRow(0,1,hf[1]);
  lc.setRow(0,2,hf[2]);
  lc.setRow(0,3,hf[3]);
  lc.setRow(0,4,hf[4]);
  lc.setRow(0,5,hf[5]);
  lc.setRow(0,6,hf[6]);
  lc.setRow(0,7,hf[7]);
}
void HappyFaceBlinkMiddle(){
  lc.setRow(0,0,hb[0]);
  lc.setRow(0,1,hb[1]);
  lc.setRow(0,2,hb[2]);
  lc.setRow(0,3,hb[3]);
  lc.setRow(0,4,hb[4]);
  lc.setRow(0,5,hb[5]);
  lc.setRow(0,6,hb[6]);
  lc.setRow(0,7,hb[7]);
}
void HappyFaceBlinkEnd(){
  lc.setRow(0,0,hbf[0]);
  lc.setRow(0,1,hbf[1]);
  lc.setRow(0,2,hbf[2]);
  lc.setRow(0,3,hbf[3]);
  lc.setRow(0,4,hbf[4]);
  lc.setRow(0,5,hbf[5]);
  lc.setRow(0,6,hbf[6]);
  lc.setRow(0,7,hbf[7]);
}
/*/////////////////////////////////FACES////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*/


void loop(){
  NeutralFaceBlinkStart();
  delay(delaytimeOpen);
  NeutralFaceBlinkMiddle();
  delay(delaytimeClosed);
  NeutralFaceBlinkEnd();
  delay(delaytimeClosed);
  
  int sensor_value = analogRead(A0);
  Serial.println(sensor_value);
  while (sensor_value < 280){
    HappyFaceBlinkStart();
    delay(delaytimeOpen);
    HappyFaceBlinkMiddle();
    delay(delaytimeClosed);
    HappyFaceBlinkEnd();
    delay(delaytimeClosed);
    sensor_value = analogRead(A0);
    Serial.println(sensor_value);
  }
}
