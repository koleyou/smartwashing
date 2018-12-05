  
const int Sensor = A0;
int sensorReading = 0;      // variable to store the value read from the sensor pin          
int washer = 0;
void setup() 
{
  Serial.begin(9600);       // use the serial port
  
}

void loop() 
{
  sensorReading = analogRead(Sensor); 
  if(sensorReading > 2)
    washer = 1;
    int isdone = 0;
    while(washer == 1)
    {
     float sum = 0;     //the sum of all the data over a cirtain amaount of time. 
     float oneup = 0;   //number to track what to devide the average by. 
    
     for(int i = 0; i < 600; i++)
     { 
        sensorReading = analogRead(Sensor); 
        if (sensorReading >= 1)
        { 
         isdone = 0;    //number to track if its done or not.
         sum = sum + sensorReading;
         oneup = oneup + 1;
        }
        delay(100);
      }
      
      if(sum != 0)
      {
        Serial.println(sum / oneup);
      }
      else
      {
        isdone = isdone + 1;
        Serial.println(isdone);
        delay(50);
        Serial.println("done yet?");
        if(isdone == 4)
        {
          delay(50);
          Serial.println("washer done");
          washer = 0;
        }
      }  
    delay(15000);  // check every 30 seconds
    }
      
  delay(100);
}  
