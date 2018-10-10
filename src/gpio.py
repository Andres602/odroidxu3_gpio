#!/usr/bin/python
# Edit by Andres602
# Orignal Markham Thomas   


def pinMode(pin, direction):
	file = '/sys/class/gpio/gpio' + str(pin) + '/direction'
	try:
		open(file).read()
	except:
		# it isn't, so export it
  		open('/sys/class/gpio/export', 'w').write(str(pin))
	open(file, 'w').write(direction)
	
def digitalWrite(pin, value):
	# when writing a 1 it briefly drops to 0 for 100 usec (no idea why)
	a = '/sys/class/gpio/gpio' + str(pin) + '/value'
	try:
		open(a, 'w').write(str(value))
	except IOError:
		print "Cannot open:", a
		print "  Did you setup that pin?"
		sys.exit(-1)
	except:
		print "GPIO pin not setup (missing): /sys/class/gpio/gpio" + str(pin)
		sys.exit(-1)
def digitalRead(pin):
	a = '/sys/class/gpio/gpio' + str(pin) + '/value'
	try:
		b = open(a).read()
	except:
		print "GPIO pin not setup (missing): /sys/class/gpio/gpio" + str(pin)
		sys.exit(-1)
	return b
	
def pinClean(pin):
	open('/sys/class/gpio/unexport', 'w').write(str(pin))
