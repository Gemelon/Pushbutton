/*------------------------------------------------------------------------
              Pushbutton Library
--------------------------------------------------------------------------
From : Thomas Stoll
Date of first issue : 06.11.2015
--------------------------------------------------------------------------
General Description

The library is used to debounce a pushbutton and interpret the
pushbutton state. If the pushbutton is pressed shortly then the
state "ButtonStateTouch" is returned. if the button is pressed a bit
longer then the state "ButtonStateHold" is returned. If the button is
held more longer then the state "ButtonStateInterval" is returned
in an interval.
------------------------------------------------------------------------
Die Bibliothek dient dazu einen Taster zu entprellen und auszuwerten.
Wird der Taster nur kurz betätigt dann wird der status "ButtonStateTouch"
zurück gegeben. Wird die Taste etwas länger betätigt dann wird der status
"ButtonStateHold" zurück gegeben. Wird der Taster noch länger gehalten
dann wird in einem Interval "ButtonStateInterval" zurück gegeben.
------------------------------------------------------------------------*/

#include "Pushbutton.h"

/*------------------------------------------------------------------------
 * Eine Instanz der Pushbutton Klasse für jeden Taster erstellen
 *------------------------------------------------------------------------*/
Pushbutton button1;
Pushbutton button2;

/*------------------------------------------------------------------------
 * Variablen für den Rückgabewert der Update- Fuktion erstellen
 *------------------------------------------------------------------------*/
byte ButtonState1;
byte ButtonState2;

void setup() {
  Serial.begin(9600);

/*------------------------------------------------------------------------
 * Die Taster initialisieren und einige Parameter einstellen
 *------------------------------------------------------------------------*/
  button1.begin(8, PullDown, 1000, 500);
  button2.begin(9, PullDown, 1000, 500);

  Serial.println ("**********************************************");
  Serial.println ("*                TwoButton test              *");
  Serial.println ("**********************************************");
}

void loop() {
  /*------------------------------------------------------------------------
   * Tastaturstatus für beide Taster abfragen
   *------------------------------------------------------------------------*/
  ButtonState1 = button1.update();
  ButtonState2 = button2.update();

  /*------------------------------------------------------------------------
   * Status auswerten
   *------------------------------------------------------------------------*/
  switch (ButtonState1){
    case ButtonStateNothing:
      /*------------------------------------------------------------------------
       * Taster wurde nicht betätigt
       *------------------------------------------------------------------------*/
      //Serial.println ("Enter Buttonstate1 = ButtonStateNothing");
    break;
    
    case ButtonStateTouch:
      /*------------------------------------------------------------------------
       * Taster wurde kurz betätigt
       *------------------------------------------------------------------------*/
      Serial.println ("Enter Buttonstate1 = ButtonStateTouch");
    break;
    
    case ButtonStateHold:
      /*------------------------------------------------------------------------
       * Taster wurde länger gehalten
       *------------------------------------------------------------------------*/
      Serial.println ("Enter Buttonstate1 = ButtonStateHold");
    break;
    
    case ButtonStateInterval:
      /*------------------------------------------------------------------------
       * Taster wurde lange gehalten
       *------------------------------------------------------------------------*/
      Serial.println ("Enter Buttonstate1 = ButtonStateInterval");
    break;    
  }
  
  switch (ButtonState2){
    case ButtonStateNothing:
      //Serial.println ("Enter Buttonstate2 = ButtonStateNothing");
    break;
    
    case ButtonStateTouch:
      Serial.println ("Enter Buttonstate2 = ButtonStateTouch");
    break;
    
    case ButtonStateHold:
      Serial.println ("Enter Buttonstate2 = ButtonStateHold");
    break;
    
    case ButtonStateInterval:
      Serial.println ("Enter Buttonstate2 = ButtonStateInterval");
    break;    
  }

}
