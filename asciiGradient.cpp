#include <stdio.h>
#include <stdlib.h>

//use: ./gradient size

int gradient(int x, int y, int height){
    float xshading = float(x)/float(height*2);
    xshading /= 2;
    float yshading = float(y)/float(height);
    yshading /= 2;
    float shading = xshading+yshading;
    return int(shading*9+1);
}

int main(int argc, char* argv[]){

    const char *values = " .:-=+*#%@";
    int width, height = 0;

    if(argc < 2){
        height = 10;
    }else{
        height = atoi(argv[1]);
    }

    width = height*2;

    for(int y = 0; y<height; y++){
        for(int x = 0; x<width; x++){
            int shade = gradient(x, y, height);
            printf("%c", values[shade]);
        }
        printf("\n");
    }

    return 0;
}