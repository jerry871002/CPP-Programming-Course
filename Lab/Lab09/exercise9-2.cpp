#include <iostream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

class Book {
	string Name; // name of book
	int Number; // how many books in your store
public:
	Book() {
		//empty
	}
	Book(string _name, int _number) : Name(_name), Number(_number) {
		//empty
	} 
	void sellBook(int num) {
		if(Number > num) {
			Number -= num;
			cout << "Sucessfully sold." << endl;
		} else
			cout << "Not enough stock";
	}

	friend ostream& operator << (ostream&, Book);
};

ostream& operator << (ostream& out, Book someBook) {
	out << setw(25) << someBook.Name << setw(10) << someBook.Number;
	return out;
}

int main() {
	map<int, Book> BookMap;
	map<int, Book>::iterator iter;
	BookMap[1] = Book("C++ Programing", 1); 
	BookMap[2] = Book("Java", 2); 
	BookMap[3] = Book("Python", 3);

	int step;
	while(1) {
		cout <<"1. show information of book store" << endl; 
		cout <<"2. add new books" << endl;
		cout <<"3. sell books " << endl; 
		cout <<"4. exit" << endl;
		cin >> step;
	
		if(step==1) {
			cout << "ID" << setw(25) << "Name" << setw(10) << "Number" << endl;
			for(iter = BookMap.begin(); iter != BookMap.end(); iter++) {
				cout << iter->first ;
				cout << setw(10) << iter->second << endl;
			}
		} else if(step==2) {
			string bookName;
			string temp; 
			int numOfBook;
			cout << "enter Name and Number of new book" << endl;
			//cin.ignore();
			getline(cin, bookName);
			cin >> temp;
			//cin.ignore();
			cin >> numOfBook;
			//cin >> bookName >> numOfBook;
			BookMap[BookMap.size()+1] = Book(bookName, numOfBook);
		} else if(step==3) {
			int sellId, sellNum;
			cout << "enter sell id" << endl;
			cin >> sellId;
			cout << "enter sell number" << endl;
			cin >> sellNum;

			iter = BookMap.find(sellId);
			if(iter != BookMap.end())
				iter->second.sellBook(sellNum);
			else
				cout << "No such book" << endl;
		} else if(step==4) { 
			break;
		} else {
			cout << "Invalid choice" << endl;
		}	
	}

	return 0; 
}