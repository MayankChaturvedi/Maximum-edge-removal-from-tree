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
int graph::dfs2(int x,bool b[]){
        int index=1;
        b[x]=1;
        for(auto p= g[x].begin();p!=g[x].end();++p){
                if(b[*p]==0){
                    index+=(dfs(*p,b));
                }
        }
        b[x]=0;
        return index;
}
int graph::explore(int m){
        explored[m]=1;
        int exp=-1;
        for(auto p= g[m].begin();p!=g[m].end();++p){
                    if(explored[*p]==1){
                            exp=*p;
                            //cout<<"\nexp"<<exp<<"\n";
                            break;
                    }
        }
        if(exp!=-1){
                //cout<<"\narr[m]"<<arr[m]<<"n"<<n<<"\n";
                arr[exp]=num-arr[m];//NOT n- arr[m] instead, graph size
        }
        int odd=0;
        for(auto p= g[m].begin();p!=g[m].end();++p){
                    if(arr[*p]%2==0){
                                int val=*p;
                                arr[m]-=arr[*p];
                                num-=arr[*p];
                                ++(*count);
                                auto it=p;
                                --it;
                                g[m].erase(p);
                                g[val].remove(m);
                                p=it;
                    }
                    else{++odd;}
        }
        if(odd%2==0){cout<<"-1";return 0;}
        return 1;
}
int graph::dfs(int x){
        //cout<<"\n"<<x<<"\n";
        //loop(n){cout<<arr[i]<<" ";}
        int t=explore(x);
        //printf("\n for x= %d t= %d \n", x,t);
        if(t==0){return 0;}

        for(auto p= g[x].begin();p!=g[x].end();++p){
                if(explored[*p]==0){
                    t=dfs(*p);
                    if(t==0){return 0;}
                }
        }
        return 1;
}
int graph::ini_dfs(){
        bool b[n];
        loop(n){b[i]=0;}
        dfs(0,b);
        loop(n){
                if(explored[i]==0){
                    num=dfs2(i,b);
                    int t=dfs(i);if(t==0){return 0;}}
        }
        return 1;
}
