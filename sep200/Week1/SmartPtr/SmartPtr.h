// SmartPtr.h - The smart pointer class

template <typename T>
class SmartPtr {
    T* p{ nullptr };
public:
    SmartPtr(T* ptr) : p(ptr) { };//SmartPtr<Title> t(new Title(s));
                                  //p points to "new Title(s)"
    ~SmartPtr() {
        delete p;//deletes the memory pointed to by p, which was "new Title(s)"
		p = nullptr;//even better
    }
    T& operator*() {
        return *p;
    }
    T* operator->() {
        return p;
    }
};