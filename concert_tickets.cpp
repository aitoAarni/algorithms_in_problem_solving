#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    multiset<int> hinnat;

    int hinta;
    for (int i = 0; i < n; i++) {
        cin >> hinta;
        hinnat.insert(hinta);
    }
    multiset<int>::iterator ylin_lippu;
    multiset<int>::iterator isompi_hinta;
    for (int i=0; i<m; i++){
        cin >> hinta;
        if (hinnat.empty()) {
            cout << "-1\n";
            continue;
        }
        ylin_lippu = hinnat.upper_bound(hinta);
        isompi_hinta = ylin_lippu;
        ylin_lippu--;
        if (*ylin_lippu > hinta || isompi_hinta == hinnat.begin()) {
            cout << -1 << "\n";
        }
        else {
            cout << *ylin_lippu << "\n";
            hinnat.erase(ylin_lippu);
        }
    }

}