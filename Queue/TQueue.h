#pragma once

template <class T>
class TQueue
{
  T* mas;
  int maxsize, head, tail, len;

public:
  TQueue(int s = 10) {
    if (s < 0)
      throw (s);
    maxsize = s;
    mas = new T[maxsize];
    head = 0;
    tail = -1;
    len = 0;
  }
TQueue(const TQueue& ñ)
  {
      maxsize = ñ.maxsize;
      mas = new T[maxsize];
      for (int i = 0; i < maxsize; i++)
         mas[i] = ñ.mas[i];
      head = ñ.head;
      tail = ñ.tail;
      len = ñ.len;
  }
  ~TQueue() {
    delete[] mas;
  }

  bool IsEmpty() {
      if (len == 0)
          return true;
      return false;
  }

  bool IsFull() {
      if (len == maxsize)
          return true;
      return false;
  }

  void Push(T n) {
    if (!IsFull()) {
        tail = (tail + 1) % maxsize;
        mas[tail] = n;
        len++;
    }      
    else
      throw 0;
  }

  T Pop() {
      if (IsEmpty())
          throw - 1;
      else
      {
          T tmp = mas[head];
          head++;
          len--;
          return tmp;
      }
  }
  int GetHead() {
    return head;
  }

  int GetMaxSize() {
    return maxsize;
  }

  int GetSize() {
    return len;
  }

};