#include "FrequenciaCardiaca.h"

//Construtor padrão instanciado


FrequenciaCardiaca::FrequenciaCardiaca()
{

}

FrequenciaCardiaca::~FrequenciaCardiaca() = default;


FrequenciaCardiaca::FrequenciaCardiaca(
    string primeiroNome,
    string sobrenome,
    int diaNasc,
    int mesNasc,
    int anoNasc
) : primeiroNome(primeiroNome),
    sobrenome(sobrenome),
    diaNasc(diaNasc),
    mesNasc(mesNasc),
    anoNasc(anoNasc)
{}
    //Não
    int FrequenciaCardiaca::obterIdade(int diaAtual, int mesAtual, int anoAtual)
    { 
        
        int idade = 0;
        int dias = 0; //compara o dia de nascimento e vê se é maior ou menor
        int meses = 0;

        dias = diaAtual - diaNasc; //compara o dia de nascimento e vê se é maior ou menor
        meses = mesAtual - mesNasc;
        idade= anoAtual - anoNasc;

        //Confere se ele já fez aniversário no ano
        if (meses<=0)
        {
            if (dias<=0)
            {
                --idade;
            }
        }


        return idade;
    }

    int FrequenciaCardiaca::obterFrequenciaMaxima(int idade) // 220 - idade
    {
        int frequenciaMaxima = 0;
        frequenciaMaxima = 220 - idade;

        return frequenciaMaxima;
    }

    
    void FrequenciaCardiaca::obterFrequenciaIdeal(int idade, int& minAlvo, int& maxAlvo) //// 50% a 85% da máxima
    {
        int max = obterFrequenciaMaxima(idade);
        minAlvo = max*0.50;
        maxAlvo = max*0.85;
    }


 /*

 o int obterFrequenciaMaxima(int idade); // 220 - idade
o void obterFrequenciaIdeal(int idade, int& minAlvo, int& maxAlvo); // 50% a 85% da
int FrequenciaCardiaca::obterIdade(int diaAtual, int mesAtual, int anoAtual)
{

}

int FrequenciaCardiaca::obterFrequenciaMaxima(int idade) // 220 - idade
{

}

void FrequenciaCardiaca::obterFrequenciaIdeal(int idade, int& minAlvo, int& maxAlvo)
{

}
 */