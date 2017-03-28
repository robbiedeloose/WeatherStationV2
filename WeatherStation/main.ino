#include <Sodaq_SHT2x.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <WiFi101.h>
#include <SPI.h>

// You will need to create an SFE_BMP180 object, here called "pressure":
Adafruit_BMP085 bmp;
#define ALTITUDE 0

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




void setup()
{
  delay(5000);
  Serial.begin(9600);
  delay(2000);
  Serial.println("REBOOT");
//  initPressure();

  //WiFi
  initiateWifi();

}

void loop()
{

readHumidity();
//readPressure();
  //readPressure();
  postDataToSparkFun();

  delay(300000);  // Pause for 5 seconds.
}
