# Arduino Setup steps (Ubuntu16)
#### http://wiki.ros.org/kinetic/Installation/Ubuntu

1. Get Arduino IDE
> download from: https://www.arduino.cc/  
> extract file to folder  
> gedit ~/.bashrc, add: export PATH=/home/hjl/program/arduino-1.6.9:$PATH

2. add user to dialout group
> sudo usermod -a -G dialout [yourname]  
> logout + login

3. create desktop luncher
> cp arduino.desktop.template arduino.desktop  
> update **ICON** path  
> chmod +x arduino.desktop 

4. HelloWorld
> open desktop luncher  
> connect arduino with use cable  
> select board  
> select port  
> File > Examples > Basic > Blink  
> compile + upload  

#### have fun!

 

