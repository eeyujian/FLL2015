#include <dht.h>


//#include <LiquidCrystal.h>
//LiquidCrystal lcd(5,6,9,10,11,12);

dht DHT;

#define DHT11_PIN 5

void setup() 
{
  //lcd.begin(16,2);
  Serial.begin(9600);
}

void loop()
{
  //READ DATA
  Serial.print("DHT11, \t");
  //read the value returned from sensor
  int chk = DHT.read11(DHT11_PIN);
  switch (chk)
  {
    case DHTLIB_OK:
    Serial.print("OK,\t");
    break;
    case DHTLIB_ERROR_CHECKSUM:
    Serial.print("Checksum error,\t");
    break;
     case DHTLIB_ERROR_TIMEOUT: 
    Serial.print("Time out error,\t"); 
    break;
    case DHTLIB_ERROR_CONNECT:
    Serial.print("Connect error,\t");
    break;
    case DHTLIB_ERROR_ACK_L:
    Serial.print("Ack Low error,\t");
    break;
    case DHTLIB_ERROR_ACK_H:
    Serial.print("Ack High error,\t");
    break;
    default: 
    Serial.print("Unknown error,\t"); 
    break;
  }

Serial.print(DHT.humidity, 1);
Serial.print(",\t");
Serial.println(DHT.temperature, 1);

delay(2000);//wait a while
}


  


