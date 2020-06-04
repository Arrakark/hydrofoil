import pigpio

class Servo:
    def __init__(self, gpioPin):
        self.pi1 = pigpio.pi()
        self.gpioPin = gpioPin
         
    def sendDutyCycle(self, value):
        self.pi1.set_servo_pulsewidth(self.gpioPin, value)