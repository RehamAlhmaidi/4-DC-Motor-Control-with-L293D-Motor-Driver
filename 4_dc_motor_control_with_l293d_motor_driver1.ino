// Reham Alhmaidi
// Motor A connections  
int enA = 6;
int in1 = 7;
int in2 = 4;
// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 2;
// Motor C connections
int enC = 10;
int in5 = 8;
int in6 = 9;
// Motor D connections
int enD = 11;
int in7 = 12;
int in8 = 13;

// Timer variables
unsigned long previousMillis = 0;
unsigned long moveDuration = 0;
bool moving = false;
int moveState = 0;
unsigned long rightLeftStartMillis = 0;

void setup() {
    Serial.begin(9600); // Start Serial Monitor
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(enC, OUTPUT);
    pinMode(enD, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(in5, OUTPUT);
    pinMode(in6, OUTPUT);
    pinMode(in7, OUTPUT);
    pinMode(in8, OUTPUT);

    // Turn off motors - Initial state
    stopMotors();
}

void loop() {
    // Move Forward for 30 seconds
    if (moveState == 0) {
        Serial.println("Starting: Moving Forward for 30 seconds");
        moveForward();
        moveDuration = 30000;  // 30 seconds
        previousMillis = millis();
        moveState = 1;
    }
    
    // Move Backward for 60 seconds
    if (moveState == 1 && millis() - previousMillis >= moveDuration) {
        Serial.println("(30 seconds pass...)");
        Serial.println("Completed: Moving Forward.");
        Serial.println("---------------------------------------------------");
        Serial.println("Starting: Moving Backward for 60 seconds");
        moveBackward();
        moveDuration = 60000;  // 60 seconds
        previousMillis = millis();
        moveState = 2;
    }

    // Alternating Right and Left for 60 seconds
    if (moveState == 2 && millis() - previousMillis >= moveDuration) {
        Serial.println("(60 seconds pass...)");
        Serial.println("Completed: Moving Backward.");
        Serial.println("---------------------------------------------------");
        Serial.println("Starting: Alternating Right and Left for 60 seconds");
        rightLeftStartMillis = millis(); // Store the start time for alternating right and left
        moveState = 3;
    }

    // Handle alternating right and left movements
    if (moveState == 3) {
        unsigned long currentMillis = millis();
        if (currentMillis - rightLeftStartMillis < 30000) {
            // First 30 seconds: Move Right
            Serial.println("Turning Right for 30 seconds");
            moveRight();
        } else if (currentMillis - rightLeftStartMillis >= 30000 && currentMillis - rightLeftStartMillis < 60000) {
            // Next 30 seconds: Move Left
            Serial.println("Turning Left for 30 seconds");
            moveLeft();
        }
        if (currentMillis - rightLeftStartMillis >= 60000) {
            // After 60 seconds, stop the motors
            Serial.println("(30 seconds pass...)");
            Serial.println("(30 seconds pass...)");
            Serial.println("Completed: Alternating Right and Left.");
            Serial.println("---------------------------------------------------");
            stopMotors();
            moveState = 4; // End state
        }
    }
}

void moveForward() {
    analogWrite(enA, 255);
    analogWrite(enB, 255);
    analogWrite(enC, 255);
    analogWrite(enD, 255);

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    digitalWrite(in5, HIGH);
    digitalWrite(in6, LOW);
    digitalWrite(in7, HIGH);
    digitalWrite(in8, LOW);
}

void moveBackward() {
    analogWrite(enA, 255);
    analogWrite(enB, 255);
    analogWrite(enC, 255);
    analogWrite(enD, 255);

    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    digitalWrite(in5, LOW);
    digitalWrite(in6, HIGH);
    digitalWrite(in7, LOW);
    digitalWrite(in8, HIGH);
}

void moveRight() {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    digitalWrite(in5, HIGH);
    digitalWrite(in6, LOW);
    digitalWrite(in7, LOW);
    digitalWrite(in8, HIGH);
}

void moveLeft() {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    digitalWrite(in5, LOW);
    digitalWrite(in6, HIGH);
    digitalWrite(in7, HIGH);
    digitalWrite(in8, LOW);
}

void stopMotors() {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    digitalWrite(in5, LOW);
    digitalWrite(in6, LOW);
    digitalWrite(in7, LOW);
    digitalWrite(in8, LOW);
    delay(500); // Small pause
}




  