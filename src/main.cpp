#include "../include/Projet.hpp"
using namespace travel;
#include <filesystem>
namespace fs = std::filesystem;

int main()
{

    fs::path exePath = fs::current_path();
    fs::path dataPath = exePath / "data";
    
    std::string stationsFile = (dataPath / "s.csv").string();
    std::string connectionsFile = (dataPath / "c.csv").string();

    // Le reste de votre code...
    Projet generic;
    generic.read_stations(stationsFile);
    generic.read_connections(connectionsFile);
    // Demander � l'utlisateur de saisir les deux station de d�part et d'arriver
    std::string _start(""), _end("");
    do{
        std::cout << "Saisisez le nom de la station de depart : "; std::cin >> _start;
        if(_start=="")
            std::cout << "Vous n'avez rien saisie!" << std::endl;
    }while(_start=="");

    do{
        std::cout << "Saisisez le nom de la station d'arriver : "; std::cin >> _end;
        if(_end=="")
            std::cout << "Vous n'avez rien saisie!" << std::endl;
    }while(_end=="");

    // Trouver le plus court chemin
    try{
    generic.compute_and_display_travel(_start, _end); //2062 //1638
    }catch(std::string const& s){
        std::cout << s << std::endl;
    }

    return EXIT_SUCCESS;
}

