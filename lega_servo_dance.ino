// lego dance lego clock

#include <Servo.h> 
 
Servo myservo_a;  // create servo object to control a servo 
Servo myservo_b;  // create servo object to control a servo
Servo myservo_c;  // create servo object to control a servo 
Servo myservo_d;  // create servo object to control a servo 
Servo myservo_e;  // create servo object to control a servo 
Servo myservo_f;  // create servo object to control a servo 
Servo myservo_g;  // create servo object to control a servo 
Servo myservo_h;  // create servo object to control a servo 
Servo myservo_i;  // create servo object to control a servo 
Servo myservo_j;  // create servo object to control a servo 
Servo myservo_k;  // create servo object to control a servo 

// ANALOG INPUT
int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin 

// LED OUTPUT LE
const int ledPin =  13;      // the number of the LED pin
int ledState = LOW;             // ledState used to set the LED
long previousMillis = 0;        // will store last time LED was updated // the follow variables is a long because the time, measured in miliseconds, // will quickly become a bigger number than can be stored in an int.
long interval = 1000;           // interval at which to blink (milliseconds)
int seconds = 0;  /// 0 to 59 seconds

 
void setup() 
{ 

  myservo_a.attach(2);  // attaches the servo on pin 9 to the servo object 
  myservo_b.attach(3);  // attaches the servo on pin 9 to the servo object 
  myservo_c.attach(4);  // attaches the servo on pin 9 to the servo object 
  myservo_d.attach(5);  // attaches the servo on pin 9 to the servo object 
  myservo_e.attach(6);  // attaches the servo on pin 9 to the servo object 
  myservo_f.attach(7);  // attaches the servo on pin 9 to the servo object 
  myservo_g.attach(8);  // attaches the servo on pin 9 to the servo object 
  myservo_h.attach(9);  // attaches the servo on pin 9 to the servo object 
  myservo_i.attach(10);  // attaches the servo on pin 10 to the servo object
  myservo_j.attach(11);  // attaches the servo on pin 11 to the servo object
  myservo_k.attach(12);  // attaches the servo on pin 12 to the servo object 
   
  pinMode(ledPin, OUTPUT);    // led output    
} 
 
void loop() 
{ 
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
  
  val = map(val, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
  myservo_a.write(val);                  // sets the servo position according to the scaled value 
  myservo_b.write(val);
  myservo_c.write(val);
  myservo_d.write(val);
  myservo_e.write(val);
  myservo_f.write(val);
  myservo_g.write(val);
 // myservo_h.write(val);
 // myservo_i.write(val);
 // myservo_j.write(val);
 // myservo_k.write(val);
 // delay(10);                           // waits for the servo to get there 
 
  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis > interval) 
    {
    // save the last time you blinked the LED 
    previousMillis = currentMillis; 
  
    if (seconds == 60)
    {  seconds = 0;
    }
    else
    {  seconds ++;}

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW)
      {ledState = HIGH;
      myservo_h.write(160-seconds);
      myservo_i.write(140);
      myservo_j.write(120+seconds);
      }
    else
      {ledState = LOW;
      myservo_h.write(180);
      myservo_i.write(180);
      myservo_j.write(180);
      }

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
    myservo_k.write(seconds*3);
    }
  
   
  
}  
