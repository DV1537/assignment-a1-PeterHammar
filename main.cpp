#include <iostream>
#include <fstream>

int main(int argc, const char * argv[])
{
    
    int a;
    int sum = 0;
    int sizeOfArray = 1;
    int * ptr = new int[sizeOfArray];
    
    std::ifstream myReadFile;
    
    myReadFile.open(argv[1]);
    
    int numberOfDigits = 0;
    while (myReadFile >> a)
    {
        ptr[numberOfDigits] = a;
        ++numberOfDigits;
        sum += a;

        if(sizeOfArray < numberOfDigits)
        {
            sizeOfArray += 1;
        }
    }

    int * newptr = new int[sizeOfArray];
    if(numberOfDigits == 0)
    {
        exit(0);
    }
    
    double avgOfDigits = static_cast<double>(sum)/numberOfDigits;

    for(int i = 0; i < sizeOfArray; i++)
    {
        newptr[i] = ptr[i];
        if(newptr[i] > avgOfDigits)
        {
            std::cout << newptr[i] << ' ';
        }
    }
    std::cout << '\n';

    myReadFile.close();

    return 0;
}

