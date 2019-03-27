reciever.txt

Type
Text
Size
20 KB (20,561 bytes)
Storage used
20 KB (20,561 bytes)
Location
My Drive
Owner
me
Modified
Jan 1, 2018 by me
Opened
Dec 13, 2017 by me
Created
Apr 8, 2017
Add a description
Viewers can download
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int sensorPin = A4;   // select the input pin for ldr
int sensorValue = 0; // variable to store the value coming from the sensor
int pot = A2;
int val = 0;
int flg = 0;
int b2 = 9;
char prnt[19] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
char alp[43] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',  ' ', ' ', ' ', ' ', '.', ',', '?'};
char alp1[43] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z','0', '1', '2', '3', '4', '5', '6', '7', '8', '9',  ' ', ' ', ' ', ' ', '.', ',', '?'};
char alp2[43] = {'M', 'N', 'O', 'J', 'K', 'L', 'T', 'U', 'V', '.', ',', '?', 'G', 'H', 'I', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', ' ', ' ', ' ', ' ','7', '3', '6', '5', '8', '1', '4', '9', '2', '0',  'P', 'Q', 'R', 'S', 'D', 'E', 'F'};
char alp3[43] = {'M', 'N', 'O', '.', ',', '?', 'A', 'B', 'C', 'D', 'E', 'F', 'T', 'U', 'V', ' ', ' ', ' ', ' ', 'G', 'H', 'I', 'P', 'Q', 'R', 'S','9', '5', '6', '1', '2', '3', '8', '0', '4', '7',  'W', 'X', 'Y', 'Z', 'J', 'K', 'L'};
bool lb2 = LOW;
bool cb2 = LOW;
long t1 = 0;
long t2 = 0;
long t3 = 0;
int f = 0;
int enc = 1;
int button = 8;
int level = 700;
bool lastbutton = LOW;
bool currentbutton = LOW;
bool calibmode = true;
void setup()
{
  pinMode (button, INPUT);

  lcd.begin(16, 2); //pin connected to the relay
  Serial.begin(9600); //sets serial port for communication
}

bool debounce2 (bool last, int button)
{
  bool current = digitalRead(button);
  if (last != current)
  {
    delay(5);
    current = digitalRead(button);
  }
  return current;
}

bool debounce (bool last)
{
  bool current = digitalRead(button);
  if (last != current)
  {
    delay(5);
    current = digitalRead(button);
  }
  return current;
}


int timecheck(unsigned long start)
{

  if ((analogRead(sensorPin) >= level) && ((millis() - start) > 150) && (f == 0))
    return 1;
  else
  {
    if ((analogRead(sensorPin) < level) && ((millis() - start) > 1000 ))
      return 1;
    else if ((analogRead(sensorPin) < level) && (t1 == 0))
    {

      f = 1;
      return (timecheck(start));
    }
    else if ((analogRead(sensorPin) >= level) && ( t1 == 0) && (f == 1))
    {


      f = 0;
      t1 = millis() - start;
      start = millis();
      return (timecheck(start));


    }
    else if ((analogRead(sensorPin) < level) && ( t2 == 0 ) && (t1 != 0))
    {

      f = 1;
      return (timecheck(start));
    }
    else if ((analogRead(sensorPin) >= level) && (t2 == 0) && ( f == 1) && (t1 != 0 ))
    {

      f = 0;
      t2 = millis() - start;
      start = millis();
      return (timecheck(start));

    }
    else if ((analogRead(sensorPin) < level) && (t3 == 0) && (t1 != 0 ) && (t2 != 0) )
    {

      f = 1;
      return (timecheck(start));
    }
    else if ((analogRead(sensorPin) >= level) && ( t3 == 0 ) && ( f == 1 ) && (t1 != 0 ) && ( t2 != 0 ))
    {

      f = 0;
      t3 = millis() - start;
      start = millis();
      return 1;
    }
    else
      return (timecheck(start));
  }
}


void loop()
{
  int i, j;
  
  currentbutton = debounce (lastbutton);
  if (lastbutton == LOW && currentbutton == HIGH)
  {
    calibmode = !calibmode;
  }
  lastbutton = currentbutton;

  cb2 = debounce2 (lb2, b2);
  if (lb2 == LOW && cb2 == HIGH)
  {
    enc++;
    if (enc == 4)
      enc = 1;
  }
  lb2 = cb2;
  lcd.setCursor(12, 1);
  lcd.print("E");
  lcd.print(enc, DEC);
  if (enc == 1)
  {
    for (i = 0; i < 40; i++)
      alp[i] = alp1[i];
  }
  if (enc == 2)
  {
    for (i = 0; i < 40; i++)
      alp[i] = alp2[i];
  }

  if (enc == 3)
  {
    for (i = 0; i < 40; i++)
      alp[i] = alp3[i];
  }
  
  val = analogRead(pot);
  level = map(val, 0, 1024, 0, 1000);

  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  if (sensorValue >= level)
  {
    lcd.setCursor(0, 1);
    lcd.print("     ");
    lcd.setCursor(0, 1);
    lcd.print(level, DEC);
    lcd.setCursor(5, 1);
    lcd.print("     ");
    lcd.setCursor(5, 1);
    lcd.print("HIGH");
  }

  else
  {
    lcd.setCursor(0, 1);
    lcd.print("     ");
    lcd.setCursor(0, 1);
    lcd.print(level, DEC);
    lcd.setCursor(5, 1);
    lcd.print("     ");
    lcd.setCursor(5, 1);
    lcd.print("LOW");
  }

  if ((sensorValue < level) && (calibmode == false)) //setting a threshold value
  {
    //lcd.setCursor(0, 0);
    //lcd.print("                     ");
    // flg=0;
    lcd.setCursor(0, 0);
    int j = timecheck(millis());
    if (t1 != 0 || t2 != 0 || t3 != 0)
    {
      /*lcd.print(t1, DEC);
        lcd.print("  ");
        lcd.print(t2, DEC);
        lcd.print("  ");
        lcd.print(t3, DEC);
        lcd.print("  ");
      */
      if ( ((t1 > 70) && (t1 < 95)) && t2 == 0 && t3 == 0) //A
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[0];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 120) && (t1 < 145)) && t2 == 0 && t3 == 0) //B
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[1];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 170) && (t1 < 195)) && t2 == 0 && t3 == 0) //C
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[2];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 70) && (t1 < 95)) && ((t2 > 195) && (t2 < 205)) && t3 == 0) //D
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[3];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 70) && (t1 < 95)) && ((t2 > 245) && (t2 < 255)) && t3 == 0) //E
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[4];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 70) && (t1 < 95)) && ((t2 > 295) && (t2 < 305)) && t3 == 0) //F
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[5];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 170) && (t1 < 195)) && ((t2 > 290) && (t2 < 310)) && ((t3 > 245) && (t3 < 255))) //"."
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[40];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 170) && (t1 < 195)) && ((t2 > 295) && (t2 < 305)) && ((t3 > 295) && (t3 < 305))) //,
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[41];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 170) && (t1 < 195)) && ((t2 > 345) && (t2 < 355)) && ((t3 > 295) && (t3 < 305))) //?
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[42];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 120) && (t1 < 145)) && ((t2 > 195) && (t2 < 205)) && (t3 == 0)) //G
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[6];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 120) && (t1 < 145)) && ((t2 > 245) && (t2 < 255)) && (t3 == 0)) //H
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[7];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 120) && (t1 < 145)) && ((t2 > 295) && (t2 < 305)) && (t3 == 0)) //I
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[8];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 170) && (t1 < 195)) && ((t2 > 195) && (t2 < 205)) && (t3 == 0)) //J
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[9];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 170) && (t1 < 195)) && ((t2 > 245) && (t2 < 255)) && (t3 == 0)) //K
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[10];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 170) && (t1 < 195)) && ((t2 > 295) && (t2 < 305)) && (t3 == 0)) //L
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[11];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 70) && (t1 < 95)) && ((t2 > 195) && (t2 < 205)) && ((t3 > 195) && (t3 < 205))) //M
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[12];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 70) && (t1 < 95)) && ((t2 > 195) && (t2 < 205)) && ((t3 > 245) && (t3 < 255))) //N
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[13];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 70) && (t1 < 95)) && ((t2 > 195) && (t2 < 205)) && ((t3 > 295) && (t3 < 305))) //O
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[14];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 70) && (t1 < 95)) && ((t2 > 245) && (t2 < 255)) && ((t3 > 195) && (t3 < 205))) //P
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[15];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 70) && (t1 < 95)) && ((t2 > 245) && (t2 < 255)) && ((t3 > 245) && (t3 < 255))) //Q
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[16];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 70) && (t1 < 95)) && ((t2 > 245) && (t2 < 255)) && ((t3 > 295) && (t3 < 305))) //R
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[17];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 70) && (t1 < 95)) && ((t2 > 295) && (t2 < 305)) && ((t3 > 195) && (t3 < 205))) //S
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[18];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 70) && (t1 < 95)) && ((t2 > 295) && (t2 < 305)) && ((t3 > 245) && (t3 < 255))) //T
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[19];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 70) && (t1 < 95)) && ((t2 > 295) && (t2 < 305)) && ((t3 > 295) && (t3 < 305))) //U
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[20];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 120) && (t1 < 145)) && ((t2 > 195) && (t2 < 205)) && ((t3 > 195) && (t3 < 205))) //V
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[21];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 120) && (t1 < 145)) && ((t2 > 195) && (t2 < 205)) && ((t3 > 245) && (t3 < 255))) //W
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[22];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 120) && (t1 < 145)) && ((t2 > 195) && (t2 < 205)) && ((t3 > 295) && (t3 < 305))) //X
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[23];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 120) && (t1 < 145)) && ((t2 > 245) && (t2 < 255)) && ((t3 > 195) && (t3 < 205))) //Y
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[24];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 120) && (t1 < 145)) && ((t2 > 245) && (t2 < 255)) && ((t3 > 245) && (t3 < 255))) //Z
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[25];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 120) && (t1 < 145)) && ((t2 > 245) && (t2 < 255)) && ((t3 > 295) && (t3 < 305))) //0
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[26];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 120) && (t1 < 145)) && ((t2 > 295) && (t2 < 305)) && ((t3 > 195) && (t3 < 205))) //1
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[27];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 120) && (t1 < 145)) && ((t2 > 295) && (t2 < 305)) && ((t3 > 245) && (t3 < 255))) //2
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[28];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 120) && (t1 < 145)) && ((t2 > 295) && (t2 < 355)) && ((t3 > 295) && (t3 < 305))) //3
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[29];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 170) && (t1 < 195)) && ((t2 > 195) && (t2 < 205)) && ((t3 > 195) && (t3 < 205))) //4
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[30];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 170) && (t1 < 195)) && ((t2 > 195) && (t2 < 205)) && ((t3 > 245) && (t3 < 255))) //5
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[31];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 170) && (t1 < 195)) && ((t2 > 195) && (t2 < 205)) && ((t3 > 295) && (t3 < 305))) //6
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[32];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 170) && (t1 < 195)) && ((t2 > 245) && (t2 < 255)) && ((t3 > 195) && (t3 < 205))) //7
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[33];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 170) && (t1 < 195)) && ((t2 > 245) && (t2 < 255)) && ((t3 > 245) && (t3 < 255))) //8
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[34];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 170) && (t1 < 195)) && ((t2 > 245) && (t2 < 255)) && ((t3 > 295) && (t3 < 305))) //9
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[35];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 170) && (t1 < 195)) && ((t2 > 295) && (t2 < 305)) && ((t3 > 195) && (t3 < 205))) //" "
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[36];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 170) && (t1 < 195)) && ((t2 > 145) && (t2 < 155)) && ((t3 > 145) && (t3 < 155))) //" "
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[37];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 170) && (t1 < 195)) && ((t2 > 145) && (t2 < 155)) && ((t3 > 195) && (t3 < 205))) //" "
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[38];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
      if ( ((t1 > 170) && (t1 < 195)) && ((t2 > 145) && (t2 < 155)) && ((t3 > 245) && (t3 < 255))) //" "
      {
        for (i = 18; i > 0; i--)
          prnt[i] = prnt[i - 1];
        prnt[0] = alp[39];
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }
       if ( ((t1 > 20) && (t1 < 45)) && (t2==0) && (t3==0) )//" "
      {
        for (i = 0; i <17; i++)
          prnt[i] = prnt[i +1];
        
        for (i = 0, j = 15; i < 19; i++, j--)
        {
          lcd.setCursor(j, 0);
          lcd.print(prnt[i]);
        }
      }




      t1 = 0;
      t2 = 0;
      t3 = 0;
    }
    else
      calibmode = true;


  }
  if (calibmode == true)
  {

    lcd.setCursor(0, 0);
    lcd.print("Calibration Mode                     ");
    flg = 1;
    for (i = 0; i < 19; i++)
      prnt[i] = ' ';
  }
  else if (flg == 1)
  {
    lcd.setCursor(0, 0);
    lcd.print("                    ");
    flg = 0;
  }



}