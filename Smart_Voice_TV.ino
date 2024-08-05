#include <IRremote.h>

const int IRsend = 11;
const int LED = 13;
unsigned int receivedValue = 0;

void setup() {
  // Debug console
  Serial.begin(9600);
  IrSender.begin(IRsend);
  pinMode(LED, OUTPUT);
}

void loop() {

  if (Serial.available()) {
    // Read the incoming bytes
    byte highByte = Serial.read();
    byte lowByte = Serial.read();

    // Combine the two bytes into a single 16-bit value
    receivedValue = (highByte << 8) | lowByte;

    // Print the received value in HEX format
    Serial.print("Received HEX value: 0x");
    Serial.println(receivedValue, HEX);
  }
  
  //DD Bangla (CH 908)
  if (receivedValue == 0xCC01){
    IrSender.sendNEC(0xC00009, 32);
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    IrSender.sendNEC(0xC00000, 32);
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    IrSender.sendNEC(0xC00008, 32);
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
  }
  
  //Star Sports 1 (CH 454)
  if (receivedValue == 0xCC02){
    IrSender.sendNEC(0xC00004, 32);
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    IrSender.sendNEC(0xC00005, 32);
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    IrSender.sendNEC(0xC00004, 32);
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
  }
  
  //Star Sports 2 (CH 456)
  if (receivedValue == 0xCC03){
    IrSender.sendNEC(0xC00004, 32);
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    IrSender.sendNEC(0xC00005, 32);
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    IrSender.sendNEC(0xC00006, 32);
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
  }

  //Sony Live (CH 473)
  if (receivedValue == 0xCC04){
    IrSender.sendNEC(0xC00004, 32);
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    IrSender.sendNEC(0xC00007, 32);
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    IrSender.sendNEC(0xC00003, 32);
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
  }

  //Power On or Off
  if (receivedValue == 0xAA01 || receivedValue == 0xAA00){
    IrSender.sendNEC(0xFE50AF, 32);
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
  }

  //Mute or Unmute
  if (receivedValue == 0xAB01 || receivedValue == 0xAB00){
    IrSender.sendNEC(0xFED02F, 32);
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
  }

  //Previous Channel
  if (receivedValue == 0xAC01){
    IrSender.sendNEC(0xC00083, 32);
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
  }
  else
  delay(10);
  receivedValue = 0;
}