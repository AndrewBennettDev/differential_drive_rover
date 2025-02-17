const int echoPin = 2;
const int trigPin = 3;
const int pwmA = 6; // left
const int pwmB = 9; // right
const int enA = 5; // left
const int enB = 10; // right

long duration;
int distance, dst;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pwmA, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  dst = measureDistance();
  delay(1000);
  dst = measureDistance();
  delay(100);
  Serial.begin(9600);
}

void loop() {
  dst = measureDistance();
  delay(50);

  if (dst < 40) {
    stop();
    delay(100);
    turnLeft();
  } else {
    forward();
  }
}

int measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.println(distance);
  return distance;
}

void forward() {
  Serial.println("Moving foward");
  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);
  analogWrite(pwmA, 150);
  analogWrite(pwmB, 145);
}

void backward() {
  Serial.println("Moving backward");
  digitalWrite(enA, LOW);
  digitalWrite(enB, LOW);
  analogWrite(pwmA, 150);
  analogWrite(pwmB, 150);
  delay(1000);
}

void turnLeft() {
  Serial.println("Turning left");
  digitalWrite(enA, HIGH);
  digitalWrite(enB, LOW);
  analogWrite(pwmA, 100);
  analogWrite(pwmB, 100);
  delay(100);
}

void turnRight() {
  Serial.println("Turning right");
  digitalWrite(enA, LOW);
  digitalWrite(enB, HIGH);
  analogWrite(pwmA, 100);
  analogWrite(pwmB, 100);
  delay(100);  
}

void stop() {
  Serial.println("Stopping");
  digitalWrite(enA, LOW);
  digitalWrite(enB, LOW);
  analogWrite(pwmA, 150);
  analogWrite(pwmB, 0);
  delay(50);  
  digitalWrite(enA, LOW);
  digitalWrite(enB, LOW);
  analogWrite(pwmA, 0);
  analogWrite(pwmB, 0);
  delay(500);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
Inputs if using Nano:
const int echoPin = 2;
const int trigPin = 3;
const int pwmA = 6; // left
const int pwmB = 9; // right
const int enA = 5; // left
const int enB = 10; // right
*/

/*
Inputs if using Uno:
const int echoPin = 8;
const int trigPin = 7;
const int pwmA = 10; // left
const int pwmB = 11; // right
const int enA = 13; // left
const int enB = 12; // right
*/

/*
Inputs if using motor hat:
const int left_motor_direction = 13;
const int right_motor_direction = 12;
const int right_motor_PWM = 10;
const int left_motor_PWM = 11;
const int pan_servo_pin = 9;
const int echoPin = 8;
const int triggerPin = 7;
const int buzzer = 4;
const int tilt_servo_pin = 6;
const int left_motor_IR_sensor_pin = 2;
const int right_motor_IR_sensor_pin = 3;
*/