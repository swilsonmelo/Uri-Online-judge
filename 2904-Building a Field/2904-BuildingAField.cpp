#include<bits/stdc++.h>
#define Maxi 100000
using namespace std;

int edges[Maxi];

int main(){
    int n,sum,mid,pairs;
    while(scanf("%d",&n) == 1){
        sum = 0;
        set<long> arcs;
        for(int i = 0; i < n; i++){
            scanf("%d",&edges[i]);
            sum += edges[i];
            arcs.insert(sum);
        }
        if( sum % 2 == 1){
            printf("N\n");
        }else{
            mid = sum/2;
            sum = 0;
            pairs = 0;
            for(int i = 0; i < n; i++){
                if(sum >= mid) break;
                if(arcs.find(sum + mid) != arcs.end() ){
                    //printf("sum %d mid %d\n",sum,mid);
                    pairs++;
                }
                sum += edges[i];
            }
            if(pairs >= 2) printf("Y\n");
            else printf("N\n");;
        }

    }
    return 0;
}