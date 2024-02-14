#include <iostream>
#include <unordered_map>
#include <utility>
#include <math.h>
#define nl "\n";
typedef long long ll;
using namespace std;
ll counter = 0;
std::unordered_map<string, ll> tower_results;



int unique_towers(int height, int blocks, int prev_pos = 0, int factorial = 1){
    if (blocks == 0) {
        int n = (height - prev_pos < 2) ? factorial : pow(pow(2, height - prev_pos-1),2) * factorial;
        return n;
    }
    const int h = height - (prev_pos);
    const string key = to_string(h) + " " + to_string(blocks);
    if (tower_results[key] != 0) {
        return tower_results[key]*factorial;
        }
   
    ll total_sum = 0;
    for (int i = prev_pos + 1 ; i <= height - blocks + 1; i++) {
        int rest = (i-prev_pos < 3) ? 1 : pow(pow(2, i-prev_pos-2),2);
        ll new_factorial = factorial * rest;
        
        total_sum += unique_towers(height, blocks - 1, i, new_factorial);
    }
    // tower_results[key] = total_sum * factorial;
    return total_sum;
}

int recursive_function(int tower_current_height, int block_places, int horizontal_blocks){
    if (tower_current_height == 0)
    {
        return 1;
    }
    string key = to_string(block_places) + " " + to_string(horizontal_blocks);
    counter += 1;
    tower_results[key] = tower_results[key] ? tower_results[key] : unique_towers(block_places, horizontal_blocks);
    // cout << "counter: " << counter << "  key: " << key << "  result: " << tower_results[key] <<  nl;
    ll total_unique_towers_height_x = tower_results[key];
    for (int i = 1; i <= tower_current_height; i++){
        if (horizontal_blocks == 0) {
            cout << "i: " << i << nl;
        }
        total_unique_towers_height_x += recursive_function(tower_current_height-i, block_places-(i-1), horizontal_blocks + 1);
        
    }
    return total_unique_towers_height_x;
}




int main() {
    // cout << unique_towers(2, 1) << nl;
    cout << recursive_function(6, 6, 0) % (1000000+7) << nl;
}