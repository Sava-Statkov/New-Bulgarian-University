#include <iostream>
#include <cmath>
using namespace std;


// TASK 1 - Primitive data types
void task1() {
    char letter;
    bool flag;
    short smallNumber;
    unsigned short positiveShort;
    int number;
    unsigned int positiveNumber;
    long bigNumber;
    unsigned long positiveLong;
    long long veryBigNumber;
    unsigned long long positiveLongLong;
    float decimal1;
    double decimal2;
    long double decimal3;

    cout << "char: "; cin >> letter;
    cout << "bool (0 or 1): "; cin >> flag;
    cout << "short: "; cin >> smallNumber;
    cout << "unsigned short: "; cin >> positiveShort;
    cout << "int: "; cin >> number;
    cout << "unsigned int: "; cin >> positiveNumber;
    cout << "long: "; cin >> bigNumber;
    cout << "unsigned long: "; cin >> positiveLong;
    cout << "long long: "; cin >> veryBigNumber;
    cout << "unsigned long long: "; cin >> positiveLongLong;
    cout << "float: "; cin >> decimal1;
    cout << "double: "; cin >> decimal2;
    cout << "long double: "; cin >> decimal3;

    cout << "\nEntered values:\n";
    cout << "char = " << letter << '\n';
    cout << "bool = " << flag << '\n';
    cout << "short = " << smallNumber << '\n';
    cout << "unsigned short = " << positiveShort << '\n';
    cout << "int = " << number << '\n';
    cout << "unsigned int = " << positiveNumber << '\n';
    cout << "long = " << bigNumber << '\n';
    cout << "unsigned long = " << positiveLong << '\n';
    cout << "long long = " << veryBigNumber << '\n';
    cout << "unsigned long long = " << positiveLongLong << '\n';
    cout << "float = " << decimal1 << '\n';
    cout << "double = " << decimal2 << '\n';
    cout << "long double = " << decimal3 << '\n';
}


// TASK 2 - Arithmetic operations
void task2() {
    int a, b;

    cout << "Enter two integers: ";
    cin >> a >> b;

    cout << "a + b = " << a + b << '\n';
    cout << "a - b = " << a - b << '\n';
    cout << "a * b = " << a * b << '\n';

    if (b != 0) {
        cout << "a / b = " << a / b << '\n';
        cout << "a % b = " << a % b << '\n';
    } else {
        cout << "Division and modulo by zero are not allowed.\n";
    }
}


// TASK 3 - Compound assignment operators
void task3() {
    int a, b;

    cout << "Enter two integers: ";
    cin >> a >> b;

    a += b;
    cout << "After a += b: a = " << a << ", b = " << b << '\n';

    a -= b;
    cout << "After a -= b: a = " << a << ", b = " << b << '\n';

    a *= b;
    cout << "After a *= b: a = " << a << ", b = " << b << '\n';

    if (b != 0) {
        a /= b;
        cout << "After a /= b: a = " << a << ", b = " << b << '\n';

        a %= b;
        cout << "After a %= b: a = " << a << ", b = " << b << '\n';
    } else {
        cout << "Cannot use /= or %= when b is zero.\n";
    }
}


// TASK 4 - Swap using bitwise operations
void task4() {
    int a, b;

    cout << "Enter two integers: ";
    cin >> a >> b;

    a ^= b;
    b ^= a;
    a ^= b;

    cout << "After swapping: a = " << a << ", b = " << b << '\n';
}


// TASK 5 - Explanation of bitwise operations
void task5() {
    cout << "Bitwise operators work with the individual bits of integers.\n";

    cout << "&  (AND): bit is 1 when both bits are 1.\n";
    cout << "|  (OR):  bit is 1 when at least one bit is 1.\n";
    cout << "^  (XOR): bit is 1 when the bits differ.\n";
    cout << "~  (NOT): flips all bits.\n";
    cout << "<< (left shift): moves bits left.\n";
    cout << ">> (right shift): moves bits right.\n";

    cout << "Used for flags, masks, embedded systems and binary data.\n";
}


// TASK 6 - Triangle centroid
void task6() {
    double x1, y1, x2, y2, x3, y3;

    cout << "Enter x1 y1: ";
    cin >> x1 >> y1;

    cout << "Enter x2 y2: ";
    cin >> x2 >> y2;

    cout << "Enter x3 y3: ";
    cin >> x3 >> y3;

    double centerX = (x1 + x2 + x3) / 3.0;
    double centerY = (y1 + y2 + y3) / 3.0;

    cout << "Centroid: (" << centerX << ", " << centerY << ")\n";
}


// Helper for tasks 7 and 8.
// Finds the distance from a point to a finite line segment.
double distanceToSide(double x, double y,
                      double x1, double y1,
                      double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;

    double t = ((x - x1) * dx + (y - y1) * dy)
             / (dx * dx + dy * dy);

    if (t < 0) t = 0;
    if (t > 1) t = 1;

    double closestX = x1 + t * dx;
    double closestY = y1 + t * dy;

    return sqrt((x - closestX) * (x - closestX)
              + (y - closestY) * (y - closestY));
}


// TASK 7 - Distances to the sides of two squares
void task7() {
    double x, y;

    cout << "Enter point coordinates x y: ";
    cin >> x >> y;

    // Square a): (0,0), (1,0), (1,1), (0,1)
    cout << "Square a)\n";

    cout << "Side 1: " << distanceToSide(x, y, 0, 0, 1, 0) << '\n';
    cout << "Side 2: " << distanceToSide(x, y, 1, 0, 1, 1) << '\n';
    cout << "Side 3: " << distanceToSide(x, y, 1, 1, 0, 1) << '\n';
    cout << "Side 4: " << distanceToSide(x, y, 0, 1, 0, 0) << '\n';

    // Square b): (1,1), (-1,1), (-1,-1), (1,-1)
    // The assignment repeats (-1,1), probably a typo.
    cout << "Square b)\n";

    cout << "Side 1: " << distanceToSide(x, y, 1, 1, -1, 1) << '\n';
    cout << "Side 2: " << distanceToSide(x, y, -1, 1, -1, -1) << '\n';
    cout << "Side 3: " << distanceToSide(x, y, -1, -1, 1, -1) << '\n';
    cout << "Side 4: " << distanceToSide(x, y, 1, -1, 1, 1) << '\n';
}


// TASK 8 - Distances to the sides of three triangles
void task8() {
    double x, y;

    cout << "Enter point coordinates x y: ";
    cin >> x >> y;

    // Triangle a): (0,0), (1,0), (0,1)
    cout << "Triangle a)\n";

    cout << "Side 1: " << distanceToSide(x, y, 0, 0, 1, 0) << '\n';
    cout << "Side 2: " << distanceToSide(x, y, 1, 0, 0, 1) << '\n';
    cout << "Side 3: " << distanceToSide(x, y, 0, 1, 0, 0) << '\n';

    // Triangle b): (0,0), (1,0), (1,1)
    cout << "Triangle b)\n";

    cout << "Side 1: " << distanceToSide(x, y, 0, 0, 1, 0) << '\n';
    cout << "Side 2: " << distanceToSide(x, y, 1, 0, 1, 1) << '\n';
    cout << "Side 3: " << distanceToSide(x, y, 1, 1, 0, 0) << '\n';

    // Triangle c): (-1,0), (0,0), (1,1)
    cout << "Triangle c)\n";

    cout << "Side 1: " << distanceToSide(x, y, -1, 0, 0, 0) << '\n';
    cout << "Side 2: " << distanceToSide(x, y, 0, 0, 1, 1) << '\n';
    cout << "Side 3: " << distanceToSide(x, y, 1, 1, -1, 0) << '\n';
}


// TASK 9 - Triangle area using angles and circumradius
void task9() {
    double A, B, C, radius;

    cout << "Enter three angles (in degrees): ";
    cin >> A >> B >> C;

    cout << "Enter circumradius: ";
    cin >> radius;

    if (A <= 0 || B <= 0 || C <= 0 ||
        radius <= 0 || fabs(A + B + C - 180) > 0.000001) {
        cout << "Invalid triangle.\n";
        return;
    }

    const double pi = acos(-1.0);

    double area = 2 * radius * radius
                * sin(A * pi / 180)
                * sin(B * pi / 180)
                * sin(C * pi / 180);

    cout << "Area = " << area << '\n';
}


// TASK 10 - Acid mixture concentration
void task10() {
    double acid = 600 * 0.56 + 800 * 0.35;
    double mixture = 600 + 800;

    double concentration = acid / mixture * 100;

    cout << "Concentration = " << concentration << "%\n";
}


// TASK 11 - Compare two bits without conditional statements
void task11() {
    unsigned int x, y, i, j;

    cout << "Enter x and y: ";
    cin >> x >> y;

    cout << "Enter bit positions i and j (starting at 0): ";
    cin >> i >> j;

    bool valid = i < sizeof(x) * 8 && j < sizeof(y) * 8;

    bool same = valid &&
                (((x >> i) & 1u) == ((y >> j) & 1u));

    cout << boolalpha;
    cout << "Valid positions: " << valid << '\n';
    cout << "Bits are equal: " << same << '\n';
    cout << noboolalpha;
}


// TASK 12 - Swap two bits of an unsigned integer
void task12() {
    unsigned int number, i, j;

    cout << "Enter an unsigned integer: ";
    cin >> number;

    cout << "Enter bit positions i and j: ";
    cin >> i >> j;

    if (i >= sizeof(number) * 8 || j >= sizeof(number) * 8) {
        cout << "Invalid bit position.\n";
        return;
    }

    unsigned int different = ((number >> i) ^ (number >> j)) & 1u;

    number ^= (different << i) | (different << j);

    cout << "Result = " << number << '\n';
}


// TASK 13 - Minimum and maximum expressions
void task13() {
    double a, b, c;

    cout << "Enter a b c: ";
    cin >> a >> b >> c;

    // a) min(a+b+c, a*b*c) + 1.5
    double sum = a + b + c;
    double product = a * b * c;

    double minimum = sum;

    if (product < minimum) {
        minimum = product;
    }

    cout << "a) " << minimum + 1.5 << '\n';

    double first = a * a - b * b * b + c;
    double second = a - 4.5 * b;
    double third = 1.5 * a + 3.5 * b - 8 * c;

    double maximum = first;

    if (second > maximum) {
        maximum = second;
    }

    if (third > maximum) {
        maximum = third;
    }

    cout << "b) " << maximum - 7.5 << '\n';
}


// TASK 14 - Multiply smaller by 3, divide larger by 5
void task14() {
    int a, b;

    cout << "Enter two different integers: ";
    cin >> a >> b;

    if (a == b) {
        cout << "The numbers must be different.\n";
    } else if (a < b) {
        cout << "New a = " << a * 3.0
             << ", new b = " << b / 5.0 << '\n';
    } else {
        cout << "New a = " << a / 5.0
             << ", new b = " << b * 3.0 << '\n';
    }
}


// TASK 15 - Absolute values or doubling, without if/switch
void task15() {
    double a, b, c;

    cout << "Enter a b c: ";
    cin >> a >> b >> c;

    bool ordered = (a <= b) && (b <= c);

    a = ordered * fabs(a) + (!ordered) * (2 * a);
    b = ordered * fabs(b) + (!ordered) * (2 * b);
    c = ordered * fabs(c) + (!ordered) * (2 * c);

    cout << "a = " << a
         << ", b = " << b
         << ", c = " << c << '\n';
}


// MAIN FUNCTION
int main() {
    int choice;

    do {
        cout << "\nChoose a task (1-15), or 0 to exit: ";
        cin >> choice;

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
            case 11: task11(); break;
            case 12: task12(); break;
            case 13: task13(); break;
            case 14: task14(); break;
            case 15: task15(); break;
            case 0: cout << "Goodbye!\n"; break;
            default: cout << "Unknown task.\n";
        }
    } while (choice != 0);

    return 0;
}