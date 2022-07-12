# cdimage
A tool for burning visible pictures on a compact disc surface

![alt text](https://github.com/arduinocelentano/cdimage/blob/main/demo.png)

## Project's Origins and Credits
I know of at least two successful attempts to implement a similar technique. One was accomplished about 15 years ago by [argon](https://www.instructables.com/Burning-visible-images-onto-CD-Rs-with-data-beta/) Instructables user. Another was made by a person with nickname [undefer]. Unfortunately I have not found her or his original GitHub or whatever repository. If you have a link, let me know to fill this gap. These two projects inspired me some time ago. And in fact my coordinate conversion code is mostly based on [undefer]’s implementation. I also used geometric parameters of some compact discs from that project. I acknowledge and am grateful to these developers for their contributions.

I played with color shades and different compact discs with moderate success and created a GUI with visual preview mode. I tried to implement a user-friendly solution but finally abandoned the project in 2008 due to a problem of calibration for every particular brand and type of compact disc. Recently I found my old code and decided to share it. More as a tribute to the compact disc era. But maybe you will make some use of it. I fixed some obvious bugs, brushed the code up a little and ported it to modern Qt6. I considered porting to Python but I still need C++ because audio track generation takes some time even on modern hardware.

## Building
You'll need [Qt 6](https://www.qt.io/product/qt6) library to build it. Just run `qmake` and then `make`. Alternatively you could build the project with [Qt Creator](https://www.qt.io/product/development-tools) if you installed it.

## Before you start
If your compact disc is not mentioned in the track generating dialog, you'll probably fail. All the discs are slightly different geometrically. This difference does not matter for data storage but dramatically influences image calculation.
You could try to guess geometry of an unknown disc and input it manually, but you'll probably spoil a lot of discs before you get some results. Moreover, all your test discs should be perfectly identical or you should use the same CD-RW disc. Sometimes discs of the same model happen to have different parameters. Don't know why. After all, manufacturers have never cared since those discs were never supposed to be used this way.

## Further readings

[Probably the first implementation of similar technique](https://www.instructables.com/Burning-visible-images-onto-CD-Rs-with-data-beta/).

[The "Red Book"](https://www.ecma-international.org/wp-content/uploads/ECMA-130_2nd_edition_june_1996.pdf) (CD-ROM ECMA standard).

[Hackaday post](https://hackaday.io/project/186303-burning-pictures-on-a-compact-disc-surface) about this project.

[A project regarding optical drive reverse engineering](https://scanlime.org/2016/08/scanlime001-coastermelt-part-1/). Not related directly to this project, but might be useful to give you a clue to how it probably could be done with hardware approach. Thanks to [some guy](https://hackaday.com/2022/07/11/burn-pictures-on-a-cd-r-no-special-drive-needed/#comment-6491772) for suggestion.
