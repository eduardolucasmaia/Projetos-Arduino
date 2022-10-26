const int botaoD1 = 30;
int estadobotaoD1;

int contBotaoD1 = 0;
int contBotaoD2 = 0;
int contBotaoD3 = 0;
int contBotaoD4 = 0;

const int display1a = 22;
const int display1b = 23;
const int display1c = 24;
const int display1d = 25;
const int display1e = 26;
const int display1f = 27;
const int display1g = 28;

const int botaoClean = 6;
int estadobotaoClean;

const int ledErro = 5;

void setup(){
  
  pinMode(display1a,OUTPUT);
  pinMode(display1b,OUTPUT);
  pinMode(display1c,OUTPUT);
  pinMode(display1d,OUTPUT);
  pinMode(display1e,OUTPUT);
  pinMode(display1f,OUTPUT);
  pinMode(display1g,OUTPUT);

  pinMode(botaoD1,INPUT);
  
  pinMode(botaoClean,INPUT);

  digitalWrite(botaoD1,HIGH); 
  
  digitalWrite(botaoClean,HIGH);
  
  pinMode(ledErro,OUTPUT);


}

void loop(){
  
  int estadobotaoClean = digitalRead(botaoClean);

  if (estadobotaoClean == LOW){
    delay(200);    
    if(contBotaoD1 == 0){
    digitalWrite(ledErro,HIGH);
    delay(1000);
    digitalWrite(ledErro,LOW);
    }
    else { 
    contBotaoD1 = 0;
    contBotaoD2 = 0;
    contBotaoD3 = 0;
    contBotaoD4 = 0;  
    }
  }
      
  
 int estadobotaoD1 = digitalRead(botaoD1);
  
 if (estadobotaoD1 == LOW){
    contBotaoD1 ++;  
    delay(200);
  }

if (contBotaoD1 == 10){
    contBotaoD1 = 0;
  }
  
  if (contBotaoD1 == 0){
    numeroZeroD1();
    digitalWrite(botaoD1,HIGH);
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




