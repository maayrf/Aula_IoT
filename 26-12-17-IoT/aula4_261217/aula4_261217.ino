const int ver = 6;
const int botao = 5;
int est;

  
void setup() {
  // put your setup code here, to run once:
pinMode (botao,INPUT);
pinMode (ver,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
est = digitalRead (botao);

if (est == HIGH) {
digitalWrite (ver,HIGH);
 }
 else{  
digitalWrite (ver,LOW);
 }
  
}

