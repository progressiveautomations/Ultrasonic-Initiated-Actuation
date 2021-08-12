// Created by Gunider M. August 11, 2021//

//pin assignment
int PWM_A = 11; 
int PWM_B = 10;
int EnablePin1 = 12;
const byte Megamoto_current= A5; 
const int Trig_Pin = 35;
const int Echo_Pin = 40;   

//defining values
long Distance_value;
int CRaw1;      
int Previous_CRaw;
int CRawAvg;

void setup() {
  //MegaMoto
  Serial.begin(9600);
  pinMode(Trig_Pin, OUTPUT);
  pinMode(Echo_Pin, INPUT);
  pinMode(Megamoto_current, INPUT);
  pinMode(PWM_A, OUTPUT);
  pinMode(PWM_B, OUTPUT);
  pinMode(EnablePin1, OUTPUT);
  digitalWrite(EnablePin1, HIGH); //enable the board

  
}

void loop() {

  Distance();
  Distance_value = Distance();

  if (Distance_value < 12) {
    Previous_CRaw = analogRead(Megamoto_current);
    digitalWrite(PWM_A, HIGH); digitalWrite(PWM_B, LOW); //Extend
   
    
    DataAvg();
    CRawAvg = DataAvg();
    if (CRawAvg > Previous_CRaw+15 || CRawAvg < Previous_CRaw-15){
      do {
        DataAvg();
        CRawAvg = DataAvg();
        }while (CRawAvg > Previous_CRaw+15 || CRawAvg < Previous_CRaw-15);
    }
    delay(3000);

    Previous_CRaw = analogRead(Megamoto_current);
    digitalWrite(PWM_A, LOW); digitalWrite(PWM_B, HIGH); //Retract
   
    
    DataAvg();
    CRawAvg = DataAvg();
    if (CRawAvg > Previous_CRaw+15 || CRawAvg < Previous_CRaw-15){
      do {
        DataAvg();
        CRawAvg = DataAvg();
        Distance();
        Distance_value = Distance();
        if (Distance_value < 12){
          break;
        }
        }while (CRawAvg > Previous_CRaw+15 || CRawAvg < Previous_CRaw-15);
    }
    
    
    
  }

  else{
    
  }
  

}


int DataAvg()
{
  int i;
  int valueAvg = 0;
  
  for (int i=0; i<10; i++){
      CRaw1 = analogRead(Megamoto_current);
      valueAvg = valueAvg + CRaw1;
      delay(10);
     
    }
    valueAvg = valueAvg/10;
    return valueAvg;
}

int Distance()
{
  int internal_distance;
  digitalWrite(Trig_Pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_Pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_Pin, LOW);
  internal_distance = pulseIn(Echo_Pin, HIGH)/148;
  Serial.println(internal_distance);
  delay(100);

  return internal_distance;
}
