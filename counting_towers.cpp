#include <iostream>
#include <math.h>
#define nl "\n";
typedef long long ll;
using namespace std;

long long unique_towers_by_height[1000001];
long long factorials[1000001];

int unique_towers(int height, int blocks, int prev_pos = 0, int factorial = 1){
    if (blocks == 0) {

        int n = (height - prev_pos < 2) ? factorial : pow(pow(2, height - prev_pos-1),2) * factorial;
        cout << "blocks: " << blocks << "  prev_pos: " << prev_pos << nl;
        cout << "factorial before: " << factorial << nl;
        cout << "factorial after: " << n << nl;
        cout << nl;
        return n;
    }

    ll total_sum = 0;
    for (int i = prev_pos + 1 ; i <= height - blocks + 1; i++) {
        cout << "blocks: " << blocks << "  block position: " << i << nl;
        cout << "factorial before: " << factorial << nl;
        int rest = (i-prev_pos < 3) ? 1 : pow(pow(2, i-prev_pos-2),2);
        cout << "(i-prev_pos < 3) ? 1 : pow(2, i-prev_pos-1:  " << rest << nl;
        ll new_factorial = factorial * rest;
        cout << "new_factorial: " << new_factorial << nl;
        cout << "total sum: " << total_sum << nl;
        cout << nl;
        
        total_sum += unique_towers(height, blocks - 1, i, new_factorial);
        cout << "blocks: " << blocks << "  block position: " << i << nl;
        cout << "total sum after: " << total_sum << nl;
        cout << nl;
    }
    cout << "total sum: " << total_sum << nl;
    return total_sum;
}

int recursive_function(int tower_current_height, int block_places, int horizontal_blocks){
    if (tower_current_height == 0)
    {
        return 1;
    }
    int numerator = factorials[block_places];
    int denominator = factorials[horizontal_blocks] * factorials[block_places - horizontal_blocks];
    long long total_unique_towers_height_x = (numerator / denominator) * pow(pow(2, tower_current_height-1), 2);
    for (int i = 1; i <= tower_current_height; i++){
        if (horizontal_blocks == 0) {
            cout << "block size: " << i-1 << "  total_unique_towers_height_x: " << total_unique_towers_height_x << nl;
        } 
        total_unique_towers_height_x += recursive_function(tower_current_height-i, block_places-(i-1), horizontal_blocks + 1);
        
    }
    if (horizontal_blocks == 0) {
            cout << "block size: " << tower_current_height << "  total_unique_towers_height_x: " << total_unique_towers_height_x << nl;
    }
    return total_unique_towers_height_x;
}




int main() {
    cout << unique_towers(2, 1) << nl;

    /* factorials[0] = 1;
    int n = 15;
    for (int i = 1; i<=n; i++){
        factorials[i] = factorials[i-1] * i;
    }
    cout << recursive_function(3, 3, 0) << nl; */
}