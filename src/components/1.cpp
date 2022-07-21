#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
ll n;
cin>>n;
vector<int> a(n);
vector<int> b(n);
for (ll i = 0; i < n; i++)
{
    cin>>a[i];
}
for (ll i = 0; i < n; i++)
{
    cin>>b[i];
}

vector<int> c=a;
sort(c.begin(),c.end());
vector<int> s;
vector<pair<int,int>> p;
ll ans=0;
vector<bool> visited(n,false);

for (ll i = 0; i < n; i++)
{
    for (ll j = i; j < n; j++)
    {
    if (visited[i]==false && c[i]==a[j] && i!=j)
        {
           ans++;
           swap(a[i],a[j]);
           p.push_back({j,i}) ;
           visited[i]=true;

        }
        
    }
    
}
for (ll i = 0; i < p.size(); i++)
{
    swap(b[p[i].first],b[p[i].second]);
}
for (ll i = 1; i < n; i++)
{
    if (b[i]>=b[i-1])
    {
        continue;
    }
    else
    {
        cout<<-1<<endl;
        return;
    }
    
}
cout<<ans<<endl;
for (ll i = 0; i < p.size(); i++)
{
    cout<<p[i].first+1<<" "<<p[i].second+1<<endl;
}

}
int main(int argc, char const *argv[]){
    ll t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    

    return 0;
}