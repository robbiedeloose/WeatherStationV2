

#include <SFE_BMP180.h>
#include <Sodaq_SHT2x.h>
#include <Wire.h>
#include <WiFi101.h>
#include <SPI.h>
#include <Adafruit_BMP085.h>

// You will need to create an SFE_BMP180 object, here called "pressure":
SFE_BMP180 pressure;

// Wifi
char ssid[] = "dd-wrt"; //  your network SSID (name)
char pass[] = "newyork20newyork15";    // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;            // your network key Index number (needed only for WEP)
WiFiClient client; // network client
char server[] = "beehives.dnsdynamic.com"; // Remote host site
// WiFi status
int status = WL_IDLE_STATUS;

// pressure
#define ALTITUDE 0



void setup()
{

  Wire.begin();
  delay(5000);
  Serial.begin(9600);
  delay(2000);
  Serial.println("REBOOT");
  initPressure();

}

void loop()
{

readHumidity();

  //readPressure();

  delay(5000);  // Pause for 5 seconds.
}
