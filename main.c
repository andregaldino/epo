#include <stdio.h>
#include <stdlib.h>

/*
Desenvolvido por :
André Galdino de Lima
Evelin Suci

Data : 28/03/2014
*/

typedef struct scriber scribers;
struct scriber
{
    char nome[50];
    char sobrenome[50];
    int codigo;
    int codigoLivro;
    float porcentagem;
    int idia;
    int imes;
    int iano;
    int fdia;
    int fmes;
    int fano;
};

int converterDias(int dia, int mes, int ano)
{
    int totalDias;
    totalDias = ((mes * 30) + (ano * 365)) + dia;
    return totalDias;
}


void listarScribers(scribers *s, int total)
{
    int contador;
    for(contador = 0;contador < total; contador++)
    {
        printf("\nCodigo : %i",s[contador].codigo);
        printf("\nNome : %s",s[contador].nome);
        printf("\nSobrenome : %s",s[contador].sobrenome);
        printf("\nPorcentagem : %i",s[contador].porcentagem);
        printf("\nData de Inicio : %i/%i/%i",s[contador].idia,s[contador].imes,s[contador].iano);
        printf("\nCodigo do Livro : %i",s[contador].codigoLivro);
    }

}

void listaNome(scribers *s, int posicao)
{
        printf("\nNome : %s",s[posicao].nome);
}

void listaNome_codigoLivro(scribers *aux, int tamanho)
{
    int i;
    for(i=0;i < tamanho;i++)
    {
        printf("Nome : %s ", aux[i].nome);
        printf("Codigo : %i ", aux[i].codigo);
        printf("Codigo Livro : %i ", aux[i].codigoLivro);
    }

}

void buscaLivro(scribers *s, int tamanho, int codigolivro)
{
    int i;
    int contador = 0;
    int chave = codigolivro;



    for(i = 0; i < tamanho;i++)
    {
        if(s[i].codigoLivro == chave )
        {
            contador++;
        }

    }

    if(contador > 0)
    {
        scribers aux[contador+1];
        int x;
        int y=0;
        for(x = 0; x < tamanho;x++)
        {
            if(s[x].codigoLivro == chave )
            {
                aux[y] = s[x];
                y++;
            }

        }

        listaNome_codigoLivro(aux,contador);
    }else{
        printf("Codigo do Livro nao encontrado!");
    }
}

void buscaScribersLivro_desafio(scribers *s,int tamanho,int posicaolivro)
{
    int contador = 0;
    int i;
    for(i=0;i<tamanho;i++)
    {
        if(s[i].codigoLivro == posicaolivro )
        {
            contador++;
        }
    }
    scribers desafio[contador];
    int x;
    int y;
    int maior = converterDias(desafio[0].fdia,desafio[0].fmes,desafio[0].fano);
    int menor;

    int dia,mes,ano;

    for(i=0;i<tamanho;i++)
    {
        if(s[i].codigoLivro == posicaolivro )
        {
            if(contador > 0)
            {

                printf("\nEntre com a data do termino do livro : ");
                printf("\ndia : ");
                scanf("%i",&dia);
                printf("\nmes : ");
                scanf("%i",&mes);
                printf("\nano: ");
                scanf("%i",&ano);

                for(y=0;y<contador;y++)
                {
                    desafio[y].fano = ano;
                    desafio[y].fmes = mes;
                    desafio[y].fdia = dia;

                }
                for(x=0;x<contador;x++)
                {


                    if(x=0)
                    {
                        menor = converterDias(desafio[x].idia,desafio[x].imes,desafio[x].iano);
                    }else if(converterDias(desafio[x].idia,desafio[x].imes,desafio[x].iano) < menor )
                    {
                            menor = converterDias(desafio[x].idia,desafio[x].imes,desafio[x].iano);
                    }
                }
            }

        }
    }

    int diferenca = maior - menor;

    printf("tempo em dias em que o livro demorou para ser escrito e : %i ",&diferenca);


}

void buscaLivro_desafio(scribers *s, int tamanho, int codigolivro)
{
    int chave = codigolivro;
    int i;
    for(i=0;i<tamanho;i++)
    {
        if(s[i].codigoLivro == chave)
        {
            buscaLivro_desafio(s,tamanho,i);

        }
    }

}

int buscarNome(scribers *s,int tamanho, char *nome)
{
    int chave = nome;
    int i;
    for(i=0;i < tamanho;i++)
    {
        if(strcmp(s[i].nome,chave) )
        {
            return i;
        }
    }
    return -1;
}

int buscarCodigo(scribers *s, int tamanho, int codigo)
{
    int chave = codigo;
    int i;
    for(i=0;i < tamanho;i++)
    {
        if(s[i].codigo == chave)
        {
            return i;
        }

    }
    return -1;

}

void troca(scribers *a, scribers *b)
{
    scribers aux;

    aux = *a;
    *a = *b;
    *b = aux;

}


void bolha_otimizado(scribers *vetor, int n)
{
    int i=0, j=0;
    int trocou = 1;

    while(i<n && trocou==1)
    {
        trocou = 0;// não houve troca
        for(j=0;j<n-1;j++)
        {
            if(vetor[j].codigo > vetor[j+1].codigo)
            {
                troca(&vetor[j],&vetor[j+1]);
                trocou = 1;// houve troca

            }
        }
        i++;
    }
}


int main()
{
    int num;
    int cont;

    printf("Deseja cadastrar quantos scribers ? ");
    scanf("%i",&num);

    scribers sb[num];

    for(cont = 0; cont < num;cont++)
    {
        printf("\n Codigo do Scriber : ");
        scanf("%i", &sb[cont].codigo);

        printf("\nNome do scriber : ");
        scanf("%s", &sb[cont].nome);

        printf("\nSobrenome : ");
        scanf("%s", &sb[cont].sobrenome);

        printf("\nPorcentagem : ");
        scanf("%f", &sb[cont].porcentagem);

        printf("\nData de inicio : ");
        printf("dia - ");
        scanf("%i", &sb[cont].idia);

        printf("mes - ");
        scanf("%i", &sb[cont].imes);

        printf("ano - ");
        scanf("%i", &sb[cont].iano);


        printf("Codigo do Livro : ");
        scanf("%d", &sb[cont].codigoLivro);

    }

    bolha_otimizado(sb,num);
    char nome[50];
    int posicao;
    int contador;
    int menu;
    int stop = 0;
    int codigo;
    int res;
    int codigoLivro;


    while(stop == 0)
    {
        do{
        printf("\n-Menu-");
        printf("\n1 - Inserir novos scribers");
        printf("\n2 - Listar dados dos scribers");
        printf("\n3 - Buscar scribers por nome ");
        printf("\n4 - Buscar scribers pelo codigo do scriber");
        printf("\n5 - Buscar scribers pelo codigo do livro");
        printf("\n6 - Desafio");
        printf("\n7 - Sair\n");
        scanf("%i",&menu);
        }while(menu <= 0 || menu >= 8);

        switch(menu)
        {
            case 1:
                break;
            case 2:
                listarScribers(sb,num);
                break;
            case 3:
                printf("\nEntre com o nome a ser encontrado ");
                scanf("%s",&nome);

                posicao = buscarNome(sb,num,nome);
                if(posicao >= 0)
                {
                    listaNome(sb,posicao);
                }else{
                    printf("Nome nao encontrado!");
                }

                break;
            case 4:
                printf("\nEntre com o codigo do scriber a ser encontrado ");
                scanf("%i",&codigo);

                res = buscarCodigo(sb,num,codigo);

                if(res >= 0)
                {
                    printf(" Nome : %s", sb[res].nome);
                    printf(" Codigo : %i",sb[res].codigo);
                }else{
                    printf("Codigo não encontrado!");
                }
                break;
            case 5:
                printf("Entre com o codigo do Livro : ");
                scanf("%i",&codigoLivro);

                buscaLivro(sb,num,codigoLivro);
                break;
            case 6:
                printf("Entre com o codigo do Livro : ");
                scanf("%i",&codigoLivro);


                buscaLivro_desafio(sb,num,codigoLivro);


                break;
            case 7:
                stop=1;
                break;
            default:
                stop = 1;
                break;
        }
    }

    system("PAUSE");
    return 0;
}
