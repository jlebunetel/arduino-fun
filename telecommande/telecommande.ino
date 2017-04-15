// ce programme ne fait qu'envoyer sur le port série toute commande reçue par le recepteur IR

// fonctionne avec la librairie IRremote by shirriff Version 2.0.1
// https://github.com/z3t0/Arduino-IRremote

#include <IRremote.h>
const int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  // la pin 13 est utilisée pour alimenter le récepteur
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  // Start the receiver
  irrecv.enableIRIn();

  Serial.begin(115200);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
