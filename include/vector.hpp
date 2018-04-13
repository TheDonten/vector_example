#include <iostream>
#include <cassert>
using namespace std;
template<typename T>
class queue_t {
private:
    struct node_t{
        node_t* next;
        T value;
    };
private:
    node_t* head;
    node_t* tail;
public:
    queue_t(){
        head = nullptr;
        tail = nullptr;
    }
    node_t* head_() const{
        return head;
    }
    node_t* tail_() const{
        return tail;
    }
    queue_t &operator =(queue_t const& other){
       if(other.head){
   node_t * node;
  while(head!=nullptr){
  node = head->next;
  delete head;
  head = node;
}
    }
     node_t* p = other.head;
     while( p!= nullptr){
         push(p->value);
         p = p->next;
           
    }
   return  *this;
}
    queue_t(queue_t const& other) : queue_t(){
     
     node_t* p = other.head;
     while( p!= nullptr){
         push(p->value);
         p = p->next;
           
    }
  
}
    void push(T  value) {
        node_t* node = new node_t;
        node->value=value;
        node->next= nullptr;
        if(head == nullptr){
            head = node;
            tail = node;
            return;
        }
       else {
            tail->next = node;
            tail = tail->next;
        }
    }
    T pop_back(){
        if(head == nullptr) throw std::logic_error("head == nullptr");
        
        T value = head->value;
        node_t* node= head->next;
        delete head;
        head = node;
        return value;
    }
void write(std::ostream & stream, node_t* head){
    node_t * p;
    p=head;
    while (p != NULL) {
        stream<<p->value<<"---";
        p = p->next;
    }
}
~queue_t(){
  node_t * node;
  while(head!=nullptr){
  node = head->next;
  delete head;
  head = node;
   }
}
};
