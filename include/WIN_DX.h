#include <string>
#include <set>
#include <filesystem>
#include <vector>


#ifndef WIN_DX_H
#define WIN_DX_H


class WIN_DX
{
    public:
        WIN_DX();
        virtual ~WIN_DX();

    protected:

    private:
        // Déclaration de la fonction pour vérifier l'existence d'un fichier
        bool FileExists(const std::string& path);

        // Déclaration de la fonction pour vérifier les versions de DirectX installées
        void CheckDirectXVersions(std::set<std::string>& directXVersions);



#endif // WIN_DX_H
