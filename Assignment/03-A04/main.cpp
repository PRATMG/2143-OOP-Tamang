
//////////////////////////////////////////////////////////////////////////////
//                    
// Author:           Prakash Tamang
// Email:            pratmg2@gmail.com
// Label:            A04
// Title:            Commenting Code
// Course:           CMPS 2143
// Semester:         Fall 2021
//
// Description:
//       We are commenting this code, given by Professor Griffin.
//
// Usage:
//       just commenting, no uses right now       
//
// Files: main.cpp
//
//////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

//////////////////////////////////////////////////////////////////////////////
 // CircularArrayQue
 // 
 // Description:
 //    This class executes array based circular queue which eliminates front items
 //    by inserting items at the end.
 // 
 // Public Methods:
 //      constructor   CircularArrayQue()
 //      constructor   CircularArrayQue(int size)
 //      void          Push(int item)
 //      int           Pop()
 // 
 // Private Methods:
 //      void           init(int size = 0)
 //      bool           Full()
 // 
 // 
 // Usage: 
 // 
 //     CircularArrayQue()            // makes queue of size ()
 //     CircularArrayQue(int size)    // makes given queue of size () 
 //     Push(int item)                // push int items
 //     Pop()                         // pop off int items
 //     
//////////////////////////////////////////////////////////////////////////////

class CircularArrayQue
{
private:
    int *Container;             // Created pointer to desiginate array
    int Front;                  // Front file
    int Rear;                   // Rear file
    int QueSize;                // Queue items
    int CurrentSize;            // Queue size

     
    void init(int size = 0)
    {
        Front = Rear = CurrentSize = 0;     // sets all value to 0 with exception of QueSize
        QueSize = size;                     // available size
    }

    bool Full()
    {
        return CurrentSize == QueSize;      // determines whether CurrentSize is equal to QueSize
    }

public:
    //////////////////////////////////////////////////////////////////////////////
    // Public : CircularArrayQue
    // 
    // Description:
    //      Constructs queue of value 10
    // 
    // Params:
    //      none
    // 
    // Returns:
    //      none
    ///////////////////////////////////////////////////////////////////////////////

    CircularArrayQue()
    {
        Container = new int[10];        //initial size 10
        init(10);
    }

    //////////////////////////////////////////////////////////////////////////////
    // Public : CircularArrayQue
    // 
    // Description:
    //      Constructs queue of empty value.
    // 
    // Params:
    //      none
    // 
    // Returns:
    //      none
    ///////////////////////////////////////////////////////////////////////////////
     
    CircularArrayQue(int size)
    {
        Container = new int[size];
        init(size);
    }

     ///////////////////////////////////////////////////////////////////////////////
     // Public : Push
     //
     // Description:
     //     push an item to the end
     //
     // Params:
     //     int : item pushed to the end of the queue
     //
     // Returns:
     //     none
    ///////////////////////////////////////////////////////////////////////////////

    void Push(int item)
    {
        if (!Full())
        {
            Container[Rear] = item;                // adds item to rear
            Rear = (Rear + 1) % QueSize;           // moves rear position
            CurrentSize++;                         // increase the current size
        }
        else
        {
            cout << "FULL!!!!" << endl;
        }
    }

     ///////////////////////////////////////////////////////////////////////////////
     // Public : Pop
     //
     // Description:
     //     eliminates item at front
     //
     // Params:
     //     none
     //
     // Returns:
     //      int : item from removed
     ///////////////////////////////////////////////////////////////////////////////

    int Pop()
    {
        int temp = Container[Front];                                        // assigns temp value
        Front = (Front + 1) % QueSize;                                      // moves to the front
        CurrentSize--;
        return temp;
    }
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other); // gives ostream access to private
};

     ///////////////////////////////////////////////////////////////////////////////
     // operator<<
     //
     // Description:
     //     compiles and cout the queue value
     //
     // Params:
     //    ostream: outfile
     //    const  : queue (const so it cant be changed)
     // 
     // Returns:
     //      ostream : outfile
     //
     ///////////////////////////////////////////////////////////////////////////////

ostream &operator<<(ostream &os, const CircularArrayQue &other)
{

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize)
    {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 * 
 */

int main()
{
    CircularArrayQue C1(5);                     // creates CircularArrayQue of size 5

    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    C1.Push(1);                                 // push value 1 onto queue
    C1.Push(2);                                 // push value 2 onto queue
    C1.Push(3);                                 // push value 3 onto queue
    // C1.Push(6);
    // C1.Push(7);
    cout << C1 << endl;                         // prints values of queue

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;                         // again prints values of queue
}

//end
