/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios2_qsys_0' in SOPC Builder design 'nios_hps_system'
 * SOPC Builder design path: C:/intelFPGA_lite/EFES_Lab/uarthwsw/nios_hps_system.sopcinfo
 *
 * Generated: Fri Dec 03 18:05:55 CET 2021
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_qsys"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x08000820
#define ALT_CPU_CPU_FREQ 100000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "tiny"
#define ALT_CPU_DATA_ADDR_WIDTH 0x1c
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x04000020
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 100000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 0
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 0
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_ICACHE_SIZE 0
#define ALT_CPU_INST_ADDR_WIDTH 0x1c
#define ALT_CPU_NAME "nios2_qsys_0"
#define ALT_CPU_RESET_ADDR 0x04000000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x08000820
#define NIOS2_CPU_FREQ 100000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "tiny"
#define NIOS2_DATA_ADDR_WIDTH 0x1c
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x04000020
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 0
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 0
#define NIOS2_ICACHE_LINE_SIZE_LOG2 0
#define NIOS2_ICACHE_SIZE 0
#define NIOS2_INST_ADDR_WIDTH 0x1c
#define NIOS2_RESET_ADDR 0x04000000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_I2C
#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_NEW_SDRAM_CONTROLLER
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_SPI
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_AVALON_TIMER
#define __ALTERA_AVALON_UART
#define __ALTERA_NIOS2_QSYS


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone V"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart_0"
#define ALT_STDERR_BASE 0x8001158
#define ALT_STDERR_DEV jtag_uart_0
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart_0"
#define ALT_STDIN_BASE 0x8001158
#define ALT_STDIN_DEV jtag_uart_0
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart_0"
#define ALT_STDOUT_BASE 0x8001158
#define ALT_STDOUT_DEV jtag_uart_0
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "nios_hps_system"


/*
 * hal configuration
 *
 */

#define ALT_MAX_FD 32
#define ALT_SYS_CLK none
#define ALT_TIMESTAMP_CLK TIMER_0


/*
 * i2c_0 configuration
 *
 */

#define ALT_MODULE_CLASS_i2c_0 altera_avalon_i2c
#define I2C_0_BASE 0x8001000
#define I2C_0_FIFO_DEPTH 4
#define I2C_0_FREQ 50000000
#define I2C_0_IRQ 3
#define I2C_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define I2C_0_NAME "/dev/i2c_0"
#define I2C_0_SPAN 64
#define I2C_0_TYPE "altera_avalon_i2c"
#define I2C_0_USE_AV_ST 0


/*
 * jtag_uart_0 configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart_0 altera_avalon_jtag_uart
#define JTAG_UART_0_BASE 0x8001158
#define JTAG_UART_0_IRQ 0
#define JTAG_UART_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_0_NAME "/dev/jtag_uart_0"
#define JTAG_UART_0_READ_DEPTH 64
#define JTAG_UART_0_READ_THRESHOLD 8
#define JTAG_UART_0_SPAN 8
#define JTAG_UART_0_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_0_WRITE_DEPTH 64
#define JTAG_UART_0_WRITE_THRESHOLD 8


/*
 * nios_7seg configuration
 *
 */

#define ALT_MODULE_CLASS_nios_7seg altera_avalon_pio
#define NIOS_7SEG_BASE 0x80010c0
#define NIOS_7SEG_BIT_CLEARING_EDGE_REGISTER 0
#define NIOS_7SEG_BIT_MODIFYING_OUTPUT_REGISTER 0
#define NIOS_7SEG_CAPTURE 0
#define NIOS_7SEG_DATA_WIDTH 24
#define NIOS_7SEG_DO_TEST_BENCH_WIRING 0
#define NIOS_7SEG_DRIVEN_SIM_VALUE 0
#define NIOS_7SEG_EDGE_TYPE "NONE"
#define NIOS_7SEG_FREQ 50000000
#define NIOS_7SEG_HAS_IN 0
#define NIOS_7SEG_HAS_OUT 1
#define NIOS_7SEG_HAS_TRI 0
#define NIOS_7SEG_IRQ -1
#define NIOS_7SEG_IRQ_INTERRUPT_CONTROLLER_ID -1
#define NIOS_7SEG_IRQ_TYPE "NONE"
#define NIOS_7SEG_NAME "/dev/nios_7seg"
#define NIOS_7SEG_RESET_VALUE 0
#define NIOS_7SEG_SPAN 16
#define NIOS_7SEG_TYPE "altera_avalon_pio"


/*
 * nios_buttons configuration
 *
 */

#define ALT_MODULE_CLASS_nios_buttons altera_avalon_pio
#define NIOS_BUTTONS_BASE 0x8001120
#define NIOS_BUTTONS_BIT_CLEARING_EDGE_REGISTER 0
#define NIOS_BUTTONS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define NIOS_BUTTONS_CAPTURE 0
#define NIOS_BUTTONS_DATA_WIDTH 4
#define NIOS_BUTTONS_DO_TEST_BENCH_WIRING 0
#define NIOS_BUTTONS_DRIVEN_SIM_VALUE 0
#define NIOS_BUTTONS_EDGE_TYPE "NONE"
#define NIOS_BUTTONS_FREQ 50000000
#define NIOS_BUTTONS_HAS_IN 1
#define NIOS_BUTTONS_HAS_OUT 0
#define NIOS_BUTTONS_HAS_TRI 0
#define NIOS_BUTTONS_IRQ -1
#define NIOS_BUTTONS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define NIOS_BUTTONS_IRQ_TYPE "NONE"
#define NIOS_BUTTONS_NAME "/dev/nios_buttons"
#define NIOS_BUTTONS_RESET_VALUE 0
#define NIOS_BUTTONS_SPAN 16
#define NIOS_BUTTONS_TYPE "altera_avalon_pio"


/*
 * nios_header_conn configuration
 *
 */

#define ALT_MODULE_CLASS_nios_header_conn altera_avalon_pio
#define NIOS_HEADER_CONN_BASE 0x80010b0
#define NIOS_HEADER_CONN_BIT_CLEARING_EDGE_REGISTER 0
#define NIOS_HEADER_CONN_BIT_MODIFYING_OUTPUT_REGISTER 0
#define NIOS_HEADER_CONN_CAPTURE 0
#define NIOS_HEADER_CONN_DATA_WIDTH 32
#define NIOS_HEADER_CONN_DO_TEST_BENCH_WIRING 0
#define NIOS_HEADER_CONN_DRIVEN_SIM_VALUE 0
#define NIOS_HEADER_CONN_EDGE_TYPE "NONE"
#define NIOS_HEADER_CONN_FREQ 50000000
#define NIOS_HEADER_CONN_HAS_IN 1
#define NIOS_HEADER_CONN_HAS_OUT 1
#define NIOS_HEADER_CONN_HAS_TRI 0
#define NIOS_HEADER_CONN_IRQ -1
#define NIOS_HEADER_CONN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define NIOS_HEADER_CONN_IRQ_TYPE "NONE"
#define NIOS_HEADER_CONN_NAME "/dev/nios_header_conn"
#define NIOS_HEADER_CONN_RESET_VALUE 0
#define NIOS_HEADER_CONN_SPAN 16
#define NIOS_HEADER_CONN_TYPE "altera_avalon_pio"


/*
 * nios_i2cclk configuration
 *
 */

#define ALT_MODULE_CLASS_nios_i2cclk altera_avalon_pio
#define NIOS_I2CCLK_BASE 0x8001100
#define NIOS_I2CCLK_BIT_CLEARING_EDGE_REGISTER 0
#define NIOS_I2CCLK_BIT_MODIFYING_OUTPUT_REGISTER 0
#define NIOS_I2CCLK_CAPTURE 0
#define NIOS_I2CCLK_DATA_WIDTH 1
#define NIOS_I2CCLK_DO_TEST_BENCH_WIRING 0
#define NIOS_I2CCLK_DRIVEN_SIM_VALUE 0
#define NIOS_I2CCLK_EDGE_TYPE "NONE"
#define NIOS_I2CCLK_FREQ 50000000
#define NIOS_I2CCLK_HAS_IN 0
#define NIOS_I2CCLK_HAS_OUT 1
#define NIOS_I2CCLK_HAS_TRI 0
#define NIOS_I2CCLK_IRQ -1
#define NIOS_I2CCLK_IRQ_INTERRUPT_CONTROLLER_ID -1
#define NIOS_I2CCLK_IRQ_TYPE "NONE"
#define NIOS_I2CCLK_NAME "/dev/nios_i2cclk"
#define NIOS_I2CCLK_RESET_VALUE 0
#define NIOS_I2CCLK_SPAN 16
#define NIOS_I2CCLK_TYPE "altera_avalon_pio"


/*
 * nios_i2cdat configuration
 *
 */

#define ALT_MODULE_CLASS_nios_i2cdat altera_avalon_pio
#define NIOS_I2CDAT_BASE 0x80010e0
#define NIOS_I2CDAT_BIT_CLEARING_EDGE_REGISTER 0
#define NIOS_I2CDAT_BIT_MODIFYING_OUTPUT_REGISTER 0
#define NIOS_I2CDAT_CAPTURE 0
#define NIOS_I2CDAT_DATA_WIDTH 1
#define NIOS_I2CDAT_DO_TEST_BENCH_WIRING 0
#define NIOS_I2CDAT_DRIVEN_SIM_VALUE 0
#define NIOS_I2CDAT_EDGE_TYPE "NONE"
#define NIOS_I2CDAT_FREQ 50000000
#define NIOS_I2CDAT_HAS_IN 1
#define NIOS_I2CDAT_HAS_OUT 1
#define NIOS_I2CDAT_HAS_TRI 0
#define NIOS_I2CDAT_IRQ -1
#define NIOS_I2CDAT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define NIOS_I2CDAT_IRQ_TYPE "NONE"
#define NIOS_I2CDAT_NAME "/dev/nios_i2cdat"
#define NIOS_I2CDAT_RESET_VALUE 0
#define NIOS_I2CDAT_SPAN 16
#define NIOS_I2CDAT_TYPE "altera_avalon_pio"


/*
 * nios_i2crw configuration
 *
 */

#define ALT_MODULE_CLASS_nios_i2crw altera_avalon_pio
#define NIOS_I2CRW_BASE 0x80010d0
#define NIOS_I2CRW_BIT_CLEARING_EDGE_REGISTER 0
#define NIOS_I2CRW_BIT_MODIFYING_OUTPUT_REGISTER 0
#define NIOS_I2CRW_CAPTURE 0
#define NIOS_I2CRW_DATA_WIDTH 1
#define NIOS_I2CRW_DO_TEST_BENCH_WIRING 0
#define NIOS_I2CRW_DRIVEN_SIM_VALUE 0
#define NIOS_I2CRW_EDGE_TYPE "NONE"
#define NIOS_I2CRW_FREQ 50000000
#define NIOS_I2CRW_HAS_IN 0
#define NIOS_I2CRW_HAS_OUT 1
#define NIOS_I2CRW_HAS_TRI 0
#define NIOS_I2CRW_IRQ -1
#define NIOS_I2CRW_IRQ_INTERRUPT_CONTROLLER_ID -1
#define NIOS_I2CRW_IRQ_TYPE "NONE"
#define NIOS_I2CRW_NAME "/dev/nios_i2crw"
#define NIOS_I2CRW_RESET_VALUE 0
#define NIOS_I2CRW_SPAN 16
#define NIOS_I2CRW_TYPE "altera_avalon_pio"


/*
 * nios_leds configuration
 *
 */

#define ALT_MODULE_CLASS_nios_leds altera_avalon_pio
#define NIOS_LEDS_BASE 0x8001140
#define NIOS_LEDS_BIT_CLEARING_EDGE_REGISTER 0
#define NIOS_LEDS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define NIOS_LEDS_CAPTURE 0
#define NIOS_LEDS_DATA_WIDTH 10
#define NIOS_LEDS_DO_TEST_BENCH_WIRING 0
#define NIOS_LEDS_DRIVEN_SIM_VALUE 0
#define NIOS_LEDS_EDGE_TYPE "NONE"
#define NIOS_LEDS_FREQ 50000000
#define NIOS_LEDS_HAS_IN 0
#define NIOS_LEDS_HAS_OUT 1
#define NIOS_LEDS_HAS_TRI 0
#define NIOS_LEDS_IRQ -1
#define NIOS_LEDS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define NIOS_LEDS_IRQ_TYPE "NONE"
#define NIOS_LEDS_NAME "/dev/nios_leds"
#define NIOS_LEDS_RESET_VALUE 0
#define NIOS_LEDS_SPAN 16
#define NIOS_LEDS_TYPE "altera_avalon_pio"


/*
 * nios_oscdivisor configuration
 *
 */

#define ALT_MODULE_CLASS_nios_oscdivisor altera_avalon_pio
#define NIOS_OSCDIVISOR_BASE 0x80010a0
#define NIOS_OSCDIVISOR_BIT_CLEARING_EDGE_REGISTER 0
#define NIOS_OSCDIVISOR_BIT_MODIFYING_OUTPUT_REGISTER 0
#define NIOS_OSCDIVISOR_CAPTURE 0
#define NIOS_OSCDIVISOR_DATA_WIDTH 16
#define NIOS_OSCDIVISOR_DO_TEST_BENCH_WIRING 0
#define NIOS_OSCDIVISOR_DRIVEN_SIM_VALUE 0
#define NIOS_OSCDIVISOR_EDGE_TYPE "NONE"
#define NIOS_OSCDIVISOR_FREQ 50000000
#define NIOS_OSCDIVISOR_HAS_IN 0
#define NIOS_OSCDIVISOR_HAS_OUT 1
#define NIOS_OSCDIVISOR_HAS_TRI 0
#define NIOS_OSCDIVISOR_IRQ -1
#define NIOS_OSCDIVISOR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define NIOS_OSCDIVISOR_IRQ_TYPE "NONE"
#define NIOS_OSCDIVISOR_NAME "/dev/nios_oscdivisor"
#define NIOS_OSCDIVISOR_RESET_VALUE 0
#define NIOS_OSCDIVISOR_SPAN 16
#define NIOS_OSCDIVISOR_TYPE "altera_avalon_pio"


/*
 * nios_switches configuration
 *
 */

#define ALT_MODULE_CLASS_nios_switches altera_avalon_pio
#define NIOS_SWITCHES_BASE 0x8001130
#define NIOS_SWITCHES_BIT_CLEARING_EDGE_REGISTER 0
#define NIOS_SWITCHES_BIT_MODIFYING_OUTPUT_REGISTER 0
#define NIOS_SWITCHES_CAPTURE 0
#define NIOS_SWITCHES_DATA_WIDTH 10
#define NIOS_SWITCHES_DO_TEST_BENCH_WIRING 0
#define NIOS_SWITCHES_DRIVEN_SIM_VALUE 0
#define NIOS_SWITCHES_EDGE_TYPE "NONE"
#define NIOS_SWITCHES_FREQ 50000000
#define NIOS_SWITCHES_HAS_IN 1
#define NIOS_SWITCHES_HAS_OUT 0
#define NIOS_SWITCHES_HAS_TRI 0
#define NIOS_SWITCHES_IRQ -1
#define NIOS_SWITCHES_IRQ_INTERRUPT_CONTROLLER_ID -1
#define NIOS_SWITCHES_IRQ_TYPE "NONE"
#define NIOS_SWITCHES_NAME "/dev/nios_switches"
#define NIOS_SWITCHES_RESET_VALUE 0
#define NIOS_SWITCHES_SPAN 16
#define NIOS_SWITCHES_TYPE "altera_avalon_pio"


/*
 * nios_uartrx configuration
 *
 */

#define ALT_MODULE_CLASS_nios_uartrx altera_avalon_pio
#define NIOS_UARTRX_BASE 0x8001110
#define NIOS_UARTRX_BIT_CLEARING_EDGE_REGISTER 0
#define NIOS_UARTRX_BIT_MODIFYING_OUTPUT_REGISTER 0
#define NIOS_UARTRX_CAPTURE 0
#define NIOS_UARTRX_DATA_WIDTH 1
#define NIOS_UARTRX_DO_TEST_BENCH_WIRING 0
#define NIOS_UARTRX_DRIVEN_SIM_VALUE 0
#define NIOS_UARTRX_EDGE_TYPE "NONE"
#define NIOS_UARTRX_FREQ 50000000
#define NIOS_UARTRX_HAS_IN 1
#define NIOS_UARTRX_HAS_OUT 0
#define NIOS_UARTRX_HAS_TRI 0
#define NIOS_UARTRX_IRQ -1
#define NIOS_UARTRX_IRQ_INTERRUPT_CONTROLLER_ID -1
#define NIOS_UARTRX_IRQ_TYPE "NONE"
#define NIOS_UARTRX_NAME "/dev/nios_uartrx"
#define NIOS_UARTRX_RESET_VALUE 0
#define NIOS_UARTRX_SPAN 16
#define NIOS_UARTRX_TYPE "altera_avalon_pio"


/*
 * nios_uarttx configuration
 *
 */

#define ALT_MODULE_CLASS_nios_uarttx altera_avalon_pio
#define NIOS_UARTTX_BASE 0x80010f0
#define NIOS_UARTTX_BIT_CLEARING_EDGE_REGISTER 0
#define NIOS_UARTTX_BIT_MODIFYING_OUTPUT_REGISTER 0
#define NIOS_UARTTX_CAPTURE 0
#define NIOS_UARTTX_DATA_WIDTH 1
#define NIOS_UARTTX_DO_TEST_BENCH_WIRING 0
#define NIOS_UARTTX_DRIVEN_SIM_VALUE 0
#define NIOS_UARTTX_EDGE_TYPE "NONE"
#define NIOS_UARTTX_FREQ 50000000
#define NIOS_UARTTX_HAS_IN 0
#define NIOS_UARTTX_HAS_OUT 1
#define NIOS_UARTTX_HAS_TRI 0
#define NIOS_UARTTX_IRQ -1
#define NIOS_UARTTX_IRQ_INTERRUPT_CONTROLLER_ID -1
#define NIOS_UARTTX_IRQ_TYPE "NONE"
#define NIOS_UARTTX_NAME "/dev/nios_uarttx"
#define NIOS_UARTTX_RESET_VALUE 0
#define NIOS_UARTTX_SPAN 16
#define NIOS_UARTTX_TYPE "altera_avalon_pio"


/*
 * sdram_controller_0 configuration
 *
 */

#define ALT_MODULE_CLASS_sdram_controller_0 altera_avalon_new_sdram_controller
#define SDRAM_CONTROLLER_0_BASE 0x4000000
#define SDRAM_CONTROLLER_0_CAS_LATENCY 3
#define SDRAM_CONTROLLER_0_CONTENTS_INFO
#define SDRAM_CONTROLLER_0_INIT_NOP_DELAY 0.0
#define SDRAM_CONTROLLER_0_INIT_REFRESH_COMMANDS 2
#define SDRAM_CONTROLLER_0_IRQ -1
#define SDRAM_CONTROLLER_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SDRAM_CONTROLLER_0_IS_INITIALIZED 1
#define SDRAM_CONTROLLER_0_NAME "/dev/sdram_controller_0"
#define SDRAM_CONTROLLER_0_POWERUP_DELAY 100.0
#define SDRAM_CONTROLLER_0_REFRESH_PERIOD 7.8125
#define SDRAM_CONTROLLER_0_REGISTER_DATA_IN 1
#define SDRAM_CONTROLLER_0_SDRAM_ADDR_WIDTH 0x19
#define SDRAM_CONTROLLER_0_SDRAM_BANK_WIDTH 2
#define SDRAM_CONTROLLER_0_SDRAM_COL_WIDTH 10
#define SDRAM_CONTROLLER_0_SDRAM_DATA_WIDTH 16
#define SDRAM_CONTROLLER_0_SDRAM_NUM_BANKS 4
#define SDRAM_CONTROLLER_0_SDRAM_NUM_CHIPSELECTS 1
#define SDRAM_CONTROLLER_0_SDRAM_ROW_WIDTH 13
#define SDRAM_CONTROLLER_0_SHARED_DATA 0
#define SDRAM_CONTROLLER_0_SIM_MODEL_BASE 0
#define SDRAM_CONTROLLER_0_SPAN 67108864
#define SDRAM_CONTROLLER_0_STARVATION_INDICATOR 0
#define SDRAM_CONTROLLER_0_TRISTATE_BRIDGE_SLAVE ""
#define SDRAM_CONTROLLER_0_TYPE "altera_avalon_new_sdram_controller"
#define SDRAM_CONTROLLER_0_T_AC 5.4
#define SDRAM_CONTROLLER_0_T_MRD 3
#define SDRAM_CONTROLLER_0_T_RCD 15.0
#define SDRAM_CONTROLLER_0_T_RFC 70.0
#define SDRAM_CONTROLLER_0_T_RP 15.0
#define SDRAM_CONTROLLER_0_T_WR 14.0


/*
 * spi_0 configuration
 *
 */

#define ALT_MODULE_CLASS_spi_0 altera_avalon_spi
#define SPI_0_BASE 0x8001040
#define SPI_0_CLOCKMULT 1
#define SPI_0_CLOCKPHASE 0
#define SPI_0_CLOCKPOLARITY 0
#define SPI_0_CLOCKUNITS "Hz"
#define SPI_0_DATABITS 8
#define SPI_0_DATAWIDTH 16
#define SPI_0_DELAYMULT "1.0E-9"
#define SPI_0_DELAYUNITS "ns"
#define SPI_0_EXTRADELAY 0
#define SPI_0_INSERT_SYNC 0
#define SPI_0_IRQ 4
#define SPI_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define SPI_0_ISMASTER 1
#define SPI_0_LSBFIRST 0
#define SPI_0_NAME "/dev/spi_0"
#define SPI_0_NUMSLAVES 1
#define SPI_0_PREFIX "spi_"
#define SPI_0_SPAN 32
#define SPI_0_SYNC_REG_DEPTH 2
#define SPI_0_TARGETCLOCK 128000u
#define SPI_0_TARGETSSDELAY "0.0"
#define SPI_0_TYPE "altera_avalon_spi"


/*
 * sysid_qsys_0 configuration
 *
 */

#define ALT_MODULE_CLASS_sysid_qsys_0 altera_avalon_sysid_qsys
#define SYSID_QSYS_0_BASE 0x8001150
#define SYSID_QSYS_0_ID 0
#define SYSID_QSYS_0_IRQ -1
#define SYSID_QSYS_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSID_QSYS_0_NAME "/dev/sysid_qsys_0"
#define SYSID_QSYS_0_SPAN 8
#define SYSID_QSYS_0_TIMESTAMP 1606380705
#define SYSID_QSYS_0_TYPE "altera_avalon_sysid_qsys"


/*
 * timer_0 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_0 altera_avalon_timer
#define TIMER_0_ALWAYS_RUN 0
#define TIMER_0_BASE 0x8001080
#define TIMER_0_COUNTER_SIZE 32
#define TIMER_0_FIXED_PERIOD 0
#define TIMER_0_FREQ 50000000
#define TIMER_0_IRQ 1
#define TIMER_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_0_LOAD_VALUE 49999
#define TIMER_0_MULT 0.001
#define TIMER_0_NAME "/dev/timer_0"
#define TIMER_0_PERIOD 1
#define TIMER_0_PERIOD_UNITS "ms"
#define TIMER_0_RESET_OUTPUT 0
#define TIMER_0_SNAPSHOT 1
#define TIMER_0_SPAN 32
#define TIMER_0_TICKS_PER_SEC 1000
#define TIMER_0_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_0_TYPE "altera_avalon_timer"


/*
 * uart_0 configuration
 *
 */

#define ALT_MODULE_CLASS_uart_0 altera_avalon_uart
#define UART_0_BASE 0x8001060
#define UART_0_BAUD 115200
#define UART_0_DATA_BITS 8
#define UART_0_FIXED_BAUD 0
#define UART_0_FREQ 50000000
#define UART_0_IRQ 2
#define UART_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define UART_0_NAME "/dev/uart_0"
#define UART_0_PARITY 'E'
#define UART_0_SIM_CHAR_STREAM ""
#define UART_0_SIM_TRUE_BAUD 0
#define UART_0_SPAN 32
#define UART_0_STOP_BITS 1
#define UART_0_SYNC_REG_DEPTH 2
#define UART_0_TYPE "altera_avalon_uart"
#define UART_0_USE_CTS_RTS 0
#define UART_0_USE_EOP_REGISTER 0

#endif /* __SYSTEM_H_ */
