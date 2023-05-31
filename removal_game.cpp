#include <chrono>
#include <iostream>
#include <deque>
#include <unordered_map>
#include <math.h>
#include <fstream>

using namespace std;
unordered_map<long, pair<long long, long long>> parhaat_tulokset;


pair<long long, long long> iteraattori(deque<long> &arvot, int vasen, int oikea, int n){

    if (vasen+oikea == n-2){
        long long pienempi = min(arvot.front(), arvot.back()), isompi = max(arvot.front(), arvot.back());

        parhaat_tulokset[vasen * 10000 + oikea] = {pienempi, isompi};
        return {pienempi, isompi};
    }
    long avain = avain = vasen * 10000 + oikea;
    if (parhaat_tulokset.find(avain) == parhaat_tulokset.end()){
        long muisti = arvot.front();
        arvot.pop_front();
        pair<long long, long long> pari = iteraattori(arvot, vasen+1, oikea, n);
        long long arvo1 = pari.first + muisti, seuraava1 = pari.second;
        arvot.push_front(muisti);

        muisti = arvot.back();
        arvot.pop_back();
        pair<long long, long long> pari2 = iteraattori(arvot, vasen, oikea+1, n);
        long long arvo2 = pari2.first + muisti, seuraava2 = pari2.second;
        arvot.push_back(muisti);

        pair<long long, long long> isompi;
        if (arvo1 > arvo2) isompi = {arvo1, seuraava1};
        else isompi = {arvo2, seuraava2};
        
        parhaat_tulokset[avain] = isompi;
    }
    pair<long long, long long> tulos = parhaat_tulokset[avain];
    return {tulos.second, tulos.first};
}

int main() {

    int n;
    ifstream f("syote.txt");
    f >> n;
    deque<long> lista;
    int i = 0;
    long numero;
    while (i<n){
        i++;
        f >> numero;
        lista.push_back(numero);
    }
    f.close();
    auto alku = chrono::system_clock::now();
    pair<long long, long long> vastaus = iteraattori(lista, 0, 0, n);
    auto loppu = chrono::system_clock::now();
    chrono::duration<double> aika = loppu-alku;
    cout << "aika: " << aika.count() << "\n";
    cout << vastaus.second;
}