const ll maxv=100,maxe=100000;
ll first[maxv],es[maxe],ef[maxe],ev[maxe],next[maxe],c=0;

typedef long long ll;

void init(ll v1,ll v2,ll val)
{
	next[++c]=first[v1];first[v1]=c;
	ef[c]=v1;es[c]=v2;ev[c]=val;
}