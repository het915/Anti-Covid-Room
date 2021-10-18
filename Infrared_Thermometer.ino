#include <Wire.h>
#include <Adafruit_MLX90614.h> 
Adafruit_MLX90614 mlx = Adafruit_MLX90614(); 
int IR_Sensor=2;
int gled=3; 
int rled=4; 
int data;
void setup() 
{ 
Serial.begin(9600);
Serial.println("Adafruit MLX90614 test");
mlx.begin();
pinMode(IR_Sensor,INPUT); //
}
void loop() {

int data=digitalRead(IR_Sensor); 
if(data==1){
Serial.print("C\tObject="); 
Serial.print(mlx.readObjectTempC());
Serial.println("C");
delay(500);
 }
if (mlx.readObjectTempC()>=37.8){ 
  digitalWrite(rled.HIGH); 
  digitalWrite(gled,LOW);
}
else{ digitalWrite(gled,HIGH); 
      digitalWrite(rled,LOW);
}
}
