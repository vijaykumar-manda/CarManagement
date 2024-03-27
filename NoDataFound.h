#ifndef NODATAFOUND_H
#define NODATAFOUND_H


#include<cstring>
#include<exception>

class NoDataFound : public std::exception
{
private:
    char * _msg;
public:
    NoDataFound() = delete;
    NoDataFound(const NoDataFound&) = delete;
    NoDataFound& operator=(const NoDataFound&) = delete;
    NoDataFound(NoDataFound&&) = delete;
    NoDataFound& operator=(NoDataFound&&) = delete;

    NoDataFound(const char * message){
        _msg = new char[strlen(message) + 1];
        strcpy(_msg, message);
    }
    ~NoDataFound(){
        delete[] _msg;
    }
    char * what(){
        return _msg;
    }
};

#endif // NODATAFOUND_H
