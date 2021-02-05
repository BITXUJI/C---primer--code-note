#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>
#include <set>
class Folder;
class Message
{
    friend class Folder;
    friend void swap(Message &, Message &);
    friend void swap(Folder &, Folder &);
    friend bool operator<(const Message &, const Message &);

public:
    explicit Message(const std::string &s = "") : contents(s) {}
    Message(const Message &);
    Message &operator=(const Message &);
    void save(Folder &);
    void remove(Folder &);
    ~Message();
    void print_debug();

private:
    std::string contents;
    std::set<Folder *> folders;
    void add_to_folders(const Message &);
    void remove_from_folders();
    void addFldr(Folder *f) { folders.insert(f); }
    void rmvFldr(Folder *f) { folders.erase(f); }
};
void swap(Message &, Message &);
bool operator<(const Message &, const Message &);
class Folder
{
    friend void swap(Message &, Message &);
    friend void swap(Folder &, Folder &);
    friend class Message;

public:
    Folder() = default;
    Folder(const Folder &);
    Folder &operator=(const Folder &);
    ~Folder();
    void print_debug();

private:
    std::set<Message *> messages;
    void add_to_Message(const Folder &);
    void remove_to_Message();
    void addMsg(Message *msg) { messages.insert(msg); }
    void rmvMsg(Message *msg) { messages.erase(msg); }
};
void swap(Folder &, Folder &);
#endif