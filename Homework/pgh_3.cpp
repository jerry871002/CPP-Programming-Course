#include <iostream>
#include <queue>
using namespace std;

class Message {
private:
    string name;
    int parameter;
    int priority_number;
public:
    Message() {;}
    Message(string n, int p, int pri_num): name(n), parameter(p), priority_number(pri_num) {;}
    bool operator<(const Message &m) const;
    friend ostream& operator<<(ostream& out, const Message &m);
};

bool Message::operator<(const Message &m) const {
    return priority_number > m.priority_number;
}

ostream& operator<<(ostream& out, const Message &m){
    out << m.name << " " << m.parameter;
    return out;
}

int main() {
    priority_queue<Message> msg_queue;
    // ......
    string command, name;
    int parameter, priority_number;
    
    while (cin >> command) {
        if(command == "GET") {
            if(msg_queue.empty())
                cout << "EMPTY QUEUE!" << endl;
            else {
                cout << msg_queue.top() << endl;
                msg_queue.pop();
            }
        } else if (command == "PUT") {
            cin >> name >> parameter >> priority_number;
            Message m(name, parameter, priority_number);
            msg_queue.push(m);
        }
    }
    return 0;
}
