#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <UrlEncode.h>
#include <DHT.h>
 
const char* ssid = "*****";
const char* password = "******";
 
// +international_country_code + phone number
// Portugal +351, example: +351912345678
String phoneNumber = "*******";
String apiKey = "******";
 
const long interval = 30 * 60 * 1000; // 30 menit dalam milidetik
unsigned long previousMillis = 0;
 
// Define DHT sensor related variables
#define DHTPIN D4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
 
// Define ultrasonic sensor related pins
#define TRIGGER_PIN D1
#define ECHO_PIN D2
 
void setup() {
  Serial.begin(115200);
 
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
 
  // Initialize the DHT sensor
  dht.begin();
 
  // Initialize the ultrasonic sensor pins
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}
 
void loop() {
  unsigned long currentMillis = millis();
 
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
 
    // Read temperature and humidity from DHT11
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();
 
    // Read distance from the ultrasonic sensor
    float distance = measureDistance();
 
    // Create a message with sensor data
    String message = "Temperature: " + String(temperature) + "°C\n";
    message += "Humidity: " + String(humidity) + "%\n";
    message += "Distance: " + String(distance) + " cm";
 
    // Send the message to WhatsApp
    sendMessage(message);
  }
}
 
float measureDistance() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
 
  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = (duration / 2.0) * 0.0344; // Speed of sound in air at 20°C in cm/ms
 
  return distance;
}
 
void sendMessage(String message) {
  // Data to send with HTTP POST
  String url = "http://api.callmebot.com/whatsapp.php?phone=" + phoneNumber + "&apikey=" + apiKey + "&text=" + urlEncode(message);
  WiFiClient client;    
  HTTPClient http;
  http.begin(client, url);
 
  // Specify content-type header
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
 
  // Send HTTP POST request
  int httpResponseCode = http.POST(url);
  if (httpResponseCode == 200) {
    Serial.print("Message sent successfully");
  }
  else {
    Serial.println("Error sending the message");
    Serial.print("HTTP response code: ");
    Serial.println(httpResponseCode);
  }
 
  // Free resources
  http.end();
}
