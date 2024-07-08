#import RPi.GPIO as GPIO
import  time
#GPIO.setmode(GPIO.BCM)
class Motor:
    def __init__(self, pin_a, pin_b, enable):
        """
        :param pin_a: control motor(on/off)
        :param pin_b: control motor(on/off)
        :param enable: control motor PWM (speed)
        """

        self.pin_a = pin_a
        self.pin_b = pin_b
        self.enable = enable

        """ 
        GPIO.setup(self.pin_a, GPIO.OUT)
        GPIO.setup(self.pin_b, GPIO.OUT)
        GPIO.setup(self.enable, GPIO.OUT)

        self.pwm = GPIO.PWM(self.enable, 100)
        self.pwm.start(0)"""

    def forward(self, speed=50):
        print(f"moving forward with speed of "+str(speed))

        """        
        GPIO.output(self.pin_a, GPIO.HIGH)
        GPIO.output(self.pin_b, GPIO.LOW)
        self.pwm.ChangeDutyCycle(speed)
                                        """

    def backward(self, speed=50):
        print("moving backward")


        """ 
        GPIO.output(self.pin_a, GPIO.LOW)
        GPIO.output(self.pin_b, GPIO.HIGH)
        self.pwm.ChangeDutyCycle(speed)"""

    def stop(self):
        print("stopping the motors")

        """     
        GPIO.output(self.pin_a, GPIO.LOW)
        GPIO.output(self.pin_b, GPIO.LOW)
        self.pwm.ChangeDutyCycle(0)"""

class SumoMovment:
    def __init__(self,top_left,top_right,bottom_left,bottom_right):
        self.top_left=top_left
        self.top_right=top_right
        self.bottom_right =bottom_left
        self.bottom_left =bottom_right



        self.tl_speed = 50
        self.bl_speed = 50
        self.tr_speed = 50
        self.br_speed = 50

    def set_speed(self, tl_speed=50, bl_speed=50, tr_speed=50, br_speed=50):
        self.tl_speed = tl_speed
        self.bl_speed = bl_speed
        self.tr_speed = tr_speed
        self.br_speed = br_speed

    def stop(self):
        self.top_left.stop()
        self.top_right.stop()
        self.bottom_left.stop()
        self.bottom_right.stop()

    def move_forward(self):
        self.top_left.forward(self.tl_speed)
        self.top_right.forward(self.tr_speed)
        self.bottom_left.forward(self.bl_speed)
        self.bottom_right.forward(self.br_speed)

    def move_backward(self):
        self.top_left.backward(self.tl_speed)
        self.top_right.backward(self.tr_speed)
        self.bottom_left.backward(self.bl_speed)
        self.bottom_right.backward(self.br_speed)

    def move_left(self):
        self.top_left.backward(self.tl_speed)
        self.top_right.forward(self.tr_speed)
        self.bottom_left.forward(self.bl_speed)
        self.bottom_right.backward(self.br_speed)

    def move_right(self):
        self.top_left.forward(self.tl_speed)
        self.top_right.backward(self.tr_speed)
        self.bottom_left.backward(self.bl_speed)
        self.bottom_right.forward(self.br_speed)

    def back_right(self):
        self.stop()
        self.set_speed()
        self.move_backward()
        time.sleep(.2)
        self.move_right()
        time.sleep(.5)

        pass

    def back_left(self):
        self.stop()
        self.move_backward()
        time.sleep(.2)
        self.move_left()
        time.sleep(.5)
        pass



class IR:
    def __init__(self,pin):
        self.pin=pin
        #GPIO.setup(self.pin, GPIO.IN)

    def read(self):
        print( "sensor is reading with pin number ",self.pin)
        pass
        #return GPIO.input(self.pin)









