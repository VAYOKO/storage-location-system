 /*
  * 
  * 
  * โปรเจคลิ้นชักค้นหาอุปกรณ์อิเล็คทรอนิกส์ ใช้สำหรับค้นหาอุปกรณ์ อิเล็คทรอนิกส์ด้วยความเร็วเนื่ิงจากเวลาจะหาอุปกรณืต้องใช้เวลานานในการหา
  * 
  * การใช้งาน 
  * 1.กด keypad ตามค่าของตัวต้านทานที่ต้องการ
  * หลังจากนั้นไฟจะเเสดงโชว์ตำเเหน่งที่อยู่ของลิ้นชักที่มีอุปกรณ์ที่เราต้องการ
  * จอเเสดงผลจะเเสดงรหัสการกด keypad เเละ ค่าตัวต้านทาน
  * 
  * 
  * อุปกรณ์ 
  * Arduino mega 2560
  * จอ LCD 20*4 ติดต่อเเบบ i2c
  * keypad 4*4
  * 
  * 
  * 
  * 
  * 
  * 
  * 
  * 
  * 
  * 
  * 
  * 
  * พัฒนาโดย นาย วาริส วิภาวนิช 
  * สาขาวิชา ช่างอุตสาหกรรมฐานวิทยาศาสตร์ 
  * สาขางาน เทคโนโลยีอีเล็คทรอนิกส์ 
  * รหัสประจำตัวนักศึกษา 63201910018
  * 
  * เเก้ไขล่าสุด 1/1/2021 - 2/1/2021 - 12:30
  * 
  */
#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Variables
int min_Ang = 0;
int max_Ang = 135;
int character = 0;
int activated = 0;
char Pass_char[4] = {' ', ' ', ' ', ' '};       //จำนวนหลัก

//Keypad config
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys [ROWS][COLS] =
{ {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};
int x = 2500;
//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
#define I2C_ADDR 0x27 // <
#define BACKLIGHT_PIN 3


LiquidCrystal_I2C lcd(I2C_ADDR, 2, 1, 0, 4, 5, 6, 7);
void setup() {
  for (int leds = 14; leds <= 53; leds++) {
    pinMode(leds, OUTPUT);
  }
  Serial.begin(9600);
  //lcd.begin (16,2); // <
  lcd.begin (20, 4); // <

  // Switch on the backlight
  lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

  lcd.setCursor(3, 1); // ไปทตัวอักษรที่ 3 แถวที่ 2
  lcd.print("Smart drawer for ");

  lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
  lcd.print("storing resistors");
}

void loop() {
  char customKey = customKeypad.getKey(); //this function reads the presed key

  if (customKey) {
    if (character == 0)
    {
      Pass_char[0] = customKey;
    }

    if (character == 1)
    {
      Pass_char[1] = customKey;
    }

    if (character == 2)
    {
      Pass_char[2] = customKey;
    }

    if (character == 3)
    {
      Pass_char[3] = customKey;
      activated = 1;
    }
    character = character + 1;
  }

  if (activated == 1)
  {
    // you can change your password here (current passowrd is 1357)


    if (character == 4 && Pass_char[0] == '0' && Pass_char[1] == '1' && Pass_char[2] == '0' && Pass_char[3] == '0' )     
    {

      digitalWrite(1, HIGH);
      activated = 2;

      lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 0 1 0 0 ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("100Ω");
      delay(x);
      digitalWrite(1, LOW);
      lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';
    }

    if (character == 4 && Pass_char[0] == '0' && Pass_char[1] == '2' && Pass_char[2] == '0' && Pass_char[3] == '0' )
    {

      digitalWrite(2, HIGH);

      lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 0 2 0 0 ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("200Ω");
      activated = 2;
      delay(x);
      digitalWrite(2, LOW);
      lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';


    } else if (character == 4 && Pass_char[0] == '0' && Pass_char[1] == '3' && Pass_char[2] == '0' && Pass_char[3] == '0' )
    {

      digitalWrite(3, HIGH);

      lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 0 3 0 0 ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("300Ω");
      activated = 2;
      delay(x);
      digitalWrite(3, LOW);
      lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';


    } else if (character == 4 && Pass_char[0] == '0' && Pass_char[1] == '4' && Pass_char[2] == '0' && Pass_char[3] == '0' )
    {

      digitalWrite(4, HIGH);
      lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 0 4 0 0 ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("400Ω");
      activated = 2;
      delay(x);
      digitalWrite(4, LOW);
      lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';


    } else if (character == 4 && Pass_char[0] == '0' && Pass_char[1] == '5' && Pass_char[2] == '0' && Pass_char[3] == '0' )
    {

      digitalWrite(5, HIGH);
      lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 0 5 0 0 ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("500Ω");
      activated = 2;
      delay(x);
      digitalWrite(5, LOW);
      lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';
    }
    else if (character == 4 && Pass_char[0] == '1' && Pass_char[1] == '0' && Pass_char[2] == '0' && Pass_char[3] == '0' )
    {

      digitalWrite(6, HIGH);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 1 0 0 0 ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("1kΩ");
      activated = 2;
      delay(x);
      digitalWrite(6, LOW);
       lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';

    }

    else if (character == 4 && Pass_char[0] == '1' && Pass_char[1] == '0' && Pass_char[2] == '*' && Pass_char[3] == '1' )
    {

      digitalWrite(7, HIGH);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 1 0 * 1 ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("10kΩ");
      activated = 2;
      delay(x);
      digitalWrite(7, LOW);
       lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';

    }
    else if (character == 4 && Pass_char[0] == '5' && Pass_char[1] == '0' && Pass_char[2] == '*' && Pass_char[3] == '1' )
    {

      digitalWrite(8, HIGH);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 5 0 * 1 ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("50kΩ");
      activated = 2;
      delay(x);
      digitalWrite(8, LOW);
       lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';

    }
    else if (character == 4 && Pass_char[0] == '1' && Pass_char[1] == '0' && Pass_char[2] == '0' && Pass_char[3] == 'A' )
    {

      digitalWrite(9, HIGH);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 1 0 0 A ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("100kΩ");
      activated = 2;
      delay(x);
      digitalWrite(9, LOW);
       lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';

    }
    else if (character == 4 && Pass_char[0] == '5' && Pass_char[1] == '0' && Pass_char[2] == '0' && Pass_char[3] == 'A' )
    {

      digitalWrite(10, HIGH);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 5 0 0 A ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("500kΩ");
      activated = 2;
      delay(x);
      digitalWrite(10, LOW);
       lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';

    }

    else if (character == 4 && Pass_char[0] == '0' && Pass_char[1] == '1' && Pass_char[2] == '1' && Pass_char[3] == '0' )
    {

      digitalWrite(11, HIGH);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 0 1 1 0 ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("110Ω");
      activated = 2;
      delay(x);
      digitalWrite(11, LOW);
       lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';

    }

    else if (character == 4 && Pass_char[0] == '0' && Pass_char[1] == '1' && Pass_char[2] == '3' && Pass_char[3] == '3' )
    {

      digitalWrite(12, HIGH);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 0 1 3 3 ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("133Ω");
      activated = 2;
      delay(x);
      digitalWrite(12, LOW);
       lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';

    }

    else if (character == 4 && Pass_char[0] == '0' && Pass_char[1] == '1' && Pass_char[2] == '5' && Pass_char[3] == '0' )
    {

      digitalWrite(13, HIGH);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 0 1 5 0 ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("150Ω");
      activated = 2;
      delay(x);
      digitalWrite(13, LOW);
       lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';

    }

    else if (character == 4 && Pass_char[0] == '0' && Pass_char[1] == '3' && Pass_char[2] == '3' && Pass_char[3] == '0' )
    {

      digitalWrite(14, HIGH);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 0 3 3 0 ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("330Ω");
      activated = 2;
      delay(x);
      digitalWrite(14, LOW);
       lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';

    }

    else if (character == 4 && Pass_char[0] == '0' && Pass_char[1] == '5' && Pass_char[2] == '5' && Pass_char[3] == '0' )
    {

      digitalWrite(15, HIGH);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 0 5 5 0 ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("550Ω");
      activated = 2;
      delay(x);
      digitalWrite(15, LOW);
       lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';

    }

    else if (character == 4 && Pass_char[0] == '1' && Pass_char[1] == '1' && Pass_char[2] == '*' && Pass_char[3] == '1' )
    {

      digitalWrite(16, HIGH);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 1 1 * 1 ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("1.1kΩ");
      activated = 2;
      delay(x);
      digitalWrite(16, LOW);
       lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';

    }

    else if (character == 4 && Pass_char[0] == '1' && Pass_char[1] == '5' && Pass_char[2] == '*' && Pass_char[3] == '1' )
    {

      digitalWrite(17, HIGH);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 1 5 * 1 ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("1.5kΩ");
      activated = 2;
      delay(x);
      digitalWrite(17, LOW);
       lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';

    }

    else if (character == 4 && Pass_char[0] == '2' && Pass_char[1] == '5' && Pass_char[2] == '*' && Pass_char[3] == '1' )
    {

      digitalWrite(18, HIGH);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 2 5 * 1 ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("2.5kΩ");
      activated = 2;
      delay(x);
      digitalWrite(18, LOW);
       lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';

    }

    else if (character == 4 && Pass_char[0] == '3' && Pass_char[1] == '5' && Pass_char[2] == '*' && Pass_char[3] == '1' )
    {

      digitalWrite(19, HIGH);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 3 5 * 1 ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("3.5kΩ");
      activated = 2;
      delay(x);
      digitalWrite(19, LOW);
       lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';

    }
    else if (character == 4 && Pass_char[0] == '5' && Pass_char[1] == '5' && Pass_char[2] == '*' && Pass_char[3] == '1' )
    {

      digitalWrite(20, HIGH);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 5 5 * 1 ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("5.5kΩ");
      activated = 2;
      delay(x);
      digitalWrite(20, LOW);
       lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';

    }

    else if (character == 4 && Pass_char[0] == '0' && Pass_char[1] == '0' && Pass_char[2] == '1' && Pass_char[3] == 'B' )
    {

      digitalWrite(21, HIGH);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 0 0 1 B ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("1MΩ");
      activated = 2;
      delay(x);
      digitalWrite(21, LOW);
       lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';

    }

    else if (character == 4 && Pass_char[0] == '0' && Pass_char[1] == '0' && Pass_char[2] == '2' && Pass_char[3] == 'B' )
    {

      digitalWrite(22, HIGH);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 0 0 2 B ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("2MΩ");
      activated = 2;
      delay(x);
      digitalWrite(22, LOW);
       lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';

    }
    else if (character == 4 && Pass_char[0] == '0' && Pass_char[1] == '0' && Pass_char[2] == '3' && Pass_char[3] == 'B' )
    {

      digitalWrite(23, HIGH);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 0 0 3 B ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("3M0Ω");
      activated = 2;
      delay(x);
      digitalWrite(23, LOW);
       lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';

    }

    else if (character == 4 && Pass_char[0] == '0' && Pass_char[1] == '0' && Pass_char[2] == '4' && Pass_char[3] == 'B' )
    {

      digitalWrite(24, HIGH);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 0 0 4 B ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("4MΩ");
      activated = 2;
      delay(x);
      digitalWrite(24, LOW);
       lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';

    }
    else if (character == 4 && Pass_char[0] == '0' && Pass_char[1] == '0' && Pass_char[2] == '5' && Pass_char[3] == 'B' )
    {

      digitalWrite(25, HIGH);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 0 0 5 B ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("5MΩ");
      activated = 2;
      delay(x);
      digitalWrite(25, LOW);
       lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';

    }

    else if (character == 4 && Pass_char[0] == '0' && Pass_char[1] == '1' && Pass_char[2] == '0' && Pass_char[3] == 'B' )
    {

      digitalWrite(26, HIGH);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 0 1 0 B ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("10MΩ");
      activated = 2;
      delay(x);
      digitalWrite(26, LOW);
       lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';

    }

    else if (character == 4 && Pass_char[0] == '0' && Pass_char[1] == '2' && Pass_char[2] == '0' && Pass_char[3] == 'B' )
    {

      digitalWrite(27, HIGH);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 0 2 0 B ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("20MΩ");
      activated = 2;
      delay(x);
      digitalWrite(27, LOW);
       lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';

    }
    else if (character == 4 && Pass_char[0] == '0' && Pass_char[1] == '3' && Pass_char[2] == '0' && Pass_char[3] == 'B' )
    {

      digitalWrite(28, HIGH);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 0 3 0 B ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("30MΩ");
      activated = 2;
      delay(x);
      digitalWrite(28, LOW);
       lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';

    }

    else if (character == 4 && Pass_char[0] == '0' && Pass_char[1] == '4' && Pass_char[2] == '0' && Pass_char[3] == 'B' )
    {

      digitalWrite(29, HIGH);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 0 4 0 B ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("40MΩ");
      activated = 2;
      delay(x);
      digitalWrite(29, LOW);
       lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';

    }

    else if (character == 4 && Pass_char[0] == '0' && Pass_char[1] == '5' && Pass_char[2] == '0' && Pass_char[3] == 'B' )
    {

      digitalWrite(30, HIGH);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 0 5 0 B ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("50MΩ");
      activated = 2;
      delay(x);
      digitalWrite(30, LOW);
       lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';

    }

    else if (character == 4 && Pass_char[0] == '0' && Pass_char[1] == '6' && Pass_char[2] == '0' && Pass_char[3] == 'B' )
    {

      digitalWrite(31, HIGH);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 0 6 0 B ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("60MΩ");
      activated = 2;
      delay(x);
      digitalWrite(31, LOW);
       lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';

    }
    else if (character == 4 && Pass_char[0] == '0' && Pass_char[1] == '7' && Pass_char[2] == '0' && Pass_char[3] == 'B' )
    {

      digitalWrite(32, HIGH);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 0 7 0 B ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("70MΩ");
      activated = 2;
      delay(x);
      digitalWrite(32, LOW);
       lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';

    }

    else if (character == 4 && Pass_char[0] == '0' && Pass_char[1] == '8' && Pass_char[2] == '0' && Pass_char[3] == 'B' )
    {

      digitalWrite(33, HIGH);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 0 8 0 B ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("80MΩ");
      activated = 2;
      delay(x);
      digitalWrite(33, LOW);
       lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';

    }

    else if (character == 4 && Pass_char[0] == '0' && Pass_char[1] == '9' && Pass_char[2] == '0' && Pass_char[3] == 'B' )
    {

      digitalWrite(34, HIGH);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 0 9 0 B ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("90MΩ");
      activated = 2;
      delay(x);
      digitalWrite(34, LOW);
       lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';

    }

    else if (character == 4 && Pass_char[0] == '1' && Pass_char[1] == '0' && Pass_char[2] == '0' && Pass_char[3] == 'B' )
    {

      digitalWrite(35, HIGH);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 1 0 0 B ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("100MΩ");
      activated = 2;
      delay(x);
      digitalWrite(35, LOW);
       lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';

    }
    else if (character == 4 && Pass_char[0] == '1' && Pass_char[1] == '1' && Pass_char[2] == '0' && Pass_char[3] == 'B' )
    {

      digitalWrite(36, HIGH);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 1 1 0 B ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("110MΩ");
      activated = 2;
      delay(x);
      digitalWrite(36, LOW);
       lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';

    }

    else if (character == 4 && Pass_char[0] == '1' && Pass_char[1] == '3' && Pass_char[2] == '0' && Pass_char[3] == 'B' )
    {

      digitalWrite(37, HIGH);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 1 3 0 B ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("130MΩ");
      activated = 2;
      delay(x);
      digitalWrite(37, LOW);
       lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';

    }

    else if (character == 4 && Pass_char[0] == '1' && Pass_char[1] == '5' && Pass_char[2] == '0' && Pass_char[3] == 'B' )
    {

      digitalWrite(38, HIGH);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 1 5 0 B ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("150MΩ");
      activated = 2;
      delay(x);
      digitalWrite(38, LOW);
       lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';

    }

    else if (character == 4 && Pass_char[0] == '2' && Pass_char[1] == '0' && Pass_char[2] == '0' && Pass_char[3] == 'B' )
    {

      digitalWrite(39, HIGH);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 2 0 0 B ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("200MΩ");
      activated = 2;
      delay(x);
      digitalWrite(39, LOW);
       lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';

    }
    else if (character == 4 && Pass_char[0] == '2' && Pass_char[1] == '5' && Pass_char[2] == '0' && Pass_char[3] == 'B' )
    {

      digitalWrite(40, HIGH);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print(" 2 5 0 B ");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("250MΩ");
      activated = 2;
      delay(x);
      digitalWrite(40, LOW);
       lcd.clear();
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';

    }
    else {
      Serial.println("ERR");
       lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
      lcd.setBacklight(HIGH);
      lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

      lcd.setCursor(3, 0); // ไปทตัวอักษรที่ 3 แถวที่ 2
      lcd.print("ERROR");

      lcd.setCursor(5, 2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
      lcd.print("plase typing again");
      delay(x);
      activated = 0;
      character = 0;
      Pass_char[0] = ' ';
      Pass_char[1] = ' ';
      Pass_char[2] = ' ';
      Pass_char[3] = ' ';
    }


  }
}
