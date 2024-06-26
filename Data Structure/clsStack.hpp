#include <iostream>
#include "clsQueue.hpp"
template <class T>

class clsStack : public	clsQueue <T>
{
	public:
		void	push(T data)
		{
			clsQueue<T>::head.addFront(data);
		}
		T	Top()
		{
			return clsQueue<T>::front();
		}
		T	Bottom()
		{
			return clsQueue<T>::back();
		}
};


// int main()
// {
// 	clsStack<int> head;

// 	head.push(5);
// 	head.push(4);
// 	head.push(3);
// 	head.push(2);
// 	head.push(1);

// 	head.print();
// }