import mcpi
from mcpi.block import *
import time

def sandTrap(mc):
  pos = mc.player.getTilePos()
  mc.setBlocks(pos.x-10,pos.y+15,pos.z-10,pos.x+10,pos.y+18,pos.z+10,SAND)
  mc.postToChat("Welcome to the beach!")

def volcanoTrap(mc):
  pos = mc.player.getTilePos()
  mc.postToChat("Warning.. volcano!")
  time.sleep(1)
  mc.setBlocks(pos.x,pos.y-50,pos.z,pos.x,pos.y-1,pos.z,LAVA)
  time.sleep(1)
  mc.setBlocks(pos.x-2,pos.y,pos.z-2,pos.x+2,pos.y+2,pos.z+2,LAVA)
  mc.postToChat("A bit too hot!")

def holeTrap(mc):
  pos = mc.player.getTilePos()
  mc.postToChat("Watch your feet!")
  time.sleep(1)

