#define VERSION_2

#include "multimedia.h"
#include <iostream>

Multimedia::Multimedia(){

        this->name = "";
        this->file_name = "";
    }


Multimedia::Multimedia(std::string name, std::string file_name){

    this->name = name;
    this->file_name = file_name;
    }

std::string Multimedia::getName() const{

    return name;
}
std::string Multimedia::getFileName() const{

    return file_name;
}

void Multimedia::setName(std::string n){

    name = n;

}
void Multimedia::setFileName(std::string f){

    file_name = f;
}

void Multimedia:: play() const{}

#ifdef VERSION_1
void Multimedia::display(std::ostream& s)const{

    s << "name " + getName() << std::endl
    << "file name " + getFileName() << std::endl ;
}
#endif


#ifdef VERSION_2
void Multimedia::display(std::ostream& s)const{

    s << "name " + getName() + " X "
    << "file name " + getFileName() + " X " ;
}
#endif
