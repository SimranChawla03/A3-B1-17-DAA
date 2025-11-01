#include <stdio.h>

#define V 5  // Number of vertices
#define M 3  // Number of colors

int isSafe(int v, int g[V][V], int color[], int c){
    for(int i=0;i<V;i++)
        if(g[v][i] && color[i]==c) return 0;
    return 1;
}

int graphColoringUtil(int g[V][V], int color[], int v){
    if(v==V) return 1;
    for(int c=1;c<=M;c++){
        if(isSafe(v,g,color,c)){
            color[v]=c;
            if(graphColoringUtil(g,color,v+1)) return 1;
            color[v]=0;
        }
    }
    return 0;
}

void graphColoring(int g[V][V]){
    int color[V]={0};
    if(graphColoringUtil(g,color,0)){
        printf("Coloring of vertices:\n");
        for(int i=0;i<V;i++) printf("Vertex %d -> Color %d\n",i+1,color[i]);
    } else printf("No coloring possible with %d colors\n",M);
}

int main(){
    int g[V][V]={
        {0,1,1,0,1},
        {1,0,1,1,0},
        {1,1,0,1,1},
        {0,1,1,0,1},
        {1,0,1,1,0}
    };
    graphColoring(g);
    return 0;
}
