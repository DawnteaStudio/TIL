#pragma

#include <string>
#include "text.h"
using namespace std;

class FixedText : public Text {
public:

    FixedText();
    void append(string _extra) override;
};

