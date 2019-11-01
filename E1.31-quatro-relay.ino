// Wemos D1 Mini E1.31 - 6 channel dumb RGB led sketch.

#include <ESP8266WiFi.h>
#include <E131.h> // Copyright (c) 2015 Shelby Merrick http://www.forkineye.com

// ***** USER SETUP STUFF *****
const char ssid[] = "You Wifi";  // replace with your SSID.
const char passphrase[] = "Pass"; // replace with your PASSWORD.
const int universe = 15; // this sets the universe number you are using.

// this sets the channel number used by the output.
const int channel_1 = 1; // the channel number to link to output 1 red.
const int channel_2 = 2; // the channel number to link to output 2 red.
const int channel_3 = 3; // the channel number to link to output 3 red.
const int channel_4 = 4; // the channel number to link to output 4 red.

// this sets the pin numbers to use as outputs.
const int output_1 = D1; // the pin to use as output 1 red (D1 = GPIO5  = SCL).
const int output_2 = D2; // the pin to use as output 1 red (D2 = GPIO4  = SDA).
const int output_3 = D5; // the pin to use as output 1 red (D5 = GPIO14 = SCLK).
const int output_4 = D6; // the pin to use as output 1 red (D6 = GPIO12 = MISO).


E131 e131;

void setup() {
  Serial.begin(115200);

  // set the pins chosen above as outputs.
  pinMode(output_1, OUTPUT);
  pinMode(output_2, OUTPUT);
  pinMode(output_3, OUTPUT);
  pinMode(output_4, OUTPUT);

  // set the pins chosen above to low / off.
  digitalWrite(output_1, LOW);
  digitalWrite(output_2, LOW);
  digitalWrite(output_3, LOW);
  digitalWrite(output_4, LOW);

  /* Choose one to begin listening for E1.31 data */
 e131.begin(ssid, passphrase);               /* via Unicast on the default port */
//   e131.beginMulticast(ssid, passphrase, universe); /* via Multicast for Universe 1 */
}

void loop() {
  /* Parse a packet */
  uint16_t num_channels = e131.parsePacket();

  /* Process channel data if we have it */
  if (num_channels) {
    Serial.println("we have data");
    /*print overige kanalen */
    Serial.print("channel_1 : ");
    Serial.println(e131.data[channel_1]);
    Serial.print("channel_2 : ");
    Serial.println(e131.data[channel_2]);
    Serial.print("channel_3 : ");
    Serial.println(e131.data[channel_3]);
    Serial.print("channel_4 : ");
    Serial.println(e131.data[channel_4]);

/*channel_1*/
if (e131.data[channel_1] >= 200) //if channel value is greater then 127
      {
       digitalWrite(output_1, HIGH); //turn relay on
            } 
      else
      {
       digitalWrite(output_1, LOW); //else turn it off 
  }
  /*channel_2 JK*/
  if (e131.data[channel_2] >= 200) //if channel value is greater then 127
      {
       digitalWrite(output_2, HIGH); //turn relay on
            } 
      else
      {
       digitalWrite(output_2, LOW); //else turn it off 
  }
  /*channel_3 JK*/
  if (e131.data[channel_3] >= 200) //if channel value is greater then 127
      {
       digitalWrite(output_3, HIGH); //turn relay on
            } 
      else
      {
       digitalWrite(output_3, LOW); //else turn it off 
  }
  /*channel_4 JK*/
  if (e131.data[channel_4] >= 200) //if channel value is greater then 127
      {
       digitalWrite(output_4, HIGH); //turn relay on
            } 
      else
      {
       digitalWrite(output_4, LOW); //else turn it off 
  } 
 }
}
 
