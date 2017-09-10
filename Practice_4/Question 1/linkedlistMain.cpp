#include "linkedlist.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main(){
    Node* head = new Node();
    head = head->destroy_list();
    int operation, value;

    do {
        head->operation_select();
        scanf("%d",&operation);

        switch (operation) {
          case 1: head->display();
                  break;
          case 2: printf("\nvalue: ");
                  scanf("%d", &value);
                  head = head->insert_at_head(value);
                  break;
          case 3: printf("\nvalue: ");
                  scanf("%d", &value);
                  head = head->insert_at_tail(value);
                  break;
	  case 4: head = head->delete_at_head();
                  break;
          case 5: head = head->delete_at_tail();
                  break;
          case 6: printf("\nwith which value? ");
                  scanf("%d", &value);
                  head = head->delete_with_val(value);
                  break;
          case 7: printf("\nfind which value? ");
                  scanf("%d", &value);
                  head->find_element(value);
                  break;
          case 8: head->count_element();
                  break;
          case 9: head = head->destroy_list();
                  break;
          case 10:
                  break;
          default: printf("undefined input\n");
        }
    } while(operation!= 10);

    return 0;
}
