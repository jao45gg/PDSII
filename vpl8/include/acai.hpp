#ifndef ACAI_H
#define ACAI_H

#include "produto.hpp"

using namespace std;

/**
 * @brief Classe responsavel pelo armazenamento e gerenciamento das informacoes
 * de um produto do tipo Açai.
 *
 */
class Acai : public Produto {
 public:
  /**
   * @brief Construtor padrao que inicializa todas as variaveis da classe.
   * Note que o valor unitario (membro da classe mãe) deve ser calculado 
   * através do método calcPreco.
   *
   * @param tamanho Tamanho do açai em ml
   * @param complementos Coleção de strings com os complementos 
   * @param qtd Quantidade de açaís do mesmo tamanho e complementos
   */
  Acai(int tamanho,
       std::vector<std::string>& complementos,
       int qtd);

  /**
   * @brief Calcula o valor do açaí de acordo com as regras:
   * 0.02 centavos por ml + 2 reais cada complemento
   * 
   * @return float preço do açaí em reais
   */
  virtual float calcPreco() override;

  /**
   * @brief Retorna uma descricao detalhada do açaí.
   * Exemplo: 2X açai 700ml com leite em pó, granola.
   *
   * @return std::string Descricao detalhada do açai
   */
  virtual std::string descricao() const override;

 private:
     std::vector<std::string> _complementos;
     int _tamanho;
};
#endif