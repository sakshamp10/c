#include <stdio.h>
#include <stdlib.h>

typedef long long ll;
typedef struct graph g;

struct graph{
    ll data;
    g* next;
};

ll visited[100000]={0};
ll queue[250000]={0};

// void bfs(node** a,ll i){
//     if(start>end){
//         end++;
//     }
//     queue[start]=i;
//     visited[i]=1;
//     while(start<=end){
//         node* t=a[queue[start]];
//         while(t!=NULL){
//             if(visited[t->val]==0){
//                 queue[++end]=t->val;
//                 visited[t->val]=1;
//             }
//             t=t->next;
//         }
//         start++;
//     }
// }

void dfs(g** grap, ll d){
    g* temp=grap[d]->next;
    while(temp!=NULL){
        if(visited[temp->data]!=1){
            visited[temp->data]=1;
            dfs(grap,temp->data);
        }
        temp=temp->next;
    }
}


void insert(g** grap,ll u, ll v){
    g* node=(g*)malloc(sizeof(g));
    node->data=v;
    node->next=NULL;
    g* temp=grap[u];
    while(temp->next!=NULL){
        temp=temp->next;
        if(temp->data==v){
            return;
        }
    }
    temp->next=node;
    return;
}

int main(){
    ll n,m;
    scanf("%lld",&n);
    scanf("%lld",&m);
    g** grap = (g**)malloc((n+1)*sizeof(g*));
    for(ll i=0;i<=n;i++){
        grap[i]=(g*)malloc(sizeof(g));
        grap[i]->data=i;
        grap[i]->next=NULL;
    }
    ll u,v;
    for(ll i=0;i<m;i++){
        scanf("%lld %lld",&u,&v);
        insert(grap,u,v);
        insert(grap,v,u);
    }
    
    ll comp=0;
    for(ll i=0;i<n;i++){
        if(!visited[i]){
            dfs(grap,i);
            comp++;
        }
    }
    printf("%lld",comp);
    return 0;
}
