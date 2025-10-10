/*2. Ficha de Leitura
Defina a classe FichaLeitura (arquivo FichaLeitura.h) para acompanhar leituras.
• Atributos: titulo, autor, anoPublicacao, numPaginas, paginaAtual, lido, nota0a5.
• Métodos: construtores, iniciarLeitura, marcarLido, avancarPaginas, avaliar, getters/setters. Inclua
protótipos de métodos para exibir percentualLido() e resumo().*/

#include <iostream>
#include <string>

using namespace std;

class fichaLeitura{
//atributos
    private:
        string autor;
        string titulo;
        int anoPublicacao;
        int numPaginas;
        int paginaAtual;
        int nota0a5;
        int lido; //Não sei se é assim
    
    public:
        fichaLeitura();//Construtor
        
        //Setters
        void marcarLido();
        void iniciaLeitura();
        void avancarPaginas();
        void avaliar();

        //getters
        int percentualLido(int numPaginas, int lido);
        void resumo(string autor, string titulo, int anoPublicacao);
};