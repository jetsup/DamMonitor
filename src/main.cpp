#include <Arduino.h>
#include <WiFi.h>
#include "credentials.hpp"
#include <ArduinoJson.h>
#include "config.hpp"
#include "mserver.hpp"

MServer server(SERVER_URL);

void setup()
{
  if (DEBUG)
  {
    Serial.begin(115200);
  }
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  DEBUG_PRINT("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED)
  {
    DEBUG_PRINT(".");
    delay(100);
  }
  DEBUG_PRINTLN("");
  DEBUG_PRINTLN("Connected to the WiFi network");
  DEBUG_PRINT("IP Address: ");
  DEBUG_PRINTLN(WiFi.localIP());
}

void loop()
{
  float depth = random(0, 100) / 10.0; // TODO: Replace this with the actual depth sensor reading

  if (millis() - server.getLastDataLogTime() > SERVER_SEND_INTERVAL)
  {
    JsonDocument doc;
    doc["depth"] = depth;
    String data;
    serializeJson(doc, data);
    DEBUG_PRINT("Data: ");
    DEBUG_PRINTLN(data);

    server.sendData(data);
    DEBUG_PRINT("Last data log time: ");
    DEBUG_PRINTLN(server.getLastDataLogTime());
  }
}
