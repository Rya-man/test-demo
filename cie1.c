//CIe1
#include<stdio.h>
#include<stdlib.h>
/*
    pointer: memory address;a pointer is a variable that stores the address of a variable;
    pointer is a variable that represents the memory location
    uses:   
            pass info back and forth between functions
            return multiplr data items from function via function arguments
            another way to access elements in an array
            we can pass arrays as arguments
            call by reference: no data duplication occurs
            complex data structures are used to create pointers

            dynamci memory allocation

            syntax: Type_name* pointername; 

            incr4ement decrement have higher priority than dereference (*) thus

            *ptr++ will increment the location then accessthe data;
            (*ptr)++ will increment the value
            NULL does not point ot any value

            genric pointer type void ; can point to any variable
            cant be derefferenced

            In cs free memory region is called heap; heap size is not constant;
            mallco is declared in <stdlib.h>

                                        
*/
int main()
{
    int a;
    printf("\n Enter a number \t");
    scanf("%d",&a);
    int* ptra=NULL;
    int* ptr;//this is a wild pointernot initialised yet
    ptra=&a;
    // (*ptra)++;
    printf("\nNumber value :\t %d\nLocation value:\t %p",*ptra,ptra);
    return;
}