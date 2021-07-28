#ifndef CALLBACK_H
#define CALLBACK_H


class CallBack
{
public:
    virtual void call() = 0;
};


class StaticCallBack : public CallBack
{

public :
    StaticCallBack(void (*func)()) : m_func(func)
    {

    }  StaticCallBack(void (*func2)(int)) : m_func2(func2)
    {

    }
    virtual void call()
    {
        m_func();
    }
private :
    void (*m_func)();
    void (*m_func2)(int);

};

#endif // CALLBACK_H
