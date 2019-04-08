#include <bits/stdc++.h>
#define INF 1<<30
#define Maxi 100005 
#define pb(x) push_back(x)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;


int isPrime[Maxi];
void seive(){
    for(int i = 0; i < Maxi; i++)isPrime[i] = 1;

    for(ll i = 2; i < Maxi; i++){
        if(isPrime[i] == 1){
            for(ll j = i; j < Maxi; j += i)isPrime[j] = i;
        }
    }

    //for(int i = 0; i < 11; i++) printf("%d ",isPrime[i]);
    //puts("");
}

struct SegmentTree {
    int start, end;
    SegmentTree *leftTree, *rightTree;
    int sumValue;

    SegmentTree(int start, int end) {
        this->start = start;
        this->end = end;
        this->sumValue = 0;
        if(start == end) {  // es una hoja
            leftTree = rightTree = NULL;
            return;
        }
        int mid = (start + end) / 2;
        leftTree = new SegmentTree(start, mid);
        rightTree = new SegmentTree(mid + 1, end);
    }

    void sum(int pos, int value) {
        // es una hoja, CASO BASE
        if(start == end) {
            sumValue += value;
            return;
        }

        int mid = (start + end) / 2;

        if(pos <= mid)
            leftTree->sum(pos, value);
        else
            rightTree->sum(pos, value);

        sumValue = leftTree->sumValue + rightTree->sumValue;
    }



    int getSum(int low, int high) {
        // [low,high] = [start,end]
        if(start == low && end == high)
            return sumValue;

        int mid = (start + end) / 2;

        // [low,high] totalmente incluido en [start,mid]
        if(high <= mid)
            return leftTree->getSum(low, high);

        // [low,high] totalmente incluido en [mid+1,end]
        if(low > mid)
            return rightTree->getSum(low, high);

        // debemos dividir el intervalo en [low,mid] y [mid+1,high]
        int leftSum = leftTree->getSum(low, mid);
        int rightSum = rightTree->getSum(mid+1, high);
        return leftSum + rightSum;
    }
};



int main(){ 
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    SegmentTree st(0, Maxi);  
    seive();
    //for(int i = 0; i < Maxi; i++) st.set(i,0);
    
    int q,n,k;
    scanf("%d",&q);
    vector<pair< pair<int,int> , int > > queries;
    for(int c = 0; c < q; c++){
        scanf("%d %d",&n,&k);
        queries.pb(make_pair( make_pair(n,k) , c ));
    }
    
    sort(queries.begin(),queries.end());
    vector<int> ans(q);
    int lastQuery = 1;
    for(int i = 0; i < q; i++){
        n = queries[i].first.first;
        k = queries[i].first.second; 
        
        for(int j = lastQuery+1; j <= n; j++){
            int prime = isPrime[j];
            st.sum(prime,1);
        }
        ans[queries[i].second] = st.getSum(2,k);
        lastQuery = n;
    }
    for(int i = 0; i < q; i++) printf("%d\n",ans[i]);
    return 0;
}
