#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

#define Button_azul 12
#define Button_branco 13
#define LED_Azul 4
#define LED_Amarelo 6

void setup()
{
  pinMode(Button_azul , INPUT_PULLUP);
  pinMode(Button_branco , INPUT_PULLUP);
  pinMode(LED_Azul, OUTPUT);
  pinMode(LED_Amarelo, OUTPUT);
  
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);
  
  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Iniciando o Modulo DFPlayer ... (Espere em torno de 3 a 5 segundos.)"));
  
  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Falha ao iniciar:"));
    Serial.println(F("1.Cheque a conexao do modulo!"));
    Serial.println(F("2.Insira um SD Card!"));
    while(true);
  }
  Serial.println(F("DFPlayer Mini Conectado."));
  
  myDFPlayer.volume(30);  //Set volume value. From 0 to 30
  

}

void loop()
{ if  (digitalRead(Button_azul) == LOW){
          digitalWrite(LED_Azul, HIGH);
          myDFPlayer.volume(30);
          myDFPlayer.play(1);
          delay(5000);
          myDFPlayer.stop();
        }
        if (digitalRead(Button_branco) == LOW){
          digitalWrite(LED_Amarelo, HIGH);
          myDFPlayer.volume(15);
          myDFPlayer.play(2);
          delay(5000);
          myDFPlayer.stop();
          }
  
        digitalWrite(LED_Azul,LOW);
        digitalWrite(LED_Amarelo,LOW);
        
 
delay(500);
}
