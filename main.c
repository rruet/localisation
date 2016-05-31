/*************************************/
/*******Algo de localisation**********/
/*********par trilateration***********/
/*************************************/

#include "localisation.h"

#define MAX_LINE 19

int main(void)
{
	//ouverture du fichier contenant les rssi envoyés depuis le badge
	FILE *f = fopen("data.txt","r+");
	int farther_marker;

	if (f == NULL){
		printf("erreur ouverture fichier..\n");
		exit (0);
	}


	Marker *dist=malloc(4*sizeof(Marker));
	if (dist == NULL){
		printf("erreur allocation 1\n");
		exit(0);
	}

	Marker *closest=malloc(3*sizeof(Marker));
	if(closest==NULL){
		printf("erreur allocation 2\n");
		exit(0);
	}

	Coordinates *coor=malloc(sizeof(Coordinates));
	if(coor==NULL){
		printf("erreur allocation 3\n");
		exit(0);
	}

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

	farther_marker=closest_devices(dist,closest);

	printf("\nthree closest devices : \n\n");

	print_markers(closest,3);

	//rssi_to_distance(closest);

	printf("\nrssi to distance conversion :\n\n");

	//example
	closest[0].dist=2.466666;
	closest[1].dist=2.466666;
	closest[2].dist=4.466666;
	//

	print_markers(closest,3);

	trilateration(closest,farther_marker,coor);

	printf("\nCoordinates of the badge : (%f,%f)\n",(*coor).x,(*coor).y);

	free(dist);
	free(closest);
	free(line);
	free(coor);	

	return 0;	
}

