#include<iostream>
#include<unordered_set>
#include<unordered_map>

using namespace std;

int a[1000000+5];

unordered_set<char> c;

unordered_map<char, int> d;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    for (auto i:s)
    {
        c.insert(i);
    }
    int l=0;
    int r=-1;
    int ans=n;
    while (l<n)
    {
        if (d.size()==c.size())
        {
            ans=min(ans,r-l+1);
            d[s[l]]--;
            if (d[s[l]]==0) d.erase(s[l]);
            l++;
            continue;
        }
        if (r!=n-1)
        {
            r++;
            d[s[r]]++;
        }
        else
        {
            break;
        }
    }
    cout<<ans;
}