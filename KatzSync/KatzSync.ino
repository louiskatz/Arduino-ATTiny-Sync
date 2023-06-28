
//KatzSync
/*Copyright Louis Katz 2023 See enclosed GNU 3. or later license or look it up at: https://www.gnu.org/licenses/gpl-3.0.txt

syncTestSlave
  This program is licensed to owners of Lights made by Louis Katz and may be used only in lights autorized by him.
  For more information see the Notes tab.
*/


#ifdef __AVR__
#include <avr/power.h>
#endif
#define INDICATOR 1   // defines sync indicator LED
#define LOOP_CYCLE 2  // defines LED pin for each loop cycle
//Used For Count Sync Function
#define SYNC_PIN 3              // pin master is connected to on slaves
#define MASTER_SYNC_PIN 4       //connects to slaves
#define SYNC_HIGH_DELAY 1       // delay in micro for slow slaves to catch up before going high
#define SYNC_LOW_DELAY 1        // stay at high delay before going low
bool Master = 0;                //set to 1 for master board, 0 as slave boards
bool indicatorMasterState = 1;  //state of INDICATOR  , 1 is on. If the indicator LEDs get out of sync then sync is not working.
// they switch on during one sync and off during the next. 


void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif

  pinMode(MASTER_SYNC_PIN, OUTPUT);
  pinMode(SYNC_PIN, INPUT);
  pinMode(INDICATOR, OUTPUT);
  pinMode(LOOP_CYCLE, OUTPUT);

  pinMode(LOOP_CYCLE, OUTPUT);
  // just a wiring check, just a test. Should be commented out in a final version
  digitalWrite(LOOP_CYCLE, HIGH);
  delay(3000);
  digitalWrite(LOOP_CYCLE, LOW);
  //
}
//just a test. Should be commented out in final version
void loop() {
  /// body of program. 
delay(500);
/* If the lenght of loop() becomes too long the chips won't sync. It depends on the accuracy of the microprocessor
 clock and the lenght of the program. Loop can be called multiple times each loop() if need be or the wait times 
 HIGH_SYNC_DELAY and LOW_SYNC_DELAY can be lengthened
*/

  if (Master) {
    MasterSync();
  } else {
    CountSync();
  }
}