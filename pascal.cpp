#include <iostream>
using namespace std;

//namespace nm2
//{

class Pascals
{

public:
    Pascals(int n) {

    }
    void pascalsmethod(int n)
    {
        int arr[20][20];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (i == j || j == 0)
                {
                    arr[i][j] = 1;
                }
                else
                {
                    arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
                }

                cout << arr[i][j] << +" ";
            }
            cout << "\n";
        }
    }
};

int main()
{
    int n;

    cout << "Give the number of lines: ";
    cin >> n;
    Pascals p(n);

    p.pascalsmethod(n);

    return 0;
}
//}
