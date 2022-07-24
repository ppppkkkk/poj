#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int maxn=105;
const double PI=acos(-1.0);

struct Point{
    int x,y;
    Point():x(0),y(0){}
    Point(int x,int y):x(x),y(y){}
}list[maxn];
int stack[maxn],top;

//计算叉积p0p1×p0p2
int cross(Point p0,Point p1,Point p2){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
//计算p1p2的距离
double dis(Point p1,Point p2){
    return sqrt((double)(p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));
}
//极角排序函数，角度相同则距离小的在前面
bool cmp(Point p1,Point p2){
    int tmp=cross(list[0],p1,p2);
    if(tmp>0) return true;
    else if(tmp==0&&dis(list[0],p1)<dis(list[0],p2)) return true;
    else return false;
}

int main(){
    int x,y,n=0;
    while(~scanf("%d%d",&x,&y)){
        list[n].x=x,list[n].y=y;
        ++n;
    }
    sort(list+1,list+n,cmp);
    for(int i=0;i<n;++i)
        printf("(%d,%d)\n",list[i].x,list[i].y);
    return 0;
}
