

const int botao = 23;
int estadoBotao = 0;

int cont = 0;



void setup(){
  
  Serial.begin(9600);
  
  pinMode(botao,INPUT);
  
  digitalWrite(botao,1); 
  
}

void loop(){
  
  int estadoBotao = digitalRead(botao);
  
  if(estadoBotao == 0){
    
    Serial.print("Botao Apertado! [");
    Serial.print(cont);
    Serial.print("x]\n\n");
    
    cont++;
    
    delay(200);
    
  }
  
  
}
