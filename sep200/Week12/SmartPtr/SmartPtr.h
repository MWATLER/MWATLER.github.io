// SmartPtr.h - The smart pointer class

template <typename T>
class SmartPtr {
    T* p{ nullptr };
public:
    explicit SmartPtr(T* ptr) : p(ptr) { };//the constructor cannot be used for implicit conversions and copy-initialization
    SmartPtr(const SmartPtr&) = delete;//do not use a compiler generated version of this function
    SmartPtr& operator=(const SmartPtr&) = delete;
    SmartPtr(SmartPtr&& s) noexcept {
        p = s.p;
        s.p = nullptr;
    }
    SmartPtr& operator=(SmartPtr&& s) noexcept {
        if (this != &s) {
            delete p;
            p = s.p;
            s.p = nullptr;
        }
        return *this;
    }
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