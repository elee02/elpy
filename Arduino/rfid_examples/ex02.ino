// C++ code
//
const int red = 13;
const int green = 8;
const int blue = 7;

void setup()
{
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop()
{

    for (int i = 0; i < 2; ++i) {
      digitalWrite(red, HIGH);
      delay(1000);
      digitalWrite(red, LOW);
      delay(1000);
    }
    for (int i = 0; i < 4; ++i) {
      digitalWrite(green, HIGH);
      delay(1000);
      digitalWrite(green, LOW);
      delay(1000);
    }
    for (int i = 0; i < 6; ++i) {
      digitalWrite(blue, HIGH);
      delay(1000);
      digitalWrite(blue, LOW);
      delay(1000);
    }
}