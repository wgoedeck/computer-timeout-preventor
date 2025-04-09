# computer-timeout-preventer
Ardiuno project that plugs into a computer USB port to prevent timeouts by generating random keystrokes at random times.

### Description of Device
This project uses a *Pro Micro*, an Arduino-compatible micro-controller that is plugged into the computer's USB port that then generates random keystrokes at random times to keep the computer from going into timeout mode. This is especially helpful with computers or laptops that have a builtin timeout that it not accessible by the user and requires much effort for one to repeatedly sign back in.

For this particular project the module is programmed to prevent a computer timeout occurring every fifteen minutes by generating a random keystroke at random intervals between seven and fourteen minutes, thus simulating someone punching a key now and then to keep the computer “awake.”

<img src="https://github.com/wgoedeck/computer-timeout-preventor/blob/main/arduino_pro_micro.jpg"  width="600" alt="Project photo">

### Hardware
A small *Pro Micro* Arduino compatible micro-controller is used, such as one offered at Sparkfun Electronics (c.f., https://www.sparkfun.com/pro-micro-5v-16mhz.html) that is an analog to digital converter among having other versatile functions. It will connect to a computer USB port by a *Micro-B to USB cable* (see photo). Once connected to a computer, it requires no other power than what the computer port supplies. 

One needs to be careful of the cable connection to the circuit board in that excessive cable movements may strain the solder joints of the cable jack on the circuit board. Other Arduino micro-controllers can be used, such as an *Arduino Uno*, although it is much larger than the *Pro Micro*. The photo shows the *Pro Micro* attached to a small breadboard, but can be mounted otherwise or not at all; however, the device should not come into contact with metal, causing shorting between onboard components or the pins. 

### Software
The unit is programmed by an *Arduino IDE* (Integrated Development Environment) program, freely available for installation on most computers. Referring to *keystroke generator.ino*, the Arduino C++ code that runs the unit, it is simple. The program initializes a random seed from pin 0 of the unit: 

    randomSeed(analogRead(0));

In the loop that then repeats, a random number is generated from 32 to 127, which is the list of ASCII printable characters from *space* to *delete*, and includes numbers and letters:

    data = random(32, 127);

The random number then simulates a keystroke, which is then released: 

    Keyboard.press(data);
    Keyboard.releaseAll();

The release is necessary otherwise the character would repeatedly be output to the computer. A commented-out section of the code would then generate a backspace after a one-second delay to erase the generated character, but is generally not needed. 

    //delay(1000);
    //Keyboard.press(8);
    //Keyboard.releaseAll();

After a delay of a random period from seven to fourteen minutes, the loop is repeated. 

	// Random delay time between 7 & 14 minutes.
	delayTime = random(420000, 840000);
	delay(delayTime);

### Addendum
The cable’s connection to the circuit board is suspect to wear, causing the connection jack to separate from the board, so additional strain relief is warranted, such has stabilizing the cable to a breadboard that the unit is mounted on, or better yet, the device put into a small plastic chassis with the output cable clamped down upon. 

One can add an external USB hub to the computer to add more USB ports in case insufficient USB ports are available to use this device. 
