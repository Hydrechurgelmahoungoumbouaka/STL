#include <iostream>
#include <string>
#include <forward_list>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    if (!(cin >> n))
    {
        return 0;
    }

    forward_list<string> playlist;

    for (int i = 0; i < n; i++)
    {
        string comando;
        cin >> comando;

        if (comando == "ADD_BEGIN")
        {
            string nome;
            cin >> nome;
            playlist.push_front(nome);
        }
        else if (comando == "ADD_AFTER")
        {
            string referencia;
            string nome;
            cin >> referencia >> nome;
            auto it = playlist.begin();
            while (it != playlist.end())
            {
                if (strcmp(it->c_str(), referencia.c_str()) == 0)
                {
                    break;
                }
                ++it;
            }

            if (it != playlist.end())
            {
                playlist.insert_after(it, nome);
            }
        }
        else if (comando == "REMOVE")
        {
            string nome;
            cin >> nome;

            auto prev = playlist.before_begin();
            auto curr = playlist.begin();
            bool achou = false;

            while (curr != playlist.end())
            {
                if (strcmp(curr->c_str(), nome.c_str()) == 0)
                {
                    achou = true;
                    break;
                }
                prev = curr;
                ++curr;
            }

            if (achou)
            {
                playlist.erase_after(prev);
            }
        }
    }

    bool primeiro = true;
    for (const string &musica : playlist)
    {
        if (!primeiro)
        {
            cout << " ";
        }
        cout << musica;
        primeiro = false;
    }
    cout << "\n";
    return 0;
}
