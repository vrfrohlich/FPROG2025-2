#include <iostream>
#include <string>
#include <vector>

// Struct que representa o estado que persiste entre evoluções
// Por exemplo: se o pokémon é shiny, qual o nível de evolução etc.
struct PokemonState
{
    // Indica se o pokémon é shiny (verdadeiro) ou normal (falso)
    bool shiny;

    // Pode ser usado para contar quantas evoluções já ocorreram,
    // ou algum outro status que precise se manter ao longo da linha evolutiva
    int statusEvolution;

    // Construtor padrão, inicializa com valores "seguros"
    PokemonState()
    {
        shiny = false;
        statusEvolution = 0;
    }
};

//
// Classe base abstrata de todos os Pokémons.
//
// Ela concentra:
// - Nome, índice, altura, peso
// - O estado que deve ser preservado durante a evolução
// - Métodos virtuais para permitir polimorfismo
//
class Pokemon
{
protected:
    // Nome da espécie (Charmander, Charmeleon, Charizard etc.)
    std::string name;

    // Índice da Pokédex (por exemplo: 4, 5, 6)
    int index;

    // Altura do pokémon
    float height;

    // Peso do pokémon
    float weight;

    // Estado que persiste durante a evolução
    PokemonState state;

public:
    //
    // Construtor padrão vazio
    // Útil para casos em que a classe derivada vai configurar tudo manualmente
    //
    Pokemon()
    {
        name = "Desconhecido";
        index = -1;
        height = 0.0f;
        weight = 0.0f;
        state = PokemonState();
    }

    //
    // Construtor que recebe nome, índice e um valor inicial para o status de evolução.
    // Este construtor pode ser usado para um pokémon recém capturado.
    //
    Pokemon(std::string nameParam, int indexParam, int statusEvolutionParam)
    {
        name = nameParam;
        index = indexParam;
        height = 0.0f;   // valores padrão, podem ser alterados nas classes filhas
        weight = 0.0f;
        state = PokemonState();
        state.statusEvolution = statusEvolutionParam;
    }

    //
    // Construtor que recebe um estado já existente.
    // Este é útil para evoluções, quando o estado deve ser reaproveitado.
    //
    Pokemon(std::string nameParam, int indexParam, PokemonState stateParam)
    {
        name = nameParam;
        index = indexParam;
        height = 0.0f;
        weight = 0.0f;
        state = stateParam;
    }

    //
    // Destrutor virtual é obrigatório em hierarquias polimórficas.
    // Garante que o destrutor da classe derivada seja chamado corretamente via ponteiro base.
    //
    virtual ~Pokemon()
    {
        // Aqui não há nada específico a liberar,
        // mas o virtual garante a destruição correta em classes derivadas.
    }

    //
    // Método que retorna o estado atual do pokémon.
    // Retornado por valor para simplificar e manter o encapsulamento.
    //
    PokemonState getState()
    {
        return state;
    }

    //
    // Método que define o estado do pokémon.
    // Útil se for necessário alterar o estado manualmente.
    //
    void setState(PokemonState newState)
    {
        state = newState;
    }

    //
    // Método puramente virtual que informa qual o índice da próxima evolução.
    // Se não houver evolução, a classe derivada pode retornar -1.
    //
    virtual int getEvolutionTargetIndex() = 0;

    //
    // Método virtual polimórfico que imprime as informações do pokémon.
    // Pode ser sobrescrito em classes concretas para detalhar tipos especiais.
    //
    virtual void printInfo()
    {
        std::cout << "-----------------------------" << std::endl;
        std::cout << "Nome: " << name << std::endl;
        std::cout << "Indice Pokedex: " << index << std::endl;
        std::cout << "Altura: " << height << " m" << std::endl;
        std::cout << "Peso: " << weight << " kg" << std::endl;
        std::cout << "Shiny: " << (state.shiny ? "Sim" : "Nao") << std::endl;
        std::cout << "Status de Evolucao: " << state.statusEvolution << std::endl;
        std::cout << "-----------------------------" << std::endl;
    }
};

//
// Classe intermediária para pokémons do tipo Fogo.
// Ela usa herança virtual para evitar o problema do diamante,
// pois Charizard herda de FirePokemon e FlyingPokemon,
// e ambos herdam de Pokemon.
//
class FirePokemon : public virtual Pokemon
{
public:
    // Construtor padrão somente para permitir construção em classes derivadas
    FirePokemon()
    {
        // Nada específico aqui
    }

    //
    // Método virtual relacionado ao comportamento de um pokémon de fogo.
    // Mantemos como puramente virtual para que as classes concretas implementem seu próprio efeito.
    //
    virtual void burnUp() = 0;
};

//
// Classe intermediária para pokémons do tipo Voador.
// Também herda virtualmente de Pokemon.
//
class FlyingPokemon : public virtual Pokemon
{
public:
    // Construtor padrão
    FlyingPokemon()
    {
        // Nada específico aqui
    }

    //
    // Método virtual que representa o ato de voar.
    // Também é puramente virtual, forçando implementação nas classes concretas.
    //
    virtual void fly() = 0;
};

//
// Classe concreta Charmander.
// Este é o primeiro estágio da linha evolutiva.
//
// Herda de FirePokemon, que por sua vez herda virtualmente de Pokemon.
//
class Charmander : public FirePokemon
{
public:
    //
    // Construtor padrão.
    // Aqui definimos os valores característicos do Charmander.
    //
    Charmander()
        : Pokemon("Charmander", 4, 0), FirePokemon()
    {
        // Configuramos altura e peso típicos
        height = 0.6f;
        weight = 8.5f;

        // Estado inicial padrão (poderia ser ajustado por entrada do usuário se desejado)
        state.shiny = false;
        state.statusEvolution = 0;
    }

    //
    // Implementação do método que indica para qual índice este pokémon evolui.
    // Charmander evolui para Charmeleon, índice 5.
    //
    int getEvolutionTargetIndex()
    {
        return 5;
    }

    //
    // Implementação do comportamento de pokémon de fogo.
    //
    void burnUp()
    {
        std::cout << name << " usou uma habilidade de fogo basica!" << std::endl;
    }
};

//
// Classe concreta Charmeleon.
// Segundo estágio da linha evolutiva.
//
// Também é do tipo Fogo.
//
class Charmeleon : public FirePokemon
{
public:
    //
    // Construtor que recebe o estado do pokémon anterior.
    // Este estado é reaproveitado para manter informações como shiny, contador de evolução etc.
    //
    Charmeleon(PokemonState previousState)
        : Pokemon("Charmeleon", 5, previousState), FirePokemon()
    {
        // Ajusta altura e peso típicos do Charmeleon
        height = 1.1f;
        weight = 19.0f;

        // Podemos incrementar o status de evolução para indicar que ele já evoluiu uma vez
        state.statusEvolution = previousState.statusEvolution + 1;
    }

    //
    // Charmeleon evolui para Charizard, índice 6.
    //
    int getEvolutionTargetIndex()
    {
        return 6;
    }

    //
    // Implementação do comportamento da habilidade de fogo de Charmeleon.
    //
    void burnUp()
    {
        std::cout << name << " soltou uma labareda ainda mais forte!" << std::endl;
    }
};

//
// Classe concreta Charizard.
// Terceiro estágio da linha evolutiva.
// Aqui temos herança múltipla: Fogo e Voador.
//
// Esta classe demonstra:
// - Herança múltipla
// - Herança virtual de Pokemon pelas classes intermediárias
// - Sobrescrita de printInfo para exibir ambos os tipos
//
class Charizard : public FirePokemon, public FlyingPokemon
{
public:
    //
    // Construtor que recebe o estado vindo de Charmeleon.
    //
    Charizard(PokemonState previousState)
        : Pokemon("Charizard", 6, previousState), FirePokemon(), FlyingPokemon()
    {
        // Altura e peso típicos do Charizard
        height = 1.7f;
        weight = 90.5f;

        // Indica que houve mais uma evolução
        state.statusEvolution = previousState.statusEvolution + 1;
    }

    //
    // Charizard é a forma final. Não tem evolução.
    // Podemos retornar -1 para indicar que não há estágio seguinte.
    //
    int getEvolutionTargetIndex()
    {
        return -1;
    }

    //
    // Implementação da habilidade de fogo em Charizard.
    //
    void burnUp()
    {
        std::cout << name << " disparou uma poderosa rajada de fogo!" << std::endl;
    }

    //
    // Implementação da habilidade de voo.
    //
    void fly()
    {
        std::cout << name << " alçou voo pelos ceus!" << std::endl;
    }

    //
    // Sobrescrita do printInfo para destacar que este pokémon
    // possui dois tipos: Fogo e Voador.
    //
    void printInfo()
    {
        std::cout << "-----------------------------" << std::endl;
        std::cout << "Nome: " << name << " (Forma Final)" << std::endl;
        std::cout << "Indice Pokedex: " << index << std::endl;
        std::cout << "Tipos: Fogo / Voador" << std::endl;
        std::cout << "Altura: " << height << " m" << std::endl;
        std::cout << "Peso: " << weight << " kg" << std::endl;
        std::cout << "Shiny: " << (state.shiny ? "Sim" : "Nao") << std::endl;
        std::cout << "Status de Evolucao: " << state.statusEvolution << std::endl;
        std::cout << "-----------------------------" << std::endl;
    }
};

//
// Classe responsável por centralizar a lógica de criação e evolução dos pokémons.
//
// Ela implementa o padrão Factory Method através de um método privado
// que, a partir de um índice de espécie, instancia a classe correta.
//
class EvolutionManager
{
private:
    //
    // Factory Method privado.
    // Recebe um índice de espécie e um estado, e retorna o ponteiro para
    // o pokémon correto já alocado dinamicamente com new.
    //
    Pokemon* createPokemon(int speciesIndex, PokemonState state)
    {
        if (speciesIndex == 4)
        {
            // Charmander normalmente é construído "do zero",
            // mas aqui podemos reaproveitar a ideia de estado também.
            // Para manter a coerência com o construtor padrão de Charmander,
            // podemos ignorar parte do estado ou ajustar conforme necessidade.
            return new Charmander();
        }
        else if (speciesIndex == 5)
        {
            return new Charmeleon(state);
        }
        else if (speciesIndex == 6)
        {
            return new Charizard(state);
        }
        else
        {
            std::cout << "Indice de especie invalido: " << speciesIndex << std::endl;
            return 0;
        }
    }

public:
    
    // Método que captura um novo pokémon, simulando encontrar um "selvagem".
    //
    // Ele recebe o índice da espécie e cria o pokémon correspondente,
    // usando um estado padrão (poderia ser aleatório, por exemplo).
        Pokemon* captureNew(int speciesIndex)
    {
        PokemonState defaultState;
        defaultState.shiny = false;
        defaultState.statusEvolution = 0;

        Pokemon* captured = 0;

        // Para Charmander, podemos utilizar diretamente o construtor padrão.
        if (speciesIndex == 4)
        {
            captured = new Charmander();
        }
        else
        {
            // Para outros índices, delegamos ao Factory Method privado.
            captured = createPokemon(speciesIndex, defaultState);
        }

        if (captured != 0)
        {
            std::cout << "Um novo Pokemon foi capturado!" << std::endl;
            captured->printInfo();
        }
        else
        {
            std::cout << "Falha ao capturar o Pokemon." << std::endl;
        }

        return captured;
    }

    
    // Passos:
    // 1. Verifica se há um alvo de evolução.
    // 2. Salva o estado do pokémon atual.
    // 3. Desaloca o pokémon antigo com delete.
    // 4. Cria o novo pokémon chamando o Factory Method.
    // 5. Retorna o ponteiro para o novo pokémon.

    Pokemon* evolve(Pokemon* oldPokemon)
    {
        if (oldPokemon == 0)
        {
            std::cout << "Nao ha Pokemon para evoluir." << std::endl;
            return 0;
        }

        // Obtém o índice da próxima forma evoluída
        int targetIndex = oldPokemon->getEvolutionTargetIndex();

        // Se o índice for -1, consideramos que não há evolução disponível
        if (targetIndex == -1)
        {
            std::cout << "Este Pokemon nao pode mais evoluir." << std::endl;
            return oldPokemon;
        }

        // Salva o estado do pokémon atual
        PokemonState savedState = oldPokemon->getState();

        // Libera a memória do pokémon antigo
        delete oldPokemon;

        // Cria o novo pokémon usando o Factory Method
        Pokemon* newPokemon = createPokemon(targetIndex, savedState);

        if (newPokemon == 0)
        {
            std::cout << "Falha ao criar o Pokemon evoluido." << std::endl;
            return 0;
        }

        std::cout << "Evolucao concluida com sucesso!" << std::endl;
        newPokemon->printInfo();

        return newPokemon;
    }
};

//
// Função principal.
// Demonstra o ciclo completo:
// - Captura de um Charmander
// - Exibição das informações
// - Evolução para Charmeleon
// - Exibição
// - Evolução para Charizard
// - Exibição
// - Tentativa de evoluir Charizard novamente (sem sucesso)
// - Liberação de memória dos pokémons restantes
//
int main()
{
    EvolutionManager manager;

    // Vetor que representa a "mochila" do jogador, armazenando ponteiros para Pokemon
    std::vector<Pokemon*> mochila;

    std::cout << "Capturando um Charmander..." << std::endl;

    // Capturamos um Charmander (indice 4)
    Pokemon* meuPokemon = manager.captureNew(4);

    if (meuPokemon != 0)
    {
        // Guardamos na mochila
        mochila.push_back(meuPokemon);

        std::cout << std::endl;
        std::cout << "Exibindo informacoes iniciais do Pokemon na mochila:" << std::endl;
        mochila[0]->printInfo();

        // Evolução para Charmeleon
        std::cout << std::endl;
        std::cout << "Evoluindo para a segunda forma..." << std::endl;
        mochila[0] = manager.evolve(mochila[0]);

        if (mochila[0] != 0)
        {
            std::cout << std::endl;
            std::cout << "Depois da primeira evolucao:" << std::endl;
            mochila[0]->printInfo();
        }

        // Evolução para Charizard
        std::cout << std::endl;
        std::cout << "Evoluindo para a terceira forma..." << std::endl;
        mochila[0] = manager.evolve(mochila[0]);

        if (mochila[0] != 0)
        {
            std::cout << std::endl;
            std::cout << "Depois da segunda evolucao:" << std::endl;
            mochila[0]->printInfo();
        }

        // Tentativa de evoluir Charizard novamente
        std::cout << std::endl;
        std::cout << "Tentando evoluir novamente (nao deve haver evolucao):" << std::endl;
        mochila[0] = manager.evolve(mochila[0]);
    }

    // Libera todos os pokémons restantes na mochila para evitar vazamento de memória
    for (std::size_t i = 0; i < mochila.size(); i++)
    {
        delete mochila[i];
        mochila[i] = 0;
    }

    std::cout << "Programa finalizado. Memoria liberada." << std::endl;

    return 0;
}
