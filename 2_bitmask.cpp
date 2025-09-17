#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin>>N;
    vector<int> a(N);
    for(int i=0;i<N;i++) cin>>a[i];

    for(int mask=0;mask<(1<<N);mask++){
        vector<int> subset;
        for(int i=0;i<N;i++){
            if(mask & (1<<i)){
                subset.push_back(a[i]);
            }
        }
    }
}