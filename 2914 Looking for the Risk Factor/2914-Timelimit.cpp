#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Maxi 100005
#define LSOne(S) (S & (-S))
using namespace std;
typedef long long ll;
typedef vector<int> vi;


int isPrime[Maxi];



void seive(){
    for(int i = 0; i < Maxi; i++)isPrime[i] = 1;
    isPrime[0] = isPrime[1] = 0;
    for(ll i = 2; i < Maxi; i++){
        if(isPrime[i] == 1){
            //printf("%d ",i);
            for(ll j = i; j < Maxi; j+= i)isPrime[j] = i;
        }
    }

    //for(int i = 2; i < 21; i++) printf("%d : MaxPrimeFactor %d\n",i,isPrime[i]);


}



int main(){
    fastIO;
    freopen("in.txt","r",stdin);
    freopen("out2.txt","w",stdout);
    seive();
    int cases,n,k,res;
    cin >> cases;
    for(int c = 0; c < cases; c++){
        res = 0;
        cin >>n >> k;
        for(int i = 2; i <= n; i += LSOne(1) ){
            if(isPrime[i] <= k) res++;
        }
        cout<<res<<"\n";
    }

    return 0;
}

