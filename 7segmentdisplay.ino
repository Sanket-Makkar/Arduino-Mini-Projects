/*
  Showing number 0-9 on a Common Anode 7-segment LED display
  Displays the numbers 0-9 on the display, with one second inbetween.
    A
   ---
F |   | B
  | G |
   ---
E |   | C
  |   |
   ---
    D
  This example code is in the public domain.
 */
 
// Pin 2-8 is connected to the 7 segments of the display.

int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8;
int D1 = 9;
int D2 = 10;
int D3 = 11;
int D4 = 12;
int arr[11];
// the setup routine runs once when you press reset:
void setup() {               
  arr[0] = 2;
  arr[1] = 3;
  arr[2] = 4;
  arr[3] = 5;
  arr[4] = 6;
  arr[5] = 7;
  arr[6] = 8;
  arr[7] = 9;
  arr[8] = 10;
  arr[9] = 11;
  arr[10] = 12; 
  // initialize the digital pins as outputs.
  pinMode(pinA, OUTPUT);     
  pinMode(pinB, OUTPUT);     
  pinMode(pinC, OUTPUT);     
  pinMode(pinD, OUTPUT);     
  pinMode(pinE, OUTPUT);     
  pinMode(pinF, OUTPUT);     
  pinMode(pinG, OUTPUT);   
  pinMode(D1, OUTPUT);  
  pinMode(D2, OUTPUT);  
  pinMode(D3, OUTPUT);  
  pinMode(D4, OUTPUT);  

  int te = 1000;
  while (te > 5){
    int n = 1045;
    int num1 = n%10;
    n/=10;
    int num2 = n%10;
    n/=10;
    int num3 = n%10;
    n/=10;
    int num4 = n%10;
  
    seg1(num1);
    delay(te);
    seg2(num2);
    delay(te);
    seg3(num3);
    delay(te);
    seg4(num4);
    delay(te);
    te = te - 100;
  }
}

// the loop routine runs over and over again forever:
void loop() {
  int n = 1045;
  int num1 = n%10;
  n/=10;
  int num2 = n%10;
  n/=10;
  int num3 = n%10;
  n/=10;
  int num4 = n%10;

  seg1(num1);
  delay(5);
  seg2(num2);
  delay(5);
  seg3(num3);
  delay(5);
  seg4(num4);
  delay(5);
  
}

void seg1(int input){
  digitalWrite(D1, LOW);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
  digitalWrite(arr[0], LOW);
  digitalWrite(arr[1], LOW);
  digitalWrite(arr[2], LOW);
  digitalWrite(arr[3], LOW);
  digitalWrite(arr[4], LOW);
  digitalWrite(arr[5], LOW);
  digitalWrite(arr[6], LOW);
  if (input == 9){
    digitalWrite(arr[0], HIGH);
    digitalWrite(arr[2], HIGH);
    digitalWrite(arr[3], HIGH);
    digitalWrite(arr[4], HIGH);
    digitalWrite(arr[5], HIGH);
    digitalWrite(arr[6], HIGH);
  }
  else if (input == 8){
    digitalWrite(arr[0], HIGH);
    digitalWrite(arr[1], HIGH);
    digitalWrite(arr[2], HIGH);
    digitalWrite(arr[3], HIGH);
    digitalWrite(arr[4], HIGH);
    digitalWrite(arr[5], HIGH);
    digitalWrite(arr[6], HIGH);
  }
  else if (input == 7){
    digitalWrite(arr[3], HIGH);
    digitalWrite(arr[4], HIGH);
    digitalWrite(arr[5], HIGH);
  }
  else if (input == 6){
    digitalWrite(arr[0], HIGH);
    digitalWrite(arr[1], HIGH);
    digitalWrite(arr[2], HIGH);
    digitalWrite(arr[3], HIGH);
    digitalWrite(arr[5], HIGH);
    digitalWrite(arr[6], HIGH);
  }
  else if (input == 5){
    digitalWrite(arr[0], HIGH);
    digitalWrite(arr[2], HIGH);
    digitalWrite(arr[3], HIGH);
    digitalWrite(arr[5], HIGH);
    digitalWrite(arr[6], HIGH);
  }
  else if (input == 4){
    digitalWrite(arr[2], HIGH);
    digitalWrite(arr[4], HIGH);
    digitalWrite(arr[5], HIGH);
    digitalWrite(arr[6], HIGH);
  }
  else if (input == 3){
    digitalWrite(arr[0], HIGH);
    digitalWrite(arr[3], HIGH);
    digitalWrite(arr[4], HIGH);
    digitalWrite(arr[5], HIGH);
    digitalWrite(arr[6], HIGH);
  }
  else if (input == 2){
    digitalWrite(arr[0], HIGH);
    digitalWrite(arr[1], HIGH);
    digitalWrite(arr[3], HIGH);
    digitalWrite(arr[4], HIGH);
    digitalWrite(arr[6], HIGH);
  }
  else if (input == 1){
    digitalWrite(arr[4], HIGH);
    digitalWrite(arr[5], HIGH);
  }
  else if (input == 0){
    digitalWrite(arr[0], HIGH);
    digitalWrite(arr[1], HIGH);
    digitalWrite(arr[2], HIGH);
    digitalWrite(arr[3], HIGH);
    digitalWrite(arr[4], HIGH);
    digitalWrite(arr[5], HIGH);
  }
}

void seg2(int input){
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
  digitalWrite(arr[0], LOW);
  digitalWrite(arr[1], LOW);
  digitalWrite(arr[2], LOW);
  digitalWrite(arr[3], LOW);
  digitalWrite(arr[4], LOW);
  digitalWrite(arr[5], LOW);
  digitalWrite(arr[6], LOW);
  if (input == 9){
    digitalWrite(arr[0], HIGH);
    digitalWrite(arr[2], HIGH);
    digitalWrite(arr[3], HIGH);
    digitalWrite(arr[4], HIGH);
    digitalWrite(arr[5], HIGH);
    digitalWrite(arr[6], HIGH);
  }
  else if (input == 8){
    digitalWrite(arr[0], HIGH);
    digitalWrite(arr[1], HIGH);
    digitalWrite(arr[2], HIGH);
    digitalWrite(arr[3], HIGH);
    digitalWrite(arr[4], HIGH);
    digitalWrite(arr[5], HIGH);
    digitalWrite(arr[6], HIGH);
  }
  else if (input == 7){
    digitalWrite(arr[3], HIGH);
    digitalWrite(arr[4], HIGH);
    digitalWrite(arr[5], HIGH);
  }
  else if (input == 6){
    digitalWrite(arr[0], HIGH);
    digitalWrite(arr[1], HIGH);
    digitalWrite(arr[2], HIGH);
    digitalWrite(arr[3], HIGH);
    digitalWrite(arr[5], HIGH);
    digitalWrite(arr[6], HIGH);
  }
  else if (input == 5){
    digitalWrite(arr[0], HIGH);
    digitalWrite(arr[2], HIGH);
    digitalWrite(arr[3], HIGH);
    digitalWrite(arr[5], HIGH);
    digitalWrite(arr[6], HIGH);
  }
  else if (input == 4){
    digitalWrite(arr[2], HIGH);
    digitalWrite(arr[4], HIGH);
    digitalWrite(arr[5], HIGH);
    digitalWrite(arr[6], HIGH);
  }
  else if (input == 3){
    digitalWrite(arr[0], HIGH);
    digitalWrite(arr[3], HIGH);
    digitalWrite(arr[4], HIGH);
    digitalWrite(arr[5], HIGH);
    digitalWrite(arr[6], HIGH);
  }
  else if (input == 2){
    digitalWrite(arr[0], HIGH);
    digitalWrite(arr[1], HIGH);
    digitalWrite(arr[3], HIGH);
    digitalWrite(arr[4], HIGH);
    digitalWrite(arr[6], HIGH);
  }
  else if (input == 1){
    digitalWrite(arr[4], HIGH);
    digitalWrite(arr[5], HIGH);
  }
  else if (input == 0){
    digitalWrite(arr[0], HIGH);
    digitalWrite(arr[1], HIGH);
    digitalWrite(arr[2], HIGH);
    digitalWrite(arr[3], HIGH);
    digitalWrite(arr[4], HIGH);
    digitalWrite(arr[5], HIGH);
  }
}

void seg3(int input){
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, LOW);
  digitalWrite(D4, HIGH);
  digitalWrite(arr[0], LOW);
  digitalWrite(arr[1], LOW);
  digitalWrite(arr[2], LOW);
  digitalWrite(arr[3], LOW);
  digitalWrite(arr[4], LOW);
  digitalWrite(arr[5], LOW);
  digitalWrite(arr[6], LOW);
  if (input == 9){
    digitalWrite(arr[0], HIGH);
    digitalWrite(arr[2], HIGH);
    digitalWrite(arr[3], HIGH);
    digitalWrite(arr[4], HIGH);
    digitalWrite(arr[5], HIGH);
    digitalWrite(arr[6], HIGH);
  }
  else if (input == 8){
    digitalWrite(arr[0], HIGH);
    digitalWrite(arr[1], HIGH);
    digitalWrite(arr[2], HIGH);
    digitalWrite(arr[3], HIGH);
    digitalWrite(arr[4], HIGH);
    digitalWrite(arr[5], HIGH);
    digitalWrite(arr[6], HIGH);
  }
  else if (input == 7){
    digitalWrite(arr[3], HIGH);
    digitalWrite(arr[4], HIGH);
    digitalWrite(arr[5], HIGH);
  }
  else if (input == 6){
    digitalWrite(arr[0], HIGH);
    digitalWrite(arr[1], HIGH);
    digitalWrite(arr[2], HIGH);
    digitalWrite(arr[3], HIGH);
    digitalWrite(arr[5], HIGH);
    digitalWrite(arr[6], HIGH);
  }
  else if (input == 5){
    digitalWrite(arr[0], HIGH);
    digitalWrite(arr[2], HIGH);
    digitalWrite(arr[3], HIGH);
    digitalWrite(arr[5], HIGH);
    digitalWrite(arr[6], HIGH);
  }
  else if (input == 4){
    digitalWrite(arr[2], HIGH);
    digitalWrite(arr[4], HIGH);
    digitalWrite(arr[5], HIGH);
    digitalWrite(arr[6], HIGH);
  }
  else if (input == 3){
    digitalWrite(arr[0], HIGH);
    digitalWrite(arr[3], HIGH);
    digitalWrite(arr[4], HIGH);
    digitalWrite(arr[5], HIGH);
    digitalWrite(arr[6], HIGH);
  }
  else if (input == 2){
    digitalWrite(arr[0], HIGH);
    digitalWrite(arr[1], HIGH);
    digitalWrite(arr[3], HIGH);
    digitalWrite(arr[4], HIGH);
    digitalWrite(arr[6], HIGH);
  }
  else if (input == 1){
    digitalWrite(arr[4], HIGH);
    digitalWrite(arr[5], HIGH);
  }
  else if (input == 0){
    digitalWrite(arr[0], HIGH);
    digitalWrite(arr[1], HIGH);
    digitalWrite(arr[2], HIGH);
    digitalWrite(arr[3], HIGH);
    digitalWrite(arr[4], HIGH);
    digitalWrite(arr[5], HIGH);
  }
}

void seg4(int input){
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, LOW);
  digitalWrite(arr[0], LOW);
  digitalWrite(arr[1], LOW);
  digitalWrite(arr[2], LOW);
  digitalWrite(arr[3], LOW);
  digitalWrite(arr[4], LOW);
  digitalWrite(arr[5], LOW);
  digitalWrite(arr[6], LOW);
  if (input == 9){
    digitalWrite(arr[0], HIGH);
    digitalWrite(arr[2], HIGH);
    digitalWrite(arr[3], HIGH);
    digitalWrite(arr[4], HIGH);
    digitalWrite(arr[5], HIGH);
    digitalWrite(arr[6], HIGH);
  }
  else if (input == 8){
    digitalWrite(arr[0], HIGH);
    digitalWrite(arr[1], HIGH);
    digitalWrite(arr[2], HIGH);
    digitalWrite(arr[3], HIGH);
    digitalWrite(arr[4], HIGH);
    digitalWrite(arr[5], HIGH);
    digitalWrite(arr[6], HIGH);
  }
  else if (input == 7){
    digitalWrite(arr[3], HIGH);
    digitalWrite(arr[4], HIGH);
    digitalWrite(arr[5], HIGH);
  }
  else if (input == 6){
    digitalWrite(arr[0], HIGH);
    digitalWrite(arr[1], HIGH);
    digitalWrite(arr[2], HIGH);
    digitalWrite(arr[3], HIGH);
    digitalWrite(arr[5], HIGH);
    digitalWrite(arr[6], HIGH);
  }
  else if (input == 5){
    digitalWrite(arr[0], HIGH);
    digitalWrite(arr[2], HIGH);
    digitalWrite(arr[3], HIGH);
    digitalWrite(arr[5], HIGH);
    digitalWrite(arr[6], HIGH);
  }
  else if (input == 4){
    digitalWrite(arr[2], HIGH);
    digitalWrite(arr[4], HIGH);
    digitalWrite(arr[5], HIGH);
    digitalWrite(arr[6], HIGH);
  }
  else if (input == 3){
    digitalWrite(arr[0], HIGH);
    digitalWrite(arr[3], HIGH);
    digitalWrite(arr[4], HIGH);
    digitalWrite(arr[5], HIGH);
    digitalWrite(arr[6], HIGH);
  }
  else if (input == 2){
    digitalWrite(arr[0], HIGH);
    digitalWrite(arr[1], HIGH);
    digitalWrite(arr[3], HIGH);
    digitalWrite(arr[4], HIGH);
    digitalWrite(arr[6], HIGH);
  }
  else if (input == 1){
    digitalWrite(arr[4], HIGH);
    digitalWrite(arr[5], HIGH);
  }
  else if (input == 0){
    digitalWrite(arr[0], HIGH);
    digitalWrite(arr[1], HIGH);
    digitalWrite(arr[2], HIGH);
    digitalWrite(arr[3], HIGH);
    digitalWrite(arr[4], HIGH);
    digitalWrite(arr[5], HIGH);
  }
}
