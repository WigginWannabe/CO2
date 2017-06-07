/*
  Basic Arduino example for K-Series sensor
  Created by Jason Berger
  Co2meter.com  
*/

#include "K30.h"

//SoftwareSerial K_30_Serial(12,13);  //Sets up a virtual serial port
//                                    //Using pin 12 for Rx and pin 13 for Tx

//byte readCO2[] = {0xFE, 0X44, 0X00, 0X08, 0X02, 0X9F, 0X25};  //Command packet to read Co2 (see app note)
//byte response[] = {0,0,0,0,0,0,0};  //create an array to store the response

void K30::initialize() {
  // put your setup code here, to run once:
  Serial.begin(9600);         //Opens the main serial port to communicate with the computer
  K_30_Serial.begin(9600);    //Opens the virtual serial port with a baud of 9600
}
//
//void loop() 
//{
////  sendRequest();
////  unsigned long valCO2 = getValue(response);
////  Serial.print("Co2 ppm = ");
////  Serial.println(valCO2);
////  delay(2000);
//}

void K30::sendRequest()
{
  byte numTries = 0;
  while(!K_30_Serial.available())  //keep sending request until we start to get a response
  {
    if (numTries > 10) {
      Serial.println("k30 not available");
      return;
    }
    K_30_Serial.write(commandPacket,7);
    numTries++;
    delay(50);
  }
  
  int timeout=0;  //set a timeoute counter
  while(K_30_Serial.available() < 7 ) //Wait to get a 7 byte response
  {
    timeout++;  
    if(timeout > 10)    //if it takes too long there was probably an error
      {
        while(K_30_Serial.available())  //flush whatever we have
          K_30_Serial.read();
          
          break;                        //exit and try again
      }
      delay(50);
  }
  
  for (int i=0; i < 7; i++)
  {
    response[i] = K_30_Serial.read();
  }  
}

int K30::getValue()
{
    int high = response[3];                        // high byte for value is 4th byte in packet in the packet
    int low = response[4];                         // low byte for value is 5th byte in the packet

    unsigned long val = high*256 + low;                //Combine high byte and low byte with this formula to get value
    return val* valMultiplier;
}

