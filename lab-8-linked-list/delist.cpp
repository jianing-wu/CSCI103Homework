#include "delist.h"
#include <cstddef>

// Constructs an empty Double-Ended List
DEList::DEList() {
  head = NULL;
  tail = NULL;
  mSize = 0;
}
  // Destructor to clean-up memory of current list
DEList::~DEList() {
  DEItem* cur = head;
  while (cur != NULL) {
    DEItem* tmp = cur;
    cur = cur->next;
    delete tmp;
  }
}
  // returns a Boolean 'true' if the list is empty
bool DEList::empty() {
  return mSize == 0;
}
  // returns number of items in the list
int DEList::size() {
  return mSize;
}
  // returns front item or -1 if empty list
int DEList::front() {
  if (empty()) return -1;
  return head->val;
}
  // returns back item or -1 if empty list
int DEList::back() {
  if (empty()) return -1;
  return tail->val;
}
  // Adds a new integer to the front of the list
void DEList::push_front(int new_val) {
  DEItem* newItem = new DEItem;
  newItem->prev = NULL;
  newItem->next = NULL;
  newItem->val = new_val;
  if (empty()) {
    head = newItem;
    tail = newItem;
  } else {
    head->prev = newItem;
    newItem->next = head;
    head = newItem;
  }
  mSize++;
}
  // Adds a new integer to the back of the list
void DEList::push_back(int new_val) {
  DEItem* newItem = new DEItem;
  newItem->prev = NULL;
  newItem->next = NULL;
  newItem->val = new_val;
  if (empty()) {
    head = newItem;
    tail = newItem;
  } else { 
    tail->next = newItem;
    newItem->prev = tail;
    tail = newItem;
  }
  mSize++;
}
  // Removes the front item of the list (if it exists)
void DEList::pop_front() {
  if (empty()) {
    return;
  }
  DEItem* first = head;
  head = head->next;
  if (size() == 1) {
    tail = NULL;
  } else {
    head->prev = NULL;
  }
  delete first;
  mSize--;
}
  // Removes the back item of the list (if it exists)
void DEList::pop_back() {
  if (empty()) {
    return;
  }
  DEItem* last = tail;
  tail = tail->prev;
  if (size() == 1) {
    head = NULL;
  } else {
    tail->next = NULL;
  }
  delete last;
  mSize--;
}