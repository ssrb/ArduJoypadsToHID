// Z:\home\sb\Hacking\ArduJoypadsToHID\ArcadeStickToUSBJoystick\joystick.hid.h


char ReportDescriptor[34] = {
    0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)
    0x15, 0x00,                    // LOGICAL_MINIMUM (0)
    0x09, 0x04,                    // USAGE (Joystick)
    0xa1, 0x01,                    // COLLECTION (Application)
    0x05, 0x01,                    //   USAGE_PAGE (Generic Desktop)
    0x09, 0x01,                    //   USAGE (Pointer)
    0xa1, 0x00,                    //   COLLECTION (Physical)
    0x09, 0x30,                    //     USAGE (X)
    0x09, 0x31,                    //     USAGE (Y)
    0x15, 0xff,                    //     LOGICAL_MINIMUM (-1)
    0x25, 0x01,                    //     LOGICAL_MAXIMUM (1)
    0x35, 0xff,                    //     PHYSICAL_MINIMUM (-1)
    0x45, 0x01,                    //     PHYSICAL_MAXIMUM (1)
    0x95, 0x02,                    //     REPORT_COUNT (2)
    0x75, 0x08,                    //     REPORT_SIZE (8)
    0x81, 0x02,                    //     INPUT (Data,Var,Abs)
    0xc0,                          //   END_COLLECTION
    0xc0                           // END_COLLECTION
};

