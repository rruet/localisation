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

	while(1){

		f=fopen("data.txt","a+");

		if(f==NULL){
			printf("erreur ouverture fichier!\n");
			exit(0);
		}

	
		fputs("hello\n",f);
		my_delay(3);
		

		fclose(f);
	}

	return 0;
}