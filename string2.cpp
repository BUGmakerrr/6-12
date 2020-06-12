#include <iostream>
#include <assert.h>
using namespace std;

//template<class T>
//class SeqList
//{
//
//};

template<class T>
class vector // ��̬����������
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

	// ����������
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

// �����涨��
template<class T>
void vector<T>::push_back(const T& x)
{
	// ����ռ䲻������Ҫ��������
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


//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	for (size_t i = 0; i < v.size(); ++i)
//	{
//		// [] д
//		v[i] *= 2;
//	}
//
//	for (size_t i = 0; i < v.size(); ++i)
//	{
//		// [] ��
//		cout << v[i] << " ";
//	}
//	cout << endl;
//
//	return 0;
//}

//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.0, d2 = 20.0;
//	// ��ʽʵ���� ��T�������Ǳ������Լ��Ƶ��ģ�
//	Add(a1, a2);
//	Add(d1, d2);
//
//	Add(a1, (int)d1);
//
//	// ��ʽʵ��������ָ��T�����ͣ�
//	Add<int>(a1, d1);
//
//
//	return 0;
//}

// ר�Ŵ���int�ļӷ�����
int Add(int left, int right)
{
	return left + right;
}

// ͨ�üӷ�����
template<class T>
T Add(T left, T right)
{
	return left + right;
}

//void main()
//{
//	Add(1, 2);       // ���ģ�庯��ƥ�䣬����������Ҫ�ػ�
//	Add<int>(1, 2);  // ���ñ������ػ���Add�汾
//}

#include <string>

//int main()
//{
//	string s1;
//	string s2("hello");
//	string s3(s2);
//	string s4(10, 'a');
//
//	string s5 = "hello";
//	string s6 = s2;
//
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//	cout << s4 << endl;
//	cout << s5 << endl;
//	cout << s6 << endl;
//
//	s1 = s2;
//	cout << s1 << endl;
//
//	return 0;
//}

int main()
{
	//string s("12345");
	//s.push_back('6');
	//s.append("78");
	//s += '1';
	//s += "1111";
	//cout << s << endl;

	/*string s;
	s += "xu";
	s += '.';
	s += "����";
	cout << s << endl;*/

	// ʵ���ַ���ת������
	string s("12345");
	int val = 0;
	for (size_t i = 0; i < s.size(); ++i)
	{
		val *= 10;
		val += (s[i] - '0');
	}
	cout << val << endl;

	return 0;
}