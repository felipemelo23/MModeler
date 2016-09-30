#include "filemanager.h"

/* Le um arquivo texto, carregando na memoria todos os objetos existentes
 * nele, ou apenas o objeto na posicao desejada. Este metodo apenas serve
 * para ser usado por metodos de classes filhas.
 *
 *  ->Param:
 *      >> readPos (int=-1): le o objeto, presente na linha readPos.
 *          caso seja -1, le todos os objetos.
 *      >> file_name(string): nome do arquivo a ser lido.
 *  ->Return:
 *      >> vector<string*>: linha(s) pedida(s);
*/
vector<string*> FileManager::readScene(int readPos, string file_name)
{
    file_reader = new ifstream(file_name.c_str());
    vector<string*> output;
    string *line;

    if(!file_reader->is_open())
    {
        output.push_back(NULL);
        delete line;
        return output;
    }

    switch (readPos)
    {
        case -1:
            string *n;
            getline(*file_reader,*n);

            for(int i=1; i<=stoi(*n); i++)
            {
                getline(*file_reader,*line);
                output.push_back(line);
            }

            delete n;
            break;

        default:
            for(int i=1; i<=readPos; i++)
            {
                getline(*file_reader,*line);
            }
            output.push_back(line);

            break;
    }

    file_reader->close();
    delete line;
    delete file_reader;
    return output;
}

/* Grava objetos em um arquivo texto.
 *
 *  ->Param:
 *      >> rewrite(bool=true): sobrescreve tudo no arquivo.
 *      >> objects(vector<string*>): descricao textual dos objetos a serem gravados
 *      >> file_name(string): nome do arquivo a ser lido.
 *  ->Return:
 *      >> bool: indica se o arquivo foi gravado com sucesso ou nao.
*/
bool FileManager::writeScene(bool rewrite, vector<string*> objects, string file_name)
{
    if(rewrite)
    {
        file_writer = new ofstream(file_name.c_str(), ios_base::trunc);
        *file_writer << objects.size() << "\n";
    }
    else
        file_writer = new ofstream(file_name.c_str(), ios_base::app);

    if(!file_writer->is_open())
        return false;

    for(unsigned int i=0; i<objects.size(); i++)
    {
        *file_writer << objects.at(i) <<"\n";
    }

    file_writer->close();
    delete file_writer;
    return true;
}
