#include "FrequenciaCardiaca.h"
#include "clocale"

int main () {
    setlocale(LC_ALL,"pt_BR.UTF-8");

    int diaAtual = 0, mesAtual = 0, anoAtual = 0;

    string primeiroNome;
    string sobrenome;
    int diaNasc = 0;
    int mesNasc = 0;
    int anoNasc = 0;
    
    int minAlvo = 0;
    int maxAlvo = 0;


    cout << "Qual seu nome e sobrenome (separado entre enters)? \n";
    cin >> primeiroNome >> sobrenome;
  // cout << "Seu nome é " << primeiroNome << " " << sobrenome;

  
    
    cout << "\nQual sua data de nascimento (dia, mês e ano)?\n";
    cin >> diaNasc >> mesNasc >> anoNasc;
     
    
    cout << "\nQual a data de hoje (dia, mês e ano)? \n";
    cin >> diaAtual>> mesAtual >> anoAtual;


    // Agora sim: passa as informações para a função
    FrequenciaCardiaca fc(primeiroNome, sobrenome, diaNasc, mesNasc, anoNasc);

    int idade = fc.obterIdade(diaAtual, mesAtual, anoAtual);
    int frequenciaMaxima = fc.obterFrequenciaMaxima(idade);
    fc.obterFrequenciaIdeal(idade, minAlvo, maxAlvo);

    cout << "\nVocê tem " << idade << " anos";
    //cout << "\nAno atual " << anoAtual << " e ano de nascimento" << anoNasc;
    cout << "\nCom base na sua idade, sua frequêcia cardiaca máxima é" << frequenciaMaxima;
    cout << "\nSua frequência ideal é entre " << minAlvo << " e " << maxAlvo << "\n";

}