#ifndef FUNCTIONTEMPLATE_H
#define FUNCTIONTEMPLATE_H

template<typename Function, typename ArgType>
class FunctionTemplate
{
    Function function;
    ArgType argument;
public:
    FunctionTemplate(Function func, ArgType arg):function(func), argument(arg){}
    void run(){function(argument);}
};

#endif // FUNCTIONTEMPLATE_H
