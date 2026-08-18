#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <list>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cin.ignore();
    deque<string> forno;
    deque<string> entrega;
    for (int i = 0; i < n; i++)
    {
        string n_comando;
        cin >> n_comando;
        if (n_comando == "PEDIDO")
        {
            string sabor;
            cin >> sabor;
            forno.push_back(sabor);
        }
        else if (n_comando == "FORNO_LIVRE")
        {
            string pizza = forno.front();
            forno.pop_front();

            entrega.push_back(pizza);
        }
        else if (n_comando == "MOTOBOY")
        {
            cout << "ENTREGUE " << entrega.front() << endl;
            entrega.pop_front();
        }
        else if (n_comando == "INSPECAO_FORNO")
        {
            int indice;
            cin >> indice;
            cout << forno[indice] << endl;
        }
        else if (n_comando == "INSPECAO_ENTREGA")
        {
            int indice;
            cin >> indice;
            cout << entrega[indice] << endl;
        }
    }

    return 0;
}
