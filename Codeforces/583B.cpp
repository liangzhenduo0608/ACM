#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	int n,c[1001],i,j,ans;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++)
			scanf("%d",&c[i]);
		for(i=j=ans=0;;i+=(ans%2?-1:1)){
			if(c[i]<=j) c[i]=n,j++;
			if(j==n) break;
			if(i==n-1||(ans>0&&i==0)) ans++;
		}
		printf("%d\n",ans);
	}
}