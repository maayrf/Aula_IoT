int vermelho = 6;
int verde = 5;
int result = 11;
  
void setup() {
  // put your setup code here, to run once:
pinMode (vermelho,OUTPUT);
pinMode (verde,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if (result > 10)
{
  digitalWrite (vermelho,HIGH);
  delay(50);
  digitalWrite (vermelho,LOW);
  delay(50);
}
else
{
  digitalWrite (verde,HIGH);
  delay(50);
  digitalWrite (verde,LOW);
  delay(50); 
}
}

