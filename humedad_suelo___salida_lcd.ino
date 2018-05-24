#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C  lcd(0x27,2,1,0,4,5,6,7); // 0x27 is the I2C bus address for an unmodified backpack

// Pin para leer la humedad
const int sensorPin = A0;
// Mensaje a salir por el display
String mensaje1;
String mensaje2;

void setup() {
 
  Serial.begin(9600);
  // activate LCD module
  lcd.begin (16,2); // for 16 x 2 LCD module
  lcd.setBacklightPin(3,POSITIVE);
  lcd.setBacklight(HIGH);
}

void loop() {
    // put your main code here, to run repeatedly:
    int humedad = map(analogRead(sensorPin), 0, 1023, 100, 0);
    
    Serial.print("Humedad: ");
    Serial.print(humedad);
    Serial.println(" %");
    mensaje1 = "Humedad: "+String(humedad)+" %";

    mensaje2 = "Norma l";
    if(humedad < 30)
    {
        Serial.println("Muy seco");  
        mensaje2 = "Muy seco";
    }
  
    if(humedad > 70)
    {
        Serial.println("Muy humedo");
        mensaje2 = "Muy humedo";  
    }

    imprimeMensaje(mensaje1, mensaje2);
    delay(5000);
}

void imprimeMensaje(String mensaje1, String  mensaje2){
    lcd.setBacklight(HIGH);
    lcd.home (); // set cursor to 0,0
    lcd.clear();
    lcd.print(mensaje1); 
    lcd.setCursor (0,1);
    lcd.print(mensaje2);
    delay(1000);
    lcd.setBacklight(LOW);  
 }
