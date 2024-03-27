#ifndef INVALIDINPUT_H
#define INVALIDINPUT_H

#include<cstring>
#include<exception>

class InValidInput : public std::exception
{
private:
    char * _msg;
public:
    InValidInput() = delete;
    InValidInput(const InValidInput&) = delete;
    InValidInput& operator=(const InValidInput&) = delete;
    InValidInput(InValidInput&&) = delete;
    InValidInput& operator=(InValidInput&&) = delete;

    InValidInput(const char * message){
        _msg = new char[strlen(message) + 1];
        strcpy(_msg, message);
    }
    ~InValidInput(){
        delete[] _msg;
    }
    char * what(){
        return _msg;
    }
};

#endif // INVALIDINPUT_H
