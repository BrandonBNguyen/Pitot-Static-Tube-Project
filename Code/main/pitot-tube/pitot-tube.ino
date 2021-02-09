// Includes and definitions for SSD1306 Display.
#include <SPI.h>
#include <i2c_t3.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUMFLAKES     10 // Number of snowflakes in the animation example

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16
static const unsigned char PROGMEM logo_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

// Includes and definitions for BMP180 sensors.
#include "sensor_read_functions.h"
SFE_BMP180 sensor_1;
SFE_BMP180_2 sensor_2;
float pressure_offset; // Accounts for offset in absolute pressure measurement between the two sensors.

void setup() {
  // Serial.begin(9600);
  // Serial.println("REBOOT");

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    // Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Clear the buffer
  display.clearDisplay();
  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0, 0);     // Start at top-left corner
  display.cp437(true);         // Use full 256 char 'Code Page 437' font

  display.write("SSD1306 Initialized\n");
  display.display();

  if (sensor_1.begin())
  {
    // Serial.println("Sensor 1 init success");
    display.write("BMP180 1 Initialized\n");
    display.display();
  }
  else
  {
    // Sensor 1 failed to connect.
    // Serial.println("Sensor 1 init fail\n\n");
    display.write("BMP180 1 Initialized\n");
    display.display();
    while(1); // Pause forever.
  }

  if (sensor_2.begin())
  {
    // Serial.println("Sensor 2 init success");
    display.write("BMP180 2 Initialized\n");
    display.display();
  }
  else
  {
    // Sensor 2 failed to connect.
    // Serial.println("Sensor 2 init fail\n\n");
    display.write("BMP180 1 Initialized\n");
    display.display();
    while(1); // Pause forever.
  }

  // Measure the initial difference in pressure (assuming no airspeed) to get pressure sensor offset.
  pressure_offset = get_pressure(sensor_1) - get_pressure(sensor_2);
  display.write("Pressure Difference\nCalibrated");
  display.display();
}

void loop() {
  // Serial.print("Sensor 1 Pressure (mb): ");
  // Serial.println(get_pressure(sensor_1));
  // Serial.print("Sensor 2 Pressure (mb): ");
  // Serial.println(get_pressure(sensor_2));

  // Calculate difference in pressure in pascals.
  float diff_pressure = 100*(get_pressure(sensor_1) - (get_pressure(sensor_2) + pressure_offset));
  float airspeed = sqrt(2 * abs(diff_pressure) / 1.225);

  // Serial.print("Pressure Diff (Pa): ");
  // Serial.println(diff_pressure);
  // Serial.print("Calculated Airspeed (m/s): ");
  // Serial.println(airspeed);
  // Serial.print("Calculated Airspeed (mph): ");
  // Serial.println(airspeed * 2.23694);
  // Serial.println();

  display.clearDisplay();
  display.setCursor(0,0);
  display.print("dP (Pa): ");
  display.println(diff_pressure);
  display.println();
  display.setTextSize(2);
  display.println("V (mph): ");
  display.setTextSize(3);
  if (airspeed * 2.23694 <= 10) {
    display.print("  ");
  } else if (airspeed * 2.23694 <= 100) {
    display.print(" ");
  }
  display.println(airspeed * 2.23694);
  display.setTextSize(1);
  display.display();

  delay(10);
}
