   /*1. Anamnese
Crie a definição da classe Anamnese (arquivo Anamnese.h), representando um pequeno cadastro clínico.
• Atributos: nome, idade, pesoKg, alturaM, alergias, doencasPreExistentes, medicamentosEmUso.
• Métodos: construtor padrão, construtor com todos os campos, getters e setters para cada
atributo. Inclua protótipos de métodos para calcular IMC e gerar resumo.*/   

#include<iostream>
#include<string>

using namespace std;


class anamnese{

    //Atributos
    private:
    string nome;
    string alergias;
    string doencasPreExistentes;
    string medicamentoEmUso;
    int idade;
    int pesoKG;
    int alturaM;

    //Metodos
    public:
 
    //getter
    anamnese(); //Construtor padrão

    anamnese( 
    string nome,
    string alergias,
    string doencasPreExistentes,
    string medicamentoEmUso,
    int idade,
    int pesoKG,
    int alturaM
    ); //construtor personalizado

    ~anamnese   (); //Destrutor

    //setter
    void calcularIMC( int idade, int pesoKG, int alturaM);
    void resumo(string nome, string alergias, string doencasPreExistentes, string medicamentoEmUso);
 };