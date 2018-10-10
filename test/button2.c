#include "gpio.h"
#include <unistd.h>

int main(){

pinMode(171, "out");
pinMode(189, "in");

while(1){
	digitalWrite(171,digitalRead(189));
	}
	
}
	