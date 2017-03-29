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
