/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/toneMelody
*/

#include "pitches.h"

#define POWER_PIN 26
#define LIGHTS_PIN 36
#define WAKE_PIN 18
#define BUZZER_PIN 19
#define BATTERYREAD_PIN 25
#define CANRX_PIN 32
#define CANTX_PIN 33



int x = 0;
// notes in the melody:
int melody[] = {
NOTE_E7, NOTE_DS7, NOTE_E7, NOTE_DS7, NOTE_E7, NOTE_B6, NOTE_D7, NOTE_C7, NOTE_A6, NOTE_C6, NOTE_E6, NOTE_A6, NOTE_B6, NOTE_E6, NOTE_GS6, NOTE_B6, NOTE_C7, NOTE_E7, NOTE_E7, NOTE_E7


};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = { 
8, 8, 8, 8, 8, 8, 8, 8, 4, 8, 8, 4, 4, 8, 8, 4, 4, 8, 8, 8


};

void setup() {
  Serial.begin(115200);
  pinMode(POWER_PIN, OUTPUT);
  pinMode(LIGHTS_PIN, OUTPUT);
  pinMode(WAKE_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BATTERYREAD_PIN, INPUT);
  pinMode(CANRX_PIN, OUTPUT);
  pinMode(CANTX_PIN, OUTPUT);


  
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < sizeof(melody) / sizeof(melody[0]); thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(BUZZER_PIN, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(BUZZER_PIN);
  }
}

void loop() {
  // no need to repeat the melody.
  Serial.print(x++);
  digitalWrite(POWER_PIN, HIGH);
  digitalWrite(LIGHTS_PIN, HIGH);
  delay(1000);
  digitalWrite(POWER_PIN, LOW);
  digitalWrite(LIGHTS_PIN, LOW);
  delay(1000);

  
  
  
}
