/* this function is designed to sync multiple ATTiny85s 
using a single 5 volt signal line. It counts the number 
of times called and then waits for 5 volts. To avoid 
problems with noise on the line it should be tied at 
both ends to ground with a 10K resistor. 
*/

void CountSync() {

  while (digitalRead(SYNC_PIN) == LOW) {
    // wait until high
  }
  while(digitalRead(SYNC_PIN) == HIGH){
    //wait for low
  }
  digitalWrite(INDICATOR, indicatorMasterState);
    indicatorMasterState = !indicatorMasterState ;
  

 
}