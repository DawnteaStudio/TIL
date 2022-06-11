using namespace std;

class BookList{
    int count;
    int size;
    Book books [10];
    void slideUp (int location);
    void slideDown (int location);

    public :
    BookList (){
        size = 0;
        count = 0;
    }

    void addBookAt (Book b, int location);

    void addBook (Book b){
        books[size] = b;
        size++;
    }

    Book findBook (int location) const;

    Book removeBook (int location);

    void displayBooks (std::ostream &out) const;

};
