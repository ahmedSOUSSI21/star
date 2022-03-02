/*Ahmed SOUSSI */

/* Ce programme affiche une étoile de surface formée d'étoiles(*) selon la dimension 
saisie en ligne de commande */
/* Pour rendre le programme un peu plus fun, on lance un processus qui affiche cette étoile*/
/* Donc Par exemple, s'il y avait d'autres taches à faire, on aurait pu afficher l'étoile grâce à ce processus,
pendant qu'un autre processus s'occupe d'une autre tache */

/* Pour lancer ce processus, j'utilise les fonctions implémentées dans la 
bibliothéque pthread.h */


/* COMPILER AVEC :  gcc star.c -o star -pthread 
N.B. ne surtout pas oublier le -pthread !!! 
*/

#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
#include <pthread.h> 

void * showStar(void * arg);
void usage();

int main(int argc, char * argv[]){
	pthread_t t;
	
	if (argc != 2){
		usage();
		return 1;
	}
	for(int i=0; i<strlen(argv[1]);i++){
		if(!(isdigit(argv[1][i]))){
			usage();
			return 1;
		}
	}
	int n = atoi(argv[1]);
	void * x = &n;
	if(pthread_create(&t,NULL,showStar,x)!=0){
		perror("pthread_create\n");
		return 1;
	}
	pthread_join(t,NULL);
	return 0;
}

void * showStar(void * arg){
	int n = *((int *) arg);
 	for(int i=1;i<=n;i++){
 		for(int k=1;k<(2*n+1);k++){
 			printf(" ");
 		}
 		for(int j=1;j<=n-i;j++){
 			printf(" ");
 		}
 		for(int j=1;j<=(2*i-1);j++){
 			if((i==n)&&(j!=(2*i-1))&&(j!=1)){
 				printf(" ");
 			}
 			else if((j==1)||(j==(2*i-1))){
 				printf("*");
 			}
 			else{
 				printf(" ");
 			}
 		}
 		printf("\n");
 	}
 	for(int i=1;i<=(6*n-1);i++){
 		if((i<(4*n-1))&&(i>(2*n+1))){
 			printf(" ");
 		}
 		else{
 			printf("*");
 		}
 	}
 	printf("\n");
 	for(int i=1;i<=n;i++){
 		for(int j=1;j<=(6*n-1);j++){
 			if((j==(i+1)) || (j==((6*n-1)-i))){
 				printf("*");
 			}
 			else if (j>((6*n-1)-i)){
 				printf("");
 			}
 			else{
 				printf(" ");
 			}
 		}
 		printf("\n");
 	}
  	for(int i=1;i<=n-1;i++){
 		for(int j=1;j<=(6*n-1);j++){
 			if((j==(n-i+1))||(j==(5*n+i-1))){
 				printf("*");
 			}
 			else if (j>(5*n+i-1)){
 				printf("");
 			}
 			else{
 				printf(" ");
 			}
 		}
 		printf("\n");
 	}
 	for(int i=1;i<=(6*n-1);i++){
 		if((i<(4*n-1))&&(i>(2*n+1))){
 			printf(" ");
 		}
 		else{
 			printf("*");
 		}
 	}
 	printf("\n");
 	for(int i=1;i<=n;i++){
 		for(int j=1;j<=(6*n-1);j++){
 			if((j==2*n+i)||(j==4*n-i)){
 				printf("*");
 			}
 			else if (j>4*n-i){
 				printf("");
 			}
 			else{
 				printf(" ");
 			}
 		}
 		printf("\n");
 	}
 		
}
void usage(){
	printf("Usage : ./star [ENTIER] \n afficher une étoile avec la dimension passée en argument\n");
	printf("sans argument : la dimension = 0 \n ");
}
