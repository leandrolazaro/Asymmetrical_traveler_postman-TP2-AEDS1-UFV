/* Gera todas as permutações */

#include <stdio.h>
#include <stdlib.h>

void troca(int vetor[], int i, int j);
void permuta(int vetor[], int inf, int sup, int melhorCaminho[], int *moduloMelhorCaminho, int distancias[], int cidadeInicial);
int setCidadeinicial(int matriculas[], int numCidades);
int setCustoCaminho(int cidades[], int **distancias, int tamanhoVetor, int cidadeInicial);
void getTracejado(void);

int main(int argc, char *argv[]){
    int modoInterativo;
    int matriculas[3];
    int cidadeInicial;
    int numCidades;
    int moduloMelhorCaminho;

    scanf("Digite 0 para modo automático e 1 para modo interativo %d\n", &modoInterativo);

    if(modoInterativo==1){
    //---MODO INTERATIVO---

        //Obtem os números de matrícula
        for(int i=0; i<=2; i++){
            scanf("Digite o número de matrícula: %d\n", &matriculas[i]);
        }

        //Obtem o número de cidades
        scanf("Digite o número de cidades: %d\n", &numCidades);
    
    }else{
    //---MODO AUTOMÁTICO---

















    }

    //Declarando uma matriz de distancias
    int distancias[numCidades][numCidades];

    //Atribui valores aleatórios na matriz de distância. Exceto quando a coluna tem o mesmo valor da linha. Nesse caso a posição vale '0'.
    for(int i=0; i<=numCidades-1; i++){
        for(int j=0; j<=numCidades-1; j++){
            if(i!=j){
                distancias[i][j]=rand() % 100;
            }else{
                distancias[i][j]=0;
            }
            
        }    
    }

    //Declarando um vetor de cidades
    int cidades[numCidades-1];

    //Definindo a cidade incial
    cidadeInicial=setCidadeinicial(matriculas, numCidades);
    
    //Preenchendo o vetor de cidades com exceção da cidade inicial
    for(int i=0; i<=numCidades-2; i++){
        if(cidadeInicial!=i){
            cidades[i]=i;
        }else{
            cidades[i]=i+1;
        }
    }

    //Definindo um caminho inicial para fins de comparação
    moduloMelhorCaminho=setCustoCaminho(cidades, distancias, numCidades-2, cidadeInicial);

    //Vetor com as cidades do melhor caminho
    int melhorCaminho[numCidades-1];


    getTracejado();

    for(int i=3; i<=2; i++){
        printf("Matricula %d -> %d\n", i+1, matriculas[i]);
    }

    getTracejado();
    getTracejado();

    printf("Quantidade de cidades %d", numCidades);

    getTracejado();
    getTracejado();

    printf("Cidade inicial %d", cidadeInicial);

    getTracejado();

    permuta(cidades, 0, numCidades - 2, melhorCaminho, &moduloMelhorCaminho, distancias, cidadeInicial);

    getTracejado();

    printf("Matriz de distancia");

    getTracejado();

    for(int i=0; i<=numCidades-1; i++){
        for(int j=0; j<=numCidades-1; j++){
            printf("%d ", distancias[i][j]);    
        }    
        printf("\n");
    }
     
    getTracejado();

    //Mostra na tela o melhor caminho e o seu custo
    printf("A menor distancia foi %d", moduloMelhorCaminho);

    getTracejado();

    printf("A sequencia de cidades percorridas\n");
    printf("%d ", cidadeInicial);
    for(int i=0; i<=numCidades-2; i++){
        printf("%d ", melhorCaminho[i]);
    }
    printf("%d\n", cidadeInicial);

    getTracejado();

	return 0;
}

//Algorítimo responsável pelas permutações
void permuta(int vetor[], int inf, int sup, int melhorCaminho[], int *moduloMelhorCaminho, int distancias[], int cidadeInicial){
	if(inf == sup){
        int somaDistancias=0;
        somaDistancias=setCustoCaminho(vetor, distancias, sup, cidadeInicial);

        if(somaDistancias<(*moduloMelhorCaminho)){
            *moduloMelhorCaminho=somaDistancias;
            for(int i=0; i<=sup; i++){
                melhorCaminho[i]=vetor[i];
            }
        }
        
	}else{
		for(int i = inf; i <= sup; i++){
			troca(vetor, inf, i);
			permuta(vetor, inf + 1, sup, melhorCaminho, moduloMelhorCaminho, distancias, cidadeInicial);
			troca(vetor, inf, i); // backtracking
		}
	}
}

//Função ajudante do algorítimo de pertmutação. Ela inverte duas posições de um vetor.
void troca(int vetor[], int i, int j){
	int aux = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = aux;
}

//Define qual será a cidade inicial
int setCidadeinicial(int matriculas[], int numCidades){
    int resultado=0;
    for(int i=0; i<=2; i++){
        resultado+= matriculas[i]/1000;
        resultado+= (matriculas[i]%1000)/100;
        resultado+= ((matriculas[i]%1000)/10)%10;
        resultado+= ((matriculas[i]%1000)%100)%10;
    }
    return (resultado%numCidades);
}

//Calcula o custo de um caminho composto por uma sequência de cidades
int setCustoCaminho(int cidades[], int **distancias, int tamanhoVetor, int cidadeInicial){
    int moduloMelhorCaminho=0;
    for(int i=0; i<tamanhoVetor; i++){
        moduloMelhorCaminho+=distancias[cidades[i]][cidades[i+1]];
    }
    moduloMelhorCaminho+=distancias[cidadeInicial][cidades[0]]+distancias[tamanhoVetor][cidadeInicial];
    return moduloMelhorCaminho;
}

void getTracejado(void){
    printf("\n\n-----------------------------------------------------------------\n");
    printf("-----------------------------------------------------------------\n\n");
}