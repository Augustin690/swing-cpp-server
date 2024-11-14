//
// main.cpp
// Created on 21/10/2018
//
#define VERSION_2

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <memory>
#include <sstream>


#include "multimedia.h"
#include "photo.h"
#include"video.h"
#include "film.h"
#include "group.h"
#include "storage.h"
#include <list>


using namespace std;
using PhotoPtr = std::shared_ptr<Photo>;
typedef std::shared_ptr<Photo> PhotoPtr;

using VideoPtr = std::shared_ptr<Video>;
typedef std::shared_ptr<Video> VideoPtr;

#ifdef VERSION_1

int main(int argc, const char* argv[])
{
    std::cout << "Hello brave new world" << std::endl;


    PhotoPtr lyon (new Photo("TROBO", "/cal/exterieurs/acurinier-21/Curinier_Augustin/lyon-peut-compter-sur-son-offre-riche-en-immobilier-de-bureaux-photo-d-illustration-le-progres-maxime-jegat-1670711708.jpg",
                            1,1));


    /*lyon->display(std::cout);*/

    /*lyon->play();*/

    VideoPtr pingouin  (new Video("LOL","/cal/exterieurs/acurinier-21/Curinier_Augustin/superb-owl-football.gif",1));

   /* pingouin->display(std::cout);*/

    /*pingouin ->play();*/

    /*Multimedia** tab = new Multimedia*[2];

    tab[1] = lyon;
    tab[0] = pingouin;

    for(int i =0; i< 2; i++){

        Multimedia* mult = tab[i];
        mult -> play();
        mult -> display(std::cout);


    }*/

    int* tab_test = new int[5];

    for(int k =0; k<5;k++){

        tab_test[k] = k+1;
    }


    /*Film* film = new Film("test", "/cal/exterieurs/acurinier-21/Curinier_Augustin/superb-owl-football.gif", 3,5);

    film->setChapters(tab_test,5);

    film-> display(std::cout);
    film ->play();

    int* tab_test_2 = new int[4];

    for(int k =0; k<4;k++){

        tab_test_2[k] = k+22;

    }


    Film* film_2 = new Film("test numero2", "/cal/exterieurs/acurinier-21/Curinier_Augustin/superb-owl-football.gif", 10,7);

    film_2->setChapters(tab_test_2,4);

    Film* film_3(film_2);

    film_3->setChapters(tab_test, 5);

    film_2->display(cout);
    film_3->display(cout);

    /*film_2-> display(std::cout);
    film_2 ->play();

    film_2 ->setChapters(tab_test,5);
    film_2->display(std::cout);

    delete film;
    delete film_2;

    film->display(std::cout);
    film_2->display(std::cout);*/

    /*Photo* lyon_2 = new Photo("68", "/cal/exterieurs/acurinier-21/Curinier_Augustin/68.jpg",
                              2,2);

    Group* group_1 = new Group("first group");

    Group* group_2 = new Group("second group");



    group_1->push_back(lyon);
    group_1->push_back(PhotoPtr(lyon_2));
    group_1->push_back(VideoPtr(film));

    group_2->push_back(VideoPtr(film_2));
    group_2->push_back(VideoPtr(pingouin));
    group_2->push_back(lyon);

    group_1->display(std::cout);

    group_2->display(std::cout);

    delete group_1;

    '\n';
    std::cout<< "after deleteting group2" <<std::endl;

    lyon->display(std::cout);*/

    //group_2->display(std::cout);

    //delete group_2 ;

    cout<< "STORAGE TEST" << std::endl;

    Storage* storage = new Storage();
    storage->createPhoto("Photo_1","/cal/exterieurs/acurinier-21/Curinier_Augustin/68.jpg",4,2);
    storage->createGroup("Group_1");

    storage->getGroups()["Group_1"]->push_back(storage->getObj()["Photo_1"]);

    storage->displayObj(cout,"Photo_1");
    storage->displayGrp(cout,"Group_1");

    storage->createVideo("Video_1","/cal/exterieurs/acurinier-21/Curinier_Augustin/superb-owl-football.gif",4);

    storage->createFilm("Film_1","/cal/exterieurs/acurinier-21/Curinier_Augustin/superb-owl-football.gif",4,tab_test,5);

    //storage->getObj()["Film_1"]->setChapters(tab_test,5);

    storage->getGroups()["Group_1"]->push_back(storage->getObj()["Video_1"]);
    storage->getGroups()["Group_1"]->push_back(storage->getObj()["Film_1"]);

    storage->displayGrp(cout, "Group_1");


    delete storage;

    cout << "END STORAGE TEST" << std::endl;



    return 0;
}

#endif

#ifdef VERSION_2

#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "tcpserver.h"

const int PORT = 3331;

int main(int argc, const char* argv[]){


    Storage* storage = new Storage();
    storage->createPhoto("Photo_1","/cal/exterieurs/acurinier-21/Curinier_Augustin/68.jpg",4,2);
    storage->createGroup("Group_1");

    int* tab_test = new int[5];

    for(int k =0; k<5;k++){

        tab_test[k] = k+1;
    }

    storage->createFilm("Film_1","/cal/exterieurs/acurinier-21/Curinier_Augustin/superb-owl-football.gif",15,tab_test,5);


    storage->getGroups()["Group_1"]->push_back(storage->getObj()["Photo_1"]);
    storage->getGroups()["Group_1"]->push_back(storage->getObj()["Film_1"]);


    // cree le TCPServer
    auto* server =
    new TCPServer( [&](std::string const& request, std::string& response) {

            // the request sent by the client to the server
            std::cout << "request: " << request << std::endl;

            // if the client wants to display the attributes of a Multimedia object
            std::string str("Afficher l'objet");
            std::size_t pos = request.find(str);

            if(pos!=std::string::npos){

                // retrieves the name of the object
                std::string name = request.substr(pos+ str.length()+1);

                // text buffer to send to the client, that will contain the display
                stringstream s;
                storage->displayObj(s,name);

                response = s.str();
                return true;
                     }

            // to display a group
            std::string str_grp("Afficher le groupe");
            std::size_t pos_grp = request.find(str_grp);

            if(pos_grp!=std::string::npos){

                // retrieves the name of the group
                std::string name = request.substr(pos_grp+ str_grp.length()+1);

                // text buffer to send to the client, that will contain the display
                stringstream s;
                storage->displayGrp(s,name);

                response = s.str();
                return true;
                     }

            // if the client wants to delete everything

            std::string str_2("Delete");
            std::size_t pos_2 = request.find(str_2);

            if(pos_2!=std::string::npos){

                delete storage;
                response = "Storage data deleted";
                return true;
              }

            // to play a Multimedia object
            std::string play("Play");
            std::size_t pos_play = request.find(play);

            if(pos_play!=std::string::npos){

                std::string name = request.substr(pos_play+ play.length()+1);

                stringstream s_play;

                storage->play(s_play,name);

                response = "playing " + name + ";" + s_play.str();

                return true;
              }

      response = "OK " + request;

      // return false would close the connecytion with the client
      return true;
    });


    // lance la boucle infinie du serveur
    std::cout << "Starting Server on port " << PORT << std::endl;

    int status = server->run(PORT);

    // en cas d'erreur
    if (status < 0) {
      std::cerr << "Could not start Server on port " << PORT << std::endl;
      return 1;
    }

    delete storage;

    return 0;

}

#endif

