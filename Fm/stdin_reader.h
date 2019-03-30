#ifndef STDIN_READER_H
#define STDIN_READER_H

#include <vector>
#include <fcntl.h>
#include "audio_format.h"
#include "error_reporter.h"

#define MAX_STREAM_SIZE 2097152
#define STREAM_SAMPLE_RATE 22050
#define STREAM_BITS_PER_SAMPLE 16
#define STREAM_CHANNELS 1

using std::vector;

class StdinReader
{
    public:
        virtual ~StdinReader();

        pthread_t thread;
        vector<float>* getFrames(unsigned frameCount, bool &forceStop);
        AudioFormat* getFormat();

        static StdinReader* getInstance();
    private:
        StdinReader();

        static vector<char> stream;
        static void* readStdin(void* params);
        static bool doStop, isDataAccess, isReading;
};

#endif // STDIN_READER_H
