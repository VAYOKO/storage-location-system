
#include <Keypad.h>

//Variables
int min_Ang = 0;                                   
int max_Ang = 135; 
int character = 0;
int activated =0;
char Pass_char[4] = {' ', ' ', ' ', ' '};       //จำนวนหลัก

int led1 = 13;
int led2 =11;

int led3 = 10;
int led4 =9;

int led5 = 1;
int led6 =0;
//Keypad config
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys [ROWS][COLS] = 
{{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};
 
//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup(){
 pinMode(led1,OUTPUT);
 pinMode(led2,OUTPUT); 
 pinMode(led3,OUTPUT);
 pinMode(led4,OUTPUT);
 pinMode(led5,OUTPUT);
 pinMode(led6,OUTPUT);
Serial.begin(9600);
  }
 
void loop(){
char customKey = customKeypad.getKey(); //this function reads the presed key
 
 if (customKey){
    if (character ==0)
  { 
  Pass_char[0]= customKey; 
 }

if (character ==1)
 { 
 Pass_char[1]= customKey; 
 }

if (character ==2)
 { 
 Pass_char[2]= customKey; 
 }

if (character ==3)
 { 
 Pass_char[3]= customKey; 
 activated=1;
 }
 character=character+1;
}

if (activated == 1)
 {
// you can change your password here (current passowrd is 1357)

if(character==4 && Pass_char[0]=='A' && Pass_char[1]=='4' && Pass_char[2]=='7' && Pass_char[3]=='0' )
 {
  
 digitalWrite(led1,HIGH);
 activated = 2;
 delay(1000);
 digitalWrite(led1,LOW);
 activated = 0;
 character=0;
 Pass_char[0]= ' ';
 Pass_char[1]= ' '; 
 Pass_char[2]= ' '; 
 Pass_char[3]= ' ';
 }
  
 if(character==4 && Pass_char[0]=='1' && Pass_char[1]=='7' && Pass_char[2]=='6' && Pass_char[3]=='7' )
 {
  
 digitalWrite(led2,HIGH);
 activated = 2;
 delay(1000);
 digitalWrite(led2,LOW);
 activated = 0;
 character=0;
 Pass_char[0]= ' ';
 Pass_char[1]= ' '; 
 Pass_char[2]= ' '; 
 Pass_char[3]= ' ';
 
 
 }else if(character==4 && Pass_char[0]=='B' && Pass_char[1]=='2' && Pass_char[2]=='9' && Pass_char[3]=='7' )
 {
  
 digitalWrite(led3,HIGH);
 activated = 2;
 delay(1000);
 digitalWrite(led3,LOW);
 activated = 0;
 character=0;
 Pass_char[0]= ' ';
 Pass_char[1]= ' '; 
 Pass_char[2]= ' '; 
 Pass_char[3]= ' ';
 
 
  }else if(character==4 && Pass_char[0]=='C' && Pass_char[1]=='4' && Pass_char[2]=='1' && Pass_char[3]=='8' )
 {
  
 digitalWrite(led4,HIGH);
 activated = 2;
 delay(1000);
 digitalWrite(led4,LOW);
 activated = 0;
 character=0;
 Pass_char[0]= ' ';
 Pass_char[1]= ' '; 
 Pass_char[2]= ' '; 
 Pass_char[3]= ' ';
 
 
 } else if(character==4 && Pass_char[0]=='D' && Pass_char[1]=='3' && Pass_char[2]=='4' && Pass_char[3]=='7' )
 {
  
 digitalWrite(led5,HIGH);
 activated = 2;
 delay(1000);
 digitalWrite(led5,LOW);
 activated = 0;
 character=0;
 Pass_char[0]= ' ';
 Pass_char[1]= ' '; 
 Pass_char[2]= ' '; 
 Pass_char[3]= ' ';
 

   } else if(character==4 && Pass_char[0]=='1' && Pass_char[1]=='A' && Pass_char[2]=='6' && Pass_char[3]=='7' )
 {
  
 digitalWrite(led6,HIGH);
 activated = 2;
 delay(1000);
 digitalWrite(led6,LOW);
 activated = 0;
 character=0;
 Pass_char[0]= ' ';
 Pass_char[1]= ' '; 
 Pass_char[2]= ' '; 
 Pass_char[3]= ' ';
 
 }else{
  Serial.println("ERR"); 
   delay(1000);
    activated = 0;
 character=0;
 Pass_char[0]= ' ';
 Pass_char[1]= ' '; 
 Pass_char[2]= ' '; 
 Pass_char[3]= ' ';
 }
  
 
}}
