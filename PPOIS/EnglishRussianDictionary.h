/**
* @file EnglishRussianDictionary.h
* This file containce prototipes of main Class
*/


#pragma once
#include <string>
#include "gtest/gtest.h"
#include <fstream>


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
	PairOfWords *english_russian_dictionary_tree_root_;

	void DeleteAll (PairOfWords* root);
	PairOfWords* FindPerentForNew(PairOfWords* root, PairOfWords* new_element);
	bool DeleteEnglishWordNoChildren(PairOfWords* root);
	bool DeleteEnglishWordOneChild(PairOfWords* root);
	bool DeleteEnglishWordTwoChildren(PairOfWords* root);
	PairOfWords* FindPerantElement(std::string english_word, PairOfWords* root);
	PairOfWords* FindElement(std::string);

public:
	EnglishRussianDictionary();
	
	~EnglishRussianDictionary();

	bool IsContain(std::string english_word);

	bool AddNewPairOfWords(std::string english_word, std::string russian_translation);

	int CountNamberOfWords(PairOfWords* root);

	bool DeleteEnglishWord(std::string english_word);

	bool ChangeTranslation(std::string english_word, std::string russian_translation);

	std::string operator [](std::string english_word);

	bool ReadDictionaryFromFile(EnglishRussianDictionary& new_dictionary, std::string falename);
};

