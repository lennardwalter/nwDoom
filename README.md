## nwDoom - Doom for the numworks graphing calculator

You can play Doom almost anywhere, even on a Nokia N900. But not on the Numworks calculator? This looks like a job for me! 

At the moment the port only works on the simulator. There are a lot errors because of all the IO stuff, which obviously doesn't work on the calculator. But even if we fixed those it probably wouldn't work because of memory restrictions.  
I'm pretty sure it is possible to do, but there is still a lot of optimizing required to actually make it work.  

A huge bottleneck for example is the whole RGBA8888 frame we keep in memory.
Any pullrequest is welcome. A first step would be to eliminate all compiler errors.

# Installation

Put the "doom"-folder into apps/ and compile with `make PLATFORM=simulator EPSILON_APPS="doom settings"`.
