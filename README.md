# Pomodoro Timer
|This was a small, quick project I whipped up on the Arduino Nano to build a physical Pomodoro Timer [Wikipedia](https://en.wikipedia.org/wiki/Pomodoro_Technique) to increase my focus and just to do a fun little electronics project! Essentially, you can press the tacile switch, which will trigger a starting animation on the LCD screen, beep the buzzer, and switch to a solid yellow LED to indicate the timer is starting. Once started, the screen will display how much time is left in the Pomodoro. Once complete, the buzzer and yellow LED will alert you that the time is up and return to the standby screen and switch to a blinking green LED. | <img src="https://github.com/user-attachments/assets/e3aec559-6733-4e56-8947-ccb84cb1dfb6" width="10000"> |
|---|---|

## Outside Sources
In this project, I utilized (but changed up) code from [phenoxyethanol on Instructables](https://www.instructables.com/Simple-Progress-Bar-for-Arduino-and-LCD/) for the LCD screen animation. Or you can follow their [YouTube Video here](https://www.youtube.com/watch?v=PkcyvoncWcw). Additionally, you will need to install the CountDown library from [Rob Tillaart](https://github.com/RobTillaart/CountDown).

## Parts Used
|     Part      |   Quantity    |
| ------------- | ------------- |
| LCD Screen (16x2) |     1     |
| Passive Buzzer |     1        |
| Tactile Switch |     1        |
|     LEDs       |     2        |
| Potentiometer (10k) |     1   |
| Resistors (220 ohm)|     4    |

## Schematic
![image_2024-07-31_154217613](https://github.com/user-attachments/assets/afd917fc-f667-40e2-a526-4a86cf7d2591)
