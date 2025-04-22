# Smart Auto-Blinds System

## Project Overview
This project involves designing and developing an **automated smart blinds system** using **NodeMCU**, **LDR sensors**, **IR sensors**, and **Servo motors**. The system adjusts the blinds automatically based on the light intensity inside and outside a room. The system also has motion detection to close the blinds when someone is detected outside. Additionally, you can control the blinds remotely using the **Blink App**.

## Features
- **Automatic Blinds Control**: Adjusts blinds based on light intensity from inside and outside the room.
- **Motion Detection**: Uses an IR sensor to detect motion and automatically close the blinds if someone is outside.
- **Remote Control via Blink App**: Use the Blink app to open and close the blinds remotely.
- **Energy-Efficient**: Powered by NodeMCU, optimized for low power consumption.

## Technologies Used
- **NodeMCU (ESP8266)**: Microcontroller for controlling the system.
- **Servo Motor**: Controls the position of the blinds.
- **LDR Sensors**: Detect light intensity inside and outside the room.
- **IR Sensor**: Detects motion outside the room.
- **Blink App**: Provides remote control functionality via the cloud.
- **Arduino IDE**: Used to write and upload the code to NodeMCU.

## Hardware Requirements
- NodeMCU ESP8266
- Servo Motor
- LDR Sensors (2)
- IR Motion Sensor
- Jumper wires
- Breadboard (optional)

## Software Requirements
- Arduino IDE
- Blink Library for Arduino
- Wi-Fi credentials for NodeMCU

## Setup and Installation
1. **Download Arduino IDE**: If you don’t have it installed, download and install the [Arduino IDE](https://www.arduino.cc/en/software).
2. **Install NodeMCU ESP8266 Board**: In the Arduino IDE, go to **File > Preferences** and in the **Additional Boards Manager URLs** field, enter:
http://arduino.esp8266.com/stable/package_esp8266com_index.json
Then, go to **Tools > Board > Boards Manager**, search for `esp8266`, and install it.
3. **Install the Blink Library**: Go to **Sketch > Include Library > Manage Libraries**. Search for `Blink` and install it.
4. **Upload the Code**: Open the Arduino IDE, copy the code provided above, and upload it to your NodeMCU.

## Usage
1. Open the **Blink app** on your phone.
2. Create a new device and get the **Auth Token** and **Device Name** from the app.
3. Replace the `authToken` and `deviceName` in the code with your own.
4. Upload the code to the NodeMCU, and the blinds will automatically adjust based on light levels or can be controlled via the Blink app.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

