#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

int A;
int B;
int carId;
sem_t Semaphore;

// Passenger B

void* passengerB(void* arg) {
printf("Thread ID: %lu, Team: B, I am looking for a car\n", pthread_self());

while (1){
sem_wait(&Semaphore);
if ( B==0 && A>2){
    sem_post(&Semaphore);

} else  if (B==2 && A>0){
    sem_post(&Semaphore);   
     
} else{
 
  B++;
  printf("Thread ID: %lu, Team: B, I have found a spot in a car\n", pthread_self());
  
  if((A+B) !=4){
  sem_post(&Semaphore);
  return NULL;}

  else{
    printf("Thread ID: %lu, Team: B, I am the captain and driving the car with ID %d\n",pthread_self(), carId);
    carId++;
    A = 0;
    B = 0;
    sem_post(&Semaphore);
    return NULL;}
}

}
}

// Passenger A


void* passengerA(void* arg) {
printf("Thread ID: %lu, Team: A, I am looking for a car\n", pthread_self());

while (1){
sem_wait(&Semaphore);

if ( A==0 && B>2){
     
     sem_post(&Semaphore);
  }  

else if (A==2 && B>0){
  
   sem_post(&Semaphore);  
} 
else{
  A++;
  printf("Thread ID: %lu, Team: A, I have found a spot in a car\n", pthread_self());
  if((A+B) !=4){
  sem_post(&Semaphore);
  return NULL;  }

  else{

   printf("Thread ID: %lu, Team: A, I am the captain and driving the car with ID %d\n",pthread_self(), carId);
   carId++;
   A = 0;
   B = 0; 
   sem_post(&Semaphore);
   return NULL; 
 }
}

}
}


int main(int argc, char *argv[]) {
    
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <teamA_size> <teamB_size>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int teamAnumber = atoi(argv[1]);
    int teamBnumber = atoi(argv[2]);
    
    A=0;
    B=0;
    carId = 0;
    sem_init(&Semaphore, 0, 1);
    
    if (teamAnumber % 2 == 0 && teamBnumber % 2 == 0 && ((teamAnumber + teamBnumber) % 4 ==0) ) {
    
    
    
    pthread_t* teamA = (pthread_t*)malloc(sizeof(pthread_t) * teamAnumber);
    pthread_t* teamB = (pthread_t*)malloc(sizeof(pthread_t) * teamBnumber);
    
    int max = teamAnumber;    
    if(teamAnumber < teamBnumber) { max = teamBnumber;}
 
    int i = 0;
    while (i < max) {
        if( i < teamAnumber){
        pthread_create(&teamA[i], NULL, passengerA, NULL);}
        if( i < teamBnumber){
        pthread_create(&teamB[i], NULL, passengerB, NULL);}
        i++;
    }
    
    int a;

        for (a = 0; a < max; a++) {
        if (a < teamAnumber){
        pthread_join(teamA[a], NULL);}

        if(a < teamBnumber){
        pthread_join(teamB[a], NULL);}

    }

    free(teamA);
    free(teamB);
    sem_destroy(&Semaphore);
    printf("The main terminates\n");
    } else{

       printf("The main terminates\n");   
    }
     
}
