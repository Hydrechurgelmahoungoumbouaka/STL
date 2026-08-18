#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

typedef struct Gestao tGestao;

struct Gestao
{
    string nome;
    string categoria;
    int identificador;
    int prioridade;
};

tGestao *gestao_construct(string nome, string categoria, int id, int prio)
{
    tGestao *g = new tGestao;
    g->nome = nome;
    g->categoria = categoria;
    g->identificador = id;
    g->prioridade = prio;
    return g;
}

void gestao_destroy(tGestao *g)
{
    delete g;
}

// comparador da prioridade_queue
struct comparaPrioriade
{
    bool operator()(tGestao *a, tGestao *b)
    {
        return (a->prioridade < b->prioridade);
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cin.ignore();
    priority_queue<tGestao *, vector<tGestao *>, comparaPrioriade> fila;

    for (int i = 0; i < n; i++)
    {
        string nome, categoria;
        int id, prioridade;
        cin >> nome >> categoria >> id >> prioridade;

        fila.push(gestao_construct(nome, categoria, id, prioridade));
    }
    // imprime o restante
    while (!fila.empty())
    {
        tGestao *g = fila.top();

        cout << g->nome << " "
             << g->categoria << " "
             << g->identificador << " "
             << g->prioridade << endl;

        fila.pop();
        gestao_destroy(g);
    }

    return 0;
}
