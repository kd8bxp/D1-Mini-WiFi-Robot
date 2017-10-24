void robotLoop() {
  client.loop(); //Check MQTT
//ping(); //Update Ultrasonic
checkUDP(); //see if a command has been sent
ping();
//checkMode(); //this is where commands are processed
resetEncoder(); //Reset Encoder Counter if needed
ismoving(); //Reset Direction if the robot is not moving
publishMQTT(); //Update MQTT with current sensor reading & other information
yield();
}

