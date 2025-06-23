#include <WiFi.h>
#include <WebServer.h>

// WiFi credentials
const char* ssid = "ARJUNA_BHAVAN";
const char* password = "Arjunabhavan#";

// Number of parking slots
const int NUM_SLOTS = 10;

// IR sensor pins (adjust to match your wiring)
const int irPins[NUM_SLOTS] = {2, 4, 5, 12, 13, 14, 15, 16, 17, 18};

// Parking slot status
String slotStatus[NUM_SLOTS];

WebServer server(80);

void setup() {
  Serial.begin(115200);

  // Configure IR pins with internal pull-up to avoid floating state
  for (int i = 0; i < NUM_SLOTS; i++) {
    pinMode(irPins[i], INPUT_PULLUP); // assumes IR gives LOW when occupied
  }

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");
  Serial.println("IP address: " + WiFi.localIP().toString());

  // Define web route
  server.on("/", handleRoot);
  server.begin();
  Serial.println("Web server started");
}

void loop() {
  updateSlotStatus();
  server.handleClient();
}

void updateSlotStatus() {
  for (int i = 0; i < NUM_SLOTS; i++) {
    int sensorValue = digitalRead(irPins[i]);
    slotStatus[i] = (sensorValue == LOW) ? "Occupied" : "Free";
  }
}

void handleRoot() {
  String html = "<!DOCTYPE html><html><head><meta charset='UTF-8'>";
  html += "<meta http-equiv='refresh' content='5'>"; // Auto-refresh every 5 seconds
  html += "<title>Parking Slot Monitor</title>";
  html += "<style>body{font-family:sans-serif;background:#f4f4f4;text-align:center;}";
  html += ".slot{margin:10px;padding:15px;border-radius:8px;display:inline-block;width:120px;";
  html += "background:#fff;box-shadow:0 0 10px rgba(0,0,0,0.2);} .occupied{color:red;font-weight:bold;}";
  html += ".free{color:green;font-weight:bold;}</style></head><body>";
  html += "<h2>🚗 Parking Slot Monitor</h2>";

  for (int i = 0; i < NUM_SLOTS; i++) {
    html += "<div class='slot'>";
    html += "Slot " + String(i + 1) + "<br>";
    if (slotStatus[i] == "Occupied")
      html += "<span class='occupied'>" + slotStatus[i] + "</span>";
    else
      html += "<span class='free'>" + slotStatus[i] + "</span>";
    html += "</div>";
  }

  html += "<p>Last updated: " + String(millis() / 1000) + " sec</p>";
  html += "</body></html>";

  server.send(200, "text/html", html);
}
