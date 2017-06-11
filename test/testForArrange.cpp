//测试c++11中的范围内循环
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main()
{
  auto a1 = make_pair(-1, 0);
  auto a2 = make_pair(1, 0);
  auto a3 = make_pair(0, -1);
  auto a4 = make_pair(0, 1);
  vector<pair<int, int>> vpi;

  vpi.push_back(a1);
  vpi.push_back(a2);
  vpi.push_back(a3);
  vpi.push_back(a4);

  for(auto ele : vpi)
	cout << "(" << ele.first << "," << ele.second << ")" << endl;
  
  return 0;
}
