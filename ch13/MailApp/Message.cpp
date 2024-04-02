#include "Message.h"
#include "Folder.h"
#include <iostream>

Message::Message(const Message &msg)
: contents(msg.contents), folders(msg.folders) {
    add_to_folders(msg);
}

Message::Message(Message &&m): contents(std::move(m.contents)) {
    move_folders(&m);
}

Message& Message::operator=(const Message &rhs) {
    remove_from_folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_folders(rhs);

    return *this;
}

Message& Message::operator=(Message &&rhs) {
    if(this != &rhs) {
        remove_from_folders();
        contents = std::move(rhs.contents);
        move_folders(&rhs);
    }

    return *this;
}

Message::~Message() {
    remove_from_folders();
}

void Message::save(Folder &f) {
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f) {
    folders.erase(&f);
    f.removeMsg(this);
}

void Message::add_to_folders(const Message& msg) {
    for(auto f : msg.folders) {
        f->addMsg(this);
    }
}

void Message::remove_from_folders() {
    for(auto f : folders) {
        f->removeMsg(this);
    }
}

void Message::addFolder(Folder *f) {
    folders.insert(f);
}

void Message::removeFolder(Folder *f) {
    folders.erase(f);
}

void Message::print() const {
    std::cout << "Msg: <" << this << ">:<" << contents << "> in "
              << folders.size() << " folders: " << std::endl;
    for(const auto &f : folders) {
        std::cout << "\t<" << f->folder_name << ">" << std::endl;
    }
}

// move msg's folders to this
void Message::move_folders(Message *m) {
    folders = std::move(m->folders);
    for(auto f : folders) {
        f->removeMsg(m);
        f->addMsg(this);
    }

    m->folders.clear();
}

void swap(Message& lhs, Message& rhs) {
    using std::swap;

    for(auto f : lhs.folders) {
        f->removeMsg(&lhs);
    }
    for(auto f : rhs.folders) {
        f->removeMsg(&rhs);
    }

    swap(lhs.contents, rhs.contents);
    swap(lhs.folders,  rhs.folders );

    for(auto f : lhs.folders) {
        f->addMsg(&lhs);
    }
    for(auto f : rhs.folders) {
        f->addMsg(&rhs);
    }
}
