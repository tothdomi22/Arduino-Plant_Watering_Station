#include <SoftwareSerial.h>
#include <ArduinoJson.h>
#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
SoftwareSerial nodemcu(5, 6);


int sensorval;
int moisture;
const int relepin = A5;
const int szaraz = 810;
const int nedves = 355;
int trigpin = 8;
int echopin = 9;
int duration;
bool kifogyott;
int distance;

void setup() {
  Serial.begin(9600);
  pinMode (relepin, OUTPUT);
  pinMode (trigpin, OUTPUT);
  pinMode (echopin, INPUT);
  digitalWrite (relepin, HIGH);
  nodemcu.begin(9600);
  dht.begin();
  delay(1000);

  Serial.println("Program started");
}

int tavolsag(){
  int xd;
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  duration = pulseIn (echopin, HIGH);
  xd = duration * 0.034 / 2;
  return xd;
}

void loop() {
  
  StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& data = jsonBuffer.createObject();

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(false);
  sensorval = analogRead(A0);
  moisture = map(sensorval, nedves, szaraz, 100, 0);
  distance = tavolsag();
  if (distance < 20){
    kifogyott = true;
  }
  else {
    kifogyott = false;
  }
  Serial.println(sensorval);
  Serial.println(moisture);
  Serial.println(distance);
  Serial.print("hum: ");
  Serial.println(humidity);
  Serial.print("temp: ");
  Serial.println(temperature);
  
  if (moisture <85 and kifogyott == false){
    digitalWrite (relepin, LOW);
    delay (3000);
    digitalWrite (relepin, HIGH);
  }
  
  //Assign collected data to JSON Object
  data["distance"] = distance;
  data["moisture"] = moisture;
  data["humidity"] = humidity;
  data["temperature"] = temperature;

  //Send data to NodeMCU
  data.printTo(nodemcu);
  jsonBuffer.clear();
  delay(2000);
}
