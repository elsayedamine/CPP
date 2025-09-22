#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;

    // Push some elements
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top: " << mstack.top() << std::endl;

    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    mstack.push(42);
    mstack.push(99);

    // Forward iteration
    std::cout << "Forward iteration:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << std::endl;

    // Reverse iteration
    std::cout << "Reverse iteration:" << std::endl;
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
        std::cout << *rit << std::endl;

    // Copy constructor test
    MutantStack<int> copy(mstack);
    std::cout << "Copy iteration:" << std::endl;
    for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it)
        std::cout << *it << std::endl;

    // Assignment operator test
    MutantStack<int> assign;
    assign = mstack;
    std::cout << "Assignment iteration:" << std::endl;
    for (MutantStack<int>::iterator it = assign.begin(); it != assign.end(); ++it)
        std::cout << *it << std::endl;

    // Const iteration
    const MutantStack<int> cmstack = mstack;
    std::cout << "Const iteration:" << std::endl;
    for (MutantStack<int>::const_iterator it = cmstack.begin(); it != cmstack.end(); ++it)
        std::cout << *it << std::endl;

    // Compare with std::list
    std::list<int> lst;
    for (MutantStack<int>::const_iterator it = cmstack.begin(); it != cmstack.end(); ++it)
        lst.push_back(*it);

    std::cout << "Compare with std::list:" << std::endl;
    MutantStack<int>::const_iterator mit = cmstack.begin();
    std::list<int>::iterator lit = lst.begin();
    while (mit != cmstack.end() && lit != lst.end()) {
        std::cout << *mit << " == " << *lit << std::endl;
        ++mit;
        ++lit;
    }

    // Stack compatibility
    std::stack<int> s(mstack);
    std::cout << "Stack top from std::stack: " << s.top() << std::endl;

    return 0;
}
