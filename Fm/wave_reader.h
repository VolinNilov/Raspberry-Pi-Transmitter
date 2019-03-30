#ifndef WAVE_READER_H
#define WAVE_READER_H

#include <string>
#include <vector>
#include <fstream>
#include "audio_format.h"
#include "pcm_wave_header.h"

using std::vector;
using std::string;
using std::ifstream;

class WaveReader
{
    public:
        WaveReader(string filename);
        virtual ~WaveReader();

        AudioFormat* getFormat();
        vector<float>* getFrames(unsigned frameCount, unsigned frameOffset);
        bool isEnd(unsigned frameOffset);
    private:
        string filename;
        PCMWaveHeader header;
        unsigned fileSize, dataOffset;
        ifstream ifs;

        vector<char>* readData(unsigned bytesToRead, bool closeFileOnException);
};

#endif // WAVE_READER_H
