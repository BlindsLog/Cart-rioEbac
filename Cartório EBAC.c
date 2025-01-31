#include <stdio.h>  
#include <stdlib.h>  
#include <locale.h>  
#include <string.h>  

int registro() //Fun��o respons�vel por cadastrar o usu�rio no sistema
{  
	//in�cio cria��o de vari�veis/string
    setlocale(LC_ALL, "Portuguese");  
    char arquivo[40];  
    char cpf[40];  
    char nome[40];  
    char sobrenome[40];  
    char cargo[40];  
    //final da cria��o de vari�veis/string

    printf("Digite o CPF a ser cadastrado: ");  //Coletando informa��es do usu�rio
    scanf("%s", cpf);  //%s refere-se � strinsgs	
    
    strcpy(arquivo, cpf); //A linha de c�digo strcpy(arquivo, cpf); na linguagem C � utilizada para copiar o conte�do de uma string (neste caso, cpf) para outra string (arquivo)  
#ifdef _WIN32
    system("cls");// O uso de system("cls"); n�o � port�til, pois funciona apenas em sistemas Windows.  
#else
    system("clear");//Para sistemas Unix/Linux, voc� deve usar system("clear");.
#endif

    FILE *file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa escrever
    if (file == NULL) {  
        printf("Erro ao abrir o arquivo!\n");  
        return 1; // Retorna um erro  
    }  
    
    fprintf(file, "%s,", cpf); // Grava o CPF e adiciona uma v�rgula  
    fclose(file);  
    
    printf("Digite o nome a ser cadastrado: ");  
    scanf("%s", nome);  
    
    file = fopen(arquivo, "a");  
    fprintf(file, "%s,", nome);  
    fclose(file);  //Fclose � para fechar o arquivo (File close)
    printf("Digite o sobrenome a ser cadastrado: ");  
    scanf("%s", sobrenome);  
    
    file = fopen(arquivo, "a");  
    fprintf(file, "%s,", sobrenome);  
    fclose(file);  
    
    printf("Digite o cargo a ser cadastrado: ");  
    scanf("%s", cargo);  
    
    file = fopen(arquivo, "a");  
    fprintf(file, "%s", cargo); // Grava o cargo sem v�rgula ao final  
    fclose(file);  
    
    return 0; // Adicionado  
}  

int consulta() {  
    setlocale(LC_ALL, "Portuguese");  // Definir a linguagem
    
    char cpf[40]; // O tipo char � fundamental para trabalhar com texto em C, permitindo a manipula��o de caracteres individuais e strings. 
    char conteudo[200];  
    
    printf("Digite o CPF a ser consultado: ");  
    scanf("%s", cpf); // Corrigido para %s  
    
    FILE* file = fopen(cpf, "r");  // o FILE � usado para procurar arquivos dentro do proprio arquivo local/ FILE* = (procure no arquivo file) e fopen � abra o arquivo  = (Fileopen)
    
    if (file == NULL) { // Verifica se o arquivo foi aberto corretamente  
        printf("N�o foi poss�vel localizar o arquivo\n");  
        return 1; // retorna um erro  
    }  
    
    printf("\nEssas s�o as informa��es do usu�rio:\n");  //Printf � usado justamente para dizer uma mensagem 
    while (fgets(conteudo, sizeof(conteudo), file) != NULL) {  
        printf("%s", conteudo); // Print das informa��es  
    }  
    
    fclose(file); // Sempre feche o arquivo quando terminar  
    system("pause");  
    return 0; // Para manter a consist�ncia  
    
}  

int deletar() 
{  
	char cpf[40]; // O tipo char � manipula��o de caracteres individuais e strings nesse caso como � deletar ele vai manipular o arquivo para ser deletado
	printf("Digite o CPF a ser deletado:\n"); //Dizer ao cliente essa pergunta	
	scanf("%s",cpf); // O scanf � uma fun��o em C utilizada para ler dados da entrada padr�o (normalmente o teclado). O especificador de formato %s na linguagem C � utilizado para manipular strings (sequ�ncias de caracteres) nas fun��es printf e scanf.
	
	remove(cpf); // Essa fun��o deleta o cpf ap�s o comando direto do c�digo acima
	
	FILE *file; //o FILE � usado para procurar arquivos dentro do proprio arquivo local/ FILE* = (procure no arquivo file) 
	file = fopen(cpf,"r"); //e fopen � abra o arquivo  = (Fileopen)
	
	if(file == NULL) //Ap�s isso ele vai procurar no sistema com esse c�digo e se n�o achar (==NULL) ele desce para a pr�xima linha do c�digo.
	{
		printf("Usu�rio Deletado com sucesso !\n"); // No caso esse aqui, uma mensagem dizendo que o usu�rio foi deletado com sucesso
		system("Pause");// O system pause � usado para parar a mensagem para que o usu�rio possa ler a mensagem antes que ela suma (sem esse comando a mensagem aparece e some rapidamente pois o c�digo n�o entende que o usu�rio precisa ler).
		
	}
	
}  

int main() {  //Essa se��o aqui j� � o menu principal do Cart�rio.
    int opcao = 0;   
    while (1) //O comando while na linguagem C � uma estrutura de controle que permite a execu��o repetida de um bloco de c�digo enquanto uma condi��o espec�fica for verdadeira.
	{   
        system("cls"); //Respons�vel por limpar a tela
        setlocale(LC_ALL, "Portuguese");  //Define o idioma do comando podendo assim ter letras como � ou �o

        printf("\tCart�rio da Ebac \n\n\n");   
        printf("Escolha a op��o desejada do menu: \n\n");  
        printf("\t1 - Registrar Nomes\n");  
        printf("\t2 - Consultar Nomes\n");  
        printf("\t3 - Deletar Nomes\n");  
        printf("Op��o: ");  

        scanf("%d", &opcao);  //O scanf � uma fun��o da biblioteca padr�o stdio.h usada para ler dados da entrada padr�o. / O %d diz ao scanf que o valor a ser lido deve ser interpretado como um inteiro.
        					 //O operador & � usado para passar o endere�o da vari�vel opcao. Isso � necess�rio porque scanf precisa saber onde armazenar o valor lido.
							// Sem o &, o programa n�o saberia onde colocar o n�mero lido, resultando em um comportamento indefinido.
        
        system("cls");  //O comando system("cls"); na linguagem C � utilizado para limpar a tela do console em sistemas operacionais Windows
        switch (opcao)//In�cio da sele��o no Menu
		{  
            case 1:   //Cada caso se deriva da op��o do usu�rio ent�o no caso registro, consulta e deletar
                registro();  
                break;  //Break � um comando essencial para parar o programa (n�o encerrar)
            case 2:   
                consulta();  
                break;  
            case 3:   
                deletar();    
                break;  
            default:   
                printf("Essa op��o n�o est� dispon�vel!\n");   
                system("pause");  
                break;  
        }  
    }  
}
