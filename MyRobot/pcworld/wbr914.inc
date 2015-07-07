
# Desc: Device definitions for Whitebox Robotics PC-BOT 914 robot.
# Author: Neil Schubert
# Date: 10 Mar 2007

# The PC-BOT IR array
define wbr914_ir ranger
(

  # sensor count used in this ranger
  scount 8

  # define the pose of each (sensor) transducer [xpos ypos heading]
  spose[4] [ 0.03 0.19 90 ]
  spose[3] [ 0.19 0.09 25 ]
  spose[2] [ 0.21 0.00 0 ]
  spose[1] [ 0.19 -0.09 -25 ]
  spose[0] [ 0.03 -0.19 -90 ]

  # these 3 transducers are the downward pointing for stairs and drops
  # because they point down, they have little effect in the Stage 2D
  # environment

  spose[7] [ 0.20 0.06 56 ]
  spose[6] [ 0.21 0.00 0 ]
  spose[5] [ 0.20 -0.06 -56 ]

		
  # define the field of view of each transducer [range_min range_max view_angle]

  sview [0.1 0.8 10]

  # the view of the downward facing ones are set at the ground hit
  # range even though they do extend farther. 

  sview[5] [0.2 0.68 10]
  sview[6] [0.2 0.46 10]
  sview[7] [0.2 0.68 10]

  # define the size of each transducer [xsize ysize] in meters
  ssize [0.01 0.03]
)

# a PC-BOT 914 in standard configuration
define wbr914 position
(

  # actual size of robot in meters for scaling

  size [0.45 0.35]

  # the PC-BOT's center of rotation is offset from its center of area

  origin [0 0.0 0]

  # draw a nose on the robot so we can see which way it points

  gui_nose 1

  # estimated mass in KG

  mass 25.0 
	
  # this polygon approximates the shape of a PC-BOT 914
  # Use two polygons to draw the robot

  polygons 2

  # details of the first polygon
  # polygon[index].points (total number of polygon points)

  polygon[0].points 12
  
  # polygon[index].point[index] [ xpos ypos ]

  polygon[0].point[0] [  0.11  0.17 ]
  polygon[0].point[1] [  0.13  0.12 ]
  polygon[0].point[2] [  0.18  0.11 ]
  polygon[0].point[3] [  0.18 -0.11 ]
  polygon[0].point[4] [  0.13 -0.12 ]
  polygon[0].point[5] [  0.11 -0.17 ]
  polygon[0].point[6] [ -0.11 -0.17 ]
  polygon[0].point[7] [ -0.14 -0.12 ]
  polygon[0].point[8] [ -0.18 -0.11 ]
  polygon[0].point[9] [ -0.18  0.11 ]
  polygon[0].point[10] [ -0.14  0.12 ]
  polygon[0].point[11] [ -0.11 0.17 ]

  # details of the second polygon

  polygon[1].points 4
  polygon[1].point[0] [ 0.18  0.08 ]
  polygon[1].point[1] [ 0.23  0.05 ]
  polygon[1].point[2] [ 0.23 -0.05 ]
  polygon[1].point[3] [ 0.18 -0.08 ]


  # differential steering model

  drive "diff"

  # laser_return refers to making the robot detectable by laser sensors
  # if the robot's sensor was mounted on the head, it would not detect other 
  # similar robots because the beam would go over the robot. This adds more
  # reality to the simulation (and worse detection) if you uncomment the line

  # laser_return 0

  # use the IR array defined above

  wbr914_ir()  
  hokuyo_URG_laser( pose [ 0.0 0.0 0.0 ])
) 

define hokuyo_URG_laser laser
(
	range_min 0.0
	range_max 4.0 
	fov 240.0
	samples 682

	color "red"
	size [ 0.05 0.05]

)
