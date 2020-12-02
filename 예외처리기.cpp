//2015041068 정민규
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <regex>
#include <string.h>

using namespace std;
ifstream file;
int line_cnt = 0;
string in; //파일에서처음읽어온문자열
har *tmp; //스트링을har형으로바꾼문자열
tring mcode; //연산자저장
tring number_a = "empty" //string 피연산자
string number_b = "empty" //string 피연산자
int error_cnt = 0;
regex num("[^0-9]"); //if(not 0~9일때를정의한um

class e {
public:
void isNum() { //숫자판별
ry {
if (regex_match(number_a, num))
throw number_a;
else if (regex_match(number_b, num))
throw number_b;
}
catch (string exception) {
error_cnt++;
cout << "Line " << line_cnt << " : " << "잘못된피연산자가있습니다" << endl;
}
}

void isZero(int op2) { //피연산자가일때나눗셈은정의되지않았다
try {
if (op2 == 0)
throw op2
}
catch (int op2) {
error_cnt++;
cout << "Line " << line_cnt << " : " << "나눗셈연산의두번째피연산자가 입니다" << endl;
}
}

void isMinus(int op1, int op2) { //피연산자가음수인지확인하는함수
ry {
if (op1 < 0)
throw op1
if (op2 < 0)
throw op2
}
catch (int op1) {
error_cnt++;
cout << "Line " << line_cnt << " : " << "데이터에음수가있습니다" << endl;
}
}
};

void f(const char* filename) { //파일예외처리에관한함수
fstream file;
file.exceptions(ifstream::eofbit | ifstream::failbit | ifstream::badbit);

try {
file.open(filename);
if (file.is_open())
cout << "file is open." << endl;
}
catch (const ifstream::failure& e) {
cerr << "파일을열수없습니다" << endl;
exit(1);
}
catch (const exception& e) {
cerr << "exception: " << e.what() << endl;
exit(1);
}
catch (...) {
cerr << "any exception!" << endl;
exit(1);
}
}

void main()
{
f("input.txt"); //파일예외처리함수
ile.open("input.txt"); //파일열기
 except;

int op1, op2; //int형으로바꾼피연산자,2
int result; //연산결과
ry {
while (!file.eof()) {
error_cnt = 0;
getline(file, in);
line_cnt++; //파일의줄을읽은다음후줄을카운트+
tmp = new char[in.length() + 1];
strcpy(tmp, in.c_str());
number_a = "empty" //피연산자를입력받지못하면mpty
number_b = "empty"
try {
if (in.empty()) //빈줄이있을때

hrow tmp;
}
else {
try {
mcode = strtok(tmp, " "); //공백을기준으로쪼개서저장
umber_a = strtok(NULL, " ");
if (tmp[mcode.length() + 1 + number_a.length() + 1] == NULL) //피연산자가개일때
hrow number_b;
number_b = strtok(NULL, " ");
except.isNum(); //피연산자가숫자인지아닌지
ry {
op1 = atoi(number_a.c_str()); //string의umber_a을har형으로바꾼뒤nt형으로
p2 = atoi(number_b.c_str());

//명령어가사칙연산인지아닌지
f (mcode == "ADD") { //ADD 덧셈연산
xcept.isMinus(op1, op2);
if (error_cnt > 0)
continue
result = op1 + op2;
cout << mcode << " " << number_a << " " << number_b << " : " << result << endl;
continue
}
else if (mcode == "SUB") { //SUB 뺄셈연산
xcept.isMinus(op1, op2);
if (error_cnt > 0)
continue
result = op1 - op2;
cout << mcode << " " << number_a << " " << number_b << " : " << result << endl;
continue
}
else if (mcode == "MUL") { //MUL 곱셈연산
xcept.isMinus(op1, op2);
if (error_cnt > 0)
continue
result = op1 * op2;
cout << mcode << " " << number_a << " " << number_b << " : " << result << endl;
continue
}
else if (mcode == "DIV") { //DIV 나눗셈연산
xcept.isMinus(op1, op2);
if (op2 == 0)
except.isZero(op2); //두번째피연산자가인지구분하는함수
f (error_cnt > 0)
continue
else if (error_cnt == 0) {
result = op1 / op2;
cout << mcode << " " << number_a << " " << number_b << " : " << result << endl;
}
continue
}
else
except.isMinus(op1, op2);
throw mcode;
}
catch (string mcode) {
cout << "Line " << line_cnt << " : " << "알수없는명령어가있습니다" << endl;
}
}
catch (string sop2) {
cout << "Line " << line_cnt << " : " << "피연산자의수가잘못되었습니다" << endl;
}
}
}
catch (char* tmp) {
cout << "Line " << line_cnt << " : 명령에빈줄이있습니다" << endl;
}
delete[]tmp;
}
}
catch (const ios_base::failure& e) {
}
file.close();
}
