#ifndef DEBUGDELETE_H
#define DEBUGDELETE_H

class DebugDelete
{
public:
    DebugDelete();
    template <typename T>
    void operator()(T *p) { delete p; }
};

#endif // !DEBUGDELETE_H
