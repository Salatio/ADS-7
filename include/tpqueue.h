// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T>
class TPQueue {
    struct ITEM {
        T data;
        ITEM* next;
    };

 public:
    TPQueue(): head(nullptr), tail(nullptr) {}
    ~TPQueue() {
        while (head)
            pop();
    }
    void push(const T& data) {
        if (tail && head) {
            if (head->data.prior < data.prior) {
                ITEM* temp = head;
                head = create(data);
                head->next = temp;
                return;
            } else {
                  ITEM* temp = head;
                  while (temp->next) {
                      if (temp->next->data.prior < data.prior) {
                          ITEM* tpr = temp->next;
                          temp->next = create(data);
                          temp->next->next = tpr;
                          return;
                      }
                      temp = temp->next;
                  }
                  tail->next = create(data);
                  tail = tail->next;
            }
        } else {
              head = create(data);
              tail = head;
        }
    }
    T pop() {
        if (head) {
            ITEM* temp = head->next;
            T data = head->data;
            delete head;
            head = temp;
            return data;
        } else {
              throw std::string(" Empty ! ");
        }
    }

 private:
    TPQueue::ITEM* create(const T& data) {
        ITEM* item = new ITEM;
        item->data = data;
        item->next = nullptr;
        return item;
    }
    ITEM* head;
    ITEM* tail;
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
