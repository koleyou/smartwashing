  
const int Sensor = A0;
int sensorReading = 0;      // Stores the value read from the sensor pin          
int washer = 0;             //Is the washer running? 
int spin = 0;               //has the washer doen the spin cylce
int isdone = 0;             //is the washer done
void setup() 
{
  Serial.begin(115200);       // use the serial port
  
}

void loop() 
{
  sensorReading = analogRead(Sensor); 
  if(sensorReading > 2)              //sense when whasher has started.
  {
    washer = 1;                      //set washer to one to start the rest of code.
    Serial.println("cycle start");
  }
    while(washer == 1)
    {
     float sum = 0;     //the sum of all the data over a cirtain amaount of time. 
     float oneup = 0;   //number to track what to divide the average by. 
    
     for(int i = 0; i < 600; i++)
     { 
        sensorReading = analogRead(Sensor); 
        if (sensorReading >= 1)             // don't count any 0's
        { 
         isdone = 0;                        //number to track if its done or not.
         sum = sum + sensorReading;         // add up all the sensor readings
         oneup = oneup + 1;                 //number to divide the sum by to get average.
         if (sensorReading >= 400)          //logic to tell if spin cylce has occured. 
         {
          spin = 1;
          }
        }
        delay(100);
      }
      
      if(sum != 0)                         
      {
        Serial.println(sum / oneup);     // sends the average over serial port.
      }
      else
      {
        if(spin == 1)
        {
        isdone = isdone + 1;
        Serial.println(isdone);
        delay(50);
        Serial.println("done yet?");
        if(isdone == 4)
        {
          delay(50);
          Serial.println("washer done");  // send washer done over serial which the wifi board will interpret and send a message. 
          washer = 0;                     // Reset the program to washer off. 
        }
      }  
      }
    delay(100);  // check every 15 seconds
    }
      
  delay(100);
}  
