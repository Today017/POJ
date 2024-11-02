#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int INF=1e9+10;
const ll INFL=4e18;

ll modPow(ll a,ll n,ll p){
	ll ret=1;
	while(n){
		if(n&1)(ret*=a)%=p;
		(a*=a)%=p;
		n>>=1;
	}
	return ret;
}

int main(){
	while(true){
		ll P,A;
		scanf("%lld%lld",&P,&A);

		if(P==0&&A==0)break;

		bool ok=true;
		for(ll i=2;i*i<=P;i++){
			if(P%i==0)ok=false;
		}
		if(ok){
			puts("no");
			continue;
		}

		ll x=modPow(A,P,P);

		puts(x==A?"yes":"no");
	}
}

