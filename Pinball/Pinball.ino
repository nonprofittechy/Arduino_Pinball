/* Aafke's Sinterklaas gift 2012
  Program to interface with a pinball machine
  
  Machine is "started" by putting 5 quarters into coin slot.
  Once machine has started, landing the ball in the "win" hole will cause a box to open,
  releasing both quarters and a gift!

*/

#include <Servo.h>
#include "pitches.h"


// pin setup
const int coinPin = 2;
const int winPin = 3;
const int servoPin = 4;
const int ledPin = 13;
const int redLED = 10;
const int greenLED = 11;

// other constants
const int costToStart = 5;

int coinCount = 0;
int coinState = 0;
int winState = 0;

Servo myservo;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
  
  pinMode(winPin, INPUT);
  pinMode(coinPin, INPUT);
  digitalWrite(coinPin, HIGH); // enable the built-in pull-up resistor for the microswitch
  pinMode(servoPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  //myservo.attach(servoPin);
  
  //myservo.write(0); // initialize starting position of box to LOCKED
  
  digitalWrite(ledPin, LOW);
}

void loop() {
  
  //  main loop if machine is started
  if (coinCount >= costToStart) {
    digitalWrite(13, HIGH);
    
    winState = digitalRead(winPin);
    
    if (winState == HIGH ) {
      digitalWrite(11, HIGH);
      delay(100);
      digitalWrite(11, LOW);
    }
  
      //myservo.write(90); // unlock the box

  // main loop if the machine hasn't started yet
  } else {
      coinState = digitalRead(coinPin);
      
      if (coinState == HIGH) {
        play_melody();
        coinCount++;
        delay(100); // delay to avoid a single coin over-registering
      }
  }
      
}

void play_melody() {
  // notes in the melody:
  
//int melody[] = {
//  NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};

  int melody[] = {NOTE_C4};
  
  int noteDurations[] = {4};
  // note durations: 4 = quarter note, 8 = eighth note, etc.:
//  int noteDurations[] = {
//    4, 8, 8, 4,4,4,4,4 };
  
    for (int thisNote = 0; thisNote < 1; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    tone(8, melody[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }

}
