#include "Wire.h" 
#include "LedControl.h"
#include "binary.h"

//all global variables
const int MPU_ADDR = 0x68; 

//manage the accelerometer
int16_t accelerometer_x, accelerometer_y, accelerometer_z; 
int16_t gyro_x, gyro_y, gyro_z; 
int16_t temperature;


LedControl lc=LedControl(5,4,3,0.5);

// delay time between faces
unsigned long delaytime=1000;


byte p1n1[8] = {B00100000, B00100000, B00100000, B00100000, B00100000, B00000000, B00000000, B00000000};
byte p1n2[8] = {B11100000, B00100000, B11100000, B10000000, B11100000, B00000000, B00000000, B00000000};
byte p1n3[8] = {B11100000, B00100000, B11100000, B00100000, B11100000, B00000000, B00000000, B00000000};
byte p1n4[8] = {B10100000, B10100000, B11100000, B00100000, B00100000, B00000000, B00000000, B00000000};
byte p1n5[8] = {B11100000, B10000000, B11100000, B00100000, B11100000, B00000000, B00000000, B00000000};
byte p1n6[8] = {B11100000, B10000000, B11100000, B10100000, B11100000, B00000000, B00000000, B00000000};
byte p1n7[8] = {B11100000, B00100000, B00100000, B00100000, B00100000, B00000000, B00000000, B00000000};
byte p1n8[8] = {B11100000, B10100000, B11100000, B10100000, B11100000, B00000000, B00000000, B00000000};
byte p1n9[8] = {B11100000, B10100000, B11100000, B00100000, B00100000, B00000000, B00000000, B00000000};
byte p1n0[8] = {B11100000, B10100000, B10100000, B10100000, B11100000, B00000000, B00000000, B00000000};

byte p2n1[8] = {B00000010, B00000010, B00000010, B00000010, B00000010, B00000000, B00000000, B00000000};
byte p2n2[8] = {B00001110, B00000010, B00001110, B00001000, B00001110, B00000000, B00000000, B00000000};
byte p2n3[8] = {B00001110, B00000010, B00001110, B00000010, B00001110, B00000000, B00000000, B00000000};
byte p2n4[8] = {B00001010, B00001010, B00001110, B00000010, B00000010, B00000000, B00000000, B00000000};
byte p2n5[8] = {B00001110, B00001000, B00001110, B00000010, B00001110, B00000000, B00000000, B00000000};
byte p2n6[8] = {B00001110, B00001000, B00001110, B00001010, B00001110, B00000000, B00000000, B00000000};
byte p2n7[8] = {B00001110, B00000010, B00000010, B00000010, B00000010, B00000000, B00000000, B00000000};
byte p2n8[8] = {B00001110, B00001010, B00001110, B00001010, B00001110, B00000000, B00000000, B00000000};
byte p2n9[8] = {B00001110, B00001010, B00001110, B00000010, B00000010, B00000000, B00000000, B00000000};
byte p2n0[8] = {B00001110, B00001010, B00001010, B00001010, B00001110, B00000000, B00000000, B00000000};

int sa = 0;

void setup(void) {
  Serial.begin(9600);
  Wire.begin();

  lc.shutdown(0,false);
  // Set brightness to a medium value
  lc.setIntensity(0,8);
  // Clear the display
  lc.clearDisplay(0);  
  
  //accelerometer stuff
  Wire.beginTransmission(MPU_ADDR); 
  Wire.write(0x6B); 
  
  Wire.write(0);
  sa = Wire.read()<<8 | Wire.read(); 
  Wire.endTransmission(true);
}//end of setup


//the main loop
int c = 0;
void loop(void) {
  //manage accelerometer
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B); 
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 7*2, true);
  
  accelerometer_x = Wire.read()<<8 | Wire.read(); 
  accelerometer_y = Wire.read()<<8 | Wire.read();
  accelerometer_z = Wire.read()<<8 | Wire.read(); 
  temperature = Wire.read()<<8 | Wire.read();
  if (sa - accelerometer_y > 2500){ 
    Serial.println(sa - accelerometer_y);
    Serial.println("left");
  }
  else if (sa - accelerometer_y < -2500){
   Serial.println(sa - accelerometer_y);
   Serial.println("right");
  }
  delay(100);
  if (c == 0){
    c += 1;
    sa = accelerometer_y;
  }
}

void iterate(void){
    for (int i = 0; i < 10; i++){
    lc.setRow(0, 0, p1n0[0]);
    lc.setRow(0, 1, p1n0[1]);
    lc.setRow(0, 2, p1n0[2]);
    lc.setRow(0, 3, p1n0[3]);
    lc.setRow(0, 4, p1n0[4]);
    lc.setRow(0, 5, p1n0[5]);
    lc.setRow(0, 6, p1n0[6]);
    lc.setRow(0, 7, p1n0[7]);
    delay(delaytime);
    lc.setRow(0, 0, p1n1[0]);
    lc.setRow(0, 1, p1n1[1]);
    lc.setRow(0, 2, p1n1[2]);
    lc.setRow(0, 3, p1n1[3]);
    lc.setRow(0, 4, p1n1[4]);
    lc.setRow(0, 5, p1n1[5]);
    lc.setRow(0, 6, p1n1[6]);
    lc.setRow(0, 7, p1n1[7]);
    delay(delaytime);
    lc.setRow(0, 0, p1n2[0]);
    lc.setRow(0, 1, p1n2[1]);
    lc.setRow(0, 2, p1n2[2]);
    lc.setRow(0, 3, p1n2[3]);
    lc.setRow(0, 4, p1n2[4]);
    lc.setRow(0, 5, p1n2[5]);
    lc.setRow(0, 6, p1n2[6]);
    lc.setRow(0, 7, p1n2[7]);
    delay(delaytime);
    lc.setRow(0, 0, p1n3[0]);
    lc.setRow(0, 1, p1n3[1]);
    lc.setRow(0, 2, p1n3[2]);
    lc.setRow(0, 3, p1n3[3]);
    lc.setRow(0, 4, p1n3[4]);
    lc.setRow(0, 5, p1n3[5]);
    lc.setRow(0, 6, p1n3[6]);
    lc.setRow(0, 7, p1n3[7]);
    delay(delaytime);
    lc.setRow(0, 0, p1n4[0]);
    lc.setRow(0, 1, p1n4[1]);
    lc.setRow(0, 2, p1n4[2]);
    lc.setRow(0, 3, p1n4[3]);
    lc.setRow(0, 4, p1n4[4]);
    lc.setRow(0, 5, p1n4[5]);
    lc.setRow(0, 6, p1n4[6]);
    lc.setRow(0, 7, p1n4[7]);
    delay(delaytime);
    lc.setRow(0, 0, p1n5[0]);
    lc.setRow(0, 1, p1n5[1]);
    lc.setRow(0, 2, p1n5[2]);
    lc.setRow(0, 3, p1n5[3]);
    lc.setRow(0, 4, p1n5[4]);
    lc.setRow(0, 5, p1n5[5]);
    lc.setRow(0, 6, p1n5[6]);
    lc.setRow(0, 7, p1n5[7]);
    delay(delaytime);
    lc.setRow(0, 0, p1n6[0]);
    lc.setRow(0, 1, p1n6[1]);
    lc.setRow(0, 2, p1n6[2]);
    lc.setRow(0, 3, p1n6[3]);
    lc.setRow(0, 4, p1n6[4]);
    lc.setRow(0, 5, p1n6[5]);
    lc.setRow(0, 6, p1n6[6]);
    lc.setRow(0, 7, p1n6[7]);
    delay(delaytime);
    lc.setRow(0, 0, p1n7[0]);
    lc.setRow(0, 1, p1n7[1]);
    lc.setRow(0, 2, p1n7[2]);
    lc.setRow(0, 3, p1n7[3]);
    lc.setRow(0, 4, p1n7[4]);
    lc.setRow(0, 5, p1n7[5]);
    lc.setRow(0, 6, p1n7[6]);
    lc.setRow(0, 7, p1n7[7]);
    delay(delaytime);
    lc.setRow(0, 0, p1n8[0]);
    lc.setRow(0, 1, p1n8[1]);
    lc.setRow(0, 2, p1n8[2]);
    lc.setRow(0, 3, p1n8[3]);
    lc.setRow(0, 4, p1n8[4]);
    lc.setRow(0, 5, p1n8[5]);
    lc.setRow(0, 6, p1n8[6]);
    lc.setRow(0, 7, p1n8[7]);
    delay(delaytime);
    lc.setRow(0, 0, p1n9[0]);
    lc.setRow(0, 1, p1n9[1]);
    lc.setRow(0, 2, p1n9[2]);
    lc.setRow(0, 3, p1n9[3]);
    lc.setRow(0, 4, p1n9[4]);
    lc.setRow(0, 5, p1n9[5]);
    lc.setRow(0, 6, p1n9[6]);
    lc.setRow(0, 7, p1n9[7]);
    delay(delaytime);

    lc.setRow(0, 0, p2n0[0]);
    lc.setRow(0, 1, p2n0[1]);
    lc.setRow(0, 2, p2n0[2]);
    lc.setRow(0, 3, p2n0[3]);
    lc.setRow(0, 4, p2n0[4]);
    lc.setRow(0, 5, p2n0[5]);
    lc.setRow(0, 6, p2n0[6]);
    lc.setRow(0, 7, p2n0[7]);
    delay(delaytime);
    lc.setRow(0, 0, p2n1[0]);
    lc.setRow(0, 1, p2n1[1]);
    lc.setRow(0, 2, p2n1[2]);
    lc.setRow(0, 3, p2n1[3]);
    lc.setRow(0, 4, p2n1[4]);
    lc.setRow(0, 5, p2n1[5]);
    lc.setRow(0, 6, p2n1[6]);
    lc.setRow(0, 7, p2n1[7]);
    delay(delaytime);
    lc.setRow(0, 0, p2n2[0]);
    lc.setRow(0, 1, p2n2[1]);
    lc.setRow(0, 2, p2n2[2]);
    lc.setRow(0, 3, p2n2[3]);
    lc.setRow(0, 4, p2n2[4]);
    lc.setRow(0, 5, p2n2[5]);
    lc.setRow(0, 6, p2n2[6]);
    lc.setRow(0, 7, p2n2[7]);
    delay(delaytime);
    lc.setRow(0, 0, p2n3[0]);
    lc.setRow(0, 1, p2n3[1]);
    lc.setRow(0, 2, p2n3[2]);
    lc.setRow(0, 3, p2n3[3]);
    lc.setRow(0, 4, p2n3[4]);
    lc.setRow(0, 5, p2n3[5]);
    lc.setRow(0, 6, p1n3[6]);
    lc.setRow(0, 7, p1n3[7]);
    delay(delaytime);
    lc.setRow(0, 0, p2n4[0]);
    lc.setRow(0, 1, p2n4[1]);
    lc.setRow(0, 2, p2n4[2]);
    lc.setRow(0, 3, p2n4[3]);
    lc.setRow(0, 4, p2n4[4]);
    lc.setRow(0, 5, p2n4[5]);
    lc.setRow(0, 6, p2n4[6]);
    lc.setRow(0, 7, p2n4[7]);
    delay(delaytime);
    lc.setRow(0, 0, p2n5[0]);
    lc.setRow(0, 1, p2n5[1]);
    lc.setRow(0, 2, p2n5[2]);
    lc.setRow(0, 3, p2n5[3]);
    lc.setRow(0, 4, p2n5[4]);
    lc.setRow(0, 5, p2n5[5]);
    lc.setRow(0, 6, p2n5[6]);
    lc.setRow(0, 7, p2n5[7]);
    delay(delaytime);
    lc.setRow(0, 0, p2n6[0]);
    lc.setRow(0, 1, p2n6[1]);
    lc.setRow(0, 2, p2n6[2]);
    lc.setRow(0, 3, p2n6[3]);
    lc.setRow(0, 4, p2n6[4]);
    lc.setRow(0, 5, p2n6[5]);
    lc.setRow(0, 6, p2n6[6]);
    lc.setRow(0, 7, p2n6[7]);
    delay(delaytime);
    lc.setRow(0, 0, p2n7[0]);
    lc.setRow(0, 1, p2n7[1]);
    lc.setRow(0, 2, p2n7[2]);
    lc.setRow(0, 3, p2n7[3]);
    lc.setRow(0, 4, p2n7[4]);
    lc.setRow(0, 5, p2n7[5]);
    lc.setRow(0, 6, p2n7[6]);
    lc.setRow(0, 7, p2n7[7]);
    delay(delaytime);
    lc.setRow(0, 0, p2n8[0]);
    lc.setRow(0, 1, p2n8[1]);
    lc.setRow(0, 2, p2n8[2]);
    lc.setRow(0, 3, p2n8[3]);
    lc.setRow(0, 4, p2n8[4]);
    lc.setRow(0, 5, p2n8[5]);
    lc.setRow(0, 6, p2n8[6]);
    lc.setRow(0, 7, p2n8[7]);
    delay(delaytime);
    lc.setRow(0, 0, p2n9[0]);
    lc.setRow(0, 1, p2n9[1]);
    lc.setRow(0, 2, p2n9[2]);
    lc.setRow(0, 3, p2n9[3]);
    lc.setRow(0, 4, p2n9[4]);
    lc.setRow(0, 5, p2n9[5]);
    lc.setRow(0, 6, p2n9[6]);
    lc.setRow(0, 7, p2n9[7]);
    delay(delaytime);
  }
}
