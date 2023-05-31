#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> paivat;
    vector<vector<int>> paivat_indeksi;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> lahtoajat;
    int ihmisten_huone_numerot[n];
    int saapuminen, lahto;
    int i = 0;
    while (n>paivat.size()) {
        cin >> saapuminen >> lahto;
        paivat.push_back({saapuminen, lahto});
        paivat_indeksi.push_back({saapuminen, lahto, i});
        i++;
    }
    sort(paivat.begin(), paivat.end());
    sort(paivat_indeksi.begin(), paivat_indeksi.end());
    int huoneita = 1;
    lahtoajat.push({paivat[0].second, huoneita});
    ihmisten_huone_numerot[paivat_indeksi[0][2]] = huoneita;
    for (int i = 1; i<n; i++){
        if (lahtoajat.top().first < paivat[i].first) {
            lahtoajat.push({paivat[i].second, lahtoajat.top().second});
            ihmisten_huone_numerot[paivat_indeksi[i][2]] = lahtoajat.top().second;
            lahtoajat.pop();
        }
        else {
            huoneita++;
            lahtoajat.push({paivat[i].second, huoneita});
            ihmisten_huone_numerot[paivat_indeksi[i][2]] = huoneita;
        }
    }

    cout << huoneita << "\n";
    for (int i = 0; i < n; i++){
        cout << ihmisten_huone_numerot[i] << " ";
    }

}