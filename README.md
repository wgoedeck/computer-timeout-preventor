# computer-timeout-preventor
Ardiuno project that plugs into a computer USB port to prevent timeouts by generating random keystrokes at random times.

### Description of program <a class="anchor" id="description"></a>

This project uses a Pro Micro, an Arduino-compatible microcontroller plugged into the computer's USB port programmed to generate random keystrokes at random times to keep it from going into timeout mode. This is especially helpful with computers or laptops that have an builtin unadjustible timeout that may require much effort to reapeatidly sign back in. 

In this case, the module is programmed to prevent a timeout occuring every fifteen minutes by generating a random keystroke at random intervals between seven and fourteen minutes, thus simulating someone punching a key now and then. 
