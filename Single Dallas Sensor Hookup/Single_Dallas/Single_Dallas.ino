#include <OneWire.h>
#include <DallasTemperature.h>

//This Is The Arduino Pin that we are feeding the Data into
#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);
int resT = 12;

//Individual Device Address
DeviceAddress dallas01={0x28, 0x2F, 0x1D, 0x62, 0x04, 0x00, 0x00, 0x15};

//Create a time Variable
unsigned long time;

void setup(void) {
  // put your setup code here, to run once:
  Serial.begin(9600);
  sensors.begin();
  sensors.setResolution(dallas01, resT);
}

void loop(void) {
  // put your main code here, to run repeatedly:
  sensors.requestTemperatures();
  delay(3000);
  printTemperature(dallas01); Serial.println("\t");
}

void printTemperature(DeviceAddress deviceAddress) {
  float tempC = sensors.getTempC(deviceAddress);
  Serial.print(tempC,2);
}
