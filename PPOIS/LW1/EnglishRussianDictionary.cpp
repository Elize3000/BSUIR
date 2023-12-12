/**
* @file EnglishRussianDictionary.cpp
* File, thet containe all informaition about realization of main class EnglishRussianDictionary
*/


#include "EnglishRussianDictionary.h"
#include <string>


EnglishRussianDictionary::EnglishRussianDictionary()
{
	english_russian_dictionary_tree_root_ = NULL;
}

/**
	*Clears the memory
*/

EnglishRussianDictionary::~EnglishRussianDictionary()
{
	DeleteAll(english_russian_dictionary_tree_root_);
}

void EnglishRussianDictionary::DeleteAll(PairOfWords* root)
{
	if (root == NULL)
		return;
	DeleteAll(root->left_child_);
	DeleteAll(root->right_child_);
	delete root;
}

/**
	*Searches for an element
*/

bool EnglishRussianDictionary::IsContain(std::string english_word)
{
	if (FindElement(english_word, english_russian_dictionary_tree_root_) != NULL)
		return true;
	return false;
}

std::string EnglishRussianDictionary::operator[](std::string english_word)
{
	PairOfWords* faunded_element = FindElement(english_word, english_russian_dictionary_tree_root_);
	if (faunded_element == NULL)
		return "";
	return faunded_element->russian_tranlation_;
}

PairOfWords* EnglishRussianDictionary::FindElement(std::string english_word, PairOfWords* root)
{
	if (root == NULL)
		return NULL;
	if (root->english_word_ > english_word)
	{
		if (root->right_child_ != NULL)
			return FindElement(english_word, root->right_child_);
		return NULL;
	}
	if (root->english_word_ < english_word)
	{
		if (root->left_child_ != NULL)
			return FindElement(english_word, root->left_child_);
		return NULL;
	}
	return root;
}

/**
*Searches for plsce, were element coud be instolen
*/

PairOfWords* EnglishRussianDictionary::FindPerentForNew(std::string english_word, PairOfWords* root)
{
	if (root == NULL)
		return NULL;
	if (root->english_word_ > english_word)
	{
		if (root->right_child_ != NULL)
			return FindPerentForNew(english_word, root->right_child_);
		return root;
	}
	if (root->english_word_ < english_word)
	{
		if (root->left_child_ != NULL)
			return FindPerentForNew(english_word, root->left_child_);
		return root;
	}
	return NULL;
}

/**
	*Adds the pair of words. Also checs if the added element already in tree
*/

bool EnglishRussianDictionary::AddNewPairOfWords(std::string english_word, std::string russian_translation)
{
	PairOfWords* new_element = new PairOfWords;
	new_element->english_word_ = english_word;
	new_element->russian_tranlation_ = russian_translation;
	if (english_russian_dictionary_tree_root_ == NULL)
	{
		english_russian_dictionary_tree_root_ = new_element;
		return true;
	}
	PairOfWords* root = FindPerentForNew(english_word, english_russian_dictionary_tree_root_);
	if (root == NULL)
		return false;
	if (root->english_word_ > english_word)
	{
		root->right_child_ = new_element;
		return true;
	}
	root->left_child_ = new_element;
	return true;
}

/**
*Counts namber of words in dictinary
*/

int EnglishRussianDictionary::CountNamberOfWords()
{
	return CountNamberOfWordsLogic(english_russian_dictionary_tree_root_);
}

int EnglishRussianDictionary::CountNamberOfWordsLogic(PairOfWords* root)
{
	if (root == NULL)
		return 0;
	return CountNamberOfWordsLogic(root->left_child_) + CountNamberOfWordsLogic(root->right_child_) + 1;
}

/**
*Changes the translation
*/

bool EnglishRussianDictionary::ChangeTranslation(std::string english_word, std::string russian_translation)
{
	PairOfWords* current_position = FindElement(english_word, english_russian_dictionary_tree_root_);
	if (current_position == NULL)
		return false;
	current_position->russian_tranlation_ = russian_translation;
	return true;
}

/**
*Reads information from file
*/

bool EnglishRussianDictionary::ReadDictionaryFromFile(EnglishRussianDictionary& new_dictionary, std::string filename)
{
	using namespace std;
	{
		ifstream fin(filename);
		string words, english, russian;
		int flag = 1;
		while (getline(fin, words))
		{
			for (int i = 0; i <= words.size(); i++)
			{
				if (flag == 2 && english != "" && russian != "" && (words[i] == ' ' || words[i] == '\n' || i == words.size()))
				{
					AddNewPairOfWords(english, russian);
					english = "";
					russian = "";
					flag = 1;
				}
				if ((flag == 1 && english != "" && words[i] == ' '))
				{
					flag = 2;
					continue;
				}
				if (words[i] >= 'A' && words[i] <= 'z' || words[i] >= 'À' && words[i] <= 'ÿ')
				{
					if (flag == 1)
						english += words[i];
					else
						russian += words[i];
				}

			}
		}
		return true;
	}
}

/**
	*algorithm, that deletes element without children
*/

bool EnglishRussianDictionary::DeleteEnglishWordNoChildren(PairOfWords* root)
{
	PairOfWords* parent_of_element = FindPerantElement(root->english_word_, english_russian_dictionary_tree_root_);
	if (parent_of_element == NULL)
	{
		english_russian_dictionary_tree_root_ = NULL;
	}else
	if (parent_of_element->left_child_ == root)
	{
		parent_of_element->left_child_ = NULL;
	}
	else
		parent_of_element->right_child_ = NULL;
	delete root;
	return true;
}

/**
	*algorithm, that deletes element with one child
*/

bool EnglishRussianDictionary::DeleteEnglishWordOneChild(PairOfWords* root)
{
	PairOfWords* parent_of_element = FindPerantElement(root->english_word_, english_russian_dictionary_tree_root_);
	if (parent_of_element == NULL)
	{
		if (root->left_child_ != NULL)
			english_russian_dictionary_tree_root_ = root->left_child_;
		else
		{
			english_russian_dictionary_tree_root_ = root->right_child_;
		}
	}
	else
	if (parent_of_element->left_child_ == root)
	{
		if (root->left_child_ != NULL)
			parent_of_element->left_child_ = root->left_child_;
		else
		{
			parent_of_element->left_child_ = root->right_child_;
		}
	}
	else
	{
		if (root->left_child_ != NULL)
			parent_of_element->right_child_ = root->left_child_;
		else
		{
			parent_of_element->right_child_ = root->right_child_;
		}
	}
	delete root;
	return true;
}

/**
	*algorithm, that deletes element with two children
*/

bool EnglishRussianDictionary::DeleteEnglishWordTwoChildren(PairOfWords* root)
{
	PairOfWords* parent_of_element = FindPerantElement(root->english_word_, english_russian_dictionary_tree_root_);
	PairOfWords* element_for_swap = root->left_child_;
	if (element_for_swap->right_child_ == NULL)
	{
		element_for_swap->right_child_ = root->right_child_;
		if (parent_of_element == NULL)
		{
			english_russian_dictionary_tree_root_ = element_for_swap;
		}
		else
			if (parent_of_element->left_child_ == root)
			{
				parent_of_element->left_child_ = element_for_swap;
			}
			else
				parent_of_element->right_child_ = element_for_swap;
		delete root;
		return true;
	}
	while (element_for_swap->right_child_ != NULL)
	{
		element_for_swap = element_for_swap->right_child_;
	}
	PairOfWords* buf_to_change_adress = FindPerantElement(element_for_swap->english_word_, english_russian_dictionary_tree_root_);
	buf_to_change_adress->right_child_ = NULL;

	element_for_swap->right_child_ = root->right_child_;
	element_for_swap->left_child_ = root->left_child_;
	if (parent_of_element == NULL)
	{
		english_russian_dictionary_tree_root_ = element_for_swap;
	} else
	if (parent_of_element->left_child_ == root)
	{
		parent_of_element->left_child_ = element_for_swap;
	}
	else
		parent_of_element->right_child_ = element_for_swap;
	delete root;
	return true;
}

/**
	*searches for elemen, that is perent
*/

PairOfWords* EnglishRussianDictionary::FindPerantElement(std::string english_word, PairOfWords* root)
{
	if (root->english_word_ == english_word)
		return NULL;
	if (root->right_child_!= NULL && root->right_child_->english_word_ == english_word)
		return root;
	if (root->left_child_!= NULL && root->left_child_->english_word_ == english_word)
		return root;
	if (root->english_word_ > english_word)
		return FindPerantElement(english_word, root->right_child_);
	return FindPerantElement(english_word, root->left_child_);
}

/**
	*Searches and deletes element
*/

bool EnglishRussianDictionary::DeleteEnglishWord(std::string english_word)
{
	PairOfWords* element = FindElement(english_word, english_russian_dictionary_tree_root_);
	if (element == NULL)
		return false;
	if (element->left_child_ == NULL && element->right_child_ == NULL)
	{
		DeleteEnglishWordNoChildren(element);
	}
	else
	{
		if (element->left_child_ == NULL || element->right_child_ == NULL)
			DeleteEnglishWordOneChild(element);
		else DeleteEnglishWordTwoChildren(element);
	}
	return true;
}
