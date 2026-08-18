#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

typedef struct product
{
    string nome;
    float preco;
    float desconto;
    int qtd;
    int num_venda;

} tProduct;

tProduct *product_construct(string nomeProduct, float precoProduc, int qtdProduct, int num_vendaProduct)
{
    tProduct *pro = new product;

    pro->nome = nomeProduct;
    pro->preco = precoProduc;
    pro->desconto = 0.0;
    pro->qtd = qtdProduct;
    pro->num_venda = num_vendaProduct;
    return pro;
}

void product_destroy(tProduct *pro)
{
    delete pro;
}

bool comparaNome(tProduct *a, tProduct *b)
{
    return (a->nome < b->nome);
}

bool comparaPreco(tProduct *a, tProduct *b)
{
    return a->preco < b->preco;
}

bool comparaNumVenda(tProduct *a, tProduct *b)
{
    return (a->num_venda < b->num_venda);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cin.ignore();
   
    vector<tProduct *> pro;

    for (int i = 0; i < n; i++)
    {
        string nome;
        getline(cin, nome);

        float preco;
        int qtd, venda;
        cin >> preco;
        cin >> qtd;
        cin >> venda;
        cin.ignore();

        pro.push_back(product_construct(nome, preco, qtd, venda));
    }

    char c;
    cin >> c;

    if (c == 'N')
    {
        sort(pro.begin(), pro.end(), comparaNome);
    }
    else if (c == 'P')
    {
        sort(pro.begin(), pro.end(), comparaPreco);
    }
    else if (c == 'S')
    {
        sort(pro.begin(), pro.end(), comparaNumVenda);
    }
    cout << fixed << setprecision(2);

    for (tProduct *p : pro)
    {
        cout << "Product("
             << p->nome << ", "
             << p->preco << ", "
             << p->desconto << ", "
             << p->preco * (1 - p->desconto) << ", "
             << p->qtd - p->num_venda << ", "
             << p->num_venda << ")" << endl;
    }
    for (tProduct *p : pro)
    {
        product_destroy(p);
    }

    return 0;
}
