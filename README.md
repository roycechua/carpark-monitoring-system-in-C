# carpark-monitoring-system-in-C
This was my first system done in college for CS-100 Fundamentals of Programming and Algorithms way back in 2014 at my college. I am uploading it as a demonstration of what you can do with C programming in terms of making a simple terminal based system like this one.

# Features
- **Password protected interface** - You need to enter the correct pin to gain access. This is to prevent unauthorized access when the person manning the computer is away.
- **8 available parking slots** - This is a fixed number (can be improved).
- **Simple User-interface** - You can view the slots available and slots currently taken on the screen.
- **Reserve / Free a parking a slot** - You can place a car in an available slot. 
- **Time-based costing** - Enter the time the car came and and car exited and the price to be paid will be computed (base cost + additional cost per hour). The limitation of this program is that the system doesn't handle overnights (more than 24 hours).
- **Lock the program** - You can lock the program if you plan to go out and leave your machine unattended.

# Software used
On the Windows version, I used to run the program with **Dev-C++** program and on Linux, I just compiled it with **gcc**. You can use the code
``` 
gcc -o CMPS-linux CMPS_Version1-70-linux.c
```
This will generate an executable for the linux-based operating system which you can execute by typing 
```
./CMPS-linux
```

# License
MIT License

# Notes
This being my first project back a long time ago back when VCS like Git wasn't still a thing in schools, which means it's sequential and filled with some bugs though the main features work. I worked on it alone and if in case someone wants to make an improvement just email me or submit a pull request.