#include "Message.h"
#include "Folder.h"
#include <initializer_list>
#include <iostream>
#include <string>

void print_msg(const std::string &s) {
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "************* " << s << " *************";
    std::cout << std::endl;
    std::cout << std::endl;
}

void print(std::initializer_list<Folder*> folders, std::initializer_list<Message*> messages) {
    for(auto f : folders) {
        f->print();
    }

    for(auto m : messages) {
        m->print();
    }
}

int main (int argc, char *argv[]) {
    Folder inbox = std::string("Inbox");
    Folder sendbox(std::string("Sendbox"));

    Message m1("m1"), m2("m2"), m3("m3"), m4("m4"), m5("m5");

    m1.save(inbox  ); m2.save(inbox  ); m5.save(inbox  );
    m3.save(sendbox); m4.save(sendbox); m5.save(sendbox);

    print_msg("Init: ");
    print({&inbox, &sendbox}, {&m1, &m2, &m3, &m4, &m5});

    {
        print_msg("Copy m5: ");
        Message m6(m5);
        print({&inbox, &sendbox}, {&m5, &m6});
    }

    print_msg("Before swap m1 and m3: ");
    print({&inbox, &sendbox}, {&m1, &m3});

    print_msg("After swap m1 and m3: ");
    swap(m1, m3);
    print({&inbox, &sendbox}, {&m1, &m3});

    print_msg("After swap back: ");
    swap(m1, m3);
    print({&inbox, &sendbox}, {&m1, &m3});

    print_msg("Swap m1 and m1:");
    swap(m1, m1);
    print({&inbox, &sendbox}, {&m1});

    print_msg("Remove all messages from folders:");
    m1.remove(inbox  ); m2.remove(inbox  ); m5.remove(inbox  );
    m3.remove(sendbox); m4.remove(sendbox); m5.remove(sendbox);
    print({&inbox, &sendbox}, {&m1, &m2, &m3, &m4, &m5});

    print_msg("Folder save Message:");
    inbox  .save(m1); inbox  .save(m2); inbox  .save(m5);
    sendbox.save(m1); sendbox.save(m2); sendbox.save(m5);
    print({&inbox, &sendbox}, {&m1, &m2, &m3, &m4, &m5});

    {
        print_msg("Create temp Folder by copy: ");
        Folder draftbox(inbox);
        print({&inbox, &sendbox, &draftbox}, {&m1, &m2, &m3, &m4, &m5});

        print_msg("Copy-assignment operator");
        draftbox = sendbox;
        print({&inbox, &sendbox, &draftbox}, {&m1, &m2, &m3, &m4, &m5});
    }

    print_msg("Auto release temp Folder: ");
    print({&inbox, &sendbox}, {&m1, &m2, &m3, &m4, &m5});

    print_msg("Swap inbox and sendbox: ");
    swap(inbox, sendbox);
    print({&inbox, &sendbox}, {&m1, &m2, &m3, &m4, &m5});
    print_msg("Swap back: ");
    swap(inbox, sendbox);
    print({&inbox, &sendbox}, {&m1, &m2, &m3, &m4, &m5});

    print_msg("Folders remove messages:");
    inbox  .remove(m1); inbox  .remove(m2), inbox  .remove(m5);
    sendbox.remove(m3); sendbox.remove(m4), sendbox.remove(m5);
    print({&inbox, &sendbox}, {&m1, &m2, &m3, &m4, &m5});

    return 0;
}
