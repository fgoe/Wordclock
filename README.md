# Wordclock
Arduino clock with LEDs showing the time with words

Code:
---------------
Provided is the .ino File for the Arduino IDE. Additionally needed are the following arduino libraries:
- DCF77 Library
- Time Library

Summary:
----------------
The Wordclock is a wallclock which uses 110 LEDs arranged as word to display the actual time.
Like:  Es ist fünf nach Zwölf.   (It is five past twelve)
The time is adjusted by using a DCF77 receiver.

Hardware needed:
-----------------
- Arduino. I used an Arduino Mega.
- Transistor arrays for powering the LEDs, like ULN2004.
- DCF77 Receiver.  I used the one from Pollin -> http://www.pollin.de/shop/dt/NTQ5OTgxOTk-/Bausaetze_Module/Module/DCF_Empfangsmodul_DCF1.html
- IKEA Frame Ribba with 50cm of "screen size"
- Printed and cutted foil for the screen
- Some thin woodplates for making a inside frame.
