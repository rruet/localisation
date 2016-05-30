/*************************************/
/*******Algo de localisation**********/
/*********par trilateration***********/
/*************************************/

#include "localisation.h"

#define A 4
#define B 7

//Determin which markers are the closest from the badge
void closest_devices(Marker dist[4], Marker closest[3])
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
}

void rssi_to_distance(Marker tab[3]){
	int i;
	for(i=0;i<4;i++){
		float expo=(-60.0 - tab[i].rssi)/10;
		tab[i].dist=pow(10.0,expo)*1000;
	}
}

void init_marker(Marker b, int num, int a, int b){
	
	switch(num){
		case 0:
			b.num=num;
			b.x=0;
			b.y=0;
			b.rssi=0;
			b.dist=0.0;
			break;

		case 1:
			b.num=num;
			b.x=0;
			b.y=a;
			b.rssi=0;
			b.dist=0.0;
			break;	

		case 2:
			b.num=num;
			b.x=b;
			b.y=a;
			b.rssi=0;
			b.dist=0.0;
			break;

		case 3:
			b.num=num;
			b.x=b;
			b.y=0;
			b.rssi=0;
			b.dist=0.0;
			break;	
	}
}

void print_markers(Marker tab[],int size){
	int i;
	for(i=0;i<size;i++)
		printf("balise %d, x=%d, y=%d, rssi=%d, dist=%f\n",tab[i].num,tab[i].x,tab[i].y,tab[i].rssi,tab[i].dist);
}

int main(void)
{
	/*
	FILE *f = fopen("data.txt","r+");

	if (f == NULL){
		printf("erreur ouverture fichier..\n");
		exit (0);
	}
	*/

	Marker b0,b1,b2,b3;
	init_marker(b0,0,A,B);
	init_marker(b1,1,A,B);
	init_marker(b2,2,A,B);
	init_marker(b3,3,A,B);

	int i;

	Marker dist[4]={b0,b1,b2,b3};
	Marker closest[3];
	closest_devices(dist,closest);
	for(i=0;i<3;i++)
		printf("%d\t",closest[i].num);
	printf("\n");

	print_markers(dist,4);
	
	rssi_to_distance(closest);

	print_marker(closest,3);

	return 0;	
}

