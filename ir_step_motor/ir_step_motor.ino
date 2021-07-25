#include <IRremote.h>

#define IR_RECEIVER_PIN 3
#define STEPPER_MOTOR_PIN1 4
#define STEPPER_MOTOR_PIN2 5
#define STEPPER_MOTOR_PIN3 6
#define STEPPER_MOTOR_PIN4 7
#define DELAY 10



void setup(){

  Serial.begin(9600);
  
  IrReceiver.begin(IR_RECEIVER_PIN);
  Serial.println("Receiver ready!");

  pinMode(STEPPER_MOTOR_PIN1, OUTPUT);                   
  pinMode(STEPPER_MOTOR_PIN2, OUTPUT);
  pinMode(STEPPER_MOTOR_PIN3, OUTPUT);
  pinMode(STEPPER_MOTOR_PIN4, OUTPUT);
  Serial.println("Motor ready!");
}  


void loop(){


  if (IrReceiver.decode()) {

    Serial.println(IrReceiver.decodedIRData.decodedRawData);
    if(IrReceiver.decodedIRData.decodedRawData == 4161210119){
      
      Serial.println("Volumen UP");
      for (int i=0; i<64; i++){
        
        digitalWrite(STEPPER_MOTOR_PIN1, HIGH);
        digitalWrite(STEPPER_MOTOR_PIN2, LOW);
        digitalWrite(STEPPER_MOTOR_PIN3, LOW);
        digitalWrite(STEPPER_MOTOR_PIN4, LOW);
        delay(DELAY);
        
        digitalWrite(STEPPER_MOTOR_PIN1, LOW);
        digitalWrite(STEPPER_MOTOR_PIN2, HIGH);
        digitalWrite(STEPPER_MOTOR_PIN3, LOW);
        digitalWrite(STEPPER_MOTOR_PIN4, LOW);
        delay(DELAY);
        
        digitalWrite(STEPPER_MOTOR_PIN1, LOW);
        digitalWrite(STEPPER_MOTOR_PIN2, LOW);
        digitalWrite(STEPPER_MOTOR_PIN3, HIGH);
        digitalWrite(STEPPER_MOTOR_PIN4, LOW);
        delay(DELAY);
        
        digitalWrite(STEPPER_MOTOR_PIN1, LOW);
        digitalWrite(STEPPER_MOTOR_PIN2, LOW);
        digitalWrite(STEPPER_MOTOR_PIN3, LOW);
        digitalWrite(STEPPER_MOTOR_PIN4, HIGH);
        delay(DELAY);
      }

    }else if (IrReceiver.decodedIRData.decodedRawData == 4094363399){
      
      Serial.println("Volumen DOWN");
      for (int i=0; i<64; i++){
        
        digitalWrite(STEPPER_MOTOR_PIN1, LOW);
        digitalWrite(STEPPER_MOTOR_PIN2, LOW);
        digitalWrite(STEPPER_MOTOR_PIN3, LOW);
        digitalWrite(STEPPER_MOTOR_PIN4, HIGH);
        delay(DELAY);
        
        digitalWrite(STEPPER_MOTOR_PIN1, LOW);
        digitalWrite(STEPPER_MOTOR_PIN2, LOW);
        digitalWrite(STEPPER_MOTOR_PIN3, HIGH);
        digitalWrite(STEPPER_MOTOR_PIN4, LOW);
        delay(DELAY);
        
        digitalWrite(STEPPER_MOTOR_PIN1, LOW);
        digitalWrite(STEPPER_MOTOR_PIN2, HIGH);
        digitalWrite(STEPPER_MOTOR_PIN3, LOW);
        digitalWrite(STEPPER_MOTOR_PIN4, LOW);
        delay(DELAY);
        
        digitalWrite(STEPPER_MOTOR_PIN1, HIGH);
        digitalWrite(STEPPER_MOTOR_PIN2, LOW);
        digitalWrite(STEPPER_MOTOR_PIN3, LOW);
        digitalWrite(STEPPER_MOTOR_PIN4, LOW);
        delay(DELAY);
      }
    }
    IrReceiver.resume();
  }
} 
