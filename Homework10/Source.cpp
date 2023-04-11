#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
#include<string.h>

typedef struct {
    double mantissa;
    int exponent;
} sciNotation;

sciNotation convert(double num); // converts a double to scientific notation
sciNotation meanVal(sciNotation arr[], int len); // computes the mean value of the array and returns mean in scientific notation
void printVal(sciNotation* num); // prints a number in scientific notation

int main(void) {
    // main function code here
    int currNum = -1;
    char value = 'y';
    double userNumber;
    sciNotation convertNumber[10], meanNum;
    while (value == 'y' || currNum < 10) {
        currNum++;
        printf("Enter a value: ");
        scanf("%lf", &userNumber);
        convertNumber[currNum] = convert(userNumber);
        printVal(&convertNumber[currNum]);
        printf("Do you want to enter another value (y/n)? ");
        scanf(" %c", &value);
    }
    meanNum = meanVal(convertNumber, currNum);
    printf("Mean value: ");
    printVal(&meanNum);
    return 0;
}

sciNotation convert(double num) {
    sciNotation convertedNum;
    double tempNumber = num;
    int exponent = 0;
    // conversion function.
    if (num == 0.00) {
        convertedNum.mantissa = 0.00;
        convertedNum.exponent = 0;
        return convertedNum;
    }
    if (num < 0 && num > -10) {
        convertedNum.mantissa = num;
        convertedNum.exponent = 0;
        return convertedNum;
    }
    if (tempNumber > 1) {
        while (tempNumber > 10) {
            exponent++;
            tempNumber = num / pow(10, exponent);
        }
    }
    else if (tempNumber < 1 && tempNumber > 0) {
        while (tempNumber < 1 && tempNumber < 10) {
            exponent--;
            tempNumber = num * pow(10, abs(exponent));
        }
    }

    convertedNum.mantissa = tempNumber;
    convertedNum.exponent = exponent;
    return convertedNum;
}

sciNotation meanVal(sciNotation arr[], int len) {

    // mean computation function
    sciNotation mean;
    double meanNum = 0;
    double meanMantissa = 0;
    int meanExponent = 0;

    for (int i = 0; i < len; i++) {
        meanNum += arr[i].mantissa * pow(10, arr[i].exponent);
    }
    meanNum /= len;

    mean = convert(meanNum);

    return mean;
}


void printVal(sciNotation* num) {

    // printing function
    if (num->exponent > 1) {
        printf("%.10gE+%d\n", num->mantissa, num->exponent);
    }
    else {
        printf("%.10gE%d\n", num->mantissa, num->exponent);
    }
}
