import gpio
import time

gpio.pinMode(171, 'out')
while(True):
	gpio.digitalWrite(171,1)
	time.sleep(1)
	gpio.digitalWrite(171,0)
	time.sleep(1)
	