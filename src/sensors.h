#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADS1015.h>
#include "uFire_SHT20.h"

//Sensors Pins
#define windDirPin  32
#define pluvPin     33
#define tempPin     36
#define anemoPin    35
#define adc1Add 0x48
#define adc2Add 0x49


//Constants
//ADS1015
#define adsGain1 0.0000078125
#define adsGain2 0.0001875
//Anemo
#define pi 3.14159265
#define radius 147
//Temp
const double BCOEFFICIENT = 3950.0;
const double THERMISTORNOMINAL = 10000.0;
const double TEMPERATURENOMINAL = 25.0;

class Sensors
{
private:
  //Sensors objects
  uFire_SHT20 sht20;
  Adafruit_ADS1115 ads1;
  Adafruit_ADS1115 ads2;

  //Atributes
  int readTimes;
  float temp;
  float pressure;
  float humidity;
  float irradiance;
  float windSpeed;
  int* windDirection;
  float rain;
  float PVtemp;
  float voltage;
  float current;

  //Sensors variables
  static unsigned int anemCounter; // magnet counter for sensor
  static unsigned int pluvCounter; // magnet counter for sensor

  //Sensors aux variables
  int act_time;

  //Sensors aux functions
public:
  void init();
  void readAllData(float currGain, float voltGain);
  String getAvgData();

private:
  void readTemp();
  void readHumidity();
  void readIradiance();
  void readWindDirection();
  void readRain();
  void readPVtemp();
  void readVoltage(float gain);
  void readCurrent(float gain);
  String getTemp();
  String getHumidity();
  String getIradiance();
  String getWindSpeed();
  String getWindDirection();
  String getRain();
  String getPVtemp();
  String getVoltage();
  String getCurrent();

  //Sensors aux functions
public:
  void setAnemCounter0();
  void setPluvCounter0();
private:
  static void addAnemCounter();
  static void addPluvCounter();
};
