#include "clsDbLinkedList.hpp"


template <typename T> class	clsQueue
{
	protected:
		clsDbLinkedList <T> head;
	public:

		void	push(T data)
		{
			head.addBack(data);
		}

		void	print()
		{
			head.printList();
		}
		int	Size()
		{
			return (head.Size());
		}
		void	pop()
		{
			head.DeleteNode(head.GetNode(0));
		}
		T	front()
		{
			if (head.IsEmpty())
				return ((T)NULL);
			return (head.GetNode(0)->data);
		}
		T back()
		{
			if (head.IsEmpty())
					return ((T)NULL);
				return (head.GetNode(head.Size() - 1)->data);
		}
		T GetItem(int i)
		{	
			
			if (i > head.Size() || i < 0)
				return (NULL);		
			return (head.GetNode(i)->data);
		}
		void	Reverse ()
		{
			head.Reverse();
		}
		void	UpdateItem(int index, T data)
		{
			clsDbLinkedList<T>	*old = head.GetNode(index);

			if (!old)
				return ;
			old->data = data;
		}
		void	Clear()
		{
			head.Clear();
		}
		void	InsertAtback(T data)
		{
			push(data);
		}
		void	InsertAtfront(T data)
		{
			head.addFront(data);
		}
};

// int main()
// {
// 	clsQueue	<int> MyQueue;


// 	std::cout << ">> push <<\n";
// 	MyQueue.push(10);
// 	MyQueue.push(20);
// 	MyQueue.push(30);
// 	MyQueue.push(40);
// 	MyQueue.push(50);

// 	MyQueue.print();

// 	std::cout << ">> size of the Queue : " << MyQueue.Size() << "\n";
// 	std::cout << ">> front of the Queue : " << MyQueue.front() << "\n";
// 	std::cout << ">> back of the Queue : " << MyQueue.back() << "\n";

// 	std::cout << ">> pop <<\n";
// 	MyQueue.pop();

// 	MyQueue.print();

// 	std::cout << ">> clear Queue << \n";
// 	MyQueue.Clear();
// 	return (0);
// }