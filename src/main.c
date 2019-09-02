#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

#define BUFFER_SIZE 32

char *(*sgets)(char *);

void hexdump(char *desc, void *addr, size_t len){
  int i;
  unsigned char buff[17];
  const unsigned char *pc = (const unsigned char*)addr;
  if (desc != NULL){
    printf ("%s:\n", desc);
  }
  for (i = 0; i < (int)len; i++) {
    if ((i % 16) == 0) {
      if (i != 0){
        printf ("  %s\n", buff);
      }
      printf ("  %04x ", i);
    }
    printf (" %02x", pc[i]);
    if ((pc[i] < 0x20) || (pc[i] > 0x7e)){
      buff[i % 16] = '.';
    } else{
      buff[i % 16] = pc[i];
    }
    buff[(i % 16) + 1] = '\0';
  }
  while ((i % 16) != 0){
    printf ("   ");
    i++;
  }
  printf ("  %s\n", buff);
}

void help_menu(){
  printf("/-----------------------------------------------------------------------\\\n");
  printf("|                    sgets - gets() Secure Implementation               |\n");
  printf("|-----------------------------------------------------------------------|\n");
  printf("|                                Examples:                              |\n");
  printf("|-----------------------------------------------------------------------|\n");
  printf("| echo 'hello' | ./sgets                                                |\n");
  printf("| ./sgets                                                               |\n");
  printf("|-----------------------------------------------------------------------|\n");
  printf("|                                 Author:                               |\n");
  printf("|-----------------------------------------------------------------------|\n");
  printf("| Lilly Chalupowski                                                     |\n");
  printf("|-----------------------------------------------------------------------|\n");
}

void pause(){
  printf("|                         Press ENTER to Continue                       |\n");
  printf("\\-----------------------------------------------------------------------/\n");
  while( getchar() != '\n' );
}

int main(){
  help_menu();
  pause();
  void *handle = dlopen("/lib64/libc.so.6", RTLD_LAZY);
  *(void**)(&sgets) = dlsym(handle, "gets");
  int c;
  char buffer[BUFFER_SIZE];
  memset(buffer, 0, BUFFER_SIZE);
  hexdump("buffer before", buffer, BUFFER_SIZE);
  printf("Good Luck! ┌∩┐(◣_◢)┌∩┐: ");
  for (int i = 0; i < BUFFER_SIZE - 1 ; i++){
    c = fgetc(stdin);
    if (c == 10 || c == 0 || c == -1){
      break;
    }
    buffer[i] = c;
  }
  ungetc('\n', stdin);
  for (int i = BUFFER_SIZE - 1; i >= 0; i--){
    ungetc(buffer[i], stdin);
  }
  sgets(buffer);
  hexdump("buffer after", buffer, 32);
  printf("Output: %s\n", buffer);
  return 0;
}
