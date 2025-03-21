#include <stdio.h>
#define INPUT "input.txt"
#define OUTPUT "output.txt"

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

void reverseFile(char* filename){
    FILE *f = fopen(filename, "r");
    int file_len = char_counter(filename);
    fseek(f, file_len, SEEK_SET);
    FILE *foutput = fopen("output.txt", "w+");
    char list[file_len];
    for(int i = 0; i < file_len; i++){
      fseek(f, file_len - i, SEEK_SET);
      char c = fgetc(f);
      list[i] = c;
    }
    printf("Inserindo string %s\n", list);
    fputs(list, foutput);
    fclose(foutput);
    fclose(f);
    return;

  }

int main() {
  char* input = INPUT;
  reverseFile(input);
  return 0;
}