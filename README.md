# Entropymon v0.0.1

Just a fun thing I wrote to show you about how much entropy your system has currently. The display updates about every quarter-second, giving you a percentage of your entropy generated.  
  
All information is gathered from `/proc/sys/kernel/random/entropy_avail`.  
  
![](screenshots/gifs/entropymon.gif)  
  
## Dependencies
* ncurses [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)  
* clang-8.0.1 License: UoI-NCSA  
* gcc-8.3.0 [![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
[![License: LGPL v3](https://img.shields.io/badge/License-LGPL%20v3-blue.svg)](https://www.gnu.org/licenses/lgpl-3.0)
[![License: FDL 1.3 ](https://img.shields.io/badge/License-FDL%20v1.3-blue.svg)](https://www.gnu.org/licenses/fdl-1.3)  

## Install  
Just type the usual:  
```make```  
  
This will install the application `entropymon` to `/usr/local/bin`  
```make install```  
  
## License [![License: GPL v2](https://img.shields.io/badge/License-GPL%20v2-blue.svg)](https://www.gnu.org/licenses/old-licenses/gpl-2.0.en.html)
This project is license under GPLv2  
  
(Not that I really know much about licensing so maybe it'll change)  
