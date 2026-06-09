#ifndef TEXT_H_
#define TEXT_H_

#include <iostream>
#include <string>
using namespace std;
class Text {
private:
	string text;
public:
	Text(string _t);
	virtual string get();
	virtual void append(string _extra);
};


#endif