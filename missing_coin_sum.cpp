#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    unsigned long n;
    cin >> n;
    vector<int> kolikot;
    int x;
    for (unsigned long i = 0; i < n; i++) {
        cin >> x;
        kolikot.push_back(x);
        }
    sort(kolikot.begin(), kolikot.end());
    unsigned long a = 0;
    int kolikko = kolikot[0];
    if (kolikko != 1) {
        cout << 1;
        return 0;
    }
    for (unsigned long i = 0; i<n; i++){
        kolikko = kolikot[i];
        if (kolikko + a < kolikot[i+1]-1 || i == n-1) {
            kolikko = kolikot[i];
            break;
        }
        a += kolikot[i];
    }
    a++;
    cout << kolikko + a;

}