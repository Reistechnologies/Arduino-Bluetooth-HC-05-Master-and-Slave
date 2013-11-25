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

int BIT_0 = 7 ;  
int BIT_1 = 8 ;  
int BIT_2 = 9 ;  
int BIT_3 = 10 ; 
 
//valor acumulado para sumar

int storage_value = 0;


void setup(){
  
    // initialize the digital pin as an output.
  pinMode( BIT_0 , OUTPUT);  
  pinMode( BIT_1 , OUTPUT); 
  pinMode( BIT_2 , OUTPUT); 
  pinMode( BIT_3 , OUTPUT);   
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);  
  
  
  //bluetooth
  blue.begin(9600);
  
  Serial.begin(9600);
 
  Serial.println("Master waiting for receive data...");
 
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
            
            //Serial.println("*********************************************");  
            //Serial.print("Master Received: ");
   
            //storage_value = storage_value + inData.toInt();
            
            TurnBits(  inData.toInt() );
            
            //Serial.print( "La suma de todos los datos recibidos : ");
            //Serial.println(storage_value);
            //Serial.println("*********************************************");

            inData = ""; // Clear recieved buffer
            
             digitalWrite(13, HIGH);   // set the LED on
             delay(500);
             digitalWrite(13, LOW);    // set the LED off
                     
            
            }
            
            
          }
   
  
}





/*
this snippet convert a decimal number into a binary code and turn on the leds
*/

void TurnBits(int number){

  digitalWrite(BIT_0, LOW);   // set the LED on
  digitalWrite(BIT_1, LOW);    // set the LED off
  digitalWrite(BIT_2, LOW);   // set the LED on
  digitalWrite(BIT_3, LOW);    // set the LED off
  
   Serial.print(number);
            
 switch(number){
  
  case 0 :      break;
  
  case 1 :  digitalWrite(BIT_0, HIGH); 
            break;
            
  case 2 :  digitalWrite(BIT_1, HIGH); 
            break;
            
  case 3 :  digitalWrite(BIT_1, HIGH); 
            digitalWrite(BIT_0, HIGH); 
            break;
            
  case 4 :  digitalWrite(BIT_2, HIGH); 
            break;
            
  case 5 :  digitalWrite(BIT_2, HIGH); 
            digitalWrite(BIT_0, HIGH); 
            break;
            
  case 6 :  digitalWrite(BIT_1, HIGH);
            digitalWrite(BIT_2, HIGH); 
            break;
            
  case 7 :  digitalWrite(BIT_2, HIGH); 
            digitalWrite(BIT_0, HIGH);
            digitalWrite(BIT_1, HIGH);  
            break;
            
  case 8 :  digitalWrite(BIT_3, HIGH); 
            break;
            
  case 9 :  digitalWrite(BIT_3, HIGH);
             digitalWrite(BIT_0, HIGH);  
            break;
            
  case 10 :  digitalWrite(BIT_3, HIGH);
             digitalWrite(BIT_1, HIGH);  
            break;
            
  case 11 : digitalWrite(BIT_3, HIGH); 
            digitalWrite(BIT_1, HIGH); 
            digitalWrite(BIT_0, HIGH); 
            break;
            
  case 12 : digitalWrite(BIT_3, HIGH); 
            digitalWrite(BIT_2, HIGH); 
            break;
            
  case 13 :  digitalWrite(BIT_3, HIGH); 
            digitalWrite(BIT_2, HIGH); 
            digitalWrite(BIT_0, HIGH); 
            break;  
            
  case 14 :  digitalWrite(BIT_3, HIGH);
            digitalWrite(BIT_1, HIGH); 
            digitalWrite(BIT_2, HIGH); 
            break;  
            
  case 15 :  digitalWrite(BIT_0, HIGH); 
             digitalWrite(BIT_1, HIGH); 
             digitalWrite(BIT_2, HIGH);
            digitalWrite(BIT_3, HIGH);  
            break;
}
    
}

