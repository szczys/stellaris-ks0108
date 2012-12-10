# KS0108 Graphic LCD driver for Stellaris Launchpad (ARM)

This is based on the library found here:

[http://en.radzio.dxp.pl/ks0108/](http://en.radzio.dxp.pl/ks0108/)

##Known issues:
* The read functionality is not used at all
* I tied RS to ground to get this to work
* I tied RST to voltage (it is active low)

##More info:
[Jumptuck.com article](http://jumptuck.com/2012/12/10/level-converter-lets-5v-hardware-33v-arm-chips)
