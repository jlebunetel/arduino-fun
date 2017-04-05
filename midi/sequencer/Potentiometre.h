/*
  Utilisation :
  - créer les objets "Potentiometre" avant la fonction "setup()"
  - dans la fonction "loop()" appeler la fonction "read()" pour mettre à jour chaque potentiometre
*/

class Potentiometre {
  public:

    char name[20 + 1];

    // contructeur
    Potentiometre(char* name = "potentiometre", int pin = 0, int minValue = 0, int maxValue = 1023) {
      this->pin = pin;
      this->value = minValue;
      this->previousValue = minValue;
      this->minValue = minValue;
      this->maxValue = maxValue;
      strcpy(this->name, name);
    };

    // accesseurs et mutateurs
    int get() {
      return value;
    };
    void set(int value) {
      this->previousValue = this->value;
      this->value = value;
    };

    //autres fonctions
    int read() {
      set(map(analogRead(pin), 0, 1023, minValue, maxValue));
      return value;
    };
    bool hasChanged() {
      return (value != previousValue);
    };

  private:

    int pin;
    int value;
    int previousValue;
    int minValue;
    int maxValue;
};
