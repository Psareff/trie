#define DEBUG 1 
#include "trie.h"
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "en_US.UTF-8");

	DBG(L"CREATE TRIE");
	trie_t *trie = create_trie();

	wchar_t *words[] = {
		#include "words_ru_RU.h"
	};

	DBG(L"INSERT");
	for (int i = 0; i < sizeof(words)/sizeof(words[0]); i++)
		insert_trie(trie, words[i]);

	wchar_t str[100] = L"";
	DBG(L"PRINT TRIE");
	trie_to_file(trie, 0, L"", str, stdout);

	DBG(L"SEARCH TRIE");
	wprintf(L"found %ls=%ld\n", L"это", search(trie, L"это"));

	DBG(L"DELETE NODE");
	delete_trie(trie, L"это");

	DBG(L"SEARCH TRIE");
	wprintf(L"found %ls=%d\n", L"это", search(trie, L"это"));

	DBG(L"PRINT TRIE");
	trie_to_file(trie, 0, L"", str, stdout);
}
