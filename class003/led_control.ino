//KODA NA MORETI I HRISTO E NAJ-DOBRIQ!!!!!
//BQHME PYRVI!
//COPYRIGHT 2015
//ALL RIGHTS RESERVERD!!!
int R = 0;
int T = 0; 

void setup(){
  Serial.begin(9600);
}
void loop(){
  R = analogRead(1);
  T = map(R, 0,1023,0,100);
  Serial.println(T);
  led_up(80,100,T,11);
  led_ctrl(10,50,T,6);
  led_ctrl(30,70,T,9);
  led_ctrl(50,90,T,10); 
  led_down(0,20,T,5);
  delay(100);
  
}
void led_up(int mint, int maxt, int tmp, int pin){
  int d = maxt-mint;
  int stp = 255/d;
  int pos = tmp - mint;
  analogWrite(pin, pos*stp);
  if(tmp>maxt || tmp < mint){
  pinMode(pin,INPUT); 
 }
}
void led_down(int mint, int maxt, int tmp, int pin){
  int d = maxt-mint;
  int stp = 255/d;
  int pos = tmp - mint;
  analogWrite(pin, 255 - pos*stp);
  if(tmp>maxt || tmp < mint){
  pinMode(pin,INPUT); 
 }
}
void led_ctrl(int mint, int maxt, int tmp, int pin){
  int d = maxt-mint;
  int stp = 255/d;
  int pos = tmp-mint;
  int avg = (maxt+mint)/2;
  if(tmp<avg){
    analogWrite(pin,stp*pos*2);
  }else{
    analogWrite(pin,255-stp*pos*2);
  }
      if(tmp>maxt || tmp < mint){
  pinMode(pin,INPUT); 
      }
}
