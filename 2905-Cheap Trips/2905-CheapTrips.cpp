#include<bits/stdc++.h>
#define Maxi 10010
#define Inf 1e15
using namespace std;

int c[Maxi];
int d[Maxi];
double dp[Maxi];

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%d %d",&d[i],&c[i]);
        dp[i] = Inf;
    }
    for(int i = 1; i <= n; i++){
        dp[i] = min(dp[i],dp[i-1]+c[i]);
        int time = d[i];
        if( time < 120 ){
            dp[i+1] = min(dp[i+1] , dp[i-1]+c[i] + 0.5*c[i+1] );
        }
        double price = 0;
        for(int j = 1; j <= 4; j++){
            time += d[i+j];
            price += c[i+j+1];
            if(time < 120){
                dp[i+j+1] = min(dp[i+j+1], dp[i-1] + c[i] + 0.5*c[i+1] + 0.25*price );
            }
        }
    }
    printf("%.2lf\n",dp[n]);
    


    return 0;
}