/* This sends a 1 microsecond pulse to other microcontrollers to sync them. It should result in all microcontrollers being within 1 microsecond.
*/
void MasterSync() {
  //delayMicroseconds(1000);
  delay(SYNC_HIGH_DELAY);
  //delay(SYNC_HIGH_DELAY);
  digitalWrite(MASTER_SYNC_PIN, HIGH);
  delay(SYNC_LOW_DELAY);
  digitalWrite(INDICATOR, indicatorMasterState);
  indicatorMasterState = !indicatorMasterState;
  digitalWrite(MASTER_SYNC_PIN, LOW);
}
