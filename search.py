import random
from time import time
from attack import *

class Oponnent:
    def __init__(self,sumo,front_left,front_between,front_right,left,right,back):

        self.sumo=sumo

        self.front_left=front_left
        self.front_between=front_between
        self.front_right=front_right
        self.left=left
        self.right=right
        self.back=back

    def track(self, attack_type,detection_timeout=.2):
        """

        Desc:  used to track the opponent direction
        once the front sensor detect the opponent,
        start the attack routine

        attack_type: specifying the attack teq

        """
        start_time=None

        while True:

            FC = self.front_between.read()
            FR = self.front_right.read()
            FL = self.front_left.read()
            L = self.left.read()
            R = self.right.read()
            B = self.back.read()

            if FC or FR or FL or L or R or B:
                # Reset the detection timer when any sensor detects an opponent
                start_time = time.time()

                # If no sensor has detected an opponent within the timeout threshold, exit the loop
            elif  (time.time() - start_time > detection_timeout):
                        break
            # if front sensor detect opponent ,then attack
            if FC:

                #make sure to check this if it would work!!!!!!!!
                attack_type()
                while FC:
                    self.sumo.set_speed(100,100,100,100)
                    self.sumo.move_forward()
                    FC = self.front_between.read()


            # if front left sensor or front sensor detect then turn left
            elif FL or L:

                self.sumo.move_left()




            # if front right sensor or front sensor detect then turn right
            elif FR or R:
                self.sumo.move_right()


            # if back ir detect then move right or left (random decision )
            elif B:
                rand = random.randint(0, 1)
                if (rand == 1):
                    self.sumo.move_left()
                else:
                    self.sumo.move_left()


class Edge:
    def __init__(self,sumo,top_left,top_right,bottom_left,bottom_right):
        self.sumo=sumo

        self.top_left=top_left
        self.top_right=top_right
        self.bottom_left=bottom_left
        self.bottom_right=bottom_right
    def detect(self):
        TL=self.top_left.read()
        TR=self.top_right.read()
        BL=self.bottom_left.read()
        BR=self.bottom_right.read()

        # if the top left sensor detect white edge,then move backward and turn right
        if(TL):
            self.sumo.back_right()

        # if the top right sensor detect white edge,then move backward and turn left
        elif TR:
            self.sumo.back_left()

        # if the bottom left sensor detect white edge,then move forward and turn right
        elif BL:
            self.sumo.set_speed(100,100,100,100)
            self.sumo.move_forward()
            time.sleep(.3)
            self.sumo.move_right()
            time.sleep(.2)
            self.sumo.move_forward()

        elif  BR:
            self.sumo.move_forward()
            time.sleep(.3)
            self.sumo.move_left()
            time.sleep(.2)


class Search:
    def __init__(self,move):
        self.sumo=move


    def tornado(self):
        """

        Desc: the robot  moves in a  circular way about it's z axis

        """

        # set all motor  speed to 50
        self.sumo.set_speed()

        # keep moving right until sensors detect something
        self.sumo.move_right()

        pass

    def zigzag(self):
        """

        Desc:he robot moves back and forth in a zigzag pattern across the ring

        """

        self.sumo.set_speed(100,100,100,100)
        self.sumo.move_forward()
        # starting search routine




    def random_walk(self):
        """

        Desc:The robot moves in random directions, changing direction periodically

        """
        delay=.5
        rand=random.randint(1,3)
        if rand==1:
            self.sumo.move_forward()
            time.sleep(delay)
        elif rand==2:
            self.sumo.move_left()
            time.sleep(delay)
        else:
            self.sumo.move_right()
            time.sleep(delay)

        # starting search routine
        
        pass

    def s_shaped(self,attack_type):
        """

        Desc:The robot moves in an S-shaped pattern

        """

        # starting search routine
        pass
