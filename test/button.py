import gpio
import time

gpio.pinMode(171, 'out')
gpio.pinMode(189, 'in')
while(True):
	gpio.digitalWrite(171,gpio.digitalRead(189))
