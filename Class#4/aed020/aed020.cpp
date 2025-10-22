#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; if(!(cin>>N)) return 0;
    vector<long long>a(N), b(N);

    for(int i=0;i<N;++i) {
        cin>>a[i]>>b[i];
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int i=0,j=0,curr=0,ans=0;

    while(i<N&&j<N){
        if(a[i]<b[j]){curr++; ans=max(ans,curr); i++;}
        else{curr--; j++;}
    }
    cout<<ans<<"\n";
    return 0;
}