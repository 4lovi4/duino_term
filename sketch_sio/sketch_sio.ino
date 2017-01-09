
//***//
int led_pin = 13,
    count = 0;
    
void setup() 
{
  pinMode(led_pin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(led_pin, HIGH);
  Serial.println("PING?");
  delay(1000);
  digitalWrite(led_pin, LOW);
  
}
