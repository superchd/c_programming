#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>
#include <cstdlib>
#include <cstring>

// stack의 size를 어떻게 처리할것인가??? 
//
using namespace std;


template <typename T>
class Stack{
	private:
		int topIdx;             
		T * stackPtr;	        
	public :
		Stack(int s = 10000);
		~Stack();
		void Pushback(const T& obj);
		T Pop();
		
		bool isEmpty();
};

template <typename T>
Stack<T>::Stack(int len){
	topIdx=-1    ;                   
	stackPtr=new T[len];		
}

template <typename T>
Stack<T>::~Stack()
{
	delete[] stackPtr;
}

template <typename T>
bool Stack<T>::isEmpty()
{
    if(topIdx == -1) 
	    return 1;
    else 
	    return 0;
}

template <typename T>
void Stack<T>::Pushback(const T& obj)
{
	stackPtr[++topIdx] = obj;
}

template <typename T>
int Ranking(T obj)
{
	int k = 0;
	if (isdigit(obj[0]))
	{
		while (!isEmpty(obj))
		{
			if (obj[0] > obj.pop())
				k++;
		}
	}
	else
	{
		while(!isEmpty(obj))
		{
			if(strcmp(obj[0], obj.pop()) > 0 )
				k++;
		}
	}
	return k;
}

template <typename T>
T Stack<T>::Pop()
{
	return stackPtr[topIdx--];
}
int maskdigit(string s) 
{
for (int i = 0; i < s.length(); ++i)
	if (isdigit(s.at(i))) 
		return 1;
return 0;
}

int main()
{
	int k = 0;
	int value = 0;
	int num;
	string s;
	string line;
	Stack<string> strs;
	Stack<int> nums;
	while (getline(cin, line))
	{
		istringstream ins(line);
		while (ins >> s)
		{
			if (maskdigit(s) == 1)
			{
				nums.Pushback(s);
				value = 1;
			}
			else
			{
				strs.Pushback(s);
			}
			k++;
		}
		if(value == 1)
			cout << Ranking(nums) << endl;
		else
			cout << Ranking(strs) << endl;
		

	}	




}
	/*
	Stack<char> stack(10);
	stack.Pushback('A');
	stack.Pushback('B');
	stack.Pushback('C');

	for(int i=0;i<3; i++)
	{
		cout<<stack.Pop()<<endl;
	}

	int num;


	while (cin >> 

	Stack<int> stack2(10);
	stack2.Push(10);
	stack2.Push(20);
	stack2.Push(30);

	for(int j=0; j<3; j++)
	{
		cout<<stack2.Pop()<<endl;
	}
	return 0; 
*/


