#define LED_PIN LED_BUILTIN

void setupLed()
{
  pinMode(LED_PIN, OUTPUT);
}

void setLed(bool state)
{
  if(state)
  {
    digitalWrite(LED_PIN, HIGH);
  }
  else
  {
    digitalWrite(LED_PIN, LOW);
  }
}
