#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    
    map<string, map<string, string>> alunos;

    for (int i = 0; i < n; i++)
    {
        string nome_aluno;
        int num_materias;
        cin >> nome_aluno >> num_materias;

        for (int j = 0; j < num_materias; j++)
        {
            string nome_materia;
            float faltas, nota;
            cin >> nome_materia >> faltas >> nota;

            string status = (nota >= 7.0f && faltas <= 0.25f) ? "APROVADO" : "REPROVADO";
            alunos[nome_aluno][nome_materia] = status;
        }
    }

    int consultas;
    if (!(cin >> consultas))
        return 0;

    while (consultas--)
    {
        string nomeAluno, nomeMateria;
        cin >> nomeAluno >> nomeMateria;

        auto it_aluno = alunos.find(nomeAluno);
        if (it_aluno == alunos.end())
        {
            cout << "NAO_CURSOU\n";
            continue;
        }

        auto it_materia = it_aluno->second.find(nomeMateria);
        if (it_materia == it_aluno->second.end())
        {
            cout << "NAO_CURSOU\n";
        }
        else
        {
            cout << it_materia->second << "\n";
        }
    }

    return 0;
}