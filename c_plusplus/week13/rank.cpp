#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>

const size_t SIZE = 100;

using namespace std;

template <class T>
class Stack 
{
public:
	Stack(size_t size = SIZE);
	Stack(const Stack<T>& s);
	const Stack<T>& operator = (const Stack<T>& s); ~Stack();
	bool isfull();
	bool isEmpty();
	void push(T d);
	T pop();
	T Elem(size_t i);
	int get_size();
//	int Ranking(T obj);
private:
	T *_data;
	size_t _top, _size;
};
template <class T>
int Stack<T>::get_size
{
	return _top;
}

template <class T>
Stack<T>::Stack(size_t size) : _top(0), _size(size) 
{
	_data = new T[size]; 
}

template <class T>
Stack<T>::Stack(const Stack<T>& s) : _top(s._top), _size(s._size)
{
	if (_data) delete[] _data;
	_size = s._size;
	_top = s._top;
	_data = new T[_size];
	for (int i = 0; i < _size; ++i)
		_data[i] = s._data[i];
}

template <class T>
const Stack<T>& Stack<T>::operator = (const Stack<T> &s) 
{
	delete [] _data;
	_top = s._top;
	_size = s._size;
	_data = new T[_size];
	for (int i = 0; i < _size; ++i)
	_data[i] = s._data[i]; 
}

template <class T> 
Stack<T>::~Stack() 
{
	delete [] _data;
}

template <class T> 
bool Stack<T>::isfull() 
{
	return _top == _size;
}

template <class T>
bool Stack<T>::isEmpty()
{
	return _top == 0;
}

template <class T>
void Stack<T>::push(T d)
{
	if (! isfull())
		_data[_top++] = d;
}

template <class T> 
T Stack<T>::pop() 
{
	if (! isEmpty())
		return _data[--_top]; 
	throw -1;
}

template <class T> 
T Stack<T>::Elem(size_t i) 
{
	return _data[i];
}


bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

template <class T> 
int Ranking(T& obj)
{
	int i = 1;
	int k = 0;
	while(i < obj.get_size())
	{
		if(strcmp(obj.Elem(0).c_str(), obj.Elem(k).c_str()))
			k++;
		i++;
	}
	return k;
}

bool is_bigger(int i, int j)
{
	if (i > j) 
		return true;
	else
		return false;
}

bool is_bigger(string a, string b)
{
	if (strcmp(a.c_str() , b.c_str()) > 0)
		return true;
	else 
		return false;
}

int maskdigit(string s)
{
	for (int i = 0; i < s.length(); ++i)
		if (isdigit(s.at(i)))
			return 1;
	return 0;
}

int main(void)
{
	int j = 0;
	int k = 0;
	int value = 0;
	int num;
	string s;
	string line;
	vector<int> nums;

//	while(getline(cin, line))
//	{
		getline(cin, line);
		Stack<string> strs;
		istringstream ins(line);
		while (ins >> s)
		{
			strs.push(s);
		}
		nums.push_back(Ranking(strs));


		j++;
//	}
	
	for(int i = 0 ; i < nums.size() ; i++)
	{
		cout << nums[i] << endl;
	}
}
