#include <math.h>
#include<Servo.h>
int x;
int y;
int d1;
int d2;
int d;
int L1=7;
int L2=5;
char inSerial[15];
int a;
Servo myservo1;
Servo myservo2;
void setup() {
  myservo1.attach(9);
  myservo2.attach(10);
  Serial.begin(9600);
  Serial.println("Enter 1 for FORWARD KINEMATIC OR 2 INVERSE KINEMATC : ");
}


void loop() {
  if (Serial.available() > 0) {    
    a=Serial.parseInt();      
    if (a == 1) {
      Serial.println("--------FORWARD KINEMATIC---------");
      Serial.print("Enter the first angle : ");
      while (1){
          d1 = Serial.parseInt(); 
          if (d1>2){
              Serial.println(d1);
              break;}
              }
      Serial.print("Enter the second angle : ");
      while (1){
          d2 = Serial.parseInt();
          if (d2>2){
              Serial.println(d2);
              break;}
              }
      x = L1 * cos(d1) + L2 * cos(d1+d2);
      y = L1 * sin(d1) + L2 * sin(d1+d1);
      Serial.print("The 2 points : (");
      Serial.print(x);
      Serial.print(",");
      Serial.print(y);
      Serial.print(")");
      myservo1.write(d1);
      myservo2.write(d2);
      Serial.println("Enter 1 for FORWARD KINEMATIC OR 2 INVERSE KINEMATC : ");
    }
    else if (a == 2){
      Serial.println("--------INVERSE KINEMATIC---------");
      Serial.print("Enter the first point : ");
      while (1){
          x = Serial.parseInt();
          if (x>1){
              Serial.println(x);
              break;}}
      Serial.print("Enter the second point : ");
      while (1){
          y = Serial.parseInt();
          if (y>1){
              Serial.println(y);
              break;}}
      Serial.print("Enter the total angle : ");
      while (1){
          d = Serial.parseInt();
          if (d>1){
              Serial.println(d);
              break;}}
      d2 = acos( x*x + y*y - L1*L1 - (L2*L2)/(2*L1*L2));
      d1 = d - d2;
      Serial.print("The 2 angles : (");
      Serial.print(d1);
      Serial.print(",");
      Serial.print(d2);
      Serial.print(")");
      myservo1.write(d1);
      myservo2.write(d2);
      Serial.println("Enter 1 for FORWARD KINEMATIC OR 2 INVERSE KINEMATC : ");
      }
    else   {
      Serial.println("Not a number.");
    }
  } // end: if (Serial.available() > 0)

}
