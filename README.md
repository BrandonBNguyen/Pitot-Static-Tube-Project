# 3D Printed Pitot Static Tube Project

## Introduction

This is an on-going project to design and develop an instrument capable of acquiring accurate measurements of air speed. 

## To Do List

 - [x] Select and order components
	 - [x] Pressure sensors ([BMP180](https://www.amazon.com/gp/product/B07Q3PQ81R/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1))
	 - [x] Display ([UCTRONICS 0.96 Inch OLED Module](https://www.amazon.com/gp/product/B072Q2X2LL/ref=ppx_yo_dt_b_asin_title_o01_s00?ie=UTF8&psc=1))
	 - [x] Microcontroller ([Teensy LC Board](https://www.pjrc.com/teensy/teensyLC.html))
	 - [x] Nozzle-to-sensor tubing ([4 mm OD pneumatic hose](https://www.amazon.com/gp/product/B07H87S1ZW/ref=ppx_yo_dt_b_asin_title_o06_s00?ie=UTF8&psc=1))
	 - [x] Power source (USB A to microUSB cable)
 - [ ] Develop CAD Model
	 - [x] Pitot static tube nozzle assembly
	 - [ ] Housing assembly for microcontroller and pressure sensors
 - [x] Test Electronics
	 - [x] Get pressure readings from single BMP 180
	 - [x] Get pressure readings from both BMP 180 sensors simultaneously.
	 - [x] Display pressure measurements and air speed reading to OLED display.
 - [ ] Manufacture Components
	 - [x] 3D print nozzle assembly
	 - [ ] 3D print housing assembly
	 - [ ] Fasten microcontroller, pressure sensors, and OLED display to housing.
	 - [ ] Solder and connect wiring.
	 - [ ] Connect tubing from nozzle assembly to housing assembly.
	 - [ ] Apply sealant to joints and openings in chamber housing pressure sensors.

## Theory

A pitot static tube is an instrument that measures air speed by measuring the pressure at an opening facing directly into the air flow (stagnation pressure), measuring the pressure at an opening perpendicular to the air flow (static pressure), and using the difference in pressure between the two to calculate air speed via Bernoulli's equation.

![Pitot-Static Tube](https://www.grc.nasa.gov/www/k-12/airplane/Images/pitot.jpg)

The pitot static tube will be tested to measure air speed from a moving car. The density used in the Bernoulli equation from the above diagram will be calculated from pressure and temperature measurements taken from a stationary position.

## Part Selection

### Sensor Selection

The BMP180 barometric pressure and temperature sensor module was selected to record the differences in pressure between the stagnation pressure and static pressure.

![BMP180 Sensors](https://images-na.ssl-images-amazon.com/images/I/71z43F3PxVL._AC_SL1500_.jpg)

With a resolution up to 0.03 hPa (3 Pa), the anticipated accuracy of using this sensor to measure air speed is within 2.2 m/s (4.9 mph).

![Sensor Accuracy Equation](https://latex.codecogs.com/gif.latex?%5CLARGE%20V%20%3D%20%5Csqrt%7B%5Cfrac%7B2%283%5Ctext%7B%20Pa%7D%29%7D%7B1.225%5Ctext%7B%20kg/m%7D%5E3%7D%7D%20%3D%202.2%5Ctext%7B%20m/s%7D%5Capprox%204.9%5Ctext%7Bmph%7D)

### Microcontroller Selection

Initial tests to acquire measurements from both BMP180 sensors using an Arduino Uno were unsuccessful due to the sensors sharing the same I2C address. The ability to measure from both sensors and thus record a pressure difference between stagnation and static pressure would require either the use of a multiplexer or a microcontroller with multiple I2C buses. To reduce the number of components used, saving on space and work required to assemble, the latter solution was chosen and the Teensy LC microcontroller board was selected.

### Display

To display the recorded pressure difference and resulting air speed measured from the pitot static tube, the UCTRONICS OLED Module 12864 was selected.

![UCTRONICS OLED Module 12864](https://images-na.ssl-images-amazon.com/images/I/51C%2B7ykfGmL._AC_SL1000_.jpg)

## CAD Design

### Nozzle Assembly

The nozzle assembly is designed to be clamped to the roof or out of the window of a car and consists of two parts: the main nozzle and the support.

![Nozzle Assembly](https://raw.githubusercontent.com/BrandonBNguyen/Pitot-Static-Tube-Project/master/Images/NozzleAssembly.PNG)
*Nozzle assembly featuring tubing running to pressure sensor chambers.*

#### Nozzle

The main nozzle has a hole in the front which will be connected to a pressure sensor chamber to measure stagnation pressure, and has a hole on the top which will be connected to a separate pressure sensor chamber to measure static pressure. The underside of the nozzle features a dovetail cutout for a rail from the support to be slotted into.

![Section View](https://raw.githubusercontent.com/BrandonBNguyen/Pitot-Static-Tube-Project/master/Images/PitotTubeNozzle_Section.PNG)
*Section view of the nozzle showing internal paths to the front and top of the nozzle to measure stagnation pressure and static pressure, respectively.*

![Underside View](https://raw.githubusercontent.com/BrandonBNguyen/Pitot-Static-Tube-Project/master/Images/PitotTubeNozzle_Underside.PNG)
*Underside view of the nozzle showing the dovetail slot to connect to the support.*

#### Support

The support features a dovetail at one end and a flat edge on the other for which to connect a clamp to hold the entire assembly in place. The support is designed in this way to place the nozzle far out in front and away from the vehicle to ensure that the instrument is not measuring reduced air speeds due to air being slowed by the boundary layer of the vehicle.

![Support rear view](https://raw.githubusercontent.com/BrandonBNguyen/Pitot-Static-Tube-Project/master/Images/Support_Rear.PNG)
*Rear view of the support showing the dovetail rail on top and the flat edge on the bottom to be clamped.*

### Initial Sensor and Board Housing

This initial design for the sensor and board housing was designed for using an Arduino Uno to measure and record readings from the BMP180 sensors and display them via serial output to a computer. Each BMP180 sensor would be housed in its own chamber with wiring passing through a wall between the chamber and the compartment holding the Arduino Uno. A lid with a hole for tubing to each chamber would be fastened to enclose the pressure sensor chambers. Silicone sealant would be used on the wall holding the wiring and between the lid and the housing to ensure an air tight seal for accurate pressure measurements from the two points on the nozzle.

 The CAD design for this was created before tests showed that the Arduino Uno would not be suitable for measuring from both sensors simultaneously. **Lesson learned: ensure that all electronic components work together as expected before designing custom parts for those components.** 

![Initial Board and Sensor Housing Design](https://raw.githubusercontent.com/BrandonBNguyen/Pitot-Static-Tube-Project/master/Images/BoardAndSensorHousing%20v1.PNG)

## Manufacturing

### Nozzle Assembly

The nozzle was printed using black PLA at 210°C with a bed temperature of 60°C. The first attempt at printing the nozzle failed when the print became separated from the build plate. This was likely due to the nozzle being a tall, thin structure with little surface area on the first layer to hold the print in place. The movement of the build plate back and forth along the Y axis and/or friction between nozzle and part likely induced stress on the first layer that lead to separation.

![Failed nozzle print attempt](https://github.com/BrandonBNguyen/Pitot-Static-Tube-Project/blob/master/Images/CE3PRO_Nozzle_20210116231118-fail.gif?raw=true)

The second attempt at printing the nozzle was printed with a raft, greatly increasing the surface area between the part and the build plate and reducing stresses on the first layer due to movement or friction with the nozzle. This resulted in a successful print.

The nozzle support was printed successfully on the first attempt. The rail fit onto the slot in the nozzle with a snug fit.

![Printed nozzle assembly](https://raw.githubusercontent.com/BrandonBNguyen/Pitot-Static-Tube-Project/master/Images/AssembledNozzleAssembly.png)

## Testing and Technical Challenges

### Shared I2C Address

A major technical problem that arose while testing the sensors was the fact that the sensors share the same I2C address. An attempted solution involved using the Arduino Uno's hardware I2C bus to measure the result from one sensor and a software I2C bus to measure the result from the other, although implementation of this solution was unsuccessful. Another solution considered was using a multiplexer to facilitate the communication between the Arduino and devices sharing I2C addresses, although this would require additional space in the housing for another component. The solution reached was to use a microcontroller that has two I2C buses such that each sensor would be on a separate I2C bus.

### Measuring from 2 BMP180 Sensors

The [SparkFun BMP180](https://github.com/sparkfun/BMP180_Breakout_Arduino_Library) library was designed to read the pressure and temperature from a single BMP180 sensor on the default I2C bus. To measure the pressure from 2 BMP180 sensors, one on the default I2C bus and the other on the second, the library had to be modified to use the `i2c_t3.h` library instead of the `Wire.h` library. Then, that library was duplicated and modified to use `Wire1` instead of `Wire` to access the BMP180 sensor on the second I2C bus. One library with the original `Wire` was used to measure the pressure from the sensor on the default I2C bus and the other with `Wire1` was used to measure the sensor on the secondary I2C bus.

## Skills Demonstrated

 - Demonstrated strong computer-aided design skills using SolidWorks in working with multiple parts in assemblies and designing custom parts for electronic components.
 - Demonstrated ability to troubleshoot.
	 - Identified cause for failure of a part to print successfully and implemented  solution to increase build plate adhesion.
	 - Identified issue with measuring from multiple sensors that share the same I2C address and identified multiple solutions before implementing the best one.
 - Demonstrated knowledge of C++ and applied it to use a microcontroller to read sensor data and display information using I2C protocol.
