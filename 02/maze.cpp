//利用宽度优先搜索找出迷宫的最短路径
#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <stack>
#include <unistd.h>

using namespace std;

typedef vector<pair<int, int>> TraceType;

void solveMaze(vector<vector<char>> &maze, TraceType &trace)
{
    int bx, by;
    int ex, ey;
    int cur = 1, next = 0, len = 0, level = 0;
    queue<pair<int, int>> check;
    stack<pair<int, int>> backTrack;
    vector<pair<int, int>> dirv;
    
    dirv.push_back(make_pair(0, 1));
    dirv.push_back(make_pair(1, 0));
    dirv.push_back(make_pair(-1, 0));
    dirv.push_back(make_pair(0, -1));

    for(auto i=0; i!=maze.size(); ++i) {
        for(auto j=0; j!=maze[0].size(); ++j) {
            if(maze[i][j]=='S') {
                bx = i;
                by = j;
                continue;
            }
            if(maze[i][j]=='G') {
                ex = i;
                ey = j;
            }
        }
    }

//    cout << "bx = " << bx << ", by = " << by << endl;
//    cout << "ex = " << ex << ", ey = " << ey << endl;
    check.push(make_pair(bx, by));
    ++next;
    while(!check.empty()) {
//        cout << "Enter loop..." << endl;
        auto curEle = check.front();
        check.pop();
//        cout << "(" << curEle.first << " " << curEle.second << ")" << endl;
        if(curEle.first==ex && curEle.second==ey)
            break;
        --cur;
        if(cur==0) {
            ++level;
            cur = next;
            next = 0;
        }


        for(auto ele : dirv) {
            int tx = curEle.first+ele.first, ty = curEle.second+ele.second;
            if(tx>=0 && tx<maze.size() && 
                ty>=0 && ty<maze[0].size() &&
                maze[tx][ty]=='.') {
                    maze[tx][ty] = '+';
                    check.push(make_pair(tx, ty));
                    ++next;
                }
        }
    } 
    
    if (check.empty()) {
        cout << "No Trace!" << endl;
        return;
    }
 /*   
    for (auto row : maze) {
        for (auto ele : row) {
            cout << ele;
        }
        cout << endl;
    } */
    

    cout << "最短长度为： " << level << endl;
}

int main()
{
    vector<vector<char>> maze;
    int len, breadth;
    TraceType trace;
	char ele;

    cout << "请输入迷宫长度: " << endl;
    cin >> len;
    cout << "请输入迷宫宽度: " << endl;
    cin >> breadth;
    cout << "请输入迷宫地图: " << endl;
    for(auto l=0; l!=len; ++l) {
        vector<char> line;
        for(auto b=0; b!=breadth; ++b) {
            cin >> ele;
            if(ele=='\n')
                break;
            line.push_back(ele);
        }
        maze.push_back(line);
    }

    solveMaze(maze, trace);
/*
    cout << "迷宫的最短路径为：" << endl;
    for(auto b : trace) {
        cout << "(" << b.first << "," << b.second << ") -> ";
    }
    cout << endl;
*/
    return 0;
}
