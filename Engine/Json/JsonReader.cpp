#include "JsonReader.h"
#include <fstream>
using namespace std;

bool JsonReader::Load(string fileName,json& _data)
{
    // �t�@�C�����J��
    ifstream readingFile;
    readingFile.open(fileName, ios::in);

    // �t�@�C�����J���Ȃ�������
    if (readingFile.is_open() == false)return false;

    // �f�[�^��json�I�u�W�F�N�g�Ɋi�[
    readingFile >> _data;

    // �t�@�C�������
    readingFile.close();

    return true;
}

bool JsonReader::Save(string fileName, json& _data)
{
    // �t�@�C�����J��
    ofstream writingFile;
    writingFile.open(fileName, ios::out);

    // �t�@�C�����J���Ȃ�������
    if (writingFile.is_open() == false)return false;

    // �f�[�^���t�@�C���ɗ���
    writingFile << _data.dump() << endl;

    // �t�@�C�������
    writingFile.close();

    return true;
}
