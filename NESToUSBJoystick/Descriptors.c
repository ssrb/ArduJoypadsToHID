/** \file
 *
 *  USB Device Descriptors, for library use when in USB device mode. Descriptors are special
 *  computer-readable structures which the host requests upon device enumeration, to determine
 *  the device's capabilities and functions.
 */

#include "Descriptors.h"

/** HID class report descriptor. This is a special descriptor constructed with values from the
 *  USBIF HID class specification to describe the reports and capabilities of the HID device. This
 *  descriptor is parsed by the host and its contents used to determine what data (and in what encoding)
 *  the device will send, and what it may be sent back from the host. Refer to the HID specification for
 *  more details on HID report descriptors.
 */
const char PROGMEM JoystickReport[] =
{
	0x05, 0x01, // USAGE_PAGE (Generic Desktop)
    0x15, 0x00, // LOGICAL_MINIMUM (0)
    0x09, 0x05, // USAGE (Game Pad)
    0xa1, 0x01, // COLLECTION (Application)
    0x05, 0x01, // USAGE_PAGE (Generic Desktop)
    0x09, 0x01, // USAGE (Pointer)
    0xa1, 0x00, // COLLECTION (Physical)
    0x09, 0x30, // USAGE (X)
    0x09, 0x31, // USAGE (Y)
    0x15, 0xff, // LOGICAL_MINIMUM (-1)
    0x25, 0x01, // LOGICAL_MAXIMUM (1)
    0x35, 0xff, // PHYSICAL_MINIMUM (-1)
    0x45, 0x01, // PHYSICAL_MAXIMUM (1)
    0x95, 0x02, // REPORT_COUNT (2)
    0x75, 0x08, // REPORT_SIZE (8)
    0x81, 0x02, // INPUT (Data,Var,Abs)
    0xc0, // END_COLLECTION
    0x05, 0x09, // USAGE_PAGE (Button)
    0x19, 0x01, // USAGE_MINIMUM (Button 1)
    0x29, 0x04, // USAGE_MAXIMUM (Button 4)
    0x15, 0x00, // LOGICAL_MINIMUM (0)
    0x25, 0x01, // LOGICAL_MAXIMUM (1)
    0x75, 0x01, // REPORT_SIZE (1)
    0x95, 0x04, // REPORT_COUNT (4)
    0x81, 0x02, // INPUT (Data,Var,Abs)
    0xc0 // END_COLLECTION
};

/** Device descriptor structure. This descriptor, located in FLASH memory, describes the overall
 *  device characteristics, including the supported USB version, control endpoint size and the
 *  number of device configurations. The descriptor is read out by the USB host when the enumeration
 *  process begins.
 */
const USB_Descriptor_Device_t PROGMEM DeviceDescriptor =
{
	.Header                 = {.Size = sizeof(USB_Descriptor_Device_t), .Type = DTYPE_Device},

	.USBSpecification       = VERSION_BCD(1,1,0),
	.Class                  = USB_CSCP_NoDeviceClass,
	.SubClass               = USB_CSCP_NoDeviceSubclass,
	.Protocol               = USB_CSCP_NoDeviceProtocol,

	.Endpoint0Size          = FIXED_CONTROL_ENDPOINT_SIZE,

	.VendorID               = 0x03EB,
	.ProductID              = 0x2043,
	.ReleaseNumber          = VERSION_BCD(0,0,1),

	.ManufacturerStrIndex   = STRING_ID_Manufacturer,
	.ProductStrIndex        = STRING_ID_Product,
	.SerialNumStrIndex      = NO_DESCRIPTOR,

	.NumberOfConfigurations = FIXED_NUM_CONFIGURATIONS
};

/** Configuration descriptor structure. This descriptor, located in FLASH memory, describes the usage
 *  of the device in one of its supported configurations, including information about any device interfaces
 *  and endpoints. The descriptor is read out by the USB host during the enumeration process when selecting
 *  a configuration so that the host may correctly communicate with the USB device.
 */
const USB_Descriptor_Configuration_t PROGMEM ConfigurationDescriptor =
{
	.Config =
		{
			.Header                 = {.Size = sizeof(USB_Descriptor_Configuration_Header_t), .Type = DTYPE_Configuration},

			.TotalConfigurationSize = sizeof(USB_Descriptor_Configuration_t),
			.TotalInterfaces        = 1,

			.ConfigurationNumber    = 1,
			.ConfigurationStrIndex  = NO_DESCRIPTOR,

			.ConfigAttributes       = (USB_CONFIG_ATTR_RESERVED | USB_CONFIG_ATTR_SELFPOWERED),

			.MaxPowerConsumption    = USB_CONFIG_POWER_MA(100)
		},

	.HID_Interface =
		{
			.Header                 = {.Size = sizeof(USB_Descriptor_Interface_t), .Type = DTYPE_Interface},

			.InterfaceNumber        = 0x00,
			.AlternateSetting       = 0x00,

			.TotalEndpoints         = 1,

			.Class                  = HID_CSCP_HIDClass,
			.SubClass               = HID_CSCP_NonBootSubclass,
			.Protocol               = HID_CSCP_NonBootProtocol,

			.InterfaceStrIndex      = NO_DESCRIPTOR
		},

	.HID_JoystickHID =
		{
			.Header                 = {.Size = sizeof(USB_HID_Descriptor_HID_t), .Type = HID_DTYPE_HID},

			.HIDSpec                = VERSION_BCD(1,1,1),
			.CountryCode            = 0x00,
			.TotalReportDescriptors = 1,
			.HIDReportType          = HID_DTYPE_Report,
			.HIDReportLength        = sizeof(JoystickReport)
		},

	.HID_ReportINEndpoint =
		{
			.Header                 = {.Size = sizeof(USB_Descriptor_Endpoint_t), .Type = DTYPE_Endpoint},

			.EndpointAddress        = JOYSTICK_EPADDR,
			.Attributes             = (EP_TYPE_INTERRUPT | ENDPOINT_ATTR_NO_SYNC | ENDPOINT_USAGE_DATA),
			.EndpointSize           = JOYSTICK_EPSIZE,
			.PollingIntervalMS      = 0x05
		}
};

/** Language descriptor structure. This descriptor, located in FLASH memory, is returned when the host requests
 *  the string descriptor with index 0 (the first index). It is actually an array of 16-bit integers, which indicate
 *  via the language ID table available at USB.org what languages the device supports for its string descriptors.
 */
const USB_Descriptor_String_t PROGMEM LanguageString =
{
	.Header                 = {.Size = USB_STRING_LEN(1), .Type = DTYPE_String},

	.UnicodeString          = {LANGUAGE_ID_ENG}
};

/** Manufacturer descriptor string. This is a Unicode string containing the manufacturer's details in human readable
 *  form, and is read out upon request by the host when the appropriate string ID is requested, listed in the Device
 *  Descriptor.
 */
const USB_Descriptor_String_t PROGMEM ManufacturerString =
{
	.Header                 = {.Size = USB_STRING_LEN(11), .Type = DTYPE_String},

	.UnicodeString          = L"Nintendo"
};

/** Product descriptor string. This is a Unicode string containing the product's details in human readable form,
 *  and is read out upon request by the host when the appropriate string ID is requested, listed in the Device
 *  Descriptor.
 */
const USB_Descriptor_String_t PROGMEM ProductString =
{
	.Header                 = {.Size = USB_STRING_LEN(18), .Type = DTYPE_String},

	.UnicodeString          = L"NES gamepad"
};

/** This function is called by the library when in device mode, and must be overridden (see library "USB Descriptors"
 *  documentation) by the application code so that the address and size of a requested descriptor can be given
 *  to the USB library. When the device receives a Get Descriptor request on the control endpoint, this function
 *  is called so that the descriptor details can be passed back and the appropriate descriptor sent back to the
 *  USB host.
 */
uint16_t CALLBACK_USB_GetDescriptor(const uint16_t wValue,
                                    const uint8_t wIndex,
                                    const void** const DescriptorAddress)
{
	const uint8_t  DescriptorType   = (wValue >> 8);
	const uint8_t  DescriptorNumber = (wValue & 0xFF);

	const void* Address = NULL;
	uint16_t    Size    = NO_DESCRIPTOR;

	switch (DescriptorType)
	{
		case DTYPE_Device:
			Address = &DeviceDescriptor;
			Size    = sizeof(USB_Descriptor_Device_t);
			break;
		case DTYPE_Configuration:
			Address = &ConfigurationDescriptor;
			Size    = sizeof(USB_Descriptor_Configuration_t);
			break;
		case DTYPE_String:
			switch (DescriptorNumber)
			{
				case STRING_ID_Language:
					Address = &LanguageString;
					Size    = pgm_read_byte(&LanguageString.Header.Size);
					break;
				case STRING_ID_Manufacturer:
					Address = &ManufacturerString;
					Size    = pgm_read_byte(&ManufacturerString.Header.Size);
					break;
				case STRING_ID_Product:
					Address = &ProductString;
					Size    = pgm_read_byte(&ProductString.Header.Size);
					break;
			}

			break;
		case HID_DTYPE_HID:
			Address = &ConfigurationDescriptor.HID_JoystickHID;
			Size    = sizeof(USB_HID_Descriptor_HID_t);
			break;
		case HID_DTYPE_Report:
			Address = &JoystickReport;
			Size    = sizeof(JoystickReport);
			break;
	}

	*DescriptorAddress = Address;
	return Size;
}

