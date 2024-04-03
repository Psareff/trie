#include <stdlib.h>
#include <stdio.h>
#include "../include/trie.h"
#include "string.h"


trie_t *create_trie()
{
	trie_t *buff = malloc(sizeof(trie_t));
	buff->is_final = 0;
	TRAVERSE_TRIE
		buff->descendants[i] = NULL;
	return buff;
}

void insert_trie(trie_t *head, wchar_t *word)
{
	DBG(L"%ls", word);
	if (*word == 0) { head->is_final = 1; return; }
	NODE_BY_LETTER(*word) = NODE_BY_LETTER(*word) ? 
	                        NODE_BY_LETTER(*word) : 
	                        create_trie();
	trie_t *buff = NODE_BY_LETTER(*word);
	insert_trie(buff, ++word);
}

int search(trie_t *head, wchar_t *word)
{
	DBG(L"%ls", word);
	trie_t *buff = head;
	for (; *word != 0, buff->descendants[*word - FIRST_LETTER] != NULL; word++)
	{
	wprintf(L"HERE\n");
		buff = buff->descendants[*word - FIRST_LETTER];
		wprintf(L"%ls %ld \n", word, *word - FIRST_LETTER);
	wprintf(L"HERE1\n");
	}
	wprintf(L"HERE2\n");
	if (buff->is_final == 1)
		return 1;
	return 0;
}

void delete_trie(trie_t *head, wchar_t *word)
{
	//DBG(L"%ls", word);
	trie_t *buff = head;
	for (; *word != '\0', buff->descendants[*word - FIRST_LETTER] != NULL; word++)
		buff = buff->descendants[*word - FIRST_LETTER];
	if (buff->is_final == 1)
		buff->is_final = 0;
	return;
}

char *prefix_search(trie_t *head, wchar_t *word, FILE *fp)
{
	trie_t *buff = head;
	wchar_t str[20], beginning[20];
	wcscpy(beginning, word);
	for (; *word != '\0', buff->descendants[*word - FIRST_LETTER] != NULL; word++)
		buff = buff->descendants[*word - FIRST_LETTER];

	trie_to_file(buff, 0, beginning, str, fp);
	return NULL;

}

void trie_to_file(trie_t *trie, int level, wchar_t *beginning, wchar_t *str, FILE *fp)
{
	if (trie->is_final)
	{
		str[level] = '\0';
		fwprintf(fp, L"%ls%ls\n", beginning, str);
	}
	TRAVERSE_TRIE
	{
		//wprintf(L"%ls\n", trie->descendants[i] == NULL ? L"null" : L"not null");
		if (trie->descendants[i] != NULL)
		{
			str[level] = i + FIRST_LETTER;
			trie_to_file(trie->descendants[i], level + 1, beginning, str, fp);
		}
	}
}
