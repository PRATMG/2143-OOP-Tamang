/*********************
*  Author:       PRAKASH TAMANG
*  Title:           MyVector CLASS
*  Course:           2143-OOP
*  Semester:         Fall 2021
*
*  Description:
*        to create a more robust MyVector class that will include more functionality.we have to write additional methods to
*   add values, remove values, and maintain sorted values if needed.
*
*  Usage:
*         no usage for now just adding robust class.
*********************/

#include <iostream>
#include <string>
#include <fstream>
#include "myvector.hpp"

using namespace std;

int main()
{
ofstream ofile;
    ofile.open("test.out");
    ofile << "PRAKASH TAMANG" << endl
          << "September 10, 2021" << endl
          << "OOP Fall 2143" << endl
          << endl;

        
    int x = 0;

    MyVector v1;
    v1.pushFront(18);
    v1.pushFront(20);
    v1.pushFront(25);
    v1.pushRear(18);
    v1.pushRear(20);
    v1.pushRear(25);
    v1.print();
    //[25, 20, 18, 18, 20, 25]

    int A[] = {11, 25, 33, 47, 51};
    MyVector v2(A, 5);
    v2.print();
    // [11, 25, 33, 47, 51]

    v2.pushFront(9);
    //v2.inOrderPush(27);
    v2.pushRear(63);
    v2.print();
    // [9, 11, 25, 27, 33, 47, 51, 63]

    v1.pushRear(v2);
    v1.print();
    // [25, 20, 18, 18, 20, 25, 9, 11, 25, 27, 33, 47, 51, 63]

    x = v1.popFront();
    x = v1.popFront();
    x = v1.popFront();
    v1.print();
    // [18, 20, 25, 9, 11, 25, 27, 33, 47, 51, 63]
    cout << x << endl;
    // 18

    x = v1.popRear();
    x = v1.popRear();
    x = v1.popRear();
    v1.print();
    // [18, 20, 25, 9, 11, 25, 27, 33]
    cout << x << endl;
    // 47

    x = v2.popAt(3);
    v2.print();
    //[9, 11, 25, 33, 47, 51, 63]
   cout << x << endl;
    // 27

    x = v2.find(51);
    cout << x << endl;
    // 5

    //x = v2.find(99);
    cout << x << endl;
    // -1

    MyVector v3(v1);
    v3.print();
    // [18, 20, 25, 9, 11, 25, 27, 33]

    v3.pushFront(v2);
    v3.print();
    //[9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]

    MyVector v4("input.dat");
    v4.print();
    v4.pushRear(v3);
    // // [56, 61, 97, 66, 83, 25, 26, 11, 53, 49, 62, 18, 10, 18,
    // // 14, 3, 4, 23, 18, 24, 26, 27, 54, 14, 12, 45, 65, 98,
    // // 56, 97, 15, 84, 98, 9, 11, 25, 33, 47, 51, 63, 18, 20, 25,
    // // 9, 11, 25, 27, 33]
    // //
}
