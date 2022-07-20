//一个地图上有n个小镇，以及连接着其中两个小镇的有向边，而且这些边无法形成回路。现在选择一些小镇空降士兵（1个小镇最多1个士兵），士兵能沿着边走到尽头，问最少空降几个士兵，能遍历完所有的小镇。
//最小路径覆盖数:
//对于一个DAG（有向无环图），选取最少条路径，使得每个 顶点属于且仅属于一条路径。路径长度可以为零；
//（有向图中找一些路径，使之覆盖了图中的所有顶点，就是任意一个顶点都跟那些路径中的某一条关联，且任何一个顶点有且只有一个与之关联）
//最小路径覆盖数（最少边覆盖）=顶点数-最大匹配数；
#include <iostream>
using namespace std;
#define MAXV 130
 
int map[MAXV][MAXV];
bool visit[MAXV];
int check[MAXV];
int n;
 
bool dfs(int v){
    for(int i=1;i<=n;i++){
        if(!visit[i]&&map[v][i]){   //i点不在交替路中
            visit[i] = 1;
            if(check[i]==-1||dfs(check[i])){ //该点未覆盖
                check[i] = v;
                return true;
            }
        }
    }
    return false;
}
 
int hungry(){
    int ans = 0;
    memset(check,-1,sizeof(check));
    for(int i=1;i<=n;i++){
        memset(visit,0,sizeof(visit));
        if(dfs(i))     //若找到一条增广路，匹配边＋1
            ans++;
    }
    return ans;
}
 
int main(){
    int t,m,i,a,b;
    int ans;
    cin>>t;
    while(t--){
        memset(map,0,sizeof(map));
        cin>>n>>m;
        for(i=0;i<m;i++){
            cin>>a>>b;
            map[a][b] = 1;
        }
        ans = n - hungry();
        cout<<ans<<endl;
    }
    return 0;
}
