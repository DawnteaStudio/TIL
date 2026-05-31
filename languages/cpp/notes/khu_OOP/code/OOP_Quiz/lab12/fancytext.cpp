#include "fancytext.h"

	// initialization list는 생성자를 호출할 수 있게 해준다.
	FancyText::FancyText(string _t, string _lb, string _rb, string _con) :
		Text::Text(_t), left_brac(_lb), right_brac(_rb), connector(_con) {}
	string FancyText::get() {
        return left_brac + Text::get() + right_brac;
    } //override 키워드 사용한 get()함수 구현, main함수 참고하여 출력화면처럼 되도록 구현
	void FancyText::append(string _extra) {
        Text::append(connector + _extra);
    } //override 키워드  