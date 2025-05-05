#include "text.h"

	Text::Text(string _t) : text(_t) {}
    string Text::get(){
        return text;
    }; //get()함수 virtual 로 구현
	void Text::append(string _extra) { text += _extra; }