  
const int Sensor = A0;
int sensorReading = 0;      // Stores the value read from the sensor pin          
int washer = 0;             //Is the washer running? 
int spin = 0;
int isdone = 0;
void setup() 
{
  Serial.begin(115200);       // use the serial port
  
}

void loop() 
{
  sensorReading = analogRead(Sensor); 
  if(sensorReading >= 3)
  {
    washer = 1;
    Serial.println("c");
  }
    while(washer == 1)
    {
     float sum = 0;     //the sum of all the data over a cirtain amaount of time. 
     float oneup = 0;   //number to track what to devide the average by. 
    
     for(int i = 0; i < 400; i++)
     { 
        sensorReading = analogRead(Sensor); 
        if (sensorReading >= 1)
        { 
         isdone = 0;    //number to track if its done or not.
         sum = sum + sensorReading;
         oneup = oneup + 1;
         if (sensorReading >= 400)
         {
          spin = 1;
          }
        }
        delay(100);
      }
      
      if(sum != 0)
      {
        Serial.println(sum / oneup);
      }
      else
      {
        if(spin == 1)
        {
        isdone = isdone + 1;
        Serial.println(isdone);
        delay(50);
        Serial.println("Done yet?");
        if(isdone == 4)
        {
          delay(50);
          Serial.println("d");
          washer = 0;
        }
      }  
      }
    delay(15000);  // check every 15 seconds
    }
      
  delay(100);
}  
