#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_blank(const char &c)
{
    bool is_char = false
                   || (c >= 'a' && c <= 'z') 
                   || (c >= 'A' && c <= 'Z')
                   || (c >= '0' && c <= '9')
                   || (c == '\n');

    return !is_char;
}

int main (int argc, char *argv[])
{
    string line;
    string str_longest;
    string str_current;
    string str_previous;
    int    max_count;
    int    cur_count;

    vector<string> tokens;

    max_count = 0;
    cur_count = 0;

    getline(cin, line);

    for(char c : line)
    {
        if(is_blank(c))
        {
            if(str_current.length() > 0)
            {
                tokens.push_back(str_current);

                if(str_current == str_previous)
                {
                    ++cur_count;
                    if(cur_count >= max_count)
                    {
                        max_count = cur_count;
                        str_longest = str_previous;
                    }
                }
                else
                {
                    cur_count = 1;
                }

                str_previous = str_current;
                str_current = "";
            }
            else
            {
                continue;
            }
        }
        else
        {
            str_current += c;
        }
    }

    cout << "The tokens in the line:" << endl;
    for(auto &str : tokens)
    {
        cout << str << endl;
    }
    cout << endl;

    cout << "The longest token: " << str_longest << ", [" << max_count << "] times" << endl;

    return 0;
}
