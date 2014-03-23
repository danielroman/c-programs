#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int
main (int argc, char **argv)
{
    const char *frase = "El resultado de la suma es:";
    const char *string = "The result of the adding is:";
    const char *idioma = NULL;
    const char *result = NULL;

    int opciones;

    opterr = 0;

    while((opciones = getopt (argc, argv, "l:")) != -1)
	switch (opciones)
	{
	    case 'l':
		idioma = optarg;
		if (!strcmp(idioma, "sphanis"))
		    result = frase;
		if (!strcmp(idioma, "english"))
		    result = string;
		break;
	    case '?':
		if (optopt == 'l')
		    fprintf (stderr, "Option -%c requires an argument.\n", optopt);
		else if (isprint (optopt))
		    fprintf (stderr, "Unknown option `-%c'.\n", optopt);
		else
		    fprintf (stderr,
			    "Unknown option character `\\x%x'.\n",
			    optopt);
		return EXIT_FAILURE;
	    default:
		abort ();
	}


    //if (result == "sphanis")
    printf ("%s \n", result);

    for (int index = optind; index < argc; index++)
	printf ("Non-option argument %s\n", argv[index]);
    return EXIT_SUCCESS;
}
