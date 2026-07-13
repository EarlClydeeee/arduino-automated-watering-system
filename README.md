General Objective
To design and develop an Arduino-based smart entry gate system that provides automated access control, gate operation, status display, and visitor monitoring.
Specific Objectives
To authenticate users using RFID cards/tags and PIN entry.
To store authorized RFID UIDs using the Arduino Uno’s onboard EEPROM.
To automatically open and close the gate using a servo motor.
To detect motion and object presence using PIR and IR sensors.
To display real-time system status through a 16x2 I2C LCD.
To provide access feedback using green, red, and yellow LED indicators.
To activate a buzzer or relay during denied access or alert conditions.
To include push buttons for override, reset, and mode selection.
To count successful entries for basic visitor monitoring.
To improve security, convenience, and efficiency in entry management.
5. Scope and Limitations
Scope
The project will cover the development of a prototype smart entry gate system with the following features:
RFID-based access using the RC522 RFID reader
PIN-based access using a 4x4 matrix keypad
Arduino-based authentication and control logic
EEPROM storage for authorized RFID UIDs
Servo motor gate arm control
PIR motion detection
IR proximity detection for auto-close support
LCD for system messages
LED and buzzer alerts
Relay output for lock or siren activation
Push buttons for override, reset, and mode selection
Entry counter for visitor count monitoring
Limitations
The system will be implemented as a prototype only.
RFID storage is limited by the Arduino Uno’s EEPROM capacity.
The system depends on a stable 5V power supply.
The servo motor requires a separate 5V 1A supply to prevent brownout.
The system does not include cloud database, mobile app, or web monitoring.
It has lower security compared to commercial biometric systems.
RFID cards may be lost, shared, or duplicated.
Outdoor use requires additional enclosure and weather protection.
Visitor counting may be inaccurate if multiple people pass at the same time.
6. Significance of the Project
This project can benefit schools, offices, laboratories, residential areas, and small facilities that need a simple and affordable access control system. It can help reduce manual gate operation, improve monitoring, and prevent unauthorized entry.
Security personnel and administrators can use the system to manage entry more efficiently through RFID/PIN authentication, status indicators, alarms, and entry counting. Users also benefit from a faster and more convenient entry process.
For Computer Engineering students, the project is useful because it applies important concepts such as microcontroller programming, SPI and I2C communication, sensor integration, PWM control, EEPROM storage, relay control, and embedded system design.
