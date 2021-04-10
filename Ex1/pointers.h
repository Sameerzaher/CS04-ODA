#pragma once

using namespace std;

class Counter
{
public:
	Counter()
	{
		_useCount = 0;
		_weakCount = 0;
	}
	void incUse() { ++_useCount; }
	void incWeak() { ++_weakCount; }
	void decUse() { --_useCount; }
	void decWeak() { --_weakCount; }
	int getUse() const { return _useCount; }
	int getWeak() const { return _weakCount; }
private:
	int _useCount; 
	int _weakCount;
};

template<class T>
class shared_ptr
{
public:
	shared_ptr(): _ptr(nullptr),_counter(new Counter)
	{
		_counter->incUse();
		_counter->incWeak();
	}
	shared_ptr(T *p) : _ptr(p),_counter(new Counter)
	{
		_counter->incUse(); 
		_counter->incWeak(); 
	}
	shared_ptr(const shared_ptr<T> &p)
	{
		_counter = nullptr;
		*this = p;
	}
	~shared_ptr() { del(); }

	const shared_ptr<T> &operator= (const shared_ptr<T> &p)
	{
		del();
		_counter = p._counter;
		_ptr = p._ptr;
		_counter->incUse();
		return *this;
	}
	const T& operator* () const { return *_ptr; }
	T *operator ->() const { return _ptr; }

	int getRefCount() const { return _counter->getUse(); }

	template<class T>
	friend class weak_ptr;
private:
	void del() 
	{
		if (_counter == nullptr)
			return; 
		_counter->decUse();
		if (_counter->getUse() == 0)
		{
			delete _ptr;
			_counter->decWeak();
			if (_counter->getWeak() == 0)
				delete _counter;
		}
	}
	T *_ptr;
	//in the past int* counter
	//in shared_ptr
	Counter *_counter;

};


template <class T>
class weak_ptr
{
public:
	weak_ptr()
	{
		_ptr = nullptr;
		_counter = nullptr;
	}
	weak_ptr(shared_ptr<T> &p) : _ptr(&p), _counter(p._counter) { _counter->incWeak(); }
	weak_ptr(const weak_ptr<T> &wp) : _counter(nullptr) { *this = wp; }
	~weak_ptr() { decrmentRef(); }
	const weak_ptr<T>& operator=(const weak_ptr<T> &wp)
	{
		decrmentRef();
		_counter = wp._counter;
		_ptr = wp._ptr;
		_counter->incWeak();
		return *this;
	}
	bool expired() const { return _counter->getUse() == 0; }
	T *operator ->() const 
	{
		if (expired())
			throw "Pointer is not longer valid.";
		return *_ptr; 
	}
	const T& operator*() const
	{
		if (expired())
			throw "Pointer is not longer valid.";
		return **_ptr; 
	}
private:
	shared_ptr<T> *_ptr; //pointer to strong pointer
	Counter *_counter;
	void decrmentRef() 
	{
		if (_counter == nullptr)
			return;
		_counter->decWeak();
		if (_counter->getWeak() == 0) 
		{
			delete _counter;
		}

	}
};

template <class T>
class UniquePtr
{
public:
    UniquePtr(T* p):_ptr(p){}
    ~UniquePtr() {delete _ptr;}
    UniquePtr(const UniquePtr<T>& p) = delete;
    const UniquePtr<T>& operator = (const UniquePtr<T>& p) = delete;
    UniquePtr(UniquePtr<T> &&p)
    {
        _ptr=p._ptr;
        p._ptr=nullptr;
    }
    const T& operator *() const {return *_ptr;}
    T* operator -> () const {return _ptr;}
private:
    T* _ptr;
};