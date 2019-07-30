  /* Projeto com arduino de alarme com câmera infravermelha de detecção de radiação de corpo negro - sensor PIR */
  //declaração de variáveis
  int pinBuzzer = 7;
  int pinSensorPIR = 8;
  int pinLed = 9;
  int valorSensorPIR = 0;
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Declaração de saída e entrada
  pinMode(pinBuzzer,OUTPUT);
  pinMode(pinSensorPIR,INPUT);
  pinMode(pinLed,OUTPUT);
}
 
void loop() {  
  // put your setup code here, to run repeatedly:
  valorSensorPIR = digitalRead(pinSensorPIR);
  Serial.print("Valor do Sensor PIR: ");  
  Serial.println("valorSensorPIR");
  //Verificação de movimentos detectados pelo sensor
  if (valorSensorPIR == 1) {
    ligarAlarme();
  } else {
    desligarAlarme();
  }    
}
 
void ligarAlarme() {
  digitalWrite(pinLed, HIGH);
  tone(pinBuzzer,261);
  delay(4000);
  desligarAlarme();
}
 
void desligarAlarme() {
  digitalWrite(pinLed, LOW);
  noTone(pinBuzzer);
}
