#include <string>
#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;

typedef struct hashTables
{
    string nome;
    string mensagem;
} tHashTables;

tHashTables *hashTables_construct(string nome, string mensagem)
{
    tHashTables *ht = new tHashTables;
    ht->nome = nome;
    ht->mensagem = mensagem;
    return ht;
}

void hashTables_destroy(tHashTables *ht)
{
    delete ht;
}

int main(int argc, char const *argv[])
{
    int n, tam;
    cin >> n >> tam;
    cin.ignore();

    unordered_map<string, tHashTables *> tabela;
    tabela.reserve(tam);
    
    for (int i = 0; i < n; i++)
    {
        string comando;
        cin >> comando;

        if (comando == "SET")
        {
            string nome, mensagem;
            
            cin >> nome;
            cin.ignore();
            getline(cin, mensagem);

            if (tabela.find(nome) != tabela.end())
            {
                hashTables_destroy(tabela[nome]);
            }
            
            tabela[nome] = hashTables_construct(nome, mensagem);
        }
        else if (comando == "GET")
        {
            string nome;
            cin >> nome;

            if (tabela.find(nome) != tabela.end())
            {
                cout << tabela[nome]->mensagem << endl;
            }
        }
    }

    for (auto it = tabela.begin(); it != tabela.end(); it++)
    {
        hashTables_destroy(it->second);
    }

    return 0;
}
