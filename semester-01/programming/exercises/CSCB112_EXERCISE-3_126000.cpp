#include <iostream>
#include <string>

using namespace std;

void task1() {
    cout << "--- Task 1: Mini Calculator ---\n";
    double a, b;
    char op;
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;
    cout << "Enter operation (+ - * /): ";
    cin >> op;

    switch (op) {
        case '+': cout << "Result: " << a + b << "\n"; break;
        case '-': cout << "Result: " << a - b << "\n"; break;
        case '*': cout << "Result: " << a * b << "\n"; break;
        case '/': 
            if (b != 0) cout << "Result: " << a / b << "\n";
            else cout << "Error: Division by zero!\n";
            break;
        default: cout << "Invalid operation!\n";
    }
}

void task2() {
    cout << "--- Task 2: Leap Year Check ---\n";
    int year;
    cout << "Enter year: ";
    cin >> year;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        cout << "The year is a leap year.\n";
    } else {
        cout << "The year is not a leap year.\n";
    }
}

void task3() {
    cout << "--- Task 3: Grade based on points ---\n";
    int points;
    cout << "Enter points (0-100): ";
    cin >> points;
    if (points >= 0 && points <= 49) cout << "Fail (2)\n";
    else if (points >= 50 && points <= 64) cout << "Average (3)\n";
    else if (points >= 65 && points <= 79) cout << "Good (4)\n";
    else if (points >= 80 && points <= 89) cout << "Very Good (5)\n";
    else if (points >= 90 && points <= 100) cout << "Excellent (6)\n";
    else cout << "Invalid score!\n";
}

void task4() {
    cout << "--- Task 4: Day of the week ---\n";
    int day;
    cout << "Enter a number (1-7): ";
    cin >> day;
    switch (day) {
        case 1: cout << "The day is: Monday\n"; break;
        case 2: cout << "The day is: Tuesday\n"; break;
        case 3: cout << "The day is: Wednesday\n"; break;
        case 4: cout << "The day is: Thursday\n"; break;
        case 5: cout << "The day is: Friday\n"; break;
        case 6: cout << "The day is: Saturday\n"; break;
        case 7: cout << "The day is: Sunday\n"; break;
        default: cout << "Invalid number!\n";
    }
}

void task5() {
    cout << "--- Task 5: Temperature Advisor ---\n";
    int temp;
    cout << "Enter temperature: ";
    cin >> temp;
    if (temp < 0) cout << "Very cold - wear a jacket!\n";
    else if (temp >= 0 && temp <= 10) cout << "Chilly - put on a sweater.\n";
    else if (temp >= 11 && temp <= 20) cout << "Pleasant weather.\n";
    else if (temp >= 21 && temp <= 30) cout << "Warm - perfect for a walk.\n";
    else cout << "Very hot - stay in the shade!\n";
}

void task6() {
    cout << "--- Task 6: Cafe Menu ---\n";
    cout << "1 - Coffee\n2 - Tea\n3 - Hot chocolate\n4 - Water\n";
    int choice;
    cout << "Choose a drink: ";
    cin >> choice;
    switch (choice) {
        case 1: cout << "You chose: Coffee. Good choice!\n"; break;
        case 2: cout << "You chose: Tea. Good choice!\n"; break;
        case 3: cout << "You chose: Hot chocolate. Good choice!\n"; break;
        case 4: cout << "You chose: Water. Good choice!\n"; break;
        default: cout << "Invalid choice!\n";
    }
}

void task7() {
    cout << "--- Task 7: 'Funny' number check ---\n";
    int num;
    cout << "Enter an integer: ";
    cin >> num;
    if (num % 3 == 0 && num % 5 == 0) cout << "FizzBuzz\n";
    else if (num % 3 == 0) cout << "Fizz\n";
    else if (num % 5 == 0) cout << "Buzz\n";
    else cout << num << "\n";
}

void task8() {
    cout << "--- Task 8: Traffic light color ---\n";
    string color;
    cout << "Enter color (red, yellow, green): ";
    cin >> color;
    if (color == "red") cout << "Wait!\n";
    else if (color == "yellow") cout << "Get ready!\n";
    else if (color == "green") cout << "Go!\n";
    else cout << "Invalid color!\n";
}

int main() {
    int choice;
    do {
        cout << "-------------------------------------\n";
        cout << "Select a task to run (1-8) or 0 to exit:\n";
        cout << "1. Mini Calculator\n";
        cout << "2. Leap Year Check\n";
        cout << "3. Grade based on points\n";
        cout << "4. Day of the week\n";
        cout << "5. Temperature Advisor\n";
        cout << "6. Cafe Menu\n";
        cout << "7. 'Funny' number check\n";
        cout << "8. Traffic light color\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> choice;
        cout << "------------------------------------\n";

        switch (choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            case 5: task5(); break;
            case 6: task6(); break;
            case 7: task7(); break;
            case 8: task8(); break;
            case 0: cout << "End of program.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}