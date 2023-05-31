#include <iostream>
#include <vector>

using namespace std;

vector<long long> numerot;

int main() {
    long long n;
    cin >> n;
    numerot.push_back(n);
    while (n != 1) {
        if (n % 2 == 0) n /= 2;
        else n = n * 3 + 1;
        numerot.push_back(n);

    }
    for (long long numero: numerot){
        cout << numero << " ";
    }

}