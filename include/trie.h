#ifndef TRIE_H_
#define TRIE_H_

#include <stdio.h>

#include <wchar.h>
#define FIRST_LETTER 0x430 
#define ALPHABET_SIZE 32

#define TRAVERSE_TRIE for (int i = 0; i < ALPHABET_SIZE; i++)
#define NODE_BY_LETTER(letter) head->descendants[letter - FIRST_LETTER]

#ifdef DEBUG 
#define DBG(...) \
	wprintf(L"[File:%s, %s<%d>]: ", __FILE__, __func__, __LINE__); \
	wprintf(__VA_ARGS__); \
	wprintf(L"\n"); \
	fflush(stdout);
#else 
#define DBG(...) {}
#endif  

typedef struct trie trie_t;

typedef struct trie {
	trie_t* descendants[ALPHABET_SIZE];
    int is_final;
} trie_t;

void insert_trie(trie_t *head, wchar_t *word);
int search(trie_t *head, wchar_t *word);
trie_t *create_trie();
void trie_to_file(trie_t *trie, int level, wchar_t *beginning, wchar_t *str, FILE *fp);
void delete_trie(trie_t *head, wchar_t *word);


#endif //TRIE_H_
