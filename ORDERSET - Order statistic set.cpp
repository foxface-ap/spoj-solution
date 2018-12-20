#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define int long long

typedef tree <
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update
> sset;

int32_t main()
{
    fastIO;

    sset s;

    int q;
    cin >> q;

    while(q--)
    {
        char t;
        int x;
        cin >> t;
        cin >> x;

        if(t == 'I')
            s.insert(x);
        else if(t == 'D')
            s.erase(x);
        else if(t == 'K')
        {
            if(s.size() < x)
                cout << "invalid" << endl;
            else
                cout << *s.find_by_order(x-1) << endl;
        }
        else
            cout << s.order_of_key(x) << endl;

        cout << s.size() << endl;

        sset :: iterator it;
    }
}