/*************************************/
/*******Algo de localisation**********/
/*********par trilateration***********/
/*************************************/

#include "localisation.h"

#define A 4
#define B 7
#define MAX_LINE 19

//Determin which markers are the closest from the badge
void closest_devices(Marker *dist, Marker *closest)
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

void init_marker(Marker *bal, int num){
	
	switch(num){
		case 0:
			(*bal).num=num;
			(*bal).x=0;
			(*bal).y=0;
			(*bal).rssi=0;
			(*bal).dist=0.0;
			break;

		case 1:
			(*bal).num=num;
			(*bal).x=0;
			(*bal).y=A;
			(*bal).rssi=0;
			(*bal).dist=0.0;
			break;	

		case 2:
			(*bal).num=num;
			(*bal).x=B;
			(*bal).y=A;
			(*bal).rssi=0;
			(*bal).dist=0.0;
			break;

		case 3:
			(*bal).num=num;
			(*bal).x=B;
			(*bal).y=0;
			(*bal).rssi=0;
			(*bal).dist=0.0;
			break;	
	}
}

void init_markers(Marker *dist){
	int i;
	for(i=0;i<4;i++)
		init_marker(&dist[i],i);
}

void print_markers(Marker *tab, int size){
	int i;
	for(i=0;i<size;i++)
		printf("balise %d, x=%d, y=%d, rssi=%d, dist=%f\n",tab[i].num,tab[i].x,tab[i].y,tab[i].rssi,tab[i].dist);
}

int main(void)
{
	//ouverture du fichier contenant les rssi envoyés depuis le badge
	FILE *f = fopen("data.txt","r+");

	if (f == NULL){
		printf("erreur ouverture fichier..\n");
		exit (0);
	}

	Marker *dist=malloc(4*sizeof(Marker));
	init_markers(dist);
	print_markers(dist,4);

	char* line=malloc(MAX_LINE*sizeof(char));
	fgets(line,MAX_LINE,f);

	printf("%s\n",line);

	int rssi[4];
	sscanf(line,"%d %d %d %d\n",&rssi[0],&rssi[1],&rssi[2],&rssi[3]);

	int i;
	for(i=0;i<4;i++)
		printf("rssi %d = %d\n",i,rssi[i]);

	for(i=0;i<4;i++)
		dist[i].rssi=rssi[i];

	Marker *closest=malloc(3*sizeof(Marker));
	closest_devices(dist,closest);

	print_markers(closest,3);
	//for(i=0;i<3;i++)
	//	printf("%d\t",closest[i].num);
	//printf("\n");
	
	//rssi_to_distance(closest);

	//print_markers(closest,3);

	free(dist);
	return 0;	
}

