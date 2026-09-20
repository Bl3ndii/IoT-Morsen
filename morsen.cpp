/**************************************************************************
* morse application
***************************************************************************/
#include "Particle.h"

// View logs with CLI using 'particle serial monitor --follow'
SerialLogHandler logHandler(LOG_LEVEL_INFO);

const int buttonPin = D5;

int buttonState = HIGH;
int oldButtonState = HIGH;
int lowCycles = 0;
int highCycles = 0;
int charLength = 0;

String morseCode = "";


// morse configuration
const int maxHighCycles = 15;


void setup() {  
    pinMode(buttonPin, INPUT_PULLUP); 
}

void loop() {      
    buttonState = digitalRead(buttonPin);

    if (buttonState == LOW) {
        // button is pressed
        lowCycles++;
        highCycles = 0;
    } else {
        // button is released
        highCycles++; 
        if (buttonState != oldButtonState) {
            // button was just released
            charLength++;
            if (lowCycles <= 1) {
                morseCode += ".";
                // Log.info("duration: " + String("."));
            } else if ( lowCycles > 1 and lowCycles <= 3) {
                morseCode += "_";
                // Log.info("duration: " + String("_"));
            }
            //Log.info("duration: " + String(lowCycles));
        } 
        lowCycles = 0;
    }
    
    if (highCycles >= maxHighCycles && charLength > 0) {
        // Log.info("charlength: " + String(charLength));
        // Log.info("morse code: " + morseCode);
        if (morseCode == "._") {
            Log.info("letter: A");
        } else if (morseCode == "_...") {
            Log.info("letter: B");
        } else if (morseCode == "_._.") {
            Log.info("letter: C");
        } else if (morseCode == "_..") {
            Log.info("letter: D");
        } else if (morseCode == ".") {
            Log.info("letter: E");
        } else if (morseCode == ".._.") {
            Log.info("letter: F");
        } else if (morseCode == "__.") {
            Log.info("letter: G");
        } else if (morseCode == "....") {
            Log.info("letter: H");
        } else if (morseCode == "..") {
            Log.info("letter: I");
        } else if (morseCode == ".___") {
            Log.info("letter: J");
        } else if (morseCode == "_._") {
            Log.info("letter: K");
        } else if (morseCode == "._..") {
            Log.info("letter: L");
        } else if (morseCode == "__") {
            Log.info("letter: M");
        } else if (morseCode == "_.") {
            Log.info("letter: N");
        } else if (morseCode == "___") {
            Log.info("letter: O");
        } else if (morseCode == ".__.") {
            Log.info("letter: P");
        } else if (morseCode == "__._") {
            Log.info("letter: Q");
        } else if (morseCode == "._.") {
            Log.info("letter: R");
        } else if (morseCode == "...") {
            Log.info("letter: S");
        } else if (morseCode == "_") {
            Log.info("letter: T");
        } else if (morseCode == ".._") {
            Log.info("letter: U");
        } else if (morseCode == "..._") {
            Log.info("letter: V");
        } else if (morseCode == ".__") {
            Log.info("letter: W");
        } else if (morseCode == "_.._") {
            Log.info("letter: X");
        } else if (morseCode == "_.__") {
            Log.info("letter: Y");
        } else if (morseCode == "__..") {
            Log.info("letter: Z");
        } else if (morseCode == "_____") {
            Log.info("letter: 0");
        } else if (morseCode == ".____") {
            Log.info("letter: 1");
        } else if (morseCode == "..___") {
            Log.info("letter: 2");
        } else if (morseCode == "...__") {
            Log.info("letter: 3");
        } else if (morseCode == "...._") {
            Log.info("letter: 4");
        } else if (morseCode == ".....") {
            Log.info("letter: 5");
        } else if (morseCode == "_....") {
            Log.info("letter: 6");
        } else if (morseCode == "__...") {
            Log.info("letter: 7");
        } else if (morseCode == "___..") {
            Log.info("letter: 8");
        } else if (morseCode == "____.") {
            Log.info("letter: 9");
        } else {
            Log.info("unknown morse code: " + morseCode);
        }
        highCycles = 0;
        charLength = 0;
        morseCode = "";
    }
    
    oldButtonState = buttonState;
    
    delay(200); 
}