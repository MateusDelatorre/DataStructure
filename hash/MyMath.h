#ifndef MyMath
#define MyMath

#include<math.h>

int getDigitCount(int number){
    return floor(log10(abs(number))) + 1;;
}

void getArrayOfDigits(int number, int * array){
    int number_nDigits = getDigitCount(number);
    int divisor = 1; 
    int i = 0;
    //estado key
    for (i = divisor = 1; i < number_nDigits; i++){
        divisor *= 10;
    }
    int digito = 0;
    for (i = 0; i < number_nDigits; i++, divisor/=10, array++){
        digito = number/divisor;
        number -= digito*divisor;
        *array = digito;
    }
}


#endif