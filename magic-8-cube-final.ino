#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


// Set up OLED display
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
#define LOGO16_GLCD_HEIGHT 64
#define LOGO16_GLCD_WIDTH  128 
#if (SSD1306_LCDHEIGHT != 64  )
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif


// Declare variables
int sensor_Pin = 5;


void setup(){


  // Initialize serial
  Serial.begin(9600);


  // Set pin mode for sensor
  pinMode(sensor_Pin, INPUT);


  // Create a random seed using A0 noise
  randomSeed(analogRead(A0));
  
  // Initialize screen with the I2C addr 0x3C
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);


  cleardisplay();
  
  // Display 8 Ball Logo
  display.fillCircle(64, 32, 30, INVERSE);
  display.fillCircle(64, 32, 15, INVERSE);
  displayText("8", 60, 26, 2, true);
  delay(2000);
  
  cleardisplay();


  // Display Intro Message
  displayText("Ask me a", 15, 15, 2, true);
  displayText("question", 15, 35, 2, true);
  delay(2000);
  
}
void loop(){




  // Read sensor pin
  long measurement = pulseIn(sensor_Pin, HIGH);
  //Serial.print(measurement);
  delay(50);


  // Check vibration magnitude
  if (measurement > 1000){


    // Display thinking dots
    cleardisplay();
    displayText(".", 35, 15, 3, true);
    delay(500);
    displayText(".", 55, 15, 3, true);
    delay(500);
    displayText(".", 75, 15, 3, true);
    delay(500);


    // Display a random message 0-3
    cleardisplay();
    int msgCase = random(0,4);
    switch (msgCase) {
      case 0:
        displayText("Most likely", 30, 26, 1, true);
        break;
      case 1:
        displayText("It is certain", 25, 26, 1, true);
        break;
      case 2:
        displayText("Ask again later", 25, 26, 1, true);
        break;
      case 3:
        displayText("Very doubtful", 30, 26, 1, true);
        break;
  }
  delay(2000);
  }
  else{
    cleardisplay();
    delay(10);
  }
}


void displayText(String text, int x, int y,int size, boolean d) {


  display.setTextSize(size);
  display.setTextColor(WHITE);
  display.setCursor(x,y);
  display.println(text);
  if(d){
    display.display();
  }
}


void cleardisplay() {


  // Clears buffer
  display.clearDisplay();


  // Displays empty buffer
  display.display();
}
