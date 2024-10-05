#include <ESP8266WiFi.h>
#include <WiFiClient.h>

String apiKey = ""; // Enter your Write API key from ThingSpeak
const char *ssid = "";     // Replace with your WiFi SSID
const char *pass = "";
const char* server = "api.thingspeak.com";

const int sensorPin = A0;           // Soil moisture analog sensor pin
const int sensorSelectPin1 = D1;    // Digital pin to select Sensor 1
const int sensorSelectPin2 = D2;    // Digital pin to select Sensor 2

WiFiClient client;

void setup() {
    Serial.begin(115200);

    Serial.println("Connecting to WiFi...");
    WiFi.begin(ssid, pass);
    
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    
    Serial.println("\nWiFi connected");
}

void loop() {
    int moisturePercentage1, moisturePercentage2;

    // Read Sensor 1
    digitalWrite(sensorSelectPin1, LOW); // Select Sensor 1
    delay(100); // Stabilization delay
    moisturePercentage1 = (100.00 - ((analogRead(sensorPin) / 1023.00) * 100.00));

    Serial.print("Soil Moisture Sensor 1 (in Percentage) = ");
    Serial.print(moisturePercentage1);
    Serial.println("%");

    // Read Sensor 2
    digitalWrite(sensorSelectPin2, HIGH); // Select Sensor 2
    delay(100); // Stabilization delay
    moisturePercentage2 = (100.00 - ((analogRead(sensorPin) / 1023.00) * 100.00));

    Serial.print("Soil Moisture Sensor 2 (in Percentage) = ");
    Serial.print(moisturePercentage2);
    Serial.println("%");

    // Send data to ThingSpeak
    if (client.connect(server, 80)) {
        String postStr = apiKey;
        postStr += "&field1=" + String(moisturePercentage1);
        postStr += "&field2=" + String(moisturePercentage2); // Add second sensor data
        postStr += "\r\n";
        
        client.print("POST /update HTTP/1.1\n");
        client.print("Host: api.thingspeak.com\n");
        client.print("Connection: close\n");
        client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
        client.print("Content-Type: application/x-www-form-urlencoded\n");
        client.print("Content-Length: ");
        client.print(postStr.length());
        client.print("\n\n");
        client.print(postStr);

        Serial.println("Data sent to ThingSpeak");
    }
    
    client.stop();
    Serial.println("Waiting...");

    delay(15000); // ThingSpeak requires a minimum of 15 seconds delay between updates
}
