#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 3

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);
int resT = 12;
//////////////////////////////////////////////////////////////////////////
// Change This to the address specific to your sensor
DeviceAddress dallas01={0x28, 0x4B, 0x4A, 0x74, 0x06, 0x00, 0x00, 0xB0};
//////////////////////////////////////////////////////////////////////////

unsigned long time;


void setup() {
  Serial.begin(9600);
  sensors.begin();
  sensors.setResolution(dallas01, resT);
}

void loop() {
  sensors.requestTemperatures();
  delay(3000);
  printTemperature(dallas01); Serial.println("\t");
}

void printTemperature(DeviceAddress deviceAddress) {
  float tempC = sensors.getTempC(deviceAddress);
  Serial.print(tempC,2);
}
