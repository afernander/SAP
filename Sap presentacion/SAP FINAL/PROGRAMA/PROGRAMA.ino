int led = 2;
int LDA = 22;
int ADD = 23;
int SUB = 24;
int MULT = 25;
int DIVI = 26;
int call = 27;
int gt = 28;
int rtrn = 29;
int opc1 = 30;
int opc2 = 31;
int out = 32;
int HLT = 33;
int adc = 34;
int LA = 35;
int EA = 36;
int EU = 37;
int LB = 38;
int LO = 39;
int LI =  40;
int EI = 41;
int ER = 42;
int LM = 43;
int EP = 44;
int SU = 45;
int RE = 46;
int ML = 47;
int DV = 48;
int PC;
int salto;
int wait = 200;

void setup() {
  DDRA = B00000000;
  DDRC = B00000111;
  pinMode(LB, OUTPUT);
  pinMode(LO, OUTPUT);
  pinMode(LI, OUTPUT);
  pinMode(EI, OUTPUT);
  pinMode(led, OUTPUT);

 
  digitalWrite(led, LOW);
  DDRL = B11111110;
  DDRK = B00001111;
  PC = 0;
  salto = 0;
  Serial.begin(9600);
}

void loop() {
  PORTK = PC;
  digitalWrite(EP, 1);
  digitalWrite(LM, 1);
  delay(wait);
  digitalWrite(LM, 0);
  digitalWrite(EP, 0);
  digitalWrite(ER, 1);
  digitalWrite(LI, 1);
  delay(wait);
  digitalWrite(LI, 0);
  digitalWrite(ER, 0);

  if (digitalRead(LDA) == HIGH) {
    digitalWrite(EI, 1);
    digitalWrite(LM, 1);
    delay(wait);
    digitalWrite(LM, 0);
    digitalWrite(EI, 0);
    digitalWrite(ER, 1);
    digitalWrite(LA, 1);
    delay(wait);
    digitalWrite(LA, 0);
    digitalWrite(ER, 0);
    PC++;
  }

  if (digitalRead(ADD) == HIGH) {
    digitalWrite(EI, 1);
    digitalWrite(LM, 1);
    delay(wait);
    digitalWrite(LM, 0);
    digitalWrite(EI, 0);
    digitalWrite(ER, 1);
    digitalWrite(LB, 1);
    delay(wait);
    digitalWrite(LB, 0);
    digitalWrite(ER, 0);
    digitalWrite(SU, 1);
    digitalWrite(EU, 1);
    digitalWrite(LA, 1);
    delay(wait);
    digitalWrite(LA, 0);
    digitalWrite(EU, 0);
    digitalWrite(SU, 0);
    PC++;
  }

  if (digitalRead(SUB) == HIGH) {
    digitalWrite(EI, 1);
    digitalWrite(LM, 1);
    delay(wait);
    digitalWrite(LM, 0);
    digitalWrite(EI, 0);
    digitalWrite(ER, 1);
    digitalWrite(LB, 1);
    delay(wait);
    digitalWrite(LB, 0);
    digitalWrite(ER, 0);
    digitalWrite(RE, 1);
    digitalWrite(EU, 1);
    digitalWrite(LA, 1);
    delay(wait);
    digitalWrite(LA, 0);
    digitalWrite(EU, 0);
    digitalWrite(RE, 0);
    PC++;
  }


  if (digitalRead(MULT) == HIGH) {
    digitalWrite(EI, 1);
    digitalWrite(LM, 1);
    delay(wait);
    digitalWrite(LM, 0);
    digitalWrite(EI, 0);
    digitalWrite(ER, 1);
    digitalWrite(LB, 1);
    delay(wait);
    digitalWrite(LB, 0);
    digitalWrite(ER, 0);
    digitalWrite(ML, 1);
    digitalWrite(EU, 1);
    digitalWrite(LA, 1);
    delay(wait);
    digitalWrite(LA, 0);
    digitalWrite(EU, 0);
    digitalWrite(ML, 0);
    PC++;
  }


  if (digitalRead(DIVI) == HIGH) {
    digitalWrite(EI, 1);
    digitalWrite(LM, 1);
    delay(wait);
    digitalWrite(LM, 0);
    digitalWrite(EI, 0);
    digitalWrite(ER, 1);
    int num = PINK >> 4;

    if (num == 0) {
      digitalWrite(led, HIGH);
      while (true);
    }
    digitalWrite(LB, 1);
    delay(wait);
    digitalWrite(LB, 0);
    digitalWrite(ER, 0);
    digitalWrite(DV, 1);
    digitalWrite(EU, 1);
    digitalWrite(LA, 1);
    delay(wait);
    digitalWrite(LA, 0);
    digitalWrite(EU, 0);
    digitalWrite(DV, 0);
    PC++;
  }

  if (digitalRead(call) == HIGH) {
    salto = PC + 1;
    digitalWrite(EI, 1);
    delay(wait);
    PC = PINK >> 4;
    digitalWrite(EI, 0);
  }

  if (digitalRead(HLT) == HIGH) {
    while (true);
  }

  if (digitalRead(out) == HIGH) {
    digitalWrite(EA, 1);
    digitalWrite(LO, 1);
    delay(wait);
    digitalWrite(LO, 0);
    digitalWrite(EA, 0);
    PC++;
  }

  if (digitalRead(rtrn) == HIGH) {
    PC = salto;
  }

  if (digitalRead(gt) == HIGH) {
    digitalWrite(EI, 1);
    delay(wait);
    PC = PINK >> 4;
    digitalWrite(EI, 0);
  }

  if (digitalRead(adc) == HIGH) {
    PORTK = 1;
    digitalWrite(EP, 1);
    digitalWrite(LB, 1);
    delay(wait);
    digitalWrite(LB, 0);
    digitalWrite(EP, 0);
    digitalWrite(RE, 1);
    digitalWrite(EU, 1);
    digitalWrite(LA, 1);
    delay(wait);
    digitalWrite(LA, 0);
    digitalWrite(EU, 0);
    digitalWrite(RE, 0);
    digitalWrite(EA, 1);
    int acumulador = PINK >> 4;
    delay(wait);
    digitalWrite(EA, 0);
    if (acumulador == 0) {
      PC += 2;
    }
    else {
      PC++;
    }
  }

  if (digitalRead(opc1) == HIGH) {
    PORTK = 1; // al bus
    digitalWrite(EP, 1);
    digitalWrite(LB, 1);
    delay(wait);
    digitalWrite(EP, 0);
    digitalWrite(LB, 0);
    digitalWrite(SU, 1);
    digitalWrite(EU, 1);
    digitalWrite(LA, 1);
    delay(wait);
    digitalWrite(LA, 0);
    digitalWrite(EU, 0);
    digitalWrite(SU, 0);
    PC++;
  }

  if (digitalRead(opc2) == HIGH) {
    digitalWrite(EA, 1);
    int acomulator = PINK >> 4;
    delay(wait);
    digitalWrite(EA, 0);
    if (acomulator % 2 == 0) {
      PORTK = 2; // al bus
      digitalWrite(EP, 1);
      digitalWrite(LB, 1);
      delay(wait);
      digitalWrite(EP, 0);
      digitalWrite(LB, 0);
      digitalWrite(SU, 1);
      digitalWrite(EU, 1);
      digitalWrite(LA, 1);
      delay(wait);
      digitalWrite(LA, 0);
      digitalWrite(EU, 0);
      digitalWrite(SU, 0);
    } else {
      PORTK = 1; // al bus
      digitalWrite(EP, 1);
      digitalWrite(LB, 1);
      delay(wait);
      digitalWrite(EP, 0);
      digitalWrite(LB, 0);
      digitalWrite(SU, 1);
      digitalWrite(EU, 1);
      digitalWrite(LA, 1);
      delay(wait);
      digitalWrite(LA, 0);
      digitalWrite(EU, 0);
      digitalWrite(SU, 0);
    }
    PC++;
  }
}
