#include "Pushbutton.h"

Pushbutton button1;
Pushbutton button2;

byte ButtonState1;
byte ButtonState2;

void setup() {
  Serial.begin(9600);

  button1.begin(8, PullDown, 1000, 500);
  button2.begin(9, PullDown, 1000, 500);

  Serial.println ("**********************************************");
  Serial.println ("*                TwoButton test              *");
  Serial.println ("**********************************************");
}

void loop() {
  ButtonState1 = button1.update();
  ButtonState2 = button2.update();

  switch (ButtonState1){
    case ButtonStateNothing:
      // If the button is not pressed
      //Serial.println ("Enter Buttonstate1 = ButtonStateNothing");
    break;
    
    case ButtonStateTouch:
      Serial.println ("Enter Buttonstate1 = ButtonStateTouch");
    break;
    
    case ButtonStateHold:
      Serial.println ("Enter Buttonstate1 = ButtonStateHold");
    break;
    
    case ButtonStateInterval:
      Serial.println ("Enter Buttonstate1 = ButtonStateInterval");
    break;    
  }
  
  switch (ButtonState2){
    case ButtonStateNothing:
      // If the button is not pressed
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
