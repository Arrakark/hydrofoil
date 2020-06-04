import ptvsd
import sys
import os

# Debugger setup code
sys.stderr = open('../error.log', 'w')
if sys.argv.count > 1 and "debug" in sys.argv:
    ptvsd.enable_attach()
    ptvsd.wait_for_attach()

os.system('sudo pigpiod')

#
# Actual code starts here
#

import time
from servo import *
from sonar import *

pi = pigpio.pi()
trigger = 26
echo = 17
pi.set_mode(trigger, pigpio.OUTPUT)
pi.set_mode(echo, pigpio.INPUT)


global falling
global raising
falling = 0
rising = 0


def cbf(gpio, level, tick):
    global rising
    rising = tick
    return 


def cbf1(gpio,level,tick1):
    global falling
    global rising
    falling = tick1
    print(falling - rising)
    return 

cb1 = pi.callback(echo, pigpio.RISING_EDGE, cbf)
cb2 = pi.callback(echo, pigpio.FALLING_EDGE, cbf1)

while True:
    time.sleep(0.1)
    pi.gpio_trigger(trigger, 100, 1)