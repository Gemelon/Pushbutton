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

Pushbutton::Pushbutton(byte Port){
  this->_PushbuttonPort = Port;

  pinMode(Port, INPUT_PULLUP);
  
  Pushbutton();
}

Pushbutton::Pushbutton(byte Port, int HoldTime){
  this->_PushbuttonPort = Port;
  this->_PushbuttonHoldTime = HoldTime;

  pinMode(Port, INPUT_PULLUP);
  
  Pushbutton();
}

Pushbutton::Pushbutton(byte Port, int HoldTime, int HoldIntervalTime){
  
  this->_PushbuttonPort = Port;
  this->_PushbuttonHoldTime = HoldTime;
  this->_PusbuttonHoldInterval = HoldIntervalTime;
  
  pinMode(Port, INPUT_PULLUP);
  
  Pushbutton();
}

Pushbutton::Pushbutton(byte Port, int HoldTime, int HoldIntervalTime, int DebounceTimeervalTime){
  this->_PushbuttonPort = Port;
  this->_PushbuttonHoldTime = HoldTime;
  this->_PusbuttonHoldInterval = HoldIntervalTime;
  this->_PushbuttonDebounceTime = DebounceTimeervalTime;
  
  pinMode(Port, INPUT_PULLUP);
  
  Pushbutton();
}

Pushbutton::Pushbutton(byte Port, void (*PushbuttonCallBack)(byte)){
  this->_PushbuttonPort = Port;
  this->_PushBtnCallBack = PushbuttonCallBack;

  pinMode(Port, INPUT_PULLUP);
  
  Pushbutton();
}

Pushbutton::Pushbutton(byte Port, void (*PushbuttonCallBack)(byte), int HoldTime){
  this->_PushbuttonPort = Port;
  this->_PushBtnCallBack = PushbuttonCallBack;
  this->_PushbuttonHoldTime = HoldTime;
  
  pinMode(Port, INPUT_PULLUP);
  
  Pushbutton();
}

Pushbutton::Pushbutton(byte Port, void (*PushbuttonCallBack)(byte), int HoldTime, int HoldIntervalTime){
  this->_PushbuttonPort = Port;
  this->_PushBtnCallBack = PushbuttonCallBack;
  this->_PushbuttonHoldTime = HoldTime;
  this->_PusbuttonHoldInterval = HoldIntervalTime;
  
  pinMode(Port, INPUT_PULLUP);
  
  Pushbutton();
}

Pushbutton::Pushbutton(byte Port, void (*PushbuttonCallBack)(byte), int HoldTime, int HoldIntervalTime, int DebounceTimeervalTime){
  this->_PushbuttonPort = Port;
  this->_PushBtnCallBack = PushbuttonCallBack;
  this->_PushbuttonHoldTime = HoldTime;
  this->_PusbuttonHoldInterval = HoldIntervalTime;
  this->_PushbuttonDebounceTime = DebounceTimeervalTime;
  
  pinMode(Port, INPUT_PULLUP);
  
  Pushbutton();
}

// -------------------------------------------------------------------------------------------------------------------
// Initialisierung
//--------------------------------------------------------------------------------------------------------------------

void begin(){
  
}

void Pushbutton::begin(byte Port){
  this->_PushbuttonPort = Port;
  
  pinMode(Port, INPUT);
  this->_PushBtnCallBack = 0;
}

void Pushbutton::begin(byte Port, int HoldTime){
  this->_PushbuttonPort = Port;
  this->_PushBtnCallBack = 0;
  this->_PushbuttonHoldTime = HoldTime;
  
  pinMode(Port, INPUT);
}

void Pushbutton::begin(byte Port, int HoldTime, int HoldIntervalTime){
  this->_PushbuttonPort = Port;
  this->_PushBtnCallBack = 0;
  this->_PushbuttonHoldTime = HoldTime;
  this->_PusbuttonHoldInterval = HoldIntervalTime;
  
  pinMode(Port, INPUT);
}

void Pushbutton::begin(byte Port, int HoldTime, int HoldIntervalTime, int DebounceTimeervalTime){
  this->_PushbuttonPort = Port;
  this->_PushBtnCallBack = 0;
  this->_PushbuttonHoldTime = HoldTime;
  this->_PusbuttonHoldInterval = HoldIntervalTime;
  this->_PushbuttonDebounceTime = DebounceTimeervalTime;
  
  pinMode(Port, INPUT);
}

void Pushbutton::begin(byte Port, void (*PushbuttonCallBack)(byte)){
  this->_PushbuttonPort = Port;
  this->_PushBtnCallBack = PushbuttonCallBack;
  
  pinMode(Port, INPUT);
}

void Pushbutton::begin(byte Port, void (*PushbuttonCallBack)(byte), int HoldTime){
  this->_PushbuttonPort = Port;
  this->_PushBtnCallBack = PushbuttonCallBack;
  this->_PushbuttonHoldTime = HoldTime;
  
  pinMode(Port, INPUT);
}

void Pushbutton::begin(byte Port, void (*PushbuttonCallBack)(byte), int HoldTime, int HoldIntervalTime){
  this->_PushbuttonPort = Port;
  this->_PushBtnCallBack = PushbuttonCallBack;
  this->_PushbuttonHoldTime = HoldTime;
  this->_PusbuttonHoldInterval = HoldIntervalTime;
  
  pinMode(Port, INPUT);
}

void Pushbutton::begin(byte Port, void (*PushbuttonCallBack)(byte), int HoldTime, int HoldIntervalTime, int DebounceTimeervalTime){
  this->_PushbuttonPort = Port;
  this->_PushBtnCallBack = PushbuttonCallBack;
  this->_PushbuttonHoldTime = HoldTime;
  this->_PusbuttonHoldInterval = HoldIntervalTime;
  this->_PushbuttonDebounceTime = DebounceTimeervalTime;
  
  pinMode(Port, INPUT);
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
  
    // ...Überprüfen welchen zustand der Taster jetzt hat.
    if (CurrentPushbuttonState){
      // der taster ist jetzt High. das entspricht der 
      // abwärts Flanke.

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
      // aufwärts Flanke.
      _PushbuttonLowTime = millis();
    }
  }

  //*
  // Wenn der Taster immer noch gedrückt ist dann auswerten wie lange schon
  //*
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

  if(_PushBtnCallBack != 0){
    this->_PushBtnCallBack(PushbuttonState);
  }
  
  return PushbuttonState;
}

