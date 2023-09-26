#include <libopencmsis/core_cm3.h>

#include <libopencm3/cm3/cortex.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/cm3/systick.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/usb/usbd.h>
#include <libopencm3/usb/cdc.h>
#include <libopencm3/cm3/scb.h>

#include "usb_init.h"

#define NULL 0
#define MS(t) ((uint32_t) (6998.39037021485058436559591294 * t))

const struct rcc_clock_scale rcc_hse_25mhz_3v3_96MHz = {
	.pllm = 25,
	.plln = 384,
	.pllp = 4,
	.pllq = 8,
	.pllr = 4,
	.pll_source = RCC_CFGR_PLLSRC_HSE_CLK,
	.flash_config = FLASH_ACR_DCEN | FLASH_ACR_ICEN | FLASH_ACR_LATENCY_2WS,
	.hpre = RCC_CFGR_HPRE_DIV_NONE,
	.ppre1 = RCC_CFGR_PPRE_DIV_2,
	.ppre2 = RCC_CFGR_PPRE_DIV_NONE,
	.voltage_scale = PWR_SCALE1,
	.ahb_frequency  = 96000000,
	.apb1_frequency = 48000000,
	.apb2_frequency = 96000000,
};

usbd_device *usbd_dev = 0;

void otg_fs_isr(void) {
	if (usbd_dev) {
		usbd_poll(usbd_dev);
	}
}

void in_callback(usbd_device *device, uint8_t ep) {
	(void)device;
	(void)ep;
}

void out_callback(usbd_device *device, uint8_t ep) {
	(void)device;
	(void)ep;
}

int main(void) {
    rcc_clock_setup_pll(&rcc_hse_25mhz_3v3_96MHz);
    //rcc_clock_setup_pll(&rcc_hse_25mhz_3v3[0]);

	/* Enable GPIOD clock. */
	rcc_periph_clock_enable(RCC_GPIOA | RCC_GPIOC);

	gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO11 | GPIO12);
	gpio_set_output_options(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_100MHZ, GPIO11 | GPIO12);
	gpio_set_af(GPIOA, GPIO_AF10, GPIO11 | GPIO12);

	usbd_dev = opencm3_usb_init(&otgfs_usb_driver, &in_callback, &out_callback);

	//nvic_set_priority(NVIC_OTG_FS_IRQ, 0);
	nvic_enable_irq(NVIC_OTG_FS_IRQ);

	cm_enable_interrupts();	

	while (1) {
		;
	}
}
