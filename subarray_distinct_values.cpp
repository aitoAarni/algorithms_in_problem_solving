#include <iostream>
#include <unordered_map>
#include <vector>
#include <fstream>


using namespace std;

int main() {
    long n, k, num, alku = 0, uniikkeja_arvoja = 0;
    unsigned long sub_arrayt = 0;
    vector<long> numerot;
    unordered_map<long, long> maarat; 
    cin >> n >> k;

    for (int i = 0; i<n; i++){
        cin >> num;
        numerot.push_back(num);
    }

    for (int paaty = 0; paaty<n; paaty++){

        maarat[numerot[paaty]]++;
        if (maarat[numerot[paaty]] == 1){
            uniikkeja_arvoja++;
            while (uniikkeja_arvoja > k){
                
                maarat[numerot[alku]]--;
                if (maarat[numerot[alku]] == 0) uniikkeja_arvoja--;
                alku++;
            }
        }
        sub_arrayt += paaty-alku+1;
    }

    cout << sub_arrayt;
}