#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cin.ignore();
    stack<string> pilha;
    for (int i = 0; i < n; i++)
    {
        string comando;
        cin >> comando;
        cin.ignore();

        if (comando == "PUSH")
        {
            string palavra;
            cin >> palavra;
            pilha.push(palavra);
        }
        else if (comando == "POP")
        {
            cout << pilha.top() << endl;
            pilha.pop();
        }
    }

    return 0;
}
