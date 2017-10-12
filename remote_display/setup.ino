void setup() {
  
  Serial.begin(9600);
  //setup_wifi();
  WiFiManager wifiManager;
  wifiManager.autoConnect();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  display.init();

 // display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
  
}
