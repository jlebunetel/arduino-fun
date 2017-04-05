// librairies
#include <Arduino.h>
#include "MIDI.h"
#include "Bouton.h"
#include "Potentiometre.h"
#include "Led.h"


// SparkFun MIDI Shield

// création des objets potentiomètre
Potentiometre potRouge("potentiometre rouge", 0, 120, 240); // name, pin, minValue, maxValue
Potentiometre potVert("potentiometre vert", 1, 0, 10); // name, pin, minValue, maxValue

// création des objets bouton
Bouton boutonD2("bouton D2", 2, HIGH, true); // nom, broche, valeur par défaut, pullup activé
Bouton boutonD3("bouton D3", 3, HIGH, true); // nom, broche, valeur par défaut, pullup activé
Bouton boutonD4("bouton D4", 4, HIGH, true); // nom, broche, valeur par défaut, pullup activé

// leds
Led led13("led 13");
Led ledVerte("led verte", 6, LOW);
Led ledRouge("led rouge", 7, LOW);

int tempo = 120; // nombre de croche à la minute
int croche = 60000 / tempo;

int channel = 9; // de 0 à 15 pour les canaux midi de 1 à 16

int pitch [6] = {
  46, // orange Hi-Hat Open
  49, // jaune  Crash Cymbal 1
  38, // rouge  Snare M
  48, // bleu   Mid Tom H
  45, // vert   Low Tom
  36, // noir   Bass Drum
};

class Sequence {
  public:

    byte pitch[6];
    int suivant;

    // contructeur
    Sequence(int suivant, byte orange, byte jaune, byte rouge, byte bleu, byte vert, byte noir) {
      this->orange = orange;
      this->jaune = jaune;
      this->rouge = rouge;
      this->bleu = bleu;
      this->vert = vert;
      this->noir = noir;

      pitch[0] = orange;
      pitch[1] = jaune;
      pitch[2] = rouge;
      pitch[3] = bleu;
      pitch[4] = vert;
      pitch[5] = noir;

      this->suivant = suivant;
    };

  private:

    byte orange;
    byte jaune;
    byte rouge;
    byte bleu;
    byte vert;
    byte noir;

};


const int nombre_de_sequences = 10;
int choix = 0;


Sequence sequence[nombre_de_sequences] = {
  Sequence(
    0,
    B00000000,
    B00000000,
    B00100010,
    B00000000,
    B00000000,
    B11011000
  ),
  Sequence(
    0,
    B10101010,
    B00000000,
    B00100010,
    B00000000,
    B00000000,
    B11011000
  ),
  Sequence(
    0,
    B00000000,
    B00000000,
    B00100010,
    B10010010,
    B01010101,
    B11011000
  ),
  Sequence(
    0,
    B10101010,
    B00000000,
    B00100010,
    B10010010,
    B01010101,
    B11011000
  ),
  Sequence(
    1,
    B00000000,
    B00000000,
    B00100010,
    B00000000,
    B00000000,
    B10010000
  ),
  Sequence(
    -1,
    B00000000,
    B00000000,
    B00100010,
    B00000000,
    B00000000,
    B10011000
  ),
  Sequence(
    1,
    B10000000,
    B00000000,
    B01000010,
    B00000000,
    B00000000,
    B10010100
  ),
  Sequence(
    -1,
    B00000000,
    B00000000,
    B00010010,
    B00000000,
    B00000000,
    B11001100
  ),
  Sequence(
    1,
    B10000000,
    B00000000,
    B00100010,
    B00000000,
    B00000000,
    B10010100
  ),
  Sequence(
    -1,
    B00000000,
    B00000000,
    B00100010,
    B00000000,
    B00000000,
    B01010100
  )
};



void setup() {
  // initialisation des boutons
  boutonD2.initialize();
  boutonD3.initialize();
  boutonD4.initialize();

  // initialisation des Leds
  led13.initialize();
  ledVerte.initialize();
  ledRouge.initialize();

  // initialisation de la communication série
  Serial.begin(31250); // vitesse de la norme MIDI
  //Serial.begin(115200); // vitesse de ttyMIDI
}

void loop() {

  for (int i = 0; i < 8; i++) {


    boutonD2.read();
    if (boutonD2.isJustPressed()) {
      pause();
    }

    boutonD3.read();
    if (boutonD3.isJustPressed()) {
      selection = 1;
      if (choix == nombre_de_sequences) {
        choix = 0;
      }
    }

    boutonD4.read();
    if (boutonD4.isJustPressed()) {
      selection = -1;
      if (choix < 0) {
        choix = nombre_de_sequences - 1;
      }
    }

    ledRouge.change();

    for (int j = 0; j < 6 ; j++) {
      if ((sequence[choix].pitch[j] >> (7 - i)) & B1) {
        noteOn(channel, pitch[j]);
      }
    }

    tempo = potRouge.read();
    croche = 60000 / tempo;
    delay(croche);
  }

  choix = choix + selection;
  

  
  choix = choix + sequence[choix].suivant;
}

int pause() {
  while (1) {
    ledVerte.change();
    delay(100);
    boutonD2.read();
    if (boutonD2.isJustPressed()) {
      ledVerte.off();
      return 0;
    }
  }
}
