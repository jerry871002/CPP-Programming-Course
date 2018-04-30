class Book {
string Name; // name of book
int Number; // how many books in your store
public:
Book(){;}
Book(string _name, int _number):Name(_name),Number(_number){} ...
};
int main() {
map<int, Book> BookMap;
BookMap[1] = Book("C++ Programing", 1); BookMap[2] = Book("Java", 2); BookMap[3] = Book("Python", 3);
int step;
while(1) {
cout <<"1. show information of book store" << endl; cout <<"2. add new books" << endl;
cout <<"3. sell books " << endl; cout <<"4. exit" << endl;
cin >> step;
if(step==1) {
... }
else if(step==2) {
cout <<"enter Name and Number of new book" << endl; ...
}
else if(step==3) {
cout << "enter sell id" << endl;
... }
else if(step==4) { break;
} }
return 0; }