#include <SoftwareSerial.h>
SoftwareSerial ESPserial(9, 10); // RX | TX

void setup()

{

Serial.begin(9600); // communication with the host computer

// Start the software serial for communication with the ESP8266
ESPserial.begin(115200);
delay(1000);
Serial.println("");
Serial.println("Remember to to set Both NL & CR in the serial monitor.");
Serial.println("Ready");
Serial.println("");
trimiteDate("AT+IPR=115200",1000);
trimiteDate("AT",1000);
trimiteDate("AT+RST",1000);
trimiteDate("AT+CWMODE=1",1000);
trimiteDate("AT+CWLAP",1000);
trimiteDate("AT+CWJAP=\"DIGI_d61430\",\"ddcc29eb\"",1000);
trimiteDate("AT+CIFSR",1000);

trimiteDate("AT+CIPMUX=1",1000);
trimiteDate("AT+CIPSERVER=1,80",1000);
scrie("Sir de caractere",1000);


}

void loop()

{
// listen for communication from the ESP8266 and then write it to the serial monitor
if ( ESPserial.available() ) { Serial.write( ESPserial.read() ); }
// listen for user input and send it to the ESP8266
if ( Serial.available() ) { ESPserial.write( Serial.read() ); }
}


void trimiteDate(String comanda, const int timp ){
    ESPserial.println(comanda);

while ( ESPserial.available() ) { Serial.write( ESPserial.read() ); } 
while ( Serial.available() ) { ESPserial.write( Serial.read() );}
  delay(timp);
  } 


 void scrie(String sir, const int timp){
      int lungimeSir = sir.length();
      String startTransmisie = "AT+CIPSEND=1,";
      String stopTransmisie = "AT+CIPCLOSE=0";
      String sirDate = startTransmisie + lungimeSir;
      trimiteDate(sirDate,1000);

      ESPserial.println(sir);

      trimiteDate(stopTransmisie,1000);
      delay(timp);
  
  
  }
