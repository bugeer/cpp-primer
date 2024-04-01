#include "Message.h"
#include "Folder.h"
#include <initializer_list>
#include <iostream>
#include <string>

void print_line() {
    std::cout << std::endl;
    std::cout << "*************";
    std::cout << std::endl;
}

void print(std::initializer_list<Folder*> folders, std::initializer_list<Message*> messages) {
    for(auto f : folders) {
        f->print();
    }

    for(auto m : messages) {
        m->print();
    }

    print_line();
}

int main (int argc, char *argv[]) {
    Folder inbox = std::string("Inbox");
    Folder sendbox(std::string("Sendbox"));

    Message m1("m1"), m2("m2"), m3("m3"), m4("m4"), m5("m5");

    m1.save(inbox  ); m2.save(inbox  ); m5.save(inbox  );
    m3.save(sendbox); m4.save(sendbox); m5.save(sendbox);
    print({&inbox, &sendbox}, {&m1, &m2, &m3, &m4, &m5});

    {
        Message m6(m5);
        print({&inbox, &sendbox}, {&m5, &m6});
    }

    print({&inbox, &sendbox}, {&m5});

    swap(m1, m3);
    print({&inbox, &sendbox}, {&m1, &m3});
    swap(m1, m3);

    swap(m1, m1);
    print({&inbox, &sendbox}, {&m1});

    m1.remove(inbox  ); m2.remove(inbox  ); m5.remove(inbox  );
    m3.remove(sendbox); m4.remove(sendbox); m5.remove(sendbox);
    print({&inbox, &sendbox}, {&m1, &m2, &m3, &m4, &m5});

    {
        Folder draftbox(inbox);
        print({&inbox, &sendbox, &draftbox}, {&m1, &m2, &m3, &m4, &m5});

        draftbox = sendbox;
        print({&inbox, &sendbox, &draftbox}, {&m1, &m2, &m3, &m4, &m5});
    }
    print({&inbox, &sendbox}, {&m1, &m2, &m3, &m4, &m5});

    swap(inbox, sendbox);
    print({&inbox, &sendbox}, {&m1, &m2, &m3, &m4, &m5});
    swap(inbox, sendbox);

    inbox  .remove(m1); inbox  .remove(m2), inbox  .remove(m5);
    sendbox.remove(m3); sendbox.remove(m4), sendbox.remove(m5);
    print({&inbox, &sendbox}, {&m1, &m2, &m3, &m4, &m5});

    return 0;
}
