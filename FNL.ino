

float wheel_dia=34; //    # mm (increase = spiral out)
float wheel_base=230; //    # mm (increase = spiral in, ccw) 
int steps_rev=3200; //        # 512 for 64x gearbox, 128 for 16x gearbox
int delay_time=1; //         # time between steps in ms

void setup() {
  pinMode(8, OUTPUT); //dirction(left frnt tyre )    
  pinMode(9, OUTPUT); // step(left frnt tyre )
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
 
   
  pinMode(6, OUTPUT); // direction(right frnt tyre)    
  pinMode(7, OUTPUT);// step (right back tyre)
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
   pinMode(3, OUTPUT);    
  pinMode(4, OUTPUT);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  randomSeed(analogRead(1)); 
  Serial.begin(9600);
  
  
  
  Serial.println("setup");
  
  penup(0);
  
  delay(1000);

}
void loop(){ // draw a calibration box 4 times

 { 
  pendown(20);
  backward(100);
  penup(20); 
  left(18);
  pendown(20);
  backward(50);
  penup(20);
  left(18);
  pendown(20);
  backward(100);
  penup(20);
  left(18);
  pendown(20); 
  backward(50);
  penup(20);
  left(18);
  done();      // releases stepper motor
  while(1);    // wait for reset
}
}
// ----- HELPER FUNCTIONS -----------
int step(float distance){
int steps = distance * steps_rev / (wheel_dia * 3.1412); //24.61
  
  Serial.print(distance);
  Serial.print(" ");
  Serial.print(steps_rev);
  Serial.print(" ");  
  Serial.print(wheel_dia);
  Serial.print(" ");  
  Serial.println(steps);
  delay(1000);
  return steps;  
}
void penup(float distance){
  int steps = step(distance);
  Serial.println(steps);
  digitalWrite(3, LOW);
  
  for(int step=0; step<steps; step++){
  { 
   digitalWrite(4, HIGH);
    delayMicroseconds(1000);
    digitalWrite(4, LOW);
    delayMicroseconds(1000);
     }
      delay(delay_time);
    } 
  }void pendown(float distance){
  int steps = step(distance);
  Serial.println(steps);
  digitalWrite(3, HIGH);
  
  for(int step=0; step<steps; step++){
  { 
   digitalWrite(4, HIGH);
    delayMicroseconds(1000);
    digitalWrite(4, LOW);
    delayMicroseconds(1000);
     }
      delay(delay_time);
    } 
  }
void backward(float distance){
int steps = step(distance);
digitalWrite(8, HIGH);
digitalWrite(6, LOW);

  for(int step=0; step<steps; step++){
  {
   digitalWrite(9, HIGH);
    delayMicroseconds(700);
    digitalWrite(9, LOW);
    delayMicroseconds(700);
    digitalWrite(7, HIGH);
    delayMicroseconds(700);
    digitalWrite(7, LOW);
    delayMicroseconds(700);
   
 
   }     
     delay(delay_time);
    } 
  }

void right(float degrees){
  float rotation = degrees / 360.0;
  float distance = wheel_base * 3.1412 * rotation;
  int steps = step(distance);
  digitalWrite(8,LOW); 
  digitalWrite(6,LOW);
  
  for(int step=0; step<steps; step++){
{
    digitalWrite(9, HIGH);
    delayMicroseconds(700);
    digitalWrite(9, LOW);
    delayMicroseconds(700);
    digitalWrite(7, HIGH);
    delayMicroseconds(700);
    digitalWrite(7, LOW);
    delayMicroseconds(700);
   
  }     
     delay(delay_time);
      } 
  }   
void left(float degrees){
  float rotation = degrees / 360.0;
  float distance = wheel_base * 3.1412 * rotation;
  int steps = step(distance);
  digitalWrite(8, LOW);
  digitalWrite(6, LOW);
  
  for(int step=0; step<steps; step++){
{ 
   digitalWrite(9, HIGH);
    delayMicroseconds(700);
    digitalWrite(9, LOW);
    delayMicroseconds(700);
    digitalWrite(7, LOW);
    delayMicroseconds(700);
    digitalWrite(7, LOW);
    delayMicroseconds(700);
   

    }     
     delay(delay_time);
      } 
  }   
void done(){ // unlock stepper to save battery  
{
 digitalWrite(8, LOW); 
 digitalWrite(9, LOW);;
 digitalWrite(6, LOW); 
 digitalWrite(7, LOW);;
 
 digitalWrite(3, LOW); 
 digitalWrite(4, LOW);;
    }
    delay(delay_time);
  }


