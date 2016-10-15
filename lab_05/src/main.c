#include "position.h"
#include <stdio.h>
#include <string.h>

char print_format[256];
FILE *outfile;
int num;

void apply(intrusive_list *list, void (*op)(intrusive_node*)){
    intrusive_node *head = &list->head;
    intrusive_node *node = head->next;

    for (; node != head; node = node->next) {
        op(node);
    }
}

void print_node(intrusive_node *node){
    //print_position(node);
    position_node *pnode = get_position(node);
    printf(print_format, pnode->x, pnode->y);
}

void save_node_txt(intrusive_node *node){
    position_node *pnode = get_position(node);
    fprintf(outfile, "%d %d\n", pnode->x, pnode->y);
}

void save_node_bin(intrusive_node *node){
    int t;
    position_node *pnode = get_position(node);
    t = pnode->x;
    fwrite(&t, 3*sizeof(char), 1, outfile);
    t = pnode->y;
    fwrite(&t, 3*sizeof(char), 1, outfile);
}

void count_node(intrusive_node *node){
    num++;
}

int main( int argc, char **argv) {

    FILE *infile;
    intrusive_list list;
    intrusive_list* l = &list;
    init_list(l);

    int i = 1;

    int x, y, t, k = 0;

    if( !strcmp(argv[i], "loadtext") ){
        i++;
        if ( !(infile = fopen( argv[i], "r" )) ) {
            printf("failed to open input file");
            return -1;
        }
        while( EOF != fscanf(infile, "%d %d", &x, &y) ){
            add_position(l, x, y);
        }
        fclose(infile);
    }
    else if( !strcmp(argv[i], "loadbin") ){
        i++;
        if ( !(infile = fopen( argv[i], "r" )) ) {
            printf("failed to open input file");
            return -1;
        }
        t = 0;
        while( fread(&t, 3*sizeof(char), 1, infile) >= 1 ){
            if( t & 0x00100000 ){
                t = t | 0xff000000;
            }
            if( (k % 2) == 0 ){
                x = t;
            }
            else{
                y = t;
                add_position(l, x, y);
            }
            k++;
            t = 0;
        }
    }

    i++;

    while( i < argc ){  //parse actions
        if( !strcmp(argv[i], "savetext") ){
            i++;
            if ( !(outfile = fopen( argv[i], "w" )) ) {
                printf("failed to open output file");
                return -1;
            }
            apply(l, save_node_txt);
            fclose(outfile);
        }

        if( !strcmp(argv[i], "savebin") ){
            i++;
            if ( !(outfile = fopen( argv[i], "wb" )) ) {
                printf("failed to open output file");
                return -1;
            }
            apply(l, save_node_bin);
            fclose(outfile);
        }


        if( !strcmp(argv[i], "print") ){
            i++;
            strcpy(print_format, argv[i]);
            apply(l, print_node);
        }

        if( !strcmp(argv[i], "count") ){
            num = 0;
            apply(l, count_node);
            printf("%d\n", num);
        }

        i++;

    }

    remove_all(l);

    return 0;
}
