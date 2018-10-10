//by Andres602

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int pinMode(int pin, char direction[]);
int digitalRead(int pin);
int digitalWrite(int pin, int value);
int pinClean(int pin);

int pinMode(int pin, char direction[]){
	FILE *fdir, *fpin;
	char buffer[256];
	char file[256];
	sprintf(buffer, "%d\n", pin);
	sprintf(file,"/sys/class/gpio/gpio%d/direction",pin);
	if(!(fdir=fopen(file, "r"))){
		fpin=fopen("/sys/class/gpio/export", "w");
		fputs(buffer, fpin);
		fflush(fpin);
		fclose(fpin);
	}
	fdir=fopen(file, "w");
	fputs(direction, fdir);
	fflush(fdir);
	fclose(fdir);
	

}

int digitalRead(int pin){
	FILE *fpin;
	int valor;
	char value[256], file[256];
	sprintf(file,"/sys/class/gpio/gpio%d/value",pin);
	fpin=fopen(file, "r");
	fgets(value,256,fpin);
	fclose(fpin);
	valor=atoi(value);
	return valor;

}

int digitalWrite(int pin, int value){
	FILE *fpin;
	char file[256];
	sprintf(file,"/sys/class/gpio/gpio%d/value",pin);
	fpin=fopen(file, "w");
	if(value){fputs("1\n", fpin);}
	else{fputs("0\n", fpin);}
	fflush(fpin);
	fclose(fpin);

}

int pinClean(int pin){
	FILE *fpin;
	char val[256];
	char file[]="/sys/class/gpio/unexport";
	fpin=fopen(file, "w");
	sprintf(val,"%d",pin);
	fputs(val, fpin);
	fflush(fpin);
	fclose(fpin);

}


/*

int main(int argc, char *argv[]){

	if(!(direction=fopen("/sys/class/gpio/gpio171/direction", "r"))){
		pin=fopen("/sys/class/gpio/export", "w");
		fputs("171\n", pin);
		fflush(pin);	
	}
	direction=fopen("/sys/class/gpio/gpio171/direction", "w");
	led=fopen("/sys/class/gpio/gpio171/value", "w");
	fputs("out\n", direction);
	fflush(direction);
	
	if(!(direction=fopen("/sys/class/gpio/gpio189/direction", "r"))){
		pin=fopen("/sys/class/gpio/export", "w");
		fputs("189\n", pin);
		fflush(pin);	
	}
	direction=fopen("/sys/class/gpio/gpio189/direction", "w");
	//button=fopen("/sys/class/gpio/gpio189/value", "r");
	fputs("in\n", direction);
	fflush(direction);
	
	while(1){
		button=fopen("/sys/class/gpio/gpio189/value", "r");
		fgets(value,255,button);
		fputs(value, led);
		fflush(led);
		fclose(button);

	}
		
}
*/