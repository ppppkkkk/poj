#include <stdio.h>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

/*

有很多房间，编号为 0、1、2、3，...。
沿着一个通道，穿过这些大房间，并把房门关上。
能否找到一条路径经过所有开着门的房间，
并使得： 1) 通过门后立即把门关上； 2) 关上了的门不再打开； 
3) 后回到你自己的房间（房间 0），并且所有的门都已经关闭了。 
在本题中，给定房间列表，及连通房间的、开着的门，并给定一个起始房间，判断是否存在 这样的一条路径。
不需要输出这样的路径，只需判断是否存在。假定任意两个房间之间都是连通的（可能需要经过其他房间）。


无向图存在欧拉通路的充要条件：

  1. 是连通图

  2. 奇度节点个数为0或2,其中为0时为欧拉回路,为2时是以这两个点节点为端点的欧拉通路

*/


int M, N, door[20];
string sh;
char sh1[789];
int main()
{
    while (cin >> sh)
    {
        if (sh == "ENDOFINPUT")
            break;
        cin >> M >> N;
        getchar();
        int cnt = 0;
        memset(door, 0, sizeof(door));
        for (int i = 0; i < N; i++)
        {
            gets(sh1);
            int len = strlen(sh1);
            for (int j = 0; j < len; j++)
            {
                if (sh1[j] != ' ')
                {
                    int d = sh1[j] - '0';
                    cnt++;
                    door[i] ++;
                    door[d] ++;
                }
            }
        }
        cin >> sh;
        int odd = 0, even = 0;
        for (int i = 0; i < N; i++)
        {
            if (door[i] % 2) odd++;
            else even++;
        }
        if (odd == 0 && M == 0)
            cout << "YES " << cnt << endl;
        else if (odd == 2 && M != 0)
            cout << "YES " << cnt << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
