#include<vector>
#include<algorithm>
template<int SZ>
struct MF{
	struct Edge{
		int to,rev;
		ll cap;
	};
	vector<Edge>g[SZ];
	bool seen[SZ];
	void add(int u,int v,ll cap){
		g[u].push_back({v,(int)g[v].size(),cap});
		g[v].push_back({u,(int)g[u].size()-1,0});
	}
	ll dfs(int now,int t,ll f){
		if(now==t)return f;
		seen[now]=true;
		for(int i=0;i<(int)g[now].size();i++){
			Edge&e=g[now][i];
			if(seen[e.to])continue;
			if(e.cap==0)continue;
			ll res=dfs(e.to,t,min(e.cap,f));
			if(res>0){
				e.cap-=res;
				g[e.to][e.rev].cap+=res;
				return res;
			}
		}
		return 0;
	}
	ll flow(int s,int t){
		ll ret=0;
		while(true){
			fill(seen,seen+SZ,false);
			ll f=dfs(s,t,1e18);
			if(f==0)return ret;
			ret+=f;
		}
	}
};
