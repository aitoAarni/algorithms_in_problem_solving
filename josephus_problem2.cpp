#include <iostream>
#include <vector>
#include <set>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
 
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> jarjestys;
    indexed_set numerot;
    for (int i = 0; i<n; i++)numerot.insert(i);
    int i = k;
    int koko = n;
    while (true) {
        
        if (numerot.size() == 0) break;

        if (i >= koko){
            i = i%koko;
        }
        auto num = numerot.find_by_order(i);
        jarjestys.push_back(*num+1);
        numerot.erase(num);
        koko--;
        i += k;
    }

    for (int pentu: jarjestys) cout << pentu << " ";
}