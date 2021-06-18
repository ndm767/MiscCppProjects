//calculates the sieve of eratosthenes, a way of getting all the prime numbers up to a givint point.
#include <stdio.h>
#include <stdlib.h>
#include <vector>

int main(int argc, char *argv[]){
    int limit = 0;

    if(argc < 2){
        printf("Enter the limit: ");
        scanf("%i", &limit);
    }else{
        limit = atoi(argv[1]);
    }

    printf("Limit: %i\n", limit);

    std::vector<int> numArray;

    for(int i = 2; i<=limit; i++){
        numArray.push_back(i);
    }

    int pos = 0;
    while(pos < numArray.size()){
        int curr = numArray[pos];
        for(int x = 0; x<numArray.size(); x++){
            if(x != pos && numArray[x]%curr == 0){
                numArray.erase(numArray.begin()+x);
            }
        }
        pos++;
    }

    printf("Primes: ");

    for(int i = 0; i<numArray.size(); i++){
        printf("%i ", numArray[i]);
    }

    printf("\n");
    return 0;
}