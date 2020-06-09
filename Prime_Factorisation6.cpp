#include<bits/stdc++.h>
#include<conio.h>
#include<stdlib.h>

using namespace std;

long long int min_ = 2000000000000000000;
vector<long long int> primes;

void factor(long long int a){
    if (a % 2 == 0) {
        factor(a/2);
        primes.push_back(2);
    }
    else {
        for (long long int i = 3; i <= sqrt(a); i++) {
            if (a % i == 0) {
                factor(a/i);
                primes.push_back(i);
                break;
            }
            i++;
        }
        if (a > 2 && a < min_) {
            min_ = a;
            primes.push_back(a);
        }
    }
}

int interval = 0;
long long int i_ = 1;

int campaign() {
    long long int n;
    primes.clear();
    n = (i_ + 1) + (rand() % (interval - (i_ + 1) + 1));
    cout << "\n Your number is " << n << "\n Press any key to continue and view the prime factorisation of this number. \n \n";
    getch();
    cout << "Prime Factorisation of " << n << ": ";
    factor(n);
    cout << "[";
    for (int i = primes.size() - 1; i >= 0; i--){
        cout << primes[i];
        if (i != 0){
            cout << " * ";
        }
    }
    cout << "]";
    cout << "\n \n Enter 'q' to quit or press 'enter' to view your next number... \n \n";
    char check;
    check = 'a';
    if (i_ == 1){
        cin.ignore(1, '\n');
    }
    do {
        check = getchar();
        if (check == 'q') {
            return 1;
        }
    } while (check != '\n');
    int change = interval - i_;
    i_ = interval + 1;
    interval = change + interval + 1;
    min_ = 2000000000000000000;
    return 0;
}

long long int lower = 2;
long long int upper = 1;

int sub_main(){
    long long int n, num;

    primes.clear();
    num = 10;
    while (num < 1 || num > 7){
        cout << "Please select a range of values: \n 1: 2-100 \n 2: 101-200 \n 3: 201-400 \n 4: Make a custom range \n 5: Reuse custom range \n 6: Increasing intervals \n 7: Quit \n Please select by entering a number between 1 and 7. \n \n";
        while(!(cin >> num)) {
            cin.clear();
            cin.ignore(12, '\n');
        }
    }
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
        upper = 1;
        lower = 2;
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
    if (num == 5) {
        if (lower == 2 && upper == 1){
            cout << "A custom range has not been set yet! \n";
            return 0;
        }
        n = lower + (rand() % (upper - lower + 1));
    }
    if (num == 6) {
        cout << " 1: Play with default interval. (default interval = 100) \n 2: Make custom interval \n";
        while (!(cin >> interval) || interval < 1 || interval > 2){
            cin.clear();
            cin.ignore(12, '\n');
            cout << "That is not a number within the valid range. \n";
        };
        if (interval == 1) {
            interval = 100;
        }
        else if (interval == 2) {
            cout << "Please enter the interval (must be an integer number over 2)...\n";
            while(!(cin >> interval) || interval <= 2) {
                cin.clear();
                cin.ignore(12, '\n');
                cout << "That interval is not an integer number over 2. \n";
            }
        }
        return 123;
    }
    if (num == 7) {
        return 1;
    }
    cout << "\n Your number is " << n << "\n Press any key to continue and view the prime factorisation of this number. \n \n";
    getch();
    cout << "Prime Factorisation of " << n << ": ";
    factor(n);
    cout << "[";
    for (int i = primes.size() - 1; i >= 0; i--){
        cout << primes[i];
        if (i != 0){
            cout << " * ";
        }
    }
    cout << "]";
    cout << endl << endl;
    min_ = 2000000000000000000;
    cout << "Press any key to continue... \n \n";
    getch();
    return 0;
}

int main() {
    srand (time(NULL));
    while (sub_main() != 1 && interval == 0) {
    }
    if (interval != 0) {
        while (campaign() != 1) {
        }
    }
    cout << "\n Press any key to exit...";
    getch();
    return 0;
}
