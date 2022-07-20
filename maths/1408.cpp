//有一个1*1的正方形，分别给出下，上，左，右边每个边上的n个点，对边对应点连线，问这些线段相交的最大的四边形面积是多少（面积最大的定义是必须当前面积内没有更小的四边形内含）。

//1、我们可以用一个矩阵来保存所有的点，四边上每个点是输入的，内部的每个点通过线段交点的计算可以计算出来。

//2、然后枚举任意i-1,i,j-1,j四个点计算四边形的面积，求最大值。在计算四边形面积的时候四边形可以转换成两个三角形来计算，这两个三角形的面积是通过向量的叉积来计算的。两个向量的叉积可以算出以这两个向量为邻边的四边形的面积，注意除以2.
#include <stdio.h>
#include <string.h>
#include <iostream>
#define  N 34
using namespace std;

struct node
{
    double x , y ;
}p[N][N] ;

int n ;
//叉积求交点
struct node point ( struct node p1 , struct node p2 , struct node p3 , struct node p4 )
{
    struct node td ;
    double A1=p2.y-p1.y;
    double B1=p1.x-p2.x;
    double C1=p1.y*(p2.x-p1.x)-p1.x*(p2.y-p1.y);
    double A2=p4.y-p3.y;
    double B2=p3.x-p4.x;
    double C2=p3.y*(p4.x-p3.x)-p3.x*(p4.y-p3.y);
    td.x=(C2*B1-C1*B2)/(A1*B2-A2*B1);
    td.y=(C2*A1-C1*A2)/(B1*A2-B2*A1);
    return td ;
}
//计算面积
double area ( struct node p1 , struct node p2 , struct node p3 , struct node p4 )
{
    int i , j ;
    struct node are[4] ;
    are[0] = p1 ;
    are[1] = p2 ;
    are[2] = p3 ;
    are[3] = p4 ;

    double sum = 0.0 ;
    for ( i = 0 ; i < 4 ; i++ )
    {
        j = ( i + 1 ) % 4 ;
        sum += are[i].x * are[j].y - are[i].y * are[j].x ;
    }
    sum /= 2 ;
    if ( sum < 0 )
    sum = -sum ;
    return sum ;
}

int main()
{
    int i , j , k ;

    while ( scanf ( "%d" , &n) , n )
    {
        //给四个角赋值
        p[0][0].x = 0.0 ;p[0][0].y = 0.0 ;
        p[0][n+1].x = 0.0 ; p[0][n+1].y = 1.0 ;
        p[n+1][n+1].x = 1.0 ; p[n+1][n+1].y = 1.0 ;
        p[n+1][0].x = 1.0 ; p[n+1][0].y = 0.0 ;
        //输入四条边上的点
        for ( i = 1 ; i <= n ; i++ )
        {
            scanf ( "%lf" , &p[i][0].x) ;
            p[i][0].y = 0.0 ;
        }
        for ( i = 1 ; i <= n ; i++ )
        {
            scanf ( "%lf" , &p[i][n+1].x) ;
            p[i][n+1].y = 1.0 ;
        }
        for ( i = 1 ; i <= n ; i++ )
        {
            scanf ( "%lf" , &p[0][i].y) ;
            p[0][i].x = 0.0 ;
        }
        for ( i = 1 ; i <= n ; i++ )
        {
            scanf ( "%lf" , &p[n+1][i].y) ;
            p[n+1][i].x = 1.0 ;
        }
        //求出其他点
        for ( i = 1 ; i <= n ; i++ )
        {
            for ( j = 1 ; j <= n ; j++ )
            p[i][j] = point ( p[i][0] , p[i][n+1] , p[0][j] , p[n+1][j] ) ;
        }
        /*for ( i = n+1 ; i >= 0 ; i-- )
        {
            for ( j =0 ; j <= n+1 ; j++ )
            printf ( "(%lf %lf)" , p[j][i].x , p[j][i].y );
            printf ( "\n" );
        }*/
        //求出最大面积
        double maxx = -1.0 ;
        for ( i = 0 ; i < n + 1 ; i++ )
        {
            for ( j = 0 ; j < n + 1 ; j++ )
            {
                double sum = area( p[i][j] , p[i+1][j] , p[i+1][j+1] , p[i][j+1] ) ;
                if ( sum > maxx )
                maxx = sum ;
            }
        }
        printf ( "%.6lf\n" , maxx );
    }
    return 0 ;
}
