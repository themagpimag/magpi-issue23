import time
import grovepi

grovepi.pinMode(7,"OUTPUT")
time.sleep(1)

while True:
    try:
        grovepi.digitalWrite(7,1)
        time.sleep(1)
        grovepi.digitalWrite(7,0)
        time.sleep(1)
    except IOError:
        print "Error"

