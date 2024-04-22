#include <iostream>
using namespace std;

namespace test
{
    template <typename T>
    void reverse(T arr[], int size)
    {
        int left = 0;
        int right = size - 1;

        while (left < right)
        {
            T temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    };
};

int main()
{
    int fop[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < 10; i++)
    {
        cout << fop[i];
    }
    cout << endl;
    test::reverse(fop, 10);

    for (int i = 0; i < 10; i++)
    {
        cout << fop[i];
    }
}
