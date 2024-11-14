#ifndef VIDEO_H
#define VIDEO_H

#include "multimedia.h"
#include <iostream>


class Video :public Multimedia{


private:

    int duration{};

public:

    Video(){};
    Video(std::string name, std::string file_name,int duration):Multimedia(name,file_name){this->duration = duration;};

    virtual ~Video(){std::cout << "Video deleted " + getName() << std::endl;};

    int getDuration()const{return duration;};

    void setDuration(int duration){this->duration = duration;};

    virtual void setChapters(int* chapters, int chapters_nbr){};

    void play() const {std::string path = getFileName(); std::string string = "mpv "+path+" &";
                system(string.data());};

    void display(std::ostream& s) const {

        s << " type: VIDEO " ;

        s<< " X ";

        Multimedia::display(s);

        s<< " X ";
        s << " total duration: " + std::to_string(getDuration()) + " min" ;

    }

};


#endif // VIDEO_H
