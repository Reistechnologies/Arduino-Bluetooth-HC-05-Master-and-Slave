// BLUETOOTH MODO ESCLAVO
// ROLE = 0 SLAVE
// MY OWN   ADDR:2013:5:312959
#include <SoftwareSerial.h>

const int buttonPin = 12;     // the number of the pushbutton pin
const int ledPin =  13;       // the number of the LED pin

// variables will change:
int buttonState = buttonState;         // variable for reading the pushbutton status
//prevent buttonState was not declared in this scope
int prev_data_state = 0;
//check if new state its diferent ** event listener manager **

//numero a enviar
int num_send = 0;

SoftwareSerial blue(2, 3 );
// blue is the instance for use that device
 
// TX , RX in blue ports - RX bluetooth port to pin X in arduino
// since 3 is the port 3 in arduino , we'll send data through this port

int pot=0;

void setup(){
  blue.begin(9600);
  blue.println("Conectado");
  

    // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);  
  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT); 
  
}
void loop(){

  SendMessageBlue();
}

 //********************************************************************
 //********************************************************************
 

/* this snippet send data when pushbutton change state
   param - 
   return - void
*/

void SendMessageBlue(){ 
  

 
   // READ PUSHBUTTON
   buttonState = digitalRead(buttonPin);
 
   if(prev_data_state == buttonState ){
     // is the same state ** means its the first time executing **
  
   }else{
     // means new value is available
       
         // delay for make real button press time
         delay(200);
         num_send+=1;
         blue.println( num_send );
 
   }
   
  
}
 //********************************************************************
 //********************************************************************
 

