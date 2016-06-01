#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void my_delay(int i)    /*Pause l'application pour i seconds*/
{
    clock_t start,end;
    start=clock();
    while(((end=clock())-start)<=i*CLOCKS_PER_SEC);
}

int main(void){

	FILE  *f;
	int choix=0;	

	while(1){

		f=fopen("coor.txt","a+");

		if(f==NULL){
			printf("erreur ouverture fichier!\n");
			exit(0);
		}

		if(choix){
			fputs("2.1 4.2\n",f);
			choix=0;
		}else{
			fputs("3.2 6.0\n",f);
			choix=1;
		}
		my_delay(3);
		

		fclose(f);
	}

	return 0;
}
