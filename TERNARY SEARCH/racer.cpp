#include <bits/stdc++.h>
using namespace std;
 
#define pr pair<int, int>
#define ll long long
#define pb push_back
#define f first
#define s second
const int dim=1e6; 
const ll inf=1e18;
const int nd=301;
vector<pr> d;
int n, T; 

double cal(double m){
	double nmin=1e18; double nmax=-1e18;
	for (int i=0; i<n; i++){
		double temp=d[i].f*m+d[i].s; 
		nmin=min(nmin, temp); nmax=max(nmax, temp);
	}
	
	return nmax-nmin;
}

int main(){
	cin>>n>>T;
	d.resize(n);
	for (int i=0; i<n; i++){
		cin>>d[i].f>>d[i].s; // 1=s, 2=d;
	}
	
	double lft=0; double rht=T;
	while(rht-lft>1e-8){
		double m1=lft+(rht-lft)*1.0L/3.0L;
		double m2=lft+(rht-lft)*2.0L/3.0L;
		
		double v1=cal(m1); 
		double v2=cal(m2); 
		
		if(v2>v1) rht=m2; 
		else lft=m1; 
		//cout<<" lft/rht= "<<lft<<" "<<rht<<endl;
	}
	//cout<<fixed<<setprecision(6)<<" lft= "<<lft<<endl;
	cout<< fixed<<setprecision(6)<<cal(lft)<<endl;
	
}