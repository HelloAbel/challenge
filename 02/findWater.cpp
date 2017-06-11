//寻找连通的水坑数量
#include <iostream>
#include <vector>

using namespace std;

void dfs(int x, int y, vector<vector<char>> &vvc)
{
  auto lx = vvc.size();
  auto ly = vvc[0].size();
  
  vvc[x][y] = '.';

  for(int i=-1; i!=2; ++i) {
	for(int j=-1; j!=2; ++j) {
	  int nx = x+i, ny = y+j;
	  if(nx>=0 && nx<lx && ny>=0 && ny<ly && vvc[nx][ny]=='w')
		dfs(nx, ny, vvc);
	}
  }
}

int solve(vector<vector<char>> &vvc)
{/*
    auto iter1=vvc.begin();
    auto iter2 = iter1->begin();
    for(; iter1!=vvc.end(); ++iter1) {
        iter2 = iter1->begin();
        for(; iter2!=iter1->end(); ++iter2) {
            if(*iter2=='w')
                break;
        }
        if(iter2!=iter1->end())
            break;
    }
 */
  auto high = vvc.size();  //庭院长度
  auto len = vvc[0].size();//庭院宽度
  int res = 0;
  
  for(auto i=0; i!=high; ++i) {
	for(auto j=0; j!=len; ++j) {
	  if(vvc[i][j]=='w') {
		dfs(i, j, vvc);
		++res;
	  }
	}
  }

  return res;
}

int findWater(vector<vector<char>> &b)
{
    vector<vector<char>> vvc(b);
    return solve(vvc);
}

int main()
{
    unsigned num = 0;
    vector<vector<char>> board;
    typedef decltype(board.size()) scapeType;
    scapeType len, breadth;
    char ele;

    cout << "请输入地板长度： " << endl;
    cin >> len;
    cout << "请输入地板宽度: " << endl;
    cin >> breadth;
    cout << "请输入地板积水情况： " << endl;
    for(auto l=0; l!=len; ++l) {
        vector<char> line;
        for(auto b=0; b!=breadth; ++b) {
            cin >> ele;
            if(ele=='\n')
                break;
            line.push_back(ele);
        }
        board.push_back(line);
    }
    cout << "总共有" << findWater(board) << "滩水" << endl;

    return 0;
}
