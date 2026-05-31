#include <iostream>
#include <fstream>
#include <sstream>
// #include "BookList.h"

using namespace std;

class Book {
    std::string title;
    std::string author;
    int year;
    std::string genre;

    public:

//    Book ();

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
        out << "Title: "<< title << '\n';
        out << "Author: "<< author << '\n';
        out << "Year: "<< year << '\n';
        out << "Genre: "<< genre << '\n';
    };

};

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

    void addBookAt (Book b, int location){
        if(location > size){
            books[size] = b;
            size++;
        }
        else{
            for(int i = size ;i > location; i--){
                    books[i] = books[i-1];
            }
            books[location] = b;
            size++;
        }
    }
        
    void addBook (Book b){
        books[size] = b;
        size++;
    }

    Book findBook (int location) const{
        return books[location];
    }

    void removeBook (int location){
        for(int i = location + 1; i < size; i++){
            books[i-1] = books[i];
        }
        size--;
    }

    void displayBooks (std::ostream &out) const{
        out<<"Books in my list:"<<endl;
        Book a;
        for(int i = 0; i < size; i++){
            a = books[i];

            a.displayBook(out);
        }

    }

};



int main() {
	BookList myBooklist;
	Book tempBook;
	string command, line;
	ifstream in("book_data.txt");
	ofstream out("output.txt");
	size_t pos = 0;
	int year, location;

	while (getline(in, line)) {
		if ( (pos=line.find("Command: ")) != string::npos ) {
			command = line.substr(9);
			if ( (pos=command.find("add")) != string::npos && (pos=command.find("addBookAt")) == string::npos ) {
				getline(in, line);
				tempBook.setTitle(line);
				getline(in, line);
				tempBook.setAuthor(line);
				in >> year;
				getline(in, line);
				tempBook.setYear(year);
				// in.get(); // eats new line
				getline(in, line);
				tempBook.setGenre(line);
				myBooklist.addBook(tempBook);
			}
			else if ( (pos=command.find("addBookAt")) != string::npos ) {
				pos = command.find(" ");
				string tmp = command.substr(pos + size_t(1));
				istringstream ss(tmp);
				ss >> location;
				getline(in, line);
				tempBook.setTitle(line);
				getline(in, line);
				tempBook.setAuthor(line);
				in >> year;
                getline(in, line);
				tempBook.setYear(year);
				// in.get(); // eats new line
				getline(in, line);
				tempBook.setGenre(line);
				myBooklist.addBookAt(tempBook, location-1);
			}
			else if ((pos = command.find("removeBook")) != string::npos ) {
				pos = command.find(" ");
				string tmp = command.substr(pos + size_t(1));				
				istringstream  ss(tmp);
				ss >> location;
				myBooklist.removeBook(location-1);
			}
			else if ((pos = command.find("findBook")) != string::npos ) {
				pos = command.find(" ");
				string tmp = command.substr(pos + size_t(1));				
				istringstream  ss(tmp);
				ss >> location;
				tempBook = myBooklist.findBook(location-1);
				tempBook.displayBook(out);
			}
			else if ((pos = command.find("displayBooks")) != string::npos) {
				myBooklist.displayBooks(out);
			}
		}		
	}
	out.close();
	in.close();
	
	return 0;
}	