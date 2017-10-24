void mode1() {
  //autonomous mode/obstical avoidance. Use Time not encoder

  startTimer(5000);
  cmd=1;
  forward(maxSpeed);
  while(isRunning) {
        updateMotor();
        //robotLoop();
        ping();
        updatePing();
       publishMQTT();
        yield();
  }

  delay(100);
  yield();
  //while(1) {
  // // resetEncoder();
  // // ismoving();
   // publishMQTT();
  // robotLoop();
  //  yield();
  //}
}

void updatePing() {

volatile unsigned int ping1 = (pingavg/pingcount);

if (ping1 <= STOPDISTANCE && cmd == 1) {
  stop();
  startTimer(2000);
  backward(maxSpeed);
  while(isRunning) {
    updateMotor();
    publishMQTT();
  }
  startTimer(500);
  left(lowSpeed);
  while(isRunning) {
    updateMotor();
    publishMQTT();
  }
    cmd = 0;
}
  
   if (pingcount >= 10) { //Reset Count
    pingavg = 0;
    pingcount = 0;
    Udp.flush();
   return;
}

  
}

