#include "Seller.h"


bool Seller::AddBook(Book book)
{
   
    return   box.AddBookToBox(book);
}

bool Seller::SendBook(Administratar& Admin)
{
    bool flag = Admin.GetBox(&box);
    while (!(box.TekeBookFromBox(0)==emptyBook))
    {

    }
    return flag;
}
