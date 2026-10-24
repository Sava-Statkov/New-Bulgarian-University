
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

#define MIN 0.0
#define MAX 100.0


// Task 1 - Convert decimal to Roman
void task1() {
    int number;

    cout << "Enter a number (1-3999): ";
    cin >> number;

    if (number < 1 || number > 3999) {
        cout << "Invalid number.\n";
        return;
    }

    cout << "Roman numeral: ";

    switch (number / 1000) {
        case 1: cout << "M"; break;
        case 2: cout << "MM"; break;
        case 3: cout << "MMM"; break;
    }

    switch ((number / 100) % 10) {
        case 1: cout << "C"; break;
        case 2: cout << "CC"; break;
        case 3: cout << "CCC"; break;
        case 4: cout << "CD"; break;
        case 5: cout << "D"; break;
        case 6: cout << "DC"; break;
        case 7: cout << "DCC"; break;
        case 8: cout << "DCCC"; break;
        case 9: cout << "CM"; break;
    }

    switch ((number / 10) % 10) {
        case 1: cout << "X"; break;
        case 2: cout << "XX"; break;
        case 3: cout << "XXX"; break;
        case 4: cout << "XL"; break;
        case 5: cout << "L"; break;
        case 6: cout << "LX"; break;
        case 7: cout << "LXX"; break;
        case 8: cout << "LXXX"; break;
        case 9: cout << "XC"; break;
    }

    switch (number % 10) {
        case 1: cout << "I"; break;
        case 2: cout << "II"; break;
        case 3: cout << "III"; break;
        case 4: cout << "IV"; break;
        case 5: cout << "V"; break;
        case 6: cout << "VI"; break;
        case 7: cout << "VII"; break;
        case 8: cout << "VIII"; break;
        case 9: cout << "IX"; break;
    }

    cout << '\n';
}

// Task 2 - Convert Roman to decimal

void task2() {
    int number = 0;

    cout << "Enter a Roman numeral (1-3999): ";
    cin >> ws;

    // Thousands
    if (cin.peek() == 'M') { cin.get(); number += 1000; }
    if (cin.peek() == 'M') { cin.get(); number += 1000; }
    if (cin.peek() == 'M') { cin.get(); number += 1000; }

    // Hundreds
    if (cin.peek() == 'C') {
        cin.get();

        if (cin.peek() == 'M') { cin.get(); number += 900; }
        else if (cin.peek() == 'D') { cin.get(); number += 400; }
        else {
            number += 100;
            if (cin.peek() == 'C') { cin.get(); number += 100; }
            if (cin.peek() == 'C') { cin.get(); number += 100; }
        }
    }
    else if (cin.peek() == 'D') {
        cin.get();
        number += 500;
        if (cin.peek() == 'C') { cin.get(); number += 100; }
        if (cin.peek() == 'C') { cin.get(); number += 100; }
        if (cin.peek() == 'C') { cin.get(); number += 100; }
    }

    // Tens
    if (cin.peek() == 'X') {
        cin.get();

        if (cin.peek() == 'C') { cin.get(); number += 90; }
        else if (cin.peek() == 'L') { cin.get(); number += 40; }
        else {
            number += 10;
            if (cin.peek() == 'X') { cin.get(); number += 10; }
            if (cin.peek() == 'X') { cin.get(); number += 10; }
        }
    }
    else if (cin.peek() == 'L') {
        cin.get();
        number += 50;
        if (cin.peek() == 'X') { cin.get(); number += 10; }
        if (cin.peek() == 'X') { cin.get(); number += 10; }
        if (cin.peek() == 'X') { cin.get(); number += 10; }
    }

    // Units
    if (cin.peek() == 'I') {
        cin.get();

        if (cin.peek() == 'X') { cin.get(); number += 9; }
        else if (cin.peek() == 'V') { cin.get(); number += 4; }
        else {
            number += 1;
            if (cin.peek() == 'I') { cin.get(); number += 1; }
            if (cin.peek() == 'I') { cin.get(); number += 1; }
        }
    }
    else if (cin.peek() == 'V') {
        cin.get();
        number += 5;
        if (cin.peek() == 'I') { cin.get(); number += 1; }
        if (cin.peek() == 'I') { cin.get(); number += 1; }
        if (cin.peek() == 'I') { cin.get(); number += 1; }
    }

    if (cin.peek() != '\n' || number == 0) {
        cout << "Invalid Roman numeral.\n";
        cin.ignore(1000, '\n');
        return;
    }

    cin.get();
    cout << "Decimal number: " << number << '\n';
}



// Task 3 - Check if a number belongs to an interval
void task3() {
    double number;

    cout << "Enter a real number: ";
    cin >> number;

    if (number >= MIN && number <= MAX) {
        cout << "The number is inside the interval.\n";
    }
    else {
        cout << "The number is outside the interval.\n";
    }
}


// Task 4 - Print every digit of an integer
void task4() {
    int number;

    cout << "Enter an integer: ";
    cin >> number;

    long long n = number;

    if (n < 0) {
        n = -n;
    }

    bool started = false;

    if (n >= 1000000000LL) {
        cout << n / 1000000000LL << '\n';
        n %= 1000000000LL;
        started = true;
    }

    if (started || n >= 100000000LL) {
        cout << n / 100000000LL << '\n';
        n %= 100000000LL;
        started = true;
    }

    if (started || n >= 10000000LL) {
        cout << n / 10000000LL << '\n';
        n %= 10000000LL;
        started = true;
    }

    if (started || n >= 1000000LL) {
        cout << n / 1000000LL << '\n';
        n %= 1000000LL;
        started = true;
    }

    if (started || n >= 100000LL) {
        cout << n / 100000LL << '\n';
        n %= 100000LL;
        started = true;
    }

    if (started || n >= 10000LL) {
        cout << n / 10000LL << '\n';
        n %= 10000LL;
        started = true;
    }

    if (started || n >= 1000LL) {
        cout << n / 1000LL << '\n';
        n %= 1000LL;
        started = true;
    }

    if (started || n >= 100LL) {
        cout << n / 100LL << '\n';
        n %= 100LL;
        started = true;
    }

    if (started || n >= 10LL) {
        cout << n / 10LL << '\n';
        n %= 10LL;
    }

    cout << n << '\n';
}


// Task 5 - Generate a random integer and print its digits
void task5() {
    int minimum, maximum;

    cout << "Enter the minimum and maximum integers: ";
    cin >> minimum >> maximum;

    long long range = (long long)maximum - minimum + 1;

    if (range <= 0 || range > RAND_MAX) {
        cout << "Invalid or too large interval.\n";
        return;
    }

    int number = minimum + rand() % (int)range;

    cout << "Random number: " << number << '\n';

    long long absoluteNumber = number;

    if (absoluteNumber < 0) {
        absoluteNumber = -absoluteNumber;
    }

    if (absoluteNumber > 999) {
        cout << "The number has more than three digits.\n";
        return;
    }

    if (absoluteNumber >= 100) {
        cout << absoluteNumber / 100 << '\n';
    }

    if (absoluteNumber >= 10) {
        cout << (absoluteNumber / 10) % 10 << '\n';
    }

    cout << absoluteNumber % 10 << '\n';
}


// Task 6 - Generate a random real number
void task6() {
    double minimum, maximum;

    cout << "Enter the minimum and maximum real numbers: ";
    cin >> minimum >> maximum;

    if (minimum > maximum) {
        cout << "Invalid interval.\n";
        return;
    }

    double fraction = (double)rand() / RAND_MAX;
    double number = minimum + fraction * (maximum - minimum);

    cout << "Random real number: " << number << '\n';
}


// Task 7 - Solve a system of two linear equations
void task7() {
    double a1, b1, c1;
    double a2, b2, c2;

    cout << "Equation 1 (a1 b1 c1): ";
    cin >> a1 >> b1 >> c1;

    cout << "Equation 2 (a2 b2 c2): ";
    cin >> a2 >> b2 >> c2;

    // Cramer's rule
    double d = a1 * b2 - a2 * b1;
    double dx = c1 * b2 - c2 * b1;
    double dy = a1 * c2 - a2 * c1;

    const double EPS = 1e-10;

    if (fabs(d) > EPS) {
        cout << "x = " << dx / d << '\n';
        cout << "y = " << dy / d << '\n';
    }
    else if (fabs(dx) <= EPS && fabs(dy) <= EPS) {
        cout << "Infinitely many solutions.\n";
    }
    else {
        cout << "No solution.\n";
    }
}


// Task 8 - Solve a system of three linear equations
void task8() {
    double a1, b1, c1, d1;
    double a2, b2, c2, d2;
    double a3, b3, c3, d3;

    cout << "Equation 1 (a1 b1 c1 d1): ";
    cin >> a1 >> b1 >> c1 >> d1;

    cout << "Equation 2 (a2 b2 c2 d2): ";
    cin >> a2 >> b2 >> c2 >> d2;

    cout << "Equation 3 (a3 b3 c3 d3): ";
    cin >> a3 >> b3 >> c3 >> d3;

    // Main determinant
    double d = a1 * (b2 * c3 - b3 * c2)
             - b1 * (a2 * c3 - a3 * c2)
             + c1 * (a2 * b3 - a3 * b2);

    if (fabs(d) < 1e-10) {
        cout << "The system does not have a unique solution.\n";
        return;
    }

    // Determinants for x, y, and z
    double dx = d1 * (b2 * c3 - b3 * c2)
              - b1 * (d2 * c3 - d3 * c2)
              + c1 * (d2 * b3 - d3 * b2);

    double dy = a1 * (d2 * c3 - d3 * c2)
              - d1 * (a2 * c3 - a3 * c2)
              + c1 * (a2 * d3 - a3 * d2);

    double dz = a1 * (b2 * d3 - b3 * d2)
              - b1 * (a2 * d3 - a3 * d2)
              + d1 * (a2 * b3 - a3 * b2);

    cout << "x = " << dx / d << '\n';
    cout << "y = " << dy / d << '\n';
    cout << "z = " << dz / d << '\n';
}


// Task 9 - Simple calculator
void task9() {
    int operation;
    double a, b;

    cout << "1 - Add\n";
    cout << "2 - Subtract\n";
    cout << "3 - Multiply\n";
    cout << "4 - Divide\n";

    cout << "Choose operation (1-4): ";

    if (!(cin >> operation) || operation < 1 || operation > 4) {
        cout << "Invalid operation.\n";
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }

    cout << "Enter A and B: ";

    if (!(cin >> a >> b)) {
        cout << "Invalid numbers.\n";
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }

    switch (operation) {
        case 1:
            cout << "Result: " << a + b << '\n';
            break;

        case 2:
            cout << "Result: " << a - b << '\n';
            break;

        case 3:
            cout << "Result: " << a * b << '\n';
            break;

        case 4:
            if (b == 0) {
                cout << "Cannot divide by zero.\n";
            }
            else {
                cout << "Result: " << a / b << '\n';
            }
            break;
    }
}


// Task 10 - Print the number of educational tasks in Bulgarian
void task10() {
    int x;

    cout << "Enter number of tasks (10-40): ";
    cin >> x;

    if (x < 10 || x > 40) {
        cout << "Invalid number.\n";
        return;
    }

    string words;

    if (x < 20) {
        switch (x) {
            case 10: words = "Десет"; break;
            case 11: words = "Единадесет"; break;
            case 12: words = "Дванадесет"; break;
            case 13: words = "Тринадесет"; break;
            case 14: words = "Четиринадесет"; break;
            case 15: words = "Петнадесет"; break;
            case 16: words = "Шестнадесет"; break;
            case 17: words = "Седемнадесет"; break;
            case 18: words = "Осемнадесет"; break;
            case 19: words = "Деветнадесет"; break;
        }
    }
    else {
        if (x < 30) {
            words = "Двадесет";
        }
        else if (x < 40) {
            words = "Тридесет";
        }
        else {
            words = "Четиридесет";
        }

        if (x % 10 != 0) {
            words += " и ";

            switch (x % 10) {
                case 1: words += "една"; break;
                case 2: words += "две"; break;
                case 3: words += "три"; break;
                case 4: words += "четири"; break;
                case 5: words += "пет"; break;
                case 6: words += "шест"; break;
                case 7: words += "седем"; break;
                case 8: words += "осем"; break;
                case 9: words += "девет"; break;
            }
        }
    }

    if (x == 21 || x == 31) {
        cout << x << " - " << words << " образователна задача\n";
    }
    else {
        cout << x << " - " << words << " образователни задачи\n";
    }
}


// Main menu
int main() {
    srand((unsigned int)time(nullptr));

    int choice;

    do {
        cout << "\nChoose a task (1-10), or 0 to exit: ";

        if (!(cin >> choice)) {
            break;
        }

        switch (choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            case 5: task5(); break;
            case 6: task6(); break;
            case 7: task7(); break;
            case 8: task8(); break;
            case 9: task9(); break;
            case 10: task10(); break;

            case 0:
                cout << "Goodbye!\n";
                break;

            default:
                cout << "Invalid task number.\n";
        }

    } while (choice != 0);

    return 0;
}
