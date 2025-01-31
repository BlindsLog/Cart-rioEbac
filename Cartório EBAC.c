#include <stdio.h>  
#include <stdlib.h>  
#include <locale.h>  
#include <string.h>  

int registro() //Função responsável por cadastrar o usuário no sistema
{  
	//início criação de variáveis/string
    setlocale(LC_ALL, "Portuguese");  
    char arquivo[40];  
    char cpf[40];  
    char nome[40];  
    char sobrenome[40];  
    char cargo[40];  
    //final da criação de variáveis/string

    printf("Digite o CPF a ser cadastrado: ");  //Coletando informações do usuário
    scanf("%s", cpf);  //%s refere-se á strinsgs	
    
    strcpy(arquivo, cpf); //A linha de código strcpy(arquivo, cpf); na linguagem C é utilizada para copiar o conteúdo de uma string (neste caso, cpf) para outra string (arquivo)  
#ifdef _WIN32
    system("cls");// O uso de system("cls"); não é portátil, pois funciona apenas em sistemas Windows.  
#else
    system("clear");//Para sistemas Unix/Linux, você deve usar system("clear");.
#endif

    FILE *file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa escrever
    if (file == NULL) {  
        printf("Erro ao abrir o arquivo!\n");  
        return 1; // Retorna um erro  
    }  
    
    fprintf(file, "%s,", cpf); // Grava o CPF e adiciona uma vírgula  
    fclose(file);  
    
    printf("Digite o nome a ser cadastrado: ");  
    scanf("%s", nome);  
    
    file = fopen(arquivo, "a");  
    fprintf(file, "%s,", nome);  
    fclose(file);  //Fclose é para fechar o arquivo (File close)
    printf("Digite o sobrenome a ser cadastrado: ");  
    scanf("%s", sobrenome);  
    
    file = fopen(arquivo, "a");  
    fprintf(file, "%s,", sobrenome);  
    fclose(file);  
    
    printf("Digite o cargo a ser cadastrado: ");  
    scanf("%s", cargo);  
    
    file = fopen(arquivo, "a");  
    fprintf(file, "%s", cargo); // Grava o cargo sem vírgula ao final  
    fclose(file);  
    
    return 0; // Adicionado  
}  

int consulta() {  
    setlocale(LC_ALL, "Portuguese");  // Definir a linguagem
    
    char cpf[40]; // O tipo char é fundamental para trabalhar com texto em C, permitindo a manipulação de caracteres individuais e strings. 
    char conteudo[200];  
    
    printf("Digite o CPF a ser consultado: ");  
    scanf("%s", cpf); // Corrigido para %s  
    
    FILE* file = fopen(cpf, "r");  // o FILE é usado para procurar arquivos dentro do proprio arquivo local/ FILE* = (procure no arquivo file) e fopen é abra o arquivo  = (Fileopen)
    
    if (file == NULL) { // Verifica se o arquivo foi aberto corretamente  
        printf("Não foi possível localizar o arquivo\n");  
        return 1; // retorna um erro  
    }  
    
    printf("\nEssas são as informações do usuário:\n");  //Printf é usado justamente para dizer uma mensagem 
    while (fgets(conteudo, sizeof(conteudo), file) != NULL) {  
        printf("%s", conteudo); // Print das informações  
    }  
    
    fclose(file); // Sempre feche o arquivo quando terminar  
    system("pause");  
    return 0; // Para manter a consistência  
    
}  

int deletar() 
{  
	char cpf[40]; // O tipo char é manipulação de caracteres individuais e strings nesse caso como é deletar ele vai manipular o arquivo para ser deletado
	printf("Digite o CPF a ser deletado:\n"); //Dizer ao cliente essa pergunta	
	scanf("%s",cpf); // O scanf é uma função em C utilizada para ler dados da entrada padrão (normalmente o teclado). O especificador de formato %s na linguagem C é utilizado para manipular strings (sequências de caracteres) nas funções printf e scanf.
	
	remove(cpf); // Essa função deleta o cpf após o comando direto do código acima
	
	FILE *file; //o FILE é usado para procurar arquivos dentro do proprio arquivo local/ FILE* = (procure no arquivo file) 
	file = fopen(cpf,"r"); //e fopen é abra o arquivo  = (Fileopen)
	
	if(file == NULL) //Após isso ele vai procurar no sistema com esse código e se não achar (==NULL) ele desce para a próxima linha do código.
	{
		printf("Usuário Deletado com sucesso !\n"); // No caso esse aqui, uma mensagem dizendo que o usuário foi deletado com sucesso
		system("Pause");// O system pause é usado para parar a mensagem para que o usuário possa ler a mensagem antes que ela suma (sem esse comando a mensagem aparece e some rapidamente pois o código não entende que o usuário precisa ler).
		
	}
	
}  

int main() {  //Essa seção aqui já é o menu principal do Cartório.
    int opcao = 0;   
    while (1) //O comando while na linguagem C é uma estrutura de controle que permite a execução repetida de um bloco de código enquanto uma condição específica for verdadeira.
	{   
        system("cls"); //Responsável por limpar a tela
        setlocale(LC_ALL, "Portuguese");  //Define o idioma do comando podendo assim ter letras como Ç ou ão

        printf("\tCartório da Ebac \n\n\n");   
        printf("Escolha a opção desejada do menu: \n\n");  
        printf("\t1 - Registrar Nomes\n");  
        printf("\t2 - Consultar Nomes\n");  
        printf("\t3 - Deletar Nomes\n");  
        printf("Opção: ");  

        scanf("%d", &opcao);  //O scanf É uma função da biblioteca padrão stdio.h usada para ler dados da entrada padrão. / O %d diz ao scanf que o valor a ser lido deve ser interpretado como um inteiro.
        					 //O operador & é usado para passar o endereço da variável opcao. Isso é necessário porque scanf precisa saber onde armazenar o valor lido.
							// Sem o &, o programa não saberia onde colocar o número lido, resultando em um comportamento indefinido.
        
        system("cls");  //O comando system("cls"); na linguagem C é utilizado para limpar a tela do console em sistemas operacionais Windows
        switch (opcao)//Início da seleção no Menu
		{  
            case 1:   //Cada caso se deriva da opção do usuário então no caso registro, consulta e deletar
                registro();  
                break;  //Break é um comando essencial para parar o programa (não encerrar)
            case 2:   
                consulta();  
                break;  
            case 3:   
                deletar();    
                break;  
            default:   
                printf("Essa opção não está disponível!\n");   
                system("pause");  
                break;  
        }  
    }  
}
