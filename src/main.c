#include "../include/trie.h"
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "en_US.UTF-8");
	//for (long int i = 0x0400; i < 0x04ff; i++)

	//wprintf(L"%lc = %ld\n", i, i);
	trie_t *trie = create_trie();
		//insert_trie(trie, L"абв");
	wchar_t *words[] = {
		#include "../include/words_ru_RU.h"
	};
	for (int i = 0; i < sizeof(words)/sizeof(words[0]); i++)
		insert_trie(trie, words[i]);
	wchar_t str[100] = L"";
	trie_to_file(trie, 0, L"", str, stdout);
	wprintf(L"found %ls=%ld\n", L"это", search(trie, L"это"));
	//delete_trie(trie, L"это");
	//wprintf(L"found %ls=%d\n", L"это", search(trie, L"это"));
	//trie_to_file(trie, 0, L"", str, stdout);
	/*

	char str[20];
	trie_to_file(trie, 0, "", str, stdout);
	printf("found %s=%d\n", "sed", search(trie, "sed"));
	printf("found %s=%d\n", "seq", search(trie, "seq"));
	delete_trie(trie, "sed");
	printf("found %s=%d\n", "sed", search(trie, "sed"));
	insert_trie(trie, "sed");
	printf("found %s=%d\n", "sed", search(trie, "sed"));
	*/
}
