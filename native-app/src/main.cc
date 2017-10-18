#include <iostream>

#include "mathy.h"
#include "version.h"

int main(const int argc, const char *argv[])
{
    printf("Hello world!\n");

    if (argc > 1) {
      printf("Number of arguments detected is %d.\n", argc);
      int i=0;
      while(argv[i]!=NULL){
        printf("The argv[%d] has `%s` value.\n", i, argv[i]);
        i++;
      }
    }
    printf("VERSION_STRING=%s\n", VERSION_STRING);
    printf("BUILD_STRING=%s\n", BUILD_STRING);
    printf("PRODUCT_STRING=%s\n", PRODUCT_STRING);

    return 0;
}
