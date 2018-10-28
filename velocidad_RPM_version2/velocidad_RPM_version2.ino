#include <LiquidCrystal.h>


const int senrpm = 13;                         // El interruptor a utilizar sera el 0 es decir el pin digital 2

int pulsos=0;                                 // variable para contar los pulsos en 1 segundo
int resolucion = 300;                          // pulsos por revolución del encoder
int tiempo;  
double rpm;

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);


void setup() {
  // put your setup code here, to run once:

  lcd.begin(16, 2);

   pinMode(senrpm, INPUT);         //declaramos el boton como entrada
   

}

void loop() {
  // put your main code here, to run repeatedly:

   velocidadrpm();

}





void velocidadrpm(){


//    Serial.println(tiempo);

int pulsos=0;
boolean bandera=LOW;
unsigned long currentTime=0;
unsigned long startTime=millis();

     while(currentTime<=1000)
       {
         if(digitalRead(senrpm)==HIGH)
         {
          bandera=HIGH;
         }
         if(digitalRead(senrpm)==LOW && bandera==HIGH)
         {
           pulsos++;
           bandera=LOW;
      
          }
        
         currentTime=millis()-startTime;
       }
       
    rpm=((double)pulsos/resolucion)*60; 
    
  //   rpm=int(60000./float(1000))*pulsos/resolucion;
    
 
   /// Serial.println(rpm);
    
   lcd.setCursor(0,1);            
   lcd.write("vel:");
   lcd.setCursor(5,1);  
   lcd.print(rpm);
}
