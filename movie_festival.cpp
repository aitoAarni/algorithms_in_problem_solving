#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int alku, loppu;
    vector<pair<int, int>> ajat;
    for (int i = 0; i < n; i++) {
        cin >> alku >> loppu;
        ajat.push_back({alku, loppu});
    }
    sort(ajat.begin(), ajat.end());


    int nahtavissa = 0;
    int leffa_loppuu = 0;
    for (pair<int, int> aika: ajat){
        if (aika.second < leffa_loppuu) leffa_loppuu = aika.second;
        else if (aika.first >= leffa_loppuu){
            nahtavissa++;
            leffa_loppuu = aika.second;
        }
    }
    cout << nahtavissa;

}