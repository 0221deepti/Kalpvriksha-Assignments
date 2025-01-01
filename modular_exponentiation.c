#include <stdio.h>

unsigned long long modular_exponentiation(unsigned long long base, unsigned long long exp, unsigned long long mod) {
    unsigned long long result = 1; 
    base = base % mod; 
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod; 
        }
        exp = exp >> 1; 
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    unsigned long long B, N, M;

    printf("Enter the base: ");
    scanf("%llu", &B);

    printf("Enter the exponent: ");
    scanf("%llu", &N);

    printf("Enter the modulus: ");
    scanf("%llu", &M);

    if (M <= 1) {
        printf("Modulus must be greater than 1\n");
        return 1;
    }
    if (N < 0) {
        printf("Exponent must be a non-negative integer\n");
        return 1;
    }

    // Calculate B^N % M
    unsigned long long result = modular_exponentiation(B, N, M);

    printf("Result: %llu\n", result);

    return 0;
}
