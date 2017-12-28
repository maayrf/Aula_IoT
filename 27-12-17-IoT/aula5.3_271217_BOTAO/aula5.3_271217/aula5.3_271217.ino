const int vm = 6;
const int vd = 3;
const int botao = 5;
int estb = LOW;
int estvm = LOW;
int estvd = LOW;
int uestb = LOW;
int uestvm = LOW;
int uestvd = LOW;

void setup() {
  // put your setup code here, to run once:
pinMode (vm,OUTPUT);
pinMode (vd,OUTPUT);
pinMode (botao,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
estb = digitalRead (botao);
if (estb != uestb)
{
 if (estb == HIGH ) 
 {
  if (uestvm == HIGH) 
  {
    digitalWrite (vm,LOW);
    uestvm = LOW;
    digitalWrite (vd,HIGH);
    uestvd = HIGH;
  }
  else 
  {
   digitalWrite (vm,HIGH);
   uestvm = HIGH;
   digitalWrite (vd,LOW);
   uestvd = LOW;
  }
 }
}
uestb = estb;
}
