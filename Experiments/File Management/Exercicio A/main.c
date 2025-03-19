//1) Contagem de Palavras em um Arquivo: Escreva um programa que abra um arquivo
//de texto, conte o número de palavras nele e exiba o resultado na tela.
//2) Cópia de Arquivo: Crie um programa que copie o conteúdo de um arquivo de texto
//para outro arquivo. Certifique-se de que o arquivo de destino seja criado se ainda
//não existir.
//3) Edição de Arquivo: Desenvolva um programa que permita ao usuário editar um
//arquivo de texto. Ele deve solicitar ao usuário que insira o texto que deseja adicionar
//ao arquivo existente e, em seguida, deve adicionar esse texto ao final do arquivo.
//4) Leitura e Impressão de Linhas Específicas: Escreva um programa que leia um
//arquivo de texto linha por linha e imprima apenas as linhas que começam com uma
//determinada letra ou palavra especificada pelo usuário.
//5) Contagem de Caracteres Específicos: Crie um programa que conte quantas vezes
//um caractere específico aparece em um arquivo de texto. Permita que o usuário
//especifique o caractere a ser contado
#include <stdio.h>

int word_counter(char* filename){
    int counter;
    printf("Contando palavras...\n");
    counter = 0;
    FILE *f = fopen(filename, "r");
    while(!feof(f)){
          if(fgetc(f) == ' '){
              ++counter;
          }
    }
    counter += 1; // EOF
    fclose(f);
    return counter;
}
int char_counter(char* filename){
    int counter;
    char c;
    printf("Contando caracteres...\n");
    counter = 0;
    FILE *f = fopen(filename, "r");
    while((c = fgetc(f)) != EOF){
        counter++;
    }
    printf("Terminou contagem de caracteres...");
    fclose(f);
    return counter;
}
void copyTo(char *origin, char *destination){
      printf("Copiando input para output...\n");

      // 1. Contagem de palavras
      int file_len = char_counter(origin);
      FILE *fdestination = fopen(destination, "w+");
      FILE *forigin = fopen(origin, "r");

      // 2. Cópia de arquivo para destino
      char output_string[32];
      fgets(output_string, file_len, forigin); // Indice começa em 0
      fputs(output_string, fdestination);
      fclose(fdestination);
      fclose(forigin);
}

void editFile(char * filename) {
    printf("Editando arquivo...");
    char input[50];
    printf("Insira um texto:\n");
    scanf("%s", input);
    FILE *f = fopen(filename, "a");
    fputc(' ', f);
    fputs(input, f);
    printf("Adicionou a frase %s\n", input);
    fclose(f);
}

int main(){
  int word_count = word_counter("input.txt");
  printf("Número de palavras no arquivo: %i\n", word_count);
  copyTo("input.txt","output.txt");
    editFile("output.txt");

  return 0;


}