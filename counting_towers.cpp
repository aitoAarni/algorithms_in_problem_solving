#include <iostream>
#include <math.h>
#define nl "\n";
typedef long long ll;
using namespace std;

unsigned long long unique_towers_by_height_width_1[1000001];
unsigned long long unique_towers_by_height[1000001];


int main() {
    int n = 13;
    unique_towers_by_height_width_1[1] = 1;
    unique_towers_by_height[1] = 2;
    for (int x = 2; x <= n; x++){
        unsigned long long total_unique_towers_height_x = 0;
        unique_towers_by_height[x] = 1;
        unique_towers_by_height_width_1[x] = 1;
        unsigned long long total_width1 = 0;
        for (int i = 1; i <= x; i++){
            total_unique_towers_height_x += unique_towers_by_height[i];
            unsigned long long unique_towers_x = unique_towers_by_height_width_1[i];
            for (int j = 1; j <= x; j++){
                total_width1 += unique_towers_x * unique_towers_by_height_width_1[j];
            }
        }
        cout << "korkeus: " << x << nl;
        for (int i = 1; i <= x; i++){
            cout << "yhdistelmia: " << unique_towers_by_height[i] << nl;
        }
        cout << "total_unique_towers_height_x: " << total_unique_towers_height_x << nl;
        cout << "total_width1: " << total_width1 << nl;
        total_unique_towers_height_x += pow(pow(2, x-1), 2);
        total_unique_towers_height_x += pow(unique_towers_by_height_width_1[x-1], 2) -1;
        cout << "total_unique_towers before added last: " << total_unique_towers_height_x << nl;
        total_unique_towers_height_x += unique_towers_by_height[x-1] - unique_towers_by_height_width_1[x-1] * unique_towers_by_height_width_1[x-1];
        unique_towers_by_height_width_1[x] = pow(2, x-1);
        unique_towers_by_height[x] = total_unique_towers_height_x;
        cout << " yhdistelmia: " << total_unique_towers_height_x  << nl;
        cout << nl nl;

    }
    for (int i = 1; i < 14; i++){
        cout << i << ": " << unique_towers_by_height_width_1[i] << ",  total: " << unique_towers_by_height[i] << nl;
    }
}