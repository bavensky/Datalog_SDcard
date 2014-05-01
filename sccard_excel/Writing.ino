/*******************************************************************************
* Writing Excel in SDcard module                                               *
*******************************************************************************/
void writing()
{
  excel = SD.open("Datalog.csv", FILE_WRITE);
  if(excel) 
  {
    lcd.setCursor(0,1);
    lcd.print("Writing Datalog ");
    Serial.println("Writing Data log");
    i++;
    m = random(1024);
    excel.print(i);
    excel.print(",");
    excel.print("Datalog");
    excel.print(",");
    excel.println(m);
    excel.close();
    delay(2000);
   }
}

