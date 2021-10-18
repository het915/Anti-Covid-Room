#define echoPin 4              // defining pins and variables
#define trigPin 5
int long duration;  
int distance;
 
const int motor= 10;          // pin connected to base of npn transistor
 
void setup()
{
  pinMode(echoPin,INPUT);     // defining pin modes
  pinMode(trigPin,OUTPUT); 
  pinMode(motor, OUTPUT);     
}
void loop()
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=(duration*0.034/2);   // now you got the distance
 
  if(distance<=5
  )             // checking the presence of hands in 20 cm limit
  { 
  digitalWrite(motor,HIGH); // if present motor operates for some time
  }
  else
  {
  digitalWrite(motor,LOW);  // if no hands detected - no operation
  }
}
