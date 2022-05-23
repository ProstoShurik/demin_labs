#include <stdlib.h>
#include <stdio.h>
struct ListNode {
	struct ListNode* next;
	int value;
};
typedef struct ListNode* LNode;
LNode get(LNode listNode, unsigned index) {
	if (listNode == NULL) {
		return NULL;
	}
	else if (index == 0) {
		return listNode;
	}
	else {
		return get(listNode->next, index - 1);
	}
}
LNode get_pos_value(LNode listNode, unsigned value) {
	if (listNode == NULL) return NULL;
	if ((listNode->value) == value) {
		return listNode;
	}
	else {
		return get_pos_value(listNode->next, value);
	}
}
LNode construct_node(int value) {
	LNode new_node = (LNode)malloc(sizeof(struct ListNode));
	new_node->value = value;
	new_node->next = NULL;
	return new_node;
}
LNode add_node_to_list(LNode list_node, int value) {
	LNode new_node = construct_node(value);
	list_node->next = new_node;
	return new_node;
}
LNode find_even(LNode list_node) {
	while (list_node != NULL) {
		if (!(list_node->value & 1)) return list_node;
		list_node = list_node->next;
	}
	return NULL;
}
LNode delete(LNode list_node, int value) {
	if (list_node == NULL) return NULL;
	unsigned char flag = 0;
	if (get_pos_value(&list_node, value) == NULL) return NULL;
	LNode delete_node = get_pos_value(&list_node, value);
	LNode end_new_list_node, start_new_list_node;
	if(list_node->value != delete_node->value){ 

	end_new_list_node = start_new_list_node = construct_node(list_node->value); 
	list_node = list_node->next;
	}
	else {
		flag = 1;
		list_node = list_node->next;
		end_new_list_node = start_new_list_node = construct_node(list_node->value);
	}
	while ((list_node->next)!= NULL) {
		if (list_node->value != delete_node->value||flag == 1) {
			end_new_list_node = add_node_to_list(end_new_list_node, list_node->value);
			list_node = list_node->next;
		}
		else {
			flag = 1;
			list_node = list_node->next;
		}
	}
	if (list_node->value != delete_node->value || flag == 1) {
		end_new_list_node = add_node_to_list(end_new_list_node, list_node->value);
	}
	return start_new_list_node;
}
void print(LNode list_node) {
	if (list_node == NULL) return;
	printf("! %d !\n", list_node->value);
	print(list_node->next);
}
LNode even(LNode listNode) {
	LNode end_new_list_node, start_new_list_node;
	listNode = find_even(listNode);

	if (listNode == NULL) return NULL;
	else {
		end_new_list_node = start_new_list_node = construct_node(listNode->value);
		listNode = listNode->next;
		while ((listNode = find_even(listNode)) != NULL) {
			end_new_list_node = add_node_to_list(end_new_list_node, listNode->value);
			listNode = listNode->next;
		}
		return start_new_list_node;
	}
}

int main() {
	struct ListNode l1, l2, l3, l4, l5, l6, l7; LNode even_list, got, del;
	l1.value = 1; l1.next = &l2;
	l2.value = 2; l2.next = &l3;
	l3.value = 3; l3.next = &l4;
	l4.value = 4; l4.next = &l5;
	l5.value = 5; l5.next = &l6;
	l6.value = 6; l6.next = &l7;
	l7.value = 5; l7.next = NULL;
	int it = 0;
	printf("l1\n");
	print(&l1);
	printf("DEL  \n");
	del = delete(&l1, 5);
	print(del);
	getchar();
}