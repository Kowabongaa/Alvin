#include <iostream>
#include <stack>

using namespace std;

// Recursive function to print and pop stack elements
void printAndPop(stack<int>& filoStack) 
{
    if (filoStack.empty()) 
    {
        return;
    }

    // Print the top element
    cout << filoStack.top() << " ";
    // Remove the top element
    filoStack.pop();

    // Recursive call
    printAndPop(filoStack);
}

int main() 
{
    stack<int> filoStack;
    int n, value;

    cout << "How many elements in one stack? ";
    cin >> n;

    for (int i = 0; i < n; ++i) 
    {
        cout << "Enter value #" << (i + 1) << ": ";
        cin >> value;
        filoStack.push(value);
    }

    cout << "FILO stack elements in order: ";
    printAndPop(filoStack);

    cout << endl;
    return 0;
}
