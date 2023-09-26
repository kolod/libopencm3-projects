/////////////////////////////////////////////////////////////
//// Auto generate by TeenyDT, http://dt.tusb.org
/////////////////////////////////////////////////////////////
#include "usb_init.h"
#include "string.h"

#ifndef NULL
#define NULL 0
#endif

#ifndef WEAK
#define WEAK
#endif

#ifndef __ALIGN_BEGIN
#define __ALIGN_BEGIN
#endif

#ifndef __ALIGN_END
#define __ALIGN_END
#endif

//#define ER_DEBUG
#ifdef ER_DEBUG
#include <stdio.h>
#define ER_DPRINTF(fmt, ...) \
	do { printf(fmt, ## __VA_ARGS__); } while (0)
#else
#define ER_DPRINTF(fmt, ...) \
	do { } while (0)
#endif

struct usb_endpoint_init{
    uint8_t addr;
    uint8_t type;
    uint16_t size;
    void (*cb)(usbd_device *, uint8_t);
};

typedef const uint8_t* desc_t;

static const struct usb_device_descriptor KB_dev_desc = {
    .bLength = 0x12,
    .bDescriptorType = USB_DT_DEVICE,
    .bcdUSB = 0x0200,
    .bDeviceClass = 0x00,
    .bDeviceSubClass = 0x00,
    .bDeviceProtocol = 0x00,
    .bMaxPacketSize0 = 0x40,
    .idVendor = 0x0483,
    .idProduct = 0x0011,
    .bcdDevice = 0x0100,
    .iManufacturer = 0x01,
    .iProduct = 0x02,
    .iSerialNumber = 0x03,
    .bNumConfigurations = 0x01,
};
static const struct usb_endpoint_descriptor KB_config1_itf0_endpoints[] = {
  {
    .bLength = 0x07,
    .bDescriptorType = USB_DT_ENDPOINT,
    .bEndpointAddress = 0x81,
    .bmAttributes = 0x03,
    .wMaxPacketSize = 0x0008,
    .bInterval = 0x01,
  },
  {
    .bLength = 0x07,
    .bDescriptorType = USB_DT_ENDPOINT,
    .bEndpointAddress = 0x01,
    .bmAttributes = 0x03,
    .wMaxPacketSize = 0x0008,
    .bInterval = 0x01,
  },

};

#define KB_config1_itf0_extra_size (9)
static const uint8_t KB_config1_itf0_extra[9] = {
  ///////////////////////////////////////
  /// hid descriptor
  ///////////////////////////////////////
  0x09,                                             /* bLength */
  0x21,                                             /* bDescriptorType */
  0x11, 0x01,                                       /* bcdHID */
  0x00,                                             /* bCountryCode */
  0x01,                                             /* bNumDescriptors */
  0x22,                                             /* bDescriptorType1 */
  0x3f, 0x00,                                       /* wDescriptorLength1 */

};

static const struct usb_interface_descriptor KB_config1_itf0 = {
    .bLength = 0x09,
    .bDescriptorType = USB_DT_INTERFACE,
    .bInterfaceNumber = 0x00,
    .bAlternateSetting = 0x00,
    .bNumEndpoints = 0x02,
    .bInterfaceClass = 0x03,
    .bInterfaceSubClass = 0x01,
    .bInterfaceProtocol = 0x01,
    .iInterface = 0x00,

    .endpoint = KB_config1_itf0_endpoints,
    .extra = KB_config1_itf0_extra,
    .extralen = 9,
};
static const struct usb_interface KB_config1_interfaces[] = {
  {
    .num_altsetting = 1,
    .altsetting = &KB_config1_itf0,
  },
};
#define KB_config1_ep_count        (2)
static const struct usb_endpoint_init KB_config1_ep_init[2] = {
    { .addr = 0x81, .type = USB_ENDPOINT_ATTR_INTERRUPT, .size = 8, .cb = NULL },
    { .addr = 0x01, .type = USB_ENDPOINT_ATTR_INTERRUPT, .size = 8, .cb = NULL },
};
static const struct usb_config_descriptor KB_config[] = {
  {
    .bLength = 0x09,
    .bDescriptorType = USB_DT_CONFIGURATION,
    .wTotalLength = 0x0029,
    .bNumInterfaces = 0x01,
    .bConfigurationValue = 0x01,
    .iConfiguration = 0x00,
    .bmAttributes = 0x80,
    .bMaxPower = 0x64,

    .interface = KB_config1_interfaces,
  },
};
/////////////////////////////////////////////
// String descriptors
/////////////////////////////////////////////

static const char * KB_usb_strings[] = {
    "TeenyUSB",
    "TeenyUSB Boot Keyboard DEMO",
    "TUSB123456"
};

/////////////////////////////////////////////
// Extra descriptors
/////////////////////////////////////////////
#if defined(HAS_WCID_20)
#define HIBYTE(v)    ( (uint8_t)((v)>>8))
#define LOBYTE(v)    ( (uint8_t)((v)&0xff))
#define USB_DESC_TYPE_BOS    0x0f
#endif

#define KB_REPORT_DESCRIPTOR_SIZE_IF0  (63)
WEAK __ALIGN_BEGIN const uint8_t KB_ReportDescriptor_if0[KB_REPORT_DESCRIPTOR_SIZE_IF0] __ALIGN_END = {
        //  Boot keyboad report descriptor
        0x05, 0x01,     // USAGE_PAGE (Generic Desktop)
        0x09, 0x06,     // USAGE (Keyboard)
        0xa1, 0x01,     // COLLECTION (Application)
        0x05, 0x07,     //   USAGE_PAGE (Keyboard)
        0x19, 0xe0,     //   USAGE_MINIMUM (Keyboard LeftControl)
        0x29, 0xe7,     //   USAGE_MAXIMUM (Keyboard Right GUI)
        0x15, 0x00,     //   LOGICAL_MINIMUM (0)
        0x25, 0x01,     //   LOGICAL_MAXIMUM (1)
        0x75, 0x01,     //   REPORT_SIZE (1)
        0x95, 0x08,     //   REPORT_COUNT (8)
        0x81, 0x02,     //   INPUT (Data,Var,Abs)
        0x95, 0x01,     //   REPORT_COUNT (1)
        0x75, 0x08,     //   REPORT_SIZE (8)
        0x81, 0x03,     //   INPUT (Cnst,Var,Abs)
        0x95, 0x05,     //   REPORT_COUNT (5)
        0x75, 0x01,     //   REPORT_SIZE (1)
        0x05, 0x08,     //   USAGE_PAGE (LEDs)
        0x19, 0x01,     //   USAGE_MINIMUM (Num Lock)
        0x29, 0x05,     //   USAGE_MAXIMUM (Kana)
        0x91, 0x02,     //   OUTPUT (Data,Var,Abs)
        0x95, 0x01,     //   REPORT_COUNT (1)
        0x75, 0x03,     //   REPORT_SIZE (3)
        0x91, 0x03,     //   OUTPUT (Cnst,Var,Abs)
        0x95, 0x06,     //   REPORT_COUNT (6)
        0x75, 0x08,     //   REPORT_SIZE (8)
        0x15, 0x00,     //   LOGICAL_MINIMUM (0)
        0x25, 0x65,     //   LOGICAL_MAXIMUM (101)
        0x05, 0x07,     //   USAGE_PAGE (Keyboard)
        0x19, 0x00,     //   USAGE_MINIMUM (Reserved (no event indicated))
        0x29, 0x65,     //   USAGE_MAXIMUM (Keyboard Application)
        0x81, 0x00,     //   INPUT (Data,Ary,Abs)
        0xc0            // END_COLLECTION
    };



/////////////////////////////////////////////
// USB init code
/////////////////////////////////////////////

const struct {
    int len;
    const struct usb_endpoint_init* ep_inits;
}KB_ep_init_map[] = {
  {
    .len = KB_config1_ep_count,
    .ep_inits = KB_config1_ep_init,
  },
};

#define ARR_SIZE(x)   (sizeof(x)/sizeof((x)[0]))

static ep_cb_t KB_ep_in_handler;
static ep_cb_t KB_ep_out_handler;

static enum usbd_request_return_codes KB_WCID_control_request(usbd_device *usbd_dev,
	struct usb_setup_data *req,
	uint8_t **buf,
	uint16_t *len,
    usbd_control_complete_callback *complete);

static void KB_set_config(usbd_device *usbd_dev, uint16_t wValue)
{
    ER_DPRINTF("set cfg %d\n", wValue);
    if(wValue && wValue <= ARR_SIZE(KB_ep_init_map) ){
        int len = KB_ep_init_map[wValue-1].len;
        const struct usb_endpoint_init* ep_inits = KB_ep_init_map[wValue-1].ep_inits;
        for(int i=0;i<len;i++){
            usbd_ep_setup(usbd_dev, ep_inits[i].addr, ep_inits[i].type, ep_inits[i].size,
                ep_inits[i].cb ? ep_inits[i].cb : ( 
                ep_inits[i].addr & 0x80 ? KB_ep_in_handler : KB_ep_out_handler ) );
        }
    }else{
        ER_DPRINTF("set configuration unknown: %d\n", wValue);
    }
}

#ifndef USB_DT_BOS
#define USB_DT_BOS  0x0f
#endif

#if defined(HAS_WCID) || defined(HAS_WCID_20)

static int usb_descriptor_type(uint16_t wValue)
{
	return wValue >> 8;
}

#if defined(HAS_WCID)
static int usb_descriptor_index(uint16_t wValue)
{
	return wValue & 0xFF;
}
#endif

#endif

#ifndef MIN
#define MIN(a,b)   ((a)<(b)?(a):(b))
#endif

static enum usbd_request_return_codes KB_WCID_control_request(usbd_device *usbd_dev,
	struct usb_setup_data *req,
	uint8_t **buf,
	uint16_t *len,
    usbd_control_complete_callback *complete)
{
    (void) usbd_dev;
    (void) complete;
#if defined(HAS_WCID)
    if(req->bRequest == USB_REQ_GET_DESCRIPTOR 
    && usb_descriptor_type(req->wValue) == USB_DT_STRING
    && usb_descriptor_index(req->wValue) == 0xee){
        #if defined(WCID_STRING_DESCRIPTOR_MSOS_SIZE)
        *len = MIN(*len, WCID_STRING_DESCRIPTOR_MSOS_SIZE);
        memcpy(*buf, WCID_StringDescriptor_MSOS, *len);
        return USBD_REQ_HANDLED;
        #endif
    }else if( (req->bmRequestType & USB_REQ_TYPE_TYPE) == USB_REQ_TYPE_VENDOR
    &&   req->bRequest == WCID_VENDOR_CODE ){
        if(req->wIndex == 4){
            #if defined(KB_WCID_DESCRIPTOR_SIZE)
            *len = MIN(*len, KB_WCID_DESCRIPTOR_SIZE);
            memcpy(*buf, KB_WCIDDescriptor, *len);
            return USBD_REQ_HANDLED;
            #endif
        }
        #if defined(KB_WCID_PROPERTIES_SIZE)
        else if(req->wIndex == 5 && req->wValue < KB_WCID_PROPERTIES_SIZE ){
            desc_t desc = KB_WCIDProperties[req->wValue];
            if(desc){
                uint16_t tlen = desc[0] + (desc[1]<<8) + (desc[2]<<16) + (desc[3]<<24);
                *len = MIN(*len, tlen);
                memcpy(*buf, desc, *len);
                return USBD_REQ_HANDLED;
            }
        }
        #endif
    }
#endif

#if defined(HAS_WCID_20)
    if(req->bRequest == USB_REQ_GET_DESCRIPTOR 
    && usb_descriptor_type(req->wValue) == USB_DT_BOS){
        #if defined( KB_WCID_BOS_SIZE )
        *len = MIN(*len, KB_WCID_BOS_SIZE);
        memcpy(*buf, KB_WCIDBOS, *len);
        return USBD_REQ_HANDLED;
        #endif
    }else if((req->bmRequestType & USB_REQ_TYPE_TYPE) == USB_REQ_TYPE_VENDOR
    &&   req->bRequest == WCID_VENDOR_CODE
    &&   req->wIndex == 7 ){
        #if defined( KB_WCID_DESC_SET_SIZE )
        *len = MIN(*len, KB_WCID_DESC_SET_SIZE);
        memcpy(*buf, KB_WCIDDescriptorSet, *len);
        return USBD_REQ_HANDLED;
        #endif
    }
#endif
    return USBD_REQ_NEXT_CALLBACK;
}


static uint8_t KB_control_buffer[1024];
usbd_device * KB_usb_init(const usbd_driver *driver, ep_cb_t ep_in_cb, ep_cb_t ep_out_cb)
{
    usbd_device *dev = usbd_init(driver, &KB_dev_desc, KB_config,
    KB_usb_strings, ARR_SIZE(KB_usb_strings),
    KB_control_buffer, sizeof(KB_control_buffer));

    KB_ep_in_handler = ep_in_cb;
    KB_ep_out_handler = ep_out_cb;

    // TODO
    // WCID_control_request may register after set configuration
    // But the WCID feature in Windows will request something before set configuration
    // So register the control request for WCID here, after set configuartion it will be clear
    usbd_register_control_callback(dev, 0, 0, KB_WCID_control_request);

    usbd_register_set_config_callback(dev, KB_set_config);
    return dev;
}