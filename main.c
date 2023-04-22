#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

struct TrieNode {
  struct TrieNode *children[ALPHABET_SIZE];
  int count;
};

struct Trie {
  struct TrieNode *root;
};

struct TrieNode *createNode() {
  struct TrieNode *node = (struct TrieNode *)malloc(sizeof(struct TrieNode));
  node->count = 0;
  for (int i = 0; i < ALPHABET_SIZE; i++) {
    node->children[i] = NULL;
  }
  return node;
}

void insert(struct Trie **ppTrie, char *word) {
  struct Trie *pTrie = *ppTrie;
  if (pTrie == NULL) {
    pTrie = (struct Trie *)malloc(sizeof(struct Trie));
    pTrie->root = createNode();
    *ppTrie = pTrie;
  }

  struct TrieNode *current = pTrie->root;
  for (int i = 0; i < strlen(word); i++) {
    char c = tolower(word[i]);
    if (current->children[c - 'a'] == NULL) {
      current->children[c - 'a'] = createNode();
    }
    current = current->children[c - 'a'];
  }
  current->count++;
}

int numberOfOccurrences(struct Trie *pTrie, char *word) {
  struct TrieNode *current = pTrie->root;
  for (int i = 0; i < strlen(word); i++) {
    char c = tolower(word[i]);
    if (current->children[c - 'a'] == NULL) {
      return 0;
    }
    current = current->children[c - 'a'];
  }
  return current->count;
}

void deallocateNode(struct TrieNode *node) {
  for (int i = 0; i < ALPHABET_SIZE; i++) {
    if (node->children[i] != NULL) {
      deallocateNode(node->children[i]);
    }
  }
  free(node);
}

struct Trie *deallocateTrie(struct Trie *pTrie) {
  if (pTrie != NULL) {
    deallocateNode(pTrie->root);
    free(pTrie);
    pTrie = NULL;
  }
  return pTrie;
}

int main(void) {
  struct Trie *trie = NULL;
  // read the number of the words in the dictionary
  //  parse line  by line, and insert each word to the trie data structure
  char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};

  

  for (int i = 0; i < 5; i++) {
    printf("\t%s : %d\n", pWords[i], numberOfOccurances(&trie, pWords[i]));
  }
  trie = deallocateTrie(&trie);
  if (trie != NULL)
    printf("There is an error in this program\n");
  return 0;
}