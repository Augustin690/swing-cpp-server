#ifndef PHOTO_H
#define PHOTO_H



#include "multimedia.h"
#include <iostream>

class Photo : public Multimedia{


private:

    int latitude{},longitude{};


public:

    Photo(){};

    Photo(std::string name, std::string file_name,int latitude, int longitude): Multimedia(name,file_name){this->latitude = latitude,this->longitude = longitude;};

    ~Photo(){std::cout << "photo deleted " + getName() << std::endl;};

    int getLat()const{return latitude;} ;
    int getLong()const{return longitude;};

    void setLat(int latitude){this->latitude = latitude;};
    void setLong(int longitude){this->longitude = longitude;};

    void play() const {std::string path = getFileName(); std::string string = "imagej "+path+" &";
                system(string.data());};

    void display(std::ostream& s) const {

        s << " type: PHOTO ";

        s<< " X ";

        Multimedia::display(s);

        s << " latitude = " + std::to_string(getLat()) + " X "
        << " longitude = " + std::to_string(getLong())+ " " ;

    }

};

#endif // PHOTO_H
