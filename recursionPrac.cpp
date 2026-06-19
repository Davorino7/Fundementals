#include <iostream>
using namespace std;

int factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial (n-1);
    }
}
int fibonacci(int n) {
    if (n == 0) { 
        return 0;
    }
    if (n == 1) {
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}
int sumDigits(int n) {        // n % 10 gets the last digit, n / 10 removes it
    if (n == 0) {
        return 0;
    } else {
        return n % 10 + sumDigits(n / 10);
    }
}

int main() {
    cout << "factorial(5) = " << factorial(5) << "\n";  
    cout << "factorial(0) = " << factorial(0) << "\n";   

    cout << "fibonacci(7) = " << fibonacci(7) << "\n";   
    cout << "fibonacci(0) = " << fibonacci(0) << "\n";   

    cout << "sumDigits(123) = " << sumDigits(123) << "\n"; 
    cout << "sumDigits(9999) = " << sumDigits(9999) << "\n"; 

    return 0;
}