int TRIG= 12;
int ECHO= 11; 
int ButtonPin= 13;
int btnnew;
int btnold=1;
int state=0;
#define buzzer A0
#define LED 10 
int run = false;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(ButtonPin,INPUT_PULLUP);
}
void loop(){
  btnnew=digitalRead(ButtonPin);
  long duration;
  int distance;
  btnnew=digitalRead(ButtonPin);
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  duration = pulseIn (ECHO, HIGH);
  distance = duration * 17 / 1000; 
  if(distance>10){
    if(state==0){
      tone(buzzer,100);
      digitalWrite(LED,HIGH);
      }
    else{
      noTone(buzzer);
      digitalWrite(LED,LOW);
      }
    if(btnold==0&&btnnew==1){
      Serial.println("T");
      if(state==0){
        Serial.println("Q") ;
        digitalWrite(LED,HIGH);
        state=1;
        }
      else{
        Serial.println("W");
        digitalWrite(LED,LOW);
        state=0;
        }
    }
    btnold=btnnew;
    delay(100);
  }
  else{
    Serial.println("E");
    noTone(A0);  
  }  
}
