// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
 private:
  T* data = {};
  int top = 1, size = 0;
  void resize(int nsize) {
    T* temp = new T[nsize];
    for (int i = 0; i < size; i++) {
      temp[i] = data[i];
    }
    delete data;
    data = temp;
    size = nsize;
  }

 public:
  TStack() {
    data = new T[SIZE];
    size = SIZE;
    top = 1;
  }
  ~TStack() { delete[] data; }
  void push(T item) {
    if (top >= size) {
      resize(size * 2);
    }
    data[top] = item;
    top++;
  }
  T pop() {
    if (top == 1) {
      throw "Stack is empty!";
    } else {
      top -= 1;
      return data[top];
    }
  }
};

#endif  // INCLUDE_TSTACK_H_
