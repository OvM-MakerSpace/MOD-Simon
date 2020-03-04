int Taster1 = 5;
int Taster2 = 6;
int Taster3 = 11;
int Taster4 = 12;

int LEDgruen =10;
int LEDrot = 9;
int LEDblau = 8;
int LEDgelb = 7;

// Tasterentprellung
// Taster1
unsigned long lastMillis1;

int state1 = LOW;
int reading1;
int previous1 = HIGH;

// Taster2
unsigned long lastMillis2;

int state2 = LOW;
int reading2;
int previous2 = HIGH;

// Entprellzeit
long time = 0;
long debounce = 500;

// Ende Tasterentprellung

int zufallsZahl;


void setup() {
  // put your setup code here, to run once:
  pinMode(Taster1, INPUT);
  pinMode(Taster2, INPUT);
  pinMode(Taster3, INPUT);
  pinMode(Taster4, INPUT);
  pinMode(LEDgruen, OUTPUT);
  pinMode(LEDrot, OUTPUT);
  pinMode(LEDblau, OUTPUT);
  pinMode(LEDgelb, OUTPUT);

  pinMode(A0, INPUT);   // Spiel wurde gestartet, LED13 wird gesetzt
  pinMode(A1, OUTPUT);  // Modul geloest
  pinMode(A2, OUTPUT);  // Modul falsch geloest, Fehlermeldung

  
  lastMillis1 = millis();
  lastMillis2 = millis();
 
  Serial.begin(9600);
  
  zufallsZahl = random(1,5);
  randomSeed( analogRead(A0) );
  
  LEDtest();

}

void loop() {
  zufallsZahl = random(1,5);
  
  //Serial.println(state1);
  //delay(100);
  //Serial.println(state2);
  //delay(100);
  Serial.println(zufallsZahl);
  delay(100);

  
  // Taster1 wählt die Zufallszahl, danach Zuordnung des Spiels zur Zufalsszahl
  // D13 wird nach Betätigung von Taster1 auf HIGH gesetzt bis das Spiel gelöst wurde 
  
  // ======
  // Spiel1
  // ======
  
  reading1 = digitalRead(Taster1);
  
  if (reading1 == HIGH && previous1 == HIGH && digitalRead(13) == !HIGH && zufallsZahl == 1 && millis() - time > debounce) {
    if (state1 == HIGH)
    state1 = LOW;
    else 
    {
    state1 = HIGH;
    }
    time = millis(); 
    //digitalWrite(LEDgruen, state1);
    Spiel1();
    digitalWrite(13, HIGH);  
  }
  
  if (zufallsZahl == 1 && (digitalRead(13) == HIGH && digitalRead(Taster3) == HIGH && digitalRead(Taster4)) == HIGH) {
    digitalWrite(LEDgruen, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    digitalWrite(LEDgruen, LOW);
    digitalWrite(A2, HIGH);
    asm volatile ("jmp 0"); // Programm ab Zeile 0 neu starten
  }

  // ======
  // Spiel2
  // ======
  
  reading1 = digitalRead(Taster1);
  
  if (reading1 == HIGH && previous1 == HIGH && digitalRead(13) == !HIGH && zufallsZahl == 2 && millis() - time > debounce) {
    if (state1 == HIGH)
    state1 = LOW;
    else 
    {
    state1 = HIGH;
    }
    time = millis(); 
    //digitalWrite(LEDgruen, state1);
    Spiel2();
    digitalWrite(13, HIGH);
  }
  
  if (zufallsZahl == 2 && digitalRead(13) == HIGH && digitalRead(Taster2) == HIGH) {
    digitalWrite(LEDgruen, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    digitalWrite(LEDgruen, LOW);
    digitalWrite(A2, HIGH);
    asm volatile ("jmp 0"); // Programm ab Zeile 0 neu starten
  }


  // ======
  // Spiel3
  // ======
  
  reading1 = digitalRead(Taster1);
  
  if (reading1 == HIGH && previous1 == HIGH && digitalRead(13) == !HIGH && zufallsZahl == 3 && millis() - time > debounce) {
    if (state1 == HIGH)
    state1 = LOW;
    else 
    {
    state1 = HIGH;
    }
    time = millis(); 
    //digitalWrite(LEDgruen, state1);
    Spiel3();
    digitalWrite(13, HIGH);
  }

  if (zufallsZahl == 3 && digitalRead(13) == HIGH && digitalRead(Taster3) == HIGH) {
    digitalWrite(LEDgruen, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    digitalWrite(LEDgruen, LOW);
    digitalWrite(A2, HIGH); 
    asm volatile ("jmp 0"); // Programm ab Zeile 0 neu starten      
    }
    

  // ======
  // Spiel4
  // ======
  
  reading1 = digitalRead(Taster1);
  
  if (reading1 == HIGH && previous1 == HIGH && digitalRead(13) == !HIGH && zufallsZahl == 4 && millis() - time > debounce) {
    if (state1 == HIGH)
    state1 = LOW;
    else 
    {
    state1 = HIGH;
    }
    time = millis(); 
    //digitalWrite(LEDgruen, state1);
    Spiel4();
    digitalWrite(13, HIGH);
  }
  
  if (zufallsZahl == 4 && digitalRead(13) == HIGH && digitalRead(Taster4) == HIGH) {
    digitalWrite(LEDgruen, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    digitalWrite(LEDgruen, LOW);
    digitalWrite(A2, HIGH);
    asm volatile ("jmp 0"); // Programm ab Zeile 0 neu starten
  }


  // Taster2
  
 }
   

// ++++++++++++
// eigene Voids
// ++++++++++++

void LEDtest() {
digitalWrite(LEDgruen, HIGH);
delay(100);
digitalWrite(LEDrot, HIGH);
delay(100);
digitalWrite(LEDgelb, HIGH);
delay(100);
digitalWrite(LEDblau, HIGH);
delay(500);
digitalWrite(LEDgruen, LOW);
digitalWrite(LEDrot, LOW);
digitalWrite(LEDblau, LOW);
digitalWrite(LEDgelb, LOW);
}

void Spiel1() {
  digitalWrite(LEDblau, HIGH);
  delay(100);
  digitalWrite(LEDblau, LOW);
  delay(100);
  digitalWrite(LEDgelb, HIGH);
  delay(100);
  digitalWrite(LEDgelb, LOW);
  delay(100);
  digitalWrite(LEDgelb, HIGH);
  delay(100);
  digitalWrite(LEDgelb, LOW);
  delay(100);
}

void Spiel2() {
  digitalWrite(LEDblau, HIGH);
  delay(200);
  digitalWrite(LEDblau, LOW);
  delay(200);
  digitalWrite(LEDgruen, HIGH);
  delay(200);
  digitalWrite(LEDgruen, LOW);
  delay(200);
  digitalWrite(LEDrot, HIGH);
  delay(200);
  digitalWrite(LEDrot, LOW);
  delay(200);
  digitalWrite(LEDgelb, HIGH);
  delay(200);
  digitalWrite(LEDgelb, LOW);
  delay(200);
}

void Spiel3() {
  digitalWrite(LEDrot, HIGH);
  delay(300);
  digitalWrite(LEDrot, LOW);
  delay(300);
  digitalWrite(LEDgruen, HIGH);
  delay(300);
  digitalWrite(LEDgruen, LOW);
  delay(300);
  digitalWrite(LEDrot, HIGH);
  delay(300);
  digitalWrite(LEDrot, LOW);
  delay(300);
  digitalWrite(LEDblau, HIGH);
  delay(300);
  digitalWrite(LEDblau, LOW);
  delay(300);
}

void Spiel4() {
  digitalWrite(LEDgelb, HIGH);
  delay(400);
  digitalWrite(LEDgelb, LOW);
  delay(400);
  digitalWrite(LEDblau, HIGH);
  delay(400);
  digitalWrite(LEDblau, LOW);
  delay(400);
  digitalWrite(LEDrot, HIGH);
  delay(400);
  digitalWrite(LEDrot, LOW);
  delay(400);
  digitalWrite(LEDblau, HIGH);
  delay(400);
  digitalWrite(LEDblau, LOW);
  delay(400);
  digitalWrite(LEDgruen, HIGH);
  delay(400);
  digitalWrite(LEDgruen, LOW);
  delay(400);
}

void Fehler() {
  digitalWrite(LEDblau, HIGH);
  digitalWrite(LEDrot, HIGH);
  digitalWrite(LEDgelb, HIGH);
  digitalWrite(LEDgruen, HIGH);
  delay(250);
  digitalWrite(LEDblau, LOW);
  digitalWrite(LEDgelb, LOW);
  digitalWrite(LEDgruen, LOW);
  delay(2000);
  digitalWrite(LEDrot, LOW);
}
