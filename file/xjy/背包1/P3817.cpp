#include<bits/stdc++.h>
using namespace std;
int a[100005]={0};
int main(){
	int n,t;
	cin>>n>>t;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans=0;
	for (int i=2;i<=n;i++){
		if (a[i-1]+a[i]>t){
			int cnt=a[i-1]+a[i]-t;
			ans+=cnt;
			if (cnt<=a[i]){
				a[i]-=cnt;
			}else{
				cnt-=a[i];
				a[i]=0;
				a[i-1]-cnt;
			}
		}
	}
	cout<<ans<<'\n';
	
} 
