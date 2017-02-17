
#include <Adafruit_GFX.h>
#include <TouchScreen.h>
#include <Adafruit_TFTLCD.h>

#define YP A3  // must be an analog pin, use "An" notation!
#define XM A2  // must be an analog pin, use "An" notation!
#define YM 9   // can be a digital pin
#define XP 8   // can be a digital pin

/*#define TS_MINX 210
  #define TS_MINY 210
  #define TS_MAXX 915
  #define TS_MAXY 910*/

#define TS_MINX 210
#define TS_MINY 210
#define TS_MAXX 915
#define TS_MAXY 910

//SPI Communication
#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
// optional
#define LCD_RESET A4

//Color Definitons
#define BLACK 0x0000
#define ORANGE2 0xFCA0

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 364);

int X, Y, Z;

int choice = 0;

int fill = 0;

void touchscreen();
void placement();
void do1();
void do2();
void do3();
void cross1();
void cross2();
void cross3();
void cross4();
void cross5();
void cross6();
void cross7();
void cross8();
void cross9();
void cross10();
void cross11();
void cross12();

void setup() {
  Serial.begin(9600);


  tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);

  digitalWrite(13, HIGH);
  TSPoint p = ts.getPoint();
  digitalWrite(13, LOW);

  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);

  X = tft.width() - map(p.x, TS_MAXX, TS_MINX, 0, tft.width());
  Y = map(p.y, TS_MAXY, TS_MINY, 0, tft.height());
  Z = p.z;

  tft.fillScreen(ORANGE2);

}

void loop() {

  switch (choice) {

    case 0:
      fill = 0; X = 0; Y = 0;
      placement();
      break;

    case 1:
      fill = 0; X = 0; Y = 0;
      do1();
      break;

    case 2:
      fill = 0; X = 0; Y = 0;
      do2();
      break;

    case 3:
      fill = 0; X = 0; Y = 0;
      do3();
      break;

    case 4:
      fill = 0; X = 0; Y = 0;
      cross1();
      break;

    case 5:
      fill = 0; X = 0; Y = 0;
      cross2();
      break;

    case 6:
      fill = 0; X = 0; Y = 0;
      cross3();
      break;

    case 7:
      fill = 0; X = 0; Y = 0;
      cross4();
      break;

    case 8:
      fill = 0; X = 0; Y = 0;
      cross5();
      break;

    case 9:
      fill = 0; X = 0; Y = 0;
      cross6();
      break;

    case 10:
      fill = 0; X = 0; Y = 0;
      cross7();
      break;

    case 11:
      fill = 0; X = 0; Y = 0;
      cross8();
      break;

    case 12:
      fill = 0; X = 0; Y = 0;
      cross9();
      break;

    case 13:
      fill = 0; X = 0; Y = 0;
      cross10();
      break;

    case 14:
      fill = 0; X = 0; Y = 0;
      cross11();
      break;

    case 15:
      fill = 0; X = 0; Y = 0;
      cross12();
      break;
  }





  /*
    if(fill == 0)//start
    {
      tft.fillScreen(ORANGE2);
      tft.setCursor(10,10);
      //(starting X, starting Y, Ending X, Ending Y, Color
      tft.fillRect(5, 5, 107, 20, BLACK);
      tft.println("position 1");
      tft.setCursor(10,35);
      tft.fillRect(5, 30, 107, 20, BLACK);
      tft.println("position 2");
      tft.setCursor(10,60);
      tft.fillRect(5, 55, 107, 20, BLACK);
      tft.println("position 3");
      fill = 1;
    }
    if(fill == 2


      touchscreen();
      if(X >= 5 && X <= 107 && Y >= 5 && Y <= 20)//placement 1
      {
        tft.setCursor(5,50);
        tft.fillScreen(BLACK);
        tft.println("Thank you for pressing the first button");
        fill = 2;
        delay(5000);
      }
      if(X >= 5 && X <= 107 && Y >= 30 && Y <=  40 )//placement 2
      {
        tft.setCursor(50,50);
        tft.fillScreen(BLACK);
        tft.println("Good choice");
        fill = 2;
        delay(5000);
      }
      if(X >= 5 && X <= 107 && Y >= 55 && Y <= 60)//placement 3
      {
        tft.setCursor(5,50);
        tft.fillScreen(BLACK);
        tft.println("You pressed the right button!");
        fill = 2;
        delay(5000);
      }
  */
}

void placement()
{
  while (choice == 0)
  {
    while (fill == 0)
    {
      //240x320 pixel
      tft.fillScreen(ORANGE2);
      tft.setCursor(10, 10);
      //(starting X, starting Y, Ending X, Ending Y, Color
      tft.fillRect(5, 5, 107, 30, BLACK);
      tft.println("position 1");
      tft.setCursor(10, 45);
      tft.fillRect(5, 40, 107, 30, BLACK);
      tft.println("position 2");
      tft.setCursor(10, 80);
      tft.fillRect(5, 75, 107, 30, BLACK);
      tft.println("position 3");
      fill = 1;
    }
    if (fill == 1)
    {
      touchscreen();
      Serial.println(Y);
      if (X >= 5 && X <= 107 && Y >= 5 && Y <= 35) //placement 1
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("You chose position 1");
        choice = 1;
        delay(2000);
        fill = 1;
      }
      if (X >= 5 && X <= 107 && Y >= 40 && Y <= 70) //placement 2
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("You chose position 2");
        choice = 2;
        delay(2000);
        fill = 2;
      }
      if (X >= 5 && X <= 107 && Y >= 75 && Y <= 105) //placement 3
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("You chose position 3");
        choice = 3;
        delay(2000);
        fill = 3;
      }
    }
  }
}

void do1()
{ fill = 0;
  while (choice == 1)
  {
    while (fill == 0)
    {
      //240x320 pixel
      tft.fillScreen(ORANGE2);
      tft.setCursor(10, 10);
      //(starting X, starting Y, Ending X, Ending Y, Color
      tft.fillRect(5, 5, 107, 30, BLACK);
      tft.println("Cancel");
      tft.setCursor(10, 45);
      tft.fillRect(5, 40, 107, 30, BLACK);
      tft.println("Shoot");
      tft.setCursor(10, 80);
      tft.fillRect(5, 75, 107, 30, BLACK);
      tft.println("Dump");
      tft.setCursor(122, 10);
      tft.fillRect(117, 5, 107, 30, BLACK);
      tft.println("Gear");
      tft.setCursor(122, 45);
      tft.fillRect(117, 40, 107, 30, BLACK);
      tft.println("Mixed");
      fill = 1;
    }
    touchscreen();
    Serial.println(X);
    if (fill == 1)
    {
      if (X >= 5 && X <= 107 && Y >= 5 && Y <= 35)// cancel
      {
        tft.fillScreen(BLACK);
        tft.println("Going back");
        delay(2000);
        fill = 0;
        choice = 0;
      }
      if (X >= 5 && X <= 107 && Y >= 40 && Y <= 70) //shoot
      {
        tft.fillScreen(BLACK);
        tft.println("You chose to shoot balls");
        delay(2000);
        fill = 0;
        choice = 4;
      }
      if (X >= 5 && X <= 107 && Y >= 75 && Y <= 105) //dump
      {
        tft.fillScreen(BLACK);
        tft.println("You chose to dump balls");
        delay(2000);
        fill = 0;
        choice = 5;
      }
      if (X >= 117 && X <= 224 && Y >= 5 && Y <= 35) //gear
      {
        tft.fillScreen(BLACK);
        tft.println("You chose to place gears");
        delay(2000);
        fill = 0;
        choice = 6;
      }
      if (X >= 117 && X <= 224 && Y >= 40 && Y <= 70) //mixed
      {
        tft.fillScreen(BLACK);
        tft.println("You chose mixed");
        delay(2000);
        fill = 0;
        choice = 7;
      }
    }
  }
}
void do2()
{ fill = 0;
  while (choice == 2)
  {
    while (fill == 0)
    {
      //240x320 pixel
      tft.fillScreen(ORANGE2);
      tft.setCursor(10, 10);
      //(starting X, starting Y, Ending X, Ending Y, Color
      tft.fillRect(5, 5, 107, 30, BLACK);
      tft.println("Cancel");
      tft.setCursor(10, 45);
      tft.fillRect(5, 40, 107, 30, BLACK);
      tft.println("Shoot");
      tft.setCursor(10, 80);
      tft.fillRect(5, 75, 107, 30, BLACK);
      tft.println("Dump");
      tft.setCursor(122, 10);
      tft.fillRect(117, 5, 107, 30, BLACK);
      tft.println("Gear");
      tft.setCursor(122, 45);
      tft.fillRect(117, 40, 107, 30, BLACK);
      tft.println("Mixed");
      fill = 1;
    }
    touchscreen();
    Serial.println(X);
    if (fill == 1)
    {
      if (X >= 5 && X <= 107 && Y >= 5 && Y <= 35)// cancel
      {
        tft.fillScreen(BLACK);
        tft.println("Going back");
        delay(2000);
        fill = 0;
        choice = 0;
      }
      if (X >= 5 && X <= 107 && Y >= 40 && Y <= 70) //shoot
      {
        tft.fillScreen(BLACK);
        tft.println("You chose to shoot balls");
        delay(2000);
        fill = 0;
        choice = 8;
      }
      if (X >= 5 && X <= 107 && Y >= 75 && Y <= 105) //dump
      {
        tft.fillScreen(BLACK);
        tft.println("You chose to dump balls");
        delay(2000);
        fill = 0;
        choice = 9;
      }
      if (X >= 117 && X <= 224 && Y >= 5 && Y <= 35) //gear
      {
        tft.fillScreen(BLACK);
        tft.println("You chose to place gears");
        delay(2000);
        fill = 0;
        choice = 10;
      }
      if (X >= 117 && X <= 224 && Y >= 40 && Y <= 70) //mixed
      {
        tft.fillScreen(BLACK);
        tft.println("You chose mixed");
        delay(2000);
        fill = 0;
        choice = 11;
      }
    }
  }
}
void do3()
{ fill = 0;
  while (choice == 3)
  {
    while (fill == 0)
    {
      //240x320 pixel
      tft.fillScreen(ORANGE2);
      tft.setCursor(10, 10);
      //(starting X, starting Y, Ending X, Ending Y, Color
      tft.fillRect(5, 5, 107, 30, BLACK);
      tft.println("Cancel");
      tft.setCursor(10, 45);
      tft.fillRect(5, 40, 107, 30, BLACK);
      tft.println("Shoot");
      tft.setCursor(10, 80);
      tft.fillRect(5, 75, 107, 30, BLACK);
      tft.println("Dump");
      tft.setCursor(122, 10);
      tft.fillRect(117, 5, 107, 30, BLACK);
      tft.println("Gear");
      tft.setCursor(122, 45);
      tft.fillRect(117, 40, 107, 30, BLACK);
      tft.println("Mixed");
      fill = 1;
    }
    touchscreen();
    Serial.println(X);
    if (fill == 1)
    {
      if (X >= 5 && X <= 107 && Y >= 5 && Y <= 35)// cancel
      {
        tft.fillScreen(BLACK);
        tft.println("Going back");
        delay(2000);
        fill = 0;
        choice = 0;
      }
      if (X >= 5 && X <= 107 && Y >= 40 && Y <= 70) //shoot
      {
        tft.fillScreen(BLACK);
        tft.println("You chose to shoot balls");
        delay(2000);
        fill = 0;
        choice = 12;
      }
      if (X >= 5 && X <= 107 && Y >= 75 && Y <= 105) //dump
      {
        tft.fillScreen(BLACK);
        tft.println("You chose to dump balls");
        delay(2000);
        fill = 0;
        choice = 13;
      }
      if (X >= 117 && X <= 224 && Y >= 5 && Y <= 35) //gear
      {
        tft.fillScreen(BLACK);
        tft.println("You chose to place gears");
        delay(2000);
        fill = 0;
        choice = 14;
      }
      if (X >= 117 && X <= 224 && Y >= 40 && Y <= 70) //mixed
      {
        tft.fillScreen(BLACK);
        tft.println("You chose mixed");
        delay(2000);
        fill = 0;
        choice = 15;
      }
    }
  }
}
void cross1()
{
  while (choice == 4)
  {
    while (fill == 0)
    {
      //240x320 pixel
      tft.fillScreen(ORANGE2);
      tft.setCursor(10, 10);
      //(starting X, starting Y, Ending X, Ending Y, Color
      tft.fillRect(5, 5, 107, 30, BLACK);
      tft.println("Cancel");
      tft.setCursor(10, 45);
      tft.fillRect(5, 40, 107, 30, BLACK);
      tft.println("Cross line");
      tft.setCursor(10, 80);
      tft.fillRect(5, 75, 107, 30, BLACK);
      tft.println("not cross line");
      fill = 1;
    }
    if (fill == 1)
    {
      touchscreen();
      Serial.println(Y);
      if (X >= 5 && X <= 107 && Y >= 5 && Y <= 35) //Cancel
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("Going back");
        choice = 0;
        delay(2000);
        fill = 1;
      }
      if (X >= 5 && X <= 107 && Y >= 40 && Y <= 70) //Yes
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("Crossing");
        delay(2000);
        fill = 0; //returns daya to robo rio #16
      }
      if (X >= 5 && X <= 107 && Y >= 75 && Y <= 105) //No
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("Not crossing");
        delay(2000);
        fill = 0; // gives data to robo rio #17
      }
    }
  }
}
void cross2()
{
  while (choice == 5)
  {
    while (fill == 0)
    {
      //240x320 pixel
      tft.fillScreen(ORANGE2);
      tft.setCursor(10, 10);
      //(starting X, starting Y, Ending X, Ending Y, Color
      tft.fillRect(5, 5, 107, 30, BLACK);
      tft.println("Cancel");
      tft.setCursor(10, 45);
      tft.fillRect(5, 40, 107, 30, BLACK);
      tft.println("Cross line");
      tft.setCursor(10, 80);
      tft.fillRect(5, 75, 107, 30, BLACK);
      tft.println("not cross line");
      fill = 1;
    }
    if (fill == 1)
    {
      touchscreen();
      Serial.println(Y);
      if (X >= 5 && X <= 107 && Y >= 5 && Y <= 35) //Cancel
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("Going back");
        choice = 0;
        delay(2000);
        fill = 1;
      }
      if (X >= 5 && X <= 107 && Y >= 40 && Y <= 70) //Yes
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("Crossing");
        delay(2000);
        fill = 0; //returns daya to robo rio #18
      }
      if (X >= 5 && X <= 107 && Y >= 75 && Y <= 105) //No
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("Not crossing");
        delay(2000);
        fill = 0; // gives data to robo rio #19
      }
    }
  }
}
void cross3()
{
  while (choice == 6)
  {
    while (fill == 0)
    {
      //240x320 pixel
      tft.fillScreen(ORANGE2);
      tft.setCursor(10, 10);
      //(starting X, starting Y, Ending X, Ending Y, Color
      tft.fillRect(5, 5, 107, 30, BLACK);
      tft.println("Cancel");
      tft.setCursor(10, 45);
      tft.fillRect(5, 40, 107, 30, BLACK);
      tft.println("Cross line");
      tft.setCursor(10, 80);
      tft.fillRect(5, 75, 107, 30, BLACK);
      tft.println("not cross line");
      fill = 1;
    }
    if (fill == 1)
    {
      touchscreen();
      Serial.println(Y);
      if (X >= 5 && X <= 107 && Y >= 5 && Y <= 35) //Cancel
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("Going back");
        choice = 0;
        delay(2000);
        fill = 1;
      }
      if (X >= 5 && X <= 107 && Y >= 40 && Y <= 70) //Yes
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("Crossing");
        delay(2000);
        fill = 0; //returns daya to robo rio #20
      }
      if (X >= 5 && X <= 107 && Y >= 75 && Y <= 105) //No
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("Not crossing");
        delay(2000);
        fill = 0; // gives data to robo rio #21
      }
    }
  }
}
void cross4()
{
  while (choice == 7)
  {
    while (fill == 0)
    {
      //240x320 pixel
      tft.fillScreen(ORANGE2);
      tft.setCursor(10, 10);
      //(starting X, starting Y, Ending X, Ending Y, Color
      tft.fillRect(5, 5, 107, 30, BLACK);
      tft.println("Cancel");
      tft.setCursor(10, 45);
      tft.fillRect(5, 40, 107, 30, BLACK);
      tft.println("Cross line");
      tft.setCursor(10, 80);
      tft.fillRect(5, 75, 107, 30, BLACK);
      tft.println("not cross line");
      fill = 1;
    }
    if (fill == 1)
    {
      touchscreen();
      Serial.println(Y);
      if (X >= 5 && X <= 107 && Y >= 5 && Y <= 35) //Cancel
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("Going back");
        choice = 0;
        delay(2000);
        fill = 1;
      }
      if (X >= 5 && X <= 107 && Y >= 40 && Y <= 70) //Yes
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("Crossing");
        delay(2000);
        fill = 0; //returns daya to robo rio #22
      }
      if (X >= 5 && X <= 107 && Y >= 75 && Y <= 105) //No
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("Not crossing");
        delay(2000);
        fill = 0; // gives data to robo rio #23
      }
    }
  }
}
void cross5()
{
  while (choice == 8)
  {
    while (fill == 0)
    {
      //240x320 pixel
      tft.fillScreen(ORANGE2);
      tft.setCursor(10, 10);
      //(starting X, starting Y, Ending X, Ending Y, Color
      tft.fillRect(5, 5, 107, 30, BLACK);
      tft.println("Cancel");
      tft.setCursor(10, 45);
      tft.fillRect(5, 40, 107, 30, BLACK);
      tft.println("Cross line");
      tft.setCursor(10, 80);
      tft.fillRect(5, 75, 107, 30, BLACK);
      tft.println("not cross line");
      fill = 1;
    }
    if (fill == 1)
    {
      touchscreen();
      Serial.println(Y);
      if (X >= 5 && X <= 107 && Y >= 5 && Y <= 35) //Cancel
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("Going back");
        choice = 0;
        delay(2000);
        fill = 1;
      }
      if (X >= 5 && X <= 107 && Y >= 40 && Y <= 70) //Yes
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("Crossing");
        delay(2000);
        fill = 0; //returns daya to robo rio #24
      }
      if (X >= 5 && X <= 107 && Y >= 75 && Y <= 105) //No
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("Not crossing");
        delay(2000);
        fill = 0; // gives data to robo rio #25
      }
    }
  }
}
void cross6()
{
  while (choice == 9)
  {
    while (fill == 0)
    {
      //240x320 pixel
      tft.fillScreen(ORANGE2);
      tft.setCursor(10, 10);
      //(starting X, starting Y, Ending X, Ending Y, Color
      tft.fillRect(5, 5, 107, 30, BLACK);
      tft.println("Cancel");
      tft.setCursor(10, 45);
      tft.fillRect(5, 40, 107, 30, BLACK);
      tft.println("Cross line");
      tft.setCursor(10, 80);
      tft.fillRect(5, 75, 107, 30, BLACK);
      tft.println("not cross line");
      fill = 1;
    }
    if (fill == 1)
    {
      touchscreen();
      Serial.println(Y);
      if (X >= 5 && X <= 107 && Y >= 5 && Y <= 35) //Cancel
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("Going back");
        choice = 0;
        delay(2000);
        fill = 1;
      }
      if (X >= 5 && X <= 107 && Y >= 40 && Y <= 70) //Yes
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("Crossing");
        delay(2000);
        fill = 0; //returns daya to robo rio #26
      }
      if (X >= 5 && X <= 107 && Y >= 75 && Y <= 105) //No
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("Not crossing");
        delay(2000);
        fill = 0; // gives data to robo rio #27
      }
    }
  }
}
void cross7()
{
  while (choice == 10)
  {
    while (fill == 0)
    {
      //240x320 pixel
      tft.fillScreen(ORANGE2);
      tft.setCursor(10, 10);
      //(starting X, starting Y, Ending X, Ending Y, Color
      tft.fillRect(5, 5, 107, 30, BLACK);
      tft.println("Cancel");
      tft.setCursor(10, 45);
      tft.fillRect(5, 40, 107, 30, BLACK);
      tft.println("Cross line");
      tft.setCursor(10, 80);
      tft.fillRect(5, 75, 107, 30, BLACK);
      tft.println("not cross line");
      fill = 1;
    }
    if (fill == 1)
    {
      touchscreen();
      Serial.println(Y);
      if (X >= 5 && X <= 107 && Y >= 5 && Y <= 35) //Cancel
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("Going back");
        choice = 0;
        delay(2000);
        fill = 1;
      }
      if (X >= 5 && X <= 107 && Y >= 40 && Y <= 70) //Yes
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("Crossing");
        delay(2000);
        fill = 0; //returns daya to robo rio #28
      }
      if (X >= 5 && X <= 107 && Y >= 75 && Y <= 105) //No
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("Not crossing");
        delay(2000);
        fill = 0; // gives data to robo rio #29
      }
    }
  }
}
void cross8()
{
  while (choice == 11)
  {
    while (fill == 0)
    {
      //240x320 pixel
      tft.fillScreen(ORANGE2);
      tft.setCursor(10, 10);
      //(starting X, starting Y, Ending X, Ending Y, Color
      tft.fillRect(5, 5, 107, 30, BLACK);
      tft.println("Cancel");
      tft.setCursor(10, 45);
      tft.fillRect(5, 40, 107, 30, BLACK);
      tft.println("Cross line");
      tft.setCursor(10, 80);
      tft.fillRect(5, 75, 107, 30, BLACK);
      tft.println("not cross line");
      fill = 1;
    }
    if (fill == 1)
    {
      touchscreen();
      Serial.println(Y);
      if (X >= 5 && X <= 107 && Y >= 5 && Y <= 35) //Cancel
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("Going back");
        choice = 0;
        delay(2000);
        fill = 1;
      }
      if (X >= 5 && X <= 107 && Y >= 40 && Y <= 70) //Yes
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("Crossing");
        delay(2000);
        fill = 0; //returns daya to robo rio #30
      }
      if (X >= 5 && X <= 107 && Y >= 75 && Y <= 105) //No
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("Not crossing");
        delay(2000);
        fill = 0; // gives data to robo rio #31
      }
    }
  }
}
void cross9()
{
  while (choice == 12)
  {
    while (fill == 0)
    {
      //240x320 pixel
      tft.fillScreen(ORANGE2);
      tft.setCursor(10, 10);
      //(starting X, starting Y, Ending X, Ending Y, Color
      tft.fillRect(5, 5, 107, 30, BLACK);
      tft.println("Cancel");
      tft.setCursor(10, 45);
      tft.fillRect(5, 40, 107, 30, BLACK);
      tft.println("Cross line");
      tft.setCursor(10, 80);
      tft.fillRect(5, 75, 107, 30, BLACK);
      tft.println("not cross line");
      fill = 1;
    }
    if (fill == 1)
    {
      touchscreen();
      Serial.println(Y);
      if (X >= 5 && X <= 107 && Y >= 5 && Y <= 35) //Cancel
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("Going back");
        choice = 0;
        delay(2000);
        fill = 1;
      }
      if (X >= 5 && X <= 107 && Y >= 40 && Y <= 70) //Yes
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("Crossing");
        delay(2000);
        fill = 0; //returns daya to robo rio #32
      }
      if (X >= 5 && X <= 107 && Y >= 75 && Y <= 105) //No
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("Not crossing");
        delay(2000);
        fill = 0; // gives data to robo rio #33
      }
    }
  }
}
void cross10()
{
  while (choice == 13)
  {
    while (fill == 0)
    {
      //240x320 pixel
      tft.fillScreen(ORANGE2);
      tft.setCursor(10, 10);
      //(starting X, starting Y, Ending X, Ending Y, Color
      tft.fillRect(5, 5, 107, 30, BLACK);
      tft.println("Cancel");
      tft.setCursor(10, 45);
      tft.fillRect(5, 40, 107, 30, BLACK);
      tft.println("Cross line");
      tft.setCursor(10, 80);
      tft.fillRect(5, 75, 107, 30, BLACK);
      tft.println("not cross line");
      fill = 1;
    }
    if (fill == 1)
    {
      touchscreen();
      Serial.println(Y);
      if (X >= 5 && X <= 107 && Y >= 5 && Y <= 35) //Cancel
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("Going back");
        choice = 0;
        delay(2000);
        fill = 1;
      }
      if (X >= 5 && X <= 107 && Y >= 40 && Y <= 70) //Yes
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("Crossing");
        delay(2000);
        fill = 0; //returns daya to robo rio #34
      }
      if (X >= 5 && X <= 107 && Y >= 75 && Y <= 105) //No
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("Not crossing");
        delay(2000);
        fill = 0; // gives data to robo rio #35
      }
    }
  }
}
void cross11()
{
  while (choice == 14)
  {
    while (fill == 0)
    {
      //240x320 pixel
      tft.fillScreen(ORANGE2);
      tft.setCursor(10, 10);
      //(starting X, starting Y, Ending X, Ending Y, Color
      tft.fillRect(5, 5, 107, 30, BLACK);
      tft.println("Cancel");
      tft.setCursor(10, 45);
      tft.fillRect(5, 40, 107, 30, BLACK);
      tft.println("Cross line");
      tft.setCursor(10, 80);
      tft.fillRect(5, 75, 107, 30, BLACK);
      tft.println("not cross line");
      fill = 1;
    }
    if (fill == 1)
    {
      touchscreen();
      Serial.println(Y);
      if (X >= 5 && X <= 107 && Y >= 5 && Y <= 35) //Cancel
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("Going back");
        choice = 0;
        delay(2000);
        fill = 1;
      }
      if (X >= 5 && X <= 107 && Y >= 40 && Y <= 70) //Yes
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("Crossing");
        delay(2000);
        fill = 0; //returns daya to robo rio #36
      }
      if (X >= 5 && X <= 107 && Y >= 75 && Y <= 105) //No
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("Not crossing");
        delay(2000);
        fill = 0; // gives data to robo rio #37
      }
    }
  }
}
void cross12()
{
  while (choice == 15)
  {
    while (fill == 0)
    {
      //240x320 pixel
      tft.fillScreen(ORANGE2);
      tft.setCursor(10, 10);
      //(starting X, starting Y, Ending X, Ending Y, Color
      tft.fillRect(5, 5, 107, 30, BLACK);
      tft.println("Cancel");
      tft.setCursor(10, 45);
      tft.fillRect(5, 40, 107, 30, BLACK);
      tft.println("Cross line");
      tft.setCursor(10, 80);
      tft.fillRect(5, 75, 107, 30, BLACK);
      tft.println("not cross line");
      fill = 1;
    }
    if (fill == 1)
    {
      touchscreen();
      Serial.println(Y);
      if (X >= 5 && X <= 107 && Y >= 5 && Y <= 35) //Cancel
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("Going back");
        choice = 0;
        delay(2000);
        fill = 1;
      }
      if (X >= 5 && X <= 107 && Y >= 40 && Y <= 70) //Yes
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("Crossing");
        delay(2000);
        fill = 0; //returns daya to robo rio #38
      }
      if (X >= 5 && X <= 107 && Y >= 75 && Y <= 105) //No
      {
        Serial.println(Y);
        tft.fillScreen(BLACK);
        tft.println("Not crossing");
        delay(2000);
        fill = 0; // gives data to robo rio #39
      }
    }
  }
}

void touchscreen()
{

  digitalWrite(13, HIGH);
  TSPoint p = ts.getPoint();
  digitalWrite(13, LOW);

  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);

  X = tft.width() - map(p.x, TS_MAXX, TS_MINX, 0, tft.width());
  Y = map(p.y, TS_MAXY, TS_MINY, 0, tft.height());
  Z = p.z;

  //X = map(p.x, 0, 4095, 0, tft.width());
  //Y = map(p.y, 0, 4095, 0, tft.height());
}

