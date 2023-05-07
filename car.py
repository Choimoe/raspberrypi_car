import RPi.GPIO as GPIO
import time
import sys
 
 
class Car(object):
    def __init__(self):
        self.enab_pin = [5,6,13,19]
        self.inx_pin = [21,22,23,24]
        self.RightAhead_pin = self.inx_pin[0]
        self.RightBack_pin = self.inx_pin[1]
        self.LeftAhead_pin = self.inx_pin[2]
        self.LeftBack_pin = self.inx_pin[3]
        self.setup()
 
    def setup(self):
        print ("begin setup ena enb pin")
        GPIO.setmode(GPIO.BCM)
        GPIO.setwarnings(False)
        for pin in self.enab_pin: 
            GPIO.setup(pin,GPIO.OUT)
            GPIO.output(pin,GPIO.HIGH)
        pin = None
        for pin in self.inx_pin:
            GPIO.setup(pin,GPIO.OUT)
            GPIO.output(pin,GPIO.LOW)
        print ("setup ena enb pin over")
 
    def front(self):
        self.setup()
        GPIO.output(self.RightAhead_pin,GPIO.HIGH)
        GPIO.output(self.LeftAhead_pin,GPIO.HIGH)
 
    def leftFront(self):
        self.setup()
        GPIO.output(self.RightAhead_pin,GPIO.HIGH)
 
    def rightFront(self):
        self.setup()
        GPIO.output(self.LeftAhead_pin,GPIO.HIGH)
 
    def rear(self):
        self.setup()
        GPIO.output(self.RightBack_pin,GPIO.HIGH)
        GPIO.output(self.LeftBack_pin,GPIO.HIGH)
 
    def leftRear(self):
        self.setup()
        GPIO.output(self.RightBack_pin,GPIO.HIGH)
 
    def rightRear(self):
        self.setup()
        GPIO.output(self.LeftBack_pin,GPIO.HIGH)
 
def main(status):
    car = Car()
    if status == "front":
        car.front()
    elif status == "leftFront":
        car.leftFront()
    elif status == "rightFront":
        car.rightFront()
    elif status == "rear":
        car.rear()
    elif status == "leftRear":
        car.leftRear()
    elif status == "rightRear":
        car.rightRear()
    elif status == "stop":
        car.setup()
             
 
if __name__ == '__main__':
    main(sys.argv[1])
