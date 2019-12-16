
# MettatonSquared v0.0.2

The goal? Try to make a prototype of a brand new fighting system for RPGs!

For that, i will first try to remade the Undertale combat system using SDL.

Then, it will be Deltarune...

And from that, i will try to implement mine.

Mettaton EX will be the dummy enemy that i will use for this demo.


I mean...
You can't have too much Mettaton, and this is going to take a while...


# How to build this shit

While i'm pretty sure that you can use another ide, i highly advise to use visual studio for this project.
Those instructions are for windows only.

1) Clone/Download project

    Pretty much self explanatory. Just download the project somewhere on your pc.

2) Download SDL development libraries.

    https://gofile.io/?c=ORFyLL

3) Create an "SDL" repository at the root of your hard drive. Very important : the root. 

    Extract the archive in this directory.
    You should have 4 sub-directories in the C:/SDL folder, called SDL2, SDL2_imageEdition, SDL2_mixer, TIFF.

4) For each of those directories, go into the include/x86 folder and copy paste all DLL files into the root of the project.
The project should now be able to build.


If you still can't make the project run, try to follow these instructions first : http://lazyfoo.net/tutorials/SDL/01_hello_SDL/windows/msvsnet2010u/index.php

And these one next: http://lazyfoo.net/tutorials/SDL/06_extension_libraries_and_loading_other_image_formats/windows/msvsnet2010u/index.php (for image, mixer and ttf, you will know what i'm talking about once you get there)


