#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(8, 9); // CE, CSN
const byte address[6] = "rccar";
int xyData[2];
int xAxis, yAxis;
void setup() {
 Serial.begin(9600);
 radio.begin();
 radio.openWritingPipe(address);
 radio.setPALevel(RF24_PA_MIN);
 radio.stopListening();
}
void loop() {
 Serial.println(xyData[0]);
 Serial.println(xyData[1]);
 xyData[0] = analogRead(A3);
 xyData[1] = analogRead(A1);
 radio.write(&xyData, sizeof(xyData));

 delay(20);
}