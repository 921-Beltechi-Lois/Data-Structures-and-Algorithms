#include "Stack.h"
#include "ShortTest.h"
#include "ExtendedTest.h"
#include <iostream>
#include <assert.h>
using namespace std;

int main() {
	testAll();
	testAllExtended();

//    Stack s(3);
//    s.push(3);
//    s.push(4);
//    s.push(5);
//    s.printStack(s);

    // tests
    Stack test(3);
    assert(test.isEmpty() == true);
    test.push(3);
    assert(test.top() == 3);
    test.push(5);
    assert(test.top() == 5);
    test.push(6);
    assert(test.top() == 6);
    test.printStack(test);


	cout << "That's all" << endl;
	system("pause");
}