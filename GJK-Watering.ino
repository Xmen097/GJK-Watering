// Tahle proměnná ukazuje, zda je zavlažování zapnuto
int watering_on = 0;
int watering_started_at = -1;

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
             watering_started_at = millis();
        }
    }
    
    // Přečte senzor vlhkosti => může nabývat hodnoty 0 - 1023
    humidity = analogRead(A0);  
    
    if (humidity > 700) { // Je potřeba otestovat a správně nastavit podle květin
        watering_on = 1;
        watering_started_at = millis();
    }
    
    if (watering_on && millis() - watering_started_at > 120000) { // Zavlažování trvá dvě minuty (potřeba taky vyladit)
        watering_on = 0;
        watering_started_at = -1;
    }
}
