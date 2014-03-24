#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

double power(double base, int exponent){

    double result = 1;

    for (int index = 0; index < exponent; index++)
	result *= base;

    return result;
}

int main(int argc, char *argv[]){

    double base, exponent;
    int options;

    opterr = 0;

	
	while ((options = getopt (argc, argv, "h")) != -1)	    
	    switch (options)
	    {
		case 'h':
		    fprintf(stderr, "Usage %s <base> <exponent> \n", argv[0]);
		    break;
	    }
	
	if (argv[1] == NULL){
	    fprintf(stderr, "Usage %s <base> <exponent> \n",argv[0]);    
	    return EXIT_FAILURE;
	}else{
	    fprintf(stderr, "Usage %s <exponent> \n",argv[0]);
	    return EXIT_FAILURE;
	}

base = atof(argv[1]);
exponent = atoi(argv[2]);

printf("%lf\n", power(base, exponent));

return EXIT_SUCCESS;

}
