#include<stdio.h>
#define BUFSIZE 100000000
char buf[BUFSIZE],*pt=buf;
#define scan(t)\
{\
	t=0;\
	while(*pt<'0'||*pt>'9')\
		 pt++;\
	while(*pt>='0'&&*pt<='9')\
		t=t*10+(*pt++)-'0';\
}
int c[2000020];
int l[2000020];
int p[2000020];
int h[2000020];
int a[2000020][2];
int z[2000020];
int x,n,m,u;
void R(int x,int y)
{
	for(u+=y;x<=n;x+=x&-x)
		c[x]+=y;
}
int G(int x)
{
	int re=0;
	for(;x;x-=x&-x)
		re+=c[x];
	return re;
}
int main()
{
	fread(buf,1,BUFSIZE,stdin);
	scan(n)scan(m)scan(m)
	for(int i=1;i<=n;i++)
	{
		scan(x)
		p[i]=l[x];
		l[x]=i;
	}
	for(int i=1;i<=m;i++)
	{
		scan(a[i][1])
		scan(x)
		a[i][0]=h[x];
		h[x]=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(p[p[i]])
			R(p[p[i]],-1);
		if(p[i])
			R(p[i],1);
		for(int j=h[i];j;j=a[j][0])
			z[j]=u-G(a[j][1]-1);
	}
	for(int i=1;i<=m;i++)
		printf("%d\n",z[i]);
	return 0;
}