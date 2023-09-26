/////////////////////////////////////////////////////////////
//// Auto generate by TeenyDT, http://dt.tusb.org
/////////////////////////////////////////////////////////////
#ifndef __KB_OPENCM3_USB_INIT_H__
#define __KB_OPENCM3_USB_INIT_H__

#include <libopencm3/usb/usbd.h>

typedef void (*ep_cb_t)(usbd_device *usbd_dev, uint8_t ep);


/**
 * 
*/
usbd_device *KB_usb_init(const usbd_driver *driver, ep_cb_t ep_in_cb, ep_cb_t ep_out_cb);

#ifndef opencm3_usb_init
#define opencm3_usb_init KB_usb_init
#endif

// Extra define
#define KB_REPORT_DESCRIPTOR_SIZE_IF0  (63)
extern const uint8_t KB_ReportDescriptor_if0[KB_REPORT_DESCRIPTOR_SIZE_IF0];


#endif  // #ifndef __KB_OPENCM3_USB_INIT_H__
