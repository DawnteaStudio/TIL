#include <vector>
std::vector<int> a;
std::vector<int> b;

void initialize(std::vector<int> A, std::vector<int> B) {
    a=A;
    b=B;
}

int answer_question(int i, int j) {
  return a[i]+b[j];
}