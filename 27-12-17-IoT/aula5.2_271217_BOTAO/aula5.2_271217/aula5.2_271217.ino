const int ver = 6;
const int botao = 5;
int estb = LOW;
int estv = LOW;
int uestb = LOW;
int uestv = LOW;

void setup() {
  // put your setup code here, to run once:
pinMode (ver,OUTPUT);
pinMode (botao,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
estb = digitalRead (botao);
if (estb != uestb)
{
 if (estb == HIGH ) 
 {
  if (uestv == HIGH) 
  {
    digitalWrite (ver,LOW);
    uestv = LOW;
  }
  else 
  {
   digitalWrite (ver,HIGH);
   uestv = HIGH; 
  }
 }
}
uestb = estb;
}
