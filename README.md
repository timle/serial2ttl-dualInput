serial2ttl-dualInput
====================

Arduino code to convert serial rx/tx to ttl.

Arduino Mega

Receives from the main serial port (#0), and serial port #1.
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
