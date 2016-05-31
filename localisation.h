#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct coo{
	float x;
	float y;
}Coordinates;

typedef struct bal{
	int num;
	Coordinates coor;
	int rssi;
	float dist;
}Marker;

int closest_devices(Marker *dist, Marker *closest);
void rssi_to_distance(Marker *tab);
void init_marker(Marker *bal, int num);
void init_markers(Marker *);
void print_markers(Marker *tab,int size);
float square(float a);
void trilateration(Marker *markers, int farther_marker, Coordinates *res);

