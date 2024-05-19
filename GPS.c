#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

FILE  *infile;
char inName[15];

//Function for scanning our user and and determining distance between each of the other users

int scan_user(char *argv[], int x){ 
  
struct user_t{
char name[10];
int time;
double latitude;
double longitude;
double altitude;
} our_user, other_user;

int usernum;

// Open sample user file for reading
    strcpy(inName, argv[x]);
     infile = fopen (inName, "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }

    printf("The name, time and coordinates of our user are: \n\n");
     
    // Scan our user into our_user structure 

    while(fscanf(infile, "%i \n %s \n %i \n %lf \n %lf \n %lf \n", &usernum, &our_user.name,
         &our_user.time, &our_user.latitude, &our_user.longitude, &our_user.altitude ) != 0){
        printf ("%s \n time: %i \n longitude: %0.2lf \n latitude: %0.2lf \n altitude: %0.2lf \n", our_user.name,
                our_user.time, our_user.latitude, our_user.longitude, our_user.altitude);}

printf("\nThe coordinates of the other users are:\n\n");
 
int num = usernum;
 
 //Loop to scan and calculate distance between our_user and each other_user
int i;
double Dist, min[i], smallest; 
  for(i = 1; i <= num; i++){
    fscanf(infile, "\n %s \n %i \n %lf \n %lf \n %lf \n",  &other_user.name,
         &other_user.time, &other_user.latitude, &other_user.longitude, &other_user.altitude ); 
    
     Dist = sqrt((our_user.latitude-other_user.latitude)*(our_user.latitude-other_user.latitude)+
      (our_user.longitude-other_user.longitude)*(our_user.longitude-other_user.longitude)+(our_user.altitude-other_user.altitude)*(our_user.altitude-other_user.altitude));
    
printf("Other user %i: %s\n", i, other_user.name);
printf("\n time: %i \n longitude: %0.2lf \n latitude: %0.2lf \n altitude: %0.2lf \n", other_user.time, other_user.latitude, other_user.longitude, other_user.altitude);
    printf(" Distance to %s: %0.2lf\n\n", our_user.name, Dist);
    
   min[i] = Dist;
  } 
    
 smallest = min[1];
char closest[10];

//Loop for using the array of distances to find the smallest distance
     for(int i = 1; i <= num; i++) {
      
      if( smallest > min[i] ){ 
         smallest = min[i];}
     }
   printf("\nClosest other user to %s is at a distance of : %0.2f m\n\n", our_user.name, smallest);
  
        return 0;
    }

  
//Main function used to execute program and read coordinate files 

int main(int argc, char *argv[]) {

  if (argc < 2){
        printf("Cannot process request");
        exit(1);
    }

    if(strcmp(argv[1], "-dist") == 0) { 
        printf("\nGPS location scan complete: \n\n"); 
        scan_user(argv, 2);
    }
  
  else { 
    printf("\nNot specifed, GPS locations scanned:\n\n");
        scan_user(argv, 2);
          }


  fclose(infile);
  return 0;
}  