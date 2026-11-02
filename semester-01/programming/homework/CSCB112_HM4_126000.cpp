// CSCB112 - Homework 4

#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <numeric>
#include <random>
#include <string>

using namespace std;

// Problem 5: Print a left-aligned triangle with 1, 3, 5, ... symbols.
void problem5() {
    int rows;
    char symbol;
    cout << "Number of rows (positive integer): ";
    cin >> rows;
    cout << "Symbol: ";
    cin >> symbol;

    if (!cin || rows <= 0) {
        cout << "Invalid input.\n";
        return;
    }

    for (int i = 1; i <= rows; ++i) {
        for (int j = 0; j < 2 * i - 1; ++j) {
            cout << symbol;
        }
        cout << '\n';
    }
}

bool readDigit(int& digit) {
    string input;
    cout << "Enter one digit (0-9): ";
    cin >> input;

    if (!cin || input.size() != 1 || input[0] < '0' || input[0] > '9') {
        cout << "Invalid digit.\n";
        return false;
    }

    char digitCharacter = input[0];
    digit = digitCharacter - '0';
    return true;
}

// Problems 6 and 7*: mirrored pattern of digits.
// In problem 7*, the central repeated digit is omitted.
void printDigitPattern(int digit, bool withoutRepeatedMiddle) {
    if (digit == 0) {
        cout << "0\n";
        return;
    }

    for (int row = 0; row <= digit; ++row) {
        for (int j = 1; j <= row; ++j) {
            cout << j;
        }

        int zeros = 2 * (digit - row);
        if (withoutRepeatedMiddle) {
            zeros = (row == digit) ? 0 : zeros - 1;
        }
        for (int j = 0; j < zeros; ++j) {
            cout << '0';
        }

        int rightStart = (withoutRepeatedMiddle && row == digit) ? row - 1 : row;
        for (int j = rightStart; j >= 1; --j) {
            cout << j;
        }
        cout << '\n';
    }
}

void problem6() {
    int digit;
    if (readDigit(digit)) {
        printDigitPattern(digit, false);
    }
}

void problem7star() {
    int digit;
    if (readDigit(digit)) {
        printDigitPattern(digit, true);
    }
}

void problem7() {
    int a, m, n;
    cout << "Enter positive integers a, m, n: ";
    cin >> a >> m >> n;
    if (!cin || a <= 0 || m <= 0 || n <= 0) {
        cout << "All three values must be positive integers.\n";
        return;
    }

    long double y = 0.0L;
    for (int i = 1; i <= n; ++i) {
        long double product = 1.0L;
        for (int j = 1; j <= m; ++j) {
            product *= (static_cast<long double>(a) + j) / (i + j);
        }
        y += product;
    }
    cout << "y = " << setprecision(15) << y << '\n';
}

// Problem 8: Greatest common divisor of n positive integers.
void problem8() {
    int n;
    cout << "How many positive integers? ";
    cin >> n;
    if (!cin || n <= 0) {
        cout << "n must be positive.\n";
        return;
    }

    long long result = 0;
    for (int i = 1; i <= n; ++i) {
        long long number;
        cout << "Number " << i << ": ";
        cin >> number;
        if (!cin || number <= 0) {
            cout << "Each number must be a positive integer.\n";
            return;
        }
        result = gcd(result, number);
    }
    cout << "GCD = " << result << '\n';
}

bool hasDistinctDigits(long long number) {
    bool seen[10] = {false};
    while (number > 0) {
        int digit = static_cast<int>(number % 10);
        if (seen[digit]) {
            return false;
        }
        seen[digit] = true;
        number /= 10;
    }
    return true;
}

// Problem 9: Integers in [m, n] with no repeated decimal digits.
void problem9() {
    long long m, n;
    cout << "Enter m and n (0 < m < n): ";
    cin >> m >> n;
    if (!cin || m <= 0 || m >= n) {
        cout << "Required: 0 < m < n.\n";
        return;
    }

    bool found = false;
    for (long long number = m; ; ++number) {
        if (hasDistinctDigits(number)) {
            cout << number << ' ';
            found = true;
        }
        if (number == n) {
            break;
        }
    }
    if (!found) {
        cout << "No such numbers.";
    }
    cout << '\n';
}

bool isPrime(long long number) {
    if (number < 2) return false;
    if (number == 2) return true;
    if (number % 2 == 0) return false;

    for (long long divisor = 3; divisor <= number / divisor; divisor += 2) {
        if (number % divisor == 0) {
            return false;
        }
    }
    return true;
}

bool startsWithDigit3(long long number) {
    while (number >= 10) {
        number /= 10;
    }
    return number == 3;
}

// Problem 10: First n prime numbers whose decimal representation starts with 3.
void problem10() {
    int n;
    cout << "Enter n (n > 1): ";
    cin >> n;
    if (!cin || n <= 1) {
        cout << "n must be greater than 1.\n";
        return;
    }

    int count = 0;
    for (long long candidate = 3; count < n; candidate += 2) {
        if (startsWithDigit3(candidate) && isPrime(candidate)) {
            cout << candidate << ' ';
            ++count;
        }
        if (candidate >= numeric_limits<long long>::max() - 2) {
            break;
        }
    }
    if (count < n) {
        cout << "\nStopped: integer range exceeded.";
    }
    cout << '\n';
}

// Problem 11: S = sum(i=1..n) [ (i-2)^2 + k*i ].
void problem11() {
    long long k;
    int n;
    cout << "Enter integer k and positive integer n: ";
    cin >> k >> n;
    if (!cin || n <= 0) {
        cout << "Invalid input (n must be positive).\n";
        return;
    }

    long double sum = 0.0L;
    for (int i = 1; i <= n; ++i) {
        long double difference = static_cast<long double>(i) - 2.0L;
        sum += difference * difference + static_cast<long double>(k) * i;
    }
    cout << "S = " << setprecision(15) << sum << '\n';
}

// Problem 12:
void problem12() {
    double a, inputN;
    cout << "Enter a and n (n must be a positive whole number): ";
    cin >> a >> inputN;
    if (!cin || !isfinite(a) || !isfinite(inputN) ||
        inputN < 1.0 || floor(inputN) != inputN ||
        inputN > static_cast<double>(numeric_limits<int>::max())) {
        cout << "Invalid input.\n";
        return;
    }

    int n = static_cast<int>(inputN);
    if (a == 0.0 && n > 1) {
        cout << "a cannot be zero when n > 1 (division by zero).\n";
        return;
    }

    random_device randomSeed;
    mt19937_64 generator(randomSeed());
    uniform_real_distribution<double> distribution(-96.0, 113.0);
    long double x = distribution(generator);

    long double sum = 0.0L;
    for (int i = 1; i <= n; ++i) {
        long double denominator = pow(static_cast<long double>(a), n - i);
        if (denominator == 0.0L) {
            cout << "Calculation stopped: division by zero.\n";
            return;
        }
        long double term = pow(x, i) * (i + x / denominator);
        sum += term;
    }
    cout << setprecision(15) << "x = " << x << "\nS = " << sum << '\n';
}

// Problem 13:
// P = y*n*z^n + x*y*(n-2)*z^(n-1) + x^2*y*(n-4)*z^(n-2)
//   + x^3*y*(n-8)*z^(n-3) + ...
// The exponent of z decreases to zero, so the sum includes i = 0..n.
void problem13() {
    long long x, y, z;
    int n;
    cout << "Enter positive integers x, y, z, n: ";
    cin >> x >> y >> z >> n;
    if (!cin || x <= 0 || y <= 0 || z <= 0 || n <= 0) {
        cout << "All four values must be positive integers.\n";
        return;
    }

    long double result = 0.0L;
    for (int i = 0; i <= n; ++i) {
        long double subtracted = (i == 0) ? 0.0L : pow(2.0L, i);
        long double term = pow(static_cast<long double>(x), i)
                         * static_cast<long double>(y)
                         * (n - subtracted)
                         * pow(static_cast<long double>(z), n - i);
        result += term;
    }
    cout << "P = " << setprecision(15) << result << '\n';
}

int main() {
    cout << "CSCB112 - Homework 4\n";
    cout << "Choose a problem: 5, 6, 7*, 7, 8, 9, 10, 11, 12, 13\n";
    cout << "Problem: ";

    string choice;
    cin >> choice;
    if (!cin) return 0;

    if      (choice == "5")  problem5();
    else if (choice == "6")  problem6();
    else if (choice == "7")  problem7();
    else if (choice == "8")  problem8();
    else if (choice == "9")  problem9();
    else if (choice == "10") problem10();
    else if (choice == "11") problem11();
    else if (choice == "12") problem12();
    else if (choice == "13") problem13();
    else cout << "Unknown problem.\n";

    return 0;
}
