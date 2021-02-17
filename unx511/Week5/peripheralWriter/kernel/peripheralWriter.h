//peripheralWriter.h - header file for the peripheral writer
//
// 26-Dec-20  M. Watler         Created
//

typedef struct peripheral_info {
    int num_channels;
    int size_channel;
} PERIPHERAL_INFO;

//IOCTL prototypes
//See https://01.org/linuxgraphics/gfx-docs/drm/ioctl/ioctl-number.html for macro syntax
#define PERIPHERAL_WRITER_GET_INFO          _IOR('b','b',PERIPHERAL_INFO*)//IOCTL get (read) command
#define PERIPHERAL_WRITER_GET_CHANNEL_INDEX _IOR('a','b',int*)//IOCTL get (read) command
#define PERIPHERAL_WRITER_SET_CHANNEL_INDEX _IOW('a','b',int*)//IOCTL set (write) command
