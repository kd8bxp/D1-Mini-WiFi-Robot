//v3.0.1

#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
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

SSD1306 display(0x3c, 4,5);// SDA D2, SCL D1

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;
 
    uint32_t chipid=ESP.getChipId(); 
    char clientid[16];
    char subclientid[16];

unsigned int localPort = 8888;      // local port to listen on

// buffers for receiving and sending data
char packetBuffer[UDP_TX_PACKET_MAX_SIZE]; //buffer to hold incoming packet,
char  ReplyBuffer[] = "Count: ";       // a string to send back

WiFiUDP Udp;

int modeCounter = 2; //this is how many modes the robot has
//mode 0 - remote
//mode 1 - automous robot
//mode 2 - unknown

int mode = 0;

int speed = 100; //Currently there is no way to use the remote to set a speed. 

/*
 * 0 - STOP
 * 1 - UP
 * 2 - CENTER
 * 3 - LEFT
 * 4 - DOWN
 * 5 - RIGHT
 */

#define UP D3
#define CENTER D4
#define LEFT D0
#define DOWN D5
#define RIGHT D6

int SwitchIN = 0;

unsigned long udpTimer = 0;
unsigned long udpCurrentTimer = 0;
String IPremote;
String subclientidTemp;
