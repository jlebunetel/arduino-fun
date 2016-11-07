// blink led on pin 13 using port definition
// 10 time faster than digitalWrite() !!!!

// pin 13 is connected on port B, pin 5
#define LED_ON PORTB |= (1<<5)
#define LED_OFF PORTB &=~ (1<<5)

void setup() {
  // data pin
  pinMode(13, OUTPUT);
}

void loop() {
  LED_ON;
  delay(1000);
  LED_OFF;
  delay(1000);
}
