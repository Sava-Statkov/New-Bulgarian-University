// CSCB112 - Homework 5: loops (for, while, do-while)
// Uses no arrays, vectors, string variables, char variables, or user-defined functions.
// Compile with: g++ -std=c++17 -Wall -Wextra -pedantic -O2
#include <iostream>
#include <iomanip>
using namespace std;

// Enter the task number (1..31), then that task's input.
int main() {
    int task;
    if (!(cin >> task)) return 0;

    switch (task) {
        case 1: {
            long long a, b;
            cin >> a >> b;
            long long sum = 0;
            for (long long i = a; i <= b; ++i) {
                if (i > a) cout << " ";
                cout << i;
                sum += i;
            }
            cout << "\n" << sum << "\n";
            break;
        }
        case 2: {
            int n, k, r;
            cin >> n >> k >> r;
            int count = 0;
            for (int i = 1; i <= n; ++i) {
                if (i % k == r) {
                    if (count > 0) cout << " ";
                    cout << i;
                    ++count;
                }
            }
            cout << "\n" << count << "\n";
            break;
        }
        case 3: {
            long long n;
            cin >> n;
            long long squares = 0, cubes = 0;
            for (long long i = 1; i <= n; ++i) {
                squares += i * i;
                cubes += i * i * i;
            }
            cout << squares << "\n" << cubes << "\n";
            break;
        }
        case 4: {
            int n;
            cin >> n;
            // long long can represent exact factorials up to 20!.
            long long factorial = 1;
            for (int i = 2; i <= n; ++i) {
                factorial *= i;
            }
            cout << factorial << "\n";
            break;
        }
        case 5: {
            int n;
            cin >> n;
            long long sum = 0;
            for (int i = 1; i <= n; ++i) {
                if (i % 2 == 1) sum += i;
                else sum -= i;
            }
            cout << sum << "\n";
            break;
        }
        case 6: {
            int n;
            cin >> n;
            long long sumPositive = 0;
            int countPositive = 0, countNegative = 0;
            for (int i = 0; i < n; ++i) {
                long long number;
                cin >> number;
                if (number > 0) {
                    sumPositive += number;
                    ++countPositive;
                } else if (number < 0) {
                    ++countNegative;
                }
            }
            if (countPositive > 0) {
                cout << "Average: " << setprecision(12)
                     << static_cast<double>(sumPositive) / countPositive << "\n";
            } else {
                cout << "No positive numbers\n";
            }
            cout << "Negative: " << countNegative << "\n";
            break;
        }
        case 7: {
            double a;
            int n;
            cin >> a >> n;
            double result = 1;
            for (int i = 0; i < n; ++i) {
                result *= a;
            }
            cout << setprecision(15) << result << "\n";
            break;
        }
        case 8: {
            int n;
            cin >> n;
            double sum = 0;
            for (int i = 1; i <= n; ++i) {
                sum += 1.0 / i;
            }
            cout << fixed << setprecision(4) << sum << "\n";
            break;
        }
        case 9: {
            int n;
            cin >> n;
            bool first = true;
            for (int number = 1; number <= n; ++number) {
                int divisors = 0;
                for (int d = 1; d <= number / d; ++d) {
                    if (number % d == 0) {
                        divisors += (d == number / d) ? 1 : 2;
                    }
                }
                if (divisors == 3) {
                    if (!first) cout << " ";
                    cout << number;
                    first = false;
                }
            }
            cout << "\n";
            break;
        }
        case 10: {
            int a, b;
            cin >> a >> b;
            bool first = true;
            for (int number = a; number <= b; ++number) {
                bool prime = (number >= 2);
                for (int d = 2; d <= number / d; ++d) {
                    if (number % d == 0) {
                        prime = false;
                        break;
                    }
                }
                if (prime) {
                    if (!first) cout << " ";
                    cout << number;
                    first = false;
                }
            }
            cout << "\n";
            break;
        }
        case 11: {
            int n;
            cin >> n;
            bool first = true;
            for (int number = 2; number <= n; ++number) {
                long long divisorsSum = 1;
                for (int d = 2; d <= number / d; ++d) {
                    if (number % d == 0) {
                        divisorsSum += d;
                        if (d != number / d) divisorsSum += number / d;
                    }
                }
                if (divisorsSum == number) {
                    if (!first) cout << " ";
                    cout << number;
                    first = false;
                }
            }
            cout << "\n";
            break;
        }
        case 12: {
            int n;
            cin >> n;
            bool first = true;
            for (int number = 1; number <= n; ++number) {
                int digitSum = 0;
                for (int temp = number; temp > 0; temp /= 10) {
                    digitSum += temp % 10;
                }
                if (number % digitSum == 0) {
                    if (!first) cout << " ";
                    cout << number;
                    first = false;
                }
            }
            cout << "\n";
            break;
        }
        case 13: {
            int n;
            cin >> n;
            long long gcdValue;
            cin >> gcdValue;
            for (int i = 2; i <= n; ++i) {
                long long number;
                cin >> number;
                long long a = gcdValue, b = number;
                while (b != 0) {
                    long long remainder = a % b;
                    a = b;
                    b = remainder;
                }
                gcdValue = a;
            }
            cout << gcdValue << "\n";
            break;
        }
        case 14: {
            int n;
            cin >> n;
            // The exact result fits in long long for n <= 20.
            long long factorial = 1, sum = 0;
            for (int i = 1; i <= n; ++i) {
                factorial *= i;
                sum += factorial;
            }
            cout << sum << "\n";
            break;
        }
        case 15: {
            int n;
            cin >> n;
            double sum = 0;
            for (int i = 0; i < n; ++i) {
                double term = 1.0 / (2.0 * i + 1);
                if (i % 2 == 0) sum += term;
                else sum -= term;
            }
            cout << fixed << setprecision(6) << 4.0 * sum << "\n";
            break;
        }
        case 16: {
            int n;
            cin >> n;
            bool first = true;
            for (int number = 1; number <= n; ++number) {
                int digits = 0;
                for (int temp = number; temp > 0; temp /= 10) ++digits;

                long long powersSum = 0;
                for (int temp = number; temp > 0; temp /= 10) {
                    int digit = temp % 10;
                    long long power = 1;
                    for (int j = 0; j < digits; ++j) power *= digit;
                    powersSum += power;
                }
                if (powersSum == number) {
                    if (!first) cout << " ";
                    cout << number;
                    first = false;
                }
            }
            cout << "\n";
            break;
        }
        case 17: {
            long long a, b, k;
            cin >> a >> b >> k;
            long long sum = 0;
            bool first = true;
            for (long long i = a; i <= b; i += k) {
                if (!first) cout << " ";
                cout << i;
                sum += i;
                first = false;
            }
            cout << "\nSum: " << sum << "\n";
            break;
        }
        case 18: {
            int n;
            cin >> n;
            double sum = 0;
            for (int i = 1; i <= n; ++i) {
                double term = static_cast<double>(i) / (i + 1);
                if (i % 2 == 1) sum += term;
                else sum -= term;
            }
            cout << fixed << setprecision(4) << sum << "\n";
            break;
        }
        case 19: {
            int n;
            cin >> n;
            // For exact signed long long Fibonacci values, n should be <= 93.
            long long a = 0, b = 1, next = 0;
            for (int i = 0; i < n; ++i) {
                if (i > 0) cout << " ";
                cout << a;
                if (i + 1 < n) {
                    next = a + b;
                    a = b;
                    b = next;
                }
            }
            cout << "\n";
            break;
        }
        case 20: {
            double a, q;
            int n;
            cin >> a >> q >> n;
            double term = a, sum = 0;
            for (int i = 0; i < n; ++i) {
                if (i > 0) cout << " ";
                cout << setprecision(15) << term;
                sum += term;
                term *= q;
            }
            cout << "\nSum: " << setprecision(15) << sum << "\n";
            break;
        }
        case 21: {
            int n;
            cin >> n;
            double sum = 0;
            for (int i = 1; i <= n; ++i) {
                sum += 1.0 / (static_cast<double>(i) * i);
            }
            cout << fixed << setprecision(5) << sum << "\n";
            break;
        }
        case 22: {
            int n;
            cin >> n;
            int belowZero = 0, above25 = 0;
            long long maxIncrease = 0, previous = 0;
            for (int i = 1; i <= n; ++i) {
                long long temperature;
                cin >> temperature;
                if (temperature < 0) ++belowZero;
                if (temperature > 25) ++above25;
                if (i > 1 && temperature - previous > maxIncrease) {
                    maxIncrease = temperature - previous;
                }
                previous = temperature;
            }
            cout << "Below zero: " << belowZero << "\n";
            cout << "Above 25: " << above25 << "\n";
            cout << "Max increase: " << maxIncrease << "\n";
            break;
        }
        case 23: {
            int n;
            cin >> n;
            double total = 0;
            int above500 = 0, streak = 0, longest = 0;
            for (int i = 0; i < n; ++i) {
                double revenue;
                cin >> revenue;
                total += revenue;
                if (revenue > 500) ++above500;
                if (revenue >= 300) {
                    ++streak;
                    if (streak > longest) longest = streak;
                } else {
                    streak = 0;
                }
            }
            cout << "Total: " << setprecision(15) << total << "\n";
            cout << "Above 500: " << above500 << "\n";
            cout << "Longest streak: " << longest << "\n";
            break;
        }
        case 24: {
            int n;
            cin >> n;
            long long total = 0, maximum = 0;
            int goalReached = 0, bestDay = 0;
            for (int day = 1; day <= n; ++day) {
                long long steps;
                cin >> steps;
                total += steps;
                if (steps >= 10000) ++goalReached;
                if (day == 1 || steps > maximum) {
                    maximum = steps;
                    bestDay = day;
                }
            }
            cout << "Total: " << total << "\n";
            cout << "Goal reached: " << goalReached << "\n";
            cout << "Best day: " << bestDay << "\n";
            break;
        }
        case 25: {
            int n;
            cin >> n;
            double previous;
            cin >> previous;
            double maxDecrease = 0;
            int bestDay = 0;
            for (int day = 2; day <= n; ++day) {
                double price;
                cin >> price;
                double decrease = previous - price;
                if (decrease > maxDecrease) {
                    maxDecrease = decrease;
                    bestDay = day;
                }
                previous = price;
            }
            if (bestDay == 0) {
                cout << "No decrease\n";
            } else {
                cout << "Max decrease: " << setprecision(15) << maxDecrease << "\n";
                cout << "Day: " << bestDay << "\n";
            }
            break;
        }
        case 26: {
            int n;
            cin >> n;
            long long previous;
            cin >> previous;
            int same = 0, different = 0;
            for (int i = 2; i <= n; ++i) {
                long long current;
                cin >> current;
                // Comparing evenness also works for negative odd numbers.
                if ((previous % 2 == 0) == (current % 2 == 0)) ++same;
                else ++different;
                previous = current;
            }
            cout << "Same parity: " << same << "\n";
            cout << "Different parity: " << different << "\n";
            break;
        }
        case 27: {
            int n;
            cin >> n;
            if (n == 0) {
                cout << "0\n";
            } else {
                // 1,000,000 needs up to 20 binary digits. A 20-digit decimal
                // representation of those bits may overflow signed long long.
                // Keep the lowest 19 bits in long long and print bit 20 separately.
                long long reversedDigits = 0;
                long long place = 1;
                int position = 0, highestBit = 0;
                while (n > 0) {
                    int bit = n % 2;
                    if (position < 19) {
                        reversedDigits += bit * place;
                        if (position < 18) place *= 10;
                    } else {
                        highestBit = bit;
                    }
                    n /= 2;
                    ++position;
                }
                if (position == 20) {
                    cout << highestBit;
                    // Print exactly 19 more binary digits, including leading zeros.
                    for (long long power = 1000000000000000000LL;
                         power > 0; power /= 10) {
                        cout << (reversedDigits / power) % 10;
                    }
                    cout << "\n";
                } else {
                    cout << reversedDigits << "\n";
                }
            }
            break;
        }
        case 28: {
            int n;
            cin >> n;
            long long position = 0;
            for (int step = 1; step <= n; ++step) {
                switch (step % 3) {
                    case 1: position += 3; break;
                    case 2: position -= 1; break;
                    case 0: position += 2; break;
                }
            }
            cout << "Position: " << position << "\n";
            break;
        }
        case 29: {
            long long target;
            cin >> target;
            long long saved = 0, deposit = 10;
            int weeks = 0;
            while (saved < target) {
                saved += deposit;
                deposit += 5;
                ++weeks;
            }
            cout << "Weeks: " << weeks << "\n";
            cout << "Saved: " << saved << "\n";
            break;
        }
        case 30: {
            long long n;
            cin >> n;
            long long maximum = n, steps = 0;
            cout << n;
            while (n != 1) {
                if (n % 2 == 0) n /= 2;
                else n = 3 * n + 1;
                if (n > maximum) maximum = n;
                ++steps;
                cout << " " << n;
            }
            cout << "\nSteps: " << steps << "\n";
            cout << "Max: " << maximum << "\n";
            break;
        }
        case 31: {
            int n;
            cin >> n;
            long long previous;
            cin >> previous;
            bool increasing = true, decreasing = true, equal = true;
            for (int i = 2; i <= n; ++i) {
                long long current;
                cin >> current;
                if (current <= previous) increasing = false;
                if (current >= previous) decreasing = false;
                if (current != previous) equal = false;
                previous = current;
            }
            if (equal) cout << "Equal\n";
            else if (increasing) cout << "Increasing\n";
            else if (decreasing) cout << "Decreasing\n";
            else cout << "Neither\n";
            break;
        }
        default:
            cout << "Invalid task number\n";
    }
    return 0;
}
