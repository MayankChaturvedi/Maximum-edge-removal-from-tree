#include "head.h"
int main(){
        int n;
        cin>>n;
        graph gr(n);
        loop(n-1){
                int a,b;
                cin>>a>>b;
                gr.addedge(a,b);
        }
        int ind=gr.ini_dfs();
        if(ind==0){cout<<-1;return 0;}
        else{cout<<*(gr.count);}
}
