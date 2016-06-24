# ROS Setup steps
#### http://wiki.ros.org/kinetic/Installation/Ubuntu

1. Setup your sources.list  
>sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'

2. Set up keys
>sudo apt-key adv --keyserver hkp://ha.pool.sks-keyservers.net:80 --recv-key 0xB01FA116

3. update apt repo
>sudo apt update  
>apt-cache search ros-kinetic

4. Installation
> sudo apt install ros-kinetic-desktop-full  
> sudo rosdep init  
> rosdep update  

5. Environment setup
> echo "source /opt/ros/kinetic/setup.bash" >> ~/.bashrc  
> source ~/.bashrc

6. install rosinstall
> sudo apt install python-rosinstall
