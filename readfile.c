#include <stdio.h>
//read byte by byte
int main(int argc, char** argv)
{

FILE *rm;
char buf[2000];
    int res;
rm = fopen("lak", "rb");
if (rm != NULL) {
    while (!feof(rm)) {
        res = fread(buf, 1, 1, rm);
        buf[res] = 0;
        printf("%s\n", buf);
    }
    fclose(rm);
}
return 0;
}
