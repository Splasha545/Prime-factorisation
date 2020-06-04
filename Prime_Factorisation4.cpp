#include<bits/stdc++.h>
#include<conio.h>
#include<stdlib.h>

using namespace std;

int min_ = 100000000;
vector<int> primes;

void factor(int a){
    if (a % 2 == 0) {
        factor(a/2);
        primes.push_back(2);
    }
    else {
        for (int i = 3; i <= sqrt(a); i++) {
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

int lower = 2;
int upper = 1;

int sub_main(){
    int n, num;
    primes.clear();
    num = 10;
    while (num < 1 || num > 6){
        cout << "Please select a range of values: \n 1: 2-100 \n 2: 101-200 \n 3: 201-400 \n 4: Make a custom range \n 5: Reuse custom range \n 6: Quit \n Please select by entering a number between 1 and 6. \n \n";
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
        return 1;
    }
    cout << "\n Your number is " << n << "\n Press any key to continue and view the prime factorisation of this number. \n \n";
    getch();
    cout << "Prime Factorisation of " << n << ": ";
    factor(n);
    for (int i = primes.size() - 1; i >= 0; i--){
        cout << primes[i] << " ";
    }
    cout << endl << endl;
    min_ = 100000000;
    getch();
    return 0;
}

int main() {
    srand (time(NULL));
    while (sub_main() != 1) {
    }
    cout << "\n Press any key to exit...";
    getch();
    return 0;
}
