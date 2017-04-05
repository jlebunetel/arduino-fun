

int latchPin = 10;
int clockPin = 8;
int outputEnablePin = 9;
int dataPin = 2;
int APin = 6;



byte data = B10100100;

void setup() {
  // put your setup code here, to run once:
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(outputEnablePin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(APin, OUTPUT);

  digitalWrite(latchPin, LOW);
  digitalWrite(clockPin, LOW);
  digitalWrite(outputEnablePin, LOW);
  digitalWrite(dataPin, LOW);
  digitalWrite(APin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(APin, LOW);
  digitalWrite(outputEnablePin, HIGH);

  shiftOut(dataPin, clockPin, LSBFIRST, B10100100);

  digitalWrite(latchPin, HIGH);
  digitalWrite(latchPin, LOW);

  digitalWrite(outputEnablePin, LOW);

  delay(5);



  digitalWrite(APin, HIGH);
  digitalWrite(outputEnablePin, HIGH);

//  shiftOut(dataPin, clockPin, LSBFIRST, B01010001);


  digitalWrite(dataPin, HIGH);

  digitalWrite(clockPin, HIGH);
  digitalWrite(clockPin, LOW);

  digitalWrite(dataPin, LOW);

  digitalWrite(clockPin, HIGH);
  digitalWrite(clockPin, LOW);

  digitalWrite(clockPin, HIGH);
  digitalWrite(clockPin, LOW);

  digitalWrite(clockPin, HIGH);
  digitalWrite(clockPin, LOW);
  


  digitalWrite(latchPin, HIGH);
  digitalWrite(latchPin, LOW);

  digitalWrite(outputEnablePin, LOW);

  delay(5);

/*
  for (int i=0; i <= 100; i++){
    digitalWrite(outputEnablePin, HIGH);
    digitalWrite(APin, HIGH);
    delay(1);
    digitalWrite(outputEnablePin, LOW);
    digitalWrite(APin, LOW);
    delay(1);

  }*/
}
