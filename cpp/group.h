#ifndef GROUP_H
#define GROUP_H

#define VERSION_2

#include "iostream"
#include "video.h"
#include "multimedia.h"
#include <memory>
#include <list>

using MultimediaPtr = std::shared_ptr<Multimedia>;
typedef std::shared_ptr<Multimedia> MultimediaPtr;

class Group : public std::list<MultimediaPtr>
{

private:

    std::string name {};


public:

    Group(){};

    Group(std::string name): std::list<MultimediaPtr>(){this->name = name;};

    ~Group(){std::cout << "group DELETED " + getName() << std::endl;
             for(auto it = this->begin(); it != this->end(); it++) {
     //            debug(it->use_count());
                 it->reset();
             }
            };

    std::string getName() const{

        return name;
    }

#ifdef VERSION_1

    void display(std::ostream& s) const{

        s << "Printing the elements in the group " + getName() << std::endl;

        for(auto it = this->begin(); it != this->end(); it++) {

                  (*it)->display(s);
              }
    }
#endif

 #ifdef VERSION_2

    void display(std::ostream& s) const{

        s << "Printing the elements in the group " + getName() + " X ";

        for(auto it = this->begin(); it != this->end(); it++) {

                  (*it)->display(s);
              }
    }
 #endif




};

#endif // GROUP_H
