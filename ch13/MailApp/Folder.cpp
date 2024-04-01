#include "Folder.h"
#include <iostream>

Folder::Folder(const Folder& f): folder_name(f.folder_name), all_messages(f.all_messages) {
    for(auto &m : all_messages) {
        m->folders.insert(this);
    }
}

Folder& Folder::operator=(const Folder &f) {
    for(auto &m : all_messages) {
        m->folders.erase(this);
    }
    all_messages = f.all_messages;
    for(auto &m : all_messages) {
        m->folders.insert(this);
    }

    return *this;
}

Folder::~Folder() {
    for(auto &m : all_messages) {
        m->folders.erase(this);
    }
}

void Folder::save(Message& msg) {
    msg.folders.insert(this);
    all_messages.insert(&msg);
}

void Folder::remove(Message& msg) {
    all_messages.erase(&msg);
    msg.folders.erase(this);
}

void Folder::addMsg(Message* msg) {
    all_messages.insert(msg);
}

void Folder::removeMsg(Message* msg) {
    all_messages.erase(msg);
}

void Folder::print() const {
    std::cout << "Folder <" << folder_name << "> contains" << all_messages.size() << " messages: " << std::endl;
    for(const auto &m : all_messages) {
        std::cout << "\t<" << m << ">:<" << m->contents << ">" << std::endl;
    }
}

void swap(Folder& lhs, Folder& rhs) {
    using std::swap;

    for(auto &m : lhs.all_messages) { m->removeFolder(&lhs); }
    for(auto &m : rhs.all_messages) { m->removeFolder(&rhs); }

    swap(lhs.folder_name,  rhs.folder_name );
    swap(lhs.all_messages, rhs.all_messages);

    for(auto &m : lhs.all_messages) { m->addFolder(&lhs); }
    for(auto &m : rhs.all_messages) { m->addFolder(&rhs); }
}
