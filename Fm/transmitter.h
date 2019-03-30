#ifndef TRANSMITTER_H
#define TRANSMITTER_H

#include "error_reporter.h"
#include "audio_format.h"
#include <vector>

using std::vector;

#define BUFFER_TIME 1000000

using std::string;

class Transmitter
{
    public:
        virtual ~Transmitter();

        void play(string filename, double frequency, bool loop);
        void stop();

	static Transmitter* getInstance(); 
        static AudioFormat* getFormat(string filename);
    private:
        Transmitter();

        bool doStop;

        static void* peripherals;
        static vector<float>* buffer;
        static unsigned frameOffset, clockDivisor;
        static bool isTransmitting;
        static void* transmit(void* params);
};

#endif // TRANSMITTER_H
