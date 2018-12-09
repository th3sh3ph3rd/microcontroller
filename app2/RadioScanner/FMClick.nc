// A Thomas Lamprecht <tlamprecht@ecs.tuwien.ac> production - 2018

typedef enum {
    PS, // Programm Station
    RT, // Radio Text
    TIME, // TIME
} RDSType;

interface FMClick {
    command error_t tune(uint16_t channel);

    command error_t seek(bool up);

    command uint16_t getChannel(void);

    command error_t setVolume(uint8_t);

    command error_t receiveRDS(bool enable);

    event void initDone(error_t res);

    async event void tuneComplete(uint16_t channel);

    async event void rdsReceived(RDSType type, char *buf);
}
