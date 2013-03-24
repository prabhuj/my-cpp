#include <iostream>
#include <cstdlib>

#define NUM_CHARS 26

using namespace std;

struct list_node
{
	int index;
	struct list_node* next;
};

typedef struct list_node* list_node_ptr;

list_node_ptr get_list_node(int index)
{
	list_node_ptr new_node = new list_node();
	new_node->index = index;
	new_node->next = NULL;
	return new_node;
}

struct trie_node
{
	bool eow;
	struct trie_node* child[NUM_CHARS];
	list_node_ptr head;
};

typedef struct trie_node* trie_node_ptr;

trie_node_ptr get_trie_node()
{
	trie_node_ptr new_node = new trie_node();
	new_node->eow = false;
	for(int i=0;i<NUM_CHARS;i++)
	{
		new_node->child[i] = NULL;
	}
	new_node->head = NULL;
	return new_node;
}

int compare_char(const void* a, const void* b)
{
	return *(char*)a - *(char*)b;
}

void trie_insert(trie_node_ptr *root, char* word, int index)
{
	if(!(*root))
		(*root) = get_trie_node();

	if (*word != '\0')
	{
		trie_insert(&((*root)->child[tolower(*word) - 'a']), word+1, index );
	}
	else
	{
		if ((*root)->eow)
		{
			list_node_ptr tmp = (*root)->head;
			while(tmp->next) tmp = tmp->next;
			tmp->next = get_list_node(index);
		}
		else
		{
			(*root)->eow = true;
			(*root)->head = get_list_node(index);
		}
	}
}

void trie_print(trie_node_ptr root, char* word_list[])
{
	if(!root) return;

	if(root->eow)
	{
		list_node_ptr head = root->head;

		while(head)
		{
			cout << word_list[head->index] << endl;
			head = head->next;
		}
	}

	for(int i=0;i<NUM_CHARS;i++)
	{
		trie_print(root->child[i], word_list);
	}
}

void print_anagrams(char* word_list[], int word_list_length)
{
	trie_node_ptr my_trie = NULL;

	for(int i=0;i<word_list_length;i++)
	{
		int len = strlen(word_list[i]);
		char *buffer = new char[len+1];
		strcpy(buffer, word_list[i]);

		qsort((void *)buffer, strlen(buffer), sizeof(char), compare_char);
		trie_insert(&my_trie, buffer, i);
	}

	trie_print(my_trie, word_list);
}

int main()
{
	char* words[] = {"cat", "dog", "tac", "god", "act", "gdo"};

	int size = sizeof(words)/sizeof(words[0]);

	print_anagrams(words, size);

	return 0;
}
