#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <SoftwareSerial.h>
#include <ArduinoJson.h>

SoftwareSerial nodemcu(D6, D5);

const char* ssid     = "*******";
const char* password = "*****";


const char* serverName = "http://diywateringstation.000webhostapp.com/post-esp-data.php";

String apiKeyValue = "tPmAT5Ab3j7F9";

String deviceId = "vDBFD3F1D4C8E9FB";
const char* logServer = "api.pushingbox.com";
bool notif_sent = false;

void setup() {
  Serial.begin(9600);
  nodemcu.begin(9600);
  while (!Serial) continue;
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

void sendNotification(String message){

  Serial.println("- connecting to Home Router SID: " + String(ssid));
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println();
  Serial.println("- succesfully connected");
  Serial.println("- starting client");
  
  WiFiClient client;

  Serial.println("- connecting to pushing server: " + String(logServer));
  if (client.connect(logServer, 80)) {
    Serial.println("- succesfully connected");
    
    String postStr = "devid=";
    postStr += String(deviceId);
    postStr += "&message_parameter=";
    postStr += String(message);
    postStr += "\r\n\r\n";
    
    Serial.println("- sending data...");
    
    client.print("POST /pushingbox HTTP/1.1\n");
    client.print("Host: api.pushingbox.com\n");
    client.print("Connection: close\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(postStr.length());
    client.print("\n\n");
    client.print(postStr);
  }
  client.stop();
  Serial.println("- stopping the client");
}


void loop() {
  
  StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& data = jsonBuffer.parseObject(nodemcu);

  if (data == JsonObject::invalid()) {
    //Serial.println("Invalid Json Object");
    jsonBuffer.clear();
    return;
  }

  Serial.println("JSON Object Recieved");
  Serial.print("Recieved distance:  ");
  int distance = data["distance"];
  Serial.println(distance);
  Serial.print("Recieved moisture:  ");
  int moisture = data["moisture"];
  Serial.println(moisture);
  Serial.print("Recieved humidity:  ");
  float humidity = data["humidity"];
  Serial.println(humidity);
  Serial.print("Recieved temperature:  ");
  float temperature = data["temperature"];
  Serial.println(temperature);
  Serial.println("-----------------------------------------");

  if (distance > 11 and notif_sent == false){
    sendNotification("Kifogyott a viz");
    notif_sent = true;
  }
  if (distance <11) {
    notif_sent =false;
  }

  if(WiFi.status()== WL_CONNECTED){
    WiFiClient client;
    HTTPClient http;
    
    http.begin(client, serverName);
    
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    
    String httpRequestData = "api_key=" + apiKeyValue + "&distance=" + String(distance)
                          + "&moisture=" + String(moisture) + "&humidity=" + String(humidity) + "&temperature=" + String(temperature) + "";
    Serial.print("httpRequestData: ");
    Serial.println(httpRequestData);

    int httpResponseCode = http.POST(httpRequestData);
       
    if (httpResponseCode>0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  }
  else {
    Serial.println("WiFi Disconnected");
  }
  delay(30000);
}
