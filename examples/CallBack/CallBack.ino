#include <Pushbutton.h>

Pushbutton Button1;

void btn1Callback(byte ButtonState);

byte ButtonState1;

void setup() {
  Serial.begin(9600);

  Button1.begin(8, PullDown, &btn1Callback, 1000, 500);

  Serial.println ("**********************************************");
  Serial.println ("*                CallBack test               *");
  Serial.println ("**********************************************");
}

void loop() {
    Button1.update();
}

void btn1Callback(byte ButtonState){
  switch (ButtonState){
    case ButtonStateNothing:
      //Serial.println ("Buttonstate = ButtonStateNothing");
    break;
    
    case ButtonStateTouch:
      Serial.println ("Buttonstate = ButtonStateTouch");
    break;
    
    case ButtonStateHold:
      Serial.println ("Buttonstate = ButtonStateHold");
    break;
    
    case ButtonStateInterval:
      Serial.println ("Buttonstate = ButtonStateInterval");
    break;    
  }
}

