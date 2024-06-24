from actuators_sensors import *
class Attack:
    def __init__(self,move):
        self.move=move

    def push(self):
        """

        Desc:directly pushing the opponent out of the ring

        """
        self.move.move_forward()


    def side_flank(self):
        """

        Desc:attack the side of the opponent

        """
        pass
    def back_flank(self):
        """

        Desc:attack the back of the opponent

        """
        pass

    def ram(self):
        """
        ram:نطح
        Desc:Repeatedly ramming the opponent(Repeatedly  moving forward and backward)

        """
        pass

    def dodge(self):

        """

        Desc:dodge an incoming attack and do a counterattack

        (when sensor detect incoming attack move away then attack the opponent)

        NOTE: ممكن نعمله يمشي حوالين الدائرة البيضاء وبعدين يهرب منه ويضربه لما يحسه جاي
        """
        pass

    def lift(self):
        """

        Desc:left the opponent to flip it down through  springs or servos

        """
