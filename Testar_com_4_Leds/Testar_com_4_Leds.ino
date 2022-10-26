const int led01 = 22;
const int led02 = 23;
const int led03 = 24;
const int led04 = 25;

int botao = 30;
int estadoBotao;

int contador;

void setup(){
  
  pinMode(led01,OUTPUT);
  pinMode(led02,OUTPUT);
  pinMode(led03,OUTPUT);
  pinMode(led04,OUTPUT);
  
  pinMode(botao,INPUT);
  
  digitalWrite(botao,1);
  
  
}


void loop(){
  
  int estadoBotao = digitalRead(botao);
  
  if(estadoBotao == 0){
    
    contador++;
    
    delay(200);
    
    
  }

  
  if(contador == 17){
    
    contador = 0;
    
  }
  
    if(contador == 0){
    
    digitalWrite(led01,LOW);
    digitalWrite(led02,LOW);
    digitalWrite(led03,LOW);
    digitalWrite(led04,LOW);
    
  }
  
  if(contador == 1){
    
    digitalWrite(led01,HIGH);
    digitalWrite(led02,LOW);
    digitalWrite(led03,LOW);
    digitalWrite(led04,LOW);
    
  }
  
    if(contador == 2){
    
    digitalWrite(led01,LOW);
    digitalWrite(led02,HIGH);
    digitalWrite(led03,LOW);
    digitalWrite(led04,LOW);
    
  }
  
    if(contador == 3){
    
    digitalWrite(led01,HIGH);
    digitalWrite(led02,HIGH);
    digitalWrite(led03,LOW);
    digitalWrite(led04,LOW);
    
  }
  
    if(contador == 4){
    
    digitalWrite(led01,LOW);
    digitalWrite(led02,LOW);
    digitalWrite(led03,HIGH);
    digitalWrite(led04,LOW);
    
  }
  
  if(contador == 5){
    
    digitalWrite(led01,HIGH);
    digitalWrite(led02,LOW);
    digitalWrite(led03,HIGH);
    digitalWrite(led04,LOW);
    
  }
  
  if(contador == 6){
    
    digitalWrite(led01,LOW);
    digitalWrite(led02,HIGH);
    digitalWrite(led03,HIGH);
    digitalWrite(led04,LOW);
    
  }
  
  if(contador == 7){
    
    digitalWrite(led01,HIGH);
    digitalWrite(led02,HIGH);
    digitalWrite(led03,HIGH);
    digitalWrite(led04,LOW);
    
  }
  
  if(contador == 8){
    
    digitalWrite(led01,LOW);
    digitalWrite(led02,LOW);
    digitalWrite(led03,LOW);
    digitalWrite(led04,HIGH);
    
  }
  
  if(contador == 9){
    
    digitalWrite(led01,HIGH);
    digitalWrite(led02,LOW);
    digitalWrite(led03,LOW);
    digitalWrite(led04,HIGH);
    
  }
  
  if(contador == 10){
    
    digitalWrite(led01,HIGH);
    digitalWrite(led02,LOW);
    digitalWrite(led03,LOW);
    digitalWrite(led04,HIGH);
    
  }
  
  if(contador == 11){
    
    digitalWrite(led01,LOW);
    digitalWrite(led02,HIGH);
    digitalWrite(led03,LOW);
    digitalWrite(led04,HIGH);
    
  }
  
  if(contador == 12){
    
    digitalWrite(led01,HIGH);
    digitalWrite(led02,HIGH);
    digitalWrite(led03,LOW);
    digitalWrite(led04,HIGH);
    
  }
  
  if(contador == 13){
    
    digitalWrite(led01,LOW);
    digitalWrite(led02,LOW);
    digitalWrite(led03,HIGH);
    digitalWrite(led04,HIGH);
    
  }
  
  if(contador == 14){
    
    digitalWrite(led01,HIGH);
    digitalWrite(led02,LOW);
    digitalWrite(led03,HIGH);
    digitalWrite(led04,HIGH);
    
  }
  
  if(contador == 15){
    
    digitalWrite(led01,LOW);
    digitalWrite(led02,HIGH);
    digitalWrite(led03,HIGH);
    digitalWrite(led04,HIGH);
    
  }
  
  if(contador == 16){
    
    digitalWrite(led01,HIGH);
    digitalWrite(led02,HIGH);
    digitalWrite(led03,HIGH);
    digitalWrite(led04,HIGH);
    
  }
  
  
  
}
