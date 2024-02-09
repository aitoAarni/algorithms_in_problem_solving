#include <iostream>
#include <math.h>
#define nl "\n";
typedef long long ll;
using namespace std;

long long unique_towers_by_height[1000001];
long long factorials[1000001];

int recursive_function(int tower_current_height, int tower_height, int horizontal_blocks){
    if (tower_current_height == 0) 
    {
        cout << "tower current height 0" << nl;
        return 1;
    }
    int numerator = factorials[tower_height];
    int denominator = factorials[horizontal_blocks] * factorials[tower_height - horizontal_blocks];
    cout << "tower_current_height: " << tower_current_height << " added combinations: " << (numerator / denominator) * pow(pow(2, tower_current_height-1), 2) << nl;
    long long total_unique_towers_height_x = (numerator / denominator) * pow(pow(2, tower_current_height-1), 2);
    for (int i = 1; i <= tower_current_height; i++){
        if (horizontal_blocks == 0){
            cout << "i: "  << i << ",   total_unique_towers_height_x: " << total_unique_towers_height_x << nl;
        }
        /* if (unique_towers_by_height[tower_current_height-i] != 0){
            return total_unique_towers_height_x + unique_towers_by_height[tower_current_height-i];
        } */
        unique_towers_by_height[tower_current_height-i] = recursive_function(tower_current_height-i, tower_height, horizontal_blocks + 1);
        total_unique_towers_height_x += unique_towers_by_height[tower_current_height-i];
        cout << "\n" << "horizontal_blocks: " << horizontal_blocks + 1 << "  i: " << i << nl;
        cout << "tower_current_height: " << tower_current_height - i << " added combinations: " << unique_towers_by_height[tower_current_height] << nl;
        
    }
    return total_unique_towers_height_x;
}




int main() {
    factorials[0] = 1;
    int n = 15;
    for (int i = 1; i<=n; i++){
        factorials[i] = factorials[i-1] * i;
    }
    cout << recursive_function(6, 6, 0) << nl;
    for (int i = 0; i < 15; i++){
        cout << i << ": " << unique_towers_by_height[i] << nl;
    }
}
    /* int n = 13;
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
} */