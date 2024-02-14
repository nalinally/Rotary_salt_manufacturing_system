#include <WiFi.h>
#include <Wire.h>
#include <OneWire.h>  //1wire
#include <DallasTemperature.h>  //DS18B20
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include "Ambient.h"
#define PERIOD 30  //30[sec]
#define SEALEVELPRESSURE_HPA (1013.25)

const uint32_t SERIAL_SPEED{115200}; 

Adafruit_BME280 bme;
WiFiClient client;
//OneWire&DS18B20
#define ONE_WIRE_BUS 9 //Portは任意。今回は2番
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

Ambient ambient;

unsigned long delayTime;
float temp;
float pressure;
float humid;
float temp01;

//const char* ssid = "tempk";
//const char* password = "D2aHr3Uc";
const char* ssid = "W03_E0A3AC70C626";
const char* password = "fgfhg36ynh3mf5m";
//const char* ssid = "Shoryu";
//const char* password = "ic191209";

//ゆうき
//unsigned int channelId = 73722; // AmbientのチャネルID(数字)
//const char* writeKey = "b3a77ab74cb1cb94"; // ライトキー
//なりと
unsigned int channelId = 72047; // AmbientのチャネルID(数字)
const char* writeKey = "9608e41ea31f0ef9"; // ライトキー

void setup() {
  Serial.begin(115200);
  bool status;
  status = bme.begin(0x77);  
  while (!status) {
    Serial.println("BME280 sensorが使えません");
    delay(1000);
  }
  delayTime = 1000;
  Serial.print("connecting");
  WiFi.begin(ssid, password);  //  Wi-Fi APに接続
    while (WiFi.status() != WL_CONNECTED) {  //  Wi-Fi AP接続待ち
        delay(100);
        Serial.print(".");
    }

  Serial.print("WiFi connected\r\nIP address: ");
  Serial.println(WiFi.localIP());
  ambient.begin(channelId, writeKey, &client); // チャネルIDとライトキーを指定してAmbientの初期化
  bme.begin(); //データの初期化
  sensors.begin();
}
void loop() { 
  temp=bme.readTemperature();
  pressure=bme.readPressure() / 100.0F;
  humid=bme.readHumidity();
  sensors.requestTemperatures();
  temp01 = sensors.getTempCByIndex(0);

  Serial.print("温度 :");
  Serial.print(temp);
  Serial.println(" °C");
   
  Serial.print("気圧 :");
  Serial.print(pressure);
  Serial.println(" hPa");

  Serial.print("湿度 :");
  Serial.print(humid);
  Serial.println(" %");

  Serial.print("水温 :");
  Serial.print(temp01);
  Serial.println(" °C");

  Serial.println();
  delay(delayTime);
  ambient.set(1, temp); // 温度をデータ1にセット
  ambient.set(2, humid); // 湿度をデータ2にセット
  ambient.set(3, pressure); // 気圧をデータ3にセット 
  ambient.set(5, temp01); 

  ambient.send(); // データをAmbientに送信

  delay(PERIOD * 1000);
}