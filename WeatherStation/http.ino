void postDataToSparkFun()
{
  // Post Hive Data
  Serial.print("Posting Data");

    if (client.connect(server, 1880))
    {
      Serial.println(F("Connected"));

      // Post the data! Request should look a little something like:
      // GET /input/publicKey?private_key=privateKey&light=1024&switch=0&time=5201 HTTP/1.1\n
      // Host: data.sparkfun.com\n
      // Connection: close\n
      // \n
      client.print("GET /weather-1");

      client.print("?");
      client.print("temp");
      client.print("=");
      client.print(temp1);

      client.print("&");
      client.print("hum");
      client.print("=");
      client.print(hum);

      client.print("&");
      client.print("pres");
      client.print("=");
      client.print(pressure);

      client.println(" HTTP/1.1");
      client.print("Host: ");
      client.println(server);
      client.println("Connection: close");
      client.println();

      //  While we're connected, print out anything the server sends:
    //  while (client.connected())
    //  {
    //    if (client.available())
    //    {
    //      char c = client.read();
    //      Serial.print(c);
    //    }
    //  }
      Serial.println();
    }
    else // If the connection failed, print a message:
    {
      Serial.println(F("Connection failed"));
    }

    // If we're disconnected, stop the client:
    if (!client.connected())
    {
      Serial.println(F("Disconnecting."));
      client.stop();

    }
    delay(1000);
}
