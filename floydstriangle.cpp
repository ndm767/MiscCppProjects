//generates floyd's triangle up to the specified number of rows
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int limit = 3;

    if(argc == 2){
        limit = atoi(argv[1]);
    }

    printf("Limit: %i\n", limit);

    int curr = 1;
    int cols = 1;

    for(int i = 0; i<limit; i++){
        for(int j = 0; j<cols; j++){
            printf("%i ", curr);
            curr++;
        }
        printf("\n");
        cols++;
    }

    return 0;
}