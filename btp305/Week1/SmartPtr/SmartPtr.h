// SmartPtr.h - The smart pointer class

template <typename T>
class SmartPtr {
    T* p{ nullptr };
public:
    SmartPtr(T* ptr) : p(ptr) { };
    ~SmartPtr() {
        delete p;
		p = nullptr;//even better
    }
    T& operator*() {
        return *p;
    }
    T* operator->() {
        return p;
    }
};