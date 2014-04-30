#!/usr/bin/env python
import mcpi
from mcpi.minecraft import Minecraft
import pifacedigitalio
from McTraps import *
import sys,time

class McControl:
  def __init__(self, ips):
    self.ips = []
    self.ips += ips

    # Open connections with the Minecraft sessions
    self.connections={}
    for ip in self.ips:
      try:
        #self.connections[ip] = Minecraft.create(ip)
        self.connections[ip] = None
      except:
        print("ERROR: cannot connect to Minecraft on %s" % ip)
        sys.exit(1)

    # Store the number of connections and initialise the current
    # connection to be the first one
    self.connectionNumber = 0
    self.numberOfConnection = len(ips)

    # Setup an input event listener, one per switch on the PiFace
    pifacedigital = pifacedigitalio.PiFaceDigital()
    self.listener = pifacedigitalio.InputEventListener(chip=pifacedigital)
    for i in range(4):
      self.listener.register(i, pifacedigitalio.IODIR_ON, self.switchPressed)

  def listen(self):
    # Start listening to the PiFace
    self.listener.activate()
    print(">> Listening to PiFace")

  def shutdown(self):
    # Stop listening to the PiFace
    self.listener.deactivate()
    print(">> Listeners shutdown")

  def nextConnection(self):
    # Change to the connection associated with the next IP in the list.
    self.connectionNumber  = self.connectionNumber  + 1
    if self.connectionNumber  >= self.numberOfConnection:
      self.connectionNumber  = 0
    print(">> Using connection to %s" % self.ips[self.connectionNumber])

  def getConnection(self):
    # Return the connection associated with the selected IP
    if not self.ips[self.connectionNumber] in self.connections.keys():
      raise Exception("Error: no connection to %s" % self.ips[self.connectionNumber])
    return self.connections[self.ips[self.connectionNumber]]

  def switchPressed(self,event):
    # Handle switch press events.

    # If the first switch has been pressed, change to the
    # next IP
    if  event.pin_num == 0:
      self.nextConnection()
      return None

    # Get the current Minecraft connection
    mc = self.getConnection()

    # Use the switch number to decide which trap to run
    if event.pin_num == 1:
      print(">> Sand trap")
      sandTrap(mc)
    elif event.pin_num == 2:
      print(">> Volcano trap")
      volcanoTrap(mc)
    elif event.pin_num == 3:
      print(">> Hole trap")
      holeTrap(mc)
    else:
      raise Exception("ERROR: pin number is out of range.")

    
if __name__ == "__main__":

  # If no command line options are provide, assume that
  # the localhost is running Minecraft
  ips = []
  if len(sys.argv) == 1:
    ips += ["localhost"]
  else:
    ips += sys.argv[1:]

  # Start the MineCraft connections and PiFace listeners.
  # The listeners are shutdown went the program exits.
  mcControl = McControl(ips)
  try:
    mcControl.listen()
    while(1):
      time.sleep(1000)
  except KeyboardInterrupt:
    mcControl.shutdown()
