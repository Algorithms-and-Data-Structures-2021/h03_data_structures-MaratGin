#include "linked_dequeue.hpp"

#include <stdexcept>  // logic_error

namespace itis {

void LinkedDequeue::Enqueue(Element e) {

  // TODO: напишите здесь свой код ...
  auto node= new DoublyNode(e, nullptr, nullptr);
    if (size_==0){
        front_=node;
        back_=node;
    } else{

        back_->previous=node;
        node->next=back_;
        back_=node;
    }
    size_++;
}

void LinkedDequeue::EnqueueFront(Element e) {
    if (size_==0){
        Enqueue(e);
    } else{
        auto a= new DoublyNode(e,front_, nullptr);
        front_->next=a;
        front_=a;
        size_++;
    }
  // TODO: напишите здесь свой код ...
}

void LinkedDequeue::Dequeue() {
  if (size_ == 0) {
    throw std::logic_error("cannot not dequeue from empty queue");
  }
DoublyNode *delete_node=front_;
  front_=front_->previous;
    if (front_!= nullptr){
        front_->next= nullptr;
    } else{
        back_= nullptr;
    }
    delete delete_node;
    size_--;
  // TODO: напишите здесь свой код ...
}

void LinkedDequeue::DequeueBack() {
  if (size_ == 0) {
    throw std::logic_error("cannot not dequeue from empty queue");
  }
DoublyNode *delete_node=back_;
  back_=back_->next;
    if (back_== nullptr){
        front_= nullptr;
    } else{
        back_->previous= nullptr;
    }
    size_--;
    delete delete_node;
  // TODO: напишите здесь свой код ...
}

void LinkedDequeue::Clear() {
    for (DoublyNode *curr=front_;curr!= nullptr;) {
        auto delete_node=curr;
        curr=curr->previous;
        delete delete_node;

    }
    front_= nullptr;
    back_= nullptr;
    size_=0;
  // TODO: напишите здесь свой код ...

}

// === РЕАЛИЗОВАНО ===

LinkedDequeue::~LinkedDequeue() {
  Clear();
}

std::optional<Element> LinkedDequeue::front() const {
  return front_ == nullptr ? std::nullopt : std::make_optional(front_->data);
}

std::optional<Element> LinkedDequeue::back() const {
  return back_ == nullptr ? std::nullopt : std::make_optional(back_->data);
}

bool LinkedDequeue::IsEmpty() const {
  return size_ == 0;
}

int LinkedDequeue::size() const {
  return size_;
}

// === НЕОБХОДИМО ДЛЯ ТЕСТИРОВАНИЯ ===

std::ostream &operator<<(std::ostream &os, const LinkedDequeue &queue) {
  os << "size: " << queue.size_ << '\n';
  for (auto current_node = queue.front_; current_node != nullptr; current_node = current_node->previous) {
    if (current_node == queue.front_) os << "[FRONT] ";
    if (current_node == queue.back_) os << "[BACK] ";
    os << enum2str(current_node->data) << '\n';
  }
  return os;
}

}  // namespace itis
