#include <VirtualWire.h>
#define button_1 5
#define button_2 6
String mensagem;
void setup() {
  pinMode(button_1, INPUT_PULLUP);
  pinMode(button_2, INPUT_PULLUP);
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Define o pino 8 do Arduino como o pino de dados do transmissor
  vw_set_tx_pin(8);
  vw_setup(2000);   // Bits per sec
}

void loop() {
  // put your main code here, to run repeatedly:
  char data[40];
  int numero;
  //if (Serial.available() > 0)
  //{
    //numero = Serial.readBytesUntil (13,data,40);
    data[0] = digitalRead(button_1) + 48;
    data[1] = digitalRead(button_2) + 48;
    data[2] = 0;
    //Serial.print("Enviado : ");
    //Serial.print(data);
    //Serial.print(" - Caracteres : ");
    //Serial.println(strlen(data));
    //Envia a mensagem para a rotina que transmite os dados via RF
    send(data);
  //}  
}
void send (char *message)
{
  vw_send((uint8_t *)message, strlen(message));
  vw_wait_tx(); // Aguarda o envio de dados
}
