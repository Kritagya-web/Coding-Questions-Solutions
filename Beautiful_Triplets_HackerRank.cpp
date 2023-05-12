// Implemented by Kritagya Kumra
#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x) * (x)
#define sz(a) int(a.size())
#define reset(a, b) memset(a, b, sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int a[111111], n, d;
set<int> mys;

int main()
{
    //    freopen("input.txt","r",stdin);
    cin >> n >> d;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        mys.insert(a[i]);
    }
    int res = 0;
    for (int i = 2; i < n; ++i)
        if (mys.count(a[i] - d) && mys.count(a[i] + d))
            ++res;
    cout << res << endl;
}
// Implemented by Kritagya Kumra