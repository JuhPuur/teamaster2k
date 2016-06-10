#define VOLT_40C 2.3

void setup() {
  const int motor1Pin = 11;
  const int motor2Pin = 12;
  const int buttonPin = 10;
  
  const int redLed1 = 9;
  const int redLed2 = 8;
  const int greenLed = 7;

  Serial.begin(9600);
  while(!Serial){;}
  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(redLed1, OUTPUT);
  pinMode(redLed2, OUTPUT);
  pinMode(greenLed, OUTPUT);
  digitalWrite(redLed1, HIGH);
}

void loop() {
  const int motor1Pin = 11;
  const int motor2Pin = 12;
  const int buttonPin = 10;

  const int redLed1 = 9;
  const int redLed2 = 8;
  const int greenLed = 7;
  
  int buttonState = 0;
  int started = 0;
  
  digitalWrite(redLed2, LOW);
  digitalWrite(greenLed, LOW);

  Serial.println("Starting. Waiting for button press.");

  while(true){
    delay(30);
    if(!started){
      buttonState = digitalRead(buttonPin);
      if(buttonState == HIGH){
        started = true;
      }
      continue;
    }
    break;
  }

  // Button has been pressed
  Serial.println("Button has been pressed.");
  // Yes that's what I said.

  // Wait for water to warm up

  while(true){
    int sensorValue = analogRead(A0);
    float voltage = sensorValue*(5.0/1023.0);
    Serial.println(voltage);
    if(voltage > VOLT_40C)
      break;
    delay(500);
  }
  digitalWrite(redLed2, HIGH);
  
  // Lower tea
  Serial.println("Lowering tea.");
  // Good boy.

  digitalWrite(motor1Pin, HIGH);
  digitalWrite(motor2Pin, LOW);
  delay(3000);

  // Stop. Steeping time. (Oh-oh Oh-oh-oh. Can't touch this. Because it's hot.)
  
  digitalWrite(motor1Pin, LOW);

  // Steep. Steep it like you mean it.
  Serial.println("Steeping.");
  // No steeping on the job!

  delay(1000); //Proper time would be 120000 = 2 minutes, but we're in a hurry.

  // Raise the soggy mess.
  Serial.println("Done steeping.");
  digitalWrite(motor2Pin, HIGH);
  delay(3000);

  // Stop raising the soggy mess.

  digitalWrite(motor2Pin, LOW);

  // Your "tea" is now done.
  Serial.println("Enjoy.");
  digitalWrite(greenLed, HIGH);
  delay(3000);
}
