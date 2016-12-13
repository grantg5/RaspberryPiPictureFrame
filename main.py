#!/usr/bin/python
import random

#Main method this will handle the user prompts and have things go to where they are suppose to
path = input("Provide the path to your pictures: ")
timeDelay = input("Provide the time delay you want on each picture in seconds

#check if the value given was a time
try:
   val = int(timeDelay)
except ValueError:
   print("That's not an int!")
   exit()

shuffle = input("Do you want to shuffle pcitures? Y/N:")

#check if the user wants to have their pictures shuffled
if(shuffle.lower() == 'y'):
	shuffle = True
else:
	shuffle = False

import getPictures
