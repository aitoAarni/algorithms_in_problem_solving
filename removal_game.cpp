#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;
ll totaali_summa;
ll ero[5001][5001];
int main(){
    int n;
    cin >> n;
    ll lista[n+1];
    for (int i = 1; i<=n; i++){
        cin >> lista[i];
        totaali_summa += lista[i];
        ero[i][i] = lista[i];
    }

    for (int vasen = n; vasen > 0; vasen--){
        for (int oikea = vasen+1; oikea < n+1; oikea++){
            ll ensimmainen = lista[vasen] - ero[vasen+1][oikea];
            ll viimeinen = lista[oikea] - ero[vasen][oikea-1];
            ero[vasen][oikea] = max(ensimmainen, viimeinen);
        }
    }
    cout << (totaali_summa + ero[1][n]) / 2;

}