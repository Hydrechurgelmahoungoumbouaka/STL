#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Programa
{
    string nome;
    string tipo;
    int prioridade;
    int carga;
    int iteracao_inicio;
    int ultimo_uso;

    Programa() : prioridade(0), carga(0), iteracao_inicio(-1), ultimo_uso(-1) {}
};

struct ComparadorSO
{
    bool operator()(const Programa &a, const Programa &b)
    {

        if (a.prioridade != b.prioridade)
        {
            return a.prioridade < b.prioridade;
        }

        if (a.carga != b.carga)
        {
            return a.carga > b.carga;
        }
        return a.nome > b.nome;
    }
};

struct ComparadorUSER
{
    bool operator()(const Programa &a, const Programa &b)
    {

        if (a.prioridade != b.prioridade)
        {
            return a.prioridade < b.prioridade;
        }

        if (a.ultimo_uso != b.ultimo_uso)
        {
            return a.ultimo_uso > b.ultimo_uso;
        }

        return a.nome > b.nome;
    }
};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n))
        return 0;

    vector<Programa> novos_programas(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> novos_programas[i].nome >> novos_programas[i].tipo >> novos_programas[i].prioridade >> novos_programas[i].carga >> novos_programas[i].iteracao_inicio;
        novos_programas[i].ultimo_uso = -1;
    }

    queue<Programa> fila_RT;
    priority_queue<Programa, vector<Programa>, ComparadorSO> fila_SO;
    priority_queue<Programa, vector<Programa>, ComparadorUSER> fila_USER;

    int iteracao = 0;
    int programas_concluidos = 0;
    int ultima_fila_usada = 0;

    while (programas_concluidos < n)
    {

        for (int i = 0; i < n; ++i)
        {
            if (novos_programas[i].iteracao_inicio == iteracao)
            {
                if (novos_programas[i].tipo == "RT")
                {
                    fila_RT.push(novos_programas[i]);
                }
                else if (novos_programas[i].tipo == "SO")
                {
                    fila_SO.push(novos_programas[i]);
                }
                else if (novos_programas[i].tipo == "USER")
                {
                    fila_USER.push(novos_programas[i]);
                }
            }
        }

        bool executou = false;
        Programa atual;
        int fila_escolhida = 0;

        if (!fila_RT.empty())
        {
            atual = fila_RT.front();
            fila_RT.pop();
            fila_escolhida = 1;
            executou = true;
        }

        else if (!fila_SO.empty() || !fila_USER.empty())
        {

            bool vez_do_SO = true;
            if (ultima_fila_usada == 1)
            {
                vez_do_SO = false;
            }
            else if (ultima_fila_usada == 2)
            {
                vez_do_SO = true;
            }

            if (vez_do_SO)
            {
                if (!fila_SO.empty())
                {
                    atual = fila_SO.top();
                    fila_SO.pop();
                    fila_escolhida = 2;
                    ultima_fila_usada = 1;
                }
                else
                {

                    atual = fila_USER.top();
                    fila_USER.pop();
                    fila_escolhida = 3;
                    ultima_fila_usada = 2;
                }
            }
            else
            {
                if (!fila_USER.empty())
                {
                    atual = fila_USER.top();
                    fila_USER.pop();
                    fila_escolhida = 3;
                    ultima_fila_usada = 2;
                }
                else
                {

                    atual = fila_SO.top();
                    fila_SO.pop();
                    fila_escolhida = 2;
                    ultima_fila_usada = 1;
                }
            }
            executou = true;
        }

        if (executou)
        {
            atual.carga--;
            if (atual.carga == 0)
            {

                cout << atual.nome << " " << iteracao << "\n";
                programas_concluidos++;
            }
            else
            {

                atual.ultimo_uso = iteracao;
                if (fila_escolhida == 1)
                {
                    fila_RT.push(atual);
                }
                else if (fila_escolhida == 2)
                {
                    fila_SO.push(atual);
                }
                else if (fila_escolhida == 3)
                {
                    fila_USER.push(atual);
                }
            }
        }

        iteracao++;
    }

    return 0;
}