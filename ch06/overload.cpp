#include <iostream>
#include <string>

using namespace std;

struct Record {};
struct Phone  {};
struct Account{};
struct Name   {};

Record lookup(const Account&) { cout << "lookup(const Account&)" << endl; return Record(); }
Record lookup(const Phone  &) { cout << "lookup(const Phone  &)" << endl; return Record(); }
Record lookup(const Name   &) { cout << "lookup(const Name   &)" << endl; return Record(); }
Record lookup(      Account&) { cout << "lookup(      Account&)" << endl; return Record(); }
Record lookup(      Phone  &) { cout << "lookup(      Phone  &)" << endl; return Record(); }
Record lookup(      Name   &) { cout << "lookup(      Name   &)" << endl; return Record(); }

const string &shorterString(const string &s1, const string &s2)
{
    cout << "const string &shorterString(const string &s1, const string &s2)" << endl;
    return s1.size() <= s2.size() ? s1 : s2;
}

string &shorterString(string &s1, string &s2)
{
    cout << "string &shorterString(string &s1, string &s2)" << endl;
    auto &r = shorterString(const_cast<const string&>(s1), const_cast<const string&>(s2));

    return const_cast<string&>(r);
}

int main (int argc, char *argv[])
{
    Account acct;
    Phone phone;
    const Phone &cp = phone;

    Record r1 = lookup(acct);
    Record r2 = lookup(phone);

    lookup(phone);
    lookup(cp);

    string s1 = "hello";
    string s2 = "hello world.";

    const string cs1 = "const hello";
    const string cs2 = "const hello world.";

    string s00 = shorterString(s1, s2);
    string cs00 = shorterString(cs1, cs2);
    s00 += "fuck";

    return 0;
}
