# An Arduino-based Control Surface
Repository for CS 207 Project files

This project is a six-fader control surface to be used with Logic Pro X (or other Digital Audio Workstations). It is based off of a previously made project by user DaniElectronics on Hackster.io. The project is USB powered, runs off the Arduino Uno, and is tailored to the MacOS. A wooden enclosure was designed and built for it. This material was chosen for aesthetic reasons but also durability. Some soldering of the components is required in order for them to be utilized with the breadboard. On the software side, a program installation (Hairless MIDI to Serial Bridge) is needed in addition to the Arduino IDE. The Arduino MIDI Library is also used. 

# Requirements and Materials 

**Dependencies:**

The Hairless MIDI to Serial Bridge: https://projectgus.github.io/hairless-midiserial/

Arduino MIDI Library: https://playground.arduino.cc/Main/MIDILibrary/ 

Digital Audio Workstation (like Logic Pro X)

**Bill of Materials:**

6 x 11K Ohm sliding potentiometers

6 x 560 Ohm resistors 

20 x Jumper wires 

1 x Breadboard 

1 x Arduino Uno

1 x (2 x 3 feet) Sheet of plywood

1 x Soldering station

1 x Solder wire

1 x Solder flux

1 x Wood chisel, hammer, and other tools

1 x Wood glue

# Build Instructions 

Solder wires onto the potentiometers and then use the pin on the other side to plug into the breadboard and Arduino. Each potentiometer is connected to power (with a baseline resistance of 560 Ohms), ground, and an analog input pin. The range of resistance on the potentiometers is 11K Ohms. 



For the enclosure, cut the wood pieces as specified in the diagrams below. Use a wood chisel to cut out the channels for the sliders. Finally, drill some holes for the potentiometer wires to run through. If including the LEDs, drill some holes above the slider channels. The approximate depth of the channels are 1.0 centimeters. Once the top plate is complete and the other pieces are cut out and sanded, use wood glue and clamps to adhere the sides to one another. 



# Usage

Plug the control surface into your computer if it is not already. Then, upload the code provided to the Arduino Uno. Open Audio MIDI Setup on MacOS and select the icon for IAC Driver. In the pop-up window, check the box that says “device is online.” After this, run the Hairless MIDI to Serial Bridge software. Ensure that the “Serial to MIDI Bridge On” box is selected as well as the correct serial port. Once the virtual MIDI port is opened, configuration with Logic Pro X can commence. In this program, navigate to Logic Pro X -> Control Surfaces -> Setup. One can add and install the control surface in the window that opens. Mapping the controls can then be done with the key command, command + L, or by navigating to Logic Pro X -> Control Surfaces -> Controller Assignments. After the faders are mapped to parameters within the digital audio workstation, you can simply move the potentiometers up and down to write automation into the track.   

# Credits

APW-Design. (2020). Building a Basic Midi Controller Part 1 - Easy 3 Pot (Potentiometer) Arduino Uno Effects Midi Controller (Serial-USB)... Quick,easy and Cheap!. Instructables.com. Retrieved 5 December 2020, from https://www.instructables.com/Easy-3-Pot-Potentiometer-Arduino-Uno-Effects-Midi-/.

DaniElectronics. (2020). Build an Arduino powered MIDI Controller. Hackster.io. Retrieved 5 December 2020, from https://www.hackster.io/danisferreira27/build-an-arduino-powered-midi-controller-7d04dd.

