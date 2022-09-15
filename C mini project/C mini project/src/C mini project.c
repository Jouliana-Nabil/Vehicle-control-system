/*
 ============================================================================
 Name        : C.c
 Author      : Jouliana Nabil
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char z;
char a;
char b;
int d;
int room_temp;
int Engine_temp;
char y;
int speed;
char engine_state[4];
char Ac[4];
char Engine_Temperature_Controller[4];
void Sensor_menu (char z);
void traffic_light (char a);
void Room_temperature(int b);
void Engine_temperature(int d);
void display(void);
void Sensors_set_menu(void);

void Sensors_set_menu (void) {
	printf("Sensors set menu\n");
	fflush(0);
	printf("CLICK a-Set the traffic light color\nClick b-Set the room temperature\nCLICK c-QUIT the system\nClick d-Set the engine temperature\n");
	fflush(0);
	scanf(" %c",&z);
	Sensor_menu(z);
}
void operation (){
	printf("CLICK a- Turn on vehicle\nCLICK b-Turn off vehicle\nCLICK c-Quit the system\n");
	fflush(0);
	scanf(" %c",&y);
	if (y=='c'){
		return; //TO QUIT THE WHOLE CODE
	}
	if (y=='b'){
		strcpy(engine_state,"OFF");
		printf("CLICK a- Turn on vehicle\nCLICK b-Turn off vehicle\nCLICK c-Quit the system");
		fflush(0);
	}
	if (y=='a'){
		strcpy(engine_state,"ON");
		Sensors_set_menu();
	}
}

void Sensor_menu (char z){
	switch(z){
	case'a':
		printf("Please enter the color of the light G or O or R \n");
		fflush(0);
		scanf(" %c",&a);
		traffic_light(a);
		break;
	case'b':
		printf("Please enter the temperature\n");
		fflush(0);
		scanf(" %d",&room_temp);
		Room_temperature(room_temp);
		break;
	case 'c':
		operation();
		break;
	case 'd':
		printf("Please enter the temperature\n");
		fflush(0);
		scanf(" %d",&d);
		Engine_temperature(d);
		break;
	}
}
void traffic_light (char a){
	if (a=='G'){
		fflush(0);
		speed=100;
	}
	if (a=='O'){
		fflush(0);
		speed=30;
	}
	if (a=='R'){
		printf ("The vehicle speed is zero km/hr\n");
		fflush(0);
		speed=0;
	}
	int i;
		do{
			i=0;
			room_temp=35;
			Engine_temp=90;
			i++;
			strcpy(Engine_Temperature_Controller,"ON");
			strcpy(Ac,"ON");
		} while (i==0); //Iterates only one time*/
	display();
}
void Room_temperature(int b){
	if (speed<10){
		strcpy(Ac,"ON");
		room_temp=20;
	}
	if (speed>30){
		strcpy(Ac,"ON");
		fflush(0);
		room_temp=20;
	}
	else strcpy(Ac,"OFF");

	if(speed==30){
		strcpy(Ac,"ON");
		room_temp= room_temp*(float)5/4 + 1;
		strcpy(Engine_Temperature_Controller,"ON");
		Engine_temp= Engine_temp*(float)5/4 + 1;
	}
	display();
}
void Engine_temperature(int d){
	if (d<100){
		strcpy(Engine_Temperature_Controller,"ON");
		Engine_temp=125;
	}
	else if (d>150){
		strcpy(Engine_Temperature_Controller,"ON");
		Engine_temp=125;
	}
	else {
		strcpy(Engine_Temperature_Controller,"OFF");
	}
	display();
}
void display(void){
	printf("i.Engine state is %s\n",engine_state);
	printf("ii.Ac is: %s\n",Ac);
	printf("iii.Vehicle Speed is %d km/h\n",speed);
	printf("iv.Room Temperature is %d C\n",room_temp);
	printf("v.Engine Temperature Controller is %s \n",Engine_Temperature_Controller);
	printf("vi.Engine Temperature is %d C\n\n",Engine_temp);
	Sensors_set_menu();
}

int main(void) {
	printf("Welcome to the vehicle system\n");
	fflush(0);
	operation ();
	return 0;
}
