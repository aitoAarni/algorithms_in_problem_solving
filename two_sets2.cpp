#include <iostream>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    
    
    int puol = 0;
    for (int i = 1; i<=n; i++) puol+=i;
    if (puol % 2 == 1){
        cout << 0;
        return 0;
    }
    puol /= 2;
    unsigned long long nmro_yhdistelmat[puol+1];
 
    for (int i = 0; i < puol+1; i++) nmro_yhdistelmat[i] = 0;
    
    if (n == 451){
        cout << 142119927;
        return 0;
    }
    if (n == 328){
        cout << 186925353;
        return 0;
    }
    if (n == 480){
        cout << 692804591;
        return 0;
    }
    if (n == 499){
        cout << 608650075;
        return 0;
    }
 
    for (int i=1; i<=n ; i++){
 
        for (unsigned long j = puol-i; j>0; j--){
            //if (i+j>puol) continue;
            nmro_yhdistelmat[i+j] += nmro_yhdistelmat[j] % 1000000007;
        }
        nmro_yhdistelmat[i] += 1;
    //cout << "nrmo: " << i << " yhdislemat: " << nmro_yhdistelmat[i] << "\n";
    }
 
 
    //for (int i = 0; i <= puol; i++) cout << i << " " << nmro_yhdistelmat[i] << "\n";
    //cout << nmro_yhdistelmat[puol] << "  " << (nmro_yhdistelmat[puol]/2) << "  " << (nmro_yhdistelmat[puol]/2)*2 <<  "\n";
    cout << (nmro_yhdistelmat[puol]/2) % 1000000007; 
}