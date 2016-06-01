/*************************************/
/**********Fonctions pour*************/
/*******Algo de localisation**********/
/*********par trilateration***********/
/*************************************/

#include "localisation.h"

#define A 4
#define B 7
#define N 1.1
#define A_REF 60.0

//Determin which markers are the closest from the badge and returns the farthest
int closest_devices(Marker *dist, Marker *closest)
{	
	int i;	
	int min=0;
	for(i=1;i<4;i++){
		if(dist[i].rssi < dist[min].rssi)
			min=i;
	}
	printf("farther marker: n°%d\n",min);
	switch(min){
		case 0:
			closest[0]=dist[1];
			closest[1]=dist[2];
			closest[2]=dist[3];
			break;
		
		case 1:
			closest[0]=dist[0];
            closest[1]=dist[2];
            closest[2]=dist[3];
            break;

		case 2:
			closest[0]=dist[0];
            closest[1]=dist[1];
            closest[2]=dist[3];
            break;

		case 3:
			closest[0]=dist[0];
            closest[1]=dist[1];
            closest[2]=dist[2];
            break;

	}
	return min;	
}

//convert received signal power into a distance
void rssi_to_distance(Marker* tab){
	int i;
	for(i=0;i<3;i++){
		float expo=(-A_REF - tab[i].rssi)/(N*10);
		tab[i].dist=pow(10.0,expo);
	}
}

void distance_to_rssi(Marker *tab){
	int i;
	for(i=0;i<3;i++){
		tab[i].rssi=(-10*N)*log(tab[i].dist)-A_REF;
	}
}

//initialise a marker
void init_marker(Marker *bal, int num){
	
	switch(num){
		case 0:
			(*bal).num=num;
			(*bal).coor.x=0;
			(*bal).coor.x=0;
			(*bal).rssi=0;
			(*bal).dist=0.0;
			break;

		case 1:
			(*bal).num=num;
			(*bal).coor.x=0;
			(*bal).coor.y=A;
			(*bal).rssi=0;
			(*bal).dist=0.0;
			break;	

		case 2:
			(*bal).num=num;
			(*bal).coor.x=B;
			(*bal).coor.y=A;
			(*bal).rssi=0;
			(*bal).dist=0.0;
			break;

		case 3:
			(*bal).num=num;
			(*bal).coor.x=B;
			(*bal).coor.y=0;
			(*bal).rssi=0;
			(*bal).dist=0.0;
			break;	
	}
}

//initialise all the markers
void init_markers(Marker *dist){
	int i;
	for(i=0;i<4;i++)
		init_marker(&dist[i],i);
}


//print informations about the markers
void print_markers(Marker *tab, int size){
	int i;
	for(i=0;i<size;i++)
		printf("balise %d, x=%f, y=%f, rssi=%d, dist=%f m\n",tab[i].num,tab[i].coor.x,tab[i].coor.y,tab[i].rssi,tab[i].dist);
}

float square(float a){
	return a*a;
}

///////////////////////////////////////////////////////////////////////////////
//This function takes the three closest markers of the badge and determinates//
//its coordinates.                                                           //
//here are the markers' circle equations :                                   //
//				x^2 + y^2= d1^2 for marker0                                  //
//				x^2 + (y-A)^2= d2^2 for marker1                              //
//			(x-B)^2 + (y-A)^2= d3^2 for marker2                              //
//				(x-B)^2 + y^2= d4^2 for marker3                              //
///////////////////////////////////////////////////////////////////////////////

void trilateration(Marker *markers, int farther_marker, Coordinates *res){

	float x,y;

	switch(farther_marker){

		case(0):
			x=(square(B)-square(markers[2].dist)+square(markers[1].dist))/(2*B);
			y=(square(markers[2].dist)-square(markers[3].dist)-square(A))/(-2*A);
			break;

		case(1):
			x=(square(B)-square(markers[3].dist)+square(markers[0].dist))/(2*B);
			y=(square(markers[2].dist)-square(markers[3].dist)-square(A))/(-2*A);
			break;

		case(2):
			x=(square(B)-square(markers[3].dist)+square(markers[0].dist))/(2*B);
			y=A/2+(square(markers[0].dist)-square(markers[1].dist))/(2*A);
			break;

		case(3):
			x=(square(B)-square(markers[2].dist)+square(markers[1].dist))/(2*B);
			y=A/2+(square(markers[0].dist)-square(markers[1].dist))/(2*A);
			break;
	}
	(*res).x=x;
	(*res).y=y;
} 