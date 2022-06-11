
using namespace std;

class Book {
    std::string title;
    std::string author;
    int year;
    std::string genre;

    public:

    Book ();

    void setTitle (std::string newTitle){
        title = newTitle;
        }
    void setAuthor (std::string newAuthor){
        author = newAuthor;
    }

    void setYear (int newYear){
        year = newYear;
    }

    void setGenre (std::string newGenre){
        genre = newGenre;
    }

    std::string getTitle () const{
        return title;
    }

    std::string getAuthor () const{
        return author;
    
    }

    int getYear () const{
        return year;
    }

    std::string getGenre () const{
        return genre;
    }

    void displayBook (std::ostream &out) const{
        out << "Books in my list:" << '\n';
        out << "Title: : "<< title << '\n';
        out << "Author: "<< author << '\n';
        out << "Year : "<< year << '\n';
        out << "Genre: "<< genre << '\n';
    };

};