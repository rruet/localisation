#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct bal{
	int num;
	int x;
	int y;
	int rssi;
	float dist;
}Marker;

void closest_devices(Marker dist[4], Marker closest[3]);
void rssi_to_distance(Marker tab[3]);
void init_marker(Marker b, int num);
void print_marker(Marker tab[4]);


