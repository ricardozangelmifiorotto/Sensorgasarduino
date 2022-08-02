 
int pinSensor = A0; //Pino Sensor
int Rele = 3; //Pino Relé
int buzzer = 2; //Pino Buzzer
int var = 0;
int ValDesarm = 30; //Variável para selecionar a quantidade de Gás/Fumaça detectada
int valor = 0;
 
void setup()
{
 Serial.begin(9600); //Inicia porta Serial em 9600 baud
 pinMode(Rele, OUTPUT);
 pinMode(buzzer, OUTPUT);
}
 
void loop()
{
 valor = analogRead(pinSensor); //Faz a leitura da entrada do sensor
 valor = map(valor, 0, 1023, 0, 100); //Faz a conversão da variável para porcentagem
 Serial.println(valor); //Escreve o valor na porta Serial
 if (valor>=ValDesarm){ //Condição, se valor continuar maior que ValDesarm faça:
 digitalWrite(Rele, HIGH); //Liga relé para solenóide
 digitalWrite(buzzer, HIGH); //Dispara alarme de vazamento ou possível incêndio
 Serial.println("Alarme Ligado"); //Apresenta mensagem na porta serial
 delay(1000); //Tempo de disparo do alarme
 digitalWrite(buzzer, LOW); //Desliga o alarme
 delay(2000); //Aguarda
 }else{
 digitalWrite(Rele, LOW); //Caso contrário permaneça com o relé desligado
 }
 delay(1000);
}
