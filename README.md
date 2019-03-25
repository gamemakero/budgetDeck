# Budget Deck
Like the elgato streamdeck but cheaper, and worse.

Schematics are still in progress, but the main components are an arduino pro micro, a SPI OLED 1 inch display and 6 bootleg cherry mx red switches.

Right now, it works fine but there are changes that have to be made in order to improve.
My main goal is to rework completely the script getting rid of the keyboard library and using serial instead.
By using serial it should be easy to read shortcuts from a folder and send the microcontroller the names of the shortcuts, then the arduino would display the shortcuts in groups of 4 (like it currently does) and when a key is pressed either change the elements on the screen or activate the shortcut accordingly.

Secondary goal is changing to a better SSD1306 library (the OLED display controller)

STL files for the housing can be found in [Thingiverse](https://www.thingiverse.com/thing:3517440).
