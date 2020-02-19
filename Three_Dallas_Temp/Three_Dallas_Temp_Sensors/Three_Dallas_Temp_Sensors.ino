#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 3

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);
int resT = 12;
//////////////////////////////////////////////////////////////////////////
// Change This to the address specific to your sensor
DeviceAddress dallas01={0x28, 0x50, 0x1D, 0x50, 0x06, 0x00, 0x00, 0xA9};
DeviceAddress dallas02={0x28, 0x4B, 0x4A, 0x74, 0x06, 0x00, 0x00, 0xB0};
DeviceAddress dallas03={0x28, 0xBF, 0xC7, 0x53, 0x06, 0x00, 0x00, 0xCF};
//////////////////////////////////////////////////////////////////////////

unsigned long time;


void setup() {
  Serial.begin(9600);
  sensors.begin();
  sensors.setResolution(dallas01, resT);
  sensors.setResolution(dallas02, resT);
  sensors.setResolution(dallas03, resT);
}

void loop() {
  sensors.requestTemperatures();
  delay(3000);
  Serial.println("---------------------");
  Serial.print("Sensor 1: ");
  printTemperature(dallas01); Serial.println("\t");
  Serial.print("Sensor 2: ");
  printTemperature(dallas02); Serial.println("\t");
  Serial.print("Sensor 3: ");
  printTemperature(dallas03); Serial.println("\t");
}

void printTemperature(DeviceAddress deviceAddress) {
  float tempC = sensors.getTempC(deviceAddress);
  Serial.print(tempC,2);
}
