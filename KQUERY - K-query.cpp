#include <bits/stdc++.h>

#define pb push_back
    
using namespace std;
    
int tree[120040];
int a[30010];
vector <pair<int,int> > v;
pair <int,tuple<int,int,int> > p[200010];
int ans[200010];
    
void update(int node, int start, int end, int idx)
{
    if(start == end)
        tree[node]++;
    else
    {
        int mid = (start + end) / 2;

        if(start <= idx and idx <= mid)
            update(2*node, start, mid, idx);
        else
            update(2*node+1, mid+1, end, idx);
    
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
    
int quary(int nd, int st, int ed, int l, int r)
{
    int mid = (st+ed)/2;
    
    if(st >= l && ed <= r)
        return tree[nd];
    else if(l > mid)
        return quary(2*nd+1,mid+1,ed,l,r);
    else if(r <= mid)
        return quary(2*nd,st,mid,l,r);
    else
        return quary(2*nd,st,mid,l,r) + quary(2*nd+1,mid+1,ed,l,r);
}
    
int main()
{
    int n;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]), v.push_back({a[i],i});

    sort(v.begin(),v.end());
    
    int q;
    scanf("%d",&q);

    //cout << "yo\n";
    
    for(int i=0;i<q;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);

        p[i].second = make_tuple(x,y,i);
        p[i].first = z;
    }

    sort(p,p+q);

    // for(int i=0;i<q;i++)
    //     cout << p[i].first << " ";
    // cout << endl;

    for(int i=q-1;i>=0;i--)
    {
        while(!v.empty() && v.back().first > p[i].first)
            update(1,0,n-1,v.back().second), v.pop_back();

        ans[get<2>(p[i].second)] = quary(1,0,n-1,get<0>(p[i].second)-1,get<1>(p[i].second)-1);
    }

    for(int i=0;i<q;i++)
        cout << ans[i] << "\n";
    cout << endl;
} 