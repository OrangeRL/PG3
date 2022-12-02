#include <iostream>
#include <string>

template <typename T>
struct Cell
{
	T val_;
	Cell* prev_;
	Cell* next_;
	Cell()
	{
		prev_ = this;
		next_ = this;
	}
	Cell(T value, Cell* prev, Cell* next)
	{
		val_ = value;
		prev_ = prev;
		next_ = next;
	}
};

template <typename T>
class List
{
	//ダミー
	Cell<T>* dummy_;
	int size_;

	void Add(T v, Cell<T>* node)
	{
		Cell<T>* newNode = new Cell<T>(v, node, node->next_);
		node->next_->prev_ = newNode;
		node->next_ = newNode;
		node = newNode;
		size_++;
	}


public:
	List()
	{
		dummy_ = new Cell<T>();
	}
	~List()
	{
		Clear();
		delete dummy_;
	}


	void PushFront(T value)
	{
		Cell<T>* cur = dummy_;
		Add(value, cur);
	}
	void PushBack(T value)
	{
		Cell<T>* cur = dummy_->prev_;
		Add(value, cur);
	}

	void Insert(T value_, int num)
	{
		Cell<T>* tmpCell = nullptr;
		tmpCell = dummy_;

		for (int i = 0; i < num; i++)
		{
			tmpCell = tmpCell->next_;
		}
		Add(value_, tmpCell);
	}

	void ElementSpecification(int num) {
		Cell<T>* tmpCell = nullptr;
		tmpCell = dummy_;

		int index = -1;

		for (int i = 0; i < num + 1; i++)
		{
			tmpCell = tmpCell->next_;
			index++;
		}
		std::cout << index << ':' << tmpCell->val_ << '\n';
	}
	Cell<T>* GetCell(int num)
	{
		Cell<T>* tmpCell = dummy_;

		for (int i = 0; i < num + 1; i++)
		{
			tmpCell = tmpCell->next_;
		}

		return tmpCell;
	}

	bool Search(int num)
	{
		if (num < 0 || num>size_)
		{
			return false;
		}

		return true;
	}

	bool ChangeValue(T value_, int num)
	{

		if (num < 0 || num>size_)
		{
			return false;
		}

		Cell<T>* tmpCell = nullptr;
		tmpCell = dummy_;

		for (int i = 0; i < num + 1; i++)
		{
			tmpCell = tmpCell->next_;
		}

		tmpCell->val_ = value_;

		return true;

	}
	void Dump()
	{
		Cell<T>* ptr = dummy_->next_;

		std::cout << "要素一覧:{" << std::endl;

		int index = 0;
		for (int i = 0; i < size_ - 1; i++)
		{
			std::cout << ' ' << index << ':' << '"' << ptr->val_ << '"' << ',' << std::endl;
			ptr = ptr->next_;
			index++;
		}
		std::cout << ' ' << index << ':' << '"' << ptr->val_ << '"' << std::endl;

		std::cout << '}' << std::endl;
	}

	int Size()
	{
		return size_;
	}
	void Clear()
	{
		while (dummy_->next_)
		{
			Erase(dummy_->next_);
		}
	}
	void Erase(Cell<T>* itr)
	{
		Cell<T>* delCell;
		delCell = itr;

		if (delCell->next_)
		{
			delCell->next_->prev_ = delCell->prev_;
		}
		else
		{
			dummy_->prev_ = delCell->prev_;
		}

		if (delCell->prev_)
		{
			delCell->prev_->next_ = delCell->next_;
		}
		else
		{
			dummy_->next_ = delCell->next_;
		}

		delete delCell;
	}
	bool Delete(int num)
	{
		if (num < 0 || num>size_)
		{
			return false;
		}

		Cell<T>* tmpCell = nullptr;
		tmpCell = dummy_;

		for (int i = 0; i < num + 1; i++)
		{
			tmpCell = tmpCell->next_;
		}

		tmpCell->prev_->next_ = tmpCell->next_;
		tmpCell->next_->prev_ = tmpCell->next_;

		delete tmpCell;
		size_--;
		return true;
	}

};
