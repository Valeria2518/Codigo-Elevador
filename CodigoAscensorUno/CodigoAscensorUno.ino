
const int Pos0 = A0;
const int PA1=2;
const int PA2=4;


unsigned int D9=0;
unsigned int D10=0;
unsigned int D11=0;unsigned int D12=0;

const int PWM1=5;
const int PWM2=6;
unsigned int An0=0;
unsigned int PosicionActual =0;
unsigned int PosicionFutura =0;
unsigned int PosicionPasada =0;



void setup() {
Serial.begin(9600);
pinMode(PA1, OUTPUT);
pinMode(PA2, OUTPUT);
pinMode(PWM1, OUTPUT);
pinMode(PWM2, OUTPUT);

pinMode(9,  INPUT);
pinMode(10, INPUT);
pinMode(11, INPUT);
pinMode(12, INPUT);


digitalWrite(PA1,LOW);
digitalWrite(PA2,LOW);
}

void loop() {
An0=analogRead(Pos0);
Posicion_Actual(An0);
Serial.println(PosicionActual);
D9=digitalRead(9);
D10=digitalRead(10);
D11=digitalRead(11);
D12=digitalRead(12);


}else if (D10==HIGH) {
  if(PosicionActual==1){
    Motor(150,0);
  }else if (PosicionActual==3) {
    Motor(0,160);
  }else{
    delay(1000);
    Motor(120,0);
  }
}else if(D11==HIGH){
  if(PosicionActual==1){
    Motor(150,0);
  }else if (PosicionActual==3) {
    Motor(0,160);
  }else{
    delay(1000);
    Motor(0,120);
  }
}else if(D12==HIGH){
 if (PosicionActual==1) {
    delay(1000);
   Motor(160,0);
  }else if(PosicionActual==3 || PosicionActual==2 ){
    Motor(0,120);
  }
}else{

}else if(D12==HIGH){
 if (PosicionActual==1) {
    delay(1000);
   Motor(160,0);
  }else if(PosicionActual==3 || PosicionActual==2 ){
    Motor(0,120);
  }
}else{
}








Segmentos();

}


void Motor(int a,int b){
  analogWrite(PWM1, a);
  analogWrite(PWM2, b);
}



}