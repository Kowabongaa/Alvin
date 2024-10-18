#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void printNextGreaterElement(vector<int>& arr) 
{
    int n = arr.size();
    stack<int> s;
    vector<int> nge(n);
  
    for (int i = n - 1; i >= 0; i--) 
    {
        while (!s.empty() && s.top() <= arr[i]) 
        {
            s.pop();
        }
      
        if (s.empty()) 
        {
            nge[i] = -1;
        } else 
        {
            nge[i] = s.top();
        }

        s.push(arr[i]);
    }

    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " --> " << nge[i] << endl;
    }
}

int main() 
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }
  
    cout << "Next Greater Elements:" << endl;
    printNextGreaterElement(arr);

    return 0;
}
