#ifndef PCM_WAVE_HEADER_H
#define PCM_WAVE_HEADER_H

#define WAVE_FORMAT_PCM 0x0001

struct PCMWaveHeader
{
    char chunkID[4];
    unsigned chunkSize;
    char format[4];
    char subchunk1ID[4];
    unsigned subchunk1Size;
    unsigned short audioFormat;
    unsigned short channels;
    unsigned sampleRate;
    unsigned byteRate;
    unsigned short blockAlign;
    unsigned short bitsPerSample;
    char subchunk2ID[4];
    unsigned subchunk2Size;
};

#endif // PCM_WAVE_HEADER
