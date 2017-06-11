//寻找可以凑出和的数字组合
#include <iostream>
#include <vector>

using namespace std;

int S;

bool findSum(int sum, vector<int> &vi, vector<int> &res, int i)
{
    
    if(i==vi.size()) {
//        cout << i << "\t" << sum << endl;
        return sum==S;
    }
  
    if(findSum(sum, vi, res, i+1)) {
 /*       if(i!=(vi.size()-1))
            res.push_back(vi[i+1]);*/
        return true;
    }
        
    if(findSum(sum+vi[i], vi, res, i+1)) {
        res.push_back(vi[i]);
        return true;
    }

    return false;
}

int main()
{
    int num, i=0, tmp, sum;
    vector<int> vi, res;

    cout << "请输入要求的和：";
    cin >> S;
    cout << "请输入数目：";
    cin >> num;

    while(i!=num) {
        cin >> tmp;
        vi.push_back(tmp);
        ++i;
    }

    auto have = findSum(0, vi, res, 0);
    if(!have)
        cout << "没有可以组成和的组合" << endl;
    else {
        auto b = res.begin();
        cout << S << " = ";
        for(; b!=(res.end()-1); ++b) {
            cout << *b << " + ";
        }
        cout << *b << endl;
    }

    return 0;
}