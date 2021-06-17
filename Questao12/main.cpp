// Algoritmo para imprimir os caminhos Preorder Inorder e postorder de uma arvore binaria
#include <iostream>
using namespace std;

struct node{
    int info;
    node *esquerda;
    node *direita;
};
typedef node *nodeptr;
void Inserir(nodeptr &p, int x){

    if (p == NULL){
        p = new node;
        p->info = x;
        p->esquerda = NULL;
        p->direita = NULL;
    }
    else{
        if(x < p->info)// Insere na subarvore esquerda caso contrario insere na sbarvore a direita
            Inserir(p->esquerda, x);
        else
            Inserir(p->direita, x);
    }
}
void Postorder(node* node){
	if (node == NULL)
		return;

	Postorder(node->esquerda);	// primeiro ocorre na subárvore esquerda
	Postorder(node->direita);// segundo  na subárvore direita
	cout << node->info << " ";//
}
void Inorder(node* node){
	if (node == NULL)
		return;
	Inorder(node->esquerda); //  primeiro ocorre na subárvore esquerda
	cout << node->info << " ";//
	Inorder(node->direita); // agora ocorre no nó correto.
}
void Preorder(node* node){
	if (node == NULL)
		return;
	cout << node->info << " ";// primeiro imprime a raiz
	Preorder(node->esquerda);
	Preorder(node->direita);
}

//Arvore -->>              8
    //                   /   \
    //                 3      10
    //               /  \      \
    //              1    6      14
    //                  / \    /
    //                 4   7  13
int main(){
    nodeptr arvore = NULL;
    Inserir(arvore,8);
    Inserir(arvore,3);
	Inserir(arvore,10);
	Inserir(arvore,14);
	Inserir(arvore,13);
	Inserir(arvore,1);
	Inserir(arvore,6);
	Inserir(arvore,4);
	Inserir(arvore,7);

	cout << "Preorder: ";
	Preorder(arvore);

	cout <<"\nInorder:  ";
	Inorder(arvore);

	cout <<"\nPostorder: ";
	Postorder(arvore);

	return 0;
}
