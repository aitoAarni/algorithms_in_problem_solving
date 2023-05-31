#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> numerot;
unordered_set<int> kaydyt_numerot;

int main(){
    int n;
    int x;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        numerot.push_back(x);
    }
    
    int iteraatiot = 0;
    for (int numero: numerot) {
        if (kaydyt_numerot.find(numero-1) == kaydyt_numerot.end()) {
            iteraatiot++;
        }
        kaydyt_numerot.insert(numero);
    }
    cout << iteraatiot;
}