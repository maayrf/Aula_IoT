const int sensor_temperatura = A0;
int leitura_sensor = 0;
float temperatura;
int ledvermelho = 6;   //vermelho
int ledamarelo = 5;   //amarelo
int ledverde = 4;   //verde
//int leitura_buzina;
int buzzer = 7;
int btn_liga_alarme = 3;   //botão que liga vermelho e buzina
int btn_desliga_alarme = 2;   //botão que volta para estado normal, sem ser de alerta
int estado_liga_alarme = LOW;
int estado_desliga_alarme = LOW;

void setup() {
  // put your setup code here, to run once:
analogReference(INTERNAL);  //como capitar a referencia da porta analógica
Serial.begin(9600);
pinMode (ledvermelho,OUTPUT);
pinMode (ledamarelo,OUTPUT);
pinMode (ledverde,OUTPUT);
pinMode (buzzer,OUTPUT);
pinMode (btn_liga_alarme,INPUT);   //botão sempre tem que estar como INPUT
pinMode (btn_desliga_alarme,INPUT);   //botão sempre tem que estar como INPUT
}

void liga_alarme(){
digitalWrite(ledvermelho,HIGH);
digitalWrite(ledverde,LOW);
digitalWrite(ledamarelo,LOW);
tone(buzzer,500);  
}

void desliga_alarme_verde() {
digitalWrite(ledvermelho,LOW);
digitalWrite(ledverde,HIGH);
digitalWrite(ledamarelo,LOW);
noTone(buzzer);
}

void desliga_alarme_amarelo() {
digitalWrite(ledvermelho,LOW);
digitalWrite(ledverde,LOW);
digitalWrite(ledamarelo,HIGH);
noTone(buzzer);
}

void leitura_botao() {
  estado_liga_alarme = digitalRead(btn_liga_alarme);
 estado_desliga_alarme = digitalRead(btn_desliga_alarme);
}
void leitura_temperatura()
{
leitura_sensor = analogRead(sensor_temperatura);
temperatura = leitura_sensor * 0.1075268817204301;  
}


void loop() {
  // put your main code here, to run repeatedly:
leitura_botao();
leitura_temperatura();

Serial.print("Temperatura: ");
Serial.println(temperatura);
delay(1000);

if (temperatura > 30) {
liga_alarme();
}
if (temperatura <= 28) {
desliga_alarme_verde();
}
if (temperatura > 28 && temperatura < 30) {
desliga_alarme_amarelo();
}

if (estado_desliga_alarme == HIGH)  {
digitalWrite(ledvermelho,HIGH);
digitalWrite(ledverde,LOW);
digitalWrite(ledamarelo,LOW);
tone(buzzer,500); 
}

if (estado_liga_alarme == HIGH) {
while (estado_desliga_alarme != HIGH) {
//digitalWrite(ledvermelho,HIGH);
//digitalWrite(ledverde,LOW);
//digitalWrite(ledamarelo,LOW);
//tone(buzzer,500);
liga_alarme();
estado_desliga_alarme = digitalRead(btn_desliga_alarme); 
}
}
}

