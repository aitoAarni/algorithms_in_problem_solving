#include <iostream>
#include <unordered_map>
#include <utility>
#include <math.h>
#define nl "\n";
typedef long long ll;
using namespace std;

std::unordered_map<string, ll> tower_results;

int unique_towers(int height, int blocks, int prev_pos = 0, int factorial = 1){
    if (blocks == 0) {

        int n = (height - prev_pos < 2) ? factorial : pow(pow(2, height - prev_pos-1),2) * factorial;
        return n;
    }

    ll total_sum = 0;
    for (int i = prev_pos + 1 ; i <= height - blocks + 1; i++) {
        int rest = (i-prev_pos < 3) ? 1 : pow(pow(2, i-prev_pos-2),2);
        ll new_factorial = factorial * rest;
        
        total_sum += unique_towers(height, blocks - 1, i, new_factorial);
    }
    return total_sum;
}

int recursive_function(int tower_current_height, int block_places, int horizontal_blocks){
    if (tower_current_height == 0)
    {
        return 1;
    }
    string key = to_string(block_places) + " " + to_string(horizontal_blocks);
    tower_results[key] = tower_results[key] ? tower_results[key] : unique_towers(block_places, horizontal_blocks);
    ll total_unique_towers_height_x = tower_results[key];
    for (int i = 1; i <= tower_current_height; i++){
        total_unique_towers_height_x += recursive_function(tower_current_height-i, block_places-(i-1), horizontal_blocks + 1);
        
    }
    return total_unique_towers_height_x;
}




int main() {
    // cout << unique_towers(2, 1) << nl;

   
    cout << recursive_function(6, 6, 0) % (1000000+7) << nl;
}