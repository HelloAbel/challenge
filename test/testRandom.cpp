#include <iostream>
#include <random>

using namespace std;

int main()
{
//	uniform_real_distribution<float> u(0, 9);
//	uniform_int_distribution<> u(-9, 9);
	uniform_int_distribution<long> u(-9, 9);
	default_random_engine e;
	
	for(int i=0; i<10; ++i)
		cout << u(e) << " ";
	cout << endl;

	return 0;
}
