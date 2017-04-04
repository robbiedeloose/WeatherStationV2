#include <Arduino.h>
#include <SPI.h>
#include <WiFi101.h>
#include <Wire.h>
#include <Sodaq_SHT2x.h>
#include <RTCZero.h> // RealTimeClock for sleep

// Wifi
char ssid[] = "dd-wrt"; //  your network SSID (name)
char pass[] = "newyork20newyork15";    // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;            // your network key Index number (needed only for WEP)
WiFiClient client; // network client
char server[] = "78.20.193.29"; // Remote host site
// WiFi status
int status = WL_IDLE_STATUS;

// weather data variables
float temp1 = 0;
float temp2 = 0;
float hum = 0;
int pressure = 0;
int lux = 0;
float rain = 0;
float wind = 0;

// Date and Time
byte seconds = 0;
byte minutes = 00;
byte hours = 17;
byte days = 17;
byte months = 11;
int years = 15;

// sleep & debug
boolean sleep = false;
int i = 0;

RTCZero rtc; // real time clock instance

void setup()
{
  Wire.begin();
  delay(2000);
  Serial.begin(9600);
  delay(2000);
  Serial.println("Setup -");
  Serial.println("15 seconds to allow reprogramming");
  delay(15000);

  Serial.println("----- Set Real Time Clock");
  setRtc();
  //WiFi
  initiateWifi();
  delay(2000);
  Serial.println("set wifi power mode");
  WiFi.lowPowerMode();
}

void loop()
{
  if (sleep == false) {
    Serial.println("Loop - readHumidity");
    readHumidity();
    Serial.println("Loop - post data");
    postDataToSparkFun();

    sleep = true;
    rtc.standbyMode();
  }
}
