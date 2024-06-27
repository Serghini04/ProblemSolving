#include <iostream>


template <typename T> class clsDynamicArray
{
	T *_arr = NULL;
	int	_Size = 0;
	public :
		clsDynamicArray(int nb = 0)
		{
			int i = 0;
			if (nb < 0)
				return ;
			_Size = nb;
			_arr = new T[nb];
		}
		void	SetItem(int index, T data)
		{
			if (index >= _Size || index < 0)
				return ;
			_arr[index] = data;
		}
		int	Size()
		{
			return _Size;
		}
		bool	IsEmpty()
		{
			return (_arr == NULL);
		}
		void	print()
		{
			for (int i = 0; i < _Size; i++)
				std::cout << _arr[i] << std::endl;
		}
		void	Resize(int nb)
		{
			if (nb < 0)
				return ;
			if (nb < _Size)
				_Size = nb;
			T *arr = new T[nb];
			for (int i = 0; i < _Size; i++)
				arr[i] = _arr[i];
			delete [] _arr;
			_arr = arr;
			_Size = nb;
		}
		void	Reverse()
		{
			int tmp;

			for (int i = 0; i < _Size / 2; i++)
			{
				tmp = _arr[i];
				_arr[i] = _arr[(_Size - 1) - i];
				_arr[(_Size - 1) - i] = tmp;
			}
		}
		T GetItem (int index)
		{
			if (index < 0 || index > _Size)
				return (NULL);
			return (_arr[index]);
		}
		void	Clear()
		{
			delete [] _arr;
		}
		void	DeleteItemAt(int index)
		{
			if (index >= _Size || index < 0)
				return ;
			--_Size;
			T *arr = new T[_Size];
			int v = 0;
			for (int i = 0; i < _Size; i++)
			{
				if (i == index)
				{
					v = 1;
					continue;
				}
				arr[i - v] = _arr[i];		
			}
			delete [] _arr;
			_arr = arr;
		}
		int	Find(T data)
		{
			int i = 0;
			while (i < _Size)
			{
				if (_arr[i] == data)
					return i;
				i++;
			}
			return -1;
		}
		int	DeleteItem(T data)
		{
			return (DeleteItemAt(Find(data)));
		}
};

// int main()
// {
// 	clsDynamicArray<int> head(5);
	
// 	head.SetItem(0, 10);
// 	head.SetItem(1, 20);
// 	head.SetItem(2, 30);
// 	head.SetItem(3, 40);
// 	head.SetItem(4, 50);

// 	std::cout << "Is Empty ? " << head.IsEmpty() << "\n";
// 	std::cout << "Array Size ? " << head.Size() << "\n";
// 	head.print();

// 	head.Resize(10);
// 	std::cout << "Array Size ? " << head.Size() << "\n";
// 	head.print();

// 	// std::cout << "Reverse array : \n";
// 	// head.Reverse();
// 	// head.print();

// 	std::cout << "Array after deleteting item\n";
// 	head.DeleteItemAt(2); 
// 	head.print();

// 	head.Clear();
// }