#include<bits/stdc++.h>


using namespace std;


int main(){
    float degree;
    int n,res;
    while(scanf("%f",&degree) == 1){
        //n = (degree*1000 + 5)/10;
        n = degree*100+0.01;//para que el casteo a entero sea exacto
        for(int i = 1; i <= 36000; i++){
            if((n*i)%36000 == 0){
                res = i;
                break;
                }
        }
        printf("%d\n",res);
    }

    return 0;
}
