    //https://www.spoj.com/problems/MICEMAZE/
    //author namanvats
	#include<bits/stdc++.h>
    using namespace std;
    #define MOD 1000000000+7
    #define MAX5 100010
    #define MAX6 1000010
    #define pb push_back
    #define mp make_pair
    typedef long long int ll;typedef pair<ll,ll> pii;
    bool visit[MAX5];
    ll dist[MAX5];
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    void dijkstra(ll src,vector<pii> vec[])
    {
    	for(ll i=0;i<=10001;i++)
    		dist[i]=INT_MAX;
    	dist[src]=0;
    	memset(visit,0,sizeof(visit));
    	pq.push({0,src});
    	while(pq.size()!=0)
    	{
    		pii var=pq.top();
    		pq.pop();
    		ll x=var.second;
    		if(visit[x]) continue;
    		else
    		{
    			visit[x]=1;
    			for(ll i=0;i<vec[x].size();i++)
    			{
    				ll e=vec[x][i].second;ll w=vec[x][i].first;
    				if(dist[x]+w<dist[e])
    				{
    					dist[e]=dist[x]+w;
    					pq.push({dist[e],e});
    				}
    			}
    		}
    	}
    }
    int main()
    {
    	ll nodes,exitt,timee,edges;
    	cin>>nodes>>exitt>>timee>>edges;
    	vector<pii> vec[MAX5];
    	for(ll i=1;i<=edges;i++)
    	{
    	    ll a,b,cost;
    		cin>>a>>b>>cost;
    		vec[a].pb(mp(cost,b));
    	}
    	ll cnt=0;
    	for(ll i=1;i<=nodes;i++)
    	{
    		dijkstra(i,vec);
    		if(dist[exitt]<=timee)
    			cnt++;
    	}
    	cout<<cnt<<'\n';
    return 0;
    }
     
