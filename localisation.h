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

void closest_devices(Marker *dist, Marker *closest);
void rssi_to_distance(Marker *tab);
void init_marker(Marker *bal, int num);
void print_markers(Marker *tab,int size);


