#include "WIN_OPENAL.h"


// Fonction pour v�rifier l'existence d'un fichier
bool WIN_OPENAL::FileExists(const std::string& path) {
    return std::filesystem::exists(path);
}


WIN_OPENAL::WIN_OPENAL()
{
    // Chemin vers le fichier OpenAL32.dll
    std::string openALPath = "C:\\Windows\\System32\\OpenAL32.dll";
    std::cout << "" << std::endl;

    // V�rifier si le fichier existe
    if (FileExists(openALPath)) {
        std::cout << "OpenAL : installed." << std::endl;
    } else {
        std::cout << "OpenAL : not installed." << std::endl;
    }
}

WIN_OPENAL::~WIN_OPENAL()
{
    //dtor
}

