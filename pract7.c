#include <stdio.h>

#define V 5

int isSafe(int v, int g[V][V], int path[], int pos){
    for(int i=0;i<pos;i++) if(path[i]==v) return 0;
    return g[path[pos-1]][v];
}

int hamCycleUtil(int g[V][V], int path[], int pos){
    if(pos==V) return g[path[pos-1]][path[0]];
    for(int v=1;v<V;v++){
        if(isSafe(v,g,path,pos)){
            path[pos]=v;
            if(hamCycleUtil(g,path,pos+1)) return 1;
            path[pos]=-1;
        }
    }
    return 0;
}

void hamCycle(int g[V][V]){
    int path[V];
    for(int i=0;i<V;i++) path[i]=-1;
    path[0]=0;
    if(hamCycleUtil(g,path,1)){
        for(int i=0;i<V;i++) printf("%c -> ",'A'+path[i]);
        printf("%c\n",'A'+path[0]);
    } else printf("No Hamiltonian Cycle exists\n");
}

int main(){
    int g[V][V]={{0,1,1,0,1},{1,0,1,1,0},{1,1,0,1,0},{0,1,1,0,1},{1,0,0,1,0}};
    hamCycle(g);
    return 0;
}
