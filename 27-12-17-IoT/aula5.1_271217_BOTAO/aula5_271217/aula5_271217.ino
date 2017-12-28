const int ver = 6;
const int botao = 5;
int est;
int f1;
int f2;

void setup() {
  // put your setup code here, to run once:
pinMode (ver,OUTPUT);
pinMode (botao,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  f1 = digitalRead (botao);
if ((f1 == HIGH) && (f2 == LOW)) {
  est = 1 - est;
  //delay (500);
}
f2=f1;
if (est == 1) {
   digitalWrite (ver,HIGH);
}
else {
   digitalWrite (ver,LOW);
}
}
