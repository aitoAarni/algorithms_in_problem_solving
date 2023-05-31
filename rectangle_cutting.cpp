#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;


int muisti[500][500];

int iteraattori(int a, int b);

long hae_arvo(int a,int b) {
    long avain;
    int x = a, y = b;

    if (x > y) swap(x, y);
        if (muisti[x][y] == false){
            muisti[x][y] = iteraattori(a, b);
        }
        return muisti[x][y];
}

int iteraattori(int a, int b) {
    if (a==b){
        return 0;
    }
    int a1, a2, b1, b2;
    long paras_leikkaus = (long)8000 ;
    long leikkaus_tulos;
    for (int leikkaus = 1; leikkaus < a; leikkaus++){
        leikkaus_tulos = 1;
        a1 = leikkaus;
        a2 = a-leikkaus;

        leikkaus_tulos += hae_arvo(a1, b);
        leikkaus_tulos += hae_arvo(a2, b);

        paras_leikkaus = min(leikkaus_tulos, paras_leikkaus);
        if (paras_leikkaus == 1) return 1;
        
    }
    for (int leikkaus = 1; leikkaus < b; leikkaus ++){
        leikkaus_tulos = 1;
        b1 = leikkaus;
        b2 = b-leikkaus;

        leikkaus_tulos += hae_arvo(a, b1);
        leikkaus_tulos += hae_arvo(a, b2);

        paras_leikkaus = min(leikkaus_tulos, paras_leikkaus);
        if (paras_leikkaus == 1) return 1;
    }
    return paras_leikkaus;
}

int main() {
    
    for (int i = 0; i<500;i++){
    for (int j = 0; j<500; j++) muisti[i][j] = false;
    }
    int a, b;
    cin >> a >> b;
    
    int num = iteraattori(a, b);
    
    cout << num;

}