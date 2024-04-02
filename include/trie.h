#ifndef TRIE_H_
#define TRIE_H_

#include <stdio.h>

#define FIRST_LETTER 'a'
#define ALPHABET_SIZE 26

#define TRAVERSE_TRIE for (int i = 0; i < ALPHABET_SIZE; i++)
#define NODE_BY_LETTER(letter) head->descendants[letter - 'a']

#ifdef DEBUG 
#define DBG(...) \
	printf("[File:%s, %s<%d>: ", __FILE__, __func__, __LINE__); \
	printf(__VA_ARGS__); \
	printf("\n");
#else 
#define DBG(...) {}
#endif  

typedef struct trie trie_t;

typedef struct trie {
	trie_t* descendants[ALPHABET_SIZE];
    int is_final;
} trie_t;

void insert_trie(trie_t *head, char *word);
int search(trie_t *head, char *word);
trie_t *create_trie();
void trie_to_file(trie_t *trie, int level, char *beginning, char *str, FILE *fp);
void delete_trie(trie_t *head, char *word);


#endif //TRIE_H_
