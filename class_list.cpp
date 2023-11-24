#include <iostream>

template <typename T>

class List 
{
	private:
	struct Node 
	{
		T element;
		Node* prev = nullptr;
		Node* next = nullptr;
	};
	Node* first = nullptr;
	Node* last = nullptr;
	int elementsCount = 0;
	
	public:
	List() = default; 
	
	List( const List<T>& copy )  //copy constructor
	{
		Node* current = copy.first;
		while(current != nullptr)
		{
			PushBack(current->element);
			current = current->next;
		}
	}
	
	List<T>& operator = ( const List<T>& copy )
	{
		Node* current = copy.first;
		while(current != nullptr)
		{
			PushBack(current->element);
			current = current->next;
		}
    
		return *this;
	}
	
	size_t Size() const
	{
		return elementsCount;
	}
	
	void PushBack( const T& elem )
	{
		Node* node = new Node( elem, last, nullptr ); 
		if( last != nullptr )
		{
			last -> next = node;
		}
		else
		{
			first = node;
		}
		last = node;
		++elementsCount;
	}
	
	void PushFront( const T& elem )
	{
		Node* node = new Node( elem, first, nullptr );
		if( first != nullptr )
		{
			first -> prev = node;
		}
		else
		{
			last = node;
		}
		first = node;
		++elementsCount;
	}
	
	void PopBack() 
	{
        if ( last != nullptr ) 
        {
            Node* prev = last -> prev;
            delete last;
            last = prev;
            --elementsCount;
        }
    }
    
	void PopFront() 
	{
        if ( first != nullptr )
         {
            Node* next = first -> next;
            delete first;
            first = next;
            --elementsCount;
        }
    }
    
    void Clear()
	{
		Node* current = first;
		while( current != nullptr )
		{
			Node* next = current -> next;
			delete current;
			current = next;
		}
		first = nullptr;
		last = nullptr;
		elementsCount = 0;
	}

};

int main() 
{
    List<int> L;
    L.PushBack(1);
    L.PushBack(2);
    L.PushBack(3);
    L.PushBack(4);
    L.PushBack(5);
    L.PushBack(6);

    std::cout << "Size: " << L.Size() << "\n";  //Size after PushBack()

    L.PopBack();
    std::cout << "PopBack(): " << L.Size() << "\n";  //Size after PopBack()

    L.PopFront();
    std::cout << "PopFront(): " << L.Size() << "\n";  //Size after PopBack()
    
    L.Clear();
    std::cout << "Clear(): " << L.Size() << "\n";  //Size after Clear()
    
    return 0;
}
