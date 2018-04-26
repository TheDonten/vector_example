#include <iostream>

using namespace std;
template <typename T>
class shared_ptr {
 private:
  T* ptr_;
  size_t* counter_;

 public:
  shared_ptr(T* ptr = nullptr) {
    ptr_ = ptr;
    if (ptr_) {
      counter_ = new std::size_t(1);
    } else
      counter_ = nullptr;
  }

  shared_ptr(shared_ptr<T> const& other) {
    ptr_ = other.ptr_;
    if (ptr_) {
      counter_ = other.counter_;
      ++*counter_;
    } else {
      counter_ = nullptr;
    }
  }
  bool before(shared_ptr<T> const& other) {
    size_t* ptr1;
    ptr1 = other.counter_;
    if (*counter_ > *ptr1) {
      return true;
    } else
      return false;
  }
  shared_ptr & operator=(shared_ptr<T> const& other) {
    if (ptr_ != other.ptr_) {
      if (ptr_) {
        if (*counter_ == 1) {
          delete ptr_;
          delete counter_;
        } else {
          --*counter_;
        }
      }
      ptr_ = other.ptr_;
      counter_ = other.counter_;
      ++*counter_;
    }
    return *this;
  }
  void reset(T* ptr) {
    if (ptr_) {
      if (*counter_ == 1) {
        delete ptr_;
        delete counter_;
      } else {
        --*counter_;
      }
    }
    ptr_ = ptr;
    if (ptr_) {
      counter_ = new std::size_t(1);
    } else {
      counter_ = nullptr;
    }
  }
  void swap(shared_ptr<T>& other) {
    std::swap(ptr_, other.ptr_);
    std::swap(counter_, other.counter_);
  }

  T& operator*() const { return *ptr_; }
  T* operator->() const { return ptr_; }
  T* get() const { return ptr_; }
  size_t use_count() { return *counter_; }
  size_t unique() {
    if (*counter_ == 1)
      return true;
    else
      return false;
  }
  ~shared_ptr() {
    if (ptr_ && --*counter_ == 0) {
      delete ptr_;
      delete counter_;
    }
  }
};
typedef std::pair<int, int> Mypair;
