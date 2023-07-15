## Controlling a Robot with EMG Sensors and Arduino 
This project was conducted for the bachelor's degree by [Ali Mahdili](https://www.linkedin.com/in/ali-mahdili-5340a1234?originalSubdomain=ir)under the supervision of [Dr.Mehdi Baradarannia](https://scholar.google.com/citations?user=zclZQhcAAAAJ) at the [University of Tabriz](https://en.wikipedia.org/wiki/University_of_Tabriz).

This project has been carried out in several stages, which are described below:
- [x] Setting up and receiving correct data from the sensor - April 2023
- [x] Controlling the robot in three states (stop-forward-backward) by connecting with a wire - June 2023
- [x] Controlling the robot in three states (stop-forward-backward) by [wireless connection](#wireless-connection) - July 2023

## Description

This project allows you to control a robot using EMG [Electromyography](https://en.wikipedia.org/wiki/Electromyography) sensors and Arduino. It also includes a remote control functionality using NRF24L01 modules. The system interprets muscle signals captured by the EMG sensors and translates them into commands for the robot, enabling intuitive control based on muscle movements.
![R](https://github.com/tfrbf/EMG-Robot/assets/79377894/04193254-7e55-4854-9875-94f626c335c0)



## Features

- Control the robot using EMG signals
- Remote control functionality via Bluetooth modules
- Real-time interpretation of muscle signals for responsive control
- Adjustable sensitivity and calibration options for personalized control
- Support for multiple robotic platforms

## Hardware Requirements

- Arduino board (*2)
- EMG sensors
- [NRF24L01 modules](https://www.seeedstudio.com/blog/2019/11/21/nrf24l01-getting-started-arduino-guide) (*2)
- Robot platform
- [Motor driver](https://lastminuteengineers.com/l298n-dc-stepper-driver-arduino-tutorial/) (L298N)
- Power supply
- Connecting wires

## Software Requirements

- Arduino IDE
- Arduino libraries for modules

## Installation

1. Clone or download the repository to your local machine.
2. Connect the Arduino board to your computer.
3. Open the Arduino IDE and load the Arduino sketch provided in the repository.
4. Install the required libraries through the Arduino Library Manager.
5. Connect the EMG sensors to the Arduino board as per the provided documentation.
6. Connect the modules and set up the communication between the master and slive boards.
7. Compile and upload the sketch to the Arduino board.
8. Power up the robot and ensure all connections are secure.

## Usage

1. Turn on the EMG sensors and ensure they are properly positioned on the user's muscles.
2. Establish a Bluetooth connection between the remote control device and the Arduino board.
3. [Calibrate](#sensor-calibration) the system, adjusting the sensitivity and thresholds as needed.
4. The EMG signals will be continuously monitored and translated into control commands for the robot.
5. Use the remote control device to send commands via Bluetooth, allowing manual control of the robot.
6. Explore the possibilities of controlling the robot through muscle movements and the remote control interface.

## Sensor calibration

Sensor start-ups can generally be divided into 3 steps:
1. In this step, only the data is displayed
2. by pressing the key once, the system starts to take the minimum and maximum and divides this period into 3 parts. At this stage, the system is not yet active.
3. In the last step by pressing the key for the second time, the system starts working according to the data of the previous step, so that the middle third is used for stop mode and the first and last third are used for forward and backward.

## Wireless connection 
nRF24L01 is a single-chip radio transceiver for the worldwide 2.4 - 2.5 GHz ISM 
band. The transceiver consists of a fully integrated frequency synthesizer, a power 
amplifier, a crystal oscillator, a demodulator, a modulator, and Enhanced ShockBurst™ 
protocol engine. Output power, frequency channels, and protocol setup are easily 
programmable through an SPI interface. Current consumption is very low, only 9.0mA 
at an output power of -6dBm and 12.3mA in RX mode. Built-in Power Down and 
Standby modes make power saving easily realizable.

![image](https://github.com/tfrbf/EMG-Robot/assets/79377894/3b70e499-caf3-42d7-a409-793f23ed5890)

## Contributing
We welcome contributions from the community to improve this project. If you would like to contribute, please follow these steps:

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Make your changes and ensure they are adequately tested.
4. Submit a pull request, describing the changes you have made.

## License

This project is licensed under the MIT License.

## Contact

If you have any questions, suggestions, or feedback, please get in touch with us at ali.mahdili1370@mail.com
