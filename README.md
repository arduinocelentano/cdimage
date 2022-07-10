# cdimage
A tool for burning visible pictures on a compact disc surface

![alt text](https://github.com/arduinocelentano/cdimage/blob/main/demo.png)

I know of at least two successful attempts to implement a similar technique. One was accomplished about 15 years ago by [argon](https://www.instructables.com/Burning-visible-images-onto-CD-Rs-with-data-beta/) Instructables user. Another was made by a person with nickname [undefer]. Unfortunately I have not found her or his original GitHub or whatever repository. If you have a link, let me know to fill this gap. These two projects inspired me some time ago. And in fact my coordinate conversion code is mostly based on [undefer]’s implementation. I also used geometric parameters of some compact discs from that project. I acknowledge and am grateful to these developers for their contributions.

I played with color shades and different compact discs with moderate success and created a GUI with visual preview mode. I tried to implement a user-friendly solution but finally abandoned the project in 2008 due to a problem of calibration for every particular brand and type of compact disc. Recently I found my old code and decided to share it. More as a tribute to the compact disc era. But maybe you will make some use of it. I fixed some obvious bugs, brushed the code up a little and ported it to modern Qt6. I considered porting to Python but I still need C++ because audio track generation takes some time even on modern hardware.
