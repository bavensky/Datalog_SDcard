  /*******************************************************************************
   * Project  : Data log in SD card                                              *
   * Compiler : Arduino 1.0.2                                                    *
   * Board    : Arduino UNO                                                      *
   * Shield   : DFROBOT LCD Keypad Shield                                        *
   * Module   : SD card Module                                                   *
   *          : IC buffer CD40                                                   *
   * Author   : Bavensky :3                                                      *
   * E-Mail   : Aphirak_Sang-ngenchai@hotmail.com                                *
   * Date     : 01/05/2014 [dd/mm/yyyy]                                          *
   *******************************************************************************/
  /*******************************************************************************
   * เรียกใช้งานไลบรารี่ต่างๆ                                                          *
   *******************************************************************************/
  #include <SD.h>
  #include <LiquidCrystal.h>
  /*******************************************************************************
   * จอผลึกเหลว ใช้งานขาดิจิตอล 8,9,4,5,6และ7                                        *
   *******************************************************************************/
  LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
  /******************************************************************************
   * โมดูลบันทึกค่าลง SDCard + IC CD4050                                            *
   * SDCard         Arduino          CD4050                                      *
   *  CS              D3              15 - 14                                    *
   *  MOSI            D11             12 - 11                                    *
   *  SCK             D13             10 - 9                                     *
   *  MISO            D12                -                                       *
   *******************************************************************************/
  File excel;
  const int chipSelect = 4;
  /*******************************************************************************
   * กำหนดใช้งานคีย์แพตในโมดูล DFRobot                                              *
   *******************************************************************************/
  int lcd_key     = 0;
  int adc_key_in  = 0;
  #define btnRIGHT  0
  #define btnUP     1
  #define btnDOWN   2
  #define btnLEFT   3
  #define btnSELECT 4
  #define btnNONE   5
  /*******  Variable   ***********************************************************/
  int i=0, m=0;
  /*******************************************************************************/
  void setup()
  {
    Serial.begin(9600);
    lcd.begin(16,2);
    pinMode(3, OUTPUT);
    if (!SD.begin(chipSelect)){return;}
    excel = SD.open("Datalog.csv", FILE_WRITE);
    if(excel) 
    {
      lcd.setCursor(0,0);
      lcd.print("Writing Datalog ");
      Serial.println("Writing Data log");
      excel.print("Num");
      excel.print(",");
      excel.print("Datalog");
      excel.print(",");
      excel.println("Key Shield");
      excel.close();
      delay(2000);
    }
  }
  
  void loop()
  {
    lcd.setCursor(0,0);
    lcd.print("RMUTL Electronic");
    lcd.setCursor(0,1);
    lcd.print("     Wait !     ");
    lcd_key = read_LCD_buttons();   
    if( lcd_key==btnSELECT)
    {
      delay(200);
      writing();
    }
  }

