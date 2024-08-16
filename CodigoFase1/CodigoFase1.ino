// Define the LED pins
#define LedEstacionamiento 31
#define LedSala 33
#define LedPieza1 35
#define LedPieza2 37
int LedE=0;
int LedS=0;
int LedP1=0;
int LedP2=0;
//Humo
#define PHumo A0
int Humo=0;
//Temperatura
#define PTemp A1
#define Disipador 5
int TempA=0;
float Temp=0.0;
const unsigned long TiempoTem = 25000;
unsigned long TmPasTem = 0;

//Buzzer
#define Buzzer 4
//Sonido
#define Sonido 22
//Lector del serial 
String input=" ";
int imput=0;
bool x=false;

void setup() {
  Serial.begin(9600);
  TmPasTem = millis();
  pinMode(LedEstacionamiento, OUTPUT);
  pinMode(LedSala, OUTPUT);
  pinMode(LedPieza1, OUTPUT);
  pinMode(LedPieza2, OUTPUT);
  digitalWrite(LedEstacionamiento, LOW);
  digitalWrite(LedSala, LOW);
  digitalWrite(LedPieza1, LOW);
  digitalWrite(LedPieza2, LOW);
  //Temperatura
  analogWrite(Disipador,0);

  //Buzzer
  analogWrite(Buzzer,0);
  //Sonido
  pinMode(Sonido,INPUT);
 
}

void loop() {
  Humo=analogRead(PHumo);
  unsigned long TmAcTem = millis();
   if (TmAcTem- TmPasTem>= TiempoTem) {
    TempA = analogRead(PTemp);
    TmPasTem = TmAcTem;
  }
 
  //Verificar si afecta el sistema 
  while (digitalRead(Sonido)!=LOW) {
    LedE = (LedE == HIGH) ? LOW : HIGH;
   
  }
  if (x) {
          imput=atoi(input.c_str());
          input=" ";
          x=false; 
          switch (imput){
            case 1:
            LedE = (LedE == HIGH) ? LOW : HIGH;
            break;
            case 2:
            LedS = (LedS == HIGH) ? LOW : HIGH;
            break;
            case 3:
            LedP1 = (LedP1 == HIGH) ? LOW : HIGH;
            break;
            case 4:
            LedP2 = (LedP2 == HIGH) ? LOW : HIGH;
            break;
          }

    }
    Leds(LedE, LedS, LedP1, LedP2); 
    Humos(Humo);
    Temperatura(TempA);
}

void Leds(int Es, int Sa, int P1, int P2) {
  digitalWrite(LedEstacionamiento, Es);
  digitalWrite(LedSala, Sa);
  digitalWrite(LedPieza1, P1);
  digitalWrite(LedPieza2, P2);
}

void Humos(int Humo) {
  Serial.print("Humo: ");
  Serial.print(Humo);
  Serial.print("     ");
  if(Humo>200){
    analogWrite(Buzzer,255);
  }else{
    analogWrite(Buzzer,0);
  }
}

void Temperatura(int TempA) {
  Temp=((TempA*5000.0)/1023)/10;
  Serial.print("Tempera: ");
  Serial.println(Temp,2);
  if(Temp>35){
    analogWrite(Disipador,255);
  }else{
    analogWrite(Disipador,0);
  }
}




void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    input += inChar;
    if (inChar =='.') {
    x = true;
    }
  }
}