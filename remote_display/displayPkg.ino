void displayPkg() {
  
  display.clear();
  display.setFont(ArialMT_Plain_10);
  display.drawString(0,0,"Remote Display.");
  display.drawString(0,11,"Distance: "); 
  display.drawString(52,11,(String)distanceIN);
  display.drawString(0,22,"Ct: ");
  char temp[30];
  snprintf(temp,30,"%d,%d", m1steps,m2steps);
  //display.drawString(50,24, (String)m1steps);
  //display.drawString(52,24, ",");
  //display.drawString(55,24, (String)m2steps);
  display.drawString(25, 22, temp);
  display.drawString(0,33, "Dir: ");
  if (m1dir == 0) {display.drawString(25,33, "S");}
  if (m1dir == -1) {display.drawString(25,33, "R");}
  if (m1dir == 1) {display.drawString(25,33, "F");}
  if (m2dir == 0) {display.drawString(30, 33, ",S");}
  if (m2dir == -1) {display.drawString(30, 33, ",R");}
  if (m2dir == 1) {display.drawString(30, 33, ",F");}
  display.drawString(0, 44, RobotID.substring(5));
  display.drawString(0, 54, IPremote);
  display.display();
}
