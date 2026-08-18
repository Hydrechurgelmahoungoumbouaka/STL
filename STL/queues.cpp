#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{

    int n;
    cin >> n;
    cin.ignore();
    queue<string> fila;
    for (int i = 0; i < n; i++)
    {
        string comando;
        cin >> comando;
        cin.ignore();
        if (comando == "ENQUEUE")
        {
            string palavras;
            cin >> palavras;
            fila.push(palavras);
        }
        else if (comando == "DEQUEUE")
        {
            cout << fila.front() << endl;
            fila.pop();
        }
    }

    return 0;
}
