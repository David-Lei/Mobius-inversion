#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<cstdlib>
#define MAXN 0x7fffffff
typedef long long LL;
const int N=50005;
using namespace std;
inline int Getint(){register int x=0,f=1;register char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}return x*f;}
int mu[N],vis[N],prime[N];
void Pre(){
	mu[1]=1;
	for(int i=2;i<N;i++){
		if(!vis[i])prime[++prime[0]]=i,mu[i]=-1;
		for(int j=1;j<=prime[0]&&i*prime[j]<N;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)break;
			mu[i*prime[j]]=-mu[i];
		}
		mu[i]+=mu[i-1];
	}
}
int Cal(int n,int m){
	int ret=0;
	for(int l=1,r=0;l<=n;l=r+1){
		r=min(n/(n/l),m/(m/l));
		ret+=(mu[r]-mu[l-1])*(n/l)*(m/l);
	}
	return ret;
}
int main(){
	Pre();
	int T=Getint();
	while(T--){
		int n=Getint(),m=Getint(),d=Getint();
		if(n>m)swap(n,m);
		int ans=Cal(n/d,m/d);
		cout<<ans<<'\n';
	}
	return 0;
}

