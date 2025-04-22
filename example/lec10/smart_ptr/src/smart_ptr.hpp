#ifndef __SMART_PTR_H__
#define __SMART_PTR_H__

template <typename T> class SmartPtr {
  T *ptr;
  int *count;

  void release() {
    if (--(*count) == 0) {
      delete ptr;
      delete count;
    }
  }

public:
  explicit SmartPtr(T *p = nullptr) : ptr(p), count(new int(1)) {}

  SmartPtr(const SmartPtr &other) : ptr(other.ptr), count(other.count) {
    ++(*count);
  }

  SmartPtr &operator=(const SmartPtr &other) {
    if (this == &other)
      return *this;

    release();
    ptr = other.ptr;
    count = other.count;
    ++(*count);
    return *this;
  }

  SmartPtr(SmartPtr &&other) noexcept : ptr(other.ptr), count(other.count) {
    other.ptr = nullptr;
    other.count = nullptr;
  }

  SmartPtr &operator=(SmartPtr &&other) noexcept {
    if (this == &other)
      return *this;

    release();
    ptr = other.ptr;
    count = other.count;

    other.ptr = nullptr;
    other.count = nullptr;
    return *this;
  }

  ~SmartPtr() {
    if (count)
      release();
  }

  T &operator*() const noexcept { return *ptr; }

  T *operator->() const noexcept { return ptr; }

  T *get() const noexcept { return ptr; }

  int useCount() const noexcept { return count ? *count : 0; }

  bool unique() const noexcept { return useCount() == 1; }

  void reset(T *p = nullptr) {
    release();
    ptr = p;
    count = new int(1);
  }
};

#endif // !__SMART_PTR_H__
