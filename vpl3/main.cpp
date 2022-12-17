#include <iostream>

using namespace std;

typedef struct Categoria
{
  int codigo;
  double verba;
} Categoria;

// Inicializa um objeto categoria com seu código e o valor que ela deve ter em caixa para gastos com sua pasta.
void inicia_categoria(Categoria *categoria,
                      int codigo_categoria, double valor_caixa)
{
  categoria->codigo = codigo_categoria;
  categoria->verba = valor_caixa;
}

// Recupera o código correspondente a uma categoria.
int codigo_categoria(Categoria *categoria)
{
  return categoria->codigo;
}

// Recupera o valor em caixa de uma categoria.
double valor_caixa_categoria(Categoria *categoria)
{
  return categoria->verba;
}

// Adiciona uma quantia ao caixa de uma categoria.
void adiciona_caixa_categoria(Categoria *categoria, double valor)
{
  categoria->verba += valor;
}

// Remove uma quantia ao caixa de uma categoria.
void gasta_caixa_categoria(Categoria *categoria, double valor)
{
  categoria->verba -= valor;
}

typedef struct Orcamento
{
  Categoria saude;
  Categoria educacao;
  Categoria seguranca;
  Categoria previdencia;
  Categoria administracao_publica;
} Orcamento;

// Inicializa um objeto Orçamento, sendo que ele deve conter um objeto categoria para cada pasta.
// Recebe como parâmetro o valor monetário que deve ser atribuído a aquele orçamento.
// Este valor deve ser distribuído a cada categoria, nos percentuais descritos anteriormente.
void inicia_orcamento(Orcamento *orcamento, double impostos)
{
  inicia_categoria(&orcamento->saude, 0, impostos * 0.15);
  inicia_categoria(&orcamento->educacao, 1, impostos * 0.15);
  inicia_categoria(&orcamento->seguranca, 2, impostos * 0.20);
  inicia_categoria(&orcamento->previdencia, 3, impostos * 0.35);
  inicia_categoria(&orcamento->administracao_publica, 4, impostos * 0.15);
}

// Retorna o ponteiro para o objeto da categoria especificada.
Categoria *recupera_categoria(Orcamento *orcamento, int codigo_categoria)
{
  switch (codigo_categoria)
  {
  case 0:
  {
    return &orcamento->saude;
    break;
  }
  case 1:
  {
    return &orcamento->educacao;
    break;
  }
  case 2:
  {
    return &orcamento->seguranca;
    break;
  }
  case 3:
  {
    return &orcamento->previdencia;
    break;
  }
  case 4:
  {
    return &orcamento->administracao_publica;
    break;
  }
  default:
    return nullptr;
  }
}

// Reduz o valor no caixa da categoria especificada.
void gasto_categoria(Orcamento *orcamento, int codigo_categoria, double valor)
{
  Categoria *desejada = recupera_categoria(orcamento, codigo_categoria);
  gasta_caixa_categoria(desejada, valor);
}

// Retorna o valor em caixa da categoria especificada.
double saldo_categoria(Orcamento *orcamento, int codigo_categoria)
{
  Categoria *desejada = recupera_categoria(orcamento, codigo_categoria);
  return valor_caixa_categoria(desejada);
}

int main()
{
  Orcamento orcamento;

  char test = 0;
  while (cin >> test)
  {
    switch (test)
    {
    case 'o':
    {
      double valor = 0;
      cin >> valor;
      inicia_orcamento(&orcamento, valor);
    }
    break;
    case 'g':
    {
      int categoria = 0;
      double valor = 0;
      cin >> categoria >> valor;
      gasto_categoria(&orcamento, categoria, valor);
      cout << categoria << ": " << saldo_categoria(&orcamento, categoria) << endl;
    }
    break;
    case 'p':
    {
      for (int categoria = 0; categoria < 5; categoria++)
      {
        cout << categoria << ": " << saldo_categoria(&orcamento, categoria) << endl;
      }
    }
    break;
    default:
    {
      cout << "----------" << endl;
    }
    break;
    }
  }
  return 0;
}
