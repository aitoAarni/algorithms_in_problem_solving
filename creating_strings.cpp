#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<string> merkkijonot;

void iteraattori(string &mj, bool merkki_kaytetty[], vector<string> &merkkijonot, string uusi_merkkijono, int iteraatio) {
    if (iteraatio == mj.size()) {
        merkkijonot.push_back(uusi_merkkijono);
    }
    unordered_set<char> kaytetyt_merkit;
    char merkki;
    for (int i = 0; i < mj.size(); i++){
        if (merkki_kaytetty[i] || kaytetyt_merkit.find(mj[i]) != kaytetyt_merkit.end()) continue;
        merkki = mj[i];
        kaytetyt_merkit.insert(merkki);
        merkki_kaytetty[i] = true;
        iteraattori(mj, merkki_kaytetty, merkkijonot, uusi_merkkijono + merkki, iteraatio + 1);
        merkki_kaytetty[i] = false;   
    }
}

int main(){
    string mj;
    cin >> mj;
    bool merkki_kaytetty[mj.size()];
    for (int i = 0; i < mj.size(); i++) {
        merkki_kaytetty[i] = false;

    }
    sort(mj.begin(), mj.end());
    string tyhja_merkkijono;
    iteraattori(mj, merkki_kaytetty, merkkijonot, tyhja_merkkijono, 0);
    int koko = merkkijonot.size();
    cout << koko << "\n";
    for (string merkkijono: merkkijonot) {
        cout << merkkijono + "\n";
    }
}