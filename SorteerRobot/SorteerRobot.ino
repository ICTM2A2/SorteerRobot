int EN1 = 5;
int EN2 = 6; 
int IN1 = 4;
int IN2 = 7;

void Motor1(int pwm, boolean reverse) {
  analogWrite(EN1, pwm); 
  if (reverse)  {
    digitalWrite(IN1, HIGH);
  }
  else  {
    digitalWrite(IN1, LOW);
  }
}

void setup() {
  for (int i = 4; i <= 7; i++){    
    pinMode(i, OUTPUT);
  }

  Serial.begin(9600);
}

void loop() {
  int x, delay_en;
  char val;
  while (1)  {
    val = Serial.read();
    if (val != -1)    {
      switch (val)      {
        case 'r'://turn right
          Motor1(255, true);
          delay(2000);
          Motor1(0, false);
          break;
        case 'l'://turn left
          Motor1(255, false);
          delay(2000);
          Motor1(0, false);
          break;
      }
    }
  }
}
