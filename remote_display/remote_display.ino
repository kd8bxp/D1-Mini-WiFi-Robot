//v1.0.0

#include <ESP8266WiFi.h>
#include "src/PubSubClient/PubSubClient.h"
#include "src/esp8266_ssd1306/SSD1306.h"
#include "src/ArduinoJson/ArduinoJson.h"
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include "src/WiFiManager/WiFiManager.h"         //https://github.com/tzapu/WiFiManager

const char* ssid = "";
const char* password = "";
//const char* mqtt_server = "broker.mqtt-dashboard.com";
const char* mqtt_server = "test.mosquitto.org";

volatile int m1dir = 0;
volatile int m2dir = 0;
long m1steps, m2steps;
long distanceIN = 0;
String RobotID = "";

SSD1306 display(0x3c, D1,D2);//4,5 SDA D2, SCL D1

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;
 
    uint32_t chipid=ESP.getChipId(); 
    char clientid[16];
    char subclientid[16];


String IPremote;
String subclientidTemp;
