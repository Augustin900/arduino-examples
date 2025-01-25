#include <Wire.h>
#include <LiquidCrystal.h>
const int rs = 11, en = 8, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int i=0;
int j=0;
int randomnum;
int z=0;
int k=0;

byte customChar[] = {
  0x18,
  0x18,
  0x1B,
  0x1B,
  0x1B,
  0x1B,
  0x1B,
  0x1B
};

byte customChar1[] = {
  0x00,
  0x00,
  0x18,
  0x18,
  0x1B,
  0x1B,
  0x1B,
  0x1B
};

byte customChar2[] = {
  0x00,
  0x00,
  0x00,
  0x00,
  0x18,
  0x18,
  0x1B,
  0x1B
};

byte customChar3[] = {
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x18,
  0x18
};

byte customChar4[] = {
  0x00,
  0x00,
  0x03,
  0x03,
  0x1B,
  0x1B,
  0x1B,
  0x1B
};

byte customChar5[] = {
  0x00,
  0x00,
  0x00,
  0x00,
  0x03,
  0x03,
  0x1B,
  0x1B
};

byte customChar6[] = {
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x03,
  0x03
};

byte customChar7[] = {
  0x1B,
  0x1B,
  0x1B,
  0x1B,
  0x1B,
  0x1B,
  0x1B,
  0x1B
};

byte customChar8[] = {
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00
};
void setup() {
  Serial.begin(9600);
 
  lcd.begin(16,2);
  lcd.createChar(0, customChar);
  lcd.createChar(1, customChar1);
  lcd.createChar(2, customChar2);
  lcd.createChar(3, customChar3);
  lcd.createChar(4, customChar4);
  lcd.createChar(5, customChar5);
  lcd.createChar(6, customChar6);
  lcd.createChar(7, customChar7);
  lcd.clear();
}

void loop() { 

  randomnum=random(0,8);
for (i=randomnum ; i>0; i--)
 {
 int z=i;
  Serial.print ("i value = ");
  Serial.println (i);
  Serial.print ("j= ");
  Serial.println (j);
  Serial.print ("k= ");
  Serial.println (k);
    test();
    lcd.setCursor(7,0);
    lcd.write(j);
    lcd.setCursor(7,1);
    lcd.write(k);

    i--;
    test();
    
    lcd.setCursor(8,0);
    lcd.write(j);
    lcd.setCursor(8,1);
    lcd.write(k);
    lcd.setCursor(6,0);
    lcd.write(j);
    lcd.setCursor(6,1);
    lcd.write(k);
     i--;
    test();
    lcd.setCursor(9,0);
    lcd.write(j);
    lcd.setCursor(9,1);
    lcd.write(k);
    lcd.setCursor(5,0);
    lcd.write(j);
    lcd.setCursor(5,1);
    lcd.write(k);

    i--;
    test();
    lcd.setCursor(10,0);
    lcd.write(j);
    lcd.setCursor(10,1);
    lcd.write(k);
    lcd.setCursor(4,0);
    lcd.write(j);
    lcd.setCursor(4,1);
    lcd.write(k);

     i--;
    test();
    lcd.setCursor(11,0);
    lcd.write(j);
    lcd.setCursor(11,1);
    lcd.write(k);
   lcd.setCursor(3,0);
    lcd.write(j);
    lcd.setCursor(3,1);
    lcd.write(k);

     i--;
    test();
    lcd.setCursor(12,0);
    lcd.write(j);
    lcd.setCursor(12,1);
    lcd.write(k);
   lcd.setCursor(2,0);
    lcd.write(j);
    lcd.setCursor(2,1);
    lcd.write(k);

     i--;
    test();
    lcd.setCursor(13,0);
    lcd.write(j);
    lcd.setCursor(13,1);
    lcd.write(k);
   lcd.setCursor(1,0);
    lcd.write(j);
    lcd.setCursor(1,1);
    lcd.write(k);

     i--;
    test();
    lcd.setCursor(14,0);
    lcd.write(j);
    lcd.setCursor(14,1);
    lcd.write(k);
   lcd.setCursor(0,0);
    lcd.write(j);
    lcd.setCursor(0,1);
    lcd.write(k);
     i--;
    test();
    lcd.setCursor(15,0);
    lcd.write(j);
    lcd.setCursor(15,1);
    lcd.write(k);
  
    lcd.clear();
   
 i=z;
 }
 }

void test()
{

  if (i ==8)
   {
    j= 4;
    k=0;
  }
   if (i ==7)
  {
    j=3;
    k=4;
  }
   if (i ==6)
  {
    j=2;
    k=4;
  }
     if (i ==5)
  {
    j=1;
    k=4;
  }
     if (i ==4)
  {
    j=0;
    k=4;
  }
     if (i ==3)
  {
    j=0;
    k=3;
  }
     if (i ==2)
  {
    j=0;
    k=2;
  }
     if (i ==1)
  {
    j=0;
    k=1;
  }
     if (i ==0)
  {
    j=0;
    k=0;
  }
  }
