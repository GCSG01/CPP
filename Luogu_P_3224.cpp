#include<bits/stdc++.h>
#define int long long
const int N=1e5+5;
using namespace std;
struct node{
    int l,r,v;
}tree[N];
int top;
int a[N],fa[N];
int root[N];
int n,m;
int find(int x)
{return fa[x]==x?fa[x]:fa[x]=find(fa[x]);}
void build(int &p,int l,int r,int k)
{
    p=++top;
    tree[p].v=1;
    if(l==r)return ;
    int mid=(l+r)>>1;
    if(k<=mid)build(tree[p].l,l,mid,k);
    else build(tree[p].r,mid+1,r,k);    
    return ;
}
int merge(int x,int y,int l,int r)
{
    if(!x||!y)return x+y;
    int rot=++top;
    tree[rot].v=tree[x].v+tree[y].v;
    int mid=(l+r)>>1;
    tree[rot].l=merge(tree[x].l,tree[y].l,l,mid);
    tree[rot].r=merge(tree[x].r,tree[y].r,mid+1,r);
    return rot;
}
int get(int x,int l,int r,int k)
{
    if(tree[x].v<k)return -1;
    if(l==r)return a[l];
    int mid=(l+r)>>1,s=tree[tree[x].l].v;
    if(k<=s)return get(tree[x].l,l,mid,k);
    else return get(tree[x].r,mid+1,r,k-s);
}
signed main()
{
    // freopen("xx.in","r",stdin);
    // freopen("xx.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1,x;i<=n;i++)cin>>x,build(root[i],1,n,x),a[x]=i;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        int fau=find(u),fav=find(v);
        if(fau!=fav)
        {
            fa[fau]=fav;
            root[fav]=merge(root[fau],root[fav],1,n);
        }
    }
    int q;cin>>q;
    while(q--)
    {
        char op;
        int x,y;
        cin>>op>>x>>y;
        if(op=='Q')cout<<get(root[find(x)],1,n,y)<<"\n";
        else
        {
            int fax=find(x),fay=find(y);
            if(fax!=fay)
            {
                fa[fax]=fay;
                root[fay]=merge(root[fax],root[fay],1,n);
            }
        }
    }
    return 0;
}