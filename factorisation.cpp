// Factorisation in O(pow(n,1/2))
#include <bits/stdc++.h>
using namespace std;

vector<int> factorize(int n) {
    vector<int> res;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            res.push_back(i);
            n /= i;
        }
    }
    if (n != 1) {
        res.push_back(n);
    }
    return res;
}

int main(){
  
  int n;
  cin>>n;

  vector<int> factors = factorize(n);

  for( auto a: factors){
    cout<<factors[a]<<" ";
  }


}