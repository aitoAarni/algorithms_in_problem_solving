#include <iostream>
#include <vector>


using namespace std;

vector<int> set1;
vector<int> set2;

int main() {
    int n;
    cin >> n;
    unsigned long summa = 0;
    for (int i = 0; i <= n; i++) {
        summa += i;
    }
    if (summa % 2 == 1) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    unsigned long puolet = summa/2;
    summa = 0;
    for (int i = n; i > 0; i--) {
    if (summa + i <= puolet) {
        summa += i;
        set1.push_back(i);
    }
    else set2.push_back(i);
    }
    cout << set1.size() << "\n";
    for (int num: set1) cout << num << " ";
    cout << "\n" << set2.size() << "\n";
    for (int num: set2) cout << num << " ";
    
}