void initPressure(){
  Serial.println("Start pressure");
  if (!bmp.begin()) {
    Serial.println("Could not find a valid BMP085 sensor, check wiring!");
    while (1) {}
  }
}

void readPressure(){
  Serial.println("Start humidity");
  temp2 = bmp.readTemperature();
  pressure = bmp.readPressure();
  Serial.print("Temperature = ");
  Serial.print(temp2);
  Serial.println(" *C");
  Serial.print("Pressure = ");
  Serial.print(pressure);
  Serial.println(" Pa");
}

void readHumidity(){
  hum = SHT2x.GetHumidity();
  temp1 = SHT2x.GetTemperature();
  Serial.print("Humidity(%RH): ");
  Serial.print(hum);
  Serial.print("     Temperature(C): ");
  Serial.println(temp1);
  Serial.print("     Dewpoint(C): ");
  Serial.println(SHT2x.GetDewPoint());
}
