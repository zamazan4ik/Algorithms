void z(string &s)
{
    vector<ll> z(s.length());
    for(ll i=1,l=0,r=0;i<n;++i)
    {
        if(i<=r)    z[i]=min(r-i+1,z[i-l]);
        while(i+z[i]<n && s[z[i]] == s[i+z[i]]) ++z[i];
        if(i+z[i]>r)   l=i,r=i+z[i]-1;
    }
}