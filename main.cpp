#include "head.h"
int main(){
        /*graph gr(4);
        gr.addedge(2,4);
        gr.addedge(4,1);
        gr.addedge(3,1);*/
        int n;
        cin>>n;
        graph gr(n);
        loop(n-1){
                int a,b;
                cin>>a>>b;
                gr.addedge(a,b);
        }
        int ind=gr.ini_dfs();
        if(ind==0){return 0;}
        else{cout<<*(gr.count);}
}
