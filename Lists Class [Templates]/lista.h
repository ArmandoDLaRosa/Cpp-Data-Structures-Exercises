#pragma once

template <class T>
class Lista
{
	public:
		Lista();

		void insert(T data);
		T erase();
		void print();

		T getData(int loc);
		int getSize();

	private:
		int max;
		int size;
		vector<T> data;
};

template <class T>
Lista <T>::Lista() 
{
	max = 100;
	size = 0;
}

template <class T>
void Lista <T>::insert(T data) 
{
	if (size < max)
	{
		//vector::push_back
		this->data.push_back(data);
		size++;
	}  else 
	{
		//El profe utilizó "throw runtime_error("La lista ya está llena")"
		//cout << "Error - Vector FULL" << endl;
		throw runtime_error("The list is full");
	}
}

template <class T>
T Lista <T>::erase()
{
	if (size == 0)
	{
		cout << "List empty" << endl;
		return 1;
	} else 
	{
		T erased = data[size-1];
		//vector::pop_back
		data.pop_back();
		size--;
		return erased;
	}
	return 0;
}

template <class T>
void Lista <T>::print()
{
	if (size !=0)
	{
		for (int i = 0; i < size; i++)
		{
			cout  << "["  <<  i  << "] - "  << data[i]  << endl;
 		}
	} else
	{
		cout << "There is no data" << endl;
	}
}

template <class T>
T Lista <T>::getData(int loc)
{
	if (size == 0)
	{
		cout << "There is no data" << endl;
	} else if (loc >= 0 && loc < size)
	{
		return data[loc];
	} else
	{
		cout << "Not valid request" << endl;
	}
	return 0;
}

template <class T>
int Lista <T>::getSize()
{
	return size;
}