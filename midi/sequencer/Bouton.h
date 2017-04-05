/*
  Utilisation :
  - créer les objets "Bouton" avant la fonction "setup()"
  - dans la fonction "setup()" appeler la fonction "initialize()" pour chaque bouton
  - dans la fonction "loop()" appeler la fonction "read()" pour mettre à jour chaque bouton
*/

class Bouton {
  public:

    char name[20 + 1];

    // contructeur
    Bouton(char* name = "bouton", int pin = 0, bool defaultValue = LOW, bool pullUp = false) { // nom, broche, valeur par défaut, pullup activé
      this->pin = pin;
      this->value = 0;
      this->previousValue = 0;
      this->defaultValue = defaultValue;
      this->pullUp = pullUp;
      strcpy(this->name, name);
    };

    // accesseurs et mutateurs
    bool get() {
      return value;
    };
    void set(bool value) {
      this->previousValue = this->value;
      this->value = value;
    };

    //autres fonctions
    void initialize() {
      if (pullUp) {
        pinMode(pin, INPUT_PULLUP);
      }
      else {
        pinMode(pin, INPUT);
      }
    };
    bool read() {
      set(digitalRead(pin) != defaultValue);
      return value;
    };
    bool isPressed() {
      return (value);
    };
    bool isReleased() {
      return (!value);
    };
    bool hasChanged() {
      return (value != previousValue);
    };
    bool isJustPressed() {
      return (hasChanged() && isPressed());
    };
    bool isJustReleased() {
      return (hasChanged() && isReleased());
    };

  private:

    int pin;
    bool value;
    bool previousValue;
    bool defaultValue;
    bool pullUp;
};
