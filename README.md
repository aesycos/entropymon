# Entropymon v0.0.1

Just a fun thing I wrote to show you about how much entropy your system has currently.  
The display updates about every quarter-second, giving you a percentage of your entropy generated.  
All information is gathered from `/proc/sys/kernel/random/entropy_avail`.  


![](screenshots/gifs/entropymon.gif)

## Dependencies
* [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT) ncurses 
* clang or gcc

## Install
Just type the usual...  
```make```

This will install the application `entropymon` to `/usr/local/bin`  
```make install```

## [![License: GPL v2](https://img.shields.io/badge/License-GPL%20v2-blue.svg)](https://www.gnu.org/licenses/old-licenses/gpl-2.0.en.html)License
This project is license under GPLv2  
(Not that I really know much about licensing so maybe it'll change)
