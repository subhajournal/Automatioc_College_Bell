int clsmd = 2;
int exmmd = 3;

int bz = 4;
int clk = 5;

int clsrun = 6;
int lunch = 7;
int clsend = 8;

int exmstrt = 9;
int hourone = 10;
int hourtwo = 11;
int hourthree = 12;

int clkrst = 13;

int i = 0;
int j = 0;
int k = 0;
int m = 0;
int n = 0;
int p = 0;

int clsmoderead;
int exmmoderead;

void setup() {
  pinMode(clsmd, INPUT);
  pinMode(exmmd, INPUT);

  pinMode(bz, OUTPUT);
  pinMode(clk, OUTPUT);
  pinMode(clsrun, OUTPUT);
  pinMode(lunch, OUTPUT);
  pinMode(clsend, OUTPUT);
  pinMode(exmstrt, OUTPUT);
  pinMode(hourone, OUTPUT);
  pinMode(hourtwo, OUTPUT);
  pinMode(hourthree, OUTPUT);
  pinMode(clkrst, OUTPUT);
}

void switchread()
{
  clsmoderead = digitalRead(clsmd);
  exmmoderead = digitalRead(exmmd);
}
void statusshow()
{
  if (clsmoderead == HIGH && exmmoderead == LOW)
  {
    digitalWrite(clkrst, HIGH);
    delay(999);
    digitalWrite(clkrst, LOW);
    classbell();
    classmode();
  }
  if (exmmoderead == HIGH && clsmoderead == LOW)
  {
    digitalWrite(clkrst, HIGH);
    delay(999);
    digitalWrite(clkrst, LOW);
    for (k = 0; k < 3; k++) {
      if (k == 1)
      {
        while (1);
      }
      exammode();
    }
  }
  if (exmmoderead == HIGH && clsmoderead == HIGH)
  {
    digitalWrite(clsrun, HIGH);
    delay(1000);
    digitalWrite(lunch, HIGH);
    delay(1000);
    digitalWrite(clsend, HIGH);
    delay(1000);
    digitalWrite(exmstrt, HIGH);
    delay(1000);
    digitalWrite(hourone, HIGH);
    delay(1000);
    digitalWrite(hourtwo, HIGH);
    delay(1000);
    digitalWrite(hourthree, HIGH);
    delay(1000);
    buzzer();
  }
  if (exmmoderead == LOW && clsmoderead == LOW)
  {
    digitalWrite(clsrun, LOW);
    digitalWrite(lunch, LOW);
    digitalWrite(clsend, LOW);
    digitalWrite(exmstrt, LOW);
    digitalWrite(hourone, LOW);
    digitalWrite(hourtwo, LOW);
    digitalWrite(hourthree, LOW);
  }
}
void buzzer()
{
  digitalWrite(bz, HIGH);
  for (p = 0; p < 5; p++)
  {
    delay(999);
  }
  digitalWrite(bz, LOW);
}

void classbell()
{
  digitalWrite(bz, HIGH);
  for (m = 0; m < 5; m++)
  {
    delay(999);
  }
  digitalWrite(bz, LOW);
}

void clockcount()
{
  digitalWrite(clk, LOW);
  digitalWrite(clk, HIGH);
  delay(999);
  digitalWrite(clk, LOW);
}

void fifteendelay()               //15min delay
{
  for (j = 0; j < 900; j++)
  {
    delay(999);
  }
}

void exammode()
{
  buzzer();
  fifteendelay();    //wait for 15 min to start exam
  buzzer();
  digitalWrite(exmstrt, HIGH);
  fifteendelay();
  fifteendelay();
  fifteendelay();
  fifteendelay();
  clockcount();
  buzzer();
  digitalWrite(hourone, HIGH);
  fifteendelay();
  fifteendelay();
  fifteendelay();
  fifteendelay();
  clockcount();
  buzzer();
  digitalWrite(hourtwo, HIGH);
  fifteendelay();
  fifteendelay();
  buzzer();
  fifteendelay();
  fifteendelay();
  clockcount();
  buzzer();
  digitalWrite(hourthree, HIGH);
  delay(999);
  digitalWrite(exmstrt, LOW);
  digitalWrite(hourone, LOW);
  digitalWrite(hourtwo, LOW);
}

void classmode()
{
  for (n = 0; n < 10; n++)
  {
    if (n == 9)
    {
      digitalWrite(clsrun, LOW);
      digitalWrite(clsend, HIGH);
      classbell();
      while (1);
    }

    if (n == 4)
    {
      digitalWrite(lunch, HIGH);
      digitalWrite(clsrun, LOW);
      fifteendelay();
      fifteendelay();
      fifteendelay();
      digitalWrite(lunch, LOW);
      classbell();
      digitalWrite(clsrun, HIGH);
    }
    clockcount();
    digitalWrite(clsrun, HIGH);
    fifteendelay();
    fifteendelay();
    fifteendelay();
    digitalWrite(clsrun, LOW);
    digitalWrite(clsend, HIGH);
    classbell();
    digitalWrite(clsend, LOW);
  }
}

void loop() {
  switchread();
  statusshow();
}
