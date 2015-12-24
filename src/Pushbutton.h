#ifndef _Pushbutton_h
#define _Pushbutton_h

#include "Arduino.h"

#define Debouncetime        100
#define Holdtime            1000
#define HoldIntervaltime    500

#define ButtonStateNothing  0
#define ButtonStateTouch    1
#define ButtonStateHold     2
#define ButtonStateInterval 3

#define PullUp              0
#define PullDown            1

class Pushbutton{
private:
  // -------------------------------------------------------------------------------------------------------------------
  // Private Variablen
  // -------------------------------------------------------------------------------------------------------------------
  
  // Speichert den letzten zustand des Tasters
  bool  _LastPushbuttonState = HIGH;

  // Die variable zeigt an ob sich der Taster im 
  // Hold- Status befindet
  bool _PushbuttonOnHold = false;

  // Die Zeit als der Taster nach High gewechselt hat
  long _PushbuttonHighTime;
  
  // Die Zeit als der Taster nach Low gewechselt hat
  long _PushbuttonLowTime;

  // Gibt an ob ein PullUp oder ein PullDown Widerstand verwendet wird
  byte _PullUpDown = PullUp;
  
  // Die Entprellzeit für den Taster
  int _PushbuttonDebounceTime = Debouncetime;
  
  // Die Haltezeit für den Taster
  int _PushbuttonHoldTime = Holdtime;

  // Die Intervallzeit
  int _PusbuttonHoldInterval = HoldIntervaltime;
  
  // Der port an dem der Taster angeschlossen ist.
  byte _PushbuttonPort;

  // Variabele für den Zeiger auf die 
  // Callback Funktion
  void (*_PushBtnCallBack)(byte);

public:
  // -------------------------------------------------------------------------------------------------------------------
  // Konstruktoren
  //--------------------------------------------------------------------------------------------------------------------
  
  Pushbutton();
  Pushbutton(byte Port, byte PullUpDown);
  Pushbutton(byte Port, byte PullUpDown, int HoldTime);
  Pushbutton(byte Port, byte PullUpDown, int HoldTime, int HoldIntervalTime);
  Pushbutton(byte Port, byte PullUpDown, int HoldTime, int HoldIntervalTime, int DebounceTime);
  Pushbutton(byte Port, byte PullUpDown, void (*PushbuttonCallBack)(byte));
  Pushbutton(byte Port, byte PullUpDown, void (*PushbuttonCallBack)(byte), int HoldTime);
  Pushbutton(byte Port, byte PullUpDown, void (*PushbuttonCallBack)(byte), int HoldTime, int HoldIntervalTime);
  Pushbutton(byte Port, byte PullUpDown, void (*PushbuttonCallBack)(byte), int HoldTime, int HoldIntervalTime, int DebounceTime);

  // -------------------------------------------------------------------------------------------------------------------
  // Funktionen
  //--------------------------------------------------------------------------------------------------------------------

  // Port festlegen oder ändern, an dem der Taster 
  // angeschlossen ist.
  void port(byte Port);

  // Pullup oder Pulldown einstellen
  void pullUpDown(byte PullUpDown);
  
  // Entprellzeit einstellen
  void debounceTime(int Time);

  // Haltezeit einstellen
  void holdTime(int Time);

  // Intervallzeit einstellen
  void holdIntervalTime(int Time);

  // Speichert den Zeiger auf die PushbuttonCallBack funktion
  void pushbuttoncallBack(void (*PushbuttonCallBack)(byte));

  // Initialisierung
  void begin();
  void begin(byte Port, byte PullUpDown);
  void begin(byte Port, byte PullUpDown, int HoldTime);
  void begin(byte Port, byte PullUpDown, int HoldTime, int HoldIntervalTime);
  void begin(byte Port, byte PullUpDown, int HoldTime, int HoldIntervalTime, int DebounceTimeervalTime);
  void begin(byte Port, byte PullUpDown, void (*PushbuttonCallBack)(byte));
  void begin(byte Port, byte PullUpDown, void (*PushbuttonCallBack)(byte), int HoldTime);
  void begin(byte Port, byte PullUpDown, void (*PushbuttonCallBack)(byte), int HoldTime, int HoldIntervalTime);
  void begin(byte Port, byte PullUpDown, void (*PushbuttonCallBack)(byte), int HoldTime, int HoldIntervalTime, int DebounceTimeervalTime);

  // Überprüft den zustand des Tasters
  byte update();
};

extern Pushbutton pushbutton;

#endif

