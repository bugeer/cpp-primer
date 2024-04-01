#ifndef __FOLDER__
#define __FOLDER__

#include "Message.h"
#include <set>
#include <string>

class Folder {
    friend class Message;
    friend void swap(Message&, Message&);
    friend void swap(Folder&,  Folder& );

public:
    Folder(const std::string& name): folder_name(name) {}
    Folder(const Folder&);
    Folder& operator=(const Folder &);
    ~Folder();

    void save(Message&);
    void remove(Message&);

    void print() const;

private:
    std::string folder_name;
    std::set<Message*> all_messages;

    void addMsg(Message *);
    void removeMsg(Message *);
};

#endif // !__FOLDER__
