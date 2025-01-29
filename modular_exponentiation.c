#include <stdio.h>

unsigned long long modular_exponentiation(unsigned long long base, unsigned long long exponent, unsigned long long modulus) {
    unsigned long long result = 1; 
    base = base % modulus; 
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus; 
        }
        exponent = exponent >> 1; 
        base = (base * base) % modulus;
    }
    return result;
}

int main() {
    unsigned long long base, exponent, modulus;

    printf("Enter the base (positive integer): ");
    scanf("%llu", &base);

    printf("Enter the exponent (positive integer): ");
    scanf("%llu", &exponent);

    printf("Enter the modulus (positive integer greater than 1): ");
    scanf("%llu", &modulus);

    if (modulus <= 1) {
        printf("Modulus must be greater than 1\n");
        return 1;
    }
    if (base == 0) {
        printf("Base must be a positive integer\n");
        return 1;
    }

    unsigned long long result = modular_exponentiation(base, exponent, modulus);

    printf("Result: %llu\n", result);

    return 0;
}
