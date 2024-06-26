#include <iostream>


template <typename T> class clsDbLinkedList
{
	int	_Size = 0;
    public :
        class   Node
        {
            public:
                T   data;
                Node    *prv;
                Node    *next;
        };
        Node	*head = NULL;

        void    addFront(T data)
        {
            Node *res = new Node;
			res->data = data;
            res->next = head;
			res->prv = NULL;
			if (head)
				head->prv = res;
			head = res;
			_Size++;
	    }
		void	printList()
		{
			Node	*lst;

			lst = head;
			while (lst)
			{
				std::cout << "Content of the node is : " << lst->data  << "\n";
				lst = lst->next;
			}
		}
		Node	*Find(T data)
		{
			Node	*lst = head;

			while (lst)
			{
				if (lst->data == data)
					return (lst);
				lst = lst->next;
			}
			return (NULL);
		}
		void	InsertAfter(Node *old, T NewData)
		{
			Node	*res;

			if (!old)
				return ;
			_Size++;
			if (!old->prv)
			{
				addFront(NewData);
				return ;
			}
			res = new Node;
			res->data = NewData;
			old->prv->next = res;
			res->prv = old->prv;
			res->next = old;
            old->prv = res;
		}
        void    addBack(T   data)
        {
        	Node* newNode = new Node();

        	newNode->data = data;
        	newNode->next = NULL;
        	if (head == NULL) {
        	    newNode->prv = NULL;
        	    head = newNode;
        	}
        	else {
        	    Node* current = head;
        	    while (current->next != NULL) {
        	        current = current->next;
        	    }
        	    current->next = newNode;
        	    newNode->prv = current;
        	}
        	_Size++;
        }
        void    DeleteNode(Node *old)
        {
            if (!old->prv)
                head = old->next;
            else
            {
                old->prv->next = old->next;
            }
            if (old->next)
                old->next->prv = old->prv;
			_Size--;
			delete old;
        }
		int	Size()
		{
			return (_Size);
		}
		bool	IsEmpty()
		{
			return (head == NULL);
		}
		void	Clear()
		{
			Node *lst = head;
			while (lst)
			{
				Node *swap = lst->next;
				DeleteNode(lst);
				lst = swap;
			}
			head = NULL;
		}
		void	Reverse()
		{
			Node	*lst = head;
			Node	*swap;

			while (lst)
			{
				swap = lst->prv;
				lst->prv = lst->next;
				lst->next = swap;
				lst = lst->prv;
			}
			head = swap->prv;
		}
		Node	*GetNode(int	index)
		{
			int	i = 0;
			Node	*lst = head;

			if (index > _Size || index < 0)
				return (NULL);
			while (lst && i < index)
			{
				i++;
				lst = lst->next;
			}
			return (lst);
		}
		void	UpdateItem(int index, T data)
		{
			Node	*old = GetNode(index);
			
			if (!old)
				return ; 
			old->data = data;
		}
};

// int main()
// {
//     clsDbLinkedList <int> head;
//     // add Front
// 	std::cout << "are empty : " << head.IsEmpty() << std::endl;
// 	head.addFront(5);
//     head.addFront(4);
//     head.addFront(3);
//     head.addFront(2);
//     head.addFront(1);

// 	// print list
//     head.printList();

// 	clsDbLinkedList<int>::Node *N1 = head.Find(5);
// 	if (!N1)
// 		std::cout << "Node is not fount\n";
// 	else
// 		std:: cout <<  "Node is found\n";

// 	head.InsertAfter(N1, 0);
// 	head.printList();

//     // add Back
//     head.addBack(6);

//     std::cout << "\t======> Last Update <=====\n";
//     head.printList();

//     std::cout << "\t======> Deleted node <=====\n";
//     head.DeleteNode(N1);
//     head.printList();


// 	std::cout << "size of lst is : " << head.Size() << "\n";

// 	std::cout << "\t Reverse lst : \n";
// 	head.Reverse();
// 	head.printList();

// 	std::cout << " change content of the node :\n";
// 	head.UpdateItem(6, 888);
// 	head.printList();

//     std::cout << "\t======> Clear lst <=====\n";
//     head.Clear();
//     head.printList();

//     return (0);
// }