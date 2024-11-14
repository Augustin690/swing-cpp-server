#ifndef STORAGE_H
#define STORAGE_H

#include <iostream>
#include "multimedia.h"
#include "group.h"
#include "photo.h"
#include "film.h"
#include <map>
#include <string>


using MultimediaPtr = std::shared_ptr<Multimedia>;
typedef std::shared_ptr<Multimedia> MultimediaPtr;


using GroupPtr = std::shared_ptr<Group>;
typedef std::shared_ptr<Group> GroupPtr;

using PhotoPtr = std::shared_ptr<Photo>;
typedef std::shared_ptr<Photo> PhotoPtr;


class Storage
{

private:

    std::map<std::string,MultimediaPtr> objects {};
    std::map<std::string,GroupPtr> groups {};


public:

    Storage(){};

    std::map<std::string,MultimediaPtr> getObj() const{return objects;};

    std::map<std::string,GroupPtr> getGroups() const{return groups;};


    void createPhoto(std::string name, std::string file_name,int latitude, int longitude) {

        MultimediaPtr photo (new Photo(name,file_name, latitude, longitude));
        objects[photo->getName()] = photo;
    };

    void createVideo(std::string name, std::string file_name,int duration) {

        MultimediaPtr video (new Video(name,file_name, duration));
        objects[video->getName()] = video;
    };


    void createFilm(std::string name, std::string file_name,int duration, int* chapters,int chapters_nbr) {

        MultimediaPtr film (new Film(name,file_name, duration, chapters,chapters_nbr));
        objects[film->getName()] = film;

    };

    void createGroup(std::string name) {

        GroupPtr group (new Group(name));
        groups[group->getName()] = group;
    };

    void displayObj(std::ostream& s,std::string name) const{

        std::map<std::string,MultimediaPtr>::const_iterator found = objects.find(name);

        if(found != objects.end()){

            MultimediaPtr mult = found->second;

            mult->display(s);

        }

        else {

           s << "file not found ";

        }


    }

    void displayGrp(std::ostream& s,std::string name) const{

        std::map<std::string,GroupPtr>::const_iterator found = groups.find(name);

        if(found != groups.end()){

            GroupPtr grp = found->second;

            grp->display(s);
        }

        else{

            s << "group not found ";
        }



    }

    void play(std::ostream& s,std::string name) const {

        std::map<std::string,MultimediaPtr>::const_iterator found = objects.find(name);

        if(found!= objects.end()){

            MultimediaPtr mult = objects.find(name)->second;

            mult->play();
        }

        else {

            s << "file to play not found";

        }

              }

};

#endif // STORAGE_H
