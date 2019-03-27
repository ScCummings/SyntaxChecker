/*
Scott Cummings
2317991
scummings@chapman.edu
CPSC 350 - Section 1
Assignment 3
Overview: the class file for the GenStack class. Implementation
as well as declarations are both contained here since it is a template
class. This stack is array based. 
*/
#include <iostream>

using namespace std;

template<typename T>
/*
a) GenStack()
b) @return - NA
c) @param - NA
d) no exceptions thrown
*/
class GenStack
{
public:
	GenStack();//constructor
	GenStack(int maxSize); //overloaded constructor
	~GenStack();//destructor


	void push(T d);
	T pop();
	T peek(); //aka top()


	int getSize();
	bool isEmpty();
	bool isFull();
private:
	int size;
	int top;

	T* myArray;
};
template <typename T>
/*
a) GenStack()- Default GenStack constructor
b) @return - NA
c) @param - NA
d) no exceptions thrown
*/
GenStack<T>::GenStack()
{
	myArray = new T[50];
	size = 50;
	top = -1;
}
template <typename T>
/*
a) GenStack(int maxSize) - overloaded GenStack constructor
b) @return - NA
c) @param - int maxSize - an int value that represents the largest size that the stack can have
d) no exceptions thrown
*/
GenStack<T>::GenStack(int maxSize)
{
	myArray = new T[maxSize];
	size = maxSize;
	top = -1;
}
template <typename T>
/*
a) ~GenStack() - GenStack destructor
b) @return - NA
c) @param - NA
d) no exceptions thrown
*/
GenStack<T>::~GenStack()
{
	delete myArray;
}
template<typename T>
/*
a) push(T d) - a function that adds an unspecified data type value to the stack
b) @return - void
c) @param - T d - an unspecified data type value that is being added to the stack
d) no exceptions thrown
*/
void GenStack<T>::push(T d)
{
	int e = 0;
	try
	{
		if (top >= size - 1)
		{
			throw e;
		}
		myArray[++top] = d;
	}
	catch (int e)
	{
		size = size * 2;
		T* newArray = new T[size];
		for (int i = 0; i < size; ++i)
		{
			newArray[i] = myArray[i];
		}
		delete myArray;
		myArray = newArray;
		push(d);
	}
}
template <typename T>
/*
a) pop() - a function that removes an unspecified data type value from the stack
b) @return - T - the unspecified data type value that was removed from the stack
c) @param - none
d) no exceptions thrown
*/
T GenStack<T>::pop()
{
	int e = 0;
	try
	{
		if (isEmpty())
		{
			throw e;
		}
		return myArray[top--];
	}
	catch (int e)
	{
		cout << "Stack is empty. Cannot pop from empty stack." << endl;
		return NULL;
	}
}
template <typename T>
/*
a) peek() - a function that shows the value at the top of the stack
b) @return - T - the unspecified data type value that is at the top of the stack
c) @param - none
d) no exceptions thrown
*/
T GenStack<T>::peek()
{
	int e = 0;
	try
	{
		if (isEmpty())
		{
			throw e;
		}
		return myArray[top];
	}
	catch (int e)
	{
		cout << "There are no elements in the stack. There is no first element." << endl;
	}
}
template <typename T>
/*
a) isFull() - a function that returns a boolean of whether or not the stack is full
b) @return - bool - a value that represents whether or not the stack is full
c) @param - none
d) no exceptions thrown
*/
bool GenStack<T>::isFull()
{
	return (top == size - 1);
}
template <typename T>
/*
a) isEmpty() - a function that returns whether or not the stack is empty
b) @return - a bool value that represents whether ot not the stack is empty
c) @param - none
d) no exceptions thrown
*/
bool GenStack<T>::isEmpty()
{
	return (top == -1);
}
template <typename T>
/*
a) getSize() - accessor method that returns the size of the stack.
b) @return - an int value that represents the current size of the stack.
c) @param - none
d) no exceptions thrown
*/
int GenStack<T>::getSize()
{
	return size;
}
