// BLUETOOTH MODO MAESTRO
// ROLE = 1 MASTER
 
#include <SoftwareSerial.h>
 
SoftwareSerial blue(2, 3 );
// blue is the instance for use that device
 
// TX , RX in blue ports - RX bluetooth port to pin X in arduino
// since 3 is the port 3 in arduino , we'll send data through this port
 
// Buffer to store incoming commands from serial port
String inData;

//led a prender
const int ledPin =  13;       // the number of the LED pin

//valor acumulado para sumar

int storage_value = 0;


void setup(){
  
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);  
  
  
  //bluetooth
  blue.begin(9600);
  
  Serial.begin(9600);
 
  Serial.println("Master waiting for receive data...");
 
  //pinMode(ledPin, OUTPUT);      
 
  
}


void loop(){

  ReceiveMessageBlue();
}

 //********************************************************************
 //********************************************************************
 

/* this snippet receive data from bluetooth device
   param - 
   return - void
*/

void ReceiveMessageBlue(){ 
  
          while(blue.available()> 0) {
    
            
             char recieved = blue.read();
             inData += recieved; 

            // Process message when new line character is recieved
            if (recieved == '\n')
            {
            
              
            Serial.println("*********************************************");  
            Serial.print("Master Received: ");
            Serial.print(inData);
            
            storage_value = storage_value + inData.toInt();
            
            Serial.print( "La suma de todos los datos recibidos : ");
            Serial.println(storage_value);
            Serial.println("*********************************************");

            inData = ""; // Clear recieved buffer
            
             digitalWrite(13, HIGH);   // set the LED on
             delay(500);
             digitalWrite(13, LOW);    // set the LED off
                     
            
            }
            
            
          }
   
  
}


