#include <bits/stdc++.h>
    
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;
    
vector <int> segtree[400010];
int a[100010];
    
void build(int nd, int st, int ed)
{
    if(st == ed)
    {
        segtree[nd].push_back(a[st]);
        return;
    }
    
    int mid = (st+ed)/2;
    
    build(2*nd,st,mid);
    build(2*nd+1,mid+1,ed);

    segtree[nd].resize(segtree[2*nd].size()+segtree[2*nd+1].size());
    
    merge(segtree[2*nd].begin(),segtree[2*nd].end(),segtree[2*nd+1].begin(),
            segtree[2*nd+1].end(),segtree[nd].begin());
}
    
vector <int> quary(int nd, int st, int ed, int l, int r)
{
    int mid = (st+ed)/2;
    
    if(st >= l && ed <= r)
        return segtree[nd];
    else if(l > mid)
        return quary(2*nd+1,mid+1,ed,l,r);
    else if(r <= mid)
        return quary(2*nd,st,mid,l,r);
    else
    {
        vector <int> temp,t1,t2;
        t1 = quary(2*nd,st,mid,l,r);
        t2 = quary(2*nd+1,mid+1,ed,l,r);
        temp.resize(t1.size()+t2.size());
        merge(t1.begin(),t1.end(),t2.begin(),t2.end(),temp.begin());
        return temp;
    }
}
    
int main()
{
    fastIO;

    int n,q;
    cin >> n >> q;
    
    for(int i=0;i<n;i++)
        cin >> a[i];
    
    build(1,0,n-1);

    while(q--)
    {
        int x,y,z;
        cin >> x >> y >> z;

        vector <int> s = quary(1,0,n-1,x-1,y-1);

        cout << s[z-1] << endl;
    }
} 