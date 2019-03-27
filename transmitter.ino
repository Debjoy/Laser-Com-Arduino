transmitter.txt
Type
Text
Size
27 KB (27,455 bytes)
Storage used
27 KB (27,469 bytes)
Location
My Drive
Owner
me
Modified
Apr 16, 2017 by me
Opened
9:23 PM by me
Created
Apr 8, 2017
Add a description
Viewers can download
int b1 = 0;
int b2 = 1;
int b3 = 2;
int b4 = 3;
int b5 = 4;
int b6 = 5;
int b7 = 6;
int b8 = 7;
int b9 = 8;
int b10 = 9;
int b11 = 14;
int enc = 1;
int back=15;
int t = 0;
int laser = 13;
int encpin = A2;
int encvalue = 0;
int  ledstat=12;
bool lb1 = LOW, lb2 = LOW, lb3 = LOW, lb4 = LOW, lb5 = LOW, lb6 = LOW, lb7 = LOW, lb8 = LOW, lb9 = LOW, lb10 = LOW, lb11 = LOW,lback=LOW;
bool cb1 = LOW, cb2 = LOW, cb3 = LOW, cb4 = LOW, cb5 = LOW, cb6 = LOW, cb7 = LOW, cb8 = LOW, cb9 = LOW, cb10 = LOW, cb11 = LOW,cback=LOW;
bool alpMode = false;
int ledalp = 11;
void setup()
{
  pinMode (b1, INPUT);
  pinMode (b3, INPUT);
  pinMode (b11, INPUT);
  pinMode (back, INPUT);
  pinMode (laser, OUTPUT);
  pinMode(ledalp, OUTPUT);
  pinMode(ledstat, OUTPUT);

}

bool debounce (bool last, int button)
{
  bool current = digitalRead(button);
  if (last != current)
  {
    delay(5);
    current = digitalRead(button);
  }
  return current;
}



int buttoncheck(unsigned long start, int b, bool lb, bool cb)
{
  if ((millis() - start) > 1000)
    return t;
  else
  {
    cb = debounce (lb, b);
    if (lb == LOW && cb == HIGH)
    {
      t++;
    }

    lb = cb;
    return (buttoncheck(start, b, lb, cb));
  }
}
void loop()
{
  cb11 = debounce(lb11, b11);
  if (lb11 == LOW && cb11 == HIGH)
  {
    alpMode = !alpMode;

  }
  lb11 = cb11;
  encvalue = analogRead(encpin);
  if (encvalue <= 341)
  {
    b1 = 0;
    b2 = 1;
    b3 = 2;
    b4 = 3;
    b5 = 4;
    b6 = 5;
    b7 = 6;
    b8 = 7;
    b9 = 8;
    b10 = 9;
  }
  if (encvalue > 341 && encvalue <= 682)
  {
    b1 = 2;
    b2 = 5;
    b3 = 4;
    b4 = 7;
    b5 = 0;
    b6 = 3;
    b7 = 8;
    b8 = 1;
    b9 = 9;
    b10 = 6;

  }
  if (encvalue > 682)
  {
    b1 = 4;
    b2 = 5;
    b3 = 0;
    b4 = 1;
    b5 = 2;
    b6 = 7;
    b7 = 9;
    b8 = 3;
    b9 = 6;
    b10 = 8;

  }



  digitalWrite (ledalp, alpMode);
  cback = debounce (lback, back);
    if (lback == LOW && cback == HIGH)
    {
      digitalWrite (laser, LOW);  
      digitalWrite (ledstat, HIGH); 
      delay(50);
      digitalWrite (laser, HIGH);
      digitalWrite (ledstat, LOW);
      

    }
    lback = cback;

  if (alpMode == true)
  {
    
     cb1 = debounce (lb1, b1);
    if (lb1 == LOW && cb1 == HIGH)
    {
      t = 0;
      t = buttoncheck(millis(), b1, lb1, cb1);
      if (t == 1)
      {


        digitalWrite (laser, LOW);
        digitalWrite (ledstat, HIGH);   
        delay(200);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(200);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(150);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
      }
      else if (t == 2)
      {

        digitalWrite (laser, LOW); 
        digitalWrite (ledstat, HIGH);  
        delay(200);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(200);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(200);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
      }
      else if (t >= 3)
      {

        digitalWrite (laser, LOW); 
        digitalWrite (ledstat, HIGH);  
        delay(200);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(250);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(200);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);

      }

    }
    lb1 = cb1;
   

    cb2 = debounce (lb2, b2);
    if (lb2 == LOW && cb2 == HIGH)
    {
      t = 0;
      t = buttoncheck(millis(), b2, lb2, cb2);
      if (t == 1)
      {

        digitalWrite (laser, LOW); 
        digitalWrite (ledstat, HIGH);   
        delay(100);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW); 

      }
      else if (t == 2)
      {

        digitalWrite (laser, LOW);
        digitalWrite (ledstat, HIGH); 
 
        delay(150);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
      }
      else if (t >= 3)
      {

        digitalWrite (laser, LOW);
        digitalWrite (ledstat, HIGH);   
        delay(200);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);


      }

    }
    lb2 = cb2;

   




    cb3 = debounce (lb3, b3);
    if (lb3 == LOW && cb3 == HIGH)
    {
      t = 0;
      t = buttoncheck(millis(), b3, lb3, cb3);
      if (t == 1)
      {

        digitalWrite (laser, LOW);  
        digitalWrite (ledstat, HIGH); 
        delay(100);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(100);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
      }
      else if (t == 2)
      {

        digitalWrite (laser, LOW);  
        digitalWrite (ledstat, HIGH); 
        delay(100);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(150);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
      }
      else if (t >= 3)
      {

        digitalWrite (laser, LOW);  
        digitalWrite (ledstat, HIGH); 
        delay(100);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(200);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);


      }

    }
    lb3 = cb3;


    cb4 = debounce (lb4, b4);
    if (lb4 == LOW && cb4 == HIGH)
    {
      t = 0;
      t = buttoncheck(millis(), b4, lb4, cb4);
      if (t == 1)
      {

        digitalWrite (laser, LOW);  
        digitalWrite (ledstat, HIGH); 
        delay(150);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(100);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
      }
      else if (t == 2)
      {

        digitalWrite (laser, LOW);  
        digitalWrite (ledstat, HIGH); 
        delay(150);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(150);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
      }
      else if (t >= 3)
      {

        digitalWrite (laser, LOW);  
        digitalWrite (ledstat, HIGH); 
        delay(150);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(200);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);


      }

    }
    lb4 = cb4;

    cb5 = debounce (lb5, b5);
    if (lb5 == LOW && cb5 == HIGH)
    {
      t = 0;
      t = buttoncheck(millis(), b5, lb5, cb5);
      if (t == 1)
      {

        digitalWrite (laser, LOW);  
        digitalWrite (ledstat, HIGH); 
        delay(200);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(100);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
      }
      else if (t == 2)
      {

        digitalWrite (laser, LOW);  
        digitalWrite (ledstat, HIGH); 
        delay(200);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(150);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
      }
      else if (t >= 3)
      {

        digitalWrite (laser, LOW);  
        digitalWrite (ledstat, HIGH); 
        delay(200);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(200);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);


      }

    }
    lb5 = cb5;

    cb6 = debounce (lb6, b6);
    if (lb6 == LOW && cb6 == HIGH)
    {
      t = 0;
      t = buttoncheck(millis(), b6, lb6, cb6);
      if (t == 1)
      {

        digitalWrite (laser, LOW);  
        digitalWrite (ledstat, HIGH); 
        delay(100);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(100);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(100);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
      }
      else if (t == 2)
      {

        digitalWrite (laser, LOW);  
        digitalWrite (ledstat, HIGH); 
        delay(100);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(100);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(150);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
      }
      else if (t >= 3)
      {

        digitalWrite (laser, LOW);  
        digitalWrite (ledstat, HIGH); 
        delay(100);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(100);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(200);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);


      }

    }
    lb6 = cb6;

    cb7 = debounce (lb7, b7);
    if (lb7 == LOW && cb7 == HIGH)
    {
      t = 0;
      t = buttoncheck(millis(), b7, lb7, cb7);
      if (t == 1)
      {

        digitalWrite (laser, LOW);  
        digitalWrite (ledstat, HIGH); 
        delay(100);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(150);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(100);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
      }
      else if (t == 2)
      {

        digitalWrite (laser, LOW);  
        digitalWrite (ledstat, HIGH); 
        delay(100);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(150);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(150);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
      }
      else if (t == 3)
      {

        digitalWrite (laser, LOW);
        digitalWrite (ledstat, HIGH);   
        delay(100);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(150);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(200);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);


      }
      else if (t >= 4)
      {
        digitalWrite (laser, LOW);  
        digitalWrite (ledstat, HIGH); 
        delay(100);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(200);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(100);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
      }

    }
    lb7 = cb7;
  


    cb8 = debounce (lb8, b8);
    if (lb8 == LOW && cb8 == HIGH)
    {
      t = 0;
      t = buttoncheck(millis(), b8, lb8, cb8);
      if (t == 1)
      {

        digitalWrite (laser, LOW);  
        digitalWrite (ledstat, HIGH); 
        delay(100);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(200);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(150);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
      }
      else if (t == 2)
      {

        digitalWrite (laser, LOW);  
        digitalWrite (ledstat, HIGH); 
        delay(100);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(200);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(200);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);

      }
      else if (t >= 3)
      {

        digitalWrite (laser, LOW);  
        digitalWrite (ledstat, HIGH); 
        delay(150);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(100);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(100);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);


      }

    }
    lb8 = cb8;


    cb9 = debounce (lb9, b9);
    if (lb9 == LOW && cb9 == HIGH)
    {
      t = 0;
      t = buttoncheck(millis(), b9, lb9, cb3);
      if (t == 1)
      {

        digitalWrite (laser, LOW);  
        digitalWrite (ledstat, HIGH); 
        delay(150);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(100);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(150);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
      }
      else if (t == 2)
      {

        digitalWrite (laser, LOW);
        digitalWrite (ledstat, HIGH);   
        delay(150);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(100);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(200);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
      }
      else if (t == 3)
      {

        digitalWrite (laser, LOW);  
        digitalWrite (ledstat, HIGH); 
        delay(150);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(150);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(100);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);


      }
      else if (t >= 4)
      {
        digitalWrite (laser, LOW);  
        digitalWrite (ledstat, HIGH); 
        delay(150);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(150);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(150);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
      }

    }
    lb9 = cb9;


    cb10 = debounce (lb10, b10);
    if (lb10 == LOW && cb10 == HIGH)
    {
      t = 0;
      t = buttoncheck(millis(), b10, lb10, cb10);
      if (t == 1)
      {

        digitalWrite (laser, LOW);  
        digitalWrite (ledstat, HIGH); 
        delay(200);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(200);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(100);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
      }
      else if (t == 2)
      {

        digitalWrite (laser, LOW);
        digitalWrite (ledstat, HIGH);   
        delay(200);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(50);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(50);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
      }
      else if (t == 3)
      {

        digitalWrite (laser, LOW);  
        digitalWrite (ledstat, HIGH); 
        delay(200);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(50);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(100);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);



      }
      else if (t >= 4)
      {
        digitalWrite (laser, LOW);
        digitalWrite (ledstat, HIGH);   
        delay(200);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(50);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
        delay(100);
        digitalWrite(laser , LOW);
        digitalWrite (ledstat, HIGH); 
        delay(150);
        digitalWrite (laser, HIGH);
        digitalWrite (ledstat, LOW);
      }





    }
    lb10 = cb10;

  }
  else
  {

    
    cb1 = debounce (lb1, b1);
    if (lb1 == LOW && cb1 == HIGH)
    {
      digitalWrite (laser, LOW);  
      digitalWrite (ledstat, HIGH); 
      delay(150);
      digitalWrite (laser, HIGH);
      digitalWrite (ledstat, LOW);
      delay(100);
      digitalWrite(laser , LOW);
      digitalWrite (ledstat, HIGH); 
      delay(200);
      digitalWrite (laser, HIGH);
      digitalWrite (ledstat, LOW);
      delay(100);
      digitalWrite(laser , LOW);
      digitalWrite (ledstat, HIGH); 
      delay(100);
      digitalWrite (laser, HIGH);
      digitalWrite (ledstat, LOW);


    }
    lb1 = cb1;
    






    cb2 = debounce (lb2, b2);
    if (lb2 == LOW && cb2 == HIGH)
    {
      digitalWrite (laser, LOW);  
      digitalWrite (ledstat, HIGH); 
      delay(150);
      digitalWrite (laser, HIGH);
      digitalWrite (ledstat, LOW);
      delay(100);
      digitalWrite(laser , LOW);
      digitalWrite (ledstat, HIGH); 
      delay(200);
      digitalWrite (laser, HIGH);
      digitalWrite (ledstat, LOW);
      delay(100);
      digitalWrite(laser , LOW);
      digitalWrite (ledstat, HIGH); 
      delay(150);
      digitalWrite (laser, HIGH);
      digitalWrite (ledstat, LOW);


    }
    lb2 = cb2;


    cb3 = debounce (lb3, b3);
    if (lb3 == LOW && cb3 == HIGH)
    {
      digitalWrite (laser, LOW);
      digitalWrite (ledstat, HIGH);   
      delay(150);
      digitalWrite (laser, HIGH);
      digitalWrite (ledstat, LOW);
      delay(100);
      digitalWrite(laser , LOW);
      digitalWrite (ledstat, HIGH); 
      delay(200);
      digitalWrite (laser, HIGH);
      digitalWrite (ledstat, LOW);
      delay(100);
      digitalWrite(laser , LOW);
      digitalWrite (ledstat, HIGH); 
      delay(200);
      digitalWrite (laser, HIGH);
      digitalWrite (ledstat, LOW);


    }
    lb3 = cb3;


    cb4 = debounce (lb4, b4);
    if (lb4 == LOW && cb4 == HIGH)
    {
      digitalWrite (laser, LOW);  
      digitalWrite (ledstat, HIGH); 
      delay(200);
      digitalWrite (laser, HIGH);
      digitalWrite (ledstat, LOW);
      delay(100);
      digitalWrite(laser , LOW);
      digitalWrite (ledstat, HIGH); 
      delay(100);
      digitalWrite (laser, HIGH);
      digitalWrite (ledstat, LOW);
      delay(100);
      digitalWrite(laser , LOW);
      digitalWrite (ledstat, HIGH); 
      delay(100);
      digitalWrite (laser, HIGH);
      digitalWrite (ledstat, LOW);


    }
    lb4 = cb4;

    cb5 = debounce (lb5, b5);
    if (lb5 == LOW && cb5 == HIGH)
    {
      digitalWrite (laser, LOW);  
      digitalWrite (ledstat, HIGH); 
      delay(200);
      digitalWrite (laser, HIGH);
      digitalWrite (ledstat, LOW);
      delay(100);
      digitalWrite(laser , LOW);
      digitalWrite (ledstat, HIGH); 
      delay(100);
      digitalWrite (laser, HIGH);
      digitalWrite (ledstat, LOW);
      delay(100);
      digitalWrite(laser , LOW);
      digitalWrite (ledstat, HIGH); 
      delay(150);
      digitalWrite (laser, HIGH);
      digitalWrite (ledstat, LOW);


    }
    lb5 = cb5;


    cb6 = debounce (lb6, b6);
    if (lb6 == LOW && cb6 == HIGH)
    {
      digitalWrite (laser, LOW);  
      digitalWrite (ledstat, HIGH); 
      delay(200);
      digitalWrite (laser, HIGH);
      digitalWrite (ledstat, LOW);
      delay(100);
      digitalWrite(laser , LOW);
      digitalWrite (ledstat, HIGH); 
      delay(100);
      digitalWrite (laser, HIGH);
      digitalWrite (ledstat, LOW);
      delay(100);
      digitalWrite(laser , LOW);
      digitalWrite (ledstat, HIGH); 
      delay(200);
      digitalWrite (laser, HIGH);
      digitalWrite (ledstat, LOW);

    }
    lb6 = cb6;


    cb7 = debounce (lb7, b7);
    if (lb7 == LOW && cb7 == HIGH)
    {
      digitalWrite (laser, LOW);  
      digitalWrite (ledstat, HIGH); 
      delay(200);
      digitalWrite (laser, HIGH);
      digitalWrite (ledstat, LOW);
      delay(100);
      digitalWrite(laser , LOW);
      digitalWrite (ledstat, HIGH); 
      delay(150);
      digitalWrite (laser, HIGH);
      digitalWrite (ledstat, LOW);
      delay(100);
      digitalWrite(laser , LOW);
      digitalWrite (ledstat, HIGH); 
      delay(100);
      digitalWrite (laser, HIGH);
      digitalWrite (ledstat, LOW);


    }
    lb7 = cb7;
    

    cb8 = debounce (lb8, b8);
    if (lb8 == LOW && cb8 == HIGH)
    {
      digitalWrite (laser, LOW);  
      digitalWrite (ledstat, HIGH); 
      delay(200);
      digitalWrite (laser, HIGH);
      digitalWrite (ledstat, LOW);
      delay(100);
      digitalWrite(laser , LOW);
      digitalWrite (ledstat, HIGH); 
      delay(150);
      digitalWrite (laser, HIGH);
      digitalWrite (ledstat, LOW);
      delay(100);
      digitalWrite(laser , LOW);
      digitalWrite (ledstat, HIGH); 
      delay(150);
      digitalWrite (laser, HIGH);
      digitalWrite (ledstat, LOW);


    }
    lb8 = cb8;


    cb9 = debounce (lb9, b9);
    if (lb9 == LOW && cb9 == HIGH)
    {

      digitalWrite (laser, LOW);  
      digitalWrite (ledstat, HIGH); 
      delay(200);
      digitalWrite (laser, HIGH);
      digitalWrite (ledstat, LOW);
      delay(100);
      digitalWrite(laser , LOW);
      digitalWrite (ledstat, HIGH); 
      delay(150);
      digitalWrite (laser, HIGH);
      digitalWrite (ledstat, LOW);
      delay(100);
      digitalWrite(laser , LOW);
      digitalWrite (ledstat, HIGH); 
      delay(200);
      digitalWrite (laser, HIGH);
      digitalWrite (ledstat, LOW);






    }
    lb9 = cb9;

    cb10 = debounce (lb10, b10);
    if (lb10 == LOW && cb10 == HIGH)
    {
      digitalWrite (laser, LOW);
      digitalWrite (ledstat, HIGH); 
      delay(150);
      digitalWrite (laser, HIGH);
      digitalWrite (ledstat, LOW);
      delay(100);
      digitalWrite(laser , LOW);
      digitalWrite (ledstat, HIGH); 
      delay(150);
      digitalWrite (laser, HIGH);
      digitalWrite (ledstat, LOW);
      delay(100);
      digitalWrite(laser , LOW);
      digitalWrite (ledstat, HIGH); 
      delay(200);
      digitalWrite (laser, HIGH);
      digitalWrite (ledstat, LOW);


    }
    lb10 = cb10;






  }
  digitalWrite (laser, 1);
  digitalWrite (ledstat, 0); 
}