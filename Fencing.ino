#include "pitches.h"

int right = 12;
int left = 11;
int rightOFF = 10;
int noteDuration = 3000;
int state = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(rightOFF, OUTPUT);
  pinMode(right, OUTPUT);
  pinMode(left, OUTPUT);
}

void loop() {
  
  if (digitalRead(2) == HIGH) {
    state++;
    if (state == 2) {
      state = 0;
    }
  } else if (state == 0) {
    epee();
  } else if (state == 1) {
    foil();
  }
  
}

void epee() {
  if (analogRead(0) > 700) {
   delay(40);
   if (analogRead(1) < 700) {
     tone(8, NOTE_C4, noteDuration);
     digitalWrite(right, HIGH); 
     delay(3000);
     noTone(8);
     digitalWrite(right, LOW);
   } else {
       digitalWrite(right, HIGH);
       digitalWrite(left, HIGH);
       tone(8, NOTE_C4, noteDuration);
       delay(3000);
       noTone(8);
       digitalWrite(right, LOW);
       digitalWrite(left, LOW);
   }
 } else if (analogRead(1) > 700) {
     delay(40);
     if (analogRead(0) < 700) {
       tone(8, NOTE_C4, noteDuration);
       digitalWrite(left, HIGH);
       delay(3000);
       noTone(8);
       digitalWrite(left, LOW);
     } else {
       digitalWrite(right, HIGH);
       digitalWrite(left, HIGH);
       tone(8, NOTE_C4, noteDuration);
       delay(3000);
       noTone(8);
       digitalWrite(right, LOW);
       digitalWrite(left, LOW);
     }
 } else if ((analogRead(0) > 700) && (analogRead(1) > 700)) {
     digitalWrite(right, HIGH);
     digitalWrite(left, HIGH);
     tone(8, NOTE_C4, noteDuration);
     delay(3000);
     noTone(8);
     digitalWrite(right, LOW);
     digitalWrite(left, LOW);
 }
}

void foil() {
  if (analogRead(2) < 900 && analogRead(1) < 500) {
    delay(15);
    if (analogRead(2) < 900) {
      tone(8, NOTE_C4, noteDuration);
      digitalWrite(rightOFF, HIGH);
      delay(3000);
      digitalWrite(rightOFF, LOW);
    }
  } else if (analogRead(1) > 500 && analogRead(2) < 900) {
    delay(15);
    if (analogRead(1) > 500) {
      tone(8, NOTE_C4, noteDuration);
      digitalWrite(right, HIGH);
      delay(3000);
      digitalWrite(right, LOW);
    }
  }
}

    
