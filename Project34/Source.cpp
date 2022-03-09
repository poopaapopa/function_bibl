#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

/*void abssort(float* x, unsigned n)
{
	sort(x, x + n, [](float a, float b){return (abs(a) < abs(b));});
}

struct S
{
	void f(int i);
};
void S::f(int i)
{
	//[&, i] {}; OK
	//[&, &i] {}; Error
	//[=, this] {}; Error
	//[=, *this] {}; OK
	//[i, i] {}; Error
}

template<class ... Args>
void f(Args... args)
{
	auto x = [args...]{ return g(args...); };
	x();
}*/
#include <vector>
class Scale
{
	int _scale;
public:
	explicit Scale(int scale):_scale(scale){}
	void ApplyScale(const vector<int>& v) const
	{
		for_each(v.begin(), v.end(), [=](int n) {cout << n * _scale << "\n"; });
	}
};


#include <functional>
#include <list>
void main()
{
	vector<int> values;
	values.push_back(1);
	values.push_back(2);
	values.push_back(3);
	values.push_back(4);
	Scale s(3);
	s.ApplyScale(values);
	cout << "\n";

	auto f1 = [](int x, int y) {return x + y; };
	cout << f1(2, 3) << "\n";
	function<int(int, int)>f2 = [](int x, int y) {return x + y; };
	cout << f2(3, 4) << "\n\n";


	int i = 3;
	int j = 5;
	function<int(void)> f = [i, &j] {return i + j; };
	i = 22;
	j = 44;
	cout << f() << "\n\n";


	list<int> numbers;
	numbers.push_back(13);
	numbers.push_back(17);
	numbers.push_back(42);
	numbers.push_back(46);
	numbers.push_back(99);
	const list<int>::const_iterator result = find_if(numbers.begin(), numbers.end(), [](int n) { return (n % 2) == 0; });
	if (result != numbers.end())
		cout << "the first even number in the list is " << *result << ".\n\n";
	else
		cout << "The list contains no even numbers.\n\n";


	int timestwoplusthree = [](int x) {return [](int y) {return y * 2; }(x)+3; }(5);
	cout << timestwoplusthree << "\n";

	auto addtwointegers = [](int x)-> function<int(int)> {return[=](int y) {return x + y; }; };
	auto higherorde = [](const function<int(int)>& f, int z) {return f(z) * 2; };
	auto answer = higherorde(addtwointegers(7), 8);
	cout << answer << "\n\n";
}