#include<bits/stdc++.h>
#define int long long
const int N=5e6+5;
using namespace std;
struct ZX_Tree{
    struct node{
        int l,r,v;
    };
    node a[N];
    int rot[N];
    int top;
    void build(int &p,int l,int r)
    {
        p=++top;
        if(l==r)return ;
        int mid=(l+r)>>1;
        build(a[p].l,l,mid);
        build(a[p].r,mid+1,r);
        return ;
    }
    void update(int x,int &y,int l,int r,int v)
    {
        y=++top;
        a[y]=a[x];
        if(l==r)return a[y].v++,void();
        int mid=(l+r)>>1;
        if(v<=mid)update(a[x].l,a[y].l,l,mid,v);
        else update(a[x].r,a[y].r,mid+1,r,v);
        a[y].v=a[ a[y].l].v+a[a[y].r].v;
        return ;
    }
    int get(int x,int y,int l,int r,int k)
    {
        if(l==r)return l;
        int mid=(l+r)>>1,s=a[a[y].l].v-a[a[x].l].v;
        if(k<=s)return get(a[x].l,a[y].l,l,mid,k);
        else return get(a[x].r,a[y].r,mid+1,r,k-s);
    }
}tr;
int n,m;
int a[N],b[N];
signed main()
{
    // freopen("xx.in","r",stdin);
    // freopen("xx.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i],b[i]=a[i];
    sort(b+1,b+n+1);
    int nn=unique(b+1,b+n+1)-b-1;
    tr.build(tr.rot[0],1,nn);
    for(int i=1;i<=n;i++)
        a[i]=lower_bound(b+1,b+nn+1,a[i])-b,
        // cout<<a[i]<<" "<<"\n",
        tr.update(tr.rot[i-1],tr.rot[i],1,nn,a[i]);
    while(m--)
    {
        int l,r,k;
        cin>>l>>r>>k;
        cout<<b[tr.get(tr.rot[l-1],tr.rot[r],1,nn,k)]<<"\n";
    }
    return 0;
}