#include <bits/stdc++.h>
using namespace std;

// int f(int ind, vector<int>& num, int sq, vector<int>& partition) {
//     int n = num.size();
//     //base case:
//     if (ind == n){
//         int sum = 0;
//         for(int x: partition){
//             cout << x << " ";
//             sum+=x;
//         }
//         cout << endl;
//         return sum == sq;
//     }

//     // int len = 0;
//     // int sum = 0;
//     // for (int j = ind; j < min(ind + k, n); j++) {
//     //     len++;
//     //     sum += stoi()
//     //     int sum = len * maxi + f(j + 1, num, k);
//     //     maxAns = max(maxAns, sum);
//     // }
//     // return maxAns;
//     bool ans = false;
//     for (int i = ind; i<n; i++){
//         partition.push_back()
//         ans = ans && f(ind+1, num, sq, partition);
//         partition.pop_back();
//     }
//     cout << endl;
//     return ans;
// }

bool solve(int i, string &s, vector<int> temp, int sq){
    int n = s.length();
    if(i > n - 1){
        int sum = 0;
        for(int x: temp){
            // cout << x << " ";
            sum += x;
        }
        // cout << "  "<<sum << endl;
        return sum == sq;
    }

    bool ans = false;
    for (int len = 1; len <= n - i; len++){
        int num = stoi(s.substr(i, len));
        temp.push_back(num);
        ans = ans || solve(i + len, s, temp, sq);
        temp.pop_back();
    }
    return ans;
}

int punishmentNumber(int n){
    int sum = 0;
    for(int i = 1; i<=n; i++){
        vector<int> temp;
        string s = to_string(i * i);
        cout << i << " ";
        if(solve(0, s, temp, i)){
            // cout << i * i << endl;
            sum += i * i;
        }
    }
    // string s = to_string(36 * 36);
    return sum;
}
int main(){
    int n;
    cin >> n;
    cout << punishmentNumber(n);
    // string s = "124";
    // cout<<s.substr(0,1)<<endl;
}