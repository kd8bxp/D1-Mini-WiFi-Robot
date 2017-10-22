void decodePacket(char* msg1) {

   StaticJsonBuffer<200> jsonBuffer;
JsonObject& root = jsonBuffer.parseObject(msg1);
//Serial.println(msg1);
if (!root.success()) {
    Serial.println("parseObject() failed");
    Udp.flush();
    return;
      }

setSpeed = root["spd"];
cmd = root["cmd"];
mode = root["mode"];

/*
//Debug
Serial.print("setSpeed: ");
Serial.print(setSpeed);
Serial.print(" Cmd: ");
Serial.print(cmd);
Serial.print(" Mode: ");
Serial.println(mode);
*/

Udp.flush();
yield();

}
