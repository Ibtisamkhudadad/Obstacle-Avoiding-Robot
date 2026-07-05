#include <Servo.h>
 Servo Myservo;
 #define trigPin 9
#define echoPin 8
#define MLa 4 
#define MLb 5 
#define MRa 6
#define MRb 7 
long duration;
long distance; 
int distanceLeft; 
int distanceRight; 
void setup() 
{   
Serial.begin(9600);   
pinMode(MLa, OUTPUT);   
pinMode(MLb, OUTPUT);   
pinMode(MRa, OUTPUT);   
pinMode(MRb, OUTPUT);   
pinMode(trigPin, OUTPUT);   
pinMode(echoPin, INPUT);   
Myservo.attach(10);   
Myservo.write(90); // Center the servo   
delay(500); 
} 
// Function to measure distance using the ultrasonic sensor 
int getDistance() {   
digitalWrite(trigPin, LOW);   
delayMicroseconds(2);   
digitalWrite(trigPin, HIGH);   
delayMicroseconds(10);   
digitalWrite(trigPin, LOW);   
long timeDuration = pulseIn(echoPin, HIGH, 30000); // 30ms timeout   
int cmDistance = timeDuration / 58;   
if (cmDistance == 0) {     
return 250; // If no echo received, assume path is clear   
}   
return cmDistance; 
} 
// Helper functions for movement 
void moveForward() {   
digitalWrite(MRb, HIGH);   
digitalWrite(MRa, LOW);   
digitalWrite(MLb, HIGH);   
digitalWrite(MLa, LOW); 
} 
void moveBackward()
{   
digitalWrite(MRb, LOW);   
digitalWrite(MRa, HIGH);   
digitalWrite(MLb, LOW);   
digitalWrite(MLa, HIGH); 
}  
void turnLeft() {   
digitalWrite(MRb, HIGH);   
digitalWrite(MRa, LOW);   
digitalWrite(MLb, LOW);   
digitalWrite(MLa, LOW); 
} 
void turnRight() {   
digitalWrite(MRb, LOW);   
digitalWrite(MRa, LOW);   
digitalWrite(MLb, HIGH);   
digitalWrite(MLa, LOW); 
} 
void robotStop() 
{   
digitalWrite(MRb, LOW);   
digitalWrite(MRa, LOW);   
digitalWrite(MLb, LOW);   
digitalWrite(MLa, LOW); 
} 
void loop() {   
Myservo.write(90); // Keep looking forward   
delay(50);   
distance = getDistance();    
Serial.print("Forward Distance: ");   
Serial.print(distance);   
Serial.println(" cm");   
// No obstacle - Keep going forward   
if (distance > 20)    
{     
moveForward();   
}   
// Obstacle detected close by   
else if (distance > 0 && distance <= 20)   
{     
robotStop();     
delay(300);     
// Back up a bit to give space to turn (increased to 1000ms for small wheels)     
moveBackward();     
delay(1000);      
robotStop();     
delay(300);     
// Look Left and take measurement     
Myservo.write(150); 
// Look Left     
delay(700);     
distanceLeft = getDistance();     
Serial.print("Left Distance: ");     
Serial.println(distanceLeft);      
// Look Right and take measurement     
Myservo.write(30); 
// Look Right     
delay(700);     
distanceRight = getDistance();     
Serial.print("Right Distance: ");     
Serial.println(distanceRight);     
// Center the servo     
Myservo.write(90);     
delay(500);     
// Compare paths and choose the clearer route     
if (distanceLeft >= distanceRight)     
{       
// Turn Left (increased to 1200ms to allow small wheels to rotate)       
turnLeft();       
delay(1200);      
}     
else     
{       
// Turn Right (increased to 1200ms to allow small wheels to rotate)       
turnRight();       
delay(1200);     
}     
robotStop();     
delay(300);   
} 
} 