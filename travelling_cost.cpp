    //Travelling Cost Spoj
	#include<bits/stdc++.h>
    using namespace std;
    #define MAX5 100010
    #define MAX6 1000010
    #define pb push_back
    #define pf push_front
    #define mp make_pair
    #define mod 1000000007
    #define all(a) a.begin(),a.end()
    typedef long long int ll;typedef long int l;typedef pair<int,int> pii;
    ll modd(ll x){if(x>=0)return x;else return -1*x;}
    vector<pii> vec[10010];
    ll dist[10010];
    bool visit[10010];
    priority_queue<pii,vector<pii>,greater<pii> >pq;
    void djikstra(int src)
    {
        for(int i=0;i<=1001;i++)
        {
            dist[i]=INT_MAX;
        }
        dist[src]=0;
        memset(visit,0,sizeof(visit));
        pq.push({0,src});
        while(pq.size()!=0)
        {
            pii var=pq.top();
            pq.pop();
            int x=var.second;
            if(visit[x]) continue;
            else
            {
                visit[x]=1;
                for(int i=0;i<vec[x].size();i++)
                {
                    int e=vec[x][i].second;int w=vec[x][i].first;
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
        int num;
        cin>>num;
        for(int i=0;i<num;i++)
        {
            int a,b,w;
            cin>>a>>b>>w;
            vec[a].pb(mp(w,b));
            vec[b].pb(mp(w,a));
        }
        int src,query;
        cin>>src>>query;
        djikstra(src);
        while(query--)
        {
            int dest;
            cin>>dest;
            if(visit[dest]==0)
                cout<<"NO PATH"<<'\n';
            else
                cout<<dist[dest]<<'\n';
        }
    return 0;
    } 
