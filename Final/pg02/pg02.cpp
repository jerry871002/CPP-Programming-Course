#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Student
{
    private:
    	string id;
    	char cls; //class
    	double score;
    public:
    	//…
        Student(string i, char c) : id(i), cls(c) { ; }
    	virtual void average_score() = 0;

        void setScore(double s) { score = s; }
        void setId(string i) { id = i; }
        void setClass(char c) { cls = c; }

        double getScore() const { return score; }
        string getId() const { return id; }
        char getClass() const { return cls; }
};

class Graduated: public Student
{
    private:
    	double Research;
    	double Math;
    	double English;
    public:
    	//…
        Graduated(string i, char c) : Student(i, c) { ; }
        void average_score() {
            double avg = (0.5 * Research) + (0.25 * Math) + (0.25 * English);
            setScore(avg);
        }
        void setAScore(string subject, double aScore) {
            if(subject == "Research")
                Research = aScore;
            else if(subject == "Math")
                Math = aScore;
            else if (subject == "English")
                English = aScore;
            else
                cout << "invalid subject!!!" << endl;
        }
        bool operator<(Graduated& a) const {
            return (this->getScore()) < (a.getScore());
        }
};

class Undergraduate: public Student
{
    private:
    	double Math;
    	double English;
    public:
        //…
        Undergraduate(string i, char c) : Student(i, c) { ; }
        void average_score() {
            double avg = (0.5 * Math) + (0.5 * English);
            setScore(avg);
        }
        void setAScore(string subject, double aScore) {
            if(subject == "Math")
                Math = aScore;
            else if (subject == "English")
                English = aScore;
            else
                cout << "invalid subject!!!" << endl;
        }
        bool operator<(Undergraduate& a) const {
            return (this->getScore()) < (a.getScore());
        }
};

int main(int argc,char* argv[])
{
    vector<Graduated> vGraduated;
    vector<Undergraduate> vUndergraduate;
    //read file
    ifstream inFile(argv[1]);
    while(!inFile.eof()) {
        string stdType, stdId, subject;
        char stdClass;
        double grade;

        inFile >> stdType >> stdId >> stdClass;
        if(stdType == "Graduated") {
            Graduated gStd(stdId, stdClass);
            for(int i = 0; i < 3; i++) {
                inFile >> subject >> grade;
                gStd.setAScore(subject, grade);
            }
            vGraduated.push_back(gStd);
        } else if (stdType == "Undergraduate") {
            Undergraduate ugStd(stdId, stdClass);
            for(int i = 0; i < 2; i++) {
                inFile >> subject >> grade;
                ugStd.setAScore(subject, grade);
            }
            vUndergraduate.push_back(ugStd);
        }
    }
	//show the original class of graduated students
	cout << "class A in graduated school : ";
    for(vector<Graduated>::iterator it = vGraduated.begin(); it != vGraduated.end(); it++) {
        if(it->getClass() == 'A')
            cout << it->getId() << " ";
    }
    cout << endl;

	cout << "class B in graduated school : ";
    for(vector<Graduated>::iterator it = vGraduated.begin(); it != vGraduated.end(); it++) {
        if(it->getClass() == 'B')
            cout << it->getId() << " ";
    }
    cout << endl;

    //show the original class of undergraduate students
	cout << "class A in undergraduate : ";
    for(vector<Undergraduate>::iterator it = vUndergraduate.begin(); it != vUndergraduate.end(); it++) {
        if(it->getClass() == 'A')
            cout << it->getId() << " ";
    }
    cout << endl;
    //…
	cout << "class B in undergraduate : ";
    for(vector<Undergraduate>::iterator it = vUndergraduate.begin(); it != vUndergraduate.end(); it++) {
        if(it->getClass() == 'B')
            cout << it->getId() << " ";
    }
    cout << endl;
    //…
    // compute the average score of each student and then reassign their class.
    //vector<Graduated> vgswap;
    vector<string> vgswapAtoB;
    vector<string> vgswapBtoA;
    for(vector<Graduated>::iterator it = vGraduated.begin(); it != vGraduated.end(); it++) {
        it->average_score();
        if(it->getScore() >= 70 && it->getClass() == 'B') {
            it->setClass('A');
            vgswapBtoA.push_back(it->getId());
        } else if (it->getScore() < 70 && it->getClass() == 'A') {
            it->setClass('B');
            vgswapAtoB.push_back(it->getId());
        }
    }

    //vector<Undergraduate> vugswap;
    vector<string> vugswapAtoB;
    vector<string> vugswapBtoA;
    for(vector<Undergraduate>::iterator it = vUndergraduate.begin(); it != vUndergraduate.end(); it++) {
        it->average_score();
        if(it->getScore() >= 60 && it->getClass() == 'B') {
            it->setClass('A');
            vugswapBtoA.push_back(it->getId());
        } else if (it->getScore() < 60 && it->getClass() == 'A') {
            it->setClass('B');
            vugswapAtoB.push_back(it->getId());
        }
    }
    //…
    // show the class and average score of graduated students after reassignment with descending order of average score.
    //sort(vGraduated.begin(), vGraduated.end());
    map<double, string> mga;
    map<double, string> mgb;
    map<double, string> muga;
    map<double, string> mugb;

    for(vector<Graduated>::iterator it = vGraduated.begin(); it != vGraduated.end(); it++) {
        if(it->getClass() == 'A')
            mga[it->getScore()] = it->getId();
        else if(it->getClass() == 'A')
            mgb[it->getScore()] = it->getId();
    }

    for(vector<Undergraduate>::iterator it = vUndergraduate.begin(); it != vUndergraduate.end(); it++) {
        if(it->getClass() == 'A')
            muga[it->getScore()] = it->getId();
        else if(it->getClass() == 'A')
            mugb[it->getScore()] = it->getId();
    }

    cout << "class A in graduated school : " << endl;
    for(map<double, string>::iterator it = mga.begin(); it != mga.end(); it++)
        cout << "student " << it->second << " score " << it->first << endl;

    cout << "class B in graduated school : " << endl;
    for(map<double, string>::iterator it = mgb.begin(); it != mgb.end(); it++)
        cout << "student " << it->second << " score " << it->first << endl;

    cout << "class A in undergraduate : " << endl;
    for(map<double, string>::iterator it = muga.begin(); it != muga.end(); it++)
        cout << "student " << it->second << " score " << it->first << endl;

    cout << "class B in undergraduate : " << endl;
    for(map<double, string>::iterator it = mugb.begin(); it != mugb.end(); it++)
        cout << "student " << it->second << " score " << it->first << endl;

    /*cout << "class A in graduated school : " << endl;
    for(vector<Graduated>::iterator it = vGraduated.begin(); it != vGraduated.end(); it++) {
        if(it->getClass() == 'A')
            cout << "student " << it->getId() << " score " << it->getScore() << endl;
    }
    cout << endl;

	cout << "class B in graduated school : " << endl;
    for(vector<Graduated>::iterator it = vGraduated.begin(); it != vGraduated.end(); it++) {
        if(it->getClass() == 'B')
            cout << "student " << it->getId() << " score " << it->getScore() << endl;
    }
    cout << endl;
    //…
    // show the class and average score of undergraduate students after reassignment with descending order of average score.
    //sort(vUndergraduate.begin(), vUndergraduate.end());
    cout << "class A in undergraduate : " << endl;
    for(vector<Undergraduate>::iterator it = vUndergraduate.begin(); it != vUndergraduate.end(); it++) {
        if(it->getClass() == 'A')
            cout << "student " << it->getId() << " score " << it->getScore() << endl;
    }
    cout << endl;
    //…
	cout << "class B in undergraduate : " << endl;
    for(vector<Undergraduate>::iterator it = vUndergraduate.begin(); it != vUndergraduate.end(); it++) {
        if(it->getClass() == 'B')
            cout << "student " << it->getId() << " score " << it->getScore() << endl;
    }
    cout << endl;*/
    //…
    //Finally, show the reassignment record with increasing order of student ID
	cout << "---------------------------------" << endl;
    //	… … …
    sort(vgswapBtoA.begin(), vgswapBtoA.end());
    sort(vgswapAtoB.begin(), vgswapAtoB.end());
    sort(vugswapBtoA.begin(), vugswapBtoA.end());
    sort(vugswapAtoB.begin(), vugswapAtoB.end());

    for(vector<string>::iterator it = vgswapBtoA.begin(); it != vgswapBtoA.end(); it++)
        cout << "Student " << *it << " move from class graduated B to A" << endl;

    for(vector<string>::iterator it = vgswapAtoB.begin(); it != vgswapAtoB.end(); it++)
        cout << "Student " << *it << " move from class graduated A to B" << endl;

    for(vector<string>::iterator it = vugswapBtoA.begin(); it != vugswapBtoA.end(); it++)
        cout << "Student " << *it << " move from class undergraduate B to A" << endl;

    for(vector<string>::iterator it = vugswapAtoB.begin(); it != vugswapAtoB.end(); it++)
        cout << "Student " << *it << " move from class undergraduate A to B" << endl;


    return 0;
}
