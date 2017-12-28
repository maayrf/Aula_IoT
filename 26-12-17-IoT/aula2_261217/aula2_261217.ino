const int porta = 13;
int soma1 = 5;
int soma2 = 3;
int resultado;

void setup() {
  // put your setup code here, to run once:
resultado = soma1 + soma2;
Serial.begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println (resultado);
delay (1000);
}

