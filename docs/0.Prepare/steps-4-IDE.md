# IDE Setup steps (QtCreator)


## Ref urls
* http://wiki.ros.org/IDEs
* https://help.ubuntu.com/community/UnityLaunchersAndDesktopFiles  


## Steps
### 1. download & install qtcreator
download from http://download.qt.io/official_releases/, fileSize>600MB   extract it  
open terminal, $ ./qt-opensource-linux-x64-5.7.0.run  
gedit ~/.bashrc, export PATH=/home/hjl/program/Qt5.6.0/Tools/QtCreator/  bin:$PATH  
create hello project and run.  


### 2. install sublimeText3 and plugin
https://github.com/timonwong/OmniMarkupPreviewer


### 3. create .desktop file
cd ~/Desktop/  
touch qtcreator.desktop  
gedit qtcreator.desktop  
```
[Desktop Entry]
Exec=bash -i -c qtcreator %F
Icon=QtProject-qtcreator
Type=Application
Terminal=false
Name=QtCreator4ROS
GenericName=Integrated Development Environment
MimeType=text/x-c++src;text/x-c++hdr;text/x-xsrc;application/x-designer;application/vnd.nokia.qt.qmakeprofile;application/vnd.nokia.xml.qt.resource;
Categories=Qt;Development;IDE;
InitialPreference=9
```
open/run it from desktop,you **CAN'T** run a .desktop file from the shell.

### 4. import projects into QtCreator
"Open File or Project" and select the top level CMakeLists.txt of the catkin workspace (e.g. "src/CMakeLists.txt")
