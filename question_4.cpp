#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int>& q) 
{
    int n = q.size();
    
    if (n % 2 != 0) 
    {
        cout << "Queue length must be even." << endl;
        return;
    }

    int halfSize = n / 2;
    queue<int> firstHalf;

    for (int i = 0; i < halfSize; i++) 
    {
        firstHalf.push(q.front());
        q.pop();
    }

    while (!firstHalf.empty()) 
    {
        q.push(firstHalf.front());
        firstHalf.pop();
        q.push(q.front());
        q.pop();
    }
}

int main() 
{
    queue<int> q;
    int n, element;
    cout << "Enter the number of elements in the queue (even length): ";
    cin >> n;
    
    if (n % 2 != 0) 
    {
        cout << "Please enter an even number of elements." << endl;
        return 0;
    }

    cout << "Enter the elements of the queue: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> element;
        q.push(element);
    }

    interleaveQueue(q);
    cout << "Interleaved queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
