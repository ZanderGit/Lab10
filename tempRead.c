#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int tempread (char *x, int y);
void usage();

int main(int argc, char *argv[]){

	
	char *device = "28-020a92455418";
	int verbose = 0;

  	/* process the arguments */
  	argc--; argv++;
  	while(argc > 0) {
    		/* printf(" test %d %s\n", argc, argv[0]); */
    		if(!strcmp("-v", argv[0])) {
      			verbose = 1;
    		} else if(!strcmp("-d", argv[0])) {
      			if(argc == 0)
        			usage();
      			argc--;  argv++;
      			device = argv[0];
    		} else
      			usage();
    	argc--; argv++;
  	}
	tempread(device, verbose);
  	exit(0);
}


void usage(){
	/* printf("SOMTHING \n"); */

}

int tempread ( char *device, int verbose) {
	char fileName[100];
	FILE *file;
	int c, count;
        int array[6];
	
	strcpy(fileName, "/sys/bus/w1/devices/");
	strcat(fileName, device);
	strcat(fileName, "/w1_slave");

	count = 0;
	
	file = fopen(fileName, "r");
	
	if (file == NULL){
		exit(1);
	}
	if (file) {
             	while ((c = getc(file)) != EOF){
                   	array[count] = c;
                        count ++;
			if (verbose == 1)
				printf("%c", c);
                        if(count == 6)
                                count = 0;
              	}
                printf ("%c%c%c%c%c\n",array[3], array[4], array[5], array[0], array[1]); 
	}


	fclose(file);
	/* printf("IN TEMPREAD device = %d verbose = %d \n", *device, verbose); */ 
		
	return 0;	

}

