#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cin.ignore();

    map<string, int> palavras;

    for (int i = 0; i < n; i++)
    {
        string n_palavra;
        cin >> n_palavra;
        palavras[n_palavra]++;
    }
    for (auto it = palavras.begin(); it != palavras.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}
