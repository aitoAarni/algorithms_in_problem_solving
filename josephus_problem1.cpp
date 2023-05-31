#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> jarjestys;
    bool kaytettavissa[n];
    for (int i = 0; i < n; i++) kaytettavissa[i] = true;

    int i = 1;
    int jktn = 0;
    while (true) {
        
        if (i == n){
            i = 0;
        }
        if (kaytettavissa[i]){
            jktn = jktn == 1 ? 0 : 1;
            if (jktn) {
                kaytettavissa[i] = false;
                jarjestys.push_back(i+1);
                if (jarjestys.size() == n) break;
            }
        }
        i++;
    }
    for (int pentu: jarjestys) cout << pentu << " ";
}