// A Thomas Lamprecht <tlamprecht@ecs.tuwien.ac> production - 2018

#define PS_BUF_SZ   8
#define RT_BUF_SZ   64
#define CT_BUF_SZ   6

typedef enum {
    UP,
    DOWN,
    BAND
} seekmode_t;

typedef enum {
    PS, // Programm Station
    RT, // Radio Text
    TIME, // TIME
} RDSType;

interface FMClick {
    command error_t tune(uint16_t channel);

    command error_t seek(seekmode_t mode);

    command uint16_t getChannel(void);

    command error_t setVolume(uint8_t);

    command error_t receiveRDS(bool enable);

    event void initDone(error_t res);

    async event void tuneComplete(uint16_t channel);
    
    async event void seekComplete(uint16_t channel);

    async event void rdsReceived(RDSType type, char *buf);
}
