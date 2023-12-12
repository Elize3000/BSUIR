/**
* @file  Test.cpp
*/

#include "pch.h"
#include "EnglishRussianDictionary.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(DictionaryTest, FindElementTest) {
	EnglishRussianDictionary dictionary;

	dictionary.AddNewPairOfWords("Table", "Stol");

	ASSERT_EQ(dictionary["Table"], "Stol");
}

TEST(DictionaryTest, DeleteElementTest) {
	EnglishRussianDictionary dictionary;

	dictionary.AddNewPairOfWords("BSUIR", "BGYIR");
	ASSERT_TRUE(dictionary.IsContain("BSUIR"));

	dictionary.DeleteEnglishWord("BSUIR");
	ASSERT_FALSE(dictionary.IsContain("BSUIR"));

	
	dictionary.AddNewPairOfWords("mint", "мята");
	dictionary.AddNewPairOfWords("beauty", "красота");
	dictionary.AddNewPairOfWords("japan", "япония");
	dictionary.AddNewPairOfWords("clover", "клевер");
	dictionary.AddNewPairOfWords("lavender", "лаванда");
	dictionary.AddNewPairOfWords("sun", "солнце");
	dictionary.AddNewPairOfWords("shiba-inu", "сиба-ину");
	dictionary.AddNewPairOfWords("design", "дизайн");
	dictionary.AddNewPairOfWords("headphones", "наушники");
	dictionary.AddNewPairOfWords("library", "библиотека");
	dictionary.AddNewPairOfWords("outfit", "образ");

	dictionary.DeleteEnglishWord("clover");
	ASSERT_FALSE(dictionary.IsContain("clover"));

	dictionary.DeleteEnglishWord("japan");
	ASSERT_FALSE(dictionary.IsContain("japan"));

}

TEST(DictionaryTest, AddNewTest) {
	EnglishRussianDictionary dictionary;

	dictionary.AddNewPairOfWords("ai", "ii");
	dictionary.AddNewPairOfWords("reading", "chtenie");

	dictionary.ChangeTranslation("ai", "topcpecuha");
	dictionary.ChangeTranslation("reading", "hobby");

	ASSERT_EQ(dictionary["ai"], "topcpecuha");
	ASSERT_EQ(dictionary["reading"], "hobby");
}

TEST(DictionaryTest, CountNamberTest) {
	EnglishRussianDictionary dictionary;

	dictionary.AddNewPairOfWords("sun", "солнце");
	dictionary.AddNewPairOfWords("shiba-inu", "сиба-ину");
	dictionary.AddNewPairOfWords("mint", "мята");
	dictionary.AddNewPairOfWords("beauty", "красота");
	dictionary.AddNewPairOfWords("japan", "япония");
	dictionary.AddNewPairOfWords("clover", "клевер");
	dictionary.AddNewPairOfWords("lavender", "лаванда");
	dictionary.AddNewPairOfWords("design", "дизайн");
	dictionary.AddNewPairOfWords("headphones", "наушники");
	dictionary.AddNewPairOfWords("library", "библиотека");
	dictionary.AddNewPairOfWords("outfit", "образ");


	ASSERT_EQ(dictionary.CountNamberOfWords(), 11);
}


TEST(DictionaryTest, ReadDictionaryFromFileTest) {
	EnglishRussianDictionary dictionary;
	ASSERT_TRUE(dictionary.CountNamberOfWords() == 0);

	std::string file = "test.txt";
	dictionary.ReadDictionaryFromFile(dictionary, file);
	ASSERT_EQ(dictionary.CountNamberOfWords(), 3);
}

