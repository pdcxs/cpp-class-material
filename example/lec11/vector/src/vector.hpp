#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <initializer_list>
#include <iterator>
#include <ostream>

namespace myvector {
template <typename T> class vector {
  // begin of iterator class
  class iterator {
  private:
    T *ptr;

  public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T *;
    using reference = T &;

    explicit iterator(T *p) : ptr(p) {}

    reference operator*() { return *ptr; }

    pointer operator->() { return ptr; }

    iterator &operator++() {
      ++ptr;
      return *this;
    }

    iterator operator++(int) {
      iterator tmp = *this;
      ++ptr;
      return tmp;
    }

    bool operator!=(const iterator &other) const { return ptr != other.ptr; }

    bool operator==(const iterator &other) const { return ptr == other.ptr; }

    reference operator[](int n) { return ptr[n]; }

    iterator operator+(int n) { return iterator(ptr + n); }

    difference_type operator-(const iterator &other) const {
      return ptr - other.ptr;
    }

    iterator operator-(difference_type n) const { return iterator(ptr - n); }

    iterator &operator+=(difference_type n) {
      ptr += n;
      return *this;
    }

    iterator &operator-=(difference_type n) {
      ptr -= n;
      return *this;
    }

    bool operator<(const iterator &other) const { return ptr < other.ptr; }
    bool operator<=(const iterator &other) const { return ptr <= other.ptr; }
    bool operator>(const iterator &other) const { return ptr > other.ptr; }
    bool operator>=(const iterator &other) const { return ptr >= other.ptr; }

    iterator &operator--() {
      --ptr;
      return *this;
    }

    iterator operator--(int) {
      iterator tmp = *this;
      --ptr;
      return tmp;
    }
  };
  // end of iterator class

  // begin of const_iterator class
  class const_iterator {
  private:
    const T *ptr;

  public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = const T *;
    using reference = const T &;

    explicit const_iterator(const T *p) : ptr(p) {}

    reference operator*() const { return *ptr; }

    pointer operator->() const { return ptr; }

    const_iterator &operator++() {
      ++ptr;
      return *this;
    }

    const_iterator operator++(int) {
      const_iterator tmp = *this;
      ++ptr;
      return tmp;
    }

    bool operator!=(const const_iterator &other) const {
      return ptr != other.ptr;
    }

    bool operator==(const const_iterator &other) const {
      return ptr == other.ptr;
    }

    reference operator[](int n) { return ptr[n]; }

    const_iterator operator+(int n) { return const_iterator(ptr + n); }

    difference_type operator-(const const_iterator &other) const {
      return ptr - other.ptr;
    }

    const_iterator operator-(difference_type n) const {
      return const_iterator(ptr - n);
    }

    const_iterator &operator+=(difference_type n) {
      ptr += n;
      return *this;
    }

    const_iterator &operator-=(difference_type n) {
      ptr -= n;
      return *this;
    }

    bool operator<(const const_iterator &other) const {
      return ptr < other.ptr;
    }
    bool operator<=(const const_iterator &other) const {
      return ptr <= other.ptr;
    }
    bool operator>(const const_iterator &other) const {
      return ptr > other.ptr;
    }
    bool operator>=(const const_iterator &other) const {
      return ptr >= other.ptr;
    }

    const_iterator &operator--() {
      --ptr;
      return *this;
    }

    const_iterator operator--(int) {
      const_iterator tmp = *this;
      --ptr;
      return tmp;
    }
  };
  // end of const_iterator class

private:
  T *data;
  size_t m_size;
  size_t m_capacity;

  void grow() {
    m_capacity *= 2;
    T *newData = new T[m_capacity * 2];
    for (int i = 0; i < m_size; i++) {
      newData[i] = data[i];
    }

    delete[] data;
    data = newData;
  }

public:
  explicit vector(size_t capacity = 0) {
    m_capacity = capacity == 0 ? 8 : capacity;
    m_size = 0;
    data = new T[m_capacity];
  }

  vector(size_t count, const T &value) {
    m_size = count;
    m_capacity = count;
    data = new T[m_capacity];
    for (int i = 0; i < count; i++) {
      data[i] = value;
    }
  }

  vector(std::initializer_list<T> init) {
    m_size = init.size();
    m_capacity = m_size < 8 ? 8 : m_size;
    data = new T[m_capacity];
    int i = 0;
    for (auto const &e : init) {
      data[i] = e;
      ++i;
    }
  }

  ~vector() {
    m_size = 0;
    m_capacity = 0;
    delete[] data;
  }

  size_t size() const { return m_size; }

  size_t capacity() const { return m_capacity; }

  const T &operator[](size_t n) const { return data[n]; }
  T &operator[](size_t n) { return data[n]; }

  void push_back(const T &elem) {
    if (m_size == m_capacity)
      grow();
    data[m_size] = elem;
    ++m_size;
  }

  iterator begin() { return iterator(data); }

  iterator end() { return iterator(data + m_size); }

  const_iterator begin() const { return const_iterator(data); }

  const_iterator end() const { return const_iterator(data + m_size); }

  const_iterator cbegin() const { return const_iterator(data); }

  const_iterator cend() const { return const_iterator(data + m_size); }
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const vector<T> &vec) {
  out << "[";
  for (auto it = vec.begin(); it != vec.end(); ++it) {
    out << *it;
    if (it + 1 != vec.end()) {
      out << ", ";
    }
  }
  out << "]";
  return out;
}
} // namespace myvector

#endif // !__VECTOR_H__
