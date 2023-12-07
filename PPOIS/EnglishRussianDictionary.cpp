/**
* @file EnglishRussianDictionary.cpp
* File, thet containe all informaition about realization of main class EnglishRussianDictionary
*/


#include "pch.h"
#include <fstream>
#include "EnglishRussianDictionary.h"
#include <string>


	EnglishRussianDictionary::EnglishRussianDictionary()
	{
		english_russian_dictionary_tree_root_ = NULL;
	}
	/**
	*Clears the memory
	*/
	void EnglishRussianDictionary::DeleteAll(PairOfWords* root)
	{
		if (root == NULL)
			return;
		DeleteAll(root->right_child_);
		DeleteAll(root->right_child_);
		delete root;
	}

	EnglishRussianDictionary::~EnglishRussianDictionary()
	{
		DeleteAll(english_russian_dictionary_tree_root_);
		english_russian_dictionary_tree_root_ == NULL;
	}

	/**
	*Adds the pair of words. Also checs if the added element already in tree
	*/
	bool EnglishRussianDictionary::AddNewPairOfWords(std::string english_word, std::string russian_translation)
	{
		PairOfWords* new_pair_of_words = new PairOfWords;
		new_pair_of_words->english_word_ = english_word;
		new_pair_of_words->russian_tranlation_ = russian_translation;
		PairOfWords* root = english_russian_dictionary_tree_root_;
	    if(root == NULL)
			root = new_pair_of_words;
		return root;
		root = FindPerentForNew(root, new_pair_of_words);
		if (root != NULL && root->english_word_ > new_pair_of_words->english_word_)
			root->left_child_ = new_pair_of_words;
		else if (root != NULL)
		{
			root->right_child_ = new_pair_of_words;
		}
		else return false;
		return true;
	}

	/**
	*Searches for plsce, were element coud be instolen
	*/

	PairOfWords* EnglishRussianDictionary::FindPerentForNew(PairOfWords* root, PairOfWords* new_element)
	{
		if (root->english_word_ == new_element->english_word_)
			return NULL;
		if (root->english_word_ > new_element->english_word_ && root->right_child_ != NULL)
			FindPerentForNew(root->right_child_, new_element);
		else if (root->english_word_ < new_element->english_word_ && root->left_child_ != NULL)
			FindPerentForNew(root->left_child_, new_element);
		return root;

	}
	/**
	*Searches for an element
	*/

	PairOfWords* EnglishRussianDictionary::FindElement(std::string english_word)
	{
		PairOfWords* current_search_point_ = english_russian_dictionary_tree_root_;
		if (current_search_point_ == NULL)
			return NULL;
			while (true)
			{
				if (current_search_point_->english_word_ > english_word)
				{
					if (current_search_point_->right_child_ != NULL)
						current_search_point_ = current_search_point_->right_child_;
					else return NULL;
				}if (current_search_point_->english_word_ < english_word)
				{      
					 if (current_search_point_->left_child_ != NULL)
						current_search_point_ = current_search_point_->left_child_;
					else return NULL;
				}
			}if (current_search_point_->english_word_ == english_word)
				return current_search_point_;
	}

	/**
	*searches for elemen, thet is perent 
	*/

	PairOfWords* EnglishRussianDictionary::FindPerantElement(std::string english_word, PairOfWords* root)
	{
		if (root->left_child_->english_word_ == english_word || root->right_child_->english_word_ == english_word)
			return root;
		if (root->english_word_ > english_word)
			return FindPerantElement(english_word, root->right_child_);
		else if (root->english_word_ < english_word)
			return FindPerantElement(english_word, root->right_child_);
		
	}

	/**
	*Searches and deletes element
	*/

	bool EnglishRussianDictionary::DeleteEnglishWord(std::string english_word)
	{
		if (english_russian_dictionary_tree_root_ == NULL)
			return false;
		
		PairOfWords* faunded_element= FindElement(english_word);
		if (faunded_element == NULL)
			return false;
		if (faunded_element->left_child_ == NULL && faunded_element->right_child_ == NULL)
		{
			return DeleteEnglishWordOneChild(faunded_element);
		}else if (faunded_element->left_child_ == NULL || faunded_element->right_child_ == NULL)
		{
			return DeleteEnglishWordNoChildren(faunded_element);
		}else
		{
			DeleteEnglishWordTwoChildren(faunded_element);
		}


	}

	/**
	*Different algorithm for different situations
	*/

	bool EnglishRussianDictionary::DeleteEnglishWordNoChildren(PairOfWords* root)
	{
		PairOfWords* Perent = FindPerantElement(root->english_word_, english_russian_dictionary_tree_root_);
		if (Perent->left_child_ == root)
			Perent->left_child_ = NULL;
		if (Perent->right_child_ == root)
			Perent->right_child_ = NULL;
		delete root;
		return true;

	}
	bool EnglishRussianDictionary::DeleteEnglishWordOneChild(PairOfWords* root)
	{
		PairOfWords* Perent = FindPerantElement(root->english_word_, english_russian_dictionary_tree_root_);
		if (Perent->left_child_ == root)
		{
			if (root->left_child_ == NULL)
			{
				Perent->left_child_ = root->right_child_;
			}
			else
				Perent->right_child_ = root->left_child_;
		}else if (root->left_child_ == NULL)
		{
			Perent->left_child_ = root->right_child_;
		}
		else
			Perent->right_child_ = root->left_child_;
		delete root;
		return true;
	}
	bool EnglishRussianDictionary::DeleteEnglishWordTwoChildren(PairOfWords* root)
	{
		PairOfWords* Perent = FindPerantElement(root->english_word_, english_russian_dictionary_tree_root_);
		PairOfWords* Child = root->right_child_;
		while (Child->left_child_!= NULL)
		{
			Child = Child->left_child_;
		}
		if (Perent->right_child_ == root)
		{
			Perent->right_child_ == Child;
		}
		else
			Perent->left_child_ == Child;
		return true;


	}

	/**
	*Changes translation for english word
	*/

	bool EnglishRussianDictionary::ChangeTranslation(std::string english_word, std::string russian_translation)
	{
		PairOfWords* current_search_point_ = FindElement(english_word);
		if (current_search_point_ != NULL)
		{
			current_search_point_->russian_tranlation_ = russian_translation;
			return true;
		}
		return false;
	}

	/**
	*Opperation override
	*/

	std::string EnglishRussianDictionary::operator [](std::string english_word)
	{
		PairOfWords* faunded_elemeent = FindElement(english_word);
		if (faunded_elemeent == NULL)
			return "";
		else return faunded_elemeent->russian_tranlation_;
	}

	/**
	*ACounts the namber of words in the dictionary
	*/

	int EnglishRussianDictionary::CountNamberOfWords(PairOfWords* root)
	{
		if (root == NULL)
			return 0;
		return CountNamberOfWords(root->left_child_) + CountNamberOfWords(root->right_child_) + 1;
	}

	/**
	*Enters dictionary from file
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
				if (flag == 2 && english != "" && russian != "" && words[i] == ' ')
				{
					AddNewPairOfWords(english, russian);
					english = "";
					russian = "";
					flag = 1;
				}
				if ((flag == 1 && english != "" && words[i] == ' '))
				{
					flag = 2;
				}
				if (words[i] >= 'a' && words[i] <= 'Z' || words[i] >= 'à' && words[i] <= 'ß')
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

bool EnglishRussianDictionary::IsContain(std::string english_word)
{
	if (FindElement(english_word) != NULL)
		return true;
	return false;
}