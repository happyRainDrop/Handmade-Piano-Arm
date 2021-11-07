# Handmade-Piano-Arm
https://youtu.be/X-1xEYDmR6k

# Overview 
This was made during the summer of 2020 as my first Arduino project. It plays a C harmonic minor scale and due to its limited range of motion, cannot play any other scales.

# Mechanical design
The bottom servo rotates a Lazy Susan, causing the base to turn.
The lower servo on the arm extends and contracts the fingertip.
The upper servo on the arm extends and contracts the arm.
The enitre contraption is taped to a table so that the base position relative to the piano stays constant.

# Software design
'writeMicroseconds' takes an integer parameter and turns servo1 to the parameter-specified position.
I determined what servo positions corresponded to which notes experimentally.
