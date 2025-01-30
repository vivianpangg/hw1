  #include <cstddef>
  #include <stdexcept>
  #include "ulliststr.h"

  ULListStr::ULListStr()
  {
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
  }

  ULListStr::~ULListStr()
  {
    clear();
  }

  bool ULListStr::empty() const
  {
    return size_ == 0;
  }

  size_t ULListStr::size() const
  {
    return size_;
  }

  // WRITE YOUR CODE HERE

  
  void ULListStr::push_back(const std::string& val){
    
    if(tail_ == nullptr || tail_->last ==ARRSIZE){
      Item* newItem = new Item();
      newItem->prev = tail_;
      newItem->next = nullptr;

      newItem->first = 0;
      

      newItem->val[0] = val;
      newItem->last = 1;

      if(tail_ != nullptr){
        tail_->next = newItem;
      }
      tail_ = newItem;

      if(head_==nullptr){
        head_=tail_;
      }
    }else if(tail_->last < ARRSIZE){
      tail_->val[tail_->last] = val;
      tail_->last++;
    }

    size_++;

  }

 
  /* Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
   */
  void ULListStr::push_front(const std::string& val){
    //doesnt exist or at capacity
    if(head_ == nullptr || head_->first==0){
      Item* newItem = new Item();
      newItem->prev = nullptr;
      newItem->next = head_;

      newItem->val[ARRSIZE-1]=val;
      newItem->last = ARRSIZE;
      newItem->first = ARRSIZE-1;

      if(head_!=nullptr){
        head_->prev = newItem;
      }
      head_= newItem;
      if(tail_==nullptr){
        tail_ = head_;  
      }
    }else if(head_->first > 0){
      head_->first--;
      head_->val[head_->first] = val;
    }

    size_++;
  }
  /**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_back(){
    if(tail_ == nullptr){
      return;
    }

    //if(tail_->last > 0){
      tail_->last--;
      size_--;
   // }

    if(tail_->first ==tail_->last){
      Item* temp = tail_;
      tail_ = tail_->prev;

      if(tail_!= nullptr){
        tail_->next = nullptr;
      }else{
        head_ = nullptr;
      }
      delete temp;
    }
  }

  /**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_front(){
    if(head_ == nullptr){
        return;
    }

    head_->first++;
    size_--;

    if(head_->first == head_->last){
      Item* temp = head_;
      head_ = head_->next;

      if(head_!= nullptr){
        head_->prev = nullptr;
      }else{
        tail_ = nullptr;
      }
      
      delete temp;
    }
  }

  /**
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   */
  std::string const & ULListStr::back() const{
    int loc = tail_->last;
    loc--;
    return tail_->val[loc];
  }

  /**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   */
  std::string const & ULListStr::front() const{
    int loc = head_->first;
    return head_->val[loc];
  }

  /** 
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   *   - MUST RUN in O(n) 
   */
  std::string* ULListStr::getValAtLoc(size_t loc) const{
    if(loc >= size_){
        return nullptr;
    }else{
      int currLoc =0;
      Item* temp = head_;
      while(temp != nullptr){
          for(size_t i = temp->first; i < temp->last; i++){
            if(currLoc == loc){
              return &(temp->val[i]);
            }
            currLoc++;
          }

          temp = temp->next;
      }

      return nullptr;
    }
    
  }
 

  void ULListStr::set(size_t loc, const std::string& val)
  {
    std::string* ptr = getValAtLoc(loc);
    if(ptr == NULL){
      throw std::invalid_argument("Bad location");
    }
    *ptr = val;
  }

  std::string& ULListStr::get(size_t loc)
  {
    std::string* ptr = getValAtLoc(loc);
    if(ptr == NULL){
      throw std::invalid_argument("Bad location");
    }
    return *ptr;
  }

  std::string const & ULListStr::get(size_t loc) const
  {
    std::string* ptr = getValAtLoc(loc);
    if(ptr == NULL){
      throw std::invalid_argument("Bad location");
    }
    return *ptr;
  }

  void ULListStr::clear()
  {
    while(head_ != NULL){
      Item *temp = head_->next;
      delete head_;
      head_ = temp;
    }
    tail_ = NULL;
    size_ = 0;
  }
