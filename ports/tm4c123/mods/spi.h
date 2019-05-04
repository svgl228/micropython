/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2013, 2014 Damien P. George
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef MICROPY_INCLUDED_TM4C_SPI_H
#define MICROPY_INCLUDED_TM4C_SPI_H

#include <stdint.h>
//#include "dma.h"
#include "inc/hw_ssi.h"
#include "inc/hw_memmap.h"
#include "driverlib/ssi.h"

//extern const mp_obj_type_ttypedef struct _spi_t {
//     spi_obj_t *spi;
//     const dma_descr_t *tx_dma_descr;
//     const dma_descr_t *rx_dma_descr;
// } spi_t;

// typedef struct _spi_t {typedef struct _spi_t {
//     spi_obj_t *spi;
//     const dma_descr_t *tx_dma_descr;
//     const dma_descr_t *rx_dma_descr;
// } spi_t;
//     spi_obj_t *spi;
//     const dma_descr_t *tx_dma_descr;
//     const dma_descr_t *rx_dma_descr;
// } spi_t;

typedef enum {
    PYB_SPI_NONE =4,
    PYB_SPI_0 = 0,
    PYB_SPI_1 = 1,
    PYB_SPI_2 = 2,
    PYB_SPI_3 = 3,
} spi_id_t;

typedef struct  {
    volatile uint32_t CR0;
    volatile uint32_t CR1;
    volatile uint32_t DR;
    volatile uint32_t SR;
    volatile uint32_t CPSR;
    volatile uint32_t IM;
    volatile uint32_t RIS;
    volatile uint32_t MIS;
    volatile uint32_t ICR;
    volatile uint32_t DMACTL;
    uint32_t _1[1000];
    volatile uint32_t CC;
} periph_spi_t;

// spi_obj_t spi_handle_0 = {
//     .spi = SSI0_BASE,
//     .periph = SYSCTL_PERIPH_SSI0,
//     .regs = (periph_spi_t*)SSI0_BASE,
//     .irqn = 0, 
//     .mode = SSI_MODE_MASTER, 
//     .phase = SSI_FRF_MOTO_MODE_0, 
//     .spi_id = PYB_SPI_0,
//     .is_enabled = false, 
//     .dma_rx_enabled = false,
//     .dma_tx_enabled = false,
// };

// spi_obj_t spi_handle_1 = {
//     .spi = SSI1_BASE,
//     .periph = SYSCTL_PERIPH_SSI1,
//     .regs = (periph_spi_t*)SSI1_BASE,
//     .irqn = 1, 
//     .mode = SSI_MODE_MASTER, 
//     .phase = SSI_FRF_MOTO_MODE_0, 
//     .spi_id = PYB_SPI_1,
//     .is_enabled = false, 
//     .dma_rx_enabled = false,
//     .dma_tx_enabled = false,
// };

// spi_obj_t spi_handle_2 = {
//     .spi = SSI2_BASE,
//     .periph = SYSCTL_PERIPH_SSI2,
//     .regs = (periph_spi_t*)SSI2_BASE,
//     .irqn = 2, 
//     .mode = SSI_MODE_MASTER, 
//     .phase = SSI_FRF_MOTO_MODE_0, 
//     .spi_id = PYB_SPI_2,
//     .is_enabled = false, 
//     .dma_rx_enabled = false,
//     .dma_tx_enabled = false,
// };

// spi_obj_t spi_handle_3 = {
//     .spi = SSI3_BASE,
//     .periph = SYSCTL_PERIPH_SSI3,
//     .regs = (periph_spi_t*)SSI3_BASE,
//     .irqn = 3, 
//     .mode = SSI_MODE_MASTER, 
//     .phase = SSI_FRF_MOTO_MODE_0, 
//     .spi_id = PYB_SPI_3,
//     .is_enabled = false, 
//     .dma_rx_enabled = false,
//     .dma_tx_enabled = false,
// };

//extern const spi_t spi_obj[6];

//extern const mp_obj_type_t pyb_spi_type;
extern const mp_obj_type_t machine_soft_spi_type;
extern const mp_obj_type_t machine_hard_spi_type;

void spi_init0(void);
void spi_init(const mp_obj_t *self);
//const spi_t *spi_from_mp_obj(mp_obj_t o);

#endif // MICROPY_INCLUDED_TM4C_SPI_H
