#pragma once

#include <type_traits>

#include "custom_exception.h"

template <class T>
class List {
    const static size_t kDefaultCapacity = 4;
    const static size_t kCapacityMultiplier = 2;

    T* arr_;
    size_t size_;
    size_t capacity_;

public:
    List() :
        List(0)
    { };

    List(const size_t& size) :
        size_(size),
        capacity_(size_ == 0 ? kDefaultCapacity : size_ * kCapacityMultiplier)
    {
        arr_ = new T[capacity_];
    };

    ~List() {
        delete[] arr_;
    }

    void add(T value) {
        if (size_ == capacity_) {
            auto new_capacity = capacity_ * kCapacityMultiplier;
            T* temp = new T[new_capacity];

            for (size_t i = 0; i < capacity_; i++)
                temp[i] = arr_[i];

            delete[] arr_;
            arr_ = temp;
            capacity_ = new_capacity;
        }
        arr_[size_++] = value;
    }

    T& operator[](size_t index) const {
        if (index < 0 || index >= size_)
            throw CustomExteption("Index out of range!");
        return arr_[index];
    }

    size_t size() const {
        return size_;
    }
};

//template <class T>
//inline List<T>::~List() {
//    delete[] arr_;
//}
//
////template <class P*>
////inline List<P>::~List() {
////    for (size_t i = 0; i < size_; i++) {
////        delete arr_[i];
////    }
////    delete[] arr_;
////}
//
//template <class T>
//inline List<T*>::~List() {
//    delete[] arr_;
//}