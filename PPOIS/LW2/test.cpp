#include "pch.h"
#include "F:\Sample-Test\BookwareHouse\Box.h"
#include "F:\Sample-Test\BookwareHouse\Box.cpp"
#include "F:\Sample-Test\BookwareHouse\Bookshel.h"
#include "F:\Sample-Test\BookwareHouse\Bookshel.cpp"
#include "F:\Sample-Test\BookwareHouse\Bookcase.h"
#include "F:\Sample-Test\BookwareHouse\Bookcase.cpp"
#include "F:\Sample-Test\BookwareHouse\Administratar.h"
#include "F:\Sample-Test\BookwareHouse\Administratar.cpp"
#include "F:\Sample-Test\BookwareHouse\AdminustrationUniuon.h"
#include "F:\Sample-Test\BookwareHouse\AdminustrationUniuon.cpp"
#include "F:\Sample-Test\BookwareHouse\Bueir.h"
#include "F:\Sample-Test\BookwareHouse\Bueir.cpp"
#include "F:\Sample-Test\BookwareHouse\Owner.h"
#include "F:\Sample-Test\BookwareHouse\Owner.cpp"
#include "F:\Sample-Test\BookwareHouse\Seller.h"
#include "F:\Sample-Test\BookwareHouse\Seller.cpp"
#include "F:\Sample-Test\BookwareHouse\WarehouseBuilding.h"
#include "F:\Sample-Test\BookwareHouse\WarehouseBuilding.cpp"
#include "F:\Sample-Test\BookwareHouse\WareHouseModel.h"
#include "F:\Sample-Test\BookwareHouse\WareHouseModel.cpp"
#include "F:\Sample-Test\BookwareHouse\WarehouseSheldure.h"
#include "F:\Sample-Test\BookwareHouse\WarehouseSheldure.cpp"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(BoxTest, BoxTest) {
	Book book1("Name1", "Nikolay", "Gogol", "mistica");
	Book book2("Name2", "Dasai", "Osamu", "novel");
	Book book3("Name3", "Edgard", "Allan Poe", "detective");
	Book book4("Name4", "Fedor", "Dostoevsky", "drama");
	Box box(3);
	EXPECT_TRUE(box.AddBookToBox(book1));
	EXPECT_TRUE(box.AddBookToBox(book2));
	EXPECT_TRUE(box.AddBookToBox(book3));
	EXPECT_FALSE(box.AddBookToBox(book4));

	EXPECT_EQ(box.TekeBookFromBox("Name5"), emptyBook);
	EXPECT_EQ(box.TekeBookFromBox("Name3"), book3);
	EXPECT_EQ(box.TekeBookFromBox(book1), book1);
	EXPECT_EQ(box.TekeBookFromBox(book4), emptyBook);

	EXPECT_TRUE(box.AddBookToBox(book4));

	EXPECT_TRUE(box.FindBookInBox(book4));
	EXPECT_TRUE(box.FindBookInBox("Name4"));
	EXPECT_FALSE(box.FindBookInBox(book3));
	EXPECT_FALSE(box.FindBookInBox("Name1"));
}

TEST(ShelTest, ShelTest) {
	Book book1("Name1", "Nikolay", "Gogol", "mistica");
	Book book2("Name2", "Dasai", "Osamu", "novel");
	Book book3("Name3", "Edgard", "Allan Poe", "detective");
	Book book4("Name4", "Fedor", "Dostoevsky", "drama");
	Bookshel shel(3);
	Bookshel shel1(3, "novel");
	Bookshel shel2(3, "Dasai", "Osamu");
	Bookshel shel3(3,"novel", "Dasai", "Osamu");
	EXPECT_TRUE(shel.AddBookToShel(book1));
	EXPECT_TRUE(shel.AddBookToShel(book2));
	EXPECT_TRUE(shel.AddBookToShel(book3));
	EXPECT_FALSE(shel.AddBookToShel(book4));

	EXPECT_FALSE(shel1.AddBookToShel(book1));
	EXPECT_TRUE(shel1.AddBookToShel(book2));
	EXPECT_FALSE(shel1.AddBookToShel(book3));
	EXPECT_FALSE(shel1.AddBookToShel(book4));

	EXPECT_FALSE(shel2.AddBookToShel(book1));
	EXPECT_TRUE(shel2.AddBookToShel(book2));
	EXPECT_FALSE(shel2.AddBookToShel(book3));
	EXPECT_FALSE(shel2.AddBookToShel(book4));

	EXPECT_FALSE(shel3.AddBookToShel(book1));
	EXPECT_TRUE(shel3.AddBookToShel(book2));
	EXPECT_FALSE(shel3.AddBookToShel(book3));
	EXPECT_FALSE(shel3.AddBookToShel(book4));

	EXPECT_EQ(shel.TekeBookFromShel("Name5"), emptyBook);
	EXPECT_EQ(shel.TekeBookFromShel("Name3"), book3);
	EXPECT_EQ(shel.TekeBookFromShel(book1), book1);
	EXPECT_EQ(shel.TekeBookFromShel(book4), emptyBook);

	EXPECT_TRUE(shel.AddBookToShel(book4));

	EXPECT_TRUE(shel.FindBookInShel(book4));
	EXPECT_TRUE(shel.FindBookInShel("Name4"));
	EXPECT_FALSE(shel.FindBookInShel(book3));
	EXPECT_FALSE(shel.FindBookInShel("Name1"));

	EXPECT_TRUE(shel1.MakeNotTheamed());
	EXPECT_TRUE(shel2.MakeNotRelatedToAuthor());

	EXPECT_TRUE(shel1.AddBookToShel(book1));
	EXPECT_TRUE(shel2.AddBookToShel(book3));

}

TEST(BookcaseTest, BookcaseTest) {
	Book book1("Name1", "Nikolay", "Gogol", "mistica");
	Book book2("Name2", "Dasai", "Osamu", "novel");
	Book book3("Name3", "Edgard", "Allan Poe", "detective");
	Book book4("Name4", "Fedor", "Dostoevsky", "drama");
	Bookcase bookcase(3,3);
	Bookcase bookcase1(3,3, "novel");
	Bookcase bookcase2(3,3, "Dasai", "Osamu");
	Bookcase bookcase3(3,3, "novel", "Dasai", "Osamu");
	EXPECT_TRUE(bookcase.AddBookToBookcase(book1));
	EXPECT_TRUE(bookcase.AddBookToBookcase(book2));
	EXPECT_TRUE(bookcase.AddBookToBookcase(book3));
	EXPECT_TRUE(bookcase.AddBookToBookcase(book4));

	EXPECT_FALSE(bookcase1.AddBookToBookcase(book1));
	EXPECT_TRUE(bookcase1.AddBookToBookcase(book2));
	EXPECT_FALSE(bookcase1.AddBookToBookcase(book3));
	EXPECT_FALSE(bookcase1.AddBookToBookcase(book4));

	EXPECT_FALSE(bookcase2.AddBookToBookcase(book1));
	EXPECT_TRUE(bookcase2.AddBookToBookcase(book2));
	EXPECT_FALSE(bookcase2.AddBookToBookcase(book3));
	EXPECT_FALSE(bookcase2.AddBookToBookcase(book4));

	EXPECT_FALSE(bookcase3.AddBookToBookcase(book1));
	EXPECT_TRUE(bookcase3.AddBookToBookcase(book2));
	EXPECT_FALSE(bookcase3.AddBookToBookcase(book3));
	EXPECT_FALSE(bookcase3.AddBookToBookcase(book4));

	EXPECT_EQ(bookcase.TekeBookFromBookcase("Name5"), emptyBook);
	EXPECT_EQ(bookcase.TekeBookFromBookcase("Name3"), book3);
	EXPECT_EQ(bookcase.TekeBookFromBookcase(book1), book1);
	EXPECT_EQ(bookcase.TekeBookFromBookcase(book4), book4);

	EXPECT_TRUE(bookcase.AddBookToBookcase(book4));

	EXPECT_TRUE(bookcase.FindBookInBookcase(book4));
	EXPECT_TRUE(bookcase.FindBookInBookcase("Name4"));
	EXPECT_FALSE(bookcase.FindBookInBookcase(book3));
	EXPECT_FALSE(bookcase.FindBookInBookcase("Name1"));

	EXPECT_TRUE(bookcase1.MakeNotTheamed());
	EXPECT_TRUE(bookcase2.MakeNotRelatedToAuthor());

	EXPECT_TRUE(bookcase1.AddBookToBookcase(book1));
	EXPECT_TRUE(bookcase2.AddBookToBookcase(book3));

}

TEST(FullTest, FullTest) {
	Book book1("Name1", "Nikolay", "Gogol", "mistica");
	Book book2("Name2", "Dasai", "Osamu", "novel");
	Book book3("Name3", "Edgard", "Allan Poe", "detective");
	Book book4("Name4", "Fedor", "Dostoevsky", "drama");
	WareHouseModel book_ware_house1;
	Bueir client1;
	Seller seller1;
	Administratar admin(&book_ware_house1);
	Owner owner(&book_ware_house1, "9:00-21:00", "7/7");
	owner.AddBookcase(3, 3);

	EXPECT_TRUE(seller1.AddBook(book1));                        
	EXPECT_TRUE(seller1.AddBook(book2));
	EXPECT_TRUE(seller1.SendBook(admin));
	EXPECT_TRUE(admin.AddBook(book3));
	EXPECT_TRUE(admin.AddBook(book4));
	EXPECT_TRUE(admin.TryToMoveBox());
	EXPECT_TRUE(client1.AddBookToTheTRecwest(book1));
	EXPECT_TRUE(client1.AddBookToTheTRecwest("Name2"));
	EXPECT_TRUE(owner.MakeTheamed("novel", 0));
	EXPECT_TRUE(owner.CheckIfExist(book1));
	EXPECT_TRUE(owner.CheckIfExist(book2.name));
	client1.SendRecwest(&admin);
	EXPECT_FALSE(admin.CheckIfExist(book1));
	EXPECT_FALSE(admin.CheckIfExist(book2.name));
}
