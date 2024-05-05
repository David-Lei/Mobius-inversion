#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<cstdlib>
#define MAXN 0x7fffffff
typedef long long LL;
const int N=10000005;
using namespace std;
inline int Getint(){register int x=0,f=1;register char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}return x*f;}
LL mu[N],vis[N],prime[N],sum[N];
int main(){
	mu[1]=1;
	for(int i=2;i<N;i++){
		if(!vis[i])prime[++prime[0]]=i,mu[i]=-1;
		for(int j=1;j<=prime[0]&&i*prime[j]<N;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)break;
			mu[i*prime[j]]=-mu[i];
		}
	}
	for(int j=1;j<=prime[0];j++)
		for(int i=1;i*prime[j]<N;i++)
			sum[i*prime[j]]+=mu[i];
	for(int i=2;i<N;i++)sum[i]+=sum[i-1];
	int T=Getint();
	while(T--){
		int n=Getint(),m=Getint();
		if(n>m)swap(n,m);
		LL ans=0,last=0;
		for(int i=1;i<=n;i=last+1){
			last=min(n/(n/i),m/(m/i));
			ans+=(sum[last]-sum[i-1])*(n/i)*(m/i);
		}
		cout<<ans<<'\n';		
	}
	return 0;
}

