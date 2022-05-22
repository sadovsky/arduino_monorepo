// Blinking LED
const int LED = 13; // LED connected to digital pin 13

void setup()
{
    pinMode(LED, OUTPUT); // sets the digital pin as output
}

void led_random(uint8_t pin, uint8_t val)
{
    long sleep = random(500,3500);
    digitalWrite(pin,val); // turns the LED on
    delay(sleep); // waits 
}

void loop()
{
    led_random(LED,HIGH);
    led_random(LED,LOW);
}