from  actuators_sensors import *
from attack import *
motor1=Motor(1,2,3)
motor2=Motor(1,2,3)
motor3=Motor(1,2,3)
motor4=Motor(1,2,3)

movmment =SumoMovment([motor1,motor2,motor3,motor4])

action=Attack(movmment)


action.push()
