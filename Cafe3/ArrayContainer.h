#ifndef _ARRAYCONTAINER_H_
#define _ARRAYCONTAINER_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>

template<typename T>
class ArrayContainer
{
public:

	class array_iterator
	{
	private:
		T* ptr_;
	public:
		typedef std::forward_iterator_tag iterator_category;
		array_iterator(T* ptr) {ptr_ = ptr;}
		array_iterator operator++ ()
		{
			array_iterator i = *this;
			ptr_++;
			return i;
		} 

		array_iterator operator++(int j)
		{
			ptr_++;
			return *this;
		}
		T& operator* ()
		{
			return *ptr_;
		}
		T* operator->()
		{
			return ptr_;
		}
		bool operator==(const array_iterator& rhs) 
		{
			return ptr_ == rhs.ptr_;
		}
		bool operator!=(const array_iterator& rhs)
		{
			return ptr_ != rhs.ptr_;
		}
	};
	ArrayContainer(){
	}
	ArrayContainer(int size)
		:size_(size)
	{
		data_ = new T[size_];
	}
	virtual ~ArrayContainer(void){}

	int size() const {return size_;}

	T& operator[](int index) 
	{
		assert(index < size_);
		return data_[index];
	}

	const T& operator[](int index) const
	{
		assert(index < size_);
		return data_[index];
	}

	array_iterator begin()
	{
		return array_iterator(data_);
	}

	array_iterator end()
	{
		return array_iterator(data_ + size_);
	}


private:
	T* data_;
	int size_;
};


#endif //_ARRAYCONTAINER_H_

