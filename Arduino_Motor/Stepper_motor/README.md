# Arduino_Motor examples  

### Stepper Motor guide:

### Hardware
We must need to understand what type of motor you have:
![GitHub Logo](http://89.22.98.13/pylog/cnt/projects/shapeoko/_img/stepper/stepper.png)
* Bipolar
  - Need Voltage Reversal
  - Higher Torque
  - Slower max speed
* Unipolar
  - No Voltage Reversal
  - Lower Torque
  - Higher max speed

Why we need to understand what type of motor we have?  
Becouse the driver change if you have Bi or Uni.
* Bipolar = L293D ( H-Bridge https://goo.gl/TU3yrG )
* Unipolar = ULN2003 ( Darlington Transistor Array https://goo.gl/8j6WHp )

My motor has different wires, have we a rule beautine wires and type of motor?  
* 4 wires = Bipolar
* 5 & 6 wires = Bipolar & Unipolar


### Software
Don't worry about the software.
All software in this guide are mode for Bipolar & Unipolar motors.

No library needed.
