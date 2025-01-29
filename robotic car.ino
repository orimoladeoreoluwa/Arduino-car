// Define motor driver pins
#define ENA 9  // Enable pin for motor A
#define IN1 8  // Motor A input 1
#define IN2 7  // Motor A input 2
#define IN3 6  // Motor B input 1
#define IN4 5  // Motor B input 2
#define ENB 10 // Enable pin for motor B

// Define ultrasonic sensor pins
#define TRIG 11
#define ECHO 12

void setup() {
    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(ENB, OUTPUT);
    
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
    
    Serial.begin(9600); // Debugging via Serial Monitor
}

// Function to measure distance
int getDistance() {
    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);
    
    long duration = pulseIn(ECHO, HIGH);
    int distance = duration * 0.034 / 2; // Convert to cm
    
    return distance;
}

// Function to move forward
void moveForward() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, 150); // Adjust speed
    analogWrite(ENB, 150);
}

// Function to move backward
void moveBackward() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, 150);
    analogWrite(ENB, 150);
}

// Function to turn left
void turnLeft() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, 150);
    analogWrite(ENB, 150);
}

// Function to turn right
void turnRight() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, 150);
    analogWrite(ENB, 150);
}

// Function to stop the car
void stopCar() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
}

void loop() {
    int distance = getDistance();
    Serial.print("Distance: ");
    Serial.println(distance);
    
    if (distance > 15) {  // Safe distance
        moveForward();
    } else {  // Obstacle detected
        stopCar();
        delay(500);
        moveBackward();
        delay(500);
        turnLeft(); // Change direction
        delay(500);
        stopCar();
    }
}
