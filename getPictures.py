from __main__ import *
import os
import random
from PIL import Image
import time
import subprocess
import webbrowser
import hardwaretiming

photos = []

for dirname, dirnames, filenames in os.walk(path):
    # print path to all filenames.
    for filename in filenames:
    	if(filename.lower().endswith(('.png', '.jpg', '.jpeg'))):
        	photos.append(path + '/' + filename)

if not photos:
	print("There are no pictures in this directory")
	exit()

if(shuffle == True):
	random.shuffle(photos)

for i in range(0, len(photos)):
    #Opens the web browser to display the photos.
    process = subprocess.Popen(["chromium-browser", photos[i]])
    """hardwaretiming.hardwaretiming(int(timedelay))"""
    time.sleep(float(timeDelay))
    process.kill()
