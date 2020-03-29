#ifndef DLINK_SEQ_H_
#define DLINK_SEQ_H_
#include "seq.hh"

template <E>
class DLinkSeq : public Seq<E> {
  struct Node {
    Node* prev;
    Node* next;
    Node(Node* prev = nullptr, Node* next = nullptr): val(val), prev(prev), next(next) {}
  };
  struct DNode : public Node {
    E val;
    DNode(E& val, Node* prev = nullptr, Node* next = nul
lptr): Node(prev, next), val(val) {}
  };
public:
  Node m_head{&m_head, &m_head};
  
  DLinkSeq() {}
  //no copy constructor
  DLinkSeq(const DLinkSeq& other) {

  };

  //no assignment operator
  void operator=(const DLinkSeq&) = delete; 

  /** base destructor */
  virtual ~DLinkSeq() {} 
  
  /** clear contents from this seq, making it empty. */
  //to do
  virtual void clear() = 0;
  
  /** add item to the start of this seq. */
  //to do
  virtual void unshift(const E& item) {
    Node* temp= new DNode(item, &m_head, m_head->next);
    m_head->next->prev=temp;
    m_head->next=temp;
  }
      
  /** remove and return first item from this seq. 
   *  fails if this seq is empty.
   */
  virtual E shift() {
    if(m_head->next==m_head){
      cout << "List is empty" << std::endl;
    Node* temp = m_head->next;
    temp->next->prev = m_head;
    m_head->next = temp->next;
    return temp;
  }
  
  /** add item at the end of this seq. */
  virtual void push(const E& item) {
    Node* temp = new DNode(item, m_head->prev, &m_head);
    temp->prev->next = temp;
    temp->next->prev = temp;
    delete temp;
  };
  
  /** remove and return last item from this seq.
   *  fails if this seq is empty.
   */
  virtual E pop() {
    if (&m_head == m_head->next)
    {
        printf("pop on empty array seq");
        exit(1);
    }
    //last item in list is m head prev
    cout << m_head-> prev << std::endl;
    Node* temp = m_head->prev;
    m_head->prev = m_head->prev->prev;
    m_head->prev->next = m_head;
    //m_head -> next is position 1/0 in iteration
    cout<< "[ " << std::endl;
    Node* tmp= m_head->next;
    while (tmp->val!=nullptr) //fake head at end is only nullptr
    {
      cout << tmp->val << ", " << std::endl;
      tmp= tmp->next; //should iterate to dlink list
    }
    cout<< "]" << std::endl;
    delete tmp;
    E value= temp->val;
    delete temp;
    return value;
  };
  
  /** return number of elements in this seq. */
  virtual int size() const = 0;

  /** return an iterator initialized to start of this seq */
  virtual ConstIterPtr<E> cbegin() const = 0;

  /** return an iterator initialized to end of this seq */
  virtual ConstIterPtr<E> cend() const = 0;

}

#endif



