# The Snag Pad

The official mascot pad of the 2018 Sydney mechanical keeyboard meetup. Based on the Pro Micro. 

## Building

To build, first make sure the bottom cover is off so you can access the reset pins. Then, be ready with a screwdriver to short the second and third pin on the right (with the usb port pointing up, looking at the face with lights and atmel chip).
```   
|--[USB]--| 
|.       .|       
|.       .|<-- Here are the second and third pin 
|.       .|<-- counting first pin as 1, not 0
|.       .|    Short the bastards twice.
```

Now, if you have your build chain installed, go to root of repo and type:  
```bash
make snagpad:default:avrdude
```  
When it asks you to reset the pro micro, touch those two pins twice quickly (you have 750ms) and it should connect to the programmer and flash. Resetting with the double tap puts the thing in boot loader mode for 8 seconds btw.

If you don't have the build tools the [docs are here](https://beta.docs.qmk.fm/detailed-guides/getting_started_build_tools)

You can also flash the pro micro using xloader, qmktoolbox or avrdudess if you select your hex file and do the reset short.

## Peeps

* PCB designed by Don Chiou, u/flehrad
* Case provided by laser_ninja, u/meowffins