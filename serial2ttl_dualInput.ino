/*
 Receives from the main serial port, and serial port #1.
 Outputs TTLs based on contents of serial command. 
 LEDs indicate when TTLs are activated.
 
 Two serial input strings. 
   'a' activates ttl 1 (led and bnc output)
   'b' activates ttl 2 (led and bnc output) 

 TTL1 and TTL2 activate and led and bnc output. The led is for feedback, 
 the bnc is to connect to other hardware.
  
 This example works only on the Arduino Mega. 
 Multiple hardware ux/tx ports required.
 
 The circuit: 
 * Serial device attached to Serial port 1
 * Serial device attached to Serial port 0
 
 * led on 22, 28
 * bnc connector to 24, 30

 */

// globals
  int ttl1_led = 22;
  int ttl1_bnc = 24;
  
  int ttl2_led = 28;
  int ttl2_bnc = 30;
  
  
void setup() {
  // initialize both serial ports:
  Serial.begin(20000);
  Serial1.begin(20000);
  
  pinMode(ttl1_led, OUTPUT);
  pinMode(ttl1_bnc, OUTPUT);
  
  pinMode(ttl2_led, OUTPUT);
  pinMode(ttl2_bnc, OUTPUT);
  
  Serial.println("done setup");
}

void loop() {

  int inByte_0 = checkSerial(Serial);
  int inByte_1 = checkSerial(Serial1);
  
  doSwitch(inByte_0);
  doSwitch(inByte_1);

}


int checkSerial(HardwareSerial &serialId){
  int inByte = 0;
  
  if (serialId.available()) {
    inByte = serialId.read();
  }
  
  return inByte;
}


void doSwitch(int dat){
    
  if (dat){
  Serial.println("got " + String(dat) + " ");
  }
  
    switch (dat) {
      case 'a':    //'a'
        doTtl(ttl1_led,ttl1_bnc);
        Serial.write("doing a\n");
        break;
      case 'b':    //'b'
        doTtl(ttl2_led,ttl2_bnc);
        Serial.write("doing b\n");
        break;
    } 
}


void doTtl(int ledId, int bncId){
    digitalWrite(ledId, HIGH);
    digitalWrite(bncId, HIGH);
    delay(10); 
    digitalWrite(ledId, LOW);
    digitalWrite(bncId, LOW);
}

