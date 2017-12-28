const int sensor_temperatura = A0;
int leitura_sensor;
float temperatura;
int led_vm = 6;   //vermelho
int led_am = 5;   //amarelo
int led_vd = 4;   //verde
int leitura_buzina;
int buzina = 7;
int botlig = 3;   //botão que liga vermelho e buzina
int botdes = 2;   //botão que volta para estado normal, sem ser de alerta
int estlig = LOW;
int estdes = LOW;

void setup() {
  // put your setup code here, to run once:
analogReference(INTERNAL);  //como capitar a referencia da porta analógica
Serial.begin(9600);
pinMode (led_vm,OUTPUT);
pinMode (led_am,OUTPUT);
pinMode (led_vd,OUTPUT);
pinMode (buzina,OUTPUT);
pinMode (botlig,INPUT);   //botão sempre tem que estar como INPUT
pinMode (botdes,INPUT);   //botão sempre tem que estar como INPUT
}

void loop() {
  // put your main code here, to run repeatedly:
estlig = digitalRead (botlig);
estdes = digitalRead (botdes);

leitura_sensor = analogRead(sensor_temperatura);
temperatura = leitura_sensor * 0.1075268817204301;
Serial.print("Temperatura: ");
Serial.println(temperatura);
delay(1000);

if (temperatura < 28){
  noTone(buzina);   //não liga buzina
  digitalWrite(led_vd,HIGH);
  digitalWrite(led_am,LOW);
  digitalWrite(led_vm,LOW);
}

else if (temperatura >= 28 && temperatura < 30){
  noTone(buzina);   //não liga buzina
  digitalWrite(led_am,HIGH);
  digitalWrite(led_vm,LOW);
  digitalWrite(led_vd,LOW);
  }

  if (temperatura >= 30) {
    
  tone (buzina,1000);   //liga buzina somente quando estier vermelho
  digitalWrite(led_vm,HIGH);
  digitalWrite(led_am,LOW);
  digitalWrite(led_vd,LOW);
   }

if (estlig == HIGH)   //quando o botão estiver ligado
{
 
   while (estdes == LOW)  // e enquanto o outro botão estiver desligado, vai rodar toda funcão do led_vm
   {
  tone (buzina,1000);
  digitalWrite(led_vm,HIGH);
  digitalWrite(led_am,LOW);
  digitalWrite(led_vd,LOW);
  estdes = digitalRead (botdes);    //quando você ligar o alarme e deseja desliga-lo, clique no outro botao, no definido para desligar
   }
}
}



