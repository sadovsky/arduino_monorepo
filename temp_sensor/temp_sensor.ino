const int sensor_pin = A0;
const float baseline_temp = 19.5; //ambient room temp

void setup()
{
    Serial.begin(9600); 

    for(int i=2;i<=4;i++) //pins 2-4
    {
         pinMode(i,OUTPUT);
         digitalWrite(i,LOW);
    }
}

void loop()
{
    int sensor_val = analogRead(sensor_pin);
    
    Serial.println("Sensor value:\t" + String(sensor_val));

    float v = (sensor_val/1024.0)*5.0;
    Serial.println("Volts:\t\t\t" + String(v));

    float t = (v-.5) * 100;
    Serial.println("Temp:\t\t\t" + String(t) + " *C");

    if(t<baseline_temp+1)
    {
        digitalWrite(2,LOW);
        digitalWrite(3,LOW);
        digitalWrite(4,LOW);
    }
    else if(t>=baseline_temp+1 && t<baseline_temp+2)
    {
        digitalWrite(2,HIGH);
        digitalWrite(3,LOW);
        digitalWrite(4,LOW);
    }
    else if (t>=baseline_temp+2 && t<baseline_temp+3)
    {
        digitalWrite(2,HIGH);
        digitalWrite(3,HIGH);
        digitalWrite(4,LOW);
    }
    else if(t>baseline_temp+3)
    {
        digitalWrite(2,HIGH);
        digitalWrite(3,HIGH);
        digitalWrite(4,HIGH);
    }
    
    delay(1);
}