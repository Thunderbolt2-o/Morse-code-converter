#include <string.h>

const int buzzer = 9; //buzzer to arduino pin 95
int ss = 1000;
char alpha[26][10] = {"10","0111","0101","011","1","1101", "001","1111","11","1000","010","1011","00", "1001","0010","101","111","0","110","1110","100","0110","0100","0011"};
int len  = 5;
void setup() {
  Serial.begin(9600);
  Serial.println("Enter your name.");
  pinMode(buzzer, OUTPUT);
}

char rx_byte = 0;
String rx_str = "";

void loop() {
  if (Serial.available() > 0) {    // is a character available?
    rx_byte = Serial.read();       // get the character
    
    if (rx_byte != '\n') {
      // a character of the string was received
      rx_str += rx_byte;
    }
    else {
      // end of string
      Serial.print("Welcome ");
      Serial.println(rx_str);
      len = rx_str.length();
      Serial.print(len);
      Serial.println("Enter your name.");
      String str,strin="abcde";
      int len1;
      for(int i=0;i<len;i++){
        str=alpha[rx_str[i]-'a'];//length();
        for(int j=0;j<str.length();j++){
          Serial.print(alpha[rx_str[i]-'a'][j]);
          if(alpha[rx_str[i]-'a'][j]=='1'){
            tone(buzzer,50);
            delay(500);
            noTone(buzzer);
            delay(200);
          }
          else{
            tone(buzzer,50);
            delay(200);
            noTone(buzzer);
            delay(200);
          }
        }
        delay(2000);
      }
      noTone(buzzer); 
      rx_str = "";     
    }
  }
}
