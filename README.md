# Budget Deck
Like the elgato streamdeck but cheaper, and worse.
Schematics are still in progress.
Right now, it works fine but there are changes that have to be made in order to improve.
My main goal is to rework completely the script getting rid of the keyboard library and using serial instead.
By using serial it should be easy to read shortcuts from a folder and send the microcontroller the names of the shortcuts, then the arduino would display the shortcuts in groups of 4 (like it currently does) and when a key is pressed either change the elements on the screen or activate the shortcut accordingly.
