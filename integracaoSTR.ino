// ----------------------------- sensor presenca ---------------------------- //
const int pinoLED = 7;
const int pinoPIR = 6;
const int qtdConsideravel = 3;     // quantidade de vezes que é considerado ter alguem presente - valor a ser definido
int iPresenca;
bool temGente;
long contadorTempo;
// ------------------------------------------------------------------------- //

// -------------------------- sensor luminosidade ------------------------- //
int limit = 70;
const int analogicoLUZ = 2;
// ----------------------------------------------------------------------- //

void setup() {
  pinMode(pinoLED, OUTPUT);
  pinMode(pinoPIR, INPUT);
  iPresenca = 0;
  temGente = false;
  Serial.begin(9600);
}

void loop() {
  long tempo = millis(); 
  int valor = digitalRead(pinoPIR);
  
  int sensorValue = analogRead(analogicoLUZ);
  if (sensorValue < limit)
     Serial.println("Apagado");
  else
     Serial.println("Aceso");
 
  if (valor == HIGH) {
    iPresenca++;
    if(iPresenca == qtdConsideravel){
      temGente = true;  
      Serial.println("Tem gente!");
      temGente = false;
      iPresenca = 0;
    }
      
    Serial.println("detectado"); 
    digitalWrite(pinoLED, HIGH);

  }else{
    iPresenca = 0;
    temGente = false;
    Serial.println("não detectado");
    digitalWrite(pinoLED, LOW);
  }
  delay(1500); // intervalo para verificar presenca
}
