class Solution {
public:
    #define fo(i, j, n) for (ll i = j; i <= n; i++)
#define rev(i, j, n) for (ll i = n; i >= j; i--)
#define print(v)                       \
    for (int i = 0; i < v.size(); i++) \
        cout << v[i] << " ";           \
    cout << endl;
#define MOD 1000000007
#define N 100000
#define mp make_pair
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define pb push_back
#define ppb pop_back
#define minpq priority_queue<int, vector<int>, greater<int>>;
#define pq priority_queue<int>;
typedef long long int ll;
#define wn(n) while (n--)
ll max(ll a , ll b){if(a > b) return a ; return b ;}
ll min(ll a , ll b){if(a < b) return a ; return b ;}
ll gcd(ll a, ll b){if(b == 0) return a; return gcd(b, a % b);}

    long long numberOfWays(string s) {
        int n=s.length();
        vector<pair<ll,ll>> left(n+2),right(n+2);
        left[0].first=0,left[0].second=0;
        right[n+1].first=right[n+1].second=0;
        for(int i=1;i<=n;i++){
            left[i].first=left[i-1].first+(s[i-1]=='1');
            left[i].second=left[i-1].second+(s[i-1]=='0');
        }
        for(int i=n;i>=1;i--){
            right[i].first=right[i+1].first+(s[i-1]=='1');
            right[i].second=right[i+1].second+(s[i-1]=='0');
        }
        ll c=0;
        for(int i=1;i<=n;i++){
            if(s[i-1]=='1'){
               
            c+=(left[i-1].second*right[i+1].second);   
            }else{
            c+=(left[i-1].first*right[i+1].first);
                
            }
        }
        return c;
    }
};