void loop() {

  /*
  Serial.print("Direction: ");
  if (m1dir == 1) {Serial.print(" Forward. "); }
  if (m1dir == -1) {Serial.print(" Backward. "); }
  if (m1dir == 0) {Serial.print(" Not Moving. "); }

Serial.print(" Count: ");
Serial.println(m1count);
*/

client.loop(); //Check MQTT
ping();
checkUDP(); //see if a command has been sent
checkMode(); //this is where commands are processed
resetEncoder();
ismoving();
publishMQTT();

yield();

}


