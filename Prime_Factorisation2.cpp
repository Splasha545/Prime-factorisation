#include<bits/stdc++.h>
#include<conio.h>

using namespace std;

int min_ = 100000000;

int factor(int a){
    if (a % 2 == 0) {
        factor(a/2);
        cout << 2 << " ";
    }
    else {
        for (int i = 3; i <= sqrt(a); i++) {
            if (a % i == 0) {
                factor(a/i);
                cout << i << " ";
                break;
            }
            i++;
        }
        if (a > 2 && a < min_) {
            min_ = a;
            cout << a << " ";
        }
    }
    return a;
}

int main() {
    int n, num;
    while (num < 0 || num > 4){
        cout << "Please select a range of values: \n 1: 2-100 \n 2: 101-200 \n 3: 201-400 \n 4: Make a custom range \n Please select by entering a number between 1 and 4. \n \n";
        cin >> num;
    }
    srand (time(NULL));
    if (num == 1) {
        n = 2 + (rand() % (100 - 2 + 1));
    }
    if (num == 2) {
        n = 101 + (rand() % (200 - 101 + 1));
    }
    if (num == 3) {
        n = 201 + (rand() % (400 - 201 + 1));
    }
    if (num == 4) {
        int lower = 2;
        int upper = 1;
        while (upper <= lower) {
            cout << "Please enter the lower boundary \n";
            cin >> lower;
            cout << "Please enter the upper boundary \n";
            cin >> upper;
            if (upper <= lower || upper < 0 || lower < 0) {
                cout << "Invalid range \n";
            }
        }
        n = lower + (rand() % (upper - lower + 1));
    }
    cout << "\n Your number is " << n << "\n Press any key to continue and view the prime factorisation of this number. \n \n";
    getch();
    factor(n);
    cout << "\n Press any key to exit...";
    getch();
    return 0;
}
