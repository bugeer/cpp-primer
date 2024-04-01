#ifndef __MESSAGE__
#define __MESSAGE__

#include <set>
#include <string>

class Folder;

class Message {
    friend class Folder;
    friend void swap(Message&, Message&);
    friend void swap(Folder&, Folder&);
public:
    explicit Message(const std::string &str = ""): contents(str) { }
    Message(const Message &);
    Message& operator=(const Message &);
    ~Message();

    void save(Folder&);
    void remove(Folder&);

    void print() const;

private:
    std::string contents;
    std::set<Folder*> folders;

    void add_to_folders(const Message&);
    void remove_from_folders();

    void addFolder(Folder*);
    void removeFolder(Folder*);
};

#endif // !__MESSAGE__
