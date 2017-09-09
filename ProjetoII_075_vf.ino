
//Programa: Projeto II EA075 - Sensor de estacionamento
//Autor: Eduardo Guimarães com colaboração do código de FILIPEFLOP
//Ra: 166754

//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>

//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5

//Inicializa o sensor e os atuadores nos pinos
Ultrasonic ultrasonic(pino_trigger, pino_echo);
int buzzer = 6;
int led_ver = 13;


void setup()
{
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
  pinMode(buzzer,OUTPUT);
  pinMode(led_ver,OUTPUT);
}


void loop()
{
  //Le as informacoes do sensor
  float cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  
  //Exibe informacoes no serial monitor para debuggar
  Serial.print("Distancia em cm: ");
  Serial.print(cmMsec);
  Serial.print("\n");

  //Condicoes de ligar o Led e o buzzer
    if (cmMsec < 50)
  {
    tone(6,300,300);
    digitalWrite(led_ver, HIGH);
  }
  else 
  {
     tone(6,0,0);
     digitalWrite(led_ver, LOW);
  }
  
  delay(1000);
}
