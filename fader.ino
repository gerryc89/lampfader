#define key1 2
#define key2 3
#define key3 4
#define doors 5
#define lamp1 9
#define lamp2 10
#define lamp3 11
#define fad 20
int bright1 = 0;
int bright2 = 0;
int bright3 = 0;
int allbright = 0;

void setup() {
  pinMode(key1, INPUT_PULLUP);
  pinMode(key2, INPUT_PULLUP);
  pinMode(key3, INPUT_PULLUP);
  pinMode(doors, INPUT_PULLUP);
  pinMode(lamp1, OUTPUT);
  pinMode(lamp2, OUTPUT);
  pinMode(lamp3, OUTPUT);
  digitalWrite(lamp1, LOW);
  digitalWrite(lamp2, LOW);
  digitalWrite(lamp3, LOW);

}

void loop() {
  if (digitalRead(doors) == LOW) {
    bright1 = 0;
    bright2 = 0;
    bright3 = 0;
    while (255 > allbright) {
      allbright++;
      analogWrite(lamp1, allbright);
      analogWrite(lamp2, allbright);
      analogWrite(lamp3, allbright);
      delay(fad);
    }
  }
  else {
    if (allbright > 254) {
      bright1 = 0;
      bright2 = 0;
      bright3 = 0;
      while (allbright > 0) {
        allbright--;
        analogWrite(lamp1, allbright);
        analogWrite(lamp2, allbright);
        analogWrite(lamp3, allbright);
        delay(fad);
      }
    }
    if (digitalRead(key1) == LOW && bright1 == 0) {
      while (255 > bright1) {
        bright1++;
        analogWrite(lamp1, bright1);
        delay(fad);
      }
    }
    if (digitalRead(key2) == LOW && bright2 == 0) {
      while (255 > bright2) {
        bright2++;
        analogWrite(lamp2, bright2);
        delay(fad);
      }
    }
    if (digitalRead(key3) == LOW && bright3 == 0) {
      while (255 > bright3) {
        bright3++;
        analogWrite(lamp3, bright3);
        delay(fad);
      }
    }
    if (digitalRead(key1) == LOW && bright1 > 254) {
      while (bright1 > 0) {
        bright1--;
        analogWrite(lamp1, bright1);
        delay(fad);
      }
    }
    if (digitalRead(key2) == LOW && bright2 > 254) {
      while (bright2 > 0) {
        bright2--;
        analogWrite(lamp2, bright2);
        delay(fad);
      }
    }
    if (digitalRead(key3) == LOW && bright3 > 254) {
      while (bright3 > 0) {
        bright3--;
        analogWrite(lamp3, bright3);
        delay(fad);
      }
    }
  }
}
