#include <stdio.h>
#include <math.h>

// Arithmetic Progression (AP) Functions

// Function to calculate the sum of the first n terms of an AP
int sumOfAP(int a, int d, int n) {
    return n * (2 * a + (n - 1) * d) / 2;
}

// Function to calculate the nth term of an AP
int nthTermOfAP(int a, int d, int n) {
    return a + (n - 1) * d;
}

// Function to calculate the sum of an AP up to a given term
int sumOfAPUptoTerm(int a, int d, int term) {
    int n = (term - a + d) / d;
    return n * (2 * a + (n - 1) * d) / 2;
}

// Function to print the first n terms of an AP
void printFirstNTermsAP(int a, int d, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a + i * d);
    }
    printf("\n");
}

// Function to find the common difference of an AP
int commonDifferenceAP(int a, int term, int n) {
    return (term - a) / (n - 1);
}

// Function to check if a given number is in an AP
int isInAP(int a, int d, int term) {
    return (term - a) % d == 0 && (term - a) / d >= 0;
}

// Function to find the nth term of an AP given the sum
int findNthTermGivenSum(int a, int d, int sum) {
    int n = (sum * 2) / (2 * a + d);
    return a + (n - 1) * d;
}

// Function to check if a new term can be inserted into an AP at a specific position
void insertNewTermAP(int a, int d, int newTerm, int pos) {
    int term = a + (pos - 1) * d;
    if (newTerm == term) {
        printf("Term %d is already in AP at position %d\n", newTerm, pos);
    }
    else {
        printf("New term %d can be inserted at position %d in AP\n", newTerm, pos);
    }
}

// Function to find the position of a given term in an AP
int findPositionInAP(int a, int d, int term) {
    if ((term - a) % d == 0) {
        return (term - a) / d + 1;
    }
    return -1;  // Not in AP
}

// Function to count the number of terms between two numbers in an AP
int countTermsBetween(int a, int d, int x, int y) {
    if (x > y) return 0;
    int start = (x - a + d - 1) / d; // First term >= x
    int end = (y - a) / d; // Last term <= y
    return end - start + 1;
}

// Geometric Progression (GP) Functions

// Function to calculate the sum of the first n terms of a GP
double sumOfGP(double a, double r, int n) {
    return a * (1 - pow(r, n)) / (1 - r);
}

// Function to calculate the nth term of a GP
double nthTermOfGP(double a, double r, int n) {
    return a * pow(r, n - 1);
}

// Function to calculate the sum of a GP up to a given term
double sumOfGPUptoTerm(double a, double r, double term) {
    int n = log(term / a) / log(r) + 1;
    return a * (1 - pow(r, n)) / (1 - r);
}

// Function to print the first n terms of a GP
void printFirstNTermsGP(double a, double r, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", a * pow(r, i));
    }
    printf("\n");
}

// Function to find the common ratio of a GP
double commonRatioGP(double a, double term, int n) {
    return pow(term / a, 1.0 / (n - 1));
}

// Function to check if a given number is in a GP
int isInGP(double a, double r, double term) {
    return (term / a) > 0 && fmod(log(term / a) / log(r), 1) == 0;
}

int main() {
    // Testing Arithmetic Progression functions
    int a = 2, d = 3, n = 5, term = 14;
    printf("Sum of first %d terms of AP: %d\n", n, sumOfAP(a, d, n));
    printf("The %dth term of AP: %d\n", n, nthTermOfAP(a, d, n));
    printf("Sum of AP up to term %d: %d\n", term, sumOfAPUptoTerm(a, d, term));
    printf("First %d terms of AP: ", n);
    printFirstNTermsAP(a, d, n);
    printf("Common difference of AP: %d\n", commonDifferenceAP(a, term, n));
    printf("Is %d in AP: %s\n", term, isInAP(a, d, term) ? "Yes" : "No");
    printf("Nth term given sum %d of AP: %d\n", 40, findNthTermGivenSum(a, d, 40));
    insertNewTermAP(a, d, term, n);
    printf("Position of %d in AP: %d\n", term, findPositionInAP(a, d, term));
    printf("Count of terms between %d and %d in AP: %d\n", 5, 20, countTermsBetween(a, d, 5, 20));

    // Testing Geometric Progression functions
    double r = 3;
    double termGP = 54;
    printf("Sum of first %d terms of GP: %.2f\n", n, sumOfGP(a, r, n));
    printf("The %dth term of GP: %.2f\n", n, nthTermOfGP(a, r, n));
    printf("Sum of GP up to term %.2f: %.2f\n", termGP, sumOfGPUptoTerm(a, r, termGP));
    printf("First %d terms of GP: ", n);
    printFirstNTermsGP(a, r, n);
    printf("Common ratio of GP: %.2f\n", commonRatioGP(a, termGP, n));
    printf("Is %.2f in GP: %s\n", termGP, isInGP(a, r, termGP) ? "Yes" : "No");

    return 0;
}
