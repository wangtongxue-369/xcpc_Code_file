#include<bits/stdc++.h>
using namespace std;
int a[55]={0};
int main(){
	int n,t;
	cin>>n>>t;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=max(0,a[i]-a[i-1]);
	}
	cout<<ans<<'\n';
	
} 
