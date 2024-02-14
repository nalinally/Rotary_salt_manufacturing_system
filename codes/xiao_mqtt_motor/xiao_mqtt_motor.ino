//https://www.shiftr.io/try?lang=arduino

#define motor_pin1 A2
#define motor_pin2 A3
#define led_connecting D10

#include <WiFi.h>
#include <MQTT.h>

//const char ssid[] = "Shoryu";
//const char pass[] = "ic191209";
const char* ssid = "W03_E0A3AC70C626";
const char* pass = "fgfhg36ynh3mf5m";

float speed = 0;

WiFiClient net;
MQTTClient client;

unsigned long lastMillis = 0;

String topic_val, payload_val;

void connect() {
  Serial.print("checking wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.print("\nconnecting...");
  while (!client.connect("arduino", "public", "public")) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nconnected!");

  client.subscribe("hello");
}

void messageReceived(String &topic, String &payload) {
  topic_val = topic;
  payload_val = payload;
  Serial.println(topic + ": " + payload);
}

void setup() {
  digitalWrite(led_connecting, LOW);
  Serial.begin(115200);

  // start wifi and mqtt
  WiFi.begin(ssid, pass);
  client.begin("public.cloud.shiftr.io", net);
  //client.begin("mqtt://public:public@public.cloud.shiftr.io", net);
  client.onMessage(messageReceived);

  connect();
  digitalWrite(led_connecting, HIGH);
}

void loop() {
  client.loop();
  delay(10);

  // check if connected
  if (!client.connected()) {
    connect();
  }

  // publish a message roughly every second.
  if (millis() - lastMillis > 1000) {
    lastMillis = millis();
    client.publish("/hello", "world");
  }

  if(payload_val != "world"){
    speed = (float)atoi(payload_val.c_str()) * 0.001;
    if(speed >= 0){
      analogWrite(motor_pin1, 255);
      analogWrite(motor_pin2, 255-(int)(255.0*speed));
    }
    if(speed < 0){
      analogWrite(motor_pin1, 255+(int)(255.0*speed));
      analogWrite(motor_pin2, 255);
    }
  }

  if(payload_val == "cw"){
    analogWrite(motor_pin1, 255);
    analogWrite(motor_pin2, 128);
  }

  if(payload_val == "ccw"){
    analogWrite(motor_pin1, 128);
    analogWrite(motor_pin2, 255);
  }

  if(payload_val == "stop"){
    analogWrite(motor_pin1, 255);
    analogWrite(motor_pin2, 255);
  }

}