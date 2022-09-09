// SmartPtr.h - The smart pointer class

template <typename T>
class SmartPtr {
    T* p{ nullptr };
public:
    SmartPtr(T* ptr) : p(ptr) { };//SmartPtr<Title> t(new Title(s));
    ~SmartPtr() {
        delete p;//deletes the Title object
		p = nullptr;//even better
    }
    T& operator*() {
        return *p;
    }
    T* operator->() {
        return p;
    }
};