#!/usr/bin/env python
from minecraft import Minecraft
import pifacedigitalio
from mcTraps import *
import time

def switch_pressed(event):
    # Turn the PiFace LED on 
    event.chip.output_pins[event.pin_num].turn_on()

   # Use the switch number to determine what should happen
   if  event.pin_num == 0:
      McControl.nextConnection()
      return None

   # Get the current connection
   mc = McControl.getConnection()
    if event.pin_num == 1:
      sandTrap(mc)
    elif event.pin_num == 2:
      volcanoTrap(mc)
    elif event.pin_num == 3:
      holeTrap(mc)
    else:
       raise Exception("ERROR: pin number is out of range.")

class McConnections:
  __init__(self, ips):
     self.ips = ips

     # Open connections with the Minecraft sessions
    self.connections={}
    for ip in ips:
      self.connections[ip] = Minecraft.create(ip)

    self.connectionNumber = 0
    self.numberOfConnection = len(ips)

  nextConnection(self):
      self.connectionNumber  = self.connectionNumber  + 1
      if self.connectionNumber  >= self.numberOfConnection:
        self.connectionNumber  = 0
      print("Using IP=%s" % self.ips[self.connectionNumber])

  getConnection(self):
      return self.connections[self.ips[self.connectionNumber]])
 
    
if __name__ == "__main__":
  # IP addresses of Minecraft users on the local area network
  ips = [ "192.168.1.13", "192.168.1.36"]
  mcControl = McControl(ips)

  pifacedigital = pifacedigitalio.PiFaceDigital()

  listener = pifacedigitalio.InputEventListener(chip=pifacedigital)
  for i in range(4):
      listener.register(i, pifacedigitalio.IODIR_ON, switch_pressed)
  listener.activate()
