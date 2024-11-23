// Declare variables
int sensor_Pin = 5;


void setup() {
  // put your setup code here, to run once:


  // Initialize serial  
  Serial.begin(9600);


  // Set pin mode for sensor
  pinMode(sensor_Pin, INPUT);


}


void loop() {
  // put your main code here, to run repeatedly:


  // Read sensor pin
  long measurement = pulseIn(sensor_Pin, HIGH);
  delay(50);


  // Print sensor measurements for calibration
  Serial.print(measurement);
  Serial.print("\n");


}