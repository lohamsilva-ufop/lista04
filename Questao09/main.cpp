#include <iostream>
#include <vector>
using namespace std;
/*

Arvore de busca binaria: cada nу possui um valor associado a ele e esse valor determina sua posicao no nу da arvore

Inserзгo: para cada nу pai, o valor maior que ele fica na direita e o valor menor ficam na esquerda

*/

//Registro para definir a arvore
struct no{
    int dado;
    int indice_direita;
    int indice_esquerda;
};

//procedimento para inserir um item na arvore
void inserir(int elemento, int indice, vector <no> &arvore){

    if (arvore.empty()){ //se a arvore esta vazia, ele insere o elemento sem o indice do no direito ou esquerdo
            no novo;
            novo.dado = elemento;
            novo.indice_direita = NULL;
            novo.indice_esquerda = NULL;

            arvore.push_back(novo);

    //se a arvore estiver cheia:

    } else if (elemento < arvore[indice].dado){ //verifica se o elemento passado й menor que elemento do nу corrente referente ao indice passado
        if (arvore[indice].indice_esquerda == NULL){ //se for menor, insere na esquerda. Se o no da esquerda nao tiver um indice apontando para o no esquerdo
        //cria um registro
            no novo;
            novo.dado = elemento;
            novo.indice_direita = NULL;
            novo.indice_esquerda = NULL;

            arvore[indice].indice_esquerda = arvore.size(); //aponta o indice esquerdo para a nova posicao
            arvore.push_back(novo); //insere um item na arvore

        } else{ //se o indice da esquerda tiver elemento, ele verifica o proximo elemento dada a referencia do indice do proximo no esquerdo
            indice = arvore[indice].indice_esquerda; // o indice recebe o indice da proximo no esquerdo
            inserir(elemento, indice ,arvore);  // a funcao repete recursivamente ate encontrar um indice esquerdo nulo para inserir.
        }

    } else if (elemento > arvore[indice].dado){ //verifica se o elemento passado й maior que elemento do nу corrente referente ao indice passado
        if (arvore[indice].indice_direita == NULL){ //se for maior, insere na direita. Se o nу da direita nao tiver um indice apontando para o no direito
        //cria um registro
            no novo;
            novo.dado = elemento;
            novo.indice_direita = NULL;
            novo.indice_esquerda = NULL;

            arvore[indice].indice_direita = arvore.size(); //aponta o indice direito para a nova posicao
            arvore.push_back(novo); //insere um item na arvore

        } else{ //se o indice da direita tiver elemento, ele verifica o proximo elemento dada a referencia do indice do proximo nу direito
            indice = arvore[indice].indice_direita;  // o indice recebe o indice da proximo nу direito
            inserir(elemento, indice ,arvore); // a funcao repete recursivamente ate encontrar um indice direito nulo para inserir.
        }

    } else{
        cout << "Dado iguais nao podem ser inseridos na arvore" << endl; //se o elemento for repetido, nao pode inserir
    }

}

//funcao para busca
void busca (vector <no> arvore, int indice, int chave){
    if (arvore.empty()){ //se a arvore esta vazia, emite mensagem dizendo que nao existe
            cout << "Nao existe elemento na arvore";
    }

    if(chave < arvore[indice].dado){ //se a chave passada e menor que o dado:
        indice = arvore[indice].indice_esquerda; //o indice verifica o proximo elemento do no esquerdo, dada a referencia
        busca(arvore, indice, chave); //chama a funcao recursivamente ate encontrar o elemento igual

    } else if (chave > arvore[indice].dado){ //se a chave passada e maior que o dado:
        indice = arvore[indice].indice_direita; //o indice verifica o proximo elemento do no direito, dada a referencia
        busca(arvore, indice, chave); //chama a funcao recursivamente ate encontrar o elemento igual

    } else if (chave == arvore[indice].dado){ //se й igual, ele encontrou o item
        cout << "O dado esta na posicao " << indice << endl;
    } else {
        cout << "Elemento nao existe"; //senao, nao existe.
    }
}


//procedimento para imprimir a arvore:
void imprimeArvore(vector <no> arv){
        for(int i=0; i<arv.size();i++){
                  cout << "No: " << i << " :" <<endl;
                  cout << "dado: " << arv[i].dado << endl;
                  if (arv[i].indice_direita == 0){
                  cout << "indice do no direito sem elemento: folha" << endl;
                  cout << "indice do no esquerdo sem elemento: folha" << endl;
                  } else{
                  cout << "indice do no direito: " << arv[i].indice_direita << endl;
                  cout << "indice do no esquerdo:" << arv[i].indice_esquerda << endl;
                  }

                  cout << endl;
            }
}

int main()
{
    vector <no> tree; //declaracao do vetor arvore do tipo nу
    int opcao = 4; //inicializacao da opcao menu
    int elemento; //declaracao da variavel que captura o elemento

    while (opcao != 0){ //enquanto a opcao e diferente do 0, mostra ao usuario o menu:
        cout << "Digite:"  << endl;
        cout << "1 - Inserir valor"  << endl;
        cout << "2 - Pocurar valor"  << endl;
        cout << "3 - Imprimir arvore"  << endl;
        cout << "0 - Sair"  << endl;
        cin >> opcao;

        if (opcao == 1){
            cout << "Digite o elemento a ser inserido na arvore:";
            cin >> elemento;
            inserir(elemento, 0, tree); //chama a funcao inserir, passando o elemento capturado, o indice para iniciar  busca e o vetor arvore do tipo nу
        } else if (opcao == 2){
            cout << "Digite o elemento a ser buscado na arvore:";
            cin >> elemento;
            busca(tree, 0, elemento); //chama a funcao busca, passando o vetor arvore do tipo nу, o indice para iniciar  busca e o elemento chave a ser buscado
        } else if (opcao == 3){
             imprimeArvore(tree); //chama a funcao que imprime a arvore passando o vetor arvore do tipo nу
        } else{
            cout << "Saindo do menu" << endl;
        }
    }


    return 0;
}
