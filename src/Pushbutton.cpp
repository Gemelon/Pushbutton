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

Pushbutton pushbutton;

// -------------------------------------------------------------------------------------------------------------------
// Konstruktoren
//--------------------------------------------------------------------------------------------------------------------

Pushbutton::Pushbutton(){
  _PushbuttonHighTime = millis();
  _PushbuttonLowTime = _PushbuttonHighTime;
}

Pushbutton::Pushbutton(byte Port, byte PullUpDown){
  this->_PushbuttonPort = Port;
  this->_PullUpDown = PullUpDown;

  pinMode(Port, INPUT);
  
  Pushbutton();
}

Pushbutton::Pushbutton(byte Port, byte PullUpDown, int HoldTime){
  this->_PushbuttonPort = Port;
  this->_PullUpDown = PullUpDown;
  this->_PushbuttonHoldTime = HoldTime;

  pinMode(Port, INPUT);
  
  Pushbutton();
}

Pushbutton::Pushbutton(byte Port, byte PullUpDown, int HoldTime, int HoldIntervalTime){
  
  this->_PushbuttonPort = Port;
  this->_PullUpDown = PullUpDown;
  this->_PushbuttonHoldTime = HoldTime;
  this->_PusbuttonHoldInterval = HoldIntervalTime;
  
  pinMode(Port, INPUT);
  
  Pushbutton();
}

Pushbutton::Pushbutton(byte Port, byte PullUpDown, int HoldTime, int HoldIntervalTime, int DebounceTimeervalTime){
  this->_PushbuttonPort = Port;
  this->_PullUpDown = PullUpDown;
  this->_PushbuttonHoldTime = HoldTime;
  this->_PusbuttonHoldInterval = HoldIntervalTime;
  this->_PushbuttonDebounceTime = DebounceTimeervalTime;
  
  pinMode(Port, INPUT);
  
  Pushbutton();
}

Pushbutton::Pushbutton(byte Port, byte PullUpDown, void (*PushbuttonCallBack)(byte)){
  this->_PushbuttonPort = Port;
  this->_PullUpDown = PullUpDown;
  this->_PushBtnCallBack = PushbuttonCallBack;

  pinMode(Port, INPUT);
  
  Pushbutton();
}

Pushbutton::Pushbutton(byte Port, byte PullUpDown, void (*PushbuttonCallBack)(byte), int HoldTime){
  this->_PushbuttonPort = Port;
  this->_PullUpDown = PullUpDown;
  this->_PushBtnCallBack = PushbuttonCallBack;
  this->_PushbuttonHoldTime = HoldTime;
  
  pinMode(Port, INPUT);
  
  Pushbutton();
}

Pushbutton::Pushbutton(byte Port, byte PullUpDown, void (*PushbuttonCallBack)(byte), int HoldTime, int HoldIntervalTime){
  this->_PushbuttonPort = Port;
  this->_PullUpDown = PullUpDown;
  this->_PushBtnCallBack = PushbuttonCallBack;
  this->_PushbuttonHoldTime = HoldTime;
  this->_PusbuttonHoldInterval = HoldIntervalTime;
  
  pinMode(Port, INPUT);
  
  Pushbutton();
}

Pushbutton::Pushbutton(byte Port, byte PullUpDown, void (*PushbuttonCallBack)(byte), int HoldTime, int HoldIntervalTime, int DebounceTimeervalTime){
  this->_PushbuttonPort = Port;
  this->_PullUpDown = PullUpDown;
  this->_PushBtnCallBack = PushbuttonCallBack;
  this->_PushbuttonHoldTime = HoldTime;
  this->_PusbuttonHoldInterval = HoldIntervalTime;
  this->_PushbuttonDebounceTime = DebounceTimeervalTime;
  
  pinMode(Port, INPUT);
  
  Pushbutton();
}

// -------------------------------------------------------------------------------------------------------------------
// Initialisierung
//--------------------------------------------------------------------------------------------------------------------

void begin(){
  
}

void Pushbutton::begin(byte Port, byte PullUpDown){
  this->begin(Port, PullUpDown, 0, Holdtime, HoldIntervaltime, Debouncetime);
}

void Pushbutton::begin(byte Port, byte PullUpDown, int HoldTime){
  this->begin(Port, PullUpDown, 0, HoldTime, HoldIntervaltime, Debouncetime);
}

void Pushbutton::begin(byte Port, byte PullUpDown, int HoldTime, int HoldIntervalTime){
  this->begin(Port, PullUpDown, 0, HoldTime, HoldIntervalTime, Debouncetime);
}

void Pushbutton::begin(byte Port, byte PullUpDown, int HoldTime, int HoldIntervalTime, int DebounceTime){  
  this->begin(Port, PullUpDown, 0, HoldTime, HoldIntervalTime, DebounceTime);
}

void Pushbutton::begin(byte Port, byte PullUpDown, void (*PushbuttonCallBack)(byte)){
  this->begin(Port, PullUpDown, PushbuttonCallBack, Holdtime, HoldIntervaltime, Debouncetime);
}

void Pushbutton::begin(byte Port, byte PullUpDown, void (*PushbuttonCallBack)(byte), int HoldTime){
  this->begin(Port, PullUpDown, PushbuttonCallBack, HoldTime, HoldIntervaltime, Debouncetime);
}

void Pushbutton::begin(byte Port, byte PullUpDown, void (*PushbuttonCallBack)(byte), int HoldTime, int HoldIntervalTime){
  this->begin(Port, PullUpDown, PushbuttonCallBack, HoldTime, HoldIntervalTime, Debouncetime);
}

void Pushbutton::begin(byte Port, byte PullUpDown, void (*PushbuttonCallBack)(byte), int HoldTime, int HoldIntervalTime, int DebounceTime){
  this->_PushbuttonPort = Port;
  this->_PullUpDown = PullUpDown;
  this->_PushBtnCallBack = PushbuttonCallBack;
  this->_PushbuttonHoldTime = HoldTime;
  this->_PusbuttonHoldInterval = HoldIntervalTime;
  this->_PushbuttonDebounceTime = DebounceTime;

  if(this->_PullUpDown == PullUp){
    _LastPushbuttonState = HIGH;
  } else {
    _LastPushbuttonState = LOW;
  }
  
  pinMode(Port, INPUT);
}

/*-----------------------------( PullUpDown )-----------------------------
 * 
 * Setzt einen neune Wert für den Pullup oder Pulldown Widerstand.
 * 
 * -------------------------------------------------------------------------
 * 
 * void PullUpDown(
 *    byte PullUpDown)
 * 
 ---------------------------------------------------------------------------*/
void Pushbutton::pullUpDown(byte PullUpDown){
  this->_PullUpDown = PullUpDown;
}

/*-----------------------------( DebounceTime )-----------------------------
 * 
 * Setzt einen neune Wert für die Entprellzeit.
 * 
 * -------------------------------------------------------------------------
 * 
 * void DebounceTime(
 *    int Time)
 * 
 ---------------------------------------------------------------------------*/
void Pushbutton::debounceTime(int Time){
  this->_PushbuttonDebounceTime = Time;
}

/*--------------------------------( HoldTime )------------------------------
 * 
 * Setzt einen neunen Wert für die Haltezeit
 * 
 * -------------------------------------------------------------------------
 * 
 * void HoldTime(
 *    int Time)
 * 
 ---------------------------------------------------------------------------*/
void Pushbutton::holdTime(int Time){
  this->_PushbuttonHoldTime = Time;
}

/*---------------------------( HoldIntervalTime )---------------------------
 * 
 * Setzt einen neunen Wert für die Intervallzeit
 * 
 * -------------------------------------------------------------------------
 * 
 * void HoldIntervalTime(
 *    int Time)
 * 
 ---------------------------------------------------------------------------*/
void Pushbutton::holdIntervalTime(int Time){
  this->_PusbuttonHoldInterval = Time;
}

/*---------------------------------( port )---------------------------------
 * 
 * Port festlegen oder ändern, an dem der Taster angeschlossen ist.
 * 
 * -------------------------------------------------------------------------
 * 
 * void port(
 *    byte Port)
 *    
 ---------------------------------------------------------------------------*/
void Pushbutton::port(byte Port){
  this->_PushbuttonPort = Port;
  pinMode(Port, INPUT);  
}

/*-------------------------------( callBack )-------------------------------
 * 
 * Setzt einen neuen Zeiger auf die CallBack- Funktion 
 * für das Pushbutton- Event
 * 
 * -------------------------------------------------------------------------
 * 
 * void pushbuttoncallBack(
 *    void (*PushbuttonCallBack)(byte))
 *    
 ---------------------------------------------------------------------------*/
void Pushbutton::pushbuttoncallBack(void (*PushbuttonCallBack)(byte)){
  this->_PushBtnCallBack = PushbuttonCallBack;
}

/*--------------------------------( update )--------------------------------
 * 
 * Gibt den Status des Taster zurück und meldet diesen per
 * PushButton CallBack.
 * 
 * -------------------------------------------------------------------------
 * 
 * byte update()
 * 
 ---------------------------------------------------------------------------*/
byte Pushbutton::update(){
  long PushbuttonTime;
  bool CurrentPushbuttonState;
  byte PushbuttonState = ButtonStateNothing;

  // Den momentanen Status des Tasters abfragen
  CurrentPushbuttonState = digitalRead(_PushbuttonPort);

  //*
  // Wenn sich der Status des Tasters seit dem letzten aufruf
  // geändert hat, dann...
  //*
  if (CurrentPushbuttonState != _LastPushbuttonState){

    // Den momentanen Status des Taster abspeichern
    _LastPushbuttonState = CurrentPushbuttonState;
  
    // Der Taster ist nicht mehr im Hold- Status
    _PushbuttonOnHold = false;

    if(this->_PullUpDown == PullUp){      
      // Es ist ein Pullup Widerstand am eingang angeschlossen

      // ...Überprüfen welchen zustand der Taster jetzt hat.
      if (CurrentPushbuttonState){
        // der taster ist jetzt High. das entspricht der 
        // aufwärts Flanke.
  
        // Zeit speichern zu der, der Taster nach High gewechselt hat.
        _PushbuttonHighTime = millis();
  
        // Zeit zwischen dem letzten aufruf und jetzt berechnen.
        PushbuttonTime = _PushbuttonHighTime - _PushbuttonLowTime;
  
        // War die Zeit länger als die Entprellzeit und kürzer als
        // die Haltezeit des Tasters, dann wurde der Taster nur 
        // kurz gedrückt. Der Status des Taster ist "Touch".
        if ((PushbuttonTime > _PushbuttonDebounceTime) && (PushbuttonTime < _PushbuttonHoldTime)){
          PushbuttonState = ButtonStateTouch;
        }
      } else {
        // der taster ist jetzt Low. das entspricht der 
        // abwärts Flanke.
        _PushbuttonLowTime = millis();
      }
    } else {
      // Es ist ein Pulldown Widerstand am eingang angeschlossen

      // ...Überprüfen welchen zustand der Taster jetzt hat.
      if (!CurrentPushbuttonState){
        // der taster ist jetzt LOW. das entspricht der 
        // abwärts Flanke.
  
        // Zeit speichern zu der, der Taster nach High gewechselt hat.
        _PushbuttonLowTime = millis();
  
        // Zeit zwischen dem letzten aufruf und jetzt berechnen.
        PushbuttonTime = _PushbuttonLowTime - _PushbuttonHighTime;
  
        // War die Zeit länger als die Entprellzeit und kürzer als
        // die Haltezeit des Tasters, dann wurde der Taster nur 
        // kurz gedrückt. Der Status des Taster ist "Touch".
        if ((PushbuttonTime > _PushbuttonDebounceTime) && (PushbuttonTime < _PushbuttonHoldTime)){
          PushbuttonState = ButtonStateTouch;
        }
      } else {
        // der taster ist jetzt Low. das entspricht der 
        // aufwärts Flanke.
        _PushbuttonHighTime = millis();
      }
    }
  }

  //*
  // Wenn der Taster immer noch gedrückt ist dann auswerten wie lange schon
  //*
  if(this->_PullUpDown == PullUp){      
    // Es ist ein Pullup Widerstand am eingang angeschlossen

    if (!CurrentPushbuttonState){
      // Zeit speichern zu der, der Taster nach High gewechselt hat.
      _PushbuttonHighTime = millis();
  
      // Zeit zwischen dem letzten aufruf und jetzt berechnen.
      PushbuttonTime = _PushbuttonHighTime - _PushbuttonLowTime;
  
      // Wenn der Taster noch nicht im Hold- Status ist und die Holdtime
      // überschritten wurde
      if (!_PushbuttonOnHold && (PushbuttonTime > _PushbuttonHoldTime)){
        _PushbuttonOnHold = true;
        PushbuttonState = ButtonStateHold;
      }
  
      // Wenn der Taster im Hold- Status ist dann den Intervall auslösen.
      if (_PushbuttonOnHold && ((_PushbuttonHighTime - (_PushbuttonLowTime + _PushbuttonHoldTime)) > _PusbuttonHoldInterval)){
        _PushbuttonLowTime = _PushbuttonLowTime + _PusbuttonHoldInterval;
        PushbuttonState = ButtonStateInterval;
      }
    }
  } else {
    // Es ist ein Pulldown Widerstand am eingang angeschlossen

    if (CurrentPushbuttonState){
      // Zeit speichern zu der, der Taster nach Low gewechselt hat.
      _PushbuttonLowTime = millis();
  
      // Zeit zwischen dem letzten aufruf und jetzt berechnen.
      PushbuttonTime = _PushbuttonLowTime - _PushbuttonHighTime;
  
      // Wenn der Taster noch nicht im Hold- Status ist und die Holdtime
      // überschritten wurde
      if (!_PushbuttonOnHold && (PushbuttonTime > _PushbuttonHoldTime)){
        _PushbuttonOnHold = true;
        PushbuttonState = ButtonStateHold;
      }
  
      // Wenn der Taster im Hold- Status ist dann den Intervall auslösen.
      if (_PushbuttonOnHold && ((_PushbuttonLowTime - (_PushbuttonHighTime + _PushbuttonHoldTime)) > _PusbuttonHoldInterval)){
        _PushbuttonHighTime = _PushbuttonHighTime + _PusbuttonHoldInterval;
        PushbuttonState = ButtonStateInterval;
      }
    }
  }

  if(_PushBtnCallBack != 0){
    this->_PushBtnCallBack(PushbuttonState);
  }
  
  return PushbuttonState;
}

