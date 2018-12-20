#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL)

typedef tree <
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update
> sset;
    
int a[100010];
int answers[100500];
int BLOCK_SIZE;

pair<tuple <int,int,int>, int> queries[100500];

inline bool mo_cmp(const pair<tuple <int,int,int>, int> &x, const pair<tuple <int,int,int>, int> &y)
{
    int block_x = get<0>(x.first) / BLOCK_SIZE;
    int block_y = get<0>(y.first) / BLOCK_SIZE;
    if(block_x != block_y)
        return block_x < block_y;
    return get<1>(x.first) < get<1>(y.first);
}
    
int32_t main()
{
    fastIO;

    int n,q;
    cin >> n >> q;

    BLOCK_SIZE = static_cast<int>(sqrt(n));
    
    for(int i=0;i<n;i++)
        cin >> a[i];
    
    for(int i = 0; i < q; i++) 
    {
        int x,y,z;
        cin >> x >> y >> z;
        queries[i].first = make_tuple(x-1,y-1,z-1);
        queries[i].second = i;
    }

    sort(queries, queries + q, mo_cmp);
    int mo_left = 0, mo_right = -1;
    sset s;

    for(int i = 0; i < q; i++) 
    {
        int left = get<0>(queries[i].first);
        int right = get<1>(queries[i].first);

        while(mo_right < right) 
        {
            mo_right++;
            s.insert(a[mo_right]);
        }

        while(mo_right > right) 
        {
            s.erase(a[mo_right]);
            mo_right--;
        }

        while(mo_left < left) 
        {
            s.erase(a[mo_left]);
            mo_left++;
        }

        while(mo_left > left) 
        {
            mo_left--;
            s.insert(a[mo_left]);
        }

        answers[queries[i].second] = *s.find_by_order(get<2>(queries[i].first));
    }

    for(int i = 0; i < q; i++)
        cout << answers[i] << "\n";
    return 0;
} 