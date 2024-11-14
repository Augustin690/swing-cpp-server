#ifndef FILM_H
#define FILM_H

#include "video.h"
#include <iostream>


class Film : public Video
{

private:

    int chapters_nbr = 0 ;
    int* chapters = nullptr;


public:

    Film();
    Film(std::string name, std::string file_name,int duration, int* chapters,int chapters_nbr): Video(name, file_name, duration){this->chapters = chapters;
                                                                                                                                   this->chapters_nbr = chapters_nbr;};

    int* getChapters() const {return chapters;};

    int getChaptersCount() const {return chapters_nbr;};

    void setChapters (int* chapters, int chapters_nbr) override{

        this->chapters_nbr = chapters_nbr;

        delete[] this-> chapters;

        if (chapters_nbr>0)

            this->chapters = new int[chapters_nbr];

        for(int i=0;i<chapters_nbr;i++){

            this->chapters[i] = chapters[i];
        }
    };

    void display(std::ostream& s) const override {

        Video::display(s);
        s<< " X ";
        s << "number of chapters " + std::to_string(getChaptersCount());
        s<< " X ";
        s<< "chapters durations" ;
        s<< " X ";
        for(int i =0; i< getChaptersCount(); i++){

            int duration_i = getChapters()[i];

            s << "chapter " + std::to_string(i+1) + " duration: " + std::to_string(duration_i);
            s<< " X ";
        }

    }

    ~Film(){delete[] chapters;};
};

#endif // FILM_H
