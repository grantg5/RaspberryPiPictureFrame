from __main__ import *
import os
import random
from PIL import Image
import time
import subprocess

import webbrowser


photos = []
#path = r"C:\Users\Alex\Desktop\PhotoFlipper\Photos"

for dirname, dirnames, filenames in os.walk(path):
    # print path to all filenames.
    for filename in filenames:
    	if(filename.lower().endswith(('.png', '.jpg', '.jpeg'))):
        	photos.append(path + '/' + filename)
        #print(os.path.join(dirname, filename))

if not photos:
	print("There are no pictures in this directory")
	exit()

if(shuffle == True):
	random.shuffle(photos)

for i in range(0, len(photos)):
    process = subprocess.Popen(["chromium-browser", photos[i]])
    time.sleep(float(timeDelay))
    process.kill()

    #webbrowser.open(photos[i])
    #time.sleep(float(timeDelay))
    #webbrowser.close()
#do something about time delay
#for photo in photos:
