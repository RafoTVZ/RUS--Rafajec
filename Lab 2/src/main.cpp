#include <Arduino.h>
#include "esp_sleep.h"

#define LED_PIN 2

#define WAKEUP_TIME_SECONDS 10
#define WAKEUP_TIME_US (WAKEUP_TIME_SECONDS * 1000000ULL)

#define MAX_MEASUREMENTS 10

RTC_DATA_ATTR int bootCounter = 0;
RTC_DATA_ATTR int measurementIndex = 0;

struct Measurement {
  float temperature;
  float humidity;
  uint32_t wakeCounter;
};

RTC_DATA_ATTR Measurement measurements[MAX_MEASUREMENTS];

void printWakeupReason() {
  esp_sleep_wakeup_cause_t reason = esp_sleep_get_wakeup_cause();

  if (reason == ESP_SLEEP_WAKEUP_TIMER) {
    Serial.println("Buđenje: TIMER (Light Sleep)");
  } else {
    Serial.println("Prvo pokretanje / reset");
  }
}

float simulateTemperature() {
  return 22.0 + (bootCounter % 6) * 0.7;
}

float simulateHumidity() {
  return 45.0 + (bootCounter % 8) * 1.5;
}

void activePhase() {

  Serial.println("Aktivna faza rada...");

  float t = simulateTemperature();
  float h = simulateHumidity();

  measurements[measurementIndex].temperature = t;
  measurements[measurementIndex].humidity = h;
  measurements[measurementIndex].wakeCounter = bootCounter;

  Serial.print("Mjerenje ");
  Serial.print(measurementIndex + 1);
  Serial.print(": T=");
  Serial.print(t);
  Serial.print("C H=");
  Serial.print(h);
  Serial.println("%");

  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);

  measurementIndex++;
}

void printMeasurements() {

  Serial.println("\n===== 10 MJERENJA =====");

  for (int i = 0; i < MAX_MEASUREMENTS; i++) {
    Serial.print(i + 1);
    Serial.print(". wake #");
    Serial.print(measurements[i].wakeCounter);
    Serial.print(" T=");
    Serial.print(measurements[i].temperature);
    Serial.print(" H=");
    Serial.println(measurements[i].humidity);
  }

  Serial.println("=======================\n");

  measurementIndex = 0;
}

void enterLightSleep() {

  Serial.println("Ulazak u LIGHT SLEEP...");
  Serial.flush();

  delay(200);

  esp_sleep_enable_timer_wakeup(WAKEUP_TIME_US);
  esp_light_sleep_start();

  Serial.println("Buđenje iz LIGHT SLEEP-a");
}

void setup() {

  Serial.begin(115200);
  delay(500);

  pinMode(LED_PIN, OUTPUT);

  Serial.println("\nESP32 Datalogger");
}

void loop() {

  bootCounter++;

  Serial.println("\n--------------------------------");
  Serial.print("Ciklus #: ");
  Serial.println(bootCounter);

  printWakeupReason();

  activePhase();

  if (measurementIndex >= MAX_MEASUREMENTS) {
    printMeasurements();
  }

  enterLightSleep();
}