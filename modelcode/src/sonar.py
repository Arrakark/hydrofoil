import pigpio

class Sonar:
    def __init__(self, triggerPin, echoPin):
        self.pi1 = pigpio.pi()
        self.triggerPin = triggerPin
        self.echoPin = echoPin
         
    def sendPulse(self):
        self.pi.gpio_trigger(self.triggerPin, 10, 1)