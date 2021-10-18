#include <WiFi.h>
#include <ThingSpeak.h>
WiFiClient client;

long myChannelNumber = 1415680;
const char myWriteAPIKey[] = "J7RQNCP5RK849CG2";

int ldr1=2;
int ldr2=4; 
int count =0;
int total_count=0;
int g_led=13;
int r_led=16;
int bldr_value=800;
int ldr1_value,ldr2_value;
int govt_count=10;

void setup() {
 Serial.begin(115200);

 
 WiFi.begin("SSID", "PASS");
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print("..");
  }
  Serial.println();
  Serial.println("NodeMCU is connected!");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);
  
  pinMode(ldr1,INPUT);
  pinMode(ldr2,INPUT);

  pinMode(r_led,OUTPUT);
  pinMode(g_led,OUTPUT);
  
}

void loop() {
ldr1_value = analogRead(ldr1);
ldr2_value = analogRead(ldr2);

if(ldr1_value>bldr_value)
    {
      for(int i=0;i<300;i++)
       {
          if(ldr2_value>bldr_value)
            {
              count = count + 1 ;
              Serial.println(count);
              break;
            }
        delay(1);
       }
    }

  else if(ldr2_value>bldr_value)
    {
      for(int i=0;i<300;i++)
       {
          if(ldr1_value>bldr_value)
            {
              count = count - 1;
              Serial.println(count);
              break;
            }
        delay(1);
       }
    }

   
if (govt_count>=count)
{
  digitalWrite(g_led,HIGH);
  digitalWrite(r_led,LOW);
}
else
{
  digitalWrite(r_led,HIGH);
  digitalWrite(g_led,LOW);
}


ThingSpeak.writeField(myChannelNumber, 1, count, myWriteAPIKey);

delay(2000);
}
