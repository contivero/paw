#include <stdio.h>
#include <stdlib.h>

int
main(void){
    char c;
    char *qs = getenv("QUERY_STRING");
    FILE *fp = fopen("products.txt", "r");

    printf("Server: Apache/2\n"
           "Content-type: text/html\n\n"
           "<html><body><h1>Lista de Productos</h1>");

    printf("<h2>%s</h2>", qs);

    while( (c = fgetc(fp)) != EOF){
        printf("<ul><li>%c",c);
        while( (c = fgetc(fp)) != '\n'){
            if (c == ',') printf("</li><li>");
            else printf("%c",c);
        }
        printf("</li></ul>");
    }

    printf("</body></html>");

    fclose(fp);
    return 0;
}