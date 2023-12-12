/**
* @file EnglishRussianDictionary.h
* This file containce prototipes of main Class
*/


#pragma once
#include <string>
#include <fstream>
#include "gtest/gtest.h"
//#include "d:\LW1\packages\Microsoft.googletest.v140.windesktop.msvcstl.static.rt-dyn.1.8.1.6\build\native\include\gtest\gtest.h"
//#include "D:\LW1\packages\Microsoft.googletest.v140.windesktop.msvcstl.static.rt-dyn.1.8.1.6\build\native\include\gtest\gtest.h"

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
protected:
	PairOfWords* english_russian_dictionary_tree_root_;

	void DeleteAll(PairOfWords* root);//done

	PairOfWords* FindPerentForNew(std::string english_word, PairOfWords* root);//done

	bool DeleteEnglishWordNoChildren(PairOfWords* root);

	bool DeleteEnglishWordOneChild(PairOfWords* root);

	bool DeleteEnglishWordTwoChildren(PairOfWords* root);

	PairOfWords* FindPerantElement(std::string english_word, PairOfWords* root);

	PairOfWords* FindElement(std::string english_word, PairOfWords* root);//done

	int CountNamberOfWordsLogic(PairOfWords* root);//done

public:
	EnglishRussianDictionary();//done

	~EnglishRussianDictionary();//done

	bool IsContain(std::string english_word);//done

	bool AddNewPairOfWords(std::string english_word, std::string russian_translation);//done

	int CountNamberOfWords();//done

	bool DeleteEnglishWord(std::string english_word);

	bool ChangeTranslation(std::string english_word, std::string russian_translation);//done

	std::string operator[](std::string english_word);//done

	bool ReadDictionaryFromFile(EnglishRussianDictionary& new_dictionary, std::string filename);//done
};


