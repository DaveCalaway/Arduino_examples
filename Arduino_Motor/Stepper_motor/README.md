# Arduino_Motor examples  

### Stepper Motor guide:

### Hardware
We must need to understand what type of motor you have:
![GitHub Logo](http://89.22.98.13/pylog/cnt/projects/shapeoko/_img/stepper/stepper.png)
* Bipolar
* Unipolar

Why we need to understand what type of motor we have?  
Becouse the driver change if you have Bi or Uni.
* Bipolar = L293D ( H-Bridge )
* Unipolar = ULN2023 ( Darlington Transistor Array )

My motor has different wires, have we a rule beautine wires and type of motor?  
* 4 wires = Bipolar
* 5 & 6 wires = Bipolar & Unipolar


### Software
Don't worry about the software.
All software in this guide are mode for Bipolar & Unipolar motors.

No library needed.
