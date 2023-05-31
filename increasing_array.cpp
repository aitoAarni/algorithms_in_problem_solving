#include <iostream>

using namespace std;

int main() {
    long n;
    cin >> n;
    long luvut[n];
    
    for (long i=0; i<n;i++){
        cin >> luvut[i];
    }
    long siirrot = 0;

    for (long i = 1; i < n; i++) {
        if (luvut[i] < luvut[i-1]) {
            long maara  = luvut[i-1] - luvut[i];
            luvut[i] += maara;
            siirrot += maara;
        }
    }
    cout << siirrot;
}