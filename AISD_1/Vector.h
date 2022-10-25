#pragma once
#include <iostream>
#include <iterator>

using namespace std;

template<typename T>
class vec
{
public:
	vec()
	{
		this->maxLen = 5;
		this->array = new T[this->maxLen];
	}

	vec(int n)
	{
		this->maxLen = n;
		this->array = new T[this->maxLen];
	}

	vec(const vec<T>& a)
	{
		this->cr = 0;

		this->maxLen = a.maxLen;
		this->len = a.len;
		this->array = new T[this->maxLen];

		for (int i = 0; i < this->len; i++)
			this->array[i] = a.array[i];
		this->cr = this->len;
	}

	~vec()
	{
		delete this->array;
	}

	int Len()
	{
		this->cr = 0;
		return this->len;
	}

	void Clear()
	{
		this->cr = 2;
		this->len = 0;
		delete this->array;
		this->array = new T[this->maxLen];
	}

	bool Empty()
	{
		this->cr = 0;
		return (this->len == 0);
	}

	void Print()
	{
		this->cr = len;
		for (int i = 0; i < this->len; i++)
			cout << this->array[i] << " ";
		cout << endl;
	}

	bool SeekEl(const T el)
	{
		this->cr = 0;
		bool sk = false;

		for (int i = 0; i < this->len; i++)
		{
			this->cr++;
			if (this->array[i] == el)
			{
				sk = true;
				break;
			}
		}

		return sk;
	}

	T SeekByInd(const T ind)
	{
		this->cr = 1;
		return this->array[ind];
	}

	bool RefactorByInd(const int ind, const T newEl)
	{
		this->cr = 1;
		if (ind >= this->len || ind < 0)
			return false;
		this->array[ind] = newEl;
		return true;
	}

	int GetPosByEl(const T El)
	{
		this->cr = 0;
		int k = -1;

		for (int i = 0; i < this->len; i++)
		{
			this->cr++;
			if (this->array[i] == El)
			{
				k = i;
				break;
			}
		}

		return k;
	}

	void Push(T El)
	{
		this->cr = 0;
		if (this->len == this->maxLen)
			this->ReSize();

		this->len++;
		this->array[this->len - 1] = El;
		this->cr++;
	}

	bool Insert(const int ind, const T El)
	{
		this->cr = 0;
		if (ind <= this->len && ind >= 0)
		{
			if (this->len == this->maxLen)
				this->ReSize();

			this->len++;
			for (int i = this->len; i > ind; i--)
			{
				this->array[i] = this->array[i - 1];
				this->cr++;
			}

			this->array[ind] = El;
			this->cr++;
			return true;
		}
		else
			return false;
	}

	bool Remove(const T El)
	{
		this->cr = 0;
		if (this->SeekEl(El))
		{
			int tmpcr = this->cr;
			int ind = GetPosByEl(El);
			tmpcr += this->cr;
			this->RemoveByInd(ind);
			this->cr += tmpcr;
			return true;
		}
		else
			return false;
	}

	bool RemoveByInd(const int ind)
	{
		this->cr = 0;
		if (ind >= 0 && ind < this->len)
		{
			for (int i = ind; i < this->len - 1; i++)
			{
				this->array[i] = this->array[i + 1];
				this->cr++;
			}

			this->len--;

			return true;
		}
		else
			return false;
	}

	int GetCounView()
	{
		return this->cr;
	}



	struct Iterator
	{
		using iterator_category = std::forward_iterator_tag;
		using defferance_type = std::ptrdiff_t;
		using value_type = T;
		using pointer = T*;
		using reference = T&;

		Iterator(pointer ptr) :m_ptr(ptr) {}

		reference operator*() const { return *m_ptr; }
		pointer operator->() { return m_ptr; }

		Iterator& operator++() { m_ptr++; return *this;}
		Iterator& operator--() { m_ptr--; return *this;}
		
		friend bool operator==(const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
		friend bool operator!=(const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };


	private:
		pointer m_ptr;
	};
	
	struct RIterator
	{
		using iterator_category = std::forward_iterator_tag;
		using defferance_type = std::ptrdiff_t;
		using value_type = T;
		using pointer = T*;
		using reference = T&;

		RIterator(pointer ptr) :m_ptr(ptr) {}

		reference operator*() const { return *m_ptr; }
		pointer operator->() { return m_ptr; }

		RIterator& operator--() { m_ptr++; return *this;}
		RIterator& operator++() { m_ptr--; return *this;}
		
		friend bool operator==(const RIterator& a, const RIterator& b) { return a.m_ptr == b.m_ptr; };
		friend bool operator!=(const RIterator& a, const RIterator& b) { return a.m_ptr != b.m_ptr; };


	private:
		pointer m_ptr;
	};

	Iterator begin()
	{
		this->cr = 1;
		return Iterator(&(this->array[0]));
	}

	Iterator end()
	{
		this->cr = 1;
		return Iterator(&(this->array[this->len]));
	}
	
	RIterator rbegin()
	{
		this->cr = 1;
		return RIterator(&(this->array[this->len - 1]));
	}

	RIterator rend()
	{
		this->cr = 1;
		return RIterator(&(this->array[-1]));
	}

private:
	T* array;
	int len = 0;
	int maxLen;
	int cr;

	void ReSize()
	{
		this->maxLen += 1;
		this->array = (int*)realloc(this->array, this->maxLen * sizeof(int));
	}
};