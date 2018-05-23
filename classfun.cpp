#include "head.h"
graph::graph(int v){
        n=v;
        g=new list<int>[n];
        explored=new bool[n]();
        arr=new int[n]();
        count=new int;*count=0;
}
void graph::addedge(int x, int y){
    g[x-1].pb(y-1);
    g[y-1].pb(x-1);
}
int graph::dfs(int x,bool b[]){
        int index=1;
        b[x]=1;
        for(auto p= g[x].begin();p!=g[x].end();++p){
                if(b[*p]==0){
                    index+=(dfs(*p,b));
                }
        }
        arr[x]=index;
        b[x]=0;
        return index;
}
//=================|Preprodcessed|========================in arr//
int graph::explore(int x, int elements){
        explored[x]=1;
        int alex=-1;
        for(auto p= g[x].begin();p!=g[x].end();++p){
                if(explored[*p]==1){
                    alex=*p;
                }
        }
        if(alex!=-1){
                arr[alex]=elements-arr[x];
                arr[x]=elements;
        }
        int odd=0;
        for(auto p=g[x].begin();p!=g[x].end();++p){
                int tnum=arr[*p];
                int ele=*p;
                if(tnum%2==0){
                        ++(*count);
                        elements-=tnum;
                        arr[x]=elements;
                        auto it=p;
                        --it;
                        g[x].erase(p);
                        g[ele].remove(x);
                        int y=dfs(ele,tnum);
                        if(y==0){return 0;}
                        p=it;
                }

                else{++odd;}
        }
        if(odd%2==0){return 0;}
        return elements;
}
int graph::dfs(int x, int elements){
        elements=explore(x,elements);
        if(elements==0){return 0;}
        for(auto p= g[x].begin();p!=g[x].end();++p){
                if(explored[*p]==0){
                    elements=dfs(*p,elements);
                    if(elements==0){return 0;}
                }
        }
        return elements;
}
int graph::ini_dfs(){
        bool b[n];
        loop(n){b[i]=0;}
        dfs(0,b);//arr build
        int k=dfs(0,n);
        if(k==0){return 0;}
        return 1;
}