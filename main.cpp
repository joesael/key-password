/* 
|| #F27JR
uso de libreria de keypad, en este caso teclado de 4 botones en membrana
password de 4 caracteres, realiza comparacion, si no coincide desde el primero reinicia la peticion
*/
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 1; //three columns
char keys[ROWS][COLS] = 
  {'1','2','3','4'};

byte rowPins[ROWS] = {5, 3, 9, 7}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

unsigned long loopCount = 0;
unsigned long timer_t = 0;

//variables
char pass[] = {'1', '1', '2', '3'};
char keyb[] = {'0', '0', '0', '0'};

 boolean valid = false;
void setup(){
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);

  Serial.println("Mensaje de bienvenida");
}

void loop(){
inicio:

      keyb[0] = keypad.getKey();
      if (keyb[0]  != 0 ){
    /*  Serial.println(".");
      Serial.print("keyb[0] = ");
      Serial.println(keyb[0]);
        Serial.print("pass[0] = ");
      Serial.println(pass[0]);
     */     if(keyb[0] == pass[0])
              Serial.println("[0] is equal...");
             else{
              Serial.print("es diferente los caracteres...");
               Serial.println("... inicia otra vez...");
               goto inicio;
             }
               
    
      keyb[1] = keypad.waitForKey();
    /*  Serial.print("keyb[1] = ");
      Serial.println(keyb[1]);
          Serial.print("pass[1] = ");
      Serial.println(pass[1]);
            if(keyb[1] == pass[1])
              Serial.println("[1] is equal...");
            else
              Serial.println("[1] is different...");
    */
      keyb[2] = keypad.waitForKey();
    /*  Serial.print("keyb[2] = ");
      Serial.println(keyb[2]);
          Serial.print("pass[2] = ");
      Serial.println(pass[2]);
            if(keyb[2] == pass[2])
              Serial.println("[2] is equal...");
              else
              Serial.println("[1] is different...");
    */
      keyb[3] = keypad.waitForKey();
    /*  Serial.print("keyb[] = ");
      Serial.println(keyb[3]);
          Serial.print("pass[3] = ");
      Serial.println(pass[3]);
            if(keyb[3] == pass[3])
              Serial.println("[3] is equal...");
              else
              Serial.println("[1] is different...");
          
      Serial.println("_");
      Serial.println(" ");
    */
    
    for(int i = 0; i < 4; i++){
        if (pass[i] == keyb[i])
            valid = true;
        else{
            valid = false;
            Serial.println("inicia otra vez___");
            break;
        }
    
    }
    
    if(valid){
        Serial.println("the arrays is the SAMEEEEEEE");
        digitalWrite(13, HIGH);
        delay(3000);
        digitalWrite(13, LOW);
    }else{
         Serial.println("the arrays is DIFERENTTTTT");
         digitalWrite(13, LOW);
    }
      
      }


}
