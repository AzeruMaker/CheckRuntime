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
        // D�claration de la fonction pour v�rifier l'existence d'un fichier
        bool FileExists(const std::string& path);

        // D�claration de la fonction pour v�rifier les versions de DirectX install�es
        void CheckDirectXVersions(std::set<std::string>& directXVersions);



#endif // WIN_DX_H
