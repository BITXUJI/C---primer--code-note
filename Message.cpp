#include "Message.h"
#include <set>
#include <string>
#include <iostream>
void Message::add_to_folders(const Message &msg)
{

    for (auto &item : msg.folders)
        item->addMsg(this);
}
void Message::remove_from_folders()
{
    for (auto &item : folders)
        item->rmvMsg(this);
}
void Message::save(Folder &fd)
{
    fd.addMsg(this);
    folders.insert(&fd);
}

void Message::remove(Folder &fd)
{
    fd.rmvMsg(this);
    folders.erase(&fd);
}

Message::Message(const Message &msg) : contents(msg.contents), folders(msg.folders)
{
    add_to_folders(*this);
}
Message &Message::operator=(const Message &msg)
{
    remove_from_folders();
    contents = msg.contents;
    folders = msg.folders;
    add_to_folders(msg);
    return *this;
}
Message::~Message()
{
    remove_from_folders();
}
void Message::print_debug()
{
    std::cout << contents << std::endl;
}
bool operator<(const Message &lhs, const Message &rhs)
{
    return lhs.contents < rhs.contents;
}

void swap(Message &lhs, Message &rhs)
{
    using std::swap;
    for (auto f : lhs.folders)
        f->rmvMsg(&lhs);
    for (auto f : rhs.folders)
        f->rmvMsg(&rhs);
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    for (auto f : lhs.folders)
        f->addMsg(&lhs);
    for (auto f : rhs.folders)
        f->addMsg(&rhs);
}
void Folder::add_to_Message(const Folder &f)
{
    for (auto m : f.messages)
        m->addFldr(this);
}
Folder::Folder(const Folder &f) : messages(f.messages)
{
    add_to_Message(f);
}
void Folder::remove_to_Message()
{
    for (auto m : messages)
        m->rmvFldr(this);
    // m->remove(*this);
}
Folder::~Folder()
{
    remove_to_Message();
}
Folder &Folder::operator=(const Folder &rhs)
{
    remove_to_Message();
    messages = rhs.messages;
    add_to_Message(rhs);
    return *this;
}
void Folder::print_debug()
{
    for (auto m : messages)
        std::cout << m->contents << " ";
    std::cout << std::endl;
}
void swap(Folder &lhs, Folder &rhs)
{
    using std::swap;
    for (auto m : lhs.messages)
        m->rmvFldr(&lhs);
    for (auto m : rhs.messages)
        m->rmvFldr(&rhs);
    swap(lhs.messages, rhs.messages);
    for (auto m : lhs.messages)
        m->addFldr(&lhs);
    for (auto m : rhs.messages)
        m->addFldr(&rhs);
}