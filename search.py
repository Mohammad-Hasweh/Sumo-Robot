from actuators_sensors import *
from attack import *

class Search:
    def __init__(self,move):
        self.move=move


    def track(self,attack_type):
        """

        Desc:  used to track the opponent direction
        once the front sensor detect the opponent,
        start the attack routine

        attack_type: specifying the attack teq

        """

        #arbitrary code for testing only
        if(True):
            attack_type

        elif True:
            print("turn right")

        pass




    def tornado(self,attack_type):
        """

        Desc: the robot  moves in a  circular way about it's z axis

        """
        self.track(attack_type)

        # starting search routine
        pass

    def zigzag(self,attack_type):
        """

        Desc:he robot moves back and forth in a zigzag pattern across the ring

        """

        self.track(attack_type)

        # starting search routine
        pass

    def random_walk(self,attack_type):
        """

        Desc:The robot moves in random directions, changing direction periodically

        """

        self.track(attack_type)

        # starting search routine
        pass

    def s_shaped(self,attack_type):
        """

        Desc:The robot moves in an S-shaped pattern

        """
        self.track(attack_type)

        # starting search routine
        pass
