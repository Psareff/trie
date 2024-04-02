#include "../include/trie.h"

int main()
{
	char *words[] = {
		#include "../include/words.h"
	};
	trie_t *trie = create_trie();
	for (int i = 0; i < sizeof(words)/sizeof(words[0]); i++)
		insert_trie(trie, words[i]);

	char str[20];
	trie_to_file(trie, 0, "", str, stdout);
	printf("found %s=%d\n", "sed", search(trie, "sed"));
	printf("found %s=%d\n", "seq", search(trie, "seq"));
	delete_trie(trie, "sed");
	printf("found %s=%d\n", "sed", search(trie, "sed"));
	insert_trie(trie, "sed");
	printf("found %s=%d\n", "sed", search(trie, "sed"));
}
