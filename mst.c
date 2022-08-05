#include<stdio.h>
#include<stdlib.h>

typedef long long ll;

ll *id,*sz;
ll nc;
void merge(ll u[],ll v[],ll w[],ll lo,ll mid,ll hi){
    ll i=lo,j=mid+1;
    ll k=0;
    ll a[hi-lo+1],b[hi-lo+1],c[hi-lo+1];
    while(i<=mid && j<=hi){
        if(w[i]<w[j]){
            a[k]=u[i];
            b[k]=v[i];
            c[k]=w[i];
            i++;k++;
        }
        else{
            a[k]=u[j];
            b[k]=v[j];
            c[k]=w[j];
            j++;k++;
        }
    }
    while(i<=mid){
        a[k]=u[i];
        b[k]=v[i];
        c[k]=w[i];
        k++;i++;
    }
    while(j<=hi){
        a[k]=u[j];
        b[k]=v[j];
        c[k]=w[j];
        k++;j++;
    }
    for(ll l=0,p=lo;l<hi-lo+1;l++,p++){
        u[p]=b[l];
        v[p]=a[l];
        w[p]=c[l];
    }
}

void mergesort(ll u[], ll v[], ll w[], ll lo, ll hi){
    if(lo<hi){
        ll mid = (lo+hi)/2;
        mergesort(u,v,w,lo,mid);
        mergesort(u,v,w,mid+1,hi);
        merge(u,v,w,lo,mid,hi);
    }
}

void unionfind(ll size, ll n){
    id=(ll*)malloc((size+1)*sizeof(ll));
    sz=(ll*)malloc((size+1)*sizeof(ll));
    for(ll i=1;i<=size;i++){
        id[i]=i;
        sz[i]=i;
    }
    nc=n;
}


ll find(ll p){
   ll root = p;
   while(root!=id[root]){
    root=id[root];
   } 
   while(p!=root){
    ll next=id[p];
    id[p]=root;
    p=next;
   }
   return root;
}

int connected(ll p, ll q){
    if(find(p)==find(q)){
        return 1;
    }
    return 0;
}

void unify(ll p, ll q){
    ll r1=find(p);
    ll r2=find(q);

    if(r1==r2){
        return;
    }
    if(sz[r1]<sz[r2]){
        sz[r2]+=sz[r1];
        id[r1]=r2;
        nc--;
    }
    else{
        sz[r1]+=sz[r2];
        id[r2]=r1;
        nc--;
    }
}

int main(){
    ll n,m;
    scanf("%lld %lld\n",&n,&m);
    ll a[n][m];
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            scanf("%lld",&a[i][j]);
        }
    }
    ll s=4*(n-2)*(m-2)+6*(n-2)+6*(m-2)+8;
    ll v[s],u[s],w[s];
    ll p=0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(i!=0){
                v[p]=(i-1)*m+j;
                u[p]=(i*m+j);
                w[p]=a[i-1][j]+a[i][j];
                p++;
            }
            if(j!=0){
                v[p]=(i*m+j-1);
                u[p]=(i*m+j);
                w[p]=a[i][j]+a[i][j-1];
                p++;
            }
            if(j!=m-1){
                v[p]=(i*m+j+1);
                u[p]=(i*m+j);
                w[p]=a[i][j]+a[i][j+1];
                p++;
            }
            if(i!=n-1){
                v[p]=(i+1)*m+j;
                u[p]=(i*m+j);
                w[p]=a[i+1][j]+a[i][j];
                p++;
            }   
        }
    }
    mergesort(u,v,w,0,s-1);
    // for(ll i=0;i<s;i++){
    //     printf("%lld ",w[i]);
    // }
    // exit;
    unionfind(s,n*m);
    ll cost=0;
    for(ll i=0;i<s;i++){
        if(!connected(u[i],v[i])){
            unify(u[i],v[i]);
            cost+=w[i];
        }
    }
    printf("%lld",cost);
    return 0;
}