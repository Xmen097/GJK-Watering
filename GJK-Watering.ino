// Tahle proměnná ukazuje, zda je zavlažování zapnuto
int watering_on = 0;

void setup() {
    // Nějakej setup kód
}

void loop() {
    // Tohleto furt dokola
    if (digitalRead(8) == HIGH) {
        // Tlačítko zmáčknuto
        if (watering_on) {
            // Vypnout zavlažování
             watering_on = 0;
        }
        else if (watering_on == 0) {
             // Zapnout zavlažování
             watering_on = 1;
        }
    }
}
