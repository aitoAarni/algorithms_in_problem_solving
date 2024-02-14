#include <iostream>
#include <unordered_map>
#include <utility>
#include <math.h>
#define nl "\n";
typedef long long ll;
using namespace std;
ll counter = 0;
std::unordered_map<string, ll> tower_results;

ll unique_towers(int height, int sections_left, int prev_pos = 0, int factorial = 1, int sections_in_a_row = 0){
    
    ll total_sum = 0;
    ll section_streak;
    ll factorial_mutliplication;
    
    if (sections_left == 0) {
        sections_in_a_row = sections_in_a_row ? sections_in_a_row : 1;
        factorial_mutliplication = pow(2, sections_in_a_row-1);
        ll n = (height - prev_pos < 2) ? factorial : pow(pow(2, height - prev_pos-1),2) * factorial;
        return n*factorial_mutliplication;
    }
    
   
    for (int i = prev_pos + 1 ; i <= height - sections_left + 1; i++) {
        if (i == prev_pos + 1){
            section_streak = sections_in_a_row + 1;
            factorial_mutliplication = 1;
        }
        else {
            section_streak = 1;
            sections_in_a_row = sections_in_a_row ? sections_in_a_row : 1;
            factorial_mutliplication = pow(2, sections_in_a_row-1);
        }
        int rest = (i-prev_pos < 3) ? 1 : pow(pow(2, i-prev_pos-2),2);
        ll new_factorial = factorial * rest;
        
        total_sum += unique_towers(height, sections_left - 1, i, new_factorial*factorial_mutliplication, section_streak);
    }
    // tower_results[key] = total_sum * factorial;
    return total_sum;
}

ll recursive_function(int tower_height){
    ll total_sum = 0;
    ll current = 0;
    for (int i = 0; i<=tower_height; i++){
        current  = unique_towers(tower_height, i);
        cout << "i: " << i << " " << current << nl;
        total_sum += current;
    }
    return total_sum;
}


int main() {
    // cout << unique_towers(6, 0) << nl;
    cout << recursive_function(6) % (1000000+7) << nl;
}