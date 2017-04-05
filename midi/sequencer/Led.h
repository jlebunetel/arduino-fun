class Led {
  public:

    char name[20 + 1];

    // contructeur
    Led(char* name = "led", int pin = 13, bool activeValue = HIGH) { // nom, broche, valeur pour allumer la led
      this->pin = pin;
      this->activeValue = activeValue;
      strcpy(this->name, name);
    };

    // accesseurs et mutateurs
    bool get() {
      return value;
    };
    void set(bool value) {
      this->value = value;
      digitalWrite(pin, value == activeValue);
    };

    //autres fonctions
    void initialize() {
      pinMode(pin, OUTPUT);
      off();
    };
    void on() {
      set(HIGH);
    };
    void off() {
      set(LOW);
    };
    void change() {
      set(!value);
    }

  private:

    int pin;
    bool value;
    bool activeValue;
};
