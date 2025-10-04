// Clap Counter using Arduino and Sound Sensor
// Works with sensors like HW-484 (sound module)

int soundSensor = 2;   // Sound sensor connected to digital pin 2
int clapCount = 0;     // Counter for claps
int state = 0;         // Current sensor state
int lastState = 0;     // Previous sensor state
unsigned long lastClapTime = 0; // To avoid multiple counts per clap
int debounceTime = 200; // Minimum time between claps in ms

void setup() {
  pinMode(soundSensor, INPUT);
  Serial.begin(9600);
  Serial.println("Clap Counter Ready...");
}

void loop() {
  state = digitalRead(soundSensor);

  // Detect rising edge (clap detected)
  if (state == HIGH && lastState == LOW) {
    unsigned long currentTime = millis();
    if (currentTime - lastClapTime > debounceTime) {
      clapCount++;
      Serial.print("Clap detected! Count = ");
      Serial.println(clapCount);
      lastClapTime = currentTime;
    }
  }

  lastState = state;
}
