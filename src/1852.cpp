#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int INF=1e9+10;
const ll INFL=4e18;

int L,N,X[1<<20];

void solve(){
	scanf("%d%d",&L,&N);
	for(int i=0;i<N;i++)scanf("%d",&X[i]);

	int ans=0;
	for(int i=0;i<N;i++)ans=max(ans,min(X[i],L-X[i]));

	printf("%d ",ans);

	ans=0;
	for(int i=0;i<N;i++)ans=max(ans,max(X[i],L-X[i]));
	printf("%d\n",ans);
}

int main(){
	int T;cin>>T;

	while(T--)solve();
}

