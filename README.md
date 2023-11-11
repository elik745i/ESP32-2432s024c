# openHASP custom firmware for ESP32-2432s024c board

[![GitHub Workflow Status]( https://img.shields.io/github/actions/workflow/status/HASwitchPlate/openHASP/build.yaml?branch=master&label=build%20status&logo=github&logoColor=%23dddddd)](https://github.com/HASwitchPlate/openHASP/actions)
[![GitHub release](https://img.shields.io/github/v/release/HASwitchPlate/openHASP?include_prereleases)](https://github.com/HASwitchPlate/openHASP/releases)
[![GitHub issues](https://img.shields.io/github/issues/HASwitchPlate/openHASP.svg)](http://github.com/HASwitchPlate/openHASP/issues)
[![Discord](https://img.shields.io/discord/538814618106331137?color=%237289DA&label=discord&logo=discord&logoColor=white)][3]
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/HASwitchPlate/openHASP/blob/master/LICENSE)


Control your home-automation devices from a customizable touchscreen UI connected via MQTT.

This project is a re-implementation of the popular HASwitchPlate sketch created by aderusha.
The [HASPone][1] project uses a Wemos D1 mini and requires a Nextion/TJC HMI display.
This rewrite removes the Nextion/TJC hardware requirement by using the [Light and Versatile Graphics Library][2] on the MCU to drive a commodity display.

openHASP uses the ESP32 and STM32F4 to take advantage of the hardware capabilities.


## Demo Screens

![Screenshot](https://www.openhasp.com/0.6/assets/images/screenshots/demo_switches_covers.png) &nbsp; 
![Screenshot](https://www.openhasp.com/0.6/assets/images/screenshots/demo_jaffa1.png) &nbsp; 
![Screenshot](https://www.openhasp.com/0.6/assets/images/screenshots/demo_mediaplayer.png)
![Screenshot](https://github.com/elik745i/ESP32-2432s024c/blob/master/ezgif-2-2f3b01c313.gif)

## Discussions
[Link to OpenHASP Forum Post](https://community.home-assistant.io/t/openhasp-an-mqtt-driven-touchscreen-scene-controller/300853/407)


## Device prototype
![Screenshot](https://github.com/elik745i/ESP32-2432s024c/blob/master/V3.1.gif)
[![YouTube Video](https://img.youtube.com/vi/8gqbHzWds7E/0.jpg)](https://youtu.be/8gqbHzWds7E)


## Getting Started

Check out the [documentation](https://www.openhasp.com/) for how-to's, information and frequently asked questions.</br>
For support using openHASP, please join the [#openHASP channel][3] on Discord.

## STL case

[Link to STL files for printing](https://www.thingiverse.com/thing:6274345)



[1]: https://github.com/HASwitchPlate/HASPone
[2]: https://github.com/lvgl/lvgl
[3]: https://www.openhasp.com/discord
[4]: https://www.paypal.com/donate/?business=E76SN28JLZCXU&currency_code=EUR
