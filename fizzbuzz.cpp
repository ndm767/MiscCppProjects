//prints the classic "fizzbuzz" exercise
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int limit = 100;

    if(argc == 2){
        limit = atoi(argv[1]);
    }

    for(int i = 1; i<=limit; i++){
        if(i%3 == 0){
            printf("Fizz");
        }
        if(i%5 == 0){
            printf("Buzz");
        }
        if(i%3 != 0 && i%5 != 0){
            printf("%i", i);
        }
        printf(" ");
    }
    printf("\n");
    return 0;
}