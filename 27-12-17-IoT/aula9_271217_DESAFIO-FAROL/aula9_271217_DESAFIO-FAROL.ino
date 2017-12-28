const int vm = 6;
const int am = 5;
const int vd = 4;
const int botao = 3;
int estb = LOW;
int uestb = LOW;
int estvm = LOW;
int uestvm = LOW;
int estam = LOW;
int uestam = LOW;
int estvd = LOW;
int uestvd = LOW;

void setup() {
  // put your setup code here, to run once:
pinMode (vm,OUTPUT);
pinMode (am,OUTPUT);
pinMode (vd,OUTPUT);
pinMode (botao,INPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  estb = digitalRead (botao);
  
switch (estb) {
   case 1:
   digitalWrite (vm,HIGH);
   digitalWrite (am,LOW);
   digitalWrite (vd,LOW);
   delay(5000);
   //break;
   case 2:
   digitalWrite (am,HIGH);
   digitalWrite (vm,LOW);
   digitalWrite (vd,LOW);
   delay(2000);
  // break;
   case 3:
   digitalWrite (vd,HIGH);
   digitalWrite (am,LOW);
   digitalWrite (vm,LOW);
   delay(7000);
 
   //break;

   //default:
  // digitalWrite (botao,HIGH);
return;

}
   }

