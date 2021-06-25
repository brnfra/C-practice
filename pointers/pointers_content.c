#include <stdio.h>
int main(){
    int  i = 10 ;
    int *p ;
    p = &i ;
    *p =  5 ;
    printf ("\n");
    printf ("\ti(content)-[ %d ]\tpointer(content)-[ %d ]\tvar pointer(content)-[ %p ]\n", i, *p, p);
    printf ("\n\n\n", i, *p, p);
    return 0;
}