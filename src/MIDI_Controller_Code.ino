/*
   CS 207 Final Project: Arduino Control Surface for Logic Pro X

   Allows a six-slider control surface powered by the Arduino Uno to communicate with various software
   in order to input track automation data.

   The Circuit:
   -six 11K sliding potentiometers connected to analog input pins A0, A1, A2, A3, A4, and A5
   -potentiometers likewise connected to 5V (with 560 Ohm resistors) and ground

   created by StarFire Tech
   on December 08 2009
   https://starfiretech.wordpress.com/2009/12/08/simple-arduino-midi-controler/

   modified by APW-Design
   in 2017
   https://www.instructables.com/Easy-3-Pot-Potentiometer-Arduino-Uno-Effects-Midi-/

   modified by Anika Zak
   on December 02 2020

*/

#include <MIDI.h> // Arduino MIDI Library included 


int val[6] = {0, 0, 0, 0, 0, 0}; // The initial pot values. One needed for the first value and a second to test if there has been a change made.
int lastVal[6] = {0, 0, 0, 0, 0, 0};
const int pins [6] = {A0, A1, A2, A3, A4, A5}; // Initialize the analog pins as input

MIDI_CREATE_DEFAULT_INSTANCE(); // Create and bind the MIDI interface to the default hardware Serial port

void setup() {
  MIDI.begin(1); // Listen to all incoming messages
  Serial.begin(115200); // Sets clock speed of serial port


}


void loop()
{
  MIDI.read(); // Read incoming messages

  for (int i = 0; i < 6; i++) // Begin at 0 and increase until 6: continue looping through
  {
    val[i] = analogRead (pins [i]) / 8; // Read the pin signal and divide by 8 to get range of 0-127 for MIDI
    if (val[i] != lastVal[i]) // If the value does not = the last value the following command is made because the pot has been turned. Otherwise the pot remains the same and no MIDI message is output.
    {
      MIDImessage(176, 1, val[i]);
    } // 176 = CC command (channel 1 control change), 1 = Which Control, val = value read from Potentionmeter 1. NOTE: this says val not val1.
    lastVal[i] = val[i];

  }


  delay(20); // A short delay to help prevent slight fluctuations, knocks on the pots, jumping around in value, etc.
}

void MIDImessage(byte command, byte data1, byte data2) // Pass values out through standard Midi Command
{
  Serial.write(command); // Passes MIDI messages through serial port
  Serial.write(data1);
  Serial.write(data2);
}
