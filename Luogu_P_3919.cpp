#include<bits/stdc++.h>
#define int long long
const int N=5e7+5;
using namespace std;
int n,m;
struct ZX_Tree{
    struct node{
        int l,r,v;
    };
    node a[N];
    int rot[N];
    int top;
    int build(int p,int l=1,int r=n)
    {
        p=++top;
        if(l==r)
        {
            cin>>a[p].v;
            return p;
        }
        int mid=(l+r)>>1;
        a[p].l=build(a[p].l,l,mid);
        a[p].r=build(a[p].r,mid+1,r);
        return p;
    }
	int add(int p)
	{
		a[++top]=a[p];
		return top;
	}
    int update(int x,int v,int p,int l=1,int r=n)
    {
        p=add(p);
        if(l==r)return a[p].v=v,p;
        int mid=(l+r)>>1;
        if(x<=mid)a[p].l=update(x,v,a[p].l,l,mid);
        else a[p].r=update(x,v,a[p].r,mid+1,r);
        return p;
    }
    int get(int x,int p,int l=1,int r=n)
    {
        if(l==r)return a[p].v;
        int mid=(l+r)>>1;
        if(x<=mid)return get(x,a[p].l,l,mid);
        else return get(x,a[p].r,mid+1,r);
    }
}tr;
signed main()
{
    // freopen("xx.in","r",stdin);
    // freopen("xx.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    tr.rot[0]=tr.build(0);
    for(int t=1;t<=m;t++)
    {
        int v,op,p,c;
        cin>>v>>op>>p;
        if(op==1)
        {
            cin>>c;
            tr.rot[t]=tr.update(p,c,tr.rot[v]);
        }
        else
        {
            cout<<tr.get(p,tr.rot[v])<<"\n";
            tr.rot[t]=tr.rot[v];
        }
    }
    return 0;
}