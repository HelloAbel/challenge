//抽签程序，检查是否存在满足条件的数
#include <iostream>
#include <vector>
#include <random>
#include "QuickSort.hpp"

using namespace std;

//生成N个随机数
template <typename T, unsigned N = 1000>
void generator(vector<T> &v, T min, T max)
{
	T tmp;
	static default_random_engine e;

	if(typeid(tmp)==typeid(int))
		static uniform_int_distribution<int> u(min, max); 
	if(typeid(tmp)==typeid(long))
		static uniform_int_distribution<long> u(min, max); 
	if(typeid(tmp)==typeid(short))
		static uniform_int_distribution<short> u(min, max); 
	if(typeid(tmp)==typeid(long long))
		static uniform_int_distribution<long long> u(min, max); 
	if(typeid(tmp)==typeid(unsigned))
		static uniform_int_distribution<unsigned> u(min, max); 
	if(typeid(tmp)==typeid(unsigned long))
		static uniform_int_distribution<unsigned long> u(min, max); 
	if(typeid(tmp)==typeid(unsigned short))
		static uniform_int_distribution<unsigned short> u(min, max); 
	if(typeid(tmp)==typeid(unsigned long long))
		static uniform_int_distribution<unsigned long long> u(min, max); 
	if(typeid(tmp)==typeid(float))
		static uniform_real_distribution<float> u(min, max); 
	if(typeid(tmp)==typeid(double))
		static uniform_real_distribution<double> u(min, max); 
	if(typeid(tmp)==typeid(long double))
		static uniform_real_distribution<long double> u(min, max); 

	for(unsigned i=0; i!=N; ++i) 
		v.push_back(u(e));	
}

//二分查找
template <typename T>
bool binarySearch(vector<T> &v, T key, unsigned low, unsigned high)
{
	auto mid = (low+high)/2;
	if(low>=high)
		return false;
	if(v[mid]==key)
		return true;
	else if(v[mid]>key)
		return binarySearch<T>(v, key, mid+1, high);
	else
		return binarySearch<T>(v, key, low, mid-1);
}

//组织n(n+1)/2个数据
template <typename T>
void organize(vector<T> &src, vector<T> &dest)
{
	for(auto sb=src.begin(); sb!=src.end(); ++sb)
		for(auto sb1=sb; sb1!=src.end(); ++sb1)
			dest.push_back((*sb)+(*sb1));
}

template <typename T>
bool solve(vector<T> &v, T key)
{
	vector<T> vv;
	organize(v, vv);
	for(int i=0; i!=v.size(); ++i)
		for(int j=0; j!=v.size(); ++j)
			if(binarySearch(vv, key-v[i]-v[j], 0, vv.size()-1))
				return true;

	return false;
}
