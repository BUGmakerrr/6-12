#include <iostream>
#include <assert.h>
using namespace std;

//template<class T>
//class SeqList
//{
//
//};

template<class T>
class vector // 动态增长的数组
{
public:
	vector()
		:_a(nullptr)
		, _size(0)
		, _capacity(0)
	{}

	vector(size_t n)
		:_a(new T[n])
		, _size(0)
		, _capacity(n)
	{}

	~vector()
	{
		delete[] _a;
		_a = nullptr;
		_size = _capacity = 0;
	}

	// 类里面声明
	void push_back(const T& x);
	void pop_back();

	size_t size()
	{
		return _size;
	}

	T& operator[](size_t i)
	{
		assert(i < _size);
		return _a[i];
	}

private:
	T* _a;
	size_t _size;
	size_t _capacity;
};

// 类外面定义
template<class T>
void vector<T>::push_back(const T& x)
{
	// 如果空间不够，需要进行增容
	if (_size == _capacity)
	{
		size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
		T* tmp = new T[newcapacity];
		if (_a)
		{
			memcpy(tmp, _a, sizeof(T)*_size);
			delete[] _a;
		}

		_a = tmp;

		_capacity = newcapacity;
	}

	_a[_size] = x;
	++_size;
}

template<class T>
void vector<T>::pop_back()
{
	assert(_size > 0);
	--_size;
}


int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	for (size_t i = 0; i < v.size(); ++i)
	{
		// [] 写
		v[i] *= 2;
	}

	for (size_t i = 0; i < v.size(); ++i)
	{
		// [] 读
		cout << v[i] << " ";
	}
	cout << endl;

	return 0;
}