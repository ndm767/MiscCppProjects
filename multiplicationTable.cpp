//prints the multiplication table for 12 (no input) or the given number

#include <stdio.h>
#include <stdlib.h>

int numDigits(int num){
    int digits = 0;

    while(num > 0){
        num /= 10;
        digits++;
    }

    return digits;
}

int main(int argc, char* argv[]){
    int limit = 12;

    if(argc == 2){
        limit = atoi(argv[1]);
        if(limit < 1){
            limit = 12;
        }
    }

    int maxDigits = numDigits(limit*limit);

    for(int row = 0; row <= limit; row++){
        for(int col = 0; col <= limit; col++){
            if(row == 0){
                if(col == 0){
                    for(int i = 0; i<maxDigits; i++){
                        printf(" ");
                    }
                }else{
                    printf("%i", col);
                    int tDig = numDigits(col);
                    for(int i = 0; i<(maxDigits - tDig); i++){
                        printf(" ");
                    }
                }
            }else{
                if(col == 0){
                    printf("%i", row);
                    int tDig = numDigits(row);
                    for(int i = 0; i<(maxDigits - tDig); i++){
                        printf(" ");
                    }
                }else{
                    int num = row*col;
                    printf("%i", num);
                    int tDig = numDigits(num);
                    for(int i = 0; i<(maxDigits - tDig); i++){
                        printf(" ");
                    }
                }
            }
            printf(" ");
        }
        printf("\n");
    }

    return 0;
}