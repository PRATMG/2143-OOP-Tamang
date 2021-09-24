
/*************************************************************************
*
*  Author:           prakash Tamang
*  Email:            pratmg2@gmail.com
*  Label:           06- P02
*  Title:            MyVector2
*  Course:           CMPS 2143-OOP
*  Semester:         Fall 2021
*
*  Description:
*        previous assignment robust Vector project with implementing overloading operators.
*
*  Files:
*     main.cpp     : driver program
*     output.txt
*
************************************************************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Node
//             +--------+      +--------+      +--------+      +--------+
//   Head ---> |        | ---> |        | ---> |        | ---> |        | ---> NULL
//   NULL <--- |        | <--- |        | <--- |        | <--- |        |
//             +--------+      +--------+      +--------+      +--------+

template <class S>
class MyVector {
  
  private:

    // Node for our linked list
    struct node {
      S data;  // data value (could be a lot more values)

      node* next;       // points to the next node
      node* previous;   // points to the previous node

      // constructor to make adding values easy
      node(S x, node* n = nullptr, node* p = nullptr) {
          data = x;
          next = n;
          previous = p;
      }
    };

    node* head;      // Indicates head of the vector
    node* tail;      // indicates tail of the vector

    int currentSize; //indicates current size of the vector


  public:

/*
 *
 *@brief to initialize object of MyVector
 *@param none
 *@returns none
 *
 */

    MyVector() {
      head = nullptr;    // the head of the vector
      tail = nullptr;    // the tail of the vector

      currentSize = 0;   //the current size of the vector
    }
    
    /*
     *@brief to initialize object of MyVector with array
     *@param int *A - array
     *@param int size - array size
     *@return none
     */

    MyVector(S *A, int size) {
      head = nullptr;    // the head of the vector
      tail = nullptr;    // the tail of the vector

      currentSize = 0;   //the current size

      for(int i = 0; i < size; i++) {
        pushRear(A[i]);
      }
    }
    /*
     *@brief to initializes object of MyVector and add items from file.
     *@param string FileName
     *@return none
     *
     */

    MyVector(string FileName) {
      head = nullptr;    // the head of the vector
      tail = nullptr;    // the tail of the vector

      currentSize = 0;   //the current size of the vector

      ifstream fin;
      fin.open(FileName);

      int temp;
      while(!fin.eof()) {
        fin >> temp;
        pushRear(temp);
      }

    }
    
    /*
     *@brief same as above but places different MyVector object
     *@param MyVector &V1
     *@return none
     *
     */


    MyVector(const MyVector &V1) {
      head = nullptr;    // the head of the vector
      tail = nullptr;    // the tail of the vector

      currentSize = 0;   //the current size

      node* temp = V1.head;

      while(temp != nullptr) {
        pushRear(temp->data);
        temp = temp->next;
      }
    }

    /*
     *@brief to deletes all free memory
     *@param none
     *@return none
     *
     */

    ~MyVector() {
      node* temp = head;
      node* garbage;

      while(temp != nullptr) {
        garbage = temp;
        temp = temp->next;
        delete garbage;

      }
    }

    /*
     *@brief to write out the current size of the array
     *@param none
     *@return none
     *
     */

    void printSize() {
      cout << currentSize << '\n';
    }

    /*
     *@brief to add integers to the front of the vector
     *@param int num
     *@return void
     *
     */

    void pushFront(S num) {
      
      // if there are no values in the vector
      if(head == nullptr) {
        head = new node(num); //make head point to the value
        tail = head;
                              
        currentSize++;
      }
      else {
        head->previous = new node(num, head);
        head = head->previous;
                                             
        currentSize++;   //increment in size
      }
    }

    /*
     *@brief to add a seperate vector infront of the vector
     *@param MyVector
     *@return void
     *
     */

    void pushFront(MyVector &vector) {
      node* temp = vector.tail;

      //while loop to add items
      while(temp) {
        pushFront(temp->data); //push the data to the end

        temp = temp->previous;

      }
    }

    /*
     *@brief to add data in back of the vector
     *@param int mun
     *@return void
     *
     */
    
    void pushRear(S num) {
      
 
      if(head == nullptr) {
        head = new node(num); //make head point to the value
        tail = head;
                              
        currentSize++;        //increment in size
      }
      else{
        tail->next = new node(num, nullptr, tail);
                                                 
        tail = tail->next;
        currentSize++;       //increment in size
      }
    }
    /*
     *@brief to add value from an array to back of the vector
     *@param S arr
     *int int index
     *@return void
     *
     */

    void push_rear(S arr, int index) {
      for(int i = 0; i < index; i++) {
        pushBack(arr[i]);
      }
    }


    void pushRear(MyVector &vector) {

      node* temp = vector.head; // to traverse the list

      //adds items from the old list to the new one
      while(temp) {
        pushRear(temp->data);  //to push the data to the end of the list

        temp = temp->next;

      }
      
    }
    
    /*
     *@brief to add an integer
     *@param int sub
     *@param S num
     *@return bool
     *
     */


    bool pushAt(int sub, S num) {
      
      
      if(sub > currentSize || sub < 0) {
        return false;
      }
      else {

        if(sub == 0) {
          pushFront(num);
 
        }
        else if (sub == currentSize) {
          pushRear(num);

        }

        else {
          
          node* temp = head; // to traverse the list

          for(int i = 0; i < sub; i++) {
            temp = temp->next;
          }

          node* temp2 = temp->previous;
          temp->previous = new node(num, temp, temp2);
          temp2->next = temp->previous;
          currentSize++;               //increment in size
                                       
        }
        
        return true;
      }
      
    }
    
    void inOrderPush(S num) {

      int sub = 0;

      if(head->data < tail->data) {
        node* temp = head;
        while(temp->data < num) {
          sub++;              // increment in subscript
          if(sub == currentSize) {
            break;
          }
          temp = temp->next;  // to move down the list
        }
        pushAt(sub, num);
      }
      else if(head > tail) {
        node* temp = head;
        while(temp->data > num) {
          sub++;              // increase in subscript
          if(sub == currentSize) {
            break;
          }
          temp = temp->next;  // to move down the list
        }
        pushAt(sub, num);
      }
    }

    /*
     *@brief to remove an integer from the front of the list
     *@param none
     *
     */

    S popFront() {
      int num = head->data;       // to remove integer

      node* temp = head;
      head = head->next;
      head->previous = nullptr;
      delete temp;

      currentSize--;              //decrement in size

      return num;
    }
    
    /*
     *@brief to remove data from the back of the list
     *@param none
     *@return
     *
     */

    S popRear() {
      int num = tail->data;

      node* temp = tail;
      tail = tail->previous;
      tail->next = nullptr;
      delete temp;

      currentSize--;            //decrement in size

      return num;
    }
    
    S popAt(int sub) {
      S num;    //to hold deleted data being removed

 
      if(sub >= currentSize || sub < 0) {
        return false;
      }
      else {
        if(sub == 0) {
          num = popFront();
        }
        else if (sub == currentSize-1) {
          num = popRear();
        }

        else {
          
          node* temp = head;

          for(int i = 0; i < sub; i++) {
            temp = temp->next;
          }
          num = temp->data;


          node* garbage = temp;
          node* temp2 = temp->previous;
          temp = garbage->next;
          temp2->next = temp;
          temp->previous = temp2;
          delete garbage;
          
        }
        currentSize--;   //increment in size
        return num;
      }

    }
    
    /*
     *@brief to find the subscript of integer.
     *@param S val
     *@return int
     *
     */


    int find(S val) {
      int sub = 0;

      node* temp = head;
      while(temp != nullptr && temp->data != val) {
        temp = temp->next;
        sub++;

      }
      if(sub == currentSize) {
        sub = -1;
      }
      
      return sub;
    }
    
    /*
     *@brief to print the vector from front to back
     *@param ofstream &fout
     *@return void
     *
     */

    void print(ofstream &fout) {
      node* temp = head;

      cout << "[";
      while(temp->next != nullptr) {
        cout << temp->data << ", ";
        temp = temp->next;
      }
      cout << temp->data << "]\n";

      temp = head;
      fout << "[";
      while(temp->next != nullptr) {
        fout << temp->data << ", ";
        temp = temp->next;
      }
      fout << temp->data << "]\n";
      
    }
    
    /*
     *@brief to print the vector from back to front
     *@param none
     *@return void
     *
     */


    void printBack(ofstream &fout) {
      node* temp = tail;

      cout << "[";
      while(temp->previous != nullptr) {
        cout << temp->data << ", ";
        temp = temp->previous;
      }
      cout << temp->data << "]\n";

      temp = tail;
      fout << "[";
      while(temp->previous != nullptr) {
        fout << temp->data << ", ";
        temp = temp->previous;
      }
      fout << temp->data << "]\n";
    }
    
    /*
     *@brief to treat MyVector as an array
     *@param int sub
     *
     */


    S &operator[](int sub) {
      node* temp = this->head;
      
      //  not in bounds
      if(sub >=this->currentSize || sub < 0) {
        cout << "subscript is out of bounds\n";
        exit(0);
      }

      else {
        for(int i = 0; i < sub; i++) {
          temp = temp->next;
        }
      }
      return temp->data;
      
    }
    
    /*
     *@brief to write out a vector
     *@param ostream& out
     *@return the data
     *
     */


    friend ostream &operator<<(ostream& out, const MyVector& vector) {

      node* temp = vector.head; // to traverse the list

      //  to print out to the terminal
      out << "[";
      while(temp->next != nullptr) {
        out << temp->data << ", ";
        temp = temp->next;
      }
      out << temp->data << "]";

      return out;
    }

    /*
     *@brief to print out a vector
     *@param ostream& out
     *@param const MyVector
     *@return the data
     *
     */

    friend ofstream &operator<<(ofstream& out, const MyVector& vector) {

      node* temp = vector.head; //to traverse the list

      // to print out to the terminal
      out << "[";
      while(temp->next != nullptr) {
        out << temp->data << ", ";
        temp = temp->next;
      }
      out << temp->data << "]";

      return out;
    }

    /*
     *@brief to add 2 vector
     *@param MyVector&
     *@return new vector
     *
     */

    MyVector operator+(MyVector& other) {
      MyVector assigned;
      node* temp = this->head;
      node* temp2 = other.head;

      int min;

      bool otherMax = false;

      if(this->currentSize >= other.currentSize) {
        min = other.currentSize;
      }
      else {
        min = this->currentSize;
        otherMax = true;
      }

      // to add the values
      for(int i = 0; i < min; i++) {
 
        assigned.pushRear(temp->data + temp2->data);
        temp = temp->next;
        temp2 = temp2->next;
      }

      if(otherMax) {
        for(int i = min; i < other.currentSize; i++) {
          assigned.pushRear(other[i]);
          
        }
      }
      else {

        for(int i = min; i < this->currentSize; i++) {
          assigned.pushRear(temp->data);
          if(temp->next != nullptr)
            temp = temp->next;
        }
      }

      return assigned;
    }
    
    MyVector operator-(MyVector& other) {
      MyVector assigned;
      node* temp = this->head;
      node* temp2 = other.head;

      int min;

      bool otherMax = false;

      if(this->currentSize >= other.currentSize) {
        min = other.currentSize;
      }
      else {
        min = this->currentSize;
        otherMax = true;
      }

      //  to add the values
      for(int i = 0; i < min; i++) {

        assigned.pushRear(temp->data - temp2->data);
        temp = temp->next;
        temp2 = temp2->next;
      }

      // to add the rest of the "other" MyVector object
      if(otherMax) {
        for(int i = min; i < other.currentSize; i++) {
          assigned.pushRear(other[i]);
        }
      }

      else {
        for(int i = min; i < this->currentSize; i++) {
          
          assigned.pushRear(temp->data);
          if(temp->next != nullptr)
            temp = temp->next;
        }
      }

      return assigned;
    }

    /*
     *@brief to multiply two vector
     *@param MyVector&
     *@return new vector
     *
     */


    MyVector operator*(MyVector& other) {
      MyVector assigned;
      node* temp = this->head;
      node* temp2 = other.head;

      int min;

      bool otherMax = false;

      if(this->currentSize >= other.currentSize) {
        min = other.currentSize;
      }
      else {
        min = this->currentSize;
        otherMax = true;
      }

      // to add the values
      for(int i = 0; i < min; i++) {

        assigned.pushRear(temp->data * temp2->data);
        temp = temp->next;
        temp2 = temp2->next;
      }
 
      if(otherMax) {
        for(int i = min; i < other.currentSize; i++) {
          assigned.pushRear(other[i]);
        }
      }
      else {
        for(int i = min; i < this->currentSize; i++) {
          
          assigned.pushRear(temp->data);
          if(temp->next != nullptr)
            temp = temp->next;
        }
      }

      return assigned;
    }
    /*
     *@brief to multiply two vector
     *@param MyVector&
     *@return new vector
     *
     */

    MyVector operator/(MyVector& other) {
      MyVector assigned;
      node* temp = this->head;
      node* temp2 = other.head;

      int min;    // indicate smallest vector

      bool otherMax = false;

      if(this->currentSize >= other.currentSize) {
        min = other.currentSize;
      }
      else {
        min = this->currentSize;
        otherMax = true;
      }

      // to add the values
      for(int i = 0; i < min; i++) {


        if(temp2->data == 0){
          cout<<"error!"<<endl;
          exit(0);
        }
        assigned.pushRear(temp->data / temp2->data);
        temp = temp->next;
        temp2 = temp2->next;
      }


      if(otherMax) {
        for(int i = min; i < other.currentSize; i++) {
          assigned.pushRear(other[i]);
        }
      }

      else {
        for(int i = min; i < this->currentSize; i++) {
          
          assigned.pushRear(temp->data);
          if(temp->next != nullptr)
            temp = temp->next;
        }
      }

      return assigned;
    }

    /*
     *@brief to verify if two vectors are same
     *@param MyVector&
     *
     */

    bool operator==(MyVector& other) {

      node* temp = this->head;
      node* temp2 = other.head;

      // to check size
      if(this->currentSize != other.currentSize) {
        return false;
      }
      else {
        // to traverse the list
        while(temp) {
   
          if(temp->data != temp2->data) {
            return false;
          }
          temp = temp->next;
          temp2 = temp2->next;
        }
      }
      return true;
    }


    MyVector &operator=(const MyVector& assigner) {

      
      node* temp = head;
      node* garbage;
      while(temp != nullptr) {
        garbage = temp;
        temp = temp->next;
        delete garbage;
      }
      head = tail = nullptr;

      node* currentSemp = assigner.head;
    

      for (int i = 0; i < assigner.currentSize; i++) {
        pushRear(currentSemp->data);
        currentSemp = currentSemp->next;
      }


      this->currentSize = assigner.currentSize;

      return *this;
    }

};


int main() {

   ofstream fout;
  fout.open("output.txt");

  int a1[] = { 1, 2, 3, 4, 5 };
  int a2[] = { 10, 20, 30 };

  MyVector<int> v1(a1, 5);
  MyVector<int> v2(a2, 3);

  cout << v1[2] << endl;
  // writes out 3

  v1[4] = 9;
  // v1 now = [1,2,3,4,9]

  cout << v1 << endl;
  // writes out [1,2,3,4,9]` to console.

  fout << v1 << endl;
  // writes out [1,2,3,4,9]` to your output file.

  MyVector v3 = v1 + v2;
  cout << v3 << endl;
  // writes out [11,22,33,4,9]` to console.

  v3 = v1 - v2;
  cout << v3 << endl;
  // writes out [-9,-18,-27,4,9]` to console.

  v3 = v2 - v1;
  cout << v3 << endl;
  // writes out [9,18,27,4,9]` to console.

  v3 = v2 * v1;
  cout << v3 << endl;
  // writes out [10,40,90,4,9]` to console.

  v3 = v1 * v2;
  cout << v3 << endl;
  // writes out [10,40,90,4,9]` to console.

  v3 = v1 / v2;
  cout << v3 << endl;
  // writes out [0,0,0,4,9]` to console.

  v3 = v2 / v1;
  cout << v3 << endl;
  // writes out [10,10,10,4,9]` to console.

  cout << (v2 == v1) << endl;
  // writes 0 to console (false)

  MyVector<int> v4 = v1;
  cout << (v4 == v1) << endl;
  // writes 1 to console (true)

}
