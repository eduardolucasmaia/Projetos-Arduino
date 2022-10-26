const int display1a = 46;
const int display1b = 47;
const int display1c = 48;
const int display1d = 49;
const int display1e = 50;
const int display1f = 51;
const int display1g = 52;

const int display2a = 38;
const int display2b = 39;
const int display2c = 40;
const int display2d = 41;
const int display2e = 42;
const int display2f = 43;
const int display2g = 44;

const int display3a = 30;
const int display3b = 31;
const int display3c = 32;
const int display3d = 33;
const int display3e = 34;
const int display3f = 35;
const int display3g = 36;

const int display4a = 22;
const int display4b = 23;
const int display4c = 24;
const int display4d = 25;
const int display4e = 26;
const int display4f = 27;
const int display4g = 28;

const int botaoD1 = 53;
const int botaoD2 = 45;
const int botaoD3 = 37;
const int botaoD4 = 29;

const int botaoSave = 6;
const int botaoClean = 5;
const int botaoOpen = 3;
const int botaoClose = 4;

int estadobotaoD1;
int estadobotaoD2;
int estadobotaoD3;
int estadobotaoD4;

int estadobotaoSave;
int estadobotaoClean;
int estadobotaoOpen;
int estadobotaoClose;

const int motorHorario = 8;
const int motorAntHorario = 9;
const int ledErro = 7;
const int ledCorreto = 10;
const int buzzer = 13;

int contBotaoD1;
int contBotaoD2;
int contBotaoD3;
int contBotaoD4;

int aberto = 1;
int fechado = 0;
int estadoCofre = aberto;  // 1 Para Aberto, 0 para Fechado;

int senhaCofre1;
int senhaCofre2;
int senhaCofre3;
int senhaCofre4;

void setup() {
  
  Serial.begin(9600);
  
  pinMode(display1a,OUTPUT);
  pinMode(display1b,OUTPUT);
  pinMode(display1c,OUTPUT);
  pinMode(display1d,OUTPUT);
  pinMode(display1e,OUTPUT);
  pinMode(display1f,OUTPUT);
  pinMode(display1g,OUTPUT);
  
  pinMode(display2a,OUTPUT);
  pinMode(display2b,OUTPUT);
  pinMode(display2c,OUTPUT);
  pinMode(display2d,OUTPUT);
  pinMode(display2e,OUTPUT);
  pinMode(display2f,OUTPUT);
  pinMode(display2g,OUTPUT);
  
  pinMode(display3a,OUTPUT);
  pinMode(display3b,OUTPUT);
  pinMode(display3c,OUTPUT);
  pinMode(display3d,OUTPUT);
  pinMode(display3e,OUTPUT);
  pinMode(display3f,OUTPUT);
  pinMode(display3g,OUTPUT);
  
  pinMode(display4a,OUTPUT);
  pinMode(display4b,OUTPUT);
  pinMode(display4c,OUTPUT);
  pinMode(display4d,OUTPUT);
  pinMode(display4e,OUTPUT);
  pinMode(display4f,OUTPUT);
  pinMode(display4g,OUTPUT);
  
  pinMode(botaoD1,INPUT);
  pinMode(botaoD2,INPUT);
  pinMode(botaoD3,INPUT);
  pinMode(botaoD4,INPUT);
  
  pinMode(botaoSave,INPUT);
  pinMode(botaoClean,INPUT);
  pinMode(botaoOpen,INPUT);
  pinMode(botaoClose,INPUT);
  
  pinMode(motorHorario,OUTPUT);
  pinMode(motorAntHorario,OUTPUT);
  digitalWrite(motorHorario,LOW);
  digitalWrite(motorAntHorario,LOW);
  
  pinMode(ledErro,OUTPUT); 
  pinMode(ledCorreto,OUTPUT);
  pinMode(buzzer,OUTPUT);
  
  digitalWrite(botaoD1,HIGH);
  digitalWrite(botaoD2,HIGH);
  digitalWrite(botaoD3,HIGH);
  digitalWrite(botaoD4,HIGH);
  
  digitalWrite(botaoSave,HIGH);
  digitalWrite(botaoOpen,HIGH);
  digitalWrite(botaoClose,HIGH);
  digitalWrite(botaoClean,HIGH);
  
  //Senha Inicial 0000
  senhaCofre1 = 0;
  senhaCofre2 = 0;
  senhaCofre3 = 0;
  senhaCofre4 = 0;
  
  contBotaoD1 = 0;
  contBotaoD2 = 0;
  contBotaoD3 = 0;
  contBotaoD4 = 0;
  
}

void loop() {
  
  int estadobotaoD1 = digitalRead(botaoD1);
  int estadobotaoD2 = digitalRead(botaoD2);
  int estadobotaoD3 = digitalRead(botaoD3);
  int estadobotaoD4 = digitalRead(botaoD4);
  
  int estadobotaoSave = digitalRead(botaoSave);
  int estadobotaoClean = digitalRead(botaoClean);
  int estadobotaoOpen = digitalRead(botaoOpen);
  int estadobotaoClose = digitalRead(botaoClose);
  
  
  //Para Salvar a Senha nova do cofre
  if (estadobotaoSave == LOW){
    delay(200);
    Serial.print("\n\nSave Apertado!"); 
  if(estadoCofre == aberto){ 
    Serial.print("\nConseguiu salvar senha!");
    digitalWrite(ledCorreto,HIGH);
    tone(buzzer,2500);   
    delay(200);
    noTone(buzzer);
    delay(50);  
    tone(buzzer,3500);   
    delay(200);
    noTone(buzzer);
    digitalWrite(ledCorreto,LOW);
    senhaCofre1 = contBotaoD1;
    senhaCofre2 = contBotaoD2;
    senhaCofre3 = contBotaoD3;
    senhaCofre4 = contBotaoD4;    
    }
  else {       //Para se algo estiver errado
    Serial.print("\nNAO Conseguiu salvar senha!"); 
    digitalWrite(ledErro,HIGH);
    tone(buzzer,500);   
    delay(200);
    noTone(buzzer);
    delay(50);  
    tone(buzzer,500);   
    delay(200);
    noTone(buzzer);
    digitalWrite(ledErro,LOW);
  }
  }
  
  
  
  if(estadobotaoOpen == LOW){ //Para Abrir o cofre
  delay(200);
  Serial.print("\n\nOpen Apertado!"); 
    if(contBotaoD1 == senhaCofre1 && contBotaoD2 == senhaCofre2 && contBotaoD3 == senhaCofre3 && contBotaoD4 == senhaCofre4 && estadoCofre == fechado){
    estadoCofre = aberto;
    Serial.print("\nEstado Atual = Aberto"); 
    digitalWrite(ledCorreto,HIGH);
    digitalWrite(motorHorario,LOW);
    digitalWrite(motorAntHorario,HIGH);
    tone(buzzer,2500);   
    delay(200);
    noTone(buzzer);
    delay(50);  
    digitalWrite(motorAntHorario,LOW);
    tone(buzzer,3500);   
    delay(200);
    noTone(buzzer);
    digitalWrite(ledCorreto,LOW);
  }
  else {                        //Para se algo estiver errado
    Serial.print("\nNao Conseguiu abrir!"); 
    digitalWrite(ledErro,HIGH);
    tone(buzzer,500);   
    delay(200);
    noTone(buzzer);
    delay(50);  
    tone(buzzer,500);   
    delay(200);
    noTone(buzzer);
    digitalWrite(ledErro,LOW);
  }
  }
  
  
  
  if (estadobotaoClose == LOW){ //Para fechar o cofre
  delay(200);
  Serial.print("\n\nClose Apertado!");  
    if(estadoCofre == aberto){
    estadoCofre = fechado;
    Serial.print("\nEstado Atual = Fechado"); 
  digitalWrite(ledCorreto,HIGH); 
    digitalWrite(motorHorario,HIGH);
    digitalWrite(motorAntHorario,LOW);
    tone(buzzer,2500);   
    delay(200);
    noTone(buzzer);
    delay(50);  
    digitalWrite(motorHorario,LOW);
    tone(buzzer,3500);   
    delay(200);
    noTone(buzzer);
    digitalWrite(ledCorreto,LOW);
  }  
  else {                        //Para se algo estiver errado
    Serial.print("\nNAO Conseguiu fechar!"); 
    digitalWrite(ledErro,HIGH);
    tone(buzzer,500);   
    delay(200);
    noTone(buzzer);
    delay(50);  
    tone(buzzer,500);   
    delay(200);
    noTone(buzzer);
    digitalWrite(ledErro,LOW);
  }
  }
  
  
  
  if (estadobotaoClean == LOW){
    delay(200);
    digitalWrite(ledCorreto,HIGH);
    contBotaoD1 = 0;
    contBotaoD2 = 0;
    contBotaoD3 = 0;
    contBotaoD4 = 0;
    
    tone(buzzer,2500);   
    delay(200);
    noTone(buzzer);
    delay(50);  
    tone(buzzer,3500);   
    delay(200);
    noTone(buzzer);
 
    Serial.print("\n\nClean Apertado!\n");
    Serial.print("Senha atual:\nDisplay 4 = ");
    Serial.print(senhaCofre4);
    Serial.print("\nDisplay 3 = ");
    Serial.print(senhaCofre3);
    Serial.print("\nDisplay 2 = ");
    Serial.print(senhaCofre2);
    Serial.print("\nDisplay 1 = ");
    Serial.print(senhaCofre1);
    contBotaoD1 = 0;
    contBotaoD2 = 0;
    contBotaoD3 = 0;
    contBotaoD4 = 0;
    digitalWrite(ledCorreto,LOW);
  }
  
  
  
  //Inicio do Contador do Display unidade
  
  if (estadobotaoD1 == LOW){
    contBotaoD1 ++;  
    tone(buzzer,3500);   
    delay(200);
    noTone(buzzer);
  }
  
  if (contBotaoD1 == 10){
    contBotaoD1 = 0;
  }
  
  if (contBotaoD1 == 0){
    numeroZeroD1();
  }
  
  if (contBotaoD1 == 1){
    numeroUmD1();
  }
  
  if (contBotaoD1 == 2){
    numeroDoisD1();
  }
  
  if (contBotaoD1 == 3){
    numeroTresD1();
  }
  
  if (contBotaoD1 == 4){
    numeroQuatroD1();
  }
  
  if (contBotaoD1 == 5){
    numeroCincoD1();
  }
  
  if (contBotaoD1 == 6){
    numeroSeisD1();
  }
  
  if (contBotaoD1 == 7){
    numeroSeteD1();
  }
  
  if (contBotaoD1 == 8){
    numeroOitoD1();
  }
  
  if (contBotaoD1 == 9){
    numeroNoveD1();
  }
  
  //Termino do Contador do Display unidade
  
  //Inicio do Contador do Display Dezena
  
  if (estadobotaoD2 == LOW){
    contBotaoD2 ++;  
    tone(buzzer,3500);   
    delay(200);
    noTone(buzzer);
  }
  
  if (contBotaoD2 == 10){
    contBotaoD2 = 0;
  }
  
  if (contBotaoD2 == 0){
    numeroZeroD2();
  }
  
  if (contBotaoD2 == 1){
    numeroUmD2();
  }
  
  if (contBotaoD2 == 2){
    numeroDoisD2();
  }
  
  if (contBotaoD2 == 3){
    numeroTresD2();
  }
  
  if (contBotaoD2 == 4){
    numeroQuatroD2();
  }
  
  if (contBotaoD2 == 5){
    numeroCincoD2();
  }
  
  if (contBotaoD2 == 6){
    numeroSeisD2();
  }
  
  if (contBotaoD2 == 7){
    numeroSeteD2();
  }
  
  if (contBotaoD2 == 8){
    numeroOitoD2();
  }
  
  if (contBotaoD2 == 9){
    numeroNoveD2();
  }
  
  //Termino do Contador do Display Dezena
  
  //Inicio do Contador do Display Centena
  
  if (estadobotaoD3 == LOW){
    contBotaoD3 ++;  
    tone(buzzer,3500);   
    delay(200);
    noTone(buzzer);
  }
  
  if (contBotaoD3 == 10){
    contBotaoD3 = 0;
  }
  
  if (contBotaoD3 == 0){
    numeroZeroD3();
  }
  
  if (contBotaoD3 == 1){
    numeroUmD3();
  }
  
  if (contBotaoD3 == 2){
    numeroDoisD3();
  }
  
  if (contBotaoD3 == 3){
    numeroTresD3();
  }
  
  if (contBotaoD3 == 4){
    numeroQuatroD3();
  }
  
  if (contBotaoD3 == 5){
    numeroCincoD3();
  }
  
  if (contBotaoD3 == 6){
    numeroSeisD3();
  }
  
  if (contBotaoD3 == 7){
    numeroSeteD3();
  }
  
  if (contBotaoD3 == 8){
    numeroOitoD3();
  }
  
  if (contBotaoD3 == 9){
    numeroNoveD3();
  }
  
  //Termino do Contador do Display Centena
  
  //Inicio do Contador do Display Milhar
  
  if (estadobotaoD4 == LOW){
   contBotaoD4 ++; 
   tone(buzzer,3500);   
    delay(200);
    noTone(buzzer);
  }
  
  if (contBotaoD4 == 10){
    contBotaoD4 = 0;
  }
  
  if (contBotaoD4 == 0){
    numeroZeroD4();
  }
  
  if (contBotaoD4 == 1){
    numeroUmD4();
  }
  
  if (contBotaoD4 == 2){
    numeroDoisD4();
  }
  
  if (contBotaoD4 == 3){
    numeroTresD4();
  }
  
  if (contBotaoD4 == 4){
    numeroQuatroD4();
  }
  
  if (contBotaoD4 == 5){
    numeroCincoD4();
  }
  
  if (contBotaoD4 == 6){
    numeroSeisD4();
  }
  
  if (contBotaoD4 == 7){
    numeroSeteD4();
  }
  
  if (contBotaoD4 == 8){
    numeroOitoD4();
  }
  
  if (contBotaoD4 == 9){
    numeroNoveD4();
  } 
  //Termino do Contador do Display Milhar
  
}

void numeroUmD1(){
    digitalWrite(display1a,LOW);
    digitalWrite(display1b,HIGH);
    digitalWrite(display1c,HIGH);
    digitalWrite(display1d,LOW);
    digitalWrite(display1e,LOW);
    digitalWrite(display1f,LOW);
    digitalWrite(display1g,LOW); 
}

void numeroDoisD1(){
    digitalWrite(display1a,HIGH);
    digitalWrite(display1b,HIGH);
    digitalWrite(display1c,LOW);
    digitalWrite(display1d,HIGH);
    digitalWrite(display1e,HIGH);
    digitalWrite(display1f,LOW);
    digitalWrite(display1g,HIGH); 
}

void numeroTresD1(){
    digitalWrite(display1a,HIGH);
    digitalWrite(display1b,HIGH);
    digitalWrite(display1c,HIGH);
    digitalWrite(display1d,HIGH);
    digitalWrite(display1e,LOW);
    digitalWrite(display1f,LOW);
    digitalWrite(display1g,HIGH); 
}

void numeroQuatroD1(){
    digitalWrite(display1a,LOW);
    digitalWrite(display1b,HIGH);
    digitalWrite(display1c,HIGH);
    digitalWrite(display1d,LOW);
    digitalWrite(display1e,LOW);
    digitalWrite(display1f,HIGH);
    digitalWrite(display1g,HIGH); 
}

void numeroCincoD1(){
    digitalWrite(display1a,HIGH);
    digitalWrite(display1b,LOW);
    digitalWrite(display1c,HIGH);
    digitalWrite(display1d,HIGH);
    digitalWrite(display1e,LOW);
    digitalWrite(display1f,HIGH);
    digitalWrite(display1g,HIGH); 
}

void numeroSeisD1(){
    digitalWrite(display1a,HIGH);
    digitalWrite(display1b,LOW);
    digitalWrite(display1c,HIGH);
    digitalWrite(display1d,HIGH);
    digitalWrite(display1e,HIGH);
    digitalWrite(display1f,HIGH);
    digitalWrite(display1g,HIGH); 
}

void numeroSeteD1(){
    digitalWrite(display1a,HIGH);
    digitalWrite(display1b,HIGH);
    digitalWrite(display1c,HIGH);
    digitalWrite(display1d,LOW);
    digitalWrite(display1e,LOW);
    digitalWrite(display1f,LOW);
    digitalWrite(display1g,LOW); 
}

void numeroOitoD1(){
    digitalWrite(display1a,HIGH);
    digitalWrite(display1b,HIGH);
    digitalWrite(display1c,HIGH);
    digitalWrite(display1d,HIGH);
    digitalWrite(display1e,HIGH);
    digitalWrite(display1f,HIGH);
    digitalWrite(display1g,HIGH); 
}

void numeroNoveD1(){
    digitalWrite(display1a,HIGH);
    digitalWrite(display1b,HIGH);
    digitalWrite(display1c,HIGH);
    digitalWrite(display1d,LOW);
    digitalWrite(display1e,LOW);
    digitalWrite(display1f,HIGH);
    digitalWrite(display1g,HIGH); 
}

void numeroZeroD1(){
    digitalWrite(display1a,HIGH);
    digitalWrite(display1b,HIGH);
    digitalWrite(display1c,HIGH);
    digitalWrite(display1d,HIGH);
    digitalWrite(display1e,HIGH);
    digitalWrite(display1f,HIGH);
    digitalWrite(display1g,LOW); 
}

void numeroUmD2(){
    digitalWrite(display2a,LOW);
    digitalWrite(display2b,HIGH);
    digitalWrite(display2c,HIGH);
    digitalWrite(display2d,LOW);
    digitalWrite(display2e,LOW);
    digitalWrite(display2f,LOW);
    digitalWrite(display2g,LOW); 
}

void numeroDoisD2(){
    digitalWrite(display2a,HIGH);
    digitalWrite(display2b,HIGH);
    digitalWrite(display2c,LOW);
    digitalWrite(display2d,HIGH);
    digitalWrite(display2e,HIGH);
    digitalWrite(display2f,LOW);
    digitalWrite(display2g,HIGH); 
}

void numeroTresD2(){
    digitalWrite(display2a,HIGH);
    digitalWrite(display2b,HIGH);
    digitalWrite(display2c,HIGH);
    digitalWrite(display2d,HIGH);
    digitalWrite(display2e,LOW);
    digitalWrite(display2f,LOW);
    digitalWrite(display2g,HIGH); 
}

void numeroQuatroD2(){
    digitalWrite(display2a,LOW);
    digitalWrite(display2b,HIGH);
    digitalWrite(display2c,HIGH);
    digitalWrite(display2d,LOW);
    digitalWrite(display2e,LOW);
    digitalWrite(display2f,HIGH);
    digitalWrite(display2g,HIGH); 
}

void numeroCincoD2(){
    digitalWrite(display2a,HIGH);
    digitalWrite(display2b,LOW);
    digitalWrite(display2c,HIGH);
    digitalWrite(display2d,HIGH);
    digitalWrite(display2e,LOW);
    digitalWrite(display2f,HIGH);
    digitalWrite(display2g,HIGH); 
}

void numeroSeisD2(){
    digitalWrite(display2a,HIGH);
    digitalWrite(display2b,LOW);
    digitalWrite(display2c,HIGH);
    digitalWrite(display2d,HIGH);
    digitalWrite(display2e,HIGH);
    digitalWrite(display2f,HIGH);
    digitalWrite(display2g,HIGH); 
}

void numeroSeteD2(){
    digitalWrite(display2a,HIGH);
    digitalWrite(display2b,HIGH);
    digitalWrite(display2c,HIGH);
    digitalWrite(display2d,LOW);
    digitalWrite(display2e,LOW);
    digitalWrite(display2f,LOW);
    digitalWrite(display2g,LOW); 
}

void numeroOitoD2(){
    digitalWrite(display2a,HIGH);
    digitalWrite(display2b,HIGH);
    digitalWrite(display2c,HIGH);
    digitalWrite(display2d,HIGH);
    digitalWrite(display2e,HIGH);
    digitalWrite(display2f,HIGH);
    digitalWrite(display2g,HIGH); 
}

void numeroNoveD2(){
    digitalWrite(display2a,HIGH);
    digitalWrite(display2b,HIGH);
    digitalWrite(display2c,HIGH);
    digitalWrite(display2d,LOW);
    digitalWrite(display2e,LOW);
    digitalWrite(display2f,HIGH);
    digitalWrite(display2g,HIGH); 
}

void numeroZeroD2(){
    digitalWrite(display2a,HIGH);
    digitalWrite(display2b,HIGH);
    digitalWrite(display2c,HIGH);
    digitalWrite(display2d,HIGH);
    digitalWrite(display2e,HIGH);
    digitalWrite(display2f,HIGH);
    digitalWrite(display2g,LOW); 
}

void numeroUmD3(){
    digitalWrite(display3a,LOW);
    digitalWrite(display3b,HIGH);
    digitalWrite(display3c,HIGH);
    digitalWrite(display3d,LOW);
    digitalWrite(display3e,LOW);
    digitalWrite(display3f,LOW);
    digitalWrite(display3g,LOW); 
}

void numeroDoisD3(){
    digitalWrite(display3a,HIGH);
    digitalWrite(display3b,HIGH);
    digitalWrite(display3c,LOW);
    digitalWrite(display3d,HIGH);
    digitalWrite(display3e,HIGH);
    digitalWrite(display3f,LOW);
    digitalWrite(display3g,HIGH); 
}

void numeroTresD3(){
    digitalWrite(display3a,HIGH);
    digitalWrite(display3b,HIGH);
    digitalWrite(display3c,HIGH);
    digitalWrite(display3d,HIGH);
    digitalWrite(display3e,LOW);
    digitalWrite(display3f,LOW);
    digitalWrite(display3g,HIGH); 
}

void numeroQuatroD3(){
    digitalWrite(display3a,LOW);
    digitalWrite(display3b,HIGH);
    digitalWrite(display3c,HIGH);
    digitalWrite(display3d,LOW);
    digitalWrite(display3e,LOW);
    digitalWrite(display3f,HIGH);
    digitalWrite(display3g,HIGH); 
}

void numeroCincoD3(){
    digitalWrite(display3a,HIGH);
    digitalWrite(display3b,LOW);
    digitalWrite(display3c,HIGH);
    digitalWrite(display3d,HIGH);
    digitalWrite(display3e,LOW);
    digitalWrite(display3f,HIGH);
    digitalWrite(display3g,HIGH); 
}

void numeroSeisD3(){
    digitalWrite(display3a,HIGH);
    digitalWrite(display3b,LOW);
    digitalWrite(display3c,HIGH);
    digitalWrite(display3d,HIGH);
    digitalWrite(display3e,HIGH);
    digitalWrite(display3f,HIGH);
    digitalWrite(display3g,HIGH); 
}

void numeroSeteD3(){
    digitalWrite(display3a,HIGH);
    digitalWrite(display3b,HIGH);
    digitalWrite(display3c,HIGH);
    digitalWrite(display3d,LOW);
    digitalWrite(display3e,LOW);
    digitalWrite(display3f,LOW);
    digitalWrite(display3g,LOW); 
}

void numeroOitoD3(){
    digitalWrite(display3a,HIGH);
    digitalWrite(display3b,HIGH);
    digitalWrite(display3c,HIGH);
    digitalWrite(display3d,HIGH);
    digitalWrite(display3e,HIGH);
    digitalWrite(display3f,HIGH);
    digitalWrite(display3g,HIGH); 
}

void numeroNoveD3(){
    digitalWrite(display3a,HIGH);
    digitalWrite(display3b,HIGH);
    digitalWrite(display3c,HIGH);
    digitalWrite(display3d,LOW);
    digitalWrite(display3e,LOW);
    digitalWrite(display3f,HIGH);
    digitalWrite(display3g,HIGH); 
}

void numeroZeroD3(){
    digitalWrite(display3a,HIGH);
    digitalWrite(display3b,HIGH);
    digitalWrite(display3c,HIGH);
    digitalWrite(display3d,HIGH);
    digitalWrite(display3e,HIGH);
    digitalWrite(display3f,HIGH);
    digitalWrite(display3g,LOW); 
}

void numeroUmD4(){
    digitalWrite(display4a,LOW);
    digitalWrite(display4b,HIGH);
    digitalWrite(display4c,HIGH);
    digitalWrite(display4d,LOW);
    digitalWrite(display4e,LOW);
    digitalWrite(display4f,LOW);
    digitalWrite(display4g,LOW); 
}

void numeroDoisD4(){
    digitalWrite(display4a,HIGH);
    digitalWrite(display4b,HIGH);
    digitalWrite(display4c,LOW);
    digitalWrite(display4d,HIGH);
    digitalWrite(display4e,HIGH);
    digitalWrite(display4f,LOW);
    digitalWrite(display4g,HIGH); 
}

void numeroTresD4(){
    digitalWrite(display4a,HIGH);
    digitalWrite(display4b,HIGH);
    digitalWrite(display4c,HIGH);
    digitalWrite(display4d,HIGH);
    digitalWrite(display4e,LOW);
    digitalWrite(display4f,LOW);
    digitalWrite(display4g,HIGH); 
}

void numeroQuatroD4(){
    digitalWrite(display4a,LOW);
    digitalWrite(display4b,HIGH);
    digitalWrite(display4c,HIGH);
    digitalWrite(display4d,LOW);
    digitalWrite(display4e,LOW);
    digitalWrite(display4f,HIGH);
    digitalWrite(display4g,HIGH); 
}

void numeroCincoD4(){
    digitalWrite(display4a,HIGH);
    digitalWrite(display4b,LOW);
    digitalWrite(display4c,HIGH);
    digitalWrite(display4d,HIGH);
    digitalWrite(display4e,LOW);
    digitalWrite(display4f,HIGH);
    digitalWrite(display4g,HIGH); 
}

void numeroSeisD4(){
    digitalWrite(display4a,HIGH);
    digitalWrite(display4b,LOW);
    digitalWrite(display4c,HIGH);
    digitalWrite(display4d,HIGH);
    digitalWrite(display4e,HIGH);
    digitalWrite(display4f,HIGH);
    digitalWrite(display4g,HIGH); 
}

void numeroSeteD4(){
    digitalWrite(display4a,HIGH);
    digitalWrite(display4b,HIGH);
    digitalWrite(display4c,HIGH);
    digitalWrite(display4d,LOW);
    digitalWrite(display4e,LOW);
    digitalWrite(display4f,LOW);
    digitalWrite(display4g,LOW); 
}

void numeroOitoD4(){
    digitalWrite(display4a,HIGH);
    digitalWrite(display4b,HIGH);
    digitalWrite(display4c,HIGH);
    digitalWrite(display4d,HIGH);
    digitalWrite(display4e,HIGH);
    digitalWrite(display4f,HIGH);
    digitalWrite(display4g,HIGH); 
}

void numeroNoveD4(){
    digitalWrite(display4a,HIGH);
    digitalWrite(display4b,HIGH);
    digitalWrite(display4c,HIGH);
    digitalWrite(display4d,LOW);
    digitalWrite(display4e,LOW);
    digitalWrite(display4f,HIGH);
    digitalWrite(display4g,HIGH); 
}

void numeroZeroD4(){
    digitalWrite(display4a,HIGH);
    digitalWrite(display4b,HIGH);
    digitalWrite(display4c,HIGH);
    digitalWrite(display4d,HIGH);
    digitalWrite(display4e,HIGH);
    digitalWrite(display4f,HIGH);
    digitalWrite(display4g,LOW); 
}



