#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include<string>
#include<iostream>

class Multimedia
{


private:

    std::string name{};
    std::string file_name{};


public:

    Multimedia();
    Multimedia(std::string name, std::string file_name);

    std::string getName() const;
    std::string getFileName() const;

    void setName(std::string);
    void setFileName(std::string);
    virtual void display(std::ostream&) const;
    virtual void play() const;
    virtual void setChapters(int* chapters, int chapters_nbr){};

    virtual ~Multimedia(){} ;
};

#endif // MULTIMEDIA_H
