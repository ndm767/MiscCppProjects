#include <iostream>
#include <ctime>

int main(int argc, char *argv[])
{
    int seed = (int)time(NULL);
    int output = 0;
    for (size_t i = 0; i < sizeof(int); i++)
    {
        int last = seed & 0x1;
        int stoLast = (seed >> 1) & 0x1;
        output = output << 1;
        output += last;
        seed = seed >> 1;
        int newDigit = last ^ stoLast;
        newDigit = newDigit << ((int)sizeof(int) - 1);
        seed = seed | newDigit;
    }

    std::cout << "Output = " << output << std::endl;
    return 0;
}