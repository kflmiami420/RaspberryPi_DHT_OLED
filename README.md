Adding New Fonts
For full details on adding new fonts see here.

Copy a new TrueType fonts (*.ttf) font file in the directory /usr/share/fonts (for all users) or ~/.fonts (for a specific user, e.g. /home/pi/.fonts  – create the directory if necessary and note the dot').


Add to  /usr/share/fonts

mkdir minecraftia folder  by typing sudo mkdir minecraftia

then type cd minecraftia    " so you are in the new empty folder "

then get the address from git hub for the ttf file then type 

sudo wget https://github.com/kflmiami420/RaspberryPi_DHT_OLED/raw/master/Minecraftia.ttf 

then it should work 

it does not hurt to do a sudo apt-get update and sudo apt-get upgrade

You can test the new fonts are then available using Leafpad

List Installed Fonts

fc-list










# RaspberryPi_DHT_OLED
Raspberry Pi + DHT Sensor and OLED in python code
#### Web Blog http://raspberrypi4u.blogspot.com/2017/02/raspberry-pi-dht-sensor-oled.html
#### Developer http://softpowergroup.net/ amphancm@gmail.com
![GitHub Logo](/raspberrypi_dht_oled.png)
