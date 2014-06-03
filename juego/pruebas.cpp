#include <stdio.h>
#include <time.h>
 
int main(){

//    time_t t = time(NULL);
//    time_t fe;
//
//    time(&fe);
//
//    struct tm beg;
//
//    beg = *localtime(&fe);
//	    printf("local: %s", asctime(localtime(&t)));

//
//
//	    beg.tm_sec = beg.tm_sec + 4;
//
//
//	    //fe = mktime(&beg);
//	    //double sc = (double)difftime(localtime(&t), mktime(&beg));
//
//	    printf("%ld \n", sc);
    time_t now;
    time_t fe;
    time(&now);

    struct tm beg;

    beg = *localtime(&now);

    beg.tm_sec = beg.tm_sec + 4;
    beg.tm_hour = beg.tm_hour;
    beg.tm_min = beg.tm_min;
    beg.tm_mday = beg.tm_mday;
    
    double sc = difftime(mktime(&beg), now);
    
    fe = mktime(&beg);


    printf("now: %s \n", asctime(localtime(&now)));

    printf("end: %s", asctime(localtime(&fe)));
   
    printf("second: %lf \n", sc);

		return 0;
}
