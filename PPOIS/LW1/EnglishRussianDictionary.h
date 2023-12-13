/**
* @file EnglishRussianDictionary.h
* This file containce prototipes of main Class
*/


#pragma once
#include <string>
#include <fstream>
#include "gtest/gtest.h"

/// Struct, thet contain information about nodes of the binar tree
struct PairOfWords
{
	std::string english_word_;///<It's english word, thet is used like key
	std::string russian_tranlation_;///< It's the translstion of the english word
	PairOfWords* right_child_ = NULL;///< It's the pointer to one of 2 children
	PairOfWords* left_child_ = NULL;///< It's the pointer to one of 2 children
};


class EnglishRussianDictionary
{
private:
	PairOfWords* english_russian_dictionary_tree_root_;

	void DeleteAll(PairOfWords* root);

	PairOfWords* FindPerentForNew(std::string english_word, PairOfWords* root);

	bool DeleteEnglishWordNoChildren(PairOfWords* root);

	bool DeleteEnglishWordOneChild(PairOfWords* root);

	bool DeleteEnglishWordTwoChildren(PairOfWords* root);

	PairOfWords* FindPerantElement(std::string english_word, PairOfWords* root);

	PairOfWords* FindElement(std::string english_word, PairOfWords* root);

	int CountNamberOfWordsLogic(PairOfWords* root);

public:
	EnglishRussianDictionary();

	~EnglishRussianDictionary();

	bool IsContain(std::string english_word);

	bool AddNewPairOfWords(std::string english_word, std::string russian_translation);

	int CountNamberOfWords();

	bool DeleteEnglishWord(std::string english_word);

	bool ChangeTranslation(std::string english_word, std::string russian_translation);

	std::string operator[](std::string english_word);

	bool ReadDictionaryFromFile(EnglishRussianDictionary& new_dictionary, std::string filename);
};


