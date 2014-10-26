#include "gpio.h"
#include <unistd.h>

int main(){

pinMode(171, "out");
while(1){
	digitalWrite(171,1);
	usleep(500*1000);
	digitalWrite(171,0);
	usleep(500*1000);
	}
	pinClean(171);
	return 0;
}
	