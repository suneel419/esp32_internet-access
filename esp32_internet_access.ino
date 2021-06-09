#include <WiFi.h>
#include <ESP32Ping.h>

const char* ssid     = "sunil";
const char* password = "8790225440";

const char* remote_host = "www.google.com";
void wifi_connect()
{
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }

}
void setup() {
  Serial.begin(115200);
  delay(10);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println("Connecting to WiFi");
  
  wifi_connect();
  
  Serial.println();
  Serial.print("WiFi connected with ip ");  
  Serial.println(WiFi.localIP());

  Serial.print("Pinging host ");
  Serial.println(remote_host);

  if(Ping.ping(remote_host)) {
    Serial.println("Success!!");
  } else {
    Serial.println("Error :(");
  }
}

void loop()
{

if (WiFi.status() == WL_CONNECTED)
  {
    if(Ping.ping(remote_host)) {
    Serial.println("Internet access");
    }
    else
    {
    Serial.println("WiFi connected but No Internet access From the source");
    //wifi_connect();
  }
  }

  else
  {
    Serial.println("WiFi Disconnected");
    wifi_connect();
  }  
}
