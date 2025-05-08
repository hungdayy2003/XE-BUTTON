#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include <Wire.h>

// Khai báo chân điều khiển 
#define ENA 3
#define IN1 2
#define IN2 4
#define ENB 6
#define IN3 7
#define IN4 8

int msg[2];
int pwm_pulse = 100;

RF24 radio(9,10);
const uint64_t pipe = 0xE8E8F0F0E1LL;
unsigned long time;
void setup(void){
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.setPALevel(RF24_PA_MIN);
  radio.setChannel(80);
  radio.setDataRate(RF24_250KBPS);
  radio.startListening();//Giao tiếp sóng giữa 2 board
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  time = millis();
}
 
void loop(void){
  if (radio.available()){
{
   radio.read(msg, sizeof(msg));     
      Serial.println(msg[0]);

      if(msg[0] == 1)
      {
        pwm_pulse = 130;
        forward();
      }
      else if(msg[0] == 2)
      {
        pwm_pulse = 130;
        back();
      }
      else if(msg[0] == 3)
      {
        pwm_pulse = 110;
        left();
      }
      else if(msg[0] == 4)
      {
        pwm_pulse = 110;
        right();
      }
      else if(msg[0] == 5)
      {
        pwm_pulse = 0;
        stop_motor();
      }
    }
  }  
}
void forward()
{
  analogWrite(ENA, pwm_pulse);
  analogWrite(ENB, pwm_pulse);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void back()
{
  analogWrite(ENA, pwm_pulse);
  analogWrite(ENB, pwm_pulse);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void left()
{
  analogWrite(ENA, pwm_pulse);
  analogWrite(ENB, pwm_pulse);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right()
{
  analogWrite(ENA, pwm_pulse);
  analogWrite(ENB, pwm_pulse);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stop_motor()
{
  analogWrite(ENA, pwm_pulse);
  analogWrite(ENB, pwm_pulse);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
