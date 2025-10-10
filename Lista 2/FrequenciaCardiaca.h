    /*
    6. Frequência Cardíaca
• Classe: FrequenciaCardiaca (arquivo FrequenciaCardiaca.h /.cpp).
• Atributos (privados): primeiroNome (string), sobrenome (string), diaNasc (int), mesNasc (int),
anoNasc (int).
• Construtores: padrão; parametrizado com todos os campos.
• Set/Get: para todos os atributos (validar datas simples: 1≤dia≤31, 1≤mes≤12, ano>1900).
• Métodos:
o int obterIdade(int diaAtual, int mesAtual, int anoAtual);
o int obterFrequenciaMaxima(int idade); // 220 - idade
o void obterFrequenciaIdeal(int idade, int& minAlvo, int& maxAlvo); // 50% a 85% da
máxima
• main.cpp: ler dados do usuário, instanciar o objeto, exibir nome completo, data de nascimento,
idade, freq. máxima e faixa ideal.
*/

#include<iostream>
#include<string>


using namespace std;

class FrequenciaCardiaca{
    
    //privado
    private:
        string primeiroNome;
        string sobrenome;
        int diaNasc;
        int mesNasc;
        int anoNasc;

    public:
        //construtor padrão
        FrequenciaCardiaca();
        
        // Personalizado
        FrequenciaCardiaca
        (
            string primeiroNome,
            string sobrenome,
            int diaNasc,
            int mesNasc,
            int anoNasc
        );
        
        //Destrutor
        ~FrequenciaCardiaca();

        //setters
        int obterIdade(int diaAtual, int mesAtual, int anoAtual);
        int obterFrequenciaMaxima(int idade); // 220 - idade
        void obterFrequenciaIdeal(int idade, int& minAlvo, int& maxAlvo); // 50% a 85% da máxima
           
        










};